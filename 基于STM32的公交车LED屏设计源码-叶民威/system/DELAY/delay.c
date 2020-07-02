#include "delay.h"

void delay_ms(u32 time)//1ms
{
	u32 i,j,k;
	for(i=0;i<time;i++)
		for(j=0;j<100;j++)
			for(k=0;k<100;k++);
}

void delay_us(u32 time)//1us
{
	u32 i,j;
	for(i=0;i<time;i++)
		for(j=0;j<10;j++);
}


void Delay_Ms(u32 time)
{
    u32 tmp;
    SysTick->LOAD=time*9000; //���ö�ʱ��ʱ��
    SysTick->VAL=0;          //��������ֵ���0
    SysTick->CTRL|=1<<0;     //�����δ�ʱ��
    do
    {
      tmp= SysTick->CTRL; //��ȡ�Ĵ�����״̬ 
    }while(!(tmp&(1<<16))); //�ж϶�ʱ����ʱ�Ƿ񵽴�
    SysTick->CTRL=0; //�رյδ�ʱ��
}

void Delay_Us(u32 time)
{
    u32 tmp;
    SysTick->LOAD=time*9; //���ö�ʱ��ʱ��
    SysTick->VAL=0;          //��������ֵ���0
    SysTick->CTRL|=1<<0;     //�����δ�ʱ��
    do
    {
      tmp= SysTick->CTRL; //��ȡ�Ĵ�����״̬ 
    }while(!(tmp&(1<<16))); //�ж϶�ʱ����ʱ�Ƿ񵽴�
    SysTick->CTRL=0; //�رյδ�ʱ��
}
