
#ifndef DEVICE_CONFIG_H
#define	DEVICE_CONFIG_H

#include "compiler.h"
#include "typedef_global.h"
#include "eeprom.h"

#define DEVICE_CONFIG_EEPROM_ADDR (0x0000)


ResultSuccess_t device_config_load(void);
ResultSuccess_t device_config_save(void);
ResultSuccess_t device_config_apply(void);

void    device_config_set_default(void);
BOOL    device_config_is_locked(void);
void    device_config_lock(void);
void  device_config_unlock(CHAR *pstrpsw);
UINT8 device_config_checksum(UINT8 *pdata, UINT8 size);

#endif	/* DEVICE_CONFIG_H */

