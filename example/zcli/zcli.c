/*****************************************************************************/
/** 
 * \file       zcli.c
 * \author     Weilun Fong | wlf@zhishan-iot.tk
 * \date       2020/02/02
 * \brief      a simple CLI demo file entirely runs on MCU, including basic
 *             information print functions and a I\O control function
 * \note       zCLI is just a toy for fun, don't expected rich functions because
 *             of limited on-chip resource. However, user can still develop a
 *             new CLI based on it
 *             This demo is inspired by https://github.com/nhivp/msp430-cli
 * \version    v1.3
 * \ingroup    generic
 * \remarks    test-board: ZM2.1; test-MCU: STC89C52RC
******************************************************************************/

/**
 * \note please disable following HML compile macro because of limited on-chip
 *       zone:
 *        (1) __CONF_COMPILE_EXTI
 *        (2) __CONF_COMPILE_ISP
 *        (3) __CONF_COMPILE_WDT
 */

/*****************************************************************************
 *                             header file                                   *
 *****************************************************************************/
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "hml/hml.h"

/*****************************************************************************
 *                                macro                                      *
 *****************************************************************************/
/**
 * \brief baudrate of zcli
 */
#define ZCLI_BAUDRANTE      115200

/**
 * \brief zcli max arguments number support
 */
#define ZCLI_MAX_ARGS       3

/**
 * \brief time stamp
 */
#define ZCLI_TIMESTAMP       "20200202"

/**
 * \brief length define for zcli
 */
#define ZCLI_CMD_LEN         8
#define ZCLI_ARGS_LEN        8
#define ZCLI_STRING_LEN      24
#define ZCLI_TABLE_LEN(x)    sizeof(x)/sizeof(*(&x[0]))

/**
 * \brief ASCII character mark
 */
#define ASCII_ETX            0x03  /* end of text(ctrl+c) */
#define ASCII_BS             0x08  /* backspace */
#define ASCII_TAB            0x09  /* horizontal tab */
#define ASCII_CR             0x0D  /* carriage return */
#define ASCII_DEL            0x7F  /* delete */

/*****************************************************************************
 *                             type define                                   *
 *****************************************************************************/
/**
 * \brief compatible with putchar() function change
 * \quote (sdcc official) sdcc 3.7.0: Changed putchar() prototype from void putchar(char)
 *        to int putchar(int) to improve standard-compliance and allow error reporting.
 */
#if ((__SDCC_VERSION_MAJOR > 3) || ((__SDCC_VERSION_MAJOR == 3 ) && (__SDCC_VERSION_MINOR >= 7)))
typedef int PUTCHAR_T;
typedef int PUTCHAR_CH_T;
#else
typedef void PUTCHAR_T;
typedef char PUTCHAR_CH_T;
#endif

/**
 * \brief function pointer for zcli action
 */
typedef int8_t (*zcli_action_t)(void);

/*****************************************************************************
 *                           structure define                                *
 *****************************************************************************/

/**
 * \brief command module
 */
typedef struct
{
    char command[ZCLI_CMD_LEN];
    char description[64];
    zcli_action_t action;
} zcli_command;

/*****************************************************************************
 *                           variable define                                 *
 *****************************************************************************/
/**
 * \brief command list
 */
static __code zcli_command zcli_command_table[] =
{
    /* Command,   Description,                       Command Action Function */
    { "?"       , "?   - Same as \"h\""            , zcli_action_h },
    { "c"       , "c   - Clear screen"             , zcli_action_c },
    { "h"       , "h   - Show help information"    , zcli_action_h },
    { "hi"      , "hi  - Say hello"                , zcli_action_hi },
    { "io"      , "io <port> <val> - Set value of target IO, e.g.: io p1 0xab", zcli_action_io },
    { "re"      , "re  - Reboot MCU"               , zcli_action_re },
    { "si"      , "si  - Show system information"  , zcli_action_si },
    { "v"       , "v   - Show version information" , zcli_action_v }
};

/**
 * \brief ETX flag
 */
static bool g_isEtx = false;

