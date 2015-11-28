/*
 * lcd.h
 *
 * Created: 9/19/2015 9:49:17 AM
 *  Author: maged
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "types.h"
#include "gpio.h"

typedef struct lcd_config {
	uint8 command_port;
	uint8 data_port;
	uint8 mode;		//specify whether you will work with 4-bin or 8-bin connection
	uint8 RS;
	uint8 RW;
	uint8 EN;
	} LCD_CONFIG_t;

uint8 send_command(LCD_CONFIG_t * object, uint8 command);
uint8 send_char(LCD_CONFIG_t * object, uint8 data);
uint8 init_lcd(LCD_CONFIG_t * object);
uint8 send_string(LCD_CONFIG_t * object, uint8 * str, uint8 length);
#endif /* LCD_H_ */