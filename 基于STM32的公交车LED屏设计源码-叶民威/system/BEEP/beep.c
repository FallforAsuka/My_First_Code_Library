#include "beep.h"
/*
函数名称：void BEEP_Init(void)
函数功能：蜂鸣器初始化
硬件链接：PA6
*/
void BEEP_Init(void)
{
	RCC->APB2ENR|=1<<2;//GPIOA时钟使能
	GPIOA->CRL&=0xF0FFFFFF;
	GPIOA->CRL|=0x03000000;
}


