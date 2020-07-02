#ifndef _74HC595_
#define _74HC595_

#include "stm32f10x.h"

#define SH_in_1 		PAout(3)   	//SH����ʱ��
#define ST_out_1 		PAout(5)		//ST�������
#define shuju_1			PAout(7)		//DS��������

#define SH_in_2 		PCout(10)   //SH����ʱ��
#define ST_out_2 		PCout(11)		//ST�������
#define shuju_2			PCout(12)		//DS��������

extern u8 Mould[2];  				//���Ƹ��е�ȡģֵ���͵�ƽ���ƣ�ÿ��ģ��16�У�ռ2�ֽ�
extern u8 upright[2];				//����ĳһ�У��ߵ�ƽ����,ÿ��ģ��16�У�ռ2�ֽ�




void hc595_init(void);

void inout595_1(u8 data);
void inout595_2(u8 data);

void HC595_Write_1(void);
void HC595_Write_2(void);



#endif



