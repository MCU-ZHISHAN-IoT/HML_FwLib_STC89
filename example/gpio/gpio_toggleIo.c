/*****************************************************************************/
/** 
 * \file       gpio_toggleIo.c
 * \author     Jiabin Hsu | zsiothsu@zhishan-iot.tk
 * \date       
 * \brief      eshow how to use HML_FwLib_STC89 to toggle GPIO bit
 * \note       
 * \version    v1.2
 * \ingroup    example
 * \remarks    test-board: TS51-V2.0; test-MCU: STC89C52RC
******************************************************************************/

/*****************************************************************************
 *                             header file                                   *
 *****************************************************************************/
#include "hml/hml.h"

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
    GPIO_resetBitValue(PERIPH_GPIO_4, PERIPH_GPIO_PIN_5);

    while (true)
    {
        sleep(500);
        GPIO_toggleBitValue(PERIPH_GPIO_4, PERIPH_GPIO_PIN_5);
    }
}
