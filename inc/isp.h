/*
 * @Author:
 *  #Jiabin Hsu | zsiothsu(at)zhishan-iot.tk
 * @E-mail:mcu(at)zhishan-iot.tk
 * @File-description:includes some definitions for operating ISP/IAP module
 * @Required-compiler:SDCC
 * @Support-mcu:STC micro STC89 series
 * @Version:V1
 */

#ifndef ___ISP_H___
#define ___ISP_H___

#include <stc89.h>
#include <stdbool.h>

#include "util.h"
#include "macro.h"

/* mark command */
typedef enum
{
	ISP_command_idle  = 0x0,
	ISP_command_read  = 0x1,
	ISP_command_write = 0x2,
	ISP_command_erase = 0x3
} ISP_command;

/* ---------- @address define --------- */

#if (MCU_MODEL == MCU_STC89C51RC)  || \
    (MCU_MODEL == MCU_STC89LE51RC) || \
    (MCU_MODEL == MCU_STC89C52RC)  || \
    (MCU_MODEL == MCU_STC89LE52RC)
	#define ISP_ADDR_START 0x2000
	#define ISP_ADDR_END 0x2FFF

#else
	#define ISP_ADDR_END 0xF3FF
	#if (MCU_MODEL == MCU_STC89C54RDP)    || \
        (MCU_MODEL == MCU_STC89LE54RDP)
		#define ISP_ADDR_START 0x4000
	#elif (MCU_MODEL == MCU_STC89C58RDP)  || \
	      (MCU_MODEL == MCU_STC89LE58RDP)
		#define ISP_ADDR_START 0x8000
	#elif (MCU_MODEL == MCU_STC89C510RDP) || \
	      (MCU_MODEL == MCU_STC89LE510RDP)
		#define ISP_ADDR_START 0xA000
	#elif (MCU_MODEL == MCU_STC89C512RDP) || \
	      (MCU_MODEL == MCU_STC89LE512RDP)
		#define ISP_ADDR_START 0xC000
	#elif (MCU_MODEL == MCU_STC89C514RDP) || \
	      (MCU_MODEL == MCU_STC89LE514RDP)
		#define ISP_ADDR_START 0xE000
	#endif

#endif   /* MCU_MODEL RC/RDP */
	
/* ----- @function ----- */
void ISP_cmd(Action a);
bool ISP_eraseByte(unsigned int addr);
void ISP_idle(void);
unsigned char ISP_readByte(unsigned int addr);
void ISP_setAddress(unsigned int addr);
void ISP_setCommand(ISP_command cmd);
void ISP_trig(void);
void ISP_writeByte(unsigned int addr,byte dat);

#endif
