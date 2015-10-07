

#ifndef CMD_DATA_H
#define CMD_DATA_H

#include "syntax.h"

    typedef enum {
    Command_set,
    Command_get,
    Command_init,
    Command_selftest,
    COMMAND_COUNT
}SyntaxCommandId_t;

typedef enum {
    Parameter_signal,
    Parameter_imp,
    Parameter_pwr,
    Parameter_pot,        
    Parameter_ver,
    Parameter_status,
    Parameter_error,
    Parameter_acc,
    Parameter_adr,
    Parameter_defaults,
    Parameter_mod,
    Parameter_profile,       
    Parameter_pwrtrig,
    Parameter_acctrig,        
    Parameter_triglev,
    Parameter_trigsum,
    Parameter_trigcnt,
    Parameter_wavtole,
    Parameter_wavtrig,
    Parameter_wavlcnt,
    Parameter_wavrcnt,    
    Parameter_id,
    Parameter_psw,
    PARAMETERS_COUNT
}SyntaxParameterId_t;

//*********************************************************

/*
        if getting sms format is #PPPP set parameter=1#
        if reading commands from FTP commands can be one after each other file should not exceed 512b
        separated with \r without any other symbols
        and if user wishes file to be deleted after reading place delete command ath the end
        example: set res=10 <CR> set period=10 <CR> set frames=10 <CR> delete [<CR>]
 */


#define END_BLOCK   "\x1d\x1d"
/************************************************************
 *						Commands set
 *************************************************************/
static const SyntaxCommand_t syx_cmd_list[] = 
    {
        {"set",         Command_set         },
        {"get",         Command_get         },
        {"init",        Command_init        },
        {"selftest",    Command_selftest    },        
        {END_BLOCK     , 0                  }  
    };


static const SyntaxParameter_t syx_param_list[] = {
    /*get values*/
    {"signal"   , Parameter_signal      , PARSER_TYPE_INTEGER}, //R
    {"imp"      , Parameter_imp         , PARSER_TYPE_INTEGER}, //R
    {"pwr"      , Parameter_pwr         , PARSER_TYPE_INTEGER}, //R
    {"pot"      , Parameter_pot         , PARSER_TYPE_INTEGER}, //RW Config.PotentiometerValue(pos)        
    {"ver"      , Parameter_ver         , PARSER_TYPE_INTEGER}, //R    
    {"status"   , Parameter_status      , PARSER_TYPE_INTEGER}, //R
    {"acc"      , Parameter_acc         , PARSER_TYPE_INTEGER}, // R State.acc_val
    {"adr"      , Parameter_adr         , PARSER_TYPE_INTEGER}, // R State.acc_val
    {"error"    , Parameter_error       , PARSER_TYPE_INTEGER}, // R State.acc_val
    {"defaults" , Parameter_defaults    , PARSER_TYPE_INTEGER},
    {"mod"      , Parameter_mod         , PARSER_TYPE_BYTEARRAY}, //WR Config.DetectionMode
    {"profile"  , Parameter_profile     , PARSER_TYPE_INTEGER}, //RW Config.PotentiometerValue(pos)
    {"pwrtrig"  , Parameter_pwrtrig     , PARSER_TYPE_INTEGER}, //WR
    {"acctrig"  , Parameter_acctrig     , PARSER_TYPE_INTEGER}, //WR        
    {"triglev"  , Parameter_triglev     , PARSER_TYPE_INTEGER}, //WR Config.DetectionConfig.ClassicTriggerValue
    {"trigsum"  , Parameter_trigsum     , PARSER_TYPE_INTEGER}, //WR Config.DetectionConfig.ClassicTriggerSum
    {"trigcnt"  , Parameter_trigcnt     , PARSER_TYPE_INTEGER}, //WR Config.DetectionConfig.ClassicTriggerCount
    {"wavtole"  , Parameter_wavtole     , PARSER_TYPE_INTEGER}, //WR
    {"wavtrig"  , Parameter_wavtrig     , PARSER_TYPE_INTEGER}, //WR
    {"wavlcnt"  , Parameter_wavlcnt     , PARSER_TYPE_INTEGER}, //WR
    {"wavrcnt"  , Parameter_wavrcnt     , PARSER_TYPE_INTEGER},//WR    
    {"idid"     , Parameter_id          , PARSER_TYPE_INTEGER},//WR
    {"pswpsw"   , Parameter_psw         , PARSER_TYPE_INTEGER},//WR
    {END_BLOCK  ,-1                     , PARSER_TYPE_NO_TYPE  }

};


#endif
