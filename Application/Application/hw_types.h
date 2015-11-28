/*
 * hw_types.h
 *
 * Created: 10/8/2015 11:32:18 AM
 *  Author: maged
 */ 


#ifndef HW_TYPES_H_
#define HW_TYPES_H_

#define unsigned char uint8;
#define unsigned int uint16;

#define TRUE 1
#define FALSE 0

/*
 * "WR_REG_8" takes 2 arguments:
 * the first one is the address where the data will be stored
 * the second one is the data
 * it deals completely with the hardware, so it only takes the data
 * and stores it in the specified address!
 */
uint8 WR_REG_8(uint8 address, uint8 val) {
	*(volatile uint8*) (address) = val;
	return TRUE;
}

/*
 * "WR_REG_16" takes 2 arguments:
 * the first one is the address where the data will be stored
 * the second one is the data
 * it deals completely with the hardware, so it only takes the data
 * and stores it in the specified address!
 */
uint8 WR_REG_16(uint16 address, uint16 val) {
	*(volatile uint16*) (address) = val;
	return TRUE;
}

uint8 SET_PIN(uint8 address, uint8 val) {
	/* Making "|" will set a single pin leaving other pins as they are */
	*(volatile uint8*) (address) |= val;
	return TRUE;
}

#endif /* HW_TYPES_H_ */