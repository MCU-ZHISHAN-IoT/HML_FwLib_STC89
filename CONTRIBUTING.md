Contribution Guidelines
=======================

Contributions to HML_FwLib_STC89 are welcome. If you find a bug or want to improve HML_FwLib_STC89 in another way, pull requests are appreciated.

For bigger changes, in order to avoid wasted effort, please open an issue to discuss the technical details before creating a pull request.

The further sections explain the process in more detail and provides some guidelines on how contributions should look like.


Coding Style
------------

* use 4 spaces for indentation
* no oneliners (conditions, loops, variable declarations ...)
* always use parenthesis for control structures
* use spaces around operators
* lines should not have trailing whitespace
* use spaces between function parameters
* use pronouncable variable names, not just a combination of letters
* use unified code comment style, you can refer to existing code

Example:

```c
/*****************************************************************************/
/** 
 * \author      Jiabin Hsu
 * \date        2018/10/08
 * \brief       calculate initial value for THx/TLx register
 * \param[in]   t: expected timing cycle(unit: us)
 * \return      initial value of timer-2 counter register(if return 0x0000, it 
 *              means that the time has over the limit)
 * \ingroup     TIM2
 * \remarks     
******************************************************************************/
uint16_t TIM2_calculateValue(uint16_t t)
{
    if((t*(MCU_FRE_CLK/1000000)/12) >= TIM2_MAXTICK)
    {
        return 0;
    }
    else
    {
        return (TIM2_MAXTICK + 1 - (t*(MCU_FRE_CLK/1000000)/12));
    }
}
```
