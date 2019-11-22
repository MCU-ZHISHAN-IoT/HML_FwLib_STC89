/*****************************************************************************/
/** 
 * \file        rst.c
 * \author      Jiabin Hsu | zsiothsu@zhishan-iot.tk
 * \brief       operations for reset module
 * \note        
 * \version     v1.2
 * \ingroup     RST
******************************************************************************/

#include "hml/rst.h"

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

#else
    #warning Nothing to be done... User should remove .c file which is disabled by compile control macro from current directory.
#endif
