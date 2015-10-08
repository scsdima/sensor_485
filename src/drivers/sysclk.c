#include "sysclk.h"
#include "compiler.h"

static IntOscFrequency_t this_freq;

void sysclk_init(void)
{
        sysclk_setup_intosc(INTOSC_4MHZ);
}

void sysclk_setup_intosc(IntOscFrequency_t frequency)
{
	OSCCON &= ~(0x07<<4);
	OSCCON |= frequency<<4;
}

IntOscFrequency_t sysclk_intosc(void)
{
	return this_freq;
}