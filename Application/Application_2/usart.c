/*
 * usart.c
 *
 * Created: 10/8/2015 11:32:33 AM
 *  Author: maged
 */ 

#include "usart.h"
#include "hw_types.h"

uint8 USART_init (USART_CONFIG_t * object) {
	/* make TXD (PD1) as output */
	WR_REG_8(object -> port, 0x02);
	
	/* setting the oscillation frequency
	 * PROBLEM HERE!!		
	 */
	//F_CPU = (object ->oscillation_frequency)UL;
	
	/* setting the baud rate */
	WR_REG_8(USER_UBRRL, 0x00);
	WR_REG_8(USER_UBRRH,(uint8) ((object ->baud_rate) >> 8));
	WR_REG_8(USER_UBRRL, (uint8) (object ->baud_rate));
	
	/* enable receiver and transmitter */
	WR_REG_8(USER_UCSRB, 0x18);
	
	/* setting URSEL in USER_UCSRC to 1 as we will use URSEL in the following code
	 * that's because the USER_UCSRC and USER_UBRRH registers share the same i/o address
	 */
	SET_PIN(USER_UCSRC, 0x80);
	
	/* setting UMSEL in USER_UCSRC register to 1 or 0
	 * Problems:
	 * - We need to make a function for setting and resetting pin !?	
	 */
	if (object ->mode == SYNCHRONOUS) {
		SET_PIN(USER_UCSRC, 0x40);
	} else if (object ->mode == ASYNCHRONOUS) {
		SET_PIN(USER_UCSRC, 0x00);
	}
	
	/* setting the parity mode */
	switch (object ->parity_mode) {
		case DISABLED:
		SET_PIN(USER_UCSRC, 0x00);
		break;
		
		case RESERVED:
		SET_PIN(USER_UCSRC, 0x10);
		break;
		
		case EVEN:
		SET_PIN(USER_UCSRC, 0x20);
		break;
		
		case ODD:
		SET_PIN(USER_UCSRC, 0x30);
		break;
		
		/* signal error when the user enter a false parity mode */
		default:
		return FALSE;
	}
	
	/* selecting whether the frame will contain 1 or 2 stop bits */
	if (object ->stop_bit_number == ONEBIT) {
		SET_PIN(USER_UCSRC, 0x00);
	} else if (object ->stop_bit_number == TWOBIT) {
		SET_PIN(USER_UCSRC, 0x08);
	}
	
	/* setting the character size:
	 * we will use UCSZ0 & UCSZ1 in USER_UCSRC and UCSZ2 in USER USER_UCSRB
	 * use the configuration table in page 158 in the data sheet (table 20-7)	
	 */
	switch(object ->character_size) {
		case '5':
		/* This statement doesn't do anything, it need to be modified after implementing the writing pin config */
		SET_PIN(USER_UCSRC, 0x00);
		SET_PIN(USER_UCSRB, 0x00);
		break;
		
		case '6':
		SET_PIN(USER_UCSRC, 0x02);
		break;
		
		case '7':
		SET_PIN(USER_UCSRC, 0x04);
		break;
		
		case '8':
		SET_PIN(USER_UCSRC, 0x06);
		break;
		
		case '9':
		SET_PIN(USER_UCSRC, 0x06);
		SET_PIN(USER_UCSRB, 0x04);
		break;
		
		/* signal an error if the character size is less than 5 or greater than 9 */
		default:
		return FALSE;
	}
	
	/* setting the clock polarity to rising or falling .. writing UCPOL in USER_UCSRC to 0 or 1 */
	if (object ->clock_polarity == RISING_TRANSMIT && (object ->mode == SYNCHRONOUS)) {
		SET_PIN(USER_UCSRC, 0x00);
	} else if (object ->clock_polarity == FALLING_TRANSMIT && (object ->mode == SYNCHRONOUS)) {
		SET_PIN(USER_UCSRC, 0x01);
	}
	
	/* setting the double transmission speed, setting U2X in USER_UCSRA register */
	if ((object ->transmission_speed_double == EN_DOUBLE_TX) && (object ->mode == SYNCHRONOUS)) {
		SET_PIN(USER_UCSRA, 0x02);
	} else if (object ->transmission_speed_double == DIS_DOUBLE_TX) {
		SET_PIN(USER_UCSRA, 0x00);
	}
	
	/* setting the multiprocessor mode, setting MPCM in USER_UCSRA register */
	if (object ->multiprocessor_mode == MULTIPROCESSOR) {
		SET_PIN(USER_UCSRA, 0x01);
	} else if (object ->multiprocessor_mode == SINGLEPROCESSOR) {
		SET_PIN(USER_UCSRA, 0x00);
	}
	return TRUE;
}

uint8 USART_transmit (USART_CONFIG_t * object, uint8 data) {
	/* wait for the buffer to be empty for transmitting, i.e check for UDRE flag on USER_UCSRA register
	 * Problems here:
	 * - NOT WORKING!
	 * - How can we make this generic !?
	 */
	while (!(USER_UCSRA & 0x20))
		;
	
	/* inserting data into buffer */
	WR_REG_8(USER_UDR, data);
	
	return TRUE;
}

uint8 USART_recieve (USART_CONFIG_t * object) {
	while (!(USER_UCSRA & 0x80))
	;
	return *(volatile uint8*) (USER_UDR);	
}