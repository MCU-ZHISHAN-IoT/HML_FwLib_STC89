/*****************************************************************************/
/** 
 * \file       exti_toggleIo.c
 * \author     Weilun Fong | wlf@zhishan-iot.tk
 * \date       
 * \brief      example for interrupt priority
 * \note       a example which shows how to use HML_FwLib_STC89 to toggle P12 
 *             state when EXTI is trigged
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
    
    GPIO_configPortValue(PERIPH_GPIO_1, 0xFF);
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
    while(true);
}

/*****************************************************************************/
/** 
 * \author      Amy Chung
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

    /* make sure the button pressed by P33(INT1) */
    if (GPIO_getBitValue(PERIPH_GPIO_3, PERIPH_GPIO_PIN_3) == RESET)
    {
        GPIO_toggleBitValue(PERIPH_GPIO_1, PERIPH_GPIO_PIN_2);
    }

    enableAllInterrupts();   /* recover */
}
