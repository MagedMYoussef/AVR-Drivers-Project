/*
 * I2C.h
 *
 * Created: 09/10/2015 11:47:53
 *  Author: fady
 */ 


#ifndef I2C_H_
#define I2C_H_

#include "hw_types.h"
#include "types.h"

uint8 I2C_init();
uint8 I2C_Start();
uint8 I2C_Stop();
uint8 I2C_Write_Address(uint8);
uint8 I2C_Write_data(uint8);
uint8 I2C_Recieve();
uint8 I2C_Transmit();


#endif /* I2C_H_ */