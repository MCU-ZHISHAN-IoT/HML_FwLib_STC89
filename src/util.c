/*****************************************************************************/
/**
 * \file        util.c
 * \author      Weilun Fong | wlf@zhishan-iot.tk
 * \brief       public operations
 * \note        
 * \version     v1.3
 * \ingroup     UTIL
******************************************************************************/

#include "hml/util.h"

#ifdef COMPILE_UTIL

/*****************************************************************************/
/**
 * \author      Weilun Fong
 * \date        
 * \brief       disable master switch of MCU interrupt
 * \param[in]   
 * \return      none
 * \ingroup     UTIL
 * \remarks     
******************************************************************************/
void disableAllInterrupts(void)
{
    EA = DISABLE;
}

/*****************************************************************************/
/**
 * \author      Weilun Fong
 * \date        
 * \brief       enable master switch of MCU interrupt
 * \param[in]   
 * \return      none
 * \ingroup     UTIL
 * \remarks     
******************************************************************************/
void enableAllInterrupts(void)
{
    EA = ENABLE;
}

/*****************************************************************************/
/**
 * \author      Qiyuan Chen & Jiabin Hsu
 * \date        2022/02/26
 * \brief       get _sleep_1ms initial value
 * \param[in]   none
 * \return      none
 * \ingroup     UTIL
 * \remarks     private function, don't use it
******************************************************************************/
uint16_t _sleep_getInitValue(void)
{
    return (uint16_t)(MCU_FRE_CLK/(float)1000/MCU_PRESCALER/2) - 12;
}

/*****************************************************************************/
/**
 * \author      Qiyuan Chen
 * \date        2022/02/26
 * \brief       sleep 1 ms
 * \param[in]   none
 * \return      none
 * \ingroup     UTIL
 * \remarks     private function, don't use it
******************************************************************************/
static void _sleep_1ms(void)
{
    __asm
        push ar6                    ;#2
        push ar7                    ;#2
        inc ar7                     ;#1
    delay1ms_loop$:
        djnz ar6,delay1ms_loop$     ;#2
        djnz ar7,delay1ms_loop$     ;#2
        pop ar7                     ;#2
        pop ar6                     ;#2
        ret                         ;#2
    __endasm;
}

/*****************************************************************************/
/**
 * \author      Jiabin Hsu
 * \date        2022/02/26
 * \brief       software delay according to MCU clock frequency
 * \param[in]   t: how many one ms you want to delay
 * \return      none
 * \ingroup     UTIL
 * \remarks
******************************************************************************/
void sleep(uint16_t t)
{
    __asm
        push ar5
        push ar6
        push ar7

        push dph
        push dpl

    ; freq -> r6,r7
        lcall __sleep_getInitValue
        mov ar6,dpl
        mov ar7,dph

    ; t -> dptr
        pop dpl
        pop dph

    ; 0xFFFF - t
        clr c
        mov a,#0xFF
        subb a,dpl
        mov dpl,a
        mov a,#0xFF
        subb a,dph
        mov dph,a

    ; return if time equals 0
        mov a,dpl
        anl a,dph
        cpl a
        jz ENDL$

    ; loop for sleep
    ; loop from (0xFFFF - t) to (0xFFFF)
    LOOP$:
        lcall __sleep_1ms               ;#2*(frep/1000/prescale) - 11
                                        ;#2 lcall
        inc dptr                        ;#2
        mov a,dpl                       ;#1
        anl a,dph                       ;#1
        cpl a                           ;#1
        jnz LOOP$                       ;#2
    ENDL$:
        pop ar7
        pop ar6
        pop ar5
        ret
    __endasm;

    UNUSED(t);
}

#else
    #warning Nothing to be done... User should remove .c file which is disabled by compile control macro from current directory.
#endif
