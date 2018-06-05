/*
 * @Author:
 *  #Jiabin Hsu | zsiothsu(at)zhishan-iot.ga
 * @E-mail:mcu(at)zhishan-iot.ga
 * @File-description:includes some definitions for operating ISP/IAP module
 * @Required-compiler:SDCC
 * @Support-mcu:STC micro STC89 series
 * @Version:V0
 */

#ifndef ___ISP_H___
#define ___ISP_H___

#include <stc89.h>
#include <stdbool.h>

#include "util.h"
#include "macro.h"

typedef enum
{
	ISP_CMMD_idle  = 0x0,
	ISP_CMMD_read  = 0x1,
	ISP_CMMD_write = 0x2,
	ISP_CMMD_erase = 0x3,
} ISP_CMMD;

/* ---------- addr define --------- */

#if (MCU_MODEL == MCU_STC89C51RC)  || \
    (MCU_MODEL == MCU_STC89LE51RC) || \
    (MCU_MODEL == MCU_STC89C52RC)  || \
    (MCU_MODEL == MCU_STC89LE52RC)
	#define ISP_beginAddress 0x2000
	#define ISP_endAddress 0x2FFF

#else
	#define ISP_endAddress 0xF3FF
	#if (MCU_MODEL == MCU_STC89C54RD)    || \
        (MCU_MODEL == MCU_STC89LE54RD)
		#define ISP_beginAddress 0x4000
	#elif (MCU_MODEL == MCU_STC89C58RD)  || \
	      (MCU_MODEL == MCU_STC89LE58RD)
		#define ISP_beginAddress 0x8000
	#elif (MCU_MODEL == MCU_STC89C510RD) || \
	      (MCU_MODEL == MCU_STC89LE510RD)
		#define ISP_beginAddress 0xA000
	#elif (MCU_MODEL == MCU_STC89C512RD) || \
	      (MCU_MODEL == MCU_STC89LE512RD)
		#define ISP_beginAddress 0xC000
	#elif (MCU_MODEL == MCU_STC89C514RD) || \
	      (MCU_MODEL == MCU_STC89LE514RD)
		#define ISP_beginAddress 0xE000
	#endif /* else */

#endif/* MCU_MODEL RC/RD */
	
/* ---------- @function --------- */
void ISP_cmd(Action a);
bool ISP_eraseByte(unsigned int addr);
void ISP_idle(void);
unsigned char ISP_readByte(unsigned int addr);
void ISP_setAddress(unsigned int addr);
void ISP_setCommand(ISP_CMMD cmd);
void ISP_trig(void);
void ISP_writeByte(unsigned int addr,unsigned char byte);

#endif /*___ISP_H___*/
