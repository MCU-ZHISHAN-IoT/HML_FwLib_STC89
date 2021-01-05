/*****************************************************************************/
/** 
 * \file       wdt_feedDog.c
 * \author     Jiabin Hsu | zsiothsu@zhishan-iot.tk
 * \date       
 * \brief      a example of watchdog module
 * \note       
 * \version    v1.3
 * \ingroup    example
 * \remarks    test-board: TS51-V2.0; test-MCU: STC89C52RC;
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
    UART_configTypeDef uc;

    uc.baudrate          = 9600;
    uc.baudGenerator     = PERIPH_TIM_1;
    uc.interruptState    = ENABLE;
    uc.interruptPriority = UTIL_interruptPriority_0;
    uc.mode              = UART_mode_1;
    uc.multiBaudrate     = DISABLE;
    uc.receiveState      = ENABLE;

    UART_config(&uc);
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
    UART_sendString("MCU boot");
    WDT_setPrescale(WDT_prescale_32);
    WDT_cmd(ENABLE);

    while (true)
    {
        /* feed watchdog per 500ms */
        sleep(500);
        WDT_feed();
        UART_sendString("root@localboard:WatchDog has been feed\r\n");
    }
}
