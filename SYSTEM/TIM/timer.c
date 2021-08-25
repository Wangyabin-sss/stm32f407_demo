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
	
	TIM_TimeBaseInitstruct.TIM_Period    =  arr;    //��װ��ֵ
	TIM_TimeBaseInitstruct.TIM_Prescaler =  psc;   //Ԥ��Ƶֵ
	TIM_TimeBaseInitstruct.TIM_CounterMode= TIM_CounterMode_Up;  //���ϼ���
	TIM_TimeBaseInitstruct.TIM_ClockDivision=TIM_CKD_DIV1; 
	//TIM_TimeBaseInitstruct.TIM_RepetitionCounter=;
	TIM_TimeBaseInit(TIM1,&TIM_TimeBaseInitstruct);
	
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;    //PWM1�Ĺ���ģʽ
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //�����������
	TIM_OCInitStructure.TIM_Pulse = 0;                 //�Ƚ�ֵ0
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //��Ч״̬Ϊ�ߵ�ƽ

	TIM_OC3Init(TIM1, &TIM_OCInitStructure);
	TIM_OC4Init(TIM1, &TIM_OCInitStructure);
	
	//TIM_ITConfig(TIM1,TIM_IT_Update,ENABLE); //����ʱ��3�����ж�
	TIM_CtrlPWMOutputs(TIM1,ENABLE);        //�߼���ʱ��Ҫ���������
	TIM_Cmd(TIM1,ENABLE); //ʹ�ܶ�ʱ��1
	
//	NVIC_InitStructure.NVIC_IRQChannel=TIM1_UP_TIM10_IRQn; 
//	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=2; //��ռ���ȼ�2
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority=2;       //��Ӧ���ȼ�2
//	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
//	NVIC_Init(&NVIC_InitStructure);
}

void Tim3_init(uint16_t psc,uint16_t arr)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitstruct;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
	
	TIM_TimeBaseInitstruct.TIM_Period    =  arr;    //��װ��ֵ  
	TIM_TimeBaseInitstruct.TIM_Prescaler =  psc;   //Ԥ��Ƶֵ 
	TIM_TimeBaseInitstruct.TIM_CounterMode= TIM_CounterMode_Up;  //���ϼ���
	TIM_TimeBaseInitstruct.TIM_ClockDivision=TIM_CKD_DIV1;   //�������ã�Ӳ��û�з�Ƶ��
	//TIM_TimeBaseInitstruct.TIM_RepetitionCounter=;
	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseInitstruct);
	
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE); //����ʱ��3�����ж�
	TIM_Cmd(TIM3,ENABLE);                  //ʹ�ܶ�ʱ��3
	
	NVIC_InitStructure.NVIC_IRQChannel=TIM3_IRQn; //��ʱ��3�ж�
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=8; //��ռ���ȼ�8
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=0;       //��Ӧ���ȼ�0
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_Init(&NVIC_InitStructure);
}

void Tim13_init(uint16_t psc,uint16_t arr)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitstruct;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM13,ENABLE);
	
	TIM_TimeBaseInitstruct.TIM_Period    =  arr;    //��װ��ֵ
	TIM_TimeBaseInitstruct.TIM_Prescaler =  psc;     //Ԥ��Ƶֵ
	TIM_TimeBaseInitstruct.TIM_CounterMode= TIM_CounterMode_Up;  //���ϼ���
	TIM_TimeBaseInitstruct.TIM_ClockDivision=TIM_CKD_DIV1; 
	//TIM_TimeBaseInitstruct.TIM_RepetitionCounter=;
	TIM_TimeBaseInit(TIM13,&TIM_TimeBaseInitstruct);
	
	TIM_ITConfig(TIM13,TIM_IT_Update,ENABLE); //����ʱ��3�����ж�
	TIM_Cmd(TIM13,ENABLE); //��ʱ��13
	
	NVIC_InitStructure.NVIC_IRQChannel=TIM8_UP_TIM13_IRQn; //��ʱ��3�ж�
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=7; //��ռ���ȼ�7
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=0;       //��Ӧ���ȼ�0
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_Init(&NVIC_InitStructure);
}

void Tim14_init(void)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitstruct;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM14,ENABLE);
	
	TIM_TimeBaseInitstruct.TIM_Period    =  65535;    //��װ��ֵ
	TIM_TimeBaseInitstruct.TIM_Prescaler =  83;   //Ԥ��Ƶֵ
	TIM_TimeBaseInitstruct.TIM_CounterMode= TIM_CounterMode_Up;  //���ϼ���
	TIM_TimeBaseInitstruct.TIM_ClockDivision=TIM_CKD_DIV1; 
	//TIM_TimeBaseInitstruct.TIM_RepetitionCounter=;
	TIM_TimeBaseInit(TIM14,&TIM_TimeBaseInitstruct);
	

	TIM_Cmd(TIM14,DISABLE); //��ʱ��14
}


/*************************************************************************************************************************************/
//void TIM1_UP_TIM10_IRQHandler(void)
//{
//	if(TIM_GetITStatus(TIM1,TIM_IT_Update)==SET) //����ж�
//	{
//		PFout(9)=!PFout(9);
//		TIM_ClearITPendingBit(TIM1,TIM_IT_Update);  //����жϱ�־λ
//	}
//}

void TIM3_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM3,TIM_IT_Update)==SET) //����ж�
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
		TIM_ClearITPendingBit(TIM3,TIM_IT_Update);  //����жϱ�־λ
	}
}

void TIM8_UP_TIM13_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM13,TIM_IT_Update)==SET) //����ж�
	{
		if(BEEP!=0){
			PFout(8)^=1;
			BEEP-=1;
		}
		TIM_ClearITPendingBit(TIM13,TIM_IT_Update);  //����жϱ�־λ
	}
}

void tim14_delay(uint16_t ts)
{
	TIM14->CNT=0x0;
	TIM14->CR1 |=0x1;
	while(TIM14->CNT<ts);
	TIM14->CR1 &=0xFFFE;
}

