/*
 * I2C.c
 *
 * Created: 09/10/2015 10:06:43
 *  Author: fady
 */ 

#include "I2C.h"

uint8 I2C_init()
{
	//some definition for a head start
	reg8_write_pin(I2C_CONTROL_REG, 2,1); //enable bin
	reg8_write_pin(I2C_CONTROL_REG,6,1);  //acknowlegement
	reg8_write_port(I2C_BIT_RATE_REG, 0x02,0);
	reg8_write_port(I2C_STATUS_REG, 0x00,0);
	return TRUE;
}

uint8 I2C_Start()
{
	reg8_write_pin(I2C_CONTROL_REG, 7, 1);
	reg8_write_pin(I2C_CONTROL_REG,6,0);
	reg8_write_pin(I2C_CONTROL_REG, 5, 1);
	
	while(!reg8_read_pin(I2C_CONTROL_REG, 7));  //wait for flag set
	
	if ((reg8_read_port(I2C_STATUS_REG)&0xF8) == 0x08)
		return FALSE;
	return TRUE;
}

uint8 I2C_Stop()
{
	reg8_write_pin(I2C_CONTROL_REG, 7, 1);
	reg8_write_pin(I2C_CONTROL_REG, 4, 1);
	
	while(!reg8_read_pin(I2C_CONTROL_REG,7));  //wait for flag set
	
	return TRUE;
}

uint8 I2C_Write_Address(uint8 address)
{
	reg8_write_port(I2C_DATA_REG, address,0);
	reg8_write_pin(I2C_CONTROL_REG,7,1);
	
	while(!reg8_read_pin(I2C_CONTROL_REG,7));
	
	if((reg8_read_port(I2C_STATUS_REG) & 0xF8) == 0x18)
		return FALSE;
	
	return TRUE;
}

uint8 I2C_Write_data(uint8 data)
{
	reg8_write_port(I2C_DATA_REG, data,0);
	reg8_write_pin(I2C_CONTROL_REG,7,1);
	
	while(!reg8_read_pin(I2C_CONTROL_REG,7));
	
	if((reg8_read_port(I2C_STATUS_REG) & 0xF8) == 0x28)
		return FALSE;
	
	return TRUE;	
}

uint8 I2C_Recieve()
{
	reg8_write_pin(I2C_CONTROL_REG,7,1);
	reg8_write_pin(I2C_CONTROL_REG,2,1);   //manually enable it as it's used in ISR
	
	return reg8_read_port(I2C_DATA_REG);  //return data
}

uint8 I2C_Transmit()
{
	I2C_init();
	I2C_Start();
	I2C_Write_Address(0x01);
	I2C_Write_data(0xFF);
	I2C_Stop();
	return TRUE;
}	 