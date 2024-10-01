/****************************************************/
/*  Author  : Rezk Ahmed                            */
/*  Date    : 18 July 2023                          */
/*  Version : V01                                   */
/****************************************************/


#ifndef STK_INT_H_
#define STK_INT_H_

ES_t STK_enuInit(void);

ES_t STK_enuDelay(u32 Copy_u32Ticks);

ES_t STK_enuSetSingleInterval(u32 Copy_u32Ticks , void(*Copy_pfNotifcationFunc)(void) );
ES_t STK_enuSetPeriodicInterval(u32 Copy_u32Ticks , void(*Copy_pfNotifcationFunc)(void) );

ES_t STK_enuStopTimer(void);

ES_t STK_enuGetTotalTicks(u32 *Copy_pu32TickCount);
ES_t STK_enuGetRemainingTicks(u32 *Copy_pu32TickCount);

#endif
