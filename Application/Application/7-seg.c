/*
 * _7_seg.c
 *
 * Created: 9/12/2015 9:16:56 AM
 *  Author: maged
 */ 
#include "7-seg.h"
#include <util/delay.h>

uint8 init_7seg (SEG_CONFIG_t * object) {
	uint8 i;
	if (object -> mode != DECODER && object -> mode != NO_DECODER)
		return FALSE;
		
	//for enables
	for (i = 0; i < object -> no_of_digits; i++) {
		init_pin(object -> control_port, i, OUTPUT);
	}
	
	//7-segment output initialization
	if(object -> mode == DECODER) {
		init_port(object -> data_port, 0x0F);
	}
	else if (object -> mode == NO_DECODER) {
		init_port(object -> data_port, 0x7F);
	}
	return TRUE;
}
/*
static uint8 separateData (SEG_CONFIG_t * object, uint8 number) {
	uint8 i, digit = number;
	for (i = 0; i < object -> no_of_digits; i++) {
		object -> digits_to_display [i] = digit % 10;
		digit /= 10;
	}
	return TRUE;
}

static uint8 controlDisplays (SEG_CONFIG_t * object) {
	uint8 i, j;
	for (i = 0; i < object -> no_of_digits; i++) {
		write_pin(object -> control_port, object -> enable[i], 1);	//for enable
		//disable other displays
		for (j = 0; j < object -> no_of_digits; j++) {
			if (i == j)
				continue;
			write_pin(object -> control_port, object -> enable[j], 0);
		}
		write_port(object -> data_port, object -> digits_to_display[i]);
	}
	return TRUE;
}
*/
uint8 display(SEG_CONFIG_t * object, uint8 number) {
	if(object -> mode == DECODER) {
		uint8 i, j;
		uint8  digits_to_display [10];
		//****hexa calc
		for (i = 0; i < (object -> no_of_digits); i++) {
			digits_to_display [i] = number % 10;
			number = number / 10;
		}
		//fe 7aga 3'alat hna 
		for (i = 0; i < object -> no_of_digits; i++) {
			write_pin(object -> control_port,i, 1);	//for enable
			//disable other displays
			for (j = 0; j < object -> no_of_digits; j++) {
				if (i == j)
					continue;
				write_pin(object -> control_port,j, 0);
			}
			write_port(object -> data_port,digits_to_display[i]);
			_delay_ms(100);
		}
	}
	else if(object -> mode == NO_DECODER) {
		if (object -> type == COMMONCATHODE) {
		}
		else if (object -> type == COMMONANODE) {
		}
	}
	return TRUE;
}