/**
 * \brief zcli PS1
 */
static const char __code zcli_str_ps1[] = "\r\n> ";

/**
 * \brief clear one character
 */
static const char __code zcli_str_backspace[] = "\b \b";

/**
 * \brief other zcli string
 */
static const char __code terminal_str_clearLine[] = "\33[2K\r\r> ";
static const char __code zcli_str_authorInfo[] = "\r\nWritten by Weilun Fong \
<wlf@zhishan-iot.tk>";
static const char __code zcli_str_commited[] = "\r\n\033[1m\033[32mCommitted!\033[0m";
static const char __code zcli_str_copyrigth[] = "\r\nzCLI v0.0 2020 (c) ZHISHAN-IoT";
static const char __code zcli_str_hello[] = "\r\nHello! I'm zCLI!";
static const char __code zcli_str_helpNote[] = "\r\nPlease input command as follows:";
static const char __code zcli_str_invalidCommand[] = "\r\nWtf? Enter '?' for usage";
static const char __code zcli_str_invalidCommandFormat[] = "\r\nInvalid command format!";
static const char __code zcli_str_noSuchIo[] = "\r\nNo such I/O!";
static const char __code zcli_str_reboot[] = "\r\nMCU will reboot after 3s ";
static const char __code zcli_str_systemInfo[7][32] = { \
 "\r\nWTD\t: yes", \
 "\r\nI\\O\t: 32+5 I\\O pins", \
 "\r\nTimer\t: 3 16-bit timer", \
 "\r\nClock\t: 11.0592MHz", \
 "\r\nBoard\t: ZM2.1", \
 "\r\nArch\t: Intel mcs-51", \
 "\r\nMCU\t: STC Micro STC89C52RC"
};

/**
 * \brief UART receive buffer
 */
char __pdata g_buf[ZCLI_STRING_LEN];

/**
 * \brief buffer for command keyword and parameters
 */
char __pdata g_commandBuffer[ZCLI_CMD_LEN];    /* buffer for read command */
char __pdata g_lastInput[ZCLI_STRING_LEN];     /* store last input */
char __pdata g_commandArguments[ZCLI_MAX_ARGS][ZCLI_ARGS_LEN];

/**
 * \brief buffer index
 */
uint16_t g_index = 0;

/**
 * \brief invalid command flag
 */
bool g_isValidCommand = false;

/**
 * \brief printf() can't print data in CODE/XRAM area, so use UART_sendString
 *        instead of it
 */
#define zcli_printString(__VA_STRING__)    UART_sendString(__VA_STRING__)

/*****************************************************************************
 *                          function declare                                 *
 *****************************************************************************/
uint16_t axtoi(char *str);
void sys_init(void);
int8_t zcli_action_c(void);
int8_t zcli_action_h(void);
int8_t zcli_action_hi(void);
int8_t zcli_action_io(void);
int8_t zcli_action_re(void);
int8_t zcli_action_si(void);
int8_t zcli_action_v(void);
void zcli_clearMemory(void);
void zcli_getCommand(char* cmd);
void zcli_getArguments(void);
void zcli_startup(void);

/*****************************************************************************/
/** 
 * \author      Weilun Fong
 * \date        2020/02/02
 * \brief       convert hexadecimal to integer
 * \param[in]   str: pointer to ascii string
 * \return      none
 * \ingroup     example
 * \remarks     result
******************************************************************************/
uint16_t axtoi(char *str)
{
    uint8_t i = strlen(str);
    uint8_t j = 1;
    uint16_t res = 0;

    while (i--)
    {
        if ((str[i] >= '0') && (str[i] <= '9'))
        {
            res = res + j*(str[i] - '0');
        }
        else if ((str[i] >= 'a') && (str[i] <= 'f'))
        {
            res = res + j*(str[i] - 'a' + 0xA);
        }
        j = j * 0x10;
    }

    return res;
}

