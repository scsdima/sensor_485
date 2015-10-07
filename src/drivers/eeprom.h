#ifndef EEPROM_H
#define EEPROM_H

#include "compiler.h"
#include "typedef_global.h"

#define EEPROM_ADDR (0b10100000)

typedef enum {EEPROM_BY_BLOCK,EEPROM_BY_BYTE} EepromReadMode_t;

void eeprom_lock(void);

void eeprom_unlock(void);

ResultError_t eeprom_write_byte(UINT16 addr,UINT8 byte);

ResultError_t eeprom_read_byte(UINT16 addr,UINT8 *byte);

ResultError_t eeprom_write_data(UINT16 addr,const UINT8 *data,UINT16 len, EepromReadMode_t mode);

ResultError_t eeprom_read_data(UINT16 addr, UINT8 *data, UINT16 len, EepromReadMode_t mode) ;


#endif