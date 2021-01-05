/*****************************************************************************/
/** 
 * \file       tim_toggleIo.c
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
    TIM_configTypeDef tc;

    tc.function          = TIM_function_tim;
    tc.interruptState    = ENABLE;
    tc.interruptPriority = UTIL_interruptPriority_0;
    tc.mode              = TIM_mode_1;
    tc.value             = TIM_calculateValue(50000, TIM_mode_1);

    TIM_config(PERIPH_TIM_0,&tc);
    TIM_cmd(PERIPH_TIM_0, ENABLE);
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
 * \brief       interrupt service function for TIM0
 * \param[in]   
 * \return      none
 * \ingroup     example
 * \remarks     
******************************************************************************/
void tim0_isr(void) __interrupt TF0_VECTOR
{
    static uint8_t i = 0;

    /* per 500ms */
    i++;
    if (i == 10)
    {
        GPIO_toggleBitValue(PERIPH_GPIO_1, PERIPH_GPIO_PIN_2);
        i = 0;
    }
}