/*****************************************************************************/
/** 
 * \author      Weilun Fong
 * \date        2020/02/02
 * \brief       override putchar function
 * \param[in]   ch: expected ascii character
 * \return      none
 * \ingroup     example
 * \remarks     
******************************************************************************/
PUTCHAR_T putchar(PUTCHAR_CH_T ch)
{
    UART_sendByte((char)ch);

    #if ((__SDCC_VERSION_MAJOR > 3) || ((__SDCC_VERSION_MAJOR == 3 ) && (__SDCC_VERSION_MINOR >= 7)))
    return ch;
    #endif
}

/*****************************************************************************/
/** 
 * \author      Weilun Fong
 * \date        2020/02/02
 * \brief       initial MCU
 * \param[in]   
 * \return      none
 * \ingroup     example
 * \remarks     
******************************************************************************/
void sys_init(void)
{
    UART_configTypeDef uc;

    MEM_cmd_internalExtendedRam(ENABLE);

    uc.baudrate          = ZCLI_BAUDRANTE;
    uc.baudGenerator     = PERIPH_TIM_2;
    uc.interruptState    = ENABLE;
    uc.interruptPriority = UTIL_interruptPriority_0;
    uc.mode              = UART_mode_1;
    uc.multiBaudrate     = DISABLE;
    uc.receiveState      = ENABLE;

    UART_config(&uc);
    enableAllInterrupts();
}

/*****************************************************************************/
/** 
 * \author      Weilun Fong
 * \date        2020/02/02
 * \brief       clear screen
 * \param[in]   
 * \return      execute status code
 * \ingroup     example
 * \remarks     when terminal accept byte 0x0C, it will clean screen
******************************************************************************/
int8_t zcli_action_c(void)
{
    UART_sendByte(0x0C);
    return 0;
}

/*****************************************************************************/
/** 
 * \author      Weilun Fong
 * \date        2020/02/02
 * \brief       show help information
 * \param[in]   
 * \return      execute status code
 * \ingroup     example
 * \remarks     print all commands and description for usage
******************************************************************************/
int8_t zcli_action_h(void)
{
    uint8_t i = 0;

    zcli_printString(zcli_str_helpNote);
    for (i = 0; i < ZCLI_TABLE_LEN(zcli_command_table); i++)
    {
        printf("\r\n%s", zcli_command_table[i].description);
    }

    return 0;
}

/*****************************************************************************/
/** 
 * \author      Weilun Fong
 * \date        2020/02/02
 * \brief       say hello via zcli
 * \param[in]   
 * \return      execute status code
 * \ingroup     example
 * \remarks     
******************************************************************************/
int8_t zcli_action_hi(void)
{
    zcli_printString(zcli_str_hello);
    return 0;
}

/*****************************************************************************/
/** 
 * \author      Weilun Fong
 * \date        2020/02/05
 * \brief       I/O control
 * \param[in]   
 * \return      execute status code
 * \ingroup     example
 * \remarks     command format is fixed with "io <port> <val>", which gap with
                space
******************************************************************************/
int8_t zcli_action_io(void)
{
    uint8_t i = 0;
    char hexString[3];
    PERIPH_GPIO p = PERIPH_GPIO_0;

    /* get first parameter value, jump "io" first */
    i = 0x2;
    if ((g_commandArguments[1][0] == 'p'))
    {
        switch (g_commandArguments[1][1])
        {
            case '0': p = PERIPH_GPIO_0; break;
            case '1': p = PERIPH_GPIO_1; break;
            case '2': p = PERIPH_GPIO_2; break;
            case '3': p = PERIPH_GPIO_2; break;
            case '4': p = PERIPH_GPIO_4; break;
            default: zcli_printString(zcli_str_noSuchIo); return -1;
        }
    }
    else
    {
        zcli_printString(zcli_str_invalidCommandFormat);
        return -1;
    }

    /* get second parameter value, jump one blank first */
    i++;
    /* get hex number */
    if ((g_commandArguments[2][0] == '0') && (g_commandArguments[2][1] == 'x'))
    {
        hexString[1] = g_commandArguments[2][2];
        hexString[0] = g_commandArguments[2][3];
        hexString[2] = '\0';
        GPIO_configPortValue(p, (byte)axtoi(hexString));
        zcli_printString(zcli_str_commited);
        return 0;
    }
    else
    {
        zcli_printString(zcli_str_invalidCommandFormat);
        return -1;
    }
}

