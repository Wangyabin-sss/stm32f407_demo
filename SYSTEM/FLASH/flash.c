#include "flash.h"


int flash_write(uint32_t addr,uint32_t *data,uint32_t len)
{
	uint32_t i;
	/* 解锁FLASH（闪存）*/
	FLASH_Unlock();
	
	/* 擦除扇区4 */
	if(FLASH_EraseSector(FLASH_Sector_4, VoltageRange_3) != FLASH_COMPLETE)
		return -1;
	for(i=0;i<len;i++){
		/* 向扇区4首地址写入data */
		if(FLASH_ProgramWord(addr,data[i])!= FLASH_COMPLETE)
			return -2;
		addr+=4;
	}
	
	/* 不再需要修改数据，则锁定闪存 */
	FLASH_Lock();
	return 0;
}








