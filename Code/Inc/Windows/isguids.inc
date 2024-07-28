;Include file created by h2incX, Version B.01.01, 10/09/2018 22:03
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: '\ObjAsm\Projects\h2IncX\header\isguids.h', last modified: 19/04/2018 10:46
;Creation parameters: 

ifndef _ISGUIDS_H_
  _ISGUIDS_H_ equ <>
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    DEFINE_GUID CLSID_InternetShortcut, 0FBF23B40h, 0E3F0h, 101Bh, 84h, 88h, 00h, 0AAh, 00h, 3Eh, 56h, 0F8h
    DEFINE_GUID IID_IUniformResourceLocatorA, 0FBF23B80h, 0E3F0h, 101Bh, 84h, 88h, 00h, 0AAh, 00h, 3Eh, 56h, 0F8h
    DEFINE_GUID IID_IUniformResourceLocatorW, 0CABB0DA0h, 0DA57h, 11CFh, 99h, 74h, 00h, 20h, 0AFh, 0D7h, 97h, 62h
    ifdef UNICODE
      IID_IUniformResourceLocator equ <IID_IUniformResourceLocatorW>
    else
      IID_IUniformResourceLocator equ <IID_IUniformResourceLocatorA>
    endif
  endif
endif

