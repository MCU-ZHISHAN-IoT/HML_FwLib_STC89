/*****************************************************************************/
/** 
 * \file        rst.h
 * \author      Jiabin Hsu | zsiothsu@zhishan-iot.tk
 * \brief       operations for reset module
 * \note        
 * \version     v1.2
 * \ingroup     RST
******************************************************************************/

#ifndef ___HML_RST_H___
#define ___HML_RST_H___

/*****************************************************************************
 *                             header file                                   *
 *****************************************************************************/
#include "hml/stc89.h"
#include "hml/macro.h"

/*****************************************************************************
 *                           enumeration type                                *
 *****************************************************************************/

/**
 * \brief mark boot area
 */
typedef enum
{
    RST_bootarea_ap  = 0x0,  /* user application area */
    RST_bootarea_isp = 0x1   /* ISP area */
} RST_bootarea;

/*****************************************************************************
 *                          function declare                                 *
 *****************************************************************************/
void RST_reset(RST_bootarea area);

#endif
