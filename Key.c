#include <REGX52.H>
#include "Delay.h"
//P1_0接JP1的K1
unsigned char Key_KeyNumber;
/**
* @brief  实现Key_KeyNumber清零，同时在While循环中用Temp储存Key_KeyNumber一次，在下一个while循环Temp重新赋值
  * @param 无
  * @retval Temp返回按下的按键的编号
  */

unsigned char Key()
{
	unsigned char Temp=0;
	Temp=Key_KeyNumber;
	Key_KeyNumber=0;
	return Temp;
}
/**
  * @brief  判断哪个按键按下，并传递出去
  * @param 无
  * @retval KeyNumber按下按键的编号，0-4
  */

unsigned char Key_GetState()
{
	unsigned char KeyNumber=0;
	
	if(P1_0==0){KeyNumber=1;}
	if(P1_1==0){KeyNumber=2;}
	if(P1_2==0){KeyNumber=3;}
	if(P1_3==0){KeyNumber=4;}
	
	return KeyNumber;
}
/**
* @brief  比较上一个状态和下一个状态，判断按键松手
  * @param 无
  * @retval 无
  */

void Key_Loop()
{
	static unsigned char NowState,LastState;
	LastState=NowState;
	NowState=Key_GetState();
	if(LastState==1 && NowState==0)
	{
		Key_KeyNumber=1;
	}
	if(LastState==2 && NowState==0)
	{
		Key_KeyNumber=2;
	}
	if(LastState==3 && NowState==0)
	{
		Key_KeyNumber=3;
	}
	if(LastState==4 && NowState==0)
	{
		Key_KeyNumber=4;
	}

}