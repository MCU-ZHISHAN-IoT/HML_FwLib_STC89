/*
 * @Author:
 *  #Jiabin Hsu | zsiothsu(at)zhishan-iot.tk
 * @Compiler:SDCC v3.6.0
 * @E-mail:mcu(at)zhishan-iot.tk
 * @File-description:show how to use HML_FwLib_STC89 to toggle GPIO bit
 * @Test-board:TS51-V2.0
 * @Test-mcu:STC89C52RC
 * @Version:V1
 */
 
#include "conf.h"

/* ----- @main ----- */
void main(void)
{
    GPIO_resetBitValue(PERIPH_GPIO_4,PERIPH_GPIO_PIN_5);
    
    while(true)
    {
        sleep(500);
        GPIO_toggleBitValue(PERIPH_GPIO_4,PERIPH_GPIO_PIN_5);
    }
}
