/*****************************************************************************/
/** 
 * \file        isp.h
 * \author      Jiabin Hsu | zsiothsu@zhishan-iot.tk
 * \brief       operations for ISP module
 * \note        
 * \version     v1.3
 * \ingroup     ISP
******************************************************************************/

#ifndef ___HML_ISP_H___
#define ___HML_ISP_H___

/*****************************************************************************
 *                             header file                                   *
 *****************************************************************************/
#include "hml/util.h"

/*****************************************************************************
 *                                macro                                      *
 *****************************************************************************/

/**
 * \brief define ISP address
 */
#if (HML_MCU_MODEL == MCU_MODEL_STC89C51RC)  || \
    (HML_MCU_MODEL == MCU_MODEL_STC89LE51RC) || \
    (HML_MCU_MODEL == MCU_MODEL_STC89C52RC)  || \
    (HML_MCU_MODEL == MCU_MODEL_STC89LE52RC)
    #define ISP_ADDR_START 0x2000
    #define ISP_ADDR_END 0x2FFF
#else
    #define ISP_ADDR_END 0xF3FF
    #if (HML_MCU_MODEL == MCU_MODEL_STC89C54RDP)    || \
        (HML_MCU_MODEL == MCU_MODEL_STC89LE54RDP)
        #define ISP_ADDR_START 0x4000
    #elif (HML_MCU_MODEL == MCU_MODEL_STC89C58RDP)  || \
          (HML_MCU_MODEL == MCU_MODEL_STC89LE58RDP)
        #define ISP_ADDR_START 0x8000
    #elif (HML_MCU_MODEL == MCU_MODEL_STC89C510RDP) || \
          (HML_MCU_MODEL == MCU_MODEL_STC89LE510RDP)
        #define ISP_ADDR_START 0xA000
    #elif (HML_MCU_MODEL == MCU_MODEL_STC89C512RDP) || \
          (HML_MCU_MODEL == MCU_MODEL_STC89LE512RDP)
        #define ISP_ADDR_START 0xC000
    #elif (HML_MCU_MODEL == MCU_MODEL_STC89C514RDP) || \
          (HML_MCU_MODEL == MCU_MODEL_STC89LE514RDP)
        #define ISP_ADDR_START 0xE000
    #endif
#endif


/**
 * \brief the wait time of ISP command, which is related to clock frequency
 */
#if   (__CONF_FRE_CLKIN <=  1000000UL)
    #define ISP_WAITTIME 0x07
#elif (__CONF_FRE_CLKIN <=  2000000UL)
    #define ISP_WAITTIME 0x06
#elif (__CONF_FRE_CLKIN <=  3000000UL)
    #define ISP_WAITTIME 0x05
#elif (__CONF_FRE_CLKIN <=  6000000UL)
    #define ISP_WAITTIME 0x04
#elif (__CONF_FRE_CLKIN <= 12000000UL)
    #define ISP_WAITTIME 0x03
#elif (__CONF_FRE_CLKIN <= 20000000UL)
    #define ISP_WAITTIME 0x02
#elif (__CONF_FRE_CLKIN <= 24000000UL)
    #define ISP_WAITTIME 0x01
#else 
    #define ISP_WAITTIME 0x00
#endif

/*****************************************************************************
 *                           enumeration type                                *
 *****************************************************************************/

/**
 * \brief define ISP command
 */
typedef enum
{
    ISP_command_idle  = 0x00,
    ISP_command_read  = 0x01,
    ISP_command_write = 0x02,
    ISP_command_erase = 0x03
} ISP_command;

/*****************************************************************************
 *                          function declare                                 *
 *****************************************************************************/
void ISP_cmd(Action a);
void ISP_config(void);
bool ISP_eraseSector(uint16_t addr);
void ISP_idle(void);
byte ISP_readByte(uint16_t addr);
void ISP_setAddress(uint16_t addr);
void ISP_setCommand(ISP_command cmd);
void ISP_trig(void);
bool ISP_writeByte(uint16_t addr, byte dat);

#endif
