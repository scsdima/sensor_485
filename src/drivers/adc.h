#ifndef ADC_H
#define ADC_H
#include "compiler.h"
#include "typedef_global.h"

#define ADC0 	0
#define ADC1 	1
#define ADC2 	5
#define ADC3 	6


void adc_init(void);

UINT8 adc_read(UINT8 adc_number);
void adc_enable(BOOL on);

#endif