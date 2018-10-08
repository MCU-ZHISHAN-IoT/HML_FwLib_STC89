/*
 * @Author:
 *  #Weilun Fong | wlf(at)zhishan-iot.tk
 * @E-mail:mcu(at)zhishan-iot.tk
 * @File-description:a demo which shows how to use the library to send string via UART module, and use TIM2 as baudrate generator
 * @Required-compiler:SDCC
 * @Support-mcu:STC micro STC89 series
 * @Version:V1
 */

#include "conf.h"

/*
 * @Prototype:void sys_init(void)
 * @Parameter:None
 * @Ret-val:None
 * @Note:init MCU
 */
void sys_init(void)
{
	UART_configTypeDef uc;
	
	uc.baudrate = 9600;
	uc.baudGenerator = PERIPH_TIM_2;
	uc.interruptState = ENABLE;
	uc.interruptPriority = DISABLE;
	uc.mode = UART_mode_1;
	uc.multiBaudrate = DISABLE;
	uc.receiveState  = ENABLE;
	
	UART_config(&uc);
	enableAllInterrupts();
}

/* ----- @main ----- */
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
