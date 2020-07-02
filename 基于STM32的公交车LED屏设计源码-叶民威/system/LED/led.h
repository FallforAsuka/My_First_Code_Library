#ifndef _LED_H_
#define _LED_H_

#include "stm32f10x.h"
//#define LED1(x)if(x){GPIOB->ODR|=1<<6;}else{GPIOB->ODR&=~(1<<6);}
//#define LED2(x)if(x){GPIOB->ODR|=1<<7;}else{GPIOB->ODR&=~(1<<7);}
//#define LED3(x)if(x){GPIOB->ODR|=1<<8;}else{GPIOB->ODR&=~(1<<8);}
//#define LED4(x)if(x){GPIOB->ODR|=1<<9;}else{GPIOB->ODR&=~(1<<9);}

#define LED0 PAout(8)
#define LED1 PDout(2)



void LED_Init(void);

#endif
