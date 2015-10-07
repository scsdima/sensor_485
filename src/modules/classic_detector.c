/* *********************************************************************


  @File:classic_detector.c

  @Project: MAMBA2
  @Date: 2013\06\26 09-52-27
  @Description: calassic detector  algoritm


 
 ********************************************************************* */


#include "classic_detector.h"


/* ********************************************************************* 
  @Function name:  ccInit
  @Return: (    void) 
  @Parameters: 
	ClassicDetector_t *d 
  @Description: initialization of detector
 
 ********************************************************************* */
  void ccInit(ClassicDetector_t *d)
  {
    d->sig_count=0;
    d->sig_sum=0;
    d->status.over_trig=0;
    d->status.alarm=0;
  }

/* ********************************************************************* 
  @Function name:  ccAddNewValue
  @Return: (    BOOL) - alarm = 1 
  @Parameters: 
  	ClassicDetector_t *d
  	INT16 val
  	INT16 zero 
  @Description: adds new value to algoritm
 
 ********************************************************************* */
  BOOL ccAddNewValue(ClassicDetector_t *d,INT16 val,INT16 zero)
  {
        d->cur_v = ABS(val- zero); //making from - to +        
        d->over_trig_value = (d->cur_v > d->config.sig_trig) ? (d->cur_v - d->config.sig_trig):0;
        if (d->status.over_trig)
        {
          d->sig_count++;
          d->sig_sum += d->over_trig_value;
          if (d->sig_sum > d->config.sig_sum_trig && d->status.alarm == FALSE)
          {
            d->status.over_trig = FALSE;
            d->status.alarm=TRUE;
            d->last_sig_count = d->sig_count;
            d->last_sig_sum = d->sig_sum;
            d->sig_count = 0;
            d->sig_sum = 0;
            return TRUE;
          }
                 /* if signal count exceeds limit reset counting*/
          if (d->sig_count > d->config.sig_max_count)
          {
            d->status.over_trig = FALSE;
            d->status.alarm = FALSE;
          }
        }

            /* start signal sum calculating*/
            else if (d->over_trig_value > d->config.sig_trig) //start calculating
            {
              d->status.over_trig = TRUE;
              d->status.alarm = FALSE;
              d->last_sig_count = 0;
              d->last_sig_sum = 0;
              d->sig_count = 0;
              d->sig_sum = 0;                        
            }
            return FALSE;
          }


/* ********************************************************************* 
  @Function name:  cc_setup
  @Return: (    void) 
  @Parameters: 
  	ClassicDetector_t *d
  	UINT16 trig
  	UINT16 trig_sum
  	UINT16 trig_window 
  @Description: classic detection setup
 
 ********************************************************************* */
  void cc_setup(ClassicDetector_t *d,UINT16 trig,UINT16 trig_sum,UINT16 trig_window)
  {
    d->config.sig_trig = trig;
    d->config.sig_sum_trig = (trig_sum > SIGNAL_SUM_MINIMUM)? 
    trig_sum
    :SIGNAL_SUM_MINIMUM;
    d->config.sig_max_count = (trig_window > SIGNAL_CNT_MINIMUM) ?
    trig_window
    :SIGNAL_CNT_MINIMUM;
  }


/* ********************************************************************* 
  @Function name:  cc_result
  @Return: (    UINT16) 
  @Parameters: 
  	ClassicDetector_t*d
  	UINT16 *value
  	UINT16 *time 
  @Description: returns result data from detection algoritm
 
 ********************************************************************* */
void cc_result(ClassicDetector_t*d,UINT16 *value,UINT16 *time)
  {
    *value=d->sig_sum;
    *time=d->sig_count;
  }