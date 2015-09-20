/*
 * gpio.h
 *
 *  Created on: Sep 11, 2015
 *      Author: maged
 */

#ifndef GPIO_H_
#define GPIO_H_

#include "hw_gpio.h"

uint8 init_port(uint8 reg, uint8 value);
uint8 write_port(uint8 reg, uint8 val);
uint8 init_pin(uint8 reg, uint8 pin_no, uint8 val);
uint8 write_pin(uint8 reg, uint8 pin_no, uint8 val);
uint8 read_pin(uint8 reg, uint8 pin_no);

#endif /* GPIO_H_ */
