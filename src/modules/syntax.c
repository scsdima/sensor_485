
#include "string_utils.h"
#include "syntax.h"
#include "cmd_data.h"



#define SYNTAX_SEPARATOR        ('\0')

//last options
BOOL this_case_sensitive;
//last parsed command id
INT8 command_id;
//last parsed parameter  id
INT8 parameter_id;
ParserType_t  parameter_type;
//last parsed paramter value
UINT8 parameter_value[SYNTAX_STRING_MAX_LEN];
//last parsed parameter text name
UINT8 parameter_text[SYNTAX_STRING_MAX_LEN];
//temporary buffer for string
char this_buf[SYNTAX_STRING_MAX_LEN];

//parse parameter
BOOL this_parse_item(const char *pstr, INT8 *pitem);
//
void this_variable_load_from_text(const char *pval);


/* *********************************************************************
@Function name: this_variable_load_from_text
@Return: (void)
@Parameters:
    char *var_ptr - pointer to byte array
    SyntaxType_t var_type - type of variable
@Description: - this fill parameter value buffer with data according to
type
********************************************************************* */
void this_variable_load_from_text(const char *pval)
{
         
  if (pval != NULL ) {
    INT16 len = string_utils_strchr(pval, SYNTAX_SEPARATOR);
    string_utils_copy(parameter_value , pval, len);
    parameter_value[len] = '\0';
    //remove quotations ::
   //len = string_utils_remove_symbol(parameter_value , parameter_value , '\"');
    parameter_type = parameter_type;
    switch (parameter_type) {
    // bytearray here means don't care about contens
    case PARSER_TYPE_BYTEARRAY:
    {
      
    }
    break;
    // integer value
    case PARSER_TYPE_BOOL:
    case PARSER_TYPE_INTEGER:
     //------------------------------------------------ *((INT16*)parameter_value) = (INT16)atoi((char*)pval);
      break;

#ifdef USE_FLOAT_TYPE
    //from real value
    case PARSER_TYPE_DOUBLE:
    {
      *((double*)parameter_value) = (double)atof((char*)pval);
    }
    break;
#endif
    //converts from hex array "AABBCD1122" ... not case sensitive
    case PARSER_TYPE_HEXARRAY:
    {
      string_utils_from_hex(parameter_value, parameter_value );
    }
    break;

    default:
      *((INT16*)parameter_value) = 0u;
      break;
    }
  }
}


/* *********************************************************************
@Function name: this_parse_parameter
@Return: (BOOL) - 0 - not ok
@Parameters:
    const char par_str[] - parameter string
@Description: This function parses parameter string
in format "parameter=value"
********************************************************************* */
BOOL this_parse_item(const char *pstr, INT8 *pitem) {
  BOOL result = FALSE;
  if (pstr != NULL) {
    const char *pvar =  pstr;//pointer to variable name
    const char *pval = NULL;//pointer to variable value
    SIZE var_len;
    INT8 i = 0;
    SIZE str_len = string_utils_strlen(pstr);
    /* parameter has = so will be evaluated as set type*/
    var_len = string_utils_strchr(pstr, '=');
    if (var_len >= 0  && var_len < str_len) {
      pval = &pstr[ var_len + 1 ] ;
    } else {
      /* if no value for variable value pointer points to variable*/
      var_len = str_len;
    }
    /* find parameter in list */
    string_utils_copy(parameter_text, pvar, var_len);
    parameter_text[var_len] = '\0';
      for(i=0;i<SYNTAX_COUNT;i++) {
        if (syntax_data[i].name_len == var_len)
	{		
          BOOL is_equal = string_utils_strncmp(syntax_data[i].name, pvar, var_len, this_case_sensitive);	  
          if ( is_equal ) 
	  {
            if(pitem) *pitem = syntax_data[i].id;
            if (pval) this_variable_load_from_text(pval);
            result = TRUE;
            break;
          }	
        }        
      }
    }
  return result;
}


/* *********************************************************************
@Function name: syntax_string - parsing a string
@Return: (INT16)
@Parameters:
    const char pstr[] - string to syntax
@Description:
 This function parses string on parameters and commands
********************************************************************* */
INT8 syntax_string(const char *pstr, SIZE str_len, BOOL case_sensitive) {
  INT8 chains ;
  INT8 result =0;
  this_case_sensitive = case_sensitive;
  chains = (INT8)string_utils_split(this_buf, pstr, str_len, '\0');
  command_id = -1;
  parameter_id = -1;
  parameter_value[0] = '\0';
  parameter_text[0] = '\0';    
  if (chains >= 1 ) {
    INT8 pos = 0;
    char *pchain;
    result = chains -1;
    while ( chains-- ) {
      pchain = &this_buf[pos];
      if (pos == 0 ) {
        /* parse command*/
        if ( !this_parse_item( pchain, &command_id ) ) {result =0;break;}
        on_parameter_found(PARSER_START, command_id, -1, (void*)NULL, PARSER_TYPE_NO_TYPE);
      }
      else {
        /* parse parameter*/
        if (this_parse_item( pchain, &parameter_id ) == TRUE) {
	   parameter_type= syntax_data[parameter_id].type;  		
          on_parameter_found(PARSER_PARAMETER, command_id, parameter_id, (void*)parameter_value, parameter_type);						  
        }
        /* parameter not found*/
        else {          
          on_parameter_found(PARSER_PARAMETER, command_id, -1 , (void*)parameter_text, PARSER_TYPE_NO_TYPE);			
        }
      }
      /* switch to next parameter */
      pos += string_utils_strlen(pchain) + 1;
    }
  }
    if (result>0 )
    {
      on_parameter_found(PARSER_STOP, command_id, -1, (void*)NULL, PARSER_TYPE_NO_TYPE);	  			
    }
   else {
      on_parameter_found(PARSER_ERROR,-1, -1, (void*)NULL, PARSER_TYPE_NO_TYPE);	  			
   }
   
  return result;
}



/* *********************************************************************
@Function name: syntax_parameter_name()
@Return: (const char*)
@Parameters:
    void
@Description:
   This function gets id and returns pointer to name
********************************************************************* */
const char* syntax_get_text(void) {
  return parameter_text;
}


INT16 syntax_as_integer(void)
{
  return *((INT16*)parameter_value);
}

double syntax_as_double(void)
{
  return *((double*)parameter_value);
}

BOOL syntax_as_BOOL(void)
{
  return *((BOOL*)parameter_value);
}

UINT8 * syntax_as_bytearray(void)
{
  return (UINT8*)parameter_value;
}