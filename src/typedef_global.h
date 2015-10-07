

#ifndef TYPEDEF_GLOBAL_H
#define	TYPEDEF_GLOBAL_H

#include "compiler.h"



/* result with error*/
typedef enum {
    RESULT_NO_ERROR = 0,
    RESULT_ERROR = -1,
    RESULT_NULL = -2,
    RESULT_EMPTY = -3
} ResultError_t;

/* result success / fail*/
typedef enum {
    RESULT_SUCCESS =  1,
    RESULT_FAIL =     0
} ResultSuccess_t;

/*cable state*/
typedef enum {
    CABLE_NORMAL =  0, /* normal state cable is ok */
    CABLE_SHORT =   1, /* terminal is shorted */
    CABLE_NO_END =  2 /* Cable has no resistor */
} CableState_t;






#ifndef ABS
#define ABS(X) ((X)<0?(-(X)):(X))
#endif


#endif	/* TYPEDEF_GLOBAL_H */

