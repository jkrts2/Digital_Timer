#ifndef __KEY_H__
#define __KEY_H__
//P1_0接JP1的K1
unsigned char Key_GetState();
void Key_Loop();
unsigned char Key();
void Nixie_Scan(unsigned char Location,Number);

#endif 