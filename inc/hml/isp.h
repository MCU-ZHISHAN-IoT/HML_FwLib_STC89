/*****************************************************************************/
/** 
 * \file        isp.h
 * \author      Jiabin Hsu | zsiothsu@zhishan-iot.tk
 * \brief       operations for ISP module
 * \note        
 * \version     v1.1
 * \ingroup     ISP
******************************************************************************/

#ifndef ___ISP_H___
#define ___ISP_H___

/*****************************************************************************
 *                             header file                                   *
 *****************************************************************************/
#include <stdbool.h>
/*****************************************************************************/
#include "util.h"

/*****************************************************************************
 *                                macro                                      *
 *****************************************************************************/

/**
 *\brief: define ISP address
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

/*****************************************************************************
 *                           enumeration type                                *
 *****************************************************************************/

/**
 *\brief: define ISP command
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
bool ISP_eraseByte(uint16_t addr);
void ISP_idle(void);
byte ISP_readByte(uint16_t addr);
void ISP_setAddress(uint16_t addr);
void ISP_setCommand(ISP_command cmd);
void ISP_trig(void);
bool ISP_writeByte(uint16_t addr,byte dat);

#endif
