#include "syntax.h"

//static const char help[] = " Help Help Help\n";

//static BOOL set_parameter(UI p_id);
//static BOOL get_parameter(int32_t p_id);
//static BOOL run_command(void);

//static char parameter_out[1000];

// #define NESTED_PAR_MAX_LEN (100);
// struct{
//   int32_t index;
//   int32_t i;
//   double r;
// }nested_par[10];
// 
// static int32_t read_as_list_of(ParserType_t type){
//   #define TMP_SIZE        (100u)
//   char tmp[TMP_SIZE];
//   int32_t j,i;
//   int32_t list_index=0;  
//   const char *p = (const char*)parameter_val;
//   for(i=0; i < TMP_SIZE; i++){
//     char c = p[i];
//     if( string_utils_is_digit(c) || c=='.'){
//      tmp[j++] =  c;     
//     } 
//     else {
//       tmp[j]='\0';
//       nested_par[list_index].index = i;
//       if(type == PARSER_TYPE_REAL)
//         {       
//           nested_par[list_index].r = atof(tmp);       
//         } 
//       else if(type == PARSER_TYPE_INTEGER || type == PARSER_TYPE_BOOL)
//       {        
//         nested_par[list_index].i = atoi(tmp);       
//       }
//       list_index++;
//       j=0;
//     }
//     if(c == '\0') break;
//   }
// }

void on_parameter_found(ParserOperation_t operation ,INT8 cmd_id 
						, INT8 p_id  , const void* p, ParserType_t type) 
{
//	bool ok ;	
//	if(operation == PARSER_PARAMETER)
//	{
//		  switch (cmd_id) {
//		  case Command_set  :
//			ok = set_parameter(p_id);
//			break;
//		
//		  case Command_get  :
//			ok = get_parameter(p_id);
//			break;
//		
//		  case Command_run  :
//			ok = run_command();
//			break;
//		
//		  default:
//			break;
//		}
//	} 
//	else if(operation == PARSER_STOP){
//		switch (cmd_id) {
//		case Command_reset:
//		{
//		 // TODO reset();
//		}		
//		break;
//		
//		case Command_help :
//		{
//		  serial_comm_puts(help);
//		  ok = true;
//		}
//		break;	  
//		}
//	  serial_comm_puts("\n");	  
//	}
//	else if(operation == PARSER_ERROR){
//		serial_comm_puts("err\n");	  
//	}
}

