/****************************************************/
/*  Author  : Rezk Ahmed                            */
/*  Date    : 15 July                               */
/*  Version : V01                                   */
/****************************************************/

#ifndef AFIO_PRIV_H_
#define AFIO_PRIV_H_

typedef struct
{
	u32 EVCR;
	u32 MAPR;
	u32 EXTICR[4];
	u32 MAPR2;
}AFIO_t;

#define AFIO ((volatile AFIO_t*) 0x40010000)
	
#endif
