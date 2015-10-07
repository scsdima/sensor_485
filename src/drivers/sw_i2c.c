
#include "compiler.h"
#include "config.h"
#include "sw_i2c.h"

static UINT16 this_gpio_sda;

static UINT16 this_gpio_scl;

volatile UINT8 i2c_buff; // temp buffer for R/W operations
volatile UINT8 bitcount; // temp buffer for bit counting


 ResultError_t this_clock_test1(void);

#define PULSE_DUTY (200)

#ifdef __TIMER_DELAY
#include "delay.h"
#define this_delay_i2c  delay_ms
#else

/********************************************************************** 
  @Function name: this_delay_i2c
  @Return: ( void ) 
  @Parameters: 
             
	volatile UINT16 tmr 
  @Description: ---

**********************************************************************/

static 
void this_delay_i2c(volatile UINT16 tmr) {
    while (tmr--) {
        Nop();
    };
}
#endif


#define  SW_I2C_SDA_LOW   //do{gpio_set(this_gpio_sda, FALSE);\
                          //   gpio_setup(this_gpio_sda, GPIO_OUT);\
                          //}while(0) //TRISBbits.TRISB13 = 0; // define macro for data pin output
#define  SW_I2C_SDA_HI    //gpio_setup(this_gpio_sda, GPIO_IN)  //TRISBbits.TRISB13= 1; // define macro for data pin input
#define  SW_I2C_SDA_PIN   1//gpio_get(this_gpio_sda)         // define macro for data pin


#define  SW_I2C_SCL_LOW  //do{gpio_set(this_gpio_scl, FALSE);\
                         // gpio_setup(this_gpio_scl, GPIO_OUT);\
                         //}while(0)//TRISBbits.TRISB12 = 0; // define macro for clock pin output
#define  SW_I2C_SCL_HI   // gpio_setup(this_gpio_scl, GPIO_IN)  //TRISBbits.TRISB12 = 1; // define macro for clock pin input
#define  SW_I2C_SCL_PIN  1 //gpio_get(this_gpio_scl)        // define macro for clock pin


/********************************************************************** 
  @Function name: sw_i2c_switch
  @Return: ( void ) 
  @Parameters: 
             
	UINT16 gpio_sda
	 UINT16 gpio_scl 
  @Description: ---

**********************************************************************/
void sw_i2c_switch(UINT16 gpio_sda, UINT16 gpio_scl) {
    this_gpio_sda = gpio_sda;
    this_gpio_scl = gpio_scl;
}


/********************************************************************** 
  @Function name: sw_i2c_write_nak
  @Return: ( void ) 
  @Parameters: 
             
	void 
  @Description: ---

**********************************************************************/
void sw_i2c_write_nak(void) {
    SW_I2C_SCL_LOW;
    SW_I2C_SDA_HI;
    this_delay_i2c(PULSE_DUTY);
    SW_I2C_SCL_HI;
    this_delay_i2c(PULSE_DUTY);
}


/********************************************************************** 
  @Function name: sw_i2c_write_ack
  @Return: ( void ) 
  @Parameters: 
             
	void 
  @Description: ---

**********************************************************************/
void sw_i2c_write_ack(void) {
    SW_I2C_SDA_LOW;
    this_delay_i2c(PULSE_DUTY);
    SW_I2C_SCL_HI;
    this_delay_i2c(PULSE_DUTY);
}


/********************************************************************** 
  @Function name: sw_i2c_start
  @Return: ( void ) 
  @Parameters: 
             
	void 
  @Description: ---

**********************************************************************/
void sw_i2c_start(void) {
    SW_I2C_SCL_HI;
    SW_I2C_SDA_HI;
    this_delay_i2c(PULSE_DUTY);
    SW_I2C_SDA_LOW; // set pin to output to drive low
    this_delay_i2c(2 * PULSE_DUTY);
}


/********************************************************************** 
  @Function name: sw_i2c_restart
  @Return: ( void ) 
  @Parameters: 
             
	void 
  @Description: ---

**********************************************************************/
void sw_i2c_restart(void) {
    this_delay_i2c(2 * PULSE_DUTY);
    SW_I2C_SCL_LOW; // set clock pin to output to drive low
    SW_I2C_SDA_HI; // release data pin to float high
    this_delay_i2c(PULSE_DUTY); // user may need to modify based on Fosc
    SW_I2C_SCL_HI; // release clock pin to float high
    this_delay_i2c(PULSE_DUTY); // user may need to modify based on Fosc
    SW_I2C_SDA_LOW; // set data pin output to drive low
    this_delay_i2c(PULSE_DUTY); // user may need to modify based on Fosc
}


