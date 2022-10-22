#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"
#include "EXTINT_Interface.h"
#include "EXTINT_Private.h"

void (*INT0_globalFunctionPointer)(void) = NULL;
void (*INT1_globalFunctionPointer)(void) = NULL;
void (*INT2_globalFunctionPointer)(void) = NULL;

void EXTINT_init(u8 copyINT,u8 copySenseControl){
	switch(copyINT) {
		case INT0:
			setBit(GICR,6);
			switch(copySenseControl) {
				case LOW:
					clearBit(MCUCR,0);
					clearBit(MCUCR,1);
					break;
				
				case FALLING:
					setBit(MCUCR,0);
					clearBit(MCUCR,1);
					break;
				
				case RISING:
					clearBit(MCUCR,0);
					setBit(MCUCR,1);
					break;
					
				case CHANGE:
					setBit(MCUCR,0);
					setBit(MCUCR,1);
					break;	
			}
			break;
		
		case INT1:
			setBit(GICR,7);
			switch(copySenseControl) {
				case LOW:
					clearBit(MCUCR,2);
					clearBit(MCUCR,3);
					break;
				
				case FALLING:
					setBit(MCUCR,2);
					clearBit(MCUCR,3);
					break;
				
				case RISING:
					clearBit(MCUCR,2);
					setBit(MCUCR,3);
					break;
					
				case CHANGE:
					setBit(MCUCR,2);
					setBit(MCUCR,3);
					break;	
			}
			break;
			
		case INT2:
			setBit(GICR,5);
			switch(copySenseControl) {
				case FALLING:
					clearBit(MCUCSR,6);
					break;
				
				case RISING:
					setBit(MCUCSR,6);
					break;	
			}
			break;	
	}
}

void EXTINT0(void (EXTINT0_localFunctionPointer)(void)) {
	INT0_globalFunctionPointer = EXTINT0_localFunctionPointer;
}

void __vector_1()__attribute__((signal));
void __vector_1() {
	if(INT0_globalFunctionPointer != '\0') INT0_globalFunctionPointer();
}

void EXTINT1(void (EXTINT1_localFunctionPointer)(void)) {
	INT1_globalFunctionPointer = EXTINT1_localFunctionPointer;
}

void __vector_2()__attribute__((signal));
void __vector_2() {
	if(INT1_globalFunctionPointer != '\0') INT1_globalFunctionPointer();
}

void EXTINT2(void (EXTINT2_localFunctionPointer)(void)) {
	INT2_globalFunctionPointer = EXTINT2_localFunctionPointer;
}

void __vector_3()__attribute__((signal));
void __vector_3() {
	if(INT2_globalFunctionPointer != '\0') INT2_globalFunctionPointer();
}
