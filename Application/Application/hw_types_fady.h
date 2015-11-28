/*
 * hw_types.h
 *
 * Created: 10/5/2015 11:28:13 PM
 *  Author: fadyf
 */ 


#ifndef HW_TYPES_H_
#define HW_TYPES_H_

#include "types.h"
#include "hw_gpio.h"

//timer-counter configuration
#define TIMERCONTROL0 0x53
#define COUNTER_OFFSET 1   //every counter register is 1 before control register.

//SPI configuration
#define SERIAL_CTRL_REG 0x2D
#define SERIAL_STATUS_REG 0x2E
#define SERIAL_DATA_REG 0x2F

//USART configuration
#define USART_DATA_REG 0x2C
#define USART_CONTROL_REG_A 0x2B
#define	USART_CONTROL_REG_B 0x2A
#define	USART_CONTROL_REG_C 0x40
#define USART_BAUDRATE_HIGH 0x40
#define USART_BAUDRATE_LOW  0x29

//I2C configuration
#define I2C_DATA_REG			0x23
#define I2C_SLAVE_ADRESS_REG    0x22
#define I2C_STATUS_REG			0x21
#define I2C_BIT_RATE_REG		0x20
#define I2C_CONTROL_REG			0x56

uint8 reg8_init_pin(uint8, uint8, uint8);
uint8 reg8_write_pin(uint8, uint8, uint8);
uint8 reg8_read_pin(uint8, uint8);
uint8 reg8_init_port(uint8, uint8);
uint8 reg8_write_port(uint8, uint8, uint8);
uint8 reg8_read_port(uint8);

#endif /* HW_TYPES_H_ */