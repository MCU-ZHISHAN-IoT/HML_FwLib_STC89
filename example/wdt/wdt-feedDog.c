/*
 * @Author:
 *  #Jiabin Hsu | zsiothsu(at)zhishan-iot.tk
 * @File-description:show how to use HML to configure and feed watchdog module
 * @Required-complier:SDCC
 * @Support-mcu:STC micro STC89 series
 * @Test-board:TS51-V2.0
 * @Test-mcu:STC89C52RC
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
    uc.baudGenerator = PERIPH_TIM_1;
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
	UART_sendString("MCU boot");
	WDT_setPrescale(WDT_prescale_32);
	WDT_cmd(ENABLE);
	
	while(true)
	{
		/*feed watchdog per 500ms*/
		sleep(500);
		WDT_clear();
		UART_sendString("root@localboard:WatchDog has been feed\r\n");
	}
}
