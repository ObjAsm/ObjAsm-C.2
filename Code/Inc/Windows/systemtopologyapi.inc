;Include file created by h2incX, Version B.01.01, 10/09/2018 22:03
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: '\ObjAsm\Projects\h2IncX\header\systemtopologyapi.h', last modified: 19/04/2018 10:43
;Creation parameters: 

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
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, GetNumaHighestNodeNumber, WIN_STD_CALL_CONV,, <:PULONG>, 4
    if _WIN32_WINNT ge 0601h
      @DefProto DllImport, GetNumaNodeProcessorMaskEx, WIN_STD_CALL_CONV,, <:USHORT, :PGROUP_AFFINITY>, 8
    endif
    if _WIN32_WINNT ge 0601h
      @DefProto DllImport, GetNumaProximityNodeEx, WIN_STD_CALL_CONV,, <:ULONG, :PUSHORT>, 8
    endif
  endif
  ifdef __cplusplus
    ;[...]
  endif
endif

