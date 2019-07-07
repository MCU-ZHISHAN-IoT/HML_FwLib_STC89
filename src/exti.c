/*****************************************************************************/
/** 
 * \file        exti.c
 * \author      Jiabin Hsu  | zsiothsu(at)zhishan-iot.tk
 * \author      Weilun Fong | wlf@zhishan-iot.tk
 * \brief       operation for on-chip EXTI module
 * \note        
 * \version     v1.1
 * \ingroup     EXTI
******************************************************************************/

#include "exti.h"
 
#ifdef __CONF_COMPILE_EXTI

/*****************************************************************************/
/** 
 * \author      Weilun Fong
 * \date        
 * \brief       configure function for EXTI module
 * \param[in]   exti: target EXTI module
 * \return      ec  : the pointer of configuration structure which includes all configuration information
 * \ingroup     EXTI
 * \remarks     
******************************************************************************/
void EXTI_config(PERIPH_EXTI exti,EXTI_configTypeDef *ec)
{
    EXTI_setMode(exti,ec->mode);
    EXTI_setPriority(exti,ec->priority);
}

/*****************************************************************************/
/** 
 * \author      Weilun Fong
 * \date        
 * \brief       disable or enable target EXTI module
 * \param[in]   exti: target EXTI module
 * \return      a   : expected status
 * \ingroup     EXTI
 * \remarks     
******************************************************************************/
void EXTI_cmd(PERIPH_EXTI exti,Action a)
{
    switch(exti)
    {
        case PERIPH_EXTI_0: EX0 = a; break;
        case PERIPH_EXTI_1: EX1 = a; break;
        case PERIPH_EXTI_2: EX2 = a; break;
        case PERIPH_EXTI_3: EX3 = a; break;
        default: break;
    }
}

/*****************************************************************************/
/** 
 * \author      Weilun Fong
 * \date        
 * \brief       configure work mode of target EXTI module
 * \param[in]   exti: target EXTI module
 * \return      mod : expected work mode
 * \ingroup     EXTI
 * \remarks     
******************************************************************************/
void EXTI_setMode(PERIPH_EXTI exti,EXTI_mode mod)
{
    switch(exti)
    {
        case PERIPH_EXTI_0: IT0 = mod; break;
        case PERIPH_EXTI_1: IT1 = mod; break;
        case PERIPH_EXTI_2: IT2 = mod; break;
        case PERIPH_EXTI_3: IT3 = mod; break;
        default: break;
    }
}

/*****************************************************************************/
/** 
 * \author      Weilun Fong
 * \date        
 * \brief       configure priority class of target EXTI module
 * \param[in]   exti: target EXTI module
 * \return      p   : target interrupt priority class
 * \ingroup     EXTI
 * \remarks     
******************************************************************************/
void EXTI_setPriority(PERIPH_EXTI exti,UTIL_interruptPriority p)
{
    switch(exti)
    {
        case PERIPH_EXTI_0:
        {
            PX0 = TESTB(p,0);
            CONFB(IPH,BIT_NUM_PX0H,TESTB(p,1));
        } break;
        case PERIPH_EXTI_1:
        {
            PX1 = TESTB(p,0);
            CONFB(IPH,BIT_NUM_PX1H,TESTB(p,1));
        } break;
        case PERIPH_EXTI_2:
        {
            PX2 = TESTB(p,0);
            CONFB(IPH,BIT_NUM_PX2H,TESTB(p,1));
        } break;
        case PERIPH_EXTI_3:
        {
            PX3 = TESTB(p,0);
            CONFB(IPH,BIT_NUM_PX3H,TESTB(p,1));
        } break;
        default: break;
    }
}

#endif
