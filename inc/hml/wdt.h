/*****************************************************************************/
/** 
 * \file        wdt.h
 * \author      Jiabin Hsu | zsiothsu@zhishan-iot.tk
 * \brief       operations for watchdog module
 * \note        
 * \version     v1.3
 * \ingroup     WDT
******************************************************************************/

#ifndef ___HML_WDT_H___
#define ___HML_WDT_H___

/*****************************************************************************
 *                             header file                                   *
 *****************************************************************************/
#include "hml/stc89.h"
#include "hml/macro.h"
#include "hml/types.h"

/*****************************************************************************
 *                           enumeration type                                *
 *****************************************************************************/

/**
 * \brief mark prescale factor
 */
typedef enum
{
    WDT_prescale_2   = 0x00,
    WDT_prescale_4   = 0x01,
    WDT_prescale_8   = 0x02,
    WDT_prescale_16  = 0x03,
    WDT_prescale_32  = 0x04,
    WDT_prescale_64  = 0x05,
    WDT_prescale_128 = 0x06,
    WDT_prescale_256 = 0x07
} WDT_prescale;

/*****************************************************************************
 *                          function declare                                 *
 *****************************************************************************/
void WDT_cmd(Action a);
void WDT_cmd_idleCount(Action a);
void WDT_feed(void);
void WDT_setPrescale(WDT_prescale pre);

#endif
