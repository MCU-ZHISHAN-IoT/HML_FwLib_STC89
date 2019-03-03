 /*
 * @Author:
 *  #Amy Chung | zhongliguo(at)zhishan-iot.tk
 * @Compiler:SDCC v3.6.0
 * @E-mail:mcu(at)zhishan-iot.tk
 * @File-description:a example which shows how to use HML to control interruptPriority between EXTI and TIM
 * @Support-mcu:STC micro STC89 series
 * @Test-board:ZS51-V1.0
 * @Test-mcu:STC89C52RC
 * @Version:V1
 */
 
 /*
  * @Extra-note:configure TIM0 priority with lowest priority(INTR_priority_0), configure EXTI0 as priority with lower priority(INTR_priority_1), configure EXTI1 as priority highest(INTR_priority_1). Each interrupt source controls a blink LED with different gap time.(EXTI0: 750ms; EXTI1: 250ms; TIM0: 500ms;)
  */

#include "conf.h"

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
    
    tc.function = TIM_function_tim;
    tc.interruptState = ENABLE;
    tc.interruptPriority = INTR_priority_0;
    tc.mode = TIM_mode_1;
    tc.value = TIM_calculateValue(50000,TIM_mode_1);
    
    TIM_config(PERIPH_TIM_0,&tc);
    TIM_cmd(PERIPH_TIM_0,ENABLE);

    ec.mode = EXTI_mode_fallEdge;
    ec.priority = INTR_priority_1;
    EXTI_config(PERIPH_EXTI_0,&ec);
    EXTI_cmd(PERIPH_EXTI_0,ENABLE);

    ec.priority = INTR_priority_2;
    EXTI_config(PERIPH_EXTI_1,&ec);
    EXTI_cmd(PERIPH_EXTI_1,ENABLE);
    enableAllInterrupts();
    
    GPIO_configPort(PERIPH_GPIO_1,0xFF);
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
    static int cnt = 0;
    
    /* per 500ms */
    cnt++;
    if(cnt == 10)
    {
        GPIO_toggleBitValue(PERIPH_GPIO_2,PERIPH_GPIO_PIN_0);
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
    static int cnt = 5;
    /* avoid shake */
    EXTI_cmd(PERIPH_EXTI_0,DISABLE);
    sleep(20);
    
    /* make sure the button connected to P32(INT0) */
    if(GPIO_getBitValue(PERIPH_GPIO_3,PERIPH_GPIO_PIN_2) == RESET)
    {
        GPIO_configPort(PERIPH_GPIO_2,0xFF);
        while(cnt != 0)
        {
            GPIO_configBitValue(PERIPH_GPIO_2,PERIPH_GPIO_PIN_1,RESET);
            sleep(750);
            GPIO_configBitValue(PERIPH_GPIO_2,PERIPH_GPIO_PIN_1,SET);
            sleep(750);
            cnt--;
        }
    }
    /* recover */
    cnt = 5;
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
   static int cnt = 5;
    /* avoid shake */
    EXTI_cmd(PERIPH_EXTI_1,DISABLE);
    sleep(20);
    
    /* make sure the button connected to P33(INT1) */
    if(GPIO_getBitValue(PERIPH_GPIO_3,PERIPH_GPIO_PIN_3) == RESET)
    {
        GPIO_configPort(PERIPH_GPIO_2,0xFF);
        while(cnt != 0)
        {
            GPIO_configBitValue(PERIPH_GPIO_2,PERIPH_GPIO_PIN_2,RESET);
            sleep(250);
            GPIO_configBitValue(PERIPH_GPIO_2,PERIPH_GPIO_PIN_2,SET);
            sleep(250);
            cnt--;
        }
    }
    /* recover */
    cnt = 5;
    EXTI_cmd(PERIPH_EXTI_1,ENABLE);
}

