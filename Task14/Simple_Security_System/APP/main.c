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
#include "../HAL/DC_Motor/DC_Motor.h"
#include "../HAL/Stepper_Motor/Stepper.h"


volatile u16 countOverflows=0,Copy_counter;
u8 password[] = "1234";
u8 flag=0;

// Define states for the system
typedef enum {
	STATE_MAIN_SCREEN,
	STATE_MOTOR_OPTIONS,
	STATE_DC_MOTOR_MOVE,
	STATE_STEPPER_MOVE,
	STATE_EXIT
} State;


u8 input[5] = {'\0'}; // Initialize input array
u8 indexz = 0;

u8 inputSteper[5] = {'\0'}; // Initialize input array
u8 indexStepper = 0;


u8 gettingMotorOption=0,gettingMovingOption=0,gettingStepperOption=0;


int main()
{
	DIO_ES_tInit();
	Lcd_ES_tInit();
	Stepper_Init();

	DC_Motor_Init(DC_MOTOR_0);

	u8 Value;
	char Option,Option2,Option3;
	u8 count=0;
	u8 stepperAngle=0;


	State currentState = STATE_MAIN_SCREEN;




	Lcd_ES_tsendString("Enter Password !");
	LCD_ES_tGoTo(1, 5);

	while(1)
	{
		switch(currentState)
		{
		case STATE_MAIN_SCREEN:
			KPD_ES_tGetKeyPressed(&Value);
			if(Value != KPD_U8_NOT_PRESSED){

				Lcd_ES_tsendChar('*');
				input[indexz] = Value; // Store input in array
				indexz++;
				if (indexz >= 4) { // Check if password entered
					if (strcmp(input, password) == 0) {
						// Password is correct, perform action
						lcd_ES_tclear();
						Lcd_ES_tsendString("Welcome to Motor");
						LCD_ES_tGoTo(1, 0);
						Lcd_ES_tsendString("Dash board");
						_delay_ms(2000);
						currentState = STATE_MOTOR_OPTIONS;
					}
					else {
						// Password is incorrect, reset input
						lcd_ES_tclear();
						Lcd_ES_tsendString("Wrong Password");
						memset(input, '\0', sizeof(input));
						indexz = 0;
						_delay_ms(1500);
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


			break;
		case STATE_MOTOR_OPTIONS:
			if (!gettingMotorOption) {
				lcd_ES_tclear();
				Lcd_ES_tsendString("1- DC Motor");
				LCD_ES_tGoTo(1, 0);
				Lcd_ES_tsendString("2- Stepper");
				gettingMotorOption = 1;
			}

			KPD_ES_tGetKeyPressed(&Option);
			if (Option != KPD_U8_NOT_PRESSED) {
				if (Option == '1') {  // DC Motor
					gettingMotorOption = 0;
					currentState = STATE_DC_MOTOR_MOVE;
				} else if (Option == '2') {  // Stepper Motor
					currentState = STATE_STEPPER_MOVE;
				} else {
					lcd_ES_tclear();
					Lcd_ES_tsendString("Invalid Option");
					_delay_ms(2000);
					gettingMotorOption=0;
					currentState = STATE_MOTOR_OPTIONS;
				}
			}
			break;

		case STATE_DC_MOTOR_MOVE:
			if (!gettingMovingOption) {
				lcd_ES_tclear();
				Lcd_ES_tsendString("1- Rotate CW");
				LCD_ES_tGoTo(1, 0);
				Lcd_ES_tsendString("2- Rotate CCW");
				gettingMovingOption = 1;
			}

			KPD_ES_tGetKeyPressed(&Option2);
			if (Option2 != KPD_U8_NOT_PRESSED) {
				if (Option2 == '1') {
					DC_Motor_Move(DC_MOTOR_0, DC_MOTOR_CW);
					_delay_ms(3000);
					DC_Motor_Stop(DC_MOTOR_0);
					gettingMovingOption = 0;
					currentState = STATE_MOTOR_OPTIONS;
				} else if (Option2 == '2') {
					DC_Motor_Move(DC_MOTOR_0, DC_MOTOR_CCW);
					_delay_ms(3000);
					DC_Motor_Stop(DC_MOTOR_0);
					gettingMovingOption = 0;
					currentState = STATE_MOTOR_OPTIONS;
				} else {
					lcd_ES_tclear();
					Lcd_ES_tsendString("Invalid Option");
					_delay_ms(2000);
					gettingMovingOption=0;
					currentState = STATE_DC_MOTOR_MOVE;
				}
			}
			break;
		case STATE_STEPPER_MOVE:
			if (!gettingStepperOption) {
				lcd_ES_tclear();
				Lcd_ES_tsendString("Angle(3dig) :");
				gettingStepperOption = 1;
			}
			KPD_ES_tGetKeyPressed(&Option3);
			if (Option3 != KPD_U8_NOT_PRESSED) {
				LCD_ES_tGoTo(1, indexStepper);
				Lcd_ES_tsendChar(Option3);
				inputSteper[indexStepper] = Option3 - '0'; // Convert character to integer
				indexStepper++;
				if (indexStepper >= 3) { // Use indexStepper instead of indexz
					stepperAngle = (inputSteper[0] * 100) + (inputSteper[1] * 10) + inputSteper[2];
					Stepper_Rotate(stepperAngle);
					memset(inputSteper, '\0', sizeof(inputSteper));
					indexStepper = 0;
					gettingStepperOption = 0;
					gettingMotorOption=0;
					currentState = STATE_MOTOR_OPTIONS;
				}
			}
			break;

		case STATE_EXIT:
			lcd_ES_tclear();
			Lcd_ES_tsendString("Exit System :)");
			_delay_ms(1000);
			return 0;
		}
	}

	return 0;
}
