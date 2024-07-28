;Include file created by h2incX, Version B.01.01, 10/09/2018 22:03
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: '\ObjAsm\Projects\h2IncX\header\jobapi.h', last modified: 19/04/2018 10:43
;Creation parameters: 

ifdef _MSC_VER
endif
ifndef _JOBAPISET_H_
  _JOBAPISET_H_ equ <>
  include apiset.inc
  include apisetcconv.inc
  include minwindef.inc
  include minwinbase.inc
  ifdef __cplusplus
    ;[...]
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    if (_WIN32_WINNT ge 0501h)
      @DefProto DllImport, IsProcessInJob, WIN_STD_CALL_CONV,, <:HANDLE, :HANDLE, :PBOOL>, 12
    endif
  endif
  ifdef __cplusplus
    ;[...]
  endif
endif

