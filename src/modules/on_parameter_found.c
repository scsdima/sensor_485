#include "syntax.h"
#include "cmd_data.h"
#include "serialport.h"
#include "potentiometer.h"
#include "config.h"

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

		default:
			break;
		}
	}
	
	else if (operation == PARSER_STOP) {
//		if(cmd_id==Command_reset)
//		{
//			// TODO reset();
//		}
	} 
	else if (operation == PARSER_ERROR) {
		serialport_write("err\n");
	}
}


BOOL set_parameter(INT8 p_id ) {
  INT16 u16_value;
  BOOL b_value;
  BOOL ok  = FALSE;
  switch (p_id ) 
  {
  
  case Parameter_signal:
  break;

  case Parameter_pot:
    u16_value = syntax_as_integer();
    if(u16_value<16)
    {
        SET_TRIMMER(u16_value);
    ok = TRUE;
    }
  break;

  case Parameter_mod:
  break;

  case  Parameter_profile:     
  break;

  case  Parameter_pwrtrig:     
  break;

   case Parameter_acctrig:     
  break;

   case Parameter_triglev:     
  break;

   case Parameter_trigsum:     
  break;

   case Parameter_trigcnt:     
  break;

   case Parameter_wavtole:     
  break;

   case Parameter_wavtrig:     
  break;

   case Parameter_wavlcnt:     
  break;

   case Parameter_wavrcnt:
  break;

   case Parameter_defaults:
  break;

   case Parameter_id:          
  break;

   case Parameter_psw:
  break;


	  
  }
  serialport_write( syntax_get_text() ); 
  if( ok )
  {
		serialport_write(":ok ");
  }
  else 
  {
	  serialport_write(":err ");
  }
  return ok;
}

BOOL get_parameter(INT8 p_id) {
  BOOL  ok = FALSE;

  serialport_write( syntax_get_text() ); 
      
  switch (p_id ) {

case Parameter_signal :
break;
case  Parameter_imp     :    
break;
case  Parameter_pwr     :    
break;
case  Parameter_pot     :    
break;
case  Parameter_ver     :    
break;
case  Parameter_status  :    
break;
case  Parameter_acc     :    
break;
case  Parameter_adr     :    
break;
case  Parameter_error   :    
break;
case  Parameter_defaults : 
break;
case  Parameter_mod   :      
break;
case  Parameter_profile :    
break;
case  Parameter_pwrtrig :    
break;
case  Parameter_acctrig :    
break;
case  Parameter_triglev :    
break;
case  Parameter_trigsum :    
break;
case  Parameter_trigcnt :    
break;
case  Parameter_wavtole :    
break;
case  Parameter_wavtrig :    
break;
case  Parameter_wavlcnt :    
break;
case  Parameter_wavrcnt :
break;
case  Parameter_id:          
break;
case  Parameter_psw:
break;
}

  
  if(!ok)     
    {
    serialport_write( ":err " );	   
	}
  return ok;
}

