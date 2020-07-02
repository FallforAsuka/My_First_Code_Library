#ifndef OLED_H
#define OLED_H
#include "stm32f10x.h"
#include "delay.h"
#include "sys.h"
#include <string.h>

//定义OLED显示屏的接口
#define OLED_SCL  PAout(3)
#define OLED_MOSI PAout(4)
#define OLED_CS   PAout(5)
#define OLED_DC   PAout(6)
#define OLED_RES  PAout(7)

//定义数据与命令
#define OLED_W_CMD 0
#define OLED_W_DAT 1

//OLED相关函数声明
void OLED_Init(void);
void OLED_SetPos(u16 x,u16 y);
void OLED_WriteOneByte(u8 data,u8 cmd);
void OLED_Clear(u8 data);
void OLED_DisplayData(u16 x,u16 y,u16 w,u16 h,u8 *p);
void OLED_DrawPoint(u16 x,u16 y,u8 c);
void OLED_Refresh_GRAM(void);
void OLED_DisplayData(u16 x,u16 y,u16 w,u16 h,u8 *p);
void OLED_Clear_GRAM(void);
#endif
