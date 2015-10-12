

#ifndef PEAK_DETECTOR_H
#define PEAK_DETECTOR_H

#include "compiler.h"


#define MAXIMUM_LVAL        (20)
#define MAXIMUM_RVAL        (20)
#define QUIET_SIGNAL_WLEV   (10)
#define NORMAL_SIGNAL_WLEV  (1000)

typedef struct {
    INT16 wtrigger; //acceleration trigger
    INT16 tolerance;
    UINT8 lval_cnt;
    UINT8 rval_cnt;
} PeakDetectorConfig_t;

typedef volatile struct {
    //dynamic values
    INT16 last_v_buf[MAXIMUM_LVAL]; //last values buffer
    UINT8 last_v_idx; //last value index
    UINT16 last_v; //last value

    INT16 ref_v_buf[MAXIMUM_RVAL]; //color values for refference color
    UINT8 ref_v_idx; //last average color index
    INT16 ref_v; //ref color value

    INT16 avlv; //average value
    INT16 cur_v; //curent value
    INT16 next_v; //next value
    INT16 wval; //acceleration value

    struct {
        unsigned alarm : 1;
        unsigned warning : 1;
        unsigned firststart : 1; //
    } status;

    PeakDetectorConfig_t config;
} PeakDetector_t;


void    pd_init(PeakDetector_t *d);

BOOL   pd_add_value(PeakDetector_t *d, INT16 val);

void    pd_result(PeakDetector_t *d, INT16 *pvalue, INT16 *ptime);

#endif

