#include "string_utils.h"


/* *********************************************************************
@Function name: string_utils_length
@Return: (unsigned char)
@Parameters:
 const char pstr - calculates length of string
@Description: - detects string length
********************************************************************* */
INT16 string_utils_strlen(const char pstr[])
{
    INT16 i = 0;
    if (pstr)
    {
        for (; i < STRING_UTILS_MAX_LEN; i++)
        {
            if (! string_utils_is_symbol(pstr[i]))
            {
                break;
            }
        }
    }
    return i;
}


/* *********************************************************************
@Function name: string_utils_remove_quotations
@Return: (void)
@Parameters:
    char *dst
     const char* src
@Description: - Removes  all quotations in text.
               Is allowed to have the same string pointer

********************************************************************* */
INT16 string_utils_remove_symbol(char *pdst, const char *psrc, char symb)
{
    INT16 i, j = 0;
    if (pdst != NULL && psrc != NULL)
    {
        for (i = 0; i < STRING_UTILS_MAX_LEN; i++)
        {
            if (psrc[i] == '\0' ) { break; }
            if (psrc[i] != symb )
            {
                pdst[j++] = psrc[i];
            }
        }
        pdst[j] = '\0';
    }
    return j;
}

/* *********************************************************************
@Function name: string_utils_copy
@Return: (void)
@Parameters:
    char pdst
    const char psrc[]
    const INT maxlen
@Description: - Copies string

********************************************************************* */
INT16 string_utils_copy(char pdst[], const char psrc[], INT16 maxlen)
{
    INT16 result = -1;
    if (psrc != NULL)
    {
        while (*psrc != '\0' && maxlen--)
        {
            result++;
            *pdst++ = *psrc++;
        }
        result++;
    }
    return result;
}

/* *********************************************************************
@Function name: string_utils_split
@Return: (uINT16)  - number of chains
@Parameters:
    char pbuf[] - buffer to get data to
    const char pstr[] - string from
    uINT16 len - length of data
    char delimeter - delimeter
@Description:
 This function cuts the sring on a words with one \0 behind every word

********************************************************************* */
INT16 string_utils_split(char pbuf[], const char pstr[], INT16 len, char delimeter)
{
    INT16 i = 0;
    INT16 chains = 0;
    char prev = ' ';
    while (1)
    {
        char symb = pstr[i];
        if (symb == ' ' || len == 0)
        {
            if (prev != ' ')
            {
                *pbuf = delimeter;
                pbuf++;
                chains++;
            }
        }
        else
        {
            *pbuf++ = symb;
        }
        if (len == 0)
        {
            break;
        }
        else
        {
            len--;
            i++;
            prev = symb;
        }
    }
    *pbuf++ = delimeter;
    return chains;
}


/* *********************************************************************
@Function name: string_utils_strchr
@Return: (INT16) - position number if not found returns 0
@Parameters:
    const char pbuf[] - buffer of data bytes
    char delimeter -  delimeter data
@Description:- finds delimeter, first occurence

********************************************************************* */
INT16 string_utils_strchr(const char pbuf[], char delimeter)
{
    INT16 result = -1;
    if (pbuf != NULL)
    {
        INT16 pos;
        for (pos = 0; (pos < STRING_UTILS_MAX_LEN) && pbuf[pos]; pos++)
        {
            if (pbuf[pos] == delimeter)
            {
                result = pos;
                break;
            }
        }
    }
    return result;
}


/* *********************************************************************
@Function name: string_utils_is_letter_upper
@Return: (BOOL)
@Parameters:
    char symb - symbol
@Description:
        detects high letters
********************************************************************* */
BOOL string_utils_is_upper_case(char symb)
{
    return (symb >= 'A') && (symb <= 'Z');
}

/* *********************************************************************
@Function name: string_utils_is_lower_case
@Return: (BOOL)
@Parameters:
    char symb - symbol
@Description:
        detects high letters
********************************************************************* */
BOOL string_utils_is_lower_case(char symb)
{
    return (symb >= 'a') && (symb <= 'z');
}


/* *********************************************************************
@Function name: string_utils_is_upper_case
@Return: (BOOL)
@Parameters:
    char symb - symbol
@Description:
        detects high letters
********************************************************************* */
BOOL string_utils_is_symbol(char symb)
{
    return (symb >= ' ') && (symb <= '~');
}

