/*****************************************************************************/
/** 
 * \file        mem.c
 * \author      Weillun Fong | wlf@zhishan-iot.tk
 * \brief       operations for memory zone of MCU
 * \note        allow you to directly access the different memory areas of STC89
 *              series MCU
 * \version     v1.3
 * \ingroup     MEM
******************************************************************************/
 
#include "hml/mem.h"

#ifdef COMPILE_MEM

/*****************************************************************************/
/** 
 * \author      Weilun Fong
 * \date        
 * \brief       enable or disable pin ALE for Intel 8080 Bus
 * \param[in]   a: expected state
 * \return      none
 * \ingroup     MEM
 * \remarks     (1) disable ALE: ALE is emitted a constant rate of 1/3 Fsoc(the 
 *              oscillator frequency) in 6 clock mode,1/6 Fsoc in 12 clock mode
 *              (2) enable ALE: ALE is active only during a MOVX or MOVC instruction
******************************************************************************/
void MEM_cmd_ale(Action a)
{
    CONFB(AUXR, BIT_NUM_ALEOFF, a);
}

/*****************************************************************************/
/** 
 * \author      Weilun Fong
 * \date        
 * \brief       enable or disable pin ALE for Intel 8080 Bus
 * \param[in]   a: expected state
 * \return      none
 * \ingroup     MEM
 * \remarks     (1) there is a RAM area integrated insides STC89 MCUs and it's
 *              independent in logic
 *              (2) if you enable this function, this area will occupy address
 *              zone whose address range is 0000H~03FFH(1024 bytes) for RD+
 *              series, or 0000H~00FFH(256 bytes) for RC series. If not, the RAM
 *              area will be hidden and it's same with classical 8051 MCU under
 *              this situation.
******************************************************************************/
void MEM_cmd_internalExtendedRam(Action a)
{
    CONFB(AUXR, BIT_NUM_EXTRAM, (~a));
}

#else
    #warning Nothing to be done... User should remove .c file which is disabled by compile control macro from current directory.
#endif
