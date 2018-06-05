/*
 * @Author:
 *  #Jiabin Hsu  | zsiothsu(at)zhishan-iot.ga
 * @E-mail:mcu(at)zhishan-iot.ga
 * @File-description:operations for timer_2 resource
 * @Required-compiler:SDCC
 * @Support-mcu:STC micro STC89 series
 * @Version:V0
 */
 
#include "tim2.h"

/*
 * @Protype:unsigned int TIM2_calculateValue(unsigned int time)
 * @Parameter:
 *  (1)time:Initial value of time (time/us)
 * @Ret-val:init value of timer counter register(if return 0x0000,it means that the time has over the limit)
 * @Note:calculate timer counter register value
 */
unsigned int TIM2_calculateValue(unsigned int time)
{
	unsigned int MaxTick = 0xFFFF;
    if((time*12)/(_FRE_OSC_/1000000) >= MaxTick ) return 0;
    else return (MaxTick+1-((time*12)/(_FRE_OSC_/1000000)));
}


/*
 * @Protype:void TIM2_clearFlag(void)
 * @Parameter:
 * @Ret-val:
 * @Note:clear Clear the interrupt flag of timer_2
 */
void TIM2_clearFlag(void)
{
	T2CON = T2CON & 0x7F;
}

/*
 * @Protype:void TIM2_cmd(Action a)
 * @Parameter:
 *  (1)a:expected action
 * @Ret-val:
 * @Note:lanuch or stop timer_2
 */
void TIM2_cmd(Action a)
{
	T2CON = (T2CON & 0xFB) | (a << 2);
}

/*
 * @Protype:void TIM2_config(TIM2_configTypeDef *tc)
 * @Parameter:
 *  (1)tc:custom config reference info.,look up details in header file
 * @Ret-val:
 * @Note:config timer_2
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
 * @Protype:unsigned int TIM2_getValue(void)
 * @Parameter:
 * @Ret-val:value
 * @Note:get timer's value
 */
unsigned int TIM2_getValue(void)
{
	return (unsigned int)((TH2 << 0x8) | TL2);
}

/*
 * @Protype:bool TIM2_isOverflow()
 * @Parameter:
 * @Ret-val:(1)false:not overflow;(2)true:overflow;
 * @Note:check value register timer_2 if is overflow
 */
bool TIM2_isOverflow()
{
	return (bool)(T2CON >> 7);
}

/*
 * @Protype:void TIM2_setFunction(TIM2_function f)
 * @Parameter:
 * (1)f:expected function
 * @Ret-val:
 * @Note:config the module as counter mode or timer mode
 */
void TIM2_setFunction(TIM2_function f)
{
	T2CON = (T2CON & 0XCF) | f;
}

/*
 * @Protype:void TIM2_setMode(TIM2_mode m)
 * @Parameter:
 * (1)m:work mode(refer to header file)
 * @Ret-val:
 * @Note:set work mode of timer_2
 */
void TIM2_setMode(TIM2_mode m)
{
	T2CON = (T2CON & 0xCE) | m;
}

/*
 * @Protype:void TIM2_setValue(unsigned int val)
 * @Parameter:
 * (1)val:expected value
 * @Ret-val:
 * @Note:set value in value register of timer_2 module
 */
void TIM2_setValue(unsigned int val)
{
	TH2 = (val>>8);
	TL2 = val;
}

/*
 * @Protype:void TIM2_INT_cmd(Action a)
 * @Parameter:
 * (1)a:expected action,decide disable or enable timer intterupt
 * @Ret-val:
 * @Note:disable or enable timer intterupt
 */
void TIM2_INT_cmd(Action a)
{
	IE = (IE & 0xDF) | (a << 5);
}

/*
 * @Protype:void TIM2_INT_setPriority(INTR_PIOR p)
 * @Parameter:
 * (1)p:expected intterrupt priority class
 * @Ret-val:
 * @Note:set priority of TIM2 module
 */
void TIM2_INT_setPriority(INTR_PIOR p)
{
	IP = (IP & 0xDF) | ((p & 0x01) << 0x5);
	IPH = (IPH & 0xDF) | ((p & 0x02) << 0x4);
}

/*
 * @Protype:void TIM2_INT_T2EX_cmd(Action a)
 * @Parameter:
 * (1)a:expected action
 * @Ret-val:
 * @Note:determine whether the jump of a produces interruptions
 */
void TIM2_INT_T2EX_cmd(Action a)
{
	T2CON = (T2CON & 0xF7) | (a << 3);
}
