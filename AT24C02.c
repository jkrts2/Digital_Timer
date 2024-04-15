#include <REGX52.H>
#include "I2C.h"
//P2_0接J4的SCL

#define AT24302_ADDRESS			0xa0
/**
  * @brief  AT2402写入一个字节
  * @param WordAddress 要写入的字节的地址
	* @param Data 要写入的数据
  * @retval 无
  */

void AT24C02_WriteByte(unsigned char WordAddress,Data)
{
	I2C_Start();
	I2C_SendByte(AT24302_ADDRESS);
	I2C_ReceiveAck();
	I2C_SendByte(WordAddress);
	I2C_ReceiveAck();
	I2C_SendByte(Data);
	I2C_ReceiveAck();
	I2C_Stop();

}
/**
  * @brief  AT2402读取一个字节
  * @param WordAddress 要写入的字节的地址
  * @retval Data要读出的数据
  */

unsigned char AT24C02_ReadByte(unsigned char WordAddress)
{
	unsigned char Data;
	I2C_Start();
	I2C_SendByte(AT24302_ADDRESS);
	I2C_ReceiveAck();
	I2C_SendByte(WordAddress);
	I2C_ReceiveAck();
	I2C_Start();
	I2C_SendByte(AT24302_ADDRESS|0x01);
	I2C_ReceiveAck();
	Data=I2C_ReceiveByte();
	I2C_SendAck(1);
	I2C_Stop();

	return Data;
}