/*
 * @Author:
 *  #Jiabin Hsu  | zsiothsu(at)zhishan-iot.ga
 *  #Weilun Fong | wlf(at)zhishan-iot.ga
 * @E-mail:mcu(at)zhishan-iot.ga
 * @File-description:includes some definitions for operating exti module
 * @Required-compiler:SDCC
 * @Support-mcu:STC micro STC89 series
 * @Version:V0
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
	EXTI_MOD_FAL = 0x1,
    EXTI_MOD_LVL = 0x0
} EXTI_MOD;

/* mark priority(lager number means higher priority)*/
typedef enum
{
	INTR_PIOR_0 = 0x00,
	INTR_PIOR_1 = 0x01,
	INTR_PIOR_2 = 0x02,
	INTR_PIOR_3 = 0x03,
} INTR_PIOR;

typedef struct
{
	EXTI_MOD mode;
	INTR_PIOR priority;
} EXTI_configTypeDef;

/* ---------- @function --------- */
void EXTI_cmd(PERIPH_EXTI exti,Action a);
void EXTI_config(PERIPH_EXTI exti,EXTI_configTypeDef *ec);
void EXTI_setMode(PERIPH_EXTI exti,EXTI_MOD mod);
void EXTI_setPriority(PERIPH_EXTI exti,INTR_PIOR p);

#endif /* ___EXTI_H___ */
