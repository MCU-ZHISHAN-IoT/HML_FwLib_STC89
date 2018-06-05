/*
 * @Author:
 *  #Jiabin Hsu  | zsiothsu(at)zhishan-iot.ga
 *  #Weilun Fong | wlf(at)zhishan-iot.ga
 * @E-mail:mcu(at)zhishan-iot.ga
 * @File-description:operations for timer resource
 * @Required-compiler:SDCC
 * @Support-mcu:STC micro STC89 series
 * @Version:V0
 */

#include "tim.h"

/*
 * @Protype:unsigned int TIM_calcValue(unsigned int time,TIM_mode m)
 * @Parameter:
 *  (1)time:Initial value of time (time/us)
 *  (2)m:work mode(refer to header file)
 * @Ret-val:init value of timer counter register(if return 0x0000,it means that the time has over the limit)
 * @Note:calculate timer counter register value
 */
unsigned int TIM_calculateValue(unsigned int time,TIM_mode m)
{
	/* MachineCycle:12/_FRE_OSC_ */
	unsigned int MaxTick = 0x0000;
	switch(m)
	{
        case TIM_MODE_0:MaxTick = 0x1FFF;break; //(1<<13)-1
        case TIM_MODE_1:MaxTick = 0xFFFF;break; //(1<<16)-1
        case TIM_MODE_2:MaxTick = 0x00FF;break; //(1<<8)-1
        case TIM_MODE_3:MaxTick = 0x00FF;break; //(1<<8)-1
		default:break;
	}
    if((time*12)/(_FRE_OSC_/1000000) >= MaxTick ) return 0;
    else return (MaxTick+1-((time*12)/(_FRE_OSC_/1000000)));
}

/*
 * @Protype:void TIM_cmd(PERIPH_TIM tim,Action a)
 * @Parameter:
 *  (1)tim:target timer module
 *  (2)a:expected action
 * @Ret-val:
 * @Note:lanuch or stop timer
 */
void TIM_cmd(PERIPH_TIM tim,Action a)
{
	switch(tim)
	{
		case PERIPH_TIM_0:TR0 = a;break;
		case PERIPH_TIM_1:TR1 = a;break;
		default:break;
	}
}

/*
 * @Protype:void TIM_config(PERIPH_TIM tim,TIM_configTypeDef *tc)
 * @Parameter:
 *  (1)tim:target timer module
 *  (2)tc:custom config reference info.,look up details in header file
 * @Ret-val:
 * @Note:config target timer
 */
void TIM_config(PERIPH_TIM tim,TIM_configTypeDef *tc)
{
	TIM_setFunction(tim,tc->function);
	TIM_setMode(tim,tc->mode);
	TIM_setValue(tim,tc->value);
	TIM_INT_cmd(tim,tc->interruptState);
	TIM_INT_setPriority(tim,tc->interruptPriority);
}

/*
 * @Protype:unsigned int TIM_getValue(PERIPH_TIM tim)
 * @Parameter:(1)tim:target timer module
 * @Ret-val:value(if return 0,means user call this function with error ways)
 * @Note:get timer's value
 */
unsigned int TIM_getValue(PERIPH_TIM tim)
{
	switch(tim)
	{
		case PERIPH_TIM_0:return ((TH0 << 0x08) | TL0);
		case PERIPH_TIM_1:return ((TH1 << 0x08) | TL1);
		default:return 0;
	}
}

/*
 * @Protype:bool TIM_isOverflow(PERIPH_TIM tim)
 * @Parameter:(1)tim:target timer module
 * @Ret-val:(1)false:not overflow;(2)true:overflow;
 * @Note:check value register timer if is overflow
 */
bool TIM_isOverflow(PERIPH_TIM tim)
{
	switch(tim)
	{
		case PERIPH_TIM_0:return (bool)TF0;
		case PERIPH_TIM_1:return (bool)TF1;
		default:return false;
	}
}

/*
 * @Protype:void TIM_setFunction(PERIPH_TIM tim,TIM_function f)
 * @Parameter:
 * (1)tim:target timer module
 * (2)f:expected function
 * @Ret-val:
 * @Note:config the module as counter mode or timer mode
 */
void TIM_setFunction(PERIPH_TIM tim,TIM_function f)
{
	switch(tim)
	{
		case PERIPH_TIM_0:TMOD = (TMOD & 0xFB) | (f << 0x02);break;
		case PERIPH_TIM_1:TMOD = (TMOD & 0xBF) | (f << 0x06);break;
		default:break;
	}
}

/*
 * @Protype:void TIM_setMode(PERIPH_TIM tim,TIM_mode m)
 * @Parameter:
 * (1)tim:target timer module
 * (2)m:work mode(refer to header file)
 * @Ret-val:
 * @Note:set work mode of timer
 */
void TIM_setMode(PERIPH_TIM tim,TIM_mode m)
{
	switch(tim)
	{
		case PERIPH_TIM_0:TMOD = (TMOD & 0xFC) | m;break;
		case PERIPH_TIM_1:TMOD = (TMOD & 0xCF) | (m << 0x04);break;
		default:break;
	}
}

/*
 * @Protype:void TIM_setValue(PERIPH_TIM tim,unsigned int val)
 * @Parameter:
 * (1)tim:target timer module
 * (2)val:expected value
 * @Ret-val:
 * @Note:set value in value register of specified timer module
 */
void TIM_setValue(PERIPH_TIM tim,unsigned int val)
{
	switch(tim)
	{
		case PERIPH_TIM_0:
		{
			TH0 = (unsigned char)(val >> 0x8);
			TL0 = (unsigned char)val;
		} break;
		case PERIPH_TIM_1:
		{
			TH1 = (unsigned char)(val >> 0x8);
			TL1 = (unsigned char)val;
		} break;
		default:break;
	}
}

/*
 * @Protype:void TIM_INT_cmd(PERIPH_TIM tim,Action a)
 * @Parameter:
 * (1)tim:target timer module
 * (2)a:expected action,decide disable or enable timer intterupt
 * @Ret-val:
 * @Note:disable or enable timer intterupt
 */
void TIM_INT_cmd(PERIPH_TIM tim,Action a)
{
	switch(tim)
	{
		case PERIPH_TIM_0:ET0 = a;break;
		case PERIPH_TIM_1:ET1 = a;break;
		default:break;
	}
}

/*
 * @Protype:void TIM_INT_setPriority(PERIPH_TIM tim,INTR_PIOR p)
 * @Parameter:
 * (1)tim:target timer module
 * (2)p:expected intterrupt priority class
 * @Ret-val:
 * @Note:set priority of TIM module
 */
void TIM_INT_setPriority(PERIPH_TIM tim,INTR_PIOR p)
{
	switch(tim)
	{
		case PERIPH_TIM_0:
		{
			IP = (IP & 0xFD) | ((P & 0x01) << 0x1);
			IPH = (IPH & 0xFD) | (p & 0x02);
		} break;
		case PERIPH_TIM_1:
		{
			IP = (IP & 0xF7) | ((p & 0x01) << 0x3);
			IPH = (IPH & 0xF7) | ((p & 0x02) << 0x2);
		} break;
		default:break;
	}
}
