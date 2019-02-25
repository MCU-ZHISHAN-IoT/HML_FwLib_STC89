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
    ISP_CONTR = SET_BIT_MASK(ISP_CONTR,ISPEN);
    ISP_CONTR = CONFB(ISP_CONTR,BIT_NUM_SWBS,area);
    ISP_CONTR = SET_BIT_MASK(ISP_CONTR,SWRST);
}

#endif
