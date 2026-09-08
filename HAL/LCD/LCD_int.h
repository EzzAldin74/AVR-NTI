#ifndef _LCD_INT_H_ 
#define _LCD_INT_H_ 

#define FUNC_SET              0X38
#define ON_OFF_DISPLAY_CTR    0X0C
#define CLEAR_DISPLAY         0X01 
#define DDRAM_ADDR_CMD        0X80

void LCD_voidInit ();
void LCD_voidWriteCommand (u8 Command);
void LCD_voidWriteChar (u8 Data);

void LCD_voidWriteString(u8* Str);
void LCD_voidGoToXY(u8 x, u8 y);
void LCD_voidWriteNumber(s32 Num);
#endif
