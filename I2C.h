#ifndef __I2C_H__
#define __I2C_H__
//P2_0接J4的SCL

void I2C_Start();
void I2C_Stop();
void I2C_SendByte(unsigned char Byte);
unsigned I2C_ReceiveByte();
void I2C_SendAck(unsigned char AckBit);
unsigned I2C_ReceiveAck();

#endif 