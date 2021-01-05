/*****************************************************************************/
/** 
 * \file        macro.h
 * \author      Jiabin Hsu  | zsiothsu@zhishan-iot.tk
 * \author      Weilun Fong | wlf@zhishan-iot.tk
 * \brief       HML macro define
 * \note        
 * \version     v1.3
 * \ingroup     generic
******************************************************************************/

#ifndef ___HML_MACRO_H___
#define ___HML_MACRO_H___

/*****************************************************************************
 *                             header file                                   *
 *****************************************************************************/
#include "hml/conf.h"

/*****************************************************************************
 *                                macro                                      *
 *****************************************************************************/

/**
 * \brief mark MCU model of STC89 series(suffix letter 'P' represents '+' )
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
 * \brief check macro for MCU model
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
 * \brief have macro for ISP function
 */
#define IS_ISP_MODEL(model)                 \
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

/**
 * \brief compile select
 */
#if (__CONF_COMPILE_EXTI == 1)
    #define COMPILE_EXTI
#endif
#if (__CONF_COMPILE_GPIO == 1)
    #define COMPILE_GPIO
#endif
#if (__CONF_COMPILE_ISP == 1)
    #define COMPILE_ISP
#endif
#if (__CONF_COMPILE_MEM == 1)
    #define COMPILE_MEM
#endif
#if (__CONF_COMPILE_RST == 1)
    #define COMPILE_RST
#endif
#if (__CONF_COMPILE_TIM == 1)
    #define COMPILE_TIM
#endif
#if (__CONF_COMPILE_TIM2 == 1)
    #define COMPILE_TIM2
#endif
#if (__CONF_COMPILE_UART == 1)
    #define COMPILE_UART
#endif
#if (__CONF_COMPILE_UTIL == 1)
    #define COMPILE_UTIL
#endif
#if (__CONF_COMPILE_WDT == 1)
    #define COMPILE_WDT
#endif

/**
 * \brief configure prescaler of MCU
 */
#define MCU_PRESCALER __CONF_MCU_PRESCALER

/*****************************************************************************
 *                           run-time check                                  *
 *****************************************************************************/
/**
 * \brief MCU clock configuration check
 */
#if (defined __CONF_FRE_CLKIN)
    #define MCU_FRE_CLK __CONF_FRE_CLKIN
#else
    #error HML run-time check: error: HML need define input clock frequency! (ERROR_CODE-0x01)
#endif

/**
 * \brief MCU clock prescaler(6T/12T) check
 */
#if (MCU_PRESCALER != 6) && (MCU_PRESCALER != 12) 
    #error HML run-time check: error: value of macro MCU_PRESCALER must be 6 or 12! (ERROR_CODE-0x02)
#endif

/**
 * \brief MCU model check
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
        #error HML run-time check: error: unknow or unsupported MCU model!(ERROR_CODE-0x03)
    #endif
#else
    #error HML run-time check: error: unspecify MCU model!(ERROR_CODE-0x04)
#endif

#if IS_ISP_MODEL(HML_MCU_MODEL)
    #define HAVE_ISP
#endif

/**
 * \brief HML compile selection check
 */
#ifndef HAVE_ISP
    #ifdef COMPILE_ISP
        #error HML run-time check: error: specified MCU model does not suppport \
ISP function, please disable macro __CONF_COMPILE_ISP in hml/conf.h (ERROR_CODE-0x05)
    #endif
#endif

#if (defined COMPILE_UART) && ((!defined COMPILE_TIM) || (!defined COMPILE_TIM2))
    #error HML run-time check: error: UART module needs extern support, please enable \
macro __CONF_COMPILE_TIM and __CONF_COMPILE_TIM2 at the same time in hml/conf.h (ERROR_CODE-0x06)
#endif

/**
 * \brief SDCC version check
 */
#if (__SDCC_VERSION_MAJOR == 3)
    #if (__SDCC_VERSION_MINOR < 6)
        #error HML run-time check: HML requires SDCC v3.6.0 or later versions (ERROR_CODE-0x07)
    #endif
#else
    #if (__SDCC_VERSION_MAJOR < 3)
        #error HML run-time check: HML requires SDCC v3.6.0 or later versions (ERROR_CODE-0x07)
    #endif
#endif

#endif
