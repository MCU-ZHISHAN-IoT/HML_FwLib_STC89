#Author     :Weilun Fong | wlf(at)zhishan-iot.tk
#Date       :2019-04-06
#Description:Makefile for HML_FwLib_STC89, it will generate a hex format file finally
#E-mail     :mcu(at)zhishan-iot.tk
#Make-tool  :GNU Make (http://www.gnu.org/software/make/manual/make.html)
#Page       :https://hw.zhishan-iot.tk/page/hml/detail/fwlib_stc89.html
#Tar-mcu    :STC89C52RC, belong to STC micro STC89 series
#Tar-project:HML_FwLib_STC90
#Version    :v0.1.3

##### variable define #####
##important directories##
DIR_ROOT         = ..
DIR_INC          = $(DIR_ROOT)/inc
DIR_OUTPUT       = $(DIR_ROOT)/obj
DIR_SRC          = $(DIR_ROOT)/src
##important files##
FILE_HML_FWLIB   := libhml_stc89.lib
HML_SRC_FILES    := $(notdir $(wildcard $(DIR_SRC)/*.c))
HML_REL_FILES    := $(patsubst %.c,%.rel,$(HML_SRC_FILES))
MODULE_TARGETS_NAME := $(patsubst %.c,%,$(HML_SRC_FILES))
OBJ_FILE_TYPE_LIST  = asm ihx lk lst map mem rel rst sym
TAR_FILE_TYPE_LIST  = hex lib
##operation parameter##
AFLAGS_HML       = -rcs
CFLAGS_HML       = -c -I $(DIR_INC) -mmcs51 --opt-code-size --std-sdcc99 --code-loc 0x0000 --code-size 0x1FFF --data-loc 0x00
CFLAGS           = -c -I $(DIR_INC) -mmcs51 --opt-code-size --std-sdcc99 -L $(DIR_OUTPUT) -lhml_stc89 --code-loc 0x0000 --code-size 0x1FFF --data-loc 0x00

##target##
TARGET           = output
##tool-chain##
AR               = sdar
CC               = sdcc
##version information##
FWLIB_NAME       = HML_FwLib_STC89
#note: we unify version code from v0.1.0 because of the same makefile template
MAK_VERSION      = v0.1.3

##### function define #####
##function-clean##
define clean_obj
	@echo
	@for i in $(OBJ_FILE_TYPE_LIST); do                   \
		find $(DIR_OUTPUT) -name "*.$$i" | xargs rm -rfv; \
	done
endef
define distclean_obj
	$(clean_obj)
	@for i in $(TAR_FILE_TYPE_LIST); do                   \
		find $(DIR_OUTPUT) -name "*.$$i" | xargs rm -rfv; \
	done
endef
##function-content_version##
define content_version
	@echo "Makefile for $(FWLIB_NAME) [$(MAK_VERSION)]"
	@echo "Copyright(c) 2018-2019 ZHISHAN-IoT, all rights reserved."
	@echo "Adapted by Weilun Fong <wlf(at)zhishan-iot.tk>"
endef
##function-show_end_information##
define show_end_information
	@echo
	@echo ===================================================
	@echo Make $(MAKECMDGOALS) done!
	@echo Makefile - $(FWLIB_NAME)
	@echo ---------------------------------------------------
	@echo completed at `date "+%Y-%m-%d %H:%M:%S"`
	@echo ===================================================
endef

##### build works #####
all: $(TARGET).hex
	$(show_end_information)

#compile source file(*.c)
$(MODULE_TARGETS_NAME): %:$(DIR_SRC)/%.c
	@if [ ! -f $(DIR_OUTPUT)/$(FILE_HML_FWLIB) ];then          \
    echo "CC  $<";                                             \
    $(CC) $(DIR_SRC)/$< $(CFLAGS_HML) -o $(DIR_OUTPUT)/$@.rel; \
    fi;
#generate static library
$(FILE_HML_FWLIB): $(MODULE_TARGETS_NAME)
	@if [ ! -f $(DIR_OUTPUT)/$(FILE_HML_FWLIB) ];then          \
    echo ;                                                     \
    echo make static link library $@;                          \
    echo "AR  $(DIR_OUTPUT)/$@";                               \
    $(AR) $(AFLAGS_HML) $(DIR_OUTPUT)/$@ $(addprefix $(DIR_OUTPUT)/, $(HML_REL_FILES)); \
    fi;
#compile source file of user
test.rel: test.c $(FILE_HML_FWLIB)
	@echo
	@echo compile user source code
	@echo "CC  $<"
	@$(CC) $< $(CFLAGS) -o $(DIR_OUTPUT)/$@
#generate hex file#
$(TARGET).ihx: test.rel $(FILE_HML_FWLIB)
	@echo
	@echo generate .ihx file
	@cd $(DIR_OUTPUT) && $(CC) $^ -o $@
$(TARGET).hex: $(TARGET).ihx
	@echo generate .hex file
	@cd $(DIR_OUTPUT) && packihx $< > $@

##### PHONY target #####
##clean temp files##
.PHONY:clean
clean:
	@echo start to clean...
	$(clean_obj)
	$(show_end_information)
##distclean##
.PHONY:distclean_core distclean
distclean_core:
	$(distclean_obj)
	@echo
distclean: distclean_core
	$(show_end_information)
##help##
.PHONY: help
help:
    sinclude Makefile.help
##rebuild##
.PHONY: distclean_core rebuild
rebuild: distclean_core $(TARGET).hex
	$(show_end_information)
##version information##
.PHONY: version
version:
	$(content_version)
