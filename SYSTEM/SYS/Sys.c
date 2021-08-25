#include "Sys.h"


void delay_ms(uint16_t nms)
{
	SysTick->CTRL = 0; 			   //关闭定时器
	SysTick->LOAD = SystemCoreClock/1000-1;  //设置重装载值
	SysTick->VAL=0;          //清零计数值
	SysTick->CTRL = 5; 		 //开启定时器
	while(nms--)
	{
		while((SysTick->CTRL&0x10000)==0); //检测flag位，计数到零时该位清零
		SysTick->VAL=0;          //清零计数值
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





