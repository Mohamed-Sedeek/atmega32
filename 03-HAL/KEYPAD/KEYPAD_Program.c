#include "KEYPAD_Config.h"
#include "STD_TYPES.h"
#include "DIO_Interface.h"
#include "KEYPAD_Interface.h"
#include "avr/delay.h"

u8 KEYPAD_values[4][4] = {{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'\0','0','=','+'}};

KEYPAD_init() {
	DIO_setPortDirection(KEYPAD_PORT,0xf0);
	DIO_setPortValue(KEYPAD_PORT,ALL_PINS_HIGH);
}

u8 KEYPAD_getPressedKey(){
	u8 row,col;
	
	for(col=0;col<4;col++) {
		DIO_setPinValue(KEYPAD_PORT,col+4,LOW);
		for(row=0;row<4;row++) {
			if(!DIO_getPinValue(KEYPAD_PORT,row)) {
				while(!DIO_getPinValue(KEYPAD_PORT,row));
				_delay_ms(50);
				return KEYPAD_values[row][col];
			}
		}
		DIO_setPinValue(KEYPAD_PORT,col+4,HIGH);
	}
	return 0xff; //indicates that no key is pressed;
}