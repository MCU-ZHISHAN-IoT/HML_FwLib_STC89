/*****************************************************************************/
/** 
 * \file        wdt.c
 * \author      Jiabin Hsu | zsiothsu@zhishan-iot.tk
 * \brief       operations for watchdog
 * \note        
 * \version     v1.3
 * \ingroup     WDT
******************************************************************************/

#include "hml/wdt.h"

#ifdef COMPILE_WDT

/*****************************************************************************/
/** 
 * \author      Jiabin Hsu
 * \date        
 * \brief       enable or disable watchdog
 * \param[in]   a: expected state
 * \return      none
 * \ingroup     WDT
 * \remarks     
******************************************************************************/
void WDT_cmd(Action a)
{
    CONFB(WDT_CONTR, BIT_NUM_EN_WDT, a);
}

/*****************************************************************************/
/** 
 * \author      Jiabin Hsu
 * \date        
 * \brief       enable or disable watchdog under idle mode
 * \param[in]   a: expected state
 * \return      none
 * \ingroup     WDT
 * \remarks     
******************************************************************************/
void WDT_cmd_idleCount(Action a)
{
    CONFB(WDT_CONTR, BIT_NUM_IDLE_WDT, a);
}

/*****************************************************************************/
/** 
 * \author      Jiabin Hsu
 * \date        
 * \brief       feeds watchdog
 * \param[in]   
 * \return      none
 * \ingroup     WDT
 * \remarks     
******************************************************************************/
void WDT_feed(void)
{
    SET_BIT_MASK(WDT_CONTR, CLR_WDT);
}

/*****************************************************************************/
/** 
 * \author      Jiabin Hsu
 * \date        
 * \brief       set prescale
 * \param[in]   pre: prescale factor
 * \return      none
 * \ingroup     WDT
 * \remarks     
******************************************************************************/
void WDT_setPrescale(WDT_prescale pre)
{
    WDT_CONTR = (WDT_CONTR & 0xF8) | pre;
}

#else
    #warning Nothing to be done... User should remove .c file which is disabled by compile control macro from current directory.
#endif
