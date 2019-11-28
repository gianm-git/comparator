/*
 * comparator.c
 *
 *
 */
#include "comparator.h"

//the variable period is passed by reference
void setSamplingTime(TIM_HandleTypeDef htim4,_Bool fastClockBoolean, double *period)
{
	if (fastClockBoolean==1)
	  {
		  //sample time for 80MHz=80 000 000
		  //1   sec 	80 000 000
		  //0.1 sec		8 000 000
		  //0.01 sec	800 000
		  //maximum for Prescaler and Period is 65000
		  htim4.Init.Prescaler = 1000;
		  htim4.Init.Period = 800;
		  //reinitialize for 80MHZ clock
		  if (HAL_TIM_Base_Init(&htim4) != HAL_OK)
		  {
		  Error_Handler();
		  }

		  *period=0.01;


	  }
	  else
	  {
		  //sample time for 20MHz
		  htim4.Init.Prescaler = 20000;
		  htim4.Init.Period = 1000;
		  //reinitialize for 80MHZ clock
		  if (HAL_TIM_Base_Init(&htim4) != HAL_OK)
		  {
	      Error_Handler();
		  }

		  *period=0.01;



	  }


}