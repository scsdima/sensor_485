#ifndef ADC_H
#define ADC_H
#include "compiler.h"
#include "typedef_global.h"

void adc_init(void);

UINT16 adc_read(UINT8 adc_number);


#endif