;Include file created by h2incX, Version B.01.01, 10/09/2018 22:03
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: '\ObjAsm\Projects\h2IncX\header\jobapi2.h', last modified: 19/04/2018 10:43
;Creation parameters: 

ifndef _JOBAPISET2_H_
  _JOBAPISET2_H_ equ <>
  include apiset.inc
  include apisetcconv.inc
  include minwindef.inc
  include minwinbase.inc
  ifdef __cplusplus
    ;[...]
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    JOBOBJECT_IO_RATE_CONTROL_INFORMATION struct
      MaxIops LONG64 ?
      MaxBandwidth LONG64 ?
      ReservationIops LONG64 ?
      VolumeName PCWSTR ?
      BaseIoSize ULONG ?
      ControlFlags ULONG ?
    JOBOBJECT_IO_RATE_CONTROL_INFORMATION ends

    @DefProto DllImport, CreateJobObjectW, WIN_STD_CALL_CONV,, <:LPSECURITY_ATTRIBUTES, :LPCWSTR>, 8
    @DefProto DllImport, FreeMemoryJobObject, WIN_STD_CALL_CONV,, <:ptr VOID>, 4
    @DefProto DllImport, OpenJobObjectW, WIN_STD_CALL_CONV,, <:DWORD, :BOOL, :LPCWSTR>, 12
    @DefProto DllImport, AssignProcessToJobObject, WIN_STD_CALL_CONV,, <:HANDLE, :HANDLE>, 8
    @DefProto DllImport, TerminateJobObject, WIN_STD_CALL_CONV,, <:HANDLE, :UINT>, 8
    @DefProto DllImport, SetInformationJobObject, WIN_STD_CALL_CONV,, <:HANDLE, :JOBOBJECTINFOCLASS, :LPVOID, :DWORD>, 16
    @DefProto DllImport, SetIoRateControlInformationJobObject, WIN_STD_CALL_CONV,, <:HANDLE, :ptr JOBOBJECT_IO_RATE_CONTROL_INFORMATION>, 8
    @DefProto DllImport, QueryInformationJobObject, WIN_STD_CALL_CONV,, <:HANDLE, :JOBOBJECTINFOCLASS, :LPVOID, :DWORD, :LPDWORD>, 20
    @DefProto DllImport, QueryIoRateControlInformationJobObject, WIN_STD_CALL_CONV,, <:HANDLE, :PCWSTR, :ptr ptr JOBOBJECT_IO_RATE_CONTROL_INFORMATION, :ptr ULONG>, 16
  endif
  ifdef __cplusplus
    ;[...]
  endif
endif

