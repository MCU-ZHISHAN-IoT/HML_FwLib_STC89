/*
 * @Author:
 *  #Weilun Fong | wlf(at)zhishan-iot.ga
 * @E-mail:mcu(at)zhishan-iot.ga
 * @File-description:
 * #contains definitions that allow you to directly access the different memory areas of the STC90.
 * #have the similar functions like absacc.h in Keil
 * @Required-compiler:SDCC
 * @Support-mcu:STC micro STC89 series
 * @Version:V0
 */

#include "mem.h"

/*
 * @Protype:void MEM_cmd_internalExtendedRam(Action a)
 * @Parameter:(1)a:expected state
 * @Ret-val:
 * @Note:
 *  > disable ALE:ALE is emitted a constant rate of 1/3 Fsoc(the oscillator frequency) in 6 clock mode,1/6 Fsoc in 12 clock mode
 *  > enable ALE:ALE is active only during a MOVX or MOVC instruction
 */
void MEM_cmd_Ale(Action a)
{
	AUXR = (AUXR & 0xFE) | a;
}

/*
 * @Protype:void MEM_cmd_internalExtendedRam(Action a)
 * @Parameter:(1)a:expected state
 * @Ret-val:
 * @Note:enable or disable internal extended RAM access
 *  > there is a RAM area integrated insides STC90 MCUs and it's independent in physics
 *  > if you enable this function,this area will occupy address zone in the beginning(RD+ series is 0000H~03FFH(1024 bytes),RC series is 0000H~00FFH(256 bytes));or this RAM area is hide,the MCU is as same as classical 8051 MCU now
 *  > if you want to enable this function,please remember select the option in STC-ISP
 */
void MEM_cmd_internalExtendedRam(Action a)
{
	AUXR = (AUXR & 0xFD) | ((~a) << 0x1);
}
