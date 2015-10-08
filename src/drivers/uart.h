#ifndef UART_H
#define UART_H

#include "compiler.h"
#include "typedef_global.h"

void uart_init(void);

void uart_enable(BOOL on);

void uart_puts(const CHAR *pstr, SIZE size);

ResultSuccess_t uart_getc(CHAR *pbyte);

//#pragma inline(uart_putc) 
void uart_putc(CHAR byte);  

////#pragma inline (uart_byte_received)
BOOL uart_byte_received(void);

//#pragma inline (uart_byte_sent)
BOOL uart_byte_sent(void);

//#pragma inline (uart_error)
BOOL uart_error(void);

void uart_reset(void);

#endif 