/*
 * hw_types.c
 *
 * Created: 10/5/2015 11:06:12 PM
 *  Author: fadyf
 */ 

#include "hw_types.h"

uint8 reg8_init_pin(uint8 reg, uint8 pin, uint8 val)
{
	if (val != 1 && val != 0)
		return FALSE;
	if (val)
		*(volatile uint8 *)(reg) |= (1 << pin);
	else if (!val)
		*(volatile uint8 *)(reg) &= ~(1 << pin);
	return TRUE; 
}

uint8 reg8_write_pin(uint8 reg, uint8 pin, uint8 val)
{
	if (val != 0 && val != 1)
		return FALSE;
	if(val)
		*(volatile uint8 *)(reg) |= (1 << pin);
	else if (!val)
		*(volatile uint8 *)(reg) &= ~(1 << pin);
	return TRUE;
}

uint8 reg8_read_pin(uint8 reg, uint8 pin)
{
	uint8 val = *(volatile uint8 *)(reg) & (1 << pin);
	if(val)
		return 1;
	else
		return 0;
}

uint8 reg8_init_port(uint8 reg, uint8 val)
{
	*(volatile uint8*)(reg) = val;
	return TRUE; 
}

uint8 reg8_write_port(uint8 reg, uint8 val, uint8 shift)
{
	*(volatile uint8 *)(reg) = (val << shift);
	return TRUE;
}

uint8 reg8_read_port(uint8 reg)
{
	uint8 val = *(volatile uint8 *)(reg);
	return val;
}