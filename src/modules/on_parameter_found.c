#include "syntax.h"
#include "cmd_data.h"
#include "serialport.h"

BOOL set_parameter(INT8 p_id);
BOOL get_parameter(INT8 p_id);
BOOL run_command(void);


void on_parameter_found(ParserOperation_t operation, INT8 cmd_id
	, INT8 p_id, const void* p, ParserType_t type)
{
	BOOL ok;
	if (operation == PARSER_PARAMETER) {
		switch (cmd_id) {
		case Command_set:
			ok = set_parameter(p_id);
			break;

		case Command_get:
			ok = get_parameter(p_id);
			break;

//		case Command_run:
//			ok = run_command();
//			break;

		default:
			break;
		}
	}
	else if (operation == PARSER_STOP) {
//		switch (cmd_id) {
////		case Command_reset:
////		{
////			// TODO reset();
////		}
////			break;
//
////		case Command_help:
////		{
////			serial_comm_puts(help);
////			ok = true;
////		}
////			break;
//		}
//		serial_comm_puts("\n");
	} else if (operation == PARSER_ERROR) {
		serialport_write("err\n");
	}
}


BOOL set_parameter(INT8 p_id ) {
  BOOL ok  = FALSE;
//  switch (p_id ) 
//  {
//  
//  case Parameter_signal:
//  break;
//	  
//  }
  serialport_write( syntax_get_text() );
  
  if( ok )
  {
		serialport_write(  ":ok " );
  }
  else 
  {
	  serialport_write( ":err " );
  }
  return ok;
}

BOOL get_parameter(INT8 p_id) {
  BOOL  ok = FALSE;
      
//serial_comm_puts(syntax_get_text());
//	parameter_out[0] = '=';
//  switch (p_id ) {
//
//  case Parameter_signal:
//break;
//  }
  
  if(ok) 
    {
	  //serialport_write( parameter_out);
	}
  else 
    {
    serialport_write( ":err " );	   
	}
  return ok;
}

