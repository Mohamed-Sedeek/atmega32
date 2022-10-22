#include "STD_TYPES.h"
#include "DIO_Interface.h"
#include "DC_MOTOR_Interface.h"
#include "DC_MOTOR_config.h"

void DC_MOTOR_init(){
	DIO_setPinDirection(DC_MOTOR_PORT,DC_MOTOR_PIN1,OUTPUT);
	DIO_setPinDirection(DC_MOTOR_PORT,DC_MOTOR_PIN2,OUTPUT);
}

void DC_MOTOR_setDirection(u8 copyDirection){
	switch(copyDirection) {
		case RIGHT:
			DIO_setPinValue(DC_MOTOR_PORT,DC_MOTOR_PIN2,LOW);
			DIO_setPinValue(DC_MOTOR_PORT,DC_MOTOR_PIN1,HIGH);
			break;
			
		case LEFT:
			DIO_setPinValue(DC_MOTOR_PORT,DC_MOTOR_PIN1,LOW);
			DIO_setPinValue(DC_MOTOR_PORT,DC_MOTOR_PIN2,HIGH);
			break;
	}
}

void DC_MOTOR_stop() {
	DIO_setPinValue(DC_MOTOR_PORT,DC_MOTOR_PIN1,LOW);
	DIO_setPinValue(DC_MOTOR_PORT,DC_MOTOR_PIN2,LOW);
}

