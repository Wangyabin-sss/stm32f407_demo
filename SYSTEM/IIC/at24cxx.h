#ifndef _AT24CXX_H
#define _AT24CXX_H

#include "iic.h"

#define AT24C02 0xA0

int32_t at24c02_write(uint8_t addr,uint8_t *buf,uint8_t len);
int32_t at24c02_read(uint8_t addr,uint8_t *buf,uint8_t len);


#endif
