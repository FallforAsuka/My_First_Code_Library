#ifndef _TIMER_H_
#define _TIMER_H_

#include "stm32f10x.h"
extern u32 key_time;
extern u8 LED2X64[34];				//开辟缓存空间，被定时器随时调用。每列两个字节，多加2个用于移位操作。
extern u8 xianshi[34];

void TIM4_Init(u16 psc,u16 arr);
void TIM4_PWM_Init(u16 psc,u16 arr,u16 cmp);
void TIM1_Init(u16 psc,u16 arr);
void TIM2_Init(u16 psc,u16 arr);
void TIM3_Init(u16 psc,u16 arr);
#endif
