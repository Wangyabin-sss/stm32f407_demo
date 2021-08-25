#ifndef _IIC_H
#define _IIC_H

#include "Sys.h"

#define SCL_W		PBout(8)
#define SDA_W		PBout(9)
#define SDA_R		PBin(9)
#define IIC_delay() delay_us(5)

void iic_init(void);
void iic_start(void);
void iic_stop(void);
void iic_send_byte(uint8_t data);
uint8_t iic_recv_byte(void);
uint8_t iic_wait_ack(void);
void iic_ack(uint8_t ack);


#endif
