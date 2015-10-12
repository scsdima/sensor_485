

#include "peak_detector.h"

/* *********************************************************************
  @Function name:  vcInit
  @Return: (void)
  @Parameters:
        PeakDetector_t *d
  @Description: detector initialization

 ********************************************************************* */
void pd_init(PeakDetector_t *d) {
    IDX8 i;
    for (i = 0; i < d->config.lval_cnt; i++) {
        d->last_v_buf[i] = 0;
    }
    d->last_v = 0;
    d->last_v_idx = 0;
    d->ref_v_idx = 0;
    d->status.firststart = TRUE;
}

/* *********************************************************************
  @Function name:  vcAddNewValue
  @Return: (    BOOL) - alarm = 1 
  @Parameters:
        PeakDetector_t*d
         INT16 val
  @Description: adds new value to detect aarm or warning

 ********************************************************************* */
BOOL pd_add_value(PeakDetector_t*d, INT16 val) {
    IDX8 i;
    INT16 tmp;

    d->last_v_idx %= d->config.lval_cnt;
    d->last_v_buf[d->last_v_idx] = (INT16) val;
    d->last_v_idx++;
    d->last_v = d->cur_v;
    d->cur_v = d->next_v; //current_value = new_value
    d->next_v = val; //new_value = value

    tmp = 0;
    for (i = 0; i < d->config.lval_cnt; i++) {
        tmp += d->last_v_buf[i];
    }
    d->avlv = tmp/d->config.lval_cnt;

    d->wval = d->cur_v * d->cur_v - d->avlv * d->next_v; // y(x) = x(n)*x(n) - x(n+1)*x(n-1);
    //sprintf(buf,"w=%d,trig=%d",d->wval,d->config.wtrigger
    if ((ABS(d->wval)) > d->config.wtrigger) {
        if (!d->status.alarm && !d->status.firststart) {
            d->status.alarm = 1;
            return TRUE;
        }
    }
    if (d->status.alarm && (ABS(d->wval)) < NORMAL_SIGNAL_WLEV
            && ABS(d->cur_v - d->ref_v) < d->config.tolerance
            && ABS(d->next_v - d->ref_v) < d->config.tolerance) {

        for (i = 0; i < d->config.lval_cnt; i++) {
            d->last_v_buf[i] = d->cur_v;
        }
        d->status.alarm = FALSE;
    }

    //  if((!d->alarm && d->wval<10 )||wc.firststart)
    if (ABS(d->wval) < QUIET_SIGNAL_WLEV) {
        if (d->ref_v_idx == 9) {
            d->status.firststart = FALSE;
        }

        /* adding new value to rval*/
        d->ref_v_buf[d->ref_v_idx] = d->cur_v;
        d->ref_v_idx = (d->ref_v_idx + 1) % d->config.rval_cnt;

        /*calculating refference value*/
        tmp = 0;
        for (i = 0; i < d->config.rval_cnt; i++) {
            tmp += d->ref_v_buf[i];
        }
        /* calculating average value*/
        d->ref_v = tmp/d->config.rval_cnt;
    }

    return FALSE;
}


/* *********************************************************************
  @Function name:  pd_result
  @Return: (void)
  @Parameters:
        PeakDetector_t *d
         UINT16 *value
         UINT16 *time
  @Description: gets result from algoritm

 ********************************************************************* */
void pd_result(PeakDetector_t *d, INT16 *pvalue, INT16 *ptime) {
    /*allways return 0*/
    *pvalue = 0;
    *ptime = 0;
}
