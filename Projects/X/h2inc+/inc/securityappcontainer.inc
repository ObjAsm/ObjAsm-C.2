;Include file created by h2inc+ version C.2.0 on (UTC) 26/05/2024 13:31:25
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\securityappcontainer.h
;             Created on (UTC) 06/04/2024 06:15:58
;             Last modified on (UTC) 21/02/2024 18:13:22

ifdef _MSC_VER
endif
ifndef _APIAPPCONTAINER_
  _APIAPPCONTAINER_ equ <>
  include apiset.inc
  include apisetcconv.inc
  include minwindef.inc
  include minwinbase.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    ifdef __cplusplus
      ;[...]
    endif
    if NTDDI_VERSION ge NTDDI_WIN8
      GetAppContainerNamedObjectPath proto WIN_STD_CALL_CONV :HANDLE, :PSID, :ULONG, :LPWSTR, :PULONG
    endif
    ifdef __cplusplus
      ;[...]
    endif
  endif
endif