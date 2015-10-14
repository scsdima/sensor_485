/* *********************************************************************
 * Communication by standard 8 byte protocol
 * 4 byte is header 4 byte is data UINT32 for example.
 * Communcation is synchronous .
 * It means 1 request - 1 answer
 * [system cannot accept 2 requests at the same time]
 *
 * 
 *
 * All packets are send in 8 bytes each command reads single refgister or
 * making one function
 *
 * [Normal packet]
 * 0:[<Preamble> AA]
 * 1:[<address 0-31> adr]
 * 2:[<Control sum> crc]
 * 3:[<command code> cmd]
 * 4:[w0]
 * 5:[w1]
 * 6:[w2]
 * 7:[w3]
 *
 * NOTE:
 *    **  crc= [3]+[4]+[5]+[6]+[7]
 *          crc is low byte of sum
 *
 *    **  all data is little endian
 *
 * EXAMPLE
 *      0xAA 0x01 0x01 0x01 0x00 0x00 0x00 0x00 reads status register 
 *      0xAA 0x81 0x15 0x01 0x00 0x10 0x05 0x00 sensor will return value
 *
 *********************************************************************** */


#include "standard_protocol.h"
#include "device.h"
#include "detection.h"
#include "typedef_global.h"
#include "compile_version.h"

#define STD_MAX_RECORDS    (5)

/*
 *  pools are used for passing commands with command size
 * This model is used to regulate commands input and do not stop
 * the process
 * 50Ms timeout between commands tx/rx must be used
 */

/*INPUT POOL*/
/* pool - buffer for protocol commands */
static StdProtocolCommand_t this_input_pool[STD_MAX_RECORDS];
/* index of pool entry*/
static UINT8 this_input_pool_cnt=0;

/* OUTPUT POOL*/
static StdProtocolCommand_t this_output_pool[STD_MAX_RECORDS];
/* index of pool entry*/
static UINT8 this_output_pool_cnt=0;

/*pointer to current record at the begining*/
static UINT8 *this_input_buf = NULL;
/*  buffer for output data  */
static UINT8 this_output_buf[20]={0};
/*  last received command    */
static UINT8 this_command ;
/*  parameter of command received*/
static UINT32 this_parameter ;
/* answwer value to send */
static UINT32 this_answer_val;
/* */
static BOOL this_input_buf_empty = TRUE;
/* check if data in buffr is a command */
StdProtocolCommandError_t this_check_command(void);
/* execute read register GET command*/
ResultSuccess_t this_command_read(void);
/* execute write register SET command*/
ResultSuccess_t this_command_write(void);
/* executes command FUNC command */
ResultSuccess_t this_command_func(void);
/* this function gets stream data */
void this_command_stream(void);
/* send answer data NAK ACK*/
void this_send_answer(ResultSuccess_t result);

/* *********************************************************************
  @Function name: standard_protocol_process - processes data as command
  @Return: (void)
  @Parameters:
        void
  @Description: $d

 ********************************************************************* */
ResultSuccess_t standard_protocol_add_packet(const UINT8 *data){
    UINT16 i;
    if(this_input_pool_cnt >= STD_MAX_RECORDS){
        return RESULT_FAIL;
    }
    else{
        this_input_buf = (UINT8*)&this_input_pool[this_input_pool_cnt];
        /*copy*/
        for(i=0; i < MAMBA_PROTOCOL_PACKET_SIZE; i++){
            this_input_buf[i] = data[i];
            }
        this_input_pool_cnt++;
        return RESULT_SUCCESS;
   }
    
}
/* ********************************************************************* 
  @Function name: standard_protocol_process - processes data as command
  @Return: (void) 
  @Parameters: 
        void
  @Description: $d
 
 ********************************************************************* */
void standard_protocol_process(void) {
    UINT16 i;
    /* process pool with packets*/
    for(i=0; i < this_input_pool_cnt; i++){
    this_input_buf = (UINT8*)&this_input_pool[i];           
    /*check header received data if it is standard mamba protocol*/
    switch (this_check_command()) {

        case(STD_PROTOCOL_NO_ERROR):
            {
                ResultSuccess_t result;
                /*STREAM*/
                if (this_command == FUNC_GET_STREAM) {
                    this_command_stream();
                } else {

                    /* READING  */
                    if (this_command <= FUNC_READ) {
                        result = this_command_read();
                    }/* WRITING  */
                else if (this_command <= FUNC_WRITE) {
                    if (device_config_is_locked() == FALSE) {
                        result = this_command_write();
                        event_set(eventSaveConfiguration);
                        //jobSaveConfiguration();
                    } else {
                        result = RESULT_FAIL;
                    }
                }/* FUNCTION */
                    else {
                        result = this_command_func();
                    }
                    /*RESULT*/
                    this_send_answer(result);
                }
            }
                break;

            case (STD_PROTOCOL_PACKET_ERROR):
                this_command = FUNC_NAK;
                this_answer_val = 0;
                this_send_answer(RESULT_FAIL);

                break;

            case (STD_PROTOCOL_IGNORE):

                break;

            default:
                break;
        }//switch
    }
    this_input_pool_cnt = 0;
}

