/*****************************************************************************/
/** 
 * \file        version.h
 * \author      Weilun Fong | wlf@zhishan-iot.tk
 * \brief       HML version information
 * \note        
 * \version     v1.1
 * \ingroup     VERSION
******************************************************************************/

#ifndef ___VERSION_H___
#define ___VERSION_H___

/*****************************************************************************
 *                                macro                                      *
 *****************************************************************************/

/**
 *\brief: version code
 */
#define HML_VERSION_CODE "1.1.1"
#define HML_VERSION_NAME "HML_FwLib_STC89"

/**
 *\brief: secondary version code
 */
#ifdef HML_VERSION_MAJOR
    #undef HML_VERSION_MAJOR
#endif
#define HML_VERSION_MAJOR 1

#ifdef HML_VERSION_MINOR
    #undef HML_VERSION_MINOR
#endif
#define HML_VERSION_MINOR 1

#ifdef HML_VERSION_PATCH
    #undef HML_VERSION_PATCH
#endif
#define HML_VERSION_PATCH 1

#endif
