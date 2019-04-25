/*
 * @Author:
 *  #Jiabin Hsu | zsiothsu(at)zhishan-iot.tk
 * @Compiler:SDCC v3.6.0
 * @E-mail:mcu(at)zhishan-iot.tk
 * @File-description:show how to use HML_FwLib_STC89 to use ISP to write and read byte
 * @Test-board:TS51-V2.0
 * @Test-mcu:STC89C52RC
 * @Version:V1
 */

#include "conf.h" 

/*
 * @Prototype:void sys_init(void)
 * @Parameter:None
 * @Ret-val:None
 * @Note:initial MCU
 */
void sys_init(void)
{
    UART_configTypeDef uc;
    
    uc.baudrate          = 9600;
    uc.baudGenerator     = PERIPH_TIM_2;
    uc.interruptState    = ENABLE;
    uc.interruptPriority = INTR_priority_0;
    uc.mode              = UART_mode_1;
    uc.multiBaudrate     = DISABLE;
    uc.receiveState      = ENABLE;
    
    UART_config(&uc);
    ISP_cmd(ENABLE);
}

/*
 * @Prototype:void util_byteToHexString(byte src,char *res)
 * @Parameter:(1)src:the byte of date which is going to transfer; (2)res:a array for storing result
 * @Ret-val:None
 * @Note:transfer byte to hex string
 */
void util_byteToHexString(byte src,char *res)
{
    u8 i = 2;
    byte tmp = 0;
    
    res = res + 2;
    *res = '\0';
    
    while(i--)
    {
        res--;
        tmp = src % 0x10;
        
        if(tmp < 10)
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

/* ----- @main ----- */
void main(void)
{
    char accessResult[3];                             /* store results */
    char __code test_data[3] = {0x20, 0x19, 0x04};    /* test data */
    u8 i = 0;

    sys_init();
    UART_sendString("MCU boot...\r\n\0");

    while(true)
    {
        for(i = 0;i < 3;i++)
        {
            ISP_eraseByte(ISP_ADDR_START+i);      /* it's necessary step */
            /* write */
            if(ISP_writeByte(ISP_ADDR_START+i,test_data[i]))
            {
                UART_sendString("Succeeded to write test byte\r\n\0");
            }
            else
            {
                UART_sendString("Fail to write test byte\r\n\0");
            }

            /* read and show access result */
            util_byteToHexString(ISP_readByte(ISP_ADDR_START+i),accessResult);       
            UART_sendString("Access result: 0x");
            UART_sendString(accessResult);
            UART_sendString("\r\n\0");
            sleep(1000);
        }
        i = 0;
    }
}