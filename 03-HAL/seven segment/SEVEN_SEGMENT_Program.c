#include "STD_TYPES.h"
#include "SEVEN_SEGMENT_Interface.h"
#include "DIO_Interface.h"
/*				these values are for common anode connection				*/
u8 seven_segment_values[10] = {0b11000000,0b11111001,0b10100100,0b10110000,0b10011001,0b10010010,0b10000010,0b11111000,0b10000000,0b10010000};

void _7segment_displayNumber(u8 copyPort, u8 copyConnectionType, u8 number) {
	setPortDirection(copyPort,ALL_PINS_OUTPUT);
	if (copyConnectionType == 1) {
		setPortValue(copyPort,seven_segment_values[number]);
	}
	else if(copyConnectionType == 0) {
		setPortValue(copyPort,~seven_segment_values[number]);
	}
}