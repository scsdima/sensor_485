#ifndef RD_BUFFER_H
#define RD_BUFFER_H
#include "compiler.h"
#include "config.h"


/*Round buffer max size*/
#define RD_BUFFER_SIZE           (COMMUNICATION_BUFFER_SIZE)


typedef struct {
    struct {    
	/*last added record*/   	 
    INT16  last;  
	/*current unread rcord*/
    INT16  first;
    SIZE  size;
    }   head;   
    UINT8   list[RD_BUFFER_SIZE+1];
} RdBuffer;


/*init*/
BOOL rd_buffer_init(RdBuffer *pbuffer, SIZE size);
/**/
BOOL rd_buffer_readline(RdBuffer *pbuffer, CHAR *pdata, SIZE *psize);
/*gets count of records in buffer*/
SIZE rd_buffer_cnt(RdBuffer *pbuffer);

void rd_buffer_reset(RdBuffer *pbuffer);

/*checks if buffer is empty */
BOOL rd_buffer_is_empty(RdBuffer *pbuffer);

/*checks if buffer is full */
BOOL rd_buffer_is_full(RdBuffer *pbuffer);

/*put/get*/
/*gets next record*/
BOOL rd_buffer_get(RdBuffer *pbuffer,UINT8 *prec);

/*puts record to periodical data buffer*/
BOOL rd_buffer_put(RdBuffer *pbuffer,UINT8 *prec);

BOOL rd_buffer_contains(RdBuffer *pbuffer, CHAR ch);

#endif 

