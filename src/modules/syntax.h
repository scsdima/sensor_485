#ifndef __SYNTAX_H
#define __SYNTAX_H

#define SYNTAX_STRING_MAX_LEN   (127u)
#define PARAMETER_NAME_LEN      (20)


#include "compiler.h"
#include "typedef_global.h"
#include "string_utils.h"



typedef enum {
	PARSER_TYPE_NO_TYPE,
	PARSER_TYPE_BYTEARRAY,
    PARSER_TYPE_HEXARRAY,
	PARSER_TYPE_INTEGER,
	PARSER_TYPE_REAL,
	PARSER_TYPE_BOOL,
	PARSER_TYPE_DOUBLE
}ParserType_t;    

typedef enum {
	PARSER_PARAMETER ,
	PARSER_START,
	PARSER_STOP,
	PARSER_ERROR
}ParserOperation_t;
	

typedef struct {
    char name[PARAMETER_NAME_LEN]; //null terminated parameter text
    INT8 name_len;
    INT8 id;    
    INT8 type;
} SyntaxItem_t;



INT8 syntax_string(const char *pstr,SIZE str_len, BOOL case_sensitive);


const char* syntax_get_text(void);
INT16 syntax_as_integer(void);
double syntax_as_double(void);
BOOL syntax_as_bool(void);
UINT8 * syntax_as_bytearray(void);


#include "cmd_data.h"

#define SYNTAX_ITEM(TXT,ID,TYPE) ID
enum {
    SYNTAX_ITEMS,
    SYNTAX_COUNT
};
#undef SYNTAX_ITEM
#define SYNTAX_ITEM(TXT,ID,TYPE) {TXT,sizeof(TXT)-1,ID,TYPE}

static const SyntaxItem_t syntax_data[SYNTAX_COUNT] = {
    SYNTAX_ITEMS
};


/*declare this function must be declared in the code*/
void on_parameter_found(ParserOperation_t operation ,INT8 cmd_id 
			, INT8 p_id  ,const void* p, ParserType_t type);

#endif
