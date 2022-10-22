#ifndef _ADC_INTERFACE_H_
#define _ADC_INTERFACE_H_

#include "STD_TYPES.h"
#include "DIO_Interface.h"

#define ADC_PORT PORTA_ID

#define ADC0 PIN0
#define ADC1 PIN1
#define ADC2 PIN2
#define ADC3 PIN3
#define ADC4 PIN4
#define ADC5 PIN5
#define ADC6 PIN6
#define ADC7 PIN7

void ADC_init(u8 copyChannel, u8 PSC);
u16 ADC_read();

#endif