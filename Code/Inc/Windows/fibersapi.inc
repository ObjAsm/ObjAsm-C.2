;Include file created by h2incX, Version B.01.01, 10/09/2018 22:03
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: '\ObjAsm\Projects\h2IncX\header\fibersapi.h', last modified: 19/04/2018 10:43
;Creation parameters: 

ifdef _MSC_VER
endif
ifndef _FIBERS_H_
  _FIBERS_H_ equ <>
  include apiset.inc
  include apisetcconv.inc
  include minwindef.inc
  ifdef __cplusplus
    ;[...]
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    if (_WIN32_WINNT ge 0600h)
      ifndef FLS_OUT_OF_INDEXES
        FLS_OUT_OF_INDEXES equ (0FFFFFFFFh)
      endif
      @DefProto DllImport, FlsAlloc, WIN_STD_CALL_CONV,, <:PFLS_CALLBACK_FUNCTION>, 4
      @DefProto DllImport, FlsGetValue, WIN_STD_CALL_CONV,, <:DWORD>, 4
      @DefProto DllImport, FlsSetValue, WIN_STD_CALL_CONV,, <:DWORD, :PVOID>, 8
      @DefProto DllImport, FlsFree, WIN_STD_CALL_CONV,, <:DWORD>, 4
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    if (_WIN32_WINNT ge 0600h)
      @DefProto DllImport, IsThreadAFiber, WIN_STD_CALL_CONV,, <>, 0
    endif
  endif
  ifdef __cplusplus
    ;[...]
  endif
endif

