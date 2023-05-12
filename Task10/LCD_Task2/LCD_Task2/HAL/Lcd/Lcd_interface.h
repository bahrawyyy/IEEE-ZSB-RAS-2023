/*
 * Lcd.h
 *
 *  Created on: Sep 12, 2022
 *      Author: 10
 */

#ifndef HAL_LCD_LCD_INTERFACE_H_
#define HAL_LCD_LCD_INTERFACE_H_



#include "Lcd_Config.h"
#include "../../MCAL/Dio/Dio_interface.h"

// ES_t DIO_ES_tTOGPin(DIO_U8_Port_Type copy_u8_PortId, DIO_U8_Pin_Type copy_u8_PinId);

ES_t Lcd_ES_tInit();
ES_t Lcd_ES_tsendCmd(u8 Local_u8_cmd);
ES_t Lcd_ES_tsendChar(u8 Local_u8_data);
ES_t Lcd_ES_tsendChar_xy(u8 Local_u8_data,u8 Local_u8_row,u8 Local_u8_col);

ES_t Lcd_ES_tsendString(s8 *Local_s8_data);
ES_t Lcd_ES_tsendString_xy(s8 *Local_s8_data,u8 Local_u8_row,u8 Local_u8_col);

ES_t Lcd_ES_tdisplayNum(u16 Local_u16_num);
ES_t Lcd_ES_tdisplayNum_xy(u16 Local_u16_num,u8 Local_u8_row,u8 Local_u8_col);

ES_t LCD_ES_tGoTo(u8 Local_u8_Line, u8 copy_u8_Col);
ES_t lcd_ES_tclear();

ES_t Lcd_CreateCustomCharacter(u8 *Local_u8_pattern,u8 Local_u8_location);


#endif /* HAL_LCD_LCD_INTERFACE_H_ */
