/* *********************************************************************


  @File:detection.c

  @Project: MAMBA2
  @Date: 2013\06\26 09-52-27
  @Description: detection module


 
 ********************************************************************* */


#include "detection.h"
#include "peak_detector.h"
#include "classic_detector.h"
#include "memory_register_map.h"

volatile BOOL   this_warning;
volatile BOOL   this_alarm;


PeakDetector_t    pd_detector;
ClassicDetector_t   cla_detector;


/* *********************************************************************
  @Function name:  detection_get_zero
  @Return: (UINT32) Detection get zero
  @Parameters:
	void
  @Description: algoritm(s) return warning state

 ********************************************************************* */
BOOL detection_is_warning(void){
    return this_warning;
}

/* *********************************************************************
  @Function name:  detection_get_zero
  @Return: (UINT32) Detection get zero
  @Parameters:
	void
  @Description: algoritm(s) return alarm state

 ********************************************************************* */
  BOOL detection_is_alarm(void) {
    return this_alarm;
}

/* ********************************************************************* 
  @Function name:  detection_init
  @Return: (void) 
  @Parameters: 
	void 
  @Description: Detection init
 
 ********************************************************************* */
void detection_init(void) {
    pd_init(&pd_detector);
    cla_init(&cla_detector);
}

/* ********************************************************************* 
  @Function name:  detection_config_apply
  @Return: (void) 
  @Parameters: 
	void 
  @Description: Detection config
 
 ********************************************************************* */
BOOL detection_config_apply(void) {
//    pd_detector.config = g_CONFIG.pd_config;
//    cla_detector.config = g_CONFIG.cla_config;       
    return TRUE;
}

/* ********************************************************************* 
  @Function name:  detection_detect
  @Return: (BOOL)     
              Resturns 1 if alarm and 0 if no alarm
  @Parameters: 
	UINT16 new_value 
  @Description: Detction processing function
 
 ********************************************************************* */
BOOL detection_detect(void)
{
    static BOOL alarm_cla;
    static BOOL alarm_wav;
    INT24  zero;

    alarm_wav = (BOOL)pd_add_value(&pd_detector, (INT24)g_analog0);
    zero = pd_detector.ref_v;/* refference zero value*/
    alarm_cla = (BOOL)cla_add_value(&cla_detector, (INT24)g_analog0, zero);
    this_warning = cla_detector.status.over_trig;

   switch (g_CONFIG.det_mode)
   {
       /*
        * Classical  detection mode
        */
   case DETECTION_MODE_OFF :
       this_alarm = FALSE;
       break;

   case DETECTION_MODE_CLA:                
       ///*D*/   printf("\ncalassic val:%d zero:%d cur_v:%d",new_value,this_zero,g_classicdetector.cur_v);
       this_alarm = alarm_cla;
       break;
       
       /*
        * vavelet function
        */
   case DETECTION_MODE_PEAK:        
       ///*D*/   printf("\nwavelet: val:%d zero:%d cur_v:%d",new_value,this_zero,g_videodetector.avlv);
       this_alarm= alarm_wav;
       break;
       
   default:
       this_alarm = FALSE;
       break;

   }//switch    
    return this_alarm;
}

/* *********************************************************************
  @Function name:  detection_get_zero
  @Return: (INT24) Detection get zero
  @Parameters:
	void
  @Description: detection get zero

 ********************************************************************* */

 INT24   detection_get_zero(void){
    return pd_detector.ref_v;
}

