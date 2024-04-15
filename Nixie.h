#ifndef __NIXIE_H__
#define __NIXIE_H__
//P3_0接J9的C,P0_0接J6的Dp
void Nixie(unsigned char Location,Number);
void Nixie_Loop(void);
unsigned char Nixie_SetBuf(unsigned char Location,Number);


#endif