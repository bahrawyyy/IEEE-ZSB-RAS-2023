/*
 * main.c
 *
 *  Created on: May 4, 2023
 *      Author: Abdallah
 */

#define F_CPU 16000000UL

#include "../HAL/Lcd/Lcd.h"
#include <util/delay.h>
#include "../HAL/KPD/KPD_interface.h"
#include "../MCAL/UART/UART.h"
#include "string.h"
#include "../MCAL/Dio/Dio_interface.h"


#define LED_RED			DIO_U8_PIN_0
#define LED_GREEN		DIO_U8_PIN_1
#define LED_BLUE		DIO_U8_PIN_2


// Simple function to check if two strings are the same
u8 stringCompare(char* str1, char* str2){
	int i=0;
	while(str1[i]!='\0'){
		if(str1[i] != str2[i])
			return 1;
		i++;
	}
	return 0;
}

int main()
{
	DIO_ES_tInit();

	DIO_ES_tSetPinDirection(DIO_U8_PORT_C, LED_RED, OUTPUT);
	DIO_ES_tSetPinDirection(DIO_U8_PORT_C, LED_GREEN, OUTPUT);
	DIO_ES_tSetPinDirection(DIO_U8_PORT_C, LED_BLUE, OUTPUT);

	Lcd_ES_tInit();
	UART_Init();
	sei();

	u8 received_string[20]={0};


	Lcd_ES_tsendString("UART");
	LCD_ES_tGoTo(1, 0);
	Lcd_ES_tsendString("Atmega32 !");
	_delay_ms(500);
	lcd_ES_tclear();


	UART_SendString_ASYNCH("Enter an Option (Valid Options: R_ON, R_OFF, G_ON, G_OFF, B_ON, B_OFF):\n");



	while (1)
	{
		UART_Receive_String(received_string);

		if(stringCompare(received_string,"R_ON") == 0){
			DIO_ES_tSetPinValue(DIO_U8_PORT_C, LED_RED, HIGH);
			UART_Send_String("LED_RED ON\n");
		}else if(stringCompare(received_string,"R_OFF") == 0){
			DIO_ES_tSetPinValue(DIO_U8_PORT_C, LED_RED, LOW);
			UART_Send_String("LED_RED OFF\n");
		}else if(stringCompare(received_string,"G_ON") == 0){
			DIO_ES_tSetPinValue(DIO_U8_PORT_C, LED_GREEN, HIGH);
			UART_Send_String("LED_GREEN ON\n");
		}else if(stringCompare(received_string,"G_OFF") == 0){
			DIO_ES_tSetPinValue(DIO_U8_PORT_C, LED_GREEN, LOW);
			UART_Send_String("LED_GREEN OFF\n");
		}else if(stringCompare(received_string,"B_ON") == 0){
			DIO_ES_tSetPinValue(DIO_U8_PORT_C, LED_BLUE, HIGH);
			UART_Send_String("LED_BLUE ON\n");
		}else if(stringCompare(received_string,"B_OFF") == 0){
			DIO_ES_tSetPinValue(DIO_U8_PORT_C, LED_BLUE, LOW);
			UART_Send_String("LED_BLUE OFF\n");
		}else{
			UART_Send_String("Not valid option\n");
		}


		_delay_ms(1000);


	}

	return 0;
}
