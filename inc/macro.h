/*
 * @Author:
 *  #Jiabin Hsu | zsiothsu(at)zhishan-iot.ga
 *  #Weilun Fong | wlf(at)zhishan-iot.ga
 * @E-mail:mcu(at)zhishan-iot.ga
 * @File-description:includes some macro definitions that used frequently
 * @Required-compiler:SDCC
 * @Support-mcu:STC micro STC89 series
 * @Version:V0
 */

#ifndef ___MACRO_H___
#define ___MACRO_H___

/* typedef */	
typedef unsigned char u8;
typedef unsigned int  u16;

typedef enum
{
	RESET = 0x0,
	SET = !RESET
}FunctionalState;

typedef enum
{
	DISABLE = 0x0,
	ENABLE = !DISABLE
}Action;

/* mark model */
#define MCU_NULL          0
#define MCU_STC89C51RC    1
#define MCU_STC89LE51RC   1
#define MCU_STC89C52RC    2
#define MCU_STC89LE52RC   2
#define MCU_STC89C54RD    3
#define MCU_STC89LE54RD   3
#define MCU_STC89C58RD    4
#define MCU_STC89LE58RD   4
#define MCU_STC89C510RD   5
#define MCU_STC89LE510RD  5
#define MCU_STC89C512RD   6
#define MCU_STC89LE512RD  6
#define MCU_STC89C514RD   7
#define MCU_STC89LE514RD  7

/* ---------- NEED TO BE SETTED ---------- */
#define MCU_MODEL MCU_STC89C52RC

/* config clock frequency */
#define _FRE_OSC_ 11059200L
//#define _FRE_OSC_ 12000000L

/* ---------- ---------- */

/* ---------- @run-time check --------- */
#if (MCU_MODEL == MCU_NULL)
	#error HML run-time check:not specify MCU model!(ERROR_CODE-0x01)
#endif /* MCU_MODEL */

#ifndef _FRE_OSC_
	#error HML run-time check:the firmware library need define extern clcok frequency!(ERROR_CODE-0x02)
#endif

#endif /* ___MACRO_H___ */
