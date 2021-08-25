#include "flash.h"


int flash_write(uint32_t addr,uint32_t *data,uint32_t len)
{
	uint32_t i;
	/* ����FLASH�����棩*/
	FLASH_Unlock();
	
	/* ��������4 */
	if(FLASH_EraseSector(FLASH_Sector_4, VoltageRange_3) != FLASH_COMPLETE)
		return -1;
	for(i=0;i<len;i++){
		/* ������4�׵�ַд��data */
		if(FLASH_ProgramWord(addr,data[i])!= FLASH_COMPLETE)
			return -2;
		addr+=4;
	}
	
	/* ������Ҫ�޸����ݣ����������� */
	FLASH_Lock();
	return 0;
}








