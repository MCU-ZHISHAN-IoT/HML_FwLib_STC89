#!/usr/bin/make

# ------------------------------------------------------------------------
# Author     : Weilun Fong | wlf@zhishan-iot.tk
# Date       : 2020-02-06
# Description: project Makefile
# E-mail     : mcu@zhishan-iot.tk
# Make-tool  : GNU Make (http://www.gnu.org/software/make/manual/make.html)
# Page       : https://hw.zhishan-iot.tk/page/hml/detail/fwlib_stc89.html
# Project    : HML_FwLib_STC89
# Version    : v0.3.1
# ------------------------------------------------------------------------

# Package Bash shell command
export SHELL       := /bin/bash
export AWK         := awk
export BASENAME    := basename
export CAT         := cat
export CD          := cd
export DATE        := date
export ECHO        := echo
export EECHO       := $(ECHO) -e
export GREP        := grep
export LS          := ls
export RM          := rm -f
export TR          := tr
export TRUE        := true
export XARGS       := xargs

# Definition of toolchain
CROSS_COMPILE      := sd
AR                 := $(CROSS_COMPILE)ar
CC                 := $(CROSS_COMPILE)cc
MAKE               := make --no-print-directory
PACKIHX            := packihx

# Mark special phony targets
PHONY_LIST_IN      := clean distclean help rebuild version

# Definition of project basic path
DIR_ROOT           := ..
DIR_INC            := $(DIR_ROOT)/inc
DIR_OUTPUT         := $(DIR_ROOT)/obj
DIR_SRC            := $(DIR_ROOT)/src

# Configure all custom parameters
SPACE              := $(empty) $(empty)
TITLE_COLOR        := \033[36m
ifeq ($(findstring $(MAKECMDGOALS), $(PHONY_LIST_IN)),)
    ifneq ($(CONF),)
        include $(CONF)
    else
        include Makefile.config
    endif
    include Makefile.mcu
endif

#  Definition of of print format
ifeq ("$(VERBOSE)", "1")
    Q :=
    VECHO := @$(TRUE)
else
    Q := @
    VECHO := @$(ECHO)
endif

# Important file
FILE_HML_FWLIB     := libhml_stc89.lib
HML_SRC_FILES      := $(wildcard $(DIR_SRC)/*.c)
HML_REL_FILES      := $(patsubst $(DIR_SRC)/%.c, $(DIR_OUTPUT)/%.rel, $(HML_SRC_FILES))
MYFILE             ?= test.c
    # file check
    ifeq ($(findstring $(MAKECMDGOALS),$(PHONY_LIST_IN)),)
        ifneq ($(wildcard $(MYFILE)),$(MYFILE))
            $(error no such file $(CURDIR)/$(MYFILE))
        endif
    endif
MYFILE_NAME        := $(shell $(BASENAME) $(MYFILE) .c)
MYFILE_REL         := $(DIR_OUTPUT)/$(MYFILE_NAME).rel
# Target file
TARGET             := output
TARGET_FWLIB       := $(DIR_OUTPUT)/$(FILE_HML_FWLIB)

all: $(DIR_OUTPUT)/$(TARGET).hex
	@$(ECHO) ===================================================
	@$(ECHO) Make $(MAKECMDGOALS) done!
	@$(ECHO) ---------------------------------------------------
	@$(ECHO) completed at `$(DATE) "+%Y-%m-%d %H:%M:%S"`
	@$(ECHO) ===================================================

# Startup
startup:
	@$(EECHO) "$(TITLE_COLOR) - Start to build!\033[0m"

# Compile HML source file(*.c)
$(HML_SRC_FILES): startup
$(HML_REL_FILES): $(DIR_OUTPUT)/%.rel:$(DIR_SRC)/%.c
	$(VECHO) "CC  $<"
	$(Q)$(CC) $< $(CFLAGS) -o $@

# Generate static library
$(TARGET_FWLIB): $(HML_REL_FILES)
	@$(EECHO) "$(TITLE_COLOR) - Make static link library `basename $@` \033[0m"
	$(VECHO) "AR  $@"
	$(Q)$(AR) $(AFLAGS) $@ $^

# Compile user file
$(MYFILE_REL): $(MYFILE) $(TARGET_FWLIB)
	@$(EECHO) "$(TITLE_COLOR) - Compile user source code \033[0m"
	$(VECHO) "CC  $<"
	$(Q)$(CC) $< $(CFLAGS) -L$(DIR_OUTPUT) -lhml_stc89 -o $(DIR_OUTPUT)/`$(BASENAME) $@`

# Generate .hex file
$(DIR_OUTPUT)/$(TARGET).ihx: $(MYFILE_REL)
	@$(EECHO) "$(TITLE_COLOR) - Generate .ihx file \033[0m"
	$(VECHO) "CC $@"
	$(Q)$(CC) $^ $(DIR_OUTPUT)/$(FILE_HML_FWLIB) -o $@
$(DIR_OUTPUT)/$(TARGET).hex: $(DIR_OUTPUT)/$(TARGET).ihx
	@$(EECHO) "\033[36m - Generate .hex file \033[0m"
	$(Q)$(PACKIHX) $< > $@

# Phony targets
# [+] clean
.PHONY: clean
clean:
	$(CD) $(DIR_OUTPUT) && $(LS) | $(GREP) -vE -e ".gitkeep" -e ^$(MYFILE_NAME)* -e *.lib$$ -e *.hex$$ | $(XARGS) $(RM)
# [+] distclean
.PHONY: distclean
distclean:
	$(CD) $(DIR_OUTPUT) && $(LS) | $(GREP) -v ".gitkeep" | $(XARGS) $(RM)
# [+] help
.PHONY: help
help:
	@$(MAKE) -s -f Makefile.help
# [+] library
.PHONY: library
library: $(TARGET_FWLIB)
	@$(ECHO) ===================================================
	@$(ECHO) Make $(MAKECMDGOALS) done!
	@$(ECHO) ---------------------------------------------------
	@$(ECHO) completed at `$(DATE) "+%Y-%m-%d %H:%M:%S"`
	@$(ECHO) ===================================================
# [+] rebuild
.PHONY: rebuild
rebuild:
	@$(EECHO) "$(TITLE_COLOR) - Clean previous files \033[0m"
	@$(MAKE) distclean
	@$(MAKE) -f Makefile -j$(JOBS) $(MAKEFLAGS)
# [+] version
.PHONY: version
version:
	@$(MAKE) -s -f Makefile.version
