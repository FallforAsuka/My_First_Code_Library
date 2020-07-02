#include "74hc595.h"
#include "sys.h"

void hc595_init(void)
{
	//��ʱ��
	RCC->APB2ENR|=1<<2;//GPIOAʱ��ʹ��
	RCC->APB2ENR|=1<<4;//GPIOCʱ��ʹ��
	//���üĴ���
	GPIOA->CRL&=0x0F0F0FFF;
	GPIOA->CRL|=0x30303000;
	
	GPIOC->CRH&=0xFFF000FF;
	GPIOC->CRH|=0x00033300;
	shuju_1=0;							//��ʼ��595IO������
	SH_in_1=0;							//��ʼ��595IO������
	ST_out_1=0;							//��ʼ��595IO������
	shuju_2=0;							//��ʼ��595IO������
	SH_in_2=0;							//��ʼ��595IO������
	ST_out_2=0;							//��ʼ��595IO������

}


void inout595_1(u8 data)//��595����һ���ֽڵ����ݣ�Ȼ���595���������������ͨ���ԡ�
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
void inout595_2(u8 data)//��595����һ���ֽڵ����ݣ�Ȼ���595���������������ͨ���ԡ�
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


u8 Mould[2];  				//���Ƹ��е�ȡģֵ���͵�ƽ���ƣ�ÿ��ģ��16�У�ռ2�ֽ�
u8 upright[2];				//����ĳһ�У��ߵ�ƽ����,ÿ��ģ��16�У�ռ2�ֽ�
void HC595_Write_1(void)
{
	u8 value,i,j=1;
	value=upright[j*2-1];
	for(i=0;i<8;i++) 					//���͸�ÿ��ģ��� U4 ���ߵ�ƽ���п��������͵�ƽ������
	{
		if((value&0x80) == 0x00)
			shuju_1 = 0;
		else
			shuju_1 = 1;
		value<<=1;						//�ֽ�����
		SH_in_1=0;						//ʱ������
		SH_in_1=1;						//ʱ�������ؿ���
	}
	value=upright[j*2-2];
	for(i=0;i<8;i++) 					//���͸�ÿ��ģ��� U3 ���ߵ�ƽ���п��������͵�ƽ������
	{
		if((value&0x80) == 0x00)
			shuju_1 = 0;
		else
			shuju_1 = 1;
		value<<=1;						//�ֽ�����
		SH_in_1=0;						//ʱ������
		SH_in_1=1;						//ʱ�������ؿ���
	}
	value=Mould[j*2-1];
	for(i=0;i<8;i++) 					//���͸�ÿ��ģ��� U2 ���͵�ƽ���п��������ߵ�ƽ����ȫ��
	{
		if((value&0x80) == 0x00)
			shuju_1 = 0;
		else
			shuju_1 = 1;
		value<<=1;						//�ֽ�����
		SH_in_1=0;						//ʱ������
		SH_in_1=1;						//ʱ�������ؿ���
	}
	value=Mould[j*2-2];
	for(i=0;i<8;i++) 					//���͸�ÿ��ģ��� U1 ���͵�ƽ���п��������ߵ�ƽ����ȫ��
	{
		if((value&0x80) == 0x00)
			shuju_1 = 0;
		else
			shuju_1 = 1;
		value<<=1;						//�ֽ�����
		SH_in_1=0;						//ʱ������
		SH_in_1=1;						//ʱ�������ؿ���
	}	
	ST_out_1=1;							//���������źţ������ء�
	shuju_1=0;							//��ʱ
	ST_out_1=0;							//���������źŸ�λ��
	SH_in_1=0;
}

void HC595_Write_2(void)
{
	u8 value,i,j=1;
	value=upright[j*2-1];
	for(i=0;i<8;i++) 					//���͸�ÿ��ģ��� U4 ���ߵ�ƽ���п��������͵�ƽ������
	{
		if((value&0x80) == 0x00)
		{
			shuju_2 = 0;
		}
		else
		{
			shuju_2 = 1;
		}
		value<<=1;						//�ֽ�����
		SH_in_2=0;						//ʱ������
		SH_in_2=1;						//ʱ�������ؿ���
	}
	value=upright[j*2-2];
	for(i=0;i<8;i++) 					//���͸�ÿ��ģ��� U3 ���ߵ�ƽ���п��������͵�ƽ������
	{
		if((value&0x80) == 0x00)
		{
			shuju_2 = 0;
		}
		else
		{
			shuju_2 = 1;
		}
		value<<=1;						//�ֽ�����
		SH_in_2=0;						//ʱ������
		SH_in_2=1;						//ʱ�������ؿ���
	}
	
	value=Mould[j*2-1];
	for(i=0;i<8;i++) 					//���͸�ÿ��ģ��� U2 ���͵�ƽ���п��������ߵ�ƽ����ȫ��
	{
		if((value&0x80) == 0x00)
		{
			shuju_2 = 0;
		}
		else
		{
			shuju_2 = 1;
		}
		value<<=1;						//�ֽ�����
		SH_in_2=0;						//ʱ������
		SH_in_2=1;						//ʱ�������ؿ���
	}
	value=Mould[j*2-2];
	for(i=0;i<8;i++) 					//���͸�ÿ��ģ��� U1 ���͵�ƽ���п��������ߵ�ƽ����ȫ��
	{
		if((value&0x80) == 0x00)
		{
			shuju_2 = 0;
		}
		else
		{
			shuju_2 = 1;
		}
		value<<=1;						//�ֽ�����
		SH_in_2=0;						//ʱ������
		SH_in_2=1;						//ʱ�������ؿ���
	}	
	ST_out_2=1;							//���������źţ������ء�
	shuju_2=0;							//��ʱ
	ST_out_2=0;							//���������źŸ�λ��
	SH_in_2=0;
}

