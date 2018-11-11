# HML_FwLib_STC89
[![BuildStatus](https://img.shields.io/badge/build-passing-brightgreen.svg)](https://hw.zhishan-iot.tk/page/hml/detail/fwlib_stc89.html)
[![License](https://img.shields.io/badge/license-WTFPL2-blue.svg)](http://wtfpl2.com/)
[![MCU](https://img.shields.io/badge/mcu-stc89-orange.svg)](http://www.stcmcu.com/)
## What is HML_FwLib_STC89
HML_FwLib_STC89 is a member component of HML firmware library, **providing a group of interface functions for users to operate on-chip resource of STC89 MCUs**, including GPIO, ISP, timer, UART, external interrupt and watchdog. The STC89 MCU is a kind of Intel MCS-51 based MCU which released by [STC Micro](http://www.stcmcu.com/)(*宏晶*), and it's one of the most widely used MCUs series in Mainland, China. This series MCU have more on-chip resource than classical 8051 MCU.

We intend to provide a lite and easy-use firmware library that can help future developers to complete projects based on STC89 MCUs more easily and quickly. All source codes are written in C language and for [SDCC compiler](http://sdcc.sourceforge.net/), i.e., it can only be compiled by SDCC. This choice is motivated by the fact that SDCC is free and highly efficient, while there are very few examples of application about SDCC on the Internet. We hope that, as one of the early attempts to develop MCU projects using SDCC, this work will make SDCC become more popular among MCU developers.<br>

Please visit [detail page](https://hw.zhishan-iot.tk/page/hml/detail/fwlib_stc89.html) for more information to get started it!

## Feature
+ :dart:Based on [SDCC compiler](http://sdcc.sourceforge.net/).
+ Cover all on-chip resource of STC89 series MCUs.
+ Open all source code on [Github](https://github.com) and licensed under the [WTPL2](http://wtfpl2.com/).
+ Readable code and provide examples to help you get started it.

## Prerequisite
+ [GNU Make](http://www.gnu.org/software/make/manual/make.html)(recommend)
+ [SDCC compiler](http://sdcc.sourceforge.net/)

## Usage
### file structure
```bash
HML_FwLib_STC89
├─doc      #store related documents about HML_FwLib_STC89
├─example  #provide some example files with *.c format to help users learn about HML_FwLib_STC89
├─inc      #include all header files(*.h) of HML_FwLib_STC89
├─obj      #store all output files, including *.hex,*.ihx,*.lk,*.rel and others during compilation
├─src      #store all source files(*.c) of HML_FwLib_STC89
└─usr      #store makefile and a source file which includes main function
```
### configuration
There are several parameters need to be configured by user manually.
#### \_FRE\_OSC\_
The macro mark frequency of clock source, including extern crystal oscillator or internal RC oscillating circuit, and it's defined in *macro.h*. The default value is `11059200L`.
#### \_MCU\_MODEL\_
The macro mark the model of target MCU and is defined in *macro.h*. The default value is `_MCU_STC89C52RC_`.
#### conditional compilation
In order to ensure the projects based on HML_FwLib_STC89 can be downloaded into the limited on-chip flash space of STC89 MCUs, the developers can modify the macro definition named `___COMPILE_XXX___` in *macro.h* to specify which piece of code should be compiled, thus to reduce the size of the HEX file. If user only use GPIO module, then user just need to enable `___COMPILE_GPIO___` macro definition in macro.h. Some macros for conditional compilation rely on others. For example, before you define the macro definition `___COMPILE_UART___`, the macro `___COMPILE_EXTI___`, `___COMPILE_TIM___` and `___COMPILE_TIM2___` should be defined, otherwise the compilation would be failed.
### code & compilation
There is a source file named *test.c* under *usr* directory, we have put a main function here. User can add and modify own code here, then enter <kbd>make</kbd> in terminal(you had better use [Cygwin](http://www.cygwin.com/) instead of cmd.exe under Windows), the Makefile will work and complete compilation. Certainly, you can just add *inc* and *src* directory into your project structure, and write your own makefile to build a custom project. 

## Contributing
Welcome suggestions and contribution from you! You can fork it or contact us via *[mcu@zhishan-iot.tk](mailto:mcu@zhishan-iot.tk)*.

## License
HML_FwLib_STC89 is licensed under the [WTPL2](http://wtfpl2.com/).

##  Team

|member        | role              |e-mail                        |
|--------------|-------------------|------------------------------|
| Amy Chung    | Testing           |[zhongliguo@zhishan-iot.tk](mailto:zhongliguo@zhishan-iot.tk) |
| Jiabin Hsu   | MCU developer     |[zsiothsu@zhishan-iot.tk](mailto:zsiothsu@zhishan-iot.tk) |
| Weilun Fong  | **Director**      |[wlf@zhishan-iot.tk](mailto:wlf@zhishan-iot.tk) |
