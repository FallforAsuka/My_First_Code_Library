#include "timer.h"
#include "sys.h"
#include "beep.h"
#include "usart.h"
#include "led.h"
#include "74hc595.h"
#include "bit_while.h"
#include "exti.h"
#include "hanzi.h"
/*
�������ƣ�void TIM1_Init(u16 psc,u16 arr)
�������ܣ���ʱ��1��ʼ��
��		����
					arr  ��װ��ֵ
					psc  Ԥ��Ƶϵ��
*/
void TIM1_Init(u16 psc,u16 arr)
{
	RCC->APB2ENR|=1<<11;//TIM1ʱ��ʹ��
	RCC->APB2RSTR|=1<<11;//TIM1��λʹ��
	RCC->APB2RSTR&=~(1<<11);//TIM1��λʧ��
	
	TIM_ClearFlag(TIM1, TIM_FLAG_Update);//�������жϱ�־
	TIM_ClearITPendingBit(TIM1, TIM_IT_Update);  		//���TIMx���жϴ�����λ:TIM �ж�Դ 
	TIM1->SR=0;
	
	TIM1->DIER|=1<<0;//��������ж�
	
	TIM_ClearFlag(TIM1, TIM_FLAG_Update);//�������жϱ�־
	TIM_ClearITPendingBit(TIM1, TIM_IT_Update);  		//���TIMx���жϴ�����λ:TIM �ж�Դ 
	TIM1->SR=0;
	
	STM32_SetPriority(TIM1_UP_IRQn,1,1);//���ø����ж����ȼ�
	
	TIM_ClearFlag(TIM1, TIM_FLAG_Update);//�������жϱ�־
	TIM_ClearITPendingBit(TIM1, TIM_IT_Update);  		//���TIMx���жϴ�����λ:TIM �ж�Դ 
	TIM1->SR=0;
	
	TIM1->CNT=0;
	TIM1->ARR=arr;
	TIM1->PSC=psc-1;
	TIM1->CR1|=1<<0;//��ʱ��1
	
	TIM_ClearFlag(TIM1, TIM_FLAG_Update);//�������жϱ�־
	TIM_ClearITPendingBit(TIM1, TIM_IT_Update);  		//���TIMx���жϴ�����λ:TIM �ж�Դ 
	TIM1->SR=0;
	
}

/*
��������: TIM1_UP_IRQHandler
��������: ��ʱ��1�ĸ����жϷ�����
*/
void TIM1_UP_IRQHandler(void)
{
  if(TIM1->SR & (1<<0))
	{
		LED0 = !LED0;
		LED1 = !LED1;
		memset(LED2X64,0,sizeof(LED2X64));
		memset(xianshi,0,sizeof(xianshi));
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
	}
  TIM1->SR=0;
}

/*
�������ƣ�void TIM2_Init(u16 psc,u16 arr)
�������ܣ���ʱ��2��ʼ��
��		����
					psc  Ԥ��Ƶϵ��
					arr  ��װ��ֵ				
*/
void TIM2_Init(u16 psc,u16 arr)
{
	RCC->APB1ENR|=1<<0;//TIM2ʱ��ʹ��
	RCC->APB1RSTR|=1<<0;//TIM2��λʹ��
	RCC->APB1RSTR&=~(1<<0);//TIM2��λʧ��
	TIM2->DIER|=1<<0;//��������ж�
	STM32_SetPriority(TIM2_IRQn,1,1);//���ø����ж����ȼ�
	TIM2->CNT=0;
	TIM2->ARR=arr;
	TIM2->PSC=psc-1;
	TIM2->CR1|=1<<0;//������ʱ��2
}


/*
�������ƣ�void TIM3_Init(u16 psc,u16 arr)
�������ܣ���ʱ��3��ʼ��
��		����
					arr  ��װ��ֵ
					psc  Ԥ��Ƶϵ��
*/
void TIM3_Init(u16 psc,u16 arr)
{
	RCC->APB1ENR|=1<<1;//TIM3ʱ��ʹ��
	RCC->APB1RSTR|=1<<1;//TIM3��λʹ��
	RCC->APB1RSTR&=~(1<<1);//TIM3��λʧ��
	TIM3->DIER|=1<<0;//��������ж�
	STM32_SetPriority(TIM3_IRQn,1,1);//���ø����ж����ȼ�
	TIM3->CNT=0;
	TIM3->ARR=arr;
	TIM3->PSC=psc-1;
	TIM3->CR1|=1<<0;//������ʱ��3
}



