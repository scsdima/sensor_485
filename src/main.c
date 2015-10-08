/* *********************************************************************


  @File:main.c

  @Project: MAMBA3
  @Date: 2013\06\26 10-13-11

 ********************************************************************* */



#include "config.h"
#include "compiler.h"
#include "typedef_global.h"
#include "startup.h"
#include "scheduler.h"
#include "delay.h"


int main(void) 
{
	
	startup();
	//TRISD=0;
	//TRISC=0;
	//LATD=0xff;
	//LATC=0xff;
	PIN_LED_ALARM=1;
	PIN_LED_TAMPER=1;
	while(1);
    while(startup() != RESULT_SUCCESS)
    {
	    
      delay_ms(1000);
    };
    while(1) 
    {        
            scheduler_process();
           CLRWDT();
    }    
}
