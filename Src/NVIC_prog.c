/**********************************************************************/
/*******************  Author  : Rezk Ahmed     ************************/
/*******************  Date    : 26 Jun 2023    ************************/
/*******************  Layer   : MCAL           ************************/
/*******************  Version : 1.0            ************************/
/**********************************************************************/
#include "std_types.h"
#include "bit_math.h"
#include "error_state.h"


#include "NVIC_int.h"
#include "NVIC_config.h"
#include "NVIC_priv.h"

ES_t NVIC_enuInit(void)
{
	ES_t Local_enuErrorState=ES_NOT_OK;

	SCB_AIRCR = NVIC_NEST_AND_SUB_PER_DISTRIBUTION;
	Local_enuErrorState=ES_OK;

	return Local_enuErrorState;
}

ES_t NVIC_enuEnableIRQ(u8 Copy_u8IRQNum)
{

	ES_t Local_enuErrorState=ES_NOT_OK;

	if(Copy_u8IRQNum <= 31)
	{
		/*Writing 0 has no effect (Faster than set_bit macro)*/
		NVIC_ISER0 = (1 << Copy_u8IRQNum);
		Local_enuErrorState=ES_OK;
	}
	else if(Copy_u8IRQNum <= 59)
	{
		Copy_u8IRQNum -= 32;
		/*Writing 0 has no effect*/
		NVIC_ISER0 = (1 << Copy_u8IRQNum);
		Local_enuErrorState=ES_OK;
	}
	else
	{
		//return error
		Local_enuErrorState=ES_NOT_OK;
	}

	return Local_enuErrorState;
}

ES_t NVIC_enuDisableIRQ(u8 Copy_u8IRQNum)
{
	ES_t Local_enuErrorState=ES_NOT_OK;

	if(Copy_u8IRQNum <= 31)
	{
		/*Writing 0 has no effect (Faster than set_bit macro)*/
		NVIC_ICER0 = (1 << Copy_u8IRQNum);

		Local_enuErrorState=ES_OK;
	}
	else if(Copy_u8IRQNum <= 59)
	{
		Copy_u8IRQNum -= 32;
		/*Writing 0 has no effect*/
		NVIC_ICER1 = (1 << Copy_u8IRQNum);

		Local_enuErrorState=ES_OK;
	}
	else
	{
		//return error
		Local_enuErrorState=ES_NOT_OK;
	}
	return Local_enuErrorState;
}

ES_t NVIC_enuSetIRQPending(u8 Copy_u8IRQNum)
{
	ES_t Local_enuErrorState=ES_NOT_OK;

	if(Copy_u8IRQNum <= 31)
	{
		/*Writing 0 has no effect (Faster than set_bit macro)*/
		NVIC_ISPR0 = (1 << Copy_u8IRQNum);

		Local_enuErrorState=ES_OK;

	}
	else if(Copy_u8IRQNum <= 59)
	{
		Copy_u8IRQNum -= 32;
		/*Writing 0 has no effect*/
		NVIC_ISPR1 = (1 << Copy_u8IRQNum);

		Local_enuErrorState=ES_OK;
	}
	else
	{
		//return error
		Local_enuErrorState=ES_NOT_OK;
	}
	return Local_enuErrorState;
}


ES_t NVIC_enuClearIRQPending(u8 Copy_u8InterruptNum)
{
	ES_t Local_enuErrorState=ES_NOT_OK;

	if(Copy_u8InterruptNum <= 31)
	{
		/*Writing 0 has no effect (Faster than set_bit macro)*/
		NVIC_ICPR0 = (1 << Copy_u8InterruptNum);

		Local_enuErrorState=ES_OK;
	}
	else if(Copy_u8InterruptNum <= 59)
	{
		Copy_u8InterruptNum -= 32;
		/*Writing 0 has no effect*/
		NVIC_ICPR1 = (1 << Copy_u8InterruptNum);
		Local_enuErrorState=ES_OK;
	}
	else
	{
		//return error
		Local_enuErrorState=ES_NOT_OK;
	}
	return Local_enuErrorState;
}

ES_t NVIC_enuGetIRQActiveState(u8 Copy_u8InterruptNum , u8 *Copy_u8ActiveFlagStatus)
{
	ES_t Local_enuErrorState=ES_NOT_OK;

	if(Copy_u8InterruptNum <= 31)
	{
		*Copy_u8ActiveFlagStatus = GET_BIT(NVIC_IABR0,Copy_u8InterruptNum);
		Local_enuErrorState=ES_OK;
	}
	else if(Copy_u8InterruptNum <= 59)
	{
		Copy_u8InterruptNum -= 32;
		*Copy_u8ActiveFlagStatus = GET_BIT(NVIC_IABR1,Copy_u8InterruptNum);
		Local_enuErrorState=ES_OK;
	}
	else
	{
		//return error
		Local_enuErrorState=ES_NOT_OK;
	}
	return Local_enuErrorState;
}

ES_t NVIC_enuSetIntPriority(s8 Copy_s8InterruptNum , u8 Copy_u8GroupPriority , u8 Copy_u8SubPriority )
{

	u8 Local_u8Priority = Copy_u8SubPriority | (Copy_u8GroupPriority <<((NVIC_NEST_AND_SUB_PER_DISTRIBUTION-NVIC_NEST_4_SUB_0)/0x100));

	ES_t Local_enuErrorState=ES_NOT_OK;

	if(Copy_s8InterruptNum < 0)
	{
		/*handelling the internal interrupts*/
		Local_enuErrorState=ES_OK;
	}
	else if(Copy_s8InterruptNum >= 0) //external interrupt
	{
		/*handelling the external interrupts*/
		NVIC_IPR[Copy_s8InterruptNum]= Local_u8Priority << 4 ;
		Local_enuErrorState=ES_OK;
	}
	else
	{
		//return error
		Local_enuErrorState=ES_NOT_OK;
	}

	return Local_enuErrorState;

}

