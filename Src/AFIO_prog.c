/****************************************************/
/*  Author  : Rezk Ahmed                            */
/*  Date    : 15 July                               */
/*  Version : V01                                   */
/****************************************************/
#include "std_types.h"
#include "bit_math.h"
#include "error_state.h"

#include "AFIO_int.h"
#include "AFIO_priv.h"

#include "GPIO_int.h"


ES_t AFIO_enuSetEXTIConfigLine(u8 Copy_u8LineNum , u8 Copy_u8Port)
{
	ES_t Local_enuErrorState=ES_NOT_OK;

	u8 Local_u8RegIndex = Copy_u8LineNum/4 ;
	Copy_u8LineNum = Copy_u8LineNum%4;
	
	AFIO->EXTICR[Local_u8RegIndex] &=~(0b1111 << Copy_u8LineNum*4 );
	AFIO->EXTICR[Local_u8RegIndex] |= (Copy_u8Port << Copy_u8LineNum*4 );

	Local_enuErrorState=ES_OK;

	return Local_enuErrorState;
}

ES_t AFIO_enuSetEventOutEnable(void)
{
	ES_t Local_enuErrorState=ES_NOT_OK;

	SET_BIT(AFIO->EVCR,7);
	Local_enuErrorState=ES_OK;

	return Local_enuErrorState;
}

ES_t AFIO_enuSetEventOutDisable(void)
{
	ES_t Local_enuErrorState=ES_NOT_OK;

	CLR_BIT(AFIO->EVCR,7);
	Local_enuErrorState=ES_OK;

	return Local_enuErrorState;
}


ES_t AFIO_enuSetEventOutPin(u8 Copy_u8GPIOPort ,u8 Copy_u8GPIOPin)
{
	ES_t Local_enuErrorState=ES_NOT_OK;

	switch(Copy_u8GPIOPort)
	{
		case GPIO_u8PORTA:AFIO->EVCR|=0b000<<4; break;
		case GPIO_u8PORTB:AFIO->EVCR|=0b001<<4; break;
		case GPIO_u8PORTC:AFIO->EVCR|=0b010<<4; break;
	}                                       
	
	switch(Copy_u8GPIOPin)
	{
		case GPIO_u8PIN0:AFIO->EVCR|= 0b0000; Local_enuErrorState=ES_OK;  break;
		case GPIO_u8PIN1:AFIO->EVCR|= 0b0001; Local_enuErrorState=ES_OK;  break;
		case GPIO_u8PIN2:AFIO->EVCR|= 0b0010; Local_enuErrorState=ES_OK;  break;
		case GPIO_u8PIN3:AFIO->EVCR|= 0b0011; Local_enuErrorState=ES_OK;  break;
		case GPIO_u8PIN4:AFIO->EVCR|= 0b0100; Local_enuErrorState=ES_OK;  break;
		case GPIO_u8PIN5:AFIO->EVCR|= 0b0101; Local_enuErrorState=ES_OK;  break;
		case GPIO_u8PIN6:AFIO->EVCR|= 0b0110; Local_enuErrorState=ES_OK;  break;
		case GPIO_u8PIN7:AFIO->EVCR|= 0b0111; Local_enuErrorState=ES_OK;  break;
		case GPIO_u8PIN8:AFIO->EVCR|= 0b1000; Local_enuErrorState=ES_OK;  break;
		case GPIO_u8PIN9:AFIO->EVCR|= 0b1001; Local_enuErrorState=ES_OK;  break;
		case GPIO_u8PIN10:AFIO->EVCR|= 0b1010; Local_enuErrorState=ES_OK;  break;
		case GPIO_u8PIN11:AFIO->EVCR|= 0b1011; Local_enuErrorState=ES_OK;  break;
		case GPIO_u8PIN12:AFIO->EVCR|= 0b1100; Local_enuErrorState=ES_OK;  break;
		case GPIO_u8PIN13:AFIO->EVCR|= 0b1101; Local_enuErrorState=ES_OK;  break;
		case GPIO_u8PIN14:AFIO->EVCR|= 0b1110; Local_enuErrorState=ES_OK;  break;
		case GPIO_u8PIN15:AFIO->EVCR|= 0b1111; Local_enuErrorState=ES_OK;  break;

	}


	return Local_enuErrorState;
}


