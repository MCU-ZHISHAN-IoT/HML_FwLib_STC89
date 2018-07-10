/*
 * @Author:
 *  #Jiabin Hsu | zsiothsu(at)zhishan-iot.ga
 * @E-mail:mcu(at)zhishan-iot.ga
 * @File-description:includes some definitions for operating watch dog
 * @Required-compiler:SDCC
 * @Support-mcu:STC micro STC89 series
 * @Version:V0
 */
 
#ifndef ___WDT_H___
#define ___WDT_H___

#include <stc89.h>
#include "macro.h"

typedef enum
{
	WDT_Prescale_2   = 0x00,
	WDT_Prescale_4   = 0x01,
	WDT_Prescale_8   = 0x02,
	WDT_Prescale_16  = 0x03,
	WDT_Prescale_32  = 0x04,
	WDT_Prescale_64  = 0x05,
	WDT_Prescale_128 = 0x06,
	WDT_Prescale_256 = 0x07
} WDT_Prescale;


/* ---------- @function --------- */
void WDT_clear(void);
void WDT_cmd(Action a);
void WDT_cmd_idleCount(Action a);
void WDT_setPrescale(WDT_Prescale pre);

#endif /* ___WDT_H___ */