

#ifndef __RCC_DRIVER_H_
#define __RCC_DRIVER_H_

#include "stm32f4xx.h"

//This returns the APB1 clock value
uint32_t RCC_GetPCLK1Value(void);

//This returns the APB2 clock value
uint32_t RCC_GetPCLK2Value(void);


uint32_t  RCC_GetPLLOutputClock(void);
#endif /* __RCC_DRIVER_H_ */

