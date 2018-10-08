/*
 * @Author:
 *  #Jiabin Hsu | zsiothsu(at)zhishan-iot.tk
 * @File-description:show how to use HML to toggle GPIO bit
 * @Required-complier:SDCC
 * @Support-mcu:STC micro STC89 series
 * @Version:V1
 */
 
#include "conf.h"

/* ----- @main ----- */
void main(void)
{
	GPIO_resetBitValue(PERIPH_GPIO_4,PERIPH_GPIO_PIN_5);
	
	while(true)
	{
		sleep(500);
		GPIO_toggleBitValue(PERIPH_GPIO_4,PERIPH_GPIO_PIN_5);
	}
}
