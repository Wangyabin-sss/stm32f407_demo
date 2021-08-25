#include "Sys.h"
#include "led.h"
#include "key.h"
#include "keyboard.h"
#include "timer.h"
#include "fsmc.h"
#include "usart.h"
#include "hc_sr04.h"
#include "dht11.h"
#include "mqtt.h"
#include "xpt2046.h"
#include "iwdg.h"
#include "rtc.h"
#include "flash.h"
#include "w25qxx.h"
#include "mfrc522.h"
#include "nrf24l01.h"
#include "iic.h"
#include "at24cxx.h"
#include "oled.h"
#include "paj7620u2.h"
#include "mpu6050.h"
#include "inv_mpu.h"
#include "inv_mpu_dmp_motion_driver.h"
#include "dmpKey.h"
#include "dmpmap.h"


int main(void)
{
	uint8_t i=0;
	uint8_t data[5]={0xc3,0x69,0xc0,0x15,0x7f};
	uint8_t user[32]={0};
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
	led_init();
	usart1_init(115200);
	usart2_init(9600);
	usart3_init(115200);
	Tim3_init(839,199);      //ÓÃÓÚ°´¼ü
//	Tim13_init(8399,2999);   //200ms beep
//	dht11_init();
	key_board_init();
//	rtc_init();
	spi1_init();
	iic_init();
//	Soft_Spi_Init();
//	MFRC522_Initializtion();
//	MPU_Init();
//	while(mpu_dmp_init());
//	printf("exit_transport=%d\n",exit_transport());
//	printf("esp_check=%d\n",esp_check());
//	printf("wifi_check=%d\n",wifi_check());
//	printf("mqtt_connect=%d\n",mqtt_connect());
//	mqtt_publist();
//	paj7620u2_init();
//	NRF24L01_GPIO_Init();
//	printf("%d\n",NRF24L01_Check());
//	delay_ms(50);
//	NRF24L01_TX_Mode();
//	
//	TFTLCD_Init();
	
	
	at24c02_write(42,data,5);
	delay_ms(5);
	
	at24c02_read(42,user,5);
//	
	for(int i=0;i<5;i++)
		printf("%x ",user[i]);
		
	while(1)
	{
//		printf("tick=%d\n",mqtt_tick());
//		delay_ms(50000);
//		if(RX1_data.b==usartdown)
//		{
//			RX1_data.b=haveread;
//			printf("u1:=%s\n",RX1_data.data);
//			usart2_send_str((char *)RX1_data.data);
//			usart2_send_str("\r\n");
//		}
//		if(RX2_data.b==usartdown)
//		{
//			RX2_data.b=haveread;
//			printf("%s\n",RX2_data.data);
//		}
		
		
		
	}
}






