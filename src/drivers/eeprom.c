

#include "eeprom.h"
#include "i2c.h"
#include "delay.h"

/* ********************************************************************* 
  @Function name:  eeprom_lock
  @Return: (void) 
  @Parameters: 
        void
  @Description: lock eeprom for write
 
 ********************************************************************* */
void eeprom_lock(void) {
//    Nop();
//    Nop();
//    Nop();
//    Nop();
//    PIN_EEPROM_WRITE_PROTECT = 0;
}

/* ********************************************************************* 
  @Function name:  eeprom_unlock
  @Return: (void) 
  @Parameters: 
        void
  @Description: unlock eeprom for write
 
 ********************************************************************* */
void eeprom_unlock(void) {
//    PIN_EEPROM_WRITE_PROTECT = 1;
//    Nop();
//    Nop();
//    Nop();
//    Nop();
}

/* ********************************************************************* 
  @Function name:  eeprom_write_byte
  @Return: (ResultError_t) 
  @Parameters: 
        UINT16 addr - address in eeprom
        UINT8 byte - byte to write
  @Description: Writes byte to eeprom
 
 ********************************************************************* */
ResultError_t eeprom_write_byte(UINT16 addr, UINT8 byte) {
    ResultError_t result = RESULT_NO_ERROR;
//    SWRestartI2C1();
//    //SWStartI2C1();
//    result |= SWWriteI2C1(EEPROM_ADDR);
//    result |= SWWriteI2C1((UINT8) addr);
//    result |= SWWriteI2C1(byte);
//    SWStopI2C1();
    return result;
}

/* ********************************************************************* 
  @Function name:  eeprom_write_data
  @Return: (ResultError_t) 
  @Parameters: 
        UINT16 addr - address
        UINT8 *data - data pointer
        UINT8 len - length of data
        EepromReadMode_t mode - mode by block /by byte
  @Description: Writes data by block
 
 ********************************************************************* */
ResultError_t eeprom_write_data(UINT16 addr, const UINT8 *data, UINT16 len, EepromReadMode_t mode) {
//#define EEPROM_WRITE_BLOCK (4)
//    
    ResultError_t result = RESULT_NO_ERROR;
//
//    switch (mode) {
//        case EEPROM_BY_BLOCK:
//        {
//            UINT16 i = 0;
//            while (len--) {                
//                SWStartI2C1();
//                result |= SWWriteI2C1(EEPROM_ADDR);
//                result |= SWWriteI2C1((UINT8) addr);
//                for (i = 0; i < EEPROM_WRITE_BLOCK; i++) {
//                    result |= SWWriteI2C1(*data);
//                    if (len == 0) {
//                        break;
//                    }
//                    data++;
//                }                
//                addr += EEPROM_WRITE_BLOCK;                
//                delay_ms(5);
//                SWStopI2C1();
//                
//            }
//        }
//            SWStopI2C1();
//            break;
//
//        case EEPROM_BY_BYTE:
//        {
//            while (len--) {
//                delay_ms(10);
//                result |= eeprom_write_byte(addr, *data);                
//                if (result != RESULT_NO_ERROR) {
//                    break;
//                }
//                data++;
//                addr++;
//            }
//        }
//            break;
//
//        default:
//            result = RESULT_ERROR;
//            break;
//    }

    return result;
}

/* ********************************************************************* 
  @Function name:  eeprom_read_byte
  @Return: (ResultError_t) 
  @Parameters: 
        UINT16 addr -  address in eeprom
        UINT8 *byte - byte pointer
  @Description: reads data from eeprom
 
 ********************************************************************* */
ResultError_t eeprom_read_byte(UINT16 addr, UINT8 *byte) {
    ResultError_t result = RESULT_NO_ERROR;
//    SWStartI2C1();
//    result |= SWWriteI2C1(EEPROM_ADDR);
//    result |= SWWriteI2C1(addr);
//    SWRestartI2C1();
//    result |= SWWriteI2C1(EEPROM_ADDR | 1);
//    result |= SWReadI2C1(byte);
//    SWStopI2C1();
    return result;
}

/* *********************************************************************
  @Function name:  eeprom_read_data
  @Return: (ResultError_t)
  @Parameters:
        UINT16 addr -  address in EEPROM
        UINT8 *data - data pointer
        UINT8 len - length of data (256) max
        EepromReadMode_t mode  - read by block or by byte
  @Description: reads data from eeprom

 ********************************************************************* */
ResultError_t eeprom_read_data(UINT16 addr, UINT8 *data, UINT16 len, EepromReadMode_t mode) {
    ResultError_t result = RESULT_NO_ERROR;

//    switch (mode) {
//        case EEPROM_BY_BLOCK:
//        {
//            SWStartI2C1();
//            result |= SWWriteI2C1(EEPROM_ADDR);
//            result |= SWWriteI2C1(addr);
//            SWRestartI2C1();
//            result |= SWWriteI2C1(EEPROM_ADDR | 1);
//            while (len--) {
//                UINT8 byte;
//                result |= SWReadI2C1(&byte);
//
//                if (result != RESULT_NO_ERROR) {
//                    break;
//                }
//                *data = byte;
//                SWSendAckI2C1();
//                data++;
//            }
//        }
//            SWSendNakI2C1();
//            SWStopI2C1();
//            break;
//
//        case EEPROM_BY_BYTE:
//        {
//            while (len--) {
//                result |= eeprom_read_byte(addr, data);
//                if (result != RESULT_NO_ERROR) {
//                    break;
//                }
//                data++;
//                addr++;
//            }
//        }
//            break;
//
//        default:
//            result = RESULT_ERROR;
//            break;
//    }
    return result;
}