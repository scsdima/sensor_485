/* *********************************************************************


@File:rd_buffer.c

@Description: round buffer driver

********************************************************************* */

#include "rd_buffer.h"


/* ********************************************************************* 
@Function name: rd_buffer_capacity
@Return: (BOOL) 
@Parameters: 
  RdBuffer *pbuffer - buffer pointer
@Description: buffer capacity

********************************************************************* */
SIZE rd_buffer_capacity(RdBuffer *pbuffer) 
{
  return pbuffer->head.size-1;
}

/* ********************************************************************* 
@Function name: rd_buffer_init
@Return: (BOOL) 
@Parameters: 
  RdBuffer *pbuffer - buffer pointer
  UINT size - size of buffer 
  BOOL stream - make buffer overwritable
@Description: rround buffer initialize

********************************************************************* */
BOOL rd_buffer_init(RdBuffer *pbuffer ,SIZE size, BOOL stream)
{    
  BOOL result = FALSE;
  if(pbuffer != NULL ){
    pbuffer->head.first = 0;
    pbuffer->head.last = 0;
    /* one element will be everytime lost ind points to next */
    pbuffer->head.size = size+1;
    pbuffer->head.stream = stream;
    result = TRUE;
  }
  return result;
}

/* ********************************************************************* 
@Function name: rd_buffer_cnt
@Return: (UINT)  count of elements
@Parameters: 
  RdBuffer *pbuffer  - buffer pointer
@Description: return number of elements in round buffer

********************************************************************* */
SIZE rd_buffer_cnt(RdBuffer *pbuffer){
  SIZE sz;
  sz = pbuffer->head.last - pbuffer->head.first;
  if(sz < 0) {
    sz += pbuffer->head.size;
  }
  return sz;
}

/* ********************************************************************* 
@Function name: rd_buffer_reset
@Return: (void) 
@Parameters: 
  RdBuffer *pbuffer - buffer pointer
@Description: resets buffer 

********************************************************************* */
void rd_buffer_reset(RdBuffer *pbuffer){

  pbuffer->head.first=0;
  pbuffer->head.last =0;
}

/* ********************************************************************* 
@Function name: rd_buffer_is_empty
@Return: (BOOL) 
@Parameters: 
  RdBuffer *pbuffer
@Description: if buffer contains no elements
********************************************************************* */
BOOL rd_buffer_is_empty(RdBuffer *pbuffer){
  BOOL result;
  result = (BOOL)(rd_buffer_cnt(pbuffer) == 0);
  return result;
}

/* ********************************************************************* 
@Function name: rd_buffer_is_full
@Return: (BOOL) 
@Parameters: 
  RdBuffer *pbuffer  - buffer pointer
@Description: buffer is full

********************************************************************* */
BOOL rd_buffer_is_full(RdBuffer *pbuffer){
  BOOL result;
  result = (BOOL)(rd_buffer_cnt(pbuffer) == (SIZE)pbuffer->head.size);  
  return result;
}

/* ********************************************************************* 
@Function name: rd_buffer_get
@Return: (BOOL) 
@Parameters: 
  RdBuffer *pbuffer - buffer pointer
  RdBufferRecord * prec 
@Description: Get Record from buffer

********************************************************************* */
BOOL rd_buffer_get(RdBuffer *pbuffer, RdBufferRecord *prec){
  BOOL result = FALSE;
  INT16 first = pbuffer->head.first;
  INT16 last = pbuffer->head.last;
  if(first  != last)  {
    (*prec) = pbuffer->list[first ];
    first  ++;
    pbuffer->head.first = first ;/*DMEM_WRITE*/
    if(first  == pbuffer->head.size){
    pbuffer->head.first = 0;/*DMEM_WRITE*/
    }
    result = TRUE;
  }
  return result;
}


