/*
 * @Author:
 *  #Jiabin Hsu | zsiothsu(at)zhishan-iot.ga
 * @File-description:show how to use firmware library to use ISP to write and read byte
 * @Required-compiler:SDCC
 * @Support-mcu:STC micro STC89 series
 * @Version:V1
 */

#include "conf.h"

void sys_init(void)
{
	UART_configTypeDef uc;
	
	uc.baudrate = 9600;
	uc.interruptState = ENABLE;
	uc.interruptPriority = DISABLE;
	uc.mode = UART_mode_1;
	uc.multiBaudrate = DISABLE;
	uc.receiveState  = ENABLE;
	uc.tim = PERIPH_TIM2;
	
	UART_config(&uc);
	enableAllInterrupts();
	
	GPIO_configBitValue(PERIPH_GPIO_1,PERIPH_GPIO_PIN_0,SET);
	ISP_cmd(ENABLE);
}

void main(void)
{
	sys_init();
	
	if(ISP_readByte(ISP_ADDR_START) == 'T')
	{
		/* reset the module.if 'T' were writen successfully,
		P10 will be lighted*/
		GPIO_configBitValue(PERIPH_GPIO_1,PERIPH_GPIO_PIN_0,RESET);
		ISP_eraseByte(ISP_ADDR_START);
	}
	else
	{
		ISP_writeByte(ISP_ADDR_START,'T');
		UART_sendByte(ISP_readByte(ISP_ADDR_START));  /* show result */
	}

	while(true);
}
