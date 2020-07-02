#include "led.h"

/*
函数名称：void LED_Init(void)
函数功能：LED初始化
硬件链接：
					LED0 -> PA8
					LED1 -> PD2

					低电平点亮
*/
void LED_Init(void)
{
	//打开时钟
	RCC->APB2ENR|=1<<2;//GPIOA时钟使能
	RCC->APB2ENR|=1<<5;//GPIOD时钟使能
	//配置寄存器
	GPIOD->CRL&=0xFFFFF0FF;
	GPIOD->CRL|=0x00000300;
	GPIOA->CRH&=0xFFFFFFF0;
	GPIOA->CRH|=0x00000003;
	//上拉
	GPIOA->ODR|=0x1<<8;
	GPIOD->ODR|=0x1<<2;
}
