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


/* ********************************************************************* 
  @Function name:  main
 
 ********************************************************************* */
int main(void) 
{
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
