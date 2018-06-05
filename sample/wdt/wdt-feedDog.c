/*
 * @Author:
 *  #Jiabin Hsu | zsiothsu(at)zhishan-iot.ga
 * @File-description:show how to use firmware library to
 *                   config and feed watchdog
 * @Required-complier:SDCC
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
	uc.interruptsState = ENABLE;
	uc.intterruptPriority = DISABLE;
	uc.mode = UART_MODE_1;
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
	WDT_setPrescale(WDT_Prescale_32);
	WDT_cmd(ENABLE);
	
	while(true)
	{
		/*feed watchdog per 500ms*/
		sleep(500);
		WDT_clear();
		UART_sendString("watch dog has been feeded");
	}
}
