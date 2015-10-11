#include "uart.h"
#include "compiler.h"

void  uart_init(void )
{    
    TXSTA   =   0b00100110;
    RCSTA   =   0b10010000;
    BAUDCTL =   0b00000000;
    BAUDCON =   0b00000000;    
    uart_set_baudrate(19200);
    // interrupts
    PIE1bits.RCIE=1;
    PIR1bits.RCIF=1;
}

void uart_set_baudrate(UINT24 baudrate)
{
    // TODO recalc on frequency
    SPBRG = 12;
    ///SPBRG = (uint16_t)(current_frequency/(64*baudrate))-1;
}

void uart_enable(BOOL on)
{
    RCSTA &= ~0x80;
    RCSTA |= (UINT8)on<<7;
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


BOOL uart_byte_available(void)
{
    return RC1IF;
}
ResultSuccess_t uart_getc(CHAR *pbyte)
{
    ResultSuccess_t result = RESULT_FAIL;
    if ( uart_error()) 
    {
            uart_reset();            
    }
    else 
    if( uart_byte_available() )
    {
        *pbyte = RCREG;
        RCIF = 0;
        result = RESULT_SUCCESS;
    }
    return result;
}

 void uart_reset() 
{
    while(uart_error() )
        {   
            CREN = 0;   // uart disable
            RCREG;      // dummy read
            RCREG;      // dummy read
            CREN = 1;  //uart enable
            while(uart_byte_available());
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