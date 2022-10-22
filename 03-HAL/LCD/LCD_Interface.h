#ifndef _LCD_INTERFACE_H_
#define _LCD_INTERFACE_H_

#include "STD_TYPES.h"

#define LINE1 0
#define LINE2 1

void LCD_init();
void LCD_writeCommand(u8 copyCommand);
void LCD_writeData(u8 copyData);
void LCD_goToXY(u8 copyX, u8 copyY);
void LCD_writeCharacter(u8 copyChar);
void LCD_writeString(u8* str);
void LCD_writeNumber(u32 number);
void LCD_clearScreen();
#endif
