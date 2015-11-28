/*
 * switch.h
 *
 *  Created on: Sep 11, 2015
 *      Author: maged
 */

#ifndef SWITCH_H_
#define SWITCH_H_

#include "types.h"
#include "gpio.h"

uint8 init_switch (uint8 reg, uint8 pin_no);
uint8 read_switch (uint8 reg, uint8 pin_no, uint8 mode);

#endif /* SWITCH_H_ */
