
#include "compiler.h"
#include "timers.h"
#include "delay.h"
#include "serialport.h"

#define int_enable(V) do{INTCONbits.GIEH=(V); INTCONbits.GIEL=(V);}while(0);

//Timer 1 ms
#define INT_TIMER_1MS_FLAG (INTCONbits.TMR0IF)
#define INT_TIMER_1MS_CLEAR do{INTCONbits.TMR0IF=0;TMR0 = -500; }while(0);

interrupt static void isr_high(void) 
 {

    if (INT_TIMER_1MS_FLAG ) //timer for signal
    {                   
        delay_interrupt_service(); //dont touch it, this is a macro for delay
//        timers_interrupt_service();
	INT_TIMER_1MS_CLEAR;
    } /*Timer 0 end*/

     if(PIR1bits.RCIF)
     {
     	// TODO add char to buffer	
        serialport_service(); 
	PIR1bits.RCIF = 0;
     }

    /* 
     * ADC
     */
     // if(ADC)
     // {
     // 	// TODO ADC measure	
     // }

 }