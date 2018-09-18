/*
 * @Author:
 *  #Jiabin Hsu | zsiothsu(at)zhishan-iot.tk
 * @File-description:show how to use firmware library to config and feed watchdog module
 * @Required-complier:SDCC
 * @Support-mcu:STC micro STC89 series
 * @Version:V1
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
	uc.mode = UART_mode_1;
	uc.multiBaudrate = DISABLE;
	uc.receiveState  = ENABLE;
	uc.tim = PERIPH_TIM_1;
	
	UART_config(&uc);
	enableAllInterrupts();
}

void main(void)
{
	sys_init();
	UART_sendString("MCU boot");
	WDT_setPrescale(WDT_prescale_32);
	WDT_cmd(ENABLE);
	
	while(true)
	{
		/*feed watchdog per 500ms*/
		sleep(500);
		WDT_clear();
		UART_sendString("root@localboard:WatchDog has been feeded\r\n");
	}
}
