#ifndef _EXTINT_PRIVATE_H_
#define _EXTINT_PRIVATE_H_

#define MCUCR *((volatile u8*)0x55)
#define MCUCSR *((volatile u8*)0x54)
#define GICR *((volatile u8*)0x5B)
#define GIFR *((volatile u8*)0x5A)

#endif