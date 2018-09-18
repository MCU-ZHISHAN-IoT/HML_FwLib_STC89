/*
 * @Author:
 *  #Jiabin Hsu  | zsiothsu(at)zhishan-iot.ga
 *  #Weilun Fong | wlf(at)zhishan-iot.ga
 * @E-mail:mcu(at)zhishan-iot.ga
 * @File-description:includes some definitions for operating gpio module
 * @Required-compiler:SDCC
 * @Support-mcu:STC micro STC89 series
 * @Version:V0
 */
 
#ifndef ___GPIO_H___
#define ___GPIO_H___

#include <stc89.h>
#include "macro.h"

/* define port */
typedef enum
{
	PERIPH_GPIO_0 = 0x0,
	PERIPH_GPIO_1 = 0x1,
	PERIPH_GPIO_2 = 0x2,
	PERIPH_GPIO_3 = 0x3,
	PERIPH_GPIO_4 = 0x4
}PERIPH_GPIO;

/* define pin */
typedef enum
{
	PERIPH_GPIO_PIN_0 = 0x01,
	PERIPH_GPIO_PIN_1 = 0x02,
	PERIPH_GPIO_PIN_2 = 0x04,
	PERIPH_GPIO_PIN_3 = 0x08,
	PERIPH_GPIO_PIN_4 = 0x10,
	PERIPH_GPIO_PIN_5 = 0x20,
	PERIPH_GPIO_PIN_6 = 0x40,
	PERIPH_GPIO_PIN_7 = 0x80
}PERIPH_GPIO_PIN;


/* ---------- @function --------- */
void GPIO_configBitValue(PERIPH_GPIO gpio,PERIPH_GPIO_PIN pin,FunctionalState f);
void GPIO_configPort(PERIPH_GPIO gpio,unsigned char val);
FunctionalState GPIO_getBitValue(PERIPH_GPIO gpio,PERIPH_GPIO_PIN pin);
void GPIO_resetBitValue(PERIPH_GPIO gpio,PERIPH_GPIO_PIN pin);
void GPIO_setBitValue(PERIPH_GPIO gpio,PERIPH_GPIO_PIN pin);
void GPIO_toggleBitValue(PERIPH_GPIO gpio,PERIPH_GPIO_PIN pin);

#endif /* ___GPIO_H___ */