/*
��������: TIM2_IRQHandler
��������: ��ʱ��2���жϷ�����
*/
u8 LED2X64[34];				//���ٻ���ռ䣬����ʱ����ʱ���á�ÿ�������ֽڣ����2��������λ������
void TIM2_IRQHandler(void)
{
	if(TIM2->SR & (1<<0))
	{
		static u8 i;	
		static u16 kkk=0x0001;				//����16����������

		Mould[1]=~(LED2X64[i+1]);				//i=0,�ѻ���ĵ�01���ֽڷ��͵���һ��ģ�������ߵ���8λ���͵�ƽ����
		Mould[0]=~(LED2X64[i+0]);				//i=0,�ѻ���ĵ�00���ֽڷ��͵���һ��ģ�������ߵ���8λ��
		
		upright[1]=kkk/256;					//16λ����KKK��ȡ��8λ�����Ƶ�һ��ģ���0~7�С�
		upright[0]=kkk%256;					//16λ����KKK��ȡ��8λ�����Ƶ�һ��ģ���8~15�С�
		
		kkk=_irol_(kkk,1);					//ѭ������0~16��
		i++;i++;
		i=i%32;
		HC595_Write_1();						//595�Ļ���Mould[8]��upright[8]���õ����ݺ������͵�оƬ
	}
  TIM2->SR=0;
}


/*
��������: TIM3_IRQHandler
��������: ��ʱ��3���жϷ�����
*/
u8 xianshi[34];

void TIM3_IRQHandler(void)
{
  if(TIM3->SR & (1<<0))
	{
		static u8 j;	
		static u16 mmm=0x0001;				//����16����������

		Mould[1]=~(xianshi[j+1]);				//i=0,�ѻ���ĵ�01���ֽڷ��͵���һ��ģ�������ߵ���8λ���͵�ƽ����
		Mould[0]=~(xianshi[j+0]);				//i=0,�ѻ���ĵ�00���ֽڷ��͵���һ��ģ�������ߵ���8λ��
		
		upright[1]=mmm/256;					//16λ����KKK��ȡ��8λ�����Ƶ�һ��ģ���0~7�С�
		upright[0]=mmm%256;					//16λ����KKK��ȡ��8λ�����Ƶ�һ��ģ���8~15�С�
		
		mmm=_irol_(mmm,1);					//ѭ������0~16��
		j++;j++;
		j=j%32;
		HC595_Write_2();						//595�Ļ���Mould[8]��upright[8]���õ����ݺ������͵�оƬ
		
	}
  TIM3->SR=0;
}


/*
�������ƣ�void TIM4_Init(u16 psc,u16 arr)
�������ܣ���ʱ��4��ʼ��
��		����
					arr  ��װ��ֵ
					psc  Ԥ��Ƶϵ��
*/
void TIM4_Init(u16 psc,u16 arr)
{
	RCC->APB1ENR|=1<<2;//TIM4ʱ��ʹ��
	RCC->APB1RSTR|=1<<2;//TIM4��λʹ��
	RCC->APB1RSTR&=~(1<<2);//TIM4��λʧ��
#ifdef TIM4_IN_IRQ
	TIM4->DIER|=1<<0;//��������ж�
	STM32_SetPriority(TIM4_IRQn,1,1);
#endif
	TIM4->CNT=0;
	TIM4->ARR=arr;
	TIM4->PSC=psc-1;
	TIM4->CR1|=1<<0;//ʹ�ܶ�ʱ��4
}


