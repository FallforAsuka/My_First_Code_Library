#ifndef _KEY_H_
#define _KEY_H_

#include "stm32f10x.h"
#include "sys.h"
//#define KEY_UP !!(GPIOA->IDR & 1<<0)
//#define KEY_0 !!(GPIOC->IDR & 1<<1) 
//#define KEY_1 !!(GPIOC->IDR & 1<<13)
//#define KEY_S5 !!(GPIOA->IDR & 1<<5)

#define KEY_UP PAin(0)
#define KEY_0 PCin(1)
#define KEY_1 PCin(13)


void KEY_Init(void);
u8 KEY_Scanf(void);
#endif
