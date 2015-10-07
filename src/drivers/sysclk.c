#include "sysclk.h"
#include "compiler.h"


void sysclk_init(void)
{
        sysclk_setup_intosc(INTOSC_4MHZ);
}

void sysclk_setup_intosc(IntOscFrequency_t frequency)
{
	OSCCON &= ~(0x07<<4);
	OSCCON |= frequency<<4;
}
