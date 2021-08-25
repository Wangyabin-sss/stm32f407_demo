#include "iwdg.h"

 /*********************************************************
 * ��������void iwdg_init(uint16_t num)
 * ����  ���������Ź�ʹ��
 * ����  ������������ֵ
 * ���  ����
 * ����  ����
 * ע��  ���ڼ�����֮ǰ����IWDG_ReloadCounter();ι��
 **********************************************************/
void iwdg_init(uint16_t num)
{
	//����������Ź��Ĵ�����д����
	IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable);
	
	//���÷�Ƶֵ256���������Ź���Ӳ����ʱ��ʱ��Ƶ��=32KHz/256=125Hz  
	IWDG_SetPrescaler(IWDG_Prescaler_256);
	
	//���ü���ֵ�������ĳ�ʱʱ��=1��
	IWDG_SetReload(num);

	//ˢ�¶������Ź��ļ���ֵ
	IWDG_ReloadCounter();
	
	//ʹ�ܶ������Ź�����
	IWDG_Enable();
}

 /*********************************************************
 * ��������void wwdg_init(void)
 * ����  �����ڿ��Ź�ʹ��
 * ����  ����
 * ���  ����
 * ����  ����
 * ע��  ���ڼ�����֮ǰ����WWDG_SetCounter(127);ι��
 **********************************************************/
void wwdg_init(void)
{
	NVIC_InitTypeDef NVIC_InitStructure;
	//ʹ�ܴ��ڿ��Ź���Ӳ��ʱ��
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_WWDG, ENABLE);
	
	//��Ƶֵ�����ã����ڿ��Ź��ļ�����ʱ��=(42MHz/4096)/8��1281Hz
	WWDG_SetPrescaler(WWDG_Prescaler_8);
	
	//����ֵ
	WWDG_SetWindowValue(80);  //����ֵΪ0x40~80
	
	//���ü���ֵ��Ȼ��ʹ�ܴ��ڿ��Ź�����
	WWDG_Enable(127);
	
	NVIC_InitStructure.NVIC_IRQChannel = WWDG_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
	
	//�����ǰ�����жϱ�־λ
	WWDG_ClearFlag();
	
	WWDG_EnableIT();
}

//��Ҫ�ڸ�λǰҪ����ĳЩ���ݿ���ʹ���ж�
void WWDG_IRQHandler(void) //����0x3F�����ж�
{
	if(WWDG_GetFlagStatus()==SET)
	{
		WWDG_SetCounter(127);
		WWDG_ClearFlag();
	}
}





