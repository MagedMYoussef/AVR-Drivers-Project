/*
 * External_EEPROM_I2C.c
 *
 * Created: 3/12/2014 12:05:19 PM
 *  Author: Mohamed Tarek
 */
 
#ifndef F_CPU
#define F_CPU 8000000UL
#endif

#include <util/delay.h>

#include"External_EEPROM.h"

int main(void)
{
	unsigned char val = 0;
	
	DDRA = 0xFF;
	PORTA = 0x00;

	// Init EEPROM
	EEPROM_Init();

	EEPROM_Write_Byte(0x0311, 0x01); // Write 0xFF in the external EEPROM
	_delay_ms(10);
	EEPROM_Read_Byte(0x0311, &val); // Read 0xFF from the external EEPROM
	while(1)
	{
		PORTA = val; // out the read value from the external EEPROM
	}
	return 0;
}