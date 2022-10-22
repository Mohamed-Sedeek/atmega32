#ifndef _DIO_INTERFACE_H_
#define _DIO_INTERFACE_H_

#include "STD_TYPES.h"
#include "DIO_Private.h"

#define PORTA_ID 0
#define PORTB_ID 1
#define PORTC_ID 2
#define PORTD_ID 3

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

#define OUTPUT 1
#define INPUT 0

#define HIGH 1
#define LOW 0

#define ALL_PINS_OUTPUT 0xff
#define ALL_PINS_INPUT 0x00

#define ALL_PINS_HIGH 0xff
#define ALL_PINS_LOW 0x00


/*			Prototypes			*/
void DIO_setPinDirection(u8 copyPort, u8 copyPin, u8 copyDirecton);
void DIO_setPinValue(u8 copyPort, u8 copyPin, u8 copyValue);
void DIO_setPortDirection(u8 copyPort, u8 copyDirection);
void DIO_setPortValue(u8 copyPort, u8 copyValue);
void DIO_togglePinValue(u8 copyPort, u8 copyPin);
u8 DIO_getPinState(u8 copyPort, u8 copyPin);

#endif