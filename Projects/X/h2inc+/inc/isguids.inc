;Include file created by h2inc+ version C.2.0 on (UTC) 19/05/2024 07:52:23
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\isguids.h\isguids.h
;             Created on (UTC) 06/04/2024 06:15:56
;             Last modified on (UTC) 16/12/2023 11:07:04

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