/* ********************************************************************* 
@Function name: rd_buffer_put
@Return: (BOOL) 
@Parameters: 
  RdBuffer *pbuffer - buffer pointer
  RdBufferRecord *prec 
@Description: buffer put element

********************************************************************* */
BOOL rd_buffer_put(RdBuffer *pbuffer, RdBufferRecord *prec){
  BOOL result = FALSE;
  SIZE sz ;
  sz = pbuffer->head.last - pbuffer->head.first;
  /* detecting size*/
  if(sz < 0 )    {
    sz += pbuffer->head.size;
  }

  /* stream mode , overwritable*/
  if(pbuffer->head.stream){
    INT16 indl = pbuffer->head.last;  
    INT16 indf =pbuffer->head.first;
    volatile RdBufferRecord *mes_rec=(volatile RdBufferRecord*)&pbuffer->list[indl];
    (*mes_rec) = (*prec); 
    indl++;    
    /* need to rotate*/
    if(indl == pbuffer->head.size ) {
      indl = 0;
    }    
    if(indl == indf){
      indf++;    
    }
    /* need to rotate*/
    if(indf == pbuffer->head.size ) {
      indf = 0;
    }    
    pbuffer->head.last = indl;
    pbuffer->head.first = indf;
    result = TRUE;    
  }
  
  /* buffer has  limited with size */
  else{
    if(sz < (pbuffer->head.size - 1)){
      INT ind = pbuffer->head.last;
      volatile RdBufferRecord *mes_rec=(volatile RdBufferRecord*)&pbuffer->list[ind];
      (*mes_rec) = (*prec);
      ind++;
      /* needs to rotate*/
      if(ind == pbuffer->head.size ) {
        ind = 0;
      }    
      pbuffer->head.last = ind;
      result = TRUE;    
    }  
  }
  return result;
}



/* ********************************************************************* 
@Function name: rd_buffer_getn
@Return: (BOOL) successfull -1
@Parameters: 
      RdBuffer *pbuffer - buffer pointer
      RdBufferRecord rec[] -  records array
      UINT rec_count - record count to get
@Description: get number of records

********************************************************************* */
BOOL rd_buffer_getn(RdBuffer *pbuffer, RdBufferRecord prec[], SIZE rec_count){
  SIZE i=0;  
  BOOL result = TRUE;
  while(rec_count--){
  if(rd_buffer_get(pbuffer, &prec[i]) == FALSE ) {
    result = FALSE;
    break;  
  }
  i++;
 }  
 return result;
}


/* ********************************************************************* 
@Function name: rd_buffer_first
@Return: (BOOL) 
@Parameters: 
    RdBuffer *pbuffer - buffer pointer
    RdBufferRecord *prec  -record pointer
@Description: gets first element, and do not delete it from list

********************************************************************* */
BOOL rd_buffer_first(RdBuffer *pbuffer, RdBufferRecord *prec){
BOOL result = FALSE;
if(rd_buffer_cnt(pbuffer) > 0){
  INT16 ind = pbuffer->head.first;
  volatile RdBufferRecord *mes_rec = (volatile RdBufferRecord*)&pbuffer->list[ind];
    (*prec) = (*mes_rec); 
    result = TRUE;
}
return result;
}

/* ********************************************************************* 
@Function name: rd_buffer_last
@Return: (BOOL) 
@Parameters: 
    RdBuffer *pbuffer - buffer pointer
    RdBufferRecord *prec -record pointer
@Description: gets last element, and do not delete it from list

********************************************************************* */
BOOL rd_buffer_last(RdBuffer *pbuffer, RdBufferRecord *prec){
BOOL result = FALSE;
if(rd_buffer_cnt(pbuffer) > 0){  
  INT16 ind = pbuffer->head.last - 1;
  if(ind < 0) {
    ind = pbuffer->head.size;
  }
  volatile RdBufferRecord *mes_rec = (volatile RdBufferRecord*)&pbuffer->list[ind];
    (*prec) = (*mes_rec); 
    result = TRUE;
}
return result;
}
