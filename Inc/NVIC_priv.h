/*
 * NVIC_config.h
 *
 *  Created on: Nov 11, 2023
 *      Author: REZK
 */

#ifndef NVIC_PRIV_H_
#define NVIC_PRIV_H_

#define NVIC_BASE_ADDRESS      0xE000E100

#define NVIC_ISER0  *((__vo u32*)0xE000E100)/*Enable external interrupt from 0  to 31*/
#define NVIC_ISER1  *((__vo u32*)0xE000E104)/*Enable external interrupt from 32 to 63*/

#define NVIC_ICER0  *((__vo u32*)0xE000E180)/*Disable external interrupt from 0   to 31*/
#define NVIC_ICER1  *((__vo u32*)0xE000E184)/*Disable external interrupt from 32  to 63*/

#define NVIC_ISPR0  *((__vo u32*)0xE000E200)/*Set pending flag register from 0  to 31*/
#define NVIC_ISPR1  *((__vo u32*)0xE000E204)/*Set pending flag register from 32 to 63*/

#define NVIC_ICPR0  *((__vo u32*)0xE000E280)/*Clear pending flag register from 0  to 31*/
#define NVIC_ICPR1  *((__vo u32*)0xE000E284)/*Clear pending flag register from 0  to 31*/

#define NVIC_IABR0  *((__vo u32*)0xE000E300)/*Interrupt active flag status from 0  to 31*/
#define NVIC_IABR1  *((__vo u32*)0xE000E304)/*Interrupt active flag status from 32 to 63*/


#define SCB_AIRCR   *((__vo u32*)0xE000ED0C)
#define NVIC_IPR     ((__vo u8*)0xE000E400)


#define NVIC_NEST_4_SUB_0    0x05FA0300
#define NVIC_NEST_3_SUB_1    0x05FA0400
#define NVIC_NEST_2_SUB_2    0x05FA0500
#define NVIC_NEST_1_SUB_3    0x05FA0600
#define NVIC_NEST_0_SUB_4    0x05FA0700

#endif /* NVIC_PRIV_H_ */
