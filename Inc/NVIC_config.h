/*
 * NVIC_config.h
 *
 *  Created on: Nov 11, 2023
 *      Author: REZK
 */

#ifndef NVIC_CONFIG_H_
#define NVIC_CONFIG_H_

/******************************************************
                         Nesting    |      Sub
Options                 priorities  |   priorities
------------------------------------|------------------
NVIC_NEST_4_SUB_0   	16          |      None
NVIC_NEST_3_SUB_1   	8           |       2
NVIC_NEST_2_SUB_2   	4           |       4
NVIC_NEST_1_SUB_3   	2           |       8
NVIC_NEST_0_SUB_4   	None        |       16

*****************************************************/

#define NVIC_NEST_AND_SUB_PER_DISTRIBUTION          NVIC_NEST_2_SUB_2


#endif /* NVIC_CONFIG_H_ */
