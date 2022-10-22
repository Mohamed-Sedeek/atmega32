#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"
#include "DIO_Private.h"

void DIO_setPinDirection(u8 copyPort, u8 copyPin, u8 copyDirecton){
	if (copyDirecton == 1) {
		switch(copyPort) {
			case PORTA_ID: setBit(DDRA_REG,copyPin);break;
			case PORTB_ID: setBit(DDRB_REG,copyPin);break;
			case PORTC_ID: setBit(DDRC_REG,copyPin);break;
			case PORTD_ID: setBit(DDRD_REG,copyPin);break;
		}
	}
	else if (copyDirecton == 0) {
		switch(copyPort) {
			case PORTA_ID: clearBit(DDRA_REG,copyPin);break;
			case PORTB_ID: clearBit(DDRB_REG,copyPin);break;
			case PORTC_ID: clearBit(DDRC_REG,copyPin);break;
			case PORTD_ID: clearBit(DDRD_REG,copyPin);break;
		}
	}
}

void DIO_setPinValue(u8 copyPort, u8 copyPin, u8 copyValue){
	if (copyValue == 1) {
		switch(copyPort) {
			case PORTA_ID: setBit(PORTA_REG,copyPin);break;
			case PORTB_ID: setBit(PORTB_REG,copyPin);break;
			case PORTC_ID: setBit(PORTC_REG,copyPin);break;
			case PORTD_ID: setBit(PORTD_REG,copyPin);break;
		}
	}
	else if (copyValue == 0) {
		switch(copyPort) {
			case PORTA_ID: clearBit(PORTA_REG,copyPin);break;
			case PORTB_ID: clearBit(PORTB_REG,copyPin);break;
			case PORTC_ID: clearBit(PORTC_REG,copyPin);break;
			case PORTD_ID: clearBit(PORTD_REG,copyPin);break;
		}
	}
}

void DIO_setPortDirection(u8 copyPort, u8 copyDirection){
	switch(copyPort) {
			case PORTA_ID: DDRA_REG = copyDirection;break;
			case PORTB_ID: DDRB_REG = copyDirection;break;
			case PORTC_ID: DDRC_REG = copyDirection;break;
			case PORTD_ID: DDRD_REG = copyDirection;break;
		}
}

void DIO_setPortValue(u8 copyPort, u8 copyValue){
	switch(copyPort) {
			case PORTA_ID: PORTA_REG = copyValue;break;
			case PORTB_ID: PORTB_REG = copyValue;break;
			case PORTC_ID: PORTC_REG = copyValue;break;
			case PORTD_ID: PORTD_REG = copyValue;break;
		}
}

void DIO_togglePinValue(u8 copyPort, u8 copyPin){
	switch(copyPort) {
			case PORTA_ID: toggleBit(PORTA_REG,copyPin);break;
			case PORTB_ID: toggleBit(PORTB_REG,copyPin);break;
			case PORTC_ID: toggleBit(PORTC_REG,copyPin);break;
			case PORTD_ID: toggleBit(PORTD_REG,copyPin);break;
		}
}

u8 DIO_getPinState(u8 copyPort, u8 copyPin){
	switch(copyPort) {
		case PORTA_ID: return getBit(PINA_REG,copyPin);break;
		case PORTB_ID: return getBit(PINB_REG,copyPin);break;
		case PORTC_ID: return getBit(PINC_REG,copyPin);break;
		case PORTD_ID: return getBit(PIND_REG,copyPin);break;
	}
}