;Include file created by h2incX, Version B.01.01, 10/09/2018 22:03
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: '\ObjAsm\Projects\h2IncX\header\apisetcconv.h', last modified: 19/04/2018 10:43
;Creation parameters: 

ifndef _APISETCCONV_
  _APISETCCONV_ equ <>
  if  not Defined(WINADVAPI)
    if  not Defined(_ADVAPI32_)
      WINADVAPI equ <DECLSPEC_IMPORT>
    else
      WINADVAPI equ <>
    endif
  endif
  if  not Defined(WINBASEAPI)
    if  not Defined(_KERNEL32_)
      WINBASEAPI equ <DECLSPEC_IMPORT>
    else
      WINBASEAPI equ <>
    endif
  endif
  if  not Defined(ZAWPROXYAPI)
    if  not Defined(_ZAWPROXY_)
      ZAWPROXYAPI equ <DECLSPEC_IMPORT>
    else
      ZAWPROXYAPI equ <>
    endif
  endif
  if  not Defined(WINUSERAPI)
    if  not Defined(_USER32_)
      WINUSERAPI equ <DECLSPEC_IMPORT>
      WINABLEAPI equ <DECLSPEC_IMPORT>
    else
      WINUSERAPI equ <>
      WINABLEAPI equ <>
    endif
  endif
  if  not Defined(WINABLEAPI)
    if  not Defined(_USER32_)
      WINABLEAPI equ <DECLSPEC_IMPORT>
    else
      WINABLEAPI equ <>
    endif
  endif
  if  not Defined(WINCFGMGR32API)
    if  not Defined(_SETUPAPI_)
      WINCFGMGR32API equ <DECLSPEC_IMPORT>
    else
      WINCFGMGR32API equ <>
    endif
  endif
  if  not Defined(WINDEVQUERYAPI)
    if  not Defined(_CFGMGR32_)
      WINDEVQUERYAPI equ <DECLSPEC_IMPORT>
    else
      WINDEVQUERYAPI equ <>
    endif
  endif
  if  not Defined(WINSWDEVICEAPI)
    if  not Defined(_CFGMGR32_)
      WINSWDEVICEAPI equ <DECLSPEC_IMPORT>
    else
      WINSWDEVICEAPI equ <>
    endif
  endif
  if  not Defined(CMAPI)
    if  not Defined(_CFGMGR32_)
      CMAPI equ <DECLSPEC_IMPORT>
    else
      CMAPI equ <>
    endif
  endif
  if  not Defined(WINPATHCCHAPI)
    if  not Defined(STATIC_PATHCCH)
      WINPATHCCHAPI equ <WINBASEAPI>
    else
      WINPATHCCHAPI equ <>
    endif
  endif
endif

