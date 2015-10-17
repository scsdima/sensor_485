
#include "delay.h"

volatile UINT16 this_delay_timer_ms;




/********************************************************************** 
  @Function name: delay_ms
  @Return: ( void ) 
  @Parameters: 
             
	UINT16 delay 
  @Description:  delay to wait
**********************************************************************/
void delay_ms(UINT16 delay)
{
  this_delay_timer_ms = delay;
  while(this_delay_timer_ms) {};
}


/********************************************************************** 
  @Function name: delay_timeout_set
  @Return: ( void ) 
  @Parameters: 
             
	UINT16 delay 
  @Description:  timeout set
**********************************************************************/
void delay_timeout_set(UINT16 delay)
{
  this_delay_timer_ms = delay;
}


/********************************************************************** 
  @Function name: delay_timeout
  @Return: ( inline ) 
  @Parameters: 
             
	void 
  @Description: delay timeout occurs
**********************************************************************/
inline BOOL delay_timeout(void)
{
  return (this_delay_timer_ms == 0u);
}


/********************************************************************** 
  @Function name: delay_service
  @Return: ( INTERRUPT_SERVICE ) 
  @Parameters: 
             
	void 
  @Description: this is service which need to be placed to interrupt
**********************************************************************/
void delay_interrupt_service(void){
  if(this_delay_timer_ms > 0u) {
    this_delay_timer_ms--;
  }
}