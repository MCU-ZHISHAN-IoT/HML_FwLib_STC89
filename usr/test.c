/*****************************************************************************/
/** 
 * \file       test.c
 * \author     Weilun Fong | wlf@zhishan-iot.tk
 * \date       
 * \brief      a demo file
 * \note       
 * \version    v1.2
 * \ingroup    generic
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
    UART_configTypeDef uc;

    uc.baudrate          = 9600;
    uc.baudGenerator     = PERIPH_TIM_2;
    uc.interruptState    = DISABLE;
    uc.interruptPriority = UTIL_interruptPriority_0;
    uc.mode              = UART_mode_1;
    uc.multiBaudrate     = DISABLE;
    uc.receiveState      = ENABLE;

    UART_config(&uc);
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
        /* send per 500ms */
        sleep(500);
        UART_sendString("Hello,world\r\n");
    }
}
