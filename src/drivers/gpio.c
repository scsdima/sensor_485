#include "gpio.h"

void gpio_init()
{

		//gpio
	TRISA=0xff;
	TRISB=0xff;
	ANSELH=0;	
	TRISC=0xc1;
	TRISD=0x00;
	LATC=0;
	LATD=0;			
}