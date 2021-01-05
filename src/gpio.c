/*****************************************************************************/
/** 
 * \file        gpio.c
 * \author      Jiabin Hsu  | zsiothsu(at)zhishan-iot.tk
 * \author      Weilun Fong | wlf@zhishan-iot.tk
 * \brief       operations for GPIO module
 * \note        
 * \version     v1.3
 * \ingroup     GPIO
******************************************************************************/

#include "hml/gpio.h" 

#ifdef COMPILE_GPIO

/*****************************************************************************/
/** 
 * \author      Weilun Fong
 * \date        
 * \brief       configure state of target GPIO bit as SET or RESET
 * \param[in]   gpio: target GPIO port
 * \param[in]   pin : target GPIO pin
 * \param[in]   f   : expected state
 * \return      none
 * \ingroup     GPIO
 * \remarks     
******************************************************************************/
void GPIO_configBitValue(PERIPH_GPIO gpio, PERIPH_GPIO_PIN pin, FunctionalState f)
{
    if (f == RESET)
    {
        GPIO_resetBitValue(gpio, pin);
    }
    else
    {
        GPIO_setBitValue(gpio, pin);
    }
}

/*****************************************************************************/
/** 
 * \author      Weilun Fong
 * \date        2019/08/12
 * \brief       configure value specified GPIO port
 * \param[in]   gpio: target GPIO port
 * \param[in]   val : expected value(0x00~0xFF)
 * \return      none
 * \ingroup     GPIO
 * \remarks     
******************************************************************************/
void GPIO_configPortValue(PERIPH_GPIO gpio, byte val)
{
    switch (gpio)
    {
        case PERIPH_GPIO_0: P0 = val; break;
        case PERIPH_GPIO_1: P1 = val; break;
        case PERIPH_GPIO_2: P2 = val; break;
        case PERIPH_GPIO_3: P3 = val; break;
        case PERIPH_GPIO_4: P4 = val; break;
        default: break;
    }
}

/*****************************************************************************/
/** 
 * \author      Weilun Fong
 * \date        
 * \brief       get state of target GPIO pin
 * \param[in]   gpio: target GPIO port
 * \param[in]   pin : target GPIO pin
 * \return      SET or RESET
 * \ingroup     GPIO
 * \remarks     
******************************************************************************/
FunctionalState GPIO_getBitValue(PERIPH_GPIO gpio, PERIPH_GPIO_PIN pin)
{
    switch (gpio)
    {
        case PERIPH_GPIO_0: return GET_BIT(P0, pin);
        case PERIPH_GPIO_1: return GET_BIT(P1, pin);
        case PERIPH_GPIO_2: return GET_BIT(P2, pin);
        case PERIPH_GPIO_3: return GET_BIT(P3, pin);
        case PERIPH_GPIO_4: return GET_BIT(P4, pin);
        default: return RESET;
    }
}

/*****************************************************************************/
/** 
 * \author      Weilun Fong
 * \date        2019/06/30
 * \brief       get value of target GPIO port
 * \param[in]   gpio: target GPIO port
 * \return      current value of target GPIO port
 * \ingroup     GPIO
 * \remarks     
******************************************************************************/
byte GPIO_getPortValue(PERIPH_GPIO gpio)
{
    switch (gpio)
    {
        case PERIPH_GPIO_0: return P0;
        case PERIPH_GPIO_1: return P1;
        case PERIPH_GPIO_2: return P2;
        case PERIPH_GPIO_3: return P3;
        case PERIPH_GPIO_4: return P4;
        default: return 0x00;
    }
}

/*****************************************************************************/
/** 
 * \author      Weilun Fong
 * \date        
 * \brief       reset target GPIO pin
 * \param[in]   gpio: target GPIO port
 * \param[in]   pin : target GPIO pin
 * \return      none
 * \ingroup     GPIO
 * \remarks     
******************************************************************************/
void GPIO_resetBitValue(PERIPH_GPIO gpio, PERIPH_GPIO_PIN pin)
{
    switch (gpio)
    {
        case PERIPH_GPIO_0: CLR_BIT_MASK(P0, pin); break;
        case PERIPH_GPIO_1: CLR_BIT_MASK(P1, pin); break;
        case PERIPH_GPIO_2: CLR_BIT_MASK(P2, pin); break;
        case PERIPH_GPIO_3: CLR_BIT_MASK(P3, pin); break;
        case PERIPH_GPIO_4: CLR_BIT_MASK(P4, pin); break;
        default: break;
    }
}

/*****************************************************************************/
/** 
 * \author      Weilun Fong
 * \date        
 * \brief       set target GPIO pin
 * \param[in]   gpio: target GPIO port
 * \param[in]   pin : target GPIO pin
 * \return      none
 * \ingroup     GPIO
 * \remarks     
******************************************************************************/
void GPIO_setBitValue(PERIPH_GPIO gpio, PERIPH_GPIO_PIN pin)
{
    switch (gpio)
    {
        case PERIPH_GPIO_0: SET_BIT_MASK(P0, pin); break;
        case PERIPH_GPIO_1: SET_BIT_MASK(P1, pin); break;
        case PERIPH_GPIO_2: SET_BIT_MASK(P2, pin); break;
        case PERIPH_GPIO_3: SET_BIT_MASK(P3, pin); break;
        case PERIPH_GPIO_4: SET_BIT_MASK(P4, pin); break;
        default: break;
    }
}

/*****************************************************************************/
/** 
 * \author      Weilun Fong
 * \date        
 * \brief       toggle state of target GPIO pin
 * \param[in]   gpio: target GPIO port
 * \param[in]   pin : target GPIO pin
 * \return      none
 * \ingroup     GPIO
 * \remarks     
******************************************************************************/
void GPIO_toggleBitValue(PERIPH_GPIO gpio, PERIPH_GPIO_PIN pin)
{
    switch (gpio)
    {
        case PERIPH_GPIO_0: NOT_BIT_MASK(P0, pin); break;
        case PERIPH_GPIO_1: NOT_BIT_MASK(P1, pin); break;
        case PERIPH_GPIO_2: NOT_BIT_MASK(P2, pin); break;
        case PERIPH_GPIO_3: NOT_BIT_MASK(P3, pin); break;
        case PERIPH_GPIO_4: NOT_BIT_MASK(P4, pin); break;
        default: break;
    }
}

#else
    #warning Nothing to be done... User should remove .c file which is disabled by compile control macro from current directory.
#endif
