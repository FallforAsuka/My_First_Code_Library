#include "beep.h"
/*
�������ƣ�void BEEP_Init(void)
�������ܣ���������ʼ��
Ӳ�����ӣ�PA6
*/
void BEEP_Init(void)
{
	RCC->APB2ENR|=1<<2;//GPIOAʱ��ʹ��
	GPIOA->CRL&=0xF0FFFFFF;
	GPIOA->CRL|=0x03000000;
}


