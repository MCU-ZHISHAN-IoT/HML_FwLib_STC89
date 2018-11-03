/*
 * @Author:
 *  #Weilun Fong | wlf(at)zhishan-iot.tk
 * @E-mail:mcu(at)zhishan-iot.tk
 * @File-description:a demo which shows how to use HML to toggle P12 state when EXTI trigged
 * @Required-compiler:SDCC
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
	EXTI_configTypeDef ec;
	
	ec.mode = EXTI_mode_fallEdge;
	ec.priority = DISABLE;
	EXTI_config(PERIPH_EXTI_1,&ec);
	EXTI_cmd(PERIPH_EXTI_1,ENABLE);
	enableAllInterrupts();
	
	GPIO_configPort(PERIPH_GPIO_1,0xFF);
}

void main(void)
{
	sys_init();
	while(true);
}

/*
 * @Prototype:void exti1_isr(void)
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
		GPIO_toggleBitValue(PERIPH_GPIO_1,PERIPH_GPIO_PIN_2);
	}
	/* recover */
	else
	{
		enableAllInterrupts();
	}
}
