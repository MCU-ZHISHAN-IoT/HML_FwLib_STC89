#Author     :Weilun Fong | wlf(at)zhishan-iot.tk
#Date       :2019-02-04
#Description:Makefile for HML_FwLib_STC89, it will generate a hex format file finally
#E-mail     :mcu(at)zhishan-iot.tk
#Make-tool  :GNU Make (http://www.gnu.org/software/make/manual/make.html)
#Page       :https://hw.zhishan-iot.tk/page/hml/detail/fwlib_stc89.html
#Tar-mcu    :STC micro STC89 series (STC89C52RC, STC89C54RD, etc.)
#Tar-project:HML_FwLib_STC89
#Version    :v0.1.2

##### variable define #####
##important directories##
DIR_ROOT       = ..
DIR_INC        = $(DIR_ROOT)/inc
DIR_OUTPUT     = $(DIR_ROOT)/obj
DIR_SRC        = $(DIR_ROOT)/src
##important files##
HML_SRC_FILES  = $(wildcard $(DIR_SRC)/*.c)
HML_REL_FILES  = $(patsubst $(DIR_SRC)/%.c,$(DIR_OUTPUT)/%.rel,$(HML_SRC_FILES))
OBJ_FILE_TYPE_LIST = asm ihx lk lst map mem rel rst sym
TAR_FILE_TYPE_LIST = hex lib
##operation parameter##
CFLAGS         = -c -o $(DIR_OUTPUT)/ -I $(DIR_INC) --std-sdcc99 -L $(DIR_OUTPUT)/hml_fw.lib
LFLAGS         = -rcs
##target##
TARGET         = output
##tool-chain##
AR             = sdar
CC             = sdcc
##version information##
HML_FWLIB_NAME = HML_FwLib_STC89
#note: we unify version code from v0.1.0 because of the same makefile template
MAK_VERSION    = v0.1.2

##### function define #####
##function-clean##
define clean_obj
	@echo
	@for i in $(OBJ_FILE_TYPE_LIST); do                   \
		find $(DIR_OUTPUT) -name "*.$$i" | xargs rm -rfv; \
	done
endef
##function-content_version##
define content_version
	@echo "Makefile for $(HML_FWLIB_NAME) [$(MAK_VERSION)]"
	@echo "Copyright(c) 2018-2019 ZHISHAN-IoT, all rights reserved."
	@echo "Adapted by Weilun Fong <wlf(at)zhishan-iot.tk>"
endef
##function-show_end_information##
define show_end_information
	@echo
	@echo ===================================================
	@echo Make $(MAKECMDGOALS) done!
	@echo Makefile - $(HML_FWLIB_NAME)
	@echo ---------------------------------------------------
	@echo completed at `date "+%Y-%m-%d %H:%M:%S"`
	@echo ===================================================
endef
##function-show_version##
define show_version
	@echo ===================================================
	$(content_version)
	@echo ===================================================
	@echo
endef

##### build works #####
all:startup $(TARGET).hex
	$(show_end_information)

$(TARGET).hex:$(TARGET).ihx
	@echo generate .hex file
	@cd $(DIR_OUTPUT) && packihx $< > $@
$(TARGET).ihx:test.rel hml_fw.lib
	@echo generate .ihx file
	@cd $(DIR_OUTPUT) && $(CC) $^ -o $@

#compile source file(*.c)
$(HML_REL_FILES):$(HML_SRC_FILES)
ifeq ($(wildcard $(DIR_OUTPUT)/hml_fw.lib), )
	@echo make static link library hml_fw.lib
	@(for cur_file in $(HML_SRC_FILES); do \
		echo CC "$$cur_file";              \
		$(CC) "$$cur_file" $(CFLAGS);      \
	done)
endif
#generate static library
hml_fw.lib:$(HML_REL_FILES)
ifeq ($(wildcard $(DIR_OUTPUT)/hml_fw.lib), )
	@echo AR $(DIR_OUTPUT)/$@
	@$(AR) $(LFLAGS) $(DIR_OUTPUT)/$@ $(HML_REL_FILES)
	@echo
endif
#startup information
startup:
	$(show_version)
	@echo start at `date "+%Y-%m-%d %H:%M:%S"`
	@echo
#compile source file of user
test.rel:test.c hml_fw.lib
	@echo compile user source code
	@echo CC $<
	@$(CC) $< $(CFLAGS) -L $(DIR_OUTPUT)/hml_fw.lib
	@echo

##### PHONY target #####
##clean temp files##
.PHONY:clean
clean:
	$(show_version)
	@echo start to clean...
	$(clean_obj)
	$(show_end_information)
##distclean##
.PHONY:distclean
distclean:
	$(show_version)
	@echo start to distclean...
	$(clean_obj)
	@for i in $(TAR_FILE_TYPE_LIST); do                   \
		find $(DIR_OUTPUT) -name "*.$$i" | xargs rm -rfv; \
	done
	$(show_end_information)
##help##
.PHONY: help
help:
    sinclude Makefile.help
##version information##
.PHONY: version
version:
	$(content_version)