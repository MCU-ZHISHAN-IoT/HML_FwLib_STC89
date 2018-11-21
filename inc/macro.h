/*
 * @Author:
 *  #Jiabin Hsu  | zsiothsu(at)zhishan-iot.tk
 *  #Weilun Fong | wlf(at)zhishan-iot.tk
 * @E-mail:mcu(at)zhishan-iot.tk
 * @File-description:includes some macro definitions that used frequently
 * @Required-compiler:SDCC
 * @Support-mcu:STC micro STC89 series
 * @Version:V1
 */

#ifndef ___MACRO_H___
#define ___MACRO_H___

/* type define */
typedef unsigned char byte;
typedef unsigned char u8;
typedef unsigned int  u16;
typedef unsigned int  word;

typedef enum
{
    RESET = 0x0,
    SET   = !RESET
} FunctionalState;

typedef enum
{
    DISABLE = 0x0,
    ENABLE  = !DISABLE
} Action;

/* mark model */
#define _MCU_NULL_           0
#define _MCU_STC89C51RC_     1
#define _MCU_STC89LE51RC_    1
#define _MCU_STC89C52RC_     2
#define _MCU_STC89LE52RC_    2
#define _MCU_STC89C54RDP_    3
#define _MCU_STC89LE54RDP_   3
#define _MCU_STC89C58RDP_    4
#define _MCU_STC89LE58RDP_   4
#define _MCU_STC89C510RDP_   5
#define _MCU_STC89LE510RDP_  5
#define _MCU_STC89C512RDP_   6
#define _MCU_STC89LE512RDP_  6
#define _MCU_STC89C514RDP_   7
#define _MCU_STC89LE514RDP_  7

/* ---------- NEED TO CONFIG MANUALLY !!! ---------- */
#define _MCU_MODEL_ _MCU_STC89C52RC_

/* configure clock frequency */
#define _FRE_OSC_ 11059200L
//#define _FRE_OSC_ 12000000L

/* select the part you need */
#define ___COMPILE_EXTI___
#define ___COMPILE_GPIO___
#define ___COMPILE_ISP___
#define ___COMPILE_MEM___
#define ___COMPILE_RST___
#define ___COMPILE_TIM___
#define ___COMPILE_TIM2___
#define ___COMPILE_UART___
#define ___COMPILE_UTIL___
#define ___COMPILE_WDT___

/* ---------- END OF MANUAL CONFIGURATON PART --------- */

/* ---------- @run-time check --------- */

/* --- MCU model check --- */
#if (_MCU_MODEL_ == _MCU_NULL_)
    #error HML run-time check:not specify MCU model!(ERROR_CODE-0x01)
#endif

/* --- frequency of crystal oscillator --- */
#ifndef _FRE_OSC_
    #error HML run-time check:the firmware library need define extern clcok frequency!(ERROR_CODE-0x02)
#endif

/* --- check compile macro --- */
#if (defined ___COMPILE_TIM___) && (!defined ___COMPILE_EXTI___)
    #error HML run-time check: TIM part need extern support, please enable macro ___COMPILE_EXTI___(ERROR_CODE-0x03)
#endif

#if (defined ___COMPILE_TIM2___) && (!defined ___COMPILE_EXTI___)
    #error HML run-time check: TIM2 part need extern support, please enable macro ___COMPILE_EXTI___(ERROR_CODE-0x04)
#endif

#if (defined ___COMPILE_UART___) && ((!defined ___COMPILE_EXTI___) || (!defined ___COMPILE_TIM___) || (!defined ___COMPILE_TIM2___))
    #error HML run-time check: UART part need extern support, please enable macro ___COMPILE_TIM___  or ___COMPILE_TIM2___ at the same time(ERROR_CODE-0x05)
#endif

#endif
