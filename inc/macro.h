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
 *\brief: mark MCU model of STC89 series(suffix letter 'P' represents '+' )
 */
#define MCU_MODEL_GENERIC         0x01
#define MCU_MODEL_STC89C51RC      0x02
#define MCU_MODEL_STC89LE51RC     0x03
#define MCU_MODEL_STC89C52RC      0x04
#define MCU_MODEL_STC89LE52RC     0x05
#define MCU_MODEL_STC89C53RC      0x06
#define MCU_MODEL_STC89LE53RC     0x07
#define MCU_MODEL_STC89C54RDP     0x08
#define MCU_MODEL_STC89LE54RDP    0x09
#define MCU_MODEL_STC89C58RDP     0x0A
#define MCU_MODEL_STC89LE58RDP    0x0B
#define MCU_MODEL_STC89C510RDP    0x0C
#define MCU_MODEL_STC89LE510RDP   0x0D
#define MCU_MODEL_STC89C512RDP    0x0E
#define MCU_MODEL_STC89LE512RDP   0x0F
#define MCU_MODEL_STC89C514RDP    0x10
#define MCU_MODEL_STC89LE514RDP   0x11
#define MCU_MODEL_STC89C516RDP    0x12
#define MCU_MODEL_STC89LE516RDP   0x13

/**
 *\brief: check macro for MCU model
 */
#define IS_STC89_MCU_MODEL(model)           \
    (                                       \
      (model == MCU_MODEL_GENERIC)       || \
      (model == MCU_MODEL_STC89C51RC)    || \
      (model == MCU_MODEL_STC89LE51RC)   || \
      (model == MCU_MODEL_STC89C52RC)    || \
      (model == MCU_MODEL_STC89LE52RC)   || \
      (model == MCU_MODEL_STC89C53RC)    || \
      (model == MCU_MODEL_STC89LE53RC)   || \
      (model == MCU_MODEL_STC89C54RDP)   || \
      (model == MCU_MODEL_STC89LE54RDP)  || \
      (model == MCU_MODEL_STC89C58RDP)   || \
      (model == MCU_MODEL_STC89LE58RDP)  || \
      (model == MCU_MODEL_STC89C510RDP)  || \
      (model == MCU_MODEL_STC89LE510RDP) || \
      (model == MCU_MODEL_STC89C512RDP)  || \
      (model == MCU_MODEL_STC89LE512RDP) || \
      (model == MCU_MODEL_STC89C514RDP)  || \
      (model == MCU_MODEL_STC89LE514RDP) || \
      (model == MCU_MODEL_STC89C516RDP)  || \
      (model == MCU_MODEL_STC89LE516RDP)    \
    )

/**
 *\brief: have macro for ISP function
 */
#define IS_ADC_MODEL(model)           \
    (                                       \
      (model == MCU_MODEL_STC89C51RC)    || \
      (model == MCU_MODEL_STC89LE51RC)   || \
      (model == MCU_MODEL_STC89C52RC)    || \
      (model == MCU_MODEL_STC89LE52RC)   || \
      (model == MCU_MODEL_STC89C54RDP)   || \
      (model == MCU_MODEL_STC89LE54RDP)  || \
      (model == MCU_MODEL_STC89C58RDP)   || \
      (model == MCU_MODEL_STC89LE58RDP)  || \
      (model == MCU_MODEL_STC89C510RDP)  || \
      (model == MCU_MODEL_STC89LE510RDP) || \
      (model == MCU_MODEL_STC89C512RDP)  || \
      (model == MCU_MODEL_STC89LE512RDP) || \
      (model == MCU_MODEL_STC89C514RDP)  || \
      (model == MCU_MODEL_STC89LE514RDP)    \
    )

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
    #if IS_STC89_MCU_MODEL(__CONF_MCU_MODEL)
        #if (__CONF_MCU_MODEL == MCU_MODEL_GENERIC)
            #warning the value of macro HML_MCU_MODEL will be filled with MCU_MODEL_STC89C52RC
            #define HML_MCU_MODEL MCU_MODEL_STC89C52RC
        #else
            #define HML_MCU_MODEL __CONF_MCU_MODEL
        #endif
    #else
        #error HML run-time check: error: unknow or unsupported MCU model!(ERROR_CODE-0x02)
    #endif
#else
    #error HML run-time check: error: unspecify MCU model!(ERROR_CODE-0x03)
#endif

#if IS_ADC_MODEL(HML_MCU_MODEL)
    #define HAVE_ISP
#endif

/**
 *\brief: HML compile selection check
 */
#ifndef HAVE_ISP
    #ifdef __CONF_COMPILE_ISP
        #error HML run-time check: error: specified MCU model does not suppport ISP function. (ERROR_CODE-0x04)
    #endif
#endif

#if (defined __CONF_COMPILE_UART) && ((!defined __CONF_COMPILE_TIM) || (!defined __CONF_COMPILE_TIM2))
    #error HML run-time check: error: UART module needs extern support, please enable macro __CONF_COMPILE_EXTI, __CONF_COMPILE_TIM and __CONF_COMPILE_TIM2 at the same time in conf.h (ERROR_CODE-0x05)
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
