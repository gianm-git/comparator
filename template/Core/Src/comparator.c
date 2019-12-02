/*
 * comparator.c
 *
 *
 */
#include "comparator.h"

//the variable period is passed by reference
void setSamplingTime(TIM_HandleTypeDef htim4,_Bool fastClockBoolean, double *period)
{
	long double clock;
	long double timer_multiplied;
	if (fastClockBoolean==1)
	  {
		  clock=80000000;
		  //sample time for 80MHz=80 000 000
		  //1   sec 	80 000 000
		  //0.1 sec		 8 000 000
		  //0.01 sec	   800 000
		  //maximum for Prescaler and Period is 65000
		  htim4.Init.Prescaler = 1000;
		  htim4.Init.Period = 8000;
		  //reinitialize for 80MHZ clock
		  if (HAL_TIM_Base_Init(&htim4) != HAL_OK)
		  {
		  Error_Handler();
		  }

		  timer_multiplied=(htim4.Init.Prescaler)*(htim4.Init.Period);
		  *period=timer_multiplied/clock;

		  //*period=0.1;


	  }
	  else
	  {
		  //sample time for 20MHz = 20 000 000
		  //	  1 sec		20 000 000
		  //	0.1 sec		 2 000 000
		  //   0.01 sec	   	   200 000

		  htim4.Init.Prescaler = 2000;
		  htim4.Init.Period = 1000;
		  //reinitialize for 80MHZ clock
		  if (HAL_TIM_Base_Init(&htim4) != HAL_OK)
		  {
	      Error_Handler();
		  }

		  timer_multiplied=(htim4.Init.Prescaler)*(htim4.Init.Period);
		  *period=timer_multiplied/clock;

		  //*period=0.1;



	  }


}
