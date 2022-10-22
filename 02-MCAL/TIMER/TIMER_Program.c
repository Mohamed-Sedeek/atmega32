#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TIMER_Private.h"
#include "TIMER_Interface.h"

void (*TIM0_globalFunctionPointer)(void)=NULL;
void (*TIM0_CTC_globalFunctionPointer)(void)=NULL;
void (*TIM2_globalFunctionPointer)(void)=NULL;
void (*TIM2_CTC_globalFunctionPointer)(void)=NULL;
void (*TIM1_globalFunctionPointer)(void)=NULL;
void (*TIM1_CTC_OC1A_globalFunctionPointer)(void)=NULL;
void (*TIM1_CTC_OC1B_globalFunctionPointer)(void)=NULL;
void (*TIM1_inputCapture_globalFunctionPointer)(void)=NULL;



/***********************************************TIMER0*****************************************/

void TIM0_init(){
	clearBit(TCCR0,3);
	clearBit(TCCR0,6);
}

void TIM0_disable(){
	TCCR0 &= 0b11111000;
}

void TIM0_interruptEnable(){
	setBit(TIMSK,0);
}

void TIM0_interruptDisable(){
	clearBit(TIMSK,0);
}

void TIM0_clockSelect(u16 copyPSC) {
	switch(copyPSC) {
		case 0:
			clearBit(TCCR0,0);
			clearBit(TCCR0,1);
			clearBit(TCCR0,2);
			break;
		case 1:
			setBit(TCCR0,0);
			clearBit(TCCR0,1);
			clearBit(TCCR0,2);
			break;
		case 8:
			clearBit(TCCR0,0);
			setBit(TCCR0,1);
			clearBit(TCCR0,2);
			break;
		case 64:
			setBit(TCCR0,0);
			setBit(TCCR0,1);
			clearBit(TCCR0,2);
			break;
		case 256:
			clearBit(TCCR0,0);
			clearBit(TCCR0,1);
			setBit(TCCR0,2);
			break;
		case 1024:
			setBit(TCCR0,0);
			clearBit(TCCR0,1);
			setBit(TCCR0,2);
			break;
		case T0_FALLING:
			clearBit(TCCR0,0);
			setBit(TCCR0,1);
			setBit(TCCR0,2);
			break;
		case T0_RISING:
			setBit(TCCR0,0);
			setBit(TCCR0,1);
			setBit(TCCR0,2);
			break;	
	}
}

void TIM0_preload(u8 copyPreloadValue){
	TCNT0 = copyPreloadValue;
}

u8 TIM0_getCount(){
	return TCNT0;
}

void TIM0_CTC_init(){
	setBit(TCCR0,3);
	clearBit(TCCR0,6);
}

void TIM0_CTC_interruptEnable() {
	setBit(TIMSK,1);
}

void TIM0_CTC_interruptDisable() {
	clearBit(TIMSK,1);
}

void TIM0_CTC_selectMode(u8 copyMode) {
	switch(copyMode) {
		case NORMAL:
			clearBit(TCCR0,4);
			clearBit(TCCR0,5);
			break;
		case TOGGLE:
			setBit(TCCR0,4);
			clearBit(TCCR0,5);
			break;
		case CLEAR:
			clearBit(TCCR0,4);
			setBit(TCCR0,5);
			break;
		case SET:
			setBit(TCCR0,4);
			setBit(TCCR0,5);
			break;	
	}
}

void TIM0_CTC_setCompareValue(u8 copyCompareValue){
	OCR0 = copyCompareValue;
}

void TIM0_FAST_PWM_init(){
	setBit(TCCR0,6);
	setBit(TCCR0,3);
}

void TIM0_FAST_PWM_selectMode(u8 copyMode){
	switch(copyMode) {
		case CLEAR_ON_MATCH:
			clearBit(TCCR1A,4);
			setBit(TCCR1A,5);
			break;
		case SET_ON_MATCH:
			setBit(TCCR1A,4);
			setBit(TCCR1A,5);
			break;
	}
}

void TIM0_FAST_PWM_setOCR(u8 copyOCR){
	OCR0= copyOCR;
}

void TIM0_interrupt(void (*TIM0_localFunctionPointer)(void)) {
	TIM0_globalFunctionPointer= TIM0_localFunctionPointer;
}

void __vector_11()__attribute__((signal));
void __vector_11() {
	if(TIM0_globalFunctionPointer!='\0') TIM0_globalFunctionPointer();
}