/********************************************************************** 
  @Function name: sw_i2c_stop
  @Return: ( void ) 
  @Parameters: 
             
	void 
  @Description: ---

**********************************************************************/
void sw_i2c_stop(void) {
    this_delay_i2c(PULSE_DUTY);
    SW_I2C_SCL_LOW; // set clock pin to output to drive low
    SW_I2C_SDA_LOW; // set data pin output to drive low
    this_delay_i2c(PULSE_DUTY); // user may need to modify based on Fosc
    SW_I2C_SCL_HI; // release clock pin to float high
    this_delay_i2c(PULSE_DUTY); // user may need to modify based on Fosc
    SW_I2C_SDA_HI; // release data pin to float high
    SW_I2C_SCL_HI;
   this_delay_i2c(2 * PULSE_DUTY);
}


/********************************************************************** 
  @Function name: sw_i2c_read_ack
  @Return: ( ResultError_t ) 
  @Parameters: 
             
	void 
  @Description: ---

**********************************************************************/
ResultError_t sw_i2c_read_ack(void) {
    SW_I2C_SCL_LOW; // set clock pin to output to drive low
    SW_I2C_SDA_HI; // release data line to float high
    this_delay_i2c(PULSE_DUTY / 2); // user may need to modify based on Fosc
    SW_I2C_SCL_HI; // release clock line to float high
    this_delay_i2c(PULSE_DUTY); // 1 cycle delay
    if (SW_I2C_SDA_PIN) { // error if ack = 1, slave did not ack
        return ( RESULT_ERROR); // return with acknowledge error
    }
    return ( RESULT_NO_ERROR); // return with no error
}


/********************************************************************** 
  @Function name: this_clock_test1
  @Return: ( ResultError_t ) 
  @Parameters: 
             
	void 
  @Description: ---

**********************************************************************/
ResultError_t this_clock_test1(void) {
    this_delay_i2c(2 * PULSE_DUTY); // user may need to adjust timeout period
    if (!SW_I2C_SCL_PIN) { // if clock is still low after wait
        return ( RESULT_NULL); // return with clock error
    }
    return ( RESULT_NO_ERROR); // return with no error
}


/********************************************************************** 
  @Function name: sw_i2c_read_byte
  @Return: ( ResultError_t ) 
  @Parameters: 
             
	UINT8 *byte 
  @Description: ---

**********************************************************************/
ResultError_t sw_i2c_read_byte(UINT8 *byte) {
    bitcount = 8; // set bit count for byte
    i2c_buff = 0;

    while (bitcount--) // stay until 8 bits have been acquired
    {
        SW_I2C_SCL_LOW; // set clock pin output to drive low
        SW_I2C_SDA_HI; // release data line to float high
        this_delay_i2c(PULSE_DUTY); // user may need to modify based on Fosc
        SW_I2C_SCL_HI; // release clock line to float high
        this_delay_i2c(PULSE_DUTY / 5);
        if (!SW_I2C_SCL_PIN) // test for clock low
        {
            if (this_clock_test1() != RESULT_NO_ERROR) {// clock wait routine
                return RESULT_NULL; // return with error condition
            }
        }
        i2c_buff <<= 1; // shift composed byte by 1
        i2c_buff &= (0xFEu); // clear bit 0

        if (SW_I2C_SDA_PIN) // is data line high
            i2c_buff |= 0x01; // set bit 0 to logic 1
    }
    *byte = i2c_buff;
    return ( RESULT_NO_ERROR); // return with data
}


/********************************************************************** 
  @Function name: sw_i2c_write_byte
  @Return: ( ResultError_t ) 
  @Parameters: 
             
	UINT8 byte 
  @Description: ---

**********************************************************************/
ResultError_t sw_i2c_write_byte(UINT8 byte) {
    bitcount = 8;
    i2c_buff = byte;
    SW_I2C_SCL_HI;
    while (bitcount--) {
        if (!SW_I2C_SCL_PIN) {
            if (this_clock_test1() != RESULT_NO_ERROR) {
                return ( RESULT_ERROR);
            }
        }
        SW_I2C_SCL_LOW;
        if (i2c_buff & 0x80) {//LOG 1
            SW_I2C_SDA_HI;
        } else //LOG 0
        {
            SW_I2C_SDA_LOW;
        }
        i2c_buff <<= 1;
        this_delay_i2c(PULSE_DUTY);
        SW_I2C_SCL_HI;
        this_delay_i2c(PULSE_DUTY);
    }
    return sw_i2c_read_ack();
}


