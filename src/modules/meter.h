#ifndef METER_H
#define METER_H
#include "compiler.h"
#include "typedef_global.h"

typedef enum {
 	SIGNAL,
 	IMPEDANCE,
 	POWER,
	METERS_COUNT
}MeterEnum_t;

BOOL meter_measure(MeterEnum_t meter_number );
UINT16 meter_get_raw(MeterEnum_t meter_number );
FLOAT meter_get_voltage(MeterEnum_t meter_number);
FLOAT meter_to_raw(UINT16 value);
UINT16 meter_to_voltage(UINT16 value);

#endif