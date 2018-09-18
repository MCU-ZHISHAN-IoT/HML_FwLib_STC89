/*
 * @Author:
 *  #Jiabin Hsu  | zsiothsu(at)zhishan-iot.tk
 *  #Weilun Fong | wlf(at)zhishan-iot.tk
 * @E-mail:mcu(at)zhishan-iot.tk
 * @File-description:operations for uart resource
 * @Required-compiler:SDCC
 * @Support-mcu:STC micro STC89 series
 * @Version:V1
 */

#include "uart.h"

#ifdef ___COMPILE_UART___

/*
 * @Protype:void UART_cmd_multiBaudrate(Action a)
 * @Parameter:(1)a:expected action
 * @Ret-val:
 * @Note:disable or enable multi baudrate mode
 */
void UART_cmd_multiBaudrate(Action a)
{
	PCON = (PCON & 0x7F) | ((unsigned char)a << 0x7);
}

/*
 * @Protype:void UART_cmd_receive(Action a)
 * @Parameter:(1)a:expected action
 * @Ret-val:
 * @Note:disable or enable receive function of UART module
 */
void UART_cmd_receive(Action a)
{
	REN = a;
}

/*
 * @Protype:void UART_config(UART_configTypeDef *uc,PERIPH_TIM tim)
 * @Parameter:(1)uc:the pointer of config struct (2)tim:target timer module
 * @Ret-val:
 * @Note:config UART module
 */
void UART_config(UART_configTypeDef *uc)
{
	TIM_configTypeDef tc;
	TIM2_configTypeDef tc2;
	
	UART_INT_cmd(uc->interruptState);
	UART_INT_setPriority(uc->interruptPriority);
	UART_cmd_multiBaudrate(uc->multiBaudrate);
	UART_setMode(uc->mode);
	UART_cmd_receive(uc->receiveState);
	UART_switchTim(uc->tim);

	switch(uc->tim)
	{
		case PERIPH_TIM_1:
			tc.function          = TIM_FUNC_TIM;
			tc.interruptState    = DISABLE;
			tc.interruptPriority = DISABLE;
			tc.mode              = TIM_MODE_2;
			tc.value             = UART_getTimerInitValue(uc->baudrate,PERIPH_TIM_1);
			TIM_config(PERIPH_TIM_1,&tc);
			TIM_cmd(PERIPH_TIM_1,ENABLE);
			break;
			
		case PERIPH_TIM2:
			tc2.function          = TIM2_FUNC_TIM;
			tc2.interruptState    = DISABLE;
			tc2.interruptPriority = DISABLE;
			tc2.mode              = TIM2_MODE_baudrateProducer;
			tc2.value             = UART_getTimerInitValue(uc->baudrate,PERIPH_TIM2);
			RCAP2L = tc2.value;
			RCAP2H = (tc2.value >> 8);
			TIM2_config(&tc2);
			T2MOD = 0x02;
			TIM2_cmd(ENABLE);
			break;
			
		default:break;
	}
}

/*
 * @Protype:unsigned int UART_getTimerInitValue(uint32_t baud,PERIPH_TIM tim)
 * @Parameter:(1)baud:expected baudrate (2)tim:target timer module
 * @Ret-val:init value the baudrate required of timer counter register(if return 0x0000,it means overflow)
 * @Note:calculate timer counter register value
 */
unsigned int UART_getTimerInitValue(uint32_t baud,PERIPH_TIM tim)
{
	unsigned char tmp = 0x00;
	
	//baud = (2^SMOD/32) * _FRE_OSC_/(256-x)*12
	switch(tim)
	{
		case PERIPH_TIM_1:
			if(PCON & 0x80)     /* multi baudrate mode */
			{
				if(baud > _FRE_OSC_/12/16)
				{
					/* baudrate over max value */
					return 0x0000;
				}
				else 
				{
					tmp = (256 - _FRE_OSC_/16/12/baud);  
				}
			}
			else
			{
				if(baud > _FRE_OSC_/12/32)
				{
					return 0x0000;
				}
				else
				{
					tmp = (256 - _FRE_OSC_/32/12/baud);
				}
			}
			break;
		
		case PERIPH_TIM2:
			return tmp = (65536 - (_FRE_OSC_/32/baud));
			break;
		
		default:break;
	}	
	return (tmp << 0x8) | tmp;
}

/*
 * @Protype:FunctionalState UART_isReceived(void)
 * @Parameter:
 * @Ret-val:(1)SET:data have been received;(2)RESET:data haven't been received
 * @Note:
 */
FunctionalState UART_isReceived(void)
{
	return (FunctionalState)RI;
}

/*
 * @Protype:FunctionalState UART_isTransmitted(void)
 * @Parameter:
 * @Ret-val:(1)SET:data have been transmitted;(2)RESET:data haven't been transmitted
 * @Note:
 */
FunctionalState UART_isTransmitted(void)
{
	return (FunctionalState)TI;
}

/*
 * @Protype:void UART_sendByte(unsigned char dat)
 * @Parameter:(1)dat:one byte of data user want to send
 * @Ret-val:
 * @Note:send a byte via UART module
 */
void UART_sendByte(unsigned char dat)
{
	SBUF = dat;
	while(!TI);
	TI = RESET;
}

/*
 * @Protype:void UART_sendString(char *str)
 * @Parameter:(1)str:the point of string user want to send
 * @Ret-val:
 * @Note:send a Ascii string via UART module
 */
void UART_sendString(char *str)
{
	while(*str != '\0')
	{
		SBUF = *str;
		while(!TI);
		TI = RESET;     /* clear */
		str++;
	}
}

/*
 * @Protype:void UART_setMode(UART_mode m)
 * @Parameter:(1)m:expected work mode
 * @Ret-val:
 * @Note:set work mode of UART module
 */
void UART_setMode(UART_mode m)
{
	SCON = (SCON & 0x3F) | ((unsigned char)m << 0x6);
}

/*
 *@Protype:void UART_switchTim(PERIPH_TIM tim)
 *@Parameter:(1)tim:target timer module
 *@Ret-val:
 *@Note:choose a timer to be baudrate productor
 */
void UART_switchTim(PERIPH_TIM tim)
{
	if(tim == PERIPH_TIM_1)
		T2CON = T2CON & 0xCF;
	if(tim == PERIPH_TIM2)
		T2CON = (T2CON & 0xCF) | 0x30;
}

/*
 * @Protype:void UART_INT_setPriority(INTR_priority p)
 * @Parameter:(1)p:expected intterrupt priority class
 * @Ret-val:
 * @Note:set priority of UART module
 */
void UART_INT_setPriority(INTR_priority p)
{
	IP = (IP & 0xEF) | ((p & 0x01) << 0x4);
	IPH = (IPH & 0xEF) | ((p & 0x02) << 0x3);
}

/*
 * @Protype:void UART_INT_cmd(Action a)
 * @Parameter:(1)a:expected action
 * @Ret-val:
 * @Note:disable or enable intterupt function of UART module
 */
void UART_INT_cmd(Action a)
{
	ES = a;
}

#endif
