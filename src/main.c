
#include "config.h"
#include "compiler.h"
#include "typedef_global.h"
#include "startup.h"
#include "delay.h"

#include "uart.h"

#include "interrupts.c"
#include "scheduler.h"

int main(void) 
{
    while(startup() != RESULT_SUCCESS)
    {    
      delay_ms(1000);
    };
	  int_enable(1);
    while(1) 
    {        	    ;
	   PROCESS_EVENTS();
     CLRWDT();
    }    
}
