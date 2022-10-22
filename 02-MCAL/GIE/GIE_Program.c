#include "GIE_private.h"
#include "GIE_Interface.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"


void GIE_enable(){
	setBit(SREG,7);
}

void GIE_disable(){
	clearBit(SREG,7);
}