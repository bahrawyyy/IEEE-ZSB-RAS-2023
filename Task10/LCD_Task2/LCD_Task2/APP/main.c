/*
 * main.c
 *
 *  Created on: May 5, 2023
 *      Author: Abdallah
 */

#define F_CPU 16000000UL

#include "../HAL/Lcd/Lcd_interface.h"
#include <util/delay.h>


// Macros to be used with custom characters
#define SMILE 0
#define BELL 1
#define ARROW 2
#define BUG 3


static u8 row=0, col=0;


void Lcd_void_checkDimension(){
	if(row==0 && col==15){
		row=1;
		col=0;
	}
	
	
	if(row == 1 && col == 15){
		lcd_ES_tclear();
		row=0;
		col=0;
	}
	
	col++;
	
	LCD_ES_tGoTo(row,col);
}

int main()
{
	DIO_ES_tInit();
	Lcd_ES_tInit();
	LCD_ES_tGoTo(0, 0);

	// Arrays of custom characters
	u8 Smile[] = {0x00,0x00,0x0A,0x00,0x11,0x11,0x0E,0x00};
	u8 bell[] = {0x00,0x00,0x04,0x00,0x1F,0x1F,0x0E,0x04};
	u8 arrow[] = {0x00,0x04,0x0E,0x1F,0x04,0x04,0x04,0x04};
	u8 bug[] = {0x11,0x11,0x0A,0x0E,0x0E,0x04,0x0A,0x11};

	// Creating Custom characters
	Lcd_CreateCustomCharacter(Smile,SMILE);
	Lcd_CreateCustomCharacter(bell,BELL);
	Lcd_CreateCustomCharacter(arrow,ARROW);
	Lcd_CreateCustomCharacter(bug,BUG);


	

	u8 Local_u8_Switch1Val=LOW;
	u8 Local_u8_Switch2Val=LOW;
	u8 Local_u8_Switch3Val=LOW;
	u8 Local_u8_Switch4Val=LOW;

	Lcd_ES_tsendCmd(0x80);   // Set DDRAM address to 0

	Lcd_ES_tsendString("Custom Character");
	_delay_ms(500);
	lcd_ES_tclear();
	//Lcd_ES_tsendChar(SMILE);
	while(1)
	{	
		DIO_ES_tGetPinValue(DIO_U8_PORT_C, DIO_U8_PIN_6, &Local_u8_Switch1Val);
		DIO_ES_tGetPinValue(DIO_U8_PORT_C, DIO_U8_PIN_5, &Local_u8_Switch2Val);
		DIO_ES_tGetPinValue(DIO_U8_PORT_C, DIO_U8_PIN_4, &Local_u8_Switch3Val);
		DIO_ES_tGetPinValue(DIO_U8_PORT_C, DIO_U8_PIN_3, &Local_u8_Switch4Val);
		
		_delay_ms(180);
			
		if(Local_u8_Switch1Val == HIGH){
			Lcd_void_checkDimension();
			Lcd_ES_tsendChar(SMILE);
		}else if(Local_u8_Switch2Val == HIGH){
			Lcd_void_checkDimension();
			Lcd_ES_tsendChar(BELL);
		}else if(Local_u8_Switch3Val == HIGH){
			Lcd_void_checkDimension();
			Lcd_ES_tsendChar(ARROW);
		}else if(Local_u8_Switch4Val == HIGH){
			Lcd_void_checkDimension();
			Lcd_ES_tsendChar(BUG);
		}
		
		
		//_delay_ms(50);
		

	}

	return 0;
}
