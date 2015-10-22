#include "potentiometer.h"
#include "config.h"


BOOL potentiometer_init()
{
	return TRUE;
}

BOOL potentiometer_set(UINT8 value)
{
	if (value < 16) {
		SET_TRIMMER(value);
		g_CONFIG.potentiometer = value;
		return TRUE;
	}
	return FALSE;
}