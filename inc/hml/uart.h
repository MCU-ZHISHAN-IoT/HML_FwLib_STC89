/*****************************************************************************/
/** 
 * \file        uart.h
 * \author      Jiabin Hsu  | zsiothsu(at)zhishan-iot.tk
 * \author      Weilun Fong | wlf@zhishan-iot.tk
 * \brief       operations for UART module
 * \note        
 * \version     v1.2
 * \ingroup     UART
******************************************************************************/

#ifndef ___HML_UART_H___
#define ___HML_UART_H___

/*****************************************************************************
 *                             header file                                   *
 *****************************************************************************/
#include "hml/util.h"
/*****************************************************************************/
#include "hml/tim.h"
#include "hml/tim2.h"

/*****************************************************************************
 *                           enumeration type                                *
 *****************************************************************************/

/**
 *\brief: mark work mode of UART
 */
typedef enum
{
    UART_mode_0 = 0x0,       /* 8-bit shift register */
    UART_mode_1 = 0x1,       /* 8-bit UART,variable baud rate */
    UART_mode_2 = 0x2,       /* 9-bit UART,baud rate = fosc/64 or fosc/32 */
    UART_mode_3 = 0x3        /* 9-bit UART,variable baud rate */
} UART_mode;

/*****************************************************************************
 *                           structure define                                *
 *****************************************************************************/

/**
 *\brief: struct for UART configuration
 */
typedef struct
{
    uint32_t               baudrate;
    PERIPH_TIM             baudGenerator;
    Action                 interruptState;
    UTIL_interruptPriority interruptPriority;
    UART_mode              mode;
    Action                 multiBaudrate;
    Action                 receiveState;
} UART_configTypeDef;

/*****************************************************************************
 *                          function declare                                 *
 *****************************************************************************/
void UART_cmd_multiBaudrate(Action a);
void UART_cmd_receive(Action a);
void UART_config(UART_configTypeDef *uc);
uint16_t UART_getBaudGeneratorInitValue(uint32_t baud,PERIPH_TIM tim);
FunctionalState UART_isReceived(void);
FunctionalState UART_isTransmitted(void);
void UART_sendByte(byte dat);
void UART_sendString(char *str);
void UART_setMode(UART_mode m);
void UART_switchTim(PERIPH_TIM tim);
void UART_INT_cmd(Action a);
void UART_INT_setPriority(UTIL_interruptPriority p);

#endif
