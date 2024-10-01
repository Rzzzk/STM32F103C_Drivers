/****************************************************/
/*  Author  : Rezk Ahmed                            */
/*  Date    : 18 July 2023                          */
/*  Version : V01                                   */
/****************************************************/

#include "std_types.h"
#include "bit_math.h"
#include "error_state.h"

#include <STK_int.h>
#include <STK_priv.h>


#include "STK_config.h"


void (*STK_pfIntervalSingleCallBack)(void)   = NULL;
void (*STK_pfIntervalPeriodicCallBack)(void) = NULL;

u8 STK_u8IntervalFlag;

ES_t STK_enuInit(void)
{

	ES_t Local_enuErrorState=ES_NOT_OK;

	/* Select Clock Source  */
#if STK_CLOCK_SOURCE  ==  AHB_CLOCK_DEV_BY_8
	CLR_BIT(STK->CTRL , STK_CTRL_CLKSOURCE); /* Select AHB/8 */
	Local_enuErrorState=ES_OK;
#elif STK_CLOCK_SOURCE  ==  AHB_CLOCK
	SET_BIT(STK->CTRL , STK_CTRL_CLKSOURCE);	/* Select AHB */
	Local_enuErrorState=ES_OK;
#else
#error " Wroge SysTick clock source ! "
#endif	

	return Local_enuErrorState;
}



ES_t STK_enuDelay(u32 Copy_u32Ticks)
{
	ES_t Local_enuErrorState=ES_NOT_OK;

	STK->LOAD = Copy_u32Ticks;                                  /*Set load register by the tick passed*/
	SET_BIT(STK->CTRL , STK_CTRL_ENABLE);                       /*Enable Systick start the timer*/
	while(GET_BIT(STK->CTRL , STK_CTRL_COUNTFLAG) == 0);        /*wait on flag*/
	STK->LOAD = 0;                                              /*Clear the load register*/
	CLR_BIT(STK->CTRL , STK_CTRL_ENABLE);                       /*Stop the timer*/

	Local_enuErrorState=ES_OK;

	return Local_enuErrorState;
}

ES_t STK_enuSetSingleInterval(u32 Copy_u32Ticks , void(*Copy_pfNotifcationFunc)(void) )
{
	ES_t Local_enuErrorState=ES_NOT_OK;

	STK->VAL = 0;                                               /*Clear the counter*/
	STK->LOAD = Copy_u32Ticks;									/*Set load register by the tick passed*/
	STK_pfIntervalSingleCallBack = Copy_pfNotifcationFunc;		/*Set the global pointer to function*/
	STK_u8IntervalFlag = SINGLE_INTERVAL;						/*Set the global flag with single interval flag*/
	SET_BIT(STK->CTRL , STK_CTRL_TICKINT);						/*Enable interrupt*/
	SET_BIT(STK->CTRL , STK_CTRL_ENABLE);						/* Enable Systick start the timer*/

	Local_enuErrorState=ES_OK;

	return Local_enuErrorState;
}

ES_t STK_enuSetPeriodicInterval(u32 Copy_u32Ticks , void(*Copy_pfNotifcationFunc)(void) )
{
	ES_t Local_enuErrorState=ES_NOT_OK;

	STK->VAL = 0;                                                     /*Clear the counter*/
	STK->LOAD = Copy_u32Ticks;                                        /*Set load register by the tick passed*/
	STK_pfIntervalPeriodicCallBack = Copy_pfNotifcationFunc;		  /*Set the global pointer to function*/
	STK_u8IntervalFlag = PERIODIC_INTERVAL;							  /*Set the global flag with periodic interval flag*/
	SET_BIT(STK->CTRL , STK_CTRL_TICKINT);                            /*Enable interrupt*/
	SET_BIT(STK->CTRL , STK_CTRL_ENABLE);                             /*Enable Systick start the timer*/

	Local_enuErrorState=ES_OK;

	return Local_enuErrorState;

}

ES_t MSTK_voidStopTimer(void)
{
	ES_t Local_enuErrorState=ES_NOT_OK;

	CLR_BIT(STK->CTRL , STK_CTRL_TICKINT);     /*Disable interrupt*/
	STK->VAL = 0;                              /*Clear the counter*/
	STK->LOAD = 0;                             /*Clear the load register*/
	CLR_BIT(STK->CTRL , STK_CTRL_ENABLE);      /*Stop the timer*/

	Local_enuErrorState=ES_OK;

	return Local_enuErrorState;
}

ES_t STK_enuGetTotalTicks(u32 *Copy_pu32TickCount)
{
	ES_t Local_enuErrorState=ES_NOT_OK;

	*Copy_pu32TickCount = STK->LOAD;

	Local_enuErrorState=ES_OK;

	return Local_enuErrorState;
}

ES_t STK_enuGetRemainingTicks(u32 *Copy_pu32TickCount)
{
	ES_t Local_enuErrorState=ES_NOT_OK;

	*Copy_pu32TickCount = (STK->LOAD - STK->VAL);

	Local_enuErrorState=ES_OK;

	return Local_enuErrorState;
}

void SysTick_Handler(void)
{
	if (STK_u8IntervalFlag == SINGLE_INTERVAL)
	{	
		CLR_BIT(STK->CTRL , STK_CTRL_TICKINT);/*Disable interrupt*/
		STK->LOAD = 0;/*Clear the load register*/
		CLR_BIT(STK->CTRL , STK_CTRL_ENABLE);/*Stop the timer*/
		/*call callback function*/
		if(STK_pfIntervalSingleCallBack != NULL)
		{
			STK_pfIntervalSingleCallBack();
		}
	}
	else if (STK_u8IntervalFlag == PERIODIC_INTERVAL)
	{
		if( STK_pfIntervalPeriodicCallBack != NULL)
		{
			STK_pfIntervalPeriodicCallBack();
		}
	}
}


