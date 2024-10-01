/**********************************************************************/
/*******************  Author  : Rezk Ahmed     ************************/
/*******************  Date    : 26 Jun 2023    ************************/
/*******************  Layer   : MCAL           ************************/
/*******************  Version : 1.0            ************************/
/**********************************************************************/

#include "std_types.h"
#include "bit_math.h"
#include "error_state.h"

#include "EXTI_int.h"
#include "EXTI_priv.h"




ES_t EXTI_enuInitLine(EXTI_Handler_t *Copy_pstrEXTIHandler)
{
	ES_t Local_enuErrorState=ES_NOT_OK;
	
	switch(Copy_pstrEXTIHandler->EXTI_EdgTrig)
	{
		case EXTI_RISING_EDGE:
		SET_BIT(EXTI->RTSR,Copy_pstrEXTIHandler->EXTI_Line);
	    CLR_BIT(EXTI->FTSR,Copy_pstrEXTIHandler->EXTI_Line);
	    Local_enuErrorState=ES_OK;
		break;

		case EXTI_FALLING_EDGE:
		CLR_BIT(EXTI->RTSR,Copy_pstrEXTIHandler->EXTI_Line);
	    SET_BIT(EXTI->FTSR,Copy_pstrEXTIHandler->EXTI_Line);
	    Local_enuErrorState=ES_OK;
		break;

		case EXTI_ON_CHANGE_EDGE:
		SET_BIT(EXTI->RTSR,Copy_pstrEXTIHandler->EXTI_Line);
	    SET_BIT(EXTI->FTSR,Copy_pstrEXTIHandler->EXTI_Line);
	    Local_enuErrorState=ES_OK;
		break;
	}

	/*Disable the Interrupt*/
	CLR_BIT(EXTI->IMR , Copy_pstrEXTIHandler->EXTI_Line );

	return Local_enuErrorState;
}

ES_t EXTI_enuEnableLine(EXTI_Line_t Copy_enuLineNum)
{
	ES_t Local_enuErrorState=ES_NOT_OK;
	SET_BIT(EXTI->IMR , Copy_enuLineNum );
	return Local_enuErrorState;
}


ES_t EXTI_enuDisableLine(EXTI_Line_t Copy_enuLineNum)
{
	ES_t Local_enuErrorState=ES_NOT_OK;

	CLR_BIT(EXTI->IMR , Copy_enuLineNum );
	Local_enuErrorState=ES_OK;

	return Local_enuErrorState;
}

ES_t EXTI_enuEnableEventReq(EXTI_Line_t Copy_enuLineNum)
{
	ES_t Local_enuErrorState=ES_NOT_OK;

	SET_BIT(EXTI->EMR , Copy_enuLineNum );
	Local_enuErrorState=ES_OK;

	return Local_enuErrorState;
}

ES_t EXTI_enuDisableEventReq(EXTI_Line_t Copy_enuLineNum)
{
	ES_t Local_enuErrorState=ES_NOT_OK;

	SET_BIT(EXTI->EMR , Copy_enuLineNum );
	Local_enuErrorState=ES_OK;

	return Local_enuErrorState;
}


ES_t EXTI_enuSwTrigger(EXTI_Line_t Copy_enuLineNum)
{
	ES_t Local_enuErrorState=ES_NOT_OK;

	SET_BIT(EXTI->SWIER , Copy_enuLineNum );
	Local_enuErrorState=ES_OK;

	return Local_enuErrorState;
}

