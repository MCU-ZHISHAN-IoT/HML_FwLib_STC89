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

/* typedef */
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
#define MCU_NULL           0
#define MCU_STC89C51RC     1
#define MCU_STC89LE51RC    1
#define MCU_STC89C52RC     2
#define MCU_STC89LE52RC    2
#define MCU_STC89C54RDP    3
#define MCU_STC89LE54RDP   3
#define MCU_STC89C58RDP    4
#define MCU_STC89LE58RDP   4
#define MCU_STC89C510RDP   5
#define MCU_STC89LE510RDP  5
#define MCU_STC89C512RDP   6
#define MCU_STC89LE512RDP  6
#define MCU_STC89C514RDP   7
#define MCU_STC89LE514RDP  7

/* ---------- NEED TO BE SETTED ---------- */
#define MCU_MODEL MCU_STC89C52RC

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


/* ---------- ---------- */

/* ---------- @run-time check --------- */

/* --- MCU model check --- */
#if (MCU_MODEL == MCU_NULL)
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
