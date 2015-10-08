#include "startup.h"
#include "memory_register_map.h"
#include "rd_buffer.h"
#include "timers.h"
#include "scheduler.h"
#include "uart.h"
#include "adc.h"
#include "eeprom.h"
#include "sysclk.h"
#include "gpio.h"


ResultSuccess_t startup(void)
{
	ResultSuccess_t result = RESULT_FAIL;
	gpio_init();
	sysclk_init();
	adc_init();
	uart_init();
	
	do{
    rd_buffer_init(&g_rx_buffer, RD_BUFFER_SIZE , FALSE);
    
    // TODO init scheduler tasks
    // TODO read config from eeprom
    // TODO timers
    
	}while(0);

	return result;
}