;Include file created by h2inc+ version C.2.0 on (UTC) 25/05/2024 20:55:09
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\wtypesbase.h
;             Created on (UTC) 22/05/2024 17:57:06
;             Last modified on (UTC) 21/02/2024 18:18:14

ifndef __REQUIRED_RPCNDR_H_VERSION__
  __REQUIRED_RPCNDR_H_VERSION__ equ 501
endif
ifndef __REQUIRED_RPCSAL_H_VERSION__
  __REQUIRED_RPCSAL_H_VERSION__ equ 100
endif
include rpc.inc
include rpcndr.inc
ifndef __RPCNDR_H_VERSION__
  .err <this stub requires an updated version of < rpcndr.h >>
endif
ifndef __wtypesbase_h__
  __wtypesbase_h__ equ <>
  if Defined(_MSC_VER) and (_MSC_VER ge 1020)
  endif
  ifndef DECLSPEC_XFGVIRT
    if Defined(_CONTROL_FLOW_GUARD_XFG)
      DECLSPEC_XFGVIRT macro base, func
        exitm <__declspec(xfg_virtual (base, func))>
      endm
    else
      DECLSPEC_XFGVIRT macro base, func
        exitm <>
      endm
    endif
  endif
  include basetsd.inc
  include guiddef.inc
  ifdef __cplusplus
    ;[...]
  endif
  if (_MSC_VER ge 1020)
  endif
  if _MSC_VER ge 1200
  endif
  externdef __MIDL_itf_wtypesbase_0000_0000_v0_0_c_ifspec:RPC_IF_HANDLE
  externdef __MIDL_itf_wtypesbase_0000_0000_v0_0_s_ifspec:RPC_IF_HANDLE
  ifndef __IWinTypesBase_INTERFACE_DEFINED__
    __IWinTypesBase_INTERFACE_DEFINED__ equ <>
    if 0
      ;[...]
    endif
    if Defined(_WIN32) and  not Defined(OLE2ANSI)
      OLECHAR typedef WCHAR
      LPOLESTR typedef ptr OLECHAR
      LPCOLESTR typedef ptr OLECHAR
      OLESTR macro str_
        exitm <L ## str_>
      endm
    else
      OLECHAR typedef SBYTE
      LPOLESTR typedef LPSTR
      LPCOLESTR typedef LPCSTR
      OLESTR macro str_
        exitm <str_>
      endm
    endif
    ifndef _WINDEF_
      ifndef _MINWINDEF_
        PVOID typedef ptr
        LPVOID typedef ptr
        FLOAT typedef REAL4
      endif
    endif
    UCHAR typedef BYTE
    SHORT_ typedef SWORD
    USHORT typedef WORD
    ULONG typedef DWORD
    DOUBLE typedef REAL8
    ifndef _DWORDLONG_
      DWORDLONG typedef QWORD
      PDWORDLONG typedef ptr DWORDLONG
    endif
    ifndef _ULONGLONG_
      LONGLONG typedef SQWORD
      ULONGLONG typedef QWORD
      PLONGLONG typedef ptr LONGLONG
      PULONGLONG typedef ptr ULONGLONG
    endif
    if 0
      ;[...]
    endif
    ifndef _WINBASE_
      ifndef _FILETIME_
        _FILETIME_ equ <>
        FILETIME struct
          dwLowDateTime DWORD ?
          dwHighDateTime DWORD ?
        FILETIME ends
        _FILETIME typedef FILETIME
        PFILETIME typedef ptr _FILETIME
        LPFILETIME typedef ptr _FILETIME
      endif
      ifndef _SYSTEMTIME_
        _SYSTEMTIME_ equ <>
        SYSTEMTIME struct
          wYear WORD ?
          wMonth WORD ?
          wDayOfWeek WORD ?
          wDay WORD ?
          wHour WORD ?
          wMinute WORD ?
          wSecond WORD ?
          wMilliseconds WORD ?
        SYSTEMTIME ends
        _SYSTEMTIME typedef SYSTEMTIME
        PSYSTEMTIME typedef ptr _SYSTEMTIME
        LPSYSTEMTIME typedef ptr _SYSTEMTIME
      endif
      ifndef _SECURITY_ATTRIBUTES_
        _SECURITY_ATTRIBUTES_ equ <>
        SECURITY_ATTRIBUTES struct
          nLength DWORD ?
          lpSecurityDescriptor LPVOID ?
          bInheritHandle BOOL ?
        SECURITY_ATTRIBUTES ends
        _SECURITY_ATTRIBUTES typedef SECURITY_ATTRIBUTES
        PSECURITY_ATTRIBUTES typedef ptr _SECURITY_ATTRIBUTES
        LPSECURITY_ATTRIBUTES typedef ptr _SECURITY_ATTRIBUTES
      endif
      ifndef SECURITY_DESCRIPTOR_REVISION
        SECURITY_DESCRIPTOR_CONTROL typedef USHORT
        PSECURITY_DESCRIPTOR_CONTROL typedef ptr USHORT
        PSID typedef PVOID
        ACL struct
          AclRevision UCHAR ?
          Sbz1 UCHAR ?
          AclSize USHORT ?
          AceCount USHORT ?
          Sbz2 USHORT ?
        ACL ends
        _ACL typedef ACL
        PACL typedef ptr ACL
        SECURITY_DESCRIPTOR struct
          Revision UCHAR ?
          Sbz1 UCHAR ?
          Control SECURITY_DESCRIPTOR_CONTROL ?
          Owner PSID ?
          Group_ PSID ?
          Sacl PACL ?
          Dacl PACL ?
        SECURITY_DESCRIPTOR ends
        _SECURITY_DESCRIPTOR typedef SECURITY_DESCRIPTOR
        PISECURITY_DESCRIPTOR typedef ptr _SECURITY_DESCRIPTOR
      endif
    endif
    COAUTHIDENTITY struct
      User POINTER ?
      UserLength ULONG ?
      Domain POINTER ?
      DomainLength ULONG ?
      Password POINTER ?
      PasswordLength ULONG ?
      Flags ULONG ?
    COAUTHIDENTITY ends
    _COAUTHIDENTITY typedef COAUTHIDENTITY
    COAUTHINFO struct
      dwAuthnSvc DWORD ?
      dwAuthzSvc DWORD ?
      pwszServerPrincName LPWSTR ?
      dwAuthnLevel DWORD ?
      dwImpersonationLevel DWORD ?
      pAuthIdentityData POINTER ?
      dwCapabilities DWORD ?
    COAUTHINFO ends
    _COAUTHINFO typedef COAUTHINFO
    SCODE typedef LONG
    PSCODE typedef ptr SCODE
    ifndef _HRESULT_DEFINED
      _HRESULT_DEFINED equ <>
      ifdef __midl
        ;[...]
      else
        HRESULT typedef LONG
      endif
    endif
    ifndef __OBJECTID_DEFINED
      __OBJECTID_DEFINED equ <>
      _OBJECTID_DEFINED equ <>
      OBJECTID struct
        Lineage GUID <>
        Uniquifier ULONG ?
      OBJECTID ends
      _OBJECTID typedef OBJECTID
    endif
    if 0
      ;[...]
    endif
    MEMCTX typedef SDWORD
    MEMCTX_TASK equ 1
    MEMCTX_SHARED equ 2
    MEMCTX_MACSYSTEM equ 3
    MEMCTX_UNKNOWN equ -1
    MEMCTX_SAME equ -2
    tagMEMCTX typedef MEMCTX

    ifndef _ROTREGFLAGS_DEFINED
      _ROTREGFLAGS_DEFINED equ <>
      ROTREGFLAGS_ALLOWANYCLIENT equ 1h
    endif
    ifndef _APPIDREGFLAGS_DEFINED
      _APPIDREGFLAGS_DEFINED equ <>
      APPIDREGFLAGS_ACTIVATE_IUSERVER_INDESKTOP equ 1h
      APPIDREGFLAGS_SECURE_SERVER_PROCESS_SD_AND_BIND equ 2h
      APPIDREGFLAGS_ISSUE_ACTIVATION_RPC_AT_IDENTIFY equ 4h
      APPIDREGFLAGS_IUSERVER_UNMODIFIED_LOGON_TOKEN equ 8h
      APPIDREGFLAGS_IUSERVER_SELF_SID_IN_LAUNCH_PERMISSION equ 10h
      APPIDREGFLAGS_IUSERVER_ACTIVATE_IN_CLIENT_SESSION_ONLY equ 20h
      APPIDREGFLAGS_RESERVED1 equ 40h
      APPIDREGFLAGS_RESERVED2 equ 80h
      APPIDREGFLAGS_RESERVED3 equ 100h
      APPIDREGFLAGS_RESERVED4 equ 200h
      APPIDREGFLAGS_RESERVED5 equ 400h
      APPIDREGFLAGS_AAA_NO_IMPLICIT_ACTIVATE_AS_IU equ 800h
      APPIDREGFLAGS_RESERVED7 equ 1000h
      APPIDREGFLAGS_RESERVED8 equ 2000h
      APPIDREGFLAGS_RESERVED9 equ 4000h
    endif
    ifndef _DCOMSCM_REMOTECALL_FLAGS_DEFINED
      _DCOMSCM_REMOTECALL_FLAGS_DEFINED equ <>
      DCOMSCM_ACTIVATION_USE_ALL_AUTHNSERVICES equ 1h
      DCOMSCM_ACTIVATION_DISALLOW_UNSECURE_CALL equ 2h
      DCOMSCM_RESOLVE_USE_ALL_AUTHNSERVICES equ 4h
      DCOMSCM_RESOLVE_DISALLOW_UNSECURE_CALL equ 8h
      DCOMSCM_PING_USE_MID_AUTHNSERVICE equ 10h
      DCOMSCM_PING_DISALLOW_UNSECURE_CALL equ 20h
    endif
    CLSCTX typedef SDWORD
    CLSCTX_INPROC_SERVER equ 1h
    CLSCTX_INPROC_HANDLER equ 2h
    CLSCTX_LOCAL_SERVER equ 4h
    CLSCTX_INPROC_SERVER16 equ 8h
    CLSCTX_REMOTE_SERVER equ 10h
    CLSCTX_INPROC_HANDLER16 equ 20h
    CLSCTX_RESERVED1 equ 40h
    CLSCTX_RESERVED2 equ 80h
    CLSCTX_RESERVED3 equ 100h
    CLSCTX_RESERVED4 equ 200h
    CLSCTX_NO_CODE_DOWNLOAD equ 400h
    CLSCTX_RESERVED5 equ 800h
    CLSCTX_NO_CUSTOM_MARSHAL equ 1000h
    CLSCTX_ENABLE_CODE_DOWNLOAD equ 2000h
    CLSCTX_NO_FAILURE_LOG equ 4000h
    CLSCTX_DISABLE_AAA equ 8000h
    CLSCTX_ENABLE_AAA equ 10000h
    CLSCTX_FROM_DEFAULT_CONTEXT equ 20000h
    CLSCTX_ACTIVATE_X86_SERVER equ 40000h
    CLSCTX_ACTIVATE_32_BIT_SERVER equ CLSCTX_ACTIVATE_X86_SERVER
    CLSCTX_ACTIVATE_64_BIT_SERVER equ 80000h
    CLSCTX_ENABLE_CLOAKING equ 100000h
    CLSCTX_APPCONTAINER equ 400000h
    CLSCTX_ACTIVATE_AAA_AS_IU equ 800000h
    CLSCTX_RESERVED6 equ 1000000h
    CLSCTX_ACTIVATE_ARM32_SERVER equ 2000000h
    CLSCTX_ALLOW_LOWER_TRUST_REGISTRATION equ 4000000h
    CLSCTX_PS_DLL equ 80000000h
    tagCLSCTX typedef CLSCTX

    CLSCTX_VALID_MASK equ <(CLSCTX_INPROC_SERVER or CLSCTX_INPROC_HANDLER or CLSCTX_LOCAL_SERVER or CLSCTX_INPROC_SERVER16 or CLSCTX_REMOTE_SERVER or CLSCTX_NO_CODE_DOWNLOAD or CLSCTX_NO_CUSTOM_MARSHAL or CLSCTX_ENABLE_CODE_DOWNLOAD or CLSCTX_NO_FAILURE_LOG or CLSCTX_DISABLE_AAA or CLSCTX_ENABLE_AAA or CLSCTX_FROM_DEFAULT_CONTEXT or CLSCTX_ACTIVATE_X86_SERVER or CLSCTX_ACTIVATE_64_BIT_SERVER or CLSCTX_ENABLE_CLOAKING or CLSCTX_APPCONTAINER or CLSCTX_ACTIVATE_AAA_AS_IU or CLSCTX_RESERVED6 or CLSCTX_ACTIVATE_ARM32_SERVER or CLSCTX_ALLOW_LOWER_TRUST_REGISTRATION or CLSCTX_PS_DLL)>
    MSHLFLAGS typedef SDWORD
    MSHLFLAGS_NORMAL equ 0
    MSHLFLAGS_TABLESTRONG equ 1
    MSHLFLAGS_TABLEWEAK equ 2
    MSHLFLAGS_NOPING equ 4
    MSHLFLAGS_RESERVED1 equ 8
    MSHLFLAGS_RESERVED2 equ 16
    MSHLFLAGS_RESERVED3 equ 32
    MSHLFLAGS_RESERVED4 equ 64
    tagMSHLFLAGS typedef MSHLFLAGS

    MSHCTX typedef SDWORD
    MSHCTX_LOCAL equ 0
    MSHCTX_NOSHAREDMEM equ 1
    MSHCTX_DIFFERENTMACHINE equ 2
    MSHCTX_INPROC equ 3
    MSHCTX_CROSSCTX equ 4
    MSHCTX_CONTAINER equ 5
    tagMSHCTX typedef MSHCTX

    BYTE_BLOB struct
      clSize ULONG ?
      abData byte 1 dup (?)
    BYTE_BLOB ends
    _BYTE_BLOB typedef BYTE_BLOB
    UP_BYTE_BLOB typedef ptr BYTE_BLOB
    WORD_BLOB struct
      clSize ULONG ?
      asData WORD 1 dup (?)
    WORD_BLOB ends
    _WORD_BLOB typedef WORD_BLOB
    UP_WORD_BLOB typedef ptr WORD_BLOB
    DWORD_BLOB struct
      clSize ULONG ?
      alData ULONG 1 dup (?)
    DWORD_BLOB ends
    _DWORD_BLOB typedef DWORD_BLOB
    UP_DWORD_BLOB typedef ptr DWORD_BLOB
    FLAGGED_BYTE_BLOB struct
      fFlags ULONG ?
      clSize ULONG ?
      abData byte 1 dup (?)
    FLAGGED_BYTE_BLOB ends
    _FLAGGED_BYTE_BLOB typedef FLAGGED_BYTE_BLOB
    UP_FLAGGED_BYTE_BLOB typedef ptr FLAGGED_BYTE_BLOB
    FLAGGED_WORD_BLOB struct
      fFlags ULONG ?
      clSize ULONG ?
      asData WORD 1 dup (?)
    FLAGGED_WORD_BLOB ends
    _FLAGGED_WORD_BLOB typedef FLAGGED_WORD_BLOB
    UP_FLAGGED_WORD_BLOB typedef ptr FLAGGED_WORD_BLOB
    BYTE_SIZEDARR struct
      clSize ULONG ?
      pData POINTER ?
    BYTE_SIZEDARR ends
    _BYTE_SIZEDARR typedef BYTE_SIZEDARR
    WORD_SIZEDARR struct
      clSize ULONG ?
      pData POINTER ?
    WORD_SIZEDARR ends
    _SHORT_SIZEDARR typedef WORD_SIZEDARR
    DWORD_SIZEDARR struct
      clSize ULONG ?
      pData POINTER ?
    DWORD_SIZEDARR ends
    _LONG_SIZEDARR typedef DWORD_SIZEDARR
    HYPER_SIZEDARR struct
      clSize ULONG ?
      pData POINTER ?
    HYPER_SIZEDARR ends
    _HYPER_SIZEDARR typedef HYPER_SIZEDARR
    externdef IWinTypesBase_v0_1_c_ifspec:RPC_IF_HANDLE
    externdef IWinTypesBase_v0_1_s_ifspec:RPC_IF_HANDLE
  endif
  BOOLEAN typedef boolean
  ifndef _tagBLOB_DEFINED
    _tagBLOB_DEFINED equ <>
    _BLOB_DEFINED equ <>
    _LPBLOB_DEFINED equ <>
    BLOB struct
      cbSize ULONG ?
      pBlobData POINTER ?
    BLOB ends
    tagBLOB typedef BLOB
    LPBLOB typedef ptr tagBLOB
  endif
  ifndef SID_IDENTIFIER_AUTHORITY_DEFINED
    SID_IDENTIFIER_AUTHORITY_DEFINED equ <>
    SID_IDENTIFIER_AUTHORITY struct
      Value UCHAR 6 dup (?)
    SID_IDENTIFIER_AUTHORITY ends
    _SID_IDENTIFIER_AUTHORITY typedef SID_IDENTIFIER_AUTHORITY
    PSID_IDENTIFIER_AUTHORITY typedef ptr _SID_IDENTIFIER_AUTHORITY
  endif
  ifndef SID_DEFINED
    SID_DEFINED equ <>
    SID struct
      Revision BYTE ?
      SubAuthorityCount BYTE ?
      IdentifierAuthority SID_IDENTIFIER_AUTHORITY <>
      SubAuthority ULONG 1 dup (?)
    SID ends
    _SID typedef SID
    PISID typedef ptr _SID
    SID_AND_ATTRIBUTES struct
      Sid POINTER ?
      Attributes DWORD ?
    SID_AND_ATTRIBUTES ends
    _SID_AND_ATTRIBUTES typedef SID_AND_ATTRIBUTES
    PSID_AND_ATTRIBUTES typedef ptr _SID_AND_ATTRIBUTES
  endif
  if _MSC_VER ge 1200
  endif
  externdef __MIDL_itf_wtypesbase_0000_0001_v0_0_c_ifspec:RPC_IF_HANDLE
  externdef __MIDL_itf_wtypesbase_0000_0001_v0_0_s_ifspec:RPC_IF_HANDLE
  ifdef __cplusplus
    ;[...]
  endif
endif
