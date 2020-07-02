#include "key.h"
#include "delay.h"
#include "stm32f10x_gpio.h"
/*
函数名称：void KEY_Init(void)
函数功能：按键初始化
硬件链接：
					UP ->PA0
					K0 ->PC1
					K1 ->PC13
					UP按下为高电平  K0 K1按下为低电平
*/
void KEY_Init(void)
{
	//打开时钟
	RCC->APB2ENR|=1<<2;//GPIOA时钟使能
	RCC->APB2ENR|=1<<4;//GPIOC时钟使能
	//配置寄存器
	GPIOA->CRL&=0xFFFFFFF0;
	GPIOA->CRL|=0x00000008;
	
	GPIOC->CRL&=0xFFFFFF0F;
	GPIOC->CRL|=0x00000080;
	
	GPIOC->CRH&=0xFF0FFFFF;
	GPIOC->CRH|=0x00800000;
	
	//上拉
	GPIOC->ODR|=1<<1;
	GPIOC->ODR|=1<<13;
//	//按键1和按键2,的键值检测  
//  GPIO_InitTypeDef  GPIO_InitStructure;
//  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1|GPIO_Pin_13;
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//上拉输入
//  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//  GPIO_Init(GPIOC, &GPIO_InitStructure); 
//	
//	//按键WK_UP,的键值检测  
//  
//  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;//下拉输入
//  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//  GPIO_Init(GPIOA, &GPIO_InitStructure); 
 
}

/*
函数名称：u8 KEY_Scanf(void)
函数功能：获取键值
返 回 值：
					1 代表KEY_UP 按下
					2 代表KEY_0 按下
					3 代表KEY_1 按下

					0	代表没有按键按下
*/
u8 KEY_Scanf(void)
{
	static u8 key_flag=0;//按键状态标识位 0代表没有按下 1代表按下了
	if((KEY_UP || !KEY_0 || !KEY_1 ) && key_flag==0)
	{
		delay_ms(10);//消抖（10ms~30ms）
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









