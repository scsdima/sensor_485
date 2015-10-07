
#include "compiler.h"
#include "timers.h"
#include "delay.h"


 interrupt static void isr_high(void) 
 {
// /*Interrupts*/
// 
//    /*
//     * Timer 0
//     */
    if (INTCONbits.TMR0IF && INTCONbits.TMR0IE) //timer for signal
    {    
        TMR0 = -500;/*1 ms 16 mHz divider 8*/
        TMR0IF = 0;

        delay_interrupt_service(); //dont touch it, this is a macro for delay
//        timers_interrupt_service();
    } /*Timer 0 end*/
//
    /*
     * UART
     */
     //if(UART)
     {
     	// TODO add char to buffer	
         
     }
//
//     /* 
//      * ADC
//      */
//      if(ADC)
//      {
//      	// TODO ADC measure	
//      }
//
 }