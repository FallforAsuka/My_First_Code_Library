#include "stm32f10x.h"
#include "beep.h"
#include "delay.h"
#include "led.h"
#include "key.h"
#include "sys.h"
#include "usart.h"
#include <string.h>
#include <stdio.h>
#include "exti.h"
#include "timer.h"
#include "rtc.h"
#include "adc.h"
#include "ds18b20.h"
#include "ble.h"
#include "esp8266.h"
#include "wdg.h"
#include "oled.h"
#include "74hc595.h"
#include "bit_while.h"
#include "hanzi.h"


	

int main()
{   
  LED_Init();
  KEY_Init();
	USART1_Init(115200);
	hc595_init();
	EXTI_KEY_Init();
	//72MHZ/36000=2000HZ	1s 2K次 1次 0.0005s 0.5ms 我需要29
	TIM1_Init(36000,2000*29.3);//用于切换车次信息
	//默认时钟频率72MHZ 72MHZ/7200=10000HZ 也就是1s 1万次，1次 0.0001s 也就是0.1ms
	TIM2_Init(7200,10);//1000HZ才趋于稳定 1ms
	TIM3_Init(7200,10);//用于输出数据到595
	u32 timer;
  while(1)
  {
		//timer越大 移动速度越慢
		timer=200000;							
		while(timer--);					//延时，可以干其他事情
		
		
		LED2X64[32]=hanzi[ww][num]; 	//把要显示的内容放到最右边，上八位。
		xianshi[32]=hanzi[mm][num];
		num++;
		LED2X64[33]=hanzi[ww][num]; 	//把要显示的内容放到最右边，下八位。
		xianshi[33]=hanzi[mm][num];
		num++;
		if(num>=32)						//每个字最多0~31个字节的模。
		{
			num=0;
			ww++,mm++;					//决定了 指向每个汉字的数组
			if(mm>=5)						//副屏 4个字 多1个字全黑更美观
			{
				mm=0;
			}
			if(ww>=35)					//主屏 总共34个汉字 多1个全黑（英文都算16*16).
			{
				ww=0;
			}
		}
		for(k=0;k<32;k++)				//把数组2字节的内容拷贝给0字节，再把4拷贝给2，以此类推。
		{								//把数组3字节的内容拷贝给1字节，再把5拷贝给3，以此类推。
			LED2X64[k]=LED2X64[k+2];
		}
		for(k=0;k<32;k++)				//把数组2字节的内容拷贝给0字节，再把4拷贝给2，以此类推。
		{								//把数组3字节的内容拷贝给1字节，再把5拷贝给3，以此类推。
			xianshi[k]=xianshi[k+2];
		}

	}

}
		

