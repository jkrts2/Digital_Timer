#include <REGX52.H>
#include "Delay.h"
//P3_0接J9的C,P0_0接J6的Dp
unsigned char Nixie_Buf[9]={0,10,10,10,10,10,10,10,10};
/**
  * @brief  将外界传进来的数据填入Nixie_Buf数组
* @param 	Location数字要显示的位置1-8，Number要显示的数字0-9或不显示或横杠
  * @retval 无
  */
void Nixie_SetBuf(unsigned char Location,Number)
{
	Nixie_Buf[Location]=Number;
}
/**
  * @brief  实现单个数字的位选和段选
  * @param 	Location单个数字要显示的位置1-8，Number对应数组NixieTable中要显示的数字0-9或不显示或横杠的段码
  * @retval 无
  */

unsigned char NixieTable[] = {0xfc,0x60,0xda,0xf2,0x66,0xb6,0xbe,0xe0,0xfe,0xf6,0x00,0x02};
//数码管段选表									0		1		 2	  3	   4		5		 6		7		 8		9	 不显示 横杠
void Nixie_Scan(unsigned char Location,Number)
{
	P0=0x00;//每一次显示前要清零
	switch(Location)//位选
	{
		case 1:P3_0=0;P3_1=0;P3_2=0;break;
		case 2:P3_0=0;P3_1=0;P3_2=1;break;
		case 3:P3_0=0;P3_1=1;P3_2=0;break;
		case 4:P3_0=0;P3_1=1;P3_2=1;break;
		case 5:P3_0=1;P3_1=0;P3_2=0;break;
		case 6:P3_0=1;P3_1=0;P3_2=1;break;
		case 7:P3_0=1;P3_1=1;P3_2=0;break;
		case 8:P3_0=1;P3_1=1;P3_2=1;break;
	}
	P0=NixieTable[Number];//段选
}
/**
  * @brief  用i循环，从数组Nixie_Buf的第一位开始，实现多个数字的显示
  * @param 无
  * @retval 无
  */

void Nixie_Loop(void)
{
	static unsigned char i=1;
	Nixie_Scan(i,Nixie_Buf[i]);
	i++;
	if(i>8){i=1;}
}	