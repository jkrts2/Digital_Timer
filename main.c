#include <REGX52.H>
#include "Timer0.h"
#include "Key.h"
#include "Nixie.h"
#include "Delay.h"
#include "AT24C02.h"
//P3_0接J9的C,P0_0接J6的Dp
//P2_0接J4的SCL
//P1_0接JP1的K1

unsigned char KeyNum;
unsigned char Min,Sec,MiniSec;
unsigned char RunFlag;

void main()
{
	Timer0_Init();//计时器初始化
	while(1)
	{
		KeyNum=Key();//通过Key()函数获取按下按键的编号
		if(KeyNum==1)//当按键1按下后，实现秒表的启停
		{
		RunFlag=!RunFlag;
		}
		if(KeyNum==2)//按键2按下后，实现时分秒清零
		{
		Min=0;
		Sec=0;
		MiniSec=0;
		}
		if(KeyNum==3)//按键3按下后，将时分秒数据储存在EEPROM中
		{
		AT24C02_WriteByte(0,Min);
		Delay(5);
		AT24C02_WriteByte(1,Sec);
		Delay(5);
		AT24C02_WriteByte(2,MiniSec);
		Delay(5);
		}
		if(KeyNum==4)//按键4按下后，从EEPROM中读取时分秒
		{
		Min=AT24C02_ReadByte(0);
		Sec=AT24C02_ReadByte(1);
		MiniSec=AT24C02_ReadByte(2);
		}
		Nixie_SetBuf(1,Min/10);//显示分钟的十进制位
			Nixie_SetBuf(2,Min%10);//显示分钟的个进制位
			Nixie_SetBuf(3,11);//显示横杠
			Nixie_SetBuf(4,Sec/10);//显示秒钟的十进制位
			Nixie_SetBuf(5,Sec%10);//显示秒钟的个进制位
			Nixie_SetBuf(6,11);//显示横杠
			Nixie_SetBuf(7,MiniSec/10);//显示十毫秒的十进制位
			Nixie_SetBuf(8,MiniSec%10);//显示十毫秒的个进制位
	}
}

void Sec_Loop(void)//计时器进位实现
{
	if(RunFlag)//通过RunFlag判断是否走时
	{
		MiniSec++;
		if(MiniSec>=100)
		{
			MiniSec=0;
			Sec++;
			if(Sec>=60)
			{
				Sec=0;
				Min++;
				if(Min>=60)
				{
				Min=0;
				}
			}
		}
	}
}

void Timer0_Routine() interrupt 1//定时打断
{
	static unsigned int T0Count1,T0Count2,T0Count3;
	TL0 = 0x18;		//设置定时初始值
	TH0 = 0xFC;		//设置定时初始值
	T0Count1++;
	if(T0Count1>=20)//每隔20ms调用Key_Loop函数检查键盘按下情况
	{
		T0Count1=0;
		Key_Loop();
	}
		T0Count2++;
	if(T0Count2>=2)//每隔2ms调用Nixie_Loop函数实现多位显示
	{
		T0Count2=0;
		Nixie_Loop();
	}
	T0Count3++;
	if(T0Count3>=10)//每隔10ms调用Sec_Loop函数实现计时器计时
	{
	T0Count3=0;
	Sec_Loop();
	}
}

