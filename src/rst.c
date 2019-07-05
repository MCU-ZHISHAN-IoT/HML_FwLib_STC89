/*****************************************************************************/
/** 
 * \file        rst.c
 * \author      Jiabin Hsu | zsiothsu@zhishan-iot.tk
 * \brief       operations for reset module
 * \note        
 * \version     v1.1
 * \ingroup     RST
******************************************************************************/

#include "rst.h"

#ifdef __CONF_COMPILE_RST

/*****************************************************************************/
/** 
 * \author      Jiabin Hsu
 * \date        
 * \brief       software reset
 * \param[in]   area: the are you want to boot from
 * \return      none
 * \ingroup     RST
 * \remarks     
******************************************************************************/
void RST_reset(RST_bootarea area)
{
    SET_BIT_MASK(ISP_CONTR,ISPEN);
    CONFB(ISP_CONTR,BIT_NUM_SWBS,area);
    SET_BIT_MASK(ISP_CONTR,SWRST);
}

#endif
