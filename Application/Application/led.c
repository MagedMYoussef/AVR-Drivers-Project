/*
 * LED.c
 *
 *  Created on: Sep 11, 2015
 *      Author: maged
 */

#include "led.h"

uint8 init_led (uint8 reg, uint8 pin_no) {
	init_pin (reg, pin_no, OUTPUT);
	return TRUE;
}

uint8 led_on (uint8 reg, uint8 pin_no) {
	write_pin(reg, pin_no, 1);
	return TRUE;
}

uint8 led_off (uint8 reg, uint8 pin_no) {
	write_pin(reg, pin_no, 0);
	return TRUE;
}

uint8 led_toggle (uint8 reg, uint8 pin_no) {
	if (read_pin(reg, pin_no))
		led_off(reg, pin_no);
	else if (!read_pin(reg, pin_no))
		led_on(reg, pin_no);
	return TRUE;
}
