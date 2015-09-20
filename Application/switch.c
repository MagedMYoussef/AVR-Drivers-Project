/*
 * switch.c
 *
 *  Created on: Sep 11, 2015
 *      Author: maged
 */
#include "switch.h"

uint8 init_switch (uint8 reg, uint8 pin_no) {
	init_pin(reg, pin_no, INPUT);
	return TRUE;
}

uint8 read_switch (uint8 reg, uint8 pin_no, uint8 mode) {
	if (mode == PULLUP) {
		return read_pin(reg, pin_no);	
	}
	else if (mode == PULLDOWN){
		return !(read_pin(reg, pin_no));
	}
}

