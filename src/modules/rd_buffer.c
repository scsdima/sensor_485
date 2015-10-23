#include "rd_buffer.h"



/* ********************************************************************* 
@Function name: rd_buffer_init
@Return: (BOOL) 
@Parameters: 
  RdBuffer *pbuffer - buffer pointer
  UINT size - size of buffer 
@Description: rround buffer initialize

********************************************************************* */
BOOL rd_buffer_init(RdBuffer *pbuffer ,SIZE size)
{    
  BOOL result = FALSE;
  if(pbuffer != NULL ){
    pbuffer->head.first = 0;
    pbuffer->head.last = 0;
    /* one element will be everytime lost ind points to next */
    pbuffer->head.size = size+1;    
    result = TRUE;
  }
  return result;
}

/* ********************************************************************* 
@Function name: rd_buffer_readline
@Return: (BOOL) 
@Parameters: 
  RdBuffer *pbuffer - buffer pointer
  UINT8 *pdata - pointer to data
  SIZE *psize - size
@Description: rround buffer initialize

********************************************************************* */
BOOL rd_buffer_readline(RdBuffer *pbuffer, CHAR *pdata, SIZE *psize)
{    
  *psize=0;
  if( pdata )
  {
    CHAR ch;
    while(rd_buffer_get(pbuffer,(UINT8*)&ch)) 
    {
	    if(ch=='\n' || ch=='\r') 
		{
			*(++pdata) = '\0';
			return TRUE;
		}     
      *pdata++ = ch;      
      (*psize)++;
    }        
  }
  return FALSE;
}

/* ********************************************************************* 
@Function name: rd_buffer_cnt
@Return: (UINT)  number of elements
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
  UINT8 * prec 
@Description: Get Record from buffer

********************************************************************* */
BOOL rd_buffer_get(RdBuffer *pbuffer, UINT8 *prec){
  BOOL result = FALSE;
  INT16 first = pbuffer->head.first;
  INT16 last = pbuffer->head.last;
  if(first  != last)  {
    (*prec) = pbuffer->list[first ];
    first  ++;
    pbuffer->head.first = first ;
    if(first  == pbuffer->head.size){
    pbuffer->head.first = 0;
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
  UINT8 *prec 
@Description: buffer put element

********************************************************************* */
BOOL rd_buffer_put(RdBuffer *pbuffer, UINT8 *prec){
  BOOL result = FALSE;
  SIZE sz ;
  sz = pbuffer->head.last - pbuffer->head.first;
  /* detecting size*/
  if(sz < 0 )    {
    sz += pbuffer->head.size;
  }
  if(sz < (pbuffer->head.size - 1))
  {
      INT ind = pbuffer->head.last;
      volatile UINT8 *mes_rec=(volatile UINT8*)&pbuffer->list[ind];
      (*mes_rec) = (*prec);
      ind++;
      /* needs to rotate*/
      if(ind == pbuffer->head.size ) {
        ind = 0;
      }    
      pbuffer->head.last = ind;
      result = TRUE;    
    }  
  return result;
}

BOOL rd_buffer_contains(RdBuffer *pbuffer, CHAR ch)
{
  INT8 i;
  SIZE sz = rd_buffer_cnt(pbuffer);
  i= pbuffer->head.first;
  while(sz--)
  {
    if(pbuffer->list[i] == ch) return TRUE;
    i++;
    if(i == pbuffer->head.size) i=0;    
  }
  return FALSE;
}
