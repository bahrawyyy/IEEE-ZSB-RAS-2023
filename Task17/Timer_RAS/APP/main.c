/*
 * main.c
 *
 *  Created on: May 4, 2023
 *      Author: Abdallah
 */

#define Act_As_Master
//#define Act_As_Slave

#define F_CPU 16000000UL

#include "../HAL/Lcd/Lcd.h"
#include <util/delay.h>
#include "../HAL/KPD/KPD_interface.h"
#include "../MCAL/TIMER/Timer.h"
#include "../HAL/DC_MOTOR/DC_Motor.h"
#include "../HAL/Servo_Motor/Servo.h"




int main()
{
	DIO_ES_tInit();
	Lcd_ES_tInit();

	sei();

	// An led
	DIO_ES_tSetPinDirection(DIO_U8_PORT_A, DIO_U8_PIN_0, OUTPUT);

    while (1)
    {
		DIO_ES_tSetPinValue(DIO_U8_PORT_A, DIO_U8_PIN_0, HIGH);
		Timer0_Set_Delay_ms(2000);
		DIO_ES_tSetPinValue(DIO_U8_PORT_A, DIO_U8_PIN_0, LOW);
		Timer0_Set_Delay_ms(2000);
    }
    return 0;
}



