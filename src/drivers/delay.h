#ifndef DELAY_H
#define DELAY_H

#include "compiler.h"
#include "config.h"
#include "typedef_global.h"

extern volatile UINT16 this_delay_timerMs;
extern volatile UINT16 this_delay_timerUs;

/*Delay routines*/
void delay_ms(UINT16 delay);
void delay_timeout_set(UINT16 delay);
inline BOOL delay_timeout(void);


void delay_interrupt_service(void);

#endif

