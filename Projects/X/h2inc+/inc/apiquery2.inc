;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\apiquery2.h
;             Created on (UTC) 06/04/2024 06:15:51
;             Last modified on (UTC) 21/02/2024 18:13:22

;********************************************************************************
ifdef _MSC_VER
endif
; _MSC_VER
ifndef _APIQUERY2_H_
  _APIQUERY2_H_ equ <>
  include apiset.inc
  include apisetcconv.inc
  include minwindef.inc
  ifdef API_QUERY_IMPORT
    APICONTRACT equ <DECLSPEC_IMPORT>
  else
    APICONTRACT equ <>
  endif
  ifdef __cplusplus
    ;[...]
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, IsApiSetImplemented, WIN_STD_CALL_CONV,, <:PCSTR>, 4
  endif
  ; WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)
  ifdef __cplusplus
    ;[...]
  endif
endif
; _APIQUERY2_H_
