/*****************************************************************************/
/** 
 * \file        uart.c
 * \author      Jiabin Hsu  | zsiothsu@zhishan-iot.tk
 * \author      Weilun Fong | wlf@zhishan-iot.tk
 * \brief       operations for UART
 * \note        
 * \version     v1.2
 * \ingroup     UART
******************************************************************************/

#include "hml/uart.h"

#ifdef __CONF_COMPILE_UART

/*****************************************************************************/
/** 
 * \author      Weilun Fong
 * \date        
 * \brief       enable or disable multi-baudrate mode
 * \param[in]   a: expected state
 * \return      none
 * \ingroup     UART
 * \remarks     
******************************************************************************/
void UART_cmd_multiBaudrate(Action a)
{
    CONFB(PCON,BIT_NUM_SMOD,a);
}

/*****************************************************************************/
/** 
 * \author      Weilun Fong
 * \date        
 * \brief       enable or disable receive function
 * \param[in]   a: expected state
 * \return      none
 * \ingroup     UART
 * \remarks     
******************************************************************************/
void UART_cmd_receive(Action a)
{
    REN = a;
}

/*****************************************************************************/
/** 
 * \author      Jiabin Hsu
 * \date        
 * \brief       configure UART module
 * \param[in]   uc: the pointer of configuration struct
 * \return      none
 * \ingroup     UART
 * \remarks     
******************************************************************************/
void UART_config(UART_configTypeDef *uc)
{
    TIM_configTypeDef  tc;
    TIM2_configTypeDef tc2;

    UART_INT_cmd(uc->interruptState);
    UART_INT_setPriority(uc->interruptPriority);
    UART_cmd_multiBaudrate(uc->multiBaudrate);
    UART_setMode(uc->mode);
    UART_cmd_receive(uc->receiveState);
    UART_switchTim(uc->baudGenerator);

    switch(uc->baudGenerator)
    {
        case PERIPH_TIM_1:
        {
            tc.function          = TIM_function_tim;
            tc.interruptState    = DISABLE;
            tc.interruptPriority = DISABLE;
            tc.mode              = TIM_mode_2;
            tc.value             = UART_getBaudGeneratorInitValue(uc->baudrate,PERIPH_TIM_1);
            TIM2_BAUD_cmd(TIM2_baudClock_receive | TIM2_baudClock_transmit,DISABLE);
            TIM_config(PERIPH_TIM_1,&tc);
            TIM_cmd(PERIPH_TIM_1,ENABLE);
        } break; 
        case PERIPH_TIM_2:
        {
            tc2.function          = TIM2_function_tim;
            tc2.interruptState    = DISABLE;
            tc2.interruptPriority = DISABLE;
            tc2.mode              = TIM2_mode_2;
            tc2.value             = 0x00;
            tc2.reloadValue       = UART_getBaudGeneratorInitValue(uc->baudrate,PERIPH_TIM_2);
            TIM2_BAUD_cmd(TIM2_baudClock_receive | TIM2_baudClock_transmit,ENABLE);
            TIM2_config(&tc2);
            TIM2_cmd(ENABLE);
        } break;  
        default: break;
    }
}

/*****************************************************************************/
/** 
 * \author      Weilun Fong
 * \date        
 * \brief       calculate initial value of counter inside timer
 * \param[in]   baud: expected baud rate
 * \param[in]   tim : expected baudrate generator
 * \return      initial value of baudrate generator's counter register(if the 
 *              function returns 0x0000, it means overflow)
 * \ingroup     UART
 * \remarks     
******************************************************************************/
uint16_t UART_getBaudGeneratorInitValue(uint32_t baud,PERIPH_TIM tim)
{
    uint8_t tmp = 0x00;

    /* baud = (2^SMOD/32) * MCU_FRE_CLK/(256-x)*12 */
    switch(tim)
    {
        case PERIPH_TIM_1:
        {
            if(GET_BIT(PCON,SMOD))     /* multi baud rate mode */
            {
                if(baud > MCU_FRE_CLK/12/16)
                {
                    return 0x0000;     /* baud rate over max value */
                }
                else 
                {
                    tmp = (256 - MCU_FRE_CLK/16/12/baud);  
                }
            }
            else
            {
                if(baud > MCU_FRE_CLK/12/32)
                {
                    return 0x0000;
                }
                else
                {
                    tmp = (256 - MCU_FRE_CLK/32/12/baud);
                }
            }
        } break;
        case PERIPH_TIM_2:
        {
            return ((65536 - (MCU_FRE_CLK/32/baud)));
        } break;
        default: break;
    }

    return (tmp << 0x8) | tmp;
}

