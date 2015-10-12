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
	setup_event(TASK_DETECTION, (PEVENT)detection_task);
	
	uart_puts("hello",100);
	do{	
	if(!serialport_startup()) break;		
	    
    // TODO read config from eeprom
    // TODO timers
	result = RESULT_SUCCESS;
	}while(0);	
	return result;
}