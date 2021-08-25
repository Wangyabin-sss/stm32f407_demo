#ifndef _KEY_H_
#define _KEY_H_

#include "Sys.h"

#define KEY_Bit (GPIOA->IDR &0x0001)>>0

void key_init(void);



#endif
