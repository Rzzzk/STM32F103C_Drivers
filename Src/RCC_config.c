/**********************************************************************/
/*******************  Author  : Rezk Ahmed     ************************/
/*******************  Date    : 26 Jun 2023    ************************/
/*******************  Layer   : MCAL           ************************/
/*******************  Version : 1.0            ************************/
/**********************************************************************/

#include "std_types.h"
#include "bit_math.h"
#include "error_state.h"

#include "RCC_int.h"



RCC_Handler_t RCC_strRCCConfiguration = {
		RCC_SYSCLK_HSI,
		RCC_AHB_not_divided,
		RCC_APB_not_divided,
		RCC_APB_not_divided,
		RCC_PLL_inputHSIDevBy2,
		RCC_PLL_inpClkx4
};
