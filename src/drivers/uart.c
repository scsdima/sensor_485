#include "uart.h"
#include "compiler.h"

void  uart_init(void )
{
    TRISCbits.TRISC7= TRUE;
    TRISCbits.TRISC6= TRUE;
    TXSTA   =   0b00100110;
    RCSTA   =   0b10010000;
    BAUDCTL =   0b00000000;
}

/* sends a string n-number bytes*/
void uart_puts(const CHAR *pstr, SIZE size)
{
    while(size-- && *pstr)
            {            
            uart_putc(*pstr);
            pstr++;
            }    
}

void uart_putc( CHAR byte)
{
	while( !uart_byte_sent() );
	TXREG = byte;	
}

BOOL uart_byte_sent(void)
{
    return TXIF;
}


BOOL uart_byte_received(void)
{
    return RCIF;
}

ResultSuccess_t uart_getc(CHAR *pbyte)
{
    ResultSuccess_t result = RESULT_FAIL;
    if ( uart_error()) 
    {
            uart_reset();            
    }
    else 
    if( uart_byte_received() )
    {
        *pbyte = RCREG;
        RCIF = 0;
        result = RESULT_SUCCESS;
    }
    return result;
}

 void uart_reset() 
{
    while(uart_error() || uart_byte_received())
        {   
            CREN = 0;   // uart disable
            RCREG;      // dummy read
            RCREG;      // dummy read
            CREN = 1;  //uart enable
        }   
}

BOOL uart_error() 
{
    return RCSTAbits.OERR || RCSTAbits.FERR ;
}

// void sci_SetSpeed(uint16 speed)
// {
//         SPBRGH = 0;
// 		SPBRG	=	(uint16)table_speed[speed];
// }