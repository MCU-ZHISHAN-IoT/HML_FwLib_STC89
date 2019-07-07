/*****************************************************************************/
/** 
 * \file        tim2.h
 * \author      Jiabin Hsu | zsiothsu@zhishan-iot.tk
 * \brief       operations for timer-2
 * \note        
 * \version     v1.1
 * \ingroup     TIM2
******************************************************************************/

#ifndef ___TIM2_H___
#define ___TIM2_H___

/*****************************************************************************
 *                             header file                                   *
 *****************************************************************************/
#include <stdbool.h>
/*****************************************************************************/
#include "util.h"

/*****************************************************************************
 *                                macro                                      *
 *****************************************************************************/
#define TIM2_MAXTICK 0xFFFF

/*****************************************************************************
 *                           enumeration type                                *
 *****************************************************************************/

/**
 *\brief: mark work mode of timer-2
 */
typedef enum
{
    TIM2_mode_0 = 0x00,       /* 16-bit timer mode(auto-reload) */
    TIM2_mode_1 = 0x01,       /* 16-bit catch mode */
    TIM2_mode_2 = 0x30        /* baud rate generator */
} TIM2_mode;


/**
 *\brief: mark work function(role) of timer-2
 */
typedef enum
{
    TIM2_function_cnt = 0x1, /* counter mode */
    TIM2_function_tim = 0x0  /* timer mode */
} TIM2_function;

/*****************************************************************************
 *                           structure define                                *
 *****************************************************************************/

/**
 *\brief: struct for timer-2 configuration
 */
typedef struct
{
    TIM2_function          function;
    Action                 interruptState;
    UTIL_interruptPriority interruptPriority;
    TIM2_mode              mode;
    unsigned int           value;      /* value of counter register */
} TIM2_configTypeDef;

/*****************************************************************************
 *                          function declare                                 *
 *****************************************************************************/
unsigned int TIM2_calculateValue(unsigned int time);
void TIM2_clearFlag(void);
void TIM2_cmd(Action a);
void TIM2_config(TIM2_configTypeDef *tc);
unsigned int TIM2_getValue(void);
bool TIM2_isOverflow(void);
void TIM2_setFunction(TIM2_function f);
void TIM2_setMode(TIM2_mode m);
void TIM2_setValue(unsigned int val);
void TIM2_INT_cmd(Action a);
void TIM2_INT_setPriority(UTIL_interruptPriority p);
void TIM2_INT_T2EX_cmd(Action a);

#endif
