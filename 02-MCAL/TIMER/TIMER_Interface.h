#ifndef _TIMER_INTERFACE_H_
#define _TIMER_INTERFACE_H_

#include "STD_TYPES.h"

#define T0_FALLING 100
#define T0_RISING 200

#define T1_FALLING 100
#define T1_RISING 200

#define NORMAL 0
#define TOGGLE 1
#define CLEAR 2
#define SET 3

#define ICR 20

#define OC1A 0
#define OC1B 1

#define CLEAR_ON_MATCH 0
#define SET_ON_MATCH 1

#define FALLING 0
#define RISING 1

/*						Timer 0						*/
void TIM0_init();
void TIM0_disable();
void TIM0_interruptEnable();
void TIM0_interruptDisable();
void TIM0_clockSelect(u16 copyPSC);
void TIM0_preload(u8 copyPreloadValue);
u8 TIM0_getCount();
void TIM0_CTC_init();
void TIM0_CTC_selectMode(u8 copyMode);
void TIM0_CTC_setCompareValue(u8 copyCompareValue);
void TIM0_CTC_interruptEnable();
void TIM0_CTC_interruptDisable();
void TIM0_FAST_PWM_init();
void TIM0_FAST_PWM_selectMode(u8 copyMode);
void TIM0_FAST_PWM_setOCR(u8 copyOCR);
void TIM0_interrupt(void (*TIM0_localFunctionPointer)(void));
void TIM0_CTC_interrupt(void (*TIM0_CTC_localFunctionPointer)(void));

/*						Timer 2						*/
void TIM2_init();
void TIM2_disable();
void TIM2_interruptEnable();
void TIM2_interruptDisable();
void TIM2_clockSelect(u16 copyPSC);
void TIM2_preload(u8 copyPreloadValue);
u8 TIM2_getCount();
void TIM2_CTC_init();
void TIM2_CTC_selectMode(u8 copyMode);
void TIM2_CTC_setCompareValue(u8 copyCompareValue);
void TIM2_CTC_interruptEnable();
void TIM2_CTC_interruptDisable();
void TIM2_interrupt(void (*TIM2_localFunctionPointer)(void));
void TIM2_CTC_interrupt(void (*TIM2_CTC_localFunctionPointer)(void));

/*						Timer 1						*/
void TIM1_init();
void TIM1_disable();
void TIM1_interruptEnable();
void TIM1_interruptDisable();
void TIM1_clockSelect(u16 copyPSC);
void TIM1_preload(u8 copyPreloadValue);
u16 TIM1_getCount();
void TIM1_CTC_init();
void TIM1_CTC_selectMode(u8 copyPin, u8 copyMode);
void TIM1_CTC_setCompareValue(u8 copyPin, u8 copyCompareValue);
void TIM1_CTC_interruptEnable(u8 copyPin);
void TIM1_CTC_interruptDisable(u8 copyPin);
void TIM1_FAST_PWM_init(u8 copyTimerBits);
void TIM1_FAST_PWM_selectMode(u8 copyPin, u8 copyMode);
void TIM1_FAST_PWM_setICR(u16 copyICR);
void TIM1_FAST_PWM_setOCR(u16 copyOCR);
void TIM1_inputCaptureEdgeSelect(u8 copyEdge);
void TIM1_inputCapture_interruptEnable();
void TIM1_inputCapture_interruptDisable();
u16 TIM1_getICR();
void TIM1_interrupt(void (*TIM1_localFunctionPointer)(void));
void TIM1_CTC_OC1A_interrupt(void (*TIM1_CTC_OC1A_localFunctionPointer)(void));
void TIM1_CTC_OC1B_interrupt(void (*TIM1_CTC_OC1B_localFunctionPointer)(void));
void TIM1_inputCapture_interrupt(void (*TIM1_CTC_localFunctionPointer)(void));

/*						Watch Dog Timer						*/
void WDT_enable();
void WDT_disable();
void WDT_sleep(f32 copySleepTime);



#endif
