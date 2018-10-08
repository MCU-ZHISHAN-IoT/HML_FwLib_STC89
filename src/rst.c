/*
 * @Author:
 *  #Jiabin Hsu | zsiothsu(at)zhishan-iot.tk
 * @E-mail:mcu(at)zhishan-iot.tk
 * @File-description:operations of reset resource
 * @Required-compiler:SDCC
 * @Support-mcu:STC micro STC89 series
 * @Version:V1
 */

#include "rst.h"

#ifdef ___COMPILE_RST___

/*
 * @Prototype:void RST_reset(RST_bootarea area)
 * @Parameter:(1)area:boot area
 * @Ret-val:
 * @Note:resets module and chooses area the module boots from
 */
void RST_reset(RST_bootarea area)
{
	ISP_CONTR = (ISP_CONTR & 0x7F) | 0x80;
	ISP_CONTR = (ISP_CONTR & 0xBF) | (area << 0x6);
	ISP_CONTR = (ISP_CONTR & 0xDF) | 0x20;
}

#endif
