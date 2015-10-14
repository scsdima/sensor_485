
#ifndef MEMORY_REGISTER_MAP_H
#define	MEMORY_REGISTER_MAP_H
 #include "compiler.h"
 #include "typedef_global.h"
#include    "rd_buffer.h"
#include "detection.h"

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
    ProfileNumber_t   profile_number; /* number of used standard profile 0x00 - is detection off */
    UINT8   address;    /* network address*/
    UINT8   potentiometer; /* potentiometer value 0..16 */    
    UINT8   acc_sensitivity; /* acc sensitivity (x1-x0) value etc delta(x) */    
    UINT16  power_trig; /* power trigger */             
    DetectionMode_t det_mode;
    ClassicDetectorConfig_t cla_config;
    PeakDetectorConfig_t   pd_config;   
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





// OUTPUT
extern volatile Config_t   g_CONFIG;
extern volatile UINT16 	g_STATUS;
extern volatile UINT16  g_analog0; //main signal
extern volatile UINT16  g_analog1; //r of cable
extern volatile UINT16  g_analog2; //pwr        
///    Axis_t     axis;

/*cable state*/
#define  CABLE_NORMAL   0 /* normal state cable is ok */
#define  CABLE_SHORT    1 /* terminal is shorted */
#define  CABLE_NO_END   2 /* Cable has no resistor */

/* status register masks*/
#define STATUS_ALARM            (1<<0)
#define STATUS_WARNING          (1<<1)
//cable
#define STATUS_CABLE_SHORT      ( CABLE_SHORT << 2)
#define STATUS_CABLE_NORMAL     (CABLE_NORMAL << 2)
#define STATUS_NO_END           (CABLE_NO_END << 2)
//acceleromter
#define STATUS_ACC_MOVE         (1<<4)
//power
#define STATUS_POWER_PROBLEM    (1<<5)
//testmode
#define STATUS_TEST_MODE        (1<<6)
#define STATUS_COMM_ERR         (1<<7)

#define STATUS_SABOTAGE         (CABLE_SHORT|CABLE_NO_END|STATUS_ACC_MOVE|STATUS_POWER_PROBLEM)

#define SET_STATUS(V)  g_STATUS |= V
#define CLR_STATUS(V)  g_STATUS &= ~V;
#define IS_STATUS(V)   (g_STATUS &V)
#define STATUS()       g_STATUS
/*profiles */


#endif	/* REGISTERS_H */

