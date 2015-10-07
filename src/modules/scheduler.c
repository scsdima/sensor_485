/**********************************************************************


@File:events.c

@Description: Events interface functions


**********************************************************************/

#include "scheduler.h"


volatile Event_t eventPool;

typedef struct{
  UINT8 missCount;
  UINT16 timeout;
  EventFunctionPtr_t pEventFunc;
  EventDataPtr_t pEventData;
}scheduler_event_t;

PRIVATE scheduler_event_t event_list[EVENT_RESOLUTION];


  UINT8   this_get_next(void);
  BOOL    this_execute_event(UINT8 event_number);


/********************************************************************** 
@Function name:  event_setup
@Return: (ResultError_t) 
@Parameters: 
    UINT8 event_number
    EventFunctionPtr_t*pevent_func function pointer for this event or job
@Description: this function makes setup for event with number  
and pointer to function
 
**********************************************************************/

ResultError_t scheduler_event_setup(UINT8 event_number, EventFunctionPtr_t pevent_func){
  ResultError_t result =  RESULT_ERROR;  
  if(event_number <EVENT_RESOLUTION && pevent_func != NULL ){
    event_list[event_number].pEventFunc = pevent_func;
    event_list[event_number].pEventData = NULL;    
    result = RESULT_NO_ERROR;
  }
  return result;
}


/********************************************************************** 
@Function name:  event_get_next
@Return: (UINT8) number of event 0..31
@Parameters: 
  void 
@Description: gets next event to execute
              This finds higher priority event 
              the
**********************************************************************/
#include "stdio.h"
UINT8 this_get_next(void) {
  UINT8 event_index;
  UINT8 result_event = 0;  
  BOOL found;
  Event_t mask = (Event_t)1u;
  /* finding priority task*/
  for(found = FALSE,event_index=0; event_index < EVENT_RESOLUTION; event_index++) {
  
    if( (event_list[event_index].timeout == 0) && ((mask & eventPool) == mask) ) {      
      if(found == FALSE) {
        found = TRUE;
        result_event = event_index;
      }else{
        /* set miss for other tasks*/
        event_list[event_index].missCount++;    
        /* find task with lots miss*/  
        if(event_list[event_index].missCount > event_index) { 
          result_event = event_index;          
          break;
        }
      }        
    }
    mask <<= 1;
  }      
  return result_event;
}


/**********************************************************************
@Function name:  event_set
@Return: (void)
@Parameters:
	   UINT8 event_number
     void* pevent_data - data structure for event
@Description: Sets event data and event push to pool

**********************************************************************/
void scheduler_event_push(UINT8 event_number, UINT16 timeout, void*pevent_data){
  if(event_number <EVENT_RESOLUTION ){
    eventPool |= (1<<event_number);
    event_list[event_number].timeout = timeout;
    event_list[event_number].missCount =0;
    if(pevent_data!= NULL){
     event_list[event_number].pEventData = pevent_data;
   }
 }
}


/**********************************************************************
@Function name:  
@Return: void
@Parameters:
            UINT8 event_number
@Description: clears event data and avent from pull

**********************************************************************/
void scheduler_event_clear(UINT8 event_number){
  if(event_number <EVENT_RESOLUTION ){
    eventPool &= ~(1<<event_number);
    event_list[event_number].pEventData = NULL;
    event_list[event_number].missCount = 0;
  }
}


/**********************************************************************
@Function name:
@Return: BOOL - true is empty
@Parameters:
            void
@Description: Check if event is empty

**********************************************************************/
BOOL scheduler_empty(void)
{
  return (BOOL)(eventPool == 0);
}


/**********************************************************************
@Function name:
@Return: BOOL false if event has no data
@Parameters:
            UINT8 event_number
            void**ppevent_data - event data will be returned here
@Description: check if event has dtaa and returns data to ppevent_data

**********************************************************************/
BOOL    scheduler_event_get_data(UINT8 event_number,void**ppevent_data){
  if (event_number <EVENT_RESOLUTION  && event_list[event_number].pEventData != NULL){
   *ppevent_data = event_list[event_number].pEventData;
   return TRUE;
 }
 return FALSE;
}


/********************************************************************** 
@Function name:  this_execute_event
@Return: (static BOOL) 
@Parameters: 
  Event_t evtask 
@Description: Executing next event
 
**********************************************************************/
BOOL this_execute_event(UINT8 event_number) {
  if(event_number < EVENT_RESOLUTION  && event_list[event_number].pEventFunc != NULL){
    EventFunctionPtr_t pfunc = event_list[event_number].pEventFunc;
    (pfunc)(event_number);
  }else{
    return FALSE;
  }    
  return TRUE;
}


/********************************************************************** 
@Function name:  event_process
@Return: (void) 
@Parameters: 
        void 
@Description: main procedure (scheduler)
 
**********************************************************************/
void scheduler_process(void) {
  UINT8 next_event_number;
  if (scheduler_empty() == FALSE) {            
        next_event_number = this_get_next(); //geting next priority event
        this_execute_event(next_event_number);
        scheduler_event_clear(next_event_number);
      }
    }

/********************************************************************** 
@Function name:  scheduler service
@Return: (void) 
@Parameters: 
        void 
@Description: scheduler service . 
Use this for delaying more priority tasks. 1ms timer
 
**********************************************************************/

void  scheduler_service(void ) {
  UINT8 i;
  for(i=0;i<EVENT_RESOLUTION;i++){
    if(event_list[i].timeout >0 ) {
      event_list[i].timeout --;
    }
  }
}