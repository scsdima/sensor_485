
#include "config.h"
#include "compiler.h"
#include "typedef_global.h"
#include "startup.h"
#include "delay.h"

#include "uart.h"

#include "interrupts.c"
#include "scheduler.h"
#include "stdlib.h"
#include "stdio.h"

#include "string_utils.h"
char tmp[10];
int main(void) 
{
    while(startup() != RESULT_SUCCESS)
    {    
      delay_ms(1000);
    };
        sprintf(tmp,"\n%d",string_utils_atoi("1"));
        uart_puts(tmp,100);
	  int_enable(1);
    while(1) 
    {        	    ;
	   PROCESS_EVENTS();
     CLRWDT();
    }    
}
