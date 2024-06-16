;Include file created by h2inc+ version C.2.0 on (UTC) 15/06/2024 16:37:44
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\lmcons.h
;             Created on (UTC) 22/05/2024 17:57:07
;             Last modified on (UTC) 08/01/2024 17:05:04

ifndef NETCONS_INCLUDED
  NETCONS_INCLUDED equ <>
  if _MSC_VER gt 1000
  endif
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    ifndef PASCAL_
      PASCAL_ equ <>
    endif
    ifndef FAR_
      FAR_ equ <>
    endif
    CNLEN equ 15
    LM20_CNLEN equ 15
    DNLEN equ <CNLEN>
    LM20_DNLEN equ <LM20_CNLEN>
    if (CNLEN ne DNLEN)
      .err <CNLEN and DNLEN are not equal>
    endif
    UNCLEN equ (CNLEN + 2)
    LM20_UNCLEN equ (LM20_CNLEN + 2)
    NNLEN equ 80
    LM20_NNLEN equ 12
    RMLEN equ (UNCLEN + 1 + NNLEN)
    LM20_RMLEN equ (LM20_UNCLEN + 1 + LM20_NNLEN)
    SNLEN equ 80
    LM20_SNLEN equ 15
    STXTLEN equ 256
    LM20_STXTLEN equ 63
    PATHLEN equ 256
    LM20_PATHLEN equ 256
    DEVLEN equ 80
    LM20_DEVLEN equ 8
    EVLEN equ 16
    UNLEN equ 256
    LM20_UNLEN equ 20
    GNLEN equ <UNLEN>
    LM20_GNLEN equ <LM20_UNLEN>
    PWLEN equ 256
    LM20_PWLEN equ 14
    SHPWLEN equ 8
    CLTYPE_LEN equ 12
    MAXCOMMENTSZ equ 256
    LM20_MAXCOMMENTSZ equ 48
    QNLEN equ <NNLEN>
    LM20_QNLEN equ <LM20_NNLEN>
    if (QNLEN ne NNLEN)
      .err <QNLEN and NNLEN are not equal>
    endif
    ALERTSZ equ 128
    MAXDEVENTRIES equ (sizeof(int) * 8)
    NETBIOS_NAME_LEN equ 16
    MAX_PREFERRED_LENGTH equ (- 1)
    CRYPT_KEY_LEN equ 7
    CRYPT_TXT_LEN equ 8
    ENCRYPTED_PWLEN equ 16
    SESSION_PWLEN equ 24
    SESSION_CRYPT_KLEN equ 21
    ifndef PARMNUM_ALL
      PARMNUM_ALL equ 0
    endif
    PARM_ERROR_UNKNOWN equ ((- 1))
    PARM_ERROR_NONE equ 0
    PARMNUM_BASE_INFOLEVEL equ 1000
    if Defined(_WIN32_WINNT) or Defined(WINNT) or Defined(__midl) or Defined(FORCE_UNICODE)
      LMSTR equ <LPWSTR>
      LMCSTR equ <LPCWSTR>
    else
      LMSTR equ <LPSTR>
      LMCSTR equ <LPCSTR>
    endif
    MESSAGE_FILENAME equ <TEXT("NETMSG")>
    OS2MSG_FILENAME equ <TEXT("BASE")>
    HELP_MSG_FILENAME equ <TEXT("NETH")>
    BACKUP_MSG_FILENAME equ <TEXT("BAK.MSG")>
    ifndef NULL
      ifdef __cplusplus
        ;[...]
      else
        NULL equ (0)
      endif
    endif
    ifndef IN_
      IN_ equ <>
    endif
    ifndef OPTIONAL
      OPTIONAL equ <>
    endif
    ifndef OUT_
      OUT_ equ <>
    endif
    PLATFORM_ID_DOS equ 300
    PLATFORM_ID_OS2 equ 400
    PLATFORM_ID_NT equ 500
    PLATFORM_ID_OSF equ 600
    PLATFORM_ID_VMS equ 700
    MIN_LANMAN_MESSAGE_ID equ <NERR_BASE>
    MAX_LANMAN_MESSAGE_ID equ 5899
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_APP or WINAPI_PARTITION_GAMES)
    NET_API_STATUS equ <DWORD>
    API_RET_TYPE equ <NET_API_STATUS>
    if (_MSC_VER ge 800) or Defined(_STDCALL_SUPPORTED)
      NET_API_FUNCTION equ <__stdcall>
    else
      NET_API_FUNCTION equ <>
    endif
  endif
endif
