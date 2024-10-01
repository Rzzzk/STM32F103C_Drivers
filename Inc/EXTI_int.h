/**********************************************************************/
/*******************  Author  : Rezk Ahmed     ************************/
/*******************  Date    : 26 Jun 2023    ************************/
/*******************  Layer   : MCAL           ************************/
/*******************  Version : 1.0            ************************/
/**********************************************************************/
#ifndef EXTI_INT_H_
#define EXTI_INT_H_

typedef enum
{
	EXTI_LINE0,
	EXTI_LINE1,
	EXTI_LINE2,
	EXTI_LINE3,
	EXTI_LINE4,
	EXTI_LINE5,
	EXTI_LINE6,
	EXTI_LINE7,
	EXTI_LINE8,
	EXTI_LINE9,
	EXTI_LINE10,
	EXTI_LINE11,
	EXTI_LINE12,
	EXTI_LINE13,
	EXTI_LINE14,
	EXTI_LINE15,
}EXTI_Line_t;
          

typedef enum
{
	EXTI_RISING_EDGE,
	EXTI_FALLING_EDGE,
	EXTI_ON_CHANGE_EDGE,

}EXTI_EdgTrig_t;


typedef struct
{
	EXTI_Line_t    EXTI_Line;
	EXTI_EdgTrig_t EXTI_EdgTrig;
}EXTI_Handler_t;

ES_t EXTI_enuInitLine(EXTI_Handler_t *Copy_pstrEXTIHandler);

ES_t EXTI_enuEnableLine(EXTI_Line_t Copy_enuLineNum);
ES_t EXTI_enuDisableLine(EXTI_Line_t Copy_enuLineNum);

ES_t EXTI_enuEnableEventReq(EXTI_Line_t Copy_enuLineNum);
ES_t EXTI_enuDisableEventReq(EXTI_Line_t Copy_enuLineNum);

ES_t EXTI_enuSwTrigger(EXTI_Line_t Copy_enuLineNum);

#endif
