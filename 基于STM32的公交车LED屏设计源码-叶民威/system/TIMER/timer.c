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
函数名称：void TIM1_Init(u16 psc,u16 arr)
函数功能：定时器1初始化
参		数：
					arr  重装载值
					psc  预分频系数
*/
void TIM1_Init(u16 psc,u16 arr)
{
	RCC->APB2ENR|=1<<11;//TIM1时钟使能
	RCC->APB2RSTR|=1<<11;//TIM1复位使能
	RCC->APB2RSTR&=~(1<<11);//TIM1复位失能
	
	TIM_ClearFlag(TIM1, TIM_FLAG_Update);//清除溢出中断标志
	TIM_ClearITPendingBit(TIM1, TIM_IT_Update);  		//清除TIMx的中断待处理位:TIM 中断源 
	TIM1->SR=0;
	
	TIM1->DIER|=1<<0;//允许更新中断
	
	TIM_ClearFlag(TIM1, TIM_FLAG_Update);//清除溢出中断标志
	TIM_ClearITPendingBit(TIM1, TIM_IT_Update);  		//清除TIMx的中断待处理位:TIM 中断源 
	TIM1->SR=0;
	
	STM32_SetPriority(TIM1_UP_IRQn,1,1);//设置更新中断优先级
	
	TIM_ClearFlag(TIM1, TIM_FLAG_Update);//清除溢出中断标志
	TIM_ClearITPendingBit(TIM1, TIM_IT_Update);  		//清除TIMx的中断待处理位:TIM 中断源 
	TIM1->SR=0;
	
	TIM1->CNT=0;
	TIM1->ARR=arr;
	TIM1->PSC=psc-1;
	TIM1->CR1|=1<<0;//定时器1
	
	TIM_ClearFlag(TIM1, TIM_FLAG_Update);//清除溢出中断标志
	TIM_ClearITPendingBit(TIM1, TIM_IT_Update);  		//清除TIMx的中断待处理位:TIM 中断源 
	TIM1->SR=0;
	
}

/*
函数名称: TIM1_UP_IRQHandler
函数功能: 定时器1的更新中断服务函数
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
函数名称：void TIM2_Init(u16 psc,u16 arr)
函数功能：定时器2初始化
参		数：
					psc  预分频系数
					arr  重装载值				
*/
void TIM2_Init(u16 psc,u16 arr)
{
	RCC->APB1ENR|=1<<0;//TIM2时钟使能
	RCC->APB1RSTR|=1<<0;//TIM2复位使能
	RCC->APB1RSTR&=~(1<<0);//TIM2复位失能
	TIM2->DIER|=1<<0;//允许更新中断
	STM32_SetPriority(TIM2_IRQn,1,1);//设置更新中断优先级
	TIM2->CNT=0;
	TIM2->ARR=arr;
	TIM2->PSC=psc-1;
	TIM2->CR1|=1<<0;//开启定时器2
}


/*
函数名称：void TIM3_Init(u16 psc,u16 arr)
函数功能：定时器3初始化
参		数：
					arr  重装载值
					psc  预分频系数
*/
void TIM3_Init(u16 psc,u16 arr)
{
	RCC->APB1ENR|=1<<1;//TIM3时钟使能
	RCC->APB1RSTR|=1<<1;//TIM3复位使能
	RCC->APB1RSTR&=~(1<<1);//TIM3复位失能
	TIM3->DIER|=1<<0;//允许更新中断
	STM32_SetPriority(TIM3_IRQn,1,1);//设置更新中断优先级
	TIM3->CNT=0;
	TIM3->ARR=arr;
	TIM3->PSC=psc-1;
	TIM3->CR1|=1<<0;//开启定时器3
}



/*
函数名称: TIM2_IRQHandler
函数功能: 定时器2的中断服务函数
*/
u8 LED2X64[34];				//开辟缓存空间，被定时器随时调用。每列两个字节，多加2个用于移位操作。
void TIM2_IRQHandler(void)
{
	if(TIM2->SR & (1<<0))
	{
		static u8 i;	
		static u16 kkk=0x0001;				//用于16列轮流控制

		Mould[1]=~(LED2X64[i+1]);				//i=0,把缓存的第01号字节发送到第一个模组的最左边的下8位。低电平点亮
		Mould[0]=~(LED2X64[i+0]);				//i=0,把缓存的第00号字节发送到第一个模组的最左边的上8位。
		
		upright[1]=kkk/256;					//16位变量KKK，取高8位。控制第一个模组的0~7列。
		upright[0]=kkk%256;					//16位变量KKK，取低8位。控制第一个模组的8~15列。
		
		kkk=_irol_(kkk,1);					//循环控制0~16列
		i++;i++;
		i=i%32;
		HC595_Write_1();						//595的缓存Mould[8]、upright[8]，得到数据后，立马发送到芯片
	}
  TIM2->SR=0;
}


/*
函数名称: TIM3_IRQHandler
函数功能: 定时器3的中断服务函数
*/
u8 xianshi[34];

