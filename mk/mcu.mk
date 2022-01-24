#!/usr/bin/make

# ------------------------------------------------------------------------
# Author     : Weilun Fong | wlf@zhishan-iot.tk
# Date       : 2021-10-24
# Description: MCU parameters config Makefile
# E-mail     : mcu@zhishan-iot.tk
# Make-tool  : GNU Make (http://www.gnu.org/software/make/manual/make.html)
# Page       : https://hw.zhishan-iot.tk/page/hml/detail/fwlib_stc89.html
# Project    : HML_FwLib_STC89
# Version    : v0.4.0
# ------------------------------------------------------------------------

# Print note information
$(info $(SPACE)- Collect MCU config information)

# Configuration parameter translation
# [CLKFRE] frequency of MCU clock
ifneq ($(CLKFRE),)
    ifeq ($(shell $(ECHO) $(CLKFRE) | $(GREP) '^[[:digit:]]*$$'),)
        $(error invalid CLKFRE value)
    else
        CLOCK_FREQUENCY := $(CLKFRE)
    endif
else
    CLOCK_FREQUENCY := 11059200
endif
# [PRESCALER] MCU prescaler
ifeq ($(PRESCALER),)
    PRESCALER_FACTOR ?= 12
else ifeq ($(PRESCALER),6)
    PRESCALER_FACTOR := 6
else ifeq ($(PRESCALER),12)
    PRESCALER_FACTOR := 12
else
    $(error invalid PRESCALER value, the value must be 6 or 12!)
endif

# [CODE] internal ROM
ifneq ($(CODE),)
    export CODE_SIZE := $(shell $(ECHO) $(CODE) | $(AWK) '{printf("%d",$$1*1024)}')
endif
# [IRAM] internal RAM
# for stc89, this value is fixed to 256
export IRAM_SIZE := 256
# [XRAM] external RAM
ifneq ($(XRAM),)
    export XRAM_SIZE := $(shell $(ECHO) $(XRAM) | $(AWK) '{printf("%d",$$1*1024)}')
endif

