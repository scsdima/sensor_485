/* *********************************************************************


  @File:text_protocol.c

  @Project: MAMBA2
  @Date: 2013\06\26 22-04-18
  @Description: $d


 
 ********************************************************************* */


#include "compiler.h"
#include "typedef_global.h"
#include "text_protocol.h"
#include "detection.h"
#include "syntax.h"
#include "cmd_data.h"


void this_command_get(SyntaxParameterId_t p_id);
void this_command_set(SyntaxParameterId_t p_id, const void* p, const SyntaxType_t type);

/* ********************************************************************* 
  @Function name: print_debug_information
  @Return: (void) 
  @Parameters: 
	void 
  @Description: Print debug information on start
 
 ********************************************************************* */

void text_protocol_print_test_information(void)
{
    printf("\n[Configuration]");
    this_command_get(Parameter_pwrtrig);
    this_command_get(Parameter_acctrig);
    this_command_get(Parameter_disens);
    this_command_get(Parameter_profile);
    this_command_get(Parameter_pot);
    //this_command_get(Parameter_potpos);
    printf("\n[Detection]");
    this_command_get(Parameter_mod);
    //MODE CLASSIC
    this_command_get(Parameter_trigcnt);
    this_command_get(Parameter_trigsum);
    this_command_get(Parameter_triglev);
    this_command_get(Parameter_wavtole);
    this_command_get(Parameter_wavtrig);
    this_command_get(Parameter_wavlcnt);
    this_command_get(Parameter_wavrcnt);
    printf("\n[Inputs/Outputs]");
    this_command_get(Parameter_acc);
    this_command_get(Parameter_a0);
    this_command_get(Parameter_a1);
    this_command_get(Parameter_a2);
    this_command_get(Parameter_t1cfg);
    this_command_get(Parameter_t2cfg);
}



/* *********************************************************************
  @Function name: text_protocol_process
  @Return: (void)
  @Parameters:
	void
  @Description: Print debug information on start

 ********************************************************************* */
ResultSuccess_t text_protocol_process(const CHAR *pstr){
    if(this_input_buf_free == FALSE)/* has data*/
    {
        syntax_string((char*)&this_input_buf[0]); //process Ascii string
        this_input_buf_free = TRUE;
    }    
}



/* *********************************************************************
  @Function name: on_parameter_found
  @Return: (void)
  @Parameters:
        unsigned int cmd_id - command ID
        unsigned int p_id - parameter ID
        void *p - unknown data pointer
        unsigned char type -data type
  @Description: Execute command from string with parameters .
                Function holder for parameters
 ********************************************************************* */
void on_parameter_found(UINT8 cmd_id , UINT8 p_id
                        , const void* p, const SyntaxType_t type) {

   // ResultSuccess_t result = RESULT_SUCCESS;

        switch (cmd_id) {
            case Command_get:
                if (type != typeCommand) {
                    this_command_get(p_id);
                }
                break;

            case Command_set:
                if (type != typeCommand) {
                    if (p)
                        this_command_set(p_id, p, type);
                } 
                break;

            case Command_init:
                printf( TXT_OK);
                event_set(eventRestart);

                break;

            case Command_list:
                print_test_information();
                break;

            case Command_selftest:
                 event_set(eventSelfControl);
                 device_self_test_pulse();
                 printf( TXT_OK);
                break;

            case Command_help:
                if (!p) {
                   printf(g_text_help);
                }
                break;

            default:
                break;
        }/*switch*/

        if (type == typeCommand) {
            uart_puts("\r\n");
        }
}

/* *********************************************************************
  @Function name: this_command_get
  @Return: (void)
  @Parameters:
        void
  @Description: Command get

 ********************************************************************* */
