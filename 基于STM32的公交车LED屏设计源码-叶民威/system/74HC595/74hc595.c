#include "74hc595.h"
#include "sys.h"

void hc595_init(void)
{
	//打开时钟
	RCC->APB2ENR|=1<<2;//GPIOA时钟使能
	RCC->APB2ENR|=1<<4;//GPIOC时钟使能
	//配置寄存器
	GPIOA->CRL&=0x0F0F0FFF;
	GPIOA->CRL|=0x30303000;
	
	GPIOC->CRH&=0xFFF000FF;
	GPIOC->CRH|=0x00033300;
	shuju_1=0;							//初始化595IO口拉低
	SH_in_1=0;							//初始化595IO口拉低
	ST_out_1=0;							//初始化595IO口拉低
	shuju_2=0;							//初始化595IO口拉低
	SH_in_2=0;							//初始化595IO口拉低
	ST_out_2=0;							//初始化595IO口拉低

}


void inout595_1(u8 data)//向595发送一个字节的数据，然后从595输出，本函数具有通用性。
{
	u8 i;
	SH_in_1 = 1;
	ST_out_1 = 1;
	for(i=0;i<8;i++)
	{
		if((data&0x80) == 0x00)
		{
			shuju_1 = 0;
		}
		else
		{
			shuju_1 = 1;
			
		}
		SH_in_1 = 0;
		SH_in_1 = 1;
		
		data <<= 1;
	}
	ST_out_1 = 0;
	ST_out_1 = 1;
}
void inout595_2(u8 data)//向595发送一个字节的数据，然后从595输出，本函数具有通用性。
{
	u8 i;
	SH_in_2 = 1;
	ST_out_2 = 1;
	for(i=0;i<8;i++)
	{
		if((data&0x80) == 0x00)
		{
			shuju_2 = 0;
		}
		else
		{
			shuju_2 = 1;
			
		}
		SH_in_2 = 0;
		SH_in_2 = 1;
		
		data <<= 1;
	}
	ST_out_2 = 0;
	ST_out_2 = 1;
}


u8 Mould[2];  				//控制该列的取模值，低电平亮灯，每个模组16行，占2字节
u8 upright[2];				//控制某一列，高电平亮灯,每个模组16列，占2字节
void HC595_Write_1(void)
{
	u8 value,i,j=1;
	value=upright[j*2-1];
	for(i=0;i<8;i++) 					//发送给每个模组的 U4 ，高电平整列可以亮，低电平整列灭。
	{
		if((value&0x80) == 0x00)
			shuju_1 = 0;
		else
			shuju_1 = 1;
		value<<=1;						//字节左移
		SH_in_1=0;						//时钟拉低
		SH_in_1=1;						//时钟上升沿拷贝
	}
	value=upright[j*2-2];
	for(i=0;i<8;i++) 					//发送给每个模组的 U3 ，高电平整列可以亮，低电平整列灭。
	{
		if((value&0x80) == 0x00)
			shuju_1 = 0;
		else
			shuju_1 = 1;
		value<<=1;						//字节左移
		SH_in_1=0;						//时钟拉低
		SH_in_1=1;						//时钟上升沿拷贝
	}
	value=Mould[j*2-1];
	for(i=0;i<8;i++) 					//发送给每个模组的 U2 ，低电平整行可以亮，高电平整行全灭。
	{
		if((value&0x80) == 0x00)
			shuju_1 = 0;
		else
			shuju_1 = 1;
		value<<=1;						//字节左移
		SH_in_1=0;						//时钟拉低
		SH_in_1=1;						//时钟上升沿拷贝
	}
	value=Mould[j*2-2];
	for(i=0;i<8;i++) 					//发送给每个模组的 U1 ，低电平整行可以亮，高电平整行全灭。
	{
		if((value&0x80) == 0x00)
			shuju_1 = 0;
		else
			shuju_1 = 1;
		value<<=1;						//字节左移
		SH_in_1=0;						//时钟拉低
		SH_in_1=1;						//时钟上升沿拷贝
	}	
	ST_out_1=1;							//锁存脉冲信号，上升沿。
	shuju_1=0;							//延时
	ST_out_1=0;							//锁存脉冲信号复位。
	SH_in_1=0;
}

void HC595_Write_2(void)
{
	u8 value,i,j=1;
	value=upright[j*2-1];
	for(i=0;i<8;i++) 					//发送给每个模组的 U4 ，高电平整列可以亮，低电平整列灭。
	{
		if((value&0x80) == 0x00)
		{
			shuju_2 = 0;
		}
		else
		{
			shuju_2 = 1;
		}
		value<<=1;						//字节左移
		SH_in_2=0;						//时钟拉低
		SH_in_2=1;						//时钟上升沿拷贝
	}
	value=upright[j*2-2];
	for(i=0;i<8;i++) 					//发送给每个模组的 U3 ，高电平整列可以亮，低电平整列灭。
	{
		if((value&0x80) == 0x00)
		{
			shuju_2 = 0;
		}
		else
		{
			shuju_2 = 1;
		}
		value<<=1;						//字节左移
		SH_in_2=0;						//时钟拉低
		SH_in_2=1;						//时钟上升沿拷贝
	}
	
	value=Mould[j*2-1];
	for(i=0;i<8;i++) 					//发送给每个模组的 U2 ，低电平整行可以亮，高电平整行全灭。
	{
		if((value&0x80) == 0x00)
		{
			shuju_2 = 0;
		}
		else
		{
			shuju_2 = 1;
		}
		value<<=1;						//字节左移
		SH_in_2=0;						//时钟拉低
		SH_in_2=1;						//时钟上升沿拷贝
	}
	value=Mould[j*2-2];
	for(i=0;i<8;i++) 					//发送给每个模组的 U1 ，低电平整行可以亮，高电平整行全灭。
	{
		if((value&0x80) == 0x00)
		{
			shuju_2 = 0;
		}
		else
		{
			shuju_2 = 1;
		}
		value<<=1;						//字节左移
		SH_in_2=0;						//时钟拉低
		SH_in_2=1;						//时钟上升沿拷贝
	}	
	ST_out_2=1;							//锁存脉冲信号，上升沿。
	shuju_2=0;							//延时
	ST_out_2=0;							//锁存脉冲信号复位。
	SH_in_2=0;
}

