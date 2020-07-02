#include "hanzi.h"


/*
取模方式:  横向取模,高位在前
尺寸:18*29   ->24*29
*/
const u8 OnFoot_2_1[]=
{
  0x00,0x38,0x00,0x00,0x78,0x00,0x00,
  0x38,0x00,0x00,0x38,0x00,0x00,0x78,
  0x00,0x01,0xF8,0x00,0x03,0xF8,0x00,
  0x03,0xF8,0x00,0x0E,0xF8,0x00,0x07,
  0xFC,0x00,0x03,0xFC,0x00,0x00,0xF8,
  0x00,0x00,0xF8,0x00,0x00,0xF8,0x00,
  0x00,0xF8,0x00,0x00,0x78,0x00,0x00,
  0x78,0x00,0x00,0xFC,0x00,0x00,0xFC,
  0x00,0x00,0xEE,0x00,0xDF,0xEE,0x00,
  0xFF,0xCE,0x00,0xE0,0x0E,0x00,0x80,
  0x0E,0x00,0x80,0x06,0x00,0x00,0x06,
  0x00,0x00,0x03,0x00,0x00,0x07,0x00,
  0x00,0x07,0xC0 /*OnFoot_2_1.bmp",0*/
};

/*
取模方式:  横向取模,高位在前
尺寸:17*32   ->24*32
*/
const u8 OnFoot_2_2[]=
{
  0x00,0xF0,0x00,0x00,0xF0,0x00,0x00,0xF0,0x00,
  0x00,0xF0,0x00,0x01,0xC0,0x00,0x03,0xE0,0x00,
  0x07,0xE0,0x00,0x07,0xE0,0x00,0x0F,0xE0,0x00,
  0x0F,0xE1,0x00,0x0F,0xFF,0x80,0x07,0xFF,0x80,
  0x07,0xC0,0x00,0x07,0xC0,0x00,0x07,0xC0,0x00,
  0x07,0xC0,0x00,0x07,0xC0,0x00,0x07,0xE0,0x00,
  0x07,0xF0,0x00,0x07,0xF8,0x00,0x07,0xF8,0x00,
  0x07,0x3C,0x00,0x07,0xF8,0x00,0x0F,0xE0,0x00,
  0x0F,0x80,0x00,0x1E,0x00,0x00,0x3E,0x00,0x00,
  0x36,0x00,0x00,0x76,0x00,0x00,0xE0,0x00,0x00,
  0xE0,0x00,0x00,0x78,0x00,0x00
};

#ifdef photo
const u8 hanzi[6][32]=
{
//五角星
	{	0x00,0x00,0x04,0x00,0x06,0x02,0x07,0x0C,0x07,0xBC,0x07,0xF8,0x0F,0xF8,0x3F,0xF0,0xFF,0xE0,0x3F,0xF0,0x0F,0xF8,0x07,0xF8,0x07,0xBC,0x07,0x0C,0x06,0x02,0x04,0x00		},
//黑桃
	{ 	0x00,0x00,0x03,0xC0,0x07,0xE0,0x0F,0xF0,0x1F,0xF0,0x3F,0xE1,0x7F,0xC3,0xFF,0xFF,0xFF,0xFF,0x7F,0xC3,0x3F,0xE1,0x1F,0xF0,0x0F,0xF0,0x07,0xE0,0x03,0xC0,0x00,0x00		},
//红心
	{	0x00,0x00,0x07,0x80,0x0F,0xC0,0x1F,0xE0,0x1F,0xF0,0x1F,0xF8,0x0F,0xFC,0x07,0xFE,0x07,0xFE,0x0F,0xFC,0x1F,0xF8,0x1F,0xF0,0x1F,0xE0,0x0F,0xC0,0x07,0x80,0x00,0x00		},
//梅花
	{ 	0x00,0x00,0x00,0xE0,0x01,0xF0,0x03,0xF8,0x33,0xF8,0x79,0xF1,0xFD,0xE3,0xFF,0xFF,0xFF,0xFF,0xFD,0xE3,0x79,0xF1,0x33,0xF8,0x03,0xF8,0x01,0xF0,0x00,0xE0,0x00,0x00		},
//方片
	{	0x00,0x00,0x01,0x00,0x03,0x80,0x07,0xC0,0x0F,0xE0,0x1F,0xF0,0x3F,0xF8,0x7F,0xFC,0xFF,0xFE,0x7F,0xFC,0x3F,0xF8,0x1F,0xF0,0x0F,0xE0,0x07,0xC0,0x03,0x80,0x01,0x00		},
//花点		
	{	0xAA,0xAA,0x55,0x55,0xAA,0xAA,0x55,0x55,0xAA,0xAA,0x55,0x55,0xAA,0xAA,0x55,0x55,0xAA,0xAA,0x55,0x55,0xAA,0xAA,0x55,0x55,0xAA,0xAA,0x55,0x55,0xAA,0xAA,0x55,0x55		}
	};
#endif	

	
u8 hanzi[40][32];
	