void this_command_get(SyntaxParameterId_t p_id) {

    UINT16 mvolt;
    UINT16 value;

    switch (p_id) {

        case Parameter_a0:
            printf("\na0=%dmV(%d)", (INT16) toVoltage_Signal(g_Analog0),g_Analog0);
            break;

        case Parameter_a1:
            printf("\na1=%dmV(%d)", (INT16) toVoltage_Signal(g_Analog1),g_Analog1);
            break;

        case Parameter_a2:
            printf("\na2=%dmV(%d)", (INT16) toVoltage_Power(g_Analog2),g_Analog2);
            break;

        case Parameter_din:
            printf("\ndi=%d\n ", PIN_EXTERNAL_INPUT);
            break;

        case Parameter_status:
            printf("\nalarm=%d end=%d pwr=%d tester=%d acc=%d tamper1=%d,tamper2=%d"
                    , g_STATUS.Alarm, g_STATUS.CableState, g_STATUS.PowerProblem
                    , g_STATUS.TesterEnabled, g_STATUS.AccMove, g_STATUS.Tamper1, g_STATUS.Tamper2);
            break;

        case Parameter_acc:/*tested*/
            printf("\nacc=x:%d,y:%d,z:%d"
                    , g_axis.x, g_axis.y, g_axis.z);
            break;

        case Parameter_adr:
            printf("\nnwadr=%d", g_nw_addr);
            break;

        case Parameter_ver:
            printf("\nver=0x%x", VERSION);
            printf(COMPILE_VERSION);
            break;

        case Parameter_aux:
            printf("\naux=%d", 0);
            break;

        case Parameter_error:
            printf("\nerror=%d,%d", error_get_last(),error_get_count());
            break;

        case Parameter_mod:
        {
            printf("\nmod=");
               switch (g_CONFIG.DetectionConfig.mode) {
                case DETECTION_MODE_CLA:
                    printf("cla");
                    break;
                case DETECTION_MODE_WAV:
                    printf("wav");
                    break;
                case DETECTION_MODE_CAW:
                    printf("wac");
                    break;
                case DETECTION_MODE_COW:
                    printf("woc");
                    break;
                default:
                    printf("off");
                    break;
            }
            printf("(%d)", g_CONFIG.DetectionConfig.mode);
        }
            break;

        case Parameter_t1cfg:
            printf("\nt1cfg=");
            if (g_CONFIG.t1cfg &TAMPER_ACCELEROMETER)    {
                printf("a");
            }
            if (g_CONFIG.t1cfg & TAMPER_CABLE_END) {
                printf("c");
            }
            if (g_CONFIG.t1cfg & TAMPER_POWER) {
                printf("p");
            }
            printf("(0x%d)", g_CONFIG.t1cfg);
            break;

        case Parameter_t2cfg:
            printf("\nt2cfg=");
            if (g_CONFIG.t2cfg & TAMPER_ACCELEROMETER)    {
                printf("a");
            }
            if (g_CONFIG.t2cfg & TAMPER_CABLE_END) {
                printf("c");
            }
            if (g_CONFIG.t2cfg & TAMPER_POWER) {
                printf("p");
            }
            printf("(0x%d)", g_CONFIG.t2cfg);
            break;

        case Parameter_disens:
            printf("\ndisens=%d", g_CONFIG.DiSensLevel);
            break;

        case Parameter_pot:
            printf("\npot=%d", g_CONFIG.PotentiometerValue);
            break;

        case Parameter_potpos:
            printf("\npotpos=%d", g_PotentiometerPos);
            break;

        case Parameter_profile:
            printf("\nprofile=%d", g_CONFIG.ProfileN);
            break;

        case Parameter_triglev:/*tested*/
            printf("\ntriglev=%d",g_CONFIG.DetectionConfig.ClassicTriggerValue);
            break;

        case Parameter_trigsum:/*tested*/
            printf("\ntrigsum=%d", g_CONFIG.DetectionConfig.ClassicTriggerSum);
            break;

        case Parameter_trigcnt:/*tested*/
            printf("\ntrigcnt=%d",g_CONFIG.DetectionConfig.ClassicTriggerCount);
            break;

        case Parameter_pwrtrig:/*tested*/
            printf("\npwrtrig=%dmV(%d)",
            (UINT16)toVoltage_Power(g_CONFIG.PowerTrig), g_CONFIG.PowerTrig);
            break;

        case Parameter_acctrig:/*tested*/
            printf("\nacctrig=%u", g_CONFIG.AccSensitivity);
            break;
        
        case Parameter_wavtole:/*tested*/
            printf("\nwavtole=%u", g_CONFIG.DetectionConfig.VaveletTolerance);
            break;

        case Parameter_wavtrig:/*tested*/
            printf("\nwavtrig=%u *1000",g_CONFIG.DetectionConfig.VaveletWTrig/ 1000);
            break;

        case Parameter_wavlcnt:/*tested*/
            printf("\nwavlcnt=%u", g_CONFIG.DetectionConfig.VaveletLastCount);
            break;

        case Parameter_wavrcnt:/*tested*/
            printf("\nwavrcnt=%u", g_CONFIG.DetectionConfig.VaveletReferenceCount);
            break;

        case Parameter_detsrc:
            printf("\ndetsrc=%u", g_CONFIG.DetectionConfig.source);
            break;
            
        default:
            break;
    }
}

