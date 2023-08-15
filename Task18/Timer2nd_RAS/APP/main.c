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
#include "../MCAL/ADC/ADC.h"



int main()
{
	// Initialization
	DIO_ES_tInit();
	Lcd_ES_tInit();
	DIO_ES_tSetPinDirection(DIO_U8_PORT_B, DIO_U8_PIN_3, OUTPUT);
	DIO_ES_tSetPinDirection(DIO_U8_PORT_A, DIO_U8_PIN_0, INPUT);
	ADC_init();


	TIMER0_Config_t Timer0Cfg = {TIMER0_PHASE_CORRECT_MODE, TIMER0_PRESCALAR_64, OC0_NON_INVERTING, TOIE0_DISABLE, OCIE0_DISABLE};

	TIMER0_Init(&Timer0Cfg);



	int PotValue = 0;


	Lcd_ES_tsendString("Percent : ");

	sei();

	while (1)
	{
		PotValue = ADC_read(ADC0);
		// Convert it to percentage
		PotValue = ((PotValue / 1024.0) * 100.0);

		PWM_Set_DutyCycle(PotValue);


		LCD_ES_tGoTo(0, 12);
		Lcd_ES_tsendString("   ");
		LCD_ES_tGoTo(0, 12);
		Lcd_ES_tdisplayNum(PotValue);


		_delay_ms(1000);




	}
	return 0;
}



