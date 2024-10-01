/****************************************************/
/*  Author  : Rezk Ahmed                            */
/*  Date    : 18 July 2023                          */
/*  Version : V01                                   */
/****************************************************/


#ifndef STK_PRIV_H_
#define STK_PRIV_H_

typedef struct
{
	u32 CTRL;
	u32 LOAD;
	u32 VAL;
	u32 CALIB;
	
}STK_t;

#define STK   ((volatile STK_t*)0xE000E010)

#define STK_CTRL_ENABLE    0
#define STK_CTRL_TICKINT   1
#define STK_CTRL_CLKSOURCE 2
#define STK_CTRL_COUNTFLAG 16

#define SINGLE_INTERVAL    0
#define PERIODIC_INTERVAL  1


#define AHB_CLOCK_DEV_BY_8       8
#define AHB_CLOCK                1

#endif
