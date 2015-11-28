/*
 * types.h
 *
 *  Created on: Sep 11, 2015
 *      Author: maged
 */

#ifndef TYPES_H_
#define TYPES_H_


#define USER_DDRA 0x3A
#define USER_DDRB 0x37
#define USER_DDRC 0x34
#define USER_DDRD 0x31

#define TRUE 1
#define FALSE 0

#define OUTPUT 1
#define INPUT 0

#define PULLUP 1
#define PULLDOWN 0

typedef unsigned char uint8;
typedef unsigned int uint16;

//use decoder or not with the 7 segment
#define DECODER 1
#define NO_DECODER 0

//specify the type of the 7 segment display
#define COMMONCATHODE 0
#define COMMONANODE 1

//USART mode
#define SYNCHRONOUS 1
#define ASYNCHRONOUS 0

//USART Parity mode
#define DISABLED 0
#define RESERVED 1
#define EVEN 2
#define ODD 3

//USART Stop bit number
#define ONEBIT 0
#define TWOBIT 1

//USART Clock Polarity
#define RISING_TRANSMIT 0
#define FALLING_TRANSMIT 1

//USART Transmission speed double control
#define EN_DOUBLE_TX 1
#define DIS_DOUBLE_TX 0

//USART Multiprocessor control
#define MULTIPROCESSOR 1
#define SINGLEPROCESSOR 0

//USART Registers
#define USER_UDR   0x2C
#define USER_UCSRA 0x2B
#define USER_UCSRB 0x2A
#define USER_UCSRC 0x40
#define USER_UBRRH 0x40
#define USER_UBRRL 0x29
/*
//I2C Registers
#define I2C_DATA_REG		0x23
#define I2C_SLAVE_ADD_REG	0x22
#define I2C_STATUS_REG		0x21
#define I2C_BIT_RATE_REG	0x20
#define I2C_CONTROL_REG		0x56
*/

#endif /* TYPES_H_ */