////-------------------------------------------------------------------
////-------------------------------------------------------------------
//bool set_parameter(int32_t p_id ) {
//  bool ok  = false;
//  switch (p_id ) {
//  
//  case Parameter_pwmperiod:
//  {    
//    // int32_t pwm_number = ((int32_t)(syntax_get_text()[3]) - '0');     
//    // read_as_list_of(PARSER_TYPE_INTEGER);
//    // ok = pwm_write( pwm_number, nested_par[0].i, nested_par[1].i );    
//  }
//  break;
//  case Parameter_pwmduty:
//  {    
//    // int32_t pwm_number = ((int32_t)(syntax_get_text()[3]) - '0');     
//    // read_as_list_of(PARSER_TYPE_INTEGER);
//    // ok = pwm_write( pwm_number, nested_par[0].i, nested_par[1].i );    
//  }
//  break;
//
//  case Parameter_pwmconf:
//  {    
//    int32_t pwm_number = ((int32_t)(syntax_get_text()[3]) - '0');         
//    ok = pwm_conf( pwm_number );	  
//  }
//  break;
//  
//  case Parameter_ainconf:
//  {
//    // int32_t ain_number = ((int32_t)(syntax_get_text()[3]) - '0');       
//    // ok = ain_setup( ain_number, syntax_get_integer() );    
//  }
//  break;
//
//  case Parameter_ainref:
//  {
//    // int32_t ain_number = ((int32_t)(syntax_get_text()[3]) - '0');       
//    // ok = ain_setup( ain_number, syntax_get_integer() );
//  }
//  break;
//  
//  case Parameter_spidata:
//  {
//    // int32_t spi_number = ((int32_t)(syntax_get_text()[3]) - '0');       
//    // read_as_list_of(PARSER_TYPE_INTEGER);
//    // ok = spi_write(spi_number, int_list[0], int_list[1], int_list[2]);
//  }
//  break;
//
//  case Parameter_spiinbits:
//  {
//    // int32_t spi_number = ((int32_t)(syntax_get_text()[3]) - '0');       
//    // read_as_list_of(PARSER_TYPE_INTEGER);
//    // ok = spi_write(spi_number, int_list[0], int_list[1], int_list[2]);
//  }
//  break;
//
//  case Parameter_spiedge:
//  {
//    // int32_t spi_number = ((int32_t)(syntax_get_text()[3]) - '0');       
//    // read_as_list_of(PARSER_TYPE_INTEGER);
//    // ok = spi_write(spi_number, int_list[0], int_list[1], int_list[2]);
//  }
//  break;
//  
//  case Parameter_spicsneg:
//  {
//    // int32_t spi_number = ((int32_t)(syntax_get_text()[3]) - '0');       
//    // read_as_list_of(PARSER_TYPE_INTEGER);
//    // ok = spi_write(spi_number, int_list[0], int_list[1], int_list[2]);
//  }
//  break;
//
//  case Parameter_spiconf:
//  {
//    // int32_t spi_number = ((int32_t)(syntax_get_text()[3]) - '0');       
//    // read_as_list_of(PARSER_TYPE_INTEGER);
//    // ok = spi_setup(spi_number, int_list[0], int_list[1], int_list[2]);
//  }
//  break;
//  
//  //sets serial data
//  case Parameter_serdata:  
//  {
//    // int32_t ser_number = ((int32_t)(syntax_get_text()[3]) - '0');   
//    // read_as_list_of(PARSER_TYPE_INTEGER);
//    // ok = ser_setup(ser_number, int_list[0], int_list[1]);
//  }
//  break;
//
//  case Parameter_serconf:  
//  {
//    // int32_t ser_number = ((int32_t)(syntax_get_text()[3]) - '0');   
//    // read_as_list_of(PARSER_TYPE_INTEGER);
//    // ok = ser_setup(ser_number, int_list[0], int_list[1]);
//  }
//  break;
//  
//  case Parameter_serbaud:  
//  {
//    // int32_t ser_number = ((int32_t)(syntax_get_text()[3]) - '0');   
//    // read_as_list_of(PARSER_TYPE_INTEGER);
//    // ok = ser_setup(ser_number, int_list[0], int_list[1]);
//  }
//  break;
//  
//  case Parameter_sermode:  
//  {
//    // int32_t ser_number = ((int32_t)(syntax_get_text()[3]) - '0');   
//    // read_as_list_of(PARSER_TYPE_INTEGER);
//    // ok = ser_setup(ser_number, int_list[0], int_list[1]);
//  }
//  break;
//
//  
//  // sets DIO value
//  case Parameter_dio1:  
//  {
//    int32_t dio_number = ((int32_t)(syntax_get_text()[3]) - '0'); 
//	if(syntax_as_integer() == 2)	
//		ok = dio_set(dio_number, true) &&dio_set(dio_number, false);	
//	else if(syntax_as_integer() == 3)
//		ok = dio_set(dio_number, false) &&dio_set(dio_number, true);	
//	else 
//		ok = dio_set(dio_number, syntax_as_integer());
//  }
//  break;
//  case Parameter_dio2:  
//  {
//    int32_t dio_number = ((int32_t)(syntax_get_text()[3])-'0') * 10
//                        + ((int32_t)(syntax_get_text()[4])-'0');  
//    if(syntax_as_integer() == 2){
//		ok = dio_set(dio_number, 1) ;
//		dio_set(dio_number, 0);
//	}
//    else if(syntax_as_integer() == 3){
//	ok = dio_set(dio_number, 1) ;
//		dio_set(dio_number, 0);	
//	}    
//    else
//    ok = dio_set(dio_number, syntax_as_integer());
//  }
//  break;
//
//  case Parameter_dioconf:    
//  {	
//	  int32_t dio_number = ((int32_t)(syntax_get_text()[3])-'0') * 10
//                        + ((int32_t)(syntax_get_text()[4])-'0');  
//		ok = dio_conf(dio_number,syntax_as_integer());	
//  }  
//  break;  
//
//  case Parameter_dioseq1:
//  {
//	  int32_t dioseq_number = ((int32_t)(syntax_get_text()[6])-'0');    
//	  ok = sequencer_set_write_seq(dioseq_number,(const char*)syntax_as_bytearray());		 
//  }
//  break;
//  
//  case Parameter_dioseq2:
//  {
//	int32_t dioseq_number = ((int32_t)(syntax_get_text()[6])-'0') * 10
//							         + ((int32_t)(syntax_get_text()[7])-'0');
//    ok = sequencer_set_write_seq(dioseq_number,(const char*)syntax_as_bytearray());		
//  }
//  break;
//   
//  case Parameter_candata:
//  {
//    // TODO
//    // int32_t can_number = ((int32_t)(syntax_get_text()[3]) - '0');  
//    // ok = can_set(can_number,,)
//  }
//  break;
//
//  case Parameter_canconf:
//  {
//    // TODO
//    // int32_t can_number = ((int32_t)(syntax_get_text()[3]) - '0');     
//    // ok = can_setup(can_number);
//  }  
//  break;
//  
//  case Parameter_rel1:  
//  {    
//     int32_t rel_number = ((int32_t)(syntax_get_text()[3]) - '0');         
//	 ok = amis_39100_set(rel_number, syntax_as_integer());
//  }  
//  break;
//  case Parameter_rel2:  
//  {    
//     int32_t rel_number =  ((int32_t)(syntax_get_text()[3])-'0') * 10
//                        + ((int32_t)(syntax_get_text()[4])-'0');  
//   ok = amis_39100_set(rel_number, syntax_as_integer());
//  }  
//  break;
//
//  case Parameter_relconf:
//  {   	 
//	 ok  = amis_39100_conf(syntax_as_integer());	      
//  }  
//  break;
//
//  case Parameter_aout:
//  {
//    // TODO
//    // int32_t aout_number = ((int32_t)(syntax_get_text()[3]) - '0');    
//    // ok = aout_set(aout_number, syntax_as_integer());
//  }
//  break;
//
//  case Parameter_aoutconf:
//  {
//    // TODO
//    // int32_t aout_number = ((int32_t)(syntax_get_text()[3]) - '0');   
//    // read_as_list_of(PARSER_TYPE_INTEGER);
//    // ok = aout_setup(aout_number, int_list[0]);
//  }    
//  break;
//  
//  case Parameter_dds:
//  //TODO
//  break;
//  case Parameter_ddsconf:
//  //TODO
//  break;
//  
//
//  case Parameter_i2cdata:
//  {
//
//  }
//  break;
//
//  case Parameter_i2cconf:
//  {
//    // int32_t i2c_number = ((int32_t)(syntax_get_text()[3]) - '0');   
//  //TODO
//  }    
//  break;
//  
//  case Parameter_foutfreq:
//  {
////     read_as_list_of(PARSER_TYPE_INTEGER);
////     freqout_write(int_list[0], int_list[1]);
//  }
//  break;
//  
//  case Parameter_foutto:
//  {
//	  //     read_as_list_of(PARSER_TYPE_INTEGER);
//	  //     freqout_write(int_list[0], int_list[1]);
//  }
//  break;
//  
//  case Parameter_foutconf:
//  {
//    freqout_conf();
//  }    
//  break;
//  
//  case Parameter_extint:
//  //TODO
//  break;
//  
//  case Parameter_baudrate:
//  //TODO
//  //serial_comm_setup(baudrate);
//  break;
//  
//  case Parameter_sysfreq:
//  //TODO
//  //
//  break;
//  
//  case Parameter_eeprom:
//  //TODO
//  //
//  break;
//  }
//
//  serial_comm_puts( syntax_get_text() );
//  if( ok )
//  {
//		serial_comm_puts( ":ok " );
//  }
//  else 
//  {
//	  serial_comm_puts( ":err " );
//  }
//  return ok;
//}
//
////-------------------------------------------------------------------
////-------------------------------------------------------------------
//bool  get_parameter(int32_t p_id) {
//  bool ok = false;
//  
//    
//	serial_comm_puts(syntax_get_text());
//	parameter_out[0] = '=';
//  switch (p_id ) {
//
//  case Parameter_errors:
//  {
//    // TODO
//  }
//  break;
//  
//  case Parameter_version:
//  {
//    // TODO
//  }
//  break;
//
//
//  case Parameter_ain:
//  {
//    int32_t ain_number = ((int32_t)(syntax_get_text()[3]) - '0');  
//  }
//  break;  
//
//  case Parameter_spidata:
//  {
//    int32_t spi_number = ((int32_t)(syntax_get_text()[3]) - '0');  
//  }
//
//  break;  
//
//  case Parameter_serdata:
//  {
//    int32_t ser_number = ((int32_t)(syntax_get_text()[3]) - '0');  
//  }
//
//  break;  
//
//  case Parameter_dio2:
//  {
//	 bool value;
//	 int32_t dio_number = ((int32_t)(syntax_get_text()[3]) - '0') * 10
//	                     + ((int32_t)(syntax_get_text()[4]) - '0');	  
//	 ok =  dio_get(dio_number, &value);	 
//	 sprintf(parameter_out, "=%d ", value);
//  }
//  break;
//
//  case Parameter_dio1:
//  {
//	  bool value;
//	  int32_t dio_number = ((int32_t)(syntax_get_text()[3]) - '0') ;
//	  ok =  dio_get(dio_number, &value);
//	  sprintf(parameter_out, "=%d ", value);
//  }
//  break;
//   case Parameter_dioseq1:
//   {
//	   int32_t dioseq_number = ((uint32_t)(syntax_get_text()[6])-'0');
//	   ok = sequencer_get_data_as_hexarray(dioseq_number, &parameter_out[1]);
//   }
//   break; 
//  case Parameter_dioseq2:
//  {
//	int32_t dioseq_number = ((uint32_t)(syntax_get_text()[6])-'0') * 10
//							+ ((uint32_t)(syntax_get_text()[7])-'0');
//	ok = sequencer_get_data_as_hexarray(dioseq_number, &parameter_out[1]);  
//  }
//  break;
//  
//  case Parameter_candata:
//  {
//    int32_t can_number = ((int32_t)(syntax_get_text()[3]) - '0');  
//  }
//  break;  
//
//  case Parameter_finduty:
//  {
//    int32_t fin_number = ((int32_t)(syntax_get_text()[3]) - '0');  
//  }  
//  break;  
//
//  case Parameter_finperiod:
//  {
//    int32_t fin_number = ((int32_t)(syntax_get_text()[3]) - '0');  
//  }  
//  break;  
//
//  case Parameter_i2cdata:
//  {
//    int32_t i2c_number = ((int32_t)(syntax_get_text()[3]) - '0');  
//  } 
//  break;  
//
//  case Parameter_eeprom:
//  {
//
//  }
//  break;
//
//  }  
//  if(ok) 
//    {
//	  serial_comm_puts(parameter_out);
//	}
//  else 
//    {
//    serial_comm_puts( ":err " );	   
//	}
//  return ok;
//}
//
////-------------------------------------------------------------------
//bool run_command(void) {
//  bool result = false;
//  
//  return result;
//}

