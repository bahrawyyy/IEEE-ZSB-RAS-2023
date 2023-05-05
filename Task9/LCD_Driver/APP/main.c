/*
 * main.c
 *
 *  Created on: May 5, 2023
 *      Author: Abdallah
 */

#define F_CPU 16000000UL

#include "../HAL/Lcd/Lcd_interface.h"
#include <util/delay.h>



#define SMILE 0

int main()
{
	DIO_ES_tInit();
	Lcd_ES_tInit();
	LCD_ES_tGoTo(0, 0);
	u8 Smile[] = {0x00,0x00,0x0A,0x00,0x11,0x11,0x0E,0x00};
	Lcd_CreateCustomCharacter(Smile,SMILE);
	u8 Local_u8_SwitchVal;

	Lcd_ES_tsendCmd(0x80);   // Set DDRAM address to 0
	u8 Local_u8_counter;

	Lcd_ES_tsendString("COUNTER TO 10");
	LCD_ES_tGoTo(0, 15);
	Lcd_ES_tsendChar(SMILE);
	while(1)
	{
		DIO_ES_tGetPinValue(DIO_U8_PORT_D, DIO_U8_PIN_6, &Local_u8_SwitchVal);

		for(Local_u8_counter=0;Local_u8_counter<11;Local_u8_counter++){
			LCD_ES_tGoTo(1,5);
			Lcd_ES_tdisplayNum(Local_u8_counter);
			_delay_ms(500);
		}
		if(Local_u8_SwitchVal == HIGH)
			lcd_ES_tclear();
		_delay_ms(500);
		LCD_ES_tGoTo(1,6);
		Lcd_ES_tsendChar(' ');
	}

	return 0;
}
