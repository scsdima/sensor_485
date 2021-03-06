#ifndef CLASSIC_DETECTOR_H
#define	CLASSIC_DETECTOR_H

#include "compiler.h"

#define SIGNAL_SUM_MINIMUM  (100)
#define SIGNAL_CNT_MINIMUM  (5)



typedef struct {
    INT16 sig_max_count; //window
    INT16 sig_sum_trig; //trigger 2 summa
    INT16 sig_trig; //trigger 1 value
} ClassicDetectorConfig_t;

typedef volatile struct {
    INT16 cur_v;
    INT16 zero;
    INT16 over_trig_value;
    INT16 sig_sum;
    INT16 sig_count;
    INT16 last_sig_sum;
    INT16 last_sig_count;
    struct {
        unsigned alarm      : 1;
        unsigned warning    : 1;
        unsigned over_trig  : 1;
    } status;
    ClassicDetectorConfig_t config;

} ClassicDetector_t;


void cla_init(ClassicDetector_t *d);

BOOL cla_add_value(ClassicDetector_t *d,INT16 val,INT16 zero);

void cla_setup(ClassicDetector_t *d,INT16 trig, INT16 trig_sum, INT16 trig_window);
  
void cla_result(ClassicDetector_t *d, INT16 *value, INT16 *time);

#endif	/* CLASSIC_DETECTOR_H */

