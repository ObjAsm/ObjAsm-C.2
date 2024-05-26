;Include file created by h2inc+ version C.2.0 on (UTC) 26/05/2024 13:31:25
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\processtopologyapi.h
;             Created on (UTC) 06/04/2024 06:15:57
;             Last modified on (UTC) 21/02/2024 18:13:14

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
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    if (_WIN32_WINNT ge 0601h)
      @DefProto DllImport, GetThreadGroupAffinity, WIN_STD_CALL_CONV,, <:HANDLE, :PGROUP_AFFINITY>, 8
      @DefProto DllImport, SetThreadGroupAffinity, WIN_STD_CALL_CONV,, <:HANDLE, :ptr GROUP_AFFINITY, :PGROUP_AFFINITY>, 12
    endif
  endif
  ifdef __cplusplus
    ;[...]
  endif
endif
