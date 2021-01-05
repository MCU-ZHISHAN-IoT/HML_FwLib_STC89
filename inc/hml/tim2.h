/*****************************************************************************/
/** 
 * \file        tim2.h
 * \author      Jiabin Hsu | zsiothsu@zhishan-iot.tk
 * \brief       operations for timer-2
 * \note        
 * \version     v1.3
 * \ingroup     TIM2
******************************************************************************/

#ifndef ___HML_TIM2_H___
#define ___HML_TIM2_H___

/*****************************************************************************
 *                             header file                                   *
 *****************************************************************************/
#include "hml/util.h"

/*****************************************************************************
 *                                macro                                      *
 *****************************************************************************/
#define TIM2_MAXTICK    WORD_MAX

/*****************************************************************************
 *                           enumeration type                                *
 *****************************************************************************/

/**
 * \brief mark baud clock type
 */
typedef enum
{
    TIM2_baudClock_receive  = 0x01, /* receive clock */
    TIM2_baudClock_transmit = 0x02  /* transmit clock */
} TIM2_baudClock;

/**
 * \brief mark work function(role) of timer-2
 */
typedef enum
{
    TIM2_function_cnt = 0x1, /* counter mode */
    TIM2_function_tim = 0x0  /* timer mode */
} TIM2_function;

/**
 * \brief mark work mode of timer-2
 */
typedef enum
{
    TIM2_mode_0 = 0x00,       /* 16-bit timer mode(auto-reload) */
    TIM2_mode_1 = 0x01,       /* 16-bit catch mode */
    TIM2_mode_2 = 0x30        /* baud rate generator */
} TIM2_mode;

/*****************************************************************************
 *                           structure define                                *
 *****************************************************************************/

/**
 * \brief struct for timer-2 configuration
 */
typedef struct
{
    TIM2_function           function;
    Action                  interruptState;
    UTIL_interruptPriority  interruptPriority;
    TIM2_mode               mode;
    uint16_t                value;          /* value of counter register */
    uint16_t                reloadValue;    /* only for auto-reload mode */
} TIM2_configTypeDef;

/*****************************************************************************
 *                          function declare                                 *
 *****************************************************************************/
uint16_t TIM2_calculateValue(uint16_t time);
void TIM2_clearFlag(void);
void TIM2_cmd(Action a);
void TIM2_config(TIM2_configTypeDef *t2c);
uint16_t TIM2_getCaptureValue(void);
uint16_t TIM2_getValue(void);
bool TIM2_isExternalEvent(void);
bool TIM2_isOverflow(void);
void TIM2_setFunction(TIM2_function f);
void TIM2_setMode(TIM2_mode mode);
void TIM2_setReloadValue(uint16_t val);
void TIM2_setValue(uint16_t val);
void TIM2_BAUD_cmd(TIM2_baudClock t, Action a);
void TIM2_INT_cmd(Action a);
void TIM2_INT_setPriority(UTIL_interruptPriority p);
void TIM2_T2EX_cmd(Action a);

#endif
