

#ifndef CMD_DATA_H
#define CMD_DATA_H

//*********************************************************

/*
        if getting sms format is #PPPP set parameter=1#
        if reading commands from FTP commands can be one after each other file should not exceed 512b
        separated with \r without any other symbols
        and if user wishes file to be deleted after reading place delete command ath the end
        example: set res=10 <CR> set period=10 <CR> set frames=10 <CR> delete [<CR>]
 */

#define SYNTAX_ITEMS \
    SYNTAX_ITEM("set"      ,Command_set             ,PARSER_TYPE_NO_TYPE),\
    SYNTAX_ITEM("get"      ,Command_get             ,PARSER_TYPE_NO_TYPE),\
    SYNTAX_ITEM("init"     ,Command_init            ,PARSER_TYPE_NO_TYPE),\
    SYNTAX_ITEM("selftest" ,Command_selftest        ,PARSER_TYPE_NO_TYPE),\
    SYNTAX_ITEM("signal"   , Parameter_signal      , PARSER_TYPE_INTEGER),\
    SYNTAX_ITEM("imp"      , Parameter_imp         , PARSER_TYPE_INTEGER),\
    SYNTAX_ITEM("pwr"      , Parameter_pwr         , PARSER_TYPE_INTEGER),\
    SYNTAX_ITEM("pot"      , Parameter_pot         , PARSER_TYPE_INTEGER),\
    SYNTAX_ITEM("ver"      , Parameter_ver         , PARSER_TYPE_INTEGER),\
    SYNTAX_ITEM("status"   , Parameter_status      , PARSER_TYPE_INTEGER),\
    SYNTAX_ITEM("acc"      , Parameter_acc         , PARSER_TYPE_INTEGER),\
    SYNTAX_ITEM("adr"      , Parameter_adr         , PARSER_TYPE_INTEGER),\
    SYNTAX_ITEM("error"    , Parameter_error       , PARSER_TYPE_INTEGER),\
    SYNTAX_ITEM("defaults" , Parameter_defaults    , PARSER_TYPE_INTEGER),\
    SYNTAX_ITEM("mod"      , Parameter_mod         , PARSER_TYPE_BYTEARRAY),\
    SYNTAX_ITEM("profile"  , Parameter_profile     , PARSER_TYPE_INTEGER),\
    SYNTAX_ITEM("pwrtrig"  , Parameter_pwrtrig     , PARSER_TYPE_INTEGER),\
    SYNTAX_ITEM("acctrig"  , Parameter_acctrig     , PARSER_TYPE_INTEGER),\
    SYNTAX_ITEM("triglev"  , Parameter_triglev     , PARSER_TYPE_INTEGER),\
    SYNTAX_ITEM("trigsum"  , Parameter_trigsum     , PARSER_TYPE_INTEGER),\
    SYNTAX_ITEM("trigcnt"  , Parameter_trigcnt     , PARSER_TYPE_INTEGER),\
    SYNTAX_ITEM("wavtole"  , Parameter_wavtole     , PARSER_TYPE_INTEGER),\
    SYNTAX_ITEM("wavtrig"  , Parameter_wavtrig     , PARSER_TYPE_INTEGER),\
    SYNTAX_ITEM("wavlcnt"  , Parameter_wavlcnt     , PARSER_TYPE_INTEGER),\
    SYNTAX_ITEM("wavrcnt"  , Parameter_wavrcnt     , PARSER_TYPE_INTEGER),\
    SYNTAX_ITEM("idid"     , Parameter_id          , PARSER_TYPE_INTEGER),\
    SYNTAX_ITEM("pswpsw"   , Parameter_psw         , PARSER_TYPE_INTEGER)\



#endif
