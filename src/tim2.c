/*****************************************************************************/
/** 
 * \file        tim2.c
 * \author      Jiabin Hsu | zsiothsu@zhishan-iot.tk
 * \brief       operations for timer-2
 * \note        
 * \version     v1.1
 * \ingroup     TIM2
******************************************************************************/

#include "tim2.h"

#ifdef __CONF_COMPILE_TIM2

/*****************************************************************************/
/** 
 * \author      Jiabin Hsu
 * \date        
 * \brief       calculate initial value for THx/TLx register
 * \param[in]   t: expected timing cycle(unit: us)
 * \return      initial value of timer-2 counter register(if return 0x0000, it 
 *              means that the time has over the limit)
 * \ingroup     TIM2
 * \remarks     
******************************************************************************/
unsigned int TIM2_calculateValue(unsigned int t)
{
    if((t*12)/(MCU_FRE_CLK/1000000) >= TIM2_MAXTICK )
    {
        return 0;
    }
    else
    {
        return (TIM2_MAXTICK + 1 - ((t*12) / (MCU_FRE_CLK / 1000000)));
    }
}

/*****************************************************************************/
/** 
 * \author      Jiabin Hsu
 * \date        
 * \brief       clear interrupt flag of TIM2
 * \param[in]   
 * \return      none
 * \ingroup     TIM2
 * \remarks     
******************************************************************************/
void TIM2_clearFlag(void)
{
    TF2 = RESET;
}

/*****************************************************************************/
/** 
 * \author      Jiabin Hsu
 * \date        
 * \brief       enable or disable timer-2
 * \param[in]   a: expected state
 * \return      none
 * \ingroup     TIM2
 * \remarks     
******************************************************************************/
void TIM2_cmd(Action a)
{
    TR2 = a;
}

/*****************************************************************************/
/** 
 * \author      Jiabin Hsu
 * \date        
 * \brief       configure timer-2
 * \param[in]   tc: pointer of the configuration struct which includes all parameters
 * \return      none
 * \ingroup     TIM2
 * \remarks     
******************************************************************************/
void TIM2_config(TIM2_configTypeDef *tc)
{
    TIM2_setFunction(tc->function);
    TIM2_setMode(tc->mode);
    TIM2_setValue(tc->value);
    TIM2_INT_cmd(tc->interruptState);
    TIM2_INT_setPriority(tc->interruptPriority);
}

/*****************************************************************************/
/** 
 * \author      Jiabin Hsu
 * \date        
 * \brief       get value inside counter register of timer-2
 * \param[in]   
 * \return      value inside counter register of timer-2
 * \ingroup     TIM2
 * \remarks     
******************************************************************************/
unsigned int TIM2_getValue(void)
{
    return (unsigned int)((TH2 << 0x8) | TL2);
}

/*****************************************************************************/
/** 
 * \author      Jiabin Hsu
 * \date        
 * \brief       check whether counter of target timer is overflow or not
 * \param[in]   
 * \return      true(overflow) or false. This function will return false when 
 *              it gets a invalid parameter
 * \ingroup     TIM2
 * \remarks     
******************************************************************************/
bool TIM2_isOverflow(void)
{
    return (bool)(TF2);
}

/*****************************************************************************/
/** 
 * \author      Jiabin Hsu
 * \date        
 * \brief       configure function(timer or counter) of timer-2
 * \param[in]   f: expected function
 * \return      none
 * \ingroup     TIM2
 * \remarks     
******************************************************************************/
void TIM2_setFunction(TIM2_function f)
{
    T2CON = (T2CON & 0XCF) | f;
}

/*****************************************************************************/
/** 
 * \author      Jiabin Hsu
 * \date        
 * \brief       configure function(timer or counter) of timer-2
 * \param[in]   f: expected function
 * \return      none
 * \ingroup     TIM2
 * \remarks     
******************************************************************************/
void TIM2_setMode(TIM2_mode m)
{
    T2CON = (T2CON & 0xCE) | m;
}

/*****************************************************************************/
/** 
 * \author      Jiabin Hsu
 * \date        
 * \brief       set value of THx/TLx register
 * \param[in]   val: expected value(range: 0x0000~0xFFFF)
 * \return      none
 * \ingroup     TIM2
 * \remarks     
******************************************************************************/
void TIM2_setValue(unsigned int val)
{
    TH2 = (val >> 0x8);
    TL2 = val;
}

/*****************************************************************************/
/** 
 * \author      Jiabin Hsu
 * \date        
 * \brief       disable or enable interrupt function of timer-2
 * \param[in]   a: expected state
 * \return      none
 * \ingroup     TIM2
 * \remarks     
******************************************************************************/
void TIM2_INT_cmd(Action a)
{
    ET2 = a;
}

/*****************************************************************************/
/** 
 * \author      Jiabin Hsu
 * \date        
 * \brief       configure interrupt priority of timer-2
 * \param[in]   p: expected interrupt priority
 * \return      none
 * \ingroup     TIM2
 * \remarks     
******************************************************************************/
void TIM2_INT_setPriority(INTR_priority p)
{
    PT2 = TESTB(p,1);
    CONFB(IPH,BIT_NUM_PT2H,TESTB(p,1));
}

/*****************************************************************************/
/** 
 * \author      Jiabin Hsu
 * \date        
 * \brief       enable or disable T2EX function of timer-2
 * \param[in]   p: expected interrupt priority
 * \return      none
 * \ingroup     TIM2
 * \remarks     determine whether the falling jump makes capture or reload or not
******************************************************************************/
void TIM2_INT_T2EX_cmd(Action a)
{
    EXEN2 = a;
}

#endif
