#ifndef SERIALPORT_H
#define SERIALPORT_H

#include "compiler.h"
#include "typedef_global.h"

ResultSuccess_t serialport_startup(void);

/* interrupt*/
void serialport_service(void);

/* scheduler_task*/
void serialport_task();

void serialport_write(const CHAR *pstr);

#endif