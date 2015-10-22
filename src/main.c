    
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

char tmp[20];

int main(void) 
{
    while(startup() != RESULT_SUCCESS)
    {    
      delay_ms(1000);
    };

	  int_enable(1);



// while(1){
//       sprintf(tmp,"%d %d %d\n",adc_read(ADC0),adc_read(ADC1),adc_read(ADC2));
//       uart_puts(tmp,10);
//       CLRWDT();
//   }

    while(1) 
    {        	           
	   PROCESS_EVENTS();
        CLRWDT();
    }    
}
