#ifndef _MQTT_H_
#define _MQTT_H_

#include "usart.h"

#define  WIFI_NAME  "16th"
#define  WIFI_PWD   "12345678"


#define  CLIENT_ID  	 "123456|securemode=3,signmethod=hmacsha1|"
#define  USRNAME    	"device1&a13jDJtaInP"
#define  PASSWORD   	"679C19C7EAF084590207DADDB7F39D323D5CBF22"
#define  SEVERADDR  	 "AT+CIPSTART=\"TCP\",\"a13jDJtaInP.iot-as-mqtt.cn-shanghai.aliyuncs.com\",1883\r\n" //服务器地址与端口
#define  SUBTOPIC   	 "/sys/a13jDJtaInP/device1/thing/service/property/set"
#define  PUBLIST    	 "/sys/a13jDJtaInP/device1/thing/event/property/post"
#define  PUBDATA    	 "{\"id\":\"123456\",\"version\": \"1.0\",\"params\": {\"LEDSwitch\": {\"value\":%d,},\"temperature\": {\"value\": %f,},\"Humidity\": {\"value\": %f,}},\"method\": \"thing.event.property.post\"}"
 

//#define  CLIENT_ID  "123456|securemode=3,signmethod=hmacsha1|"
//#define  USRNAME    "device1&a1MtLo2ilYo"
//#define  PASSWORD   "8F3164B717EB86DC4678A370168D11195CEDAF17"
//#define  SEVERADDR  "AT+CIPSTART=\"TCP\",\"A1UGBNNIFGU.IOT-AS-MQTT.CN-SHANGHAI.ALIYUNCS.COM\",1883\r\n" //服务器地址与端口
//#define  SUBTOPIC   "/sys/a1MtLo2ilYo/device1/thing/service/property/set"
//#define  PUBLIST    "/sys/a1MtLo2ilYo/device1/thing/event/property/post"
//#define  PUBDATA    "{\"id\":\"12345\",\"version\": \"1.0\",\"params\": {\"SwitchStatus\": {\"value\":%d,},\"Temperature\": {\"value\": 30,},\"Humidity\": {\"value\": 23,},\"Shadecloth\": {\"value\": 0,}},\"method\": \"thing.event.property.post\"}"
// 

int esp_check(void);
int wifi_check(void);
int mqtt_connect(void);
int mqtt_subtopic(char *sub);
void mqtt_publist(void);
int mqtt_tick(void);
int exit_transport(void);

#endif
