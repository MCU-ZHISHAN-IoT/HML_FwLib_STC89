/*****************************************************************************/
/** 
 * \file       exti_interruptPriority.c
 * \author     Amy Chung | zhongliguo@zhishan-iot.tk
 * \date       
 * \brief      example for interrupt priority
 * \note       a example which shows how to use HML_FwLib_STC89 to configure 
 *             interrupt priority of extern interrupts and timers
 * \version    v1.3
 * \ingroup    example
 * \remarks    test-board: ZS5110; test-MCU: STC89C52RC
******************************************************************************/

/**
 *\extra-note:
 * (1) This file configures TIM0 priority as lowest priority(INTR_priority_0), 
 *     EXTI0's priority is lower priority(INTR_priority_1), and EXTI1 's priority 
 *     is highest(INTR_priority_1). At the same time, each interrupt source 
 *     controls a blink LED with different gap time, higher priority means shorter 
 *     time(EXTI0: 250ms; EXTI1: 150ms; TIM0: 500ms;).
 * (2) On board ZS51-V1.0, pin INT0 and INT1 are connected to buttons so we can 
 *     use them to wakeup interrupt. And a 8-bit LED group controlled by GPIO2.
 */

/*****************************************************************************
 *                             header file                                   *
 *****************************************************************************/
#include "hml/hml.h"

/*****************************************************************************
 *                                macro                                      *
 *****************************************************************************/

/**
 * \brief LED define
 */
#define PERIPH_LED           PERIPH_GPIO_2
#define PERIPH_LED_TIM0      PERIPH_GPIO_PIN_0   /* indicator LED for TIM0 */
#define PERIPH_LED_EXTI0     PERIPH_GPIO_PIN_1   /* indicator LED for EXTI0 */
#define PERIPH_LED_EXTI1     PERIPH_GPIO_PIN_2   /* indicator LED for EXTI1 */

/**
 * \brief key define
 */
#define PERIPH_KEY           PERIPH_GPIO_3
#define PERIPH_KEY_EXTI0     PERIPH_GPIO_PIN_2   /* key connected to EXTI1 */
#define PERIPH_KEY_EXTI1     PERIPH_GPIO_PIN_3

/*****************************************************************************/
/** 
 * \author      Amy Chung
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
    TIM_configTypeDef tc;

    tc.function          = TIM_function_tim;
    tc.interruptState    = ENABLE;
    tc.interruptPriority = UTIL_interruptPriority_0;
    tc.mode              = TIM_mode_1;
    tc.value             = TIM_calculateValue(50000, TIM_mode_1);

    TIM_config(PERIPH_TIM_0, &tc);
    TIM_cmd(PERIPH_TIM_0, ENABLE);

    ec.mode     = EXTI_mode_fallEdge;
    ec.priority = UTIL_interruptPriority_1;
    EXTI_config(PERIPH_EXTI_0, &ec);
    EXTI_cmd(PERIPH_EXTI_0, ENABLE);

    ec.priority = UTIL_interruptPriority_2;
    EXTI_config(PERIPH_EXTI_1, &ec);
    EXTI_cmd(PERIPH_EXTI_1, ENABLE);

    enableAllInterrupts();
    GPIO_configPortValue(PERIPH_LED, 0xFF);
}

/*****************************************************************************/
/** 
 * \author      Amy Chung
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
 * \brief       interrupt service function for TIM0
 * \param[in]   
 * \return      none
 * \ingroup     example
 * \remarks     
******************************************************************************/
void tim0_isr(void) __interrupt TF0_VECTOR
{
    static uint8_t cnt = 0;

    /* per 500ms */
    cnt++;
    if (cnt == 10)
    {
        GPIO_toggleBitValue(PERIPH_LED, PERIPH_LED_TIM0);
        cnt = 0;
    }
}

/*****************************************************************************/
/** 
 * \author      Amy Chung
 * \date        
 * \brief       interrupt service function for EXTI0
 * \param[in]   
 * \return      none
 * \ingroup     example
 * \remarks     
******************************************************************************/
void exti0_isr(void) __interrupt IE0_VECTOR
{
    uint8_t i = 10;

    /* avoid shake */
    EXTI_cmd(PERIPH_EXTI_0, DISABLE);
    sleep(20);

    /* make sure the button pressed by P32(INT0) */
    if (GPIO_getBitValue(PERIPH_KEY, PERIPH_KEY_EXTI0) == RESET)
    {
        GPIO_configPortValue(PERIPH_LED, 0xFF);
        while (i--)
        {
            GPIO_toggleBitValue(PERIPH_LED, PERIPH_LED_EXTI0);
            sleep(250);
        }
    }

    /* recover */
    GPIO_configPortValue(PERIPH_LED, 0xFF);
    EXTI_cmd(PERIPH_EXTI_0, ENABLE);
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
    uint8_t j = 10;

    /* avoid shake */
    EXTI_cmd(PERIPH_EXTI_1, DISABLE);
    sleep(20);

    /* make sure the button pressed by P33(INT1) */
    if (GPIO_getBitValue(PERIPH_KEY, PERIPH_KEY_EXTI1) == RESET)
    {
        GPIO_configPortValue(PERIPH_LED, 0xFF);
        while (j--)
        {
            GPIO_toggleBitValue(PERIPH_LED, PERIPH_LED_EXTI1);
            sleep(150);
        }
    }

    /* recover */
    GPIO_configPortValue(PERIPH_LED, 0xFF);
    EXTI_cmd(PERIPH_EXTI_1, ENABLE);
}

