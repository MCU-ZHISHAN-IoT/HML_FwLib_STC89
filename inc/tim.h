/*
 * @Author:
 *  #Jiabin Hsu  | zsiothsu(at)zhishan-iot.tk
 *  #Weilun Fong | wlf(at)zhishan-iot.tk
 * @E-mail:mcu(at)zhishan-iot..tk
 * @File-description:includes some definitions for operating timer module
 * @Required-compiler:SDCC
 * @Support-mcu:STC micro STC89 series
 * @Version:V1
 */
 
#ifndef ___TIM_H___
#define ___TIM_H___

/* --- @header file --- */
#include <stc89.h>
#include <stdbool.h>
#include "exti.h"
#include "macro.h"

typedef enum
{
	PERIPH_TIM_0 = 0x0,
	PERIPH_TIM_1 = 0x1,
	PERIPH_TIM_2 = 0x2 /* refer to tim2.h */
} PERIPH_TIM;

typedef enum
{
	TIM_mode_0 = 0x0,   /* 13-bit timer/counter */
	TIM_mode_1 = 0x1,   /* 16-bit timer/counter */
	TIM_mode_2 = 0x2,   /* 8-bit auto reload */
	TIM_mode_3 = 0x3    /* only for timer-0 */
} TIM_mode;

/* mark function of timer */
typedef enum
{
	TIM_FUNC_CNT = 0x1, /* counter mode */
	TIM_FUNC_TIM = 0x0  /* timer mode */
} TIM_function;

typedef struct
{
	TIM_function  function;
	Action        interruptState;
	INTR_priority interruptPriority;
	TIM_mode      mode;
	unsigned int value;
} TIM_configTypeDef;

/* ----- @function ----- */
unsigned int TIM_calculateValue(unsigned int time,TIM_mode m);  /* (time/us) */
void TIM_cmd(PERIPH_TIM tim,Action a);
void TIM_config(PERIPH_TIM tim,TIM_configTypeDef *tc);
unsigned int TIM_getValue(PERIPH_TIM tim);
bool TIM_isOverflow(PERIPH_TIM tim);
void TIM_setFunction(PERIPH_TIM tim,TIM_function f);
void TIM_setMode(PERIPH_TIM tim,TIM_mode m);
void TIM_setValue(PERIPH_TIM tim,unsigned int val);
void TIM_INT_cmd(PERIPH_TIM tim,Action a);
void TIM_INT_setPriority(PERIPH_TIM tim,INTR_priority p);

#endif /* ___TIM_H___ */
