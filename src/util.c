/*****************************************************************************/
/** 
 * \file        util.c
 * \author      Weilun Fong | wlf@zhishan-iot.tk
 * \brief       public operations
 * \note        
 * \version     v1.1
 * \ingroup     UTIL
******************************************************************************/

#include "util.h"

#ifdef __CONF_COMPILE_UTIL

/*****************************************************************************/
/** 
 * \author      Weilun Fong
 * \date        
 * \brief       disable master switch of MCU interrupt
 * \param[in]   
 * \return      none
 * \ingroup     UTIL
 * \remarks     
******************************************************************************/
void disableAllInterrupts(void)
{
    EA = DISABLE;
}

/*****************************************************************************/
/** 
 * \author      Weilun Fong
 * \date        
 * \brief       enable master switch of MCU interrupt
 * \param[in]   
 * \return      none
 * \ingroup     UTIL
 * \remarks     
******************************************************************************/
void enableAllInterrupts(void)
{
    EA = ENABLE;
}

/*****************************************************************************/
/** 
 * \author      Weilun Fong
 * \date        
 * \brief       software delay according to MCU clock frequency
 * \param[in]   t: how many one ms you want to delay
 * \return      none
 * \ingroup     UTIL
 * \remarks     
******************************************************************************/
void sleep(unsigned int t)
{
    u8 i = 0;
    
    #if ( MCU_FRE_CLK == 11059200L )

        while(t--)
        {
            i = 110;
            while(i--);
        }

    #elif ( MCU_FRE_CLK == 12000000L )

        while(t--)
        {
            i = 120;
            while(i--);
        }
        
    #else

    //TODO

    #endif
}

#endif
