/*****************************************************************************/
/** 
 * \file        macro.h
 * \author      Jiabin Hsu  | zsiothsu@zhishan-iot.tk
 * \author      Weilun Fong | wlf@zhishan-iot.tk
 * \brief       HML macro define
 * \note        
 * \version     v1.1
 * \ingroup     generic
******************************************************************************/

#ifndef ___MACRO_H___
#define ___MACRO_H___

/*****************************************************************************
 *                             header file                                   *
 *****************************************************************************/
#include "conf.h"

/*****************************************************************************
 *                             type define                                   *
 *****************************************************************************/
typedef unsigned char byte;
typedef unsigned char u8;
typedef unsigned int  u16;
typedef unsigned int  word;

/*****************************************************************************
 *                           enumeration type                                *
 *****************************************************************************/

/**
 *\brief: mark user action
 */
typedef enum
{
    DISABLE = 0x0,
    ENABLE  = !DISABLE
} Action;

/**
 *\brief: mark bit value/state
 */
typedef enum
{
    RESET = 0x0,
    SET   = !RESET
} FunctionalState;

/*****************************************************************************
 *                                macro                                      *
 *****************************************************************************/

/**
 *\brief: mark MCU model of STC89 series
 */
#define MCU_MODEL_NULL            0x00
#define MCU_MODEL_STC89C51RC      0x01
#define MCU_MODEL_STC89LE51RC     0x01
#define MCU_MODEL_STC89C52RC      0x02
#define MCU_MODEL_STC89LE52RC     0x02
#define MCU_MODEL_STC89C54RDP     0x03
#define MCU_MODEL_STC89LE54RDP    0x03
#define MCU_MODEL_STC89C58RDP     0x04
#define MCU_MODEL_STC89LE58RDP    0x04
#define MCU_MODEL_STC89C510RDP    0x05
#define MCU_MODEL_STC89LE510RDP   0x05
#define MCU_MODEL_STC89C512RDP    0x06
#define MCU_MODEL_STC89LE512RDP   0x06
#define MCU_MODEL_STC89C514RDP    0x07
#define MCU_MODEL_STC89LE514RDP   0x07

/*****************************************************************************
 *                           run-time check                                  *
 *****************************************************************************/
/**
 *\brief: MCU clock configuration check
 */
#if (defined __CONF_FRE_CLKIN)
    #define MCU_FRE_CLK __CONF_FRE_CLKIN
#else
    #error HML run-time check: error: HML need define input clock frequency! (ERROR_CODE-0x01)
#endif

/**
 *\brief: MCU model check
 */
#if (defined __CONF_MCU_MODEL)
    #if (__CONF_MCU_MODEL == MCU_MODEL_NULL)
        /* default MCU model: STC89C52RC */
        #pragma message("HML run-time check: error: HML will fill MCU model macro with MCU_MODEL_STC89C52RC")
        #define HML_MCU_MODEL MCU_MODEL_STC89C52RC
    #else
        #define HML_MCU_MODEL __CONF_MCU_MODEL
    #endif
#else
    #error HML run-time check: error: no specified MCU model!(ERROR_CODE-0x02)
#endif

/**
 *\brief: HML compile selection check
 */
#if (defined __CONF_COMPILE_TIM) && (!defined __CONF_COMPILE_EXTI)
    #error HML run-time check: error: TIM module need extern support, please enable macro __CONF_COMPILE_EXTI in conf.h (ERROR_CODE-0x03)
#endif

#if (defined __CONF_COMPILE_TIM2) && (!defined __CONF_COMPILE_EXTI)
    #error HML run-time check: error: TIM2 module need extern support, please enable macro __CONF_COMPILE_EXTI in conf.h (ERROR_CODE-0x04)
#endif

#if (defined __CONF_COMPILE_UART) && ((!defined __CONF_COMPILE_EXTI) || (!defined __CONF_COMPILE_TIM) || (!defined __CONF_COMPILE_TIM2))
    #error HML run-time check: error UART module need extern support, please enable macro __CONF_COMPILE_EXTI, __CONF_COMPILE_TIM  or __CONF_COMPILE_TIM2 at the same time in conf.h (ERROR_CODE-0x05)
#endif

/**
 *\brief: SDCC version check
 */
#if (__SDCC_VERSION_MAJOR == 3)
    #if (__SDCC_VERSION_MINOR < 6)
        #error HML run-time check: HML requires SDCC v3.6.0 or later versions (ERROR_CODE-0x06)
    #endif
#else
    #if (__SDCC_VERSION_MAJOR < 3)
        #error HML run-time check: HML requires SDCC v3.6.0 or later versions (ERROR_CODE-0x06)
    #endif
#endif

#endif
