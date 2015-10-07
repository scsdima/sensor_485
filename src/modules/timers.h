/**********************************************************************

  @File:timers.h
 
**********************************************************************/


#ifndef TIMERS_H
#define TIMERS_H
#include "compiler.h"
#include "typedef_global.h"

#define TIMERS_COUNT    (10u)

#define __TIMER_NAME__(v) timer_##v
#define __TIMER_EVENT__(v)  void __TIMER_NAME__(v)(void)

typedef void(*TimerCallbackPtr_t)(void) ;

typedef enum {
    TIMER_RUN = 1,
    TIMER_SINGLESHOT = 3
} DelayTimerState_t;

void timers_init(void);
BOOL timers_setup(UINT8 timer_n, UINT16 interval, TimerCallbackPtr_t pcallback_function);
void timers_change_interval(UINT8 timer_n, UINT16 interval);
void timers_start(UINT8 timer_n, UINT8 option);
void timers_interrupt_service(void) ;


#endif