
#include "std_types.h"
#include "bit_math.h"
#include "error_state.h"

#include "RCC_int.h"
#include "GPIO_int.h"

extern RCC_Handler_t RCC_strRCCConfiguration;


int main(void)
{
	RCC_enuInitSystemClk(&RCC_strRCCConfiguration);

	GPIO_Handle_t Local_strGPIOHand;
	Local_strGPIOHand.GPIO_Mode = GPIO_u8OUTPUT_2MHZ_PP;
	Local_strGPIOHand.GPIO_Port = GPIO_u8PORTA;
	Local_strGPIOHand.GPIO_PinNumber = GPIO_u8PIN0;

	RCC_enuAPB2PeriphClkCtrl(GPIOA,ENABLE);
	
	GPIO_enuInit(&Local_strGPIOHand);
	GPIO_enuWriteOutputPin(Local_strGPIOHand.GPIO_Port,Local_strGPIOHand.GPIO_PinNumber,GPIO_u8HIGH);
	
	while(1)
	{

	}
}
