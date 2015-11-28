/*
 * Name        : application.c
 * Author      : fady
 * Version     :
 * Copyright   : Your copyright notice
 * Description : Hello World in C, Ansi-style
 */

#include "I2C.h"

int main()
{
	while(1)
	{
		I2C_Transmit();
		I2C_Transmit();
	}
	return 0;
} 

/*#include "SPI.h"
#include "gpio.h"
#include <util/delay.h>

int main()
{
	SPI_t obj = {
		BASE_B ,
		6,5,7,4,
		1
	};
	init_slave(&obj);
	init_pin(BASE_B, 4, 1);
	write_pin(BASE_B, 0, 0);
	while(1)
	{
		SPI_tranceiver(15);
		_delay_ms(100);
	}	
}*/

/*#include "keypad.h"
#include "LCD.h"
#include <util/delay.h>

uint8 is_equal(uint8 *, uint8);
uint8 my_password[] = {1,2,3,4};
		
int main ()
{
	KeyPad_t pad1 ={BASE_B};
	init_Pad(&pad1);
	
	LCD_t lcd1 = {
		BASE_D,
		0,1,2,
		BASE_C,
		1
	};
	init_LCD(&lcd1);
	
	uint8 password[4];
	uint8 temp, count=0;
	uint16 pressed_confedence, released_confedence;
	
	while(1)	
	{
		if(button_pressed(&pad1)){
			pressed_confedence++;
			if(pressed_confedence > 200) {
			temp = read_button(&pad1);
			Send_Char(&lcd1, temp + '0');
			Send_Command(&lcd1, 0x14);
			password[count] = temp;
			count++; 
			_delay_ms(100);
			pressed_confedence = 0;
			}			
		}
		else {
			released_confedence = 0;
			if(released_confedence > 200)
				released_confedence = 0;
		}		
		if(is_equal(password,4))
			{
				Send_Command(&lcd1, 0x01);
				Send_String(&lcd1, "successful");
				_delay_ms(300);
				break;
			}		
	}
}


uint8 is_equal (uint8* password, uint8 length) {
	uint8 count,flag=0;
	for (count = 0; count < 4;count++)
	{
		if(*(password+count) !=*(my_password+count)) {
			flag = 1;
			break;
		}
	}
	if(flag)
		return FALSE;
	return TRUE;
}*/

/*#include "LCD.h"

int main()
{
	LCD_t lcd1 = {
		BASE_B,
		1,
		2,
		3,
		BASE_A,
		0
	};
	init_LCD(&lcd1);
	while(1)
	{
		Send_String(&lcd1, "fady");
		_delay_ms(1000);
		Send_Command(&lcd1, 0x01);
		_delay_ms(200);
	}
}*/

/*#include "keypad.h"
#include "simple_7seg.h"
#include <util/delay.h>

int main ()
{
	KeyPad_t key1 ={BASE_D};
	init_Pad(&key1);
	Seven_SegConfig_t seg1 ={
		NODECODER,
		BASE_C,
		0,1,2,3,4,5,6,
		BASE_C,
		7,
		COMMONCATHODE
	};
	initialize_7seg(&seg1);
	uint8 num;
	while(1)
	{
		if(button_pressed(&key1)){
			num = read_button(&key1);
			display_digit(&seg1,num);
			_delay_ms(100);
		}			
	}	
}*/



