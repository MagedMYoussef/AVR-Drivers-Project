/*
 * simple_7seg.h
 *
 * Created: 9/22/2015 11:26:35 PM
 *  Author: fadyf
 */ 


#ifndef SIMPLE_7SEG_H_
#define SIMPLE_7SEG_H_

#include "gpio.h"

typedef struct Seven_SegConfig {
	uint8 mode;
	uint8 data_port;
	uint8 data_pins[7];
	uint8 control_port;
	uint8 control_pin;
	uint8 type;	
}Seven_SegConfig_t;

static uint8 digit[] ={0x7E, 0x30, 0x6D, 0x79, 0x33, 0x5B, 0x5F, 0x70, 0x7F, 0x7B, 0xFF};  //digits to display in case of NODECODER 7-segment.

uint8 initialize_7seg(Seven_SegConfig_t *);
uint8 display_digit(Seven_SegConfig_t *,const uint8);
static void write_it(Seven_SegConfig_t *, uint8);
#endif /* SIMPLE_7SEG_H_ */