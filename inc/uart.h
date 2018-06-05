/*
 * @Author:
 *  #Jiabin Hsu  | zsiothsu(at)zhishan-iot.ga
 *  #Weilun Fong | wlf(at)zhishan-iot.ga
 * @E-mail:mcu(at)zhishan-iot.ga
 * @File-description:includes some definitions for operating uart module
 * @Required-compiler:SDCC
 * @Support-mcu:STC micro STC89 series
 * @Version:V0
 */
 
#ifndef ___UART_H___
#define ___UART_H___

#include "exti.h"
#include "tim.h"
#include "tim2.h"

/* mark work mode */
typedef enum
{
	UART_MODE_0 = 0x0,   /* 8-bit shift register */
	UART_MODE_1 = 0x1,   /* 8-bit UART,variable baudrate */
	UART_MODE_2 = 0x2,   /* 9-bit UART,baudrate = fosc/64 or fosc/32 */
	UART_MODE_3 = 0x3    /* 9-bit UART,variable baudrate */
} UART_MODE;

typedef struct
{
	unsigned int baudrate;
	Action       interruptState;
	INTR_PIOR    interruptPriority;
	UART_MODE    mode;
	Action       multiBaudrate;
	Action       receiveState;
	PERIPH_TIM   tim;
} UART_configTypeDef;

/* ---------- @function --------- */
void UART_cmd_multiBaudrate(Action a);
void UART_cmd_receive(Action a);
void UART_config(UART_configTypeDef *uc);
unsigned int UART_getTimerInitValue(unsigned int baud,PERIPH_TIM tim);
FunctionalState UART_isReceived(void);
FunctionalState UART_isTransmitted(void);
void UART_sendByte(unsigned char dat);
void UART_sendString(char *str);
void UART_setMode(UART_MODE m);
void UART_INT_setPriority(INTR_PIOR p);
void UART_INT_cmd(Action a);
		
#endif /* ___UART_H___ */