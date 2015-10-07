/**********************************************************************

  @File:scheduler.h
 
  @Description: $d
 
**********************************************************************/


#ifndef EVENTS_H
#define EVENTS_H
#include "compiler.h"
#include "typedef_global.h"

#define __EVENT_NAME__(v) sch_event_##v
#define __SCHEDULER_EVENT__(v)  void __EVENT_NAME__(v)(UINT8 argn)

typedef void (*EventFunctionPtr_t)(UINT8);    
typedef void* EventDataPtr_t;    
typedef UINT8          Event_t;//this is event type

#define EVENT_RESOLUTION    (8*sizeof(Event_t))


ResultError_t scheduler_event_setup(UINT8 event_number,EventFunctionPtr_t pevent_func);
void    scheduler_event_clear(UINT8 event_number);
BOOL    scheduler_empty(void);
void    scheduler_event_push(UINT8 event_number, UINT16 timeout,void *pevent_data);
BOOL    scheduler_event_get_data(UINT8 event_number,void **ppevent_data);
void    scheduler_process(void);

#endif