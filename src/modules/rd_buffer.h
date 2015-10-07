#ifndef RD_BUFFER_H
#define RD_BUFFER_H
#include "compiler.h"

/*Round buffer max size*/
#define RD_BUFFER_SIZE           (200u)

typedef UINT8 RdBufferRecord;


typedef struct {
    struct {    
/*last added record*/
    INT16  last;  
/*current unread rcord*/
    INT16  first;
    SIZE  size;
    BOOL stream;
    }   head;   
    RdBufferRecord   list[RD_BUFFER_SIZE];
} RdBuffer;


SIZE rd_buffer_capacity(RdBuffer *pbuffer);
/*init*/
BOOL rd_buffer_init(RdBuffer *pbuffer, SIZE size, BOOL stream);

/*gets count of records in buffer*/
SIZE rd_buffer_cnt(RdBuffer *pbuffer);

void rd_buffer_reset(RdBuffer *pbuffer);

/*checks if buffer is empty */
BOOL rd_buffer_is_empty(RdBuffer *pbuffer);

/*checks if buffer is full */
BOOL rd_buffer_is_full(RdBuffer *pbuffer);

/*put/get*/
/*gets next record*/
BOOL rd_buffer_get(RdBuffer *pbuffer,RdBufferRecord *prec);

/*puts record to periodical data buffer*/
BOOL rd_buffer_put(RdBuffer *pbuffer,RdBufferRecord *prec);


/*get number of records*/
BOOL rd_buffer_getn(RdBuffer *pbuffer, RdBufferRecord prec[], SIZE rec_count);

BOOL rd_buffer_first(RdBuffer *pbuffer, RdBufferRecord *prec);

BOOL rd_buffer_last(RdBuffer *pbuffer, RdBufferRecord *prec);

#endif 

