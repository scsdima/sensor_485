#include "typedef_global.h"
#include "compiler.h"
#include "memory_register_map.h"


 BOOL potentiometer_init();
 BOOL potentiometer_set(UINT8 value);
 #define potentiometer_value() 	(g_CONFIG.potentiometer)