/*
 * @Author:
 *  #Jiabin Hsu | zsiothsu(at)zhishan-iot.tk
 * @E-mail:mcu(at)zhishan-iot.tk
 * @File-description:operations for TIM2 module
 * @Required-compiler:SDCC
 * @Support-mcu:STC micro STC89 series
 * @Version:V1
 */
 
#include "tim2.h"

#ifdef ___COMPILE_TIM2___

/*
 * @Prototype:unsigned int TIM2_calculateValue(unsigned int t)
 * @Parameter:(1)t:Initial value of time (t/us)
 * @Ret-val:initial value of timer counter register(if return 0x0000,it means that the time has over the limit)
 * @Note:calculate timer counter register value
 */
unsigned int TIM2_calculateValue(unsigned int t)
{
	unsigned int maxTick = 0xFFFF;
	
    if((t*12)/(_FRE_OSC_/1000000) >= maxTick )
	{
        return 0;
	}
    else
	{
        return (maxTick+1-((t*12)/(_FRE_OSC_/1000000)));
	}
}


/*
 * @Prototype:void TIM2_clearFlag(void)
 * @Parameter:
 * @Ret-val:
 * @Note:clear the interrupt flag of TIM2
 */
void TIM2_clearFlag(void)
{
	T2CON = T2CON & 0x7F;
}

/*
 * @Prototype:void TIM2_cmd(Action a)
 * @Parameter:(1)a:expected action
 * @Ret-val:
 * @Note:lanuch or stop TIM2
 */
void TIM2_cmd(Action a)
{
	T2CON = (T2CON & 0xFB) | (a << 2);
}

/*
 * @Prototype:void TIM2_config(TIM2_configTypeDef *tc)
 * @Parameter:(1)tc:custom configure reference info., look up details in header file
 * @Ret-val:
 * @Note:configure TIM2
 */
void TIM2_config(TIM2_configTypeDef *tc)
{
	TIM2_setFunction(tc->function);
	TIM2_setMode(tc->mode);
	TIM2_setValue(tc->value);
	TIM2_INT_cmd(tc->interruptState);
	TIM2_INT_setPriority(tc->interruptPriority);
}

/*
 * @Prototype:unsigned int TIM2_getValue(void)
 * @Parameter:
 * @Ret-val:value
 * @Note:get timer's value
 */
unsigned int TIM2_getValue(void)
{
	return (unsigned int)((TH2 << 0x8) | TL2);
}

/*
 * @Prototype:bool TIM2_isOverflow(void)
 * @Parameter:
 * @Ret-val:(1)false:not overflow;(2)true:overflow;
 * @Note:check value register TIM2 if is overflow
 */
bool TIM2_isOverflow(void)
{
	return (bool)(T2CON >> 7);
}

/*
 * @Prototype:void TIM2_setFunction(TIM2_function f)
 * @Parameter:(1)f:expected function
 * @Ret-val:
 * @Note:configure the module as counter mode or timer mode
 */
void TIM2_setFunction(TIM2_function f)
{
	T2CON = (T2CON & 0XCF) | f;
}

/*
 * @Prototype:void TIM2_setMode(TIM2_mode m)
 * @Parameter:(1)m:work mode(refer to header file)
 * @Ret-val:
 * @Note:set work mode of TIM2
 */
void TIM2_setMode(TIM2_mode m)
{
	T2CON = (T2CON & 0xCE) | m;
}

/*
 * @Prototype:void TIM2_setValue(unsigned int val)
 * @Parameter:(1)val:expected value
 * @Ret-val:
 * @Note:set value in value register of TIM2 module
 */
void TIM2_setValue(unsigned int val)
{
	TH2 = (val >> 8);
	TL2 = val;
}

/*
 * @Prototype:void TIM2_INT_cmd(Action a)
 * @Parameter:(1)a:expected action,decide disable or enable timer interrupt
 * @Ret-val:
 * @Note:disable or enable timer interrupt
 */
void TIM2_INT_cmd(Action a)
{
	IE = (IE & 0xDF) | (a << 5);
}

/*
 * @Prototype:void TIM2_INT_setPriority(INTR_priority p)
 * @Parameter:(1)p:expected interrupt priority class
 * @Ret-val:
 * @Note:set priority of TIM2 module
 */
void TIM2_INT_setPriority(INTR_priority p)
{
	IP  = (IP & 0xDF)  | ((p & 0x01) << 0x5);
	IPH = (IPH & 0xDF) | ((p & 0x02) << 0x4);
}

/*
 * @Prototype:void TIM2_INT_T2EX_cmd(Action a)
 * @Parameter:(1)a:expected action
 * @Ret-val:
 * @Note:determine whether the jump of a produces interruptions
 */
void TIM2_INT_T2EX_cmd(Action a)
{
	T2CON = (T2CON & 0xF7) | (a << 3);
}

#endif