/* *********************************************************************
  @Function name: this_send_answer
  @Return: (void)
  @Parameters:
        (ResultSuccess_t result) - sends result if ok or NAK  if fail
  @Description: $d

 ********************************************************************* */
void this_send_answer(ResultSuccess_t result) {
    UINT8 check_sum;

    this_output_buf[0] = MAMBA_PROTOCOL_PREAMBLE;
    this_output_buf[1] = (g_nw_addr | SP_OPTION_ANSWER); //is answer
    this_output_buf[3] = (UINT8) this_command;
    *((UINT32*) & this_output_buf[4]) = this_answer_val;
    /* control sum calculating*/
    check_sum = (this_output_buf[3] + this_output_buf[4]
            + this_output_buf[5] + this_output_buf[6]
            + this_output_buf[7]);
    this_output_buf[2] = check_sum;
    uart_put_data(this_output_buf, 8); /*finally sending answer packet*/

}

/* *********************************************************************
  @Function name: this_check_command -  this implement checking for header of
                                    command packet
  @Return: (StdProtocolCommandError_t)
  @Parameters:
        void
  @Description: $d

 ********************************************************************* */
StdProtocolCommandError_t this_check_command(void) {
    UINT8 address;
    UINT8 option = this_input_buf[1];
    UINT8 check_sum = this_input_buf[2];
    this_command = 0u;

    /* if preamble not correct*/
    if (this_input_buf[0] != MAMBA_PROTOCOL_PREAMBLE) {
        return STD_PROTOCOL_PACKET_ERROR;
    }

    /* dont process return messages /answers/*/
    if (option & SP_OPTION_ANSWER) {
        return STD_PROTOCOL_IGNORE;
    }
    address = option & SP_ADDRESS_MASK;
    if (g_nw_addr != address) {
        return STD_PROTOCOL_IGNORE;
    }

    /* checking of control sum*/
    check_sum = (this_input_buf[3] + this_input_buf[4]
            + this_input_buf[5] + this_input_buf[6] + this_input_buf[7]) - check_sum;
    if (check_sum != 0) {
        return STD_PROTOCOL_PACKET_ERROR;
    }
    this_command = this_input_buf[3];
    this_parameter = *((UINT32*) & this_input_buf[4]);

    return STD_PROTOCOL_NO_ERROR;
}

/* *********************************************************************
  @Function name: this_command_write - makes write of data to system
  @Return: (ResultSuccess_t)
  @Parameters:
        void
  @Description: $d

 ********************************************************************* */
