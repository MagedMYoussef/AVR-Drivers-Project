/*
 * usart.h
 *
 * Created: 10/8/2015 11:41:27 AM
 *  Author: maged
 */ 


#ifndef USART_H_
#define USART_H_

#include "types.h"

typedef struct usart_config {
	uint8 port;		//specify the port where the serial communication occurs, by default it's port D (pin 0 & 1)
	uint8 oscillation_frequency;
	uint16 baud_rate;
	uint8 mode;		//Synchronous = 1 or Asynchronous = 0
	uint8 parity_mode;	//Disabled = 0, Reserved = 1, Even = 2, Odd = 3
	uint8 stop_bit_number;	// 1-bit = 0, 2-bit = 1
	uint8 character_size;	//from 5-bit to 9-bit
	uint8 clock_polarity;	// rising = 0, falling = 1
	uint8 transmission_speed_double;	//in Asynchronous mode only
	uint8 multiprocessor_mode;	//Multiprocessor = 1, Single processor = 0
	} USART_CONFIG_t;

uint8 USART_init (USART_CONFIG_t * object);
uint8 USART_transmit (USART_CONFIG_t * object, uint8 data);
uint8 USART_recieve (USART_CONFIG_t * object);

#endif /* USART_H_ */