/* *********************************************************************
  @Function name: this_command_set
  @Return: (void)
  @Parameters:
        void
  @Description: Command set

 ********************************************************************* */

void this_command_set(SyntaxParameterId_t p_id, const void* p, const SyntaxType_t type) {

    ResultSuccess_t result = RESULT_FAIL;
    UINT16 value_u16;
    UINT8  value_u8;
    sprintf(debug_buffer,"\n%s:",syx_param_list[p_id].name);
    DEBUG(debug_buffer);
    switch (p_id) {

        case Parameter_profile:        
            value_u8 = reinterpret_ptr(UINT8, p);
            if( value_u8 <= 5 ){
                device_set_profile_n(value_u8);
                result = RESULT_SUCCESS;
            }        
            break;

        case Parameter_mod:/*#mod# - tested*/
              result = RESULT_SUCCESS;
            if (strncmp(((char*) p), "wav", 3) == 0) {
                g_CONFIG.DetectionConfig.mode = DETECTION_MODE_WAV;
            } else if (strncmp(((char*) p), "cla", 3) == 0) {
                g_CONFIG.DetectionConfig.mode = DETECTION_MODE_CLA;
            } else if (strncmp(((char*) p), "wac", 3) == 0) {
                g_CONFIG.DetectionConfig.mode = DETECTION_MODE_CAW;
            } else if (strncmp(((char*) p), "woc", 3) == 0) {
                g_CONFIG.DetectionConfig.mode = DETECTION_MODE_COW;
            }
            else {
                result = RESULT_FAIL;
            }
            break;

        case Parameter_id:
        {
            value_u16 = reinterpret_ptr(UINT16, p);
            UINT32 id = (UINT32)2010000UL + (UINT32)value_u16;
            result = config_save_device_inf(DEV_INF_ID, id);
        }
            break;

        case Parameter_psw:
            break;

        case Parameter_pot:/*#pot# - tested*/            
                value_u8 = reinterpret_ptr(UINT8, p);
                result = trimmer_set_value(POTENTIOMETER_A, value_u8);
                if(result == RESULT_SUCCESS) {
                    g_CONFIG.PotentiometerValue = value_u8;
                }            
            break;

        case Parameter_triglev:/*#trigval# - 0-1999 tested*/
            value_u16 = reinterpret_ptr(UINT16, p);
            if(value_u16 >0 && value_u16 <= 1999U){
                g_CONFIG.DetectionConfig.ClassicTriggerValue = value_u16;
                result = RESULT_SUCCESS;
            }
            break;

        case Parameter_trigsum:/*#trigsum# - doesnot work under 9999!!!!*/
            value_u16 = reinterpret_ptr(UINT16, p);
            if(value_u16 >100 && value_u16 <= 9999U){
                g_CONFIG.DetectionConfig.ClassicTriggerSum = value_u16;
                result = RESULT_SUCCESS;
            }
            break;

        case Parameter_trigcnt:/*#trigcnt# - tested 1-999*/
            value_u16 = reinterpret_ptr(UINT16, p);
            if(value_u16 >0 && value_u16 <= 999U){
                g_CONFIG.DetectionConfig.ClassicTriggerCount = value_u16;
                result = RESULT_SUCCESS;
            }
            break;

        case Parameter_disens:
            value_u8 = reinterpret_ptr(UINT8, p);
            if(value_u8 < 100){
                g_CONFIG.DiSensLevel = value_u8;
                result = RESULT_SUCCESS;
            }
            break;

        case Parameter_pwrtrig:                                       
            value_u16 = reinterpret_ptr(UINT16, p);
            if(value_u16 > MINIMUM_POWER){
                g_CONFIG.PowerTrig = toValue_Power((double)value_u16);
                result = RESULT_SUCCESS;
            }        
            break;

        case Parameter_acctrig:
            value_u16 = reinterpret_ptr(UINT16, p);
            if(value_u16 >0 && value_u16 < 20U){
                g_CONFIG.AccSensitivity = value_u16;
                result = RESULT_SUCCESS;
            }
            break;

        case Parameter_t1cfg:
            value_u16=0;
            if(strchr((char*)p,'a')) {value_u16 |= TAMPER_ACCELEROMETER ;}
            if(strchr((char*)p,'p')) {value_u16 |= TAMPER_POWER;}
            if(strchr((char*)p,'c')) {value_u16 |= TAMPER_CABLE_END;}
            g_CONFIG.t1cfg = (UINT8)value_u16;
            result = RESULT_SUCCESS;
            break;

        case Parameter_t2cfg:
            value_u16 = 0;
            if(strchr((char*)p,'a')) {value_u16 |= TAMPER_ACCELEROMETER;}
            if(strchr((char*)p,'p')) {value_u16 |= TAMPER_POWER;}
            if(strchr((char*)p,'c')) {value_u16 |= TAMPER_CABLE_END;}
             g_CONFIG.t2cfg = (UINT8)value_u16;
             result = RESULT_SUCCESS;
            break;

        case Parameter_wavtole:/**/
            value_u16 = reinterpret_ptr(UINT16, p);
            if(value_u16 >0 && value_u16 <= 100U){
                g_CONFIG.DetectionConfig.VaveletTolerance = value_u16;
                result = RESULT_SUCCESS;
            }
            break;

        case Parameter_wavtrig:/*tested*/
            value_u16 = reinterpret_ptr(UINT16, p);
            if(value_u16 >0U && value_u16 <= 999U){
                g_CONFIG.DetectionConfig.VaveletWTrig = (UINT32)value_u16 *1000U;
                result = RESULT_SUCCESS;
            }
            break;

        case Parameter_wavlcnt:/**/
            value_u16 = reinterpret_ptr(UINT16, p);
            if(value_u16 >0 && value_u16 <= 10U){
                g_CONFIG.DetectionConfig.VaveletLastCount = value_u16;
                result = RESULT_SUCCESS;
            }
            break;

        case Parameter_wavrcnt:
            value_u16 = reinterpret_ptr(UINT16, p);
            if(value_u16 >0 && value_u16 <= 10U ){
                g_CONFIG.DetectionConfig.VaveletReferenceCount = value_u16;
                result = RESULT_SUCCESS;
            }
            break;

        case Parameter_detsrc:
            value_u8 = reinterpret_ptr(UINT8, p);
            if(value_u8 < DETECTION_SOURCE_COUNT){
                g_CONFIG.DetectionConfig.source = value_u8;
            }
        break;

        case Parameter_defaults:
            device_config_set_default();
            result = RESULT_SUCCESS;            
            break;
        default:
            break;
    }
    if(result == RESULT_SUCCESS){
        result = device_config_save();
    }
    if( result == RESULT_SUCCESS ){
            device_config_apply();
            uart_puts(TXT_OK);            
        }        
    
    else{
     uart_puts(TXT_ERROR);
    }
}





