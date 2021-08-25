#include "Sys.h"


void delay_ms(uint16_t nms)
{
	SysTick->CTRL = 0; 			   //�رն�ʱ��
	SysTick->LOAD = SystemCoreClock/1000-1;  //������װ��ֵ
	SysTick->VAL=0;          //�������ֵ
	SysTick->CTRL = 5; 		 //������ʱ��
	while(nms--)
	{
		while((SysTick->CTRL&0x10000)==0); //���flagλ����������ʱ��λ����
		SysTick->VAL=0;          //�������ֵ
	}
	SysTick->CTRL = 0;
}


void delay_us(uint16_t nus)
{
	SysTick->CTRL = 0; 			
	SysTick->LOAD = SystemCoreClock/1000000*nus-1; //168*nus < 2^24
	SysTick->VAL=0;
	SysTick->CTRL = 5; 		
	while((SysTick->CTRL&0x10000)==0);
	SysTick->CTRL = 0;
}





