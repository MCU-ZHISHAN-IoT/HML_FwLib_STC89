/*
 * @Author:
 *  #Weilun Fong | wlf(at)zhishan-iot.ga
 * @E-mail:mcu(at)zhishan-iot.ga
 * @File-description:a demo which shows how to use the library to send string via UART module
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
	
	uc.baudrate = 9600;
	uc.interruptState = ENABLE;
	uc.interruptPriority = DISABLE;
	uc.mode = UART_MODE_1;
	uc.multiBaudrate = DISABLE;
	uc.receiveState  = ENABLE;
	
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
