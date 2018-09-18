/*
 * @Author:
 *  #Jiabin Hsu | zsiothsu(at)zhishan-iot.ga
 * @File-description:show how to use firmware library to
 *                   use ISP to write and read byte
 * @Required-compiler:SDCC
 * @Support-mcu:STC micro STC89 series
 * @Version:V0
 */

#include "conf.h"

void main(void)
{
	GPIO_configBitValue(PERIPH_GPIO_1,PERIPH_GPIO_PIN_0,SET);
	ISP_cmd(ENABLE);
	if(ISP_readByte(ISP_beginAddress) == 'T')
	{
		/* reset the module.if 'T' were writen successfully,
		P1_0 will be lighted*/
		GPIO_configBitValue(PERIPH_GPIO_1,PERIPH_GPIO_PIN_0,RESET);
		ISP_eraseByte(ISP_beginAddress);
	}

	else ISP_writeByte(ISP_beginAddress,'T');

	while(true);
}