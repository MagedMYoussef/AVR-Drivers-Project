/*
 * LED.h
 *
 *  Created on: Sep 11, 2015
 *      Author: maged
 */

#ifndef LED_H_
#define LED_H_

#include "types.h"
#include "gpio.h"

uint8 init_led (uint8 reg, uint8 pin_no);
uint8 led_on (uint8 reg, uint8 pin_no);
uint8 led_off (uint8 reg, uint8 pin_no);
uint8 led_toggle (uint8 reg, uint8 pin_no);

#endif /* LED_H_ */
