#include "key.h"
#include "delay.h"
#include "stm32f10x_gpio.h"
/*
�������ƣ�void KEY_Init(void)
�������ܣ�������ʼ��
Ӳ�����ӣ�
					UP ->PA0
					K0 ->PC1
					K1 ->PC13
					UP����Ϊ�ߵ�ƽ  K0 K1����Ϊ�͵�ƽ
*/
void KEY_Init(void)
{
	//��ʱ��
	RCC->APB2ENR|=1<<2;//GPIOAʱ��ʹ��
	RCC->APB2ENR|=1<<4;//GPIOCʱ��ʹ��
	//���üĴ���
	GPIOA->CRL&=0xFFFFFFF0;
	GPIOA->CRL|=0x00000008;
	
	GPIOC->CRL&=0xFFFFFF0F;
	GPIOC->CRL|=0x00000080;
	
	GPIOC->CRH&=0xFF0FFFFF;
	GPIOC->CRH|=0x00800000;
	
	//����
	GPIOC->ODR|=1<<1;
	GPIOC->ODR|=1<<13;
//	//����1�Ͱ���2,�ļ�ֵ���  
//  GPIO_InitTypeDef  GPIO_InitStructure;
//  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1|GPIO_Pin_13;
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//��������
//  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//  GPIO_Init(GPIOC, &GPIO_InitStructure); 
//	
//	//����WK_UP,�ļ�ֵ���  
//  
//  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;//��������
//  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//  GPIO_Init(GPIOA, &GPIO_InitStructure); 
 
}

/*
�������ƣ�u8 KEY_Scanf(void)
�������ܣ���ȡ��ֵ
�� �� ֵ��
					1 ����KEY_UP ����
					2 ����KEY_0 ����
					3 ����KEY_1 ����

					0	����û�а�������
*/
u8 KEY_Scanf(void)
{
	static u8 key_flag=0;//����״̬��ʶλ 0����û�а��� 1��������
	if((KEY_UP || !KEY_0 || !KEY_1 ) && key_flag==0)
	{
		delay_ms(10);//������10ms~30ms��
		key_flag=1;
		if(KEY_UP)return 1;
		else if(!KEY_0)return 2;
		else if(!KEY_1)return 3;
	}
	else
	{
		if(!KEY_UP && KEY_0 && KEY_1) key_flag=0;
	}
	return 0;
}









