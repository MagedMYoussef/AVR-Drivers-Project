/*
 * simple_7seg.c
 *
 * Created: 9/22/2015 11:26:13 PM
 *  Author: fadyf
 */ 

#include "simple_7seg.h"

uint8 initialize_7seg(Seven_SegConfig_t *object)
{
	//initializing data port
	uint8 count;
	if (object -> mode == DECODER) {
		for (count = 0; count < 4; count++)   //there is only 4 pins
			init_pin(object -> data_port, object -> data_pins[count], OUTPUT);
	}
	else if (object -> mode == NO_DECODER){
		for (count = 0; count < 7; count++)
			init_pin(object -> data_port, object -> data_pins[count], OUTPUT);
	}
	
	//initializing data pins
	init_pin(object -> control_port, object -> control_pin, OUTPUT);
	return TRUE;	 
}

uint8 display_digit(Seven_SegConfig_t *object,const uint8 digit)
{
	uint8 count, temp;   // temp is declared to mask some bits
	
	if(object -> mode == DECODER) {
		
		//writing control pin
		write_pin(object ->control_port, object -> control_pin, 1);
		
		//writing data pins
		temp = 0x01;   
		for(count = 0; count < 4; count++) {
			write_pin(object -> data_port, object -> data_pins[count],(digit & temp) >> count);   //to write each pin individually
			temp = temp << 1;
		}		
	}
	
	else if(object -> mode == NO_DECODER) {
		write_it(object, digit);
		
		//writing enable pin
		if (object -> type == COMMONCATHODE)
			write_pin(object -> control_port, object -> control_pin, 0);
		else 
			write_pin(object -> control_port, object -> control_pin, 1);
	}
	return TRUE;	
}

static void write_it(Seven_SegConfig_t *object, uint8 number)
{
	switch (number) {
		case 0 :
			write_port(object -> data_port, digit[0]);
			break;
		case 1 :
			write_port(object -> data_port, digit[1]);
			break;
		case 2 :
			write_port(object -> data_port, digit[2]);
			break;
		case 3 :
			write_port(object -> data_port, digit[3]);
			break;
		case 4 :
			write_port(object -> data_port, digit[4]);
			break;
		case 5 :
			write_port(object -> data_port, digit[5]);
			break;
		case 6 :
			write_port(object -> data_port, digit[6]);
			break;
		case 7 :
			write_port(object -> data_port, digit[7]);
			break;
		case 8 :
			write_port(object -> data_port, digit[8]);
			break;
		case 9 :
			write_port(object -> data_port, digit[9]);
			break;
	}
}