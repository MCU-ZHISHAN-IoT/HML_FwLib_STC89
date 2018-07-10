/*
 * @Author:
 *  #Jiabin Hsu  | zsiothsu(at)zhishan-iot.ga
 * @E-mail:mcu(at)zhishan-iot.ga
 * @File-description:operations for watch dog resource
 * @Required-compiler:SDCC
 * @Support-mcu:STC micro STC89 series
 * @Version:V0
 */
 
#include "wdt.h"

/*
 * @Protype:void WDT_clear(void)
 * @Parameter:
 * @Ret-val:
 * @Note:feeds the watch dog 
 */
void WDT_clear(void)
{
	WDT_CONTR = WDT_CONTR | 0x10;
}

/*
 * @Protype:void WDT_cmd(Action a)
 * @Parameter:(1)a:expected action
 * @Ret-val:
 * @Note:lanuch or stop watch dog
 */
void WDT_cmd(Action a)
{
	WDT_CONTR = (WDT_CONTR & 0xDF) | (a << 0x5);
}

/*
 * @Protype:void WDT_cmd_idleCount(Action a)
 * @Parameter:(1)a:expected action
 * @Ret-val:
 * @Note:enable or disable watch dog when idle mode
 */
void WDT_cmd_idleCount(Action a)
{
	WDT_CONTR = (WDT_CONTR & 0xF7) | (a << 0x3);
}

/*
 * @Protype:void WDT_setPrescale(WDT_Prescale pre)
 * @Parameter:(1)pre:prescale factor
 * @Ret-val:
 * @Note:set prescale
 */
void WDT_setPrescale(WDT_Prescale pre)
{
	WDT_CONTR = (WDT_CONTR & 0xF8) | pre;
}
