
#ifndef __DETECTION_H__
#define	__DETECTION_H__

#include "compiler.h"
#include "peak_detector.h"
#include "classic_detector.h"



typedef enum {
    DETECTION_MODE_OFF      = (UINT8)0,    
    DETECTION_MODE_CLA      = 1,
    DETECTION_MODE_PEAK     = 2,
    DETECTION_MODE_COUNT

} DetectionMode_t;


void detection_init(void);
BOOL detection_profile_set(UINT8 profile_number);
BOOL detection_defaults_set(void);
BOOL detection_config_apply(void);
BOOL detection_is_warning(void);
BOOL  detection_is_alarm(void) ;
INT16 detection_get_zero(void) ;
void detection_task(void);
void detection_obtain_analog_service(void);

#endif	/* DETECTION_H */

