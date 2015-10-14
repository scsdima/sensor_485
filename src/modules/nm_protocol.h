/* 
 * File:   standard_protocol.h
 * Author: dmitry
 *
 * Created on June 19, 2013, 7:44 PM
 */

#ifndef NM_PROTOCOL_H
#define	NM_PROTOCOL_H

#include "compiler.h"
#include "typedef_global.h"



#define MAMBA_PROTOCOL_PACKET_SIZE     (8u)
#define MAMBA_PROTOCOL_PREAMBLE       (0xAAu)

typedef enum{
/*READ*/
    FUNC_GET_STATUS         =(0x01u),
    FUNC_GET_POTPOS         =(0x02u),/* get potentiometer position 1,2,3,4,5,6*/
    FUNC_GET_ANA2           =(0x03u),
    FUNC_GET_ANA0           =(0x04u),
    FUNC_GET_ANA1           =(0x05u),
    FUNC_GET_ACCVAL         =(0x06u),
    FUNC_GET_ACCAXIS        =(0x07u),/*not implemetned*/
    FUNC_GET_DEVID          =(0x08u),
    FUNC_GET_LASTERROR      =(0x09u),
    FUNC_GET_ANA0_STATUS    =(0x0Au),
    FUNC_GET_ZERO           =(0x0Bu),
    FUNC_GET_ANA1_STATUS    =(0x0Cu),
    FUNC_GET_WVAL           =(0x0Du),
    FUNC_GET_FWVER          =(0x0Eu),
    FUNC_GET_STREAM         =(0x0Fu), /* not standard*/


    FUNC_GET_POTVAL         =(0x20u), /* get potentiometer value 0..255*/
    FUNC_GET_BAUD           =(0x21u),
    FUNC_GET_DETMODE        =(0x22u), /*Detection mode wav cla*/
    FUNC_GET_ACCSENS        =(0x23u),
    FUNC_GET_PWRTRIG        =(0x24u),
    FUNC_GET_T0DUR          =(0x25u),
    FUNC_GET_T1DUR          =(0x26u),
    FUNC_GET_T2DUR          =(0x27u),
    FUNC_GET_DISENS         =(0x28u),
    FUNC_GET_T1T2CFG        =(0x29u),
    FUNC_GET_DFREQ          =(0x2Au),
    FUNC_GET_PROFILEN       =(0x2Bu),
 /* files */
    FUNC_GET_FILE_DATA      =(0x2Cu),
    FUNC_GET_FILE_LIST      =(0x2Du),
    FUNC_GET_LAST_FILE_DATA =(0x2Eu),

    FUNC_GET_TRIGLEV        =(0x30u),
    FUNC_GET_TRIGSUM     =(0x31u),
    FUNC_GET_TRIGCNT     =(0x32u),
    FUNC_GET_DETRES1        =(0x33u),
    FUNC_GET_DETRES2        =(0x34u),

    FUNC_GET_WAVWTRIG       =(0x40u),
    FUNC_GET_WAVTOLERANCE   =(0x41u),
    FUNC_GET_WAVLVAL        =(0x42u),
    FUNC_GET_WAVRVAL        =(0x43u),
    FUNC_READ               =(0x4Fu),

/*WRITE*/
    FUNC_SET_POTVAL         =(0x50u),
    FUNC_SET_BAUD           =(0x51u),
    FUNC_SET_DETMODE        =(0x52u),
    FUNC_SET_PROFILEN       =(0x5Bu),
    FUNC_SET_ACCSENS        =(0x53u),
    FUNC_SET_DFREQ          =(0x5Au),
    FUNC_SET_PWRTRIG        =(0x54u),
    FUNC_SET_ALARMDUR       =(0x55u),
    FUNC_SET_T1DUR          =(0x56u),
    FUNC_SET_T2DUR          =(0x57u),
    FUNC_SET_DISENS         =(0x58u),
    FUNC_SET_T1T2CFG        =(0x59u),
    FUNC_REMOVE_FILE        =(0x5Fu),
/*classic*/
    FUNC_SET_TRIGLEV     =(0x60u),
    FUNC_SET_TRIGSUM     =(0x61u),
    FUNC_SET_TRIGCNT     =(0x62u),
/*wavelet*/
    FUNC_SET_WAVTRIG       =(0x70u),
    FUNC_SET_WAVTOLE        =(0x71u),
    FUNC_SET_WAVLCNT        =(0x72u),
    FUNC_SET_WAVRCNT        =(0x73u),
    FUNC_WRITE              =(0x8Fu),
/* FUNC*/
    FUNC_LOCK               =(0x90u),
    FUNC_UNLOCK             =(0x91u),
    FUNC_RESET              =(0x92u),
    FUNC_DEFAULTS           =(0x93u),


    FUNC_SET_ID             =(0xFCu), /* secret function set id*/
    FUNC_SET_PSW            =(0xFDu), /* sectret function set psw*/
    FUNC_ACK                =(0xF0u), /* sectret function set psw*/
    FUNC_NAK                =(0xFEu) /* sectret function set psw*/
}StdProtocolCommands_t;

typedef enum{
    STD_PROTOCOL_NO_ERROR,
    STD_PROTOCOL_IGNORE,
    STD_PROTOCOL_PACKET_ERROR
}StdProtocolCommandError_t;

/* mask for options*/
#define   SP_OPTION_ANSWER  (0x80u)
#define   SP_OPTION_STREAM  (0x40u)
#define   SP_ADDRESS_MASK   (0b00011111)


#pragma pack(push)
/* standard packet 8 byte*/
typedef struct {
    UINT8 preamble;
    UINT8 address;
    UINT8 control_sum;
    UINT8 cmd_function;

    union {        
        struct {
            UINT16 hval;
            UINT16 lval;
        };
        UINT8 db[4];
        UINT32 val;
    } data;
} StdProtocolCommand_t;

/* stream 24 bytes*/
typedef struct {
    UINT8 pre;
    UINT8 adr;
    UINT8 sum;
    UINT8 cmd;

    struct {
        Status_t status;
        UINT16 a0;
        UINT16 a1;
        UINT16 a2;
        UINT32 wsig;
    } data;
} StdProtocolCommandEx_t;

#pragma pack(pop)

ResultSuccess_t standard_protocol_add_packet(const UINT8 *data);
void standard_protocol_process(void);

#endif	/* STANDARD_PROTOCOL_H */


