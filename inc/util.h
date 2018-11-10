/*
 * @Author:
 *  #Weilun Fong | wlf(at)zhishan-iot.tk
 * @E-mail:mcu(at)zhishan-iot.tk
 * @File-description:includes some public functions
 * @Required-compiler:SDCC
 * @Support-mcu:STC micro STC89 series
 * @Version:V1
 */

#ifndef ___UTIL_H___
#define ___UTIL_H___

#include "macro.h"

/* ---------- @function --------- */
void disableAllInterrupts(void);
void enableAllInterrupts(void);
void sleep(unsigned int t);

#endif /* ___UTIL_H___ */