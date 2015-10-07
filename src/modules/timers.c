/**********************************************************************

  @File:timers.c
  @Description: Timers is module which has 10 position table with timers
  each timer has shot periodically or single shot.
  on call back function of timer use shortest command
 
**********************************************************************/

#include "timers.h"
#include "compiler.h"


typedef volatile struct 
{
/*private*/
  BOOL   shot;
  UINT16  timer;
/*public*/
  UINT8   option;
  UINT16  interval;
  TimerCallbackPtr_t callback_function;
} DelayTimer_t;


static DelayTimer_t timers_list[TIMERS_COUNT];


void timers_init(void)
{
  // TODO
}

// starts timer
void timers_start(UINT8 timer_n, UINT8 option) 
{
  timers_list[timer_n].timer = timers_list[timer_n].interval;
  timers_list[timer_n].option = option;
}


/* ********************************************************************* 
@Function name:  delay_timer_service
@Return: inline void 
@Parameters: 
void 
@Description: this function needs to be placed to interrupt
lookup timer in list and set shot to

********************************************************************* */
void timers_interrupt_service(void) 
{  
  UINT8 timer_n;
  for (timer_n = 0u; timer_n < TIMERS_COUNT; timer_n++) {
    if ((timers_list[timer_n].option & TIMER_RUN) == 0u) {
      continue;
    }

    if (timers_list[timer_n].timer == 0u) {
      timers_list[timer_n].shot = TRUE;            
      
	  if (timers_list[timer_n].callback_function != NULL) {
		timers_list[timer_n].callback_function();
       }
      if ((timers_list[timer_n].option & TIMER_SINGLESHOT) == TIMER_SINGLESHOT){
        timers_list[timer_n].option &= ~TIMER_RUN;
      }
/*restart interval*/
      timers_list[timer_n].timer = timers_list[timer_n].interval;
    } else {
      timers_list[timer_n].timer--;
    }
  }  
}
/* ********************************************************************* 
@Function name:  timer_setup
@Return: bool
@Parameters: 
uint32_t timer_n -- timer number
uint32_t interval -- timer interval
TimerCallback_t callback_function  -- function which will be called 
                            after timer timeout
@Description: setup of timer with numer timer_n

********************************************************************* */
BOOL timers_setup(UINT8 timer_n, UINT16 interval, TimerCallbackPtr_t pcallback_function){
  if(pcallback_function != NULL){
    timers_list[timer_n].interval = interval;
    timers_list[timer_n].callback_function = pcallback_function;
    return TRUE;
  }
  else {
    return FALSE;
  }
}

/* ********************************************************************* 
@Function name:  timer_change_interval
@Return: void
@Parameters: 
uint32_t timer_n
uint32_t interval 
@Description: Timer change interval

********************************************************************* */
void timers_change_interval(UINT8 timer_n, UINT16 interval)
{
  timers_list[timer_n].interval= interval;
}


