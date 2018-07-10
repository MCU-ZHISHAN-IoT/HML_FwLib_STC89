/*
 * @Author:
 *  #Jiabin Hsu | zsiothsu(at)zhishan-iot.ga
 * @E-mail:mcu(at)zhishan-iot.ga
 * @File-description:includes some definitions for operating timer_2 module
 * @Required-compiler:SDCC
 * @Support-mcu:STC micro STC89 series
 * @Version:V0
 */

#ifndef ___TIM2_H___
#define ___TIM2_H___

#define _FRE_OSC_ 11059200L
//#define _FRE_OSC_ 12000000L

#include <stc89.h>
#include <stdbool.h>

#include "exti.h"
#include "macro.h"

typedef enum
{
	TIM2_MODE_TIM = 0x00, /* timer mode */
	TIM2_MODE_catch = 0x01,  /* catch mode */
	TIM2_MODE_baudrateProducer = 0x30 /* baudrateProducer */
} TIM2_mode;

typedef enum
{
	TIM2_FUNC_CNT = 0x1, /* couter mode */
	TIM2_FUNC_TIM = 0x0  /* timer mode */
} TIM2_function;

typedef struct
{
	TIM2_function function;
	Action        interruptState;
	INTR_PIOR     interruptPriority;
	TIM2_mode     mode;
	unsigned int  value;
} TIM2_configTypeDef;

/* ---------- @function --------- */
unsigned int TIM2_calculateValue(unsigned int time);/* (time/us) */
void TIM2_clearFlag(void);
void TIM2_cmd(Action a);
void TIM2_config(TIM2_configTypeDef *tc);
unsigned int TIM2_getValue();
bool TIM2_isOverflow();
void TIM2_setFunction(TIM2_function f);
void TIM2_setMode(TIM2_mode m);
void TIM2_setValue(unsigned int val);
void TIM2_INT_cmd(Action a);
void TIM2_INT_setPriority(INTR_PIOR p);
void TIM2_INT_T2EX_cmd(Action a);

#endif /*___TIM2_H___*/
