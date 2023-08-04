/*
 * main.c
 *
 *  Created on: May 4, 2023
 *      Author: Abdallah
 */



#define F_CPU 16000000UL

#include "../HAL/Lcd/Lcd.h"
#include <util/delay.h>
#include "../MCAL/ADC/ADC.h"




int main()
{
	DIO_ES_tInit();
	Lcd_ES_tInit();
	ADC_init();

	u16 Ldr_read;


	Lcd_ES_tsendString("ADC Testing");
	LCD_ES_tGoTo(1, 0);
	Lcd_ES_tsendString("LDR Out : ");


    while (1)
    {
    	Lcd_ES_tsendString("   ");
    	LCD_ES_tGoTo(1, 10);
    	Ldr_read = ADC_read(ADC0);
    	Lcd_ES_tdisplayNum(Ldr_read);
    	_delay_ms(500);

    }

    return 0;
}
