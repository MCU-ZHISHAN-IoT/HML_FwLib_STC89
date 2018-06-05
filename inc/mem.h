/*
 * @Author:
 *  #Weilun Fong | wlf(at)zhishan-iot.ga
 * @E-mail:mcu(at)zhishan-iot.ga
 * @File-description:
 * #contains definitions that allow you to directly access the different memory areas of the STC90.
 * #have the similar functions like absacc.h in Keil
 * @Required-compiler:SDCC
 * @Support-mcu:STC micro STC89 series
 * @Version:V0
 */

#ifndef ___MEM_H___
#define ___MEM_H___

#include <stc89.h>
#include "macro.h"

#define __CBYTE ((unsigned char volatile __code  *) 0)
#define __DBYTE ((unsigned char volatile __data  *) 0)
#define __PDATA ((unsigned char volatile __pdata *) 0)
#define __XBYTE ((unsigned char volatile __xdata *) 0)

#define __CWORD ((unsigned int volatile __code  *) 0)
#define __DWORD ((unsigned int volatile __data  *) 0)
#define __PWORD ((unsigned int volatile __pdata *) 0)
#define __XWORD ((unsigned int volatile __xdata *) 0)

/* ---------- @function --------- */
void MEM_cmd_Ale(Action a);
void MEM_cmd_internalExtendedRam(Action a);

#endif
