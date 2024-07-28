;Include file created by h2incX, Version B.01.01, 10/09/2018 22:03
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: '\ObjAsm\Projects\h2IncX\header\profileapi.h', last modified: 19/04/2018 10:43
;Creation parameters: 

ifdef _MSC_VER
endif
ifndef _PROFILEAPI_H_
  _PROFILEAPI_H_ equ <>
  include apiset.inc
  include apisetcconv.inc
  include minwindef.inc
  ifdef __cplusplus
    ;[...]
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, QueryPerformanceCounter, WIN_STD_CALL_CONV,, <:ptr LARGE_INTEGER>, 4
    @DefProto DllImport, QueryPerformanceFrequency, WIN_STD_CALL_CONV,, <:ptr LARGE_INTEGER>, 4
  endif
  ifdef __cplusplus
    ;[...]
  endif
endif