/*****************************************************************************/
/** 
 * \author      Weilun Fong
 * \date        2020/02/02
 * \brief       reboot MCU
 * \param[in]   
 * \return      execute status code
 * \ingroup     example
 * \remarks     
******************************************************************************/
int8_t zcli_action_re(void)
{
    uint8_t i = 3;

    zcli_printString(zcli_str_reboot);
    while (i--)
    {
        if (g_isEtx == true)
        {
            g_isEtx = false;
            return -1;
        }
        else
        {
            printf(".");
        }
        sleep(1000);
    }
    RST_reset(RST_bootarea_ap);

    return 0;
}

/*****************************************************************************/
/** 
 * \author      Weilun Fong
 * \date        2020/02/02
 * \brief       show system information
 * \param[in]   
 * \return      execute status code
 * \ingroup     example
 * \remarks     
******************************************************************************/
int8_t zcli_action_si(void)
{
    uint8_t i = ZCLI_TABLE_LEN(zcli_str_systemInfo);

    while (i--)
    {
        printf("%s", zcli_str_systemInfo[i]);
    }

    return 0;
}

/*****************************************************************************/
/** 
 * \author      Weilun Fong
 * \date        2020/02/02
 * \brief       show version information
 * \param[in]   
 * \return      execute status code
 * \ingroup     example
 * \remarks     
******************************************************************************/
int8_t zcli_action_v(void)
{
    printf("\r\nzCLI v0.0 [%s]", ZCLI_TIMESTAMP);
    zcli_printString(zcli_str_authorInfo);
    return 0;
}

/*****************************************************************************/
/** 
 * \author      Weilun Fong
 * \date        2020/02/07
 * \brief       clear zcli memory
 * \param[in]   
 * \return      none
 * \ingroup     example
 * \remarks     
******************************************************************************/
void zcli_clearMemory(void)
{
    g_index = 0;
    memset(g_buf, '\0', ZCLI_STRING_LEN);
    memset(g_commandArguments[0], '\0', ZCLI_STRING_LEN);
    memset(g_commandBuffer, '\0', ZCLI_CMD_LEN);
}

/*****************************************************************************/
/** 
 * \author      Weilun Fong
 * \date        2020/02/02
 * \brief       get command string
 * \param[in]   cmd: pointer for string store
 * \return      none
 * \ingroup     example
 * \remarks     
******************************************************************************/
void zcli_getCommand(char* cmd)
{
    zcli_getArguments();
    strncpy((char*)cmd, (char*)g_commandArguments[0], strlen(g_commandArguments[0]));
}

/*****************************************************************************/
/** 
 * \author      Weilun Fong
 * \date        2020/02/07
 * \brief       split user input and obtain all arguments
 * \param[in]   
 * \return      none
 * \ingroup     example
 * \remarks     parse result will store in g_commandArguments
******************************************************************************/
void zcli_getArguments(void)
{
    uint8_t aLen = 0;   /* current arguments length */
    uint8_t aNum = 0;   /* arguments item number */
    uint8_t i = 0;

    for (i = 0; i < g_index; i++)
    {
        if ((g_buf[i] == '\0')
         || (g_buf[i] == ' ')
         || (g_buf[i] == ASCII_CR))
        {
            strncpy((char*)g_commandArguments[aNum++], (char*)&g_buf[i - aLen], aLen);
            aLen = 0;
        }
        else
        {
            aLen++;
        }

        if (aNum > ZCLI_MAX_ARGS)
        {
            break;
        }
    }
}

/*****************************************************************************/
/** 
 * \author      Weilun Fong
 * \date        2020/02/02
 * \brief       show startup information
 * \param[in]   
 * \return      none
 * \ingroup     example
 * \remarks     
******************************************************************************/
void zcli_startup(void)
{
    zcli_action_c();
    zcli_printString(zcli_str_copyrigth);
    zcli_printString(zcli_str_ps1);
}

