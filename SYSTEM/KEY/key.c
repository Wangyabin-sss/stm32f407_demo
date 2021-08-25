#include "key.h"

void key_init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;	
//	EXTI_InitTypeDef EXTI_InitStruct;
//	NVIC_InitTypeDef NVIC_InitStruct;
	//打开端口A的硬件时钟，就是供电
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG,ENABLE);
	
	//SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOE,EXTI_PinSource2);
	
	GPIO_InitStruct.GPIO_Pin   = GPIO_Pin_0;	  //0号引脚 按键1
	GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_IN;    //输入模式
	//GPIO_InitStruct.GPIO_OType = GPIO_OType_PP; //推挽输出（配置了也不会生效，因为内部结构已经是关闭了）
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_25MHz; 
	//当你们去做一个矩阵键盘，需要使能内部上拉电阻
	GPIO_InitStruct.GPIO_PuPd  = GPIO_PuPd_NOPULL;//不使能上下拉电阻(因为外部已经有上拉电阻)
	GPIO_Init(GPIOA,&GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Pin   = GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4;            //按键2的引脚
	GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_IN;          //输入模式
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_25MHz;      //25MHz
	//GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;		 //推挽
	GPIO_InitStruct.GPIO_PuPd  = GPIO_PuPd_NOPULL;		 
	GPIO_Init(GPIOE,&GPIO_InitStruct);
	
	
//	EXTI_InitStruct.EXTI_Line=EXTI_Line2;           
//	EXTI_InitStruct.EXTI_Mode=EXTI_Mode_Interrupt;
//	EXTI_InitStruct.EXTI_Trigger=EXTI_Trigger_Falling;  //配置为下升沿触发
//	EXTI_InitStruct.EXTI_LineCmd=ENABLE;
//	EXTI_Init(&EXTI_InitStruct);
//	
//	NVIC_InitStruct.NVIC_IRQChannel=EXTI2_IRQn;
//	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority=2;   //抢占优先级
//	NVIC_InitStruct.NVIC_IRQChannelSubPriority=3;          //响应优先级
//	NVIC_InitStruct.NVIC_IRQChannelCmd=ENABLE;
//	NVIC_Init(&NVIC_InitStruct);
	
}



//void EXTI2_IRQHandler(void)
//{
//	if(EXTI_GetITStatus(EXTI_Line2)==SET)
//	{

//		EXTI_ClearITPendingBit(EXTI_Line2);
//	}
//	
//}


