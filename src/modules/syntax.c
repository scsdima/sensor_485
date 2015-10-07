
#include "string_utils.h"
#include "syntax.h"
#include "cmd_data.h"



#define SYNTAX_SEPARATOR        ('$')

//last options
BOOL case_sensitive;
//last parsed command id
INT16 command_id;
//last parsed parameter  id
INT16 parameter_id;
//last parsed paramter value
UINT8 parameter_value[SYNTAX_STRING_MAX_LEN];
//last parsed parameter text name
UINT8 parameter_text[SYNTAX_STRING_MAX_LEN];
//last parsed parmater type
ParserType_t parameter_type;
//temporary buffer for string
char this_buf[SYNTAX_STRING_MAX_LEN];

//parse parameter
BOOL this_parse_parameter(char par_str[]);
//parse command
 BOOL this_parse_command(char pbuf[]);
//
void this_variable_load_from_text(const char *pval, ParserType_t var_type);


/* *********************************************************************
@Function name: this_variable_load_from_text
@Return: (void)
@Parameters:
    char *var_ptr - pointer to byte array
    SyntaxType_t var_type - type of variable
@Description: - this fill parameter value buffer with data according to
type
********************************************************************* */
void this_variable_load_from_text(const char *pval, ParserType_t var_type)
{
  if (pval != NULL ) {
    INT16 len = string_utils_strchr(pval, SYNTAX_SEPARATOR);
    string_utils_copy(parameter_value , pval, len);
    parameter_value[len] = '\0';
    //remove quotations ::
   //len = string_utils_remove_symbol(parameter_value , parameter_value , '\"');
    parameter_type = var_type;
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
@Function name: this_parse_command
@Return: (BOOL)
@Parameters:
    const char pbuf[] - parse command
@Description:- finding command

********************************************************************* */
BOOL  this_parse_command(char pbuf[]) {
  BOOL found = FALSE;
  INT16 i = 0;
  INT16 len = string_utils_strchr(pbuf, SYNTAX_SEPARATOR);
  while(syx_cmd_list[i].name[0] != 0x1D)    {
    const char *pname  = syx_cmd_list[i].name;
    BOOL is_equal = string_utils_strncmp(pbuf, pname, len, case_sensitive);
    if ( is_equal ) {
      command_id = syx_cmd_list[i].id;
      found = TRUE;
      break;
    }
    i++;
  }
  return found;
}


/* *********************************************************************
@Function name: this_parse_parameter
@Return: (BOOL) - 0 - not ok
@Parameters:
    const char par_str[] - parameter string
@Description: This function parses parameter string
in format "parameter=value"
********************************************************************* */
BOOL this_parse_parameter(char pstr[]) {
  BOOL result = FALSE;
  if (pstr != NULL) {
    const char *pvar =  pstr;//pointer to variable name
    const char *pval = NULL;//pointer to variable value
    INT16 var_len;
    INT16 i = 0;
    INT16 str_len = string_utils_strchr(pstr, SYNTAX_SEPARATOR);
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
      while( syx_param_list[i].name[0] != 0x1D ) {
        if (string_utils_strlen( syx_param_list[i].name ) == var_len){
          BOOL is_equal = string_utils_strncmp(syx_param_list[i].name, pvar, var_len, case_sensitive);
          if ( is_equal ) {
            parameter_id =  syx_param_list[i].id;
            parameter_type = syx_param_list[i].type;            
            if (pval)
              this_variable_load_from_text(pval, parameter_type);
            result = TRUE;
            break;
          }	
        }
        i++;
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
INT16 syntax_string(const char pstr[], BOOL case_sensitive) {
  INT16 chains ;
  INT16 result =0;
  INT16 str_len = string_utils_strlen(pstr);
  chains = string_utils_split(this_buf, pstr, str_len, SYNTAX_SEPARATOR);
  command_id = -1;
  parameter_id = -1;
  parameter_value[0] = '\0';
  parameter_text[0] = '\0';
  if (chains >= 1 ) {
    INT16 pos = 0;
    char *pchain;
    result = chains -1;
    while ( chains-- ) {
      pchain = &this_buf[pos];
      if (pos == 0 ) {
        /* parse command*/
        if ( !this_parse_command( pchain ) ) {result =0;break;}
        on_parameter_found(PARSER_START, command_id, -1, (void*)NULL, PARSER_TYPE_NO_TYPE);
      }
      else {
        /* parse parameter*/
        if (this_parse_parameter( pchain ) == TRUE) {
          on_parameter_found(PARSER_PARAMETER, command_id, parameter_id, (void*)parameter_value, parameter_type);					
        }
        /* parameter not found*/
        else {          
          on_parameter_found(PARSER_PARAMETER, command_id, -1 , (void*)parameter_text, PARSER_TYPE_NO_TYPE);			
        }
      }
      /* switch to next parameter */
      pos += string_utils_strchr(pchain, SYNTAX_SEPARATOR) + 1;
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