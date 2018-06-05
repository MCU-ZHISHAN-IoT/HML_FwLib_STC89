/*
 * @Author:
 *  #Jiabin Hsu  | zsiothsu(at)zhishan-iot.ga
 * @E-mail:mcu(at)zhishan-iot.ga
 * @File-description:operations of ISP/IAP resource
 * @Required-compiler:SDCC
 * @Support-mcu:STC micro STC89 series
 * @Version:V0
 */
 
#include "isp.h"

/*
 * @Protype:void ISP_cmd(Action a)
 * @Parameter:(1)a:expected action
 * @Ret-val:
 * @Note:lanuch or stop ISP/IAP module
 */
void ISP_cmd(Action a)
{
	ISP_CONTR = (ISP_CONTR & 0x7F) | a << 0x7;
}

/*
 * @Protype:bool ISP_eraseByte(unsigned int addr)
 * @Parameter:(1)addr:operating address
 * @Ret-val:
 * @Note:clear the value of the register in the specified address
 */
bool ISP_eraseByte(unsigned int addr)
{
	if((ISP_beginAddress > addr) | (ISP_endAddress < addr)) return false;
	
	ISP_cmd(ENABLE);
	ISP_setAddress(addr);
	ISP_setCommand(ISP_CMMD_erase);
	ISP_trig();
	sleep(1);
	ISP_idle();
	return true;
}

/*
 * @Protype:void ISP_idle(void)
 * @Parameter:
 * @Ret-val:
 * @Note:Let ISP be idle
 */
void ISP_idle(void)
{
	ISP_cmd(DISABLE);
	ISP_setAddress(0x0000);
	ISP_setCommand(ISP_CMMD_idle);
	ISP_DATA = 0xFF;
}

/*
 * @Protype:unsigned char ISP_readByte(unsigned int addr)
 * @Parameter:(1)addr:operating address
 * @Ret-val:byte
 * @Note:read the value of the register in the specified address
 */
unsigned char ISP_readByte(unsigned int addr)
{
	unsigned char data__;
	
	ISP_cmd(ENABLE);
	ISP_setAddress(addr);
	ISP_setCommand(ISP_CMMD_read);
	ISP_trig();
	sleep(1);
	data__ = ISP_DATA;
	ISP_idle();
	
	return data__;
}

/*
 * @Protype:void ISP_setAddress(unsigned int addr)
 * @Parameter:(1)addr:operating address
 * @Ret-val:
 * @Note:setting the address to be operated
 */
void ISP_setAddress(unsigned int addr)
{
	ISP_ADDRL = addr;
	ISP_ADDRH = addr >> 0x8;
}

/*
 * @Protype:void ISP_setCommand(ISP_CMMD cmd)
 * @Parameter:(1)addr:operating address
 * @Ret-val:
 * @Note:set commmand
 */
void ISP_setCommand(ISP_CMMD cmd)
{
	ISP_CMD = cmd;
}

/*
 * @Protype:void ISP_trig(void)
 * @Parameter:
 * @Ret-val:
 * @Note:Trigger instruction
 */
void ISP_trig(void)
{
	ISP_TRIG = 0x46;
	ISP_TRIG = 0xB9;
}

/*
 * @Protype:void ISP_writeByte(unsigned int addr,unsigned char byte)
 * @Parameter:(1)addr:operating address
 * @Ret-val:
 * @Note:write the value into the register in the specified address
 */
void ISP_writeByte(unsigned int addr,unsigned char byte)
{
	if((ISP_beginAddress > addr) | (ISP_endAddress < addr)) return;
	
	ISP_cmd(ENABLE);
	ISP_setAddress(addr);
	ISP_setCommand(ISP_CMMD_write);
	ISP_DATA = byte;
	ISP_trig();
	sleep(1);
	ISP_idle();
}
