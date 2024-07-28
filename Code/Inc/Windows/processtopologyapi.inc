;Include file created by h2incX, Version B.01.01, 10/09/2018 22:03
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: '\ObjAsm\Projects\h2IncX\header\processtopologyapi.h', last modified: 19/04/2018 10:43
;Creation parameters: 

ifdef _MSC_VER
endif
ifndef _PROCESSTOPOLOGYAPI_H_
  _PROCESSTOPOLOGYAPI_H_ equ <>
  include apiset.inc
  include apisetcconv.inc
  include minwindef.inc
  include minwinbase.inc
  ifdef __cplusplus
    ;[...]
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    if (_WIN32_WINNT ge 0601h)
      @DefProto DllImport, GetProcessGroupAffinity, WIN_STD_CALL_CONV,, <:HANDLE, :PUSHORT, :PUSHORT>, 12
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    if (_WIN32_WINNT ge 0601h)
      @DefProto DllImport, GetThreadGroupAffinity, WIN_STD_CALL_CONV,, <:HANDLE, :PGROUP_AFFINITY>, 8
      @DefProto DllImport, SetThreadGroupAffinity, WIN_STD_CALL_CONV,, <:HANDLE, :ptr GROUP_AFFINITY, :PGROUP_AFFINITY>, 12
    endif
  endif
  ifdef __cplusplus
    ;[...]
  endif
endif

