#ifndef _DC_MOTOR_INTERFACE_H_
#define _DC_MOTOR_INTERFACE_H_

#include "STD_TYPES.h"
#include "DIO_Interface.h"

#define RIGHT 0
#define LEFT 1


void DC_MOTOR_init();
void DC_MOTOR_setDirection(u8 copyDirection);
void DC_MOTOR_STOP();

#endif