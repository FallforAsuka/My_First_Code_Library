#ifndef _BEEP_H_
#define _BEEP_H_

#include "stm32f10x.h"
#include "sys.h"
//#define BEEP(x) if(x){GPIOA->ODR|=1<<6;}else{GPIOA->ODR&=~(1<<6);}
#define BEEP PAout(6)

void BEEP_Init(void);

#endif



