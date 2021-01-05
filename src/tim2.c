/*****************************************************************************/
/** 
 * \file        tim2.c
 * \author      Jiabin Hsu | zsiothsu@zhishan-iot.tk
 * \brief       operations for timer-2
 * \note        
 * \version     v1.3
 * \ingroup     TIM2
******************************************************************************/

#include "hml/tim2.h"

#ifdef COMPILE_TIM2

/*****************************************************************************/
/** 
 * \author      Jiabin Hsu
 * \date        2018/10/08
 * \brief       calculate initial value for THx/TLx register
 * \param[in]   t: expected timing cycle(unit: us)
 * \return      initial value of timer-2 counter register(if return 0x0000, it 
 *              means that the time has over the limit)
 * \ingroup     TIM2
 * \remarks     
******************************************************************************/
uint16_t TIM2_calculateValue(uint16_t t)
{
    if ((t*(MCU_FRE_CLK/1000000)/MCU_PRESCALER) >= TIM2_MAXTICK)
    {
        return 0;
    }
    else
    {
        return (TIM2_MAXTICK + 1 - (t*(MCU_FRE_CLK/1000000)/MCU_PRESCALER));
    }
}

/*****************************************************************************/
/** 
 * \author      Jiabin Hsu
 * \date        2018/10/08
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
 * \date        2018/10/08
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
 * \date        2018/10/08
 * \brief       configure timer-2
 * \param[in]   tc: pointer of the configuration struct which includes all parameters
 * \return      none
 * \ingroup     TIM2
 * \remarks     
******************************************************************************/
void TIM2_config(TIM2_configTypeDef *t2c)
{
    TIM2_setFunction(t2c->function);
    TIM2_setMode(t2c->mode);
    TIM2_setReloadValue(t2c->reloadValue);
    TIM2_setValue(t2c->value);
    TIM2_INT_cmd(t2c->interruptState);
    TIM2_INT_setPriority(t2c->interruptPriority);
}

/*****************************************************************************/
/** 
 * \author      Weilun Fong
 * \date        2019/09/22
 * \brief       get capture result of timer-2
 * \param[in]   none
 * \return      16-bit result form RCAP2H/RCAP2L
 * \ingroup     TIM2
 * \remarks     this function only can be called validly under capture mode
******************************************************************************/
uint16_t TIM2_getCaptureValue(void)
{
    return (uint16_t)((RCAP2H << 0x8) | RCAP2L);
}

/*****************************************************************************/
/** 
 * \author      Jiabin Hsu
 * \date        2018/10/08
 * \brief       get value inside counter register of timer-2
 * \param[in]   none
 * \return      value inside counter register of timer-2
 * \ingroup     TIM2
 * \remarks     
******************************************************************************/
uint16_t TIM2_getValue(void)
{
    return (uint16_t)((TH2 << 0x8) | TL2);
}

/*****************************************************************************/
/** 
 * \author      Jiabin Hsu
 * \date        2019/10/08
 * \brief       get external flag from EXF2 which indicte state of pin T2EX
 * \param[in]   none
 * \return      external flag
 * \ingroup     TIM2
 * \remarks     
******************************************************************************/
bool TIM2_isExternalEvent(void)
{
    return (bool)T2EX;
}

/*****************************************************************************/
/** 
 * \author      Jiabin Hsu
 * \date        2018/10/08
 * \brief       check whether counter of target timer is overflow or not
 * \param[in]   none
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
 * \date        2018/10/08
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
 * \date        2018/10/08
 * \brief       configure function(timer or counter) of timer-2
 * \param[in]   mode: expected work mode
 * \return      none
 * \ingroup     TIM2
 * \remarks     
******************************************************************************/
void TIM2_setMode(TIM2_mode mode)
{
    T2CON = (T2CON & 0xCE) | mode;
}

/*****************************************************************************/
/** 
 * \author      Weilun Fong
 * \date        2019/09/22
 * \brief       set 16-bit reload value of timer-2
 * \param[in]   val: expected 16-bit value
 * \return      none
 * \ingroup     TIM2
 * \remarks     the parameter value will be written into register RCAP2H/RCAP2L
******************************************************************************/
void TIM2_setReloadValue(uint16_t val)
{
    RCAP2H = (byte)(val >> 0x8);
    RCAP2L = val;
}

/*****************************************************************************/
/** 
 * \author      Jiabin Hsu
 * \date        2018/10/08
 * \brief       set value of THx/TLx register
 * \param[in]   val: expected value(range: 0x0000~0xFFFF)
 * \return      none
 * \ingroup     TIM2
 * \remarks     
******************************************************************************/
void TIM2_setValue(uint16_t val)
{
    TH2 = (val >> 0x8);
    TL2 = val;
}

/*****************************************************************************/
/** 
 * \author      Weilun Fong
 * \date        2019/09/21
 * \brief       enable or disable baud clock source
 * \param[in]   t: UART receive or transmit clock
 * \param[in]   a: expected action
 * \return      none
 * \ingroup     TIM2
 * \remarks     this function is usually used to take place baud clock source
                of UART from timer-1
******************************************************************************/
void TIM2_BAUD_cmd(TIM2_baudClock t, Action a)
{
    if (t & TIM2_baudClock_receive)
    {
        RCLK = (FunctionalState)a;
    }
    if (t & TIM2_baudClock_transmit)
    {
        TCLK = (FunctionalState)a;
    }
}

/*****************************************************************************/
/** 
 * \author      Jiabin Hsu
 * \date        2018/10/08
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
 * \date        2018/10/08
 * \brief       configure interrupt priority of timer-2
 * \param[in]   p: expected interrupt priority
 * \return      none
 * \ingroup     TIM2
 * \remarks     
******************************************************************************/
void TIM2_INT_setPriority(UTIL_interruptPriority p)
{
    PT2 = TESTB(p,1);
    CONFB(IPH, BIT_NUM_PT2H, TESTB(p, 1));
}

/*****************************************************************************/
/** 
 * \author      Jiabin Hsu
 * \date        2018/10/08
 * \brief       enable or disable T2EX function of timer-2
 * \param[in]   a: expected action
 * \return      none
 * \ingroup     TIM2
 * \remarks     timer-2 external enable. When set, allows a capture or reload 
 *              to occur as a result of a negative transition on T2EX if timer-2
 *              is not being used to clock the serial port. EXEN2 = 0 causes 
 *              timer-2 to ignore events at T2EX.
******************************************************************************/
void TIM2_T2EX_cmd(Action a)
{
    EXEN2 = a;
}

#else
    #warning Nothing to be done... User should remove .c file which is disabled by compile control macro from current directory.
#endif
