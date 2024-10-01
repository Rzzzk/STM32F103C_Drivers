/*
 * NVIC_int.h
 *
 *  Created on: Nov 11, 2023
 *      Author: REZK
 */

#ifndef NVIC_INT_H_
#define NVIC_INT_H_

#define  EXTI0_PIN_NUM    6
#define  EXTI1_PIN_NUM    7
#define  EXTI2_PIN_NUM    8
#define  EXTI3_PIN_NUM    9
#define  EXTI4_PIN_NUM   10


ES_t NVIC_enudInit(void);
ES_t NVIC_enudEnableIRQ(u8 Copy_u8InterruptNum);
ES_t NVIC_enudDisableIRQ(u8 Copy_u8InterruptNum);
ES_t NVIC_enudSetIRQPending(u8 Copy_u8InterruptNum);
ES_t NVIC_enudClearIRQPending(u8 Copy_u8InterruptNum);

ES_t NVIC_enuGetIRQActiveState(u8 Copy_u8InterruptNum, u8 *Copy_u8ActiveFlagStatus);


ES_t NVIC_enuSetIntPriority(s8 Copy_s8InterruptNum , u8 Copy_u8GroupPriority , u8 Copy_u8SubPriority );


#endif /* NVIC_INT_H_ */
