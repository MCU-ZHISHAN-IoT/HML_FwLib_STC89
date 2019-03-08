/*
 * @Author:
 *  #Weilun Fong | wlf(at)zhishan-iot.tk
 * @E-mail:mcu(at)zhishan-iot.tk
 * @File-description:bit operation
 * @Required-compiler:SDCC
 * @Support-mcu:general purpose header file
 * @Version:V1
 */
 
#ifndef ___BIT_H___
#define ___BIT_H___

/* ----- @header file ----- */
#include <iso646.h>

/* ----- @macro define ----- */
/* --- constants define --- */
#define BITS_PER_BYTE           8
/* --- bit operation --- */
#define CLR(x)                  (complement(1U << (x % BITS_PER_BYTE)))
#define SET(x)                  (1U << (x % BITS_PER_BYTE))
/* --- bit operation for register */
#define CLRB(reg,x)             (reg and_eq (complement(1U << (x % BITS_PER_BYTE))))
#define NOTB(reg,x)             (reg xor_eq (1U << (x % BITS_PER_BYTE)))
#define SETB(reg,x)             (reg or_eq  (1U << (x % BITS_PER_BYTE)))
#define TESTB(val,x)            (not(not(val bitand (1U << (x % BITS_PER_BYTE)))))
#define CONFB(reg,x,val)        (reg = (reg and_eq (complement(1U << (x % BITS_PER_BYTE)))) bitor (val << x))
 
/* --- bit mask function --- */
#define BIT_MASK(x)             SET(x)
#define CLR_BIT_MASK(reg,mask)  (reg and_eq (complement(mask)))
#define GET_BIT(reg,mask)       (not(not(reg bitand mask)))
#define NOT_BIT_MASK(reg,mask)  (reg xor_eq mask)
#define SET_BIT_MASK(reg,mask)  (reg or_eq mask)

#endif
