/*
 * @Author:
 *  #Jiabin Hsu  | zsiothsu(at)zhishan-iot.tk
 *  #Weilun Fong | wlf(at)zhishan-iot.tk
 * @E-mail:mcu(at)zhishan-iot.tk
 * @File-description:operations for EXTI resource
 * @Required-compiler:SDCC
 * @Support-mcu:STC micro STC89 series
 * @Version:V1
 */

#include "exti.h"
 
#ifdef ___COMPILE_EXTI___ 

/*
 * @Prototype:void EXTI_config(PERIPH_EXTI exti,EXTI_configTypeDef ec)
 * @Parameter:
 *  (1)exti:target EXTI module
 *  (2)ec:the pointer of configure structure which includes all configuration information
 * @Note:configure EXTI module
 */
void EXTI_config(PERIPH_EXTI exti,EXTI_configTypeDef *ec)
{
    EXTI_setMode(exti,ec->mode);
    EXTI_setPriority(exti,ec->priority);
}

/*
 * @Prototype:void EXTI_cmd(PERIPH_EXTI exti,Action a)
 * @Parameter:
 *  (1)exti:target EXTI module
 *  (2)a:expected status
 * @Note:enable or disable EXTI module
 */
void EXTI_cmd(PERIPH_EXTI exti,Action a)
{
    switch(exti)
    {
        case PERIPH_EXTI_0:EX0 = a;break;
        case PERIPH_EXTI_1:EX1 = a;break;
        case PERIPH_EXTI_2:EX2 = a;break;
        case PERIPH_EXTI_3:EX3 = a;break;
        default:break;
    }
}

/*
 * @Prototype:void EXTI_setMode(PERIPH_EXTI exti,EXTI_mode mod)
 * @Parameter:
 *  (1)exti:target EXTI module
 *  (2)mod:expected work mode
 * @Note:set work mode EXTI module
 */
void EXTI_setMode(PERIPH_EXTI exti,EXTI_mode mod)
{
    switch(exti)
    {
        case PERIPH_EXTI_0:IT0 = mod;break;
        case PERIPH_EXTI_1:IT1 = mod;break;
        case PERIPH_EXTI_2:IT2 = mod;break;
        case PERIPH_EXTI_3:IT3 = mod;break;
        default:break;
    }
}

/*
 * @Prototype:void EXTI_setPriority(PERIPH_EXTI exti,INTR_priority p)
 * @Parameter:
 *  (1)exti:target EXTI module
 *  (2)p:expected interrupt priority class
 * @Note:set priority of EXTI module
 */
void EXTI_setPriority(PERIPH_EXTI exti,INTR_priority p)
{
    switch(exti)
    {
        case PERIPH_EXTI_0:
        {
            PX0 = TESTB(p,0);
            IPH = CONFB(IPH,BIT_NUM_PX0H,TESTB(p,1));
        } break;
        case PERIPH_EXTI_1:
        {
            PX1 = TESTB(p,0);
            IPH = CONFB(IPH,BIT_NUM_PX1H,TESTB(p,1));
        } break;
        case PERIPH_EXTI_2:
        {
            PX2 = TESTB(p,0);
            IPH = CONFB(IPH,BIT_NUM_PX2H,TESTB(p,1));
        } break;
        case PERIPH_EXTI_3:
        {
            PX3 = TESTB(p,0);
            IPH = CONFB(IPH,BIT_NUM_PX3H,TESTB(p,1));
        } break;
        default:break;
    }
}

#endif
