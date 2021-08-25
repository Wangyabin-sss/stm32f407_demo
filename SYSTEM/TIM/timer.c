#include "timer.h"

volatile static uint32_t _K1=0,_K2=0,_K3=0,_K4=0;
volatile uint32_t KEY1=0,KEY2=0,KEY3=0,KEY4=0;
volatile uint32_t BEEP=0;

void Tim1_init(uint16_t psc,uint16_t arr)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitstruct;
	TIM_OCInitTypeDef       TIM_OCInitStructure;
//	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1,ENABLE);
	
	TIM_TimeBaseInitstruct.TIM_Period    =  arr;    //重装载值
	TIM_TimeBaseInitstruct.TIM_Prescaler =  psc;   //预分频值
	TIM_TimeBaseInitstruct.TIM_CounterMode= TIM_CounterMode_Up;  //向上计数
	TIM_TimeBaseInitstruct.TIM_ClockDivision=TIM_CKD_DIV1; 
	//TIM_TimeBaseInitstruct.TIM_RepetitionCounter=;
	TIM_TimeBaseInit(TIM1,&TIM_TimeBaseInitstruct);
	
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;    //PWM1的工作模式
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //允许输出脉冲
	TIM_OCInitStructure.TIM_Pulse = 0;                 //比较值0
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //有效状态为高电平

	TIM_OC3Init(TIM1, &TIM_OCInitStructure);
	TIM_OC4Init(TIM1, &TIM_OCInitStructure);
	
	//TIM_ITConfig(TIM1,TIM_IT_Update,ENABLE); //允许定时器3更新中断
	TIM_CtrlPWMOutputs(TIM1,ENABLE);        //高级定时器要打开输出开关
	TIM_Cmd(TIM1,ENABLE); //使能定时器1
	
//	NVIC_InitStructure.NVIC_IRQChannel=TIM1_UP_TIM10_IRQn; 
//	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=2; //抢占优先级2
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority=2;       //响应优先级2
//	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
//	NVIC_Init(&NVIC_InitStructure);
}

void Tim3_init(uint16_t psc,uint16_t arr)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitstruct;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
	
	TIM_TimeBaseInitstruct.TIM_Period    =  arr;    //重装载值  
	TIM_TimeBaseInitstruct.TIM_Prescaler =  psc;   //预分频值 
	TIM_TimeBaseInitstruct.TIM_CounterMode= TIM_CounterMode_Up;  //向上计数
	TIM_TimeBaseInitstruct.TIM_ClockDivision=TIM_CKD_DIV1;   //不起作用，硬件没有分频器
	//TIM_TimeBaseInitstruct.TIM_RepetitionCounter=;
	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseInitstruct);
	
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE); //允许定时器3更新中断
	TIM_Cmd(TIM3,ENABLE);                  //使能定时器3
	
	NVIC_InitStructure.NVIC_IRQChannel=TIM3_IRQn; //定时器3中断
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=8; //抢占优先级8
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=0;       //响应优先级0
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_Init(&NVIC_InitStructure);
}

void Tim13_init(uint16_t psc,uint16_t arr)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitstruct;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM13,ENABLE);
	
	TIM_TimeBaseInitstruct.TIM_Period    =  arr;    //重装载值
	TIM_TimeBaseInitstruct.TIM_Prescaler =  psc;     //预分频值
	TIM_TimeBaseInitstruct.TIM_CounterMode= TIM_CounterMode_Up;  //向上计数
	TIM_TimeBaseInitstruct.TIM_ClockDivision=TIM_CKD_DIV1; 
	//TIM_TimeBaseInitstruct.TIM_RepetitionCounter=;
	TIM_TimeBaseInit(TIM13,&TIM_TimeBaseInitstruct);
	
	TIM_ITConfig(TIM13,TIM_IT_Update,ENABLE); //允许定时器3更新中断
	TIM_Cmd(TIM13,ENABLE); //定时器13
	
	NVIC_InitStructure.NVIC_IRQChannel=TIM8_UP_TIM13_IRQn; //定时器3中断
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=7; //抢占优先级7
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=0;       //响应优先级0
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_Init(&NVIC_InitStructure);
}

void Tim14_init(void)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitstruct;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM14,ENABLE);
	
	TIM_TimeBaseInitstruct.TIM_Period    =  65535;    //重装载值
	TIM_TimeBaseInitstruct.TIM_Prescaler =  83;   //预分频值
	TIM_TimeBaseInitstruct.TIM_CounterMode= TIM_CounterMode_Up;  //向上计数
	TIM_TimeBaseInitstruct.TIM_ClockDivision=TIM_CKD_DIV1; 
	//TIM_TimeBaseInitstruct.TIM_RepetitionCounter=;
	TIM_TimeBaseInit(TIM14,&TIM_TimeBaseInitstruct);
	

	TIM_Cmd(TIM14,DISABLE); //定时器14
}


/*************************************************************************************************************************************/
//void TIM1_UP_TIM10_IRQHandler(void)
//{
//	if(TIM_GetITStatus(TIM1,TIM_IT_Update)==SET) //溢出中断
//	{
//		PFout(9)=!PFout(9);
//		TIM_ClearITPendingBit(TIM1,TIM_IT_Update);  //清除中断标志位
//	}
//}

void TIM3_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM3,TIM_IT_Update)==SET) //溢出中断
	{
		if(PAin(0)==0){
			_K1+=1;
		}else{
			_K1=0;
		}
		if(PEin(2)==0){
			_K2+=1;
		}else{
			_K2=0;
		}
		if(PEin(3)==0){
			_K3+=1;
		}else{
			_K3=0;
		}
		if(PEin(4)==0){
			_K4+=1;
		}else{
			_K4=0;
		}
		if(_K1>55)
		{
			_K1=0;
			KEY1=1;
		}
		if(_K2>55)
		{
			_K2=0;
			KEY2=1;
		}
		if(_K3>55)
		{
			_K3=0;
			KEY3=1;
		}
		if(_K4>55)
		{
			_K4=0;
			KEY4=1;
		}
		TIM_ClearITPendingBit(TIM3,TIM_IT_Update);  //清除中断标志位
	}
}

void TIM8_UP_TIM13_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM13,TIM_IT_Update)==SET) //溢出中断
	{
		if(BEEP!=0){
			PFout(8)^=1;
			BEEP-=1;
		}
		TIM_ClearITPendingBit(TIM13,TIM_IT_Update);  //清除中断标志位
	}
}

void tim14_delay(uint16_t ts)
{
	TIM14->CNT=0x0;
	TIM14->CR1 |=0x1;
	while(TIM14->CNT<ts);
	TIM14->CR1 &=0xFFFE;
}

