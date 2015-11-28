/*
 * Name        : application.c
 * Author      : Maged
 * Version     :
 * Copyright   : Your copyright notice
 * Description : Hello World in C, Ansi-style
 */

#include "application_2.h"

int main(void) {
	USART_CONFIG_t usart_comm = {
		USER_DDRD,
		1000000,
		9600,
		ASYNCHRONOUS,
		DISABLED,
		ONEBIT,
		'8',
		RISING_TRANSMIT,
		DIS_DOUBLE_TX,
		SINGLEPROCESSOR
	};
	USART_init(&usart_comm);
	while (1) {
		_delay_ms(500);
		USART_recieve(&usart_comm);
	}	
	return 0;
}