//211
const u8 hanzi_1[35][32] =
{
	{0x00,0x00,0x0E,0x0C,0x10,0x14,0x10,0x24,0x10,0x44,0x11,0x84,0x0E,0x0C,0x00,0x00},/*"2",0*/
	/* (8 X 16 , 宋体 ) */

	{0x00,0x00,0x08,0x04,0x08,0x04,0x1F,0xFC,0x00,0x04,0x00,0x04,0x00,0x00,0x00,0x00},/*"1",1*/
	/* (8 X 16 , 宋体 ) */

	{0x00,0x00,0x08,0x04,0x08,0x04,0x1F,0xFC,0x00,0x04,0x00,0x04,0x00,0x00,0x00,0x00},/*"1",2*/
	/* (8 X 16 , 宋体 ) */

	{0x00,0x02,0x7C,0x7E,0x44,0x02,0x47,0xFC,0x44,0x44,0x7C,0x44,0x00,0x00,0x08,0x80,0x11,0x7F,0xEA,0x42,0x24,0x42,0x2A,0x42,0x31,0x7F,0x00,0x80,0x00,0x80,0x00,0x00},/*"路",3*/
	/* (16 X 16 , 宋体 ) */

	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"	",4*/
	/* (8 X 16 , 宋体 ) */

	{0x00,0x00,0x02,0x02,0x42,0x22,0x22,0x22,0x1A,0x22,0x02,0x22,0x02,0x22,0xFE,0x22,0x02,0x22,0x02,0x22,0x0A,0x22,0x12,0x22,0x63,0xFF,0x00,0x00,0x00,0x00,0x00,0x00},/*"当",5*/
	/* (16 X 16 , 宋体 ) */

	{0x10,0x00,0x10,0x00,0x17,0xFF,0x94,0x90,0x74,0x92,0x14,0x91,0x17,0xFE,0x10,0x00,0x10,0x00,0x13,0xF0,0x30,0x02,0xD0,0x01,0x17,0xFE,0x10,0x00,0x10,0x00,0x00,0x00},/*"前",6*/
	/* (16 X 16 , 宋体 ) */

	{0x00,0x08,0x13,0x0C,0x10,0xE8,0x90,0x08,0x70,0x70,0x17,0x90,0x10,0x10,0x00,0xFF,0x00,0x82,0x00,0x82,0xFF,0x82,0x08,0x82,0x08,0x82,0x08,0xFF,0x08,0x00,0x00,0x00},/*"站",7*/
	/* (16 X 16 , 宋体 ) */

	{0x00,0x01,0x00,0x02,0x03,0xEC,0x02,0x20,0x02,0x20,0x02,0x28,0xFE,0x26,0x12,0x20,0x12,0x28,0x12,0x26,0x12,0x20,0x13,0xE0,0x10,0x08,0x10,0x07,0x00,0x00,0x00,0x00},/*"点",8*/
	/* (16 X 16 , 宋体 ) */

	{0x00,0x00,0x00,0x00,0x00,0x6C,0x00,0x6C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"：",9*/
	/* (16 X 16 , 宋体 ) */

	{0x10,0x01,0x10,0x81,0x11,0x02,0x16,0x02,0x10,0x84,0x10,0x44,0x90,0x28,0x70,0x10,0x10,0x28,0x10,0x44,0x11,0x82,0x14,0x02,0x12,0x01,0x11,0x81,0x10,0x01,0x00,0x00},/*"交",10*/
	/* (16 X 16 , 宋体 ) */

	{0x04,0x01,0x04,0x01,0x04,0x02,0x04,0x04,0x04,0x08,0x04,0x30,0x04,0xC0,0xFF,0x00,0x04,0xC0,0x04,0x30,0x04,0x08,0x04,0x04,0x04,0x02,0x04,0x01,0x04,0x01,0x00,0x00},/*"大",11*/
	/* (16 X 16 , 宋体 ) */

	{0x20,0x04,0x21,0x06,0x21,0x04,0x3F,0xF8,0x21,0x08,0x21,0x08,0x00,0x02,0x7F,0x22,0x49,0x22,0x49,0x22,0x7F,0xFE,0x49,0x22,0x49,0x22,0x7F,0x22,0x00,0x02,0x00,0x00},/*"理",12*/
	/* (16 X 16 , 宋体 ) */

	{0x00,0x04,0x20,0x04,0x20,0x04,0x20,0x04,0x20,0x04,0x20,0x04,0x20,0x04,0x3F,0xFC,0x20,0x04,0x20,0x04,0x20,0x04,0x20,0x04,0x20,0x04,0x20,0x04,0x00,0x04,0x00,0x00},/*"工",13*/
	/* (16 X 16 , 宋体 ) */

	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"	",14*/
	/* (8 X 16 , 宋体 ) */

	{0x08,0x02,0x08,0x44,0x0F,0xA8,0xF8,0x10,0x08,0x68,0x0F,0x84,0x00,0x00,0x02,0x00,0x07,0x7F,0x1A,0x42,0xE2,0x42,0x02,0x42,0x0A,0x42,0x06,0x7F,0x03,0x00,0x00,0x00},/*"始",15*/
	/* (16 X 16 , 宋体 ) */

	{0x00,0x00,0x00,0x04,0x18,0x08,0x68,0x31,0x08,0xC1,0x0B,0x01,0x1D,0x82,0xE9,0x62,0x09,0x14,0x09,0x08,0x09,0x14,0x49,0x22,0x29,0xC2,0x08,0x01,0x00,0x01,0x00,0x00},/*"发",16*/
	/* (16 X 16 , 宋体 ) */

	{0x00,0x08,0x13,0x0C,0x10,0xE8,0x90,0x08,0x70,0x70,0x17,0x90,0x10,0x10,0x00,0xFF,0x00,0x82,0x00,0x82,0xFF,0x82,0x08,0x82,0x08,0x82,0x08,0xFF,0x08,0x00,0x00,0x00},/*"站",17*/
	/* (16 X 16 , 宋体 ) */

	{0x00,0x00,0x00,0x00,0x00,0x6C,0x00,0x6C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"：",18*/
	/* (16 X 16 , 宋体 ) */

	{0x00,0x00,0x00,0x00,0x1F,0xFF,0x10,0x82,0x10,0x82,0x30,0x82,0x50,0x82,0x90,0x82,0x10,0x82,0x10,0x82,0x10,0x82,0x10,0x82,0x1F,0xFF,0x00,0x00,0x00,0x00,0x00,0x00},/*"白",19*/
	/* (16 X 16 , 宋体 ) */

	{0x00,0x04,0x04,0x08,0x04,0x10,0x04,0x60,0x05,0x80,0x06,0x02,0x00,0x01,0xFF,0xFE,0x06,0x00,0x01,0x80,0x02,0x40,0x04,0x20,0x18,0x10,0x00,0x08,0x00,0x08,0x00,0x00},/*"水",20*/
	/* (16 X 16 , 宋体 ) */

	{0x01,0x00,0x06,0x00,0x1F,0xFF,0xE0,0x00,0x00,0xC0,0x20,0x80,0x2E,0xA0,0x2A,0xA2,0xAA,0xA1,0x6A,0xBE,0x2A,0xA0,0x2A,0xA0,0x2E,0xA0,0x20,0x80,0x00,0xC0,0x00,0x00},/*"停",21*/
	/* (16 X 16 , 宋体 ) */

	{0x00,0x10,0x10,0x10,0x11,0x90,0x12,0x90,0x14,0x90,0x18,0x90,0xF0,0x90,0x17,0xFF,0x10,0x90,0x10,0x90,0x10,0x90,0x10,0x90,0x10,0x90,0x10,0x10,0x00,0x10,0x00,0x00},/*"车",22*/
	/* (16 X 16 , 宋体 ) */

	{0x04,0x08,0x04,0x0C,0xFF,0xF8,0x04,0x10,0x04,0x14,0x00,0x08,0x42,0x31,0x47,0xC2,0x4A,0x04,0x52,0x18,0x63,0xE2,0x42,0x01,0x02,0x02,0x03,0xFC,0x00,0x00,0x00,0x00},/*"场",23*/
	/* (16 X 16 , 宋体 ) */

	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"	",24*/
	/* (8 X 16 , 宋体 ) */

	{0x04,0x44,0x0C,0xE6,0x35,0x44,0xC6,0x48,0x0C,0x48,0x04,0x40,0x08,0x80,0x18,0x84,0xE5,0x24,0x22,0x22,0x25,0x12,0x28,0x89,0x30,0x80,0x00,0x40,0x00,0x40,0x00,0x00},/*"终",25*/
	/* (16 X 16 , 宋体 ) */

	{0x00,0x01,0x00,0x02,0x03,0xEC,0x02,0x20,0x02,0x20,0x02,0x28,0xFE,0x26,0x12,0x20,0x12,0x28,0x12,0x26,0x12,0x20,0x13,0xE0,0x10,0x08,0x10,0x07,0x00,0x00,0x00,0x00},/*"点",26*/
	/* (16 X 16 , 宋体 ) */

	{0x00,0x08,0x13,0x0C,0x10,0xE8,0x90,0x08,0x70,0x70,0x17,0x90,0x10,0x10,0x00,0xFF,0x00,0x82,0x00,0x82,0xFF,0x82,0x08,0x82,0x08,0x82,0x08,0xFF,0x08,0x00,0x00,0x00},/*"站",27*/
	/* (16 X 16 , 宋体 ) */

	{0x00,0x00,0x00,0x00,0x00,0x6C,0x00,0x6C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"：",28*/
	/* (16 X 16 , 宋体 ) */

	{0x20,0x20,0x20,0x40,0x20,0x80,0x21,0xFF,0xF6,0x00,0x20,0x08,0x20,0x10,0x20,0x20,0x27,0xFC,0x20,0x82,0xF1,0x02,0x22,0x02,0x24,0x02,0x20,0x02,0x20,0x1E,0x00,0x00},/*"花",29*/
	/* (16 X 16 , 宋体 ) */

	{0x00,0x22,0x00,0x22,0x00,0x24,0x7F,0xA4,0x49,0x28,0x49,0x30,0x49,0x20,0x7F,0xFF,0x49,0x20,0x49,0x30,0x49,0x28,0x7F,0xA4,0x00,0x24,0x00,0x22,0x00,0x22,0x00,0x00},/*"果",30*/
	/* (16 X 16 , 宋体 ) */

	{0x00,0x00,0x00,0x00,0x0F,0xFC,0x00,0x04,0x00,0x04,0x00,0x04,0x00,0x04,0xFF,0xFC,0x00,0x04,0x00,0x04,0x00,0x04,0x00,0x04,0x0F,0xFE,0x00,0x00,0x00,0x00,0x00,0x00},/*"山",31*/
	/* (16 X 16 , 宋体 ) */

	{0x20,0x00,0x27,0xFF,0x24,0x00,0x24,0x10,0x26,0x90,0x25,0x90,0x24,0x90,0xFC,0xFE,0x24,0x90,0x25,0x90,0x26,0x90,0x24,0x12,0x24,0x01,0x27,0xFE,0x20,0x00,0x00,0x00},/*"南",32*/
	/* (16 X 16 , 宋体 ) */

	{0x00,0x00,0x00,0x00,0x3F,0xFE,0x20,0x04,0x20,0x04,0x20,0x04,0x20,0x04,0x20,0x04,0x20,0x04,0x20,0x04,0x20,0x04,0x20,0x04,0x3F,0xFE,0x00,0x00,0x00,0x00,0x00,0x00},/*"口",33*/
		
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	/* (16 X 16 , 宋体 ) */
};


//214路
const u8 hanzi_2[35][32] =
{
	{0x00,0x00,0x0E,0x0C,0x10,0x14,0x10,0x24,0x10,0x44,0x11,0x84,0x0E,0x0C,0x00,0x00},/*"2",0*/
	/* (8 X 16 , 宋体 ) */

	{0x00,0x00,0x08,0x04,0x08,0x04,0x1F,0xFC,0x00,0x04,0x00,0x04,0x00,0x00,0x00,0x00},/*"1",1*/
	/* (8 X 16 , 宋体 ) */

	{0x00,0x00,0x00,0xE0,0x03,0x20,0x04,0x24,0x08,0x24,0x1F,0xFC,0x00,0x24,0x00,0x00},/*"4",2*/
	/* (8 X 16 , 宋体 ) */

	{0x00,0x02,0x7C,0x7E,0x44,0x02,0x47,0xFC,0x44,0x44,0x7C,0x44,0x00,0x00,0x08,0x80,0x11,0x7F,0xEA,0x42,0x24,0x42,0x2A,0x42,0x31,0x7F,0x00,0x80,0x00,0x80,0x00,0x00},/*"路",3*/
	/* (16 X 16 , 宋体 ) */

	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"	",4*/
	/* (8 X 16 , 宋体 ) */

	{0x00,0x00,0x02,0x02,0x42,0x22,0x22,0x22,0x1A,0x22,0x02,0x22,0x02,0x22,0xFE,0x22,0x02,0x22,0x02,0x22,0x0A,0x22,0x12,0x22,0x63,0xFF,0x00,0x00,0x00,0x00,0x00,0x00},/*"当",5*/
	/* (16 X 16 , 宋体 ) */

	{0x10,0x00,0x10,0x00,0x17,0xFF,0x94,0x90,0x74,0x92,0x14,0x91,0x17,0xFE,0x10,0x00,0x10,0x00,0x13,0xF0,0x30,0x02,0xD0,0x01,0x17,0xFE,0x10,0x00,0x10,0x00,0x00,0x00},/*"前",6*/
	/* (16 X 16 , 宋体 ) */

	{0x00,0x08,0x13,0x0C,0x10,0xE8,0x90,0x08,0x70,0x70,0x17,0x90,0x10,0x10,0x00,0xFF,0x00,0x82,0x00,0x82,0xFF,0x82,0x08,0x82,0x08,0x82,0x08,0xFF,0x08,0x00,0x00,0x00},/*"站",7*/
	/* (16 X 16 , 宋体 ) */

	{0x00,0x01,0x00,0x02,0x03,0xEC,0x02,0x20,0x02,0x20,0x02,0x28,0xFE,0x26,0x12,0x20,0x12,0x28,0x12,0x26,0x12,0x20,0x13,0xE0,0x10,0x08,0x10,0x07,0x00,0x00,0x00,0x00},/*"点",8*/
	/* (16 X 16 , 宋体 ) */

	{0x00,0x00,0x00,0x00,0x00,0x6C,0x00,0x6C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"：",9*/
	/* (16 X 16 , 宋体 ) */

	{0x10,0x01,0x10,0x81,0x11,0x02,0x16,0x02,0x10,0x84,0x10,0x44,0x90,0x28,0x70,0x10,0x10,0x28,0x10,0x44,0x11,0x82,0x14,0x02,0x12,0x01,0x11,0x81,0x10,0x01,0x00,0x00},/*"交",10*/
	/* (16 X 16 , 宋体 ) */

	{0x04,0x01,0x04,0x01,0x04,0x02,0x04,0x04,0x04,0x08,0x04,0x30,0x04,0xC0,0xFF,0x00,0x04,0xC0,0x04,0x30,0x04,0x08,0x04,0x04,0x04,0x02,0x04,0x01,0x04,0x01,0x00,0x00},/*"大",11*/
	/* (16 X 16 , 宋体 ) */

	{0x20,0x04,0x21,0x06,0x21,0x04,0x3F,0xF8,0x21,0x08,0x21,0x08,0x00,0x02,0x7F,0x22,0x49,0x22,0x49,0x22,0x7F,0xFE,0x49,0x22,0x49,0x22,0x7F,0x22,0x00,0x02,0x00,0x00},/*"理",12*/
	/* (16 X 16 , 宋体 ) */

	{0x00,0x04,0x20,0x04,0x20,0x04,0x20,0x04,0x20,0x04,0x20,0x04,0x20,0x04,0x3F,0xFC,0x20,0x04,0x20,0x04,0x20,0x04,0x20,0x04,0x20,0x04,0x20,0x04,0x00,0x04,0x00,0x00},/*"工",13*/
	/* (16 X 16 , 宋体 ) */

	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"	",14*/
	/* (8 X 16 , 宋体 ) */

	{0x08,0x02,0x08,0x44,0x0F,0xA8,0xF8,0x10,0x08,0x68,0x0F,0x84,0x00,0x00,0x02,0x00,0x07,0x7F,0x1A,0x42,0xE2,0x42,0x02,0x42,0x0A,0x42,0x06,0x7F,0x03,0x00,0x00,0x00},/*"始",15*/
	/* (16 X 16 , 宋体 ) */

	{0x00,0x00,0x00,0x04,0x18,0x08,0x68,0x31,0x08,0xC1,0x0B,0x01,0x1D,0x82,0xE9,0x62,0x09,0x14,0x09,0x08,0x09,0x14,0x49,0x22,0x29,0xC2,0x08,0x01,0x00,0x01,0x00,0x00},/*"发",16*/
	/* (16 X 16 , 宋体 ) */

	{0x00,0x08,0x13,0x0C,0x10,0xE8,0x90,0x08,0x70,0x70,0x17,0x90,0x10,0x10,0x00,0xFF,0x00,0x82,0x00,0x82,0xFF,0x82,0x08,0x82,0x08,0x82,0x08,0xFF,0x08,0x00,0x00,0x00},/*"站",17*/
	/* (16 X 16 , 宋体 ) */

	{0x00,0x00,0x00,0x00,0x00,0x6C,0x00,0x6C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"：",18*/
	/* (16 X 16 , 宋体 ) */

	{0x08,0x00,0x30,0x00,0x28,0x3F,0x2B,0xAA,0x2A,0xAA,0x2A,0xAA,0xAA,0xAA,0x6A,0xBE,0x2A,0xAA,0x2A,0xAA,0x2A,0xAA,0x2B,0xAA,0x28,0x3F,0x28,0x00,0x30,0x00,0x00,0x00},/*"富",19*/
	/* (16 X 16 , 宋体 ) */

	{0x08,0x60,0x09,0x80,0xFF,0xFF,0x09,0x00,0x7D,0xC1,0x42,0x41,0x5C,0x59,0x42,0x6A,0x7D,0xCA,0x00,0x44,0x7D,0x4C,0x42,0x72,0x5C,0x42,0x42,0x41,0x7D,0x40,0x00,0x00},/*"樱",20*/
	/* (16 X 16 , 宋体 ) */

	{0x00,0x02,0x7C,0x7E,0x44,0x02,0x47,0xFC,0x44,0x44,0x7C,0x44,0x00,0x00,0x08,0x80,0x11,0x7F,0xEA,0x42,0x24,0x42,0x2A,0x42,0x31,0x7F,0x00,0x80,0x00,0x80,0x00,0x00},/*"路",21*/
	/* (16 X 16 , 宋体 ) */

	{0x20,0x00,0x20,0x00,0x27,0xFF,0xA4,0x92,0x64,0x92,0x2C,0x92,0x34,0x92,0x24,0x92,0x24,0x92,0x24,0x92,0x64,0x92,0xA4,0x92,0x27,0xFF,0x20,0x00,0x20,0x00,0x00,0x00},/*"首",22*/
	/* (16 X 16 , 宋体 ) */

	{0x10,0x04,0x11,0x04,0x11,0x08,0x11,0x10,0x11,0x20,0x11,0x40,0x11,0x80,0xFF,0xFF,0x11,0x80,0x11,0x40,0x11,0x20,0x11,0x10,0x11,0x08,0x11,0x04,0x10,0x04,0x00,0x00},/*"末",23*/
	/* (16 X 16 , 宋体 ) */

	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"	",24*/
	/* (8 X 16 , 宋体 ) */

	{0x04,0x44,0x0C,0xE6,0x35,0x44,0xC6,0x48,0x0C,0x48,0x04,0x40,0x08,0x80,0x18,0x84,0xE5,0x24,0x22,0x22,0x25,0x12,0x28,0x89,0x30,0x80,0x00,0x40,0x00,0x40,0x00,0x00},/*"终",25*/
	/* (16 X 16 , 宋体 ) */

	{0x00,0x01,0x00,0x02,0x03,0xEC,0x02,0x20,0x02,0x20,0x02,0x28,0xFE,0x26,0x12,0x20,0x12,0x28,0x12,0x26,0x12,0x20,0x13,0xE0,0x10,0x08,0x10,0x07,0x00,0x00,0x00,0x00},/*"点",26*/
	/* (16 X 16 , 宋体 ) */

	{0x00,0x08,0x13,0x0C,0x10,0xE8,0x90,0x08,0x70,0x70,0x17,0x90,0x10,0x10,0x00,0xFF,0x00,0x82,0x00,0x82,0xFF,0x82,0x08,0x82,0x08,0x82,0x08,0xFF,0x08,0x00,0x00,0x00},/*"站",27*/
	/* (16 X 16 , 宋体 ) */

	{0x00,0x00,0x00,0x00,0x00,0x6C,0x00,0x6C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"：",28*/
	/* (16 X 16 , 宋体 ) */

	{0x08,0x02,0x10,0x52,0x3E,0x52,0x52,0x94,0xD2,0xA4,0x53,0x28,0x57,0x4A,0x5A,0x91,0x52,0x7E,0x52,0x20,0x72,0x50,0x12,0x88,0x1E,0x04,0x00,0x02,0x00,0x02,0x00,0x00},/*"象",29*/
	/* (16 X 16 , 宋体 ) */

	{0x00,0x00,0x00,0x00,0x0F,0xFC,0x00,0x04,0x00,0x04,0x00,0x04,0x00,0x04,0xFF,0xFC,0x00,0x04,0x00,0x04,0x00,0x04,0x00,0x04,0x0F,0xFE,0x00,0x00,0x00,0x00,0x00,0x00},/*"山",30*/
	/* (16 X 16 , 宋体 ) */

	{0x00,0x02,0x7C,0x7E,0x44,0x02,0x47,0xFC,0x44,0x44,0x7C,0x44,0x00,0x00,0x08,0x80,0x11,0x7F,0xEA,0x42,0x24,0x42,0x2A,0x42,0x31,0x7F,0x00,0x80,0x00,0x80,0x00,0x00},/*"路",31*/
	/* (16 X 16 , 宋体 ) */

	{0x00,0x04,0x04,0x06,0x04,0x04,0x04,0x08,0x04,0x08,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFC,0x02,0x02,0x04,0x02,0x08,0x02,0x10,0x02,0x00,0x1E,0x00,0x00},/*"北",32*/
	/* (16 X 16 , 宋体 ) */

	{0x00,0x00,0x00,0x00,0x3F,0xFE,0x20,0x04,0x20,0x04,0x20,0x04,0x20,0x04,0x20,0x04,0x20,0x04,0x20,0x04,0x20,0x04,0x20,0x04,0x3F,0xFE,0x00,0x00,0x00,0x00,0x00,0x00},/*"口",33*/
	/* (16 X 16 , 宋体 ) */
		
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	/* (16 X 16 , 宋体 ) */
};



//251路
const u8 hanzi_3[35][32] =
{	
	{0x00,0x00,0x0E,0x0C,0x10,0x14,0x10,0x24,0x10,0x44,0x11,0x84,0x0E,0x0C,0x00,0x00},/*"2",0*/
	/* (8 X 16 , 宋体 ) */

	{0x00,0x00,0x1F,0x98,0x10,0x84,0x11,0x04,0x11,0x04,0x10,0x88,0x10,0x70,0x00,0x00},/*"5",1*/
	/* (8 X 16 , 宋体 ) */

	{0x00,0x00,0x08,0x04,0x08,0x04,0x1F,0xFC,0x00,0x04,0x00,0x04,0x00,0x00,0x00,0x00},/*"1",2*/
	/* (8 X 16 , 宋体 ) */

	{0x00,0x02,0x7C,0x7E,0x44,0x02,0x47,0xFC,0x44,0x44,0x7C,0x44,0x00,0x00,0x08,0x80,0x11,0x7F,0xEA,0x42,0x24,0x42,0x2A,0x42,0x31,0x7F,0x00,0x80,0x00,0x80,0x00,0x00},/*"路",3*/
	/* (16 X 16 , 宋体 ) */

	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"	",4*/
	/* (8 X 16 , 宋体 ) */

	{0x00,0x00,0x02,0x02,0x42,0x22,0x22,0x22,0x1A,0x22,0x02,0x22,0x02,0x22,0xFE,0x22,0x02,0x22,0x02,0x22,0x0A,0x22,0x12,0x22,0x63,0xFF,0x00,0x00,0x00,0x00,0x00,0x00},/*"当",5*/
	/* (16 X 16 , 宋体 ) */

	{0x10,0x00,0x10,0x00,0x17,0xFF,0x94,0x90,0x74,0x92,0x14,0x91,0x17,0xFE,0x10,0x00,0x10,0x00,0x13,0xF0,0x30,0x02,0xD0,0x01,0x17,0xFE,0x10,0x00,0x10,0x00,0x00,0x00},/*"前",6*/
	/* (16 X 16 , 宋体 ) */

	{0x00,0x08,0x13,0x0C,0x10,0xE8,0x90,0x08,0x70,0x70,0x17,0x90,0x10,0x10,0x00,0xFF,0x00,0x82,0x00,0x82,0xFF,0x82,0x08,0x82,0x08,0x82,0x08,0xFF,0x08,0x00,0x00,0x00},/*"站",7*/
	/* (16 X 16 , 宋体 ) */

	{0x00,0x01,0x00,0x02,0x03,0xEC,0x02,0x20,0x02,0x20,0x02,0x28,0xFE,0x26,0x12,0x20,0x12,0x28,0x12,0x26,0x12,0x20,0x13,0xE0,0x10,0x08,0x10,0x07,0x00,0x00,0x00,0x00},/*"点",8*/
	/* (16 X 16 , 宋体 ) */

	{0x00,0x00,0x00,0x00,0x00,0x6C,0x00,0x6C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"：",9*/
	/* (16 X 16 , 宋体 ) */

	{0x10,0x01,0x10,0x81,0x11,0x02,0x16,0x02,0x10,0x84,0x10,0x44,0x90,0x28,0x70,0x10,0x10,0x28,0x10,0x44,0x11,0x82,0x14,0x02,0x12,0x01,0x11,0x81,0x10,0x01,0x00,0x00},/*"交",10*/
	/* (16 X 16 , 宋体 ) */

	{0x04,0x01,0x04,0x01,0x04,0x02,0x04,0x04,0x04,0x08,0x04,0x30,0x04,0xC0,0xFF,0x00,0x04,0xC0,0x04,0x30,0x04,0x08,0x04,0x04,0x04,0x02,0x04,0x01,0x04,0x01,0x00,0x00},/*"大",11*/
	/* (16 X 16 , 宋体 ) */

	{0x20,0x04,0x21,0x06,0x21,0x04,0x3F,0xF8,0x21,0x08,0x21,0x08,0x00,0x02,0x7F,0x22,0x49,0x22,0x49,0x22,0x7F,0xFE,0x49,0x22,0x49,0x22,0x7F,0x22,0x00,0x02,0x00,0x00},/*"理",12*/
	/* (16 X 16 , 宋体 ) */

	{0x00,0x04,0x20,0x04,0x20,0x04,0x20,0x04,0x20,0x04,0x20,0x04,0x20,0x04,0x3F,0xFC,0x20,0x04,0x20,0x04,0x20,0x04,0x20,0x04,0x20,0x04,0x20,0x04,0x00,0x04,0x00,0x00},/*"工",13*/
	/* (16 X 16 , 宋体 ) */

	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"	",14*/
	/* (8 X 16 , 宋体 ) */

	{0x08,0x02,0x08,0x44,0x0F,0xA8,0xF8,0x10,0x08,0x68,0x0F,0x84,0x00,0x00,0x02,0x00,0x07,0x7F,0x1A,0x42,0xE2,0x42,0x02,0x42,0x0A,0x42,0x06,0x7F,0x03,0x00,0x00,0x00},/*"始",15*/
	/* (16 X 16 , 宋体 ) */

	{0x00,0x00,0x00,0x04,0x18,0x08,0x68,0x31,0x08,0xC1,0x0B,0x01,0x1D,0x82,0xE9,0x62,0x09,0x14,0x09,0x08,0x09,0x14,0x49,0x22,0x29,0xC2,0x08,0x01,0x00,0x01,0x00,0x00},/*"发",16*/
	/* (16 X 16 , 宋体 ) */

	{0x00,0x08,0x13,0x0C,0x10,0xE8,0x90,0x08,0x70,0x70,0x17,0x90,0x10,0x10,0x00,0xFF,0x00,0x82,0x00,0x82,0xFF,0x82,0x08,0x82,0x08,0x82,0x08,0xFF,0x08,0x00,0x00,0x00},/*"站",17*/
	/* (16 X 16 , 宋体 ) */

	{0x00,0x00,0x00,0x00,0x00,0x6C,0x00,0x6C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"：",18*/
	/* (16 X 16 , 宋体 ) */

	{0x00,0x00,0x00,0x00,0x00,0xFF,0xFE,0x92,0x92,0x92,0x92,0x92,0x92,0x92,0x92,0x92,0x92,0x92,0x92,0x92,0x92,0x92,0xFE,0x92,0x00,0xFF,0x00,0x00,0x00,0x00,0x00,0x00},/*"昌",19*/
	/* (16 X 16 , 宋体 ) */

	{0x00,0x04,0x04,0x06,0x04,0x04,0x04,0x08,0x04,0x08,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFC,0x02,0x02,0x04,0x02,0x08,0x02,0x10,0x02,0x00,0x1E,0x00,0x00},/*"北",20*/
	/* (16 X 16 , 宋体 ) */

	{0x01,0x00,0x06,0x00,0x1F,0xFF,0xE0,0x00,0x00,0xC0,0x20,0x80,0x2E,0xA0,0x2A,0xA2,0xAA,0xA1,0x6A,0xBE,0x2A,0xA0,0x2A,0xA0,0x2E,0xA0,0x20,0x80,0x00,0xC0,0x00,0x00},/*"停",21*/
	/* (16 X 16 , 宋体 ) */

	{0x00,0x10,0x10,0x10,0x11,0x90,0x12,0x90,0x14,0x90,0x18,0x90,0xF0,0x90,0x17,0xFF,0x10,0x90,0x10,0x90,0x10,0x90,0x10,0x90,0x10,0x90,0x10,0x10,0x00,0x10,0x00,0x00},/*"车",22*/
	/* (16 X 16 , 宋体 ) */

	{0x04,0x08,0x04,0x0C,0xFF,0xF8,0x04,0x10,0x04,0x14,0x00,0x08,0x42,0x31,0x47,0xC2,0x4A,0x04,0x52,0x18,0x63,0xE2,0x42,0x01,0x02,0x02,0x03,0xFC,0x00,0x00,0x00,0x00},/*"场",23*/
	/* (16 X 16 , 宋体 ) */

	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"	",24*/
	/* (8 X 16 , 宋体 ) */

	{0x04,0x44,0x0C,0xE6,0x35,0x44,0xC6,0x48,0x0C,0x48,0x04,0x40,0x08,0x80,0x18,0x84,0xE5,0x24,0x22,0x22,0x25,0x12,0x28,0x89,0x30,0x80,0x00,0x40,0x00,0x40,0x00,0x00},/*"终",25*/
	/* (16 X 16 , 宋体 ) */

	{0x00,0x01,0x00,0x02,0x03,0xEC,0x02,0x20,0x02,0x20,0x02,0x28,0xFE,0x26,0x12,0x20,0x12,0x28,0x12,0x26,0x12,0x20,0x13,0xE0,0x10,0x08,0x10,0x07,0x00,0x00,0x00,0x00},/*"点",26*/
	/* (16 X 16 , 宋体 ) */

	{0x00,0x08,0x13,0x0C,0x10,0xE8,0x90,0x08,0x70,0x70,0x17,0x90,0x10,0x10,0x00,0xFF,0x00,0x82,0x00,0x82,0xFF,0x82,0x08,0x82,0x08,0x82,0x08,0xFF,0x08,0x00,0x00,0x00},/*"站",27*/
	/* (16 X 16 , 宋体 ) */

	{0x00,0x00,0x00,0x00,0x00,0x6C,0x00,0x6C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"：",28*/
	/* (16 X 16 , 宋体 ) */

	{0x00,0x80,0x01,0x00,0x06,0x00,0x1F,0xFF,0xE0,0x00,0x20,0x00,0x27,0xF0,0x24,0x20,0x24,0x20,0x27,0xF0,0x20,0x02,0x20,0x01,0x3F,0xFE,0x20,0x00,0x20,0x00,0x00,0x00},/*"何",29*/
	/* (16 X 16 , 宋体 ) */

	{0x04,0x08,0x04,0x0C,0x04,0x08,0xFF,0xF0,0x04,0x10,0x04,0x11,0x10,0x02,0x10,0x0C,0x1F,0xF0,0x91,0x00,0x71,0x02,0x11,0x01,0x11,0x02,0x11,0xFC,0x10,0x00,0x00,0x00},/*"坊",30*/
	/* (16 X 16 , 宋体 ) */

	{0x40,0x00,0x40,0x00,0x47,0xFF,0x44,0x12,0x44,0x22,0x7F,0xC2,0x44,0x02,0x44,0x02,0x44,0x02,0x7F,0xC2,0x44,0x22,0x44,0x22,0x47,0xFF,0x40,0x00,0x40,0x00,0x00,0x00},/*"西",31*/
	/* (16 X 16 , 宋体 ) */

	{0x00,0x02,0x7C,0x7E,0x44,0x02,0x47,0xFC,0x44,0x44,0x7C,0x44,0x00,0x00,0x08,0x80,0x11,0x7F,0xEA,0x42,0x24,0x42,0x2A,0x42,0x31,0x7F,0x00,0x80,0x00,0x80,0x00,0x00},/*"路",32*/
	/* (16 X 16 , 宋体 ) */

	{0x40,0x00,0x40,0x00,0x47,0xFF,0x44,0x12,0x44,0x22,0x7F,0xC2,0x44,0x02,0x44,0x02,0x44,0x02,0x7F,0xC2,0x44,0x22,0x44,0x22,0x47,0xFF,0x40,0x00,0x40,0x00,0x00,0x00},/*"西",33*/
	/* (16 X 16 , 宋体 ) */

	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	/* (16 X 16 , 宋体 ) */
};





