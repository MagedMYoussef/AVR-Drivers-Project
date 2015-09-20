/*
 * types.h
 *
 *  Created on: Sep 11, 2015
 *      Author: maged
 */

#ifndef TYPES_H_
#define TYPES_H_

#define TRUE 1
#define FALSE 0

#define OUTPUT 1
#define INPUT 0

#define PULLUP 1
#define PULLDOWN 0

typedef unsigned char uint8;
typedef unsigned int uint16;

//use decoder or not with the 7 segment
#define DECODER 1
#define NO_DECODER 0

//specify the type of the 7 segment display
#define COMMONCATHODE 0
#define COMMONANODE 1

#endif /* TYPES_H_ */
