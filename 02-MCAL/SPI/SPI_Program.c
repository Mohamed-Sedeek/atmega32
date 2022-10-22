#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "SPI_Private.h"
#include "SPI_Interface.h"

void (*SPI_globalFunctionPointer)(void) = NULL;

void SPI_enable(u8 copyMode,u8 copyPSC){ // any PSC number could be passed in case of slave mode ; use 1 for example
	setBit(SPCR,6); // enable SPI
	setBit(SPCR,5); // set data direction to LSB first
	clearBit(SPCR,3); // set clock polarity to a high leading edge and low rising edge 
	clearBit(SPCR,2); // set clock phase to sample first
	
	switch(copyMode) {
		case SPI_MASTER:
			setBit(SPCR,4); // configure as master
			break;
		case SPI_SLAVE:
			clearBit(SPCR,4); // configure as slave
			break;
	}
	if (copyMode == SPI_MASTER) {
		switch(copyPSC) {
			case 4:
				clearBit(SPCR,0);
				clearBit(SPCR,1);	
				clearBit(SPSR,0);
				break;
			case 16:
				setBit(SPCR,0);
				clearBit(SPCR,1);	
				clearBit(SPSR,0);
				break;
			case 64:
				clearBit(SPCR,0);
				setBit(SPCR,1);	
				clearBit(SPSR,0);
				break;
			case 128:
				setBit(SPCR,0);
				setBit(SPCR,1);	
				clearBit(SPSR,0);
				break;
			case 2:
				clearBit(SPCR,0);
				clearBit(SPCR,1);	
				setBit(SPSR,0);
				break;
			case 8:
				setBit(SPCR,0);
				clearBit(SPCR,1);	
				setBit(SPSR,0);
				break;
			case 32:
				clearBit(SPCR,0);
				setBit(SPCR,1);	
				setBit(SPSR,0);
				break;
		}
	}
}

void SPI_disable(){
	clearBit(SPCR,6); // disable SPI
}

void SPI_dataOrder(u8 copyDataOrder){
	switch(copyDataOrder) {
		case LSB_FIRST:
			setBit(SPCR,5); // set data order as LSB first
			break;
		case MSB_FIRST:
			clearBit(SPCR,5); // set data order as MSB first
			break;
	}
}

void SPI_interruptEnable(){
	setBit(SPCR,7); // enable interrupt
}

void SPI_interruptDisable(){
	clearBit(SPCR,7); // disable interrupt
}

u8 SPI_transceiver(u8 copyData){
	SPDR= copyData; // write data to register
	while(getBit(SPSR,7) == 0); // wait until transfer is complete
	return SPDR; // return regiser data
}

void SPI_interrupt(void (SPI_localfunctionPointer)(void)){
	SPI_globalFunctionPointer= SPI_localfunctionPointer; // set call back
}

void __vector_12()__attribute__((signal));
void __vector_12() {
	if(SPI_globalFunctionPointer!=NULL) SPI_globalFunctionPointer();
}
