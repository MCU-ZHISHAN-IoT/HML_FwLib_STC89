/*****************************************************************************/
/** 
 * \file        bit.h
 * \author      Weilun Fong | wlf@zhishan-iot.tk
 * \brief       bit operation
 * \note        this is a general purpose header file
 * \version
 * \ingroup     generic
******************************************************************************/
 
#ifndef ___HML_BIT_H___
#define ___HML_BIT_H___

/*****************************************************************************
 *                             header file                                   *
 *****************************************************************************/
#include <iso646.h>

/*****************************************************************************
 *                                macro                                      *
 *****************************************************************************/

/**
 * \brief constants define
 */
#define BITS_PER_BYTE           8

/**
 * \brief bit operation
 */
#define CLR(x)                  (complement(1U << (x % BITS_PER_BYTE)))
#define SET(x)                  (1U << (x % BITS_PER_BYTE))

/**
 * \brief bit operation for register
 */
#define CLRB(reg,x)             (reg and_eq (complement(1U << (x % BITS_PER_BYTE))))
#define NOTB(reg,x)             (reg xor_eq (1U << (x % BITS_PER_BYTE)))
#define SETB(reg,x)             (reg or_eq  (1U << (x % BITS_PER_BYTE)))
#define TESTB(val,x)            (not(not(val bitand (1U << (x % BITS_PER_BYTE)))))
#define CONFB(reg,x,val)        (reg = (reg bitand (complement(1U << (x % BITS_PER_BYTE)))) bitor (val << x))

/**
 * \brief bit mask operation
 */
#define BIT_MASK(x)             SET(x)
#define CLR_BIT_MASK(reg,mask)  (reg and_eq (complement(mask)))
#define GET_BIT(reg,mask)       (not(not(reg bitand mask)))
#define NOT_BIT_MASK(reg,mask)  (reg xor_eq mask)
#define SET_BIT_MASK(reg,mask)  (reg or_eq mask)

#endif
