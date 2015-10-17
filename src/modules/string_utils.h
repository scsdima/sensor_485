#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#include "compiler.h"
#include "string.h"
#include "stdio.h"


#define  STRING_UTILS_MAX_LEN   (1000)


#define LETTER_CASE_DIFF        ('a' - 'A')

#define fromUpperToLower(V)	(V+LETTER_CASE_DIFF)
#define fromLowerToUpper(V)	(V-LETTER_CASE_DIFF)

INT16 string_utils_strlen(const char pstr[]) ;
INT16 string_utils_copy(char pdst[],const char psrc[],  INT16 maxlen);
INT16 string_utils_length(const char pstr[]);
INT16 string_utils_remove_symbol(char *pdst, const char *psrc, char symb);
INT16 string_utils_split(char pbuf[], const char pstr[], INT16 len, char delimeter);
INT16 string_utils_strchr(const char pbuf[], char delimeter);
BOOL string_utils_is_upper_case(char symb);
BOOL string_utils_is_lower_case(char symb);
BOOL string_utils_is_symbol(char symb);
BOOL string_utils_is_letter(char symb);
BOOL string_utils_is_digit(char symb);
SIZE string_utils_from_hex(UINT8 *pdata, const char* phex_str);
void string_utils_to_lower_case(char pstr[]);
void string_utils_to_upper_case(char pstr[]);
BOOL string_utils_strcmp(const char pstr1[],const char pstr2[],BOOL case_sensitive);
BOOL string_utils_strncmp(const char pstr1[], const char pstr2[], 
						SIZE len, BOOL case_sensitive);
INT16 string_utils_atoi(const char *c);		
FLOAT  string_utils_atof(const char *s);
char string_utils_toHex(unsigned char byte);						

#endif