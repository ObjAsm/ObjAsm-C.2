;Include file created by h2inc+ version C.2.0 on (UTC) 19/05/2024 07:52:23
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\interlockedapi.h\interlockedapi.h
;             Created on (UTC) 06/04/2024 06:15:56
;             Last modified on (UTC) 21/02/2024 18:13:14

ifdef _MSC_VER
endif
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
      endif
    endif
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
          @DefProto DllImport, InterlockedFlushSList, WIN_STD_CALL_CONV,, <:PSLIST_HEADER>, 4
          @DefProto DllImport, QueryDepthSList, WIN_STD_CALL_CONV,, <:PSLIST_HEADER>, 4
        endif
      endif
    endif
  endif
  ifdef __cplusplus
    ;[...]
  endif
endif