void TIM3_IRQHandler(void)
{
  if(TIM3->SR & (1<<0))
	{
		static u8 j;	
		static u16 mmm=0x0001;				//用于16列轮流控制

		Mould[1]=~(xianshi[j+1]);				//i=0,把缓存的第01号字节发送到第一个模组的最左边的下8位。低电平点亮
		Mould[0]=~(xianshi[j+0]);				//i=0,把缓存的第00号字节发送到第一个模组的最左边的上8位。
		
		upright[1]=mmm/256;					//16位变量KKK，取高8位。控制第一个模组的0~7列。
		upright[0]=mmm%256;					//16位变量KKK，取低8位。控制第一个模组的8~15列。
		
		mmm=_irol_(mmm,1);					//循环控制0~16列
		j++;j++;
		j=j%32;
		HC595_Write_2();						//595的缓存Mould[8]、upright[8]，得到数据后，立马发送到芯片
		
	}
  TIM3->SR=0;
}


/*
函数名称：void TIM4_Init(u16 psc,u16 arr)
函数功能：定时器4初始化
参		数：
					arr  重装载值
					psc  预分频系数
*/
void TIM4_Init(u16 psc,u16 arr)
{
	RCC->APB1ENR|=1<<2;//TIM4时钟使能
	RCC->APB1RSTR|=1<<2;//TIM4复位使能
	RCC->APB1RSTR&=~(1<<2);//TIM4复位失能
#ifdef TIM4_IN_IRQ
	TIM4->DIER|=1<<0;//允许更新中断
	STM32_SetPriority(TIM4_IRQn,1,1);
#endif
	TIM4->CNT=0;
	TIM4->ARR=arr;
	TIM4->PSC=psc-1;
	TIM4->CR1|=1<<0;//使能定时器4
}


/*
void TIM4_PWM_Init(u16 psc,u16 arr,u16 cmp)
函数功能：定时器4输出PWM波
参		数：
					arr  重装载值
					psc  预分频系数
					cmp  比较值
硬件链接：
					OC1 PB6
					OC2 PB7
					OC3 PB8
					OC4 PB9
*/
void TIM4_PWM_Init(u16 psc,u16 arr,u16 cmp)
{
	//打开时钟
	RCC->APB1ENR|=1<<2;//TIM4时钟使能
	RCC->APB2ENR|=1<<3;//GPIOB时钟使能
	RCC->APB1RSTR|=1<<2;//TIM4复位使能
	RCC->APB1RSTR&=~(1<<2);//TIM4复位失能
	//GPIOB配置
	GPIOB->CRL&=0x00FFFFFF;
	GPIOB->CRL|=0xBB000000;
	GPIOB->CRH&=0xFFFFFF00;
	GPIOB->CRH|=0x000000BB;
	//定时器4配置
	TIM4->CNT=0;
	TIM4->ARR=arr;
	TIM4->PSC=psc-1;
	TIM4->CR1|=1<<7;//重装载预装载
	//OC1配置
	TIM4->CCMR1&=~(0x3<<0);//OC1通道为输出
	TIM4->CCMR1|=0x6<<4;//PWM1模式 CNT<CCR1 有效
	TIM4->CCMR1|=1<<3;//输出比较预装载使能
	TIM4->CCER|=1<<1;//设置有效电平为低电平
	TIM4->CCER|=1<<0;//开启OC1输出
	TIM4->CCR1=cmp;
	//OC2配置
	TIM4->CCMR1&=~(0x3<<8);//OC2通道为输出
	TIM4->CCMR1|=0x6<<12;//PWM1模式 CNT<CCR1 有效
	TIM4->CCMR1|=1<<11;//输出比较预装载使能
	TIM4->CCER|=1<<5;//设置有效电平为低电平
	TIM4->CCER|=1<<4;//开启OC1输出
	TIM4->CCR2=cmp;
	//OC3配置
	TIM4->CCMR2&=~(0x3<<0);//OC3通道为输出
	TIM4->CCMR2|=0x6<<4;//PWM1模式 CNT<CCR1 有效
	TIM4->CCMR2|=1<<3;//输出比较预装载使能
	TIM4->CCER|=1<<9;//设置有效电平为低电平
	TIM4->CCER|=1<<8;//开启OC1输出
	TIM4->CCR3=cmp;
	//OC4配置
	TIM4->CCMR2&=~(0x3<<8);//OC2通道为输出
	TIM4->CCMR2|=0x6<<12;//PWM1模式 CNT<CCR1 有效
	TIM4->CCMR2|=1<<11;//输出比较预装载使能
	TIM4->CCER|=1<<13;//设置有效电平为低电平
	TIM4->CCER|=1<<12;//开启OC1输出
	TIM4->CCR4=cmp;
	
	TIM4->DIER|=1<<0;//允许更新中断
	STM32_SetPriority(TIM4_IRQn,1,1);
	
	TIM4->CR1|=1<<0;//使能定时器4
	
}	


u32 key_time=0;
void TIM4_IRQHandler(void)
{
//	static u8 dir_flag=0;//0代表自加  1代表自减
	if(TIM4->SR & 1<<0)
	{
		//key_time++;
//		if(TIM4->CCR1==1000)dir_flag=1;
//		else if(TIM4->CCR1==0)dir_flag=0;
//		if(dir_flag==1)TIM4->CCR1--;
//		else if(dir_flag==0)TIM4->CCR1++;
		USART1_RX_FLAG=1;
		TIM4->CR1&=~(1<<0);//失能定时器4
	}
	TIM4->SR=0;
}



