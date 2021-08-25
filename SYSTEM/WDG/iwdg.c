#include "iwdg.h"

 /*********************************************************
 * 函数名：void iwdg_init(uint16_t num)
 * 描述  ：独立看门狗使能
 * 输入  ：计数器重载值
 * 输出  ：无
 * 返回  ：无
 * 注意  ：在计数完之前调用IWDG_ReloadCounter();喂狗
 **********************************************************/
void iwdg_init(uint16_t num)
{
	//解除独立看门狗寄存器的写保护
	IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable);
	
	//设置分频值256，独立看门狗的硬件定时器时钟频率=32KHz/256=125Hz  
	IWDG_SetPrescaler(IWDG_Prescaler_256);
	
	//设置计数值就是它的超时时间=1秒
	IWDG_SetReload(num);

	//刷新独立看门狗的计数值
	IWDG_ReloadCounter();
	
	//使能独立看门狗工作
	IWDG_Enable();
}

 /*********************************************************
 * 函数名：void wwdg_init(void)
 * 描述  ：窗口看门狗使能
 * 输入  ：无
 * 输出  ：无
 * 返回  ：无
 * 注意  ：在计数完之前调用WWDG_SetCounter(127);喂狗
 **********************************************************/
void wwdg_init(void)
{
	NVIC_InitTypeDef NVIC_InitStructure;
	//使能窗口看门狗的硬件时钟
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_WWDG, ENABLE);
	
	//分频值的配置，窗口看门狗的计数器时钟=(42MHz/4096)/8≈1281Hz
	WWDG_SetPrescaler(WWDG_Prescaler_8);
	
	//窗口值
	WWDG_SetWindowValue(80);  //窗口值为0x40~80
	
	//配置计数值，然后使能窗口看门狗工作
	WWDG_Enable(127);
	
	NVIC_InitStructure.NVIC_IRQChannel = WWDG_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
	
	//清空提前唤醒中断标志位
	WWDG_ClearFlag();
	
	WWDG_EnableIT();
}

//若要在复位前要保存某些数据可以使能中断
void WWDG_IRQHandler(void) //减到0x3F产生中断
{
	if(WWDG_GetFlagStatus()==SET)
	{
		WWDG_SetCounter(127);
		WWDG_ClearFlag();
	}
}





