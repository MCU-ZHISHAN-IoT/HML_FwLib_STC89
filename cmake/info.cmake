# ------------------------------------------------------------------------
# Author     : Weilun Fong | wlf@zhishan-iot.tk
# Date       : 2022-03-12
# Description: show build information
# E-mail     : mcu@zhishan-iot.tk
# Make-tool  : CMake
# Page       : https://hw.zhishan-iot.tk/page/hml/detail/fwlib_stc89.html
# Project    : HML_FwLib_STC89
# Version    : v0.0.2
# ------------------------------------------------------------------------

message("--------------------------------------------------")
message(" Build Information                                ")
message("--------------------------------------------------")
message(" PROJECT_NAME            : ${PROJECT_NAME}")
message(" PROJECT_VERSION         : ${PROJECT_VERSION}")
message("--------------------------------------------------")
message(" CMAKE_TOOLCHAIN_FILE    : ${CMAKE_TOOLCHAIN_FILE}")
message(" CMAKE_SYSTEM_PROCESSOR  : ${CMAKE_SYSTEM_PROCESSOR}")
message(" CMAKE_AR                : ${CMAKE_AR}")
message(" CMAKE_C_COMPILER        : ${CMAKE_C_COMPILER}")
message("--------------------------------------------------")
message(" CMAKE_COMMAND           : ${CMAKE_COMMAND}")
message(" CMAKE_GENERATOR         : ${CMAKE_GENERATOR}")
message(" CMAKE_VERSION           : ${CMAKE_VERSION}")
message("--------------------------------------------------")
