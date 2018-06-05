/*
 * @Author:
 *  #Jiabin Hsu | zsiothsu(at)zhishan-iot.ga
 * @File-description:show how to use firmware library to
 *                   use timer_2 as a baudrate producer
 * @Required-compiler:SDCC
 * @Support-mcu:STC micro STC89 series
 * @Version:V0
 */

#include "conf.h"
 
/*
 * @Protype:void sys_init(void)
 * @Parameter:None
 * @Ret-val:None
 * @Note:init MCU
 */
void sys_init(void)
{
	UART_configTypeDef uc;
	
	/* set baudrate as 9600bps */
	uc.baudrate = 9600;
	uc.interruptsState = ENABLE;
	uc.intterruptPriority = DISABLE;
	uc.mode = UART_MODE_1;
	uc.multiBaudrate = DISABLE;
	uc.receiveState  = ENABLE;
	uc.tim = PERIPH_TIM2;
	
	UART_config(&uc);
	enableAllInterrupts();
}

void main(void)
{
	sys_init();
	while(true)
	{
		/* send per 500ms */
		sleep(500);
		UART_sendString("Hello,world\r\n");
	}
}