void TIM0_CTC_interrupt(void (*TIM0_CTC_localFunctionPointer)(void)) {
	TIM0_CTC_globalFunctionPointer= TIM0_CTC_localFunctionPointer;
}

void __vector_10()__attribute__((signal));
void __vector_10() {
	if(TIM0_CTC_globalFunctionPointer!='\0') TIM0_CTC_globalFunctionPointer();
}



/***********************************************TIMER2*****************************************/

void TIM2_init(){
	clearBit(TCCR2,3);
	clearBit(TCCR2,6);
}

void TIM2_disable(){
	TCCR2 &= 0b11111000;
}

void TIM2_interruptEnable(){
	setBit(TIMSK,6);
}

void TIM2_interruptDisable(){
	clearBit(TIMSK,6);
}

void TIM2_clockSelect(u16 copyPSC) {
	switch(copyPSC) {
		case 0:
			clearBit(TCCR2,0);
			clearBit(TCCR2,1);
			clearBit(TCCR2,2);
			break;
		case 1:
			setBit(TCCR2,0);
			clearBit(TCCR2,1);
			clearBit(TCCR2,2);
			break;
		case 8:
			clearBit(TCCR2,0);
			setBit(TCCR2,1);
			clearBit(TCCR2,2);
			break;
		case 64:
			setBit(TCCR2,0);
			setBit(TCCR2,1);
			clearBit(TCCR2,2);
			break;
		case 256:
			clearBit(TCCR2,0);
			clearBit(TCCR2,1);
			setBit(TCCR2,2);
			break;
		case 1024:
			setBit(TCCR2,0);
			clearBit(TCCR2,1);
			setBit(TCCR2,2);
			break;
		case T0_FALLING:
			clearBit(TCCR2,0);
			setBit(TCCR2,1);
			setBit(TCCR2,2);
			break;
		case T0_RISING:
			setBit(TCCR2,0);
			setBit(TCCR2,1);
			setBit(TCCR2,2);
			break;	
	}
}

void TIM2_preload(u8 copyPreloadValue){
	TCNT2 = copyPreloadValue;
}

u8 TIM2_getCount(){
	return TCNT2;
}

void TIM2_CTC_init(){
	setBit(TCCR2,3);
	clearBit(TCCR2,6);
}

void TIM2_CTC_interruptEnable() {
	setBit(TIMSK,7);
}

void TIM2_CTC_interruptDisable() {
	clearBit(TIMSK,7);
}

void TIM2_CTC_selectMode(u8 copyMode) {
	switch(copyMode) {
		case NORMAL:
			clearBit(TCCR2,4);
			clearBit(TCCR2,5);
			break;
		case TOGGLE:
			setBit(TCCR2,4);
			clearBit(TCCR2,5);
			break;
		case CLEAR:
			clearBit(TCCR2,4);
			setBit(TCCR2,5);
			break;
		case SET:
			setBit(TCCR2,4);
			setBit(TCCR2,5);
			break;	
	}
}

void TIM2_CTC_setCompareValue(u8 copyCompareValue){
	OCR2 = copyCompareValue;
}


void TIM2_interrupt(void (*TIM2_localFunctionPointer)(void)) {
	TIM2_globalFunctionPointer= TIM2_localFunctionPointer;
}

void __vector_5()__attribute__((signal));
void __vector_5() {
	if(TIM2_globalFunctionPointer!='\0') TIM2_globalFunctionPointer();
}


void TIM2_CTC_interrupt(void (*TIM2_CTC_localFunctionPointer)(void)) {
	TIM2_CTC_globalFunctionPointer= TIM2_CTC_localFunctionPointer;
}

void __vector_4()__attribute__((signal));
void __vector_4() {
	if(TIM2_CTC_globalFunctionPointer!='\0') TIM2_CTC_globalFunctionPointer();
}


/***********************************************TIMER1*****************************************/

void TIM1_init(){
	clearBit(TCCR1A,0);
	clearBit(TCCR1A,1);
	clearBit(TCCR1B,3);
	clearBit(TCCR1B,4);
}

void TIM1_disable() {
	TCCR1B &= 0b11111000;
}

void TIM1_interruptEnable(){
	setBit(TIMSK,2);
}

void TIM1_interruptDisable(){
	clearBit(TIMSK,2);
}

void TIM1_preload(u8 copyPreloadValue){
	TCNT1 = copyPreloadValue;
}

u16 TIM1_getCount(){
	return TCNT1;
}

