/*****************************************************************************/
/** 
 * \file       tim2_toggleIo.c
 * \author     Jiabin Hsu | zhongliguo@zhishan-iot.tk
 * \date       
 * \brief      a example which shows how to toggle state of specified pin periodic
 *             via timers' interrupt
 * \note       
 * \version    v1.3
 * \ingroup    example
 * \remarks    test-board: TS51-V2.0; test-MCU: STC89C52RC
******************************************************************************/

/*****************************************************************************
 *                             header file                                   *
 *****************************************************************************/
#include "hml/hml.h"

/*****************************************************************************/
/** 
 * \author      Jiabin Hsu
 * \date        
 * \brief       initial MCU
 * \param[in]   
 * \return      none
 * \ingroup     example
 * \remarks     
******************************************************************************/
void sys_init(void)
{
    TIM2_configTypeDef tc;

    tc.function          = TIM2_function_tim;
    tc.interruptState    = ENABLE;
    tc.interruptPriority = UTIL_interruptPriority_0;
    tc.mode              = TIM2_mode_0;
    tc.value             = TIM2_calculateValue(50000);

    TIM2_config(&tc);
    TIM2_cmd(ENABLE);
    enableAllInterrupts();
}

/*****************************************************************************/
/** 
 * \author      Jiabin Hsu
 * \date        
 * \brief       main function
 * \param[in]   
 * \return      none
 * \ingroup     example
 * \remarks     
******************************************************************************/
void main(void)
{
    sys_init();
    while(true);
}

/*****************************************************************************/
/** 
 * \author      Jiabin Hsu
 * \date        
 * \brief       interrupt service function for TIM2
 * \param[in]   
 * \return      none
 * \ingroup     example
 * \remarks     
******************************************************************************/
void tim2_isr(void) __interrupt TF2_VECTOR
{
    static uint8_t i = 0;
    TIM2_clearFlag();

    /* per 500ms */
    i++;
    if (i == 10)
    {
        GPIO_toggleBitValue(PERIPH_GPIO_1, PERIPH_GPIO_PIN_2);
        i = 0;
    }
}
