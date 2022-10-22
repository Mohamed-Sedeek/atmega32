#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "USART_Private.h"
#include "USART_Interface.h"




void UART_init(u32 copyBaudRate){
	u8 registerValue=0; // will be used to assign its value to register UCSRC since we should access it at once
	setBit(UCSRB,3);
	setBit(UCSRB,4);
	clearBit(UCSRB,2);

	setBit(registerValue,7);
	clearBit(registerValue,6);
	clearBit(registerValue,5);
	clearBit(registerValue,4);
	clearBit(registerValue,3);
	setBit(registerValue,2);
	setBit(registerValue,1);
	clearBit(registerValue,0);
	UCSRC= registerValue;
	
	UBRRH= 0;
	switch(copyBaudRate) {
		case 2400:
			UBRRL= 207;
			break;
		case 4800:
			UBRRL= 103;
			break;
		case 9600:
			UBRRL= 51;
			break;
		case 14400:
			UBRRL= 34;
			break;
		case 19200:
			UBRRL= 25;
			break;
		case 28800:
			UBRRL= 16;
			break;
		case 38400:
			UBRRL= 12;
			break;
		case 57600:
			UBRRL= 8;
			break;
		case 76800:
			UBRRL= 6;
			break;
		case 115200:
			UBRRL= 3;
			break;
		case 230400:
			UBRRL= 1;
			break;
		case 250000:
			UBRRL= 1;
			break;
		case 500000:
			UBRRL= 0;
			break;	
	}
	
}

void UART_write(u8 copyData){
	UDR= copyData;
	while(getBit(UCSRA,6) == 0);
	setBit(UCSRA,6);
}

u8 UART_read(){
	while(getBit(UCSRA,7) == 0);
	return UDR;
}


