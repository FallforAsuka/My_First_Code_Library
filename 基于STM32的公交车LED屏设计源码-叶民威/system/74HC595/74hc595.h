#ifndef _74HC595_
#define _74HC595_

#include "stm32f10x.h"

#define SH_in_1 		PAout(3)   	//SH输入时钟
#define ST_out_1 		PAout(5)		//ST输出锁存
#define shuju_1			PAout(7)		//DS输入数据

#define SH_in_2 		PCout(10)   //SH输入时钟
#define ST_out_2 		PCout(11)		//ST输出锁存
#define shuju_2			PCout(12)		//DS输入数据

extern u8 Mould[2];  				//控制该列的取模值，低电平亮灯，每个模组16行，占2字节
extern u8 upright[2];				//控制某一列，高电平亮灯,每个模组16列，占2字节




void hc595_init(void);

void inout595_1(u8 data);
void inout595_2(u8 data);

void HC595_Write_1(void);
void HC595_Write_2(void);



#endif



