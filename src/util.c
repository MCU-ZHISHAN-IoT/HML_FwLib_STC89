/*
 * @Author:
 *  #Weilun Fong | wlf(at)zhishan-iot.tk
 * @E-mail:mcu(at)zhishan-iot.tk
 * @File-description:provides some public functions
 * @Required-complier:SDCC
 * @Support-mcu:STC micro STC89 series
 * @Version:V1
 */


#include <stc89.h>
#include "macro.h"

#ifdef ___COMPILE_UTIL___

/*
 * @Prototype:void disableAllInterrupts(void)
 * @Parameter:
 * @Ret-val:
 * @Note:disable all interrupts
 */
void disableAllInterrupts(void)
{
    EA = DISABLE;
}

/*
 * @Prototype:void enableAllInterrupts(void)
 * @Parameter:
 * @Ret-val:
 * @Note:enable total switch of intterupts
 */
void enableAllInterrupts(void)
{
    EA = ENABLE;
}

/*
 * @Prototype:void sleep(u16 t)
 * @Parameter:(1)how many ms users expected
 * @Ret-val:
 * @Note:software delay according to frequency of crystal oscillator
 */
void sleep(unsigned int t)
{
    u8 i = 0x00;
    u8 j = 0x00;
    
    #if ( _FRE_OSC_ == 11059200L )

        while(t--)
        {
            j = 110;
            while(j--);
        }
        
    //TODO
    #elif ( _FRE_OSC_ == 12000000L )

        while(t--)
        {
            j = 120;
            while(j--);
        }
        
    #else
        
    //TODO
    
    #endif
}

#endif
