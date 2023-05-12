/*
 * Lcd.c
 *
 *  Created on: Sep 12, 2022
 *      Author: 10
 */

#define F_CPU 16000000UL

#include "Lcd_interface.h"
#include "Lcd_private.h"
#include <util/delay.h>
#include <string.h>

#include "../../MCAL/Registers.h"


static ES_t LCD_ES_tTrigger_Enable(void);  //ProtoType of static is defined in source file itself(Private declaration)
static ES_t LCD_ES_tSet_Cursor_Pos(u8 copy_u8_row,u8 copy_u8_column);


// ES_t DIO_ES_tTOGPin(DIO_U8_Port_Type copy_u8_PortId, DIO_U8_Pin_Type copy_u8_PinId);

ES_t Lcd_ES_tInit(){
	Lcd_ES_tsendCmd(fourbit_mode);  /* Go into 4-bit operating mode*/
	Lcd_ES_tsendCmd(fourbit_mode11);	/* Go into 4-bit operating mode*/
	Lcd_ES_tsendCmd(D4_D7);  /* 2 Line, 5*7 matrix in 4-bit mode */
	Lcd_ES_tsendCmd(CursorOFF);  /* Display on cursor off */
	Lcd_ES_tsendCmd(IncrCursor);  /* Increment cursor (shift cursor to right) */
	Lcd_ES_tsendCmd(CLR_Display);  /* Clear display screen */
	return ES_OK;
}

/*
 * RS = 0 // To send command
 * RW = 0 //To write on the LCD
 *  4-bit mode
 * Send higher nibble(1/2 Byte)
 * Send Trigger Enable
 * Send Lower nibble
 * Send Trigger Enable
 * delay
 *
 *
 *	Ex. 0x28 0b 0010 1000  //Read bit by bit and see if it is low or high
 */

ES_t lcd_ES_tclear()
{
	Lcd_ES_tsendCmd(CLR_Display);
	_delay_ms(2);
	return ES_OK;
}

ES_t Lcd_ES_tsendCmd(u8 copy_u8_cmd){
	DIO_ES_tSetPinValue(LCD_CMD_PORT, RS, LOW);
	DIO_ES_tSetPinValue(LCD_CMD_PORT, RW, LOW);
	// DIO_ES_tGetPinValue, DIO_ES_tSetPinValue
	// 0b01111010
	// Higher nibble
	DIO_ES_tSetPortValue(LCD_DATA_PORT, (LCD_DATA_PORT & 0x0F) | (copy_u8_cmd & 0xF0));
	//Trigger Enable
	LCD_ES_tTrigger_Enable();
	// Lower nibble
	DIO_ES_tSetPortValue(LCD_DATA_PORT, (LCD_DATA_PORT & 0x0F) | (copy_u8_cmd << NIBBLE_SIZE));
	//Trigger Enable
	LCD_ES_tTrigger_Enable();
	return ES_OK;
}
ES_t Lcd_ES_tsendChar(u8 copy_u8_data){
	// ((REG>>PIN) & 0x1)
	DIO_ES_tSetPinValue(LCD_CMD_PORT, RS, HIGH);
	DIO_ES_tSetPinValue(LCD_CMD_PORT, RW, LOW);
	((copy_u8_data>>D7) & LOCAL_ONE) ? DIO_ES_tSetPinValue(LCD_DATA_PORT, D7,HIGH) : DIO_ES_tSetPinValue(LCD_DATA_PORT, D7,LOW);
	((copy_u8_data>>D6) & LOCAL_ONE) ? DIO_ES_tSetPinValue(LCD_DATA_PORT, D6,HIGH) : DIO_ES_tSetPinValue(LCD_DATA_PORT, D6,LOW);
	((copy_u8_data>>D5) & LOCAL_ONE) ? DIO_ES_tSetPinValue(LCD_DATA_PORT, D5,HIGH) : DIO_ES_tSetPinValue(LCD_DATA_PORT, D5,LOW);
	((copy_u8_data>>D4) & LOCAL_ONE) ? DIO_ES_tSetPinValue(LCD_DATA_PORT, D4,HIGH) : DIO_ES_tSetPinValue(LCD_DATA_PORT, D4,LOW);
	//Trigger Enable
	LCD_ES_tTrigger_Enable();
	((copy_u8_data>>D3) & LOCAL_ONE) ? DIO_ES_tSetPinValue(LCD_DATA_PORT, D7,HIGH) : DIO_ES_tSetPinValue(LCD_DATA_PORT, D7,LOW);
	((copy_u8_data>>D2) & LOCAL_ONE) ? DIO_ES_tSetPinValue(LCD_DATA_PORT, D6,HIGH) : DIO_ES_tSetPinValue(LCD_DATA_PORT, D6,LOW);
	((copy_u8_data>>D1) & LOCAL_ONE) ? DIO_ES_tSetPinValue(LCD_DATA_PORT, D5,HIGH) : DIO_ES_tSetPinValue(LCD_DATA_PORT, D5,LOW);
	((copy_u8_data>>D0) & LOCAL_ONE) ? DIO_ES_tSetPinValue(LCD_DATA_PORT, D4,HIGH) : DIO_ES_tSetPinValue(LCD_DATA_PORT, D4,LOW);
	//Trigger Enable
	LCD_ES_tTrigger_Enable();
	return ES_OK;
}

ES_t Lcd_ES_tsendString(s8 *copy_s8_data)
{
	DIO_ES_tSetPinValue(LCD_CMD_PORT, RS, HIGH);
	DIO_ES_tSetPinValue(LCD_CMD_PORT, RW, LOW);

	unsigned char i=0;
	while(copy_s8_data[i]!=NULL)
	{
		Lcd_ES_tsendChar(copy_s8_data[i]);
		i++;
	}
	return ES_OK;
}

