/*
 * Name        : application.c
 * Author      : Maged
 * Version     :
 * Copyright   : Your copyright notice
 * Description : Hello World in C, Ansi-style
 */

//#include "led.h"
//#include "switch.h"
#include "7-seg.h"
#include "lcd.h"
#include <util/delay.h>
#define F_CPU  1000000UL
int main(void) {
	/***Testing 7 segment
	SEG_CONFIG_t Segment = {DECODER, BASE_C, BASE_D, 3, COMMONCATHODE};
	init_7seg(&Segment);
	while (1)
	{
		display(&Segment, 215);
	}
	*/
	LCD_CONFIG_t display_test= {BASE_D, BASE_C, 1, 0, 1, 2};
	init_lcd(&display_test);
	while (1) {
		send_string(&display_test, "MAGED", 5);
		_delay_ms(500);
		send_command(&display_test, 0x01);
	}	
	return 0;
}