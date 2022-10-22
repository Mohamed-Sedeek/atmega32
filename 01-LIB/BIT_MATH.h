/************************************************************************************/
/* Author: Mohamed Sedeek                                                           */
/* Date: 17 Aug 2022                                                                */
/* Version: 01                                                                      */
/************************************************************************************/

#ifndef _BIT_MATH_H_
#define _BIT_MATH_H_

#define setBit(reg,bit) reg=reg|(1<<bit)
#define clearBit(reg,bit) reg=reg&(~(1<<bit))
#define toggleBit(reg,bit) reg=reg^(1<<bit)
#define getBit(reg,bit) (reg>>bit)&1

#endif