/*****************************************************************************/
/** 
 * \author      Weilun Fong
 * \date        2020/02/02
 * \brief       main function
 * \param[in]   
 * \return      none
 * \ingroup     example
 * \remarks     
******************************************************************************/
void main(void)
{
    uint8_t i = 0;

    /**
     * \brief zcli startup works
     */
    sys_init();
    zcli_clearMemory();
    zcli_startup();

    /**
     * \brief zcli main work
     */
    while (true)
    {
        while (g_isValidCommand == true)
        {
            zcli_getCommand(g_commandBuffer);
            if (g_commandBuffer[0] != '\0')
            {
                for (i = 0; i < ZCLI_TABLE_LEN(zcli_command_table); i++)
                {
                    /* jump out when target command matches */
                    if (!strcmp((char *)g_commandBuffer, (char*)zcli_command_table[i].command))
                    {
                        break;
                    }
                }
                if (i < ZCLI_TABLE_LEN(zcli_command_table))     /* make sure and execute action */
                {
                    if (g_isEtx == false)
                    {
                        zcli_command_table[i].action();
                    }
                    else
                    {
                        g_isEtx = false;
                    }
                }
                else
                {
                    zcli_printString(zcli_str_invalidCommand);
                }
            }
            /* display header */
            zcli_printString(zcli_str_ps1);
            zcli_clearMemory();
            g_isValidCommand = false;
        }
    }
}

/*****************************************************************************/
/** 
 * \author      Weilun Fong
 * \date        2020/02/02
 * \brief       interrupt service function for UART
 * \param[in]   
 * \return      none
 * \ingroup     example
 * \remarks     special ascii character: BS, CR, DEL, ETX
******************************************************************************/
void uart_isr(void) __interrupt SI0_VECTOR
{
    char rBuf = 0x00;

    disableAllInterrupts();  /* avoid disturb */

    /**
     * \brief handle data when MCU receives data
     */
    if (RI == SET)
    {
        rBuf = UART_getByte();
        if (g_index > ZCLI_STRING_LEN)
        {
            putchar(rBuf);
        }
        else
        {
            switch (rBuf)
            {
                /* backspace & delete support */
                case ASCII_BS:
                case ASCII_DEL:
                {
                    g_buf[g_index] = '\0';
                    if (g_index >= 1)       /* clear last character */
                    {
                        zcli_printString(zcli_str_backspace);
                        g_index--;
                    }
                } break;
                /* regard '\r' as end flag, and increase value of index */
                case ASCII_CR:
                {
                    g_buf[g_index] = '\0';
                    g_isValidCommand = true;
                    memcpy(g_lastInput, g_buf, ZCLI_STRING_LEN);
                    /* avoid buffer overflow */
                    if (g_index < ZCLI_STRING_LEN)
                    {
                        g_index++;
                    }
                } break;
                /* ctrl+c support */
                case ASCII_ETX:
                {
                    memset(g_buf, '\0', g_index + 1);
                    zcli_printString("^C");
                    zcli_printString(zcli_str_ps1);
                    g_index = 0;
                    g_isEtx = true;
                } break;
                /* tab support */
                case ASCII_TAB:
                {
                    /* obtain history command */
                    memcpy(g_buf, g_lastInput, ZCLI_STRING_LEN);
                    g_index = sizeof(g_buf) / sizeof(char);
                    zcli_printString(terminal_str_clearLine);
                    zcli_printString(g_buf);
                } break;
                /* other characters */
                default:
                {
                    /* visible characters */
                    if ((rBuf >= 32) && (rBuf <= 126))
                    {
                        putchar(rBuf);
                        g_buf[g_index] = tolower(rBuf);
                    }
                    else
                    {
                        g_buf[g_index--] = '\0';
                    }
                    /* avoid buffer overflow */
                    if (g_index < ZCLI_STRING_LEN)
                    {
                        g_index++;
                    }
                } break;
            }
            RI = RESET;
        }
    }

    enableAllInterrupts();   /* recover */
}
