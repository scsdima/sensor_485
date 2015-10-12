

#ifndef EVENTS_H
#define EVENTS_H
#include "compiler.h"
#include "typedef_global.h"

typedef void (*PEVENT)(void); 


extern volatile  UINT8 pool[8];
extern volatile PEVENT events[8];
extern volatile UINT8 event_miss[8];

volatile UINT8 pool[8];
volatile PEVENT events[8];
volatile UINT8 event_miss[8];

#define MISS_COUNTER 		(10)


#define setup_event(N,FUNC) events[N] = FUNC

#define issue_event(N) do{pool[N] = 1;event_miss[N]= MISS_COUNTER;}while(0)

#define clear_event(N) pool[N]=0;

#define PROCESS_EVENTS() \
do{\
	INT8 event_old=-1;\
	INT8 event_priority=-1;\
	UINT8 i;\
	for(i=0;i<8;i++)\
	{\
		if(pool[i]==1)\
			{\
			if(event_miss[i] == 0 )\
		 		event_old=i;\
		 	else event_miss[i]--;\
		 	if(event_priority<0) event_priority=i;\
		 	}\
	}\
	if(event_old >= 0)	{\
        events[event_old]();\
        clear_event(event_old);\
    }\
	else if(event_priority >= 0) {\
        events[event_priority]();\
        clear_event(event_priority);\
    }\
}while(0);

#endif