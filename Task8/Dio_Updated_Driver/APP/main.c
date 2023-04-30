/*
 * main.c
 *
 *  Created on: Apr 30, 2023
 *      Author: Abdallah
 */



#include "../MCAL/Dio/Dio_interface.h"


int main()
{
	u8 Switch_Value,Switch2_Value;

	// Do the initialization of A1,C7, and B5 internally
	DIO_ES_tInit();

	DIO_ES_tSetPinDirection(DIO_U8_PORT_B, DIO_U8_PIN_3, OUTPUT);
	DIO_ES_tSetPinDirection(DIO_U8_PORT_C, DIO_U8_PIN_2, INPUT);
	DIO_ES_tSetPortDirection(DIO_U8_PORT_D,OUTPUT);
	while(1)
	{
		DIO_ES_tSetPortValue(DIO_U8_PORT_D,HIGH);
		DIO_ES_tGetPinValue(DIO_U8_PORT_C, DIO_U8_PIN_2, &Switch_Value);
		DIO_ES_tGetPinValue(DIO_U8_PORT_A, DIO_U8_PIN_1, &Switch2_Value);
		if(Switch_Value == HIGH){
			DIO_ES_tSetPinValue(DIO_U8_PORT_B, DIO_U8_PIN_3, HIGH);
		}else{
			DIO_ES_tSetPinValue(DIO_U8_PORT_B, DIO_U8_PIN_3, LOW);
		}
		if(Switch2_Value == HIGH){
			DIO_ES_tSetPinValue(DIO_U8_PORT_B, DIO_U8_PIN_5, HIGH);
			DIO_ES_tSetPinValue(DIO_U8_PORT_C, DIO_U8_PIN_7, HIGH);
		}else{
			DIO_ES_tSetPinValue(DIO_U8_PORT_B, DIO_U8_PIN_5, LOW);
			DIO_ES_tSetPinValue(DIO_U8_PORT_C, DIO_U8_PIN_7, LOW);
		}
	}
	return 0;
}


