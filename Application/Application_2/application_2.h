/*
 * application.h
 *
 * Created: 10/8/2015 11:25:34 AM
 *  Author: maged
 */ 


#ifndef APPLICATION_H_
#define APPLICATION_H_

//**** Header Files to be used (remove the comment if you want to use any of them) *****

//#include "led.h"
//#include "switch.h"
//#include "7-seg.h"
//#include "lcd.h"
//#include "keypad.h"
//#include "simple_7seg.h"
#include "usart.h"

/** Problems in the Project: **/
/*	- We have to implement our own delay function */

#include <util/delay.h>		//define the delay function if you want to use it
#define F_CPU  1000000UL		//define the oscillation frequency in MHz

#endif /* APPLICATION_H_ */