void TIM1_CTC_init(){
	clearBit(TCCR1A,0);
	clearBit(TCCR1A,1);
	setBit(TCCR1B,3);
	clearBit(TCCR1B,4);
}

void TIM1_CTC_interruptEnable(u8 copyPin) {
	switch(copyPin) {
		case OC1A:
			setBit(TIMSK,4);
			break;
		case OC1B:
			setBit(TIMSK,3);
			break;
	}

}

void TIM1_CTC_interruptDisable(u8 copyPin) {
	switch(copyPin) {
			case OC1A:
				clearBit(TIMSK,4);
				break;
			case OC1B:
				clearBit(TIMSK,3);
				break;
		}
}

void TIM1_CTC_selectMode(u8 copyPin, u8 copyMode){
	switch(copyPin) {
		case OC1A:
			switch(copyMode) {
				case NORMAL:
					clearBit(TCCR1A,6);
					clearBit(TCCR1A,7);
					break;
				case TOGGLE:
					setBit(TCCR1A,6);
					clearBit(TCCR1A,7);
					break;
				case CLEAR:
					clearBit(TCCR1A,6);
					setBit(TCCR1A,7);
					break;
				case SET:
					setBit(TCCR1A,6);
					setBit(TCCR1A,7);
					break;	
			}
			break;
		case OC1B:
			switch(copyMode) {
				case NORMAL:
					clearBit(TCCR1A,4);
					clearBit(TCCR1A,5);
					break;
				case TOGGLE:
					setBit(TCCR1A,4);
					clearBit(TCCR1A,5);
					break;
				case CLEAR:
					clearBit(TCCR1A,4);
					setBit(TCCR1A,5);
					break;
				case SET:
					setBit(TCCR1A,4);
					setBit(TCCR1A,5);
					break;	
			}
			break;	
	}
}

void TIM1_CTC_setCompareValue(u8 copyPin, u8 copyCompareValue){
	switch(copyPin) {
		case OC1A:
			OCR1A = copyCompareValue;
			break;
		case OC1B:
			OCR1B = copyCompareValue;
			break;	
	}
}



void TIM1_FAST_PWM_init(u8 copyTimerBits){
	switch(copyTimerBits) {
		case 8:
			setBit(TCCR1A,0);
			clearBit(TCCR1A,1);
			setBit(TCCR1B,3);
			clearBit(TCCR1B,4);
			break;
		case 9:
			clearBit(TCCR1A,0);
			setBit(TCCR1A,1);
			setBit(TCCR1B,3);
			clearBit(TCCR1B,4);
			break;
		case 10:
			setBit(TCCR1A,0);
			setBit(TCCR1A,1);
			setBit(TCCR1B,3);
			clearBit(TCCR1B,4);
			break;
		case 16:
			setBit(TCCR1A,0);
			setBit(TCCR1A,1);
			setBit(TCCR1B,3);
			setBit(TCCR1B,4);
			break;
		case ICR:
			clearBit(TCCR1A,0);
			setBit(TCCR1A,1);
			setBit(TCCR1B,3);
			setBit(TCCR1B,4);
			break;	
	}
}

void TIM1_FAST_PWM_selectMode(u8 copyPin, u8 copyMode){
	switch(copyPin) {
		case OC1A:
			switch(copyMode) {
				case CLEAR_ON_MATCH:
					clearBit(TCCR1A,6);
					setBit(TCCR1A,7);
					break;
				case SET_ON_MATCH:
					setBit(TCCR1A,6);
					setBit(TCCR1A,7);
					break;	
			}
			break;
		case OC1B:
			switch(copyMode) {
				case CLEAR_ON_MATCH:
					clearBit(TCCR1A,4);
					setBit(TCCR1A,5);
					break;
				case SET_ON_MATCH:
					setBit(TCCR1A,4);
					setBit(TCCR1A,5);
					break;	
			}
			break;
	}
}

void TIM1_clockSelect(u16 copyPSC) {
	switch(copyPSC) {
		case 0:
			clearBit(TCCR1B,0);
			clearBit(TCCR1B,1);
			clearBit(TCCR1B,2);
			break;
		case 1:
			setBit(TCCR1B,0);
			clearBit(TCCR1B,1);
			clearBit(TCCR1B,2);
			break;
		case 8:
			clearBit(TCCR1B,0);
			setBit(TCCR1B,1);
			clearBit(TCCR1B,2);
			break;
		case 64:
			setBit(TCCR1B,0);
			setBit(TCCR1B,1);
			clearBit(TCCR1B,2);
			break;
		case 256:
			clearBit(TCCR1B,0);
			clearBit(TCCR1B,1);
			setBit(TCCR1B,2);
			break;
		case 1024:
			setBit(TCCR1B,0);
			clearBit(TCCR1B,1);
			setBit(TCCR1B,2);
			break;
		case T1_FALLING:
			clearBit(TCCR1B,0);
			setBit(TCCR1B,1);
			setBit(TCCR1B,2);
			break;
		case T1_RISING:
			setBit(TCCR1B,0);
			setBit(TCCR1B,1);
			setBit(TCCR1B,2);
			break;	
	}
}

