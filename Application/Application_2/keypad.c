/*
 * keybad.c
 *
 * Created: 9/18/2015 10:12:32 AM
 *  Author: fady
 */ 

#include "keypad.h"
#include <util/delay.h>

static uint8 row, column, flag = 1;

uint8 init_Pad(KeyPad_t *object)
{
	init_port(object -> data_port, 0x0F);
	write_port(object -> data_port, 0xFF);
	return TRUE;
}

uint8 read_button(KeyPad_t *object)
{	
	write_port(object ->data_port , 0xFF);
	//generating sequence
	for(row = 0; row < row_nums; row++)
	{
		write_pin(object -> data_port, (row), 0);
		for(column = 0; column < column_num; column++)
		{
			flag = read_pin(object -> data_port, (column+4));
			if (!flag)
				break;
		}
		if(!flag) {
			flag = 1;
			break;
		}	
		write_pin(object ->data_port, (row), 1);
	}
	_delay_ms(30);
	return digits[row][column];
}
