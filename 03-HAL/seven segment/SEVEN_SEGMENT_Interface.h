#ifndef _SEVEN_SEGMENT_INTERFACE_H_
#define _SEVEN_SEGMENT_INTERFACE_H_

#include "STD_TYPES.h"

#define ANODE 1
#define CATHODE 0

void _7segment_displayNumber(u8 copyPort, u8 copyConnectionType, u8 number);

#endif