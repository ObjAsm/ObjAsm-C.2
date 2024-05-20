;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\interlockedapi.h
;             Created on (UTC) 06/04/2024 06:15:56
;             Last modified on (UTC) 21/02/2024 18:13:14

;********************************************************************************
ifdef _MSC_VER
endif
; _MSC_VER
ifndef _INTERLOCKAPI_H_
  _INTERLOCKAPI_H_ equ <>
  include apiset.inc
  include apisetcconv.inc
  include minwindef.inc
  ifdef __cplusplus
    ;[...]
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    ifndef NOWINBASEINTERLOCK
      ifndef _NTOS_
        ;* _NTOS_ *
      endif
      ;* NOWINBASEINTERLOCK *
    endif
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM) *
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    ifndef NOWINBASEINTERLOCK
      ifndef _NTOS_
        if Defined(_SLIST_HEADER_) and  not Defined(_NTOSP_)
          @DefProto DllImport, InitializeSListHead, WIN_STD_CALL_CONV,, <:PSLIST_HEADER>, 4
          @DefProto DllImport, InterlockedPopEntrySList, WIN_STD_CALL_CONV,, <:PSLIST_HEADER>, 4
          @DefProto DllImport, InterlockedPushEntrySList, WIN_STD_CALL_CONV,, <:PSLIST_HEADER, :PSLIST_ENTRY>, 8
          if (NTDDI_VERSION ge NTDDI_WIN8)
            InterlockedPushListSList equ <InterlockedPushListSListEx>
            @DefProto DllImport, InterlockedPushListSListEx, WIN_STD_CALL_CONV,, <:PSLIST_HEADER, :PSLIST_ENTRY, :PSLIST_ENTRY, :ULONG>, 16
          endif
          ; (NTDDI_VERSION >= NTDDI_WIN8)
          @DefProto DllImport, InterlockedFlushSList, WIN_STD_CALL_CONV,, <:PSLIST_HEADER>, 4
          @DefProto DllImport, QueryDepthSList, WIN_STD_CALL_CONV,, <:PSLIST_HEADER>, 4
          ;* SLIST_HEADER_ *
        endif
        ;* _NTOS_ *
      endif
      ;* NOWINBASEINTERLOCK *
    endif
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
  endif
  ifdef __cplusplus
    ;[...]
  endif
endif
; _INTERLOCKAPI_H_
