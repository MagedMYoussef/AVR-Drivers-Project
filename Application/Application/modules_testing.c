	/*
	* modules_testing.c
	* This file will include the test cases for our modules
	* It will be all commented
	* Created: 10/8/2015 11:23:18 AM
	*  Author: maged
	*/ 

	/************************* 
	/**** Testing LCD only ****
	/* Problems till now:
	/* - Sending the data in 4-bits to the LCD
	/**************************
	LCD_CONFIG_t display_test= {BASE_D, BASE_C, 1, 0, 1, 2};
	init_lcd(&display_test);
	while (1) {
		send_string(&display_test, "MAGED", 5);
		_delay_ms(1000);
		send_command(&display_test, 0x01);
	}
	/*****************************/
	
	
	/******************************
	/**** Testing Keypad & LCD ****
	/* Problems till now:
	/* - Numbers done but symbols not yet
	/* - We have to clear the screen when the screen is full "NOT YET"
	/* - Extra space is printed after displaying each number
	/* - Sending the data in 4-bits to the LCD
	/******************************
	KeyPad_t keypad = {BASE_B};
	init_Pad(&keypad);
	
		
	LCD_CONFIG_t lcd= {BASE_D, BASE_C, 1, 0, 1, 2};
	init_lcd(&lcd);
	
	uint8 key;
	char * str;
	while (1) {
		if (read_button(&keypad)) {
			key = read_button(&keypad);
			send_string(&lcd, itoa(key, str,10), 1);
		}
		_delay_ms(100);
	}
	/******************************/
	
	
	/************************************************************************/
	/****** Testing USART: ***********
	/* Problems:
	/* - Not Working																	 
	/************************************************************************
	USART_CONFIG_t usart_comm = {
		USER_DDRD,
		1000000,
		9600,
		ASYNCHRONOUS,
		DISABLED,
		ONEBIT,
		'8',
		RISING_TRANSMIT,
		DIS_DOUBLE_TX,
		SINGLEPROCESSOR
	};
	USART_init(&usart_comm);
	while (1) {
		USART_transmit(&usart_comm, 0x90);
		_delay_ms(500);
	}	
	/************************************************************************/
	