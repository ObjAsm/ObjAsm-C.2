;Include file created by h2incX, Version B.01.01, 10/09/2018 22:03
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: '\ObjAsm\Projects\h2IncX\header\interlockedapi.h', last modified: 19/04/2018 10:43
;Creation parameters: 

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

