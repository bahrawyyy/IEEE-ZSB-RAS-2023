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
#include <string.h>


volatile u16 countOverflows=0,Copy_counter;
u8 password[] = "1234";
u8 flag=0;

#define MOTOR_PIN DIO_U8_PIN_4
#define RED_LED DIO_U8_PIN_0


u8 input[5] = {'\0'}; // Initialize input array
u8 indexz = 0;





int main()
{
	DIO_ES_tInit();
	Lcd_ES_tInit();

	u8 Value;
	u8 count=0;



	Lcd_ES_tsendString("Enter Password !");
	LCD_ES_tGoTo(1, 5);

	while(1)
	{
			KPD_ES_tGetKeyPressed(&Value);
			if(Value != KPD_U8_NOT_PRESSED){

				Lcd_ES_tsendChar('*');
				input[indexz] = Value; // Store input in array
				indexz++;
				if (indexz >= 4) { // Check if password entered
					if (strcmp(input, password) == 0) {
						// Password is correct, perform action
						lcd_ES_tclear();
						Lcd_ES_tsendString("Correct Password");

					}
					else {
						// Password is incorrect, reset input
						lcd_ES_tclear();
						Lcd_ES_tsendString("Wrong Password");
						memset(input, '\0', sizeof(input));
						indexz = 0;
						_delay_ms(1500);
//						_delay_ms(1500);
//						_delay_ms(1500);
						flag=0;
						count++;
						lcd_ES_tclear();
						Lcd_ES_tsendString("Try again");
						LCD_ES_tGoTo(1, 5);
						if(count == 3){
							lcd_ES_tclear();
							Lcd_ES_tsendString("Blocked !!!");
							count=0;
						}

					}
				}
			}





	}

	return 0;
}
