/*
 * keybad.h
 *
 * Created: 9/18/2015 10:13:42 AM
 *  Author: fadyf
 */ 


#ifndef KEYBAD_H_
#define KEYBAD_H_

#include "gpio.h"
#include "types.h"

#define row_nums 4
#define column_num 4

static uint8 digits[4][4] = {{7,4,1,0},{8,5,2,0},{9,6,3,0},{1,4,8,9}};

typedef struct KeyPad {
	uint8 data_port;
} KeyPad_t;


uint8 init_Pad (KeyPad_t *object);
uint8 read_button(KeyPad_t *object);

#endif /* KEYBAD_H_ */