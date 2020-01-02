##################################################
# Author     : Weilun Fong | wlf(at)zhishan-iot.tk
# Date       : 2020-01-02
# Description: Makefile for HML_FwLib_STC89, it will generate a hex format file finally
# E-mail     : mcu@zhishan-iot.tk
# Make-tool  : GNU Make (http://www.gnu.org/software/make/manual/make.html)
# Page       : https://hw.zhishan-iot.tk/page/hml/detail/fwlib_stc89.html
# Tar-mcu    : STC89C52RC, belong to STC micro STC89 series
# Tar-project: HML_FwLib_STC89
# Version    : v0.2.6
##################################################

########################################
##### [*]ENVIRONMENT CONFIGURATION
########################################
##### shell
export SHELL       := /bin/bash
export BASENAME    := basename
export CAT         := cat
export CD          := cd
export ECHO        := echo
export EECHO       := $(ECHO) -e
export GREP        := grep
export LS          := ls
export RM          := rm -f
export XARGS       := xargs
##### tool-chain
AR                 := sdar
CC                 := sdcc
MAKE               := make --no-print-directory
PACKIHX            := packihx

########################################
##### [1]PATH & TARGET DEFINE
########################################
##### important path
DIR_ROOT           := ..
DIR_INC            := $(DIR_ROOT)/inc
DIR_OUTPUT         := $(DIR_ROOT)/obj
DIR_SRC            := $(DIR_ROOT)/src
##### important file
FILE_HML_FWLIB     := libhml_stc89.lib
HML_SRC_FILES      := $(wildcard $(DIR_SRC)/*.c)
HML_REL_FILES      := $(patsubst $(DIR_SRC)/%.c, $(DIR_OUTPUT)/%.rel, $(HML_SRC_FILES))
MYFILE             ?= test.c
    # file check
    PHONY_LIST_IN := distclean help version
    ifeq ($(findstring $(MAKECMDGOALS),$(PHONY_LIST_IN)),)
        ifneq ($(wildcard $(MYFILE)),$(MYFILE))
            $(error no such file $(CURDIR)/$(MYFILE))
        endif
    endif
MYFILE_NAME        := $(shell $(BASENAME) $(MYFILE) .c)
MYFILE_REL         := $(patsubst %.c, $(DIR_OUTPUT)/%.rel, $(MYFILE))
###### target
TARGET             := output
TARGET_FWLIB       := $(DIR_OUTPUT)/$(FILE_HML_FWLIB)
###### compile parameter
AFLAGS_HML         := -rcs
CFLAGS_HML         := -c -I$(DIR_INC) -mmcs51 --opt-code-size --std-sdcc99 --code-loc 0x0000 --code-size 0x1FFF --data-loc 0x00
CFLAGS             := -c -I$(DIR_INC) -mmcs51 --opt-code-size --std-sdcc99 -L$(DIR_OUTPUT) -lhml_stc89 --code-loc 0x0000 --code-size 0x1FFF --data-loc 0x00

########################################
##### [2]BUILD WORKS
########################################
##### all target
all: $(TARGET).hex
	@echo ===================================================
	@echo Make $(MAKECMDGOALS) done!
	@echo project: $(HML_FWLIB_NAME) $(HML_FWLIB_VERSION)
	@echo ---------------------------------------------------
	@echo completed at `date "+%Y-%m-%d %H:%M:%S"`
	@echo ===================================================
########################################
###### compile HML source file(*.c)
$(HML_REL_FILES): $(DIR_OUTPUT)/%.rel:$(DIR_SRC)/%.c
	@$(ECHO) "CC  $<"
	@$(CC) $< $(CFLAGS_HML) -o $@
########################################
##### generate static library
$(TARGET_FWLIB): $(HML_REL_FILES)
	@$(EECHO) "\033[36m - Make static link library `basename $@` \033[0m"
	@$(ECHO) "AR  $@"
	@$(AR) $(AFLAGS_HML) $@ $^
########################################
#### compile source file of user
$(MYFILE_REL): $(MYFILE) $(TARGET_FWLIB)
	@$(EECHO) "\033[36m - Compile user source code \033[0m"
	@$(ECHO) "CC  $<"
	@$(CC) $< $(CFLAGS) -o $(DIR_OUTPUT)/`$(BASENAME) $@`
########################################
##### generate .hex file
$(TARGET).ihx: $(MYFILE_REL)
	@$(EECHO) "\033[36m - Generate .ihx file \033[0m"
	@$(CD) $(DIR_OUTPUT) && $(CC) `$(BASENAME) $^` $(FILE_HML_FWLIB) -o $@
$(TARGET).hex: $(TARGET).ihx
	@$(EECHO) "\033[36m - Generate .hex file \033[0m"
	@$(CD) $(DIR_OUTPUT) && $(PACKIHX) $< > $@

########################################
##### [+]PHONY TARGET
########################################
##### clean
.PHONY:clean
clean:
	$(CD) $(DIR_OUTPUT) && $(LS) | $(GREP) -vE -e ".gitkeep" -e ^$(MYFILE_NAME)* -e *.lib$$ -e *.hex$$ | $(XARGS) $(RM)
##### distclean
.PHONY:distclean
distclean:
	$(CD) $(DIR_OUTPUT) && $(LS) | $(GREP) -v ".gitkeep" | $(XARGS) $(RM)
##### help
.PHONY: help
help:
    sinclude Makefile.help
##### library
.PHONY: library
library: $(TARGET_FWLIB)
	@echo ===================================================
	@echo Make $(MAKECMDGOALS) done!
	@echo project: $(HML_FWLIB_NAME) $(HML_FWLIB_VERSION)
	@echo ---------------------------------------------------
	@echo completed at `date "+%Y-%m-%d %H:%M:%S"`
	@echo ===================================================
##### rebuild
.PHONY: rebuild
rebuild:
	@$(EECHO) "\033[36m - Clean all middle or temporary files \033[0m"
	$(CD) $(DIR_OUTPUT) && $(LS) | $(GREP) -v ".gitkeep" | $(XARGS) $(RM)
	@$(EECHO) "\033[36m - Start to build... \033[0m"
	@$(MAKE) -f Makefile -j$(JOBS) MAKECMDGOALS=$(MAKECMDGOALS)
##### version
.PHONY: version
version:
    sinclude Makefile.version
