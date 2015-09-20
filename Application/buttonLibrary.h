/*
 * buttonLibrary.h
 *
 * Created: 9/11/2015 12:06:20 PM
 *  Author: maged
 */ 


#ifndef BUTTONLIBRARY_H_
#define BUTTONLIBRARY_H_

#include <avr/io.h>

char ButtonPressed(unsigned char pinOfButton, unsigned char portBit, int confidenceLevel);

char Pressed;
int Pressed_Confidence_Level; //Measure button press confidence
int Released_Confidence_Level; //Measure button release confidence

char ButtonPressed(unsigned char pinOfButton, unsigned char portBit, int confidenceLevel)
{
	if (bit_is_clear(pinOfButton, portBit))
	{
		Pressed_Confidence_Level++; //Increase Pressed Confidence
		Released_Confidence_Level = 0; //Reset released button confidence since there is a button press
		if (Pressed_Confidence_Level > confidenceLevel) //Indicator of good button press
		{
			if (Pressed == 0)
			{
				Pressed = 1;
				return 1;
			}
			//Zero it so a new pressed condition can be evaluated
			Pressed_Confidence_Level = 0;
		}
	}
	else
	{
		Released_Confidence_Level ++; //This works just like the pressed
		Pressed_Confidence_Level = 0; //Reset pressed button confidence since the button is released
		if (Released_Confidence_Level > confidenceLevel)
		{
			Pressed = 0;
			Released_Confidence_Level = 0;
		}
	}
	return 0;
}

#endif


#endif /* BUTTONLIBRARY_H_ */