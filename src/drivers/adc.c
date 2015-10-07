#include "adc.h"    
#include "compiler.h"        

void adc_init(void)
{
	ADCON0	=	0b00000000;
	ADCON1	=	0b00000000;
	ADCON2	=	0b10111000;
    ANSEL   =   0b01100011; //analog ports ANS5 ANS6 ANS0 ANS1
    ANS9 = 0;
    ANSELH  =   0;
}

UINT16 adc_read(UINT8 adc_number )
{
    if(ADCON0bits.CHS != adc_number)
    {
        ADCON0 = 0b10000001 | (adc_number << 2);
    }
    GODONE = 1;
    while (GODONE) NOP();
    ADIF = 0;
    return ADRES;
}


  
