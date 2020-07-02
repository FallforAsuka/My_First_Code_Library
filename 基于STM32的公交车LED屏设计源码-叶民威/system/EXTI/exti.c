#include "exti.h"
#include <stdio.h>
#include <string.h>
#include "key.h"
#include "sys.h"
#include "delay.h"
#include "timer.h"
#include "74hc595.h"
#include "bit_while.h"
#include "hanzi.h"


/*
函数名称：void EXTI_KEY_Init(void)
函数功能：按键中断
硬件链接：						
						UP ->PA0
						K0 ->PC1
						K1 ->PC13
*/
void EXTI_KEY_Init(void)
{
	KEY_Init();
	EXTI->IMR|=1<<0;//开放中断线0的中断请求
	EXTI->IMR|=1<<1;//开放中断线1的中断请求
	EXTI->IMR|=1<<13;//开放中断线13的中断请求
	
	EXTI->FTSR|=1<<0;//允许中断线0下降沿触发请求
	EXTI->RTSR|=1<<0;//允许中断线0上升沿沿触发请求
	EXTI->FTSR|=1<<1;//允许中断线1下降沿触发请求
	EXTI->RTSR|=1<<1;//允许中断线1上升沿沿触发请求
	EXTI->FTSR|=1<<13;//允许中断线13下降沿触发请求
	EXTI->RTSR|=1<<13;//允许中断线13上升沿沿触发请求

	RCC->APB2ENR|=1<<0;//AFIO时钟使能
	AFIO->EXTICR[0]&=~(0xF<< (0*4));//选择输入源为PA0
	AFIO->EXTICR[0]&=~(0xD<< (1*4));//选择输入源为PC1
	AFIO->EXTICR[3]&=~(0xD<< (0*4));//选择输入源为PC13
	STM32_SetPriority(EXTI0_IRQn,0,1);
	STM32_SetPriority(EXTI1_IRQn,1,1);
	STM32_SetPriority(EXTI9_5_IRQn,1,1);
}
/*
函数名称：void EVENT_Init(void)
函数功能：事件中断
*/
void EVENT_Init(void)
{
	EXTI->IMR|=1<<1;//开放中断线1的中断请求
	EXTI->EMR|=1<<1;//开放中断线1的事件请求
	STM32_SetPriority(EXTI1_IRQn,1,1);
}

//void EXTI0_IRQHandler(void)
//{
//	static u8 exti_flag=0;//按键标识位  0代表没有按下  1代表已经按下
//	u32 time;
//	delay_ms(20);
//	if(exti_flag==0 && KEY_S2)
//	{
//		exti_flag=1;
//		TIM4->CNT=0;
//		key_time=0;
//		printf("S2按下\r\n");
//	}
//	else if(exti_flag==1 && !KEY_S2)
//	{
//		exti_flag=0;
//		time=key_time*500+TIM4->CNT/10;
//		printf("按键按下的时间为%d ms\r\n",time);
//		printf("S2松开\r\n");
//	}
//	EXTI->PR|=1<<0;//清除中断线0中断请求
//}
u8 k=0,a=0;
u8 num=0,ww=0,mm=0;
void EXTI0_IRQHandler(void)
{
	static u8 exti_flag=0;//按键标识位  0代表没有按下  1代表已经按下
	delay_ms(20);
	if(exti_flag==0 && KEY_UP)
	{
		memset(LED2X64,0,sizeof(LED2X64));
		memset(xianshi,0,sizeof(xianshi));
		LED0 = !LED0;
		LED1 = !LED1;
		if(a == 0)
		{
			memcpy(hanzi,hanzi_1,sizeof(hanzi_1));
			num=0,ww=0,mm=0;
			a++;
		}else if(a == 1)
		{
			memcpy(hanzi,hanzi_2,sizeof(hanzi_2));		
			num=0,ww=0,mm=0;
			a++;
		}else if(a == 2)
		{
			memcpy(hanzi,hanzi_3,sizeof(hanzi_3));
			num=0,ww=0,mm=0;
			a = 0;
		}
		exti_flag=1;
	}
	if(exti_flag==1 && !KEY_UP)
		exti_flag=0;
	
	TIM1->CNT=0;
	EXTI->PR|=1<<0;//清除中断线0中断请求
}

//void EXTI1_IRQHandler(void)
//{
//	
//	if(!KEY_S3)
//	{
//		printf("S3按下\r\n");
//	}
//	else
//	{
//		printf("S3松开\r\n");
//	}
//	
//	EXTI->PR|=1<<1;//清除中断线1中断请求
//}

//void EXTI4_IRQHandler(void)
//{
//	
//	if(!KEY_S4)
//	{
//		printf("S4按下\r\n");
//	}
//	else
//	{
//		printf("S4松开\r\n");
//	}
//	
//	EXTI->PR|=1<<4;//清除中断线4中断请求
//}

//void EXTI9_5_IRQHandler(void)
//{
//	if(!KEY_S5)
//	{
//		printf("S5按下\r\n");
//	}
//	else
//	{
//		printf("S5松开\r\n");
//	}
//	EXTI->PR|=1<<5;//清除中断线5中断请求
//}
