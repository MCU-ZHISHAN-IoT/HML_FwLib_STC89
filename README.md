# HML_FwLib_STC89
[![Jenkins](https://img.shields.io/jenkins/build?jobUrl=http%3A%2F%2Fjenkins.zhishan-iot.tk%3A12463%2Fjob%2FHML_FwLib_STC89)](http://jenkins.zhishan-iot.tk:12463/job/HML_FwLib_STC89)
[![GitHub repo size](https://img.shields.io/github/repo-size/MCU-ZHISHAN-IoT/HML_FwLib_STC89)](https://github.com/MCU-ZHISHAN-IoT/HML_FwLib_STC89)
[![GitHub](https://img.shields.io/github/license/MCU-ZHISHAN-IoT/HML_FwLib_STC89)](https://github.com/MCU-ZHISHAN-IoT/HML_FwLib_STC89/blob/master/LICENSE)
[![GitHub tag (latest by date)](https://img.shields.io/github/v/tag/MCU-ZHISHAN-IoT/HML_FwLib_STC89?color=26a69a)](https://github.com/MCU-ZHISHAN-IoT/HML_FwLib_STC89/tags)

## What is HML_FwLib_STC89
HML_FwLib_STC89 is a important member component of HML firmware library, **providing a group of interface functions for users to 
operate on-chip resource of STC89 MCUs**, including GPIO, ISP, timer, UART, external interrupt and watchdog. The STC89 MCU is a 
kind of Intel MCS-51 based MCU which released by [STC Micro](http://www.stcmcu.com/)(*宏晶*), and it's one of the most widely 
used MCUs series in Mainland, China. This series MCU have more on-chip resource than classical 8051 MCU.

We intend to provide a lite and easy-use firmware library that can help future developers to complete projects based on STC89 
MCUs more easily and quickly. All source codes are written in C language and for [SDCC compiler](http://sdcc.sourceforge.net/),
i.e., it can only be compiled by SDCC. This choice is motivated by the fact that SDCC is free and highly efficient, while there
are very few examples of application about SDCC on the Internet. We hope that, as one of the early attempts to develop MCU 
projects using SDCC, this work will make SDCC become more popular among MCU developers.

Please visit [detail page](https://hw.zhishan-iot.tk/page/hml/detail/fwlib_stc89.html) for more information to get started it!

## Feature
+ :dart:Based on [SDCC compiler](http://sdcc.sourceforge.net/).
+ Cover all on-chip resource of STC89 series MCUs.
+ Open all source code on [Github](https://github.com) and licensed under the [WTFPL2](http://wtfpl2.com/).
+ Readable code and provide examples to help you get started it.
+ Attached Makefile offers a good reference for developers.

## What's working
Here is a list of the all on-chip peripheral drivers and examples that need to be ported.

| Peripheral | Description | Status |
| --- | --- | --- |
| extended bus | Intel 8080 bus receiver/transmitter | supported |
| EXTI | extern interrupt | supported |
| GPIO | I/O peripheral | supported  |
| ISP | internal EEPROM | supported  |
| RST | reset control | supported |
| TIM | timer | supported |
| UART | universal asynchronous receiver/transmitter | supported |
| WDT | watchdog | supported |

## Prerequisite
+ [GNU Make](http://www.gnu.org/software/make/manual/make.html)(recommend)
+ [SDCC compiler](http://sdcc.sourceforge.net/)
+ *\[for Windows\]* Unix shell tools([msys](http://www.mingw.org/wiki/MSYS), [Cygwin](http://www.cygwin.com/), [GNUwin32](http://gnuwin32.sourceforge.net/)) needed by makefile for SDCC

## Usage
### file structure
```bash
HML_FwLib_STC89
├─doc      # store related documents about HML_FwLib_STC89
├─example  # provide some example files with *.c format to help users learn about HML_FwLib_STC89
├─inc      # include all header files(*.h) of HML_FwLib_STC89
├─obj      # store all output files, including *.hex,*.ihx,*.lk,*.rel and others during compilation
├─src      # store all source files(*.c) of HML_FwLib_STC89
├─usr      # store makefile and a source file which includes main function
├─LICENSE  # license of HML_FwLib_STC89
└─VERSION  # version code of HML_FwLib_STC89
```
### configuration
There are several parameters with compile macro format need to be configured by user manually. They are all defined in 
*hml/conf.h*.
#### \_\_CONF\_COMPILE\_xxx (for conditional compilation)
In order to ensure the projects based on HML_FwLib_STC89 can run on STC89 MCUs with limited on-chip flash space, the developers 
can modify value of the macro definition named `__CONF_COMPILE_xxx` in *hml/conf.h* as `0` to specify which piece of code will not
take part in compilation, then it will reduce size of .hex file finally. If user only use GPIO module, then user just need to 
enable `__CONF_COMPILE_GPIO` macro in *hml/conf.h*. Some macros for conditional compilation rely on others. For example, before 
you enable the macro definition `__CONF_COMPILE_UART`, the macro `__CONF_COMPILE_TIM` and `__CONF_COMPILE_TIM2` should be 
enabled, otherwise the compilation would be failed.
####  \_\_CONF\_FRE\_CLKIN
This macro marks frequency of clock source, including extern crystal oscillator or internal RC oscillating circuit, and it's 
defined in *conf.h*.
#### \_\_CONF\_MCU\_MODEL
This macro marks the model of target MCU and is defined in *hml/conf.h*.
#### \_\_CONF\_MCU\_PRESCALER
This macro is used to specify MCU prescaler factor. The value must be 6 or 12, and they stand for 6T mode and 12T mode.

Above macros can be set via make command line interface variable or a config Makefile (refer to default config file *usr/Makefile.config*).

### code & compile
There is a source file named *test.c* under *usr* directory, we have put a main function here. User can add and modify own code
here, then enter <kbd>make -j</kbd> in terminal, the Makefile will work and complete compilation. From version V0R3, you can 
enter <kbd>make help</kbd> to get all usages, and former version makefile only support <kbd>make</kbd>, <kbd>make clean</kbd>,
<kbd>make mostlyclean</kbd>(change into <kbd>make distclean</kbd> now)

Certainly, you can just add *inc* and *src* directory into your project, and write your own makefile to build a custom project. 

## Contributing
Welcome PR or issues from you! Please read our [CONTRIBUTING.md](https://github.com/MCU-ZHISHAN-IoT/HML_FwLib_STC89/blob/master/CONTRIBUTING.md)

## License
HML_FwLib_STC89 is licensed under the [WTFPL2](http://wtfpl2.com/).

## Team

|member        | role              |e-mail                        |
|--------------|-------------------|------------------------------|
| Amy Chung    | Testing           |[zhongliguo@zhishan-iot.tk](mailto:zhongliguo@zhishan-iot.tk) |
| Jiabin Hsu   | MCU developer     |[zsiothsu@zhishan-iot.tk](mailto:zsiothsu@zhishan-iot.tk) |
| Weilun Fong  | **Director**      |[wlf@zhishan-iot.tk](mailto:wlf@zhishan-iot.tk) |