ES_t Lcd_ES_tsendString_xy(s8 *copy_s8_data,u8 copy_u8_row,u8 copy_u8_col){
	DIO_ES_tSetPinValue(LCD_CMD_PORT, RS, HIGH);
	DIO_ES_tSetPinValue(LCD_CMD_PORT, RW, LOW);

	LCD_ES_tSet_Cursor_Pos(copy_u8_row,copy_u8_col);
	Lcd_ES_tsendString(copy_s8_data);
	return ES_OK;

}

static ES_t LCD_ES_tTrigger_Enable(void){  //We make it static cuz we won't use it anywhere but here
	DIO_ES_tSetPinValue(LCD_CMD_PORT, EN, HIGH);
	_delay_us(10);
	DIO_ES_tSetPinValue(LCD_CMD_PORT, EN, LOW);
	_delay_us(2000);
	return ES_OK;
}

//A function to display Numbers instead of characters
ES_t Lcd_ES_tdisplayNum(u16 copy_u16_num)
{
	DIO_ES_tSetPinValue(LCD_CMD_PORT, RS, HIGH);
	DIO_ES_tSetPinValue(LCD_CMD_PORT, RW, LOW);

	u8 Local_u8_ch[10],i=0,j=0;
	if(copy_u16_num == 0)
	{
		Lcd_ES_tsendChar('0');
	}
	else
	{
		while(copy_u16_num)
		{
			Local_u8_ch[i] = copy_u16_num % DECIMAL + '0';  //To convert int to char
			copy_u16_num /= DECIMAL;
			i++;
		} //Thus number entered is reversed so, we want to display it correctly
		for(j=i;j>0;j--)
		{
			Lcd_ES_tsendChar(Local_u8_ch[j-1]);
		}
	}
	return ES_OK;
}

ES_t Lcd_ES_tdisplayNum_xy(u16 copy_u16_num,u8 copy_u8_row,u8 copy_u8_col){

	DIO_ES_tSetPinValue(LCD_CMD_PORT, RS, HIGH);
	DIO_ES_tSetPinValue(LCD_CMD_PORT, RW, LOW);


	if(copy_u8_row == FIRSTROW){
		Lcd_ES_tsendCmd(Force1stline);
		_delay_ms(1);
	}else if(copy_u8_row == SECONDROW){
		Lcd_ES_tsendCmd(Force2ndline);
		_delay_ms(10);
	}else{
		return ES_NOT_OK;
	}


	for(int j=1;j<=copy_u8_col;j++){
		Lcd_ES_tsendCmd(ShiftRight);
	}

	Lcd_ES_tdisplayNum(copy_u16_num);
	return ES_OK;

}

ES_t Lcd_ES_tsendChar_xy(u8 copy_u8_data,u8 copy_u8_row,u8 copy_u8_col){
	DIO_ES_tSetPinValue(LCD_CMD_PORT, RS, HIGH);
	DIO_ES_tSetPinValue(LCD_CMD_PORT, RW, LOW);


	if(copy_u8_row == FIRSTROW){
		Lcd_ES_tsendCmd(Force1stline);
		_delay_ms(1);
	}else if(copy_u8_row == FIRSTROW){
		Lcd_ES_tsendCmd(Force2ndline);
		_delay_ms(10);
	}else{
		return ES_NOT_OK;
	}

	for(int j=1;j<=copy_u8_col;j++){
		Lcd_ES_tsendCmd(ShiftRight);
	}
	Lcd_ES_tsendChar(copy_u8_data);
	return ES_OK;
}

static ES_t LCD_ES_tSet_Cursor_Pos(u8 copy_u8_row,u8 copy_u8_column){
	copy_u8_column--;
	switch(copy_u8_row){
	         case 1:
	        	 Lcd_ES_tsendCmd((Force1stline + copy_u8_column));
	        	 break;
	         case 2:
	        	 Lcd_ES_tsendCmd((Force2ndline + copy_u8_column));
	        	 break;
	         default:
	        	 return ES_NOT_OK;
	}
	return ES_OK;
}

/************************************************************************/
ES_t LCD_ES_tGoTo(u8 copy_u8_Line, u8 copy_u8_Col){
	if(0 == copy_u8_Line)
	{
		if ( copy_u8_Col <=MAX_COL_SIZE)
		{
			Lcd_ES_tsendCmd(0x80 + copy_u8_Col);
		}
	}
	else if (FIRSTROW == copy_u8_Line)
	{
		if ( copy_u8_Col <=MAX_COL_SIZE)
		{
			Lcd_ES_tsendCmd(0xC0 + copy_u8_Col);
		}
	}else{
		return ES_NOT_OK;
	}
	return ES_OK;
}

                                                      
/************************************************************************/


ES_t Lcd_CreateCustomCharacter(u8 *Local_u8_pattern,u8 Local_u8_location)
{
	// First send the address in CGRAM
	Lcd_ES_tsendCmd(CGRAM_ADD + (Local_u8_location * MAX_LOCATION));
	// Adding 0x40 is the command to set CGRAM address
	// + each character takes 8 bytes
	for(u8 Local_Iterator=LOW;Local_Iterator<MAX_LOCATION;Local_Iterator++){
		// Passing the bytes on the pattern on LCD
		Lcd_ES_tsendChar(Local_u8_pattern[Local_Iterator]);
	}
	return ES_OK;
}
