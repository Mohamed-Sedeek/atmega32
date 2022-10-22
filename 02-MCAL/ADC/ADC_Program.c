#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ADC_Interface.h"
#include "ADC_Private.h"

void ADC_init(u8 copyChannel, u8 copyPSC){
	setBit(ADMUX,6);
	setBit(ADCSRA,7);
	switch(copyChannel) {
		case ADC0:
			clearBit(ADMUX,0);
			clearBit(ADMUX,1);
			clearBit(ADMUX,2);
			clearBit(ADMUX,3);
			clearBit(ADMUX,4);
			break;
			
		case ADC1:
			setBit(ADMUX,0);
			clearBit(ADMUX,1);
			clearBit(ADMUX,2);
			clearBit(ADMUX,3);
			clearBit(ADMUX,4);
			break;
	
		case ADC2:
			clearBit(ADMUX,0);
			setBit(ADMUX,1);
			clearBit(ADMUX,2);
			clearBit(ADMUX,3);
			clearBit(ADMUX,4);
			break;
			
		case ADC3:
			setBit(ADMUX,0);
			setBit(ADMUX,1);
			clearBit(ADMUX,2);
			clearBit(ADMUX,3);
			clearBit(ADMUX,4);
			break;
			
		case ADC4:
			clearBit(ADMUX,0);
			clearBit(ADMUX,1);
			setBit(ADMUX,2);
			clearBit(ADMUX,3);
			clearBit(ADMUX,4);
			break;
			
		case ADC5:
			setBit(ADMUX,0);
			clearBit(ADMUX,1);
			setBit(ADMUX,2);
			clearBit(ADMUX,3);
			clearBit(ADMUX,4);
			break;
			
		case ADC6:
			clearBit(ADMUX,0);
			setBit(ADMUX,1);
			setBit(ADMUX,2);
			clearBit(ADMUX,3);
			clearBit(ADMUX,4);
			break;
			
		case ADC7:
			setBit(ADMUX,0);
			setBit(ADMUX,1);
			setBit(ADMUX,2);
			clearBit(ADMUX,3);
			clearBit(ADMUX,4);
			break;
	}
	
	switch(copyPSC) {
		case 2:
			clearBit(ADCSRA,0);
			clearBit(ADCSRA,1);
			clearBit(ADCSRA,2);
			break;
		case 4:
			clearBit(ADCSRA,0);
			setBit(ADCSRA,1);
			clearBit(ADCSRA,2);
			break;
		case 8:
			setBit(ADCSRA,0);
			setBit(ADCSRA,1);
			clearBit(ADCSRA,2);
			break;
		case 16:
			clearBit(ADCSRA,0);
			clearBit(ADCSRA,1);
			setBit(ADCSRA,2);
			break;
		case 32:
			setBit(ADCSRA,0);
			clearBit(ADCSRA,1);
			setBit(ADCSRA,2);
			break;
		case 64:
			clearBit(ADCSRA,0);
			setBit(ADCSRA,1);
			setBit(ADCSRA,2);
			break;
		case 128:
			setBit(ADCSRA,0);
			setBit(ADCSRA,1);
			setBit(ADCSRA,2);
			break;
	}
	setBit(ADCSRA,6);
}

u16 ADC_read(){
	u16 reading; 
	setBit(ADCSRA,6);
	reading = (u16)(ADCL|(u16)(ADCH<<8)); // read from ADCL first or else the registers will get locked
	return reading;
}