# [MCU] MCU model enumeration
ifneq ($(MCU),)
    mcu_model := $(shell $(ECHO) $(MCU) | $(TR) '[a-z]' '[A-Z]')
    ifeq ($(mcu_model), STC89C51RC)
        MCU_MACRO := MCU_MODEL_$(mcu_model)
        CODE_SIZE ?= 4096
        XRAM_SIZE ?= 256
    else ifeq ($(mcu_model), STC89LE51RC)
        MCU_MACRO := MCU_MODEL_$(mcu_model)
        CODE_SIZE ?= 4096
        XRAM_SIZE ?= 256
    else ifeq ($(mcu_model), STC89C52RC)
        MCU_MACRO := MCU_MODEL_$(mcu_model)
        CODE_SIZE ?= 8192
        XRAM_SIZE ?= 256
    else ifeq ($(mcu_model), STC89LE52RC)
        MCU_MACRO := MCU_MODEL_$(mcu_model)
        CODE_SIZE ?= 8192
        XRAM_SIZE ?= 256
    else ifeq ($(mcu_model), STC89C53RC)
        MCU_MACRO := MCU_MODEL_$(mcu_model)
        CODE_SIZE ?= 13312
        XRAM_SIZE ?= 256
    else ifeq ($(mcu_model), STC89LE53RC)
        MCU_MACRO := MCU_MODEL_$(mcu_model)
        CODE_SIZE ?= 13312
        XRAM_SIZE ?= 256
    else ifeq ($(mcu_model), STC89C54RD+)
        MCU_MACRO := MCU_MODEL_STC89C54RDP
        CODE_SIZE ?= 16384
        XRAM_SIZE ?= 1024
    else ifeq ($(mcu_model), STC89LE54RD+)
        MCU_MACRO := MCU_MODEL_STC89LE54RDP
        CODE_SIZE ?= 16384
        XRAM_SIZE ?= 1024
    else ifeq ($(mcu_model), STC89C58RD+)
        MCU_MACRO := MCU_MODEL_STC89C58RDP
        CODE_SIZE ?= 32768
        XRAM_SIZE ?= 1024
    else ifeq ($(mcu_model), STC89LE58RD+)
        MCU_MACRO := MCU_MODEL_STC89LE58RDP
        CODE_SIZE ?= 32768
        XRAM_SIZE ?= 1024
    else ifeq ($(mcu_model), STC89C510RD+)
        MCU_MACRO := MCU_MODEL_STC89C510RDP
        CODE_SIZE ?= 40960
        XRAM_SIZE ?= 1024
    else ifeq ($(mcu_model), STC89LE510RD+)
        MCU_MACRO := MCU_MODEL_STC89LE510RDP
        CODE_SIZE ?= 40960
        XRAM_SIZE ?= 1024
    else ifeq ($(mcu_model), STC89C512RD+)
        MCU_MACRO := MCU_MODEL_STC89C512RDP
        CODE_SIZE ?= 49152
        XRAM_SIZE ?= 1024
    else ifeq ($(mcu_model), STC89LE512RD+)
        MCU_MACRO := MCU_MODEL_STC89LE512RDP
        CODE_SIZE ?= 49152
        XRAM_SIZE ?= 1024
    else ifeq ($(mcu_model), STC89C514RD+)
        MCU_MACRO := MCU_MODEL_STC89C514RDP
        CODE_SIZE ?= 57344
        XRAM_SIZE ?= 1024
    else ifeq ($(mcu_model), STC89LE514RD+)
        MCU_MACRO := MCU_MODEL_STC89LE514RDP
        CODE_SIZE ?= 57344
        XRAM_SIZE ?= 1024
    else ifeq ($(mcu_model), STC89C516RD+)
        MCU_MACRO := MCU_MODEL_STC89C516RDP
        CODE_SIZE ?= 65536
        XRAM_SIZE ?= 1024
    else ifeq ($(mcu_model), STC89LE516RD+)
        MCU_MACRO := MCU_MODEL_STC89LE516RDP
        CODE_SIZE ?= 65536
        XRAM_SIZE ?= 1024
    else
        $(error unknow or unsupport MCU model $(MCU))
    endif
else
    $(error unspecify MCU model!)
endif

# Generate and export CFLAGS
#   Details:
#     --fsigned-char    Make "char" signed by default
#    -mmcs51            Generate code for the Intel MCS51 family of processors.
#                       This is the default processor target.
#    --std-sdcc99       Use ISO C99 standard with SDCC extensions
#    --opt-code-size    Optimize for code size rather than speed
#    --code-loc         Code Segment Location
#    --code-size        Code Segment size
#    --iram-size        Internal Ram size
#    --xram-size        External Ram size
export CFLAGS := -c -I$(INCDIR) \
-mmcs51 -D__CONF_MCU_MODEL=$(MCU_MACRO) \
-D__CONF_FRE_CLKIN=$(CLOCK_FREQUENCY)UL -D__CONF_MCU_PRESCALER=$(PRESCALER_FACTOR) \
--std-sdcc99 --fsigned-char \
--opt-code-size \
--code-loc 0x0000 --code-size $(CODE_SIZE) \
--iram-size $(IRAM_SIZE) \
--xram-size $(XRAM_SIZE)

# Generate and export AFLAGS
#     -c      do not warn if the library had to be created
#     -s      act as ranlib
#     -r      replace existing or insert new file(s) into the archive
AFLAGS        := -rcs

# Print final MCU information according to all configurations
$(info [mcu-model] $(mcu_model) (code=$(CODE_SIZE)B, iram=$(IRAM_SIZE)B, xram=$(XRAM_SIZE)B))
$(info [mcu-clock] $(shell $(ECHO) $(CLOCK_FREQUENCY) | $(AWK) '{printf("%.6f",$$1/1000000)}') MHz)
$(info [prescaler] $(PRESCALER_FACTOR)T mode)
