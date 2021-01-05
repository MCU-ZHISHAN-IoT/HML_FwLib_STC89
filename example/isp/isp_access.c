/*****************************************************************************/
/** 
 * \file       isp_access.c
 * \author     Amy Chung | zhongliguo@zhishan-iot.tk
 * \date       
 * \brief      show how to use HML_FwLib_STC89 to execute access operation on ISP
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
    UART_configTypeDef uc;

    uc.baudrate          = 9600;
    uc.baudGenerator     = PERIPH_TIM_2;
    uc.interruptState    = ENABLE;
    uc.interruptPriority = UTIL_interruptPriority_0;
    uc.mode              = UART_mode_1;
    uc.multiBaudrate     = DISABLE;
    uc.receiveState      = ENABLE;

    UART_config(&uc);
    ISP_cmd(ENABLE);
    ISP_config();
}

/*****************************************************************************/
/** 
 * \author      Amy Chung
 * \date        
 * \brief       transfer byte to hex string
 * \param[in]   src: the byte of date which is going to transfer
 * \param[in]   res: a array for storing result
 * \return      none
 * \ingroup     example
 * \remarks     
******************************************************************************/
void util_byteToHexString(byte src, char *res)
{
    uint8_t i = 2;
    byte tmp = 0x00;

    res = res + 2;
    *res = '\0';
    
    while (i--)
    {
        res--;
        tmp = src % 0x10;
        
        if (tmp < 10)
        {
            *res = '0' + tmp;
        }
        else
        {
            *res = 'A' + (tmp - 0x0A);
        }
        src = src / 0x10;
    }

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
    char accessResult[3];                             /* store results */
    char __code test_data[3] = {0x20, 0x19, 0x04};    /* test data */
    uint8_t i = 0;

    sys_init();
    UART_sendString("MCU boot...\r\n\0");

    while (true)
    {
        ISP_eraseSector(ISP_ADDR_START);        /* it's necessary step */
        for (i = 0;i < 3;i++)
        {
            /* write */
            if (ISP_writeByte(ISP_ADDR_START+i, test_data[i]))
            {
                UART_sendString("Succeeded to write test byte\r\n\0");
            }
            else
            {
                UART_sendString("Fail to write test byte\r\n\0");
            }

            /* read and show access result */
            util_byteToHexString(ISP_readByte(ISP_ADDR_START+i), accessResult);
            UART_sendString("Access result: 0x");
            UART_sendString(accessResult);
            UART_sendString("\r\n\0");
            sleep(1000);
        }
        i = 0;
    }
}
