#ifndef _TIMER_H_
#define _TIMER_H_

#include "Sys.h"

extern volatile uint32_t KEY1,KEY2,KEY3,KEY4;
extern volatile uint32_t BEEP;

/****************Ԥ��Ƶֵ   ��װ��ֵ*****************/
void Tim1_init(uint16_t psc,uint16_t arr); //�ж�ʱ��x(us)=[(psc+1)*(arr+1)]/168
void Tim3_init(uint16_t psc,uint16_t arr); //�ж�ʱ��x(us)=[(psc+1)*(arr+1)]/84
void Tim13_init(uint16_t psc,uint16_t arr);//��������ÿ [(psc+1)/84] us��һ
void Tim14_init(void);
void tim14_delay(uint16_t ts);

#endif
