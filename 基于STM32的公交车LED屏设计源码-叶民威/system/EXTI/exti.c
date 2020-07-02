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
�������ƣ�void EXTI_KEY_Init(void)
�������ܣ������ж�
Ӳ�����ӣ�						
						UP ->PA0
						K0 ->PC1
						K1 ->PC13
*/
void EXTI_KEY_Init(void)
{
	KEY_Init();
	EXTI->IMR|=1<<0;//�����ж���0���ж�����
	EXTI->IMR|=1<<1;//�����ж���1���ж�����
	EXTI->IMR|=1<<13;//�����ж���13���ж�����
	
	EXTI->FTSR|=1<<0;//�����ж���0�½��ش�������
	EXTI->RTSR|=1<<0;//�����ж���0�������ش�������
	EXTI->FTSR|=1<<1;//�����ж���1�½��ش�������
	EXTI->RTSR|=1<<1;//�����ж���1�������ش�������
	EXTI->FTSR|=1<<13;//�����ж���13�½��ش�������
	EXTI->RTSR|=1<<13;//�����ж���13�������ش�������

	RCC->APB2ENR|=1<<0;//AFIOʱ��ʹ��
	AFIO->EXTICR[0]&=~(0xF<< (0*4));//ѡ������ԴΪPA0
	AFIO->EXTICR[0]&=~(0xD<< (1*4));//ѡ������ԴΪPC1
	AFIO->EXTICR[3]&=~(0xD<< (0*4));//ѡ������ԴΪPC13
	STM32_SetPriority(EXTI0_IRQn,0,1);
	STM32_SetPriority(EXTI1_IRQn,1,1);
	STM32_SetPriority(EXTI9_5_IRQn,1,1);
}
/*
�������ƣ�void EVENT_Init(void)
�������ܣ��¼��ж�
*/
void EVENT_Init(void)
{
	EXTI->IMR|=1<<1;//�����ж���1���ж�����
	EXTI->EMR|=1<<1;//�����ж���1���¼�����
	STM32_SetPriority(EXTI1_IRQn,1,1);
}

//void EXTI0_IRQHandler(void)
//{
//	static u8 exti_flag=0;//������ʶλ  0����û�а���  1�����Ѿ�����
//	u32 time;
//	delay_ms(20);
//	if(exti_flag==0 && KEY_S2)
//	{
//		exti_flag=1;
//		TIM4->CNT=0;
//		key_time=0;
//		printf("S2����\r\n");
//	}
//	else if(exti_flag==1 && !KEY_S2)
//	{
//		exti_flag=0;
//		time=key_time*500+TIM4->CNT/10;
//		printf("�������µ�ʱ��Ϊ%d ms\r\n",time);
//		printf("S2�ɿ�\r\n");
//	}
//	EXTI->PR|=1<<0;//����ж���0�ж�����
//}
u8 k=0,a=0;
u8 num=0,ww=0,mm=0;
void EXTI0_IRQHandler(void)
{
	static u8 exti_flag=0;//������ʶλ  0����û�а���  1�����Ѿ�����
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
	EXTI->PR|=1<<0;//����ж���0�ж�����
}

//void EXTI1_IRQHandler(void)
//{
//	
//	if(!KEY_S3)
//	{
//		printf("S3����\r\n");
//	}
//	else
//	{
//		printf("S3�ɿ�\r\n");
//	}
//	
//	EXTI->PR|=1<<1;//����ж���1�ж�����
//}

//void EXTI4_IRQHandler(void)
//{
//	
//	if(!KEY_S4)
//	{
//		printf("S4����\r\n");
//	}
//	else
//	{
//		printf("S4�ɿ�\r\n");
//	}
//	
//	EXTI->PR|=1<<4;//����ж���4�ж�����
//}

//void EXTI9_5_IRQHandler(void)
//{
//	if(!KEY_S5)
//	{
//		printf("S5����\r\n");
//	}
//	else
//	{
//		printf("S5�ɿ�\r\n");
//	}
//	EXTI->PR|=1<<5;//����ж���5�ж�����
//}
