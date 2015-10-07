/* 
 * File:   memory_register_map.h
 * Author: dmitry
 *
 * Created on July 24, 2013, 8:54 PM
 */


#ifndef MEMORY_REGISTER_MAP_H
#define	MEMORY_REGISTER_MAP_H
 #include "compiler.h"
 #include "typedef_global.h"
#include    "rd_buffer.h"


typedef enum {
    PROFILE_DIS=0,
    PROFILE1,/* wired fence*/
    PROFILE2,/* rigid fence*/
    PROFILE3,/* concrete fence*/
    PROFILE4,/* solar panel*/
    PROFILE5,/* underground*/
    PROFILE6,/* experimental*/
    PROFILES_COUNT
} ProfileNumber_t;

/* system configuration */
typedef struct 
{
    UINT8 checksum;
    ProfileNumber_t   profile; /* number of used standard profile 0x00 - is detection off */
    UINT8   address;    /* network address*/
    UINT8   potentiometer; /* potentiometer value 0..255 */    
    UINT8   acc_sensitivity; /* acc sensitivity (x1-x0) value etc delta(x) */    
    UINT16  power_trig; /* power trigger */             
  //  DetectionMode_t mode;
  //  ClassicDetectorConfig_t cla_config;
  //  VavDetectorConfig_t;   vav_config;   
} Config_t;
#define  CONFIG_SIZE sizeof(Config_t)

/* deveice information*/
typedef struct {
    UINT16 id; /* device id */
    UINT16 psw; /* password */
} DevInf_t;

/* ****PRIVATE:**** */
volatile Config_t   g_CONFIG;
volatile UINT16  g_STATUS;
volatile UINT16  g_analog0; //main signal
volatile UINT16  g_analog1; //r of cable
volatile UINT16  g_analog2; //pwr        
RdBuffer    g_rx_buffer;




// OUTPUT
extern volatile Config_t   g_CONFIG;
extern volatile UINT16 	g_STATUS;
extern volatile UINT16  g_analog0; //main signal
extern volatile UINT16  g_analog1; //r of cable
extern volatile UINT16  g_analog2; //pwr        
extern RdBuffer    g_rx_buffer;
///    Axis_t     axis;

/* status register masks*/
#define STATUS_ALARM            (1<<0)
#define STATUS_CABLE_SHORT      ( CABLE_SHORT << 1)
#define STATUS_CABLE_NORMAL     (CABLE_NORMAL << 1)
#define STATUS_NO_END           (CABLE_NO_END << 1)
#define STATUS_TAMPER1          (1<<3)
#define STATUS_TAMPER2          (1<<4)
#define STATUS_DATA_RECEIVED    (1<<5)
#define STATUS_ACC_MOVE         (1<<6)
#define STATUS_POWER_PROBLEM    (1<<7)
#define STATUS_TESTER_ENABLED   (1<<8)
#define STATUS_DIGITAL_IN       (1<<9)
#define STATUS_WARNING          (1<<10)

/*profiles */


#endif	/* REGISTERS_H */

