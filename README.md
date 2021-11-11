## 2021.7.20
### 1.IO初始化后可以写该寄存器进行置1、置0
```c
#define led_write(n) n ? (GPIOF->BSRRL=GPIO_Pin_9 | GPIO_Pin_10):(GPIOF->BSRRH=GPIO_Pin_9 | GPIO_Pin_10)
```
### 2.总线（带上拉电阻）一般输出配置为开漏(不然容易短路)
## 2021.7.21
### 1.RCC更改时钟HSE_VALUE、PLL_M   (system_stm32f4xx.c stm32f4xx.h)
![](.\image\PLL.png)
### 2.位带操作
## 2021.7.22
### 1.中断优先级分组NVIC_PriorityGroup_0~4 
![](.\image\NVIC.png)
当抢占优先级与响应优先级相同时，还有硬件优先级
![](.\image\NVIC1.png)
### 2.如果代码跑飞到(B   .)位置，一般是中断函数问题[仿真看卡在哪],配置完中断，一定要写终端服务函数。
### 3.系统启动文件
![](.\image\startS.png)
### 4.
```c
//系统时钟频率为168MHz 该函数参数为重装载值
//只要进行168000000次计数，就是1秒时间的到达。
SysTick_Config(SystemCoreClock/1000); //中断周期是1ms，就是1秒内触发1000次中断，中断频率为1000Hz

void SysTick_Handler(void)
{
	
}
```
## 2021.7.26
### 1.串口打印速度慢，115200一个字节大约86.6us,一个字节前后有起始和停止位(共10个位)
## 2020.7.31
### 1.mqtt基本流程
![](.\image\mqtt0.png)
## 2021.8.1
### 1.检测由谁导致复位
```c
/**
  * @brief  Checks whether the specified RCC flag is set or not.
  * @param  RCC_FLAG: specifies the flag to check.
  *          This parameter can be one of the following values:
  *            @arg RCC_FLAG_HSIRDY: HSI oscillator clock ready
  *            @arg RCC_FLAG_HSERDY: HSE oscillator clock ready
  *            @arg RCC_FLAG_PLLRDY: main PLL clock ready
  *            @arg RCC_FLAG_PLLI2SRDY: PLLI2S clock ready
  *            @arg RCC_FLAG_PLLSAIRDY: PLLSAI clock ready (only for STM32F42xxx/43xxx/446xx/469xx/479xx devices)
  *            @arg RCC_FLAG_LSERDY: LSE oscillator clock ready
  *            @arg RCC_FLAG_LSIRDY: LSI oscillator clock ready
  *            @arg RCC_FLAG_BORRST: POR/PDR or BOR reset
  *            @arg RCC_FLAG_PINRST: Pin reset
  *            @arg RCC_FLAG_PORRST: POR/PDR reset
  *            @arg RCC_FLAG_SFTRST: Software reset
  *            @arg RCC_FLAG_IWDGRST: Independent Watchdog reset
  *            @arg RCC_FLAG_WWDGRST: Window Watchdog reset
  *            @arg RCC_FLAG_LPWRRST: Low Power reset
  * @retval The new state of RCC_FLAG (SET or RESET).
  */
FlagStatus RCC_GetFlagStatus(uint8_t RCC_FLAG);
RCC_ClearFlag();
```
### 2.RTC时钟 时间保存使用的是BCD码
```c
if(data_ready==1){
	data_ready=0;
	RTC_GetTime(RTC_Format_BCD,&RTC_TimeStructure);
	printf("%02x:%02x:%02x\r\n",RTC_TimeStructure.RTC_Hours,RTC_TimeStructure.RTC_Minutes,RTC_TimeStructure.RTC_Seconds);

	//获取日期
	RTC_GetDate(RTC_Format_BCD,&RTC_DateStructure);
	printf("20%02x/%02x/%02xWeek:%x\r\n",RTC_DateStructure.RTC_Year,RTC_DateStructure.RTC_Month,RTC_DateStructure.RTC_Date,RTC_DateStructure.RTC_WeekDay);
}
```
### 3.字符串常用函数
atoi() strstr() strtok()
## 2021.8.4
### 1.spi时序图
![](.\image\spi.bmp)
## 2021.8.5
### 1.指针快速存储与取值(内部flash操作)
```c
uint32_t flash_write_record(char *pbuf,uint32_t record_count)
{
	uint32_t addr_start=ADDR_FLASH_SECTOR_4+record_count*64;
	uint32_t addr_end  =addr_start+64;

	uint32_t i=0;
	
	while (addr_start < addr_end)
	{
		//每次写入数据是4个字节
		if (FLASH_ProgramWord(addr_start, *(uint32_t *)&pbuf[i]) == FLASH_COMPLETE)
		{
			//地址每次偏移4个字节
			addr_start +=4;
			
			i+=4;
		}

		else
		{ 
			printf("flash write record fail,now goto erase sector!\r\n");
			
			//重新擦除扇区
			flash_erase_record();

			return 1;
		}
	}
	return 0;
}

void flash_read_record(char *pbuf,uint32_t record_count)
{
	uint32_t addr_start=ADDR_FLASH_SECTOR_4+record_count*64;
	uint32_t addr_end  =addr_start+64;

	uint32_t i=0;
	
	while (addr_start < addr_end)
	{
		*(uint32_t *)&pbuf[i] = *(__IO uint32_t*)addr_start;

		addr_start+=4;
		
		i = i + 4;
	}

}

void flash_erase_record(void)
{

	
	/* 如果不擦除，写入会失败，读取的数据都为0 */
	printf("FLASH_EraseSector start\r\n");
	

	if (FLASH_EraseSector(FLASH_Sector_4, VoltageRange_3) != FLASH_COMPLETE)
	{ 
			printf("Erase error\r\n");
			return;
	}

	printf("FLASH_EraseSector ends\r\n");
}
```
## 2021.8.6
### 1.IIC速度
标速：100Khz
快速：400Khz
高速：3Mhz 以上（一般为触摸芯片）

7位地址加1位读写位
## 2021.8.9
### 1.mpu6050(dsp使用延时不能超过250ms)
![](.\image\mpudmp.png)








