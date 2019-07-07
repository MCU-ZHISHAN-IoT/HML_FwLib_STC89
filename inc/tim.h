/*****************************************************************************/
/** 
 * \file        tim.h
 * \author      Jiabin Hsu   | zsiothsu@zhishan-iot.tk
 * \author      Weillun Fong | wlf@zhishan-iot.tk
 * \brief       operations for timers
 * \note        not for timer-2
 * \version     v1.1
 * \ingroup     TIM
******************************************************************************/

#ifndef ___TIM_H___
#define ___TIM_H___

/*****************************************************************************
 *                             header file                                   *
 *****************************************************************************/
#include <stdbool.h>
/*****************************************************************************/
#include "util.h"

/*****************************************************************************
 *                           enumeration type                                *
 *****************************************************************************/

/**
 *\brief: mark timer module
 */
typedef enum
{
    PERIPH_TIM_0 = 0x0,
    PERIPH_TIM_1 = 0x1,
    PERIPH_TIM_2 = 0x2
} PERIPH_TIM;

/**
 *\brief: mark timer work mode
 */
typedef enum
{
    TIM_mode_0 = 0x0,        /* 13-bit timer/counter */
    TIM_mode_1 = 0x1,        /* 16-bit timer/counter */
    TIM_mode_2 = 0x2,        /* 8-bit auto reload */
    TIM_mode_3 = 0x3         /* only for timer-0 */
} TIM_mode;

/**
 *\brief: mark function of timer
 */
typedef enum
{
    TIM_function_cnt = 0x1,  /* counter mode */
    TIM_function_tim = 0x0   /* timer mode */
} TIM_function;

/*****************************************************************************
 *                           structure define                                *
 *****************************************************************************/

/**
 *\brief: struct for timer configuration
 */
typedef struct
{
    TIM_function           function;
    Action                 interruptState;
    UTIL_interruptPriority interruptPriority;
    TIM_mode               mode;
    unsigned int           value;
} TIM_configTypeDef;

/*****************************************************************************
 *                          function declare                                 *
 *****************************************************************************/
unsigned int TIM_calculateValue(unsigned int time,TIM_mode m);
void TIM_cmd(PERIPH_TIM tim,Action a);
void TIM_config(PERIPH_TIM tim,TIM_configTypeDef *tc);
unsigned int TIM_getValue(PERIPH_TIM tim);
bool TIM_isOverflow(PERIPH_TIM tim);
void TIM_setFunction(PERIPH_TIM tim,TIM_function f);
void TIM_setMode(PERIPH_TIM tim,TIM_mode m);
void TIM_setValue(PERIPH_TIM tim,unsigned int val);
void TIM_INT_cmd(PERIPH_TIM tim,Action a);
void TIM_INT_setPriority(PERIPH_TIM tim,UTIL_interruptPriority p);

#endif
