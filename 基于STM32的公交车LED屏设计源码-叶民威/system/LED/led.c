#include "led.h"

/*
�������ƣ�void LED_Init(void)
�������ܣ�LED��ʼ��
Ӳ�����ӣ�
					LED0 -> PA8
					LED1 -> PD2

					�͵�ƽ����
*/
void LED_Init(void)
{
	//��ʱ��
	RCC->APB2ENR|=1<<2;//GPIOAʱ��ʹ��
	RCC->APB2ENR|=1<<5;//GPIODʱ��ʹ��
	//���üĴ���
	GPIOD->CRL&=0xFFFFF0FF;
	GPIOD->CRL|=0x00000300;
	GPIOA->CRH&=0xFFFFFFF0;
	GPIOA->CRH|=0x00000003;
	//����
	GPIOA->ODR|=0x1<<8;
	GPIOD->ODR|=0x1<<2;
}
