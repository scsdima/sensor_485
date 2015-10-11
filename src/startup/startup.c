#include "startup.h"
#include "memory_register_map.h"
#include "rd_buffer.h"
#include "timers.h"
#include "uart.h"
#include "adc.h"
#include "eeprom.h"
#include "sysclk.h"
#include "gpio.h"
#include "serialport.h"
#include "config.h"

#include "scheduler.h"

ResultSuccess_t startup(void)
{
	ResultSuccess_t result = RESULT_FAIL;
	gpio_init();
	sysclk_init();
	adc_init();
	uart_init();
	setup_event(TASK_COMMUNICATION, (PEVENT)serialport_task);
	uart_puts("[1]",100);
	do{
	uart_puts("[2]",100);
	if(!serialport_startup()) break;	
	uart_puts("[3]",100);
	
    // TODO init scheduler tasks
    // TODO read config from eeprom
    // TODO timers
	result = RESULT_SUCCESS;
	}while(0);
	uart_puts("[4]",100);
	return result;
}