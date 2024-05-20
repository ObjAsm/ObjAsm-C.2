;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\fibersapi.h
;             Created on (UTC) 06/04/2024 06:15:55
;             Last modified on (UTC) 21/02/2024 18:13:16

;********************************************************************************
ifdef _MSC_VER
endif
; _MSC_VER
ifndef _FIBERS_H_
  _FIBERS_H_ equ <>
  include apiset.inc
  include apisetcconv.inc
  include minwindef.inc
  ifdef __cplusplus
    ;[...]
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    if (_WIN32_WINNT ge 0600h)
      ifndef FLS_OUT_OF_INDEXES
        FLS_OUT_OF_INDEXES equ (0FFFFFFFFh)
      endif
      @DefProto DllImport, FlsAlloc, WIN_STD_CALL_CONV,, <:PFLS_CALLBACK_FUNCTION>, 4
      @DefProto DllImport, FlsGetValue, WIN_STD_CALL_CONV,, <:DWORD>, 4
      @DefProto DllImport, FlsSetValue, WIN_STD_CALL_CONV,, <:DWORD, :PVOID>, 8
      @DefProto DllImport, FlsFree, WIN_STD_CALL_CONV,, <:DWORD>, 4
    endif
    ; (_WIN32_WINNT >= 0x0600)
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    if (_WIN32_WINNT ge 0600h)
      @DefProto DllImport, IsThreadAFiber, WIN_STD_CALL_CONV,, <>, 0
    endif
    ; (_WIN32_WINNT >= 0x0600)
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
  endif
  ifdef __cplusplus
    ;[...]
  endif
endif
; _FIBERS_H_
