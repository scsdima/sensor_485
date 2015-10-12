#include "adc.h"    
#include "compiler.h"        

void adc_init(void)
{
	ADCON0	=	0b00000001;// enabled
	ADCON1	=	0b00000000;// reference vdd ,vss
	ADCON2	=	0b00010110;// left aligned , Fosc/64,4Tad
    ANSEL   =   0b01100011; //analog ports ANS5 ANS6 ANS0 ANS1
    ANSELH  = 0;
    PIE1bits.ADIE = 1;
   // IPR1bits.ADIP =1;

void adc_enable(BOOL on)
{
    ADCON0 &= ~1;
    ADCON0 |= (UINT8)on;
}

UINT16  adc_read(UINT8 adc_number )
{    
    if(ADCON0bits.CHS != adc_number)
    {
        ADCON0bits.CHS = adc_number;
        NOP();NOP();NOP();NOP();NOP();NOP();NOP();
    }
    ADCON0bits.GO_nDONE = TRUE;
    while (GODONE) {NOP();NOP();}
    ADIF = FALSE;
    return ADRES;
}


  
