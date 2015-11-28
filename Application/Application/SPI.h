/*
 * SPI.h
 *
 * Created: 10/5/2015 10:37:25 PM
 *  Author: fadyf
 */ 


#ifndef SPI_H_
#define SPI_H_

#include "hw_types.h"
#include "types.h"
#include <avr/interrupt.h>

typedef struct spi_conf {
	uint8 SPI_port;
	uint8 MISO;
	uint8 MOSI;
	uint8 SCLK;
	uint8 SS_bar;
	uint8 Interrupts;
}SPI_t;

uint8 init_master (SPI_t *);
uint8 init_slave(SPI_t *object);
uint8 SPI_tranceiver(uint8 data);


#endif /* SPI_H_ */