/*****************************************************************************/
/** 
 * \author      Weilun Fong
 * \date        
 * \brief       check if UART module has received one byte of data or not
 * \param[in]   
 * \return      value of bit TI
 * \ingroup     UART
 * \remarks     
******************************************************************************/
FunctionalState UART_isReceived(void)
{
    return (FunctionalState)RI;
}

/*****************************************************************************/
/** 
 * \author      Weilun Fong
 * \date        
 * \brief       check if UART module has transmitted one byte of data or not
 * \param[in]   
 * \return      value of bit RI
 * \ingroup     UART
 * \remarks     
******************************************************************************/
FunctionalState UART_isTransmitted(void)
{
    return (FunctionalState)TI;
}

/*****************************************************************************/
/** 
 * \author      Weilun Fong
 * \date        
 * \brief       send one byte of data via UART
 * \param[in]   dat: expected byte data
 * \return      none
 * \ingroup     UART
 * \remarks     
******************************************************************************/
void UART_sendByte(byte dat)
{
    SBUF = dat;
    while(!TI);
    TI = RESET;
}

/*****************************************************************************/
/** 
 * \author      Weilun Fong
 * \date        
 * \brief       send string via UART
 * \param[in]   str: pointer to target string
 * \return      none
 * \ingroup     UART
 * \remarks     the string must be end with '\0'
******************************************************************************/
void UART_sendString(char *str)
{
    while(*str != '\0')
    {
        SBUF = *str;
        while(!TI);
        TI = RESET;          /* reset flag */
        str++;
    }
}

/*****************************************************************************/
/** 
 * \author      Weilun Fong
 * \date        
 * \brief       set work mode of UART module
 * \param[in]   m: expected work mode
 * \return      none
 * \ingroup     UART
 * \remarks     
******************************************************************************/
void UART_setMode(UART_mode m)
{
    SCON = (SCON & 0x3F) | ((uint8_t)m << 0x6);
}

/*****************************************************************************/
/** 
 * \author      Jiabin Hsu
 * \date        
 * \brief       select a timer as baudrate generator
 * \param[in]   tim: target timer
 * \return      none
 * \ingroup     UART
 * \remarks     parameter tim must be PERIPH_TIM_1 or PERIPH_TIM_2
******************************************************************************/
void UART_switchTim(PERIPH_TIM tim)
{
    if(tim == PERIPH_TIM_1)
    {
        T2CON = T2CON & 0xCF;
    }
    else if(tim == PERIPH_TIM_2)
    {
        T2CON = (T2CON & 0xCF) | 0x30;
    }
}

/*****************************************************************************/
/** 
 * \author      Weilun Fong
 * \date        
 * \brief       enable or disable interrupt of UART
 * \param[in]   a: expected state
 * \return      none
 * \ingroup     UART
 * \remarks     
******************************************************************************/
void UART_INT_cmd(Action a)
{
    ES = a;
}

/*****************************************************************************/
/** 
 * \author      Weilun Fong
 * \date        
 * \brief       configure interrupt priority class of UART
 * \param[in]   p: expected interrupt priority class
 * \return      none
 * \ingroup     UART
 * \remarks     
******************************************************************************/
void UART_INT_setPriority(UTIL_interruptPriority p)
{
    PS = TESTB(p,0);
    CONFB(IPH,BIT_NUM_PSH,TESTB(p,1));
}

#else
    #warning Nothing to be done... User should remove .c file which is disabled by compile control macro from current directory.
#endif
