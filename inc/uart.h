/*
 * @Author:
 *  #Jiabin Hsu  | zsiothsu(at)zhishan-iot.tk
 *  #Weilun Fong | wlf(at)zhishan-iot.tk
 * @E-mail:mcu(at)zhishan-iot.tk
 * @File-description:includes some definitions for operating uart module
 * @Required-compiler:SDCC
 * @Support-mcu:STC micro STC89 series
 * @Version:V1
 */
 
#ifndef ___UART_H___
#define ___UART_H___

/* ----- @header file ----- */
#include <stdint.h>
#include "exti.h"
#include "tim.h"
#include "tim2.h"

/* mark work mode */
typedef enum
{
    UART_mode_0 = 0x0,   /* 8-bit shift register */
    UART_mode_1 = 0x1,   /* 8-bit UART,variable baud rate */
    UART_mode_2 = 0x2,   /* 9-bit UART,baud rate = fosc/64 or fosc/32 */
    UART_mode_3 = 0x3    /* 9-bit UART,variable baud rate */
} UART_mode;

typedef struct
{
    uint32_t      baudrate;
    PERIPH_TIM    baudGenerator;
    Action        interruptState;
    INTR_priority interruptPriority;
    UART_mode     mode;
    Action        multiBaudrate;
    Action        receiveState;
} UART_configTypeDef;

/* ----- @function ----- */
void UART_cmd_multiBaudrate(Action a);
void UART_cmd_receive(Action a);
void UART_config(UART_configTypeDef *uc);
unsigned int UART_getBaudGeneratorInitValue(uint32_t baud,PERIPH_TIM tim);
FunctionalState UART_isReceived(void);
FunctionalState UART_isTransmitted(void);
void UART_sendByte(byte dat);
void UART_sendString(char *str);
void UART_setMode(UART_mode m);
void UART_switchTim(PERIPH_TIM tim);
void UART_INT_setPriority(INTR_priority p);
void UART_INT_cmd(Action a);

#endif
