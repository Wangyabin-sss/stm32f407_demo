#include "adc.h"


 /*********************************************************
 * ��������void adc_init(void)
 * ����  ��adc��ʼ��
 * ����  ����
 * ���  ����
 * ����  ����
 * ע��  ��ADC_SoftwareStartConv(ADC1);����ADC,
		   while(ADC_GetFlagStatus(ADC1,ADC_FLAG_EOC)==RESET);
		   ADC_ClearFlag(ADC1,ADC_FLAG_EOC);
		   adc_val = ADC_GetConversionValue(ADC1);��ȡadcֵ
 **********************************************************/
void adc_init(void)
{
	GPIO_InitTypeDef      GPIO_InitStructure;	
	ADC_InitTypeDef       ADC_InitStructure;
	ADC_CommonInitTypeDef ADC_CommonInitStructure;
	
	//�˿�A��Ӳ��ʱ��
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);  
	
	//ADC1��Ӳ��ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1,ENABLE);
	
	//����PA5����ΪAN��ģ���źţ�ģʽ
	GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_5; 	//5������
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AN;//ģ��ģʽ
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_NOPULL;//��ʹ������������
	GPIO_Init(GPIOA,&GPIO_InitStructure);	


	//����ADC1��ز���
	ADC_CommonInitStructure.ADC_Mode = ADC_Mode_Independent;	//����ADC����
	ADC_CommonInitStructure.ADC_Prescaler = ADC_Prescaler_Div2;	//ADC1��Ӳ��ʱ��Ƶ��=84MHz/2=42MHz
	ADC_CommonInitStructure.ADC_DMAAccessMode = ADC_DMAAccessMode_Disabled;//DMA�ر�
	ADC_CommonInitStructure.ADC_TwoSamplingDelay = ADC_TwoSamplingDelay_5Cycles;//5*(1/42MHz)
	ADC_CommonInit(&ADC_CommonInitStructure);	
	
	ADC_InitStructure.ADC_Resolution = ADC_Resolution_12b;		//ת�����Ϊ12λ������
	ADC_InitStructure.ADC_ScanConvMode = DISABLE;				//��ͨ��ɨ��
	ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;			//��������
	ADC_InitStructure.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None;//����Ҫ���崥��ADC����
	//ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_T1_CC1;
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;		//ת���Ľ���Ҷ���洢
	ADC_InitStructure.ADC_NbrOfConversion = 1;					//����ADCҪɨ���ͨ����Ŀ����ǰ��1��
	ADC_Init(ADC1, &ADC_InitStructure);
	
	
	//PA5�������ӵ�ADC1��ͨ��5���Ϊ1���Բ�����Ĳ���ʱ��Ϊ3��ADCʱ�����ڣ�ʱ��Խ��Խ׼ȷ
	ADC_RegularChannelConfig(ADC1, ADC_Channel_5, 1, ADC_SampleTime_3Cycles);
	
	//ʹ��ADC1����
	ADC_Cmd(ADC1, ENABLE);

}




