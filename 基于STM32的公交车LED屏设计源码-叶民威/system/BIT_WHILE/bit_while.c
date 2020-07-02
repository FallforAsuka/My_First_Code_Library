#include "bit_while.h"


//8位的左移
u8 _crol_(u8 data,u8 size)
{
	u8 i;
	for(i=0;i<size;i++)
	{
		if((data&0x80) == 0x00)
		{
			data <<= 1;
			data &= 0xFE;
		}
		else
		{
			data <<= 1;
			data |= 0x01;
		}
	}
	return data;
}


//8位的右移
u8 _cror_(u8 data,u8 size)
{
	u8 i;
	for(i=0;i<size;i++)
	{
		if((data&0x01) == 0x00)
		{
			data >>= 1;
			data &= 0x7F;
		}
		else
		{
			data >>= 1;
			data |= 0x80;
		}
	}
	return data;
}


//16位的左移
u16 _irol_(u16 data,u8 size)
{
	u32 i;
	for(i=0;i<size;i++)
	{
		if((data&0x8000) == 0)
		{
			data <<= 1;
			data &= 0xFFFE;
		}
		else
		{
			data <<= 1;
			data |= 0x0001;
		}
	}
	return data;
}

//16位的右移
u16 _iror_(u16 data,u8 size)
{
	u32 i;
	for(i=0;i<size;i++)
	{
		if((data&0x0001) == 0)
		{
			data >>= 1;
			data &= 0x7FFF;
		}
		else
		{
			data >>= 1;
			data |= 0x8000;
		}
	}
	return data;
}
