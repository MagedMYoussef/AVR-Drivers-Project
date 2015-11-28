/*
 * gpio.c
 *
 *  Created on: Sep 11, 2015
 *      Author: maged
 */

#include "gpio.h"

uint8 init_port(uint8 reg, uint8 val) {
	*(volatile uint8*) (reg + DIR_OFFSET) |= val;
	return TRUE;
}

uint8 write_port(uint8 reg, uint8 val) {
	*(volatile uint8*) (reg + OUT_OFFSET) = val;
	return TRUE;
}

uint8 init_pin(uint8 reg, uint8 pin_no, uint8 val) {
	if (0 != val && 1 != val)
		return FALSE;

	if (val)
		*(volatile uint8*) (reg + DIR_OFFSET) |= 1 << pin_no;
	else if (!val)
		*(volatile uint8*) (reg + DIR_OFFSET) &= ~(1 << pin_no);

	return TRUE;
}

uint8 write_pin(uint8 reg, uint8 pin_no, uint8 val) {
	if (0 != val && 1 != val)
		return FALSE;

	if (val)
		*(volatile uint8*) (reg + OUT_OFFSET) |= 1 << pin_no;
	else if (!val)
		*(volatile uint8*) (reg + OUT_OFFSET) &= ~(1 << pin_no);

	return TRUE;
}

uint8 read_pin(uint8 reg, uint8 pin_no) {

	uint8 val = *(volatile uint8*) (reg + INPUT_OFFSET) & 1 << pin_no;
	if (val)
		return 1;

	return 0;
}




