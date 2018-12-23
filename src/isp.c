/*
 * @Author:
 *  #Jiabin Hsu | zsiothsu(at)zhishan-iot.tk
 * @E-mail:mcu(at)zhishan-iot.tk
 * @File-description:operations of ISP resource
 * @Required-compiler:SDCC
 * @Support-mcu:STC micro STC89 series
 * @Version:V1
 */
 
#include "isp.h"
 
#ifdef ___COMPILE_ISP___

/*
 * @Prototype:void ISP_cmd(Action a)
 * @Parameter:(1)a:expected action
 * @Ret-val:
 * @Note:launch or stop ISP/IAP module
 */
void ISP_cmd(Action a)
{
    ISP_CONTR = (ISP_CONTR & 0x7F) | a << 0x7;
}

/*
 * @Prototype:bool ISP_eraseByte(unsigned int addr)
 * @Parameter:(1)addr:operating address
 * @Ret-val:
 * @Note:clear the value of the register in the specified address
 */
bool ISP_eraseByte(unsigned int addr)
{
    /* check address */
    if((addr < ISP_ADDR_START) || (addr > ISP_ADDR_END))
    {
        return false;
    }
    
    ISP_cmd(ENABLE);
    ISP_setAddress(addr);
    ISP_setCommand(ISP_command_erase);
    ISP_trig();
    sleep(1);
    ISP_idle();
    
    return true;
}

/*
 * @Prototype:void ISP_idle(void)
 * @Parameter:
 * @Ret-val:
 * @Note:Let ISP be idle
 */
void ISP_idle(void)
{
    ISP_cmd(DISABLE);
    ISP_setAddress(0x0000);
    ISP_setCommand(ISP_command_idle);
    ISP_DATA = 0xFF;
}

/*
 * @Prototype:unsigned char ISP_readByte(unsigned int addr)
 * @Parameter:(1)addr:operating address
 * @Ret-val:byte
 * @Note:read the value of the register in the specified address
 */
unsigned char ISP_readByte(unsigned int addr)
{
    unsigned char dat;
    
    ISP_cmd(ENABLE);
    ISP_setAddress(addr);
    ISP_setCommand(ISP_command_read);
    ISP_trig();
    sleep(1);
    dat = ISP_DATA;
    ISP_idle();
    
    return dat;
}

/*
 * @Prototype:void ISP_setAddress(unsigned int addr)
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
 * @Prototype:void ISP_setCommand(ISP_command cmd)
 * @Parameter:(1)addr:operating address
 * @Ret-val:
 * @Note:set command
 */
void ISP_setCommand(ISP_command cmd)
{
    ISP_CMD = cmd;
}

/*
 * @Prototype:void ISP_trig(void)
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
 * @Prototype:bool ISP_writeByte(unsigned int addr,byte dat)
 * @Parameter:(1)addr:operating address
 * @Ret-val:
 * @Note:write the value into the register in the specified address
 */
bool ISP_writeByte(unsigned int addr,byte dat)
{
    if((addr < ISP_ADDR_START) || (addr > ISP_ADDR_END))
    {
        return false;
    }
    else
    {
        ISP_cmd(ENABLE);
        ISP_setAddress(addr);
        ISP_setCommand(ISP_command_write);
        ISP_DATA = dat;
        ISP_trig();
        sleep(1);
        ISP_idle();
        
        return true;
    }
}

#endif