ResultSuccess_t this_command_write(void) {

    ResultSuccess_t result = RESULT_FAIL;
    this_answer_val = 0;
    switch (this_command) {

        case FUNC_SET_POTVAL:
            if(this_parameter < 255UL){
                g_CONFIG.PotentiometerValue = (UINT8) this_parameter;
                result = RESULT_SUCCESS;
            }
            break;

        case FUNC_SET_BAUD:
            result = RESULT_FAIL;        
            break;

        case FUNC_SET_DETMODE:
            if ( this_parameter < (UINT32)DETECTION_MODE_COUNT) {
                g_CONFIG.DetectionConfig.mode = (UINT8) this_parameter;
                result = RESULT_SUCCESS;
            }
            break;

        case FUNC_SET_PROFILEN:
            if (this_parameter < (UINT32)PROFILES_COUNT) {
                device_set_profile_n((UINT8) this_parameter);
                result = RESULT_SUCCESS;
            }
            break;

        case FUNC_SET_ACCSENS:
            if (this_parameter <= 20U && this_parameter > 1U) {
                g_CONFIG.AccSensitivity = (UINT8) this_parameter;
                result = RESULT_SUCCESS;
            }
            break;

        case FUNC_SET_DFREQ:
            if (this_parameter <= 20U) {
                g_CONFIG.DiscretizationFrequency = (UINT8) this_parameter;
                result = RESULT_SUCCESS;
            }
            break;

        case FUNC_SET_PWRTRIG://config.min_power
            //if((UINT8) this_parameter <
            g_CONFIG.PowerTrig = (UINT16) this_parameter;
            result = RESULT_SUCCESS;
            break;

        case FUNC_SET_ALARMDUR://config.alarm_dur
            if ( this_parameter <= 20000UL) {
                g_CONFIG.AlarmDuration = (UINT16) this_parameter;
                result = RESULT_SUCCESS;
            }
            break;

        case FUNC_SET_T1DUR:
            if (this_parameter <= 20000UL) {
                g_CONFIG.Tamper1Duration = (UINT16) this_parameter;
                result = RESULT_SUCCESS;
            }
            break;

        case FUNC_SET_T2DUR:
            if (this_parameter <= 20000UL) {
                g_CONFIG.Tamper2Duration = (UINT16) this_parameter;
                result = RESULT_SUCCESS;
            }
            break;

        case FUNC_SET_DISENS:
            if ( this_parameter < 100UL) {
                g_CONFIG.DiSensLevel = (UINT16) this_parameter;
                result = RESULT_SUCCESS;
            }
            break;

        case FUNC_SET_T1T2CFG:
            g_CONFIG.t1cfg = (UINT8) (this_parameter >> 16);
            g_CONFIG.t2cfg = ((UINT8) this_parameter);
            result = RESULT_SUCCESS;
            break;

            //*****classic
        case FUNC_SET_TRIGLEV://trigger
            if ( this_parameter < 1000UL) {
                g_CONFIG.DetectionConfig.ClassicTriggerValue = (UINT16) this_parameter;
                result = RESULT_SUCCESS;
            }
            break;

        case FUNC_SET_TRIGSUM://trigger sum
            if ( this_parameter < 9999UL) {
                g_CONFIG.DetectionConfig.ClassicTriggerSum = (UINT16) this_parameter;
                result = RESULT_SUCCESS;
            }
            break;

        case FUNC_SET_TRIGCNT://trigger count
            if (this_parameter < 300UL) {
                g_CONFIG.DetectionConfig.ClassicTriggerCount = (UINT16) this_parameter;
                result = RESULT_SUCCESS;
            }
            break;

            //****vavelet
        case FUNC_SET_WAVTRIG://trigger
            if (this_parameter < 999000UL) {
                g_CONFIG.DetectionConfig.VaveletWTrig =  this_parameter;
                result = RESULT_SUCCESS;
            }
            break;

        case FUNC_SET_WAVTOLE://trigger sumcase
            if ( this_parameter < 100UL) {
                g_CONFIG.DetectionConfig.VaveletTolerance =  this_parameter;
                result = RESULT_SUCCESS;
            }
            break;

        case FUNC_SET_WAVLCNT://trigger count
            if ( this_parameter >0UL && this_parameter < 10UL) {
                g_CONFIG.DetectionConfig.VaveletLastCount =  this_parameter;
                result = RESULT_SUCCESS;
            }
            break;

        case FUNC_SET_WAVRCNT://trigger count
            if ( this_parameter > 1UL && this_parameter < 10UL) {
                g_CONFIG.DetectionConfig.VaveletReferenceCount =  this_parameter;
                result = RESULT_SUCCESS;
            }
            break;
        

        case 0x75:

            break;

        default:
            result = RESULT_FAIL;
            break;
    }//switch


    return result;
}

/* *********************************************************************
  @Function name: this_command_stream -sends stream packet for pc
                    communication
  @Return: (void)
  @Parameters:
        void
  @Description: Fill stream command with data

 ********************************************************************* */
void this_command_stream(void) {
    static StdProtocolCommandEx_t _acmd;
    /*TODO alter*/
    _acmd.data.status.value = g_STATUS.value;
    _acmd.data.a0 = g_Analog0;
    _acmd.data.a1 = g_Analog1;
    _acmd.data.a2 = g_Analog2;
    _acmd.data.wsig = (UINT32) videodetector.wval;
    _acmd.adr = g_nw_addr | 0x80 | 0x40;
    _acmd.pre = MAMBA_PROTOCOL_PREAMBLE;
    _acmd.cmd = this_command;
    _acmd.sum = 0xF0; //fixed value to control
    uart_put_data((UINT8*) & _acmd, sizeof (StdProtocolCommandEx_t));
}

