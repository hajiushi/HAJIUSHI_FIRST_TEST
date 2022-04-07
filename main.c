/*
����HPD482S���ذ������������£���תLED�Ƶ�״̬
���Ե�Ƭ���ͺţ�STC12C5A60S2   ����12.000MHz���ɸ���11.0592MHz��
���ߣ�֪��diy
�Ա����̣�֪��diy
�Ա����ӣ�
ԭ��������������Ϊ������ӡ��ģ��HPD482S�������̣�����ѧϰʹ�ã�δ��������ɣ��������������κ���;��
����ʹ�ã�ע��������HPD482SΪ����ԭ������������ϵQQ:2421523603
*/
#include "reg51.h"

sbit LED0	=P0^0;//��������״ָ̬ʾ��
sbit LED1	=P0^1;//����ָʾ��
sbit KEY	=P0^7;//����KEY
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

/*����ɨ�躯��
���ز�����0��û�а��£�1�����°���
*/
u8 KEY_Scan()
{	 
	static u8 upcheck=1;//����������
	if(upcheck&&(KEY==1))
	{
		Delay10ms();//ȥ���� 
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
	KEY=0;//��������IOֵ

    while(1)
	{
		if(KEY_Scan())
		{
			LED1=!LED1;//��תLED�Ƶ�״̬
			KEY=0;//��������IOֵ
		}
		
		LED0=!LED0;
		Delay200ms();
	}
}

