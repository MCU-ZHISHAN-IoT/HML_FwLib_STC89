/*
 * @Author:
 *  #Jiabin Hsu  | zsiothsu(at)zhishan-iot.tk
 *  #Weilun Fong | wlf(at)zhishan-iot.tk
 * @E-mail:mcu(at)zhishan-iot.tk
 * @File-description:includes some definitions for operating EXTI module
 * @Required-compiler:SDCC
 * @Support-mcu:STC micro STC89 series
 * @Version:V1
 */

#ifndef ___EXTI_H___
#define ___EXTI_H___

#include <stc89.h>
#include "macro.h"

/* mark EXTI module */
typedef enum
{
	PERIPH_EXTI_0 = 0x0,
	PERIPH_EXTI_1 = 0x1,
	PERIPH_EXTI_2 = 0x2,
	PERIPH_EXTI_3 = 0x3
} PERIPH_EXTI;

/* mark work mode */
typedef enum
{
	EXTI_mode_fallEdge = 0x1,
    EXTI_mode_lowLevel = 0x0
} EXTI_mode;

/* mark priority(lager number means higher priority)*/
typedef enum
{
	INTR_priority_0 = 0x00,
	INTR_priority_1 = 0x01,
	INTR_priority_2 = 0x02,
	INTR_priority_3 = 0x03,
} INTR_priority;

typedef struct
{
	EXTI_mode     mode;
	INTR_priority priority;
} EXTI_configTypeDef;

/* ----- @function ----- */
void EXTI_cmd(PERIPH_EXTI exti,Action a);
void EXTI_config(PERIPH_EXTI exti,EXTI_configTypeDef *ec);
void EXTI_setMode(PERIPH_EXTI exti,EXTI_mode mod);
void EXTI_setPriority(PERIPH_EXTI exti,INTR_priority p);

#endif