/* *********************************************************************
@Function name: string_utils_is_letter
@Return: (BOOL)
@Parameters:
    char symb - symbol
@Description:
        detects if it is letter a..z or A..Z
********************************************************************* */
BOOL string_utils_is_letter(char symb)
{
    return string_utils_is_lower_case(symb) || string_utils_is_upper_case(symb);
}

/* *********************************************************************
@Function name: string_utils_to_lower_case
@Return: (void)
@Parameters:
    char pstr - string pointer
@Description:
    changes all letters to low case
********************************************************************* */
void string_utils_to_lower_case(char pstr[])
{
    INT16 i = 0;
    INT16 maxlen = STRING_UTILS_MAX_LEN;
    while (pstr[i] && maxlen--)
    {
        if ( string_utils_is_upper_case(pstr[i]) )
        {
            pstr[i] = fromUpperToLower(pstr[i]);
        }
        i++;

    }
}

/* *********************************************************************
@Function name: string_utils_to_upper_case
@Return: (void)
@Parameters:
    char pstr - string pointer
@Description:
    changes all letters to upper case
********************************************************************* */
void string_utils_to_upper_case(char pstr[])
{
    INT16 i = 0;
    INT16 maxlen = STRING_UTILS_MAX_LEN;
    while (pstr[i] && maxlen--)
    {
        if ( string_utils_is_lower_case(pstr[i]) )
        {
            pstr[i] = fromLowerToUpper(pstr[i]);

        }
        i++;
    }
}

/* *********************************************************************
@Function name: string_utils_strcmp
@Return: (void)
@Parameters:
    char pstr1,pstr2 - string1 compare to string2

@Description:
    compres two string  and its' length
********************************************************************* */
BOOL string_utils_strcmp(const char pstr1[], const char pstr2[], BOOL case_sensitive)
{
    BOOL result = FALSE;
    if (pstr1 != NULL && pstr2 != NULL )
    {
        INT16 len1 = string_utils_strlen(pstr1);
        INT16 len2 = string_utils_strlen(pstr2);
        if (len1 == len2)
        {
            result = string_utils_strncmp(pstr1, pstr2, len1, case_sensitive);
        }
    }
    return result;
}


/* *********************************************************************
@Function name: string_utils_strncmp
@Return: (void)
@Parameters:
    char pstr1,pstr2 - string1 compare to string2

@Description:
    compres two string  and its' length
********************************************************************* */
BOOL string_utils_strncmp(const char pstr1[], const char pstr2[], INT16 len, BOOL case_sensitive)
{
    BOOL result = FALSE;
    if (pstr1 != NULL && pstr2 != NULL )
    {
        INT16 pos = 0;
        while ( len-- )
        {
            char symb1 = pstr1[pos];
            char symb2 = pstr2[pos];
            //all compare as upper case
            if ( !case_sensitive )
            {
                if ( string_utils_is_upper_case(symb1) )
                {
                    symb1 = fromUpperToLower(symb1);
                }
                if ( string_utils_is_upper_case(symb2) )
                {
                    symb2 = fromUpperToLower(symb2);
                }
            }
            if (symb1 == symb2 || symb1 == '?' || symb2 == '?')
            {
                result = TRUE;
            }
            else
            {
                result = FALSE;
                break;
            }
            pos++;
        }
    }
    return result;
}

BOOL string_utils_is_digit(char symb)
{
    return (symb >= '0' && symb <= '9');
}

UINT8 symb_from_hex_to_bin(char symb)
{
    switch (symb)
    {
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
        return (UINT8)(symb - '0');
    case 'a':
    case 'b':
    case 'c':
    case 'd':
    case 'e':
    case 'f':
        return (UINT8)(symb - 'a') + 10;
    case 'A':
    case 'B':
    case 'C':
    case 'D':
    case 'E':
    case 'F':
        return (UINT8)(symb - 'A') + 10;
    }
    return 0;
}

char string_utils_toHex(unsigned char byte)
{
    char result;
    switch (byte)
    {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
        result = byte + '0';
        break;
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
        result = byte - 10 + 'a';
        break;
    default:
        result = ' ';
        break;
    }
    return result;
}


INT16 string_utils_from_hex(UINT8 *pdata, const char* phex_str)
{
    INT16 i = 0;
    INT16 j = 0;
    INT16 len = string_utils_strlen(phex_str);
    while (i < (len - 1))
    {
        pdata[j] =  symb_from_hex_to_bin(phex_str[i]) * 16
                    + symb_from_hex_to_bin(phex_str[i + 1]);
        i += 2; j++;
    }
    return j;
}