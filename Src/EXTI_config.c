/**********************************************************************/
/*******************  Author  : Rezk Ahmed     ************************/
/*******************  Date    : 26 Jun 2023    ************************/
/*******************  Layer   : MCAL           ************************/
/*******************  Version : 1.0            ************************/
/**********************************************************************/

#include "std_types.h"
#include "bit_math.h"
#include "error_state.h"

#include <EXTI_int.h>
#include <EXTI_priv.h>

EXTI_Handler_t EXT_strInitHandler = {EXTI_LINE0, EXTI_RISING_EDGE};