/* *********************************************************************
  @Function name: this_command_read
  @Return: (ResultSuccess_t) - reads data from system
  @Parameters:
        void
  @Description: $d

 ********************************************************************* */
ResultSuccess_t this_command_read(void) {
    ResultSuccess_t result = RESULT_SUCCESS;
    this_answer_val = 0u;
    switch (this_command) {
        case FUNC_GET_STATUS:
            this_answer_val = (UINT32) g_STATUS.value;
            break;

        case FUNC_GET_POTPOS://state.pot_pos
            this_answer_val = (UINT32) g_PotentiometerPos;
            break;

        case FUNC_GET_ANA2://state.analog2
            this_answer_val = (UINT32) g_Analog2; //power
            break;

        case FUNC_GET_ANA0://state.analog0
            this_answer_val = (UINT32) g_Analog0;
            break;

        case FUNC_GET_ANA1://state.analog1
            this_answer_val = (UINT32) g_Analog1; //terminal
            break;

        case FUNC_GET_ACCVAL://state.acc_value
            this_answer_val = (UINT32) 0;
            break;

        case FUNC_GET_ACCAXIS://state.comm value
            this_answer_val = (UINT32) g_axis.x | ((UINT32) g_axis.y << 8) | ((UINT32) g_axis.z << 16);
            break;

        case FUNC_GET_DEVID://state.comm value
            this_answer_val = (UINT32) DEVICE_ID; //id
            break;

        case FUNC_GET_LASTERROR:
            this_answer_val = (UINT32) error_get_last();
            break;

        case FUNC_GET_ZERO://zero read
            this_answer_val = detection_get_zero();
            break;

        case FUNC_GET_ANA0_STATUS://combined ad value and status
            this_answer_val = g_Analog0;
            this_answer_val |= (UINT32) g_STATUS.value << 16;
            break;

        case FUNC_GET_FWVER:
            this_answer_val = RELEASE_VERSION;
            break;

        case FUNC_GET_ANA1_STATUS:
            this_answer_val = g_Analog1;
            this_answer_val |= (UINT32) g_STATUS.value << 16;
            break;

        case FUNC_GET_WVAL:
            this_answer_val = videodetector.wval;
            break;

            /**********Config********/
        case FUNC_GET_POTVAL://config.sw_pot_val
            this_answer_val = (UINT32) g_CONFIG.PotentiometerValue;
            break;

        case FUNC_GET_BAUD://config.baudrate
            this_answer_val = (UINT32) g_CONFIG.PortSpeed;
            break;

        case FUNC_GET_DETMODE://config.DetectionMode
            this_answer_val = (UINT32) g_CONFIG.DetectionConfig.mode;
            break;

        case FUNC_GET_ACCSENS://config.acc_sens
            this_answer_val = (UINT32) g_CONFIG.AccSensitivity;
            break;

        case FUNC_GET_PWRTRIG://config.min_power
            this_answer_val = (UINT32) g_CONFIG.PowerTrig;
            break;

        case FUNC_GET_T0DUR://config.alarm_dur
            this_answer_val = (UINT32) g_CONFIG.AlarmDuration;
            break;

        case FUNC_GET_T1DUR://config.tamper1_dur
            this_answer_val = (UINT32) g_CONFIG.Tamper1Duration;
            break;

        case FUNC_GET_T2DUR://config.tamper2_dur
            this_answer_val = (UINT32) g_CONFIG.Tamper2Duration;
            break;

        case FUNC_GET_DISENS://config.digital_in_dur
            this_answer_val = (UINT32) g_CONFIG.DiSensLevel;
            break;

        case FUNC_GET_T1T2CFG:
            this_answer_val = (UINT32) (g_CONFIG.t1cfg << 16) | g_CONFIG.t2cfg;
            break;

        case FUNC_GET_DFREQ://
            this_answer_val = (UINT8) g_CONFIG.DiscretizationFrequency;
            break;

        case FUNC_GET_PROFILEN:
            this_answer_val = (UINT32) g_CONFIG.ProfileN;
            break;

        case FUNC_GET_TRIGLEV://trigger
            this_answer_val = (UINT32) g_CONFIG.DetectionConfig.ClassicTriggerValue;
            break;

        case FUNC_GET_TRIGSUM://trigger sum
            this_answer_val = (UINT32) g_CONFIG.DetectionConfig.ClassicTriggerSum;
            break;

        case FUNC_GET_TRIGCNT://trigger count
            this_answer_val = (UINT32) g_CONFIG.DetectionConfig.ClassicTriggerCount;
            break;

        case FUNC_GET_DETRES1://result trigger sum
            this_answer_val = (UINT32) detection_get_res1();
            break;

        case FUNC_GET_DETRES2: //tesult trigger count
            this_answer_val = (UINT32) detection_get_res2();
            break;

        case FUNC_GET_WAVWTRIG://trigger
            this_answer_val = (UINT32) g_CONFIG.DetectionConfig.VaveletWTrig;
            break;

        case FUNC_GET_WAVTOLERANCE://trigger sumcase
            this_answer_val = (UINT32) g_CONFIG.DetectionConfig.VaveletTolerance;
            break;

        case FUNC_GET_WAVLVAL://trigger count
            this_answer_val = (UINT32) g_CONFIG.DetectionConfig.VaveletLastCount;
            break;

        case FUNC_GET_WAVRVAL://trigger count
            this_answer_val = (UINT32) g_CONFIG.DetectionConfig.VaveletReferenceCount;
            break;

   /* files commuication */
        /* function to get a file data */
        case FUNC_GET_FILE_DATA:
        {
            UINT32 *file_ptr;
            UINT16 file_n = (UINT16) ((0xFFFF0000UL & this_parameter) >> 16);
            UINT16 pos_in_file = (UINT16) (0x0000FFFFUL &this_parameter);
            file_ptr = (UINT32*) datatracker_get(file_n);            
            if (file_ptr != NULL) {
                /* 0xffff means send all file*/
                if(pos_in_file == (UINT16)0xFFFFUL) { 
                    UINT16 i;
                    for(i=0; i<DT_FILE_SIZE-1; i++){
                       this_answer_val = (UINT32) file_ptr[i];
                       this_send_answer(RESULT_SUCCESS);
                    }
                    /* send last element*/
                    this_answer_val = (UINT32) file_ptr[i];
                }
                /* send by one point */
                else{
                    this_answer_val = (UINT32) file_ptr[pos_in_file];
                }
            } else {
                this_answer_val = 0;
                result = RESULT_FAIL;
            }
        }
            break;
        /* get last file data*/
        case FUNC_GET_LAST_FILE_DATA:
        {
            UINT32 *file_ptr;
            UINT16 file_n;            
            file_n = (UINT16) datatracker_file_last();
            file_ptr = (UINT32*) datatracker_get(file_n);
            if (file_ptr != NULL) {
                    UINT16 i;
                    for( i=0; i < DT_FILE_SIZE-1; i++){
                       this_answer_val = (UINT32)file_ptr[i];
                       this_send_answer(RESULT_SUCCESS);
                    }
                    /* send last element*/
                    this_answer_val = (UINT32)file_ptr[i];
            } else {
                this_answer_val = 0;
                result = RESULT_FAIL;
            }
        }
            break;
        /* get files in system count and last number */
        case FUNC_GET_FILE_LIST:
            {
                UINT16 files_count = (UINT16) datatracker_files_count();
                UINT16 last_file_number = (UINT16) datatracker_file_last();
                this_answer_val = (UINT32)(last_file_number << 16) | files_count;
            }
            break;
    }//switch
    return result;
}

/* *********************************************************************
  @Function name: this_command_func - executes command
  @Return: (ResultSuccess_t)
  @Parameters:
        void
  @Description: $d

 ********************************************************************* */
ResultSuccess_t this_command_func(void) {
    ResultSuccess_t result = RESULT_FAIL;
    this_answer_val = 0u;

    switch (this_command) {

        case FUNC_LOCK: //lock
            device_config_lock();
            result = RESULT_SUCCESS;
            break;

        case FUNC_UNLOCK: //unlock
            device_config_unlock(this_parameter);
            if (!device_config_is_locked()) {
                result = RESULT_SUCCESS;
            }
            break;

        case FUNC_RESET://reset
            SoftReset();
            break;

        case FUNC_DEFAULTS://reset
            device_config_set_default();
            SoftReset();
            break;

        case FUNC_SET_ID://set ID
            if (TesterIsEnabled()) {
                config_save_device_inf(DEV_INF_ID,this_parameter);
                result = RESULT_SUCCESS;
            }
            break;

        case FUNC_SET_PSW://set PSW
            if (TesterIsEnabled()) {
                config_save_device_inf(DEV_INF_PSW, this_parameter);
                result = RESULT_SUCCESS;
            }
            break;

    }//switch
    return result;
}

