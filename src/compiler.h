#include "xc.h"

#ifndef COMPILER_H
#define COMPILER_H

typedef char            CHAR;

typedef unsigned char   UINT8;
typedef unsigned int    UINT16;
typedef unsigned short long UINT24; //xc pic18 24 bit
typedef unsigned long   UINT32;

typedef signed char     INT8;
typedef signed int      INT16;
typedef signed short long INT24;//xc pic18 24 bit
typedef signed long     INT32;
typedef unsigned char   IDX8;//index 8 bit
typedef unsigned int   IDX16;//index 16 bit

typedef float FLOAT;
typedef signed  int     SIZE;

#define BOOL CHAR
#endif