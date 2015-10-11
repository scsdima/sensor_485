#include <pic18f45k20.h>

#include "serialport.h"
#include "rd_buffer.h"
#include "uart.h"
#include "syntax.h"
#include "config.h"
#include "config.h"
#include "scheduler.h"

static CHAR serialport_buffer[100];
static RdBuffer g_rx_buffer;
static RdBuffer g_tx_buffer;

ResultSuccess_t serialport_startup(void)
{
	ResultSuccess_t result = RESULT_FAIL;
	result = (ResultSuccess_t) rd_buffer_init(&g_rx_buffer, RD_BUFFER_SIZE)
		| (ResultSuccess_t) rd_buffer_init(&g_tx_buffer, RD_BUFFER_SIZE);
	return result;
}

void serialport_service(void)
{
	UINT8 byte;
	if (uart_byte_available()) {
		if (uart_getc(&byte) == RESULT_SUCCESS) {
			rd_buffer_put(&g_rx_buffer, &byte);
			issue_event(TASK_COMMUNICATION);
		}
	}
}

void serialport_task()
{
	SIZE size;
	if (rd_buffer_readline(&g_rx_buffer, &serialport_buffer, &size)) {
		syntax_string(serialport_buffer, FALSE);
	}
	size = rd_buffer_cnt(&g_tx_buffer);
	if (size > 0) {
		rd_buffer_getn(&g_tx_buffer, &serialport_buffer, size);
		uart_puts(serialport_buffer, size);
	}
}

void serialport_write(const CHAR *pstr)
{
	while (pstr && *pstr) 
	{
		rd_buffer_put(&g_tx_buffer, (UINT8*)pstr);
		pstr++;
	}
}

void putch(unsigned char byte){
	rd_buffer_put(&g_tx_buffer, &byte);
}
