

#ifndef EVENTS_H
#define EVENTS_H
#include "compiler.h"
#include "typedef_global.h"

typedef void (*PEVENT)(void); 


extern volatile  UINT8 pool;
extern volatile PEVENT events[8];
extern volatile UINT8 current_event;


volatile  UINT8 pool;
volatile PEVENT events[8];
volatile UINT8 current_event;

#define setup_event(N,FUNC) events[N] = FUNC

#define issue_event(N) pool |= 1<<N

#define clear_event(N) pool &= ~(1<<N)

#define PROCESS_EVENTS() \
do{\
if(pool&(1<<current_event) && events[current_event]!= NULL){\
    events[current_event]();\
	}\
    clear_event(current_event);\
	current_event++;\
	current_event %= 8;\
}while(0);

#endif