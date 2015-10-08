#ifndef CLASSIC_DETECTOR_H
#define	CLASSIC_DETECTOR_H

#include "compiler.h"

#define SIGNAL_SUM_MINIMUM  (100)
#define SIGNAL_CNT_MINIMUM  (5)



typedef struct {
    INT24 sig_max_count; //window
    INT24 sig_sum_trig; //trigger 2 summa
    INT24 sig_trig; //trigger 1 value
} ClassicDetectorConfig_t;

typedef volatile struct {
    INT24 cur_v;
    INT24 zero;
    INT24 over_trig_value;
    INT24 sig_sum;
    INT24 sig_count;
    INT24 last_sig_sum;
    INT24 last_sig_count;
    struct {
        unsigned alarm      : 1;
        unsigned warning    : 1;
        unsigned over_trig  : 1;
    } status;
    ClassicDetectorConfig_t config;

} ClassicDetector_t;


void cla_init(ClassicDetector_t *d);

BOOL cla_add_value(ClassicDetector_t *d,INT24 val,INT24 zero);

void cla_setup(ClassicDetector_t *d,INT24 trig, INT24 trig_sum, INT24 trig_window);
  
void cla_result(ClassicDetector_t *d, INT24 *value, INT24 *time);

#endif	/* CLASSIC_DETECTOR_H */

