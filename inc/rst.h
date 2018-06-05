/*
 * @Author:
 *  #Jiabin Hsu | zsiothsu(at)zhishan-iot.ga
 * @E-mail:mcu(at)zhishan-iot.ga
 * @File-description:includes some definitions of reset function
 * @Required-compiler:SDCC
 * @Support-mcu:STC micro STC89 series
 * @Version:V0
 */

#ifndef ___RST_H___
#define ___RST_H___

#include <stc89.h>
#include "macro.h"

typedef enum
{
	RST_AP  = 0x0,
	RST_ISP = 0x1
} RST_bootarea;

/* ---------- @function --------- */
void RST_reset(RST_bootarea area);

#endif /* ___RST_H___ */
