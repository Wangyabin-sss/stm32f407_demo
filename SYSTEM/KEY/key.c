#include "key.h"

void key_init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;	
//	EXTI_InitTypeDef EXTI_InitStruct;
//	NVIC_InitTypeDef NVIC_InitStruct;
	//�򿪶˿�A��Ӳ��ʱ�ӣ����ǹ���
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG,ENABLE);
	
	//SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOE,EXTI_PinSource2);
	
	GPIO_InitStruct.GPIO_Pin   = GPIO_Pin_0;	  //0������ ����1
	GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_IN;    //����ģʽ
	//GPIO_InitStruct.GPIO_OType = GPIO_OType_PP; //���������������Ҳ������Ч����Ϊ�ڲ��ṹ�Ѿ��ǹر��ˣ�
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_25MHz; 
	//������ȥ��һ��������̣���Ҫʹ���ڲ���������
	GPIO_InitStruct.GPIO_PuPd  = GPIO_PuPd_NOPULL;//��ʹ������������(��Ϊ�ⲿ�Ѿ�����������)
	GPIO_Init(GPIOA,&GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Pin   = GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4;            //����2������
	GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_IN;          //����ģʽ
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_25MHz;      //25MHz
	//GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;		 //����
	GPIO_InitStruct.GPIO_PuPd  = GPIO_PuPd_NOPULL;		 
	GPIO_Init(GPIOE,&GPIO_InitStruct);
	
	
//	EXTI_InitStruct.EXTI_Line=EXTI_Line2;           
//	EXTI_InitStruct.EXTI_Mode=EXTI_Mode_Interrupt;
//	EXTI_InitStruct.EXTI_Trigger=EXTI_Trigger_Falling;  //����Ϊ�����ش���
//	EXTI_InitStruct.EXTI_LineCmd=ENABLE;
//	EXTI_Init(&EXTI_InitStruct);
//	
//	NVIC_InitStruct.NVIC_IRQChannel=EXTI2_IRQn;
//	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority=2;   //��ռ���ȼ�
//	NVIC_InitStruct.NVIC_IRQChannelSubPriority=3;          //��Ӧ���ȼ�
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