void TIM1_FAST_PWM_setICR(u16 copyICR){
	ICR1 = copyICR;
}

void TIM1_FAST_PWM_setOCR(u16 copyOCR){
	OCR1A = copyOCR;
}

void TIM1_inputCaptureEdgeSelect(u8 copyEdge){
	switch(copyEdge) {
		case FALLING:
			clearBit(TCCR1B,6);
			break;
		case RISING:
			setBit(TCCR1B,6);
			break;
	}
}

void TIM1_inputCapture_interruptEnable() {
	setBit(TIMSK,5);
}

void TIM1_inputCapture_interruptDisable() {
	clearBit(TIMSK,5);
}

u16 TIM1_getICR(){
	return ICR1;
}

void TIM1_interrupt(void (*TIM1_localFunctionPointer)(void)) {
	TIM1_globalFunctionPointer= TIM1_localFunctionPointer;
}

void __vector_9()__attribute__((signal));
void __vector_9() {
	if(TIM1_globalFunctionPointer!='\0') TIM1_globalFunctionPointer();
}


void TIM1_CTC_OC1A_interrupt(void (*TIM1_CTC_OC1A_localFunctionPointer)(void)) {
	TIM1_CTC_OC1A_globalFunctionPointer= TIM1_CTC_OC1A_localFunctionPointer;
}

void __vector_7()__attribute__((signal));
void __vector_7() {
	if(TIM1_CTC_OC1A_globalFunctionPointer!='\0') TIM1_CTC_OC1A_globalFunctionPointer();
}

void TIM1_CTC_OC1B_interrupt(void (*TIM1_CTC_OC1B_localFunctionPointer)(void)) {
	TIM1_CTC_OC1B_globalFunctionPointer= TIM1_CTC_OC1B_localFunctionPointer;
}

void __vector_8()__attribute__((signal));
void __vector_8() {
	if(TIM1_CTC_OC1B_globalFunctionPointer!='\0') TIM1_CTC_OC1B_globalFunctionPointer();
}

void TIM1_inputCapture_interrupt(void (*TIM1_inputCapture_localFunctionPointer)(void)) {
	TIM1_inputCapture_globalFunctionPointer= TIM1_inputCapture_localFunctionPointer;
}

void __vector_6()__attribute__((signal));
void __vector_6() {
	if(TIM1_inputCapture_globalFunctionPointer!='\0') TIM1_inputCapture_globalFunctionPointer();
}


/***********************************************Watch Dog Timer*****************************************/


void WDT_enable(){
	setBit(WDTCR,3);
}

void WDT_disable(){
	WDTCR |= (0b00011000);
}

void WDT_sleep(f32 copySleepTime) {
	switch ((int)(copySleepTime*10)) {   // since switch case only accepts integer values
		case 163:
			clearBit(WDTCR,0);
			clearBit(WDTCR,1);
			clearBit(WDTCR,2);
			break;
		case 325:
			setBit(WDTCR,0);
			clearBit(WDTCR,1);
			clearBit(WDTCR,2);
			break;
		case 650:
			clearBit(WDTCR,0);
			setBit(WDTCR,1);
			clearBit(WDTCR,2);
			break;
		case 1300:
			setBit(WDTCR,0);
			setBit(WDTCR,1);
			clearBit(WDTCR,2);
			break;
		case 2600:
			clearBit(WDTCR,0);
			clearBit(WDTCR,1);
			setBit(WDTCR,2);
			break;
		case 5200:
			setBit(WDTCR,0);
			clearBit(WDTCR,1);
			setBit(WDTCR,2);
			break;
		case 10000:
			clearBit(WDTCR,0);
			setBit(WDTCR,1);
			setBit(WDTCR,2);
			break;
		case 21000:
			setBit(WDTCR,0);
			setBit(WDTCR,1);
			setBit(WDTCR,2);
			break;
	}
}
