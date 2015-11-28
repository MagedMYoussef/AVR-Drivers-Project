/*
 * SPI.c
 *
 * Created: 10/5/2015 10:36:59 PM
 *  Author: fady
 */ 
#include "SPI.h"

uint8 init_master(SPI_t *object)
{
	//configure both SCLK and MOSI as output
	reg8_init_pin(object -> SPI_port+DIR_OFFSET, object -> MOSI, GPIO_OUTPUT);
	reg8_init_pin(object -> SPI_port+DIR_OFFSET, object -> SCLK, GPIO_OUTPUT);
	reg8_init_pin(object -> SPI_port+DIR_OFFSET, object -> MISO, GPIO_INPUT);
	
	reg8_write_pin(SERIAL_CTRL_REG, 6, 1);    //enable SPI
	reg8_write_pin(SERIAL_CTRL_REG, 4, 1);	  //configure it as a master
	reg8_write_pin(SERIAL_CTRL_REG, 0, 1);	  //prescaler/16
	
	if(object -> Interrupts)
	{
		reg8_write_pin(SERIAL_CTRL_REG, 7, 1);    //enable SPI interrupts
		sei();									  //enable interrupts globally 	
	}
	return TRUE;
}

uint8 init_slave(SPI_t *object)
{
	reg8_init_pin(object -> SPI_port+DIR_OFFSET ,object -> MISO, GPIO_OUTPUT);  //make MISO as an output
	
	reg8_write_pin(SERIAL_CTRL_REG, 6, 1);           //enable SPI
	reg8_write_pin(SERIAL_CTRL_REG, 4, 0);			 //configure it as slave
	
	return TRUE;
}

uint8 SPI_tranceiver(uint8 data)
{
	reg8_write_port(SERIAL_DATA_REG, data, 0);
	
	while(!reg8_read_pin(SERIAL_STATUS_REG, 7));
	
	return reg8_read_port(SERIAL_DATA_REG);
}