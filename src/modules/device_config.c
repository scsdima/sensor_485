/* *********************************************************************


  @File:device_config.c

  @Project: MAMBA2
  @Date: 2013\06\26 10-03-20
  @Description: eeprom config


 
 ********************************************************************* */


#include "device_config.h"
#include "compiler.h"
#include "eeprom.h"
#include "typedef_global.h"
#include "memory_register_map.h"

// static const Config_t default_config ={
//     .__crc                    = 0u,
//     .ProfileN                 = 1u,
//     .PotentiometerValue       = DEFAULT_POT,
//     .PortSpeed                = DEFAULT_BAUD,
//     .AccSensitivity           = DEFAULT_ACC_SENSITIVITY,
//     .DiscretizationFrequency  = DEFAULT_DFREQ,
//     .PowerTrig                = DEFAULT_POWER_TRIGGER,
//     .AlarmDuration            = DEFAULT_T0DUR,
//     .Tamper1Duration          = DEFAULT_T1DUR,
//     .Tamper2Duration          = DEFAULT_T2DUR,
//     .DiSensLevel              = DEFAULT_DISENS,
//     .t1cfg                    = TAMPER_CABLE_END,
//     .t2cfg                    = DEFAULT_T2CFG ,
//     .DetectionConfig          = DEFAULT_DETECTION,
//     .LastZero                 = 431u
// };


static BOOL locked = TRUE;


/* ********************************************************************* 
  @Function name:  device_config_save
  @Return: (ResultSuccess_t) 
  @Parameters: 
	void 
  @Description: EEPROM config save
 
 ********************************************************************* */
ResultSuccess_t device_config_save(void)
{
    UINT8 *p_config = (UINT8*) &g_CONFIG;
    UINT8 checksum;
    UINT8 retries=3;
    ResultError_t result =  RESULT_FAIL;
    /*count crc for config*/

    checksum = device_config_checksum(&p_config[1], CONFIG_SIZE - 1);
    g_CONFIG.checksum = checksum;

    while(retries--){
     result = eeprom_write_data(DEVICE_CONFIG_EEPROM_ADDR
                                , p_config, CONFIG_SIZE,EEPROM_BY_BYTE);
     if( result == RESULT_NO_ERROR){
        result= RESULT_SUCCESS;
     }
    }
   return result;
}

/* ********************************************************************* 
  @Function name:  device_config_load
  @Return: (ResultSuccess_t) 
  @Parameters: 
        void
  @Description: EEPROM config load
 
 ********************************************************************* */
ResultSuccess_t device_config_load(void) {
    UINT8 *p_config = (UINT8*) & g_CONFIG;    
    UINT8 checksum;
    UINT8 retries=3;
    ResultError_t result =  RESULT_FAIL;
    while(retries--){
        result =   eeprom_read_data(DEVICE_CONFIG_EEPROM_ADDR
                                    , p_config, CONFIG_SIZE, EEPROM_BY_BYTE);
        checksum = device_config_checksum(&p_config[1], CONFIG_SIZE - 1);
        if (result == RESULT_NO_ERROR && g_CONFIG.checksum == checksum) {
            result= RESULT_SUCCESS;
        }
    }
    return result;
}

/* ********************************************************************* 
  @Function name:  device_config_set_default
  @Return: (void) 
  @Parameters: 
	void 
  @Description: Setting default values to config
 
 ********************************************************************* */
void device_config_set_default(void){
   // g_CONFIG = default_config;
}


/* ********************************************************************* 
  @Function name:  device_config_is_locked
  @Return: (inline BOOL ) 
  @Parameters: 
	void 
  @Description: device config is locked
 
 ********************************************************************* */
 BOOL  device_config_is_locked(void)
{
#if  USE_PASSWORD_LOCK == 1
    return locked;
#else
    return FALSE;
#endif
}


/* ********************************************************************* 
  @Function name:  device_config_lock
  @Return: (void) 
  @Parameters: 
	void 
  @Description: lock device for config write
 
 ********************************************************************* */
void device_config_lock(void)
{
    locked = TRUE;
}


/* ********************************************************************* 
  @Function name:  device_config_unlock
  @Return: (void) 
  @Parameters: 
	UINT32 password 
  @Description: unlock device for write config
 
 ********************************************************************* */
void device_config_unlock(CHAR* pstrpsw)
{
//    if(password == DEVICE_PSW){
//    /*TODO* check password and unlockcontrolPSW(code);*/
//        locked = FALSE;
//    }
//    else {
//        locked = TRUE;
//    }
}


/* *********************************************************************
  @Function name:  device_config_apply
  @Return: (ResultSuccess_t )
  @Parameters:
	void
  @Description: EEPROM apply config

 ********************************************************************* */
ResultSuccess_t  device_config_apply(void)
{
    ResultSuccess_t result =RESULT_FAIL;
    
//    do{
//        if(g_CONFIG.ProfileN >= PROFILES_COUNT) break;
//        if(g_CONFIG.DiscretizationFrequency > 50 ) break;        
//        if(g_CONFIG.DiSensLevel >100) break;        
//        if(detection_config_apply() == FALSE  ) break;
//        result = RESULT_SUCCESS;
//    }while(0);

    return result;
}

UINT8 device_config_checksum(UINT8 *pdata, UINT8 size)
{
    return 0;
}