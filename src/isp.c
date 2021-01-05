/*****************************************************************************/
/** 
 * \file        isp.c
 * \author      Jiabin Hsu | zsiothsu@zhishan-iot.tk
 * \brief       operations for ISP module
 * \note        
 * \version     v1.3
 * \ingroup     ISP
******************************************************************************/

#include "hml/isp.h"

#ifdef HAVE_ISP

#ifdef COMPILE_ISP

/*****************************************************************************/
/** 
 * \author      Jiabin Hsu
 * \date        2020/11/01
 * \brief       enable or disable ISP module
 * \param[in]   a : expected action
 * \return      none
 * \ingroup     ISP
 * \remarks     
******************************************************************************/
void ISP_cmd(Action a)
{
    CONFB(ISP_CONTR, BIT_NUM_ISPEN, a);
}

/*****************************************************************************/
/** 
 * \author      Jiabin Hsu
 * \date        2020/11/01
 * \brief       set the wait time of cpu after isp model is triggered
 * \param[in]   none
 * \return      none
 * \ingroup     ISP
 * \remarks     
******************************************************************************/
void ISP_config(void)
{
    ISP_CONTR = (ISP_CONTR & 0xF8) | ISP_WAITTIME;
}

/*****************************************************************************/
/** 
 * \author      Jiabin Hsu
 * \date        2020/10/29
 * \brief       erase the sector where given address is located
 * \param[in]   addr: address of target area
 * \return      complete to erase(true) or failed to execute operation(false)
 * \ingroup     ISP
 * \remarks     if some data in the sector needs to be retained, it needs to be
 *              read to RAM first, and write to EEPROM after erase is completed
******************************************************************************/
bool ISP_eraseSector(uint16_t addr)
{
    /* check address */
    if ((addr < ISP_ADDR_START) || (addr > ISP_ADDR_END))
    {
        return false;
    }

    ISP_setAddress(addr);
    ISP_setCommand(ISP_command_erase);
    ISP_trig();

    return true;
}

/*****************************************************************************/
/** 
 * \author      Jiabin Hsu
 * \date        2020/10/29
 * \brief       make ISP module be in idle mode
 * \param[in]   none
 * \return      none
 * \ingroup     ISP
 * \remarks     
******************************************************************************/
void ISP_idle(void)
{
    ISP_cmd(DISABLE);
    ISP_setAddress(0x0000);
    ISP_setCommand(ISP_command_idle);
    ISP_DATA = 0xFF;
}

/*****************************************************************************/
/** 
 * \author      Jiabin Hsu
 * \date        2020/10/29
 * \brief       read one byte of data form specified ISP area
 * \param[in]   addr: address of target area
 * \return      access result
 * \ingroup     ISP
 * \remarks     
******************************************************************************/
byte ISP_readByte(uint16_t addr)
{
    byte dat = 0x00;

    ISP_setAddress(addr);
    ISP_setCommand(ISP_command_read);
    ISP_trig();
    dat = ISP_DATA;

    return dat;
}

/*****************************************************************************/
/** 
 * \author      Jiabin Hsu
 * \date        2020/10/29
 * \brief       configure value of ISP address register for access
 * \param[in]   addr: address of target area
 * \return      none
 * \ingroup     ISP
 * \remarks     
******************************************************************************/
void ISP_setAddress(uint16_t addr)
{
    ISP_ADDRL = addr;
    ISP_ADDRH = addr >> 0x8;
}

/*****************************************************************************/
/** 
 * \author      Jiabin Hsu
 * \date        2020/10/29
 * \brief       send command to ISP module by writing ISP_CMD register
 * \param[in]   cmd: ISP command type
 * \return      none
 * \ingroup     ISP
 * \remarks     
******************************************************************************/
void ISP_setCommand(ISP_command cmd)
{
    ISP_CMD = cmd;
}

/*****************************************************************************/
/** 
 * \author      Jiabin Hsu
 * \date        2020/10/29
 * \brief       trigger instruction
 * \param[in]   none
 * \return      none
 * \ingroup     ISP
 * \remarks     
******************************************************************************/
void ISP_trig(void)
{
    ISP_TRIG = 0x46;
    ISP_TRIG = 0xB9;
}

/*****************************************************************************/
/** 
 * \author      Jiabin Hsu
 * \date        2020/10/29
 * \brief       write data to specified ISP area
 * \param[in]   addr: address of target ISP area
 * \param[in]   dat : one byte of data
 * \return      write successfully(true) or not(false)
 * \ingroup     ISP
 * \remarks     
******************************************************************************/
bool ISP_writeByte(uint16_t addr, byte dat)
{
    if ((addr < ISP_ADDR_START) || (addr > ISP_ADDR_END))
    {
        return false;
    }
    else
    {
        ISP_setAddress(addr);
        ISP_setCommand(ISP_command_write);
        ISP_DATA = dat;
        ISP_trig();

        return true;
    }
}

#else
    #warning Nothing to be done... User should remove .c file which is disabled by compile control macro from current directory.
#endif

#endif
