#ifndef _SPI_INTERFACE_H_
#define _SPI_INTERFACE_H_

#include "STD_TYPES.h"

#define SPI_SLAVE 0
#define SPI_MASTER 1

#define LSB_FIRST 0
#define MSB_FIRST 1


void SPI_enable(u8 copyMode, u8 copyPSC);
void SPI_disable();
void SPI_dataOrder(u8 copyDataOrder);
void SPI_interruptEnable();
void SPI_interruptDisable();
u8 SPI_transceiver(u8 copyData);
void SPI_interrupt(void (SPI_localfunctionPointer)(void));


#endif