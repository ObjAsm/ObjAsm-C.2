;Include file created by h2inc+ version C.2.0 on (UTC) 25/05/2024 16:54:49
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\sspi.h
;             Created on (UTC) 22/05/2024 17:57:06
;             Last modified on (UTC) 12/02/2024 17:05:46

include sdkddkver.inc
include winapifamily.inc
ifndef __SSPI_H__
  __SSPI_H__ equ <>
  if _MSC_VER gt 1000
  endif
  ifdef __cplusplus
    ;[...]
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    ifdef SECURITY_WIN32
      ISSP_LEVEL equ 32
      ISSP_MODE equ 1
    endif
    ifdef SECURITY_KERNEL
      ISSP_LEVEL equ 32
      ifdef ISSP_MODE
      endif
      ISSP_MODE equ 0
    endif
    ifdef SECURITY_MAC
      ISSP_LEVEL equ 32
      ISSP_MODE equ 1
    endif
    ifndef ISSP_LEVEL
      .err <You must define one of SECURITY_WIN32 , SECURITY_KERNEL , or>
      .err <SECURITY_MAC>
    endif
    if Defined(_NO_KSECDD_IMPORT_)
      KSECDDDECLSPEC equ <>
    else
      KSECDDDECLSPEC equ <__declspec(dllimport)>
    endif
    SEC_WCHAR typedef WCHAR
    SEC_CHAR typedef CHAR
    ifndef __SECSTATUS_DEFINED__
      SECURITY_STATUS typedef LONG
      __SECSTATUS_DEFINED__ equ <>
    endif
    SEC_TEXT equ <TEXT>
    SEC_FAR equ <>
    SEC_ENTRY equ <__stdcall>
    ifdef UNICODE
      SECURITY_PSTR typedef ptr SEC_WCHAR
      SECURITY_PCSTR typedef ptr SEC_WCHAR
    else
      SECURITY_PSTR typedef ptr SEC_CHAR
      SECURITY_PCSTR typedef ptr SEC_CHAR
    endif
    __SEC_FAR equ <SEC_FAR>
    ifndef __SECHANDLE_DEFINED__
      SecHandle struct
        dwLower ULONG_PTR ?
        dwUpper ULONG_PTR ?
      SecHandle ends
      _SecHandle typedef SecHandle
      PSecHandle typedef ptr SecHandle
      __SECHANDLE_DEFINED__ equ <>
    endif
    SecInvalidateHandle macro x
      exitm <((PSecHandle) (x)) - dwLower = ((PSecHandle) (x)) - dwUpper = ((- 1)) ;>
    endm
    SecIsValidHandle macro x
      exitm <((((PSecHandle) (x)) - dwLower != ((- 1))) and (((PSecHandle) (x)) - dwUpper != ((- 1))))>
    endm
    SEC_DELETED_HANDLE equ ((- 2))
    CredHandle typedef SecHandle
    PCredHandle typedef PSecHandle
    CtxtHandle typedef SecHandle
    PCtxtHandle typedef PSecHandle
    ifdef WIN32_CHICAGO
      SECURITY_INTEGER typedef QWORD
      PSECURITY_INTEGER typedef ptr QWORD
      SEC_SUCCESS macro Status
        exitm <((Status) >= 0)>
      endm
    elseif Defined(_NTDEF_) or Defined(_WINNT_)
      _SECURITY_INTEGER typedef LARGE_INTEGER
      SECURITY_INTEGER typedef LARGE_INTEGER
      PSECURITY_INTEGER typedef ptr LARGE_INTEGER
    else
      SECURITY_INTEGER struct
        LowPart DWORD ?
        HighPart SDWORD ?
      SECURITY_INTEGER ends
      _SECURITY_INTEGER typedef SECURITY_INTEGER
      PSECURITY_INTEGER typedef ptr SECURITY_INTEGER
    endif
    ifndef SECURITY_MAC
      TimeStamp typedef SECURITY_INTEGER
      PTimeStamp typedef ptr SECURITY_INTEGER
    else
      TimeStamp typedef DWORD
      PTimeStamp typedef ptr DWORD
    endif
    ifndef _NTDEF_
      SECURITY_STRING struct
        Length_ WORD ?
        MaximumLength WORD ?
        ifdef MIDL_PASS
          ;[...]
        endif
        Buffer POINTER ?
      SECURITY_STRING ends
      _SECURITY_STRING typedef SECURITY_STRING
      PSECURITY_STRING typedef ptr SECURITY_STRING
    else
      SECURITY_STRING typedef UNICODE_STRING
      PSECURITY_STRING typedef ptr UNICODE_STRING
    endif
    SecPkgInfoW struct
      fCapabilities DWORD ?
      wVersion WORD ?
      wRPCID WORD ?
      cbMaxToken DWORD ?
      ifdef MIDL_PASS
        ;[...]
      endif
      Name_ POINTER ?
      ifdef MIDL_PASS
        ;[...]
      endif
      Comment_ POINTER ?
    SecPkgInfoW ends
    _SecPkgInfoW typedef SecPkgInfoW
    PSecPkgInfoW typedef ptr SecPkgInfoW
    SecPkgInfoA struct
      fCapabilities DWORD ?
      wVersion WORD ?
      wRPCID WORD ?
      cbMaxToken DWORD ?
      ifdef MIDL_PASS
        ;[...]
      endif
      Name_ POINTER ?
      ifdef MIDL_PASS
        ;[...]
      endif
      Comment_ POINTER ?
    SecPkgInfoA ends
    _SecPkgInfoA typedef SecPkgInfoA
    PSecPkgInfoA typedef ptr SecPkgInfoA
    ifdef UNICODE
      SecPkgInfo equ <SecPkgInfoW>
      PSecPkgInfo equ <PSecPkgInfoW>
    else
      SecPkgInfo equ <SecPkgInfoA>
      PSecPkgInfo equ <PSecPkgInfoA>
    endif
    SECPKG_FLAG_INTEGRITY equ 00000001h
    SECPKG_FLAG_PRIVACY equ 00000002h
    SECPKG_FLAG_TOKEN_ONLY equ 00000004h
    SECPKG_FLAG_DATAGRAM equ 00000008h
    SECPKG_FLAG_CONNECTION equ 00000010h
    SECPKG_FLAG_MULTI_REQUIRED equ 00000020h
    SECPKG_FLAG_CLIENT_ONLY equ 00000040h
    SECPKG_FLAG_EXTENDED_ERROR equ 00000080h
    SECPKG_FLAG_IMPERSONATION equ 00000100h
    SECPKG_FLAG_ACCEPT_WIN32_NAME equ 00000200h
    SECPKG_FLAG_STREAM equ 00000400h
    SECPKG_FLAG_NEGOTIABLE equ 00000800h
    SECPKG_FLAG_GSS_COMPATIBLE equ 00001000h
    SECPKG_FLAG_LOGON equ 00002000h
    SECPKG_FLAG_ASCII_BUFFERS equ 00004000h
    SECPKG_FLAG_FRAGMENT equ 00008000h
    SECPKG_FLAG_MUTUAL_AUTH equ 00010000h
    SECPKG_FLAG_DELEGATION equ 00020000h
    SECPKG_FLAG_READONLY_WITH_CHECKSUM equ 00040000h
    SECPKG_FLAG_RESTRICTED_TOKENS equ 00080000h
    SECPKG_FLAG_NEGO_EXTENDER equ 00100000h
    SECPKG_FLAG_NEGOTIABLE2 equ 00200000h
    SECPKG_FLAG_APPCONTAINER_PASSTHROUGH equ 00400000h
    SECPKG_FLAG_APPCONTAINER_CHECKS equ 00800000h
    SECPKG_FLAG_CREDENTIAL_ISOLATION_ENABLED equ 01000000h
    SECPKG_FLAG_APPLY_LOOPBACK equ 02000000h
    SECPKG_ID_NONE equ 0FFFFh
    SECPKG_CALLFLAGS_APPCONTAINER equ 00000001h
    SECPKG_CALLFLAGS_APPCONTAINER_AUTHCAPABLE equ 00000002h
    SECPKG_CALLFLAGS_FORCE_SUPPLIED equ 00000004h
    SECPKG_CALLFLAGS_APPCONTAINER_UPNCAPABLE equ 00000008h
    SecBuffer struct
      cbBuffer DWORD ?
      BufferType DWORD ?
      ifdef MIDL_PASS
        ;[...]
      else
        pvBuffer POINTER ?
      endif
    SecBuffer ends
    _SecBuffer typedef SecBuffer
    PSecBuffer typedef ptr SecBuffer
    SecBufferDesc struct
      ulVersion DWORD ?
      cBuffers DWORD ?
      ifdef MIDL_PASS
        ;[...]
      endif
      pBuffers PSecBuffer ?
    SecBufferDesc ends
    _SecBufferDesc typedef SecBufferDesc
    PSecBufferDesc typedef ptr SecBufferDesc
    SECBUFFER_VERSION equ 0
    SECBUFFER_EMPTY equ 0
    SECBUFFER_DATA equ 1
    SECBUFFER_TOKEN equ 2
    SECBUFFER_PKG_PARAMS equ 3
    SECBUFFER_MISSING equ 4
    SECBUFFER_EXTRA equ 5
    SECBUFFER_STREAM_TRAILER equ 6
    SECBUFFER_STREAM_HEADER equ 7
    SECBUFFER_NEGOTIATION_INFO equ 8
    SECBUFFER_PADDING equ 9
    SECBUFFER_STREAM equ 10
    SECBUFFER_MECHLIST equ 11
    SECBUFFER_MECHLIST_SIGNATURE equ 12
    SECBUFFER_TARGET equ 13
    SECBUFFER_CHANNEL_BINDINGS equ 14
    SECBUFFER_CHANGE_PASS_RESPONSE equ 15
    SECBUFFER_TARGET_HOST equ 16
    SECBUFFER_ALERT equ 17
    SECBUFFER_APPLICATION_PROTOCOLS equ 18
    SECBUFFER_SRTP_PROTECTION_PROFILES equ 19
    SECBUFFER_SRTP_MASTER_KEY_IDENTIFIER equ 20
    SECBUFFER_TOKEN_BINDING equ 21
    SECBUFFER_PRESHARED_KEY equ 22
    SECBUFFER_PRESHARED_KEY_IDENTITY equ 23
    SECBUFFER_DTLS_MTU equ 24
    SECBUFFER_SEND_GENERIC_TLS_EXTENSION equ 25
    SECBUFFER_SUBSCRIBE_GENERIC_TLS_EXTENSION equ 26
    SECBUFFER_FLAGS equ 27
    SECBUFFER_TRAFFIC_SECRETS equ 28
    SECBUFFER_CERTIFICATE_REQUEST_CONTEXT equ 29
    SECBUFFER_CHANNEL_BINDINGS_RESULT equ 30
    SECBUFFER_ATTRMASK equ 0F0000000h
    SECBUFFER_READONLY equ 80000000h
    SECBUFFER_READONLY_WITH_CHECKSUM equ 10000000h
    SECBUFFER_RESERVED equ 60000000h
    SEC_NEGOTIATION_INFO struct
      Size_ DWORD ?
      NameLength DWORD ?
      Name_ POINTER ?
      Reserved POINTER ?
    SEC_NEGOTIATION_INFO ends
    _SEC_NEGOTIATION_INFO typedef SEC_NEGOTIATION_INFO
    PSEC_NEGOTIATION_INFO typedef ptr SEC_NEGOTIATION_INFO
    SEC_CHANNEL_BINDINGS struct
      dwInitiatorAddrType DWORD ?
      cbInitiatorLength DWORD ?
      dwInitiatorOffset DWORD ?
      dwAcceptorAddrType DWORD ?
      cbAcceptorLength DWORD ?
      dwAcceptorOffset DWORD ?
      cbApplicationDataLength DWORD ?
      dwApplicationDataOffset DWORD ?
    SEC_CHANNEL_BINDINGS ends
    _SEC_CHANNEL_BINDINGS typedef SEC_CHANNEL_BINDINGS
    PSEC_CHANNEL_BINDINGS typedef ptr SEC_CHANNEL_BINDINGS
    SEC_CHANNEL_BINDINGS_EX_MAGIC equ <'XEBC'>
    SEC_CHANNEL_BINDINGS_EX struct
      magicNumber DWORD ?
      flags DWORD ?
      cbHeaderLength DWORD ?
      cbStructureLength DWORD ?
      dwInitiatorAddrType DWORD ?
      cbInitiatorLength DWORD ?
      dwInitiatorOffset DWORD ?
      dwAcceptorAddrType DWORD ?
      cbAcceptorLength DWORD ?
      dwAcceptorOffset DWORD ?
      cbApplicationDataLength DWORD ?
      dwApplicationDataOffset DWORD ?
    SEC_CHANNEL_BINDINGS_EX ends
    _SEC_CHANNEL_BINDINGS_EX typedef SEC_CHANNEL_BINDINGS_EX
    PSEC_CHANNEL_BINDINGS_EX typedef ptr SEC_CHANNEL_BINDINGS_EX
    SEC_CHANNEL_BINDINGS_AUDIT_BINDINGS equ 1h
    SEC_CHANNEL_BINDINGS_VALID_FLAGS equ <SEC_CHANNEL_BINDINGS_AUDIT_BINDINGS>
    SEC_CHANNEL_BINDINGS_RESULT struct
      flags DWORD ?
    SEC_CHANNEL_BINDINGS_RESULT ends
    _SEC_CHANNEL_BINDINGS_RESULT typedef SEC_CHANNEL_BINDINGS_RESULT
    PSEC_CHANNEL_BINDINGS_RESULT typedef ptr SEC_CHANNEL_BINDINGS_RESULT
    SEC_CHANNEL_BINDINGS_RESULT_CLIENT_SUPPORT equ 1h
    SEC_CHANNEL_BINDINGS_RESULT_ABSENT equ 2h
    SEC_CHANNEL_BINDINGS_RESULT_NOTVALID_MISMATCH equ 4h
    SEC_CHANNEL_BINDINGS_RESULT_NOTVALID_MISSING equ 8h
    SEC_CHANNEL_BINDINGS_RESULT_VALID_MATCHED equ 10h
    SEC_CHANNEL_BINDINGS_RESULT_VALID_PROXY equ 20h
    SEC_CHANNEL_BINDINGS_RESULT_VALID_MISSING equ 40h
    SEC_CHANNEL_BINDINGS_RESULT_VALID equ <(SEC_CHANNEL_BINDINGS_RESULT_VALID_MATCHED or SEC_CHANNEL_BINDINGS_RESULT_VALID_PROXY or SEC_CHANNEL_BINDINGS_RESULT_VALID_MISSING)>
    SEC_CHANNEL_BINDINGS_RESULT_NOTVALID equ <(SEC_CHANNEL_BINDINGS_RESULT_NOTVALID_MISMATCH or SEC_CHANNEL_BINDINGS_RESULT_NOTVALID_MISSING)>
    SEC_APPLICATION_PROTOCOL_NEGOTIATION_EXT typedef SDWORD
    SecApplicationProtocolNegotiationExt_None equ 0
    SecApplicationProtocolNegotiationExt_NPN equ 1
    SecApplicationProtocolNegotiationExt_ALPN equ 2
    _SEC_APPLICATION_PROTOCOL_NEGOTIATION_EXT typedef SEC_APPLICATION_PROTOCOL_NEGOTIATION_EXT
    PSEC_APPLICATION_PROTOCOL_NEGOTIATION_EXT typedef ptr SEC_APPLICATION_PROTOCOL_NEGOTIATION_EXT
    SEC_APPLICATION_PROTOCOL_LIST struct
      ProtoNegoExt SEC_APPLICATION_PROTOCOL_NEGOTIATION_EXT ?
      ProtocolListSize WORD ?
      ProtocolList BYTE ANYSIZE_ARRAY dup (?)
    SEC_APPLICATION_PROTOCOL_LIST ends
    _SEC_APPLICATION_PROTOCOL_LIST typedef SEC_APPLICATION_PROTOCOL_LIST
    PSEC_APPLICATION_PROTOCOL_LIST typedef ptr SEC_APPLICATION_PROTOCOL_LIST
    SEC_APPLICATION_PROTOCOLS struct
      ProtocolListsSize DWORD ?
      ProtocolLists SEC_APPLICATION_PROTOCOL_LIST ANYSIZE_ARRAY dup (<>)
    SEC_APPLICATION_PROTOCOLS ends
    _SEC_APPLICATION_PROTOCOLS typedef SEC_APPLICATION_PROTOCOLS
    PSEC_APPLICATION_PROTOCOLS typedef ptr SEC_APPLICATION_PROTOCOLS
    SEC_SRTP_PROTECTION_PROFILES struct
      ProfilesSize WORD ?
      ProfilesList WORD ANYSIZE_ARRAY dup (?)
    SEC_SRTP_PROTECTION_PROFILES ends
    _SEC_SRTP_PROTECTION_PROFILES typedef SEC_SRTP_PROTECTION_PROFILES
    PSEC_SRTP_PROTECTION_PROFILES typedef ptr SEC_SRTP_PROTECTION_PROFILES
    SEC_SRTP_MASTER_KEY_IDENTIFIER struct
      MasterKeyIdentifierSize BYTE ?
      MasterKeyIdentifier BYTE ANYSIZE_ARRAY dup (?)
    SEC_SRTP_MASTER_KEY_IDENTIFIER ends
    _SEC_SRTP_MASTER_KEY_IDENTIFIER typedef SEC_SRTP_MASTER_KEY_IDENTIFIER
    PSEC_SRTP_MASTER_KEY_IDENTIFIER typedef ptr SEC_SRTP_MASTER_KEY_IDENTIFIER
    SEC_TOKEN_BINDING struct
      MajorVersion BYTE ?
      MinorVersion BYTE ?
      KeyParametersSize WORD ?
      KeyParameters BYTE ANYSIZE_ARRAY dup (?)
    SEC_TOKEN_BINDING ends
    _SEC_TOKEN_BINDING typedef SEC_TOKEN_BINDING
    PSEC_TOKEN_BINDING typedef ptr SEC_TOKEN_BINDING
    SEC_PRESHAREDKEY struct
      KeySize WORD ?
      Key BYTE ANYSIZE_ARRAY dup (?)
    SEC_PRESHAREDKEY ends
    _SEC_PRESHAREDKEY typedef SEC_PRESHAREDKEY
    PSEC_PRESHAREDKEY typedef ptr SEC_PRESHAREDKEY
    SEC_PRESHAREDKEY_IDENTITY struct
      KeyIdentitySize WORD ?
      KeyIdentity BYTE ANYSIZE_ARRAY dup (?)
    SEC_PRESHAREDKEY_IDENTITY ends
    _SEC_PRESHAREDKEY_IDENTITY typedef SEC_PRESHAREDKEY_IDENTITY
    PSEC_PRESHAREDKEY_IDENTITY typedef ptr SEC_PRESHAREDKEY_IDENTITY
    SEC_DTLS_MTU struct
      PathMTU WORD ?
    SEC_DTLS_MTU ends
    _SEC_DTLS_MTU typedef SEC_DTLS_MTU
    PSEC_DTLS_MTU typedef ptr SEC_DTLS_MTU
    SEC_FLAGS struct
      Flags QWORD ?
    SEC_FLAGS ends
    _SEC_FLAGS typedef SEC_FLAGS
    PSEC_FLAGS typedef ptr SEC_FLAGS
    SEC_CERTIFICATE_REQUEST_CONTEXT struct
      cbCertificateRequestContext BYTE ?
      rgCertificateRequestContext BYTE ANYSIZE_ARRAY dup (?)
    SEC_CERTIFICATE_REQUEST_CONTEXT ends
    _SEC_CERTIFICATE_REQUEST_CONTEXT typedef SEC_CERTIFICATE_REQUEST_CONTEXT
    PSEC_CERTIFICATE_REQUEST_CONTEXT typedef ptr SEC_CERTIFICATE_REQUEST_CONTEXT
    SEC_TRAFFIC_SECRET_TYPE typedef SDWORD
    SecTrafficSecret_None equ 0
    SecTrafficSecret_Client equ 1
    SecTrafficSecret_Server equ 2
    _SEC_TRAFFIC_SECRET_TYPE typedef SEC_TRAFFIC_SECRET_TYPE
    PSEC_TRAFFIC_SECRET_TYPE typedef ptr SEC_TRAFFIC_SECRET_TYPE
    SZ_ALG_MAX_SIZE equ 64
    SEC_TRAFFIC_SECRETS struct
      SymmetricAlgId wchar_t SZ_ALG_MAX_SIZE dup (?)
      ChainingMode wchar_t SZ_ALG_MAX_SIZE dup (?)
      HashAlgId wchar_t SZ_ALG_MAX_SIZE dup (?)
      KeySize WORD ?
      IvSize WORD ?
      MsgSequenceStart WORD ?
      MsgSequenceEnd WORD ?
      TrafficSecretType SEC_TRAFFIC_SECRET_TYPE ?
      TrafficSecretSize WORD ?
      TrafficSecret BYTE ANYSIZE_ARRAY dup (?)
    SEC_TRAFFIC_SECRETS ends
    _SEC_TRAFFIC_SECRETS typedef SEC_TRAFFIC_SECRETS
    PSEC_TRAFFIC_SECRETS typedef ptr SEC_TRAFFIC_SECRETS
    SECURITY_NATIVE_DREP equ 00000010h
    SECURITY_NETWORK_DREP equ 00000000h
    SECPKG_CRED_INBOUND equ 00000001h
    SECPKG_CRED_OUTBOUND equ 00000002h
    SECPKG_CRED_BOTH equ 00000003h
    SECPKG_CRED_DEFAULT equ 00000004h
    SECPKG_CRED_RESERVED equ 0F0000000h
    SECPKG_CRED_AUTOLOGON_RESTRICTED equ 00000010h
    SECPKG_CRED_PROCESS_POLICY_ONLY equ 00000020h
    ISC_REQ_DELEGATE equ 00000001h
    ISC_REQ_MUTUAL_AUTH equ 00000002h
    ISC_REQ_REPLAY_DETECT equ 00000004h
    ISC_REQ_SEQUENCE_DETECT equ 00000008h
    ISC_REQ_CONFIDENTIALITY equ 00000010h
    ISC_REQ_USE_SESSION_KEY equ 00000020h
    ISC_REQ_PROMPT_FOR_CREDS equ 00000040h
    ISC_REQ_USE_SUPPLIED_CREDS equ 00000080h
    ISC_REQ_ALLOCATE_MEMORY equ 00000100h
    ISC_REQ_USE_DCE_STYLE equ 00000200h
    ISC_REQ_DATAGRAM equ 00000400h
    ISC_REQ_CONNECTION equ 00000800h
    ISC_REQ_CALL_LEVEL equ 00001000h
    ISC_REQ_FRAGMENT_SUPPLIED equ 00002000h
    ISC_REQ_EXTENDED_ERROR equ 00004000h
    ISC_REQ_STREAM equ 00008000h
    ISC_REQ_INTEGRITY equ 00010000h
    ISC_REQ_IDENTIFY equ 00020000h
    ISC_REQ_NULL_SESSION equ 00040000h
    ISC_REQ_MANUAL_CRED_VALIDATION equ 00080000h
    ISC_REQ_RESERVED1 equ 00100000h
    ISC_REQ_FRAGMENT_TO_FIT equ 00200000h
    ISC_REQ_FORWARD_CREDENTIALS equ 00400000h
    ISC_REQ_NO_INTEGRITY equ 00800000h
    ISC_REQ_USE_HTTP_STYLE equ 01000000h
    ISC_REQ_UNVERIFIED_TARGET_NAME equ 20000000h
    ISC_REQ_CONFIDENTIALITY_ONLY equ 40000000h
    ISC_REQ_MESSAGES equ 0000000100000000h
    ISC_REQ_DEFERRED_CRED_VALIDATION equ 0000000200000000h
    ISC_REQ_NO_POST_HANDSHAKE_AUTH equ 0000000400000000h
    ISC_RET_DELEGATE equ 00000001h
    ISC_RET_MUTUAL_AUTH equ 00000002h
    ISC_RET_REPLAY_DETECT equ 00000004h
    ISC_RET_SEQUENCE_DETECT equ 00000008h
    ISC_RET_CONFIDENTIALITY equ 00000010h
    ISC_RET_USE_SESSION_KEY equ 00000020h
    ISC_RET_USED_COLLECTED_CREDS equ 00000040h
    ISC_RET_USED_SUPPLIED_CREDS equ 00000080h
    ISC_RET_ALLOCATED_MEMORY equ 00000100h
    ISC_RET_USED_DCE_STYLE equ 00000200h
    ISC_RET_DATAGRAM equ 00000400h
    ISC_RET_CONNECTION equ 00000800h
    ISC_RET_INTERMEDIATE_RETURN equ 00001000h
    ISC_RET_CALL_LEVEL equ 00002000h
    ISC_RET_EXTENDED_ERROR equ 00004000h
    ISC_RET_STREAM equ 00008000h
    ISC_RET_INTEGRITY equ 00010000h
    ISC_RET_IDENTIFY equ 00020000h
    ISC_RET_NULL_SESSION equ 00040000h
    ISC_RET_MANUAL_CRED_VALIDATION equ 00080000h
    ISC_RET_RESERVED1 equ 00100000h
    ISC_RET_FRAGMENT_ONLY equ 00200000h
    ISC_RET_FORWARD_CREDENTIALS equ 00400000h
    ISC_RET_USED_HTTP_STYLE equ 01000000h
    ISC_RET_NO_ADDITIONAL_TOKEN equ 02000000h
    ISC_RET_REAUTHENTICATION equ 08000000h
    ISC_RET_CONFIDENTIALITY_ONLY equ 40000000h
    ISC_RET_MESSAGES equ 0000000100000000h
    ISC_RET_DEFERRED_CRED_VALIDATION equ 0000000200000000h
    ISC_RET_NO_POST_HANDSHAKE_AUTH equ 0000000400000000h
    ASC_REQ_DELEGATE equ 00000001h
    ASC_REQ_MUTUAL_AUTH equ 00000002h
    ASC_REQ_REPLAY_DETECT equ 00000004h
    ASC_REQ_SEQUENCE_DETECT equ 00000008h
    ASC_REQ_CONFIDENTIALITY equ 00000010h
    ASC_REQ_USE_SESSION_KEY equ 00000020h
    ASC_REQ_SESSION_TICKET equ 00000040h
    ASC_REQ_ALLOCATE_MEMORY equ 00000100h
    ASC_REQ_USE_DCE_STYLE equ 00000200h
    ASC_REQ_DATAGRAM equ 00000400h
    ASC_REQ_CONNECTION equ 00000800h
    ASC_REQ_CALL_LEVEL equ 00001000h
    ASC_REQ_FRAGMENT_SUPPLIED equ 00002000h
    ASC_REQ_EXTENDED_ERROR equ 00008000h
    ASC_REQ_STREAM equ 00010000h
    ASC_REQ_INTEGRITY equ 00020000h
    ASC_REQ_LICENSING equ 00040000h
    ASC_REQ_IDENTIFY equ 00080000h
    ASC_REQ_ALLOW_NULL_SESSION equ 00100000h
    ASC_REQ_ALLOW_NON_USER_LOGONS equ 00200000h
    ASC_REQ_ALLOW_CONTEXT_REPLAY equ 00400000h
    ASC_REQ_FRAGMENT_TO_FIT equ 00800000h
    ASC_REQ_NO_TOKEN equ 01000000h
    ASC_REQ_PROXY_BINDINGS equ 04000000h
    ASC_REQ_ALLOW_MISSING_BINDINGS equ 10000000h
    ASC_REQ_MESSAGES equ 0000000100000000h
    ASC_RET_DELEGATE equ 00000001h
    ASC_RET_MUTUAL_AUTH equ 00000002h
    ASC_RET_REPLAY_DETECT equ 00000004h
    ASC_RET_SEQUENCE_DETECT equ 00000008h
    ASC_RET_CONFIDENTIALITY equ 00000010h
    ASC_RET_USE_SESSION_KEY equ 00000020h
    ASC_RET_SESSION_TICKET equ 00000040h
    ASC_RET_ALLOCATED_MEMORY equ 00000100h
    ASC_RET_USED_DCE_STYLE equ 00000200h
    ASC_RET_DATAGRAM equ 00000400h
    ASC_RET_CONNECTION equ 00000800h
    ASC_RET_CALL_LEVEL equ 00002000h
    ASC_RET_THIRD_LEG_FAILED equ 00004000h
    ASC_RET_EXTENDED_ERROR equ 00008000h
    ASC_RET_STREAM equ 00010000h
    ASC_RET_INTEGRITY equ 00020000h
    ASC_RET_LICENSING equ 00040000h
    ASC_RET_IDENTIFY equ 00080000h
    ASC_RET_NULL_SESSION equ 00100000h
    ASC_RET_ALLOW_NON_USER_LOGONS equ 00200000h
    ASC_RET_ALLOW_CONTEXT_REPLAY equ 00400000h
    ASC_RET_FRAGMENT_ONLY equ 00800000h
    ASC_RET_NO_TOKEN equ 01000000h
    ASC_RET_NO_ADDITIONAL_TOKEN equ 02000000h
    ASC_RET_MESSAGES equ 0000000100000000h
    SECPKG_CRED_ATTR_NAMES equ 1
    SECPKG_CRED_ATTR_SSI_PROVIDER equ 2
    SECPKG_CRED_ATTR_KDC_PROXY_SETTINGS equ 3
    SECPKG_CRED_ATTR_CERT equ 4
    SECPKG_CRED_ATTR_PAC_BYPASS equ 5
    SecPkgCredentials_NamesW struct
      ifdef MIDL_PASS
        ;[...]
      endif
      sUserName POINTER ?
    SecPkgCredentials_NamesW ends
    _SecPkgCredentials_NamesW typedef SecPkgCredentials_NamesW
    PSecPkgCredentials_NamesW typedef ptr SecPkgCredentials_NamesW
    SecPkgCredentials_NamesA struct
      ifdef MIDL_PASS
        ;[...]
      endif
      sUserName POINTER ?
    SecPkgCredentials_NamesA ends
    _SecPkgCredentials_NamesA typedef SecPkgCredentials_NamesA
    PSecPkgCredentials_NamesA typedef ptr SecPkgCredentials_NamesA
    ifdef UNICODE
      SecPkgCredentials_Names equ <SecPkgCredentials_NamesW>
      PSecPkgCredentials_Names equ <PSecPkgCredentials_NamesW>
    else
      SecPkgCredentials_Names equ <SecPkgCredentials_NamesA>
      PSecPkgCredentials_Names equ <PSecPkgCredentials_NamesA>
    endif
    if NTDDI_VERSION gt NTDDI_WS03
      SecPkgCredentials_SSIProviderW struct
        sProviderName POINTER ?
        ProviderInfoLength DWORD ?
        ProviderInfo POINTER ?
      SecPkgCredentials_SSIProviderW ends
      _SecPkgCredentials_SSIProviderW typedef SecPkgCredentials_SSIProviderW
      PSecPkgCredentials_SSIProviderW typedef ptr SecPkgCredentials_SSIProviderW
    endif
    SecPkgCredentials_SSIProviderA struct
      sProviderName POINTER ?
      ProviderInfoLength DWORD ?
      ProviderInfo POINTER ?
    SecPkgCredentials_SSIProviderA ends
    _SecPkgCredentials_SSIProviderA typedef SecPkgCredentials_SSIProviderA
    PSecPkgCredentials_SSIProviderA typedef ptr SecPkgCredentials_SSIProviderA
    ifdef UNICODE
      SecPkgCredentials_SSIProvider equ <SecPkgCredentials_SSIProviderW>
      PSecPkgCredentials_SSIProvider equ <PSecPkgCredentials_SSIProviderW>
    else
      SecPkgCredentials_SSIProvider equ <SecPkgCredentials_SSIProviderA>
      PSecPkgCredentials_SSIProvider equ <PSecPkgCredentials_SSIProviderA>
    endif
    KDC_PROXY_SETTINGS_V1 equ 1
    KDC_PROXY_SETTINGS_FLAGS_FORCEPROXY equ 1h
    SecPkgCredentials_KdcProxySettingsW struct
      Version ULONG ?
      Flags ULONG ?
      ProxyServerOffset USHORT ?
      ProxyServerLength USHORT ?
      ClientTlsCredOffset USHORT ?
      ClientTlsCredLength USHORT ?
    SecPkgCredentials_KdcProxySettingsW ends
    _SecPkgCredentials_KdcProxySettingsW typedef SecPkgCredentials_KdcProxySettingsW
    PSecPkgCredentials_KdcProxySettingsW typedef ptr SecPkgCredentials_KdcProxySettingsW
    SecPkgCredentials_Cert struct
      EncodedCertSize DWORD ?
      EncodedCert POINTER ?
    SecPkgCredentials_Cert ends
    _SecPkgCredentials_Cert typedef SecPkgCredentials_Cert
    PSecPkgCredentials_Cert typedef ptr SecPkgCredentials_Cert
    SECPKG_ATTR_SIZES equ 0
    SECPKG_ATTR_NAMES equ 1
    SECPKG_ATTR_LIFESPAN equ 2
    SECPKG_ATTR_DCE_INFO equ 3
    SECPKG_ATTR_STREAM_SIZES equ 4
    SECPKG_ATTR_KEY_INFO equ 5
    SECPKG_ATTR_AUTHORITY equ 6
    SECPKG_ATTR_PROTO_INFO equ 7
    SECPKG_ATTR_PASSWORD_EXPIRY equ 8
    SECPKG_ATTR_SESSION_KEY equ 9
    SECPKG_ATTR_PACKAGE_INFO equ 10
    SECPKG_ATTR_USER_FLAGS equ 11
    SECPKG_ATTR_NEGOTIATION_INFO equ 12
    SECPKG_ATTR_NATIVE_NAMES equ 13
    SECPKG_ATTR_FLAGS equ 14
    SECPKG_ATTR_USE_VALIDATED equ 15
    SECPKG_ATTR_CREDENTIAL_NAME equ 16
    SECPKG_ATTR_TARGET_INFORMATION equ 17
    SECPKG_ATTR_ACCESS_TOKEN equ 18
    SECPKG_ATTR_TARGET equ 19
    SECPKG_ATTR_AUTHENTICATION_ID equ 20
    SECPKG_ATTR_LOGOFF_TIME equ 21
    SECPKG_ATTR_NEGO_KEYS equ 22
    SECPKG_ATTR_PROMPTING_NEEDED equ 24
    SECPKG_ATTR_UNIQUE_BINDINGS equ 25
    SECPKG_ATTR_ENDPOINT_BINDINGS equ 26
    SECPKG_ATTR_CLIENT_SPECIFIED_TARGET equ 27
    SECPKG_ATTR_LAST_CLIENT_TOKEN_STATUS equ 30
    SECPKG_ATTR_NEGO_PKG_INFO equ 31
    SECPKG_ATTR_NEGO_STATUS equ 32
    SECPKG_ATTR_CONTEXT_DELETED equ 33
    SECPKG_ATTR_DTLS_MTU equ 34
    SECPKG_ATTR_DATAGRAM_SIZES equ <SECPKG_ATTR_STREAM_SIZES>
    SECPKG_ATTR_SUBJECT_SECURITY_ATTRIBUTES equ 128
    SECPKG_ATTR_APPLICATION_PROTOCOL equ 35
    SECPKG_ATTR_NEGOTIATED_TLS_EXTENSIONS equ 36
    SECPKG_ATTR_IS_LOOPBACK equ 37
    SecPkgContext_SubjectAttributes struct
      AttributeInfo POINTER ?
    SecPkgContext_SubjectAttributes ends
    _SecPkgContext_SubjectAttributes typedef SecPkgContext_SubjectAttributes
    PSecPkgContext_SubjectAttributes typedef ptr SecPkgContext_SubjectAttributes
    SECPKG_ATTR_NEGO_INFO_FLAG_NO_KERBEROS equ 1h
    SECPKG_ATTR_NEGO_INFO_FLAG_NO_NTLM equ 2h
    SECPKG_CRED_CLASS typedef SDWORD
    SecPkgCredClass_None equ 0
    SecPkgCredClass_Ephemeral equ 10
    SecPkgCredClass_PersistedGeneric equ 20
    SecPkgCredClass_PersistedSpecific equ 30
    SecPkgCredClass_Explicit equ 40
    _SECPKG_CRED_CLASS typedef SECPKG_CRED_CLASS
    PSECPKG_CRED_CLASS typedef ptr SECPKG_CRED_CLASS
    SecPkgContext_CredInfo struct
      CredClass SECPKG_CRED_CLASS ?
      IsPromptingNeeded DWORD ?
    SecPkgContext_CredInfo ends
    _SecPkgContext_CredInfo typedef SecPkgContext_CredInfo
    PSecPkgContext_CredInfo typedef ptr SecPkgContext_CredInfo
    SecPkgContext_NegoPackageInfo struct
      PackageMask DWORD ?
    SecPkgContext_NegoPackageInfo ends
    _SecPkgContext_NegoPackageInfo typedef SecPkgContext_NegoPackageInfo
    PSecPkgContext_NegoPackageInfo typedef ptr SecPkgContext_NegoPackageInfo
    SecPkgContext_NegoStatus struct
      LastStatus DWORD ?
    SecPkgContext_NegoStatus ends
    _SecPkgContext_NegoStatus typedef SecPkgContext_NegoStatus
    PSecPkgContext_NegoStatus typedef ptr SecPkgContext_NegoStatus
    SecPkgContext_Sizes struct
      cbMaxToken DWORD ?
      cbMaxSignature DWORD ?
      cbBlockSize DWORD ?
      cbSecurityTrailer DWORD ?
    SecPkgContext_Sizes ends
    _SecPkgContext_Sizes typedef SecPkgContext_Sizes
    PSecPkgContext_Sizes typedef ptr SecPkgContext_Sizes
    SecPkgContext_StreamSizes struct
      cbHeader DWORD ?
      cbTrailer DWORD ?
      cbMaximumMessage DWORD ?
      cBuffers DWORD ?
      cbBlockSize DWORD ?
    SecPkgContext_StreamSizes ends
    _SecPkgContext_StreamSizes typedef SecPkgContext_StreamSizes
    PSecPkgContext_StreamSizes typedef ptr SecPkgContext_StreamSizes
    SecPkgContext_DatagramSizes typedef SecPkgContext_StreamSizes
    PSecPkgContext_DatagramSizes typedef PSecPkgContext_StreamSizes
    SecPkgContext_NamesW struct
      sUserName POINTER ?
    SecPkgContext_NamesW ends
    _SecPkgContext_NamesW typedef SecPkgContext_NamesW
    PSecPkgContext_NamesW typedef ptr SecPkgContext_NamesW
    SECPKG_ATTR_LCT_STATUS typedef SDWORD
    SecPkgAttrLastClientTokenYes equ 0
    SecPkgAttrLastClientTokenNo equ 1
    SecPkgAttrLastClientTokenMaybe equ 2
    _SECPKG_ATTR_LCT_STATUS typedef SECPKG_ATTR_LCT_STATUS
    PSECPKG_ATTR_LCT_STATUS typedef ptr SECPKG_ATTR_LCT_STATUS
    SecPkgContext_LastClientTokenStatus struct
      LastClientTokenStatus SECPKG_ATTR_LCT_STATUS ?
    SecPkgContext_LastClientTokenStatus ends
    _SecPkgContext_LastClientTokenStatus typedef SecPkgContext_LastClientTokenStatus
    PSecPkgContext_LastClientTokenStatus typedef ptr SecPkgContext_LastClientTokenStatus
    SecPkgContext_NamesA struct
      sUserName POINTER ?
    SecPkgContext_NamesA ends
    _SecPkgContext_NamesA typedef SecPkgContext_NamesA
    PSecPkgContext_NamesA typedef ptr SecPkgContext_NamesA
    ifdef UNICODE
      SecPkgContext_Names equ <SecPkgContext_NamesW>
      PSecPkgContext_Names equ <PSecPkgContext_NamesW>
    else
      SecPkgContext_Names equ <SecPkgContext_NamesA>
      PSecPkgContext_Names equ <PSecPkgContext_NamesA>
    endif
    SecPkgContext_Lifespan struct
      tsStart TimeStamp <>
      tsExpiry TimeStamp <>
    SecPkgContext_Lifespan ends
    _SecPkgContext_Lifespan typedef SecPkgContext_Lifespan
    PSecPkgContext_Lifespan typedef ptr SecPkgContext_Lifespan
    SecPkgContext_DceInfo struct
      AuthzSvc DWORD ?
      pPac POINTER ?
    SecPkgContext_DceInfo ends
    _SecPkgContext_DceInfo typedef SecPkgContext_DceInfo
    PSecPkgContext_DceInfo typedef ptr SecPkgContext_DceInfo
    SecPkgContext_KeyInfoA struct
      sSignatureAlgorithmName POINTER ?
      sEncryptAlgorithmName POINTER ?
      KeySize DWORD ?
      SignatureAlgorithm DWORD ?
      EncryptAlgorithm DWORD ?
    SecPkgContext_KeyInfoA ends
    _SecPkgContext_KeyInfoA typedef SecPkgContext_KeyInfoA
    PSecPkgContext_KeyInfoA typedef ptr SecPkgContext_KeyInfoA
    SecPkgContext_KeyInfoW struct
      sSignatureAlgorithmName POINTER ?
      sEncryptAlgorithmName POINTER ?
      KeySize DWORD ?
      SignatureAlgorithm DWORD ?
      EncryptAlgorithm DWORD ?
    SecPkgContext_KeyInfoW ends
    _SecPkgContext_KeyInfoW typedef SecPkgContext_KeyInfoW
    PSecPkgContext_KeyInfoW typedef ptr SecPkgContext_KeyInfoW
    ifdef UNICODE
      SecPkgContext_KeyInfo equ <SecPkgContext_KeyInfoW>
      PSecPkgContext_KeyInfo equ <PSecPkgContext_KeyInfoW>
    else
      SecPkgContext_KeyInfo equ <SecPkgContext_KeyInfoA>
      PSecPkgContext_KeyInfo equ <PSecPkgContext_KeyInfoA>
    endif
    SecPkgContext_AuthorityA struct
      sAuthorityName POINTER ?
    SecPkgContext_AuthorityA ends
    _SecPkgContext_AuthorityA typedef SecPkgContext_AuthorityA
    PSecPkgContext_AuthorityA typedef ptr SecPkgContext_AuthorityA
    SecPkgContext_AuthorityW struct
      sAuthorityName POINTER ?
    SecPkgContext_AuthorityW ends
    _SecPkgContext_AuthorityW typedef SecPkgContext_AuthorityW
    PSecPkgContext_AuthorityW typedef ptr SecPkgContext_AuthorityW
    ifdef UNICODE
      SecPkgContext_Authority equ <SecPkgContext_AuthorityW>
      PSecPkgContext_Authority equ <PSecPkgContext_AuthorityW>
    else
      SecPkgContext_Authority equ <SecPkgContext_AuthorityA>
      PSecPkgContext_Authority equ <PSecPkgContext_AuthorityA>
    endif
    SecPkgContext_ProtoInfoA struct
      sProtocolName POINTER ?
      majorVersion DWORD ?
      minorVersion DWORD ?
    SecPkgContext_ProtoInfoA ends
    _SecPkgContext_ProtoInfoA typedef SecPkgContext_ProtoInfoA
    PSecPkgContext_ProtoInfoA typedef ptr SecPkgContext_ProtoInfoA
    SecPkgContext_ProtoInfoW struct
      sProtocolName POINTER ?
      majorVersion DWORD ?
      minorVersion DWORD ?
    SecPkgContext_ProtoInfoW ends
    _SecPkgContext_ProtoInfoW typedef SecPkgContext_ProtoInfoW
    PSecPkgContext_ProtoInfoW typedef ptr SecPkgContext_ProtoInfoW
    ifdef UNICODE
      SecPkgContext_ProtoInfo equ <SecPkgContext_ProtoInfoW>
      PSecPkgContext_ProtoInfo equ <PSecPkgContext_ProtoInfoW>
    else
      SecPkgContext_ProtoInfo equ <SecPkgContext_ProtoInfoA>
      PSecPkgContext_ProtoInfo equ <PSecPkgContext_ProtoInfoA>
    endif
    SecPkgContext_PasswordExpiry struct
      tsPasswordExpires TimeStamp <>
    SecPkgContext_PasswordExpiry ends
    _SecPkgContext_PasswordExpiry typedef SecPkgContext_PasswordExpiry
    PSecPkgContext_PasswordExpiry typedef ptr SecPkgContext_PasswordExpiry
    if NTDDI_VERSION gt NTDDI_WS03
      SecPkgContext_LogoffTime struct
        tsLogoffTime TimeStamp <>
      SecPkgContext_LogoffTime ends
      _SecPkgContext_LogoffTime typedef SecPkgContext_LogoffTime
      PSecPkgContext_LogoffTime typedef ptr SecPkgContext_LogoffTime
    endif
    SecPkgContext_SessionKey struct
      SessionKeyLength DWORD ?
      SessionKey POINTER ?
    SecPkgContext_SessionKey ends
    _SecPkgContext_SessionKey typedef SecPkgContext_SessionKey
    PSecPkgContext_SessionKey typedef ptr SecPkgContext_SessionKey
    SecPkgContext_NegoKeys struct
      KeyType DWORD ?
      KeyLength WORD ?
      KeyValue POINTER ?
      VerifyKeyType DWORD ?
      VerifyKeyLength WORD ?
      VerifyKeyValue POINTER ?
    SecPkgContext_NegoKeys ends
    _SecPkgContext_NegoKeys typedef SecPkgContext_NegoKeys
    PSecPkgContext_NegoKeys typedef ptr SecPkgContext_NegoKeys
    SecPkgContext_PackageInfoW struct
      PackageInfo PSecPkgInfoW ?
    SecPkgContext_PackageInfoW ends
    _SecPkgContext_PackageInfoW typedef SecPkgContext_PackageInfoW
    PSecPkgContext_PackageInfoW typedef ptr SecPkgContext_PackageInfoW
    SecPkgContext_PackageInfoA struct
      PackageInfo PSecPkgInfoA ?
    SecPkgContext_PackageInfoA ends
    _SecPkgContext_PackageInfoA typedef SecPkgContext_PackageInfoA
    PSecPkgContext_PackageInfoA typedef ptr SecPkgContext_PackageInfoA
    SecPkgContext_UserFlags struct
      UserFlags DWORD ?
    SecPkgContext_UserFlags ends
    _SecPkgContext_UserFlags typedef SecPkgContext_UserFlags
    PSecPkgContext_UserFlags typedef ptr SecPkgContext_UserFlags
    SecPkgContext_Flags struct
      Flags DWORD ?
    SecPkgContext_Flags ends
    _SecPkgContext_Flags typedef SecPkgContext_Flags
    PSecPkgContext_Flags typedef ptr SecPkgContext_Flags
    ifdef UNICODE
      SecPkgContext_PackageInfo equ <SecPkgContext_PackageInfoW>
      PSecPkgContext_PackageInfo equ <PSecPkgContext_PackageInfoW>
    else
      SecPkgContext_PackageInfo equ <SecPkgContext_PackageInfoA>
      PSecPkgContext_PackageInfo equ <PSecPkgContext_PackageInfoA>
    endif
    SecPkgContext_NegotiationInfoA struct
      PackageInfo PSecPkgInfoA ?
      NegotiationState DWORD ?
    SecPkgContext_NegotiationInfoA ends
    _SecPkgContext_NegotiationInfoA typedef SecPkgContext_NegotiationInfoA
    PSecPkgContext_NegotiationInfoA typedef ptr SecPkgContext_NegotiationInfoA
    SecPkgContext_NegotiationInfoW struct
      PackageInfo PSecPkgInfoW ?
      NegotiationState DWORD ?
    SecPkgContext_NegotiationInfoW ends
    _SecPkgContext_NegotiationInfoW typedef SecPkgContext_NegotiationInfoW
    PSecPkgContext_NegotiationInfoW typedef ptr SecPkgContext_NegotiationInfoW
    ifdef UNICODE
      SecPkgContext_NegotiationInfo equ <SecPkgContext_NegotiationInfoW>
      PSecPkgContext_NegotiationInfo equ <PSecPkgContext_NegotiationInfoW>
    else
      SecPkgContext_NegotiationInfo equ <SecPkgContext_NegotiationInfoA>
      PSecPkgContext_NegotiationInfo equ <PSecPkgContext_NegotiationInfoA>
    endif
    SECPKG_NEGOTIATION_COMPLETE equ 0
    SECPKG_NEGOTIATION_OPTIMISTIC equ 1
    SECPKG_NEGOTIATION_IN_PROGRESS equ 2
    SECPKG_NEGOTIATION_DIRECT equ 3
    SECPKG_NEGOTIATION_TRY_MULTICRED equ 4
    SecPkgContext_NativeNamesW struct
      sClientName POINTER ?
      sServerName POINTER ?
    SecPkgContext_NativeNamesW ends
    _SecPkgContext_NativeNamesW typedef SecPkgContext_NativeNamesW
    PSecPkgContext_NativeNamesW typedef ptr SecPkgContext_NativeNamesW
    SecPkgContext_NativeNamesA struct
      sClientName POINTER ?
      sServerName POINTER ?
    SecPkgContext_NativeNamesA ends
    _SecPkgContext_NativeNamesA typedef SecPkgContext_NativeNamesA
    PSecPkgContext_NativeNamesA typedef ptr SecPkgContext_NativeNamesA
    ifdef UNICODE
      SecPkgContext_NativeNames equ <SecPkgContext_NativeNamesW>
      PSecPkgContext_NativeNames equ <PSecPkgContext_NativeNamesW>
    else
      SecPkgContext_NativeNames equ <SecPkgContext_NativeNamesA>
      PSecPkgContext_NativeNames equ <PSecPkgContext_NativeNamesA>
    endif
    if OSVER(NTDDI_VERSION) gt NTDDI_WIN2K
      SecPkgContext_CredentialNameW struct
        CredentialType DWORD ?
        sCredentialName POINTER ?
      SecPkgContext_CredentialNameW ends
      _SecPkgContext_CredentialNameW typedef SecPkgContext_CredentialNameW
      PSecPkgContext_CredentialNameW typedef ptr SecPkgContext_CredentialNameW
    endif
    SecPkgContext_CredentialNameA struct
      CredentialType DWORD ?
      sCredentialName POINTER ?
    SecPkgContext_CredentialNameA ends
    _SecPkgContext_CredentialNameA typedef SecPkgContext_CredentialNameA
    PSecPkgContext_CredentialNameA typedef ptr SecPkgContext_CredentialNameA
    ifdef UNICODE
      SecPkgContext_CredentialName equ <SecPkgContext_CredentialNameW>
      PSecPkgContext_CredentialName equ <PSecPkgContext_CredentialNameW>
    else
      SecPkgContext_CredentialName equ <SecPkgContext_CredentialNameA>
      PSecPkgContext_CredentialName equ <PSecPkgContext_CredentialNameA>
    endif
    SecPkgContext_AccessToken struct
      AccessToken POINTER ?
    SecPkgContext_AccessToken ends
    _SecPkgContext_AccessToken typedef SecPkgContext_AccessToken
    PSecPkgContext_AccessToken typedef ptr SecPkgContext_AccessToken
    SecPkgContext_TargetInformation struct
      MarshalledTargetInfoLength DWORD ?
      MarshalledTargetInfo POINTER ?
    SecPkgContext_TargetInformation ends
    _SecPkgContext_TargetInformation typedef SecPkgContext_TargetInformation
    PSecPkgContext_TargetInformation typedef ptr SecPkgContext_TargetInformation
    SecPkgContext_AuthzID struct
      AuthzIDLength DWORD ?
      AuthzID POINTER ?
    SecPkgContext_AuthzID ends
    _SecPkgContext_AuthzID typedef SecPkgContext_AuthzID
    PSecPkgContext_AuthzID typedef ptr SecPkgContext_AuthzID
    SecPkgContext_Target struct
      TargetLength DWORD ?
      Target POINTER ?
    SecPkgContext_Target ends
    _SecPkgContext_Target typedef SecPkgContext_Target
    PSecPkgContext_Target typedef ptr SecPkgContext_Target
    SecPkgContext_ClientSpecifiedTarget struct
      sTargetName POINTER ?
    SecPkgContext_ClientSpecifiedTarget ends
    _SecPkgContext_ClientSpecifiedTarget typedef SecPkgContext_ClientSpecifiedTarget
    PSecPkgContext_ClientSpecifiedTarget typedef ptr SecPkgContext_ClientSpecifiedTarget
    SecPkgContext_Bindings struct
      BindingsLength DWORD ?
      Bindings POINTER ?
    SecPkgContext_Bindings ends
    _SecPkgContext_Bindings typedef SecPkgContext_Bindings
    PSecPkgContext_Bindings typedef ptr SecPkgContext_Bindings
    SEC_APPLICATION_PROTOCOL_NEGOTIATION_STATUS typedef SDWORD
    SecApplicationProtocolNegotiationStatus_None equ 0
    SecApplicationProtocolNegotiationStatus_Success equ 1
    SecApplicationProtocolNegotiationStatus_SelectedClientOnly equ 2
    _SEC_APPLICATION_PROTOCOL_NEGOTIATION_STATUS typedef SEC_APPLICATION_PROTOCOL_NEGOTIATION_STATUS
    PSEC_APPLICATION_PROTOCOL_NEGOTIATION_STATUS typedef ptr SEC_APPLICATION_PROTOCOL_NEGOTIATION_STATUS
    MAX_PROTOCOL_ID_SIZE equ 0ffh
    SecPkgContext_ApplicationProtocol struct
      ProtoNegoStatus SEC_APPLICATION_PROTOCOL_NEGOTIATION_STATUS ?
      ProtoNegoExt SEC_APPLICATION_PROTOCOL_NEGOTIATION_EXT ?
      ProtocolIdSize BYTE ?
      ProtocolId BYTE MAX_PROTOCOL_ID_SIZE dup (?)
    SecPkgContext_ApplicationProtocol ends
    _SecPkgContext_ApplicationProtocol typedef SecPkgContext_ApplicationProtocol
    PSecPkgContext_ApplicationProtocol typedef ptr SecPkgContext_ApplicationProtocol
    SecPkgContext_NegotiatedTlsExtensions struct
      ExtensionsCount DWORD ?
      Extensions POINTER ?
    SecPkgContext_NegotiatedTlsExtensions ends
    _SecPkgContext_NegotiatedTlsExtensions typedef SecPkgContext_NegotiatedTlsExtensions
    PSecPkgContext_NegotiatedTlsExtensions typedef ptr SecPkgContext_NegotiatedTlsExtensions
    SECPKG_APP_MODE_INFO struct
      UserFunction ULONG ?
      Argument1 ULONG_PTR ?
      Argument2 ULONG_PTR ?
      UserData SecBuffer <>
      ReturnToLsa BOOLEAN ?
    SECPKG_APP_MODE_INFO ends
    _SECPKG_APP_MODE_INFO typedef SECPKG_APP_MODE_INFO
    PSECPKG_APP_MODE_INFO typedef ptr SECPKG_APP_MODE_INFO
    TYPE_SEC_GET_KEY_FN typedef proto WIN_STD_CALL_CONV :ptr, :ptr, :DWORD, :ptr ptr, :ptr SECURITY_STATUS
    SEC_GET_KEY_FN typedef ptr TYPE_SEC_GET_KEY_FN

    SECPKG_CONTEXT_EXPORT_RESET_NEW equ 00000001h
    SECPKG_CONTEXT_EXPORT_DELETE_OLD equ 00000002h
    SECPKG_CONTEXT_EXPORT_TO_KERNEL equ 00000004h
    AcquireCredentialsHandleW proto WIN_STD_CALL_CONVif ISSP_MODE eq 0
       :PSECURITY_STRING, :PSECURITY_STRING,else
       :LPWSTR, :LPWSTR,endif
     :DWORD, :ptr, :ptr, :SEC_GET_KEY_FN, :ptr, :PCredHandle, :PTimeStamp
    if ISSP_MODE eq 0
    else
    endif
    TYPE_ACQUIRE_CREDENTIALS_HANDLE_FN_W typedef proto WIN_STD_CALL_CONV :PSECURITY_STRING, :PSECURITY_STRING, :ptr SEC_WCHAR, :ptr SEC_WCHAR, :DWORD, :ptr, :ptr, :SEC_GET_KEY_FN, :ptr, :PCredHandle, :PTimeStamp
    ACQUIRE_CREDENTIALS_HANDLE_FN_W typedef ptr TYPE_ACQUIRE_CREDENTIALS_HANDLE_FN_W

    AcquireCredentialsHandleA proto WIN_STD_CALL_CONV :LPSTR, :LPSTR, :DWORD, :ptr, :ptr, :SEC_GET_KEY_FN, :ptr, :PCredHandle, :PTimeStamp
    TYPE_ACQUIRE_CREDENTIALS_HANDLE_FN_A typedef proto WIN_STD_CALL_CONV :ptr SEC_CHAR, :ptr SEC_CHAR, :DWORD, :ptr, :ptr, :SEC_GET_KEY_FN, :ptr, :PCredHandle, :PTimeStamp
    ACQUIRE_CREDENTIALS_HANDLE_FN_A typedef ptr TYPE_ACQUIRE_CREDENTIALS_HANDLE_FN_A

    ifdef UNICODE
      AcquireCredentialsHandle equ <AcquireCredentialsHandleW>
      ACQUIRE_CREDENTIALS_HANDLE_FN equ <ACQUIRE_CREDENTIALS_HANDLE_FN_W>
    else
      AcquireCredentialsHandle equ <AcquireCredentialsHandleA>
      ACQUIRE_CREDENTIALS_HANDLE_FN equ <ACQUIRE_CREDENTIALS_HANDLE_FN_A>
    endif
    FreeCredentialsHandle proto WIN_STD_CALL_CONV :PCredHandle
    TYPE_FREE_CREDENTIALS_HANDLE_FN typedef proto WIN_STD_CALL_CONV :PCredHandle
    FREE_CREDENTIALS_HANDLE_FN typedef ptr TYPE_FREE_CREDENTIALS_HANDLE_FN

    AddCredentialsW proto WIN_STD_CALL_CONV :PCredHandle,if ISSP_MODE eq 0
       :PSECURITY_STRING, :PSECURITY_STRING,else
       :LPWSTR, :LPWSTR,endif
     :DWORD, :ptr, :SEC_GET_KEY_FN, :ptr, :PTimeStamp
    if ISSP_MODE eq 0
    else
    endif
    TYPE_ADD_CREDENTIALS_FN_W typedef proto WIN_STD_CALL_CONV :PCredHandle, :PSECURITY_STRING, :PSECURITY_STRING, :ptr SEC_WCHAR, :ptr SEC_WCHAR, :DWORD, :ptr, :SEC_GET_KEY_FN, :ptr, :PTimeStamp
    ADD_CREDENTIALS_FN_W typedef ptr TYPE_ADD_CREDENTIALS_FN_W

    AddCredentialsA proto WIN_STD_CALL_CONV :PCredHandle, :LPSTR, :LPSTR, :DWORD, :ptr, :SEC_GET_KEY_FN, :ptr, :PTimeStamp
    TYPE_ADD_CREDENTIALS_FN_A typedef proto WIN_STD_CALL_CONV :PCredHandle, :ptr SEC_CHAR, :ptr SEC_CHAR, :DWORD, :ptr, :SEC_GET_KEY_FN, :ptr, :PTimeStamp
    ADD_CREDENTIALS_FN_A typedef ptr TYPE_ADD_CREDENTIALS_FN_A

    ifdef UNICODE
      AddCredentials equ <AddCredentialsW>
      ADD_CREDENTIALS_FN equ <ADD_CREDENTIALS_FN_W>
    else
      AddCredentials equ <AddCredentialsA>
      ADD_CREDENTIALS_FN equ <ADD_CREDENTIALS_FN_A>
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    if ISSP_MODE eq 0
      SspiAsyncContext typedef _SspiAsyncContext
      TYPE_SspiAsyncNotifyCallback typedef proto WIN_STD_CALL_CONV :ptr SspiAsyncContext, :PVOID
      SspiAsyncNotifyCallback typedef ptr TYPE_SspiAsyncNotifyCallback

      SspiCreateAsyncContext proto WIN_STD_CALL_CONV
      SspiFreeAsyncContext proto WIN_STD_CALL_CONV :ptr SspiAsyncContext
      SspiReinitAsyncContext proto WIN_STD_CALL_CONV :ptr SspiAsyncContext
      SspiSetAsyncNotifyCallback proto WIN_STD_CALL_CONV :ptr SspiAsyncContext, :SspiAsyncNotifyCallback, :ptr
      SspiAsyncContextRequiresNotify proto WIN_STD_CALL_CONV :ptr SspiAsyncContext
      SspiGetAsyncCallStatus proto WIN_STD_CALL_CONV :ptr SspiAsyncContext
      SspiAcquireCredentialsHandleAsyncW proto WIN_STD_CALL_CONV :ptr SspiAsyncContext,if ISSP_MODE eq 0
         :PSECURITY_STRING, :PSECURITY_STRING,else
         :LPWSTR, :LPWSTR,endif
       :DWORD, :ptr, :ptr, :SEC_GET_KEY_FN, :ptr, :PCredHandle, :PTimeStamp
      SspiAcquireCredentialsHandleAsyncA proto WIN_STD_CALL_CONV :ptr SspiAsyncContext, :LPSTR, :LPSTR, :DWORD, :ptr, :ptr, :SEC_GET_KEY_FN, :ptr, :PCredHandle, :PTimeStamp
      SspiInitializeSecurityContextAsyncW proto WIN_STD_CALL_CONV :ptr SspiAsyncContext, :PCredHandle, :PCtxtHandle,if ISSP_MODE eq 0
         :PSECURITY_STRING,else
         :LPWSTR,endif
       :DWORD, :DWORD, :DWORD, :PSecBufferDesc, :DWORD, :PCtxtHandle, :PSecBufferDesc, :ptr DWORD, :PTimeStamp
      SspiInitializeSecurityContextAsyncA proto WIN_STD_CALL_CONV :ptr SspiAsyncContext, :PCredHandle, :PCtxtHandle, :LPSTR, :DWORD, :DWORD, :DWORD, :PSecBufferDesc, :DWORD, :PCtxtHandle, :PSecBufferDesc, :ptr DWORD, :PTimeStamp
      SspiAcceptSecurityContextAsync proto WIN_STD_CALL_CONV :ptr SspiAsyncContext, :PCredHandle, :PCtxtHandle, :PSecBufferDesc, :DWORD, :DWORD, :PCtxtHandle, :PSecBufferDesc, :ptr DWORD, :PTimeStamp
      SspiFreeCredentialsHandleAsync proto WIN_STD_CALL_CONV :ptr SspiAsyncContext, :PCredHandle
      SspiDeleteSecurityContextAsync proto WIN_STD_CALL_CONV :ptr SspiAsyncContext, :PCtxtHandle
      ifdef UNICODE
        SspiAcquireCredentialsHandleAsync equ <SspiAcquireCredentialsHandleAsyncW>
        SspiInitializeSecurityContextAsync equ <SspiInitializeSecurityContextAsyncW>
      else
        SspiAcquireCredentialsHandleAsync equ <SspiAcquireCredentialsHandleAsyncA>
        SspiInitializeSecurityContextAsync equ <SspiInitializeSecurityContextAsync>
      endif
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    if ISSP_MODE ne 0
      ;[...]
    endif
    InitializeSecurityContextW proto WIN_STD_CALL_CONV :PCredHandle, :PCtxtHandle,if ISSP_MODE eq 0
       :PSECURITY_STRING,else
       :ptr SEC_WCHAR,endif
     :DWORD, :DWORD, :DWORD, :PSecBufferDesc, :DWORD, :PCtxtHandle, :PSecBufferDesc, :ptr DWORD, :PTimeStamp
    if ISSP_MODE eq 0
    else
    endif
    TYPE_INITIALIZE_SECURITY_CONTEXT_FN_W typedef proto WIN_STD_CALL_CONV :PCredHandle, :PCtxtHandle, :PSECURITY_STRING, :ptr SEC_WCHAR, :DWORD, :DWORD, :DWORD, :PSecBufferDesc, :DWORD, :PCtxtHandle, :PSecBufferDesc, :ptr DWORD, :PTimeStamp
    INITIALIZE_SECURITY_CONTEXT_FN_W typedef ptr TYPE_INITIALIZE_SECURITY_CONTEXT_FN_W

    InitializeSecurityContextA proto WIN_STD_CALL_CONV :PCredHandle, :PCtxtHandle, :ptr SEC_CHAR, :DWORD, :DWORD, :DWORD, :PSecBufferDesc, :DWORD, :PCtxtHandle, :PSecBufferDesc, :ptr DWORD, :PTimeStamp
    TYPE_INITIALIZE_SECURITY_CONTEXT_FN_A typedef proto WIN_STD_CALL_CONV :PCredHandle, :PCtxtHandle, :ptr SEC_CHAR, :DWORD, :DWORD, :DWORD, :PSecBufferDesc, :DWORD, :PCtxtHandle, :PSecBufferDesc, :ptr DWORD, :PTimeStamp
    INITIALIZE_SECURITY_CONTEXT_FN_A typedef ptr TYPE_INITIALIZE_SECURITY_CONTEXT_FN_A

    ifdef UNICODE
      InitializeSecurityContext equ <InitializeSecurityContextW>
      INITIALIZE_SECURITY_CONTEXT_FN equ <INITIALIZE_SECURITY_CONTEXT_FN_W>
    else
      InitializeSecurityContext equ <InitializeSecurityContextA>
      INITIALIZE_SECURITY_CONTEXT_FN equ <INITIALIZE_SECURITY_CONTEXT_FN_A>
    endif
    AcceptSecurityContext proto WIN_STD_CALL_CONV :PCredHandle, :PCtxtHandle, :PSecBufferDesc, :DWORD, :DWORD, :PCtxtHandle, :PSecBufferDesc, :ptr DWORD, :PTimeStamp
    TYPE_ACCEPT_SECURITY_CONTEXT_FN typedef proto WIN_STD_CALL_CONV :PCredHandle, :PCtxtHandle, :PSecBufferDesc, :DWORD, :DWORD, :PCtxtHandle, :PSecBufferDesc, :ptr DWORD, :PTimeStamp
    ACCEPT_SECURITY_CONTEXT_FN typedef ptr TYPE_ACCEPT_SECURITY_CONTEXT_FN

    CompleteAuthToken proto WIN_STD_CALL_CONV :PCtxtHandle, :PSecBufferDesc
    TYPE_COMPLETE_AUTH_TOKEN_FN typedef proto WIN_STD_CALL_CONV :PCtxtHandle, :PSecBufferDesc
    COMPLETE_AUTH_TOKEN_FN typedef ptr TYPE_COMPLETE_AUTH_TOKEN_FN

    ImpersonateSecurityContext proto WIN_STD_CALL_CONV :PCtxtHandle
    TYPE_IMPERSONATE_SECURITY_CONTEXT_FN typedef proto WIN_STD_CALL_CONV :PCtxtHandle
    IMPERSONATE_SECURITY_CONTEXT_FN typedef ptr TYPE_IMPERSONATE_SECURITY_CONTEXT_FN

    RevertSecurityContext proto WIN_STD_CALL_CONV :PCtxtHandle
    TYPE_REVERT_SECURITY_CONTEXT_FN typedef proto WIN_STD_CALL_CONV :PCtxtHandle
    REVERT_SECURITY_CONTEXT_FN typedef ptr TYPE_REVERT_SECURITY_CONTEXT_FN

    QuerySecurityContextToken proto WIN_STD_CALL_CONV :PCtxtHandle, :ptr ptr
    TYPE_QUERY_SECURITY_CONTEXT_TOKEN_FN typedef proto WIN_STD_CALL_CONV :PCtxtHandle, :ptr ptr
    QUERY_SECURITY_CONTEXT_TOKEN_FN typedef ptr TYPE_QUERY_SECURITY_CONTEXT_TOKEN_FN

    DeleteSecurityContext proto WIN_STD_CALL_CONV :PCtxtHandle
    TYPE_DELETE_SECURITY_CONTEXT_FN typedef proto WIN_STD_CALL_CONV :PCtxtHandle
    DELETE_SECURITY_CONTEXT_FN typedef ptr TYPE_DELETE_SECURITY_CONTEXT_FN

    ApplyControlToken proto WIN_STD_CALL_CONV :PCtxtHandle, :PSecBufferDesc
    TYPE_APPLY_CONTROL_TOKEN_FN typedef proto WIN_STD_CALL_CONV :PCtxtHandle, :PSecBufferDesc
    APPLY_CONTROL_TOKEN_FN typedef ptr TYPE_APPLY_CONTROL_TOKEN_FN

    QueryContextAttributesW proto WIN_STD_CALL_CONV :PCtxtHandle, :DWORD, :ptr
    TYPE_QUERY_CONTEXT_ATTRIBUTES_FN_W typedef proto WIN_STD_CALL_CONV :PCtxtHandle, :DWORD, :ptr
    QUERY_CONTEXT_ATTRIBUTES_FN_W typedef ptr TYPE_QUERY_CONTEXT_ATTRIBUTES_FN_W

    QueryContextAttributesExW proto WIN_STD_CALL_CONV :PCtxtHandle, :DWORD, :ptr, :DWORD
    TYPE_QUERY_CONTEXT_ATTRIBUTES_EX_FN_W typedef proto WIN_STD_CALL_CONV :PCtxtHandle, :DWORD, :ptr, :DWORD
    QUERY_CONTEXT_ATTRIBUTES_EX_FN_W typedef ptr TYPE_QUERY_CONTEXT_ATTRIBUTES_EX_FN_W

    QueryContextAttributesA proto WIN_STD_CALL_CONV :PCtxtHandle, :DWORD, :ptr
    TYPE_QUERY_CONTEXT_ATTRIBUTES_FN_A typedef proto WIN_STD_CALL_CONV :PCtxtHandle, :DWORD, :ptr
    QUERY_CONTEXT_ATTRIBUTES_FN_A typedef ptr TYPE_QUERY_CONTEXT_ATTRIBUTES_FN_A

    QueryContextAttributesExA proto WIN_STD_CALL_CONV :PCtxtHandle, :DWORD, :ptr, :DWORD
    TYPE_QUERY_CONTEXT_ATTRIBUTES_EX_FN_A typedef proto WIN_STD_CALL_CONV :PCtxtHandle, :DWORD, :ptr, :DWORD
    QUERY_CONTEXT_ATTRIBUTES_EX_FN_A typedef ptr TYPE_QUERY_CONTEXT_ATTRIBUTES_EX_FN_A

    ifdef UNICODE
      QueryContextAttributes equ <QueryContextAttributesW>
      QUERY_CONTEXT_ATTRIBUTES_FN equ <QUERY_CONTEXT_ATTRIBUTES_FN_W>
      QueryContextAttributesEx equ <QueryContextAttributesExW>
      QUERY_CONTEXT_ATTRIBUTES_EX_FN equ <QUERY_CONTEXT_ATTRIBUTES_EX_FN_W>
    else
      QueryContextAttributes equ <QueryContextAttributesA>
      QUERY_CONTEXT_ATTRIBUTES_FN equ <QUERY_CONTEXT_ATTRIBUTES_FN_A>
      QueryContextAttributesEx equ <QueryContextAttributesExA>
      QUERY_CONTEXT_ATTRIBUTES_EX_FN equ <QUERY_CONTEXT_ATTRIBUTES_EX_FN_A>
    endif
    if (OSVER(NTDDI_VERSION) gt NTDDI_WIN2K)
      SetContextAttributesW proto WIN_STD_CALL_CONV :PCtxtHandle, :DWORD, :ptr, :DWORD
      TYPE_SET_CONTEXT_ATTRIBUTES_FN_W typedef proto WIN_STD_CALL_CONV :PCtxtHandle, :DWORD, :ptr, :DWORD
      SET_CONTEXT_ATTRIBUTES_FN_W typedef ptr TYPE_SET_CONTEXT_ATTRIBUTES_FN_W

    endif
    SetContextAttributesA proto WIN_STD_CALL_CONV :PCtxtHandle, :DWORD, :ptr, :DWORD
    TYPE_SET_CONTEXT_ATTRIBUTES_FN_A typedef proto WIN_STD_CALL_CONV :PCtxtHandle, :DWORD, :ptr, :DWORD
    SET_CONTEXT_ATTRIBUTES_FN_A typedef ptr TYPE_SET_CONTEXT_ATTRIBUTES_FN_A

    ifdef UNICODE
      SetContextAttributes equ <SetContextAttributesW>
      SET_CONTEXT_ATTRIBUTES_FN equ <SET_CONTEXT_ATTRIBUTES_FN_W>
    else
      SetContextAttributes equ <SetContextAttributesA>
      SET_CONTEXT_ATTRIBUTES_FN equ <SET_CONTEXT_ATTRIBUTES_FN_A>
    endif
    QueryCredentialsAttributesW proto WIN_STD_CALL_CONV :PCredHandle, :DWORD, :ptr
    TYPE_QUERY_CREDENTIALS_ATTRIBUTES_FN_W typedef proto WIN_STD_CALL_CONV :PCredHandle, :DWORD, :ptr
    QUERY_CREDENTIALS_ATTRIBUTES_FN_W typedef ptr TYPE_QUERY_CREDENTIALS_ATTRIBUTES_FN_W

    QueryCredentialsAttributesExW proto WIN_STD_CALL_CONV :PCredHandle, :DWORD, :ptr, :DWORD
    TYPE_QUERY_CREDENTIALS_ATTRIBUTES_EX_FN_W typedef proto WIN_STD_CALL_CONV :PCredHandle, :DWORD, :ptr, :DWORD
    QUERY_CREDENTIALS_ATTRIBUTES_EX_FN_W typedef ptr TYPE_QUERY_CREDENTIALS_ATTRIBUTES_EX_FN_W

    QueryCredentialsAttributesA proto WIN_STD_CALL_CONV :PCredHandle, :DWORD, :ptr
    TYPE_QUERY_CREDENTIALS_ATTRIBUTES_FN_A typedef proto WIN_STD_CALL_CONV :PCredHandle, :DWORD, :ptr
    QUERY_CREDENTIALS_ATTRIBUTES_FN_A typedef ptr TYPE_QUERY_CREDENTIALS_ATTRIBUTES_FN_A

    QueryCredentialsAttributesExA proto WIN_STD_CALL_CONV :PCredHandle, :DWORD, :ptr, :DWORD
    TYPE_QUERY_CREDENTIALS_ATTRIBUTES_EX_FN_A typedef proto WIN_STD_CALL_CONV :PCredHandle, :DWORD, :ptr, :DWORD
    QUERY_CREDENTIALS_ATTRIBUTES_EX_FN_A typedef ptr TYPE_QUERY_CREDENTIALS_ATTRIBUTES_EX_FN_A

    ifdef UNICODE
      QueryCredentialsAttributes equ <QueryCredentialsAttributesW>
      QUERY_CREDENTIALS_ATTRIBUTES_FN equ <QUERY_CREDENTIALS_ATTRIBUTES_FN_W>
      QueryCredentialsAttributesEx equ <QueryCredentialsAttributesExW>
      QUERY_CREDENTIALS_ATTRIBUTES_EX_FN equ <QUERY_CREDENTIALS_ATTRIBUTES_EX_FN_W>
    else
      QueryCredentialsAttributes equ <QueryCredentialsAttributesA>
      QUERY_CREDENTIALS_ATTRIBUTES_FN equ <QUERY_CREDENTIALS_ATTRIBUTES_FN_A>
      QueryCredentialsAttributesEx equ <QueryCredentialsAttributesExA>
      QUERY_CREDENTIALS_ATTRIBUTES_EX_FN equ <QUERY_CREDENTIALS_ATTRIBUTES_EX_FN_A>
    endif
    if NTDDI_VERSION gt NTDDI_WS03
      SetCredentialsAttributesW proto WIN_STD_CALL_CONV :PCredHandle, :DWORD, :ptr, :DWORD
      TYPE_SET_CREDENTIALS_ATTRIBUTES_FN_W typedef proto WIN_STD_CALL_CONV :PCredHandle, :DWORD, :ptr, :DWORD
      SET_CREDENTIALS_ATTRIBUTES_FN_W typedef ptr TYPE_SET_CREDENTIALS_ATTRIBUTES_FN_W

    endif
    SetCredentialsAttributesA proto WIN_STD_CALL_CONV :PCredHandle, :DWORD, :ptr, :DWORD
    TYPE_SET_CREDENTIALS_ATTRIBUTES_FN_A typedef proto WIN_STD_CALL_CONV :PCredHandle, :DWORD, :ptr, :DWORD
    SET_CREDENTIALS_ATTRIBUTES_FN_A typedef ptr TYPE_SET_CREDENTIALS_ATTRIBUTES_FN_A

    ifdef UNICODE
      SetCredentialsAttributes equ <SetCredentialsAttributesW>
      SET_CREDENTIALS_ATTRIBUTES_FN equ <SET_CREDENTIALS_ATTRIBUTES_FN_W>
    else
      SetCredentialsAttributes equ <SetCredentialsAttributesA>
      SET_CREDENTIALS_ATTRIBUTES_FN equ <SET_CREDENTIALS_ATTRIBUTES_FN_A>
    endif
    FreeContextBuffer proto WIN_STD_CALL_CONV :PVOID
    TYPE_FREE_CONTEXT_BUFFER_FN typedef proto WIN_STD_CALL_CONV :PVOID
    FREE_CONTEXT_BUFFER_FN typedef ptr TYPE_FREE_CONTEXT_BUFFER_FN

    MakeSignature proto WIN_STD_CALL_CONV :PCtxtHandle, :DWORD, :PSecBufferDesc, :DWORD
    TYPE_MAKE_SIGNATURE_FN typedef proto WIN_STD_CALL_CONV :PCtxtHandle, :DWORD, :PSecBufferDesc, :DWORD
    MAKE_SIGNATURE_FN typedef ptr TYPE_MAKE_SIGNATURE_FN

    VerifySignature proto WIN_STD_CALL_CONV :PCtxtHandle, :PSecBufferDesc, :DWORD, :ptr DWORD
    TYPE_VERIFY_SIGNATURE_FN typedef proto WIN_STD_CALL_CONV :PCtxtHandle, :PSecBufferDesc, :DWORD, :ptr DWORD
    VERIFY_SIGNATURE_FN typedef ptr TYPE_VERIFY_SIGNATURE_FN

    SECQOP_WRAP_NO_ENCRYPT equ 80000001h
    SECQOP_WRAP_OOB_DATA equ 40000000h
    EncryptMessage proto WIN_STD_CALL_CONV :PCtxtHandle, :DWORD, :PSecBufferDesc, :DWORD
    TYPE_ENCRYPT_MESSAGE_FN typedef proto WIN_STD_CALL_CONV :PCtxtHandle, :DWORD, :PSecBufferDesc, :DWORD
    ENCRYPT_MESSAGE_FN typedef ptr TYPE_ENCRYPT_MESSAGE_FN

    DecryptMessage proto WIN_STD_CALL_CONV :PCtxtHandle, :PSecBufferDesc, :DWORD, :ptr DWORD
    TYPE_DECRYPT_MESSAGE_FN typedef proto WIN_STD_CALL_CONV :PCtxtHandle, :PSecBufferDesc, :DWORD, :ptr DWORD
    DECRYPT_MESSAGE_FN typedef ptr TYPE_DECRYPT_MESSAGE_FN

    EnumerateSecurityPackagesW proto WIN_STD_CALL_CONV :ptr DWORD, :ptr PSecPkgInfoW
    TYPE_ENUMERATE_SECURITY_PACKAGES_FN_W typedef proto WIN_STD_CALL_CONV :ptr DWORD, :ptr PSecPkgInfoW
    ENUMERATE_SECURITY_PACKAGES_FN_W typedef ptr TYPE_ENUMERATE_SECURITY_PACKAGES_FN_W

    EnumerateSecurityPackagesA proto WIN_STD_CALL_CONV :ptr DWORD, :ptr PSecPkgInfoA
    TYPE_ENUMERATE_SECURITY_PACKAGES_FN_A typedef proto WIN_STD_CALL_CONV :ptr DWORD, :ptr PSecPkgInfoA
    ENUMERATE_SECURITY_PACKAGES_FN_A typedef ptr TYPE_ENUMERATE_SECURITY_PACKAGES_FN_A

    ifdef UNICODE
      EnumerateSecurityPackages equ <EnumerateSecurityPackagesW>
      ENUMERATE_SECURITY_PACKAGES_FN equ <ENUMERATE_SECURITY_PACKAGES_FN_W>
    else
      EnumerateSecurityPackages equ <EnumerateSecurityPackagesA>
      ENUMERATE_SECURITY_PACKAGES_FN equ <ENUMERATE_SECURITY_PACKAGES_FN_A>
    endif
    QuerySecurityPackageInfoW proto WIN_STD_CALL_CONVif ISSP_MODE eq 0
       :PSECURITY_STRING,else
       :LPWSTR,endif
     :ptr PSecPkgInfoW
    if ISSP_MODE eq 0
    else
    endif
    TYPE_QUERY_SECURITY_PACKAGE_INFO_FN_W typedef proto WIN_STD_CALL_CONV :PSECURITY_STRING, :ptr SEC_WCHAR, :ptr PSecPkgInfoW
    QUERY_SECURITY_PACKAGE_INFO_FN_W typedef ptr TYPE_QUERY_SECURITY_PACKAGE_INFO_FN_W

    QuerySecurityPackageInfoA proto WIN_STD_CALL_CONV :LPSTR, :ptr PSecPkgInfoA
    TYPE_QUERY_SECURITY_PACKAGE_INFO_FN_A typedef proto WIN_STD_CALL_CONV :ptr SEC_CHAR, :ptr PSecPkgInfoA
    QUERY_SECURITY_PACKAGE_INFO_FN_A typedef ptr TYPE_QUERY_SECURITY_PACKAGE_INFO_FN_A

    ifdef UNICODE
      QuerySecurityPackageInfo equ <QuerySecurityPackageInfoW>
      QUERY_SECURITY_PACKAGE_INFO_FN equ <QUERY_SECURITY_PACKAGE_INFO_FN_W>
    else
      QuerySecurityPackageInfo equ <QuerySecurityPackageInfoA>
      QUERY_SECURITY_PACKAGE_INFO_FN equ <QUERY_SECURITY_PACKAGE_INFO_FN_A>
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    SecDelegationType typedef SDWORD
    SecFull equ 0
    SecService equ 1
    SecTree equ 2
    SecDirectory equ 3
    SecObject equ 4
    _SecDelegationType typedef SecDelegationType
    PSecDelegationType typedef ptr SecDelegationType
    DelegateSecurityContext proto WIN_STD_CALL_CONV :PCtxtHandle,if ISSP_MODE eq 0
       :PSECURITY_STRING,else
       :LPSTR,endif
     :SecDelegationType, :PTimeStamp, :PSecBuffer, :PSecBufferDesc
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    ExportSecurityContext proto WIN_STD_CALL_CONV :PCtxtHandle, :ULONG, :PSecBuffer, :ptr ptr
    TYPE_EXPORT_SECURITY_CONTEXT_FN typedef proto WIN_STD_CALL_CONV :PCtxtHandle, :ULONG, :PSecBuffer, :ptr ptr
    EXPORT_SECURITY_CONTEXT_FN typedef ptr TYPE_EXPORT_SECURITY_CONTEXT_FN

    ImportSecurityContextW proto WIN_STD_CALL_CONVif ISSP_MODE eq 0
       :PSECURITY_STRING,else
       :LPWSTR,endif
     :PSecBuffer, :ptr, :PCtxtHandle
    if ISSP_MODE eq 0
    else
    endif
    TYPE_IMPORT_SECURITY_CONTEXT_FN_W typedef proto WIN_STD_CALL_CONV :PSECURITY_STRING, :ptr SEC_WCHAR, :PSecBuffer, :ptr VOID, :PCtxtHandle
    IMPORT_SECURITY_CONTEXT_FN_W typedef ptr TYPE_IMPORT_SECURITY_CONTEXT_FN_W

    ImportSecurityContextA proto WIN_STD_CALL_CONV :LPSTR, :PSecBuffer, :ptr VOID, :PCtxtHandle
    TYPE_IMPORT_SECURITY_CONTEXT_FN_A typedef proto WIN_STD_CALL_CONV :ptr SEC_CHAR, :PSecBuffer, :ptr, :PCtxtHandle
    IMPORT_SECURITY_CONTEXT_FN_A typedef ptr TYPE_IMPORT_SECURITY_CONTEXT_FN_A

    ifdef UNICODE
      ImportSecurityContext equ <ImportSecurityContextW>
      IMPORT_SECURITY_CONTEXT_FN equ <IMPORT_SECURITY_CONTEXT_FN_W>
    else
      ImportSecurityContext equ <ImportSecurityContextA>
      IMPORT_SECURITY_CONTEXT_FN equ <IMPORT_SECURITY_CONTEXT_FN_A>
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    if ISSP_MODE eq 0
      SecMakeSPN proto WIN_STD_CALL_CONV :PUNICODE_STRING, :PUNICODE_STRING, :PUNICODE_STRING, :USHORT, :PUNICODE_STRING, :PUNICODE_STRING, :PULONG, :BOOLEAN
      if OSVER(NTDDI_VERSION) gt NTDD_WIN2K
        SecMakeSPNEx proto WIN_STD_CALL_CONV :PUNICODE_STRING, :PUNICODE_STRING, :PUNICODE_STRING, :USHORT, :PUNICODE_STRING, :PUNICODE_STRING, :PUNICODE_STRING, :PULONG, :BOOLEAN
        if OSVER(NTDDI_VERSION) gt NTDDI_WS03
          SecMakeSPNEx2 proto WIN_STD_CALL_CONV :PUNICODE_STRING, :PUNICODE_STRING, :PUNICODE_STRING, :USHORT, :PUNICODE_STRING, :PUNICODE_STRING, :PUNICODE_STRING, :PULONG, :BOOLEAN, :BOOLEAN
        endif
        SecLookupAccountSid proto WIN_STD_CALL_CONV :PSID, :PULONG, :PUNICODE_STRING, :PULONG, :PUNICODE_STRING, :PSID_NAME_USE
        SecLookupAccountName proto WIN_STD_CALL_CONV :PUNICODE_STRING, :PULONG, :PSID, :PSID_NAME_USE, :PULONG, :PUNICODE_STRING
      endif
      if OSVER(NTDDI_VERSION) gt NTDDI_WINXP
        SecLookupWellKnownSid proto WIN_STD_CALL_CONV :WELL_KNOWN_SID_TYPE, :PSID, :ULONG, :PULONG
      endif
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    SECURITY_ENTRYPOINT_ANSIW equ <"InitSecurityInterfaceW">
    SECURITY_ENTRYPOINT_ANSIA equ <"InitSecurityInterfaceA">
    SECURITY_ENTRYPOINTW equ <SEC_TEXT ("InitSecurityInterfaceW")>
    SECURITY_ENTRYPOINTA equ <SEC_TEXT ("InitSecurityInterfaceA")>
    SECURITY_ENTRYPOINT16 equ <"INITSECURITYINTERFACEA">
    ifdef SECURITY_WIN32
      ifdef UNICODE
        SECURITY_ENTRYPOINT equ <SECURITY_ENTRYPOINTW>
        SECURITY_ENTRYPOINT_ANSI equ <SECURITY_ENTRYPOINT_ANSIW>
      else
        SECURITY_ENTRYPOINT equ <SECURITY_ENTRYPOINTA>
        SECURITY_ENTRYPOINT_ANSI equ <SECURITY_ENTRYPOINT_ANSIA>
      endif
    else
      SECURITY_ENTRYPOINT equ <SECURITY_ENTRYPOINT16>
      SECURITY_ENTRYPOINT_ANSI equ <SECURITY_ENTRYPOINT16>
    endif
    FreeCredentialHandle equ <FreeCredentialsHandle>
    SecurityFunctionTableW struct
      dwVersion DWORD ?
      EnumerateSecurityPackagesW ENUMERATE_SECURITY_PACKAGES_FN_W ?
      QueryCredentialsAttributesW QUERY_CREDENTIALS_ATTRIBUTES_FN_W ?
      AcquireCredentialsHandleW ACQUIRE_CREDENTIALS_HANDLE_FN_W ?
      FreeCredentialsHandle FREE_CREDENTIALS_HANDLE_FN ?
      Reserved2 POINTER ?
      InitializeSecurityContextW INITIALIZE_SECURITY_CONTEXT_FN_W ?
      AcceptSecurityContext ACCEPT_SECURITY_CONTEXT_FN ?
      CompleteAuthToken COMPLETE_AUTH_TOKEN_FN ?
      DeleteSecurityContext DELETE_SECURITY_CONTEXT_FN ?
      ApplyControlToken APPLY_CONTROL_TOKEN_FN ?
      QueryContextAttributesW QUERY_CONTEXT_ATTRIBUTES_FN_W ?
      ImpersonateSecurityContext IMPERSONATE_SECURITY_CONTEXT_FN ?
      RevertSecurityContext REVERT_SECURITY_CONTEXT_FN ?
      MakeSignature MAKE_SIGNATURE_FN ?
      VerifySignature VERIFY_SIGNATURE_FN ?
      FreeContextBuffer FREE_CONTEXT_BUFFER_FN ?
      QuerySecurityPackageInfoW QUERY_SECURITY_PACKAGE_INFO_FN_W ?
      Reserved3 POINTER ?
      Reserved4 POINTER ?
      ExportSecurityContext EXPORT_SECURITY_CONTEXT_FN ?
      ImportSecurityContextW IMPORT_SECURITY_CONTEXT_FN_W ?
      AddCredentialsW ADD_CREDENTIALS_FN_W ?
      Reserved8 POINTER ?
      QuerySecurityContextToken QUERY_SECURITY_CONTEXT_TOKEN_FN ?
      EncryptMessage ENCRYPT_MESSAGE_FN ?
      DecryptMessage DECRYPT_MESSAGE_FN ?
      if OSVER(NTDDI_VERSION) gt NTDDI_WIN2K
        SetContextAttributesW SET_CONTEXT_ATTRIBUTES_FN_W ?
      endif
      if NTDDI_VERSION gt NTDDI_WS03SP1
        SetCredentialsAttributesW SET_CREDENTIALS_ATTRIBUTES_FN_W ?
      endif
      if ISSP_MODE ne 0
        ;[...]
      else
        Reserved9 POINTER ?
      endif
      if NTDDI_VERSION gt NTDDI_WINBLUE
        QueryContextAttributesExW QUERY_CONTEXT_ATTRIBUTES_EX_FN_W ?
        QueryCredentialsAttributesExW QUERY_CREDENTIALS_ATTRIBUTES_EX_FN_W ?
      endif
    SecurityFunctionTableW ends
    _SECURITY_FUNCTION_TABLE_W typedef SecurityFunctionTableW
    PSecurityFunctionTableW typedef ptr SecurityFunctionTableW
    SecurityFunctionTableA struct
      dwVersion DWORD ?
      EnumerateSecurityPackagesA ENUMERATE_SECURITY_PACKAGES_FN_A ?
      QueryCredentialsAttributesA QUERY_CREDENTIALS_ATTRIBUTES_FN_A ?
      AcquireCredentialsHandleA ACQUIRE_CREDENTIALS_HANDLE_FN_A ?
      FreeCredentialHandle FREE_CREDENTIALS_HANDLE_FN ?
      Reserved2 POINTER ?
      InitializeSecurityContextA INITIALIZE_SECURITY_CONTEXT_FN_A ?
      AcceptSecurityContext ACCEPT_SECURITY_CONTEXT_FN ?
      CompleteAuthToken COMPLETE_AUTH_TOKEN_FN ?
      DeleteSecurityContext DELETE_SECURITY_CONTEXT_FN ?
      ApplyControlToken APPLY_CONTROL_TOKEN_FN ?
      QueryContextAttributesA QUERY_CONTEXT_ATTRIBUTES_FN_A ?
      ImpersonateSecurityContext IMPERSONATE_SECURITY_CONTEXT_FN ?
      RevertSecurityContext REVERT_SECURITY_CONTEXT_FN ?
      MakeSignature MAKE_SIGNATURE_FN ?
      VerifySignature VERIFY_SIGNATURE_FN ?
      FreeContextBuffer FREE_CONTEXT_BUFFER_FN ?
      QuerySecurityPackageInfoA QUERY_SECURITY_PACKAGE_INFO_FN_A ?
      Reserved3 POINTER ?
      Reserved4 POINTER ?
      ExportSecurityContext EXPORT_SECURITY_CONTEXT_FN ?
      ImportSecurityContextA IMPORT_SECURITY_CONTEXT_FN_A ?
      AddCredentialsA ADD_CREDENTIALS_FN_A ?
      Reserved8 POINTER ?
      QuerySecurityContextToken QUERY_SECURITY_CONTEXT_TOKEN_FN ?
      EncryptMessage ENCRYPT_MESSAGE_FN ?
      DecryptMessage DECRYPT_MESSAGE_FN ?
      SetContextAttributesA SET_CONTEXT_ATTRIBUTES_FN_A ?
      SetCredentialsAttributesA SET_CREDENTIALS_ATTRIBUTES_FN_A ?
      if ISSP_MODE ne 0
        ;[...]
      else
        Reserved9 POINTER ?
      endif
      if NTDDI_VERSION gt NTDDI_WINBLUE
        QueryContextAttributesExA QUERY_CONTEXT_ATTRIBUTES_EX_FN_A ?
        QueryCredentialsAttributesExA QUERY_CREDENTIALS_ATTRIBUTES_EX_FN_A ?
      endif
    SecurityFunctionTableA ends
    _SECURITY_FUNCTION_TABLE_A typedef SecurityFunctionTableA
    PSecurityFunctionTableA typedef ptr SecurityFunctionTableA
    ifdef UNICODE
      SecurityFunctionTable equ <SecurityFunctionTableW>
      PSecurityFunctionTable equ <PSecurityFunctionTableW>
    else
      SecurityFunctionTable equ <SecurityFunctionTableA>
      PSecurityFunctionTable equ <PSecurityFunctionTableA>
    endif
    SECURITY_ equ <>
    SECURITY_SUPPORT_PROVIDER_INTERFACE_VERSION equ 1
    SECURITY_SUPPORT_PROVIDER_INTERFACE_VERSION_2 equ 2
    SECURITY_SUPPORT_PROVIDER_INTERFACE_VERSION_3 equ 3
    SECURITY_SUPPORT_PROVIDER_INTERFACE_VERSION_4 equ 4
    SECURITY_SUPPORT_PROVIDER_INTERFACE_VERSION_5 equ 5
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    InitSecurityInterfaceA proto WIN_STD_CALL_CONV
    TYPE_INIT_SECURITY_INTERFACE_A typedef proto WIN_STD_CALL_CONV
    INIT_SECURITY_INTERFACE_A typedef ptr TYPE_INIT_SECURITY_INTERFACE_A

    InitSecurityInterfaceW proto WIN_STD_CALL_CONV
    TYPE_INIT_SECURITY_INTERFACE_W typedef proto WIN_STD_CALL_CONV
    INIT_SECURITY_INTERFACE_W typedef ptr TYPE_INIT_SECURITY_INTERFACE_W

    ifdef UNICODE
      InitSecurityInterface equ <InitSecurityInterfaceW>
      INIT_SECURITY_INTERFACE equ <INIT_SECURITY_INTERFACE_W>
    else
      InitSecurityInterface equ <InitSecurityInterfaceA>
      INIT_SECURITY_INTERFACE equ <INIT_SECURITY_INTERFACE_A>
    endif
    ifdef SECURITY_WIN32
      SaslEnumerateProfilesA proto WIN_STD_CALL_CONV :ptr LPSTR, :ptr ULONG
      SaslEnumerateProfilesW proto WIN_STD_CALL_CONV :ptr LPWSTR, :ptr ULONG
      ifdef UNICODE
        SaslEnumerateProfiles equ <SaslEnumerateProfilesW>
      else
        SaslEnumerateProfiles equ <SaslEnumerateProfilesA>
      endif
      SaslGetProfilePackageA proto WIN_STD_CALL_CONV :LPSTR, :ptr PSecPkgInfoA
      SaslGetProfilePackageW proto WIN_STD_CALL_CONV :LPWSTR, :ptr PSecPkgInfoW
      ifdef UNICODE
        SaslGetProfilePackage equ <SaslGetProfilePackageW>
      else
        SaslGetProfilePackage equ <SaslGetProfilePackageA>
      endif
      SaslIdentifyPackageA proto WIN_STD_CALL_CONV :PSecBufferDesc, :ptr PSecPkgInfoA
      SaslIdentifyPackageW proto WIN_STD_CALL_CONV :PSecBufferDesc, :ptr PSecPkgInfoW
      ifdef UNICODE
        SaslIdentifyPackage equ <SaslIdentifyPackageW>
      else
        SaslIdentifyPackage equ <SaslIdentifyPackageA>
      endif
      SaslInitializeSecurityContextW proto WIN_STD_CALL_CONV :PCredHandle, :PCtxtHandle, :LPWSTR, :DWORD, :DWORD, :DWORD, :PSecBufferDesc, :DWORD, :PCtxtHandle, :PSecBufferDesc, :ptr DWORD, :PTimeStamp
      SaslInitializeSecurityContextA proto WIN_STD_CALL_CONV :PCredHandle, :PCtxtHandle, :LPSTR, :DWORD, :DWORD, :DWORD, :PSecBufferDesc, :DWORD, :PCtxtHandle, :PSecBufferDesc, :ptr DWORD, :PTimeStamp
      ifdef UNICODE
        SaslInitializeSecurityContext equ <SaslInitializeSecurityContextW>
      else
        SaslInitializeSecurityContext equ <SaslInitializeSecurityContextA>
      endif
      SaslAcceptSecurityContext proto WIN_STD_CALL_CONV :PCredHandle, :PCtxtHandle, :PSecBufferDesc, :DWORD, :DWORD, :PCtxtHandle, :PSecBufferDesc, :ptr DWORD, :PTimeStamp
      SASL_OPTION_SEND_SIZE equ 1
      SASL_OPTION_RECV_SIZE equ 2
      SASL_OPTION_AUTHZ_STRING equ 3
      SASL_OPTION_AUTHZ_PROCESSING equ 4
      SASL_AUTHZID_STATE typedef SDWORD
      Sasl_AuthZIDForbidden equ 0
      Sasl_AuthZIDProcessed equ 1
      _SASL_AUTHZID_STATE typedef SASL_AUTHZID_STATE

      SaslSetContextOption proto WIN_STD_CALL_CONV :PCtxtHandle, :ULONG, :PVOID, :ULONG
      SaslGetContextOption proto WIN_STD_CALL_CONV :PCtxtHandle, :ULONG, :PVOID, :ULONG, :PULONG
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    ifdef SECURITY_DOS
      if _MSC_VER ge 1200
      else
      endif
    endif
    ifndef _AUTH_IDENTITY_EX2_DEFINED
      _AUTH_IDENTITY_EX2_DEFINED equ <>
      SEC_WINNT_AUTH_IDENTITY_VERSION_2 equ 201h
      SEC_WINNT_AUTH_IDENTITY_EX2 struct
        Version DWORD ?
        cbHeaderLength WORD ?
        cbStructureLength DWORD ?
        UserOffset DWORD ?
        UserLength WORD ?
        DomainOffset DWORD ?
        DomainLength WORD ?
        PackedCredentialsOffset DWORD ?
        PackedCredentialsLength WORD ?
        Flags DWORD ?
        PackageListOffset DWORD ?
        PackageListLength WORD ?
      SEC_WINNT_AUTH_IDENTITY_EX2 ends
      _SEC_WINNT_AUTH_IDENTITY_EX2 typedef SEC_WINNT_AUTH_IDENTITY_EX2
      PSEC_WINNT_AUTH_IDENTITY_EX2 typedef ptr SEC_WINNT_AUTH_IDENTITY_EX2
    endif
    ifndef _AUTH_IDENTITY_DEFINED
      _AUTH_IDENTITY_DEFINED equ <>
      SEC_WINNT_AUTH_IDENTITY_ANSI equ 1h
      SEC_WINNT_AUTH_IDENTITY_UNICODE equ 2h
      SEC_WINNT_AUTH_IDENTITY_W struct
        User POINTER ?
        UserLength DWORD ?
        Domain POINTER ?
        DomainLength DWORD ?
        Password POINTER ?
        PasswordLength DWORD ?
        Flags DWORD ?
      SEC_WINNT_AUTH_IDENTITY_W ends
      _SEC_WINNT_AUTH_IDENTITY_W typedef SEC_WINNT_AUTH_IDENTITY_W
      PSEC_WINNT_AUTH_IDENTITY_W typedef ptr SEC_WINNT_AUTH_IDENTITY_W
      _AUTH_IDENTITY_A_DEFINED equ <>
      SEC_WINNT_AUTH_IDENTITY_A struct
        User POINTER ?
        UserLength DWORD ?
        Domain POINTER ?
        DomainLength DWORD ?
        Password POINTER ?
        PasswordLength DWORD ?
        Flags DWORD ?
      SEC_WINNT_AUTH_IDENTITY_A ends
      _SEC_WINNT_AUTH_IDENTITY_A typedef SEC_WINNT_AUTH_IDENTITY_A
      PSEC_WINNT_AUTH_IDENTITY_A typedef ptr SEC_WINNT_AUTH_IDENTITY_A
      ifdef UNICODE
        SEC_WINNT_AUTH_IDENTITY equ <SEC_WINNT_AUTH_IDENTITY_W>
        PSEC_WINNT_AUTH_IDENTITY equ <PSEC_WINNT_AUTH_IDENTITY_W>
        _SEC_WINNT_AUTH_IDENTITY equ <_SEC_WINNT_AUTH_IDENTITY_W>
      else
        SEC_WINNT_AUTH_IDENTITY equ <SEC_WINNT_AUTH_IDENTITY_A>
        PSEC_WINNT_AUTH_IDENTITY equ <PSEC_WINNT_AUTH_IDENTITY_A>
        _SEC_WINNT_AUTH_IDENTITY equ <_SEC_WINNT_AUTH_IDENTITY_A>
      endif
    endif
    ifndef SEC_WINNT_AUTH_IDENTITY_VERSION
      SEC_WINNT_AUTH_IDENTITY_VERSION equ 200h
      SEC_WINNT_AUTH_IDENTITY_EXW struct
        Version DWORD ?
        Length_ DWORD ?
        User POINTER ?
        UserLength DWORD ?
        Domain POINTER ?
        DomainLength DWORD ?
        Password POINTER ?
        PasswordLength DWORD ?
        Flags DWORD ?
        PackageList POINTER ?
        PackageListLength DWORD ?
      SEC_WINNT_AUTH_IDENTITY_EXW ends
      _SEC_WINNT_AUTH_IDENTITY_EXW typedef SEC_WINNT_AUTH_IDENTITY_EXW
      PSEC_WINNT_AUTH_IDENTITY_EXW typedef ptr SEC_WINNT_AUTH_IDENTITY_EXW
      SEC_WINNT_AUTH_IDENTITY_EXA struct
        Version DWORD ?
        Length_ DWORD ?
        User POINTER ?
        UserLength DWORD ?
        Domain POINTER ?
        DomainLength DWORD ?
        Password POINTER ?
        PasswordLength DWORD ?
        Flags DWORD ?
        PackageList POINTER ?
        PackageListLength DWORD ?
      SEC_WINNT_AUTH_IDENTITY_EXA ends
      _SEC_WINNT_AUTH_IDENTITY_EXA typedef SEC_WINNT_AUTH_IDENTITY_EXA
      PSEC_WINNT_AUTH_IDENTITY_EXA typedef ptr SEC_WINNT_AUTH_IDENTITY_EXA
      ifdef UNICODE
        SEC_WINNT_AUTH_IDENTITY_EX equ <SEC_WINNT_AUTH_IDENTITY_EXW>
        PSEC_WINNT_AUTH_IDENTITY_EX equ <PSEC_WINNT_AUTH_IDENTITY_EXW>
      else
        SEC_WINNT_AUTH_IDENTITY_EX equ <SEC_WINNT_AUTH_IDENTITY_EXA>
      endif
    endif
    ifndef _AUTH_IDENTITY_INFO_DEFINED
      _AUTH_IDENTITY_INFO_DEFINED equ <>
      SEC_WINNT_AUTH_IDENTITY_INFO union
        AuthIdExw SEC_WINNT_AUTH_IDENTITY_EXW <>
        AuthIdExa SEC_WINNT_AUTH_IDENTITY_EXA <>
        AuthId_a SEC_WINNT_AUTH_IDENTITY_A <>
        AuthId_w SEC_WINNT_AUTH_IDENTITY_W <>
        AuthIdEx2 SEC_WINNT_AUTH_IDENTITY_EX2 <>
      SEC_WINNT_AUTH_IDENTITY_INFO ends
      _SEC_WINNT_AUTH_IDENTITY_INFO typedef SEC_WINNT_AUTH_IDENTITY_INFO
      PSEC_WINNT_AUTH_IDENTITY_INFO typedef ptr SEC_WINNT_AUTH_IDENTITY_INFO
      SEC_WINNT_AUTH_IDENTITY_FLAGS_PROCESS_ENCRYPTED equ 10h
      SEC_WINNT_AUTH_IDENTITY_FLAGS_SYSTEM_PROTECTED equ 20h
      SEC_WINNT_AUTH_IDENTITY_FLAGS_USER_PROTECTED equ 40h
      SEC_WINNT_AUTH_IDENTITY_FLAGS_SYSTEM_ENCRYPTED equ 80h
      SEC_WINNT_AUTH_IDENTITY_FLAGS_RESERVED equ 10000h
      SEC_WINNT_AUTH_IDENTITY_FLAGS_NULL_USER equ 20000h
      SEC_WINNT_AUTH_IDENTITY_FLAGS_NULL_DOMAIN equ 40000h
      SEC_WINNT_AUTH_IDENTITY_FLAGS_ID_PROVIDER equ 80000h
      SEC_WINNT_AUTH_IDENTITY_FLAGS_SSPIPFC_USE_MASK equ 0FF000000h
      SEC_WINNT_AUTH_IDENTITY_FLAGS_SSPIPFC_CREDPROV_DO_NOT_SAVE equ 80000000h
      SEC_WINNT_AUTH_IDENTITY_FLAGS_SSPIPFC_SAVE_CRED_BY_CALLER equ <SEC_WINNT_AUTH_IDENTITY_FLAGS_SSPIPFC_CREDPROV_DO_NOT_SAVE>
      SEC_WINNT_AUTH_IDENTITY_FLAGS_SSPIPFC_SAVE_CRED_CHECKED equ 40000000h
      SEC_WINNT_AUTH_IDENTITY_FLAGS_SSPIPFC_NO_CHECKBOX equ 20000000h
      SEC_WINNT_AUTH_IDENTITY_FLAGS_SSPIPFC_CREDPROV_DO_NOT_LOAD equ 10000000h
      SEC_WINNT_AUTH_IDENTITY_FLAGS_VALID_SSPIPFC_FLAGS equ <(SEC_WINNT_AUTH_IDENTITY_FLAGS_SSPIPFC_CREDPROV_DO_NOT_SAVE or SEC_WINNT_AUTH_IDENTITY_FLAGS_SSPIPFC_SAVE_CRED_CHECKED or SEC_WINNT_AUTH_IDENTITY_FLAGS_SSPIPFC_NO_CHECKBOX or SEC_WINNT_AUTH_IDENTITY_FLAGS_SSPIPFC_CREDPROV_DO_NOT_LOAD)>
    endif
    ifndef _SSPIPFC_NONE_
      PSEC_WINNT_AUTH_IDENTITY_OPAQUE typedef PVOID
    else
      PSEC_WINNT_AUTH_IDENTITY_OPAQUE typedef PSEC_WINNT_AUTH_IDENTITY_INFO
    endif
    SSPIPFC_CREDPROV_DO_NOT_SAVE equ 00000001h
    SSPIPFC_SAVE_CRED_BY_CALLER equ <SSPIPFC_CREDPROV_DO_NOT_SAVE>
    SSPIPFC_NO_CHECKBOX equ 00000002h
    SSPIPFC_CREDPROV_DO_NOT_LOAD equ 00000004h
    SSPIPFC_USE_CREDUIBROKER equ 00000008h
    SSPIPFC_VALID_FLAGS equ <(SSPIPFC_CREDPROV_DO_NOT_SAVE or SSPIPFC_NO_CHECKBOX or SSPIPFC_CREDPROV_DO_NOT_LOAD or SSPIPFC_USE_CREDUIBROKER)>
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    ifndef _SSPIPFC_NONE_
      SspiPromptForCredentialsW proto WIN_STD_CALL_CONV :PCWSTR,ifdef _CREDUI_INFO_DEFINED
         :PCREDUI_INFOW,else
         :PVOID,endif
       :DWORD, :PCWSTR, :PSEC_WINNT_AUTH_IDENTITY_OPAQUE, :ptr PSEC_WINNT_AUTH_IDENTITY_OPAQUE, :ptr SDWORD, :DWORD
      SspiPromptForCredentialsA proto WIN_STD_CALL_CONV :PCSTR,ifdef _CREDUI_INFO_DEFINED
         :PCREDUI_INFOA,else
         :PVOID,endif
       :DWORD, :PCSTR, :PSEC_WINNT_AUTH_IDENTITY_OPAQUE, :ptr PSEC_WINNT_AUTH_IDENTITY_OPAQUE, :ptr SDWORD, :DWORD
    endif
    ifdef UNICODE
      SspiPromptForCredentials equ <SspiPromptForCredentialsW>
    else
      SspiPromptForCredentials equ <SspiPromptForCredentialsA>
    endif
    ifdef _SEC_WINNT_AUTH_TYPES
      SEC_WINNT_AUTH_BYTE_VECTOR struct
        ByteArrayOffset DWORD ?
        ByteArrayLength WORD ?
      SEC_WINNT_AUTH_BYTE_VECTOR ends
      _SEC_WINNT_AUTH_BYTE_VECTOR typedef SEC_WINNT_AUTH_BYTE_VECTOR
      PSEC_WINNT_AUTH_BYTE_VECTOR typedef ptr SEC_WINNT_AUTH_BYTE_VECTOR
      SEC_WINNT_AUTH_DATA struct
        CredType GUID <>
        CredData SEC_WINNT_AUTH_BYTE_VECTOR <>
      SEC_WINNT_AUTH_DATA ends
      _SEC_WINNT_AUTH_DATA typedef SEC_WINNT_AUTH_DATA
      PSEC_WINNT_AUTH_DATA typedef ptr SEC_WINNT_AUTH_DATA
      SEC_WINNT_AUTH_PACKED_CREDENTIALS struct
        cbHeaderLength WORD ?
        cbStructureLength WORD ?
        AuthData SEC_WINNT_AUTH_DATA <>
      SEC_WINNT_AUTH_PACKED_CREDENTIALS ends
      _SEC_WINNT_AUTH_PACKED_CREDENTIALS typedef SEC_WINNT_AUTH_PACKED_CREDENTIALS
      PSEC_WINNT_AUTH_PACKED_CREDENTIALS typedef ptr SEC_WINNT_AUTH_PACKED_CREDENTIALS
      SEC_WINNT_AUTH_DATA_PASSWORD struct
        UnicodePassword SEC_WINNT_AUTH_BYTE_VECTOR <>
      SEC_WINNT_AUTH_DATA_PASSWORD ends
      _SEC_WINNT_AUTH_DATA_PASSWORD typedef SEC_WINNT_AUTH_DATA_PASSWORD
      PSEC_WINNT_AUTH_DATA_PASSWORD typedef SEC_WINNT_AUTH_DATA_PASSWORD
      SEC_WINNT_AUTH_CERTIFICATE_DATA struct
        cbHeaderLength WORD ?
        cbStructureLength WORD ?
        Certificate SEC_WINNT_AUTH_BYTE_VECTOR <>
      SEC_WINNT_AUTH_CERTIFICATE_DATA ends
      _SEC_WINNT_AUTH_CERTIFICATE_DATA typedef SEC_WINNT_AUTH_CERTIFICATE_DATA
      PSEC_WINNT_AUTH_CERTIFICATE_DATA typedef ptr SEC_WINNT_AUTH_CERTIFICATE_DATA
      SEC_WINNT_AUTH_NGC_DATA struct
        LogonId LUID <>
        Flags DWORD ?
        CspInfo SEC_WINNT_AUTH_BYTE_VECTOR <>
        UserIdKeyAuthTicket SEC_WINNT_AUTH_BYTE_VECTOR <>
        DecryptionKeyName SEC_WINNT_AUTH_BYTE_VECTOR <>
        DecryptionKeyAuthTicket SEC_WINNT_AUTH_BYTE_VECTOR <>
      SEC_WINNT_AUTH_NGC_DATA ends
      _SEC_WINNT_AUTH_NGC_DATA typedef SEC_WINNT_AUTH_NGC_DATA
      PSEC_WINNT_AUTH_NGC_DATA typedef ptr SEC_WINNT_AUTH_NGC_DATA
      NGC_DATA_FLAG_KERB_CERTIFICATE_LOGON_FLAG_CHECK_DUPLICATES equ (1h)
      NGC_DATA_FLAG_KERB_CERTIFICATE_LOGON_FLAG_USE_CERTIFICATE_INFO equ (2h)
      NGC_DATA_FLAG_IS_SMARTCARD_DATA equ (4h)
      NGC_DATA_FLAG_IS_CLOUD_TRUST_CRED equ (8h)
      SEC_WINNT_AUTH_DATA_TYPE_SMARTCARD_CONTEXTS_DATA struct
        pcc PVOID ?
        hProv PVOID ?
        pwszECDHKeyName LPWSTR ?
      SEC_WINNT_AUTH_DATA_TYPE_SMARTCARD_CONTEXTS_DATA ends
      _SEC_WINNT_AUTH_DATA_TYPE_SMARTCARD_CONTEXTS_DATA typedef SEC_WINNT_AUTH_DATA_TYPE_SMARTCARD_CONTEXTS_DATA
      PSEC_WINNT_AUTH_DATA_TYPE_SMARTCARD_CONTEXTS_DATA typedef ptr SEC_WINNT_AUTH_DATA_TYPE_SMARTCARD_CONTEXTS_DATA
      SEC_WINNT_AUTH_FIDO_DATA struct
        cbHeaderLength WORD ?
        cbStructureLength WORD ?
        Secret SEC_WINNT_AUTH_BYTE_VECTOR <>
        NewSecret SEC_WINNT_AUTH_BYTE_VECTOR <>
        EncryptedNewSecret SEC_WINNT_AUTH_BYTE_VECTOR <>
        NetworkLogonBuffer SEC_WINNT_AUTH_BYTE_VECTOR <>
        ulSignatureCount ULONG64 ?
      SEC_WINNT_AUTH_FIDO_DATA ends
      _SEC_WINNT_AUTH_FIDO_DATA typedef SEC_WINNT_AUTH_FIDO_DATA
      PSEC_WINNT_AUTH_FIDO_DATA typedef ptr SEC_WINNT_AUTH_FIDO_DATA
      SEC_WINNT_CREDUI_CONTEXT_VECTOR struct
        CredUIContextArrayOffset ULONG ?
        CredUIContextCount USHORT ?
      SEC_WINNT_CREDUI_CONTEXT_VECTOR ends
      _SEC_WINNT_CREDUI_CONTEXT_VECTOR typedef SEC_WINNT_CREDUI_CONTEXT_VECTOR
      PSEC_WINNT_CREDUI_CONTEXT_VECTOR typedef ptr SEC_WINNT_CREDUI_CONTEXT_VECTOR
      SEC_WINNT_AUTH_SHORT_VECTOR struct
        ShortArrayOffset ULONG ?
        ShortArrayCount USHORT ?
      SEC_WINNT_AUTH_SHORT_VECTOR ends
      _SEC_WINNT_AUTH_SHORT_VECTOR typedef SEC_WINNT_AUTH_SHORT_VECTOR
      PSEC_WINNT_AUTH_SHORT_VECTOR typedef ptr SEC_WINNT_AUTH_SHORT_VECTOR
      SspiGetCredUIContext proto WIN_STD_CALL_CONV :HANDLE, :ptr GUID, :ptr LUID, :ptr PSEC_WINNT_CREDUI_CONTEXT_VECTOR, :ptr HANDLE
      SspiUpdateCredentials proto WIN_STD_CALL_CONV :HANDLE, :ptr GUID, :ULONG, :PUCHAR
      CREDUIWIN_MARSHALED_CONTEXT struct
        StructureType GUID <>
        cbHeaderLength USHORT ?
        LogonId LUID <>
        MarshaledDataType GUID <>
        MarshaledDataOffset ULONG ?
        MarshaledDataLength USHORT ?
      CREDUIWIN_MARSHALED_CONTEXT ends
      _CREDUIWIN_MARSHALED_CONTEXT typedef CREDUIWIN_MARSHALED_CONTEXT
      PCREDUIWIN_MARSHALED_CONTEXT typedef ptr CREDUIWIN_MARSHALED_CONTEXT
      SEC_WINNT_CREDUI_CONTEXT struct
        cbHeaderLength USHORT ?
        CredUIContextHandle HANDLE ?
        ifdef _CREDUI_INFO_DEFINED
          UIInfo PCREDUI_INFOW ?
        else
          UIInfo PVOID ?
        endif
        dwAuthError ULONG ?
        pInputAuthIdentity PSEC_WINNT_AUTH_IDENTITY_OPAQUE ?
        TargetName PUNICODE_STRING ?
      SEC_WINNT_CREDUI_CONTEXT ends
      _SEC_WINNT_CREDUI_CONTEXT typedef SEC_WINNT_CREDUI_CONTEXT
      PSEC_WINNT_CREDUI_CONTEXT typedef ptr SEC_WINNT_CREDUI_CONTEXT
      SEC_WINNT_AUTH_PACKED_CREDENTIALS_EX struct
        cbHeaderLength WORD ?
        Flags DWORD ?
        PackedCredentials SEC_WINNT_AUTH_BYTE_VECTOR <>
        PackageList SEC_WINNT_AUTH_SHORT_VECTOR <>
      SEC_WINNT_AUTH_PACKED_CREDENTIALS_EX ends
      _SEC_WINNT_AUTH_PACKED_CREDENTIALS_EX typedef SEC_WINNT_AUTH_PACKED_CREDENTIALS_EX
      PSEC_WINNT_AUTH_PACKED_CREDENTIALS_EX typedef ptr SEC_WINNT_AUTH_PACKED_CREDENTIALS_EX
      SspiUnmarshalCredUIContext proto WIN_STD_CALL_CONV :PUCHAR, :ULONG, :ptr PSEC_WINNT_CREDUI_CONTEXT
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    SspiPrepareForCredRead proto WIN_STD_CALL_CONV :PSEC_WINNT_AUTH_IDENTITY_OPAQUE, :PCWSTR, :PULONG, :ptr PCWSTR
    SspiPrepareForCredWrite proto WIN_STD_CALL_CONV :PSEC_WINNT_AUTH_IDENTITY_OPAQUE, :PCWSTR, :PULONG, :ptr PCWSTR, :ptr PCWSTR, :ptr PUCHAR, :PULONG
    SEC_WINNT_AUTH_IDENTITY_ENCRYPT_SAME_LOGON equ 1h
    SEC_WINNT_AUTH_IDENTITY_ENCRYPT_SAME_PROCESS equ 2h
    SEC_WINNT_AUTH_IDENTITY_ENCRYPT_FOR_SYSTEM equ 4h
    SspiEncryptAuthIdentity proto WIN_STD_CALL_CONV :PSEC_WINNT_AUTH_IDENTITY_OPAQUE
    SspiEncryptAuthIdentityEx proto WIN_STD_CALL_CONV :ULONG, :PSEC_WINNT_AUTH_IDENTITY_OPAQUE
    SspiDecryptAuthIdentity proto WIN_STD_CALL_CONV :PSEC_WINNT_AUTH_IDENTITY_OPAQUE
    SspiDecryptAuthIdentityEx proto WIN_STD_CALL_CONV :ULONG, :PSEC_WINNT_AUTH_IDENTITY_OPAQUE
    SspiIsAuthIdentityEncrypted proto WIN_STD_CALL_CONV :PSEC_WINNT_AUTH_IDENTITY_OPAQUE
    if (NTDDI_VERSION ge NTDDI_WIN7)
      SspiEncodeAuthIdentityAsStrings proto WIN_STD_CALL_CONV :PSEC_WINNT_AUTH_IDENTITY_OPAQUE, :ptr PCWSTR, :ptr PCWSTR, :ptr PCWSTR
      SspiValidateAuthIdentity proto WIN_STD_CALL_CONV :PSEC_WINNT_AUTH_IDENTITY_OPAQUE
      SspiCopyAuthIdentity proto WIN_STD_CALL_CONV :PSEC_WINNT_AUTH_IDENTITY_OPAQUE, :ptr PSEC_WINNT_AUTH_IDENTITY_OPAQUE
      SspiFreeAuthIdentity proto WIN_STD_CALL_CONV :PSEC_WINNT_AUTH_IDENTITY_OPAQUE
      SspiZeroAuthIdentity proto WIN_STD_CALL_CONV :PSEC_WINNT_AUTH_IDENTITY_OPAQUE
      SspiLocalFree proto WIN_STD_CALL_CONV :PVOID
      SspiEncodeStringsAsAuthIdentity proto WIN_STD_CALL_CONV :PCWSTR, :PCWSTR, :PCWSTR, :ptr PSEC_WINNT_AUTH_IDENTITY_OPAQUE
      SspiCompareAuthIdentities proto WIN_STD_CALL_CONV :PSEC_WINNT_AUTH_IDENTITY_OPAQUE, :PSEC_WINNT_AUTH_IDENTITY_OPAQUE, :PBOOLEAN, :PBOOLEAN
      SspiMarshalAuthIdentity proto WIN_STD_CALL_CONV :PSEC_WINNT_AUTH_IDENTITY_OPAQUE, :ptr DWORD, :ptr ptr SBYTE
      SspiUnmarshalAuthIdentity proto WIN_STD_CALL_CONV :DWORD, :ptr SBYTE, :ptr PSEC_WINNT_AUTH_IDENTITY_OPAQUE
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    if (NTDDI_VERSION ge NTDDI_WIN7)
      SspiIsPromptingNeeded proto WIN_STD_CALL_CONV :DWORD
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    if (NTDDI_VERSION ge NTDDI_WIN7)
      SspiGetTargetHostName proto WIN_STD_CALL_CONV :PCWSTR, :ptr PWSTR
      SspiExcludePackage proto WIN_STD_CALL_CONV :PSEC_WINNT_AUTH_IDENTITY_OPAQUE, :PCWSTR, :ptr PSEC_WINNT_AUTH_IDENTITY_OPAQUE
    endif
    SEC_WINNT_AUTH_IDENTITY_MARSHALLED equ 4h
    SEC_WINNT_AUTH_IDENTITY_ONLY equ 8h
    SspiSetChannelBindingFlags proto WIN_STD_CALL_CONV :ptr SecPkgContext_Bindings, :DWORD
    SECURITY_PACKAGE_OPTIONS struct
      Size_ DWORD ?
      Type_ DWORD ?
      Flags DWORD ?
      SignatureSize DWORD ?
      Signature POINTER ?
    SECURITY_PACKAGE_OPTIONS ends
    _SECURITY_PACKAGE_OPTIONS typedef SECURITY_PACKAGE_OPTIONS
    PSECURITY_PACKAGE_OPTIONS typedef ptr SECURITY_PACKAGE_OPTIONS
    SECPKG_OPTIONS_TYPE_UNKNOWN equ 0
    SECPKG_OPTIONS_TYPE_LSA equ 1
    SECPKG_OPTIONS_TYPE_SSPI equ 2
    SECPKG_OPTIONS_PERMANENT equ 00000001h
    AddSecurityPackageA proto WIN_STD_CALL_CONV :LPSTR, :PSECURITY_PACKAGE_OPTIONS
    AddSecurityPackageW proto WIN_STD_CALL_CONV :LPWSTR, :PSECURITY_PACKAGE_OPTIONS
    ifdef UNICODE
      AddSecurityPackage equ <AddSecurityPackageW>
    else
      AddSecurityPackage equ <AddSecurityPackageA>
    endif
    DeleteSecurityPackageA proto WIN_STD_CALL_CONV :LPSTR
    DeleteSecurityPackageW proto WIN_STD_CALL_CONV :LPWSTR
    ifdef UNICODE
      DeleteSecurityPackage equ <DeleteSecurityPackageW>
    else
      DeleteSecurityPackage equ <DeleteSecurityPackageA>
    endif
  endif
  ifdef __cplusplus
    ;[...]
  endif
endif
