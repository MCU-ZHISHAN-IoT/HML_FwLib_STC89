/*
 * @Author:
 *  #Weilun Fong | wlf(at)zhishan-iot.tk
 * @File-description:show how to use firmware library to trigger software reset
 * @Required-compiler:SDCC
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
	EXTI_configTypeDef ec;
	
	ec.mode = EXTI_mode_fallEdge;
	ec.priority = DISABLE;
	EXTI_config(PERIPH_EXTI_1,&ec);
	EXTI_cmd(PERIPH_EXTI_1,ENABLE);
	enableAllInterrupts();
}

void main()
{
	sys_init();
	while(true)
	{
		GPIO_configBitValue(PERIPH_GPIO_1,PERIPH_GPIO_PIN_0,RESET);
		sleep(500);
		GPIO_configBitValue(PERIPH_GPIO_1,PERIPH_GPIO_PIN_0,SET);
		sleep(500);
	}
}

/*
 * @Protype:void exti1_isr(void)
 * @Parameter:None
 * @Ret-val:None
 * @Note:interrupt service function for EXTI1
 */
void exti1_isr(void) __interrupt IE1_VECTOR
{
	/* avoid shake */
	disableAllInterrupts();
	sleep(20);
	
	/* make sure the button connected to P33(INT1) */
	if(GPIO_getBitValue(PERIPH_GPIO_3,PERIPH_GPIO_PIN_3) == RESET)
	{
		RST_reset(RST_AP);
	}
	/* recover */
	else
	{
		enableAllInterrupts();
	}
}
