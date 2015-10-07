#ifndef SYSCLK_H
#define SYSCLK_H

typedef enum 
{
	INTOSC_32KHZ=0,
	INTOSC_250KHZ,
	INTOSC_500KHZ,
	INTOSC_1MHZ,
	INTOSC_2MHZ,
	INTOSC_4MHZ,
	INTOSC_8MHZ,
	INTOSC_16MHZ,
	INTOSC_COUNT
}IntOscFrequency_t;

void sysclk_init(void);

void sysclk_setup_intosc(IntOscFrequency_t frequency);


#endif