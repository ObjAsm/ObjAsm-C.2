;Include file created by h2inc+ version C.2.0 on (UTC) 26/05/2024 13:31:25
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\jobapi2.h
;             Created on (UTC) 06/04/2024 06:15:56
;             Last modified on (UTC) 21/02/2024 18:13:14

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
