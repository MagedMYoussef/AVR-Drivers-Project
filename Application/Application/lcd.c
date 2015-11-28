/*
 * lcd.c
 *
 * Created: 9/19/2015 9:49:03 AM
 *  Author: maged
 */ 

#include "lcd.h"
#include <util/delay.h>

uint8 send_command(LCD_CONFIG_t * object, uint8 command) {
	write_pin(object -> command_port, object ->RS, 0);
	write_pin(object ->command_port, object -> RW, 0);
	
	write_port(object ->data_port, command);
	
	//latching from high to low -- data must be sent before latching
	write_pin(object ->command_port, object -> EN, 0);
	_delay_us(10);
	write_pin(object ->command_port, object -> EN, 1);
	_delay_us(100);
	
	if (command == 0x01 || command == 0x02) {
		_delay_ms(2);
		return TRUE;
	}
	
	_delay_us(50);
	return TRUE;
}

uint8 send_char(LCD_CONFIG_t * object, uint8 data) {
	write_pin(object -> command_port, object ->RS, 1);
	write_pin(object ->command_port, object -> RW, 0);
	
	write_port(object ->data_port, data);
	
	//latching from high to low -- data must be sent before latching	
	write_pin(object ->command_port, object -> EN, 0);
	_delay_us(10);
	write_pin(object ->command_port, object -> EN, 1);
	_delay_us(100);
	return TRUE;
}

uint8 send_string(LCD_CONFIG_t * object, uint8 * str, uint8 length) {
	uint8 i;
	for (i = 0; i < length; i++) {
		send_char(object, *(str + i));
		_delay_ms(100);
		send_command(object, 0x14);
	}
	return TRUE;
}

uint8 init_lcd(LCD_CONFIG_t * object) {
	_delay_us(15);
	
	init_port(object ->command_port, 0xFF);
	init_port(object ->data_port, 0xFF);
	send_command(object, 0x38);
	send_command(object, 0x0E);
	send_command(object, 0x01);
	
	return TRUE;
}