/*
 * _7_seg.h
 *
 * Created: 9/12/2015 9:15:46 AM
 *  Author: maged
 */ 


#ifndef SEG_H_
#define SEG_H_

#include "types.h"
#include "gpio.h"

typedef struct seg_config {
	uint8 mode;
	uint8 data_port;
	uint8 control_port;
	uint8 no_of_digits;
	//uint8 * digits_to_display;
	//uint8 * enable;
	uint8 type;
	} SEG_CONFIG_t;

uint8 init_7seg (SEG_CONFIG_t * object);
//static uint8 separateData (SEG_CONFIG_t * object, uint8 number);
//static uint8 controlDisplays (SEG_CONFIG_t * object);
uint8 display(SEG_CONFIG_t * object, uint8 number);

#endif /* 7-SEG_H_ */