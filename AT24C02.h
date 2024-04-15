#ifndef __AT24C02_H__
#define __AT24C02_H__
//P2_0接J4的SCL
void AT24C02_WriteByte(unsigned char WordAddress,Data);
unsigned char AT24C02_ReadByte(unsigned char WordAddress);


#endif 