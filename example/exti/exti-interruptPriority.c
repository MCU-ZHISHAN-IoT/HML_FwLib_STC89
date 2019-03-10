 /*
 * @Author:
 *  #Amy Chung | zhongliguo(at)zhishan-iot.tk
 * @Compiler:SDCC v3.6.0
 * @E-mail:mcu(at)zhishan-iot.tk
 * @File-description:a example which shows how to use HML_FwLib_STC89 to configure interrupt priority of extern interrupts and timers
 * @Test-board:ZS5110
 * @Test-mcu:STC89C52RC
 * @Version:V1
 */
 
/*
  * @Extra-note:(1)This file configures TIM0 priority as lowest priority(INTR_priority_0), EXTI0's priority is lower priority(INTR_priority_1), and EXTI1 's priority is highest(INTR_priority_1). At the same time, each interrupt source controls a blink LED with different gap time, higher priority means shorter time(EXTI0: 250ms; EXTI1: 150ms; TIM0: 500ms;).(2)On board ZS51-V1.0, pin INT0 and INT1 are connected to buttons so we can use them to wakeup interrupt. And a 8-bit LED group controlled by GPIO2.
  */
#include "conf.h"

/* ----- @macro define ----- */
/* --- led define --- */
#define PERIPH_LED PERIPH_GPIO_2
/* --- led bit define --- */
#define PERIPH_LED_TIM0 PERIPH_GPIO_PIN_0
#define PERIPH_LED_EXTI0 PERIPH_GPIO_PIN_1
#define PERIPH_LED_EXTI1 PERIPH_GPIO_PIN_2
/* --- key define --- */
#define PERIPH_KEY PERIPH_GPIO_3
/* --- key bit define --- */
#define PERIPH_KEY_EXTI0 PERIPH_GPIO_PIN_2
#define PERIPH_KEY_EXTI1 PERIPH_GPIO_PIN_3

/*
 * @Prototype:void sys_init(void)
 * @Parameter:None
 * @Ret-val:None
 * @Note:initial MCU
 */
void sys_init(void)
{
    EXTI_configTypeDef ec;
    TIM_configTypeDef tc;
    
    tc.function          = TIM_function_tim;
    tc.interruptState    = ENABLE;
    tc.interruptPriority = INTR_priority_0;
    tc.mode              = TIM_mode_1;
    tc.value             = TIM_calculateValue(50000,TIM_mode_1);
    
    TIM_config(PERIPH_TIM_0,&tc);
    TIM_cmd(PERIPH_TIM_0,ENABLE);

    ec.mode     = EXTI_mode_fallEdge;
    ec.priority = INTR_priority_1;
    EXTI_config(PERIPH_EXTI_0,&ec);
    EXTI_cmd(PERIPH_EXTI_0,ENABLE);

    ec.priority = INTR_priority_2;
    EXTI_config(PERIPH_EXTI_1,&ec);
    EXTI_cmd(PERIPH_EXTI_1,ENABLE);
    enableAllInterrupts();
    
    GPIO_configPort(PERIPH_LED,0xFF);
}

void main(void)
{
    sys_init();
    while(true);
}

/*
 * @Prototype:void tim0_isr(void)
 * @Parameter:None
 * @Ret-val:None
 * @Note:interrupt service function for TIM0
 */
void tim0_isr(void) __interrupt TF0_VECTOR
{
    static u8 cnt = 0;
    
    /* per 500ms */
    cnt++;
    if(cnt == 10)
    {
        GPIO_toggleBitValue(PERIPH_LED,PERIPH_LED_TIM0);
        cnt = 0;
    }
}

/*
 * @Prototype:void exti0_isr(void)
 * @Parameter:None
 * @Ret-val:None
 * @Note:interrupt service function for EXTI0
 */
void exti0_isr(void) __interrupt IE0_VECTOR
{
    u8 i = 10;

    /* avoid shake */
    EXTI_cmd(PERIPH_EXTI_0,DISABLE);
    sleep(20);
    
    /* make sure the button pressed by P32(INT0) */
    if(GPIO_getBitValue(PERIPH_KEY,PERIPH_KEY_EXTI0) == RESET)
    {
        GPIO_configPort(PERIPH_LED,0xFF);
        while(i--)
        {
            GPIO_toggleBitValue(PERIPH_LED,PERIPH_LED_EXTI0);
            sleep(250);
        }
    }

    /* recover */
    GPIO_configPort(PERIPH_LED,0xFF);
    EXTI_cmd(PERIPH_EXTI_0,ENABLE);
}

/*
 * @Prototype:void exti1_isr(void)
 * @Parameter:None
 * @Ret-val:None
 * @Note:interrupt service function for EXTI1
 */
void exti1_isr(void) __interrupt IE1_VECTOR
{
    u8 j = 10;

    /* avoid shake */
    EXTI_cmd(PERIPH_EXTI_1,DISABLE);
    sleep(20);
    
    /* make sure the button pressed by P33(INT1) */
    if(GPIO_getBitValue(PERIPH_KEY,PERIPH_KEY_EXTI1) == RESET)
    {
        GPIO_configPort(PERIPH_LED,0xFF);
        while(j--)
        {
            GPIO_toggleBitValue(PERIPH_LED,PERIPH_LED_EXTI1);
            sleep(150);
        }
    }

    /* recover */
    GPIO_configPort(PERIPH_LED,0xFF);
    EXTI_cmd(PERIPH_EXTI_1,ENABLE);
}

