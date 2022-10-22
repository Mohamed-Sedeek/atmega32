#ifndef _USART_INTERFACE_H_
#define _USART_INTERFACE_H_

#include "STD_TYPES.h"

void UART_init(u32 copyBaudRate);
void UART_write(u8 copyData);
u8 UART_read();



#endif