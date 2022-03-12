# ------------------------------------------------------------------------
# Author     : Weilun Fong | wlf@zhishan-iot.tk
# Date       : 2022-03-12
# Description: obtain project version
# E-mail     : mcu@zhishan-iot.tk
# Make-tool  : CMake
# Page       : https://hw.zhishan-iot.tk/page/hml/detail/fwlib_stc89.html
# Project    : HML_FwLib_STC89
# Version    : v0.0.2
# ------------------------------------------------------------------------

# Read version string from file VERSION
file(READ "${CMAKE_SOURCE_DIR}/VERSION" VERSION)

# Obtain number
STRING(REGEX MATCHALL "[0-9]" VERSION_PARTS "${VERSION}")
LIST(GET VERSION_PARTS 0 VERSION_MAJOR)
LIST(GET VERSION_PARTS 1 VERSION_MINOR)
LIST(GET VERSION_PARTS 2 VERSION_PATCH)

# Set version
SET(PROJECT_VERSION "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")