/*
void TIM4_PWM_Init(u16 psc,u16 arr,u16 cmp)
�������ܣ���ʱ��4���PWM��
��		����
					arr  ��װ��ֵ
					psc  Ԥ��Ƶϵ��
					cmp  �Ƚ�ֵ
Ӳ�����ӣ�
					OC1 PB6
					OC2 PB7
					OC3 PB8
					OC4 PB9
*/
void TIM4_PWM_Init(u16 psc,u16 arr,u16 cmp)
{
	//��ʱ��
	RCC->APB1ENR|=1<<2;//TIM4ʱ��ʹ��
	RCC->APB2ENR|=1<<3;//GPIOBʱ��ʹ��
	RCC->APB1RSTR|=1<<2;//TIM4��λʹ��
	RCC->APB1RSTR&=~(1<<2);//TIM4��λʧ��
	//GPIOB����
	GPIOB->CRL&=0x00FFFFFF;
	GPIOB->CRL|=0xBB000000;
	GPIOB->CRH&=0xFFFFFF00;
	GPIOB->CRH|=0x000000BB;
	//��ʱ��4����
	TIM4->CNT=0;
	TIM4->ARR=arr;
	TIM4->PSC=psc-1;
	TIM4->CR1|=1<<7;//��װ��Ԥװ��
	//OC1����
	TIM4->CCMR1&=~(0x3<<0);//OC1ͨ��Ϊ���
	TIM4->CCMR1|=0x6<<4;//PWM1ģʽ CNT<CCR1 ��Ч
	TIM4->CCMR1|=1<<3;//����Ƚ�Ԥװ��ʹ��
	TIM4->CCER|=1<<1;//������Ч��ƽΪ�͵�ƽ
	TIM4->CCER|=1<<0;//����OC1���
	TIM4->CCR1=cmp;
	//OC2����
	TIM4->CCMR1&=~(0x3<<8);//OC2ͨ��Ϊ���
	TIM4->CCMR1|=0x6<<12;//PWM1ģʽ CNT<CCR1 ��Ч
	TIM4->CCMR1|=1<<11;//����Ƚ�Ԥװ��ʹ��
	TIM4->CCER|=1<<5;//������Ч��ƽΪ�͵�ƽ
	TIM4->CCER|=1<<4;//����OC1���
	TIM4->CCR2=cmp;
	//OC3����
	TIM4->CCMR2&=~(0x3<<0);//OC3ͨ��Ϊ���
	TIM4->CCMR2|=0x6<<4;//PWM1ģʽ CNT<CCR1 ��Ч
	TIM4->CCMR2|=1<<3;//����Ƚ�Ԥװ��ʹ��
	TIM4->CCER|=1<<9;//������Ч��ƽΪ�͵�ƽ
	TIM4->CCER|=1<<8;//����OC1���
	TIM4->CCR3=cmp;
	//OC4����
	TIM4->CCMR2&=~(0x3<<8);//OC2ͨ��Ϊ���
	TIM4->CCMR2|=0x6<<12;//PWM1ģʽ CNT<CCR1 ��Ч
	TIM4->CCMR2|=1<<11;//����Ƚ�Ԥװ��ʹ��
	TIM4->CCER|=1<<13;//������Ч��ƽΪ�͵�ƽ
	TIM4->CCER|=1<<12;//����OC1���
	TIM4->CCR4=cmp;
	
	TIM4->DIER|=1<<0;//��������ж�
	STM32_SetPriority(TIM4_IRQn,1,1);
	
	TIM4->CR1|=1<<0;//ʹ�ܶ�ʱ��4
	
}	


u32 key_time=0;
void TIM4_IRQHandler(void)
{
//	static u8 dir_flag=0;//0�����Լ�  1�����Լ�
	if(TIM4->SR & 1<<0)
	{
		//key_time++;
//		if(TIM4->CCR1==1000)dir_flag=1;
//		else if(TIM4->CCR1==0)dir_flag=0;
//		if(dir_flag==1)TIM4->CCR1--;
//		else if(dir_flag==0)TIM4->CCR1++;
		USART1_RX_FLAG=1;
		TIM4->CR1&=~(1<<0);//ʧ�ܶ�ʱ��4
	}
	TIM4->SR=0;
}



