#ifndef __bsp_h__
#define __bsp_h__

#include<reg52.h>

sbit DI=P1^0;
sbit CLK=P1^1;
sbit STEP_A=P1^2;		//�������A��//
sbit STEP_B=P1^3;		//�������B��//
sbit STEP_E=P1^4;		//�������������Ч//
sbit STB1=P1^5;			//����ͷ1//
sbit STB2=P1^6;			//����ͷ2//
sbit POWER_OPEN=P1^7;
sbit  LAT  =P3^0;
sbit  NO_PAPER=P3^1;

void port_init(void);

#endif
