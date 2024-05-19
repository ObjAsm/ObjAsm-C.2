;Include file created by h2inc+ version C.2.0 on (UTC) 19/05/2024 07:52:23
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\systemtopologyapi.h\systemtopologyapi.h
;             Created on (UTC) 06/04/2024 06:15:58
;             Last modified on (UTC) 21/02/2024 18:13:14

ifdef _MSC_VER
endif
ifndef _SYSTEMTOPOLOGY_H_
  _SYSTEMTOPOLOGY_H_ equ <>
  include apiset.inc
  include apisetcconv.inc
  include minwindef.inc
  include minwinbase.inc
  ifdef __cplusplus
    ;[...]
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, GetNumaHighestNodeNumber, WIN_STD_CALL_CONV,, <:PULONG>, 4
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    if _WIN32_WINNT ge 0601h
      @DefProto DllImport, GetNumaNodeProcessorMaskEx, WIN_STD_CALL_CONV,, <:USHORT, :PGROUP_AFFINITY>, 8
    endif
    if (_WIN32_WINNT ge _WIN32_WINNT_WIN10_FE)
      @DefProto DllImport, GetNumaNodeProcessorMask2, WIN_STD_CALL_CONV,, <:USHORT, :PGROUP_AFFINITY, :USHORT, :PUSHORT>, 16
    endif
    if _WIN32_WINNT ge 0601h
      @DefProto DllImport, GetNumaProximityNodeEx, WIN_STD_CALL_CONV,, <:ULONG, :PUSHORT>, 8
    endif
  endif
  ifdef __cplusplus
    ;[...]
  endif
endif
