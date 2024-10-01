/****************************************************/
/*  Author  : Rezk Ahmed                            */
/*  Date    : 15 July                               */
/*  Version : V01                                   */
/****************************************************/

#ifndef AFIO_INT_H_
#define AFIO_INT_H_

#define MAFIO_u8PINA   0
#define MAFIO_u8PINB   1
#define MAFIO_u8PINC   2

ES_t AFIO_enuSetEXTIConfigLine(u8 Copy_u8LineNum , u8 Copy_u8Port);
ES_t AFIO_enuSetEventOutEnable(void);
ES_t AFIO_enuSetEventOutDisable(void);
ES_t AFIO_enuSetEventOutPin(u8 Copy_u8GPIOPort ,u8 Copy_u8GPIOPin);



#endif
