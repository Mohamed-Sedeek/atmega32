#include "STD_TYPES.h"
#include "LCD_Interface.h"
#include "LCD_Config.h"
#include "DIO_Interface.h"
#include "avr/delay.h"
#include <stdlib.h>

void LCD_init(){
	DIO_setPinDirection(CONTROL_PORT,RS,OUTPUT);
	DIO_setPinDirection(CONTROL_PORT,RW,OUTPUT);
	DIO_setPinDirection(CONTROL_PORT,EN,OUTPUT);

	DIO_setPortDirection(DATA_PORT,ALL_PINS_OUTPUT);
	
	_delay_ms(30);

	LCD_writeCommand(0b00111000); //send command function set
	_delay_ms(2);
	
	LCD_writeCommand(0b00001100); //send command on/off
	_delay_ms(2);
	
	LCD_writeCommand(0b00000001); //send command clear display
}

void LCD_writeCommand(u8 copyCommand) {
	DIO_setPinValue(CONTROL_PORT,RS,LOW); //enable command
	DIO_setPinValue(CONTROL_PORT,RW,LOW); // enable write
	
	DIO_setPortValue(DATA_PORT,copyCommand); //send command
	
	DIO_setPinValue(CONTROL_PORT,EN,HIGH);
	_delay_ms(2);
	DIO_setPinValue(CONTROL_PORT,EN,LOW);
}

void LCD_writeData(u8 copyData) {
	DIO_setPinValue(CONTROL_PORT,RS,HIGH); //enable data
	DIO_setPinValue(CONTROL_PORT,RW,LOW); //enable write
	
	DIO_setPortValue(DATA_PORT,copyData); //send data
	
	DIO_setPinValue(CONTROL_PORT,EN,HIGH);
	_delay_ms(2);
	DIO_setPinValue(CONTROL_PORT,EN,LOW);
}

void LCD_goToXY(u8 copyX, u8 copyY) {
	if (copyX == 0) {
		LCD_writeCommand(128+copyY);
	}
	else if (copyX == 1) {
		LCD_writeCommand(128+0x40+copyY);
	}
}

void LCD_writeCharacter(u8 copyChar) {
	LCD_writeData(copyChar);
}

void LCD_writeString(u8* str){
	u8 i=0;
	while(*(str+i) != '\0') {
		if(i>15) {
			LCD_goToXY(LINE2,i-16);
			LCD_writeData(*(str+i));
		}
		else {
			LCD_goToXY(LINE1,i);
			LCD_writeData(*(str+i));
		}
		i++;
	}
}

void LCD_writeNumber(u32 number){
	s8 i=0;
	u8 digitNum=0,*digitsArr;
	u32 copyNumber=number;
	while(copyNumber) {
		digitNum++;
		copyNumber/=10;
	}
	digitsArr = (u8*)malloc(digitNum * sizeof(u8));
	while(number) {
		*(digitsArr+i)=number%10;
		number/=10;
		i++;
	}
	for(i=digitNum-1;i>=0;i--) {
		LCD_writeData(*(digitsArr+i)+48);
	}
	free(digitsArr);
}

void LCD_clearScreen() {
	LCD_writeCommand(0x01);
}
