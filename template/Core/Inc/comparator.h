/*
 * comparator.h
 *
 *
 */

#ifndef INC_COMPARATOR_H_
#define INC_COMPARATOR_H_

#include "stm32l4xx_hal.h"
#include "stm32l4xx.h"

#include "stm32l476g_discovery.h"

void setSamplingTime(TIM_HandleTypeDef htim4,_Bool fastClockBoolean, double *period);



#endif /* INC_COMPARATOR_H_ */
