/*
测试HPD482S板载按键：按键按下，翻转LED灯的状态
测试单片机型号：STC12C5A60S2   晶振：12.000MHz（可改用11.0592MHz）
作者：知立diy
淘宝店铺：知立diy
淘宝链接：
原创声明：本例程为热敏打印机模块HPD482S配套例程，仅供学习使用，未经作者许可，不得用于其它任何用途；
如需使用，注明出处。HPD482S为本店原创，合作请联系QQ:2421523603
*/
#include "reg51.h"

sbit LED0	=P0^0;//程序运行状态指示灯
sbit LED1	=P0^1;//按键指示灯
sbit KEY	=P0^7;//按键KEY
typedef unsigned char u8;

void Delay10ms()		//@12.000MHz
{
	unsigned char i, j;

	i = 117;
	j = 183;
	do
	{
		while (--j);
	} while (--i);
}

void Delay200ms()
{
	u8 t=20;
	while(t--)Delay10ms();
}

/*按键扫描函数
返回参数：0，没有按下；1，按下按键
*/
u8 KEY_Scan()
{	 
	static u8 upcheck=1;//按键弹起检测
	if(upcheck&&(KEY==1))
	{
		Delay10ms();//去抖动 
		upcheck=0;
		if(KEY==1)return 1;
	}
	else if(KEY==0)upcheck=1;
 	return 0;
}

void main()
{
	LED0=0;
	LED1=0;
	KEY=0;//给定按键IO值

    while(1)
	{
		if(KEY_Scan())
		{
			LED1=!LED1;//翻转LED灯的状态
			KEY=0;//给定按键IO值
		}
		
		LED0=!LED0;
		Delay200ms();
	}
}

