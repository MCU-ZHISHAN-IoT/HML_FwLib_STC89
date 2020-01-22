/*****************************************************************************/
/**
 * \file        util.c
 * \author      Weilun Fong | wlf@zhishan-iot.tk
 * \brief       public operations
 * \note
 * \version     v1.2
 * \ingroup     UTIL
******************************************************************************/

#include "hml/util.h"

#ifdef __CONF_COMPILE_UTIL

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
 * \author      Weilun Fong
 * \date
 * \brief       software delay according to MCU clock frequency
 * \param[in]   t: how many one ms you want to delay
 * \return      none
 * \ingroup     UTIL
 * \remarks
******************************************************************************/
void sleep(uint16_t t)
{
    __asm

        ; preprocess
        clr c
        mov a,dpl
        subb a,#1
        mov dpl,a
        mov a,dph
        subb a,#0
        mov dph,a

        ; calculate total cosume time
        mov r6,dpl
        mov r7,dph
        mov __mullong_PARM_2,r6
        mov (__mullong_PARM_2 + 1),r7
        mov (__mullong_PARM_2 + 2),#0x00
        mov (__mullong_PARM_2 + 3),#0x00
        mov dptr,#0x0399
        clr a
        mov b,a
        lcall   __mullong
        mov r4,dpl
        mov r5,dph
        mov r6,b
        mov r7,a
        mov __divslong_PARM_2,#0x07
        clr a
        mov (__divslong_PARM_2 + 1),a
        mov (__divslong_PARM_2 + 2),a
        mov (__divslong_PARM_2 + 3),a
        mov dpl,r4
        mov dph,r5
        mov b,r6
        mov a,r7
        lcall   __divslong
        mov r4,dpl
        mov r5,dph
        mov a,#0xd2
        clr c
        subb    a,r4
        mov dpl,a
        mov a,#0xff
        subb a,r5
        mov dph,a

        ; loop for sleep
        mov a,dpl
        anl a,dph
        cpl a
        jz ENDL$
    LOOP$:
        inc dptr
        mov a,dpl
        anl a,dph
        cpl a
        jnz LOOP$
    ENDL$:

    __endasm;

    /**
     * @node: disable SDCC warning
     */
    t = 0;
}

#else
    #warning Nothing to be done... User should remove .c file which is disabled by compile control macro from current directory.
#endif
