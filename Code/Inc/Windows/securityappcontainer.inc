;Include file created by h2incX, Version B.01.01, 10/09/2018 22:03
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: '\ObjAsm\Projects\h2IncX\header\securityappcontainer.h', last modified: 19/04/2018 10:43
;Creation parameters: 

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

