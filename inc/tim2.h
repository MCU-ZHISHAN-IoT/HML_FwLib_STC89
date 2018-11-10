/*
 * @Author:
 *  #Jiabin Hsu | zsiothsu(at)zhishan-iot.tk
 * @E-mail:mcu(at)zhishan-iot.tk
 * @File-description:includes some definitions for operating timer_2 module
 * @Required-compiler:SDCC
 * @Support-mcu:STC micro STC89 series
 * @Version:V1
 */

#ifndef ___TIM2_H___
#define ___TIM2_H___

/* --- @header file --- */
#include <stc89.h>
#include <stdbool.h>
#include "exti.h"
#include "macro.h"

/* mark work mode of TIM2 */
typedef enum
{
    TIM2_mode_0 = 0x00,  /* 16-bit timer mode(auto-reload) */
    TIM2_mode_1 = 0x01,  /* 16-bit catch mode */
    TIM2_mode_2 = 0x30   /* baud rate generator */
} TIM2_mode;

typedef enum
{
    TIM2_FUNC_CNT = 0x1, /* counter mode */
    TIM2_FUNC_TIM = 0x0  /* timer mode */
} TIM2_function;

/* define configure struct */
typedef struct
{
    TIM2_function  function;
    Action         interruptState;
    INTR_priority  interruptPriority;
    TIM2_mode      mode;
    unsigned int   value;
} TIM2_configTypeDef;

/* ---------- @function --------- */
unsigned int TIM2_calculateValue(unsigned int time);  /* (time/us) */
void TIM2_clearFlag(void);
void TIM2_cmd(Action a);
void TIM2_config(TIM2_configTypeDef *tc);
unsigned int TIM2_getValue(void);
bool TIM2_isOverflow(void);
void TIM2_setFunction(TIM2_function f);
void TIM2_setMode(TIM2_mode m);
void TIM2_setValue(unsigned int val);
void TIM2_INT_cmd(Action a);
void TIM2_INT_setPriority(INTR_priority p);
void TIM2_INT_T2EX_cmd(Action a);

#endif /*___TIM2_H___*/
