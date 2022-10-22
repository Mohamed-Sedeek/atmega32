#ifndef _EXTINT_INTERFACE_H_
#define _EXTINT_INTERFACE_H_

#include "STD_TYPES.h"
#include "DIO_Interface.h"

#define INT0 0
#define INT1 1
#define INT2 2

#define LOW 0
#define FALLING 1
#define RISING 2
#define CHANGE 3

#define INT0_PORT PORTD_ID
#define INT1_PORT PORTD_ID
#define INT2_PORT PORTB_ID

#define INT0_PIN PIN2
#define INT1_PIN PIN3
#define INT2_PIN PIN2

void EXTINT_init(u8 copyINT,u8 copySenseControl);
void EXTINT0(void (EXTINT0_localFunctionPointer)(void));
void EXTINT1(void (EXTINT1_localFunctionPointer)(void));
void EXTINT2(void (EXTINT2_localFunctionPointer)(void));

#endif