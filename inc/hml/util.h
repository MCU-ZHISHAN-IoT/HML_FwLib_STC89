/*****************************************************************************/
/** 
 * \file        util.h
 * \author      Weilun Fong | wlf@zhishan-iot.tk
 * \brief       public operations
 * \note        
 * \version     v1.2
 * \ingroup     UTIL
******************************************************************************/

#ifndef ___HML_UTIL_H___
#define ___HML_UTIL_H___

/*****************************************************************************
 *                             header file                                   *
 *****************************************************************************/
#include "hml/stc89.h"
#include "hml/conf.h"
#include "hml/macro.h"
#include "hml/types.h"

/*****************************************************************************
 *                           enumeration type                                *
 *****************************************************************************/
/**
 *\brief: mark interrupt priority, lager number means higher priority
 */
typedef enum
{
    UTIL_interruptPriority_0 = 0x00,
    UTIL_interruptPriority_1 = 0x01,
    UTIL_interruptPriority_2 = 0x02,
    UTIL_interruptPriority_3 = 0x03,
} UTIL_interruptPriority;

/*****************************************************************************
 *                          function declare                                 *
 *****************************************************************************/
void disableAllInterrupts(void);
void enableAllInterrupts(void);
void sleep(uint16_t t);

#endif
