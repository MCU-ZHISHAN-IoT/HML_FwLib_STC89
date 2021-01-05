/*****************************************************************************/
/** 
 * \file       rst_softwareReset.c
 * \author     Weilun Fong | wlf@zhishan-iot.tk
 * \date       
 * \brief      a example for software reset
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
 * \author      Weilun Fong
 * \date        
 * \brief       initial MCU
 * \param[in]   
 * \return      none
 * \ingroup     example
 * \remarks     
******************************************************************************/
void sys_init(void)
{
    EXTI_configTypeDef ec;
    
    ec.mode     = EXTI_mode_fallEdge;
    ec.priority = UTIL_interruptPriority_0;
    EXTI_config(PERIPH_EXTI_1, &ec);
    EXTI_cmd(PERIPH_EXTI_1, ENABLE);
    enableAllInterrupts();
}

/*****************************************************************************/
/** 
 * \author      Weilun Fong
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
    while (true)
    {
        GPIO_configBitValue(PERIPH_GPIO_1, PERIPH_GPIO_PIN_0, RESET);
        sleep(500);
        GPIO_configBitValue(PERIPH_GPIO_1, PERIPH_GPIO_PIN_0, SET);
        sleep(500);
    }
}

/*****************************************************************************/
/** 
 * \author      Weilun Fong
 * \date        
 * \brief       interrupt service function for EXTI1
 * \param[in]   
 * \return      none
 * \ingroup     example
 * \remarks     
******************************************************************************/
void exti1_isr(void) __interrupt IE1_VECTOR
{
    /* avoid shake */
    disableAllInterrupts();
    sleep(20);

    /* make sure the button connected to P33(INT1) */
    if (GPIO_getBitValue(PERIPH_GPIO_3, PERIPH_GPIO_PIN_3) == RESET)
    {
        RST_reset(RST_bootarea_ap);
    }
    else
    {
        enableAllInterrupts();    /* recover */
    }
}
