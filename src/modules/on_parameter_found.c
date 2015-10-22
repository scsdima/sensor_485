#include "syntax.h"
#include "cmd_data.h"
#include "serialport.h"
#include "potentiometer.h"
#include "config.h"
#include "detection.h"



static BOOL set_parameter(INT8 p_id);
static BOOL run_command(void);
static BOOL ok;
static UINT16 u16_value;

void on_parameter_found(ParserOperation_t operation, INT8 cmd_id
                        , INT8 p_id, const void* p)
{


    if (operation == PARSER_PARAMETER) {
        ok = FALSE;
        switch (cmd_id) {
        case Command_set:
            switch (p_id) {

            case Parameter_signal:
                break;

            case Parameter_pot:
                u16_value = syntax_as_integer();                
                ok =potentiometer_set(u16_value);
                break;

            case Parameter_mod:
                // TODO
                break;

            case Parameter_profile:
                ok = detection_profile_set(syntax_as_integer());
                break;

            case Parameter_pwrtrig:
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
                ok = detection_defaults_set();
                break;

            case Parameter_id:
                // TODO id
                break;

            case Parameter_psw:
                // TODO psw
                break;

            }
            serialport_write(syntax_get_text());
            if (ok) {
                serialport_write(":ok ");
            } else {
                serialport_write(":err ");
            }

            break;

        case Command_get:
            ok = FALSE;
            serialport_write(syntax_get_text());
            switch (p_id) {

            case Parameter_signal:
                printf("=%d\n", adc_read(1));
                ok = TRUE;
                break;
            case Parameter_imp:
                printf("=%d", adc_read(1));
                ok = TRUE;
                break;
            case Parameter_pwr:
                printf("=%d\n", adc_read(2));
                ok = TRUE;
                break;
            case Parameter_pot:
                printf("=%d", potentiometer_value());
                ok = TRUE;
                break;
            case Parameter_ver:
                break;
            case Parameter_status:
                break;
            case Parameter_acc:
                break;
            case Parameter_adr:
                break;
            case Parameter_error:
                break;
            case Parameter_defaults:
                break;
            case Parameter_mod:
                break;
            case Parameter_profile:
                break;
            case Parameter_pwrtrig:
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
            case Parameter_id:
                break;
            case Parameter_psw:
                break;
            }
            if (!ok) {
                serialport_write(":err ");
            }
            break;

        default:
            break;
        }
    }
    else if (operation == PARSER_STOP) {
        //      if(cmd_id==Command_reset)
        //      {
        //          // TODO reset();
        //      }
    }
    else if (operation == PARSER_ERROR) {
        serialport_write("err\n");
    }
}
