/*
 * @Author:
 *  #Jiabin Hsu | zsiothsu(at)zhishan-iot.ga
 * @File-description:show how to use firmware library to
 *                   use GPIO
 * @Required-complier:SDCC
 * @Support-mcu:STC micro STC89 series
 * @Version:V0
 */
 
#include "conf.h"

void main()
{
	GPIO_resetBitValue(PERIPH_GPIO_4,PERIPH_GPIO_Pin_5);
	while(true)
	{
		sleep(500);
		GPIO_toggleBitValue(PERIPH_GPIO_4,PERIPH_GPIO_Pin_5);
	}
}
