;Include file created by h2inc+ version C.2.0 on (UTC) 25/05/2024 20:55:09
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\wincrypt.h
;             Created on (UTC) 06/04/2024 06:16:02
;             Last modified on (UTC) 21/02/2024 18:13:14

ifndef __WINCRYPT_H__
  __WINCRYPT_H__ equ <>
  include specstrings.inc
  if Defined(_MSC_VER)
    if (_MSC_VER ge 800)
      if _MSC_VER ge 1200
      endif
    endif
    if (_MSC_VER gt 1020)
    endif
  endif
  include winapifamily.inc
  ifdef __cplusplus
    ;[...]
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    ifndef _HRESULT_DEFINED
      _HRESULT_DEFINED equ <>
      HRESULT typedef SDWORD
    endif
    ifndef WINADVAPI
      WINADVAPI equ <>
    endif
    ifndef WINAPI
      WINAPI equ <__stdcall>
    endif
    ifndef CALLBACK
      CALLBACK equ <__stdcall>
    endif
    ifndef DECLSPEC_IMPORT
      DECLSPEC_IMPORT equ <>
    endif
    ifndef CONST
      CONST equ <const>
    endif
    ifndef IN_
      IN_ equ <>
    endif
    ifndef OUT_
      OUT_ equ <>
    endif
    ifndef OPTIONAL
      OPTIONAL equ <>
    endif
    if (NTDDI_VERSION ge NTDDI_VISTA)
      if  not Defined(WINCRYPT32API)
        if  not Defined(_CRYPT32_)
          WINCRYPT32API equ <DECLSPEC_IMPORT>
        else
          WINCRYPT32API equ <>
        endif
      endif
    else
      if  not Defined(_CRYPT32_)
        WINCRYPT32API equ <DECLSPEC_IMPORT>
      else
        WINCRYPT32API equ <>
      endif
    endif
    if  not Defined(WINCRYPT32STRINGAPI)
      if  not Defined(_CRYPT32STRING_)
        WINCRYPT32STRINGAPI equ <WINCRYPT32API>
      else
        WINCRYPT32STRINGAPI equ <>
      endif
    endif
    GET_ALG_CLASS macro x
      exitm <(x and (7 shl 13))>
    endm
    GET_ALG_TYPE macro x
      exitm <(x and (15 shl 9))>
    endm
    GET_ALG_SID macro x
      exitm <(x and (511))>
    endm
    ALG_CLASS_ANY equ (0)
    ALG_CLASS_SIGNATURE equ (1 shl 13)
    ALG_CLASS_MSG_ENCRYPT equ (2 shl 13)
    ALG_CLASS_DATA_ENCRYPT equ (3 shl 13)
    ALG_CLASS_HASH equ (4 shl 13)
    ALG_CLASS_KEY_EXCHANGE equ (5 shl 13)
    ALG_CLASS_ALL equ (7 shl 13)
    ALG_TYPE_ANY equ (0)
    ALG_TYPE_DSS equ (1 shl 9)
    ALG_TYPE_RSA equ (2 shl 9)
    ALG_TYPE_BLOCK equ (3 shl 9)
    ALG_TYPE_STREAM equ (4 shl 9)
    ALG_TYPE_DH equ (5 shl 9)
    ALG_TYPE_SECURECHANNEL equ (6 shl 9)
    if (NTDDI_VERSION ge NTDDI_VISTA)
      ALG_TYPE_ECDH equ (7 shl 9)
    endif
    if (NTDDI_VERSION ge NTDDI_WIN10_RS1)
      ALG_TYPE_THIRDPARTY equ (8 shl 9)
    endif
    ALG_SID_ANY equ (0)
    if (NTDDI_VERSION ge NTDDI_WIN10_RS1)
      ALG_SID_THIRDPARTY_ANY equ (0)
    endif
    ALG_SID_RSA_ANY equ 0
    ALG_SID_RSA_PKCS equ 1
    ALG_SID_RSA_MSATWORK equ 2
    ALG_SID_RSA_ENTRUST equ 3
    ALG_SID_RSA_PGP equ 4
    ALG_SID_DSS_ANY equ 0
    ALG_SID_DSS_PKCS equ 1
    ALG_SID_DSS_DMS equ 2
    if (NTDDI_VERSION ge NTDDI_VISTA)
      ALG_SID_ECDSA equ 3
    endif
    ALG_SID_DES equ 1
    ALG_SID_3DES equ 3
    ALG_SID_DESX equ 4
    ALG_SID_IDEA equ 5
    ALG_SID_CAST equ 6
    ALG_SID_SAFERSK64 equ 7
    ALG_SID_SAFERSK128 equ 8
    ALG_SID_3DES_112 equ 9
    ALG_SID_CYLINK_MEK equ 12
    ALG_SID_RC5 equ 13
    if (NTDDI_VERSION ge NTDDI_WINXP)
      ALG_SID_AES_128 equ 14
      ALG_SID_AES_192 equ 15
      ALG_SID_AES_256 equ 16
      ALG_SID_AES equ 17
    endif
    ALG_SID_SKIPJACK equ 10
    ALG_SID_TEK equ 11
    CRYPT_MODE_CBCI equ 6
    CRYPT_MODE_CFBP equ 7
    CRYPT_MODE_OFBP equ 8
    CRYPT_MODE_CBCOFM equ 9
    CRYPT_MODE_CBCOFMI equ 10
    ALG_SID_RC2 equ 2
    ALG_SID_RC4 equ 1
    ALG_SID_SEAL equ 2
    ALG_SID_DH_SANDF equ 1
    ALG_SID_DH_EPHEM equ 2
    ALG_SID_AGREED_KEY_ANY equ 3
    ALG_SID_KEA equ 4
    if (NTDDI_VERSION ge NTDDI_VISTA)
      ALG_SID_ECDH equ 5
      ALG_SID_ECDH_EPHEM equ 6
    endif
    ALG_SID_MD2 equ 1
    ALG_SID_MD4 equ 2
    ALG_SID_MD5 equ 3
    ALG_SID_SHA equ 4
    ALG_SID_SHA1 equ 4
    ALG_SID_MAC equ 5
    ALG_SID_RIPEMD equ 6
    ALG_SID_RIPEMD160 equ 7
    ALG_SID_SSL3SHAMD5 equ 8
    ALG_SID_HMAC equ 9
    ALG_SID_TLS1PRF equ 10
    if (NTDDI_VERSION ge NTDDI_WINXP)
      ALG_SID_HASH_REPLACE_OWF equ 11
    endif
    if (NTDDI_VERSION gt NTDDI_WINXPSP2)
      ALG_SID_SHA_256 equ 12
      ALG_SID_SHA_384 equ 13
      ALG_SID_SHA_512 equ 14
    endif
    ALG_SID_SSL3_MASTER equ 1
    ALG_SID_SCHANNEL_MASTER_HASH equ 2
    ALG_SID_SCHANNEL_MAC_KEY equ 3
    ALG_SID_PCT1_MASTER equ 4
    ALG_SID_SSL2_MASTER equ 5
    ALG_SID_TLS1_MASTER equ 6
    ALG_SID_SCHANNEL_ENC_KEY equ 7
    if (NTDDI_VERSION ge NTDDI_VISTA)
      ALG_SID_ECMQV equ 1
    endif
    ALG_SID_EXAMPLE equ 80
    ifndef ALGIDDEF
      ALGIDDEF equ <>
      ALG_ID typedef DWORD
    endif
    CALG_MD2 equ <(ALG_CLASS_HASH or ALG_TYPE_ANY or ALG_SID_MD2)>
    CALG_MD4 equ <(ALG_CLASS_HASH or ALG_TYPE_ANY or ALG_SID_MD4)>
    CALG_MD5 equ <(ALG_CLASS_HASH or ALG_TYPE_ANY or ALG_SID_MD5)>
    CALG_SHA equ <(ALG_CLASS_HASH or ALG_TYPE_ANY or ALG_SID_SHA)>
    CALG_SHA1 equ <(ALG_CLASS_HASH or ALG_TYPE_ANY or ALG_SID_SHA1)>
    CALG_MAC equ <(ALG_CLASS_HASH or ALG_TYPE_ANY or ALG_SID_MAC)>
    CALG_RSA_SIGN equ <(ALG_CLASS_SIGNATURE or ALG_TYPE_RSA or ALG_SID_RSA_ANY)>
    CALG_DSS_SIGN equ <(ALG_CLASS_SIGNATURE or ALG_TYPE_DSS or ALG_SID_DSS_ANY)>
    if (NTDDI_VERSION ge NTDDI_WINXP)
      CALG_NO_SIGN equ <(ALG_CLASS_SIGNATURE or ALG_TYPE_ANY or ALG_SID_ANY)>
    endif
    CALG_RSA_KEYX equ <(ALG_CLASS_KEY_EXCHANGE or ALG_TYPE_RSA or ALG_SID_RSA_ANY)>
    CALG_DES equ <(ALG_CLASS_DATA_ENCRYPT or ALG_TYPE_BLOCK or ALG_SID_DES)>
    CALG_3DES_112 equ <(ALG_CLASS_DATA_ENCRYPT or ALG_TYPE_BLOCK or ALG_SID_3DES_112)>
    CALG_3DES equ <(ALG_CLASS_DATA_ENCRYPT or ALG_TYPE_BLOCK or ALG_SID_3DES)>
    CALG_DESX equ <(ALG_CLASS_DATA_ENCRYPT or ALG_TYPE_BLOCK or ALG_SID_DESX)>
    CALG_RC2 equ <(ALG_CLASS_DATA_ENCRYPT or ALG_TYPE_BLOCK or ALG_SID_RC2)>
    CALG_RC4 equ <(ALG_CLASS_DATA_ENCRYPT or ALG_TYPE_STREAM or ALG_SID_RC4)>
    CALG_SEAL equ <(ALG_CLASS_DATA_ENCRYPT or ALG_TYPE_STREAM or ALG_SID_SEAL)>
    CALG_DH_SF equ <(ALG_CLASS_KEY_EXCHANGE or ALG_TYPE_DH or ALG_SID_DH_SANDF)>
    CALG_DH_EPHEM equ <(ALG_CLASS_KEY_EXCHANGE or ALG_TYPE_DH or ALG_SID_DH_EPHEM)>
    CALG_AGREEDKEY_ANY equ <(ALG_CLASS_KEY_EXCHANGE or ALG_TYPE_DH or ALG_SID_AGREED_KEY_ANY)>
    CALG_KEA_KEYX equ <(ALG_CLASS_KEY_EXCHANGE or ALG_TYPE_DH or ALG_SID_KEA)>
    CALG_HUGHES_MD5 equ <(ALG_CLASS_KEY_EXCHANGE or ALG_TYPE_ANY or ALG_SID_MD5)>
    CALG_SKIPJACK equ <(ALG_CLASS_DATA_ENCRYPT or ALG_TYPE_BLOCK or ALG_SID_SKIPJACK)>
    CALG_TEK equ <(ALG_CLASS_DATA_ENCRYPT or ALG_TYPE_BLOCK or ALG_SID_TEK)>
    CALG_CYLINK_MEK equ <(ALG_CLASS_DATA_ENCRYPT or ALG_TYPE_BLOCK or ALG_SID_CYLINK_MEK)>
    CALG_SSL3_SHAMD5 equ <(ALG_CLASS_HASH or ALG_TYPE_ANY or ALG_SID_SSL3SHAMD5)>
    CALG_SSL3_MASTER equ <(ALG_CLASS_MSG_ENCRYPT or ALG_TYPE_SECURECHANNEL or ALG_SID_SSL3_MASTER)>
    CALG_SCHANNEL_MASTER_HASH equ <(ALG_CLASS_MSG_ENCRYPT or ALG_TYPE_SECURECHANNEL or ALG_SID_SCHANNEL_MASTER_HASH)>
    CALG_SCHANNEL_MAC_KEY equ <(ALG_CLASS_MSG_ENCRYPT or ALG_TYPE_SECURECHANNEL or ALG_SID_SCHANNEL_MAC_KEY)>
    CALG_SCHANNEL_ENC_KEY equ <(ALG_CLASS_MSG_ENCRYPT or ALG_TYPE_SECURECHANNEL or ALG_SID_SCHANNEL_ENC_KEY)>
    CALG_PCT1_MASTER equ <(ALG_CLASS_MSG_ENCRYPT or ALG_TYPE_SECURECHANNEL or ALG_SID_PCT1_MASTER)>
    CALG_SSL2_MASTER equ <(ALG_CLASS_MSG_ENCRYPT or ALG_TYPE_SECURECHANNEL or ALG_SID_SSL2_MASTER)>
    CALG_TLS1_MASTER equ <(ALG_CLASS_MSG_ENCRYPT or ALG_TYPE_SECURECHANNEL or ALG_SID_TLS1_MASTER)>
    CALG_RC5 equ <(ALG_CLASS_DATA_ENCRYPT or ALG_TYPE_BLOCK or ALG_SID_RC5)>
    CALG_HMAC equ <(ALG_CLASS_HASH or ALG_TYPE_ANY or ALG_SID_HMAC)>
    CALG_TLS1PRF equ <(ALG_CLASS_HASH or ALG_TYPE_ANY or ALG_SID_TLS1PRF)>
    if (NTDDI_VERSION ge NTDDI_WINXP)
      CALG_HASH_REPLACE_OWF equ <(ALG_CLASS_HASH or ALG_TYPE_ANY or ALG_SID_HASH_REPLACE_OWF)>
      CALG_AES_128 equ <(ALG_CLASS_DATA_ENCRYPT or ALG_TYPE_BLOCK or ALG_SID_AES_128)>
      CALG_AES_192 equ <(ALG_CLASS_DATA_ENCRYPT or ALG_TYPE_BLOCK or ALG_SID_AES_192)>
      CALG_AES_256 equ <(ALG_CLASS_DATA_ENCRYPT or ALG_TYPE_BLOCK or ALG_SID_AES_256)>
      CALG_AES equ <(ALG_CLASS_DATA_ENCRYPT or ALG_TYPE_BLOCK or ALG_SID_AES)>
    endif
    if (NTDDI_VERSION gt NTDDI_WINXPSP2)
      CALG_SHA_256 equ <(ALG_CLASS_HASH or ALG_TYPE_ANY or ALG_SID_SHA_256)>
      CALG_SHA_384 equ <(ALG_CLASS_HASH or ALG_TYPE_ANY or ALG_SID_SHA_384)>
      CALG_SHA_512 equ <(ALG_CLASS_HASH or ALG_TYPE_ANY or ALG_SID_SHA_512)>
    endif
    if (NTDDI_VERSION ge NTDDI_VISTA)
      CALG_ECDH equ <(ALG_CLASS_KEY_EXCHANGE or ALG_TYPE_DH or ALG_SID_ECDH)>
      CALG_ECDH_EPHEM equ <(ALG_CLASS_KEY_EXCHANGE or ALG_TYPE_ECDH or ALG_SID_ECDH_EPHEM)>
      CALG_ECMQV equ <(ALG_CLASS_KEY_EXCHANGE or ALG_TYPE_ANY or ALG_SID_ECMQV)>
      CALG_ECDSA equ <(ALG_CLASS_SIGNATURE or ALG_TYPE_DSS or ALG_SID_ECDSA)>
      CALG_NULLCIPHER equ (ALG_CLASS_DATA_ENCRYPT or ALG_TYPE_ANY or 0)
    endif
    if (NTDDI_VERSION ge NTDDI_WIN10_RS1)
      CALG_THIRDPARTY_KEY_EXCHANGE equ <(ALG_CLASS_KEY_EXCHANGE or ALG_TYPE_THIRDPARTY or ALG_SID_THIRDPARTY_ANY)>
      CALG_THIRDPARTY_SIGNATURE equ <(ALG_CLASS_SIGNATURE or ALG_TYPE_THIRDPARTY or ALG_SID_THIRDPARTY_ANY)>
      CALG_THIRDPARTY_CIPHER equ <(ALG_CLASS_DATA_ENCRYPT or ALG_TYPE_THIRDPARTY or ALG_SID_THIRDPARTY_ANY)>
      CALG_THIRDPARTY_HASH equ <(ALG_CLASS_HASH or ALG_TYPE_THIRDPARTY or ALG_SID_THIRDPARTY_ANY)>
    endif
    if (NTDDI_VERSION lt NTDDI_WINXP)
      SIGNATURE_RESOURCE_NUMBER equ 29Ah
      VTableProvStruc struct
        Version DWORD ?
        FuncVerifyImage FARPROC ?
        FuncReturnhWnd FARPROC ?
        dwProvType DWORD ?
        pbContextInfo POINTER ?
        cbContextInfo DWORD ?
        pszProvName LPSTR ?
      VTableProvStruc ends
      _VTableProvStruc typedef VTableProvStruc
      PVTableProvStruc typedef ptr VTableProvStruc
    endif
    ifndef HCRYPTPROV_DEFINED
      HCRYPTPROV_DEFINED equ <>
      HCRYPTPROV typedef ULONG_PTR
      HCRYPTKEY typedef ULONG_PTR
      HCRYPTHASH typedef ULONG_PTR
    endif
    CRYPT_VERIFYCONTEXT equ 0F0000000h
    CRYPT_NEWKEYSET equ 00000008h
    CRYPT_DELETEKEYSET equ 00000010h
    CRYPT_MACHINE_KEYSET equ 00000020h
    CRYPT_SILENT equ 00000040h
    if (NTDDI_VERSION ge NTDDI_VISTA)
      CRYPT_DEFAULT_CONTAINER_OPTIONAL equ 00000080h
    endif
    CRYPT_EXPORTABLE equ 00000001h
    CRYPT_USER_PROTECTED equ 00000002h
    CRYPT_CREATE_SALT equ 00000004h
    CRYPT_UPDATE_KEY equ 00000008h
    CRYPT_NO_SALT equ 00000010h
    CRYPT_PREGEN equ 00000040h
    CRYPT_RECIPIENT equ 00000010h
    CRYPT_INITIATOR equ 00000040h
    CRYPT_ONLINE equ 00000080h
    CRYPT_SF equ 00000100h
    CRYPT_CREATE_IV equ 00000200h
    CRYPT_KEK equ 00000400h
    CRYPT_DATA_KEY equ 00000800h
    CRYPT_VOLATILE equ 00001000h
    CRYPT_SGCKEY equ 00002000h
    CRYPT_USER_PROTECTED_STRONG equ 00100000h
    if (NTDDI_VERSION ge NTDDI_WINXP)
      CRYPT_ARCHIVABLE equ 00004000h
    endif
    if (NTDDI_VERSION ge NTDDI_VISTA)
      CRYPT_FORCE_KEY_PROTECTION_HIGH equ 00008000h
    endif
    RSA1024BIT_KEY equ 04000000h
    CRYPT_SERVER equ 00000400h
    KEY_LENGTH_MASK equ 0FFFF0000h
    CRYPT_Y_ONLY equ 00000001h
    CRYPT_SSL2_FALLBACK equ 00000002h
    CRYPT_DESTROYKEY equ 00000004h
    CRYPT_OAEP equ 00000040h
    CRYPT_BLOB_VER3 equ 00000080h
    if (NTDDI_VERSION ge NTDDI_WINXP)
      CRYPT_IPSEC_HMAC_KEY equ 00000100h
    endif
    if (NTDDI_VERSION ge NTDDI_WS03)
      CRYPT_DECRYPT_RSA_NO_PADDING_CHECK equ 00000020h
    endif
    CRYPT_SECRETDIGEST equ 00000001h
    if (NTDDI_VERSION ge NTDDI_WINXP)
      CRYPT_OWF_REPL_LM_HASH equ 00000001h
    endif
    CRYPT_LITTLE_ENDIAN equ 00000001h
    CRYPT_NOHASHOID equ 00000001h
    CRYPT_TYPE2_FORMAT equ 00000002h
    CRYPT_X931_FORMAT equ 00000004h
    CRYPT_MACHINE_DEFAULT equ 00000001h
    CRYPT_USER_DEFAULT equ 00000002h
    CRYPT_DELETE_DEFAULT equ 00000004h
    SIMPLEBLOB equ 1h
    PUBLICKEYBLOB equ 6h
    PRIVATEKEYBLOB equ 7h
    PLAINTEXTKEYBLOB equ 8h
    OPAQUEKEYBLOB equ 9h
    PUBLICKEYBLOBEX equ 0Ah
    SYMMETRICWRAPKEYBLOB equ 0Bh
    if (NTDDI_VERSION ge NTDDI_WS03)
      KEYSTATEBLOB equ 0Ch
    endif
    AT_KEYEXCHANGE equ 1
    AT_SIGNATURE equ 2
    CRYPT_USERDATA equ 1
    KP_IV equ 1
    KP_SALT equ 2
    KP_PADDING equ 3
    KP_MODE equ 4
    KP_MODE_BITS equ 5
    KP_PERMISSIONS equ 6
    KP_ALGID equ 7
    KP_BLOCKLEN equ 8
    KP_KEYLEN equ 9
    KP_SALT_EX equ 10
    KP_P equ 11
    KP_G equ 12
    KP_Q equ 13
    KP_X equ 14
    KP_Y equ 15
    KP_RA equ 16
    KP_RB equ 17
    KP_INFO equ 18
    KP_EFFECTIVE_KEYLEN equ 19
    KP_SCHANNEL_ALG equ 20
    KP_CLIENT_RANDOM equ 21
    KP_SERVER_RANDOM equ 22
    KP_RP equ 23
    KP_PRECOMP_MD5 equ 24
    KP_PRECOMP_SHA equ 25
    KP_CERTIFICATE equ 26
    KP_CLEAR_KEY equ 27
    KP_PUB_EX_LEN equ 28
    KP_PUB_EX_VAL equ 29
    KP_KEYVAL equ 30
    KP_ADMIN_PIN equ 31
    KP_KEYEXCHANGE_PIN equ 32
    KP_SIGNATURE_PIN equ 33
    KP_PREHASH equ 34
    if (NTDDI_VERSION ge NTDDI_WS03)
      KP_ROUNDS equ 35
    endif
    KP_OAEP_PARAMS equ 36
    KP_CMS_KEY_INFO equ 37
    KP_CMS_DH_KEY_INFO equ 38
    KP_PUB_PARAMS equ 39
    KP_VERIFY_PARAMS equ 40
    KP_HIGHEST_VERSION equ 41
    if (NTDDI_VERSION ge NTDDI_WS03)
      KP_GET_USE_COUNT equ 42
    endif
    KP_PIN_ID equ 43
    KP_PIN_INFO equ 44
    PKCS5_PADDING equ 1
    RANDOM_PADDING equ 2
    ZERO_PADDING equ 3
    CRYPT_MODE_CBC equ 1
    CRYPT_MODE_ECB equ 2
    CRYPT_MODE_OFB equ 3
    CRYPT_MODE_CFB equ 4
    CRYPT_MODE_CTS equ 5
    CRYPT_ENCRYPT equ 0001h
    CRYPT_DECRYPT equ 0002h
    CRYPT_EXPORT equ 0004h
    CRYPT_READ equ 0008h
    CRYPT_WRITE equ 0010h
    CRYPT_MAC equ 0020h
    CRYPT_EXPORT_KEY equ 0040h
    CRYPT_IMPORT_KEY equ 0080h
    if (NTDDI_VERSION ge NTDDI_WINXP)
      CRYPT_ARCHIVE equ 0100h
    endif
    HP_ALGID equ 0001h
    HP_HASHVAL equ 0002h
    HP_HASHSIZE equ 0004h
    HP_HMAC_INFO equ 0005h
    HP_TLS1PRF_LABEL equ 0006h
    HP_TLS1PRF_SEED equ 0007h
    CRYPT_FAILED equ <FALSE>
    CRYPT_SUCCEED equ <TRUE>
    RCRYPT_SUCCEEDED macro rt
      exitm <((rt) == CRYPT_SUCCEED)>
    endm
    RCRYPT_FAILED macro rt
      exitm <((rt) == CRYPT_FAILED)>
    endm
    PP_ENUMALGS equ 1
    PP_ENUMCONTAINERS equ 2
    PP_IMPTYPE equ 3
    PP_NAME equ 4
    PP_VERSION equ 5
    PP_CONTAINER equ 6
    PP_CHANGE_PASSWORD equ 7
    PP_KEYSET_SEC_DESCR equ 8
    PP_CERTCHAIN equ 9
    PP_KEY_TYPE_SUBTYPE equ 10
    PP_PROVTYPE equ 16
    PP_KEYSTORAGE equ 17
    PP_APPLI_CERT equ 18
    PP_SYM_KEYSIZE equ 19
    PP_SESSION_KEYSIZE equ 20
    PP_UI_PROMPT equ 21
    PP_ENUMALGS_EX equ 22
    PP_ENUMMANDROOTS equ 25
    PP_ENUMELECTROOTS equ 26
    PP_KEYSET_TYPE equ 27
    PP_ADMIN_PIN equ 31
    PP_KEYEXCHANGE_PIN equ 32
    PP_SIGNATURE_PIN equ 33
    PP_SIG_KEYSIZE_INC equ 34
    PP_KEYX_KEYSIZE_INC equ 35
    PP_UNIQUE_CONTAINER equ 36
    PP_SGC_INFO equ 37
    PP_USE_HARDWARE_RNG equ 38
    PP_KEYSPEC equ 39
    PP_ENUMEX_SIGNING_PROT equ 40
    if (NTDDI_VERSION ge NTDDI_WS03)
      PP_CRYPT_COUNT_KEY_USE equ 41
    endif
    if (NTDDI_VERSION ge NTDDI_VISTA)
      PP_USER_CERTSTORE equ 42
      PP_SMARTCARD_READER equ 43
      PP_SMARTCARD_GUID equ 45
      PP_ROOT_CERTSTORE equ 46
    endif
    if (NTDDI_VERSION ge NTDDI_WIN8)
      PP_SMARTCARD_READER_ICON equ 47
    endif
    CRYPT_FIRST equ 1
    CRYPT_NEXT equ 2
    CRYPT_SGC_ENUM equ 4
    CRYPT_IMPL_HARDWARE equ 1
    CRYPT_IMPL_SOFTWARE equ 2
    CRYPT_IMPL_MIXED equ 3
    CRYPT_IMPL_UNKNOWN equ 4
    CRYPT_IMPL_REMOVABLE equ 8
    CRYPT_SEC_DESCR equ 00000001h
    CRYPT_PSTORE equ 00000002h
    CRYPT_UI_PROMPT equ 00000004h
    CRYPT_FLAG_PCT1 equ 0001h
    CRYPT_FLAG_SSL2 equ 0002h
    CRYPT_FLAG_SSL3 equ 0004h
    CRYPT_FLAG_TLS1 equ 0008h
    CRYPT_FLAG_IPSEC equ 0010h
    CRYPT_FLAG_SIGNING equ 0020h
    CRYPT_SGC equ 0001h
    CRYPT_FASTSGC equ 0002h
    PP_CLIENT_HWND equ 1
    PP_CONTEXT_INFO equ 11
    PP_KEYEXCHANGE_KEYSIZE equ 12
    PP_SIGNATURE_KEYSIZE equ 13
    PP_KEYEXCHANGE_ALG equ 14
    PP_SIGNATURE_ALG equ 15
    PP_DELETEKEY equ 24
    if (NTDDI_VERSION ge NTDDI_VISTA)
      PP_PIN_PROMPT_STRING equ 44
      PP_SECURE_KEYEXCHANGE_PIN equ 47
      PP_SECURE_SIGNATURE_PIN equ 48
    endif
    if (NTDDI_VERSION ge NTDDI_WIN10_RS5)
      PP_DISMISS_PIN_UI_SEC equ 49
      PP_IS_PFX_EPHEMERAL equ 50
    endif
    PROV_RSA_FULL equ 1
    PROV_RSA_SIG equ 2
    PROV_DSS equ 3
    PROV_FORTEZZA equ 4
    PROV_MS_EXCHANGE equ 5
    PROV_SSL equ 6
    PROV_RSA_SCHANNEL equ 12
    PROV_DSS_DH equ 13
    PROV_EC_ECDSA_SIG equ 14
    PROV_EC_ECNRA_SIG equ 15
    PROV_EC_ECDSA_FULL equ 16
    PROV_EC_ECNRA_FULL equ 17
    PROV_DH_SCHANNEL equ 18
    PROV_SPYRUS_LYNKS equ 20
    PROV_RNG equ 21
    PROV_INTEL_SEC equ 22
    if (NTDDI_VERSION ge NTDDI_WINXP)
      PROV_REPLACE_OWF equ 23
      PROV_RSA_AES equ 24
    endif
    if (NTDDI_VERSION le NTDDI_WINXP)
      PROV_STT_MER equ 7
      PROV_STT_ACQ equ 8
      PROV_STT_BRND equ 9
      PROV_STT_ROOT equ 10
      PROV_STT_ISS equ 11
    endif
    MS_DEF_PROV_A equ <"Microsoft Base Cryptographic Provider v1.0">
    MS_DEF_PROV_W equ <L("Microsoft Base Cryptographic Provider v1.0")>
    ifdef UNICODE
      MS_DEF_PROV equ <MS_DEF_PROV_W>
    else
      MS_DEF_PROV equ <MS_DEF_PROV_A>
    endif
    MS_ENHANCED_PROV_A equ <"Microsoft Enhanced Cryptographic Provider v1.0">
    MS_ENHANCED_PROV_W equ <L("Microsoft Enhanced Cryptographic Provider v1.0")>
    ifdef UNICODE
      MS_ENHANCED_PROV equ <MS_ENHANCED_PROV_W>
    else
      MS_ENHANCED_PROV equ <MS_ENHANCED_PROV_A>
    endif
    MS_STRONG_PROV_A equ <"Microsoft Strong Cryptographic Provider">
    MS_STRONG_PROV_W equ <L("Microsoft Strong Cryptographic Provider")>
    ifdef UNICODE
      MS_STRONG_PROV equ <MS_STRONG_PROV_W>
    else
      MS_STRONG_PROV equ <MS_STRONG_PROV_A>
    endif
    MS_DEF_RSA_SIG_PROV_A equ <"Microsoft RSA Signature Cryptographic Provider">
    MS_DEF_RSA_SIG_PROV_W equ <L("Microsoft RSA Signature Cryptographic Provider")>
    ifdef UNICODE
      MS_DEF_RSA_SIG_PROV equ <MS_DEF_RSA_SIG_PROV_W>
    else
      MS_DEF_RSA_SIG_PROV equ <MS_DEF_RSA_SIG_PROV_A>
    endif
    MS_DEF_RSA_SCHANNEL_PROV_A equ <"Microsoft RSA SChannel Cryptographic Provider">
    MS_DEF_RSA_SCHANNEL_PROV_W equ <L("Microsoft RSA SChannel Cryptographic Provider")>
    ifdef UNICODE
      MS_DEF_RSA_SCHANNEL_PROV equ <MS_DEF_RSA_SCHANNEL_PROV_W>
    else
      MS_DEF_RSA_SCHANNEL_PROV equ <MS_DEF_RSA_SCHANNEL_PROV_A>
    endif
    MS_DEF_DSS_PROV_A equ <"Microsoft Base DSS Cryptographic Provider">
    MS_DEF_DSS_PROV_W equ <L("Microsoft Base DSS Cryptographic Provider")>
    ifdef UNICODE
      MS_DEF_DSS_PROV equ <MS_DEF_DSS_PROV_W>
    else
      MS_DEF_DSS_PROV equ <MS_DEF_DSS_PROV_A>
    endif
    MS_DEF_DSS_DH_PROV_A equ <"Microsoft Base DSS and Diffie-Hellman Cryptographic Provider">
    MS_DEF_DSS_DH_PROV_W equ <L("Microsoft Base DSS and Diffie-Hellman Cryptographic Provider")>
    ifdef UNICODE
      MS_DEF_DSS_DH_PROV equ <MS_DEF_DSS_DH_PROV_W>
    else
      MS_DEF_DSS_DH_PROV equ <MS_DEF_DSS_DH_PROV_A>
    endif
    MS_ENH_DSS_DH_PROV_A equ <"Microsoft Enhanced DSS and Diffie-Hellman Cryptographic Provider">
    MS_ENH_DSS_DH_PROV_W equ <L("Microsoft Enhanced DSS and Diffie-Hellman Cryptographic Provider")>
    ifdef UNICODE
      MS_ENH_DSS_DH_PROV equ <MS_ENH_DSS_DH_PROV_W>
    else
      MS_ENH_DSS_DH_PROV equ <MS_ENH_DSS_DH_PROV_A>
    endif
    MS_DEF_DH_SCHANNEL_PROV_A equ <"Microsoft DH SChannel Cryptographic Provider">
    MS_DEF_DH_SCHANNEL_PROV_W equ <L("Microsoft DH SChannel Cryptographic Provider")>
    ifdef UNICODE
      MS_DEF_DH_SCHANNEL_PROV equ <MS_DEF_DH_SCHANNEL_PROV_W>
    else
      MS_DEF_DH_SCHANNEL_PROV equ <MS_DEF_DH_SCHANNEL_PROV_A>
    endif
    MS_SCARD_PROV_A equ <"Microsoft Base Smart Card Crypto Provider">
    MS_SCARD_PROV_W equ <L("Microsoft Base Smart Card Crypto Provider")>
    ifdef UNICODE
      MS_SCARD_PROV equ <MS_SCARD_PROV_W>
    else
      MS_SCARD_PROV equ <MS_SCARD_PROV_A>
    endif
    if (NTDDI_VERSION ge NTDDI_WINXP)
      MS_ENH_RSA_AES_PROV_A equ <"Microsoft Enhanced RSA and AES Cryptographic Provider">
      MS_ENH_RSA_AES_PROV_W equ <L("Microsoft Enhanced RSA and AES Cryptographic Provider")>
      MS_ENH_RSA_AES_PROV_XP_A equ <"Microsoft Enhanced RSA and AES Cryptographic Provider (Prototype)">
      MS_ENH_RSA_AES_PROV_XP_W equ <L("Microsoft Enhanced RSA and AES Cryptographic Provider (Prototype)")>
      ifdef UNICODE
        MS_ENH_RSA_AES_PROV_XP equ <MS_ENH_RSA_AES_PROV_XP_W>
        MS_ENH_RSA_AES_PROV equ <MS_ENH_RSA_AES_PROV_W>
      else
        MS_ENH_RSA_AES_PROV_XP equ <MS_ENH_RSA_AES_PROV_XP_A>
        MS_ENH_RSA_AES_PROV equ <MS_ENH_RSA_AES_PROV_A>
      endif
    endif
    MAXUIDLEN equ 64
    EXPO_OFFLOAD_REG_VALUE equ <"ExpoOffload">
    EXPO_OFFLOAD_FUNC_NAME equ <"OffloadModExpo">
    ifndef szKEY_CRYPTOAPI_PRIVATE_KEY_OPTIONS
      szKEY_CRYPTOAPI_PRIVATE_KEY_OPTIONS equ <"Software\Policies\Microsoft\Cryptography">
    endif
    szKEY_CACHE_ENABLED equ <"CachePrivateKeys">
    szKEY_CACHE_SECONDS equ <"PrivateKeyLifetimeSeconds">
    if (NTDDI_VERSION ge NTDDI_WINXP)
      szPRIV_KEY_CACHE_MAX_ITEMS equ <"PrivKeyCacheMaxItems">
      cPRIV_KEY_CACHE_MAX_ITEMS_DEFAULT equ 20
      szPRIV_KEY_CACHE_PURGE_INTERVAL_SECONDS equ <"PrivKeyCachePurgeIntervalSeconds">
      cPRIV_KEY_CACHE_PURGE_INTERVAL_SECONDS_DEFAULT equ 86400
    endif
    CUR_BLOB_VERSION equ 2
    CMS_KEY_INFO struct
      dwVersion DWORD ?
      Algid ALG_ID ?
      pbOID POINTER ?
      cbOID DWORD ?
    CMS_KEY_INFO ends
    _CMS_KEY_INFO typedef CMS_KEY_INFO
    PCMS_KEY_INFO typedef ptr CMS_KEY_INFO
    HMAC_INFO struct
      HashAlgid ALG_ID ?
      pbInnerString POINTER ?
      cbInnerString DWORD ?
      pbOuterString POINTER ?
      cbOuterString DWORD ?
    HMAC_INFO ends
    _HMAC_Info typedef HMAC_INFO
    PHMAC_INFO typedef ptr HMAC_INFO
    SCHANNEL_ALG struct
      dwUse DWORD ?
      Algid ALG_ID ?
      cBits DWORD ?
      dwFlags DWORD ?
      dwReserved DWORD ?
    SCHANNEL_ALG ends
    _SCHANNEL_ALG typedef SCHANNEL_ALG
    PSCHANNEL_ALG typedef ptr SCHANNEL_ALG
    SCHANNEL_MAC_KEY equ 00000000h
    SCHANNEL_ENC_KEY equ 00000001h
    INTERNATIONAL_USAGE equ 00000001h
    PROV_ENUMALGS struct
      aiAlgid ALG_ID ?
      dwBitLen DWORD ?
      dwNameLen DWORD ?
      szName CHAR 20 dup (?)
    PROV_ENUMALGS ends
    _PROV_ENUMALGS typedef PROV_ENUMALGS
    PROV_ENUMALGS_EX struct
      aiAlgid ALG_ID ?
      dwDefaultLen DWORD ?
      dwMinLen DWORD ?
      dwMaxLen DWORD ?
      dwProtocols DWORD ?
      dwNameLen DWORD ?
      szName CHAR 20 dup (?)
      dwLongNameLen DWORD ?
      szLongName CHAR 40 dup (?)
    PROV_ENUMALGS_EX ends
    _PROV_ENUMALGS_EX typedef PROV_ENUMALGS_EX
    BLOBHEADER struct
      bType BYTE ?
      bVersion BYTE ?
      reserved WORD ?
      aiKeyAlg ALG_ID ?
    BLOBHEADER ends
    _PUBLICKEYSTRUC typedef BLOBHEADER
    PUBLICKEYSTRUC typedef BLOBHEADER
    RSAPUBKEY struct
      magic DWORD ?
      bitlen DWORD ?
      pubexp DWORD ?
    RSAPUBKEY ends
    _RSAPUBKEY typedef RSAPUBKEY
    DHPUBKEY struct
      magic DWORD ?
      bitlen DWORD ?
    DHPUBKEY ends
    _PUBKEY typedef DHPUBKEY
    DSSPUBKEY typedef DHPUBKEY
    KEAPUBKEY typedef DHPUBKEY
    TEKPUBKEY typedef DHPUBKEY
    DSSSEED struct
      counter DWORD ?
      seed BYTE 20 dup (?)
    DSSSEED ends
    _DSSSEED typedef DSSSEED
    DHPUBKEY_VER3 struct
      magic DWORD ?
      bitlenP DWORD ?
      bitlenQ DWORD ?
      bitlenJ DWORD ?
      DSSSeed DSSSEED <>
    DHPUBKEY_VER3 ends
    _PUBKEYVER3 typedef DHPUBKEY_VER3
    DSSPUBKEY_VER3 typedef DHPUBKEY_VER3
    DHPRIVKEY_VER3 struct
      magic DWORD ?
      bitlenP DWORD ?
      bitlenQ DWORD ?
      bitlenJ DWORD ?
      bitlenX DWORD ?
      DSSSeed DSSSEED <>
    DHPRIVKEY_VER3 ends
    _PRIVKEYVER3 typedef DHPRIVKEY_VER3
    DSSPRIVKEY_VER3 typedef DHPRIVKEY_VER3
    KEY_TYPE_SUBTYPE struct
      dwKeySpec DWORD ?
      Type_ GUID <>
      Subtype GUID <>
    KEY_TYPE_SUBTYPE ends
    _KEY_TYPE_SUBTYPE typedef KEY_TYPE_SUBTYPE
    PKEY_TYPE_SUBTYPE typedef ptr KEY_TYPE_SUBTYPE
    CERT_FORTEZZA_DATA_PROP struct
      SerialNumber BYTE 8 dup (?)
      CertIndex SDWORD ?
      CertLabel BYTE 36 dup (?)
    CERT_FORTEZZA_DATA_PROP ends
    _CERT_FORTEZZA_DATA_PROP typedef CERT_FORTEZZA_DATA_PROP
    if (NTDDI_VERSION ge NTDDI_WS03)
      CRYPT_RC4_KEY_STATE struct
        Key BYTE 16 dup (?)
        SBox BYTE 256 dup (?)
        i BYTE ?
        j BYTE ?
      CRYPT_RC4_KEY_STATE ends
      _CRYPT_RC4_KEY_STATE typedef CRYPT_RC4_KEY_STATE
      PCRYPT_RC4_KEY_STATE typedef ptr CRYPT_RC4_KEY_STATE
      CRYPT_DES_KEY_STATE struct
        Key BYTE 8 dup (?)
        IV BYTE 8 dup (?)
        Feedback BYTE 8 dup (?)
      CRYPT_DES_KEY_STATE ends
      _CRYPT_DES_KEY_STATE typedef CRYPT_DES_KEY_STATE
      PCRYPT_DES_KEY_STATE typedef ptr CRYPT_DES_KEY_STATE
      CRYPT_3DES_KEY_STATE struct
        Key BYTE 24 dup (?)
        IV BYTE 8 dup (?)
        Feedback BYTE 8 dup (?)
      CRYPT_3DES_KEY_STATE ends
      _CRYPT_3DES_KEY_STATE typedef CRYPT_3DES_KEY_STATE
      PCRYPT_3DES_KEY_STATE typedef ptr CRYPT_3DES_KEY_STATE
    endif
    if (NTDDI_VERSION ge NTDDI_VISTA)
      CRYPT_AES_128_KEY_STATE struct
        Key BYTE 16 dup (?)
        IV BYTE 16 dup (?)
        EncryptionState BYTE 11 * 16 dup (?)
        DecryptionState BYTE 11 * 16 dup (?)
        Feedback BYTE 16 dup (?)
      CRYPT_AES_128_KEY_STATE ends
      _CRYPT_AES_128_KEY_STATE typedef CRYPT_AES_128_KEY_STATE
      PCRYPT_AES_128_KEY_STATE typedef ptr CRYPT_AES_128_KEY_STATE
      CRYPT_AES_256_KEY_STATE struct
        Key BYTE 32 dup (?)
        IV BYTE 16 dup (?)
        EncryptionState BYTE 15 * 16 dup (?)
        DecryptionState BYTE 15 * 16 dup (?)
        Feedback BYTE 16 dup (?)
      CRYPT_AES_256_KEY_STATE ends
      _CRYPT_AES_256_KEY_STATE typedef CRYPT_AES_256_KEY_STATE
      PCRYPT_AES_256_KEY_STATE typedef ptr CRYPT_AES_256_KEY_STATE
    endif
    ifndef CRYPTO_BLOBS_DEFINED
      CRYPTO_BLOBS_DEFINED equ <>
      CRYPT_INTEGER_BLOB struct
        cbData DWORD ?
        pbData POINTER ?
      CRYPT_INTEGER_BLOB ends
      _CRYPTOAPI_BLOB typedef CRYPT_INTEGER_BLOB
      PCRYPT_INTEGER_BLOB typedef ptr CRYPT_INTEGER_BLOB
      CRYPT_UINT_BLOB typedef CRYPT_INTEGER_BLOB
      PCRYPT_UINT_BLOB typedef ptr CRYPT_INTEGER_BLOB
      CRYPT_OBJID_BLOB typedef CRYPT_INTEGER_BLOB
      PCRYPT_OBJID_BLOB typedef ptr CRYPT_INTEGER_BLOB
      CERT_NAME_BLOB typedef CRYPT_INTEGER_BLOB
      PCERT_NAME_BLOB typedef ptr CRYPT_INTEGER_BLOB
      CERT_RDN_VALUE_BLOB typedef CRYPT_INTEGER_BLOB
      PCERT_RDN_VALUE_BLOB typedef ptr CRYPT_INTEGER_BLOB
      CERT_BLOB typedef CRYPT_INTEGER_BLOB
      PCERT_BLOB typedef ptr CRYPT_INTEGER_BLOB
      CRL_BLOB typedef CRYPT_INTEGER_BLOB
      PCRL_BLOB typedef ptr CRYPT_INTEGER_BLOB
      DATA_BLOB typedef CRYPT_INTEGER_BLOB
      PDATA_BLOB typedef ptr CRYPT_INTEGER_BLOB
      CRYPT_DATA_BLOB typedef CRYPT_INTEGER_BLOB
      PCRYPT_DATA_BLOB typedef ptr CRYPT_INTEGER_BLOB
      CRYPT_HASH_BLOB typedef CRYPT_INTEGER_BLOB
      PCRYPT_HASH_BLOB typedef ptr CRYPT_INTEGER_BLOB
      CRYPT_DIGEST_BLOB typedef CRYPT_INTEGER_BLOB
      PCRYPT_DIGEST_BLOB typedef ptr CRYPT_INTEGER_BLOB
      CRYPT_DER_BLOB typedef CRYPT_INTEGER_BLOB
      PCRYPT_DER_BLOB typedef ptr CRYPT_INTEGER_BLOB
      CRYPT_ATTR_BLOB typedef CRYPT_INTEGER_BLOB
      PCRYPT_ATTR_BLOB typedef ptr CRYPT_INTEGER_BLOB
    endif
    CMS_DH_KEY_INFO struct
      dwVersion DWORD ?
      Algid ALG_ID ?
      pszContentEncObjId LPSTR ?
      PubInfo CRYPT_DATA_BLOB <>
      pReserved POINTER ?
    CMS_DH_KEY_INFO ends
    _CMS_DH_KEY_INFO typedef CMS_DH_KEY_INFO
    PCMS_DH_KEY_INFO typedef ptr CMS_DH_KEY_INFO
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_PHONE_RESTRICTED or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, CryptAcquireContextA, WIN_STD_CALL_CONV,, <:ptr HCRYPTPROV, :LPCSTR, :LPCSTR, :DWORD, :DWORD>, 20
    @DefProto DllImport, CryptAcquireContextW, WIN_STD_CALL_CONV,, <:ptr HCRYPTPROV, :LPCWSTR, :LPCWSTR, :DWORD, :DWORD>, 20
    ifdef UNICODE
      CryptAcquireContext equ <CryptAcquireContextW>
    else
      CryptAcquireContext equ <CryptAcquireContextA>
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, CryptReleaseContext, WIN_STD_CALL_CONV,, <:HCRYPTPROV, :DWORD>, 8
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_PHONE_RESTRICTED or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, CryptGenKey, WIN_STD_CALL_CONV,, <:HCRYPTPROV, :ALG_ID, :DWORD, :ptr HCRYPTKEY>, 16
    @DefProto DllImport, CryptDeriveKey, WIN_STD_CALL_CONV,, <:HCRYPTPROV, :ALG_ID, :HCRYPTHASH, :DWORD, :ptr HCRYPTKEY>, 20
    @DefProto DllImport, CryptDestroyKey, WIN_STD_CALL_CONV,, <:HCRYPTKEY>, 4
    @DefProto DllImport, CryptSetKeyParam, WIN_STD_CALL_CONV,, <:HCRYPTKEY, :DWORD, :ptr BYTE, :DWORD>, 16
    @DefProto DllImport, CryptGetKeyParam, WIN_STD_CALL_CONV,, <:HCRYPTKEY, :DWORD, :ptr BYTE, :ptr DWORD, :DWORD>, 20
    @DefProto DllImport, CryptSetHashParam, WIN_STD_CALL_CONV,, <:HCRYPTHASH, :DWORD, :ptr BYTE, :DWORD>, 16
    @DefProto DllImport, CryptGetHashParam, WIN_STD_CALL_CONV,, <:HCRYPTHASH, :DWORD, :ptr BYTE, :ptr DWORD, :DWORD>, 20
    @DefProto DllImport, CryptSetProvParam, WIN_STD_CALL_CONV,, <:HCRYPTPROV, :DWORD, :ptr BYTE, :DWORD>, 16
    @DefProto DllImport, CryptGetProvParam, WIN_STD_CALL_CONV,, <:HCRYPTPROV, :DWORD, :ptr BYTE, :ptr DWORD, :DWORD>, 20
    @DefProto DllImport, CryptGenRandom, WIN_STD_CALL_CONV,, <:HCRYPTPROV, :DWORD, :ptr BYTE>, 12
    @DefProto DllImport, CryptGetUserKey, WIN_STD_CALL_CONV,, <:HCRYPTPROV, :DWORD, :ptr HCRYPTKEY>, 12
    @DefProto DllImport, CryptExportKey, WIN_STD_CALL_CONV,, <:HCRYPTKEY, :HCRYPTKEY, :DWORD, :DWORD, :ptr BYTE, :ptr DWORD>, 24
    @DefProto DllImport, CryptImportKey, WIN_STD_CALL_CONV,, <:HCRYPTPROV, :ptr BYTE, :DWORD, :HCRYPTKEY, :DWORD, :ptr HCRYPTKEY>, 24
    @DefProto DllImport, CryptEncrypt, WIN_STD_CALL_CONV,, <:HCRYPTKEY, :HCRYPTHASH, :BOOL, :DWORD, :ptr BYTE, :ptr DWORD, :DWORD>, 28
    @DefProto DllImport, CryptDecrypt, WIN_STD_CALL_CONV,, <:HCRYPTKEY, :HCRYPTHASH, :BOOL, :DWORD, :ptr BYTE, :ptr DWORD>, 24
    @DefProto DllImport, CryptCreateHash, WIN_STD_CALL_CONV,, <:HCRYPTPROV, :ALG_ID, :HCRYPTKEY, :DWORD, :ptr HCRYPTHASH>, 20
    @DefProto DllImport, CryptHashData, WIN_STD_CALL_CONV,, <:HCRYPTHASH, :ptr BYTE, :DWORD, :DWORD>, 16
    @DefProto DllImport, CryptHashSessionKey, WIN_STD_CALL_CONV,, <:HCRYPTHASH, :HCRYPTKEY, :DWORD>, 12
    @DefProto DllImport, CryptDestroyHash, WIN_STD_CALL_CONV,, <:HCRYPTHASH>, 4
    @DefProto DllImport, CryptSignHashA, WIN_STD_CALL_CONV,, <:HCRYPTHASH, :DWORD, :LPCSTR, :DWORD, :ptr BYTE, :ptr DWORD>, 24
    @DefProto DllImport, CryptSignHashW, WIN_STD_CALL_CONV,, <:HCRYPTHASH, :DWORD, :LPCWSTR, :DWORD, :ptr BYTE, :ptr DWORD>, 24
    ifdef UNICODE
      CryptSignHash equ <CryptSignHashW>
    else
      CryptSignHash equ <CryptSignHashA>
    endif
    @DefProto DllImport, CryptVerifySignatureA, WIN_STD_CALL_CONV,, <:HCRYPTHASH, :ptr BYTE, :DWORD, :HCRYPTKEY, :LPCSTR, :DWORD>, 24
    @DefProto DllImport, CryptVerifySignatureW, WIN_STD_CALL_CONV,, <:HCRYPTHASH, :ptr BYTE, :DWORD, :HCRYPTKEY, :LPCWSTR, :DWORD>, 24
    ifdef UNICODE
      CryptVerifySignature equ <CryptVerifySignatureW>
    else
      CryptVerifySignature equ <CryptVerifySignatureA>
    endif
    @DefProto DllImport, CryptSetProviderA, WIN_STD_CALL_CONV,, <:LPCSTR, :DWORD>, 8
    @DefProto DllImport, CryptSetProviderW, WIN_STD_CALL_CONV,, <:LPCWSTR, :DWORD>, 8
    ifdef UNICODE
      CryptSetProvider equ <CryptSetProviderW>
    else
      CryptSetProvider equ <CryptSetProviderA>
    endif
    @DefProto DllImport, CryptSetProviderExA, WIN_STD_CALL_CONV,, <:LPCSTR, :DWORD, :ptr DWORD, :DWORD>, 16
    @DefProto DllImport, CryptSetProviderExW, WIN_STD_CALL_CONV,, <:LPCWSTR, :DWORD, :ptr DWORD, :DWORD>, 16
    ifdef UNICODE
      CryptSetProviderEx equ <CryptSetProviderExW>
    else
      CryptSetProviderEx equ <CryptSetProviderExA>
    endif
    @DefProto DllImport, CryptGetDefaultProviderA, WIN_STD_CALL_CONV,, <:DWORD, :ptr DWORD, :DWORD, :LPSTR, :ptr DWORD>, 20
    @DefProto DllImport, CryptGetDefaultProviderW, WIN_STD_CALL_CONV,, <:DWORD, :ptr DWORD, :DWORD, :LPWSTR, :ptr DWORD>, 20
    ifdef UNICODE
      CryptGetDefaultProvider equ <CryptGetDefaultProviderW>
    else
      CryptGetDefaultProvider equ <CryptGetDefaultProviderA>
    endif
    @DefProto DllImport, CryptEnumProviderTypesA, WIN_STD_CALL_CONV,, <:DWORD, :ptr DWORD, :DWORD, :ptr DWORD, :LPSTR, :ptr DWORD>, 24
    @DefProto DllImport, CryptEnumProviderTypesW, WIN_STD_CALL_CONV,, <:DWORD, :ptr DWORD, :DWORD, :ptr DWORD, :LPWSTR, :ptr DWORD>, 24
    ifdef UNICODE
      CryptEnumProviderTypes equ <CryptEnumProviderTypesW>
    else
      CryptEnumProviderTypes equ <CryptEnumProviderTypesA>
    endif
    @DefProto DllImport, CryptEnumProvidersA, WIN_STD_CALL_CONV,, <:DWORD, :ptr DWORD, :DWORD, :ptr DWORD, :LPSTR, :ptr DWORD>, 24
    @DefProto DllImport, CryptEnumProvidersW, WIN_STD_CALL_CONV,, <:DWORD, :ptr DWORD, :DWORD, :ptr DWORD, :LPWSTR, :ptr DWORD>, 24
    ifdef UNICODE
      CryptEnumProviders equ <CryptEnumProvidersW>
    else
      CryptEnumProviders equ <CryptEnumProvidersA>
    endif
    @DefProto DllImport, CryptContextAddRef, WIN_STD_CALL_CONV,, <:HCRYPTPROV, :ptr DWORD, :DWORD>, 12
    @DefProto DllImport, CryptDuplicateKey, WIN_STD_CALL_CONV,, <:HCRYPTKEY, :ptr DWORD, :DWORD, :ptr HCRYPTKEY>, 16
    @DefProto DllImport, CryptDuplicateHash, WIN_STD_CALL_CONV,, <:HCRYPTHASH, :ptr DWORD, :DWORD, :ptr HCRYPTHASH>, 16
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_PHONE_RESTRICTED or WINAPI_PARTITION_GAMES)
    if (NTDDI_VERSION ge NTDDI_WS03)
      GetEncSChannel proto c :ptr ptr BYTE, :ptr DWORD
    endif
  endif
  if  not Defined(_DDK_DRIVER_)
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_PHONE_RESTRICTED or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      include bcrypt.inc
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      include ncrypt.inc
      HCRYPTPROV_OR_NCRYPT_KEY_HANDLE typedef ULONG_PTR
      HCRYPTPROV_LEGACY typedef ULONG_PTR
      CRYPT_BIT_BLOB struct
        cbData DWORD ?
        pbData POINTER ?
        cUnusedBits DWORD ?
      CRYPT_BIT_BLOB ends
      _CRYPT_BIT_BLOB typedef CRYPT_BIT_BLOB
      PCRYPT_BIT_BLOB typedef ptr CRYPT_BIT_BLOB
      CRYPT_ALGORITHM_IDENTIFIER struct
        pszObjId LPSTR ?
        Parameters CRYPT_OBJID_BLOB <>
      CRYPT_ALGORITHM_IDENTIFIER ends
      _CRYPT_ALGORITHM_IDENTIFIER typedef CRYPT_ALGORITHM_IDENTIFIER
      PCRYPT_ALGORITHM_IDENTIFIER typedef ptr CRYPT_ALGORITHM_IDENTIFIER
      szOID_RSA equ <"1.2.840.113549">
      szOID_PKCS equ <"1.2.840.113549.1">
      szOID_RSA_HASH equ <"1.2.840.113549.2">
      szOID_RSA_ENCRYPT equ <"1.2.840.113549.3">
      szOID_PKCS_1 equ <"1.2.840.113549.1.1">
      szOID_PKCS_2 equ <"1.2.840.113549.1.2">
      szOID_PKCS_3 equ <"1.2.840.113549.1.3">
      szOID_PKCS_4 equ <"1.2.840.113549.1.4">
      szOID_PKCS_5 equ <"1.2.840.113549.1.5">
      szOID_PKCS_6 equ <"1.2.840.113549.1.6">
      szOID_PKCS_7 equ <"1.2.840.113549.1.7">
      szOID_PKCS_8 equ <"1.2.840.113549.1.8">
      szOID_PKCS_9 equ <"1.2.840.113549.1.9">
      szOID_PKCS_10 equ <"1.2.840.113549.1.10">
      szOID_PKCS_12 equ <"1.2.840.113549.1.12">
      szOID_RSA_RSA equ <"1.2.840.113549.1.1.1">
      szOID_RSA_MD2RSA equ <"1.2.840.113549.1.1.2">
      szOID_RSA_MD4RSA equ <"1.2.840.113549.1.1.3">
      szOID_RSA_MD5RSA equ <"1.2.840.113549.1.1.4">
      szOID_RSA_SHA1RSA equ <"1.2.840.113549.1.1.5">
      szOID_RSA_SETOAEP_RSA equ <"1.2.840.113549.1.1.6">
      szOID_RSAES_OAEP equ <"1.2.840.113549.1.1.7">
      szOID_RSA_MGF1 equ <"1.2.840.113549.1.1.8">
      szOID_RSA_PSPECIFIED equ <"1.2.840.113549.1.1.9">
      szOID_RSA_SSA_PSS equ <"1.2.840.113549.1.1.10">
      szOID_RSA_SHA256RSA equ <"1.2.840.113549.1.1.11">
      szOID_RSA_SHA384RSA equ <"1.2.840.113549.1.1.12">
      szOID_RSA_SHA512RSA equ <"1.2.840.113549.1.1.13">
      szOID_RSA_DH equ <"1.2.840.113549.1.3.1">
      szOID_RSA_data equ <"1.2.840.113549.1.7.1">
      szOID_RSA_signedData equ <"1.2.840.113549.1.7.2">
      szOID_RSA_envelopedData equ <"1.2.840.113549.1.7.3">
      szOID_RSA_signEnvData equ <"1.2.840.113549.1.7.4">
      szOID_RSA_digestedData equ <"1.2.840.113549.1.7.5">
      szOID_RSA_hashedData equ <"1.2.840.113549.1.7.5">
      szOID_RSA_encryptedData equ <"1.2.840.113549.1.7.6">
      szOID_RSA_emailAddr equ <"1.2.840.113549.1.9.1">
      szOID_RSA_unstructName equ <"1.2.840.113549.1.9.2">
      szOID_RSA_contentType equ <"1.2.840.113549.1.9.3">
      szOID_RSA_messageDigest equ <"1.2.840.113549.1.9.4">
      szOID_RSA_signingTime equ <"1.2.840.113549.1.9.5">
      szOID_RSA_counterSign equ <"1.2.840.113549.1.9.6">
      szOID_RSA_challengePwd equ <"1.2.840.113549.1.9.7">
      szOID_RSA_unstructAddr equ <"1.2.840.113549.1.9.8">
      szOID_RSA_extCertAttrs equ <"1.2.840.113549.1.9.9">
      szOID_RSA_certExtensions equ <"1.2.840.113549.1.9.14">
      szOID_RSA_SMIMECapabilities equ <"1.2.840.113549.1.9.15">
      szOID_RSA_preferSignedData equ <"1.2.840.113549.1.9.15.1">
      szOID_TIMESTAMP_TOKEN equ <"1.2.840.113549.1.9.16.1.4">
      szOID_RFC3161_counterSign equ <"1.3.6.1.4.1.311.3.3.1">
      szOID_RFC3161v21_counterSign equ <"1.3.6.1.4.1.311.3.3.2">
      szOID_RFC3161v21_thumbprints equ <"1.3.6.1.4.1.311.3.3.3">
      szOID_RSA_SMIMEalg equ <"1.2.840.113549.1.9.16.3">
      szOID_RSA_SMIMEalgESDH equ <"1.2.840.113549.1.9.16.3.5">
      szOID_RSA_SMIMEalgCMS3DESwrap equ <"1.2.840.113549.1.9.16.3.6">
      szOID_RSA_SMIMEalgCMSRC2wrap equ <"1.2.840.113549.1.9.16.3.7">
      szOID_RSA_MD2 equ <"1.2.840.113549.2.2">
      szOID_RSA_MD4 equ <"1.2.840.113549.2.4">
      szOID_RSA_MD5 equ <"1.2.840.113549.2.5">
      szOID_RSA_RC2CBC equ <"1.2.840.113549.3.2">
      szOID_RSA_RC4 equ <"1.2.840.113549.3.4">
      szOID_RSA_DES_EDE3_CBC equ <"1.2.840.113549.3.7">
      szOID_RSA_RC5_CBCPad equ <"1.2.840.113549.3.9">
      szOID_ANSI_X942 equ <"1.2.840.10046">
      szOID_ANSI_X942_DH equ <"1.2.840.10046.2.1">
      szOID_X957 equ <"1.2.840.10040">
      szOID_X957_DSA equ <"1.2.840.10040.4.1">
      szOID_X957_SHA1DSA equ <"1.2.840.10040.4.3">
      szOID_ECC_PUBLIC_KEY equ <"1.2.840.10045.2.1">
      szOID_ECC_CURVE_P256 equ <"1.2.840.10045.3.1.7">
      szOID_ECC_CURVE_P384 equ <"1.3.132.0.34">
      szOID_ECC_CURVE_P521 equ <"1.3.132.0.35">
      szOID_ECC_CURVE_BRAINPOOLP160R1 equ <"1.3.36.3.3.2.8.1.1.1">
      szOID_ECC_CURVE_BRAINPOOLP160T1 equ <"1.3.36.3.3.2.8.1.1.2">
      szOID_ECC_CURVE_BRAINPOOLP192R1 equ <"1.3.36.3.3.2.8.1.1.3">
      szOID_ECC_CURVE_BRAINPOOLP192T1 equ <"1.3.36.3.3.2.8.1.1.4">
      szOID_ECC_CURVE_BRAINPOOLP224R1 equ <"1.3.36.3.3.2.8.1.1.5">
      szOID_ECC_CURVE_BRAINPOOLP224T1 equ <"1.3.36.3.3.2.8.1.1.6">
      szOID_ECC_CURVE_BRAINPOOLP256R1 equ <"1.3.36.3.3.2.8.1.1.7">
      szOID_ECC_CURVE_BRAINPOOLP256T1 equ <"1.3.36.3.3.2.8.1.1.8">
      szOID_ECC_CURVE_BRAINPOOLP320R1 equ <"1.3.36.3.3.2.8.1.1.9">
      szOID_ECC_CURVE_BRAINPOOLP320T1 equ <"1.3.36.3.3.2.8.1.1.10">
      szOID_ECC_CURVE_BRAINPOOLP384R1 equ <"1.3.36.3.3.2.8.1.1.11">
      szOID_ECC_CURVE_BRAINPOOLP384T1 equ <"1.3.36.3.3.2.8.1.1.12">
      szOID_ECC_CURVE_BRAINPOOLP512R1 equ <"1.3.36.3.3.2.8.1.1.13">
      szOID_ECC_CURVE_BRAINPOOLP512T1 equ <"1.3.36.3.3.2.8.1.1.14">
      szOID_ECC_CURVE_EC192WAPI equ <"1.2.156.11235.1.1.2.1">
      szOID_CN_ECDSA_SHA256 equ <"1.2.156.11235.1.1.1">
      szOID_ECC_CURVE_NISTP192 equ <"1.2.840.10045.3.1.1">
      szOID_ECC_CURVE_NISTP224 equ <"1.3.132.0.33">
      szOID_ECC_CURVE_NISTP256 equ <szOID_ECC_CURVE_P256>
      szOID_ECC_CURVE_NISTP384 equ <szOID_ECC_CURVE_P384>
      szOID_ECC_CURVE_NISTP521 equ <szOID_ECC_CURVE_P521>
      szOID_ECC_CURVE_SECP160K1 equ <"1.3.132.0.9">
      szOID_ECC_CURVE_SECP160R1 equ <"1.3.132.0.8">
      szOID_ECC_CURVE_SECP160R2 equ <"1.3.132.0.30">
      szOID_ECC_CURVE_SECP192K1 equ <"1.3.132.0.31">
      szOID_ECC_CURVE_SECP192R1 equ <szOID_ECC_CURVE_NISTP192>
      szOID_ECC_CURVE_SECP224K1 equ <"1.3.132.0.32">
      szOID_ECC_CURVE_SECP224R1 equ <szOID_ECC_CURVE_NISTP224>
      szOID_ECC_CURVE_SECP256K1 equ <"1.3.132.0.10">
      szOID_ECC_CURVE_SECP256R1 equ <szOID_ECC_CURVE_P256>
      szOID_ECC_CURVE_SECP384R1 equ <szOID_ECC_CURVE_P384>
      szOID_ECC_CURVE_SECP521R1 equ <szOID_ECC_CURVE_P521>
      szOID_ECC_CURVE_WTLS7 equ <szOID_ECC_CURVE_SECP160R2>
      szOID_ECC_CURVE_WTLS9 equ <"2.23.43.1.4.9">
      szOID_ECC_CURVE_WTLS12 equ <szOID_ECC_CURVE_NISTP224>
      szOID_ECC_CURVE_X962P192V1 equ <"1.2.840.10045.3.1.1">
      szOID_ECC_CURVE_X962P192V2 equ <"1.2.840.10045.3.1.2">
      szOID_ECC_CURVE_X962P192V3 equ <"1.2.840.10045.3.1.3">
      szOID_ECC_CURVE_X962P239V1 equ <"1.2.840.10045.3.1.4">
      szOID_ECC_CURVE_X962P239V2 equ <"1.2.840.10045.3.1.5">
      szOID_ECC_CURVE_X962P239V3 equ <"1.2.840.10045.3.1.6">
      szOID_ECC_CURVE_X962P256V1 equ <szOID_ECC_CURVE_P256>
      szOID_ECDSA_SHA1 equ <"1.2.840.10045.4.1">
      szOID_ECDSA_SPECIFIED equ <"1.2.840.10045.4.3">
      szOID_ECDSA_SHA256 equ <"1.2.840.10045.4.3.2">
      szOID_ECDSA_SHA384 equ <"1.2.840.10045.4.3.3">
      szOID_ECDSA_SHA512 equ <"1.2.840.10045.4.3.4">
      szOID_NIST_AES128_CBC equ <"2.16.840.1.101.3.4.1.2">
      szOID_NIST_AES192_CBC equ <"2.16.840.1.101.3.4.1.22">
      szOID_NIST_AES256_CBC equ <"2.16.840.1.101.3.4.1.42">
      szOID_NIST_AES128_WRAP equ <"2.16.840.1.101.3.4.1.5">
      szOID_NIST_AES192_WRAP equ <"2.16.840.1.101.3.4.1.25">
      szOID_NIST_AES256_WRAP equ <"2.16.840.1.101.3.4.1.45">
      szOID_DH_SINGLE_PASS_STDDH_SHA1_KDF equ <"1.3.133.16.840.63.0.2">
      szOID_DH_SINGLE_PASS_STDDH_SHA256_KDF equ <"1.3.132.1.11.1">
      szOID_DH_SINGLE_PASS_STDDH_SHA384_KDF equ <"1.3.132.1.11.2">
      szOID_DS equ <"2.5">
      szOID_DSALG equ <"2.5.8">
      szOID_DSALG_CRPT equ <"2.5.8.1">
      szOID_DSALG_HASH equ <"2.5.8.2">
      szOID_DSALG_SIGN equ <"2.5.8.3">
      szOID_DSALG_RSA equ <"2.5.8.1.1">
      szOID_OIW equ <"1.3.14">
      szOID_OIWSEC equ <"1.3.14.3.2">
      szOID_OIWSEC_md4RSA equ <"1.3.14.3.2.2">
      szOID_OIWSEC_md5RSA equ <"1.3.14.3.2.3">
      szOID_OIWSEC_md4RSA2 equ <"1.3.14.3.2.4">
      szOID_OIWSEC_desECB equ <"1.3.14.3.2.6">
      szOID_OIWSEC_desCBC equ <"1.3.14.3.2.7">
      szOID_OIWSEC_desOFB equ <"1.3.14.3.2.8">
      szOID_OIWSEC_desCFB equ <"1.3.14.3.2.9">
      szOID_OIWSEC_desMAC equ <"1.3.14.3.2.10">
      szOID_OIWSEC_rsaSign equ <"1.3.14.3.2.11">
      szOID_OIWSEC_dsa equ <"1.3.14.3.2.12">
      szOID_OIWSEC_shaDSA equ <"1.3.14.3.2.13">
      szOID_OIWSEC_mdc2RSA equ <"1.3.14.3.2.14">
      szOID_OIWSEC_shaRSA equ <"1.3.14.3.2.15">
      szOID_OIWSEC_dhCommMod equ <"1.3.14.3.2.16">
      szOID_OIWSEC_desEDE equ <"1.3.14.3.2.17">
      szOID_OIWSEC_sha equ <"1.3.14.3.2.18">
      szOID_OIWSEC_mdc2 equ <"1.3.14.3.2.19">
      szOID_OIWSEC_dsaComm equ <"1.3.14.3.2.20">
      szOID_OIWSEC_dsaCommSHA equ <"1.3.14.3.2.21">
      szOID_OIWSEC_rsaXchg equ <"1.3.14.3.2.22">
      szOID_OIWSEC_keyHashSeal equ <"1.3.14.3.2.23">
      szOID_OIWSEC_md2RSASign equ <"1.3.14.3.2.24">
      szOID_OIWSEC_md5RSASign equ <"1.3.14.3.2.25">
      szOID_OIWSEC_sha1 equ <"1.3.14.3.2.26">
      szOID_OIWSEC_dsaSHA1 equ <"1.3.14.3.2.27">
      szOID_OIWSEC_dsaCommSHA1 equ <"1.3.14.3.2.28">
      szOID_OIWSEC_sha1RSASign equ <"1.3.14.3.2.29">
      szOID_OIWDIR equ <"1.3.14.7.2">
      szOID_OIWDIR_CRPT equ <"1.3.14.7.2.1">
      szOID_OIWDIR_HASH equ <"1.3.14.7.2.2">
      szOID_OIWDIR_SIGN equ <"1.3.14.7.2.3">
      szOID_OIWDIR_md2 equ <"1.3.14.7.2.2.1">
      szOID_OIWDIR_md2RSA equ <"1.3.14.7.2.3.1">
      szOID_INFOSEC equ <"2.16.840.1.101.2.1">
      szOID_INFOSEC_sdnsSignature equ <"2.16.840.1.101.2.1.1.1">
      szOID_INFOSEC_mosaicSignature equ <"2.16.840.1.101.2.1.1.2">
      szOID_INFOSEC_sdnsConfidentiality equ <"2.16.840.1.101.2.1.1.3">
      szOID_INFOSEC_mosaicConfidentiality equ <"2.16.840.1.101.2.1.1.4">
      szOID_INFOSEC_sdnsIntegrity equ <"2.16.840.1.101.2.1.1.5">
      szOID_INFOSEC_mosaicIntegrity equ <"2.16.840.1.101.2.1.1.6">
      szOID_INFOSEC_sdnsTokenProtection equ <"2.16.840.1.101.2.1.1.7">
      szOID_INFOSEC_mosaicTokenProtection equ <"2.16.840.1.101.2.1.1.8">
      szOID_INFOSEC_sdnsKeyManagement equ <"2.16.840.1.101.2.1.1.9">
      szOID_INFOSEC_mosaicKeyManagement equ <"2.16.840.1.101.2.1.1.10">
      szOID_INFOSEC_sdnsKMandSig equ <"2.16.840.1.101.2.1.1.11">
      szOID_INFOSEC_mosaicKMandSig equ <"2.16.840.1.101.2.1.1.12">
      szOID_INFOSEC_SuiteASignature equ <"2.16.840.1.101.2.1.1.13">
      szOID_INFOSEC_SuiteAConfidentiality equ <"2.16.840.1.101.2.1.1.14">
      szOID_INFOSEC_SuiteAIntegrity equ <"2.16.840.1.101.2.1.1.15">
      szOID_INFOSEC_SuiteATokenProtection equ <"2.16.840.1.101.2.1.1.16">
      szOID_INFOSEC_SuiteAKeyManagement equ <"2.16.840.1.101.2.1.1.17">
      szOID_INFOSEC_SuiteAKMandSig equ <"2.16.840.1.101.2.1.1.18">
      szOID_INFOSEC_mosaicUpdatedSig equ <"2.16.840.1.101.2.1.1.19">
      szOID_INFOSEC_mosaicKMandUpdSig equ <"2.16.840.1.101.2.1.1.20">
      szOID_INFOSEC_mosaicUpdatedInteg equ <"2.16.840.1.101.2.1.1.21">
      szOID_NIST_sha256 equ <"2.16.840.1.101.3.4.2.1">
      szOID_NIST_sha384 equ <"2.16.840.1.101.3.4.2.2">
      szOID_NIST_sha512 equ <"2.16.840.1.101.3.4.2.3">
      CRYPT_OBJID_TABLE struct
        dwAlgId DWORD ?
        pszObjId LPCSTR ?
      CRYPT_OBJID_TABLE ends
      _CRYPT_OBJID_TABLE typedef CRYPT_OBJID_TABLE
      PCRYPT_OBJID_TABLE typedef ptr CRYPT_OBJID_TABLE
      CRYPT_HASH_INFO struct
        HashAlgorithm CRYPT_ALGORITHM_IDENTIFIER <>
        Hash CRYPT_HASH_BLOB <>
      CRYPT_HASH_INFO ends
      _CRYPT_HASH_INFO typedef CRYPT_HASH_INFO
      PCRYPT_HASH_INFO typedef ptr CRYPT_HASH_INFO
      CERT_EXTENSION struct
        pszObjId LPSTR ?
        fCritical BOOL ?
        Value CRYPT_OBJID_BLOB <>
      CERT_EXTENSION ends
      _CERT_EXTENSION typedef CERT_EXTENSION
      PCERT_EXTENSION typedef ptr CERT_EXTENSION
      PCCERT_EXTENSION typedef ptr CERT_EXTENSION
      CRYPT_ATTRIBUTE_TYPE_VALUE struct
        pszObjId LPSTR ?
        Value CRYPT_OBJID_BLOB <>
      CRYPT_ATTRIBUTE_TYPE_VALUE ends
      _CRYPT_ATTRIBUTE_TYPE_VALUE typedef CRYPT_ATTRIBUTE_TYPE_VALUE
      PCRYPT_ATTRIBUTE_TYPE_VALUE typedef ptr CRYPT_ATTRIBUTE_TYPE_VALUE
      CRYPT_ATTRIBUTE struct
        pszObjId LPSTR ?
        cValue DWORD ?
        rgValue PCRYPT_ATTR_BLOB ?
      CRYPT_ATTRIBUTE ends
      _CRYPT_ATTRIBUTE typedef CRYPT_ATTRIBUTE
      PCRYPT_ATTRIBUTE typedef ptr CRYPT_ATTRIBUTE
      CRYPT_ATTRIBUTES struct
        cAttr DWORD ?
        rgAttr PCRYPT_ATTRIBUTE ?
      CRYPT_ATTRIBUTES ends
      _CRYPT_ATTRIBUTES typedef CRYPT_ATTRIBUTES
      PCRYPT_ATTRIBUTES typedef ptr CRYPT_ATTRIBUTES
      CERT_RDN_ATTR struct
        pszObjId LPSTR ?
        dwValueType DWORD ?
        Value CERT_RDN_VALUE_BLOB <>
      CERT_RDN_ATTR ends
      _CERT_RDN_ATTR typedef CERT_RDN_ATTR
      PCERT_RDN_ATTR typedef ptr CERT_RDN_ATTR
      szOID_COMMON_NAME equ <"2.5.4.3">
      szOID_SUR_NAME equ <"2.5.4.4">
      szOID_DEVICE_SERIAL_NUMBER equ <"2.5.4.5">
      szOID_COUNTRY_NAME equ <"2.5.4.6">
      szOID_LOCALITY_NAME equ <"2.5.4.7">
      szOID_STATE_OR_PROVINCE_NAME equ <"2.5.4.8">
      szOID_STREET_ADDRESS equ <"2.5.4.9">
      szOID_ORGANIZATION_NAME equ <"2.5.4.10">
      szOID_ORGANIZATIONAL_UNIT_NAME equ <"2.5.4.11">
      szOID_TITLE equ <"2.5.4.12">
      szOID_DESCRIPTION equ <"2.5.4.13">
      szOID_SEARCH_GUIDE equ <"2.5.4.14">
      szOID_BUSINESS_CATEGORY equ <"2.5.4.15">
      szOID_POSTAL_ADDRESS equ <"2.5.4.16">
      szOID_POSTAL_CODE equ <"2.5.4.17">
      szOID_POST_OFFICE_BOX equ <"2.5.4.18">
      szOID_PHYSICAL_DELIVERY_OFFICE_NAME equ <"2.5.4.19">
      szOID_TELEPHONE_NUMBER equ <"2.5.4.20">
      szOID_TELEX_NUMBER equ <"2.5.4.21">
      szOID_TELETEXT_TERMINAL_IDENTIFIER equ <"2.5.4.22">
      szOID_FACSIMILE_TELEPHONE_NUMBER equ <"2.5.4.23">
      szOID_X21_ADDRESS equ <"2.5.4.24">
      szOID_INTERNATIONAL_ISDN_NUMBER equ <"2.5.4.25">
      szOID_REGISTERED_ADDRESS equ <"2.5.4.26">
      szOID_DESTINATION_INDICATOR equ <"2.5.4.27">
      szOID_PREFERRED_DELIVERY_METHOD equ <"2.5.4.28">
      szOID_PRESENTATION_ADDRESS equ <"2.5.4.29">
      szOID_SUPPORTED_APPLICATION_CONTEXT equ <"2.5.4.30">
      szOID_MEMBER equ <"2.5.4.31">
      szOID_OWNER equ <"2.5.4.32">
      szOID_ROLE_OCCUPANT equ <"2.5.4.33">
      szOID_SEE_ALSO equ <"2.5.4.34">
      szOID_USER_PASSWORD equ <"2.5.4.35">
      szOID_USER_CERTIFICATE equ <"2.5.4.36">
      szOID_CA_CERTIFICATE equ <"2.5.4.37">
      szOID_AUTHORITY_REVOCATION_LIST equ <"2.5.4.38">
      szOID_CERTIFICATE_REVOCATION_LIST equ <"2.5.4.39">
      szOID_CROSS_CERTIFICATE_PAIR equ <"2.5.4.40">
      szOID_GIVEN_NAME equ <"2.5.4.42">
      szOID_INITIALS equ <"2.5.4.43">
      szOID_DN_QUALIFIER equ <"2.5.4.46">
      szOID_DOMAIN_COMPONENT equ <"0.9.2342.19200300.100.1.25">
      szOID_PKCS_12_FRIENDLY_NAME_ATTR equ <"1.2.840.113549.1.9.20">
      szOID_PKCS_12_LOCAL_KEY_ID equ <"1.2.840.113549.1.9.21">
      szOID_PKCS_12_KEY_PROVIDER_NAME_ATTR equ <"1.3.6.1.4.1.311.17.1">
      szOID_LOCAL_MACHINE_KEYSET equ <"1.3.6.1.4.1.311.17.2">
      szOID_PKCS_12_EXTENDED_ATTRIBUTES equ <"1.3.6.1.4.1.311.17.3">
      szOID_PKCS_12_PROTECTED_PASSWORD_SECRET_BAG_TYPE_ID equ <"1.3.6.1.4.1.311.17.4">
      szOID_KEYID_RDN equ <"1.3.6.1.4.1.311.10.7.1">
      szOID_EV_RDN_LOCALE equ <"1.3.6.1.4.1.311.60.2.1.1">
      szOID_EV_RDN_STATE_OR_PROVINCE equ <"1.3.6.1.4.1.311.60.2.1.2">
      szOID_EV_RDN_COUNTRY equ <"1.3.6.1.4.1.311.60.2.1.3">
      CERT_RDN_ANY_TYPE equ 0
      CERT_RDN_ENCODED_BLOB equ 1
      CERT_RDN_OCTET_STRING equ 2
      CERT_RDN_NUMERIC_STRING equ 3
      CERT_RDN_PRINTABLE_STRING equ 4
      CERT_RDN_TELETEX_STRING equ 5
      CERT_RDN_T61_STRING equ 5
      CERT_RDN_VIDEOTEX_STRING equ 6
      CERT_RDN_IA5_STRING equ 7
      CERT_RDN_GRAPHIC_STRING equ 8
      CERT_RDN_VISIBLE_STRING equ 9
      CERT_RDN_ISO646_STRING equ 9
      CERT_RDN_GENERAL_STRING equ 10
      CERT_RDN_UNIVERSAL_STRING equ 11
      CERT_RDN_INT4_STRING equ 11
      CERT_RDN_BMP_STRING equ 12
      CERT_RDN_UNICODE_STRING equ 12
      CERT_RDN_UTF8_STRING equ 13
      CERT_RDN_TYPE_MASK equ 000000FFh
      CERT_RDN_FLAGS_MASK equ 0FF000000h
      CERT_RDN_ENABLE_T61_UNICODE_FLAG equ 80000000h
      CERT_RDN_ENABLE_UTF8_UNICODE_FLAG equ 20000000h
      CERT_RDN_FORCE_UTF8_UNICODE_FLAG equ 10000000h
      CERT_RDN_DISABLE_CHECK_TYPE_FLAG equ 40000000h
      CERT_RDN_DISABLE_IE4_UTF8_FLAG equ 01000000h
      CERT_RDN_ENABLE_PUNYCODE_FLAG equ 02000000h
      IS_CERT_RDN_CHAR_STRING macro X
        exitm <(((X) and CERT_RDN_TYPE_MASK) >= CERT_RDN_NUMERIC_STRING)>
      endm
      CERT_RDN struct
        cRDNAttr DWORD ?
        rgRDNAttr PCERT_RDN_ATTR ?
      CERT_RDN ends
      _CERT_RDN typedef CERT_RDN
      PCERT_RDN typedef ptr CERT_RDN
      CERT_NAME_INFO struct
        cRDN DWORD ?
        rgRDN PCERT_RDN ?
      CERT_NAME_INFO ends
      _CERT_NAME_INFO typedef CERT_NAME_INFO
      PCERT_NAME_INFO typedef ptr CERT_NAME_INFO
      CERT_NAME_VALUE struct
        dwValueType DWORD ?
        Value CERT_RDN_VALUE_BLOB <>
      CERT_NAME_VALUE ends
      _CERT_NAME_VALUE typedef CERT_NAME_VALUE
      PCERT_NAME_VALUE typedef ptr CERT_NAME_VALUE
      CERT_PUBLIC_KEY_INFO struct
        Algorithm CRYPT_ALGORITHM_IDENTIFIER <>
        PublicKey CRYPT_BIT_BLOB <>
      CERT_PUBLIC_KEY_INFO ends
      _CERT_PUBLIC_KEY_INFO typedef CERT_PUBLIC_KEY_INFO
      PCERT_PUBLIC_KEY_INFO typedef ptr CERT_PUBLIC_KEY_INFO
      CERT_RSA_PUBLIC_KEY_OBJID equ <szOID_RSA_RSA>
      CERT_DEFAULT_OID_PUBLIC_KEY_SIGN equ <szOID_RSA_RSA>
      CERT_DEFAULT_OID_PUBLIC_KEY_XCHG equ <szOID_RSA_RSA>
      CRYPT_ECC_PRIVATE_KEY_INFO struct
        dwVersion DWORD ?
        PrivateKey CRYPT_DER_BLOB <>
        szCurveOid LPSTR ?
        PublicKey CRYPT_BIT_BLOB <>
      CRYPT_ECC_PRIVATE_KEY_INFO ends
      _CRYPT_ECC_PRIVATE_KEY_INFO typedef CRYPT_ECC_PRIVATE_KEY_INFO
      PCRYPT_ECC_PRIVATE_KEY_INFO typedef ptr CRYPT_ECC_PRIVATE_KEY_INFO
      CRYPT_ECC_PRIVATE_KEY_INFO_v1 equ 1
      CRYPT_PRIVATE_KEY_INFO struct
        Version DWORD ?
        Algorithm CRYPT_ALGORITHM_IDENTIFIER <>
        PrivateKey CRYPT_DER_BLOB <>
        pAttributes PCRYPT_ATTRIBUTES ?
      CRYPT_PRIVATE_KEY_INFO ends
      _CRYPT_PRIVATE_KEY_INFO typedef CRYPT_PRIVATE_KEY_INFO
      PCRYPT_PRIVATE_KEY_INFO typedef ptr CRYPT_PRIVATE_KEY_INFO
      CRYPT_ENCRYPTED_PRIVATE_KEY_INFO struct
        EncryptionAlgorithm CRYPT_ALGORITHM_IDENTIFIER <>
        EncryptedPrivateKey CRYPT_DATA_BLOB <>
      CRYPT_ENCRYPTED_PRIVATE_KEY_INFO ends
      _CRYPT_ENCRYPTED_PRIVATE_KEY_INFO typedef CRYPT_ENCRYPTED_PRIVATE_KEY_INFO
      PCRYPT_ENCRYPTED_PRIVATE_KEY_INFO typedef ptr CRYPT_ENCRYPTED_PRIVATE_KEY_INFO
      TYPE_PCRYPT_DECRYPT_PRIVATE_KEY_FUNC typedef proto WIN_STD_CALL_CONV :CRYPT_ALGORITHM_IDENTIFIER, :CRYPT_DATA_BLOB, :ptr BYTE, :ptr DWORD, :LPVOID
      PCRYPT_DECRYPT_PRIVATE_KEY_FUNC typedef ptr TYPE_PCRYPT_DECRYPT_PRIVATE_KEY_FUNC

      TYPE_PCRYPT_ENCRYPT_PRIVATE_KEY_FUNC typedef proto WIN_STD_CALL_CONV :ptr CRYPT_ALGORITHM_IDENTIFIER, :ptr CRYPT_DATA_BLOB, :ptr BYTE, :ptr DWORD, :LPVOID
      PCRYPT_ENCRYPT_PRIVATE_KEY_FUNC typedef ptr TYPE_PCRYPT_ENCRYPT_PRIVATE_KEY_FUNC

      TYPE_PCRYPT_RESOLVE_HCRYPTPROV_FUNC typedef proto WIN_STD_CALL_CONV :ptr CRYPT_PRIVATE_KEY_INFO, :ptr HCRYPTPROV, :LPVOID
      PCRYPT_RESOLVE_HCRYPTPROV_FUNC typedef ptr TYPE_PCRYPT_RESOLVE_HCRYPTPROV_FUNC

      CRYPT_PKCS8_IMPORT_PARAMS struct
        PrivateKey CRYPT_DIGEST_BLOB <>
        pResolvehCryptProvFunc PCRYPT_RESOLVE_HCRYPTPROV_FUNC ?
        pVoidResolveFunc LPVOID ?
        pDecryptPrivateKeyFunc PCRYPT_DECRYPT_PRIVATE_KEY_FUNC ?
        pVoidDecryptFunc LPVOID ?
      CRYPT_PKCS8_IMPORT_PARAMS ends
      _CRYPT_PKCS8_IMPORT_PARAMS typedef CRYPT_PKCS8_IMPORT_PARAMS
      PCRYPT_PKCS8_IMPORT_PARAMS typedef ptr CRYPT_PKCS8_IMPORT_PARAMS
      CRYPT_PRIVATE_KEY_BLOB_AND_PARAMS typedef CRYPT_PKCS8_IMPORT_PARAMS
      PCRYPT_PRIVATE_KEY_BLOB_AND_PARAMS typedef ptr CRYPT_PKCS8_IMPORT_PARAMS
      CRYPT_PKCS8_EXPORT_PARAMS struct
        hCryptProv HCRYPTPROV ?
        dwKeySpec DWORD ?
        pszPrivateKeyObjId LPSTR ?
        pEncryptPrivateKeyFunc PCRYPT_ENCRYPT_PRIVATE_KEY_FUNC ?
        pVoidEncryptFunc LPVOID ?
      CRYPT_PKCS8_EXPORT_PARAMS ends
      _CRYPT_PKCS8_EXPORT_PARAMS typedef CRYPT_PKCS8_EXPORT_PARAMS
      PCRYPT_PKCS8_EXPORT_PARAMS typedef ptr CRYPT_PKCS8_EXPORT_PARAMS
      CERT_INFO struct
        dwVersion DWORD ?
        SerialNumber CRYPT_INTEGER_BLOB <>
        SignatureAlgorithm CRYPT_ALGORITHM_IDENTIFIER <>
        Issuer CERT_NAME_BLOB <>
        NotBefore FILETIME <>
        NotAfter FILETIME <>
        Subject CERT_NAME_BLOB <>
        SubjectPublicKeyInfo CERT_PUBLIC_KEY_INFO <>
        IssuerUniqueId CRYPT_BIT_BLOB <>
        SubjectUniqueId CRYPT_BIT_BLOB <>
        cExtension DWORD ?
        rgExtension PCERT_EXTENSION ?
      CERT_INFO ends
      _CERT_INFO typedef CERT_INFO
      PCERT_INFO typedef ptr CERT_INFO
      CERT_V1 equ 0
      CERT_V2 equ 1
      CERT_V3 equ 2
      CERT_INFO_VERSION_FLAG equ 1
      CERT_INFO_SERIAL_NUMBER_FLAG equ 2
      CERT_INFO_SIGNATURE_ALGORITHM_FLAG equ 3
      CERT_INFO_ISSUER_FLAG equ 4
      CERT_INFO_NOT_BEFORE_FLAG equ 5
      CERT_INFO_NOT_AFTER_FLAG equ 6
      CERT_INFO_SUBJECT_FLAG equ 7
      CERT_INFO_SUBJECT_PUBLIC_KEY_INFO_FLAG equ 8
      CERT_INFO_ISSUER_UNIQUE_ID_FLAG equ 9
      CERT_INFO_SUBJECT_UNIQUE_ID_FLAG equ 10
      CERT_INFO_EXTENSION_FLAG equ 11
      CRL_ENTRY struct
        SerialNumber CRYPT_INTEGER_BLOB <>
        RevocationDate FILETIME <>
        cExtension DWORD ?
        rgExtension PCERT_EXTENSION ?
      CRL_ENTRY ends
      _CRL_ENTRY typedef CRL_ENTRY
      PCRL_ENTRY typedef ptr CRL_ENTRY
      CRL_INFO struct
        dwVersion DWORD ?
        SignatureAlgorithm CRYPT_ALGORITHM_IDENTIFIER <>
        Issuer CERT_NAME_BLOB <>
        ThisUpdate FILETIME <>
        NextUpdate FILETIME <>
        cCRLEntry DWORD ?
        rgCRLEntry PCRL_ENTRY ?
        cExtension DWORD ?
        rgExtension PCERT_EXTENSION ?
      CRL_INFO ends
      _CRL_INFO typedef CRL_INFO
      PCRL_INFO typedef ptr CRL_INFO
      CRL_V1 equ 0
      CRL_V2 equ 1
      CERT_BUNDLE_CERTIFICATE equ 0
      CERT_BUNDLE_CRL equ 1
      CERT_OR_CRL_BLOB struct
        dwChoice DWORD ?
        cbEncoded DWORD ?
        pbEncoded POINTER ?
      CERT_OR_CRL_BLOB ends
      _CERT_OR_CRL_BLOB typedef CERT_OR_CRL_BLOB
      PCERT_OR_CRL_BLOB typedef ptr CERT_OR_CRL_BLOB
      CERT_OR_CRL_BUNDLE struct
        cItem DWORD ?
        rgItem PCERT_OR_CRL_BLOB ?
      CERT_OR_CRL_BUNDLE ends
      _CERT_OR_CRL_BUNDLE typedef CERT_OR_CRL_BUNDLE
      PCERT_OR_CRL_BUNDLE typedef ptr CERT_OR_CRL_BUNDLE
      CERT_REQUEST_INFO struct
        dwVersion DWORD ?
        Subject CERT_NAME_BLOB <>
        SubjectPublicKeyInfo CERT_PUBLIC_KEY_INFO <>
        cAttribute DWORD ?
        rgAttribute PCRYPT_ATTRIBUTE ?
      CERT_REQUEST_INFO ends
      _CERT_REQUEST_INFO typedef CERT_REQUEST_INFO
      PCERT_REQUEST_INFO typedef ptr CERT_REQUEST_INFO
      CERT_REQUEST_V1 equ 0
      CERT_KEYGEN_REQUEST_INFO struct
        dwVersion DWORD ?
        SubjectPublicKeyInfo CERT_PUBLIC_KEY_INFO <>
        pwszChallengeString LPWSTR ?
      CERT_KEYGEN_REQUEST_INFO ends
      _CERT_KEYGEN_REQUEST_INFO typedef CERT_KEYGEN_REQUEST_INFO
      PCERT_KEYGEN_REQUEST_INFO typedef ptr CERT_KEYGEN_REQUEST_INFO
      CERT_KEYGEN_REQUEST_V1 equ 0
      CERT_SIGNED_CONTENT_INFO struct
        ToBeSigned CRYPT_DER_BLOB <>
        SignatureAlgorithm CRYPT_ALGORITHM_IDENTIFIER <>
        Signature CRYPT_BIT_BLOB <>
      CERT_SIGNED_CONTENT_INFO ends
      _CERT_SIGNED_CONTENT_INFO typedef CERT_SIGNED_CONTENT_INFO
      PCERT_SIGNED_CONTENT_INFO typedef ptr CERT_SIGNED_CONTENT_INFO
      CTL_USAGE struct
        cUsageIdentifier DWORD ?
        rgpszUsageIdentifier POINTER ?
      CTL_USAGE ends
      _CTL_USAGE typedef CTL_USAGE
      PCTL_USAGE typedef ptr CTL_USAGE
      CERT_ENHKEY_USAGE typedef CTL_USAGE
      PCERT_ENHKEY_USAGE typedef ptr CTL_USAGE
      PCCTL_USAGE typedef ptr CTL_USAGE
      PCCERT_ENHKEY_USAGE typedef ptr CERT_ENHKEY_USAGE
      CTL_ENTRY struct
        SubjectIdentifier CRYPT_DATA_BLOB <>
        cAttribute DWORD ?
        rgAttribute PCRYPT_ATTRIBUTE ?
      CTL_ENTRY ends
      _CTL_ENTRY typedef CTL_ENTRY
      PCTL_ENTRY typedef ptr CTL_ENTRY
      CTL_INFO struct
        dwVersion DWORD ?
        SubjectUsage CTL_USAGE <>
        ListIdentifier CRYPT_DATA_BLOB <>
        SequenceNumber CRYPT_INTEGER_BLOB <>
        ThisUpdate FILETIME <>
        NextUpdate FILETIME <>
        SubjectAlgorithm CRYPT_ALGORITHM_IDENTIFIER <>
        cCTLEntry DWORD ?
        rgCTLEntry PCTL_ENTRY ?
        cExtension DWORD ?
        rgExtension PCERT_EXTENSION ?
      CTL_INFO ends
      _CTL_INFO typedef CTL_INFO
      PCTL_INFO typedef ptr CTL_INFO
      CTL_V1 equ 0
      CRYPT_TIME_STAMP_REQUEST_INFO struct
        pszTimeStampAlgorithm LPSTR ?
        pszContentType LPSTR ?
        Content CRYPT_OBJID_BLOB <>
        cAttribute DWORD ?
        rgAttribute PCRYPT_ATTRIBUTE ?
      CRYPT_TIME_STAMP_REQUEST_INFO ends
      _CRYPT_TIME_STAMP_REQUEST_INFO typedef CRYPT_TIME_STAMP_REQUEST_INFO
      PCRYPT_TIME_STAMP_REQUEST_INFO typedef ptr CRYPT_TIME_STAMP_REQUEST_INFO
      CRYPT_ENROLLMENT_NAME_VALUE_PAIR struct
        pwszName LPWSTR ?
        pwszValue LPWSTR ?
      CRYPT_ENROLLMENT_NAME_VALUE_PAIR ends
      _CRYPT_ENROLLMENT_NAME_VALUE_PAIR typedef CRYPT_ENROLLMENT_NAME_VALUE_PAIR
      PCRYPT_ENROLLMENT_NAME_VALUE_PAIR typedef ptr CRYPT_ENROLLMENT_NAME_VALUE_PAIR
      CRYPT_CSP_PROVIDER struct
        dwKeySpec DWORD ?
        pwszProviderName LPWSTR ?
        Signature CRYPT_BIT_BLOB <>
      CRYPT_CSP_PROVIDER ends
      _CRYPT_CSP_PROVIDER typedef CRYPT_CSP_PROVIDER
      PCRYPT_CSP_PROVIDER typedef ptr CRYPT_CSP_PROVIDER
      CERT_ENCODING_TYPE_MASK equ 0000FFFFh
      CMSG_ENCODING_TYPE_MASK equ 0FFFF0000h
      GET_CERT_ENCODING_TYPE macro X
        exitm <(X and CERT_ENCODING_TYPE_MASK)>
      endm
      GET_CMSG_ENCODING_TYPE macro X
        exitm <(X and CMSG_ENCODING_TYPE_MASK)>
      endm
      CRYPT_ASN_ENCODING equ 00000001h
      CRYPT_NDR_ENCODING equ 00000002h
      X509_ASN_ENCODING equ 00000001h
      X509_NDR_ENCODING equ 00000002h
      PKCS_7_ASN_ENCODING equ 00010000h
      PKCS_7_NDR_ENCODING equ 00020000h
      @DefProto DllImport, CryptFormatObject, WIN_STD_CALL_CONV,, <:DWORD, :DWORD, :DWORD, :ptr, :LPCSTR, :ptr BYTE, :DWORD, :ptr, :ptr DWORD>, 36
      CRYPT_FORMAT_STR_MULTI_LINE equ 0001h
      CRYPT_FORMAT_STR_NO_HEX equ 0010h
      CRYPT_FORMAT_SIMPLE equ 0001h
      CRYPT_FORMAT_X509 equ 0002h
      CRYPT_FORMAT_OID equ 0004h
      CRYPT_FORMAT_RDN_SEMICOLON equ 0100h
      CRYPT_FORMAT_RDN_CRLF equ 0200h
      CRYPT_FORMAT_RDN_UNQUOTE equ 0400h
      CRYPT_FORMAT_RDN_REVERSE equ 0800h
      CRYPT_FORMAT_COMMA equ 1000h
      CRYPT_FORMAT_SEMICOLON equ <CRYPT_FORMAT_RDN_SEMICOLON>
      CRYPT_FORMAT_CRLF equ <CRYPT_FORMAT_RDN_CRLF>
      TYPE_PFN_CRYPT_ALLOC typedef proto WIN_STD_CALL_CONV :size_t
      PFN_CRYPT_ALLOC typedef ptr TYPE_PFN_CRYPT_ALLOC

      TYPE_PFN_CRYPT_FREE typedef proto WIN_STD_CALL_CONV :LPVOID
      PFN_CRYPT_FREE typedef ptr TYPE_PFN_CRYPT_FREE

      CRYPT_ENCODE_PARA struct
        cbSize DWORD ?
        pfnAlloc PFN_CRYPT_ALLOC ?
        pfnFree PFN_CRYPT_FREE ?
      CRYPT_ENCODE_PARA ends
      _CRYPT_ENCODE_PARA typedef CRYPT_ENCODE_PARA
      PCRYPT_ENCODE_PARA typedef ptr CRYPT_ENCODE_PARA
      @DefProto DllImport, CryptEncodeObjectEx, WIN_STD_CALL_CONV,, <:DWORD, :LPCSTR, :ptr, :DWORD, :PCRYPT_ENCODE_PARA, :ptr, :ptr DWORD>, 28
      @DefProto DllImport, CryptEncodeObject, WIN_STD_CALL_CONV,, <:DWORD, :LPCSTR, :ptr, :ptr BYTE, :ptr DWORD>, 20
      CRYPT_ENCODE_NO_SIGNATURE_BYTE_REVERSAL_FLAG equ 8h
      CRYPT_ENCODE_ALLOC_FLAG equ 8000h
      CRYPT_UNICODE_NAME_ENCODE_ENABLE_T61_UNICODE_FLAG equ <CERT_RDN_ENABLE_T61_UNICODE_FLAG>
      CRYPT_UNICODE_NAME_ENCODE_ENABLE_UTF8_UNICODE_FLAG equ <CERT_RDN_ENABLE_UTF8_UNICODE_FLAG>
      CRYPT_UNICODE_NAME_ENCODE_FORCE_UTF8_UNICODE_FLAG equ <CERT_RDN_FORCE_UTF8_UNICODE_FLAG>
      CRYPT_UNICODE_NAME_ENCODE_DISABLE_CHECK_TYPE_FLAG equ <CERT_RDN_DISABLE_CHECK_TYPE_FLAG>
      CRYPT_SORTED_CTL_ENCODE_HASHED_SUBJECT_IDENTIFIER_FLAG equ 10000h
      CRYPT_ENCODE_ENABLE_PUNYCODE_FLAG equ 20000h
      CRYPT_ENCODE_ENABLE_UTF8PERCENT_FLAG equ 40000h
      CRYPT_ENCODE_ENABLE_IA5CONVERSION_FLAG equ <(CRYPT_ENCODE_ENABLE_PUNYCODE_FLAG or CRYPT_ENCODE_ENABLE_UTF8PERCENT_FLAG)>
      CRYPT_DECODE_PARA struct
        cbSize DWORD ?
        pfnAlloc PFN_CRYPT_ALLOC ?
        pfnFree PFN_CRYPT_FREE ?
      CRYPT_DECODE_PARA ends
      _CRYPT_DECODE_PARA typedef CRYPT_DECODE_PARA
      PCRYPT_DECODE_PARA typedef ptr CRYPT_DECODE_PARA
      @DefProto DllImport, CryptDecodeObjectEx, WIN_STD_CALL_CONV,, <:DWORD, :LPCSTR, :ptr BYTE, :DWORD, :DWORD, :PCRYPT_DECODE_PARA, :ptr, :ptr DWORD>, 32
      @DefProto DllImport, CryptDecodeObject, WIN_STD_CALL_CONV,, <:DWORD, :LPCSTR, :ptr BYTE, :DWORD, :DWORD, :ptr, :ptr DWORD>, 28
      CRYPT_DECODE_NOCOPY_FLAG equ 1h
      CRYPT_DECODE_TO_BE_SIGNED_FLAG equ 2h
      CRYPT_DECODE_SHARE_OID_STRING_FLAG equ 4h
      CRYPT_DECODE_NO_SIGNATURE_BYTE_REVERSAL_FLAG equ 8h
      CRYPT_DECODE_ALLOC_FLAG equ 8000h
      CRYPT_UNICODE_NAME_DECODE_DISABLE_IE4_UTF8_FLAG equ <CERT_RDN_DISABLE_IE4_UTF8_FLAG>
      CRYPT_DECODE_ENABLE_PUNYCODE_FLAG equ 02000000h
      CRYPT_DECODE_ENABLE_UTF8PERCENT_FLAG equ 04000000h
      CRYPT_DECODE_ENABLE_IA5CONVERSION_FLAG equ <(CRYPT_DECODE_ENABLE_PUNYCODE_FLAG or CRYPT_DECODE_ENABLE_UTF8PERCENT_FLAG)>
      CRYPT_ENCODE_DECODE_NONE equ 0
      X509_CERT equ (1)
      X509_CERT_TO_BE_SIGNED equ (2)
      X509_CERT_CRL_TO_BE_SIGNED equ (3)
      X509_CERT_REQUEST_TO_BE_SIGNED equ (4)
      X509_EXTENSIONS equ (5)
      X509_NAME_VALUE equ (6)
      X509_NAME equ (7)
      X509_PUBLIC_KEY_INFO equ (8)
      X509_AUTHORITY_KEY_ID equ (9)
      X509_KEY_ATTRIBUTES equ (10)
      X509_KEY_USAGE_RESTRICTION equ (11)
      X509_ALTERNATE_NAME equ (12)
      X509_BASIC_CONSTRAINTS equ (13)
      X509_KEY_USAGE equ (14)
      X509_BASIC_CONSTRAINTS2 equ (15)
      X509_CERT_POLICIES equ (16)
      PKCS_UTC_TIME equ (17)
      PKCS_TIME_REQUEST equ (18)
      RSA_CSP_PUBLICKEYBLOB equ (19)
      X509_UNICODE_NAME equ (20)
      X509_KEYGEN_REQUEST_TO_BE_SIGNED equ (21)
      PKCS_ATTRIBUTE equ (22)
      PKCS_CONTENT_INFO_SEQUENCE_OF_ANY equ (23)
      X509_UNICODE_NAME_VALUE equ (24)
      X509_ANY_STRING equ <X509_NAME_VALUE>
      X509_UNICODE_ANY_STRING equ <X509_UNICODE_NAME_VALUE>
      X509_OCTET_STRING equ (25)
      X509_BITS equ (26)
      X509_INTEGER equ (27)
      X509_MULTI_BYTE_INTEGER equ (28)
      X509_ENUMERATED equ (29)
      X509_CHOICE_OF_TIME equ (30)
      X509_AUTHORITY_KEY_ID2 equ (31)
      X509_AUTHORITY_INFO_ACCESS equ (32)
      X509_SUBJECT_INFO_ACCESS equ <X509_AUTHORITY_INFO_ACCESS>
      X509_CRL_REASON_CODE equ <X509_ENUMERATED>
      PKCS_CONTENT_INFO equ (33)
      X509_SEQUENCE_OF_ANY equ (34)
      X509_CRL_DIST_POINTS equ (35)
      X509_ENHANCED_KEY_USAGE equ (36)
      PKCS_CTL equ (37)
      X509_MULTI_BYTE_UINT equ (38)
      X509_DSS_PUBLICKEY equ <X509_MULTI_BYTE_UINT>
      X509_DSS_PARAMETERS equ (39)
      X509_DSS_SIGNATURE equ (40)
      PKCS_RC2_CBC_PARAMETERS equ (41)
      PKCS_SMIME_CAPABILITIES equ (42)
      X509_QC_STATEMENTS_EXT equ (42)
      PKCS_RSA_PRIVATE_KEY equ (43)
      PKCS_PRIVATE_KEY_INFO equ (44)
      PKCS_ENCRYPTED_PRIVATE_KEY_INFO equ (45)
      X509_PKIX_POLICY_QUALIFIER_USERNOTICE equ (46)
      X509_DH_PUBLICKEY equ <X509_MULTI_BYTE_UINT>
      X509_DH_PARAMETERS equ (47)
      PKCS_ATTRIBUTES equ (48)
      PKCS_SORTED_CTL equ (49)
      X509_ECC_SIGNATURE equ (47)
      X942_DH_PARAMETERS equ (50)
      X509_BITS_WITHOUT_TRAILING_ZEROES equ (51)
      X942_OTHER_INFO equ (52)
      X509_CERT_PAIR equ (53)
      X509_ISSUING_DIST_POINT equ (54)
      X509_NAME_CONSTRAINTS equ (55)
      X509_POLICY_MAPPINGS equ (56)
      X509_POLICY_CONSTRAINTS equ (57)
      X509_CROSS_CERT_DIST_POINTS equ (58)
      CMC_DATA equ (59)
      CMC_RESPONSE equ (60)
      CMC_STATUS equ (61)
      CMC_ADD_EXTENSIONS equ (62)
      CMC_ADD_ATTRIBUTES equ (63)
      X509_CERTIFICATE_TEMPLATE equ (64)
      OCSP_SIGNED_REQUEST equ (65)
      OCSP_REQUEST equ (66)
      OCSP_RESPONSE equ (67)
      OCSP_BASIC_SIGNED_RESPONSE equ (68)
      OCSP_BASIC_RESPONSE equ (69)
      X509_LOGOTYPE_EXT equ (70)
      X509_BIOMETRIC_EXT equ (71)
      CNG_RSA_PUBLIC_KEY_BLOB equ (72)
      X509_OBJECT_IDENTIFIER equ (73)
      X509_ALGORITHM_IDENTIFIER equ (74)
      PKCS_RSA_SSA_PSS_PARAMETERS equ (75)
      PKCS_RSAES_OAEP_PARAMETERS equ (76)
      ECC_CMS_SHARED_INFO equ (77)
      TIMESTAMP_REQUEST equ (78)
      TIMESTAMP_RESPONSE equ (79)
      TIMESTAMP_INFO equ (80)
      X509_CERT_BUNDLE equ (81)
      X509_ECC_PRIVATE_KEY equ (82)
      CNG_RSA_PRIVATE_KEY_BLOB equ (83)
      X509_SUBJECT_DIR_ATTRS equ (84)
      X509_ECC_PARAMETERS equ (85)
      PKCS7_SIGNER_INFO equ (500)
      CMS_SIGNER_INFO equ (501)
      szOID_AUTHORITY_KEY_IDENTIFIER equ <"2.5.29.1">
      szOID_KEY_ATTRIBUTES equ <"2.5.29.2">
      szOID_CERT_POLICIES_95 equ <"2.5.29.3">
      szOID_KEY_USAGE_RESTRICTION equ <"2.5.29.4">
      szOID_SUBJECT_ALT_NAME equ <"2.5.29.7">
      szOID_ISSUER_ALT_NAME equ <"2.5.29.8">
      szOID_BASIC_CONSTRAINTS equ <"2.5.29.10">
      szOID_KEY_USAGE equ <"2.5.29.15">
      szOID_PRIVATEKEY_USAGE_PERIOD equ <"2.5.29.16">
      szOID_BASIC_CONSTRAINTS2 equ <"2.5.29.19">
      szOID_CERT_POLICIES equ <"2.5.29.32">
      szOID_ANY_CERT_POLICY equ <"2.5.29.32.0">
      szOID_INHIBIT_ANY_POLICY equ <"2.5.29.54">
      szOID_AUTHORITY_KEY_IDENTIFIER2 equ <"2.5.29.35">
      szOID_SUBJECT_KEY_IDENTIFIER equ <"2.5.29.14">
      szOID_SUBJECT_ALT_NAME2 equ <"2.5.29.17">
      szOID_ISSUER_ALT_NAME2 equ <"2.5.29.18">
      szOID_CRL_REASON_CODE equ <"2.5.29.21">
      szOID_REASON_CODE_HOLD equ <"2.5.29.23">
      szOID_CRL_DIST_POINTS equ <"2.5.29.31">
      szOID_ENHANCED_KEY_USAGE equ <"2.5.29.37">
      szOID_ANY_ENHANCED_KEY_USAGE equ <"2.5.29.37.0">
      szOID_CRL_NUMBER equ <"2.5.29.20">
      szOID_DELTA_CRL_INDICATOR equ <"2.5.29.27">
      szOID_ISSUING_DIST_POINT equ <"2.5.29.28">
      szOID_FRESHEST_CRL equ <"2.5.29.46">
      szOID_NAME_CONSTRAINTS equ <"2.5.29.30">
      szOID_POLICY_MAPPINGS equ <"2.5.29.33">
      szOID_LEGACY_POLICY_MAPPINGS equ <"2.5.29.5">
      szOID_POLICY_CONSTRAINTS equ <"2.5.29.36">
      szOID_RENEWAL_CERTIFICATE equ <"1.3.6.1.4.1.311.13.1">
      szOID_ENROLLMENT_NAME_VALUE_PAIR equ <"1.3.6.1.4.1.311.13.2.1">
      szOID_ENROLLMENT_CSP_PROVIDER equ <"1.3.6.1.4.1.311.13.2.2">
      szOID_OS_VERSION equ <"1.3.6.1.4.1.311.13.2.3">
      szOID_ENROLLMENT_AGENT equ <"1.3.6.1.4.1.311.20.2.1">
      szOID_PKIX equ <"1.3.6.1.5.5.7">
      szOID_PKIX_PE equ <"1.3.6.1.5.5.7.1">
      szOID_AUTHORITY_INFO_ACCESS equ <"1.3.6.1.5.5.7.1.1">
      szOID_SUBJECT_INFO_ACCESS equ <"1.3.6.1.5.5.7.1.11">
      szOID_BIOMETRIC_EXT equ <"1.3.6.1.5.5.7.1.2">
      szOID_QC_STATEMENTS_EXT equ <"1.3.6.1.5.5.7.1.3">
      szOID_LOGOTYPE_EXT equ <"1.3.6.1.5.5.7.1.12">
      szOID_TLS_FEATURES_EXT equ <"1.3.6.1.5.5.7.1.24">
      szOID_CERT_EXTENSIONS equ <"1.3.6.1.4.1.311.2.1.14">
      szOID_NEXT_UPDATE_LOCATION equ <"1.3.6.1.4.1.311.10.2">
      szOID_REMOVE_CERTIFICATE equ <"1.3.6.1.4.1.311.10.8.1">
      szOID_CROSS_CERT_DIST_POINTS equ <"1.3.6.1.4.1.311.10.9.1">
      szOID_CTL equ <"1.3.6.1.4.1.311.10.1">
      szOID_SORTED_CTL equ <"1.3.6.1.4.1.311.10.1.1">
      ifndef szOID_SERIALIZED
        szOID_SERIALIZED equ <"1.3.6.1.4.1.311.10.3.3.1">
      endif
      ifndef szOID_NT_PRINCIPAL_NAME
        szOID_NT_PRINCIPAL_NAME equ <"1.3.6.1.4.1.311.20.2.3">
      endif
      ifndef szOID_INTERNATIONALIZED_EMAIL_ADDRESS
        szOID_INTERNATIONALIZED_EMAIL_ADDRESS equ <"1.3.6.1.4.1.311.20.2.4">
      endif
      ifndef szOID_PRODUCT_UPDATE
        szOID_PRODUCT_UPDATE equ <"1.3.6.1.4.1.311.31.1">
      endif
      szOID_ANY_APPLICATION_POLICY equ <"1.3.6.1.4.1.311.10.12.1">
      szOID_AUTO_ENROLL_CTL_USAGE equ <"1.3.6.1.4.1.311.20.1">
      szOID_ENROLL_CERTTYPE_EXTENSION equ <"1.3.6.1.4.1.311.20.2">
      szOID_CERT_MANIFOLD equ <"1.3.6.1.4.1.311.20.3">
      ifndef szOID_CERTSRV_CA_VERSION
        szOID_CERTSRV_CA_VERSION equ <"1.3.6.1.4.1.311.21.1">
      endif
      szOID_CERTSRV_PREVIOUS_CERT_HASH equ <"1.3.6.1.4.1.311.21.2">
      szOID_CRL_VIRTUAL_BASE equ <"1.3.6.1.4.1.311.21.3">
      szOID_CRL_NEXT_PUBLISH equ <"1.3.6.1.4.1.311.21.4">
      szOID_KP_CA_EXCHANGE equ <"1.3.6.1.4.1.311.21.5">
      szOID_KP_PRIVACY_CA equ <"1.3.6.1.4.1.311.21.36">
      szOID_KP_KEY_RECOVERY_AGENT equ <"1.3.6.1.4.1.311.21.6">
      szOID_CERTIFICATE_TEMPLATE equ <"1.3.6.1.4.1.311.21.7">
      szOID_ENTERPRISE_OID_ROOT equ <"1.3.6.1.4.1.311.21.8">
      szOID_RDN_DUMMY_SIGNER equ <"1.3.6.1.4.1.311.21.9">
      szOID_APPLICATION_CERT_POLICIES equ <"1.3.6.1.4.1.311.21.10">
      szOID_APPLICATION_POLICY_MAPPINGS equ <"1.3.6.1.4.1.311.21.11">
      szOID_APPLICATION_POLICY_CONSTRAINTS equ <"1.3.6.1.4.1.311.21.12">
      szOID_ARCHIVED_KEY_ATTR equ <"1.3.6.1.4.1.311.21.13">
      szOID_CRL_SELF_CDP equ <"1.3.6.1.4.1.311.21.14">
      szOID_REQUIRE_CERT_CHAIN_POLICY equ <"1.3.6.1.4.1.311.21.15">
      szOID_ARCHIVED_KEY_CERT_HASH equ <"1.3.6.1.4.1.311.21.16">
      szOID_ISSUED_CERT_HASH equ <"1.3.6.1.4.1.311.21.17">
      szOID_DS_EMAIL_REPLICATION equ <"1.3.6.1.4.1.311.21.19">
      szOID_REQUEST_CLIENT_INFO equ <"1.3.6.1.4.1.311.21.20">
      szOID_ENCRYPTED_KEY_HASH equ <"1.3.6.1.4.1.311.21.21">
      szOID_CERTSRV_CROSSCA_VERSION equ <"1.3.6.1.4.1.311.21.22">
      szOID_NTDS_REPLICATION equ <"1.3.6.1.4.1.311.25.1">
      szOID_NTDS_CA_SECURITY_EXT equ <"1.3.6.1.4.1.311.25.2">
      szOID_NTDS_OBJECTSID equ <"1.3.6.1.4.1.311.25.2.1">
      wszURI_NTDS_OBJECTSID_PREFIX equ <L("tag:microsoft.com,2022-09-14:sid:")>
      szOID_SUBJECT_DIR_ATTRS equ <"2.5.29.9">
      szOID_PKIX_KP equ <"1.3.6.1.5.5.7.3">
      szOID_PKIX_KP_SERVER_AUTH equ <"1.3.6.1.5.5.7.3.1">
      szOID_PKIX_KP_CLIENT_AUTH equ <"1.3.6.1.5.5.7.3.2">
      szOID_PKIX_KP_CODE_SIGNING equ <"1.3.6.1.5.5.7.3.3">
      szOID_PKIX_KP_EMAIL_PROTECTION equ <"1.3.6.1.5.5.7.3.4">
      szOID_PKIX_KP_IPSEC_END_SYSTEM equ <"1.3.6.1.5.5.7.3.5">
      szOID_PKIX_KP_IPSEC_TUNNEL equ <"1.3.6.1.5.5.7.3.6">
      szOID_PKIX_KP_IPSEC_USER equ <"1.3.6.1.5.5.7.3.7">
      szOID_PKIX_KP_TIMESTAMP_SIGNING equ <"1.3.6.1.5.5.7.3.8">
      szOID_PKIX_KP_OCSP_SIGNING equ <"1.3.6.1.5.5.7.3.9">
      szOID_PKIX_OCSP_NOCHECK equ <"1.3.6.1.5.5.7.48.1.5">
      szOID_PKIX_OCSP_NONCE equ <"1.3.6.1.5.5.7.48.1.2">
      szOID_IPSEC_KP_IKE_INTERMEDIATE equ <"1.3.6.1.5.5.8.2.2">
      szOID_PKINIT_KP_KDC equ <"1.3.6.1.5.2.3.5">
      szOID_KP_CTL_USAGE_SIGNING equ <"1.3.6.1.4.1.311.10.3.1">
      szOID_KP_TIME_STAMP_SIGNING equ <"1.3.6.1.4.1.311.10.3.2">
      ifndef szOID_SERVER_GATED_CRYPTO
        szOID_SERVER_GATED_CRYPTO equ <"1.3.6.1.4.1.311.10.3.3">
      endif
      ifndef szOID_SGC_NETSCAPE
        szOID_SGC_NETSCAPE equ <"2.16.840.1.113730.4.1">
      endif
      szOID_KP_EFS equ <"1.3.6.1.4.1.311.10.3.4">
      szOID_EFS_RECOVERY equ <"1.3.6.1.4.1.311.10.3.4.1">
      szOID_WHQL_CRYPTO equ <"1.3.6.1.4.1.311.10.3.5">
      szOID_ATTEST_WHQL_CRYPTO equ <"1.3.6.1.4.1.311.10.3.5.1">
      szOID_NT5_CRYPTO equ <"1.3.6.1.4.1.311.10.3.6">
      szOID_OEM_WHQL_CRYPTO equ <"1.3.6.1.4.1.311.10.3.7">
      szOID_EMBEDDED_NT_CRYPTO equ <"1.3.6.1.4.1.311.10.3.8">
      szOID_ROOT_LIST_SIGNER equ <"1.3.6.1.4.1.311.10.3.9">
      szOID_KP_QUALIFIED_SUBORDINATION equ <"1.3.6.1.4.1.311.10.3.10">
      szOID_KP_KEY_RECOVERY equ <"1.3.6.1.4.1.311.10.3.11">
      szOID_KP_DOCUMENT_SIGNING equ <"1.3.6.1.4.1.311.10.3.12">
      szOID_KP_LIFETIME_SIGNING equ <"1.3.6.1.4.1.311.10.3.13">
      szOID_KP_MOBILE_DEVICE_SOFTWARE equ <"1.3.6.1.4.1.311.10.3.14">
      szOID_KP_SMART_DISPLAY equ <"1.3.6.1.4.1.311.10.3.15">
      szOID_KP_CSP_SIGNATURE equ <"1.3.6.1.4.1.311.10.3.16">
      szOID_KP_FLIGHT_SIGNING equ <"1.3.6.1.4.1.311.10.3.27">
      szOID_PLATFORM_MANIFEST_BINARY_ID equ <"1.3.6.1.4.1.311.10.3.28">
      ifndef szOID_DRM
        szOID_DRM equ <"1.3.6.1.4.1.311.10.5.1">
      endif
      ifndef szOID_DRM_INDIVIDUALIZATION
        szOID_DRM_INDIVIDUALIZATION equ <"1.3.6.1.4.1.311.10.5.2">
      endif
      ifndef szOID_LICENSES
        szOID_LICENSES equ <"1.3.6.1.4.1.311.10.6.1">
      endif
      ifndef szOID_LICENSE_SERVER
        szOID_LICENSE_SERVER equ <"1.3.6.1.4.1.311.10.6.2">
      endif
      ifndef szOID_KP_SMARTCARD_LOGON
        szOID_KP_SMARTCARD_LOGON equ <"1.3.6.1.4.1.311.20.2.2">
      endif
      szOID_KP_KERNEL_MODE_CODE_SIGNING equ <"1.3.6.1.4.1.311.61.1.1">
      szOID_KP_KERNEL_MODE_TRUSTED_BOOT_SIGNING equ <"1.3.6.1.4.1.311.61.4.1">
      szOID_REVOKED_LIST_SIGNER equ <"1.3.6.1.4.1.311.10.3.19">
      szOID_WINDOWS_KITS_SIGNER equ <"1.3.6.1.4.1.311.10.3.20">
      szOID_WINDOWS_RT_SIGNER equ <"1.3.6.1.4.1.311.10.3.21">
      szOID_PROTECTED_PROCESS_LIGHT_SIGNER equ <"1.3.6.1.4.1.311.10.3.22">
      szOID_WINDOWS_TCB_SIGNER equ <"1.3.6.1.4.1.311.10.3.23">
      szOID_PROTECTED_PROCESS_SIGNER equ <"1.3.6.1.4.1.311.10.3.24">
      szOID_WINDOWS_THIRD_PARTY_COMPONENT_SIGNER equ <"1.3.6.1.4.1.311.10.3.25">
      szOID_WINDOWS_SOFTWARE_EXTENSION_SIGNER equ <"1.3.6.1.4.1.311.10.3.26">
      szOID_DISALLOWED_LIST equ <"1.3.6.1.4.1.311.10.3.30">
      szOID_PIN_RULES_SIGNER equ <"1.3.6.1.4.1.311.10.3.31">
      szOID_PIN_RULES_CTL equ <"1.3.6.1.4.1.311.10.3.32">
      szOID_PIN_RULES_EXT equ <"1.3.6.1.4.1.311.10.3.33">
      szOID_PIN_RULES_DOMAIN_NAME equ <"1.3.6.1.4.1.311.10.3.34">
      szOID_PIN_RULES_LOG_END_DATE_EXT equ <"1.3.6.1.4.1.311.10.3.35">
      szOID_IUM_SIGNING equ <"1.3.6.1.4.1.311.10.3.37">
      szOID_EV_WHQL_CRYPTO equ <"1.3.6.1.4.1.311.10.3.39">
      szOID_BIOMETRIC_SIGNING equ <"1.3.6.1.4.1.311.10.3.41">
      szOID_ENCLAVE_SIGNING equ <"1.3.6.1.4.1.311.10.3.42">
      szOID_SYNC_ROOT_CTL_EXT equ <"1.3.6.1.4.1.311.10.3.50">
      szOID_HPKP_DOMAIN_NAME_CTL equ <"1.3.6.1.4.1.311.10.3.60">
      szOID_HPKP_HEADER_VALUE_CTL equ <"1.3.6.1.4.1.311.10.3.61">
      szOID_KP_KERNEL_MODE_HAL_EXTENSION_SIGNING equ <"1.3.6.1.4.1.311.61.5.1">
      szOID_WINDOWS_STORE_SIGNER equ <"1.3.6.1.4.1.311.76.3.1">
      szOID_DYNAMIC_CODE_GEN_SIGNER equ <"1.3.6.1.4.1.311.76.5.1">
      szOID_MICROSOFT_PUBLISHER_SIGNER equ <"1.3.6.1.4.1.311.76.8.1">
      szOID_YESNO_TRUST_ATTR equ <"1.3.6.1.4.1.311.10.4.1">
      szOID_SITE_PIN_RULES_INDEX_ATTR equ <"1.3.6.1.4.1.311.10.4.2">
      szOID_SITE_PIN_RULES_FLAGS_ATTR equ <"1.3.6.1.4.1.311.10.4.3">
      SITE_PIN_RULES_ALL_SUBDOMAINS_FLAG equ 1h
      szOID_PKIX_POLICY_QUALIFIER_CPS equ <"1.3.6.1.5.5.7.2.1">
      szOID_PKIX_POLICY_QUALIFIER_USERNOTICE equ <"1.3.6.1.5.5.7.2.2">
      szOID_ROOT_PROGRAM_FLAGS equ <"1.3.6.1.4.1.311.60.1.1">
      CERT_ROOT_PROGRAM_FLAG_ORG equ 80h
      CERT_ROOT_PROGRAM_FLAG_LSC equ 40h
      CERT_ROOT_PROGRAM_FLAG_SUBJECT_LOGO equ 20h
      CERT_ROOT_PROGRAM_FLAG_OU equ 10h
      CERT_ROOT_PROGRAM_FLAG_ADDRESS equ 08h
      szOID_CERT_POLICIES_95_QUALIFIER1 equ <"2.16.840.1.113733.1.7.1.1">
      szOID_RDN_TPM_MANUFACTURER equ <"2.23.133.2.1">
      szOID_RDN_TPM_MODEL equ <"2.23.133.2.2">
      szOID_RDN_TPM_VERSION equ <"2.23.133.2.3">
      szOID_RDN_TCG_PLATFORM_MANUFACTURER equ <"2.23.133.2.4">
      szOID_RDN_TCG_PLATFORM_MODEL equ <"2.23.133.2.5">
      szOID_RDN_TCG_PLATFORM_VERSION equ <"2.23.133.2.6">
      szOID_CT_CERT_SCTLIST equ <"1.3.6.1.4.1.11129.2.4.2">
      szOID_ENROLL_EK_INFO equ <"1.3.6.1.4.1.311.21.23">
      szOID_ENROLL_AIK_INFO equ <"1.3.6.1.4.1.311.21.39">
      szOID_ENROLL_ATTESTATION_STATEMENT equ <"1.3.6.1.4.1.311.21.24">
      szOID_ENROLL_KSP_NAME equ <"1.3.6.1.4.1.311.21.25">
      szOID_ENROLL_EKPUB_CHALLENGE equ <"1.3.6.1.4.1.311.21.26">
      szOID_ENROLL_CAXCHGCERT_HASH equ <"1.3.6.1.4.1.311.21.27">
      szOID_ENROLL_ATTESTATION_CHALLENGE equ <"1.3.6.1.4.1.311.21.28">
      szOID_ENROLL_ENCRYPTION_ALGORITHM equ <"1.3.6.1.4.1.311.21.29">
      szOID_KP_TPM_EK_CERTIFICATE equ <"2.23.133.8.1">
      szOID_KP_TPM_PLATFORM_CERTIFICATE equ <"2.23.133.8.2">
      szOID_KP_TPM_AIK_CERTIFICATE equ <"2.23.133.8.3">
      szOID_ENROLL_EKVERIFYKEY equ <"1.3.6.1.4.1.311.21.30">
      szOID_ENROLL_EKVERIFYCERT equ <"1.3.6.1.4.1.311.21.31">
      szOID_ENROLL_EKVERIFYCREDS equ <"1.3.6.1.4.1.311.21.32">
      szOID_ENROLL_SCEP_ERROR equ <"1.3.6.1.4.1.311.21.33">
      szOID_ENROLL_SCEP_SERVER_STATE equ <"1.3.6.1.4.1.311.21.34">
      szOID_ENROLL_SCEP_CHALLENGE_ANSWER equ <"1.3.6.1.4.1.311.21.35">
      szOID_ENROLL_SCEP_CLIENT_REQUEST equ <"1.3.6.1.4.1.311.21.37">
      szOID_ENROLL_SCEP_SERVER_MESSAGE equ <"1.3.6.1.4.1.311.21.38">
      szOID_ENROLL_SCEP_SERVER_SECRET equ <"1.3.6.1.4.1.311.21.40">
      szOID_ENROLL_KEY_AFFINITY equ <"1.3.6.1.4.1.311.21.41">
      szOID_ENROLL_SCEP_SIGNER_HASH equ <"1.3.6.1.4.1.311.21.42">
      szOID_ENROLL_EK_CA_KEYID equ <"1.3.6.1.4.1.311.21.43">
      szOID_ATTR_SUPPORTED_ALGORITHMS equ <"2.5.4.52">
      szOID_ATTR_TPM_SPECIFICATION equ <"2.23.133.2.16">
      szOID_ATTR_PLATFORM_SPECIFICATION equ <"2.23.133.2.17">
      szOID_ATTR_TPM_SECURITY_ASSERTIONS equ <"2.23.133.2.18">
      CERT_EXTENSIONS struct
        cExtension DWORD ?
        rgExtension PCERT_EXTENSION ?
      CERT_EXTENSIONS ends
      _CERT_EXTENSIONS typedef CERT_EXTENSIONS
      PCERT_EXTENSIONS typedef ptr CERT_EXTENSIONS
      CERT_UNICODE_RDN_ERR_INDEX_MASK equ 3FFh
      CERT_UNICODE_RDN_ERR_INDEX_SHIFT equ 22
      CERT_UNICODE_ATTR_ERR_INDEX_MASK equ 003Fh
      CERT_UNICODE_ATTR_ERR_INDEX_SHIFT equ 16
      CERT_UNICODE_VALUE_ERR_INDEX_MASK equ 0000FFFFh
      CERT_UNICODE_VALUE_ERR_INDEX_SHIFT equ 0
      GET_CERT_UNICODE_RDN_ERR_INDEX macro X
        exitm <((X shr CERT_UNICODE_RDN_ERR_INDEX_SHIFT) and CERT_UNICODE_RDN_ERR_INDEX_MASK)>
      endm
      GET_CERT_UNICODE_ATTR_ERR_INDEX macro X
        exitm <((X shr CERT_UNICODE_ATTR_ERR_INDEX_SHIFT) and CERT_UNICODE_ATTR_ERR_INDEX_MASK)>
      endm
      GET_CERT_UNICODE_VALUE_ERR_INDEX macro X
        exitm <(X and CERT_UNICODE_VALUE_ERR_INDEX_MASK)>
      endm
      CERT_AUTHORITY_KEY_ID_INFO struct
        KeyId CRYPT_DATA_BLOB <>
        CertIssuer CERT_NAME_BLOB <>
        CertSerialNumber CRYPT_INTEGER_BLOB <>
      CERT_AUTHORITY_KEY_ID_INFO ends
      _CERT_AUTHORITY_KEY_ID_INFO typedef CERT_AUTHORITY_KEY_ID_INFO
      PCERT_AUTHORITY_KEY_ID_INFO typedef ptr CERT_AUTHORITY_KEY_ID_INFO
      CERT_PRIVATE_KEY_VALIDITY struct
        NotBefore FILETIME <>
        NotAfter FILETIME <>
      CERT_PRIVATE_KEY_VALIDITY ends
      _CERT_PRIVATE_KEY_VALIDITY typedef CERT_PRIVATE_KEY_VALIDITY
      PCERT_PRIVATE_KEY_VALIDITY typedef ptr CERT_PRIVATE_KEY_VALIDITY
      CERT_KEY_ATTRIBUTES_INFO struct
        KeyId CRYPT_DATA_BLOB <>
        IntendedKeyUsage CRYPT_BIT_BLOB <>
        pPrivateKeyUsagePeriod PCERT_PRIVATE_KEY_VALIDITY ?
      CERT_KEY_ATTRIBUTES_INFO ends
      _CERT_KEY_ATTRIBUTES_INFO typedef CERT_KEY_ATTRIBUTES_INFO
      PCERT_KEY_ATTRIBUTES_INFO typedef ptr CERT_KEY_ATTRIBUTES_INFO
      CERT_DIGITAL_SIGNATURE_KEY_USAGE equ 80h
      CERT_NON_REPUDIATION_KEY_USAGE equ 40h
      CERT_KEY_ENCIPHERMENT_KEY_USAGE equ 20h
      CERT_DATA_ENCIPHERMENT_KEY_USAGE equ 10h
      CERT_KEY_AGREEMENT_KEY_USAGE equ 08h
      CERT_KEY_CERT_SIGN_KEY_USAGE equ 04h
      CERT_OFFLINE_CRL_SIGN_KEY_USAGE equ 02h
      CERT_CRL_SIGN_KEY_USAGE equ 02h
      CERT_ENCIPHER_ONLY_KEY_USAGE equ 01h
      CERT_DECIPHER_ONLY_KEY_USAGE equ 80h
      CERT_POLICY_ID struct
        cCertPolicyElementId DWORD ?
        rgpszCertPolicyElementId POINTER ?
      CERT_POLICY_ID ends
      _CERT_POLICY_ID typedef CERT_POLICY_ID
      PCERT_POLICY_ID typedef ptr CERT_POLICY_ID
      CERT_KEY_USAGE_RESTRICTION_INFO struct
        cCertPolicyId DWORD ?
        rgCertPolicyId PCERT_POLICY_ID ?
        RestrictedKeyUsage CRYPT_BIT_BLOB <>
      CERT_KEY_USAGE_RESTRICTION_INFO ends
      _CERT_KEY_USAGE_RESTRICTION_INFO typedef CERT_KEY_USAGE_RESTRICTION_INFO
      PCERT_KEY_USAGE_RESTRICTION_INFO typedef ptr CERT_KEY_USAGE_RESTRICTION_INFO
      CERT_OTHER_NAME struct
        pszObjId LPSTR ?
        Value CRYPT_OBJID_BLOB <>
      CERT_OTHER_NAME ends
      _CERT_OTHER_NAME typedef CERT_OTHER_NAME
      PCERT_OTHER_NAME typedef ptr CERT_OTHER_NAME
      CERT_ALT_NAME_ENTRY struct
        dwAltNameChoice DWORD ?
        union
          pOtherName PCERT_OTHER_NAME ?
          pwszRfc822Name LPWSTR ?
          pwszDNSName LPWSTR ?
          DirectoryName CERT_NAME_BLOB <>
          pwszURL LPWSTR ?
          IPAddress CRYPT_DATA_BLOB <>
          pszRegisteredID LPSTR ?
        ends
      CERT_ALT_NAME_ENTRY ends
      _CERT_ALT_NAME_ENTRY typedef CERT_ALT_NAME_ENTRY
      PCERT_ALT_NAME_ENTRY typedef ptr CERT_ALT_NAME_ENTRY
      CERT_ALT_NAME_OTHER_NAME equ 1
      CERT_ALT_NAME_RFC822_NAME equ 2
      CERT_ALT_NAME_DNS_NAME equ 3
      CERT_ALT_NAME_X400_ADDRESS equ 4
      CERT_ALT_NAME_DIRECTORY_NAME equ 5
      CERT_ALT_NAME_EDI_PARTY_NAME equ 6
      CERT_ALT_NAME_URL equ 7
      CERT_ALT_NAME_IP_ADDRESS equ 8
      CERT_ALT_NAME_REGISTERED_ID equ 9
      CERT_ALT_NAME_INFO struct
        cAltEntry DWORD ?
        rgAltEntry PCERT_ALT_NAME_ENTRY ?
      CERT_ALT_NAME_INFO ends
      _CERT_ALT_NAME_INFO typedef CERT_ALT_NAME_INFO
      PCERT_ALT_NAME_INFO typedef ptr CERT_ALT_NAME_INFO
      CERT_ALT_NAME_ENTRY_ERR_INDEX_MASK equ 0FFh
      CERT_ALT_NAME_ENTRY_ERR_INDEX_SHIFT equ 16
      CERT_ALT_NAME_VALUE_ERR_INDEX_MASK equ 0000FFFFh
      CERT_ALT_NAME_VALUE_ERR_INDEX_SHIFT equ 0
      GET_CERT_ALT_NAME_ENTRY_ERR_INDEX macro X
        exitm <((X shr CERT_ALT_NAME_ENTRY_ERR_INDEX_SHIFT) and CERT_ALT_NAME_ENTRY_ERR_INDEX_MASK)>
      endm
      GET_CERT_ALT_NAME_VALUE_ERR_INDEX macro X
        exitm <(X and CERT_ALT_NAME_VALUE_ERR_INDEX_MASK)>
      endm
      CERT_BASIC_CONSTRAINTS_INFO struct
        SubjectType CRYPT_BIT_BLOB <>
        fPathLenConstraint BOOL ?
        dwPathLenConstraint DWORD ?
        cSubtreesConstraint DWORD ?
        rgSubtreesConstraint POINTER ?
      CERT_BASIC_CONSTRAINTS_INFO ends
      _CERT_BASIC_CONSTRAINTS_INFO typedef CERT_BASIC_CONSTRAINTS_INFO
      PCERT_BASIC_CONSTRAINTS_INFO typedef ptr CERT_BASIC_CONSTRAINTS_INFO
      CERT_CA_SUBJECT_FLAG equ 80h
      CERT_END_ENTITY_SUBJECT_FLAG equ 40h
      CERT_BASIC_CONSTRAINTS2_INFO struct
        fCA BOOL ?
        fPathLenConstraint BOOL ?
        dwPathLenConstraint DWORD ?
      CERT_BASIC_CONSTRAINTS2_INFO ends
      _CERT_BASIC_CONSTRAINTS2_INFO typedef CERT_BASIC_CONSTRAINTS2_INFO
      PCERT_BASIC_CONSTRAINTS2_INFO typedef ptr CERT_BASIC_CONSTRAINTS2_INFO
      CERT_POLICY_QUALIFIER_INFO struct
        pszPolicyQualifierId LPSTR ?
        Qualifier CRYPT_OBJID_BLOB <>
      CERT_POLICY_QUALIFIER_INFO ends
      _CERT_POLICY_QUALIFIER_INFO typedef CERT_POLICY_QUALIFIER_INFO
      PCERT_POLICY_QUALIFIER_INFO typedef ptr CERT_POLICY_QUALIFIER_INFO
      CERT_POLICY_INFO struct
        pszPolicyIdentifier LPSTR ?
        cPolicyQualifier DWORD ?
        rgPolicyQualifier POINTER ?
      CERT_POLICY_INFO ends
      _CERT_POLICY_INFO typedef CERT_POLICY_INFO
      PCERT_POLICY_INFO typedef ptr CERT_POLICY_INFO
      CERT_POLICIES_INFO struct
        cPolicyInfo DWORD ?
        rgPolicyInfo POINTER ?
      CERT_POLICIES_INFO ends
      _CERT_POLICIES_INFO typedef CERT_POLICIES_INFO
      PCERT_POLICIES_INFO typedef ptr CERT_POLICIES_INFO
      CERT_POLICY_QUALIFIER_NOTICE_REFERENCE struct
        pszOrganization LPSTR ?
        cNoticeNumbers DWORD ?
        rgNoticeNumbers POINTER ?
      CERT_POLICY_QUALIFIER_NOTICE_REFERENCE ends
      _CERT_POLICY_QUALIFIER_NOTICE_REFERENCE typedef CERT_POLICY_QUALIFIER_NOTICE_REFERENCE
      PCERT_POLICY_QUALIFIER_NOTICE_REFERENCE typedef ptr CERT_POLICY_QUALIFIER_NOTICE_REFERENCE
      CERT_POLICY_QUALIFIER_USER_NOTICE struct
        pNoticeReference POINTER ?
        pszDisplayText LPWSTR ?
      CERT_POLICY_QUALIFIER_USER_NOTICE ends
      _CERT_POLICY_QUALIFIER_USER_NOTICE typedef CERT_POLICY_QUALIFIER_USER_NOTICE
      PCERT_POLICY_QUALIFIER_USER_NOTICE typedef ptr CERT_POLICY_QUALIFIER_USER_NOTICE
      CPS_URLS struct
        pszURL LPWSTR ?
        pAlgorithm POINTER ?
        pDigest POINTER ?
      CPS_URLS ends
      _CPS_URLS typedef CPS_URLS
      PCPS_URLS typedef ptr CPS_URLS
      CERT_POLICY95_QUALIFIER1 struct
        pszPracticesReference LPWSTR ?
        pszNoticeIdentifier LPSTR ?
        pszNSINoticeIdentifier LPSTR ?
        cCPSURLs DWORD ?
        rgCPSURLs POINTER ?
      CERT_POLICY95_QUALIFIER1 ends
      _CERT_POLICY95_QUALIFIER1 typedef CERT_POLICY95_QUALIFIER1
      PCERT_POLICY95_QUALIFIER1 typedef ptr CERT_POLICY95_QUALIFIER1
      CERT_POLICY_MAPPING struct
        pszIssuerDomainPolicy LPSTR ?
        pszSubjectDomainPolicy LPSTR ?
      CERT_POLICY_MAPPING ends
      _CERT_POLICY_MAPPING typedef CERT_POLICY_MAPPING
      PCERT_POLICY_MAPPING typedef ptr CERT_POLICY_MAPPING
      CERT_POLICY_MAPPINGS_INFO struct
        cPolicyMapping DWORD ?
        rgPolicyMapping PCERT_POLICY_MAPPING ?
      CERT_POLICY_MAPPINGS_INFO ends
      _CERT_POLICY_MAPPINGS_INFO typedef CERT_POLICY_MAPPINGS_INFO
      PCERT_POLICY_MAPPINGS_INFO typedef ptr CERT_POLICY_MAPPINGS_INFO
      CERT_POLICY_CONSTRAINTS_INFO struct
        fRequireExplicitPolicy BOOL ?
        dwRequireExplicitPolicySkipCerts DWORD ?
        fInhibitPolicyMapping BOOL ?
        dwInhibitPolicyMappingSkipCerts DWORD ?
      CERT_POLICY_CONSTRAINTS_INFO ends
      _CERT_POLICY_CONSTRAINTS_INFO typedef CERT_POLICY_CONSTRAINTS_INFO
      PCERT_POLICY_CONSTRAINTS_INFO typedef ptr CERT_POLICY_CONSTRAINTS_INFO
      CRYPT_CONTENT_INFO_SEQUENCE_OF_ANY struct
        pszObjId LPSTR ?
        cValue DWORD ?
        rgValue PCRYPT_DER_BLOB ?
      CRYPT_CONTENT_INFO_SEQUENCE_OF_ANY ends
      _CRYPT_CONTENT_INFO_SEQUENCE_OF_ANY typedef CRYPT_CONTENT_INFO_SEQUENCE_OF_ANY
      PCRYPT_CONTENT_INFO_SEQUENCE_OF_ANY typedef ptr CRYPT_CONTENT_INFO_SEQUENCE_OF_ANY
      CRYPT_CONTENT_INFO struct
        pszObjId LPSTR ?
        Content CRYPT_DER_BLOB <>
      CRYPT_CONTENT_INFO ends
      _CRYPT_CONTENT_INFO typedef CRYPT_CONTENT_INFO
      PCRYPT_CONTENT_INFO typedef ptr CRYPT_CONTENT_INFO
      CRYPT_SEQUENCE_OF_ANY struct
        cValue DWORD ?
        rgValue PCRYPT_DER_BLOB ?
      CRYPT_SEQUENCE_OF_ANY ends
      _CRYPT_SEQUENCE_OF_ANY typedef CRYPT_SEQUENCE_OF_ANY
      PCRYPT_SEQUENCE_OF_ANY typedef ptr CRYPT_SEQUENCE_OF_ANY
      CERT_AUTHORITY_KEY_ID2_INFO struct
        KeyId CRYPT_DATA_BLOB <>
        AuthorityCertIssuer CERT_ALT_NAME_INFO <>
        AuthorityCertSerialNumber CRYPT_INTEGER_BLOB <>
      CERT_AUTHORITY_KEY_ID2_INFO ends
      _CERT_AUTHORITY_KEY_ID2_INFO typedef CERT_AUTHORITY_KEY_ID2_INFO
      PCERT_AUTHORITY_KEY_ID2_INFO typedef ptr CERT_AUTHORITY_KEY_ID2_INFO
      CERT_ACCESS_DESCRIPTION struct
        pszAccessMethod LPSTR ?
        AccessLocation CERT_ALT_NAME_ENTRY <>
      CERT_ACCESS_DESCRIPTION ends
      _CERT_ACCESS_DESCRIPTION typedef CERT_ACCESS_DESCRIPTION
      PCERT_ACCESS_DESCRIPTION typedef ptr CERT_ACCESS_DESCRIPTION
      CERT_AUTHORITY_INFO_ACCESS struct
        cAccDescr DWORD ?
        rgAccDescr PCERT_ACCESS_DESCRIPTION ?
      CERT_AUTHORITY_INFO_ACCESS ends
      _CERT_AUTHORITY_INFO_ACCESS typedef CERT_AUTHORITY_INFO_ACCESS
      PCERT_AUTHORITY_INFO_ACCESS typedef ptr CERT_AUTHORITY_INFO_ACCESS
      CERT_SUBJECT_INFO_ACCESS typedef CERT_AUTHORITY_INFO_ACCESS
      PCERT_SUBJECT_INFO_ACCESS typedef ptr CERT_AUTHORITY_INFO_ACCESS
      szOID_PKIX_ACC_DESCR equ <"1.3.6.1.5.5.7.48">
      szOID_PKIX_OCSP equ <"1.3.6.1.5.5.7.48.1">
      szOID_PKIX_CA_ISSUERS equ <"1.3.6.1.5.5.7.48.2">
      szOID_PKIX_TIME_STAMPING equ <"1.3.6.1.5.5.7.48.3">
      szOID_PKIX_CA_REPOSITORY equ <"1.3.6.1.5.5.7.48.5">
      CRL_REASON_UNSPECIFIED equ 0
      CRL_REASON_KEY_COMPROMISE equ 1
      CRL_REASON_CA_COMPROMISE equ 2
      CRL_REASON_AFFILIATION_CHANGED equ 3
      CRL_REASON_SUPERSEDED equ 4
      CRL_REASON_CESSATION_OF_OPERATION equ 5
      CRL_REASON_CERTIFICATE_HOLD equ 6
      CRL_REASON_REMOVE_FROM_CRL equ 8
      CRL_REASON_PRIVILEGE_WITHDRAWN equ 9
      CRL_REASON_AA_COMPROMISE equ 10
      CRL_DIST_POINT_NAME struct
        dwDistPointNameChoice DWORD ?
        union
          FullName CERT_ALT_NAME_INFO <>
        ends
      CRL_DIST_POINT_NAME ends
      _CRL_DIST_POINT_NAME typedef CRL_DIST_POINT_NAME
      PCRL_DIST_POINT_NAME typedef ptr CRL_DIST_POINT_NAME
      CRL_DIST_POINT_NO_NAME equ 0
      CRL_DIST_POINT_FULL_NAME equ 1
      CRL_DIST_POINT_ISSUER_RDN_NAME equ 2
      CRL_DIST_POINT struct
        DistPointName CRL_DIST_POINT_NAME <>
        ReasonFlags CRYPT_BIT_BLOB <>
        CRLIssuer CERT_ALT_NAME_INFO <>
      CRL_DIST_POINT ends
      _CRL_DIST_POINT typedef CRL_DIST_POINT
      PCRL_DIST_POINT typedef ptr CRL_DIST_POINT
      CRL_REASON_UNUSED_FLAG equ 80h
      CRL_REASON_KEY_COMPROMISE_FLAG equ 40h
      CRL_REASON_CA_COMPROMISE_FLAG equ 20h
      CRL_REASON_AFFILIATION_CHANGED_FLAG equ 10h
      CRL_REASON_SUPERSEDED_FLAG equ 08h
      CRL_REASON_CESSATION_OF_OPERATION_FLAG equ 04h
      CRL_REASON_CERTIFICATE_HOLD_FLAG equ 02h
      CRL_REASON_PRIVILEGE_WITHDRAWN_FLAG equ 01h
      CRL_REASON_AA_COMPROMISE_FLAG equ 80h
      CRL_DIST_POINTS_INFO struct
        cDistPoint DWORD ?
        rgDistPoint PCRL_DIST_POINT ?
      CRL_DIST_POINTS_INFO ends
      _CRL_DIST_POINTS_INFO typedef CRL_DIST_POINTS_INFO
      PCRL_DIST_POINTS_INFO typedef ptr CRL_DIST_POINTS_INFO
      CRL_DIST_POINT_ERR_INDEX_MASK equ 7Fh
      CRL_DIST_POINT_ERR_INDEX_SHIFT equ 24
      GET_CRL_DIST_POINT_ERR_INDEX macro X
        exitm <((X shr CRL_DIST_POINT_ERR_INDEX_SHIFT) and CRL_DIST_POINT_ERR_INDEX_MASK)>
      endm
      CRL_DIST_POINT_ERR_CRL_ISSUER_BIT equ 80000000h
      IS_CRL_DIST_POINT_ERR_CRL_ISSUER macro X
        exitm <(0 != (X and CRL_DIST_POINT_ERR_CRL_ISSUER_BIT))>
      endm
      CROSS_CERT_DIST_POINTS_INFO struct
        dwSyncDeltaTime DWORD ?
        cDistPoint DWORD ?
        rgDistPoint PCERT_ALT_NAME_INFO ?
      CROSS_CERT_DIST_POINTS_INFO ends
      _CROSS_CERT_DIST_POINTS_INFO typedef CROSS_CERT_DIST_POINTS_INFO
      PCROSS_CERT_DIST_POINTS_INFO typedef ptr CROSS_CERT_DIST_POINTS_INFO
      CROSS_CERT_DIST_POINT_ERR_INDEX_MASK equ 0FFh
      CROSS_CERT_DIST_POINT_ERR_INDEX_SHIFT equ 24
      GET_CROSS_CERT_DIST_POINT_ERR_INDEX macro X
        exitm <((X shr CROSS_CERT_DIST_POINT_ERR_INDEX_SHIFT) and CROSS_CERT_DIST_POINT_ERR_INDEX_MASK)>
      endm
      CERT_PAIR struct
        Forward CERT_BLOB <>
        Reverse CERT_BLOB <>
      CERT_PAIR ends
      _CERT_PAIR typedef CERT_PAIR
      PCERT_PAIR typedef ptr CERT_PAIR
      CRL_ISSUING_DIST_POINT struct
        DistPointName CRL_DIST_POINT_NAME <>
        fOnlyContainsUserCerts BOOL ?
        fOnlyContainsCACerts BOOL ?
        OnlySomeReasonFlags CRYPT_BIT_BLOB <>
        fIndirectCRL BOOL ?
      CRL_ISSUING_DIST_POINT ends
      _CRL_ISSUING_DIST_POINT typedef CRL_ISSUING_DIST_POINT
      PCRL_ISSUING_DIST_POINT typedef ptr CRL_ISSUING_DIST_POINT
      CERT_GENERAL_SUBTREE struct
        Base CERT_ALT_NAME_ENTRY <>
        dwMinimum DWORD ?
        fMaximum BOOL ?
        dwMaximum DWORD ?
      CERT_GENERAL_SUBTREE ends
      _CERT_GENERAL_SUBTREE typedef CERT_GENERAL_SUBTREE
      PCERT_GENERAL_SUBTREE typedef ptr CERT_GENERAL_SUBTREE
      CERT_NAME_CONSTRAINTS_INFO struct
        cPermittedSubtree DWORD ?
        rgPermittedSubtree PCERT_GENERAL_SUBTREE ?
        cExcludedSubtree DWORD ?
        rgExcludedSubtree PCERT_GENERAL_SUBTREE ?
      CERT_NAME_CONSTRAINTS_INFO ends
      _CERT_NAME_CONSTRAINTS_INFO typedef CERT_NAME_CONSTRAINTS_INFO
      PCERT_NAME_CONSTRAINTS_INFO typedef ptr CERT_NAME_CONSTRAINTS_INFO
      CERT_EXCLUDED_SUBTREE_BIT equ 80000000h
      IS_CERT_EXCLUDED_SUBTREE macro X
        exitm <(0 != (X and CERT_EXCLUDED_SUBTREE_BIT))>
      endm
      SORTED_CTL_EXT_FLAGS_OFFSET equ (0 * 4)
      SORTED_CTL_EXT_COUNT_OFFSET equ (1 * 4)
      SORTED_CTL_EXT_MAX_COLLISION_OFFSET equ (2 * 4)
      SORTED_CTL_EXT_HASH_BUCKET_OFFSET equ (3 * 4)
      SORTED_CTL_EXT_HASHED_SUBJECT_IDENTIFIER_FLAG equ 1h
      CERT_DSS_PARAMETERS struct
        p CRYPT_UINT_BLOB <>
        q CRYPT_UINT_BLOB <>
        g CRYPT_UINT_BLOB <>
      CERT_DSS_PARAMETERS ends
      _CERT_DSS_PARAMETERS typedef CERT_DSS_PARAMETERS
      PCERT_DSS_PARAMETERS typedef ptr CERT_DSS_PARAMETERS
      CERT_DSS_R_LEN equ 20
      CERT_DSS_S_LEN equ 20
      CERT_DSS_SIGNATURE_LEN equ <(CERT_DSS_R_LEN + CERT_DSS_S_LEN)>
      CERT_MAX_ASN_ENCODED_DSS_SIGNATURE_LEN equ (2 + 2 * (2 + 20 + 1))
      CERT_DH_PARAMETERS struct
        p CRYPT_UINT_BLOB <>
        g CRYPT_UINT_BLOB <>
      CERT_DH_PARAMETERS ends
      _CERT_DH_PARAMETERS typedef CERT_DH_PARAMETERS
      PCERT_DH_PARAMETERS typedef ptr CERT_DH_PARAMETERS
      CERT_ECC_SIGNATURE struct
        r CRYPT_UINT_BLOB <>
        s CRYPT_UINT_BLOB <>
      CERT_ECC_SIGNATURE ends
      _CERT_ECC_SIGNATURE typedef CERT_ECC_SIGNATURE
      PCERT_ECC_SIGNATURE typedef ptr CERT_ECC_SIGNATURE
      CERT_X942_DH_VALIDATION_PARAMS struct
        seed CRYPT_BIT_BLOB <>
        pgenCounter DWORD ?
      CERT_X942_DH_VALIDATION_PARAMS ends
      _CERT_X942_DH_VALIDATION_PARAMS typedef CERT_X942_DH_VALIDATION_PARAMS
      PCERT_X942_DH_VALIDATION_PARAMS typedef ptr CERT_X942_DH_VALIDATION_PARAMS
      CERT_X942_DH_PARAMETERS struct
        p CRYPT_UINT_BLOB <>
        g CRYPT_UINT_BLOB <>
        q CRYPT_UINT_BLOB <>
        j CRYPT_UINT_BLOB <>
        pValidationParams PCERT_X942_DH_VALIDATION_PARAMS ?
      CERT_X942_DH_PARAMETERS ends
      _CERT_X942_DH_PARAMETERS typedef CERT_X942_DH_PARAMETERS
      PCERT_X942_DH_PARAMETERS typedef ptr CERT_X942_DH_PARAMETERS
      CRYPT_X942_COUNTER_BYTE_LENGTH equ 4
      CRYPT_X942_KEY_LENGTH_BYTE_LENGTH equ 4
      CRYPT_X942_PUB_INFO_BYTE_LENGTH equ (512 / 8)
      CRYPT_X942_OTHER_INFO struct
        pszContentEncryptionObjId LPSTR ?
        rgbCounter BYTE CRYPT_X942_COUNTER_BYTE_LENGTH dup (?)
        rgbKeyLength BYTE CRYPT_X942_KEY_LENGTH_BYTE_LENGTH dup (?)
        PubInfo CRYPT_DATA_BLOB <>
      CRYPT_X942_OTHER_INFO ends
      _CRYPT_X942_OTHER_INFO typedef CRYPT_X942_OTHER_INFO
      PCRYPT_X942_OTHER_INFO typedef ptr CRYPT_X942_OTHER_INFO
      CRYPT_ECC_CMS_SHARED_INFO_SUPPPUBINFO_BYTE_LENGTH equ 4
      CRYPT_ECC_CMS_SHARED_INFO struct
        Algorithm CRYPT_ALGORITHM_IDENTIFIER <>
        EntityUInfo CRYPT_DATA_BLOB <>
        rgbSuppPubInfo BYTE CRYPT_ECC_CMS_SHARED_INFO_SUPPPUBINFO_BYTE_LENGTH dup (?)
      CRYPT_ECC_CMS_SHARED_INFO ends
      _CRYPT_ECC_CMS_SHARED_INFO typedef CRYPT_ECC_CMS_SHARED_INFO
      PCRYPT_ECC_CMS_SHARED_INFO typedef ptr CRYPT_ECC_CMS_SHARED_INFO
      CRYPT_RC2_CBC_PARAMETERS struct
        dwVersion DWORD ?
        fIV BOOL ?
        rgbIV BYTE 8 dup (?)
      CRYPT_RC2_CBC_PARAMETERS ends
      _CRYPT_RC2_CBC_PARAMETERS typedef CRYPT_RC2_CBC_PARAMETERS
      PCRYPT_RC2_CBC_PARAMETERS typedef ptr CRYPT_RC2_CBC_PARAMETERS
      CRYPT_RC2_40BIT_VERSION equ 160
      CRYPT_RC2_56BIT_VERSION equ 52
      CRYPT_RC2_64BIT_VERSION equ 120
      CRYPT_RC2_128BIT_VERSION equ 58
      CRYPT_SMIME_CAPABILITY struct
        pszObjId LPSTR ?
        Parameters CRYPT_OBJID_BLOB <>
      CRYPT_SMIME_CAPABILITY ends
      _CRYPT_SMIME_CAPABILITY typedef CRYPT_SMIME_CAPABILITY
      PCRYPT_SMIME_CAPABILITY typedef ptr CRYPT_SMIME_CAPABILITY
      CRYPT_SMIME_CAPABILITIES struct
        cCapability DWORD ?
        rgCapability PCRYPT_SMIME_CAPABILITY ?
      CRYPT_SMIME_CAPABILITIES ends
      _CRYPT_SMIME_CAPABILITIES typedef CRYPT_SMIME_CAPABILITIES
      PCRYPT_SMIME_CAPABILITIES typedef ptr CRYPT_SMIME_CAPABILITIES
      CERT_QC_STATEMENT struct
        pszStatementId LPSTR ?
        StatementInfo CRYPT_OBJID_BLOB <>
      CERT_QC_STATEMENT ends
      _CERT_QC_STATEMENT typedef CERT_QC_STATEMENT
      PCERT_QC_STATEMENT typedef ptr CERT_QC_STATEMENT
      CERT_QC_STATEMENTS_EXT_INFO struct
        cStatement DWORD ?
        rgStatement PCERT_QC_STATEMENT ?
      CERT_QC_STATEMENTS_EXT_INFO ends
      _CERT_QC_STATEMENTS_EXT_INFO typedef CERT_QC_STATEMENTS_EXT_INFO
      PCERT_QC_STATEMENTS_EXT_INFO typedef ptr CERT_QC_STATEMENTS_EXT_INFO
      szOID_QC_EU_COMPLIANCE equ <"0.4.0.1862.1.1">
      szOID_QC_SSCD equ <"0.4.0.1862.1.4">
      CRYPT_MASK_GEN_ALGORITHM struct
        pszObjId LPSTR ?
        HashAlgorithm CRYPT_ALGORITHM_IDENTIFIER <>
      CRYPT_MASK_GEN_ALGORITHM ends
      _CRYPT_MASK_GEN_ALGORITHM typedef CRYPT_MASK_GEN_ALGORITHM
      PCRYPT_MASK_GEN_ALGORITHM typedef ptr CRYPT_MASK_GEN_ALGORITHM
      CRYPT_RSA_SSA_PSS_PARAMETERS struct
        HashAlgorithm CRYPT_ALGORITHM_IDENTIFIER <>
        MaskGenAlgorithm CRYPT_MASK_GEN_ALGORITHM <>
        dwSaltLength DWORD ?
        dwTrailerField DWORD ?
      CRYPT_RSA_SSA_PSS_PARAMETERS ends
      _CRYPT_RSA_SSA_PSS_PARAMETERS typedef CRYPT_RSA_SSA_PSS_PARAMETERS
      PCRYPT_RSA_SSA_PSS_PARAMETERS typedef ptr CRYPT_RSA_SSA_PSS_PARAMETERS
      PKCS_RSA_SSA_PSS_TRAILER_FIELD_BC equ 1
      CRYPT_PSOURCE_ALGORITHM struct
        pszObjId LPSTR ?
        EncodingParameters CRYPT_DATA_BLOB <>
      CRYPT_PSOURCE_ALGORITHM ends
      _CRYPT_PSOURCE_ALGORITHM typedef CRYPT_PSOURCE_ALGORITHM
      PCRYPT_PSOURCE_ALGORITHM typedef ptr CRYPT_PSOURCE_ALGORITHM
      CRYPT_RSAES_OAEP_PARAMETERS struct
        HashAlgorithm CRYPT_ALGORITHM_IDENTIFIER <>
        MaskGenAlgorithm CRYPT_MASK_GEN_ALGORITHM <>
        PSourceAlgorithm CRYPT_PSOURCE_ALGORITHM <>
      CRYPT_RSAES_OAEP_PARAMETERS ends
      _CRYPT_RSAES_OAEP_PARAMETERS typedef CRYPT_RSAES_OAEP_PARAMETERS
      PCRYPT_RSAES_OAEP_PARAMETERS typedef ptr CRYPT_RSAES_OAEP_PARAMETERS
      szOID_VERISIGN_PRIVATE_6_9 equ <"2.16.840.1.113733.1.6.9">
      szOID_VERISIGN_ONSITE_JURISDICTION_HASH equ <"2.16.840.1.113733.1.6.11">
      szOID_VERISIGN_BITSTRING_6_13 equ <"2.16.840.1.113733.1.6.13">
      szOID_VERISIGN_ISS_STRONG_CRYPTO equ <"2.16.840.1.113733.1.8.1">
      szOIDVerisign_MessageType equ <"2.16.840.1.113733.1.9.2">
      szOIDVerisign_PkiStatus equ <"2.16.840.1.113733.1.9.3">
      szOIDVerisign_FailInfo equ <"2.16.840.1.113733.1.9.4">
      szOIDVerisign_SenderNonce equ <"2.16.840.1.113733.1.9.5">
      szOIDVerisign_RecipientNonce equ <"2.16.840.1.113733.1.9.6">
      szOIDVerisign_TransactionID equ <"2.16.840.1.113733.1.9.7">
      szOID_NETSCAPE equ <"2.16.840.1.113730">
      szOID_NETSCAPE_CERT_EXTENSION equ <"2.16.840.1.113730.1">
      szOID_NETSCAPE_CERT_TYPE equ <"2.16.840.1.113730.1.1">
      szOID_NETSCAPE_BASE_URL equ <"2.16.840.1.113730.1.2">
      szOID_NETSCAPE_REVOCATION_URL equ <"2.16.840.1.113730.1.3">
      szOID_NETSCAPE_CA_REVOCATION_URL equ <"2.16.840.1.113730.1.4">
      szOID_NETSCAPE_CERT_RENEWAL_URL equ <"2.16.840.1.113730.1.7">
      szOID_NETSCAPE_CA_POLICY_URL equ <"2.16.840.1.113730.1.8">
      szOID_NETSCAPE_SSL_SERVER_NAME equ <"2.16.840.1.113730.1.12">
      szOID_NETSCAPE_COMMENT equ <"2.16.840.1.113730.1.13">
      szOID_NETSCAPE_DATA_TYPE equ <"2.16.840.1.113730.2">
      szOID_NETSCAPE_CERT_SEQUENCE equ <"2.16.840.1.113730.2.5">
      NETSCAPE_SSL_CLIENT_AUTH_CERT_TYPE equ 80h
      NETSCAPE_SSL_SERVER_AUTH_CERT_TYPE equ 40h
      NETSCAPE_SMIME_CERT_TYPE equ 20h
      NETSCAPE_SIGN_CERT_TYPE equ 10h
      NETSCAPE_SSL_CA_CERT_TYPE equ 04h
      NETSCAPE_SMIME_CA_CERT_TYPE equ 02h
      NETSCAPE_SIGN_CA_CERT_TYPE equ 01h
      szOID_CT_PKI_DATA equ <"1.3.6.1.5.5.7.12.2">
      szOID_CT_PKI_RESPONSE equ <"1.3.6.1.5.5.7.12.3">
      szOID_PKIX_NO_SIGNATURE equ <"1.3.6.1.5.5.7.6.2">
      szOID_CMC equ <"1.3.6.1.5.5.7.7">
      szOID_CMC_STATUS_INFO equ <"1.3.6.1.5.5.7.7.1">
      szOID_CMC_IDENTIFICATION equ <"1.3.6.1.5.5.7.7.2">
      szOID_CMC_IDENTITY_PROOF equ <"1.3.6.1.5.5.7.7.3">
      szOID_CMC_DATA_RETURN equ <"1.3.6.1.5.5.7.7.4">
      szOID_CMC_TRANSACTION_ID equ <"1.3.6.1.5.5.7.7.5">
      szOID_CMC_SENDER_NONCE equ <"1.3.6.1.5.5.7.7.6">
      szOID_CMC_RECIPIENT_NONCE equ <"1.3.6.1.5.5.7.7.7">
      szOID_CMC_ADD_EXTENSIONS equ <"1.3.6.1.5.5.7.7.8">
      szOID_CMC_ENCRYPTED_POP equ <"1.3.6.1.5.5.7.7.9">
      szOID_CMC_DECRYPTED_POP equ <"1.3.6.1.5.5.7.7.10">
      szOID_CMC_LRA_POP_WITNESS equ <"1.3.6.1.5.5.7.7.11">
      szOID_CMC_GET_CERT equ <"1.3.6.1.5.5.7.7.15">
      szOID_CMC_GET_CRL equ <"1.3.6.1.5.5.7.7.16">
      szOID_CMC_REVOKE_REQUEST equ <"1.3.6.1.5.5.7.7.17">
      szOID_CMC_REG_INFO equ <"1.3.6.1.5.5.7.7.18">
      szOID_CMC_RESPONSE_INFO equ <"1.3.6.1.5.5.7.7.19">
      szOID_CMC_QUERY_PENDING equ <"1.3.6.1.5.5.7.7.21">
      szOID_CMC_ID_POP_LINK_RANDOM equ <"1.3.6.1.5.5.7.7.22">
      szOID_CMC_ID_POP_LINK_WITNESS equ <"1.3.6.1.5.5.7.7.23">
      szOID_CMC_ID_CONFIRM_CERT_ACCEPTANCE equ <"1.3.6.1.5.5.7.7.24">
      szOID_CMC_ADD_ATTRIBUTES equ <"1.3.6.1.4.1.311.10.10.1">
      CMC_TAGGED_ATTRIBUTE struct
        dwBodyPartID DWORD ?
        Attribute CRYPT_ATTRIBUTE <>
      CMC_TAGGED_ATTRIBUTE ends
      _CMC_TAGGED_ATTRIBUTE typedef CMC_TAGGED_ATTRIBUTE
      PCMC_TAGGED_ATTRIBUTE typedef ptr CMC_TAGGED_ATTRIBUTE
      CMC_TAGGED_CERT_REQUEST struct
        dwBodyPartID DWORD ?
        SignedCertRequest CRYPT_DER_BLOB <>
      CMC_TAGGED_CERT_REQUEST ends
      _CMC_TAGGED_CERT_REQUEST typedef CMC_TAGGED_CERT_REQUEST
      PCMC_TAGGED_CERT_REQUEST typedef ptr CMC_TAGGED_CERT_REQUEST
      CMC_TAGGED_REQUEST struct
        dwTaggedRequestChoice DWORD ?
        union
          pTaggedCertRequest PCMC_TAGGED_CERT_REQUEST ?
        ends
      CMC_TAGGED_REQUEST ends
      _CMC_TAGGED_REQUEST typedef CMC_TAGGED_REQUEST
      PCMC_TAGGED_REQUEST typedef ptr CMC_TAGGED_REQUEST
      CMC_TAGGED_CERT_REQUEST_CHOICE equ 1
      CMC_TAGGED_CONTENT_INFO struct
        dwBodyPartID DWORD ?
        EncodedContentInfo CRYPT_DER_BLOB <>
      CMC_TAGGED_CONTENT_INFO ends
      _CMC_TAGGED_CONTENT_INFO typedef CMC_TAGGED_CONTENT_INFO
      PCMC_TAGGED_CONTENT_INFO typedef ptr CMC_TAGGED_CONTENT_INFO
      CMC_TAGGED_OTHER_MSG struct
        dwBodyPartID DWORD ?
        pszObjId LPSTR ?
        Value CRYPT_OBJID_BLOB <>
      CMC_TAGGED_OTHER_MSG ends
      _CMC_TAGGED_OTHER_MSG typedef CMC_TAGGED_OTHER_MSG
      PCMC_TAGGED_OTHER_MSG typedef ptr CMC_TAGGED_OTHER_MSG
      CMC_DATA_INFO struct
        cTaggedAttribute DWORD ?
        rgTaggedAttribute PCMC_TAGGED_ATTRIBUTE ?
        cTaggedRequest DWORD ?
        rgTaggedRequest PCMC_TAGGED_REQUEST ?
        cTaggedContentInfo DWORD ?
        rgTaggedContentInfo PCMC_TAGGED_CONTENT_INFO ?
        cTaggedOtherMsg DWORD ?
        rgTaggedOtherMsg PCMC_TAGGED_OTHER_MSG ?
      CMC_DATA_INFO ends
      _CMC_DATA_INFO typedef CMC_DATA_INFO
      PCMC_DATA_INFO typedef ptr CMC_DATA_INFO
      CMC_RESPONSE_INFO struct
        cTaggedAttribute DWORD ?
        rgTaggedAttribute PCMC_TAGGED_ATTRIBUTE ?
        cTaggedContentInfo DWORD ?
        rgTaggedContentInfo PCMC_TAGGED_CONTENT_INFO ?
        cTaggedOtherMsg DWORD ?
        rgTaggedOtherMsg PCMC_TAGGED_OTHER_MSG ?
      CMC_RESPONSE_INFO ends
      _CMC_RESPONSE_INFO typedef CMC_RESPONSE_INFO
      PCMC_RESPONSE_INFO typedef ptr CMC_RESPONSE_INFO
      CMC_PEND_INFO struct
        PendToken CRYPT_DATA_BLOB <>
        PendTime FILETIME <>
      CMC_PEND_INFO ends
      _CMC_PEND_INFO typedef CMC_PEND_INFO
      PCMC_PEND_INFO typedef ptr CMC_PEND_INFO
      CMC_STATUS_INFO struct
        dwStatus DWORD ?
        cBodyList DWORD ?
        rgdwBodyList POINTER ?
        pwszStatusString LPWSTR ?
        dwOtherInfoChoice DWORD ?
        union
          dwFailInfo DWORD ?
          pPendInfo PCMC_PEND_INFO ?
        ends
      CMC_STATUS_INFO ends
      _CMC_STATUS_INFO typedef CMC_STATUS_INFO
      PCMC_STATUS_INFO typedef ptr CMC_STATUS_INFO
      CMC_OTHER_INFO_NO_CHOICE equ 0
      CMC_OTHER_INFO_FAIL_CHOICE equ 1
      CMC_OTHER_INFO_PEND_CHOICE equ 2
      CMC_STATUS_SUCCESS equ 0
      CMC_STATUS_FAILED equ 2
      CMC_STATUS_PENDING equ 3
      CMC_STATUS_NO_SUPPORT equ 4
      CMC_STATUS_CONFIRM_REQUIRED equ 5
      CMC_FAIL_BAD_ALG equ 0
      CMC_FAIL_BAD_MESSAGE_CHECK equ 1
      CMC_FAIL_BAD_REQUEST equ 2
      CMC_FAIL_BAD_TIME equ 3
      CMC_FAIL_BAD_CERT_ID equ 4
      CMC_FAIL_UNSUPORTED_EXT equ 5
      CMC_FAIL_MUST_ARCHIVE_KEYS equ 6
      CMC_FAIL_BAD_IDENTITY equ 7
      CMC_FAIL_POP_REQUIRED equ 8
      CMC_FAIL_POP_FAILED equ 9
      CMC_FAIL_NO_KEY_REUSE equ 10
      CMC_FAIL_INTERNAL_CA_ERROR equ 11
      CMC_FAIL_TRY_LATER equ 12
      CMC_ADD_EXTENSIONS_INFO struct
        dwCmcDataReference DWORD ?
        cCertReference DWORD ?
        rgdwCertReference POINTER ?
        cExtension DWORD ?
        rgExtension PCERT_EXTENSION ?
      CMC_ADD_EXTENSIONS_INFO ends
      _CMC_ADD_EXTENSIONS_INFO typedef CMC_ADD_EXTENSIONS_INFO
      PCMC_ADD_EXTENSIONS_INFO typedef ptr CMC_ADD_EXTENSIONS_INFO
      CMC_ADD_ATTRIBUTES_INFO struct
        dwCmcDataReference DWORD ?
        cCertReference DWORD ?
        rgdwCertReference POINTER ?
        cAttribute DWORD ?
        rgAttribute PCRYPT_ATTRIBUTE ?
      CMC_ADD_ATTRIBUTES_INFO ends
      _CMC_ADD_ATTRIBUTES_INFO typedef CMC_ADD_ATTRIBUTES_INFO
      PCMC_ADD_ATTRIBUTES_INFO typedef ptr CMC_ADD_ATTRIBUTES_INFO
      CERT_TEMPLATE_EXT struct
        pszObjId LPSTR ?
        dwMajorVersion DWORD ?
        fMinorVersion BOOL ?
        dwMinorVersion DWORD ?
      CERT_TEMPLATE_EXT ends
      _CERT_TEMPLATE_EXT typedef CERT_TEMPLATE_EXT
      PCERT_TEMPLATE_EXT typedef ptr CERT_TEMPLATE_EXT
      CERT_HASHED_URL struct
        HashAlgorithm CRYPT_ALGORITHM_IDENTIFIER <>
        Hash CRYPT_HASH_BLOB <>
        pwszUrl LPWSTR ?
      CERT_HASHED_URL ends
      _CERT_HASHED_URL typedef CERT_HASHED_URL
      PCERT_HASHED_URL typedef ptr CERT_HASHED_URL
      CERT_LOGOTYPE_DETAILS struct
        pwszMimeType LPWSTR ?
        cHashedUrl DWORD ?
        rgHashedUrl PCERT_HASHED_URL ?
      CERT_LOGOTYPE_DETAILS ends
      _CERT_LOGOTYPE_DETAILS typedef CERT_LOGOTYPE_DETAILS
      PCERT_LOGOTYPE_DETAILS typedef ptr CERT_LOGOTYPE_DETAILS
      CERT_LOGOTYPE_REFERENCE struct
        cHashedUrl DWORD ?
        rgHashedUrl PCERT_HASHED_URL ?
      CERT_LOGOTYPE_REFERENCE ends
      _CERT_LOGOTYPE_REFERENCE typedef CERT_LOGOTYPE_REFERENCE
      PCERT_LOGOTYPE_REFERENCE typedef ptr CERT_LOGOTYPE_REFERENCE
      CERT_LOGOTYPE_IMAGE_INFO struct
        dwLogotypeImageInfoChoice DWORD ?
        dwFileSize DWORD ?
        dwXSize DWORD ?
        dwYSize DWORD ?
        dwLogotypeImageResolutionChoice DWORD ?
        union
          dwNumBits DWORD ?
          dwTableSize DWORD ?
        ends
        pwszLanguage LPWSTR ?
      CERT_LOGOTYPE_IMAGE_INFO ends
      _CERT_LOGOTYPE_IMAGE_INFO typedef CERT_LOGOTYPE_IMAGE_INFO
      PCERT_LOGOTYPE_IMAGE_INFO typedef ptr CERT_LOGOTYPE_IMAGE_INFO
      CERT_LOGOTYPE_GRAY_SCALE_IMAGE_INFO_CHOICE equ 1
      CERT_LOGOTYPE_COLOR_IMAGE_INFO_CHOICE equ 2
      CERT_LOGOTYPE_NO_IMAGE_RESOLUTION_CHOICE equ 0
      CERT_LOGOTYPE_BITS_IMAGE_RESOLUTION_CHOICE equ 1
      CERT_LOGOTYPE_TABLE_SIZE_IMAGE_RESOLUTION_CHOICE equ 2
      CERT_LOGOTYPE_IMAGE struct
        LogotypeDetails CERT_LOGOTYPE_DETAILS <>
        pLogotypeImageInfo PCERT_LOGOTYPE_IMAGE_INFO ?
      CERT_LOGOTYPE_IMAGE ends
      _CERT_LOGOTYPE_IMAGE typedef CERT_LOGOTYPE_IMAGE
      PCERT_LOGOTYPE_IMAGE typedef ptr CERT_LOGOTYPE_IMAGE
      CERT_LOGOTYPE_AUDIO_INFO struct
        dwFileSize DWORD ?
        dwPlayTime DWORD ?
        dwChannels DWORD ?
        dwSampleRate DWORD ?
        pwszLanguage LPWSTR ?
      CERT_LOGOTYPE_AUDIO_INFO ends
      _CERT_LOGOTYPE_AUDIO_INFO typedef CERT_LOGOTYPE_AUDIO_INFO
      PCERT_LOGOTYPE_AUDIO_INFO typedef ptr CERT_LOGOTYPE_AUDIO_INFO
      CERT_LOGOTYPE_AUDIO struct
        LogotypeDetails CERT_LOGOTYPE_DETAILS <>
        pLogotypeAudioInfo PCERT_LOGOTYPE_AUDIO_INFO ?
      CERT_LOGOTYPE_AUDIO ends
      _CERT_LOGOTYPE_AUDIO typedef CERT_LOGOTYPE_AUDIO
      PCERT_LOGOTYPE_AUDIO typedef ptr CERT_LOGOTYPE_AUDIO
      CERT_LOGOTYPE_DATA struct
        cLogotypeImage DWORD ?
        rgLogotypeImage PCERT_LOGOTYPE_IMAGE ?
        cLogotypeAudio DWORD ?
        rgLogotypeAudio PCERT_LOGOTYPE_AUDIO ?
      CERT_LOGOTYPE_DATA ends
      _CERT_LOGOTYPE_DATA typedef CERT_LOGOTYPE_DATA
      PCERT_LOGOTYPE_DATA typedef ptr CERT_LOGOTYPE_DATA
      CERT_LOGOTYPE_INFO struct
        dwLogotypeInfoChoice DWORD ?
        union
          pLogotypeDirectInfo PCERT_LOGOTYPE_DATA ?
          pLogotypeIndirectInfo PCERT_LOGOTYPE_REFERENCE ?
        ends
      CERT_LOGOTYPE_INFO ends
      _CERT_LOGOTYPE_INFO typedef CERT_LOGOTYPE_INFO
      PCERT_LOGOTYPE_INFO typedef ptr CERT_LOGOTYPE_INFO
      CERT_LOGOTYPE_DIRECT_INFO_CHOICE equ 1
      CERT_LOGOTYPE_INDIRECT_INFO_CHOICE equ 2
      CERT_OTHER_LOGOTYPE_INFO struct
        pszObjId LPSTR ?
        LogotypeInfo CERT_LOGOTYPE_INFO <>
      CERT_OTHER_LOGOTYPE_INFO ends
      _CERT_OTHER_LOGOTYPE_INFO typedef CERT_OTHER_LOGOTYPE_INFO
      PCERT_OTHER_LOGOTYPE_INFO typedef ptr CERT_OTHER_LOGOTYPE_INFO
      szOID_LOYALTY_OTHER_LOGOTYPE equ <"1.3.6.1.5.5.7.20.1">
      szOID_BACKGROUND_OTHER_LOGOTYPE equ <"1.3.6.1.5.5.7.20.2">
      CERT_LOGOTYPE_EXT_INFO struct
        cCommunityLogo DWORD ?
        rgCommunityLogo PCERT_LOGOTYPE_INFO ?
        pIssuerLogo PCERT_LOGOTYPE_INFO ?
        pSubjectLogo PCERT_LOGOTYPE_INFO ?
        cOtherLogo DWORD ?
        rgOtherLogo PCERT_OTHER_LOGOTYPE_INFO ?
      CERT_LOGOTYPE_EXT_INFO ends
      _CERT_LOGOTYPE_EXT_INFO typedef CERT_LOGOTYPE_EXT_INFO
      PCERT_LOGOTYPE_EXT_INFO typedef ptr CERT_LOGOTYPE_EXT_INFO
      CERT_BIOMETRIC_DATA struct
        dwTypeOfBiometricDataChoice DWORD ?
        union
          dwPredefined DWORD ?
          pszObjId LPSTR ?
        ends
        HashedUrl CERT_HASHED_URL <>
      CERT_BIOMETRIC_DATA ends
      _CERT_BIOMETRIC_DATA typedef CERT_BIOMETRIC_DATA
      PCERT_BIOMETRIC_DATA typedef ptr CERT_BIOMETRIC_DATA
      CERT_BIOMETRIC_PREDEFINED_DATA_CHOICE equ 1
      CERT_BIOMETRIC_OID_DATA_CHOICE equ 2
      CERT_BIOMETRIC_PICTURE_TYPE equ 0
      CERT_BIOMETRIC_SIGNATURE_TYPE equ 1
      CERT_BIOMETRIC_EXT_INFO struct
        cBiometricData DWORD ?
        rgBiometricData PCERT_BIOMETRIC_DATA ?
      CERT_BIOMETRIC_EXT_INFO ends
      _CERT_BIOMETRIC_EXT_INFO typedef CERT_BIOMETRIC_EXT_INFO
      PCERT_BIOMETRIC_EXT_INFO typedef ptr CERT_BIOMETRIC_EXT_INFO
      OCSP_SIGNATURE_INFO struct
        SignatureAlgorithm CRYPT_ALGORITHM_IDENTIFIER <>
        Signature CRYPT_BIT_BLOB <>
        cCertEncoded DWORD ?
        rgCertEncoded PCERT_BLOB ?
      OCSP_SIGNATURE_INFO ends
      _OCSP_SIGNATURE_INFO typedef OCSP_SIGNATURE_INFO
      POCSP_SIGNATURE_INFO typedef ptr OCSP_SIGNATURE_INFO
      OCSP_SIGNED_REQUEST_INFO struct
        ToBeSigned CRYPT_DER_BLOB <>
        pOptionalSignatureInfo POCSP_SIGNATURE_INFO ?
      OCSP_SIGNED_REQUEST_INFO ends
      _OCSP_SIGNED_REQUEST_INFO typedef OCSP_SIGNED_REQUEST_INFO
      POCSP_SIGNED_REQUEST_INFO typedef ptr OCSP_SIGNED_REQUEST_INFO
      OCSP_CERT_ID struct
        HashAlgorithm CRYPT_ALGORITHM_IDENTIFIER <>
        IssuerNameHash CRYPT_HASH_BLOB <>
        IssuerKeyHash CRYPT_HASH_BLOB <>
        SerialNumber CRYPT_INTEGER_BLOB <>
      OCSP_CERT_ID ends
      _OCSP_CERT_ID typedef OCSP_CERT_ID
      POCSP_CERT_ID typedef ptr OCSP_CERT_ID
      OCSP_REQUEST_ENTRY struct
        CertId OCSP_CERT_ID <>
        cExtension DWORD ?
        rgExtension PCERT_EXTENSION ?
      OCSP_REQUEST_ENTRY ends
      _OCSP_REQUEST_ENTRY typedef OCSP_REQUEST_ENTRY
      POCSP_REQUEST_ENTRY typedef ptr OCSP_REQUEST_ENTRY
      OCSP_REQUEST_INFO struct
        dwVersion DWORD ?
        pRequestorName PCERT_ALT_NAME_ENTRY ?
        cRequestEntry DWORD ?
        rgRequestEntry POCSP_REQUEST_ENTRY ?
        cExtension DWORD ?
        rgExtension PCERT_EXTENSION ?
      OCSP_REQUEST_INFO ends
      _OCSP_REQUEST_INFO typedef OCSP_REQUEST_INFO
      POCSP_REQUEST_INFO typedef ptr OCSP_REQUEST_INFO
      OCSP_REQUEST_V1 equ 0
      OCSP_RESPONSE_INFO struct
        dwStatus DWORD ?
        pszObjId LPSTR ?
        Value CRYPT_OBJID_BLOB <>
      OCSP_RESPONSE_INFO ends
      _OCSP_RESPONSE_INFO typedef OCSP_RESPONSE_INFO
      POCSP_RESPONSE_INFO typedef ptr OCSP_RESPONSE_INFO
      OCSP_SUCCESSFUL_RESPONSE equ 0
      OCSP_MALFORMED_REQUEST_RESPONSE equ 1
      OCSP_INTERNAL_ERROR_RESPONSE equ 2
      OCSP_TRY_LATER_RESPONSE equ 3
      OCSP_SIG_REQUIRED_RESPONSE equ 5
      OCSP_UNAUTHORIZED_RESPONSE equ 6
      szOID_PKIX_OCSP_BASIC_SIGNED_RESPONSE equ <"1.3.6.1.5.5.7.48.1.1">
      OCSP_BASIC_SIGNED_RESPONSE_INFO struct
        ToBeSigned CRYPT_DER_BLOB <>
        SignatureInfo OCSP_SIGNATURE_INFO <>
      OCSP_BASIC_SIGNED_RESPONSE_INFO ends
      _OCSP_BASIC_SIGNED_RESPONSE_INFO typedef OCSP_BASIC_SIGNED_RESPONSE_INFO
      POCSP_BASIC_SIGNED_RESPONSE_INFO typedef ptr OCSP_BASIC_SIGNED_RESPONSE_INFO
      OCSP_BASIC_REVOKED_INFO struct
        RevocationDate FILETIME <>
        dwCrlReasonCode DWORD ?
      OCSP_BASIC_REVOKED_INFO ends
      _OCSP_BASIC_REVOKED_INFO typedef OCSP_BASIC_REVOKED_INFO
      POCSP_BASIC_REVOKED_INFO typedef ptr OCSP_BASIC_REVOKED_INFO
      OCSP_BASIC_RESPONSE_ENTRY struct
        CertId OCSP_CERT_ID <>
        dwCertStatus DWORD ?
        union
          pRevokedInfo POCSP_BASIC_REVOKED_INFO ?
        ends
        ThisUpdate FILETIME <>
        NextUpdate FILETIME <>
        cExtension DWORD ?
        rgExtension PCERT_EXTENSION ?
      OCSP_BASIC_RESPONSE_ENTRY ends
      _OCSP_BASIC_RESPONSE_ENTRY typedef OCSP_BASIC_RESPONSE_ENTRY
      POCSP_BASIC_RESPONSE_ENTRY typedef ptr OCSP_BASIC_RESPONSE_ENTRY
      OCSP_BASIC_GOOD_CERT_STATUS equ 0
      OCSP_BASIC_REVOKED_CERT_STATUS equ 1
      OCSP_BASIC_UNKNOWN_CERT_STATUS equ 2
      OCSP_BASIC_RESPONSE_INFO struct
        dwVersion DWORD ?
        dwResponderIdChoice DWORD ?
        union
          ByNameResponderId CERT_NAME_BLOB <>
          ByKeyResponderId CRYPT_HASH_BLOB <>
        ends
        ProducedAt FILETIME <>
        cResponseEntry DWORD ?
        rgResponseEntry POCSP_BASIC_RESPONSE_ENTRY ?
        cExtension DWORD ?
        rgExtension PCERT_EXTENSION ?
      OCSP_BASIC_RESPONSE_INFO ends
      _OCSP_BASIC_RESPONSE_INFO typedef OCSP_BASIC_RESPONSE_INFO
      POCSP_BASIC_RESPONSE_INFO typedef ptr OCSP_BASIC_RESPONSE_INFO
      OCSP_BASIC_RESPONSE_V1 equ 0
      OCSP_BASIC_BY_NAME_RESPONDER_ID equ 1
      OCSP_BASIC_BY_KEY_RESPONDER_ID equ 2
      CERT_SUPPORTED_ALGORITHM_INFO struct
        Algorithm CRYPT_ALGORITHM_IDENTIFIER <>
        IntendedKeyUsage CRYPT_BIT_BLOB <>
        IntendedCertPolicies CERT_POLICIES_INFO <>
      CERT_SUPPORTED_ALGORITHM_INFO ends
      _CERT_SUPPORTED_ALGORITHM_INFO typedef CERT_SUPPORTED_ALGORITHM_INFO
      PCERT_SUPPORTED_ALGORITHM_INFO typedef ptr CERT_SUPPORTED_ALGORITHM_INFO
      CERT_TPM_SPECIFICATION_INFO struct
        pwszFamily LPWSTR ?
        dwLevel DWORD ?
        dwRevision DWORD ?
      CERT_TPM_SPECIFICATION_INFO ends
      _CERT_TPM_SPECIFICATION_INFO typedef CERT_TPM_SPECIFICATION_INFO
      PCERT_TPM_SPECIFICATION_INFO typedef ptr CERT_TPM_SPECIFICATION_INFO
      HCRYPTOIDFUNCSET typedef ptr
      HCRYPTOIDFUNCADDR typedef ptr
      CRYPT_OID_ENCODE_OBJECT_FUNC equ <"CryptDllEncodeObject">
      CRYPT_OID_DECODE_OBJECT_FUNC equ <"CryptDllDecodeObject">
      CRYPT_OID_ENCODE_OBJECT_EX_FUNC equ <"CryptDllEncodeObjectEx">
      CRYPT_OID_DECODE_OBJECT_EX_FUNC equ <"CryptDllDecodeObjectEx">
      CRYPT_OID_CREATE_COM_OBJECT_FUNC equ <"CryptDllCreateCOMObject">
      CRYPT_OID_VERIFY_REVOCATION_FUNC equ <"CertDllVerifyRevocation">
      CRYPT_OID_VERIFY_CTL_USAGE_FUNC equ <"CertDllVerifyCTLUsage">
      CRYPT_OID_FORMAT_OBJECT_FUNC equ <"CryptDllFormatObject">
      CRYPT_OID_FIND_OID_INFO_FUNC equ <"CryptDllFindOIDInfo">
      CRYPT_OID_FIND_LOCALIZED_NAME_FUNC equ <"CryptDllFindLocalizedName">
      CRYPT_OID_REGPATH equ <"Software\Microsoft\Cryptography\OID">
      CRYPT_OID_REG_ENCODING_TYPE_PREFIX equ <"EncodingType ">
      CRYPT_OID_REG_DLL_VALUE_NAME equ <L("Dll")>
      CRYPT_OID_REG_FUNC_NAME_VALUE_NAME equ <L("FuncName")>
      CRYPT_OID_REG_FUNC_NAME_VALUE_NAME_A equ <"FuncName">
      CRYPT_OID_REG_FLAGS_VALUE_NAME equ <L("CryptFlags")>
      CRYPT_DEFAULT_OID equ <"DEFAULT">
      CRYPT_OID_FUNC_ENTRY struct
        pszOID LPCSTR ?
        pvFuncAddr POINTER ?
      CRYPT_OID_FUNC_ENTRY ends
      _CRYPT_OID_FUNC_ENTRY typedef CRYPT_OID_FUNC_ENTRY
      PCRYPT_OID_FUNC_ENTRY typedef ptr CRYPT_OID_FUNC_ENTRY
      CRYPT_INSTALL_OID_FUNC_BEFORE_FLAG equ 1
      @DefProto DllImport, CryptInstallOIDFunctionAddress, WIN_STD_CALL_CONV,, <:HMODULE, :DWORD, :LPCSTR, :DWORD, :ptr CRYPT_OID_FUNC_ENTRY, :DWORD>, 24
      @DefProto DllImport, CryptInitOIDFunctionSet, WIN_STD_CALL_CONV,, <:LPCSTR, :DWORD>, 8
      @DefProto DllImport, CryptGetOIDFunctionAddress, WIN_STD_CALL_CONV,, <:HCRYPTOIDFUNCSET, :DWORD, :LPCSTR, :DWORD, :ptr ptr, :ptr HCRYPTOIDFUNCADDR>, 24
      CRYPT_GET_INSTALLED_OID_FUNC_FLAG equ 1h
      @DefProto DllImport, CryptGetDefaultOIDDllList, WIN_STD_CALL_CONV,, <:HCRYPTOIDFUNCSET, :DWORD, :ptr WCHAR, :ptr DWORD>, 16
      @DefProto DllImport, CryptGetDefaultOIDFunctionAddress, WIN_STD_CALL_CONV,, <:HCRYPTOIDFUNCSET, :DWORD, :LPCWSTR, :DWORD, :ptr ptr, :ptr HCRYPTOIDFUNCADDR>, 24
      @DefProto DllImport, CryptFreeOIDFunctionAddress, WIN_STD_CALL_CONV,, <:HCRYPTOIDFUNCADDR, :DWORD>, 8
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_PHONE_RESTRICTED or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      @DefProto DllImport, CryptRegisterOIDFunction, WIN_STD_CALL_CONV,, <:DWORD, :LPCSTR, :LPCSTR, :LPCWSTR, :LPCSTR>, 20
      @DefProto DllImport, CryptUnregisterOIDFunction, WIN_STD_CALL_CONV,, <:DWORD, :LPCSTR, :LPCSTR>, 12
      @DefProto DllImport, CryptRegisterDefaultOIDFunction, WIN_STD_CALL_CONV,, <:DWORD, :LPCSTR, :DWORD, :LPCWSTR>, 16
      CRYPT_REGISTER_FIRST_INDEX equ 0
      CRYPT_REGISTER_LAST_INDEX equ 0FFFFFFFFh
      @DefProto DllImport, CryptUnregisterDefaultOIDFunction, WIN_STD_CALL_CONV,, <:DWORD, :LPCSTR, :LPCWSTR>, 12
      @DefProto DllImport, CryptSetOIDFunctionValue, WIN_STD_CALL_CONV,, <:DWORD, :LPCSTR, :LPCSTR, :LPCWSTR, :DWORD, :ptr BYTE, :DWORD>, 28
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      @DefProto DllImport, CryptGetOIDFunctionValue, WIN_STD_CALL_CONV,, <:DWORD, :LPCSTR, :LPCSTR, :LPCWSTR, :ptr DWORD, :ptr BYTE, :ptr DWORD>, 28
      TYPE_PFN_CRYPT_ENUM_OID_FUNC typedef proto WIN_STD_CALL_CONV :DWORD, :LPCSTR, :LPCSTR, :DWORD, :ptr DWORD, :ptr LPCWSTR, :ptr ptr BYTE, :ptr DWORD, :ptr
      PFN_CRYPT_ENUM_OID_FUNC typedef ptr TYPE_PFN_CRYPT_ENUM_OID_FUNC

      @DefProto DllImport, CryptEnumOIDFunction, WIN_STD_CALL_CONV,, <:DWORD, :LPCSTR, :LPCSTR, :DWORD, :ptr, :PFN_CRYPT_ENUM_OID_FUNC>, 24
      CRYPT_MATCH_ANY_ENCODING_TYPE equ 0FFFFFFFFh
      CALG_OID_INFO_CNG_ONLY equ 0FFFFFFFFh
      CALG_OID_INFO_PARAMETERS equ 0FFFFFFFEh
      IS_SPECIAL_OID_INFO_ALGID macro Algid
        exitm <(Algid >= CALG_OID_INFO_PARAMETERS)>
      endm
      CRYPT_OID_INFO_HASH_PARAMETERS_ALGORITHM equ <L("CryptOIDInfoHashParameters")>
      CRYPT_OID_INFO_ECC_PARAMETERS_ALGORITHM equ <L("CryptOIDInfoECCParameters")>
      CRYPT_OID_INFO_MGF1_PARAMETERS_ALGORITHM equ <L("CryptOIDInfoMgf1Parameters")>
      CRYPT_OID_INFO_NO_SIGN_ALGORITHM equ <L("CryptOIDInfoNoSign")>
      CRYPT_OID_INFO_OAEP_PARAMETERS_ALGORITHM equ <L("CryptOIDInfoOAEPParameters")>
      CRYPT_OID_INFO_ECC_WRAP_PARAMETERS_ALGORITHM equ <L("CryptOIDInfoECCWrapParameters")>
      CRYPT_OID_INFO_NO_PARAMETERS_ALGORITHM equ <L("CryptOIDInfoNoParameters")>
      CRYPT_OID_INFO struct
        cbSize DWORD ?
        pszOID LPCSTR ?
        pwszName LPCWSTR ?
        dwGroupId DWORD ?
        union
          dwValue DWORD ?
          Algid ALG_ID ?
          dwLength DWORD ?
        ends
        ExtraInfo CRYPT_DATA_BLOB <>
        ifdef CRYPT_OID_INFO_HAS_EXTRA_FIELDS
          pwszCNGAlgid LPCWSTR ?
          pwszCNGExtraAlgid LPCWSTR ?
        endif
      CRYPT_OID_INFO ends
      _CRYPT_OID_INFO typedef CRYPT_OID_INFO
      PCRYPT_OID_INFO typedef ptr CRYPT_OID_INFO
      CCRYPT_OID_INFO typedef CRYPT_OID_INFO
      PCCRYPT_OID_INFO typedef ptr CRYPT_OID_INFO
      CRYPT_HASH_ALG_OID_GROUP_ID equ 1
      CRYPT_ENCRYPT_ALG_OID_GROUP_ID equ 2
      CRYPT_PUBKEY_ALG_OID_GROUP_ID equ 3
      CRYPT_SIGN_ALG_OID_GROUP_ID equ 4
      CRYPT_RDN_ATTR_OID_GROUP_ID equ 5
      CRYPT_EXT_OR_ATTR_OID_GROUP_ID equ 6
      CRYPT_ENHKEY_USAGE_OID_GROUP_ID equ 7
      CRYPT_POLICY_OID_GROUP_ID equ 8
      CRYPT_TEMPLATE_OID_GROUP_ID equ 9
      CRYPT_KDF_OID_GROUP_ID equ 10
      CRYPT_LAST_OID_GROUP_ID equ 10
      CRYPT_FIRST_ALG_OID_GROUP_ID equ <CRYPT_HASH_ALG_OID_GROUP_ID>
      CRYPT_LAST_ALG_OID_GROUP_ID equ <CRYPT_SIGN_ALG_OID_GROUP_ID>
      CRYPT_OID_INHIBIT_SIGNATURE_FORMAT_FLAG equ 00000001h
      CRYPT_OID_USE_PUBKEY_PARA_FOR_PKCS7_FLAG equ 00000002h
      CRYPT_OID_NO_NULL_ALGORITHM_PARA_FLAG equ 00000004h
      CRYPT_OID_PUBKEY_SIGN_ONLY_FLAG equ 80000000h
      CRYPT_OID_PUBKEY_ENCRYPT_ONLY_FLAG equ 40000000h
      CRYPT_OID_USE_CURVE_NAME_FOR_ENCODE_FLAG equ 20000000h
      CRYPT_OID_USE_CURVE_PARAMETERS_FOR_ENCODE_FLAG equ 10000000h
      @DefProto DllImport, CryptFindOIDInfo, WIN_STD_CALL_CONV,, <:DWORD, :ptr, :DWORD>, 12
      CRYPT_OID_INFO_OID_KEY equ 1
      CRYPT_OID_INFO_NAME_KEY equ 2
      CRYPT_OID_INFO_ALGID_KEY equ 3
      CRYPT_OID_INFO_SIGN_KEY equ 4
      CRYPT_OID_INFO_CNG_ALGID_KEY equ 5
      CRYPT_OID_INFO_CNG_SIGN_KEY equ 6
      CRYPT_OID_INFO_OID_KEY_FLAGS_MASK equ 0FFFF0000h
      CRYPT_OID_INFO_PUBKEY_SIGN_KEY_FLAG equ 80000000h
      CRYPT_OID_INFO_PUBKEY_ENCRYPT_KEY_FLAG equ 40000000h
      CRYPT_OID_DISABLE_SEARCH_DS_FLAG equ 80000000h
      ifdef CRYPT_OID_INFO_HAS_EXTRA_FIELDS
        CRYPT_OID_PREFER_CNG_ALGID_FLAG equ 40000000h
      endif
      CRYPT_OID_INFO_OID_GROUP_BIT_LEN_MASK equ 0FFF0000h
      CRYPT_OID_INFO_OID_GROUP_BIT_LEN_SHIFT equ 16
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_PHONE_RESTRICTED or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      @DefProto DllImport, CryptRegisterOIDInfo, WIN_STD_CALL_CONV,, <:PCCRYPT_OID_INFO, :DWORD>, 8
      CRYPT_INSTALL_OID_INFO_BEFORE_FLAG equ 1
      @DefProto DllImport, CryptUnregisterOIDInfo, WIN_STD_CALL_CONV,, <:PCCRYPT_OID_INFO>, 4
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      TYPE_PFN_CRYPT_ENUM_OID_INFO typedef proto WIN_STD_CALL_CONV :PCCRYPT_OID_INFO, :ptr
      PFN_CRYPT_ENUM_OID_INFO typedef ptr TYPE_PFN_CRYPT_ENUM_OID_INFO

      @DefProto DllImport, CryptEnumOIDInfo, WIN_STD_CALL_CONV,, <:DWORD, :DWORD, :ptr, :PFN_CRYPT_ENUM_OID_INFO>, 16
      @DefProto DllImport, CryptFindLocalizedName, WIN_STD_CALL_CONV,, <:LPCWSTR>, 4
      CRYPT_LOCALIZED_NAME_ENCODING_TYPE equ 0
      CRYPT_LOCALIZED_NAME_OID equ <"LocalizedNames">
      CERT_STRONG_SIGN_SERIALIZED_INFO struct
        dwFlags DWORD ?
        pwszCNGSignHashAlgids LPWSTR ?
        pwszCNGPubKeyMinBitLengths LPWSTR ?
      CERT_STRONG_SIGN_SERIALIZED_INFO ends
      _CERT_STRONG_SIGN_SERIALIZED_INFO typedef CERT_STRONG_SIGN_SERIALIZED_INFO
      PCERT_STRONG_SIGN_SERIALIZED_INFO typedef ptr CERT_STRONG_SIGN_SERIALIZED_INFO
      CERT_STRONG_SIGN_ECDSA_ALGORITHM equ <L("ECDSA")>
      CERT_STRONG_SIGN_PARA struct
        cbSize DWORD ?
        dwInfoChoice DWORD ?
        union
          pvInfo POINTER ?
          pSerializedInfo PCERT_STRONG_SIGN_SERIALIZED_INFO ?
          pszOID LPSTR ?
        ends
      CERT_STRONG_SIGN_PARA ends
      _CERT_STRONG_SIGN_PARA typedef CERT_STRONG_SIGN_PARA
      PCERT_STRONG_SIGN_PARA typedef ptr CERT_STRONG_SIGN_PARA
      PCCERT_STRONG_SIGN_PARA typedef ptr CERT_STRONG_SIGN_PARA
      CERT_STRONG_SIGN_SERIALIZED_INFO_CHOICE equ 1
      CERT_STRONG_SIGN_OID_INFO_CHOICE equ 2
      CERT_STRONG_SIGN_ENABLE_CRL_CHECK equ 1h
      CERT_STRONG_SIGN_ENABLE_OCSP_CHECK equ 2h
      szOID_CERT_STRONG_SIGN_OS_PREFIX equ <"1.3.6.1.4.1.311.72.1.">
      szOID_CERT_STRONG_SIGN_OS_1 equ <"1.3.6.1.4.1.311.72.1.1">
      szOID_CERT_STRONG_SIGN_OS_CURRENT equ <szOID_CERT_STRONG_SIGN_OS_1>
      CERT_STRONG_SIGN_PARA_OS_1 equ <{ sizeof(CERT_STRONG_SIGN_PARA), CERT_STRONG_SIGN_OID_INFO_CHOICE, szOID_CERT_STRONG_SIGN_OS_1 }>
      CERT_STRONG_SIGN_PARA_OS_CURRENT equ <{ sizeof(CERT_STRONG_SIGN_PARA), CERT_STRONG_SIGN_OID_INFO_CHOICE, szOID_CERT_STRONG_SIGN_OS_CURRENT }>
      szOID_CERT_STRONG_KEY_OS_PREFIX equ <"1.3.6.1.4.1.311.72.2.">
      szOID_CERT_STRONG_KEY_OS_1 equ <"1.3.6.1.4.1.311.72.2.1">
      szOID_CERT_STRONG_KEY_OS_CURRENT equ <szOID_CERT_STRONG_KEY_OS_1>
      CERT_STRONG_KEY_PARA_OS_1 equ <{ sizeof(CERT_STRONG_SIGN_PARA), CERT_STRONG_SIGN_OID_INFO_CHOICE, szOID_CERT_STRONG_KEY_OS_1 }>
      CERT_STRONG_KEY_PARA_OS_CURRENT equ <{ sizeof(CERT_STRONG_SIGN_PARA), CERT_STRONG_SIGN_OID_INFO_CHOICE, szOID_CERT_STRONG_KEY_OS_CURRENT }>
      HCRYPTMSG typedef ptr
      szOID_PKCS_7_DATA equ <"1.2.840.113549.1.7.1">
      szOID_PKCS_7_SIGNED equ <"1.2.840.113549.1.7.2">
      szOID_PKCS_7_ENVELOPED equ <"1.2.840.113549.1.7.3">
      szOID_PKCS_7_SIGNEDANDENVELOPED equ <"1.2.840.113549.1.7.4">
      szOID_PKCS_7_DIGESTED equ <"1.2.840.113549.1.7.5">
      szOID_PKCS_7_ENCRYPTED equ <"1.2.840.113549.1.7.6">
      szOID_PKCS_9_CONTENT_TYPE equ <"1.2.840.113549.1.9.3">
      szOID_PKCS_9_MESSAGE_DIGEST equ <"1.2.840.113549.1.9.4">
      CMSG_DATA equ 1
      CMSG_SIGNED equ 2
      CMSG_ENVELOPED equ 3
      CMSG_SIGNED_AND_ENVELOPED equ 4
      CMSG_HASHED equ 5
      CMSG_ENCRYPTED equ 6
      CMSG_ALL_FLAGS equ (not 0)
      CMSG_DATA_FLAG equ (1 shl CMSG_DATA)
      CMSG_SIGNED_FLAG equ (1 shl CMSG_SIGNED)
      CMSG_ENVELOPED_FLAG equ (1 shl CMSG_ENVELOPED)
      CMSG_SIGNED_AND_ENVELOPED_FLAG equ (1 shl CMSG_SIGNED_AND_ENVELOPED)
      CMSG_HASHED_FLAG equ (1 shl CMSG_HASHED)
      CMSG_ENCRYPTED_FLAG equ (1 shl CMSG_ENCRYPTED)
      CERT_ISSUER_SERIAL_NUMBER struct
        Issuer CERT_NAME_BLOB <>
        SerialNumber CRYPT_INTEGER_BLOB <>
      CERT_ISSUER_SERIAL_NUMBER ends
      _CERT_ISSUER_SERIAL_NUMBER typedef CERT_ISSUER_SERIAL_NUMBER
      PCERT_ISSUER_SERIAL_NUMBER typedef ptr CERT_ISSUER_SERIAL_NUMBER
      CERT_ID struct
        dwIdChoice DWORD ?
        union
          IssuerSerialNumber CERT_ISSUER_SERIAL_NUMBER <>
          KeyId CRYPT_HASH_BLOB <>
          HashId CRYPT_HASH_BLOB <>
        ends
      CERT_ID ends
      _CERT_ID typedef CERT_ID
      PCERT_ID typedef ptr CERT_ID
      CERT_ID_ISSUER_SERIAL_NUMBER equ 1
      CERT_ID_KEY_IDENTIFIER equ 2
      CERT_ID_SHA1_HASH equ 3
      CMSG_SIGNER_ENCODE_INFO struct
        cbSize DWORD ?
        pCertInfo PCERT_INFO ?
        union
          hCryptProv HCRYPTPROV ?
          hNCryptKey NCRYPT_KEY_HANDLE ?
          ifdef CMSG_SIGNER_ENCODE_INFO_HAS_IUM_FIELDS
            hBCryptKey BCRYPT_KEY_HANDLE ?
          endif
        ends
        dwKeySpec DWORD ?
        HashAlgorithm CRYPT_ALGORITHM_IDENTIFIER <>
        pvHashAuxInfo POINTER ?
        cAuthAttr DWORD ?
        rgAuthAttr PCRYPT_ATTRIBUTE ?
        cUnauthAttr DWORD ?
        rgUnauthAttr PCRYPT_ATTRIBUTE ?
        ifdef CMSG_SIGNER_ENCODE_INFO_HAS_CMS_FIELDS
          SignerId CERT_ID <>
          HashEncryptionAlgorithm CRYPT_ALGORITHM_IDENTIFIER <>
          pvHashEncryptionAuxInfo POINTER ?
        endif
      CMSG_SIGNER_ENCODE_INFO ends
      _CMSG_SIGNER_ENCODE_INFO typedef CMSG_SIGNER_ENCODE_INFO
      PCMSG_SIGNER_ENCODE_INFO typedef ptr CMSG_SIGNER_ENCODE_INFO
      CMSG_SIGNED_ENCODE_INFO struct
        cbSize DWORD ?
        cSigners DWORD ?
        rgSigners PCMSG_SIGNER_ENCODE_INFO ?
        cCertEncoded DWORD ?
        rgCertEncoded PCERT_BLOB ?
        cCrlEncoded DWORD ?
        rgCrlEncoded PCRL_BLOB ?
        ifdef CMSG_SIGNED_ENCODE_INFO_HAS_CMS_FIELDS
          cAttrCertEncoded DWORD ?
          rgAttrCertEncoded PCERT_BLOB ?
        endif
      CMSG_SIGNED_ENCODE_INFO ends
      _CMSG_SIGNED_ENCODE_INFO typedef CMSG_SIGNED_ENCODE_INFO
      PCMSG_SIGNED_ENCODE_INFO typedef ptr CMSG_SIGNED_ENCODE_INFO
      CMSG_RECIPIENT_ENCODE_INFO typedef _CMSG_RECIPIENT_ENCODE_INFO
      PCMSG_RECIPIENT_ENCODE_INFO typedef ptr _CMSG_RECIPIENT_ENCODE_INFO
      CMSG_ENVELOPED_ENCODE_INFO struct
        cbSize DWORD ?
        hCryptProv HCRYPTPROV_LEGACY ?
        ContentEncryptionAlgorithm CRYPT_ALGORITHM_IDENTIFIER <>
        pvEncryptionAuxInfo POINTER ?
        cRecipients DWORD ?
        rgpRecipients POINTER ?
        ifdef CMSG_ENVELOPED_ENCODE_INFO_HAS_CMS_FIELDS
          rgCmsRecipients PCMSG_RECIPIENT_ENCODE_INFO ?
          cCertEncoded DWORD ?
          rgCertEncoded PCERT_BLOB ?
          cCrlEncoded DWORD ?
          rgCrlEncoded PCRL_BLOB ?
          cAttrCertEncoded DWORD ?
          rgAttrCertEncoded PCERT_BLOB ?
          cUnprotectedAttr DWORD ?
          rgUnprotectedAttr PCRYPT_ATTRIBUTE ?
        endif
      CMSG_ENVELOPED_ENCODE_INFO ends
      _CMSG_ENVELOPED_ENCODE_INFO typedef CMSG_ENVELOPED_ENCODE_INFO
      PCMSG_ENVELOPED_ENCODE_INFO typedef ptr CMSG_ENVELOPED_ENCODE_INFO
      CMSG_KEY_TRANS_RECIPIENT_ENCODE_INFO struct
        cbSize DWORD ?
        KeyEncryptionAlgorithm CRYPT_ALGORITHM_IDENTIFIER <>
        pvKeyEncryptionAuxInfo POINTER ?
        hCryptProv HCRYPTPROV_LEGACY ?
        RecipientPublicKey CRYPT_BIT_BLOB <>
        RecipientId CERT_ID <>
      CMSG_KEY_TRANS_RECIPIENT_ENCODE_INFO ends
      _CMSG_KEY_TRANS_RECIPIENT_ENCODE_INFO typedef CMSG_KEY_TRANS_RECIPIENT_ENCODE_INFO
      PCMSG_KEY_TRANS_RECIPIENT_ENCODE_INFO typedef ptr CMSG_KEY_TRANS_RECIPIENT_ENCODE_INFO
      CMSG_RECIPIENT_ENCRYPTED_KEY_ENCODE_INFO struct
        cbSize DWORD ?
        RecipientPublicKey CRYPT_BIT_BLOB <>
        RecipientId CERT_ID <>
        Date FILETIME <>
        pOtherAttr PCRYPT_ATTRIBUTE_TYPE_VALUE ?
      CMSG_RECIPIENT_ENCRYPTED_KEY_ENCODE_INFO ends
      _CMSG_RECIPIENT_ENCRYPTED_KEY_ENCODE_INFO typedef CMSG_RECIPIENT_ENCRYPTED_KEY_ENCODE_INFO
      PCMSG_RECIPIENT_ENCRYPTED_KEY_ENCODE_INFO typedef ptr CMSG_RECIPIENT_ENCRYPTED_KEY_ENCODE_INFO
      CMSG_KEY_AGREE_RECIPIENT_ENCODE_INFO struct
        cbSize DWORD ?
        KeyEncryptionAlgorithm CRYPT_ALGORITHM_IDENTIFIER <>
        pvKeyEncryptionAuxInfo POINTER ?
        KeyWrapAlgorithm CRYPT_ALGORITHM_IDENTIFIER <>
        pvKeyWrapAuxInfo POINTER ?
        hCryptProv HCRYPTPROV_LEGACY ?
        dwKeySpec DWORD ?
        dwKeyChoice DWORD ?
        union
          pEphemeralAlgorithm PCRYPT_ALGORITHM_IDENTIFIER ?
          pSenderId PCERT_ID ?
        ends
        UserKeyingMaterial CRYPT_DATA_BLOB <>
        cRecipientEncryptedKeys DWORD ?
        rgpRecipientEncryptedKeys POINTER ?
      CMSG_KEY_AGREE_RECIPIENT_ENCODE_INFO ends
      _CMSG_KEY_AGREE_RECIPIENT_ENCODE_INFO typedef CMSG_KEY_AGREE_RECIPIENT_ENCODE_INFO
      PCMSG_KEY_AGREE_RECIPIENT_ENCODE_INFO typedef ptr CMSG_KEY_AGREE_RECIPIENT_ENCODE_INFO
      CMSG_KEY_AGREE_EPHEMERAL_KEY_CHOICE equ 1
      CMSG_KEY_AGREE_STATIC_KEY_CHOICE equ 2
      CMSG_MAIL_LIST_RECIPIENT_ENCODE_INFO struct
        cbSize DWORD ?
        KeyEncryptionAlgorithm CRYPT_ALGORITHM_IDENTIFIER <>
        pvKeyEncryptionAuxInfo POINTER ?
        hCryptProv HCRYPTPROV ?
        dwKeyChoice DWORD ?
        union
          hKeyEncryptionKey HCRYPTKEY ?
          pvKeyEncryptionKey POINTER ?
        ends
        KeyId CRYPT_DATA_BLOB <>
        Date FILETIME <>
        pOtherAttr PCRYPT_ATTRIBUTE_TYPE_VALUE ?
      CMSG_MAIL_LIST_RECIPIENT_ENCODE_INFO ends
      _CMSG_MAIL_LIST_RECIPIENT_ENCODE_INFO typedef CMSG_MAIL_LIST_RECIPIENT_ENCODE_INFO
      PCMSG_MAIL_LIST_RECIPIENT_ENCODE_INFO typedef ptr CMSG_MAIL_LIST_RECIPIENT_ENCODE_INFO
      CMSG_MAIL_LIST_HANDLE_KEY_CHOICE equ 1
      _CMSG_RECIPIENT_ENCODE_INFO struct
        dwRecipientChoice DWORD ?
        union
          pKeyTrans PCMSG_KEY_TRANS_RECIPIENT_ENCODE_INFO ?
          pKeyAgree PCMSG_KEY_AGREE_RECIPIENT_ENCODE_INFO ?
          pMailList PCMSG_MAIL_LIST_RECIPIENT_ENCODE_INFO ?
        ends
      _CMSG_RECIPIENT_ENCODE_INFO ends
      CMSG_KEY_TRANS_RECIPIENT equ 1
      CMSG_KEY_AGREE_RECIPIENT equ 2
      CMSG_MAIL_LIST_RECIPIENT equ 3
      CMSG_RC2_AUX_INFO struct
        cbSize DWORD ?
        dwBitLen DWORD ?
      CMSG_RC2_AUX_INFO ends
      _CMSG_RC2_AUX_INFO typedef CMSG_RC2_AUX_INFO
      PCMSG_RC2_AUX_INFO typedef ptr CMSG_RC2_AUX_INFO
      CMSG_SP3_COMPATIBLE_AUX_INFO struct
        cbSize DWORD ?
        dwFlags DWORD ?
      CMSG_SP3_COMPATIBLE_AUX_INFO ends
      _CMSG_SP3_COMPATIBLE_AUX_INFO typedef CMSG_SP3_COMPATIBLE_AUX_INFO
      PCMSG_SP3_COMPATIBLE_AUX_INFO typedef ptr CMSG_SP3_COMPATIBLE_AUX_INFO
      CMSG_SP3_COMPATIBLE_ENCRYPT_FLAG equ 80000000h
      CMSG_RC4_AUX_INFO struct
        cbSize DWORD ?
        dwBitLen DWORD ?
      CMSG_RC4_AUX_INFO ends
      _CMSG_RC4_AUX_INFO typedef CMSG_RC4_AUX_INFO
      PCMSG_RC4_AUX_INFO typedef ptr CMSG_RC4_AUX_INFO
      CMSG_RC4_NO_SALT_FLAG equ 40000000h
      CMSG_SIGNED_AND_ENVELOPED_ENCODE_INFO struct
        cbSize DWORD ?
        SignedInfo CMSG_SIGNED_ENCODE_INFO <>
        EnvelopedInfo CMSG_ENVELOPED_ENCODE_INFO <>
      CMSG_SIGNED_AND_ENVELOPED_ENCODE_INFO ends
      _CMSG_SIGNED_AND_ENVELOPED_ENCODE_INFO typedef CMSG_SIGNED_AND_ENVELOPED_ENCODE_INFO
      PCMSG_SIGNED_AND_ENVELOPED_ENCODE_INFO typedef ptr CMSG_SIGNED_AND_ENVELOPED_ENCODE_INFO
      CMSG_HASHED_ENCODE_INFO struct
        cbSize DWORD ?
        hCryptProv HCRYPTPROV_LEGACY ?
        HashAlgorithm CRYPT_ALGORITHM_IDENTIFIER <>
        pvHashAuxInfo POINTER ?
      CMSG_HASHED_ENCODE_INFO ends
      _CMSG_HASHED_ENCODE_INFO typedef CMSG_HASHED_ENCODE_INFO
      PCMSG_HASHED_ENCODE_INFO typedef ptr CMSG_HASHED_ENCODE_INFO
      CMSG_ENCRYPTED_ENCODE_INFO struct
        cbSize DWORD ?
        ContentEncryptionAlgorithm CRYPT_ALGORITHM_IDENTIFIER <>
        pvEncryptionAuxInfo POINTER ?
      CMSG_ENCRYPTED_ENCODE_INFO ends
      _CMSG_ENCRYPTED_ENCODE_INFO typedef CMSG_ENCRYPTED_ENCODE_INFO
      PCMSG_ENCRYPTED_ENCODE_INFO typedef ptr CMSG_ENCRYPTED_ENCODE_INFO
      TYPE_PFN_CMSG_STREAM_OUTPUT typedef proto WIN_STD_CALL_CONV :ptr, :ptr BYTE, :DWORD, :BOOL
      PFN_CMSG_STREAM_OUTPUT typedef ptr TYPE_PFN_CMSG_STREAM_OUTPUT

      CMSG_INDEFINITE_LENGTH equ (0FFFFFFFFh)
      CMSG_STREAM_INFO struct
        cbContent DWORD ?
        pfnStreamOutput PFN_CMSG_STREAM_OUTPUT ?
        pvArg POINTER ?
      CMSG_STREAM_INFO ends
      _CMSG_STREAM_INFO typedef CMSG_STREAM_INFO
      PCMSG_STREAM_INFO typedef ptr CMSG_STREAM_INFO
      CMSG_BARE_CONTENT_FLAG equ 00000001h
      CMSG_LENGTH_ONLY_FLAG equ 00000002h
      CMSG_DETACHED_FLAG equ 00000004h
      CMSG_AUTHENTICATED_ATTRIBUTES_FLAG equ 00000008h
      CMSG_CONTENTS_OCTETS_FLAG equ 00000010h
      CMSG_MAX_LENGTH_FLAG equ 00000020h
      CMSG_CMS_ENCAPSULATED_CONTENT_FLAG equ 00000040h
      CMSG_SIGNED_DATA_NO_SIGN_FLAG equ 00000080h
      CMSG_CRYPT_RELEASE_CONTEXT_FLAG equ 00008000h
      @DefProto DllImport, CryptMsgOpenToEncode, WIN_STD_CALL_CONV,, <:DWORD, :DWORD, :DWORD, :ptr, :LPSTR, :PCMSG_STREAM_INFO>, 24
      @DefProto DllImport, CryptMsgCalculateEncodedLength, WIN_STD_CALL_CONV,, <:DWORD, :DWORD, :DWORD, :ptr, :LPSTR, :DWORD>, 24
      @DefProto DllImport, CryptMsgOpenToDecode, WIN_STD_CALL_CONV,, <:DWORD, :DWORD, :DWORD, :HCRYPTPROV_LEGACY, :PCERT_INFO, :PCMSG_STREAM_INFO>, 24
      @DefProto DllImport, CryptMsgDuplicate, WIN_STD_CALL_CONV,, <:HCRYPTMSG>, 4
      @DefProto DllImport, CryptMsgClose, WIN_STD_CALL_CONV,, <:HCRYPTMSG>, 4
      @DefProto DllImport, CryptMsgUpdate, WIN_STD_CALL_CONV,, <:HCRYPTMSG, :ptr BYTE, :DWORD, :BOOL>, 16
      @DefProto DllImport, CryptMsgGetParam, WIN_STD_CALL_CONV,, <:HCRYPTMSG, :DWORD, :DWORD, :ptr, :ptr DWORD>, 20
      CMSG_TYPE_PARAM equ 1
      CMSG_CONTENT_PARAM equ 2
      CMSG_BARE_CONTENT_PARAM equ 3
      CMSG_INNER_CONTENT_TYPE_PARAM equ 4
      CMSG_SIGNER_COUNT_PARAM equ 5
      CMSG_SIGNER_INFO_PARAM equ 6
      CMSG_SIGNER_CERT_INFO_PARAM equ 7
      CMSG_SIGNER_HASH_ALGORITHM_PARAM equ 8
      CMSG_SIGNER_AUTH_ATTR_PARAM equ 9
      CMSG_SIGNER_UNAUTH_ATTR_PARAM equ 10
      CMSG_CERT_COUNT_PARAM equ 11
      CMSG_CERT_PARAM equ 12
      CMSG_CRL_COUNT_PARAM equ 13
      CMSG_CRL_PARAM equ 14
      CMSG_ENVELOPE_ALGORITHM_PARAM equ 15
      CMSG_RECIPIENT_COUNT_PARAM equ 17
      CMSG_RECIPIENT_INDEX_PARAM equ 18
      CMSG_RECIPIENT_INFO_PARAM equ 19
      CMSG_HASH_ALGORITHM_PARAM equ 20
      CMSG_HASH_DATA_PARAM equ 21
      CMSG_COMPUTED_HASH_PARAM equ 22
      CMSG_ENCRYPT_PARAM equ 26
      CMSG_ENCRYPTED_DIGEST equ 27
      CMSG_ENCODED_SIGNER equ 28
      CMSG_ENCODED_MESSAGE equ 29
      CMSG_VERSION_PARAM equ 30
      CMSG_ATTR_CERT_COUNT_PARAM equ 31
      CMSG_ATTR_CERT_PARAM equ 32
      CMSG_CMS_RECIPIENT_COUNT_PARAM equ 33
      CMSG_CMS_RECIPIENT_INDEX_PARAM equ 34
      CMSG_CMS_RECIPIENT_ENCRYPTED_KEY_INDEX_PARAM equ 35
      CMSG_CMS_RECIPIENT_INFO_PARAM equ 36
      CMSG_UNPROTECTED_ATTR_PARAM equ 37
      CMSG_SIGNER_CERT_ID_PARAM equ 38
      CMSG_CMS_SIGNER_INFO_PARAM equ 39
      CMSG_SIGNER_INFO struct
        dwVersion DWORD ?
        Issuer CERT_NAME_BLOB <>
        SerialNumber CRYPT_INTEGER_BLOB <>
        HashAlgorithm CRYPT_ALGORITHM_IDENTIFIER <>
        HashEncryptionAlgorithm CRYPT_ALGORITHM_IDENTIFIER <>
        EncryptedHash CRYPT_DATA_BLOB <>
        AuthAttrs CRYPT_ATTRIBUTES <>
        UnauthAttrs CRYPT_ATTRIBUTES <>
      CMSG_SIGNER_INFO ends
      _CMSG_SIGNER_INFO typedef CMSG_SIGNER_INFO
      PCMSG_SIGNER_INFO typedef ptr CMSG_SIGNER_INFO
      CMSG_CMS_SIGNER_INFO struct
        dwVersion DWORD ?
        SignerId CERT_ID <>
        HashAlgorithm CRYPT_ALGORITHM_IDENTIFIER <>
        HashEncryptionAlgorithm CRYPT_ALGORITHM_IDENTIFIER <>
        EncryptedHash CRYPT_DATA_BLOB <>
        AuthAttrs CRYPT_ATTRIBUTES <>
        UnauthAttrs CRYPT_ATTRIBUTES <>
      CMSG_CMS_SIGNER_INFO ends
      _CMSG_CMS_SIGNER_INFO typedef CMSG_CMS_SIGNER_INFO
      PCMSG_CMS_SIGNER_INFO typedef ptr CMSG_CMS_SIGNER_INFO
      CMSG_ATTR typedef CRYPT_ATTRIBUTES
      PCMSG_ATTR typedef ptr CRYPT_ATTRIBUTES
      CMSG_SIGNED_DATA_V1 equ 1
      CMSG_SIGNED_DATA_V3 equ 3
      CMSG_SIGNED_DATA_PKCS_1_5_VERSION equ <CMSG_SIGNED_DATA_V1>
      CMSG_SIGNED_DATA_CMS_VERSION equ <CMSG_SIGNED_DATA_V3>
      CMSG_SIGNER_INFO_V1 equ 1
      CMSG_SIGNER_INFO_V3 equ 3
      CMSG_SIGNER_INFO_PKCS_1_5_VERSION equ <CMSG_SIGNER_INFO_V1>
      CMSG_SIGNER_INFO_CMS_VERSION equ <CMSG_SIGNER_INFO_V3>
      CMSG_HASHED_DATA_V0 equ 0
      CMSG_HASHED_DATA_V2 equ 2
      CMSG_HASHED_DATA_PKCS_1_5_VERSION equ <CMSG_HASHED_DATA_V0>
      CMSG_HASHED_DATA_CMS_VERSION equ <CMSG_HASHED_DATA_V2>
      CMSG_ENVELOPED_DATA_V0 equ 0
      CMSG_ENVELOPED_DATA_V2 equ 2
      CMSG_ENVELOPED_DATA_PKCS_1_5_VERSION equ <CMSG_ENVELOPED_DATA_V0>
      CMSG_ENVELOPED_DATA_CMS_VERSION equ <CMSG_ENVELOPED_DATA_V2>
      CMSG_KEY_TRANS_RECIPIENT_INFO struct
        dwVersion DWORD ?
        RecipientId CERT_ID <>
        KeyEncryptionAlgorithm CRYPT_ALGORITHM_IDENTIFIER <>
        EncryptedKey CRYPT_DATA_BLOB <>
      CMSG_KEY_TRANS_RECIPIENT_INFO ends
      _CMSG_KEY_TRANS_RECIPIENT_INFO typedef CMSG_KEY_TRANS_RECIPIENT_INFO
      PCMSG_KEY_TRANS_RECIPIENT_INFO typedef ptr CMSG_KEY_TRANS_RECIPIENT_INFO
      CMSG_RECIPIENT_ENCRYPTED_KEY_INFO struct
        RecipientId CERT_ID <>
        EncryptedKey CRYPT_DATA_BLOB <>
        Date FILETIME <>
        pOtherAttr PCRYPT_ATTRIBUTE_TYPE_VALUE ?
      CMSG_RECIPIENT_ENCRYPTED_KEY_INFO ends
      _CMSG_RECIPIENT_ENCRYPTED_KEY_INFO typedef CMSG_RECIPIENT_ENCRYPTED_KEY_INFO
      PCMSG_RECIPIENT_ENCRYPTED_KEY_INFO typedef ptr CMSG_RECIPIENT_ENCRYPTED_KEY_INFO
      CMSG_KEY_AGREE_RECIPIENT_INFO struct
        dwVersion DWORD ?
        dwOriginatorChoice DWORD ?
        union
          OriginatorCertId CERT_ID <>
          OriginatorPublicKeyInfo CERT_PUBLIC_KEY_INFO <>
        ends
        UserKeyingMaterial CRYPT_DATA_BLOB <>
        KeyEncryptionAlgorithm CRYPT_ALGORITHM_IDENTIFIER <>
        cRecipientEncryptedKeys DWORD ?
        rgpRecipientEncryptedKeys POINTER ?
      CMSG_KEY_AGREE_RECIPIENT_INFO ends
      _CMSG_KEY_AGREE_RECIPIENT_INFO typedef CMSG_KEY_AGREE_RECIPIENT_INFO
      PCMSG_KEY_AGREE_RECIPIENT_INFO typedef ptr CMSG_KEY_AGREE_RECIPIENT_INFO
      CMSG_KEY_AGREE_ORIGINATOR_CERT equ 1
      CMSG_KEY_AGREE_ORIGINATOR_PUBLIC_KEY equ 2
      CMSG_MAIL_LIST_RECIPIENT_INFO struct
        dwVersion DWORD ?
        KeyId CRYPT_DATA_BLOB <>
        KeyEncryptionAlgorithm CRYPT_ALGORITHM_IDENTIFIER <>
        EncryptedKey CRYPT_DATA_BLOB <>
        Date FILETIME <>
        pOtherAttr PCRYPT_ATTRIBUTE_TYPE_VALUE ?
      CMSG_MAIL_LIST_RECIPIENT_INFO ends
      _CMSG_MAIL_LIST_RECIPIENT_INFO typedef CMSG_MAIL_LIST_RECIPIENT_INFO
      PCMSG_MAIL_LIST_RECIPIENT_INFO typedef ptr CMSG_MAIL_LIST_RECIPIENT_INFO
      CMSG_CMS_RECIPIENT_INFO struct
        dwRecipientChoice DWORD ?
        union
          pKeyTrans PCMSG_KEY_TRANS_RECIPIENT_INFO ?
          pKeyAgree PCMSG_KEY_AGREE_RECIPIENT_INFO ?
          pMailList PCMSG_MAIL_LIST_RECIPIENT_INFO ?
        ends
      CMSG_CMS_RECIPIENT_INFO ends
      _CMSG_CMS_RECIPIENT_INFO typedef CMSG_CMS_RECIPIENT_INFO
      PCMSG_CMS_RECIPIENT_INFO typedef ptr CMSG_CMS_RECIPIENT_INFO
      CMSG_ENVELOPED_RECIPIENT_V0 equ 0
      CMSG_ENVELOPED_RECIPIENT_V2 equ 2
      CMSG_ENVELOPED_RECIPIENT_V3 equ 3
      CMSG_ENVELOPED_RECIPIENT_V4 equ 4
      CMSG_KEY_TRANS_PKCS_1_5_VERSION equ <CMSG_ENVELOPED_RECIPIENT_V0>
      CMSG_KEY_TRANS_CMS_VERSION equ <CMSG_ENVELOPED_RECIPIENT_V2>
      CMSG_KEY_AGREE_VERSION equ <CMSG_ENVELOPED_RECIPIENT_V3>
      CMSG_MAIL_LIST_VERSION equ <CMSG_ENVELOPED_RECIPIENT_V4>
      @DefProto DllImport, CryptMsgControl, WIN_STD_CALL_CONV,, <:HCRYPTMSG, :DWORD, :DWORD, :ptr>, 16
      CMSG_CTRL_VERIFY_SIGNATURE equ 1
      CMSG_CTRL_DECRYPT equ 2
      CMSG_CTRL_VERIFY_HASH equ 5
      CMSG_CTRL_ADD_SIGNER equ 6
      CMSG_CTRL_DEL_SIGNER equ 7
      CMSG_CTRL_ADD_SIGNER_UNAUTH_ATTR equ 8
      CMSG_CTRL_DEL_SIGNER_UNAUTH_ATTR equ 9
      CMSG_CTRL_ADD_CERT equ 10
      CMSG_CTRL_DEL_CERT equ 11
      CMSG_CTRL_ADD_CRL equ 12
      CMSG_CTRL_DEL_CRL equ 13
      CMSG_CTRL_ADD_ATTR_CERT equ 14
      CMSG_CTRL_DEL_ATTR_CERT equ 15
      CMSG_CTRL_KEY_TRANS_DECRYPT equ 16
      CMSG_CTRL_KEY_AGREE_DECRYPT equ 17
      CMSG_CTRL_MAIL_LIST_DECRYPT equ 18
      CMSG_CTRL_VERIFY_SIGNATURE_EX equ 19
      CMSG_CTRL_ADD_CMS_SIGNER_INFO equ 20
      CMSG_CTRL_ENABLE_STRONG_SIGNATURE equ 21
      CMSG_CTRL_VERIFY_SIGNATURE_EX_PARA struct
        cbSize DWORD ?
        hCryptProv HCRYPTPROV_LEGACY ?
        dwSignerIndex DWORD ?
        dwSignerType DWORD ?
        pvSigner POINTER ?
      CMSG_CTRL_VERIFY_SIGNATURE_EX_PARA ends
      _CMSG_CTRL_VERIFY_SIGNATURE_EX_PARA typedef CMSG_CTRL_VERIFY_SIGNATURE_EX_PARA
      PCMSG_CTRL_VERIFY_SIGNATURE_EX_PARA typedef ptr CMSG_CTRL_VERIFY_SIGNATURE_EX_PARA
      CMSG_VERIFY_SIGNER_PUBKEY equ 1
      CMSG_VERIFY_SIGNER_CERT equ 2
      CMSG_VERIFY_SIGNER_CHAIN equ 3
      CMSG_VERIFY_SIGNER_NULL equ 4
      CMSG_CTRL_DECRYPT_PARA struct
        cbSize DWORD ?
        union
          hCryptProv HCRYPTPROV ?
          hNCryptKey NCRYPT_KEY_HANDLE ?
        ends
        dwKeySpec DWORD ?
        dwRecipientIndex DWORD ?
      CMSG_CTRL_DECRYPT_PARA ends
      _CMSG_CTRL_DECRYPT_PARA typedef CMSG_CTRL_DECRYPT_PARA
      PCMSG_CTRL_DECRYPT_PARA typedef ptr CMSG_CTRL_DECRYPT_PARA
      CMSG_CTRL_KEY_TRANS_DECRYPT_PARA struct
        cbSize DWORD ?
        union
          hCryptProv HCRYPTPROV ?
          hNCryptKey NCRYPT_KEY_HANDLE ?
        ends
        dwKeySpec DWORD ?
        pKeyTrans PCMSG_KEY_TRANS_RECIPIENT_INFO ?
        dwRecipientIndex DWORD ?
      CMSG_CTRL_KEY_TRANS_DECRYPT_PARA ends
      _CMSG_CTRL_KEY_TRANS_DECRYPT_PARA typedef CMSG_CTRL_KEY_TRANS_DECRYPT_PARA
      PCMSG_CTRL_KEY_TRANS_DECRYPT_PARA typedef ptr CMSG_CTRL_KEY_TRANS_DECRYPT_PARA
      CMSG_CTRL_KEY_AGREE_DECRYPT_PARA struct
        cbSize DWORD ?
        union
          hCryptProv HCRYPTPROV ?
          hNCryptKey NCRYPT_KEY_HANDLE ?
        ends
        dwKeySpec DWORD ?
        pKeyAgree PCMSG_KEY_AGREE_RECIPIENT_INFO ?
        dwRecipientIndex DWORD ?
        dwRecipientEncryptedKeyIndex DWORD ?
        OriginatorPublicKey CRYPT_BIT_BLOB <>
      CMSG_CTRL_KEY_AGREE_DECRYPT_PARA ends
      _CMSG_CTRL_KEY_AGREE_DECRYPT_PARA typedef CMSG_CTRL_KEY_AGREE_DECRYPT_PARA
      PCMSG_CTRL_KEY_AGREE_DECRYPT_PARA typedef ptr CMSG_CTRL_KEY_AGREE_DECRYPT_PARA
      CMSG_CTRL_MAIL_LIST_DECRYPT_PARA struct
        cbSize DWORD ?
        hCryptProv HCRYPTPROV ?
        pMailList PCMSG_MAIL_LIST_RECIPIENT_INFO ?
        dwRecipientIndex DWORD ?
        dwKeyChoice DWORD ?
        union
          hKeyEncryptionKey HCRYPTKEY ?
          pvKeyEncryptionKey POINTER ?
        ends
      CMSG_CTRL_MAIL_LIST_DECRYPT_PARA ends
      _CMSG_CTRL_MAIL_LIST_DECRYPT_PARA typedef CMSG_CTRL_MAIL_LIST_DECRYPT_PARA
      PCMSG_CTRL_MAIL_LIST_DECRYPT_PARA typedef ptr CMSG_CTRL_MAIL_LIST_DECRYPT_PARA
      CMSG_CTRL_ADD_SIGNER_UNAUTH_ATTR_PARA struct
        cbSize DWORD ?
        dwSignerIndex DWORD ?
        blob CRYPT_DATA_BLOB <>
      CMSG_CTRL_ADD_SIGNER_UNAUTH_ATTR_PARA ends
      _CMSG_CTRL_ADD_SIGNER_UNAUTH_ATTR_PARA typedef CMSG_CTRL_ADD_SIGNER_UNAUTH_ATTR_PARA
      PCMSG_CTRL_ADD_SIGNER_UNAUTH_ATTR_PARA typedef ptr CMSG_CTRL_ADD_SIGNER_UNAUTH_ATTR_PARA
      CMSG_CTRL_DEL_SIGNER_UNAUTH_ATTR_PARA struct
        cbSize DWORD ?
        dwSignerIndex DWORD ?
        dwUnauthAttrIndex DWORD ?
      CMSG_CTRL_DEL_SIGNER_UNAUTH_ATTR_PARA ends
      _CMSG_CTRL_DEL_SIGNER_UNAUTH_ATTR_PARA typedef CMSG_CTRL_DEL_SIGNER_UNAUTH_ATTR_PARA
      PCMSG_CTRL_DEL_SIGNER_UNAUTH_ATTR_PARA typedef ptr CMSG_CTRL_DEL_SIGNER_UNAUTH_ATTR_PARA
      CryptMsgVerifyCountersignatureEncoded proto WIN_STD_CALL_CONV :HCRYPTPROV_LEGACY, :DWORD, :PBYTE, :DWORD, :PBYTE, :DWORD, :PCERT_INFO
      CryptMsgVerifyCountersignatureEncodedEx proto WIN_STD_CALL_CONV :HCRYPTPROV_LEGACY, :DWORD, :PBYTE, :DWORD, :PBYTE, :DWORD, :DWORD, :ptr, :DWORD, :ptr
      CMSG_VERIFY_COUNTER_SIGN_ENABLE_STRONG_FLAG equ 00000001h
      CryptMsgCountersign proto WIN_STD_CALL_CONV :HCRYPTMSG, :DWORD, :DWORD, :PCMSG_SIGNER_ENCODE_INFO
      CryptMsgCountersignEncoded proto WIN_STD_CALL_CONV :DWORD, :PBYTE, :DWORD, :DWORD, :PCMSG_SIGNER_ENCODE_INFO, :PBYTE, :PDWORD
      TYPE_PFN_CMSG_ALLOC typedef proto WIN_STD_CALL_CONV :size_t
      PFN_CMSG_ALLOC typedef ptr TYPE_PFN_CMSG_ALLOC

      TYPE_PFN_CMSG_FREE typedef proto WIN_STD_CALL_CONV :ptr
      PFN_CMSG_FREE typedef ptr TYPE_PFN_CMSG_FREE

      CMSG_OID_GEN_ENCRYPT_KEY_FUNC equ <"CryptMsgDllGenEncryptKey">
      TYPE_PFN_CMSG_GEN_ENCRYPT_KEY typedef proto WIN_STD_CALL_CONV :ptr HCRYPTPROV, :PCRYPT_ALGORITHM_IDENTIFIER, :PVOID, :PCERT_PUBLIC_KEY_INFO, :PFN_CMSG_ALLOC, :ptr HCRYPTKEY, :ptr PBYTE, :PDWORD
      PFN_CMSG_GEN_ENCRYPT_KEY typedef ptr TYPE_PFN_CMSG_GEN_ENCRYPT_KEY

      CMSG_OID_EXPORT_ENCRYPT_KEY_FUNC equ <"CryptMsgDllExportEncryptKey">
      TYPE_PFN_CMSG_EXPORT_ENCRYPT_KEY typedef proto WIN_STD_CALL_CONV :HCRYPTPROV, :HCRYPTKEY, :PCERT_PUBLIC_KEY_INFO, :PBYTE, :PDWORD
      PFN_CMSG_EXPORT_ENCRYPT_KEY typedef ptr TYPE_PFN_CMSG_EXPORT_ENCRYPT_KEY

      CMSG_OID_IMPORT_ENCRYPT_KEY_FUNC equ <"CryptMsgDllImportEncryptKey">
      TYPE_PFN_CMSG_IMPORT_ENCRYPT_KEY typedef proto WIN_STD_CALL_CONV :HCRYPTPROV, :DWORD, :PCRYPT_ALGORITHM_IDENTIFIER, :PCRYPT_ALGORITHM_IDENTIFIER, :PBYTE, :DWORD, :ptr HCRYPTKEY
      PFN_CMSG_IMPORT_ENCRYPT_KEY typedef ptr TYPE_PFN_CMSG_IMPORT_ENCRYPT_KEY

      CMSG_DEFAULT_INSTALLABLE_FUNC_OID equ (1)
      CMSG_CONTENT_ENCRYPT_INFO struct
        cbSize DWORD ?
        hCryptProv HCRYPTPROV_LEGACY ?
        ContentEncryptionAlgorithm CRYPT_ALGORITHM_IDENTIFIER <>
        pvEncryptionAuxInfo POINTER ?
        cRecipients DWORD ?
        rgCmsRecipients PCMSG_RECIPIENT_ENCODE_INFO ?
        pfnAlloc PFN_CMSG_ALLOC ?
        pfnFree PFN_CMSG_FREE ?
        dwEncryptFlags DWORD ?
        union
          hContentEncryptKey HCRYPTKEY ?
          hCNGContentEncryptKey BCRYPT_KEY_HANDLE ?
        ends
        dwFlags DWORD ?
        fCNG BOOL ?
        pbCNGContentEncryptKeyObject POINTER ?
        pbContentEncryptKey POINTER ?
        cbContentEncryptKey DWORD ?
      CMSG_CONTENT_ENCRYPT_INFO ends
      _CMSG_CONTENT_ENCRYPT_INFO typedef CMSG_CONTENT_ENCRYPT_INFO
      PCMSG_CONTENT_ENCRYPT_INFO typedef ptr CMSG_CONTENT_ENCRYPT_INFO
      CMSG_CONTENT_ENCRYPT_PAD_ENCODED_LEN_FLAG equ 00000001h
      CMSG_CONTENT_ENCRYPT_FREE_PARA_FLAG equ 00000001h
      CMSG_CONTENT_ENCRYPT_FREE_OBJID_FLAG equ 00000002h
      CMSG_CONTENT_ENCRYPT_RELEASE_CONTEXT_FLAG equ 00008000h
      CMSG_OID_GEN_CONTENT_ENCRYPT_KEY_FUNC equ <"CryptMsgDllGenContentEncryptKey">
      CMSG_OID_CAPI1_GEN_CONTENT_ENCRYPT_KEY_FUNC equ <CMSG_OID_GEN_CONTENT_ENCRYPT_KEY_FUNC>
      TYPE_PFN_CMSG_GEN_CONTENT_ENCRYPT_KEY typedef proto WIN_STD_CALL_CONV :PCMSG_CONTENT_ENCRYPT_INFO, :DWORD, :ptr
      PFN_CMSG_GEN_CONTENT_ENCRYPT_KEY typedef ptr TYPE_PFN_CMSG_GEN_CONTENT_ENCRYPT_KEY

      CMSG_OID_CNG_GEN_CONTENT_ENCRYPT_KEY_FUNC equ <"CryptMsgDllCNGGenContentEncryptKey">
      CMSG_KEY_TRANS_ENCRYPT_INFO struct
        cbSize DWORD ?
        dwRecipientIndex DWORD ?
        KeyEncryptionAlgorithm CRYPT_ALGORITHM_IDENTIFIER <>
        EncryptedKey CRYPT_DATA_BLOB <>
        dwFlags DWORD ?
      CMSG_KEY_TRANS_ENCRYPT_INFO ends
      _CMSG_KEY_TRANS_ENCRYPT_INFO typedef CMSG_KEY_TRANS_ENCRYPT_INFO
      PCMSG_KEY_TRANS_ENCRYPT_INFO typedef ptr CMSG_KEY_TRANS_ENCRYPT_INFO
      CMSG_KEY_TRANS_ENCRYPT_FREE_PARA_FLAG equ 00000001h
      CMSG_KEY_TRANS_ENCRYPT_FREE_OBJID_FLAG equ 00000002h
      CMSG_OID_EXPORT_KEY_TRANS_FUNC equ <"CryptMsgDllExportKeyTrans">
      CMSG_OID_CAPI1_EXPORT_KEY_TRANS_FUNC equ <CMSG_OID_EXPORT_KEY_TRANS_FUNC>
      TYPE_PFN_CMSG_EXPORT_KEY_TRANS typedef proto WIN_STD_CALL_CONV :PCMSG_CONTENT_ENCRYPT_INFO, :PCMSG_KEY_TRANS_RECIPIENT_ENCODE_INFO, :PCMSG_KEY_TRANS_ENCRYPT_INFO, :DWORD, :ptr
      PFN_CMSG_EXPORT_KEY_TRANS typedef ptr TYPE_PFN_CMSG_EXPORT_KEY_TRANS

      CMSG_OID_CNG_EXPORT_KEY_TRANS_FUNC equ <"CryptMsgDllCNGExportKeyTrans">
      CMSG_KEY_AGREE_KEY_ENCRYPT_INFO struct
        cbSize DWORD ?
        EncryptedKey CRYPT_DATA_BLOB <>
      CMSG_KEY_AGREE_KEY_ENCRYPT_INFO ends
      _CMSG_KEY_AGREE_KEY_ENCRYPT_INFO typedef CMSG_KEY_AGREE_KEY_ENCRYPT_INFO
      PCMSG_KEY_AGREE_KEY_ENCRYPT_INFO typedef ptr CMSG_KEY_AGREE_KEY_ENCRYPT_INFO
      CMSG_KEY_AGREE_ENCRYPT_INFO struct
        cbSize DWORD ?
        dwRecipientIndex DWORD ?
        KeyEncryptionAlgorithm CRYPT_ALGORITHM_IDENTIFIER <>
        UserKeyingMaterial CRYPT_DATA_BLOB <>
        dwOriginatorChoice DWORD ?
        union
          OriginatorCertId CERT_ID <>
          OriginatorPublicKeyInfo CERT_PUBLIC_KEY_INFO <>
        ends
        cKeyAgreeKeyEncryptInfo DWORD ?
        rgpKeyAgreeKeyEncryptInfo POINTER ?
        dwFlags DWORD ?
      CMSG_KEY_AGREE_ENCRYPT_INFO ends
      _CMSG_KEY_AGREE_ENCRYPT_INFO typedef CMSG_KEY_AGREE_ENCRYPT_INFO
      PCMSG_KEY_AGREE_ENCRYPT_INFO typedef ptr CMSG_KEY_AGREE_ENCRYPT_INFO
      CMSG_KEY_AGREE_ENCRYPT_FREE_PARA_FLAG equ 00000001h
      CMSG_KEY_AGREE_ENCRYPT_FREE_MATERIAL_FLAG equ 00000002h
      CMSG_KEY_AGREE_ENCRYPT_FREE_PUBKEY_ALG_FLAG equ 00000004h
      CMSG_KEY_AGREE_ENCRYPT_FREE_PUBKEY_PARA_FLAG equ 00000008h
      CMSG_KEY_AGREE_ENCRYPT_FREE_PUBKEY_BITS_FLAG equ 00000010h
      CMSG_KEY_AGREE_ENCRYPT_FREE_OBJID_FLAG equ 00000020h
      CMSG_OID_EXPORT_KEY_AGREE_FUNC equ <"CryptMsgDllExportKeyAgree">
      CMSG_OID_CAPI1_EXPORT_KEY_AGREE_FUNC equ <CMSG_OID_EXPORT_KEY_AGREE_FUNC>
      TYPE_PFN_CMSG_EXPORT_KEY_AGREE typedef proto WIN_STD_CALL_CONV :PCMSG_CONTENT_ENCRYPT_INFO, :PCMSG_KEY_AGREE_RECIPIENT_ENCODE_INFO, :PCMSG_KEY_AGREE_ENCRYPT_INFO, :DWORD, :ptr
      PFN_CMSG_EXPORT_KEY_AGREE typedef ptr TYPE_PFN_CMSG_EXPORT_KEY_AGREE

      CMSG_OID_CNG_EXPORT_KEY_AGREE_FUNC equ <"CryptMsgDllCNGExportKeyAgree">
      CMSG_MAIL_LIST_ENCRYPT_INFO struct
        cbSize DWORD ?
        dwRecipientIndex DWORD ?
        KeyEncryptionAlgorithm CRYPT_ALGORITHM_IDENTIFIER <>
        EncryptedKey CRYPT_DATA_BLOB <>
        dwFlags DWORD ?
      CMSG_MAIL_LIST_ENCRYPT_INFO ends
      _CMSG_MAIL_LIST_ENCRYPT_INFO typedef CMSG_MAIL_LIST_ENCRYPT_INFO
      PCMSG_MAIL_LIST_ENCRYPT_INFO typedef ptr CMSG_MAIL_LIST_ENCRYPT_INFO
      CMSG_MAIL_LIST_ENCRYPT_FREE_PARA_FLAG equ 00000001h
      CMSG_MAIL_LIST_ENCRYPT_FREE_OBJID_FLAG equ 00000002h
      CMSG_OID_EXPORT_MAIL_LIST_FUNC equ <"CryptMsgDllExportMailList">
      CMSG_OID_CAPI1_EXPORT_MAIL_LIST_FUNC equ <CMSG_OID_EXPORT_MAIL_LIST_FUNC>
      TYPE_PFN_CMSG_EXPORT_MAIL_LIST typedef proto WIN_STD_CALL_CONV :PCMSG_CONTENT_ENCRYPT_INFO, :PCMSG_MAIL_LIST_RECIPIENT_ENCODE_INFO, :PCMSG_MAIL_LIST_ENCRYPT_INFO, :DWORD, :ptr
      PFN_CMSG_EXPORT_MAIL_LIST typedef ptr TYPE_PFN_CMSG_EXPORT_MAIL_LIST

      CMSG_OID_IMPORT_KEY_TRANS_FUNC equ <"CryptMsgDllImportKeyTrans">
      CMSG_OID_CAPI1_IMPORT_KEY_TRANS_FUNC equ <CMSG_OID_IMPORT_KEY_TRANS_FUNC>
      TYPE_PFN_CMSG_IMPORT_KEY_TRANS typedef proto WIN_STD_CALL_CONV :PCRYPT_ALGORITHM_IDENTIFIER, :PCMSG_CTRL_KEY_TRANS_DECRYPT_PARA, :DWORD, :ptr, :ptr HCRYPTKEY
      PFN_CMSG_IMPORT_KEY_TRANS typedef ptr TYPE_PFN_CMSG_IMPORT_KEY_TRANS

      CMSG_OID_IMPORT_KEY_AGREE_FUNC equ <"CryptMsgDllImportKeyAgree">
      CMSG_OID_CAPI1_IMPORT_KEY_AGREE_FUNC equ <CMSG_OID_IMPORT_KEY_AGREE_FUNC>
      TYPE_PFN_CMSG_IMPORT_KEY_AGREE typedef proto WIN_STD_CALL_CONV :PCRYPT_ALGORITHM_IDENTIFIER, :PCMSG_CTRL_KEY_AGREE_DECRYPT_PARA, :DWORD, :ptr, :ptr HCRYPTKEY
      PFN_CMSG_IMPORT_KEY_AGREE typedef ptr TYPE_PFN_CMSG_IMPORT_KEY_AGREE

      CMSG_OID_IMPORT_MAIL_LIST_FUNC equ <"CryptMsgDllImportMailList">
      CMSG_OID_CAPI1_IMPORT_MAIL_LIST_FUNC equ <CMSG_OID_IMPORT_MAIL_LIST_FUNC>
      TYPE_PFN_CMSG_IMPORT_MAIL_LIST typedef proto WIN_STD_CALL_CONV :PCRYPT_ALGORITHM_IDENTIFIER, :PCMSG_CTRL_MAIL_LIST_DECRYPT_PARA, :DWORD, :ptr, :ptr HCRYPTKEY
      PFN_CMSG_IMPORT_MAIL_LIST typedef ptr TYPE_PFN_CMSG_IMPORT_MAIL_LIST

      CMSG_CNG_CONTENT_DECRYPT_INFO struct
        cbSize DWORD ?
        ContentEncryptionAlgorithm CRYPT_ALGORITHM_IDENTIFIER <>
        pfnAlloc PFN_CMSG_ALLOC ?
        pfnFree PFN_CMSG_FREE ?
        hNCryptKey NCRYPT_KEY_HANDLE ?
        pbContentEncryptKey POINTER ?
        cbContentEncryptKey DWORD ?
        hCNGContentEncryptKey BCRYPT_KEY_HANDLE ?
        pbCNGContentEncryptKeyObject POINTER ?
      CMSG_CNG_CONTENT_DECRYPT_INFO ends
      _CMSG_CNG_CONTENT_DECRYPT_INFO typedef CMSG_CNG_CONTENT_DECRYPT_INFO
      PCMSG_CNG_CONTENT_DECRYPT_INFO typedef ptr CMSG_CNG_CONTENT_DECRYPT_INFO
      CMSG_OID_CNG_IMPORT_KEY_TRANS_FUNC equ <"CryptMsgDllCNGImportKeyTrans">
      TYPE_PFN_CMSG_CNG_IMPORT_KEY_TRANS typedef proto WIN_STD_CALL_CONV :PCMSG_CNG_CONTENT_DECRYPT_INFO, :PCMSG_CTRL_KEY_TRANS_DECRYPT_PARA, :DWORD, :ptr
      PFN_CMSG_CNG_IMPORT_KEY_TRANS typedef ptr TYPE_PFN_CMSG_CNG_IMPORT_KEY_TRANS

      CMSG_OID_CNG_IMPORT_KEY_AGREE_FUNC equ <"CryptMsgDllCNGImportKeyAgree">
      TYPE_PFN_CMSG_CNG_IMPORT_KEY_AGREE typedef proto WIN_STD_CALL_CONV :PCMSG_CNG_CONTENT_DECRYPT_INFO, :PCMSG_CTRL_KEY_AGREE_DECRYPT_PARA, :DWORD, :ptr
      PFN_CMSG_CNG_IMPORT_KEY_AGREE typedef ptr TYPE_PFN_CMSG_CNG_IMPORT_KEY_AGREE

      CMSG_OID_CNG_IMPORT_CONTENT_ENCRYPT_KEY_FUNC equ <"CryptMsgDllCNGImportContentEncryptKey">
      TYPE_PFN_CMSG_CNG_IMPORT_CONTENT_ENCRYPT_KEY typedef proto WIN_STD_CALL_CONV :PCMSG_CNG_CONTENT_DECRYPT_INFO, :DWORD, :ptr
      PFN_CMSG_CNG_IMPORT_CONTENT_ENCRYPT_KEY typedef ptr TYPE_PFN_CMSG_CNG_IMPORT_CONTENT_ENCRYPT_KEY

      HCERTSTORE typedef ptr
      CERT_CONTEXT struct
        dwCertEncodingType DWORD ?
        pbCertEncoded POINTER ?
        cbCertEncoded DWORD ?
        pCertInfo PCERT_INFO ?
        hCertStore HCERTSTORE ?
      CERT_CONTEXT ends
      _CERT_CONTEXT typedef CERT_CONTEXT
      PCERT_CONTEXT typedef ptr CERT_CONTEXT
      PCCERT_CONTEXT typedef ptr CERT_CONTEXT
      CRL_CONTEXT struct
        dwCertEncodingType DWORD ?
        pbCrlEncoded POINTER ?
        cbCrlEncoded DWORD ?
        pCrlInfo PCRL_INFO ?
        hCertStore HCERTSTORE ?
      CRL_CONTEXT ends
      _CRL_CONTEXT typedef CRL_CONTEXT
      PCRL_CONTEXT typedef ptr CRL_CONTEXT
      PCCRL_CONTEXT typedef ptr CRL_CONTEXT
      CTL_CONTEXT struct
        dwMsgAndCertEncodingType DWORD ?
        pbCtlEncoded POINTER ?
        cbCtlEncoded DWORD ?
        pCtlInfo PCTL_INFO ?
        hCertStore HCERTSTORE ?
        hCryptMsg HCRYPTMSG ?
        pbCtlContent POINTER ?
        cbCtlContent DWORD ?
      CTL_CONTEXT ends
      _CTL_CONTEXT typedef CTL_CONTEXT
      PCTL_CONTEXT typedef ptr CTL_CONTEXT
      PCCTL_CONTEXT typedef ptr CTL_CONTEXT
      CERT_KEY_PROV_HANDLE_PROP_ID equ 1
      CERT_KEY_PROV_INFO_PROP_ID equ 2
      CERT_SHA1_HASH_PROP_ID equ 3
      CERT_MD5_HASH_PROP_ID equ 4
      CERT_HASH_PROP_ID equ <CERT_SHA1_HASH_PROP_ID>
      CERT_KEY_CONTEXT_PROP_ID equ 5
      CERT_KEY_SPEC_PROP_ID equ 6
      CERT_IE30_RESERVED_PROP_ID equ 7
      CERT_PUBKEY_HASH_RESERVED_PROP_ID equ 8
      CERT_ENHKEY_USAGE_PROP_ID equ 9
      CERT_CTL_USAGE_PROP_ID equ <CERT_ENHKEY_USAGE_PROP_ID>
      CERT_NEXT_UPDATE_LOCATION_PROP_ID equ 10
      CERT_FRIENDLY_NAME_PROP_ID equ 11
      CERT_PVK_FILE_PROP_ID equ 12
      CERT_DESCRIPTION_PROP_ID equ 13
      CERT_ACCESS_STATE_PROP_ID equ 14
      CERT_SIGNATURE_HASH_PROP_ID equ 15
      CERT_SMART_CARD_DATA_PROP_ID equ 16
      CERT_EFS_PROP_ID equ 17
      CERT_FORTEZZA_DATA_PROP_ID equ 18
      CERT_ARCHIVED_PROP_ID equ 19
      CERT_KEY_IDENTIFIER_PROP_ID equ 20
      CERT_AUTO_ENROLL_PROP_ID equ 21
      CERT_PUBKEY_ALG_PARA_PROP_ID equ 22
      CERT_CROSS_CERT_DIST_POINTS_PROP_ID equ 23
      CERT_ISSUER_PUBLIC_KEY_MD5_HASH_PROP_ID equ 24
      CERT_SUBJECT_PUBLIC_KEY_MD5_HASH_PROP_ID equ 25
      CERT_ENROLLMENT_PROP_ID equ 26
      CERT_DATE_STAMP_PROP_ID equ 27
      CERT_ISSUER_SERIAL_NUMBER_MD5_HASH_PROP_ID equ 28
      CERT_SUBJECT_NAME_MD5_HASH_PROP_ID equ 29
      CERT_EXTENDED_ERROR_INFO_PROP_ID equ 30
      CERT_RENEWAL_PROP_ID equ 64
      CERT_ARCHIVED_KEY_HASH_PROP_ID equ 65
      CERT_AUTO_ENROLL_RETRY_PROP_ID equ 66
      CERT_AIA_URL_RETRIEVED_PROP_ID equ 67
      CERT_AUTHORITY_INFO_ACCESS_PROP_ID equ 68
      CERT_BACKED_UP_PROP_ID equ 69
      CERT_OCSP_RESPONSE_PROP_ID equ 70
      CERT_REQUEST_ORIGINATOR_PROP_ID equ 71
      CERT_SOURCE_LOCATION_PROP_ID equ 72
      CERT_SOURCE_URL_PROP_ID equ 73
      CERT_NEW_KEY_PROP_ID equ 74
      CERT_OCSP_CACHE_PREFIX_PROP_ID equ 75
      CERT_SMART_CARD_ROOT_INFO_PROP_ID equ 76
      CERT_NO_AUTO_EXPIRE_CHECK_PROP_ID equ 77
      CERT_NCRYPT_KEY_HANDLE_PROP_ID equ 78
      CERT_HCRYPTPROV_OR_NCRYPT_KEY_HANDLE_PROP_ID equ 79
      CERT_SUBJECT_INFO_ACCESS_PROP_ID equ 80
      CERT_CA_OCSP_AUTHORITY_INFO_ACCESS_PROP_ID equ 81
      CERT_CA_DISABLE_CRL_PROP_ID equ 82
      CERT_ROOT_PROGRAM_CERT_POLICIES_PROP_ID equ 83
      CERT_ROOT_PROGRAM_NAME_CONSTRAINTS_PROP_ID equ 84
      CERT_SUBJECT_OCSP_AUTHORITY_INFO_ACCESS_PROP_ID equ 85
      CERT_SUBJECT_DISABLE_CRL_PROP_ID equ 86
      CERT_CEP_PROP_ID equ 87
      CERT_SIGN_HASH_CNG_ALG_PROP_ID equ 89
      CERT_SCARD_PIN_ID_PROP_ID equ 90
      CERT_SCARD_PIN_INFO_PROP_ID equ 91
      CERT_SUBJECT_PUB_KEY_BIT_LENGTH_PROP_ID equ 92
      CERT_PUB_KEY_CNG_ALG_BIT_LENGTH_PROP_ID equ 93
      CERT_ISSUER_PUB_KEY_BIT_LENGTH_PROP_ID equ 94
      CERT_ISSUER_CHAIN_SIGN_HASH_CNG_ALG_PROP_ID equ 95
      CERT_ISSUER_CHAIN_PUB_KEY_CNG_ALG_BIT_LENGTH_PROP_ID equ 96
      CERT_NO_EXPIRE_NOTIFICATION_PROP_ID equ 97
      CERT_AUTH_ROOT_SHA256_HASH_PROP_ID equ 98
      CERT_NCRYPT_KEY_HANDLE_TRANSFER_PROP_ID equ 99
      CERT_HCRYPTPROV_TRANSFER_PROP_ID equ 100
      CERT_SMART_CARD_READER_PROP_ID equ 101
      CERT_SEND_AS_TRUSTED_ISSUER_PROP_ID equ 102
      CERT_KEY_REPAIR_ATTEMPTED_PROP_ID equ 103
      CERT_DISALLOWED_FILETIME_PROP_ID equ 104
      CERT_ROOT_PROGRAM_CHAIN_POLICIES_PROP_ID equ 105
      CERT_SMART_CARD_READER_NON_REMOVABLE_PROP_ID equ 106
      CERT_SHA256_HASH_PROP_ID equ 107
      CERT_SCEP_SERVER_CERTS_PROP_ID equ 108
      CERT_SCEP_RA_SIGNATURE_CERT_PROP_ID equ 109
      CERT_SCEP_RA_ENCRYPTION_CERT_PROP_ID equ 110
      CERT_SCEP_CA_CERT_PROP_ID equ 111
      CERT_SCEP_SIGNER_CERT_PROP_ID equ 112
      CERT_SCEP_NONCE_PROP_ID equ 113
      CERT_SCEP_ENCRYPT_HASH_CNG_ALG_PROP_ID equ 114
      CERT_SCEP_FLAGS_PROP_ID equ 115
      CERT_SCEP_GUID_PROP_ID equ 116
      CERT_SERIALIZABLE_KEY_CONTEXT_PROP_ID equ 117
      CERT_ISOLATED_KEY_PROP_ID equ 118
      CERT_SERIAL_CHAIN_PROP_ID equ 119
      CERT_KEY_CLASSIFICATION_PROP_ID equ 120
      CERT_OCSP_MUST_STAPLE_PROP_ID equ 121
      CERT_DISALLOWED_ENHKEY_USAGE_PROP_ID equ 122
      CERT_NONCOMPLIANT_ROOT_URL_PROP_ID equ 123
      CERT_PIN_SHA256_HASH_PROP_ID equ 124
      CERT_CLR_DELETE_KEY_PROP_ID equ 125
      CERT_NOT_BEFORE_FILETIME_PROP_ID equ 126
      CERT_NOT_BEFORE_ENHKEY_USAGE_PROP_ID equ 127
      CERT_DISALLOWED_CA_FILETIME_PROP_ID equ 128
      CERT_FIRST_RESERVED_PROP_ID equ 129
      CERT_LAST_RESERVED_PROP_ID equ 00007FFFh
      CERT_FIRST_USER_PROP_ID equ 00008000h
      CERT_LAST_USER_PROP_ID equ 0000FFFFh
      if Defined(__cplusplus) and  not Defined(SORTPP_PASS)
        ;[...]
      else
        WINCRYPT_DWORD_CPP_ONLY equ <>
      endif
      WINCRYPT_DWORD_CPP_ONLY typedef SDWORD
      IS_CERT_HASH_PROP_ID macro X
        exitm <(CERT_SHA1_HASH_PROP_ID == (X) or CERT_MD5_HASH_PROP_ID == (X) or CERT_SHA256_HASH_PROP_ID == (X) or CERT_SIGNATURE_HASH_PROP_ID == (X))>
      endm
      IS_PUBKEY_HASH_PROP_ID macro X
        exitm <(CERT_ISSUER_PUBLIC_KEY_MD5_HASH_PROP_ID == (X) or CERT_PIN_SHA256_HASH_PROP_ID == (X) or CERT_SUBJECT_PUBLIC_KEY_MD5_HASH_PROP_ID == (X))>
      endm
      IS_CHAIN_HASH_PROP_ID macro X
        exitm <(CERT_ISSUER_PUBLIC_KEY_MD5_HASH_PROP_ID == (X) or CERT_SUBJECT_PUBLIC_KEY_MD5_HASH_PROP_ID == (X) or CERT_ISSUER_SERIAL_NUMBER_MD5_HASH_PROP_ID == (X) or CERT_SUBJECT_NAME_MD5_HASH_PROP_ID == (X))>
      endm
      IS_STRONG_SIGN_PROP_ID macro X
        exitm <(CERT_SIGN_HASH_CNG_ALG_PROP_ID == (X) or CERT_SUBJECT_PUB_KEY_BIT_LENGTH_PROP_ID == (X) or CERT_PUB_KEY_CNG_ALG_BIT_LENGTH_PROP_ID == (X))>
      endm
      szOID_CERT_PROP_ID_PREFIX equ <"1.3.6.1.4.1.311.10.11.">
      _szPROP_ID macro PropId
        exitm <# PropId>
      endm
      szOID_CERT_PROP_ID macro PropId
        exitm <szOID_CERT_PROP_ID_PREFIX _szPROP_ID(PropId)>
      endm
      __CRYPT32WTEXT macro quote
        exitm <L ## quote>
      endm
      _CRYPT32WTEXT macro quote
        exitm <__CRYPT32WTEXT(quote)>
      endm
      wszOID_CERT_PROP_ID macro PropId
        exitm <_CRYPT32WTEXT(szOID_CERT_PROP_ID_PREFIX) _CRYPT32WTEXT(_szPROP_ID(PropId))>
      endm
      szOID_CERT_KEY_IDENTIFIER_PROP_ID equ <"1.3.6.1.4.1.311.10.11.20">
      szOID_CERT_ISSUER_SERIAL_NUMBER_MD5_HASH_PROP_ID equ <"1.3.6.1.4.1.311.10.11.28">
      szOID_CERT_SUBJECT_NAME_MD5_HASH_PROP_ID equ <"1.3.6.1.4.1.311.10.11.29">
      szOID_CERT_MD5_HASH_PROP_ID equ <"1.3.6.1.4.1.311.10.11.4">
      szOID_CERT_SIGNATURE_HASH_PROP_ID equ <"1.3.6.1.4.1.311.10.11.15">
      szOID_DISALLOWED_HASH equ <szOID_CERT_SIGNATURE_HASH_PROP_ID>
      szOID_CERT_DISALLOWED_FILETIME_PROP_ID equ <"1.3.6.1.4.1.311.10.11.104">
      szOID_CERT_DISALLOWED_CA_FILETIME_PROP_ID equ <"1.3.6.1.4.1.311.10.11.128">
      CERT_ACCESS_STATE_WRITE_PERSIST_FLAG equ 1h
      CERT_ACCESS_STATE_SYSTEM_STORE_FLAG equ 2h
      CERT_ACCESS_STATE_LM_SYSTEM_STORE_FLAG equ 4h
      CERT_ACCESS_STATE_GP_SYSTEM_STORE_FLAG equ 8h
      CERT_ACCESS_STATE_SHARED_USER_FLAG equ 10h
      szOID_ROOT_PROGRAM_AUTO_UPDATE_CA_REVOCATION equ <"1.3.6.1.4.1.311.60.3.1">
      szOID_ROOT_PROGRAM_AUTO_UPDATE_END_REVOCATION equ <"1.3.6.1.4.1.311.60.3.2">
      szOID_ROOT_PROGRAM_NO_OCSP_FAILOVER_TO_CRL equ <"1.3.6.1.4.1.311.60.3.3">
      CRYPT_KEY_PROV_PARAM struct
        dwParam DWORD ?
        pbData POINTER ?
        cbData DWORD ?
        dwFlags DWORD ?
      CRYPT_KEY_PROV_PARAM ends
      _CRYPT_KEY_PROV_PARAM typedef CRYPT_KEY_PROV_PARAM
      PCRYPT_KEY_PROV_PARAM typedef ptr CRYPT_KEY_PROV_PARAM
      CRYPT_KEY_PROV_INFO struct
        pwszContainerName LPWSTR ?
        pwszProvName LPWSTR ?
        dwProvType DWORD ?
        dwFlags DWORD ?
        cProvParam DWORD ?
        rgProvParam PCRYPT_KEY_PROV_PARAM ?
        dwKeySpec DWORD ?
      CRYPT_KEY_PROV_INFO ends
      _CRYPT_KEY_PROV_INFO typedef CRYPT_KEY_PROV_INFO
      PCRYPT_KEY_PROV_INFO typedef ptr CRYPT_KEY_PROV_INFO
      CERT_SET_KEY_PROV_HANDLE_PROP_ID equ 00000001h
      CERT_SET_KEY_CONTEXT_PROP_ID equ 00000001h
      CERT_NCRYPT_KEY_SPEC equ 0FFFFFFFFh
      CERT_KEY_CONTEXT struct
        cbSize DWORD ?
        union
          hCryptProv HCRYPTPROV ?
          hNCryptKey NCRYPT_KEY_HANDLE ?
        ends
        dwKeySpec DWORD ?
      CERT_KEY_CONTEXT ends
      _CERT_KEY_CONTEXT typedef CERT_KEY_CONTEXT
      PCERT_KEY_CONTEXT typedef ptr CERT_KEY_CONTEXT
      ROOT_INFO_LUID struct
        LowPart DWORD ?
        HighPart LONG ?
      ROOT_INFO_LUID ends
      _ROOT_INFO_LUID typedef ROOT_INFO_LUID
      PROOT_INFO_LUID typedef ptr ROOT_INFO_LUID
      CRYPT_SMART_CARD_ROOT_INFO struct
        rgbCardID BYTE 16 dup (?)
        luid ROOT_INFO_LUID <>
      CRYPT_SMART_CARD_ROOT_INFO ends
      _CRYPT_SMART_CARD_ROOT_INFO typedef CRYPT_SMART_CARD_ROOT_INFO
      PCRYPT_SMART_CARD_ROOT_INFO typedef ptr CRYPT_SMART_CARD_ROOT_INFO
      CERT_STORE_PROV_MSG equ (1)
      CERT_STORE_PROV_MEMORY equ (2)
      CERT_STORE_PROV_FILE equ (3)
      CERT_STORE_PROV_REG equ (4)
      CERT_STORE_PROV_PKCS7 equ (5)
      CERT_STORE_PROV_SERIALIZED equ (6)
      CERT_STORE_PROV_FILENAME_A equ (7)
      CERT_STORE_PROV_FILENAME_W equ (8)
      CERT_STORE_PROV_FILENAME equ <CERT_STORE_PROV_FILENAME_W>
      CERT_STORE_PROV_SYSTEM_A equ (9)
      CERT_STORE_PROV_SYSTEM_W equ (10)
      CERT_STORE_PROV_SYSTEM equ <CERT_STORE_PROV_SYSTEM_W>
      CERT_STORE_PROV_COLLECTION equ (11)
      CERT_STORE_PROV_SYSTEM_REGISTRY_A equ (12)
      CERT_STORE_PROV_SYSTEM_REGISTRY_W equ (13)
      CERT_STORE_PROV_SYSTEM_REGISTRY equ <CERT_STORE_PROV_SYSTEM_REGISTRY_W>
      CERT_STORE_PROV_PHYSICAL_W equ (14)
      CERT_STORE_PROV_PHYSICAL equ <CERT_STORE_PROV_PHYSICAL_W>
      CERT_STORE_PROV_SMART_CARD_W equ (15)
      CERT_STORE_PROV_SMART_CARD equ <CERT_STORE_PROV_SMART_CARD_W>
      CERT_STORE_PROV_LDAP_W equ (16)
      CERT_STORE_PROV_LDAP equ <CERT_STORE_PROV_LDAP_W>
      CERT_STORE_PROV_PKCS12 equ (17)
      sz_CERT_STORE_PROV_MEMORY equ <"Memory">
      sz_CERT_STORE_PROV_FILENAME_W equ <"File">
      sz_CERT_STORE_PROV_FILENAME equ <sz_CERT_STORE_PROV_FILENAME_W>
      sz_CERT_STORE_PROV_SYSTEM_W equ <"System">
      sz_CERT_STORE_PROV_SYSTEM equ <sz_CERT_STORE_PROV_SYSTEM_W>
      sz_CERT_STORE_PROV_PKCS7 equ <"PKCS7">
      sz_CERT_STORE_PROV_PKCS12 equ <"PKCS12">
      sz_CERT_STORE_PROV_SERIALIZED equ <"Serialized">
      sz_CERT_STORE_PROV_COLLECTION equ <"Collection">
      sz_CERT_STORE_PROV_SYSTEM_REGISTRY_W equ <"SystemRegistry">
      sz_CERT_STORE_PROV_SYSTEM_REGISTRY equ <sz_CERT_STORE_PROV_SYSTEM_REGISTRY_W>
      sz_CERT_STORE_PROV_PHYSICAL_W equ <"Physical">
      sz_CERT_STORE_PROV_PHYSICAL equ <sz_CERT_STORE_PROV_PHYSICAL_W>
      sz_CERT_STORE_PROV_SMART_CARD_W equ <"SmartCard">
      sz_CERT_STORE_PROV_SMART_CARD equ <sz_CERT_STORE_PROV_SMART_CARD_W>
      sz_CERT_STORE_PROV_LDAP_W equ <"Ldap">
      sz_CERT_STORE_PROV_LDAP equ <sz_CERT_STORE_PROV_LDAP_W>
      CERT_STORE_SIGNATURE_FLAG equ 00000001h
      CERT_STORE_TIME_VALIDITY_FLAG equ 00000002h
      CERT_STORE_REVOCATION_FLAG equ 00000004h
      CERT_STORE_NO_CRL_FLAG equ 00010000h
      CERT_STORE_NO_ISSUER_FLAG equ 00020000h
      CERT_STORE_BASE_CRL_FLAG equ 00000100h
      CERT_STORE_DELTA_CRL_FLAG equ 00000200h
      CERT_STORE_NO_CRYPT_RELEASE_FLAG equ 00000001h
      CERT_STORE_SET_LOCALIZED_NAME_FLAG equ 00000002h
      CERT_STORE_DEFER_CLOSE_UNTIL_LAST_FREE_FLAG equ 00000004h
      CERT_STORE_DELETE_FLAG equ 00000010h
      CERT_STORE_UNSAFE_PHYSICAL_FLAG equ 00000020h
      CERT_STORE_SHARE_STORE_FLAG equ 00000040h
      CERT_STORE_SHARE_CONTEXT_FLAG equ 00000080h
      CERT_STORE_MANIFOLD_FLAG equ 00000100h
      CERT_STORE_ENUM_ARCHIVED_FLAG equ 00000200h
      CERT_STORE_UPDATE_KEYID_FLAG equ 00000400h
      CERT_STORE_BACKUP_RESTORE_FLAG equ 00000800h
      CERT_STORE_READONLY_FLAG equ 00008000h
      CERT_STORE_OPEN_EXISTING_FLAG equ 00004000h
      CERT_STORE_CREATE_NEW_FLAG equ 00002000h
      CERT_STORE_MAXIMUM_ALLOWED_FLAG equ 00001000h
      CERT_SYSTEM_STORE_MASK equ 0FFFF0000h
      CERT_SYSTEM_STORE_RELOCATE_FLAG equ 80000000h
      CERT_SYSTEM_STORE_RELOCATE_PARA struct
        union
          hKeyBase HKEY ?
          pvBase POINTER ?
        ends
        union
          pvSystemStore POINTER ?
          pszSystemStore LPCSTR ?
          pwszSystemStore LPCWSTR ?
        ends
      CERT_SYSTEM_STORE_RELOCATE_PARA ends
      _CERT_SYSTEM_STORE_RELOCATE_PARA typedef CERT_SYSTEM_STORE_RELOCATE_PARA
      PCERT_SYSTEM_STORE_RELOCATE_PARA typedef ptr CERT_SYSTEM_STORE_RELOCATE_PARA
      CERT_SYSTEM_STORE_UNPROTECTED_FLAG equ 40000000h
      CERT_SYSTEM_STORE_DEFER_READ_FLAG equ 20000000h
      CERT_SYSTEM_STORE_LOCATION_MASK equ 00FF0000h
      CERT_SYSTEM_STORE_LOCATION_SHIFT equ 16
      CERT_SYSTEM_STORE_CURRENT_USER_ID equ 1
      CERT_SYSTEM_STORE_LOCAL_MACHINE_ID equ 2
      CERT_SYSTEM_STORE_CURRENT_SERVICE_ID equ 4
      CERT_SYSTEM_STORE_SERVICES_ID equ 5
      CERT_SYSTEM_STORE_USERS_ID equ 6
      CERT_SYSTEM_STORE_CURRENT_USER_GROUP_POLICY_ID equ 7
      CERT_SYSTEM_STORE_LOCAL_MACHINE_GROUP_POLICY_ID equ 8
      CERT_SYSTEM_STORE_LOCAL_MACHINE_ENTERPRISE_ID equ 9
      CERT_SYSTEM_STORE_LOCAL_MACHINE_WCOS_ID equ 10
      CERT_SYSTEM_STORE_CURRENT_USER equ (CERT_SYSTEM_STORE_CURRENT_USER_ID shl CERT_SYSTEM_STORE_LOCATION_SHIFT)
      CERT_SYSTEM_STORE_LOCAL_MACHINE equ (CERT_SYSTEM_STORE_LOCAL_MACHINE_ID shl CERT_SYSTEM_STORE_LOCATION_SHIFT)
      CERT_SYSTEM_STORE_CURRENT_SERVICE equ (CERT_SYSTEM_STORE_CURRENT_SERVICE_ID shl CERT_SYSTEM_STORE_LOCATION_SHIFT)
      CERT_SYSTEM_STORE_SERVICES equ (CERT_SYSTEM_STORE_SERVICES_ID shl CERT_SYSTEM_STORE_LOCATION_SHIFT)
      CERT_SYSTEM_STORE_USERS equ (CERT_SYSTEM_STORE_USERS_ID shl CERT_SYSTEM_STORE_LOCATION_SHIFT)
      CERT_SYSTEM_STORE_CURRENT_USER_GROUP_POLICY equ (CERT_SYSTEM_STORE_CURRENT_USER_GROUP_POLICY_ID shl CERT_SYSTEM_STORE_LOCATION_SHIFT)
      CERT_SYSTEM_STORE_LOCAL_MACHINE_GROUP_POLICY equ (CERT_SYSTEM_STORE_LOCAL_MACHINE_GROUP_POLICY_ID shl CERT_SYSTEM_STORE_LOCATION_SHIFT)
      CERT_SYSTEM_STORE_LOCAL_MACHINE_ENTERPRISE equ (CERT_SYSTEM_STORE_LOCAL_MACHINE_ENTERPRISE_ID shl CERT_SYSTEM_STORE_LOCATION_SHIFT)
      CERT_SYSTEM_STORE_LOCAL_MACHINE_WCOS equ (CERT_SYSTEM_STORE_LOCAL_MACHINE_WCOS_ID shl CERT_SYSTEM_STORE_LOCATION_SHIFT)
      CERT_GROUP_POLICY_SYSTEM_STORE_REGPATH equ <L("Software\Policies\Microsoft\SystemCertificates")>
      CERT_EFSBLOB_REGPATH equ <CERT_GROUP_POLICY_SYSTEM_STORE_REGPATH L("\EFS")>
      CERT_EFSBLOB_VALUE_NAME equ <L("EFSBlob")>
      CERT_PROT_ROOT_FLAGS_REGPATH equ <CERT_GROUP_POLICY_SYSTEM_STORE_REGPATH L("\Root\ProtectedRoots")>
      CERT_PROT_ROOT_FLAGS_VALUE_NAME equ <L("Flags")>
      CERT_PROT_ROOT_DISABLE_CURRENT_USER_FLAG equ 1h
      CERT_PROT_ROOT_INHIBIT_ADD_AT_INIT_FLAG equ 2h
      CERT_PROT_ROOT_INHIBIT_PURGE_LM_FLAG equ 4h
      CERT_PROT_ROOT_DISABLE_LM_AUTH_FLAG equ 8h
      CERT_PROT_ROOT_ONLY_LM_GPT_FLAG equ 8h
      CERT_PROT_ROOT_DISABLE_NT_AUTH_REQUIRED_FLAG equ 10h
      CERT_PROT_ROOT_DISABLE_NOT_DEFINED_NAME_CONSTRAINT_FLAG equ 20h
      CERT_PROT_ROOT_DISABLE_PEER_TRUST equ 10000h
      CERT_PROT_ROOT_PEER_USAGES_VALUE_NAME equ <L("PeerUsages")>
      CERT_PROT_ROOT_PEER_USAGES_VALUE_NAME_A equ <"PeerUsages">
      CERT_PROT_ROOT_PEER_USAGES_DEFAULT_A equ <szOID_PKIX_KP_CLIENT_AUTH,0o szOID_PKIX_KP_EMAIL_PROTECTION,0o szOID_KP_EFS,0o>
      CERT_TRUST_PUB_SAFER_GROUP_POLICY_REGPATH equ <CERT_GROUP_POLICY_SYSTEM_STORE_REGPATH L("\TrustedPublisher\Safer")>
      CERT_LOCAL_MACHINE_SYSTEM_STORE_REGPATH equ <L("Software\Microsoft\SystemCertificates")>
      CERT_TRUST_PUB_SAFER_LOCAL_MACHINE_REGPATH equ <CERT_LOCAL_MACHINE_SYSTEM_STORE_REGPATH L("\TrustedPublisher\Safer")>
      CERT_TRUST_PUB_AUTHENTICODE_FLAGS_VALUE_NAME equ <L("AuthenticodeFlags")>
      CERT_TRUST_PUB_ALLOW_TRUST_MASK equ 00000003h
      CERT_TRUST_PUB_ALLOW_END_USER_TRUST equ 00000000h
      CERT_TRUST_PUB_ALLOW_MACHINE_ADMIN_TRUST equ 00000001h
      CERT_TRUST_PUB_ALLOW_ENTERPRISE_ADMIN_TRUST equ 00000002h
      CERT_TRUST_PUB_CHECK_PUBLISHER_REV_FLAG equ 00000100h
      CERT_TRUST_PUB_CHECK_TIMESTAMP_REV_FLAG equ 00000200h
      CERT_OCM_SUBCOMPONENTS_LOCAL_MACHINE_REGPATH equ <L("SOFTWARE\Microsoft\Windows\CurrentVersion\Setup\OC Manager\Subcomponents")>
      CERT_OCM_SUBCOMPONENTS_ROOT_AUTO_UPDATE_VALUE_NAME equ <L("RootAutoUpdate")>
      CERT_DISABLE_ROOT_AUTO_UPDATE_REGPATH equ <CERT_GROUP_POLICY_SYSTEM_STORE_REGPATH L("\AuthRoot")>
      CERT_DISABLE_ROOT_AUTO_UPDATE_VALUE_NAME equ <L("DisableRootAutoUpdate")>
      CERT_ENABLE_DISALLOWED_CERT_AUTO_UPDATE_VALUE_NAME equ <L("EnableDisallowedCertAutoUpdate")>
      CERT_DISABLE_PIN_RULES_AUTO_UPDATE_VALUE_NAME equ <L("DisablePinRulesAutoUpdate")>
      CERT_AUTO_UPDATE_LOCAL_MACHINE_REGPATH equ <CERT_LOCAL_MACHINE_SYSTEM_STORE_REGPATH L("\AuthRoot\AutoUpdate")>
      CERT_AUTO_UPDATE_ROOT_DIR_URL_VALUE_NAME equ <L("RootDirUrl")>
      CERT_AUTO_UPDATE_SYNC_FROM_DIR_URL_VALUE_NAME equ <L("SyncFromDirUrl")>
      CERT_AUTH_ROOT_AUTO_UPDATE_LOCAL_MACHINE_REGPATH equ <CERT_AUTO_UPDATE_LOCAL_MACHINE_REGPATH>
      CERT_AUTH_ROOT_AUTO_UPDATE_ROOT_DIR_URL_VALUE_NAME equ <CERT_AUTO_UPDATE_ROOT_DIR_URL_VALUE_NAME>
      CERT_AUTH_ROOT_AUTO_UPDATE_SYNC_DELTA_TIME_VALUE_NAME equ <L("SyncDeltaTime")>
      CERT_AUTH_ROOT_AUTO_UPDATE_FLAGS_VALUE_NAME equ <L("Flags")>
      CERT_AUTH_ROOT_AUTO_UPDATE_DISABLE_UNTRUSTED_ROOT_LOGGING_FLAG equ 1h
      CERT_AUTH_ROOT_AUTO_UPDATE_DISABLE_PARTIAL_CHAIN_LOGGING_FLAG equ 2h
      CERT_AUTO_UPDATE_DISABLE_RANDOM_QUERY_STRING_FLAG equ 4h
      CERT_AUTH_ROOT_AUTO_UPDATE_LAST_SYNC_TIME_VALUE_NAME equ <L("LastSyncTime")>
      CERT_AUTH_ROOT_AUTO_UPDATE_ENCODED_CTL_VALUE_NAME equ <L("EncodedCtl")>
      CERT_AUTH_ROOT_CTL_FILENAME equ <L("authroot.stl")>
      CERT_AUTH_ROOT_CTL_FILENAME_A equ <"authroot.stl">
      CERT_AUTH_ROOT_CAB_FILENAME equ <L("authrootstl.cab")>
      CERT_AUTH_ROOT_SEQ_FILENAME equ <L("authrootseq.txt")>
      CERT_AUTH_ROOT_CERT_EXT equ <L(".crt")>
      CERT_DISALLOWED_CERT_AUTO_UPDATE_SYNC_DELTA_TIME_VALUE_NAME equ <L("DisallowedCertSyncDeltaTime")>
      CERT_DISALLOWED_CERT_AUTO_UPDATE_LAST_SYNC_TIME_VALUE_NAME equ <L("DisallowedCertLastSyncTime")>
      CERT_DISALLOWED_CERT_AUTO_UPDATE_ENCODED_CTL_VALUE_NAME equ <L("DisallowedCertEncodedCtl")>
      CERT_DISALLOWED_CERT_CTL_FILENAME equ <L("disallowedcert.stl")>
      CERT_DISALLOWED_CERT_CTL_FILENAME_A equ <"disallowedcert.stl">
      CERT_DISALLOWED_CERT_CAB_FILENAME equ <L("disallowedcertstl.cab")>
      CERT_DISALLOWED_CERT_AUTO_UPDATE_LIST_IDENTIFIER equ <L("DisallowedCert_AutoUpdate_1")>
      CERT_PIN_RULES_AUTO_UPDATE_SYNC_DELTA_TIME_VALUE_NAME equ <L("PinRulesSyncDeltaTime")>
      CERT_PIN_RULES_AUTO_UPDATE_LAST_SYNC_TIME_VALUE_NAME equ <L("PinRulesLastSyncTime")>
      CERT_PIN_RULES_AUTO_UPDATE_ENCODED_CTL_VALUE_NAME equ <L("PinRulesEncodedCtl")>
      CERT_PIN_RULES_CTL_FILENAME equ <L("pinrules.stl")>
      CERT_PIN_RULES_CTL_FILENAME_A equ <"pinrules.stl">
      CERT_PIN_RULES_CAB_FILENAME equ <L("pinrulesstl.cab")>
      CERT_PIN_RULES_AUTO_UPDATE_LIST_IDENTIFIER equ <L("PinRules_AutoUpdate_1")>
      CERT_REGISTRY_STORE_REMOTE_FLAG equ 10000h
      CERT_REGISTRY_STORE_SERIALIZED_FLAG equ 20000h
      CERT_REGISTRY_STORE_CLIENT_GPT_FLAG equ 80000000h
      CERT_REGISTRY_STORE_LM_GPT_FLAG equ 01000000h
      CERT_REGISTRY_STORE_CLIENT_GPT_PARA struct
        hKeyBase HKEY ?
        pwszRegPath LPWSTR ?
      CERT_REGISTRY_STORE_CLIENT_GPT_PARA ends
      _CERT_REGISTRY_STORE_CLIENT_GPT_PARA typedef CERT_REGISTRY_STORE_CLIENT_GPT_PARA
      PCERT_REGISTRY_STORE_CLIENT_GPT_PARA typedef ptr CERT_REGISTRY_STORE_CLIENT_GPT_PARA
      CERT_REGISTRY_STORE_ROAMING_FLAG equ 40000h
      CERT_REGISTRY_STORE_ROAMING_PARA struct
        hKey HKEY ?
        pwszStoreDirectory LPWSTR ?
      CERT_REGISTRY_STORE_ROAMING_PARA ends
      _CERT_REGISTRY_STORE_ROAMING_PARA typedef CERT_REGISTRY_STORE_ROAMING_PARA
      PCERT_REGISTRY_STORE_ROAMING_PARA typedef ptr CERT_REGISTRY_STORE_ROAMING_PARA
      CERT_REGISTRY_STORE_MY_IE_DIRTY_FLAG equ 80000h
      CERT_REGISTRY_STORE_EXTERNAL_FLAG equ 100000h
      CERT_IE_DIRTY_FLAGS_REGPATH equ <L("Software\Microsoft\Cryptography\IEDirtyFlags")>
      CERT_FILE_STORE_COMMIT_ENABLE_FLAG equ 10000h
      CERT_LDAP_STORE_SIGN_FLAG equ 10000h
      CERT_LDAP_STORE_AREC_EXCLUSIVE_FLAG equ 20000h
      CERT_LDAP_STORE_OPENED_FLAG equ 40000h
      CERT_LDAP_STORE_OPENED_PARA struct
        pvLdapSessionHandle POINTER ?
        pwszLdapUrl LPCWSTR ?
      CERT_LDAP_STORE_OPENED_PARA ends
      _CERT_LDAP_STORE_OPENED_PARA typedef CERT_LDAP_STORE_OPENED_PARA
      PCERT_LDAP_STORE_OPENED_PARA typedef ptr CERT_LDAP_STORE_OPENED_PARA
      CERT_LDAP_STORE_UNBIND_FLAG equ 80000h
      @DefProto DllImport, CertOpenStore, WIN_STD_CALL_CONV,, <:LPCSTR, :DWORD, :HCRYPTPROV_LEGACY, :DWORD, :ptr>, 20
      HCERTSTOREPROV typedef ptr
      CRYPT_OID_OPEN_STORE_PROV_FUNC equ <"CertDllOpenStoreProv">
      CERT_STORE_PROV_INFO struct
        cbSize DWORD ?
        cStoreProvFunc DWORD ?
        rgpvStoreProvFunc POINTER ?
        hStoreProv HCERTSTOREPROV ?
        dwStoreProvFlags DWORD ?
        hStoreProvFuncAddr2 HCRYPTOIDFUNCADDR ?
      CERT_STORE_PROV_INFO ends
      _CERT_STORE_PROV_INFO typedef CERT_STORE_PROV_INFO
      PCERT_STORE_PROV_INFO typedef ptr CERT_STORE_PROV_INFO
      TYPE_PFN_CERT_DLL_OPEN_STORE_PROV_FUNC typedef proto WIN_STD_CALL_CONV :LPCSTR, :DWORD, :HCRYPTPROV_LEGACY, :DWORD, :ptr, :HCERTSTORE, :PCERT_STORE_PROV_INFO
      PFN_CERT_DLL_OPEN_STORE_PROV_FUNC typedef ptr TYPE_PFN_CERT_DLL_OPEN_STORE_PROV_FUNC

      CERT_STORE_PROV_EXTERNAL_FLAG equ 1h
      CERT_STORE_PROV_DELETED_FLAG equ 2h
      CERT_STORE_PROV_NO_PERSIST_FLAG equ 4h
      CERT_STORE_PROV_SYSTEM_STORE_FLAG equ 8h
      CERT_STORE_PROV_LM_SYSTEM_STORE_FLAG equ 10h
      CERT_STORE_PROV_GP_SYSTEM_STORE_FLAG equ 20h
      CERT_STORE_PROV_SHARED_USER_FLAG equ 40h
      CERT_STORE_PROV_CLOSE_FUNC equ 0
      CERT_STORE_PROV_READ_CERT_FUNC equ 1
      CERT_STORE_PROV_WRITE_CERT_FUNC equ 2
      CERT_STORE_PROV_DELETE_CERT_FUNC equ 3
      CERT_STORE_PROV_SET_CERT_PROPERTY_FUNC equ 4
      CERT_STORE_PROV_READ_CRL_FUNC equ 5
      CERT_STORE_PROV_WRITE_CRL_FUNC equ 6
      CERT_STORE_PROV_DELETE_CRL_FUNC equ 7
      CERT_STORE_PROV_SET_CRL_PROPERTY_FUNC equ 8
      CERT_STORE_PROV_READ_CTL_FUNC equ 9
      CERT_STORE_PROV_WRITE_CTL_FUNC equ 10
      CERT_STORE_PROV_DELETE_CTL_FUNC equ 11
      CERT_STORE_PROV_SET_CTL_PROPERTY_FUNC equ 12
      CERT_STORE_PROV_CONTROL_FUNC equ 13
      CERT_STORE_PROV_FIND_CERT_FUNC equ 14
      CERT_STORE_PROV_FREE_FIND_CERT_FUNC equ 15
      CERT_STORE_PROV_GET_CERT_PROPERTY_FUNC equ 16
      CERT_STORE_PROV_FIND_CRL_FUNC equ 17
      CERT_STORE_PROV_FREE_FIND_CRL_FUNC equ 18
      CERT_STORE_PROV_GET_CRL_PROPERTY_FUNC equ 19
      CERT_STORE_PROV_FIND_CTL_FUNC equ 20
      CERT_STORE_PROV_FREE_FIND_CTL_FUNC equ 21
      CERT_STORE_PROV_GET_CTL_PROPERTY_FUNC equ 22
      TYPE_PFN_CERT_STORE_PROV_CLOSE typedef proto WIN_STD_CALL_CONV :HCERTSTOREPROV, :DWORD
      PFN_CERT_STORE_PROV_CLOSE typedef ptr TYPE_PFN_CERT_STORE_PROV_CLOSE

      TYPE_PFN_CERT_STORE_PROV_READ_CERT typedef proto WIN_STD_CALL_CONV :HCERTSTOREPROV, :PCCERT_CONTEXT, :DWORD, :ptr PCCERT_CONTEXT
      PFN_CERT_STORE_PROV_READ_CERT typedef ptr TYPE_PFN_CERT_STORE_PROV_READ_CERT

      CERT_STORE_PROV_WRITE_ADD_FLAG equ 1h
      TYPE_PFN_CERT_STORE_PROV_WRITE_CERT typedef proto WIN_STD_CALL_CONV :HCERTSTOREPROV, :PCCERT_CONTEXT, :DWORD
      PFN_CERT_STORE_PROV_WRITE_CERT typedef ptr TYPE_PFN_CERT_STORE_PROV_WRITE_CERT

      TYPE_PFN_CERT_STORE_PROV_DELETE_CERT typedef proto WIN_STD_CALL_CONV :HCERTSTOREPROV, :PCCERT_CONTEXT, :DWORD
      PFN_CERT_STORE_PROV_DELETE_CERT typedef ptr TYPE_PFN_CERT_STORE_PROV_DELETE_CERT

      TYPE_PFN_CERT_STORE_PROV_SET_CERT_PROPERTY typedef proto WIN_STD_CALL_CONV :HCERTSTOREPROV, :PCCERT_CONTEXT, :DWORD, :DWORD, :ptr
      PFN_CERT_STORE_PROV_SET_CERT_PROPERTY typedef ptr TYPE_PFN_CERT_STORE_PROV_SET_CERT_PROPERTY

      TYPE_PFN_CERT_STORE_PROV_READ_CRL typedef proto WIN_STD_CALL_CONV :HCERTSTOREPROV, :PCCRL_CONTEXT, :DWORD, :ptr PCCRL_CONTEXT
      PFN_CERT_STORE_PROV_READ_CRL typedef ptr TYPE_PFN_CERT_STORE_PROV_READ_CRL

      TYPE_PFN_CERT_STORE_PROV_WRITE_CRL typedef proto WIN_STD_CALL_CONV :HCERTSTOREPROV, :PCCRL_CONTEXT, :DWORD
      PFN_CERT_STORE_PROV_WRITE_CRL typedef ptr TYPE_PFN_CERT_STORE_PROV_WRITE_CRL

      TYPE_PFN_CERT_STORE_PROV_DELETE_CRL typedef proto WIN_STD_CALL_CONV :HCERTSTOREPROV, :PCCRL_CONTEXT, :DWORD
      PFN_CERT_STORE_PROV_DELETE_CRL typedef ptr TYPE_PFN_CERT_STORE_PROV_DELETE_CRL

      TYPE_PFN_CERT_STORE_PROV_SET_CRL_PROPERTY typedef proto WIN_STD_CALL_CONV :HCERTSTOREPROV, :PCCRL_CONTEXT, :DWORD, :DWORD, :ptr
      PFN_CERT_STORE_PROV_SET_CRL_PROPERTY typedef ptr TYPE_PFN_CERT_STORE_PROV_SET_CRL_PROPERTY

      TYPE_PFN_CERT_STORE_PROV_READ_CTL typedef proto WIN_STD_CALL_CONV :HCERTSTOREPROV, :PCCTL_CONTEXT, :DWORD, :ptr PCCTL_CONTEXT
      PFN_CERT_STORE_PROV_READ_CTL typedef ptr TYPE_PFN_CERT_STORE_PROV_READ_CTL

      TYPE_PFN_CERT_STORE_PROV_WRITE_CTL typedef proto WIN_STD_CALL_CONV :HCERTSTOREPROV, :PCCTL_CONTEXT, :DWORD
      PFN_CERT_STORE_PROV_WRITE_CTL typedef ptr TYPE_PFN_CERT_STORE_PROV_WRITE_CTL

      TYPE_PFN_CERT_STORE_PROV_DELETE_CTL typedef proto WIN_STD_CALL_CONV :HCERTSTOREPROV, :PCCTL_CONTEXT, :DWORD
      PFN_CERT_STORE_PROV_DELETE_CTL typedef ptr TYPE_PFN_CERT_STORE_PROV_DELETE_CTL

      TYPE_PFN_CERT_STORE_PROV_SET_CTL_PROPERTY typedef proto WIN_STD_CALL_CONV :HCERTSTOREPROV, :PCCTL_CONTEXT, :DWORD, :DWORD, :ptr
      PFN_CERT_STORE_PROV_SET_CTL_PROPERTY typedef ptr TYPE_PFN_CERT_STORE_PROV_SET_CTL_PROPERTY

      TYPE_PFN_CERT_STORE_PROV_CONTROL typedef proto WIN_STD_CALL_CONV :HCERTSTOREPROV, :DWORD, :DWORD, :ptr
      PFN_CERT_STORE_PROV_CONTROL typedef ptr TYPE_PFN_CERT_STORE_PROV_CONTROL

      CERT_STORE_PROV_FIND_INFO struct
        cbSize DWORD ?
        dwMsgAndCertEncodingType DWORD ?
        dwFindFlags DWORD ?
        dwFindType DWORD ?
        pvFindPara POINTER ?
      CERT_STORE_PROV_FIND_INFO ends
      _CERT_STORE_PROV_FIND_INFO typedef CERT_STORE_PROV_FIND_INFO
      PCERT_STORE_PROV_FIND_INFO typedef ptr CERT_STORE_PROV_FIND_INFO
      CCERT_STORE_PROV_FIND_INFO typedef CERT_STORE_PROV_FIND_INFO
      PCCERT_STORE_PROV_FIND_INFO typedef ptr CERT_STORE_PROV_FIND_INFO
      TYPE_PFN_CERT_STORE_PROV_FIND_CERT typedef proto WIN_STD_CALL_CONV :HCERTSTOREPROV, :PCCERT_STORE_PROV_FIND_INFO, :PCCERT_CONTEXT, :DWORD, :ptr ptr, :ptr PCCERT_CONTEXT
      PFN_CERT_STORE_PROV_FIND_CERT typedef ptr TYPE_PFN_CERT_STORE_PROV_FIND_CERT

      TYPE_PFN_CERT_STORE_PROV_FREE_FIND_CERT typedef proto WIN_STD_CALL_CONV :HCERTSTOREPROV, :PCCERT_CONTEXT, :ptr, :DWORD
      PFN_CERT_STORE_PROV_FREE_FIND_CERT typedef ptr TYPE_PFN_CERT_STORE_PROV_FREE_FIND_CERT

      TYPE_PFN_CERT_STORE_PROV_GET_CERT_PROPERTY typedef proto WIN_STD_CALL_CONV :HCERTSTOREPROV, :PCCERT_CONTEXT, :DWORD, :DWORD, :ptr, :ptr DWORD
      PFN_CERT_STORE_PROV_GET_CERT_PROPERTY typedef ptr TYPE_PFN_CERT_STORE_PROV_GET_CERT_PROPERTY

      TYPE_PFN_CERT_STORE_PROV_FIND_CRL typedef proto WIN_STD_CALL_CONV :HCERTSTOREPROV, :PCCERT_STORE_PROV_FIND_INFO, :PCCRL_CONTEXT, :DWORD, :ptr ptr, :ptr PCCRL_CONTEXT
      PFN_CERT_STORE_PROV_FIND_CRL typedef ptr TYPE_PFN_CERT_STORE_PROV_FIND_CRL

      TYPE_PFN_CERT_STORE_PROV_FREE_FIND_CRL typedef proto WIN_STD_CALL_CONV :HCERTSTOREPROV, :PCCRL_CONTEXT, :ptr, :DWORD
      PFN_CERT_STORE_PROV_FREE_FIND_CRL typedef ptr TYPE_PFN_CERT_STORE_PROV_FREE_FIND_CRL

      TYPE_PFN_CERT_STORE_PROV_GET_CRL_PROPERTY typedef proto WIN_STD_CALL_CONV :HCERTSTOREPROV, :PCCRL_CONTEXT, :DWORD, :DWORD, :ptr, :ptr DWORD
      PFN_CERT_STORE_PROV_GET_CRL_PROPERTY typedef ptr TYPE_PFN_CERT_STORE_PROV_GET_CRL_PROPERTY

      TYPE_PFN_CERT_STORE_PROV_FIND_CTL typedef proto WIN_STD_CALL_CONV :HCERTSTOREPROV, :PCCERT_STORE_PROV_FIND_INFO, :PCCTL_CONTEXT, :DWORD, :ptr ptr, :ptr PCCTL_CONTEXT
      PFN_CERT_STORE_PROV_FIND_CTL typedef ptr TYPE_PFN_CERT_STORE_PROV_FIND_CTL

      TYPE_PFN_CERT_STORE_PROV_FREE_FIND_CTL typedef proto WIN_STD_CALL_CONV :HCERTSTOREPROV, :PCCTL_CONTEXT, :ptr, :DWORD
      PFN_CERT_STORE_PROV_FREE_FIND_CTL typedef ptr TYPE_PFN_CERT_STORE_PROV_FREE_FIND_CTL

      TYPE_PFN_CERT_STORE_PROV_GET_CTL_PROPERTY typedef proto WIN_STD_CALL_CONV :HCERTSTOREPROV, :PCCTL_CONTEXT, :DWORD, :DWORD, :ptr, :ptr DWORD
      PFN_CERT_STORE_PROV_GET_CTL_PROPERTY typedef ptr TYPE_PFN_CERT_STORE_PROV_GET_CTL_PROPERTY

      @DefProto DllImport, CertDuplicateStore, WIN_STD_CALL_CONV,, <:HCERTSTORE>, 4
      CERT_STORE_SAVE_AS_STORE equ 1
      CERT_STORE_SAVE_AS_PKCS7 equ 2
      CERT_STORE_SAVE_AS_PKCS12 equ 3
      CERT_STORE_SAVE_TO_FILE equ 1
      CERT_STORE_SAVE_TO_MEMORY equ 2
      CERT_STORE_SAVE_TO_FILENAME_A equ 3
      CERT_STORE_SAVE_TO_FILENAME_W equ 4
      CERT_STORE_SAVE_TO_FILENAME equ <CERT_STORE_SAVE_TO_FILENAME_W>
      @DefProto DllImport, CertSaveStore, WIN_STD_CALL_CONV,, <:HCERTSTORE, :DWORD, :DWORD, :DWORD, :ptr, :DWORD>, 24
      CERT_CLOSE_STORE_FORCE_FLAG equ 00000001h
      CERT_CLOSE_STORE_CHECK_FLAG equ 00000002h
      @DefProto DllImport, CertCloseStore, WIN_STD_CALL_CONV,, <:HCERTSTORE, :DWORD>, 8
      @DefProto DllImport, CertGetSubjectCertificateFromStore, WIN_STD_CALL_CONV,, <:HCERTSTORE, :DWORD, :PCERT_INFO>, 12
      @DefProto DllImport, CertEnumCertificatesInStore, WIN_STD_CALL_CONV,, <:HCERTSTORE, :PCCERT_CONTEXT>, 8
      @DefProto DllImport, CertFindCertificateInStore, WIN_STD_CALL_CONV,, <:HCERTSTORE, :DWORD, :DWORD, :DWORD, :ptr, :PCCERT_CONTEXT>, 24
      CERT_COMPARE_MASK equ 0FFFFh
      CERT_COMPARE_SHIFT equ 16
      CERT_COMPARE_ANY equ 0
      CERT_COMPARE_SHA1_HASH equ 1
      CERT_COMPARE_NAME equ 2
      CERT_COMPARE_ATTR equ 3
      CERT_COMPARE_MD5_HASH equ 4
      CERT_COMPARE_PROPERTY equ 5
      CERT_COMPARE_PUBLIC_KEY equ 6
      CERT_COMPARE_HASH equ <CERT_COMPARE_SHA1_HASH>
      CERT_COMPARE_NAME_STR_A equ 7
      CERT_COMPARE_NAME_STR_W equ 8
      CERT_COMPARE_KEY_SPEC equ 9
      CERT_COMPARE_ENHKEY_USAGE equ 10
      CERT_COMPARE_CTL_USAGE equ <CERT_COMPARE_ENHKEY_USAGE>
      CERT_COMPARE_SUBJECT_CERT equ 11
      CERT_COMPARE_ISSUER_OF equ 12
      CERT_COMPARE_EXISTING equ 13
      CERT_COMPARE_SIGNATURE_HASH equ 14
      CERT_COMPARE_KEY_IDENTIFIER equ 15
      CERT_COMPARE_CERT_ID equ 16
      CERT_COMPARE_CROSS_CERT_DIST_POINTS equ 17
      CERT_COMPARE_PUBKEY_MD5_HASH equ 18
      CERT_COMPARE_SUBJECT_INFO_ACCESS equ 19
      CERT_COMPARE_HASH_STR equ 20
      CERT_COMPARE_HAS_PRIVATE_KEY equ 21
      CERT_FIND_ANY equ (CERT_COMPARE_ANY shl CERT_COMPARE_SHIFT)
      CERT_FIND_SHA1_HASH equ (CERT_COMPARE_SHA1_HASH shl CERT_COMPARE_SHIFT)
      CERT_FIND_MD5_HASH equ (CERT_COMPARE_MD5_HASH shl CERT_COMPARE_SHIFT)
      CERT_FIND_SIGNATURE_HASH equ (CERT_COMPARE_SIGNATURE_HASH shl CERT_COMPARE_SHIFT)
      CERT_FIND_KEY_IDENTIFIER equ (CERT_COMPARE_KEY_IDENTIFIER shl CERT_COMPARE_SHIFT)
      CERT_FIND_HASH equ <CERT_FIND_SHA1_HASH>
      CERT_FIND_PROPERTY equ (CERT_COMPARE_PROPERTY shl CERT_COMPARE_SHIFT)
      CERT_FIND_PUBLIC_KEY equ (CERT_COMPARE_PUBLIC_KEY shl CERT_COMPARE_SHIFT)
      CERT_FIND_SUBJECT_NAME equ (CERT_COMPARE_NAME shl CERT_COMPARE_SHIFT or CERT_INFO_SUBJECT_FLAG)
      CERT_FIND_SUBJECT_ATTR equ (CERT_COMPARE_ATTR shl CERT_COMPARE_SHIFT or CERT_INFO_SUBJECT_FLAG)
      CERT_FIND_ISSUER_NAME equ (CERT_COMPARE_NAME shl CERT_COMPARE_SHIFT or CERT_INFO_ISSUER_FLAG)
      CERT_FIND_ISSUER_ATTR equ (CERT_COMPARE_ATTR shl CERT_COMPARE_SHIFT or CERT_INFO_ISSUER_FLAG)
      CERT_FIND_SUBJECT_STR_A equ (CERT_COMPARE_NAME_STR_A shl CERT_COMPARE_SHIFT or CERT_INFO_SUBJECT_FLAG)
      CERT_FIND_SUBJECT_STR_W equ (CERT_COMPARE_NAME_STR_W shl CERT_COMPARE_SHIFT or CERT_INFO_SUBJECT_FLAG)
      CERT_FIND_SUBJECT_STR equ <CERT_FIND_SUBJECT_STR_W>
      CERT_FIND_ISSUER_STR_A equ (CERT_COMPARE_NAME_STR_A shl CERT_COMPARE_SHIFT or CERT_INFO_ISSUER_FLAG)
      CERT_FIND_ISSUER_STR_W equ (CERT_COMPARE_NAME_STR_W shl CERT_COMPARE_SHIFT or CERT_INFO_ISSUER_FLAG)
      CERT_FIND_ISSUER_STR equ <CERT_FIND_ISSUER_STR_W>
      CERT_FIND_KEY_SPEC equ (CERT_COMPARE_KEY_SPEC shl CERT_COMPARE_SHIFT)
      CERT_FIND_ENHKEY_USAGE equ (CERT_COMPARE_ENHKEY_USAGE shl CERT_COMPARE_SHIFT)
      CERT_FIND_CTL_USAGE equ <CERT_FIND_ENHKEY_USAGE>
      CERT_FIND_SUBJECT_CERT equ (CERT_COMPARE_SUBJECT_CERT shl CERT_COMPARE_SHIFT)
      CERT_FIND_ISSUER_OF equ (CERT_COMPARE_ISSUER_OF shl CERT_COMPARE_SHIFT)
      CERT_FIND_EXISTING equ (CERT_COMPARE_EXISTING shl CERT_COMPARE_SHIFT)
      CERT_FIND_CERT_ID equ (CERT_COMPARE_CERT_ID shl CERT_COMPARE_SHIFT)
      CERT_FIND_CROSS_CERT_DIST_POINTS equ (CERT_COMPARE_CROSS_CERT_DIST_POINTS shl CERT_COMPARE_SHIFT)
      CERT_FIND_PUBKEY_MD5_HASH equ (CERT_COMPARE_PUBKEY_MD5_HASH shl CERT_COMPARE_SHIFT)
      CERT_FIND_SUBJECT_INFO_ACCESS equ (CERT_COMPARE_SUBJECT_INFO_ACCESS shl CERT_COMPARE_SHIFT)
      CERT_FIND_HASH_STR equ (CERT_COMPARE_HASH_STR shl CERT_COMPARE_SHIFT)
      CERT_FIND_HAS_PRIVATE_KEY equ (CERT_COMPARE_HAS_PRIVATE_KEY shl CERT_COMPARE_SHIFT)
      CERT_FIND_OPTIONAL_ENHKEY_USAGE_FLAG equ 1h
      CERT_FIND_EXT_ONLY_ENHKEY_USAGE_FLAG equ 2h
      CERT_FIND_PROP_ONLY_ENHKEY_USAGE_FLAG equ 4h
      CERT_FIND_NO_ENHKEY_USAGE_FLAG equ 8h
      CERT_FIND_OR_ENHKEY_USAGE_FLAG equ 10h
      CERT_FIND_VALID_ENHKEY_USAGE_FLAG equ 20h
      CERT_FIND_OPTIONAL_CTL_USAGE_FLAG equ <CERT_FIND_OPTIONAL_ENHKEY_USAGE_FLAG>
      CERT_FIND_EXT_ONLY_CTL_USAGE_FLAG equ <CERT_FIND_EXT_ONLY_ENHKEY_USAGE_FLAG>
      CERT_FIND_PROP_ONLY_CTL_USAGE_FLAG equ <CERT_FIND_PROP_ONLY_ENHKEY_USAGE_FLAG>
      CERT_FIND_NO_CTL_USAGE_FLAG equ <CERT_FIND_NO_ENHKEY_USAGE_FLAG>
      CERT_FIND_OR_CTL_USAGE_FLAG equ <CERT_FIND_OR_ENHKEY_USAGE_FLAG>
      CERT_FIND_VALID_CTL_USAGE_FLAG equ <CERT_FIND_VALID_ENHKEY_USAGE_FLAG>
      @DefProto DllImport, CertGetIssuerCertificateFromStore, WIN_STD_CALL_CONV,, <:HCERTSTORE, :PCCERT_CONTEXT, :PCCERT_CONTEXT, :ptr DWORD>, 16
      @DefProto DllImport, CertVerifySubjectCertificateContext, WIN_STD_CALL_CONV,, <:PCCERT_CONTEXT, :PCCERT_CONTEXT, :ptr DWORD>, 12
      @DefProto DllImport, CertDuplicateCertificateContext, WIN_STD_CALL_CONV,, <:PCCERT_CONTEXT>, 4
      @DefProto DllImport, CertCreateCertificateContext, WIN_STD_CALL_CONV,, <:DWORD, :ptr BYTE, :DWORD>, 12
      @DefProto DllImport, CertFreeCertificateContext, WIN_STD_CALL_CONV,, <:PCCERT_CONTEXT>, 4
      @DefProto DllImport, CertSetCertificateContextProperty, WIN_STD_CALL_CONV,, <:PCCERT_CONTEXT, :DWORD, :DWORD, :ptr>, 16
      CERT_SET_PROPERTY_IGNORE_PERSIST_ERROR_FLAG equ 80000000h
      CERT_SET_PROPERTY_INHIBIT_PERSIST_FLAG equ 40000000h
      @DefProto DllImport, CertGetCertificateContextProperty, WIN_STD_CALL_CONV,, <:PCCERT_CONTEXT, :DWORD, :ptr, :ptr DWORD>, 16
      @DefProto DllImport, CertEnumCertificateContextProperties, WIN_STD_CALL_CONV,, <:PCCERT_CONTEXT, :DWORD>, 8
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_PHONE_RESTRICTED or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      @DefProto DllImport, CertCreateCTLEntryFromCertificateContextProperties, WIN_STD_CALL_CONV,, <:PCCERT_CONTEXT, :DWORD, :PCRYPT_ATTRIBUTE, :DWORD, :ptr, :PCTL_ENTRY, :ptr DWORD>, 28
      CTL_ENTRY_FROM_PROP_CHAIN_FLAG equ 1h
      @DefProto DllImport, CertSetCertificateContextPropertiesFromCTLEntry, WIN_STD_CALL_CONV,, <:PCCERT_CONTEXT, :PCTL_ENTRY, :DWORD>, 12
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      @DefProto DllImport, CertGetCRLFromStore, WIN_STD_CALL_CONV,, <:HCERTSTORE, :PCCERT_CONTEXT, :PCCRL_CONTEXT, :ptr DWORD>, 16
      @DefProto DllImport, CertEnumCRLsInStore, WIN_STD_CALL_CONV,, <:HCERTSTORE, :PCCRL_CONTEXT>, 8
      @DefProto DllImport, CertFindCRLInStore, WIN_STD_CALL_CONV,, <:HCERTSTORE, :DWORD, :DWORD, :DWORD, :ptr, :PCCRL_CONTEXT>, 24
      CRL_FIND_ANY equ 0
      CRL_FIND_ISSUED_BY equ 1
      CRL_FIND_EXISTING equ 2
      CRL_FIND_ISSUED_FOR equ 3
      CRL_FIND_ISSUED_BY_AKI_FLAG equ 1h
      CRL_FIND_ISSUED_BY_SIGNATURE_FLAG equ 2h
      CRL_FIND_ISSUED_BY_DELTA_FLAG equ 4h
      CRL_FIND_ISSUED_BY_BASE_FLAG equ 8h
      CRL_FIND_ISSUED_FOR_PARA struct
        pSubjectCert PCCERT_CONTEXT ?
        pIssuerCert PCCERT_CONTEXT ?
      CRL_FIND_ISSUED_FOR_PARA ends
      _CRL_FIND_ISSUED_FOR_PARA typedef CRL_FIND_ISSUED_FOR_PARA
      PCRL_FIND_ISSUED_FOR_PARA typedef ptr CRL_FIND_ISSUED_FOR_PARA
      CRL_FIND_ISSUED_FOR_SET_STRONG_PROPERTIES_FLAG equ 10h
      @DefProto DllImport, CertDuplicateCRLContext, WIN_STD_CALL_CONV,, <:PCCRL_CONTEXT>, 4
      @DefProto DllImport, CertCreateCRLContext, WIN_STD_CALL_CONV,, <:DWORD, :ptr BYTE, :DWORD>, 12
      @DefProto DllImport, CertFreeCRLContext, WIN_STD_CALL_CONV,, <:PCCRL_CONTEXT>, 4
      @DefProto DllImport, CertSetCRLContextProperty, WIN_STD_CALL_CONV,, <:PCCRL_CONTEXT, :DWORD, :DWORD, :ptr>, 16
      @DefProto DllImport, CertGetCRLContextProperty, WIN_STD_CALL_CONV,, <:PCCRL_CONTEXT, :DWORD, :ptr, :ptr DWORD>, 16
      @DefProto DllImport, CertEnumCRLContextProperties, WIN_STD_CALL_CONV,, <:PCCRL_CONTEXT, :DWORD>, 8
      @DefProto DllImport, CertFindCertificateInCRL, WIN_STD_CALL_CONV,, <:PCCERT_CONTEXT, :PCCRL_CONTEXT, :DWORD, :ptr, :ptr PCRL_ENTRY>, 20
      @DefProto DllImport, CertIsValidCRLForCertificate, WIN_STD_CALL_CONV,, <:PCCERT_CONTEXT, :PCCRL_CONTEXT, :DWORD, :ptr>, 16
      CERT_STORE_ADD_NEW equ 1
      CERT_STORE_ADD_USE_EXISTING equ 2
      CERT_STORE_ADD_REPLACE_EXISTING equ 3
      CERT_STORE_ADD_ALWAYS equ 4
      CERT_STORE_ADD_REPLACE_EXISTING_INHERIT_PROPERTIES equ 5
      CERT_STORE_ADD_NEWER equ 6
      CERT_STORE_ADD_NEWER_INHERIT_PROPERTIES equ 7
      @DefProto DllImport, CertAddEncodedCertificateToStore, WIN_STD_CALL_CONV,, <:HCERTSTORE, :DWORD, :ptr BYTE, :DWORD, :DWORD, :ptr PCCERT_CONTEXT>, 24
      @DefProto DllImport, CertAddCertificateContextToStore, WIN_STD_CALL_CONV,, <:HCERTSTORE, :PCCERT_CONTEXT, :DWORD, :ptr PCCERT_CONTEXT>, 16
      CERT_STORE_CERTIFICATE_CONTEXT equ 1
      CERT_STORE_CRL_CONTEXT equ 2
      CERT_STORE_CTL_CONTEXT equ 3
      CERT_STORE_ALL_CONTEXT_FLAG equ (not 0)
      CERT_STORE_CERTIFICATE_CONTEXT_FLAG equ (1 shl CERT_STORE_CERTIFICATE_CONTEXT)
      CERT_STORE_CRL_CONTEXT_FLAG equ (1 shl CERT_STORE_CRL_CONTEXT)
      CERT_STORE_CTL_CONTEXT_FLAG equ (1 shl CERT_STORE_CTL_CONTEXT)
      @DefProto DllImport, CertAddSerializedElementToStore, WIN_STD_CALL_CONV,, <:HCERTSTORE, :ptr BYTE, :DWORD, :DWORD, :DWORD, :DWORD, :ptr DWORD, :ptr ptr>, 32
      @DefProto DllImport, CertDeleteCertificateFromStore, WIN_STD_CALL_CONV,, <:PCCERT_CONTEXT>, 4
      @DefProto DllImport, CertAddEncodedCRLToStore, WIN_STD_CALL_CONV,, <:HCERTSTORE, :DWORD, :ptr BYTE, :DWORD, :DWORD, :ptr PCCRL_CONTEXT>, 24
      @DefProto DllImport, CertAddCRLContextToStore, WIN_STD_CALL_CONV,, <:HCERTSTORE, :PCCRL_CONTEXT, :DWORD, :ptr PCCRL_CONTEXT>, 16
      @DefProto DllImport, CertDeleteCRLFromStore, WIN_STD_CALL_CONV,, <:PCCRL_CONTEXT>, 4
      @DefProto DllImport, CertSerializeCertificateStoreElement, WIN_STD_CALL_CONV,, <:PCCERT_CONTEXT, :DWORD, :ptr BYTE, :ptr DWORD>, 16
      @DefProto DllImport, CertSerializeCRLStoreElement, WIN_STD_CALL_CONV,, <:PCCRL_CONTEXT, :DWORD, :ptr BYTE, :ptr DWORD>, 16
      @DefProto DllImport, CertDuplicateCTLContext, WIN_STD_CALL_CONV,, <:PCCTL_CONTEXT>, 4
      @DefProto DllImport, CertCreateCTLContext, WIN_STD_CALL_CONV,, <:DWORD, :ptr BYTE, :DWORD>, 12
      @DefProto DllImport, CertFreeCTLContext, WIN_STD_CALL_CONV,, <:PCCTL_CONTEXT>, 4
      @DefProto DllImport, CertSetCTLContextProperty, WIN_STD_CALL_CONV,, <:PCCTL_CONTEXT, :DWORD, :DWORD, :ptr>, 16
      @DefProto DllImport, CertGetCTLContextProperty, WIN_STD_CALL_CONV,, <:PCCTL_CONTEXT, :DWORD, :ptr, :ptr DWORD>, 16
      @DefProto DllImport, CertEnumCTLContextProperties, WIN_STD_CALL_CONV,, <:PCCTL_CONTEXT, :DWORD>, 8
      @DefProto DllImport, CertEnumCTLsInStore, WIN_STD_CALL_CONV,, <:HCERTSTORE, :PCCTL_CONTEXT>, 8
      @DefProto DllImport, CertFindSubjectInCTL, WIN_STD_CALL_CONV,, <:DWORD, :DWORD, :ptr, :PCCTL_CONTEXT, :DWORD>, 20
      CTL_ANY_SUBJECT_TYPE equ 1
      CTL_CERT_SUBJECT_TYPE equ 2
      CTL_ANY_SUBJECT_INFO struct
        SubjectAlgorithm CRYPT_ALGORITHM_IDENTIFIER <>
        SubjectIdentifier CRYPT_DATA_BLOB <>
      CTL_ANY_SUBJECT_INFO ends
      _CTL_ANY_SUBJECT_INFO typedef CTL_ANY_SUBJECT_INFO
      PCTL_ANY_SUBJECT_INFO typedef ptr CTL_ANY_SUBJECT_INFO
      @DefProto DllImport, CertFindCTLInStore, WIN_STD_CALL_CONV,, <:HCERTSTORE, :DWORD, :DWORD, :DWORD, :ptr, :PCCTL_CONTEXT>, 24
      CTL_FIND_ANY equ 0
      CTL_FIND_SHA1_HASH equ 1
      CTL_FIND_MD5_HASH equ 2
      CTL_FIND_USAGE equ 3
      CTL_FIND_SUBJECT equ 4
      CTL_FIND_EXISTING equ 5
      CTL_FIND_USAGE_PARA struct
        cbSize DWORD ?
        SubjectUsage CTL_USAGE <>
        ListIdentifier CRYPT_DATA_BLOB <>
        pSigner PCERT_INFO ?
      CTL_FIND_USAGE_PARA ends
      _CTL_FIND_USAGE_PARA typedef CTL_FIND_USAGE_PARA
      PCTL_FIND_USAGE_PARA typedef ptr CTL_FIND_USAGE_PARA
      CTL_FIND_NO_LIST_ID_CBDATA equ 0FFFFFFFFh
      CTL_FIND_NO_SIGNER_PTR equ ((PCERT_INFO) - 1)
      CTL_FIND_SAME_USAGE_FLAG equ 1h
      CTL_FIND_SUBJECT_PARA struct
        cbSize DWORD ?
        pUsagePara PCTL_FIND_USAGE_PARA ?
        dwSubjectType DWORD ?
        pvSubject POINTER ?
      CTL_FIND_SUBJECT_PARA ends
      _CTL_FIND_SUBJECT_PARA typedef CTL_FIND_SUBJECT_PARA
      PCTL_FIND_SUBJECT_PARA typedef ptr CTL_FIND_SUBJECT_PARA
      @DefProto DllImport, CertAddEncodedCTLToStore, WIN_STD_CALL_CONV,, <:HCERTSTORE, :DWORD, :ptr BYTE, :DWORD, :DWORD, :ptr PCCTL_CONTEXT>, 24
      @DefProto DllImport, CertAddCTLContextToStore, WIN_STD_CALL_CONV,, <:HCERTSTORE, :PCCTL_CONTEXT, :DWORD, :ptr PCCTL_CONTEXT>, 16
      @DefProto DllImport, CertSerializeCTLStoreElement, WIN_STD_CALL_CONV,, <:PCCTL_CONTEXT, :DWORD, :ptr BYTE, :ptr DWORD>, 16
      @DefProto DllImport, CertDeleteCTLFromStore, WIN_STD_CALL_CONV,, <:PCCTL_CONTEXT>, 4
      @DefProto DllImport, CertAddCertificateLinkToStore, WIN_STD_CALL_CONV,, <:HCERTSTORE, :PCCERT_CONTEXT, :DWORD, :ptr PCCERT_CONTEXT>, 16
      @DefProto DllImport, CertAddCRLLinkToStore, WIN_STD_CALL_CONV,, <:HCERTSTORE, :PCCRL_CONTEXT, :DWORD, :ptr PCCRL_CONTEXT>, 16
      @DefProto DllImport, CertAddCTLLinkToStore, WIN_STD_CALL_CONV,, <:HCERTSTORE, :PCCTL_CONTEXT, :DWORD, :ptr PCCTL_CONTEXT>, 16
      @DefProto DllImport, CertAddStoreToCollection, WIN_STD_CALL_CONV,, <:HCERTSTORE, :HCERTSTORE, :DWORD, :DWORD>, 16
      @DefProto DllImport, CertRemoveStoreFromCollection, WIN_STD_CALL_CONV,, <:HCERTSTORE, :HCERTSTORE>, 8
      @DefProto DllImport, CertControlStore, WIN_STD_CALL_CONV,, <:HCERTSTORE, :DWORD, :DWORD, :ptr>, 16
      CERT_STORE_CTRL_RESYNC equ 1
      CERT_STORE_CTRL_NOTIFY_CHANGE equ 2
      CERT_STORE_CTRL_COMMIT equ 3
      CERT_STORE_CTRL_AUTO_RESYNC equ 4
      CERT_STORE_CTRL_CANCEL_NOTIFY equ 5
      CERT_STORE_CTRL_INHIBIT_DUPLICATE_HANDLE_FLAG equ 1h
      CERT_STORE_CTRL_COMMIT_FORCE_FLAG equ 1h
      CERT_STORE_CTRL_COMMIT_CLEAR_FLAG equ 2h
      CERT_STORE_LOCALIZED_NAME_PROP_ID equ 1000h
      @DefProto DllImport, CertSetStoreProperty, WIN_STD_CALL_CONV,, <:HCERTSTORE, :DWORD, :DWORD, :ptr>, 16
      @DefProto DllImport, CertGetStoreProperty, WIN_STD_CALL_CONV,, <:HCERTSTORE, :DWORD, :ptr, :ptr DWORD>, 16
      TYPE_PFN_CERT_CREATE_CONTEXT_SORT_FUNC typedef proto WIN_STD_CALL_CONV :DWORD, :DWORD, :DWORD, :ptr
      PFN_CERT_CREATE_CONTEXT_SORT_FUNC typedef ptr TYPE_PFN_CERT_CREATE_CONTEXT_SORT_FUNC

      CERT_CREATE_CONTEXT_PARA struct
        cbSize DWORD ?
        pfnFree PFN_CRYPT_FREE ?
        pvFree POINTER ?
        pfnSort PFN_CERT_CREATE_CONTEXT_SORT_FUNC ?
        pvSort POINTER ?
      CERT_CREATE_CONTEXT_PARA ends
      _CERT_CREATE_CONTEXT_PARA typedef CERT_CREATE_CONTEXT_PARA
      PCERT_CREATE_CONTEXT_PARA typedef ptr CERT_CREATE_CONTEXT_PARA
      @DefProto DllImport, CertCreateContext, WIN_STD_CALL_CONV,, <:DWORD, :DWORD, :ptr BYTE, :DWORD, :DWORD, :PCERT_CREATE_CONTEXT_PARA>, 24
      CERT_CREATE_CONTEXT_NOCOPY_FLAG equ 1h
      CERT_CREATE_CONTEXT_SORTED_FLAG equ 2h
      CERT_CREATE_CONTEXT_NO_HCRYPTMSG_FLAG equ 4h
      CERT_CREATE_CONTEXT_NO_ENTRY_FLAG equ 8h
      CERT_SYSTEM_STORE_INFO struct
        cbSize DWORD ?
      CERT_SYSTEM_STORE_INFO ends
      _CERT_SYSTEM_STORE_INFO typedef CERT_SYSTEM_STORE_INFO
      PCERT_SYSTEM_STORE_INFO typedef ptr CERT_SYSTEM_STORE_INFO
      CERT_PHYSICAL_STORE_INFO struct
        cbSize DWORD ?
        pszOpenStoreProvider LPSTR ?
        dwOpenEncodingType DWORD ?
        dwOpenFlags DWORD ?
        OpenParameters CRYPT_DATA_BLOB <>
        dwFlags DWORD ?
        dwPriority DWORD ?
      CERT_PHYSICAL_STORE_INFO ends
      _CERT_PHYSICAL_STORE_INFO typedef CERT_PHYSICAL_STORE_INFO
      PCERT_PHYSICAL_STORE_INFO typedef ptr CERT_PHYSICAL_STORE_INFO
      CERT_PHYSICAL_STORE_ADD_ENABLE_FLAG equ 1h
      CERT_PHYSICAL_STORE_OPEN_DISABLE_FLAG equ 2h
      CERT_PHYSICAL_STORE_REMOTE_OPEN_DISABLE_FLAG equ 4h
      CERT_PHYSICAL_STORE_INSERT_COMPUTER_NAME_ENABLE_FLAG equ 8h
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_PHONE_RESTRICTED or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      @DefProto DllImport, CertRegisterSystemStore, WIN_STD_CALL_CONV,, <:ptr, :DWORD, :PCERT_SYSTEM_STORE_INFO, :ptr>, 16
      @DefProto DllImport, CertRegisterPhysicalStore, WIN_STD_CALL_CONV,, <:ptr, :DWORD, :LPCWSTR, :PCERT_PHYSICAL_STORE_INFO, :ptr>, 20
      @DefProto DllImport, CertUnregisterSystemStore, WIN_STD_CALL_CONV,, <:ptr, :DWORD>, 8
      @DefProto DllImport, CertUnregisterPhysicalStore, WIN_STD_CALL_CONV,, <:ptr, :DWORD, :LPCWSTR>, 12
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      TYPE_PFN_CERT_ENUM_SYSTEM_STORE_LOCATION typedef proto WIN_STD_CALL_CONV :LPCWSTR, :DWORD, :ptr, :ptr
      PFN_CERT_ENUM_SYSTEM_STORE_LOCATION typedef ptr TYPE_PFN_CERT_ENUM_SYSTEM_STORE_LOCATION

      TYPE_PFN_CERT_ENUM_SYSTEM_STORE typedef proto WIN_STD_CALL_CONV :ptr, :DWORD, :PCERT_SYSTEM_STORE_INFO, :ptr, :ptr
      PFN_CERT_ENUM_SYSTEM_STORE typedef ptr TYPE_PFN_CERT_ENUM_SYSTEM_STORE

      TYPE_PFN_CERT_ENUM_PHYSICAL_STORE typedef proto WIN_STD_CALL_CONV :ptr, :DWORD, :LPCWSTR, :PCERT_PHYSICAL_STORE_INFO, :ptr, :ptr
      PFN_CERT_ENUM_PHYSICAL_STORE typedef ptr TYPE_PFN_CERT_ENUM_PHYSICAL_STORE

      CERT_PHYSICAL_STORE_PREDEFINED_ENUM_FLAG equ 1h
      CERT_PHYSICAL_STORE_DEFAULT_NAME equ <L(".Default")>
      CERT_PHYSICAL_STORE_GROUP_POLICY_NAME equ <L(".GroupPolicy")>
      CERT_PHYSICAL_STORE_LOCAL_MACHINE_NAME equ <L(".LocalMachine")>
      CERT_PHYSICAL_STORE_DS_USER_CERTIFICATE_NAME equ <L(".UserCertificate")>
      CERT_PHYSICAL_STORE_LOCAL_MACHINE_GROUP_POLICY_NAME equ <L(".LocalMachineGroupPolicy")>
      CERT_PHYSICAL_STORE_ENTERPRISE_NAME equ <L(".Enterprise")>
      CERT_PHYSICAL_STORE_AUTH_ROOT_NAME equ <L(".AuthRoot")>
      CERT_PHYSICAL_STORE_SMART_CARD_NAME equ <L(".SmartCard")>
      @DefProto DllImport, CertEnumSystemStoreLocation, WIN_STD_CALL_CONV,, <:DWORD, :ptr, :PFN_CERT_ENUM_SYSTEM_STORE_LOCATION>, 12
      @DefProto DllImport, CertEnumSystemStore, WIN_STD_CALL_CONV,, <:DWORD, :ptr, :ptr, :PFN_CERT_ENUM_SYSTEM_STORE>, 16
      @DefProto DllImport, CertEnumPhysicalStore, WIN_STD_CALL_CONV,, <:ptr, :DWORD, :ptr, :PFN_CERT_ENUM_PHYSICAL_STORE>, 16
      CRYPT_OID_OPEN_SYSTEM_STORE_PROV_FUNC equ <"CertDllOpenSystemStoreProv">
      CRYPT_OID_REGISTER_SYSTEM_STORE_FUNC equ <"CertDllRegisterSystemStore">
      CRYPT_OID_UNREGISTER_SYSTEM_STORE_FUNC equ <"CertDllUnregisterSystemStore">
      CRYPT_OID_ENUM_SYSTEM_STORE_FUNC equ <"CertDllEnumSystemStore">
      CRYPT_OID_REGISTER_PHYSICAL_STORE_FUNC equ <"CertDllRegisterPhysicalStore">
      CRYPT_OID_UNREGISTER_PHYSICAL_STORE_FUNC equ <"CertDllUnregisterPhysicalStore">
      CRYPT_OID_ENUM_PHYSICAL_STORE_FUNC equ <"CertDllEnumPhysicalStore">
      CRYPT_OID_SYSTEM_STORE_LOCATION_VALUE_NAME equ <L("SystemStoreLocation")>
      @DefProto DllImport, CertGetEnhancedKeyUsage, WIN_STD_CALL_CONV,, <:PCCERT_CONTEXT, :DWORD, :PCERT_ENHKEY_USAGE, :ptr DWORD>, 16
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_PHONE_RESTRICTED or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      @DefProto DllImport, CertSetEnhancedKeyUsage, WIN_STD_CALL_CONV,, <:PCCERT_CONTEXT, :PCERT_ENHKEY_USAGE>, 8
      @DefProto DllImport, CertAddEnhancedKeyUsageIdentifier, WIN_STD_CALL_CONV,, <:PCCERT_CONTEXT, :LPCSTR>, 8
      @DefProto DllImport, CertRemoveEnhancedKeyUsageIdentifier, WIN_STD_CALL_CONV,, <:PCCERT_CONTEXT, :LPCSTR>, 8
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      @DefProto DllImport, CertGetValidUsages, WIN_STD_CALL_CONV,, <:DWORD, :ptr PCCERT_CONTEXT, :ptr SDWORD, :ptr LPSTR, :ptr DWORD>, 20
      @DefProto DllImport, CryptMsgGetAndVerifySigner, WIN_STD_CALL_CONV,, <:HCRYPTMSG, :DWORD, :ptr HCERTSTORE, :DWORD, :ptr PCCERT_CONTEXT, :ptr DWORD>, 24
      CMSG_TRUSTED_SIGNER_FLAG equ 1h
      CMSG_SIGNER_ONLY_FLAG equ 2h
      CMSG_USE_SIGNER_INDEX_FLAG equ 4h
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_PHONE_RESTRICTED or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      @DefProto DllImport, CryptMsgSignCTL, WIN_STD_CALL_CONV,, <:DWORD, :ptr BYTE, :DWORD, :PCMSG_SIGNED_ENCODE_INFO, :DWORD, :ptr BYTE, :ptr DWORD>, 28
      CMSG_CMS_ENCAPSULATED_CTL_FLAG equ 00008000h
      @DefProto DllImport, CryptMsgEncodeAndSignCTL, WIN_STD_CALL_CONV,, <:DWORD, :PCTL_INFO, :PCMSG_SIGNED_ENCODE_INFO, :DWORD, :ptr BYTE, :ptr DWORD>, 24
      CMSG_ENCODE_SORTED_CTL_FLAG equ 1h
      CMSG_ENCODE_HASHED_SUBJECT_IDENTIFIER_FLAG equ 2h
      @DefProto DllImport, CertFindSubjectInSortedCTL, WIN_STD_CALL_CONV,, <:PCRYPT_DATA_BLOB, :PCCTL_CONTEXT, :DWORD, :ptr, :PCRYPT_DER_BLOB>, 20
      @DefProto DllImport, CertEnumSubjectInSortedCTL, WIN_STD_CALL_CONV,, <:PCCTL_CONTEXT, :ptr ptr, :PCRYPT_DER_BLOB, :PCRYPT_DER_BLOB>, 16
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      CTL_VERIFY_USAGE_PARA struct
        cbSize DWORD ?
        ListIdentifier CRYPT_DATA_BLOB <>
        cCtlStore DWORD ?
        rghCtlStore POINTER ?
        cSignerStore DWORD ?
        rghSignerStore POINTER ?
      CTL_VERIFY_USAGE_PARA ends
      _CTL_VERIFY_USAGE_PARA typedef CTL_VERIFY_USAGE_PARA
      PCTL_VERIFY_USAGE_PARA typedef ptr CTL_VERIFY_USAGE_PARA
      CTL_VERIFY_USAGE_STATUS struct
        cbSize DWORD ?
        dwError DWORD ?
        dwFlags DWORD ?
        ppCtl POINTER ?
        dwCtlEntryIndex DWORD ?
        ppSigner POINTER ?
        dwSignerIndex DWORD ?
      CTL_VERIFY_USAGE_STATUS ends
      _CTL_VERIFY_USAGE_STATUS typedef CTL_VERIFY_USAGE_STATUS
      PCTL_VERIFY_USAGE_STATUS typedef ptr CTL_VERIFY_USAGE_STATUS
      CERT_VERIFY_INHIBIT_CTL_UPDATE_FLAG equ 1h
      CERT_VERIFY_TRUSTED_SIGNERS_FLAG equ 2h
      CERT_VERIFY_NO_TIME_CHECK_FLAG equ 4h
      CERT_VERIFY_ALLOW_MORE_USAGE_FLAG equ 8h
      CERT_VERIFY_UPDATED_CTL_FLAG equ 1h
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_PHONE_RESTRICTED or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      @DefProto DllImport, CertVerifyCTLUsage, WIN_STD_CALL_CONV,, <:DWORD, :DWORD, :ptr, :PCTL_USAGE, :DWORD, :PCTL_VERIFY_USAGE_PARA, :PCTL_VERIFY_USAGE_STATUS>, 28
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      CERT_REVOCATION_CRL_INFO struct
        cbSize DWORD ?
        pBaseCrlContext PCCRL_CONTEXT ?
        pDeltaCrlContext PCCRL_CONTEXT ?
        pCrlEntry PCRL_ENTRY ?
        fDeltaCrlEntry BOOL ?
      CERT_REVOCATION_CRL_INFO ends
      _CERT_REVOCATION_CRL_INFO typedef CERT_REVOCATION_CRL_INFO
      PCERT_REVOCATION_CRL_INFO typedef ptr CERT_REVOCATION_CRL_INFO
      CERT_REVOCATION_CHAIN_PARA typedef _CERT_REVOCATION_CHAIN_PARA
      PCERT_REVOCATION_CHAIN_PARA typedef ptr _CERT_REVOCATION_CHAIN_PARA
      CERT_REVOCATION_PARA struct
        cbSize DWORD ?
        pIssuerCert PCCERT_CONTEXT ?
        cCertStore DWORD ?
        rgCertStore POINTER ?
        hCrlStore HCERTSTORE ?
        pftTimeToUse LPFILETIME ?
        ifdef CERT_REVOCATION_PARA_HAS_EXTRA_FIELDS
          dwUrlRetrievalTimeout DWORD ?
          fCheckFreshnessTime BOOL ?
          dwFreshnessTime DWORD ?
          pftCurrentTime LPFILETIME ?
          pCrlInfo PCERT_REVOCATION_CRL_INFO ?
          pftCacheResync LPFILETIME ?
          pChainPara PCERT_REVOCATION_CHAIN_PARA ?
        endif
      CERT_REVOCATION_PARA ends
      _CERT_REVOCATION_PARA typedef CERT_REVOCATION_PARA
      PCERT_REVOCATION_PARA typedef ptr CERT_REVOCATION_PARA
      CERT_REVOCATION_STATUS struct
        cbSize DWORD ?
        dwIndex DWORD ?
        dwError DWORD ?
        dwReason DWORD ?
        fHasFreshnessTime BOOL ?
        dwFreshnessTime DWORD ?
      CERT_REVOCATION_STATUS ends
      _CERT_REVOCATION_STATUS typedef CERT_REVOCATION_STATUS
      PCERT_REVOCATION_STATUS typedef ptr CERT_REVOCATION_STATUS
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_PHONE_RESTRICTED or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      @DefProto DllImport, CertVerifyRevocation, WIN_STD_CALL_CONV,, <:DWORD, :DWORD, :DWORD, :ptr PVOID, :DWORD, :PCERT_REVOCATION_PARA, :PCERT_REVOCATION_STATUS>, 28
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      CERT_CONTEXT_REVOCATION_TYPE equ 1
      CERT_VERIFY_REV_CHAIN_FLAG equ 00000001h
      CERT_VERIFY_CACHE_ONLY_BASED_REVOCATION equ 00000002h
      CERT_VERIFY_REV_ACCUMULATIVE_TIMEOUT_FLAG equ 00000004h
      CERT_VERIFY_REV_SERVER_OCSP_FLAG equ 00000008h
      CERT_VERIFY_REV_NO_OCSP_FAILOVER_TO_CRL_FLAG equ 00000010h
      CERT_VERIFY_REV_SERVER_OCSP_WIRE_ONLY_FLAG equ 00000020h
      CertCompareIntegerBlob proto WIN_STD_CALL_CONV :PCRYPT_INTEGER_BLOB, :PCRYPT_INTEGER_BLOB
      @DefProto DllImport, CertCompareCertificate, WIN_STD_CALL_CONV,, <:DWORD, :PCERT_INFO, :PCERT_INFO>, 12
      @DefProto DllImport, CertCompareCertificateName, WIN_STD_CALL_CONV,, <:DWORD, :PCERT_NAME_BLOB, :PCERT_NAME_BLOB>, 12
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_PHONE_RESTRICTED or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      @DefProto DllImport, CertIsRDNAttrsInCertificateName, WIN_STD_CALL_CONV,, <:DWORD, :DWORD, :PCERT_NAME_BLOB, :PCERT_RDN>, 16
      CERT_UNICODE_IS_RDN_ATTRS_FLAG equ 1h
      CERT_CASE_INSENSITIVE_IS_RDN_ATTRS_FLAG equ 2h
      @DefProto DllImport, CertComparePublicKeyInfo, WIN_STD_CALL_CONV,, <:DWORD, :PCERT_PUBLIC_KEY_INFO, :PCERT_PUBLIC_KEY_INFO>, 12
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      @DefProto DllImport, CertGetPublicKeyLength, WIN_STD_CALL_CONV,, <:DWORD, :PCERT_PUBLIC_KEY_INFO>, 8
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_PHONE_RESTRICTED or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      @DefProto DllImport, CryptVerifyCertificateSignature, WIN_STD_CALL_CONV,, <:HCRYPTPROV_LEGACY, :DWORD, :ptr BYTE, :DWORD, :PCERT_PUBLIC_KEY_INFO>, 20
      @DefProto DllImport, CryptVerifyCertificateSignatureEx, WIN_STD_CALL_CONV,, <:HCRYPTPROV_LEGACY, :DWORD, :DWORD, :ptr, :DWORD, :ptr, :DWORD, :ptr>, 32
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      CRYPT_VERIFY_CERT_SIGN_SUBJECT_BLOB equ 1
      CRYPT_VERIFY_CERT_SIGN_SUBJECT_CERT equ 2
      CRYPT_VERIFY_CERT_SIGN_SUBJECT_CRL equ 3
      CRYPT_VERIFY_CERT_SIGN_SUBJECT_OCSP_BASIC_SIGNED_RESPONSE equ 4
      CRYPT_VERIFY_CERT_SIGN_ISSUER_PUBKEY equ 1
      CRYPT_VERIFY_CERT_SIGN_ISSUER_CERT equ 2
      CRYPT_VERIFY_CERT_SIGN_ISSUER_CHAIN equ 3
      CRYPT_VERIFY_CERT_SIGN_ISSUER_NULL equ 4
      CRYPT_VERIFY_CERT_SIGN_DISABLE_MD2_MD4_FLAG equ 00000001h
      CRYPT_VERIFY_CERT_SIGN_SET_STRONG_PROPERTIES_FLAG equ 00000002h
      CRYPT_VERIFY_CERT_SIGN_RETURN_STRONG_PROPERTIES_FLAG equ 00000004h
      CRYPT_VERIFY_CERT_SIGN_STRONG_PROPERTIES_INFO struct
        CertSignHashCNGAlgPropData CRYPT_DATA_BLOB <>
        CertIssuerPubKeyBitLengthPropData CRYPT_DATA_BLOB <>
      CRYPT_VERIFY_CERT_SIGN_STRONG_PROPERTIES_INFO ends
      _CRYPT_VERIFY_CERT_SIGN_STRONG_PROPERTIES_INFO typedef CRYPT_VERIFY_CERT_SIGN_STRONG_PROPERTIES_INFO
      PCRYPT_VERIFY_CERT_SIGN_STRONG_PROPERTIES_INFO typedef ptr CRYPT_VERIFY_CERT_SIGN_STRONG_PROPERTIES_INFO
      CRYPT_VERIFY_CERT_SIGN_CHECK_WEAK_HASH_FLAG equ 00000008h
      CRYPT_VERIFY_CERT_SIGN_WEAK_HASH_INFO struct
        cCNGHashAlgid DWORD ?
        rgpwszCNGHashAlgid POINTER ?
        dwWeakIndex DWORD ?
      CRYPT_VERIFY_CERT_SIGN_WEAK_HASH_INFO ends
      _CRYPT_VERIFY_CERT_SIGN_WEAK_HASH_INFO typedef CRYPT_VERIFY_CERT_SIGN_WEAK_HASH_INFO
      PCRYPT_VERIFY_CERT_SIGN_WEAK_HASH_INFO typedef ptr CRYPT_VERIFY_CERT_SIGN_WEAK_HASH_INFO
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_PHONE_RESTRICTED or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      @DefProto DllImport, CertIsStrongHashToSign, WIN_STD_CALL_CONV,, <:PCCERT_STRONG_SIGN_PARA, :LPCWSTR, :PCCERT_CONTEXT>, 12
      @DefProto DllImport, CryptHashToBeSigned, WIN_STD_CALL_CONV,, <:HCRYPTPROV_LEGACY, :DWORD, :ptr BYTE, :DWORD, :ptr BYTE, :ptr DWORD>, 24
      @DefProto DllImport, CryptHashCertificate, WIN_STD_CALL_CONV,, <:HCRYPTPROV_LEGACY, :ALG_ID, :DWORD, :ptr BYTE, :DWORD, :ptr BYTE, :ptr DWORD>, 28
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      if (NTDDI_VERSION ge NTDDI_VISTA)
        @DefProto DllImport, CryptHashCertificate2, WIN_STD_CALL_CONV,, <:LPCWSTR, :DWORD, :ptr, :ptr BYTE, :DWORD, :ptr BYTE, :ptr DWORD>, 28
      endif
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_PHONE_RESTRICTED or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      @DefProto DllImport, CryptSignCertificate, WIN_STD_CALL_CONV,, <ifdef CMSG_SIGNER_ENCODE_INFO_HAS_IUM_FIELDS
        :BCRYPT_KEY_HANDLE,else
         :HCRYPTPROV_OR_NCRYPT_KEY_HANDLE,endif
       :DWORD, :DWORD, :ptr BYTE, :DWORD, :PCRYPT_ALGORITHM_IDENTIFIER, :ptr, :ptr BYTE, :ptr DWORD>, 40
      @DefProto DllImport, CryptSignAndEncodeCertificate, WIN_STD_CALL_CONV,, <ifdef CMSG_SIGNER_ENCODE_INFO_HAS_IUM_FIELDS
        :BCRYPT_KEY_HANDLE,else
         :HCRYPTPROV_OR_NCRYPT_KEY_HANDLE,endif
       :DWORD, :DWORD, :LPCSTR, :ptr, :PCRYPT_ALGORITHM_IDENTIFIER, :ptr, :ptr BYTE, :ptr DWORD>, 40
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      CRYPT_OID_EXTRACT_ENCODED_SIGNATURE_PARAMETERS_FUNC equ <"CryptDllExtractEncodedSignatureParameters">
      TYPE_PFN_CRYPT_EXTRACT_ENCODED_SIGNATURE_PARAMETERS_FUNC typedef proto WIN_STD_CALL_CONV :DWORD, :PCRYPT_ALGORITHM_IDENTIFIER, :ptr ptr, :ptr LPWSTR
      PFN_CRYPT_EXTRACT_ENCODED_SIGNATURE_PARAMETERS_FUNC typedef ptr TYPE_PFN_CRYPT_EXTRACT_ENCODED_SIGNATURE_PARAMETERS_FUNC

      CRYPT_OID_SIGN_AND_ENCODE_HASH_FUNC equ <"CryptDllSignAndEncodeHash">
      TYPE_PFN_CRYPT_SIGN_AND_ENCODE_HASH_FUNC typedef proto WIN_STD_CALL_CONV :NCRYPT_KEY_HANDLE, :DWORD, :PCRYPT_ALGORITHM_IDENTIFIER, :ptr, :LPCWSTR, :LPCWSTR, :ptr BYTE, :DWORD, :ptr BYTE, :ptr DWORD
      PFN_CRYPT_SIGN_AND_ENCODE_HASH_FUNC typedef ptr TYPE_PFN_CRYPT_SIGN_AND_ENCODE_HASH_FUNC

      CRYPT_OID_VERIFY_ENCODED_SIGNATURE_FUNC equ <"CryptDllVerifyEncodedSignature">
      TYPE_PFN_CRYPT_VERIFY_ENCODED_SIGNATURE_FUNC typedef proto WIN_STD_CALL_CONV :DWORD, :PCERT_PUBLIC_KEY_INFO, :PCRYPT_ALGORITHM_IDENTIFIER, :ptr, :LPCWSTR, :LPCWSTR, :ptr BYTE, :DWORD, :ptr BYTE, :DWORD
      PFN_CRYPT_VERIFY_ENCODED_SIGNATURE_FUNC typedef ptr TYPE_PFN_CRYPT_VERIFY_ENCODED_SIGNATURE_FUNC

      @DefProto DllImport, CertVerifyTimeValidity, WIN_STD_CALL_CONV,, <:LPFILETIME, :PCERT_INFO>, 8
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_PHONE_RESTRICTED or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      @DefProto DllImport, CertVerifyCRLTimeValidity, WIN_STD_CALL_CONV,, <:LPFILETIME, :PCRL_INFO>, 8
      @DefProto DllImport, CertVerifyValidityNesting, WIN_STD_CALL_CONV,, <:PCERT_INFO, :PCERT_INFO>, 8
      @DefProto DllImport, CertVerifyCRLRevocation, WIN_STD_CALL_CONV,, <:DWORD, :PCERT_INFO, :DWORD, :ptr PCRL_INFO>, 16
      @DefProto DllImport, CertAlgIdToOID, WIN_STD_CALL_CONV,, <:DWORD>, 4
      @DefProto DllImport, CertOIDToAlgId, WIN_STD_CALL_CONV,, <:LPCSTR>, 4
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      @DefProto DllImport, CertFindExtension, WIN_STD_CALL_CONV,, <:LPCSTR, :DWORD, :ptr CERT_EXTENSION>, 12
      @DefProto DllImport, CertFindAttribute, WIN_STD_CALL_CONV,, <:LPCSTR, :DWORD, :ptr CRYPT_ATTRIBUTE>, 12
      @DefProto DllImport, CertFindRDNAttr, WIN_STD_CALL_CONV,, <:LPCSTR, :PCERT_NAME_INFO>, 8
      @DefProto DllImport, CertGetIntendedKeyUsage, WIN_STD_CALL_CONV,, <:DWORD, :PCERT_INFO, :ptr BYTE, :DWORD>, 16
      HCRYPTDEFAULTCONTEXT typedef ptr
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_PHONE_RESTRICTED or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      @DefProto DllImport, CryptInstallDefaultContext, WIN_STD_CALL_CONV,, <:HCRYPTPROV, :DWORD, :ptr, :DWORD, :ptr, :ptr HCRYPTDEFAULTCONTEXT>, 24
      CRYPT_DEFAULT_CONTEXT_AUTO_RELEASE_FLAG equ 00000001h
      CRYPT_DEFAULT_CONTEXT_PROCESS_FLAG equ 00000002h
      CRYPT_DEFAULT_CONTEXT_CERT_SIGN_OID equ 1
      CRYPT_DEFAULT_CONTEXT_MULTI_CERT_SIGN_OID equ 2
      CRYPT_DEFAULT_CONTEXT_MULTI_OID_PARA struct
        cOID DWORD ?
        rgpszOID POINTER ?
      CRYPT_DEFAULT_CONTEXT_MULTI_OID_PARA ends
      _CRYPT_DEFAULT_CONTEXT_MULTI_OID_PARA typedef CRYPT_DEFAULT_CONTEXT_MULTI_OID_PARA
      PCRYPT_DEFAULT_CONTEXT_MULTI_OID_PARA typedef ptr CRYPT_DEFAULT_CONTEXT_MULTI_OID_PARA
      @DefProto DllImport, CryptUninstallDefaultContext, WIN_STD_CALL_CONV,, <:HCRYPTDEFAULTCONTEXT, :DWORD, :ptr>, 12
      @DefProto DllImport, CryptExportPublicKeyInfo, WIN_STD_CALL_CONV,, <:HCRYPTPROV_OR_NCRYPT_KEY_HANDLE, :DWORD, :DWORD, :PCERT_PUBLIC_KEY_INFO, :ptr DWORD>, 20
      @DefProto DllImport, CryptExportPublicKeyInfoEx, WIN_STD_CALL_CONV,, <:HCRYPTPROV_OR_NCRYPT_KEY_HANDLE, :DWORD, :DWORD, :LPSTR, :DWORD, :ptr, :PCERT_PUBLIC_KEY_INFO, :ptr DWORD>, 32
      CRYPT_OID_EXPORT_PUBLIC_KEY_INFO_FUNC equ <"CryptDllExportPublicKeyInfoEx">
      CRYPT_OID_EXPORT_PUBLIC_KEY_INFO_EX2_FUNC equ <"CryptDllExportPublicKeyInfoEx2">
      TYPE_PFN_CRYPT_EXPORT_PUBLIC_KEY_INFO_EX2_FUNC typedef proto WIN_STD_CALL_CONV :NCRYPT_KEY_HANDLE, :DWORD, :LPSTR, :DWORD, :ptr, :PCERT_PUBLIC_KEY_INFO, :ptr DWORD
      PFN_CRYPT_EXPORT_PUBLIC_KEY_INFO_EX2_FUNC typedef ptr TYPE_PFN_CRYPT_EXPORT_PUBLIC_KEY_INFO_EX2_FUNC

      if (NTDDI_VERSION ge NTDDI_WIN7)
        @DefProto DllImport, CryptExportPublicKeyInfoFromBCryptKeyHandle, WIN_STD_CALL_CONV,, <:BCRYPT_KEY_HANDLE, :DWORD, :LPSTR, :DWORD, :ptr, :PCERT_PUBLIC_KEY_INFO, :ptr DWORD>, 28
        CRYPT_OID_EXPORT_PUBLIC_KEY_INFO_FROM_BCRYPT_HANDLE_FUNC equ <"CryptDllExportPublicKeyInfoFromBCryptKeyHandle">
        TYPE_PFN_CRYPT_EXPORT_PUBLIC_KEY_INFO_FROM_BCRYPT_HANDLE_FUNC typedef proto WIN_STD_CALL_CONV :BCRYPT_KEY_HANDLE, :DWORD, :LPSTR, :DWORD, :ptr, :PCERT_PUBLIC_KEY_INFO, :ptr DWORD
        PFN_CRYPT_EXPORT_PUBLIC_KEY_INFO_FROM_BCRYPT_HANDLE_FUNC typedef ptr TYPE_PFN_CRYPT_EXPORT_PUBLIC_KEY_INFO_FROM_BCRYPT_HANDLE_FUNC

      endif
      @DefProto DllImport, CryptImportPublicKeyInfo, WIN_STD_CALL_CONV,, <:HCRYPTPROV, :DWORD, :PCERT_PUBLIC_KEY_INFO, :ptr HCRYPTKEY>, 16
      CRYPT_OID_IMPORT_PUBLIC_KEY_INFO_FUNC equ <"CryptDllImportPublicKeyInfoEx">
      @DefProto DllImport, CryptImportPublicKeyInfoEx, WIN_STD_CALL_CONV,, <:HCRYPTPROV, :DWORD, :PCERT_PUBLIC_KEY_INFO, :ALG_ID, :DWORD, :ptr, :ptr HCRYPTKEY>, 28
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      if (NTDDI_VERSION ge NTDDI_VISTA)
        @DefProto DllImport, CryptImportPublicKeyInfoEx2, WIN_STD_CALL_CONV,, <:DWORD, :PCERT_PUBLIC_KEY_INFO, :DWORD, :ptr, :ptr BCRYPT_KEY_HANDLE>, 20
        CRYPT_OID_IMPORT_PUBLIC_KEY_INFO_EX2_FUNC equ <"CryptDllImportPublicKeyInfoEx2">
        TYPE_PFN_IMPORT_PUBLIC_KEY_INFO_EX2_FUNC typedef proto WIN_STD_CALL_CONV :DWORD, :PCERT_PUBLIC_KEY_INFO, :DWORD, :ptr, :ptr BCRYPT_KEY_HANDLE
        PFN_IMPORT_PUBLIC_KEY_INFO_EX2_FUNC typedef ptr TYPE_PFN_IMPORT_PUBLIC_KEY_INFO_EX2_FUNC

      endif
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_PHONE_RESTRICTED or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      @DefProto DllImport, CryptAcquireCertificatePrivateKey, WIN_STD_CALL_CONV,, <:PCCERT_CONTEXT, :DWORD, :ptr, :ptr HCRYPTPROV_OR_NCRYPT_KEY_HANDLE, :ptr DWORD, :ptr BOOL>, 24
      CRYPT_ACQUIRE_CACHE_FLAG equ 00000001h
      CRYPT_ACQUIRE_USE_PROV_INFO_FLAG equ 00000002h
      CRYPT_ACQUIRE_COMPARE_KEY_FLAG equ 00000004h
      CRYPT_ACQUIRE_NO_HEALING equ 00000008h
      CRYPT_ACQUIRE_SILENT_FLAG equ 00000040h
      CRYPT_ACQUIRE_WINDOW_HANDLE_FLAG equ 00000080h
      CRYPT_ACQUIRE_NCRYPT_KEY_FLAGS_MASK equ 00070000h
      CRYPT_ACQUIRE_ALLOW_NCRYPT_KEY_FLAG equ 00010000h
      CRYPT_ACQUIRE_PREFER_NCRYPT_KEY_FLAG equ 00020000h
      CRYPT_ACQUIRE_ONLY_NCRYPT_KEY_FLAG equ 00040000h
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_PHONE_RESTRICTED or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      @DefProto DllImport, CryptFindCertificateKeyProvInfo, WIN_STD_CALL_CONV,, <:PCCERT_CONTEXT, :DWORD, :ptr>, 12
      CRYPT_FIND_USER_KEYSET_FLAG equ 00000001h
      CRYPT_FIND_MACHINE_KEYSET_FLAG equ 00000002h
      CRYPT_FIND_SILENT_KEYSET_FLAG equ 00000040h
      TYPE_PFN_IMPORT_PRIV_KEY_FUNC typedef proto WIN_STD_CALL_CONV :HCRYPTPROV, :ptr CRYPT_PRIVATE_KEY_INFO, :DWORD, :ptr
      PFN_IMPORT_PRIV_KEY_FUNC typedef ptr TYPE_PFN_IMPORT_PRIV_KEY_FUNC

      CRYPT_OID_IMPORT_PRIVATE_KEY_INFO_FUNC equ <"CryptDllImportPrivateKeyInfoEx">
      @DefProto DllImport, CryptImportPKCS8, WIN_STD_CALL_CONV,, <:CRYPT_PKCS8_IMPORT_PARAMS, :DWORD, :ptr HCRYPTPROV, :ptr>, 16
      TYPE_PFN_EXPORT_PRIV_KEY_FUNC typedef proto WIN_STD_CALL_CONV :HCRYPTPROV, :DWORD, :LPSTR, :DWORD, :ptr, :ptr CRYPT_PRIVATE_KEY_INFO, :ptr DWORD
      PFN_EXPORT_PRIV_KEY_FUNC typedef ptr TYPE_PFN_EXPORT_PRIV_KEY_FUNC

      CRYPT_OID_EXPORT_PRIVATE_KEY_INFO_FUNC equ <"CryptDllExportPrivateKeyInfoEx">
      CRYPT_DELETE_KEYSET equ <CRYPT_DELETEKEYSET>
      @DefProto DllImport, CryptExportPKCS8, WIN_STD_CALL_CONV,, <:HCRYPTPROV, :DWORD, :LPSTR, :DWORD, :ptr, :ptr BYTE, :ptr DWORD>, 28
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_PHONE_RESTRICTED or WINAPI_PARTITION_GAMES)
      @DefProto DllImport, CryptExportPKCS8Ex, WIN_STD_CALL_CONV,, <:ptr CRYPT_PKCS8_EXPORT_PARAMS, :DWORD, :ptr, :ptr BYTE, :ptr DWORD>, 20
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      @DefProto DllImport, CryptHashPublicKeyInfo, WIN_STD_CALL_CONV,, <:HCRYPTPROV_LEGACY, :ALG_ID, :DWORD, :DWORD, :PCERT_PUBLIC_KEY_INFO, :ptr BYTE, :ptr DWORD>, 28
      @DefProto DllImport, CertRDNValueToStrA, WIN_STD_CALL_CONV,, <:DWORD, :PCERT_RDN_VALUE_BLOB, :LPSTR, :DWORD>, 16
      @DefProto DllImport, CertRDNValueToStrW, WIN_STD_CALL_CONV,, <:DWORD, :PCERT_RDN_VALUE_BLOB, :LPWSTR, :DWORD>, 16
      ifdef UNICODE
        CertRDNValueToStr equ <CertRDNValueToStrW>
      else
        CertRDNValueToStr equ <CertRDNValueToStrA>
      endif
      @DefProto DllImport, CertNameToStrA, WIN_STD_CALL_CONV,, <:DWORD, :PCERT_NAME_BLOB, :DWORD, :LPSTR, :DWORD>, 20
      @DefProto DllImport, CertNameToStrW, WIN_STD_CALL_CONV,, <:DWORD, :PCERT_NAME_BLOB, :DWORD, :LPWSTR, :DWORD>, 20
      ifdef UNICODE
        CertNameToStr equ <CertNameToStrW>
      else
        CertNameToStr equ <CertNameToStrA>
      endif
      CERT_SIMPLE_NAME_STR equ 1
      CERT_OID_NAME_STR equ 2
      CERT_X500_NAME_STR equ 3
      CERT_XML_NAME_STR equ 4
      CERT_NAME_STR_SEMICOLON_FLAG equ 40000000h
      CERT_NAME_STR_NO_PLUS_FLAG equ 20000000h
      CERT_NAME_STR_NO_QUOTING_FLAG equ 10000000h
      CERT_NAME_STR_CRLF_FLAG equ 08000000h
      CERT_NAME_STR_COMMA_FLAG equ 04000000h
      CERT_NAME_STR_REVERSE_FLAG equ 02000000h
      CERT_NAME_STR_FORWARD_FLAG equ 01000000h
      CERT_NAME_STR_DISABLE_IE4_UTF8_FLAG equ 00010000h
      CERT_NAME_STR_ENABLE_T61_UNICODE_FLAG equ 00020000h
      CERT_NAME_STR_ENABLE_UTF8_UNICODE_FLAG equ 00040000h
      CERT_NAME_STR_FORCE_UTF8_DIR_STR_FLAG equ 00080000h
      CERT_NAME_STR_DISABLE_UTF8_DIR_STR_FLAG equ 00100000h
      CERT_NAME_STR_ENABLE_PUNYCODE_FLAG equ 00200000h
      @DefProto DllImport, CertStrToNameA, WIN_STD_CALL_CONV,, <:DWORD, :LPCSTR, :DWORD, :ptr, :ptr BYTE, :ptr DWORD, :ptr LPCSTR>, 28
      @DefProto DllImport, CertStrToNameW, WIN_STD_CALL_CONV,, <:DWORD, :LPCWSTR, :DWORD, :ptr, :ptr BYTE, :ptr DWORD, :ptr LPCWSTR>, 28
      ifdef UNICODE
        CertStrToName equ <CertStrToNameW>
      else
        CertStrToName equ <CertStrToNameA>
      endif
      @DefProto DllImport, CertGetNameStringA, WIN_STD_CALL_CONV,, <:PCCERT_CONTEXT, :DWORD, :DWORD, :ptr, :LPSTR, :DWORD>, 24
      @DefProto DllImport, CertGetNameStringW, WIN_STD_CALL_CONV,, <:PCCERT_CONTEXT, :DWORD, :DWORD, :ptr, :LPWSTR, :DWORD>, 24
      ifdef UNICODE
        CertGetNameString equ <CertGetNameStringW>
      else
        CertGetNameString equ <CertGetNameStringA>
      endif
      CERT_NAME_EMAIL_TYPE equ 1
      CERT_NAME_RDN_TYPE equ 2
      CERT_NAME_ATTR_TYPE equ 3
      CERT_NAME_SIMPLE_DISPLAY_TYPE equ 4
      CERT_NAME_FRIENDLY_DISPLAY_TYPE equ 5
      CERT_NAME_DNS_TYPE equ 6
      CERT_NAME_URL_TYPE equ 7
      CERT_NAME_UPN_TYPE equ 8
      CERT_NAME_ISSUER_FLAG equ 1h
      CERT_NAME_DISABLE_IE4_UTF8_FLAG equ 00010000h
      CERT_NAME_SEARCH_ALL_NAMES_FLAG equ 2h
      TYPE_PFN_CRYPT_GET_SIGNER_CERTIFICATE typedef proto WIN_STD_CALL_CONV :ptr, :DWORD, :PCERT_INFO, :HCERTSTORE
      PFN_CRYPT_GET_SIGNER_CERTIFICATE typedef ptr TYPE_PFN_CRYPT_GET_SIGNER_CERTIFICATE

      CRYPT_SIGN_MESSAGE_PARA struct
        cbSize DWORD ?
        dwMsgEncodingType DWORD ?
        pSigningCert PCCERT_CONTEXT ?
        HashAlgorithm CRYPT_ALGORITHM_IDENTIFIER <>
        pvHashAuxInfo POINTER ?
        cMsgCert DWORD ?
        rgpMsgCert POINTER ?
        cMsgCrl DWORD ?
        rgpMsgCrl POINTER ?
        cAuthAttr DWORD ?
        rgAuthAttr PCRYPT_ATTRIBUTE ?
        cUnauthAttr DWORD ?
        rgUnauthAttr PCRYPT_ATTRIBUTE ?
        dwFlags DWORD ?
        dwInnerContentType DWORD ?
        ifdef CRYPT_SIGN_MESSAGE_PARA_HAS_CMS_FIELDS
          HashEncryptionAlgorithm CRYPT_ALGORITHM_IDENTIFIER <>
          pvHashEncryptionAuxInfo POINTER ?
        endif
      CRYPT_SIGN_MESSAGE_PARA ends
      _CRYPT_SIGN_MESSAGE_PARA typedef CRYPT_SIGN_MESSAGE_PARA
      PCRYPT_SIGN_MESSAGE_PARA typedef ptr CRYPT_SIGN_MESSAGE_PARA
      CRYPT_MESSAGE_BARE_CONTENT_OUT_FLAG equ 00000001h
      CRYPT_MESSAGE_ENCAPSULATED_CONTENT_OUT_FLAG equ 00000002h
      CRYPT_MESSAGE_KEYID_SIGNER_FLAG equ 00000004h
      CRYPT_MESSAGE_SILENT_KEYSET_FLAG equ 00000040h
      CRYPT_VERIFY_MESSAGE_PARA struct
        cbSize DWORD ?
        dwMsgAndCertEncodingType DWORD ?
        hCryptProv HCRYPTPROV_LEGACY ?
        pfnGetSignerCertificate PFN_CRYPT_GET_SIGNER_CERTIFICATE ?
        pvGetArg POINTER ?
        ifdef CRYPT_VERIFY_MESSAGE_PARA_HAS_EXTRA_FIELDS
          pStrongSignPara PCCERT_STRONG_SIGN_PARA ?
        endif
      CRYPT_VERIFY_MESSAGE_PARA ends
      _CRYPT_VERIFY_MESSAGE_PARA typedef CRYPT_VERIFY_MESSAGE_PARA
      PCRYPT_VERIFY_MESSAGE_PARA typedef ptr CRYPT_VERIFY_MESSAGE_PARA
      CRYPT_ENCRYPT_MESSAGE_PARA struct
        cbSize DWORD ?
        dwMsgEncodingType DWORD ?
        hCryptProv HCRYPTPROV_LEGACY ?
        ContentEncryptionAlgorithm CRYPT_ALGORITHM_IDENTIFIER <>
        pvEncryptionAuxInfo POINTER ?
        dwFlags DWORD ?
        dwInnerContentType DWORD ?
      CRYPT_ENCRYPT_MESSAGE_PARA ends
      _CRYPT_ENCRYPT_MESSAGE_PARA typedef CRYPT_ENCRYPT_MESSAGE_PARA
      PCRYPT_ENCRYPT_MESSAGE_PARA typedef ptr CRYPT_ENCRYPT_MESSAGE_PARA
      CRYPT_MESSAGE_KEYID_RECIPIENT_FLAG equ 4h
      CRYPT_DECRYPT_MESSAGE_PARA struct
        cbSize DWORD ?
        dwMsgAndCertEncodingType DWORD ?
        cCertStore DWORD ?
        rghCertStore POINTER ?
        ifdef CRYPT_DECRYPT_MESSAGE_PARA_HAS_EXTRA_FIELDS
          dwFlags DWORD ?
        endif
      CRYPT_DECRYPT_MESSAGE_PARA ends
      _CRYPT_DECRYPT_MESSAGE_PARA typedef CRYPT_DECRYPT_MESSAGE_PARA
      PCRYPT_DECRYPT_MESSAGE_PARA typedef ptr CRYPT_DECRYPT_MESSAGE_PARA
      CRYPT_HASH_MESSAGE_PARA struct
        cbSize DWORD ?
        dwMsgEncodingType DWORD ?
        hCryptProv HCRYPTPROV_LEGACY ?
        HashAlgorithm CRYPT_ALGORITHM_IDENTIFIER <>
        pvHashAuxInfo POINTER ?
      CRYPT_HASH_MESSAGE_PARA ends
      _CRYPT_HASH_MESSAGE_PARA typedef CRYPT_HASH_MESSAGE_PARA
      PCRYPT_HASH_MESSAGE_PARA typedef ptr CRYPT_HASH_MESSAGE_PARA
      CRYPT_KEY_SIGN_MESSAGE_PARA struct
        cbSize DWORD ?
        dwMsgAndCertEncodingType DWORD ?
        union
          hCryptProv HCRYPTPROV ?
          hNCryptKey NCRYPT_KEY_HANDLE ?
        ends
        dwKeySpec DWORD ?
        HashAlgorithm CRYPT_ALGORITHM_IDENTIFIER <>
        pvHashAuxInfo POINTER ?
        PubKeyAlgorithm CRYPT_ALGORITHM_IDENTIFIER <>
      CRYPT_KEY_SIGN_MESSAGE_PARA ends
      _CRYPT_KEY_SIGN_MESSAGE_PARA typedef CRYPT_KEY_SIGN_MESSAGE_PARA
      PCRYPT_KEY_SIGN_MESSAGE_PARA typedef ptr CRYPT_KEY_SIGN_MESSAGE_PARA
      CRYPT_KEY_VERIFY_MESSAGE_PARA struct
        cbSize DWORD ?
        dwMsgEncodingType DWORD ?
        hCryptProv HCRYPTPROV_LEGACY ?
      CRYPT_KEY_VERIFY_MESSAGE_PARA ends
      _CRYPT_KEY_VERIFY_MESSAGE_PARA typedef CRYPT_KEY_VERIFY_MESSAGE_PARA
      PCRYPT_KEY_VERIFY_MESSAGE_PARA typedef ptr CRYPT_KEY_VERIFY_MESSAGE_PARA
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_PHONE_RESTRICTED or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      @DefProto DllImport, CryptSignMessage, WIN_STD_CALL_CONV,, <:PCRYPT_SIGN_MESSAGE_PARA, :BOOL, :DWORD, :ptr ptr BYTE, :ptr DWORD, :ptr BYTE, :ptr DWORD>, 28
      @DefProto DllImport, CryptVerifyMessageSignature, WIN_STD_CALL_CONV,, <:PCRYPT_VERIFY_MESSAGE_PARA, :DWORD, :ptr BYTE, :DWORD, :ptr BYTE, :ptr DWORD, :ptr PCCERT_CONTEXT>, 28
      @DefProto DllImport, CryptGetMessageSignerCount, WIN_STD_CALL_CONV,, <:DWORD, :ptr BYTE, :DWORD>, 12
      @DefProto DllImport, CryptGetMessageCertificates, WIN_STD_CALL_CONV,, <:DWORD, :HCRYPTPROV_LEGACY, :DWORD, :ptr BYTE, :DWORD>, 20
      @DefProto DllImport, CryptVerifyDetachedMessageSignature, WIN_STD_CALL_CONV,, <:PCRYPT_VERIFY_MESSAGE_PARA, :DWORD, :ptr BYTE, :DWORD, :DWORD, :ptr ptr BYTE, :ptr DWORD, :ptr PCCERT_CONTEXT>, 32
      @DefProto DllImport, CryptEncryptMessage, WIN_STD_CALL_CONV,, <:PCRYPT_ENCRYPT_MESSAGE_PARA, :DWORD, :ptr PCCERT_CONTEXT, :ptr BYTE, :DWORD, :ptr BYTE, :ptr DWORD>, 28
      @DefProto DllImport, CryptDecryptMessage, WIN_STD_CALL_CONV,, <:PCRYPT_DECRYPT_MESSAGE_PARA, :ptr BYTE, :DWORD, :ptr BYTE, :ptr DWORD, :ptr PCCERT_CONTEXT>, 24
      @DefProto DllImport, CryptSignAndEncryptMessage, WIN_STD_CALL_CONV,, <:PCRYPT_SIGN_MESSAGE_PARA, :PCRYPT_ENCRYPT_MESSAGE_PARA, :DWORD, :ptr PCCERT_CONTEXT, :ptr BYTE, :DWORD, :ptr BYTE, :ptr DWORD>, 32
      @DefProto DllImport, CryptDecryptAndVerifyMessageSignature, WIN_STD_CALL_CONV,, <:PCRYPT_DECRYPT_MESSAGE_PARA, :PCRYPT_VERIFY_MESSAGE_PARA, :DWORD, :ptr BYTE, :DWORD, :ptr BYTE, :ptr DWORD, :ptr PCCERT_CONTEXT, :ptr PCCERT_CONTEXT>, 36
      @DefProto DllImport, CryptDecodeMessage, WIN_STD_CALL_CONV,, <:DWORD, :PCRYPT_DECRYPT_MESSAGE_PARA, :PCRYPT_VERIFY_MESSAGE_PARA, :DWORD, :ptr BYTE, :DWORD, :DWORD, :ptr DWORD, :ptr DWORD, :ptr BYTE, :ptr DWORD, :ptr PCCERT_CONTEXT, :ptr PCCERT_CONTEXT>, 52
      @DefProto DllImport, CryptHashMessage, WIN_STD_CALL_CONV,, <:PCRYPT_HASH_MESSAGE_PARA, :BOOL, :DWORD, :ptr ptr BYTE, :ptr DWORD, :ptr BYTE, :ptr DWORD, :ptr BYTE, :ptr DWORD>, 36
      @DefProto DllImport, CryptVerifyMessageHash, WIN_STD_CALL_CONV,, <:PCRYPT_HASH_MESSAGE_PARA, :ptr BYTE, :DWORD, :ptr BYTE, :ptr DWORD, :ptr BYTE, :ptr DWORD>, 28
      @DefProto DllImport, CryptVerifyDetachedMessageHash, WIN_STD_CALL_CONV,, <:PCRYPT_HASH_MESSAGE_PARA, :ptr BYTE, :DWORD, :DWORD, :ptr ptr BYTE, :ptr DWORD, :ptr BYTE, :ptr DWORD>, 32
      @DefProto DllImport, CryptSignMessageWithKey, WIN_STD_CALL_CONV,, <:PCRYPT_KEY_SIGN_MESSAGE_PARA, :ptr BYTE, :DWORD, :ptr BYTE, :ptr DWORD>, 20
      @DefProto DllImport, CryptVerifyMessageSignatureWithKey, WIN_STD_CALL_CONV,, <:PCRYPT_KEY_VERIFY_MESSAGE_PARA, :PCERT_PUBLIC_KEY_INFO, :ptr BYTE, :DWORD, :ptr BYTE, :ptr DWORD>, 24
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_PHONE_RESTRICTED or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      @DefProto DllImport, CertOpenSystemStoreA, WIN_STD_CALL_CONV,, <:HCRYPTPROV_LEGACY, :LPCSTR>, 8
      @DefProto DllImport, CertOpenSystemStoreW, WIN_STD_CALL_CONV,, <:HCRYPTPROV_LEGACY, :LPCWSTR>, 8
      ifdef UNICODE
        CertOpenSystemStore equ <CertOpenSystemStoreW>
      else
        CertOpenSystemStore equ <CertOpenSystemStoreA>
      endif
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_PHONE_RESTRICTED or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      @DefProto DllImport, CertAddEncodedCertificateToSystemStoreA, WIN_STD_CALL_CONV,, <:LPCSTR, :ptr BYTE, :DWORD>, 12
      @DefProto DllImport, CertAddEncodedCertificateToSystemStoreW, WIN_STD_CALL_CONV,, <:LPCWSTR, :ptr BYTE, :DWORD>, 12
      ifdef UNICODE
        CertAddEncodedCertificateToSystemStore equ <CertAddEncodedCertificateToSystemStoreW>
      else
        CertAddEncodedCertificateToSystemStore equ <CertAddEncodedCertificateToSystemStoreA>
      endif
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_PHONE_RESTRICTED or WINAPI_PARTITION_PKG_WINTRUST or WINAPI_PARTITION_GAMES)
      CERT_CHAIN struct
        cCerts DWORD ?
        certs PCERT_BLOB ?
        keyLocatorInfo CRYPT_KEY_PROV_INFO <>
      CERT_CHAIN ends
      _CERT_CHAIN typedef CERT_CHAIN
      PCERT_CHAIN typedef ptr CERT_CHAIN
      FindCertsByIssuer proto WIN_STD_CALL_CONV :PCERT_CHAIN, :ptr DWORD, :ptr DWORD, :ptr BYTE, :DWORD, :LPCWSTR, :DWORD
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      @DefProto DllImport, CryptQueryObject, WIN_STD_CALL_CONV,, <:DWORD, :ptr, :DWORD, :DWORD, :DWORD, :ptr DWORD, :ptr DWORD, :ptr DWORD, :ptr HCERTSTORE, :ptr HCRYPTMSG, :ptr ptr>, 44
      CERT_QUERY_OBJECT_FILE equ 00000001h
      CERT_QUERY_OBJECT_BLOB equ 00000002h
      CERT_QUERY_CONTENT_CERT equ 1
      CERT_QUERY_CONTENT_CTL equ 2
      CERT_QUERY_CONTENT_CRL equ 3
      CERT_QUERY_CONTENT_SERIALIZED_STORE equ 4
      CERT_QUERY_CONTENT_SERIALIZED_CERT equ 5
      CERT_QUERY_CONTENT_SERIALIZED_CTL equ 6
      CERT_QUERY_CONTENT_SERIALIZED_CRL equ 7
      CERT_QUERY_CONTENT_PKCS7_SIGNED equ 8
      CERT_QUERY_CONTENT_PKCS7_UNSIGNED equ 9
      CERT_QUERY_CONTENT_PKCS7_SIGNED_EMBED equ 10
      CERT_QUERY_CONTENT_PKCS10 equ 11
      CERT_QUERY_CONTENT_PFX equ 12
      CERT_QUERY_CONTENT_CERT_PAIR equ 13
      CERT_QUERY_CONTENT_PFX_AND_LOAD equ 14
      CERT_QUERY_CONTENT_FLAG_CERT equ (1 shl CERT_QUERY_CONTENT_CERT)
      CERT_QUERY_CONTENT_FLAG_CTL equ (1 shl CERT_QUERY_CONTENT_CTL)
      CERT_QUERY_CONTENT_FLAG_CRL equ (1 shl CERT_QUERY_CONTENT_CRL)
      CERT_QUERY_CONTENT_FLAG_SERIALIZED_STORE equ (1 shl CERT_QUERY_CONTENT_SERIALIZED_STORE)
      CERT_QUERY_CONTENT_FLAG_SERIALIZED_CERT equ (1 shl CERT_QUERY_CONTENT_SERIALIZED_CERT)
      CERT_QUERY_CONTENT_FLAG_SERIALIZED_CTL equ (1 shl CERT_QUERY_CONTENT_SERIALIZED_CTL)
      CERT_QUERY_CONTENT_FLAG_SERIALIZED_CRL equ (1 shl CERT_QUERY_CONTENT_SERIALIZED_CRL)
      CERT_QUERY_CONTENT_FLAG_PKCS7_SIGNED equ (1 shl CERT_QUERY_CONTENT_PKCS7_SIGNED)
      CERT_QUERY_CONTENT_FLAG_PKCS7_UNSIGNED equ (1 shl CERT_QUERY_CONTENT_PKCS7_UNSIGNED)
      CERT_QUERY_CONTENT_FLAG_PKCS7_SIGNED_EMBED equ (1 shl CERT_QUERY_CONTENT_PKCS7_SIGNED_EMBED)
      CERT_QUERY_CONTENT_FLAG_PKCS10 equ (1 shl CERT_QUERY_CONTENT_PKCS10)
      CERT_QUERY_CONTENT_FLAG_PFX equ (1 shl CERT_QUERY_CONTENT_PFX)
      CERT_QUERY_CONTENT_FLAG_CERT_PAIR equ (1 shl CERT_QUERY_CONTENT_CERT_PAIR)
      CERT_QUERY_CONTENT_FLAG_PFX_AND_LOAD equ (1 shl CERT_QUERY_CONTENT_PFX_AND_LOAD)
      CERT_QUERY_CONTENT_FLAG_ALL equ <(CERT_QUERY_CONTENT_FLAG_CERT or CERT_QUERY_CONTENT_FLAG_CTL or CERT_QUERY_CONTENT_FLAG_CRL or CERT_QUERY_CONTENT_FLAG_SERIALIZED_STORE or CERT_QUERY_CONTENT_FLAG_SERIALIZED_CERT or CERT_QUERY_CONTENT_FLAG_SERIALIZED_CTL or CERT_QUERY_CONTENT_FLAG_SERIALIZED_CRL or CERT_QUERY_CONTENT_FLAG_PKCS7_SIGNED or CERT_QUERY_CONTENT_FLAG_PKCS7_UNSIGNED or CERT_QUERY_CONTENT_FLAG_PKCS7_SIGNED_EMBED or CERT_QUERY_CONTENT_FLAG_PKCS10 or CERT_QUERY_CONTENT_FLAG_PFX or CERT_QUERY_CONTENT_FLAG_CERT_PAIR)>
      CERT_QUERY_CONTENT_FLAG_ALL_ISSUER_CERT equ <(CERT_QUERY_CONTENT_FLAG_CERT or CERT_QUERY_CONTENT_FLAG_SERIALIZED_STORE or CERT_QUERY_CONTENT_FLAG_SERIALIZED_CERT or CERT_QUERY_CONTENT_FLAG_PKCS7_SIGNED or CERT_QUERY_CONTENT_FLAG_PKCS7_UNSIGNED)>
      CERT_QUERY_FORMAT_BINARY equ 1
      CERT_QUERY_FORMAT_BASE64_ENCODED equ 2
      CERT_QUERY_FORMAT_ASN_ASCII_HEX_ENCODED equ 3
      CERT_QUERY_FORMAT_FLAG_BINARY equ (1 shl CERT_QUERY_FORMAT_BINARY)
      CERT_QUERY_FORMAT_FLAG_BASE64_ENCODED equ (1 shl CERT_QUERY_FORMAT_BASE64_ENCODED)
      CERT_QUERY_FORMAT_FLAG_ASN_ASCII_HEX_ENCODED equ (1 shl CERT_QUERY_FORMAT_ASN_ASCII_HEX_ENCODED)
      CERT_QUERY_FORMAT_FLAG_ALL equ <(CERT_QUERY_FORMAT_FLAG_BINARY or CERT_QUERY_FORMAT_FLAG_BASE64_ENCODED or CERT_QUERY_FORMAT_FLAG_ASN_ASCII_HEX_ENCODED)>
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_PHONE_RESTRICTED or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      @DefProto DllImport, CryptMemAlloc, WIN_STD_CALL_CONV,, <:ULONG>, 4
      @DefProto DllImport, CryptMemRealloc, WIN_STD_CALL_CONV,, <:LPVOID, :ULONG>, 8
      @DefProto DllImport, CryptMemFree, WIN_STD_CALL_CONV,, <:LPVOID>, 4
      HCRYPTASYNC typedef HANDLE
      PHCRYPTASYNC typedef ptr HANDLE
      TYPE_PFN_CRYPT_ASYNC_PARAM_FREE_FUNC typedef proto WIN_STD_CALL_CONV :LPSTR, :LPVOID
      PFN_CRYPT_ASYNC_PARAM_FREE_FUNC typedef ptr TYPE_PFN_CRYPT_ASYNC_PARAM_FREE_FUNC

      @DefProto DllImport, CryptCreateAsyncHandle, WIN_STD_CALL_CONV,, <:DWORD, :PHCRYPTASYNC>, 8
      @DefProto DllImport, CryptSetAsyncParam, WIN_STD_CALL_CONV,, <:HCRYPTASYNC, :LPSTR, :LPVOID, :PFN_CRYPT_ASYNC_PARAM_FREE_FUNC>, 16
      @DefProto DllImport, CryptGetAsyncParam, WIN_STD_CALL_CONV,, <:HCRYPTASYNC, :LPSTR, :ptr LPVOID, :ptr PFN_CRYPT_ASYNC_PARAM_FREE_FUNC>, 16
      @DefProto DllImport, CryptCloseAsyncHandle, WIN_STD_CALL_CONV,, <:HCRYPTASYNC>, 4
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      CRYPT_BLOB_ARRAY struct
        cBlob DWORD ?
        rgBlob PCRYPT_DATA_BLOB ?
      CRYPT_BLOB_ARRAY ends
      _CRYPT_BLOB_ARRAY typedef CRYPT_BLOB_ARRAY
      PCRYPT_BLOB_ARRAY typedef ptr CRYPT_BLOB_ARRAY
      CRYPT_CREDENTIALS struct
        cbSize DWORD ?
        pszCredentialsOid LPCSTR ?
        pvCredentials LPVOID ?
      CRYPT_CREDENTIALS ends
      _CRYPT_CREDENTIALS typedef CRYPT_CREDENTIALS
      PCRYPT_CREDENTIALS typedef ptr CRYPT_CREDENTIALS
      CREDENTIAL_OID_PASSWORD_CREDENTIALS_A equ (1)
      CREDENTIAL_OID_PASSWORD_CREDENTIALS_W equ (2)
      ifdef UNICODE
        CREDENTIAL_OID_PASSWORD_CREDENTIALS equ <CREDENTIAL_OID_PASSWORD_CREDENTIALS_W>
      else
        CREDENTIAL_OID_PASSWORD_CREDENTIALS equ <CREDENTIAL_OID_PASSWORD_CREDENTIALS_A>
      endif
      CRYPT_PASSWORD_CREDENTIALSA struct
        cbSize DWORD ?
        pszUsername LPSTR ?
        pszPassword LPSTR ?
      CRYPT_PASSWORD_CREDENTIALSA ends
      _CRYPT_PASSWORD_CREDENTIALSA typedef CRYPT_PASSWORD_CREDENTIALSA
      PCRYPT_PASSWORD_CREDENTIALSA typedef ptr CRYPT_PASSWORD_CREDENTIALSA
      CRYPT_PASSWORD_CREDENTIALSW struct
        cbSize DWORD ?
        pszUsername LPWSTR ?
        pszPassword LPWSTR ?
      CRYPT_PASSWORD_CREDENTIALSW ends
      _CRYPT_PASSWORD_CREDENTIALSW typedef CRYPT_PASSWORD_CREDENTIALSW
      PCRYPT_PASSWORD_CREDENTIALSW typedef ptr CRYPT_PASSWORD_CREDENTIALSW
      ifdef UNICODE
        CRYPT_PASSWORD_CREDENTIALS typedef CRYPT_PASSWORD_CREDENTIALSW
        PCRYPT_PASSWORD_CREDENTIALS typedef PCRYPT_PASSWORD_CREDENTIALSW
      else
        CRYPT_PASSWORD_CREDENTIALS typedef CRYPT_PASSWORD_CREDENTIALSA
        PCRYPT_PASSWORD_CREDENTIALS typedef PCRYPT_PASSWORD_CREDENTIALSA
      endif
      SCHEME_OID_RETRIEVE_ENCODED_OBJECT_FUNC equ <"SchemeDllRetrieveEncodedObject">
      SCHEME_OID_RETRIEVE_ENCODED_OBJECTW_FUNC equ <"SchemeDllRetrieveEncodedObjectW">
      TYPE_PFN_FREE_ENCODED_OBJECT_FUNC typedef proto WIN_STD_CALL_CONV :LPCSTR, :PCRYPT_BLOB_ARRAY, :LPVOID
      PFN_FREE_ENCODED_OBJECT_FUNC typedef ptr TYPE_PFN_FREE_ENCODED_OBJECT_FUNC

      CONTEXT_OID_CREATE_OBJECT_CONTEXT_FUNC equ <"ContextDllCreateObjectContext">
      CONTEXT_OID_CERTIFICATE equ (1)
      CONTEXT_OID_CRL equ (2)
      CONTEXT_OID_CTL equ (3)
      CONTEXT_OID_PKCS7 equ (4)
      CONTEXT_OID_CAPI2_ANY equ (5)
      CONTEXT_OID_OCSP_RESP equ (6)
      CRYPT_RETRIEVE_MULTIPLE_OBJECTS equ 00000001h
      CRYPT_CACHE_ONLY_RETRIEVAL equ 00000002h
      CRYPT_WIRE_ONLY_RETRIEVAL equ 00000004h
      CRYPT_DONT_CACHE_RESULT equ 00000008h
      CRYPT_ASYNC_RETRIEVAL equ 00000010h
      CRYPT_STICKY_CACHE_RETRIEVAL equ 00001000h
      CRYPT_LDAP_SCOPE_BASE_ONLY_RETRIEVAL equ 00002000h
      CRYPT_OFFLINE_CHECK_RETRIEVAL equ 00004000h
      CRYPT_LDAP_INSERT_ENTRY_ATTRIBUTE equ 00008000h
      CRYPT_LDAP_SIGN_RETRIEVAL equ 00010000h
      CRYPT_NO_AUTH_RETRIEVAL equ 00020000h
      CRYPT_LDAP_AREC_EXCLUSIVE_RETRIEVAL equ 00040000h
      CRYPT_AIA_RETRIEVAL equ 00080000h
      CRYPT_HTTP_POST_RETRIEVAL equ 00100000h
      CRYPT_PROXY_CACHE_RETRIEVAL equ 00200000h
      CRYPT_NOT_MODIFIED_RETRIEVAL equ 00400000h
      CRYPT_ENABLE_SSL_REVOCATION_RETRIEVAL equ 00800000h
      CRYPT_RANDOM_QUERY_STRING_RETRIEVAL equ 04000000h
      CRYPT_ENABLE_FILE_RETRIEVAL equ 08000000h
      CRYPT_CREATE_NEW_FLUSH_ENTRY equ 10000000h
      CRYPT_VERIFY_CONTEXT_SIGNATURE equ 00000020h
      CRYPT_VERIFY_DATA_HASH equ 00000040h
      CRYPT_KEEP_TIME_VALID equ 00000080h
      CRYPT_DONT_VERIFY_SIGNATURE equ 00000100h
      CRYPT_DONT_CHECK_TIME_VALIDITY equ 00000200h
      CRYPT_CHECK_FRESHNESS_TIME_VALIDITY equ 00000400h
      CRYPT_ACCUMULATIVE_TIMEOUT equ 00000800h
      CRYPT_OCSP_ONLY_RETRIEVAL equ 01000000h
      CRYPT_NO_OCSP_FAILOVER_TO_CRL_RETRIEVAL equ 02000000h
      CRYPTNET_URL_CACHE_PRE_FETCH_INFO struct
        cbSize DWORD ?
        dwObjectType DWORD ?
        dwError DWORD ?
        dwReserved DWORD ?
        ThisUpdateTime FILETIME <>
        NextUpdateTime FILETIME <>
        PublishTime FILETIME <>
      CRYPTNET_URL_CACHE_PRE_FETCH_INFO ends
      _CRYPTNET_URL_CACHE_PRE_FETCH_INFO typedef CRYPTNET_URL_CACHE_PRE_FETCH_INFO
      PCRYPTNET_URL_CACHE_PRE_FETCH_INFO typedef ptr CRYPTNET_URL_CACHE_PRE_FETCH_INFO
      CRYPTNET_URL_CACHE_PRE_FETCH_NONE equ 0
      CRYPTNET_URL_CACHE_PRE_FETCH_BLOB equ 1
      CRYPTNET_URL_CACHE_PRE_FETCH_CRL equ 2
      CRYPTNET_URL_CACHE_PRE_FETCH_OCSP equ 3
      CRYPTNET_URL_CACHE_PRE_FETCH_AUTOROOT_CAB equ 5
      CRYPTNET_URL_CACHE_PRE_FETCH_DISALLOWED_CERT_CAB equ 6
      CRYPTNET_URL_CACHE_PRE_FETCH_PIN_RULES_CAB equ 7
      CRYPTNET_URL_CACHE_FLUSH_INFO struct
        cbSize DWORD ?
        dwExemptSeconds DWORD ?
        ExpireTime FILETIME <>
      CRYPTNET_URL_CACHE_FLUSH_INFO ends
      _CRYPTNET_URL_CACHE_FLUSH_INFO typedef CRYPTNET_URL_CACHE_FLUSH_INFO
      PCRYPTNET_URL_CACHE_FLUSH_INFO typedef ptr CRYPTNET_URL_CACHE_FLUSH_INFO
      CRYPTNET_URL_CACHE_DEFAULT_FLUSH equ 0
      CRYPTNET_URL_CACHE_DISABLE_FLUSH equ 0FFFFFFFFh
      CRYPTNET_URL_CACHE_RESPONSE_INFO struct
        cbSize DWORD ?
        wResponseType WORD ?
        wResponseFlags WORD ?
        LastModifiedTime FILETIME <>
        dwMaxAge DWORD ?
        pwszETag LPCWSTR ?
        dwProxyId DWORD ?
      CRYPTNET_URL_CACHE_RESPONSE_INFO ends
      _CRYPTNET_URL_CACHE_RESPONSE_INFO typedef CRYPTNET_URL_CACHE_RESPONSE_INFO
      PCRYPTNET_URL_CACHE_RESPONSE_INFO typedef ptr CRYPTNET_URL_CACHE_RESPONSE_INFO
      CRYPTNET_URL_CACHE_RESPONSE_NONE equ 0
      CRYPTNET_URL_CACHE_RESPONSE_HTTP equ 1
      CRYPTNET_URL_CACHE_RESPONSE_VALIDATED equ 8000h
      CRYPT_RETRIEVE_AUX_INFO struct
        cbSize DWORD ?
        pLastSyncTime POINTER ?
        dwMaxUrlRetrievalByteCount DWORD ?
        pPreFetchInfo PCRYPTNET_URL_CACHE_PRE_FETCH_INFO ?
        pFlushInfo PCRYPTNET_URL_CACHE_FLUSH_INFO ?
        ppResponseInfo POINTER ?
        pwszCacheFileNamePrefix LPWSTR ?
        pftCacheResync LPFILETIME ?
        fProxyCacheRetrieval BOOL ?
        dwHttpStatusCode DWORD ?
        ppwszErrorResponseHeaders POINTER ?
        ppErrorContentBlob POINTER ?
      CRYPT_RETRIEVE_AUX_INFO ends
      _CRYPT_RETRIEVE_AUX_INFO typedef CRYPT_RETRIEVE_AUX_INFO
      PCRYPT_RETRIEVE_AUX_INFO typedef ptr CRYPT_RETRIEVE_AUX_INFO
      CRYPT_RETRIEVE_MAX_ERROR_CONTENT_LENGTH equ 1000h
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_PHONE_RESTRICTED or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      @DefProto DllImport, CryptRetrieveObjectByUrlA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPCSTR, :DWORD, :DWORD, :ptr LPVOID, :HCRYPTASYNC, :PCRYPT_CREDENTIALS, :LPVOID, :PCRYPT_RETRIEVE_AUX_INFO>, 36
      @DefProto DllImport, CryptRetrieveObjectByUrlW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCSTR, :DWORD, :DWORD, :ptr LPVOID, :HCRYPTASYNC, :PCRYPT_CREDENTIALS, :LPVOID, :PCRYPT_RETRIEVE_AUX_INFO>, 36
      ifdef UNICODE
        CryptRetrieveObjectByUrl equ <CryptRetrieveObjectByUrlW>
      else
        CryptRetrieveObjectByUrl equ <CryptRetrieveObjectByUrlA>
      endif
      TYPE_PFN_CRYPT_CANCEL_RETRIEVAL typedef proto WIN_STD_CALL_CONV :DWORD, :ptr
      PFN_CRYPT_CANCEL_RETRIEVAL typedef ptr TYPE_PFN_CRYPT_CANCEL_RETRIEVAL

      @DefProto DllImport, CryptInstallCancelRetrieval, WIN_STD_CALL_CONV,, <:PFN_CRYPT_CANCEL_RETRIEVAL, :ptr, :DWORD, :ptr>, 16
      @DefProto DllImport, CryptUninstallCancelRetrieval, WIN_STD_CALL_CONV,, <:DWORD, :ptr>, 8
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_PHONE_RESTRICTED or WINAPI_PARTITION_GAMES)
      @DefProto DllImport, CryptCancelAsyncRetrieval, WIN_STD_CALL_CONV,, <:HCRYPTASYNC>, 4
      CRYPT_PARAM_ASYNC_RETRIEVAL_COMPLETION equ (1)
      TYPE_PFN_CRYPT_ASYNC_RETRIEVAL_COMPLETION_FUNC typedef proto WIN_STD_CALL_CONV :LPVOID, :DWORD, :LPCSTR, :LPSTR, :LPVOID
      PFN_CRYPT_ASYNC_RETRIEVAL_COMPLETION_FUNC typedef ptr TYPE_PFN_CRYPT_ASYNC_RETRIEVAL_COMPLETION_FUNC

      CRYPT_ASYNC_RETRIEVAL_COMPLETION struct
        pfnCompletion PFN_CRYPT_ASYNC_RETRIEVAL_COMPLETION_FUNC ?
        pvCompletion LPVOID ?
      CRYPT_ASYNC_RETRIEVAL_COMPLETION ends
      _CRYPT_ASYNC_RETRIEVAL_COMPLETION typedef CRYPT_ASYNC_RETRIEVAL_COMPLETION
      PCRYPT_ASYNC_RETRIEVAL_COMPLETION typedef ptr CRYPT_ASYNC_RETRIEVAL_COMPLETION
      CRYPT_PARAM_CANCEL_ASYNC_RETRIEVAL equ (2)
      TYPE_PFN_CANCEL_ASYNC_RETRIEVAL_FUNC typedef proto WIN_STD_CALL_CONV :HCRYPTASYNC
      PFN_CANCEL_ASYNC_RETRIEVAL_FUNC typedef ptr TYPE_PFN_CANCEL_ASYNC_RETRIEVAL_FUNC

    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_PHONE_RESTRICTED or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      CRYPT_GET_URL_FROM_PROPERTY equ 00000001h
      CRYPT_GET_URL_FROM_EXTENSION equ 00000002h
      CRYPT_GET_URL_FROM_UNAUTH_ATTRIBUTE equ 00000004h
      CRYPT_GET_URL_FROM_AUTH_ATTRIBUTE equ 00000008h
      CRYPT_URL_ARRAY struct
        cUrl DWORD ?
        rgwszUrl POINTER ?
      CRYPT_URL_ARRAY ends
      _CRYPT_URL_ARRAY typedef CRYPT_URL_ARRAY
      PCRYPT_URL_ARRAY typedef ptr CRYPT_URL_ARRAY
      CRYPT_URL_INFO struct
        cbSize DWORD ?
        dwSyncDeltaTime DWORD ?
        cGroup DWORD ?
        rgcGroupEntry POINTER ?
      CRYPT_URL_INFO ends
      _CRYPT_URL_INFO typedef CRYPT_URL_INFO
      PCRYPT_URL_INFO typedef ptr CRYPT_URL_INFO
      @DefProto DllImport, CryptGetObjectUrl, WIN_STD_CALL_CONV,, <:LPCSTR, :LPVOID, :DWORD, :PCRYPT_URL_ARRAY, :ptr DWORD, :PCRYPT_URL_INFO, :ptr DWORD, :LPVOID>, 32
      URL_OID_GET_OBJECT_URL_FUNC equ <"UrlDllGetObjectUrl">
      URL_OID_CERTIFICATE_ISSUER equ (1)
      URL_OID_CERTIFICATE_CRL_DIST_POINT equ (2)
      URL_OID_CTL_ISSUER equ (3)
      URL_OID_CTL_NEXT_UPDATE equ (4)
      URL_OID_CRL_ISSUER equ (5)
      URL_OID_CERTIFICATE_FRESHEST_CRL equ (6)
      URL_OID_CRL_FRESHEST_CRL equ (7)
      URL_OID_CROSS_CERT_DIST_POINT equ (8)
      URL_OID_CERTIFICATE_OCSP equ (9)
      URL_OID_CERTIFICATE_OCSP_AND_CRL_DIST_POINT equ (10)
      URL_OID_CERTIFICATE_CRL_DIST_POINT_AND_OCSP equ (11)
      URL_OID_CROSS_CERT_SUBJECT_INFO_ACCESS equ (12)
      URL_OID_CERTIFICATE_ONLY_OCSP equ (13)
      CERT_CRL_CONTEXT_PAIR struct
        pCertContext PCCERT_CONTEXT ?
        pCrlContext PCCRL_CONTEXT ?
      CERT_CRL_CONTEXT_PAIR ends
      _CERT_CRL_CONTEXT_PAIR typedef CERT_CRL_CONTEXT_PAIR
      PCERT_CRL_CONTEXT_PAIR typedef ptr CERT_CRL_CONTEXT_PAIR
      PCCERT_CRL_CONTEXT_PAIR typedef ptr CERT_CRL_CONTEXT_PAIR
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_PHONE_RESTRICTED or WINAPI_PARTITION_GAMES)
      CRYPT_GET_TIME_VALID_OBJECT_EXTRA_INFO struct
        cbSize DWORD ?
        iDeltaCrlIndicator SDWORD ?
        pftCacheResync LPFILETIME ?
        pLastSyncTime LPFILETIME ?
        pMaxAgeTime LPFILETIME ?
        pChainPara PCERT_REVOCATION_CHAIN_PARA ?
        pDeltaCrlIndicator PCRYPT_INTEGER_BLOB ?
      CRYPT_GET_TIME_VALID_OBJECT_EXTRA_INFO ends
      _CRYPT_GET_TIME_VALID_OBJECT_EXTRA_INFO typedef CRYPT_GET_TIME_VALID_OBJECT_EXTRA_INFO
      PCRYPT_GET_TIME_VALID_OBJECT_EXTRA_INFO typedef ptr CRYPT_GET_TIME_VALID_OBJECT_EXTRA_INFO
      @DefProto DllImport, CryptGetTimeValidObject, WIN_STD_CALL_CONV,, <:LPCSTR, :LPVOID, :PCCERT_CONTEXT, :LPFILETIME, :DWORD, :DWORD, :ptr LPVOID, :PCRYPT_CREDENTIALS, :PCRYPT_GET_TIME_VALID_OBJECT_EXTRA_INFO>, 36
      TIME_VALID_OID_GET_OBJECT_FUNC equ <"TimeValidDllGetObject">
      TIME_VALID_OID_GET_CTL equ (1)
      TIME_VALID_OID_GET_CRL equ (2)
      TIME_VALID_OID_GET_CRL_FROM_CERT equ (3)
      TIME_VALID_OID_GET_FRESHEST_CRL_FROM_CERT equ (4)
      TIME_VALID_OID_GET_FRESHEST_CRL_FROM_CRL equ (5)
      @DefProto DllImport, CryptFlushTimeValidObject, WIN_STD_CALL_CONV,, <:LPCSTR, :LPVOID, :PCCERT_CONTEXT, :DWORD, :LPVOID>, 20
      TIME_VALID_OID_FLUSH_OBJECT_FUNC equ <"TimeValidDllFlushObject">
      TIME_VALID_OID_FLUSH_CTL equ (1)
      TIME_VALID_OID_FLUSH_CRL equ (2)
      TIME_VALID_OID_FLUSH_CRL_FROM_CERT equ (3)
      TIME_VALID_OID_FLUSH_FRESHEST_CRL_FROM_CERT equ (4)
      TIME_VALID_OID_FLUSH_FRESHEST_CRL_FROM_CRL equ (5)
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      @DefProto DllImport, CertCreateSelfSignCertificate, WIN_STD_CALL_CONV,, <:HCRYPTPROV_OR_NCRYPT_KEY_HANDLE, :PCERT_NAME_BLOB, :DWORD, :PCRYPT_KEY_PROV_INFO, :PCRYPT_ALGORITHM_IDENTIFIER, :PSYSTEMTIME, :PSYSTEMTIME, :PCERT_EXTENSIONS>, 32
      CERT_CREATE_SELFSIGN_NO_SIGN equ 1
      CERT_CREATE_SELFSIGN_NO_KEY_INFO equ 2
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_PHONE_RESTRICTED or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      @DefProto DllImport, CryptGetKeyIdentifierProperty, WIN_STD_CALL_CONV,, <:ptr CRYPT_HASH_BLOB, :DWORD, :DWORD, :LPCWSTR, :ptr, :ptr, :ptr DWORD>, 28
      CRYPT_KEYID_MACHINE_FLAG equ 00000020h
      CRYPT_KEYID_ALLOC_FLAG equ 00008000h
      @DefProto DllImport, CryptSetKeyIdentifierProperty, WIN_STD_CALL_CONV,, <:ptr CRYPT_HASH_BLOB, :DWORD, :DWORD, :LPCWSTR, :ptr, :ptr>, 24
      CRYPT_KEYID_DELETE_FLAG equ 00000010h
      CRYPT_KEYID_SET_NEW_FLAG equ 00002000h
      TYPE_PFN_CRYPT_ENUM_KEYID_PROP typedef proto WIN_STD_CALL_CONV :ptr CRYPT_HASH_BLOB, :DWORD, :ptr, :ptr, :DWORD, :ptr DWORD, :ptr ptr, :ptr DWORD
      PFN_CRYPT_ENUM_KEYID_PROP typedef ptr TYPE_PFN_CRYPT_ENUM_KEYID_PROP

      @DefProto DllImport, CryptEnumKeyIdentifierProperties, WIN_STD_CALL_CONV,, <:ptr CRYPT_HASH_BLOB, :DWORD, :DWORD, :LPCWSTR, :ptr, :ptr, :PFN_CRYPT_ENUM_KEYID_PROP>, 28
      @DefProto DllImport, CryptCreateKeyIdentifierFromCSP, WIN_STD_CALL_CONV,, <:DWORD, :LPCSTR, :ptr PUBLICKEYSTRUC, :DWORD, :DWORD, :ptr, :ptr BYTE, :ptr DWORD>, 32
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      CERT_CHAIN_CONFIG_REGPATH equ <L("Software\Microsoft\Cryptography\OID\EncodingType 0\CertDllCreateCertificateChainEngine\Config")>
      CERT_CHAIN_MAX_URL_RETRIEVAL_BYTE_COUNT_VALUE_NAME equ <L("MaxUrlRetrievalByteCount")>
      CERT_CHAIN_MAX_URL_RETRIEVAL_BYTE_COUNT_DEFAULT equ (100 * 1024 * 1024)
      CERT_CHAIN_CACHE_RESYNC_FILETIME_VALUE_NAME equ <L("ChainCacheResyncFiletime")>
      CERT_CHAIN_DISABLE_MANDATORY_BASIC_CONSTRAINTS_VALUE_NAME equ <L("DisableMandatoryBasicConstraints")>
      CERT_CHAIN_DISABLE_CA_NAME_CONSTRAINTS_VALUE_NAME equ <L("DisableCANameConstraints")>
      CERT_CHAIN_DISABLE_UNSUPPORTED_CRITICAL_EXTENSIONS_VALUE_NAME equ <L("DisableUnsupportedCriticalExtensions")>
      CERT_CHAIN_MAX_AIA_URL_COUNT_IN_CERT_VALUE_NAME equ <L("MaxAIAUrlCountInCert")>
      CERT_CHAIN_MAX_AIA_URL_COUNT_IN_CERT_DEFAULT equ 5
      CERT_CHAIN_MAX_AIA_URL_RETRIEVAL_COUNT_PER_CHAIN_VALUE_NAME equ <L("MaxAIAUrlRetrievalCountPerChain")>
      CERT_CHAIN_MAX_AIA_URL_RETRIEVAL_COUNT_PER_CHAIN_DEFAULT equ 3
      CERT_CHAIN_MAX_AIA_URL_RETRIEVAL_BYTE_COUNT_VALUE_NAME equ <L("MaxAIAUrlRetrievalByteCount")>
      CERT_CHAIN_MAX_AIA_URL_RETRIEVAL_BYTE_COUNT_DEFAULT equ 100000
      CERT_CHAIN_MAX_AIA_URL_RETRIEVAL_CERT_COUNT_VALUE_NAME equ <L("MaxAIAUrlRetrievalCertCount")>
      CERT_CHAIN_MAX_AIA_URL_RETRIEVAL_CERT_COUNT_DEFAULT equ 10
      CERT_CHAIN_OCSP_VALIDITY_SECONDS_VALUE_NAME equ <L("OcspValiditySeconds")>
      CERT_CHAIN_OCSP_VALIDITY_SECONDS_DEFAULT equ (12 * 60 * 60)
      CERT_CHAIN_DISABLE_SERIAL_CHAIN_VALUE_NAME equ <L("DisableSerialChain")>
      CERT_CHAIN_SERIAL_CHAIN_LOG_FILE_NAME_VALUE_NAME equ <L("SerialChainLogFileName")>
      CERT_CHAIN_DISABLE_SYNC_WITH_SSL_TIME_VALUE_NAME equ <L("DisableSyncWithSslTime")>
      CERT_CHAIN_MAX_SSL_TIME_UPDATED_EVENT_COUNT_VALUE_NAME equ <L("MaxSslTimeUpdatedEventCount")>
      CERT_CHAIN_MAX_SSL_TIME_UPDATED_EVENT_COUNT_DEFAULT equ 5
      CERT_CHAIN_MAX_SSL_TIME_UPDATED_EVENT_COUNT_DISABLE equ 0FFFFFFFFh
      CERT_CHAIN_SSL_HANDSHAKE_LOG_FILE_NAME_VALUE_NAME equ <L("SslHandshakeLogFileName")>
      CERT_CHAIN_ENABLE_WEAK_SIGNATURE_FLAGS_VALUE_NAME equ <L("EnableWeakSignatureFlags")>
      CERT_CHAIN_ENABLE_MD2_MD4_FLAG equ 00000001h
      CERT_CHAIN_ENABLE_WEAK_RSA_ROOT_FLAG equ 00000002h
      CERT_CHAIN_ENABLE_WEAK_LOGGING_FLAG equ 00000004h
      CERT_CHAIN_ENABLE_ONLY_WEAK_LOGGING_FLAG equ 00000008h
      CERT_CHAIN_MIN_RSA_PUB_KEY_BIT_LENGTH_VALUE_NAME equ <L("MinRsaPubKeyBitLength")>
      CERT_CHAIN_MIN_RSA_PUB_KEY_BIT_LENGTH_DEFAULT equ 1023
      CERT_CHAIN_MIN_RSA_PUB_KEY_BIT_LENGTH_DISABLE equ 0FFFFFFFFh
      CERT_CHAIN_WEAK_RSA_PUB_KEY_TIME_VALUE_NAME equ <L("WeakRsaPubKeyTime")>
      CERT_CHAIN_WEAK_RSA_PUB_KEY_TIME_DEFAULT equ 01CA8A755C6E0000h
      CERT_CHAIN_WEAK_SIGNATURE_LOG_DIR_VALUE_NAME equ <L("WeakSignatureLogDir")>
      CERT_CHAIN_DEFAULT_CONFIG_SUBDIR equ <L("Default")>
      CERT_CHAIN_WEAK_PREFIX_NAME equ <L("Weak")>
      CERT_CHAIN_WEAK_THIRD_PARTY_CONFIG_NAME equ <L("ThirdParty")>
      CERT_CHAIN_WEAK_ALL_CONFIG_NAME equ <L("All")>
      CERT_CHAIN_WEAK_FLAGS_NAME equ <L("Flags")>
      CERT_CHAIN_WEAK_HYGIENE_NAME equ <L("Hygiene")>
      CERT_CHAIN_WEAK_AFTER_TIME_NAME equ <L("AfterTime")>
      CERT_CHAIN_WEAK_FILE_HASH_AFTER_TIME_NAME equ <L("FileHashAfterTime")>
      CERT_CHAIN_WEAK_TIMESTAMP_HASH_AFTER_TIME_NAME equ <L("TimestampHashAfterTime")>
      CERT_CHAIN_WEAK_MIN_BIT_LENGTH_NAME equ <L("MinBitLength")>
      CERT_CHAIN_WEAK_SHA256_ALLOW_NAME equ <L("Sha256Allow")>
      CERT_CHAIN_MIN_PUB_KEY_BIT_LENGTH_DISABLE equ 0FFFFFFFFh
      CERT_CHAIN_ENABLE_WEAK_SETTINGS_FLAG equ 80000000h
      CERT_CHAIN_DISABLE_ECC_PARA_FLAG equ 00000010h
      CERT_CHAIN_DISABLE_ALL_EKU_WEAK_FLAG equ 00010000h
      CERT_CHAIN_ENABLE_ALL_EKU_HYGIENE_FLAG equ 00020000h
      CERT_CHAIN_DISABLE_OPT_IN_SERVER_AUTH_WEAK_FLAG equ 00040000h
      CERT_CHAIN_DISABLE_SERVER_AUTH_WEAK_FLAG equ 00100000h
      CERT_CHAIN_ENABLE_SERVER_AUTH_HYGIENE_FLAG equ 00200000h
      CERT_CHAIN_DISABLE_CODE_SIGNING_WEAK_FLAG equ 00400000h
      CERT_CHAIN_DISABLE_MOTW_CODE_SIGNING_WEAK_FLAG equ 00800000h
      CERT_CHAIN_ENABLE_CODE_SIGNING_HYGIENE_FLAG equ 01000000h
      CERT_CHAIN_ENABLE_MOTW_CODE_SIGNING_HYGIENE_FLAG equ 02000000h
      CERT_CHAIN_DISABLE_TIMESTAMP_WEAK_FLAG equ 04000000h
      CERT_CHAIN_DISABLE_MOTW_TIMESTAMP_WEAK_FLAG equ 08000000h
      CERT_CHAIN_ENABLE_TIMESTAMP_HYGIENE_FLAG equ 10000000h
      CERT_CHAIN_ENABLE_MOTW_TIMESTAMP_HYGIENE_FLAG equ 20000000h
      CERT_CHAIN_MOTW_IGNORE_AFTER_TIME_WEAK_FLAG equ 40000000h
      CERT_CHAIN_DISABLE_FILE_HASH_WEAK_FLAG equ 00001000h
      CERT_CHAIN_DISABLE_MOTW_FILE_HASH_WEAK_FLAG equ 00002000h
      CERT_CHAIN_DISABLE_TIMESTAMP_HASH_WEAK_FLAG equ 00004000h
      CERT_CHAIN_DISABLE_MOTW_TIMESTAMP_HASH_WEAK_FLAG equ 00008000h
      CERT_CHAIN_DISABLE_WEAK_FLAGS equ <(CERT_CHAIN_DISABLE_ECC_PARA_FLAG or CERT_CHAIN_DISABLE_ALL_EKU_WEAK_FLAG or CERT_CHAIN_DISABLE_SERVER_AUTH_WEAK_FLAG or CERT_CHAIN_DISABLE_OPT_IN_SERVER_AUTH_WEAK_FLAG or CERT_CHAIN_DISABLE_CODE_SIGNING_WEAK_FLAG or CERT_CHAIN_DISABLE_MOTW_CODE_SIGNING_WEAK_FLAG or CERT_CHAIN_DISABLE_TIMESTAMP_WEAK_FLAG or CERT_CHAIN_DISABLE_MOTW_TIMESTAMP_WEAK_FLAG)>
      CERT_CHAIN_DISABLE_FILE_HASH_WEAK_FLAGS equ <(CERT_CHAIN_DISABLE_FILE_HASH_WEAK_FLAG or CERT_CHAIN_DISABLE_MOTW_FILE_HASH_WEAK_FLAG)>
      CERT_CHAIN_DISABLE_TIMESTAMP_HASH_WEAK_FLAGS equ <(CERT_CHAIN_DISABLE_TIMESTAMP_HASH_WEAK_FLAG or CERT_CHAIN_DISABLE_MOTW_TIMESTAMP_HASH_WEAK_FLAG)>
      CERT_CHAIN_ENABLE_HYGIENE_FLAGS equ <(CERT_CHAIN_ENABLE_ALL_EKU_HYGIENE_FLAG or CERT_CHAIN_ENABLE_SERVER_AUTH_HYGIENE_FLAG or CERT_CHAIN_ENABLE_CODE_SIGNING_HYGIENE_FLAG or CERT_CHAIN_ENABLE_MOTW_CODE_SIGNING_HYGIENE_FLAG or CERT_CHAIN_ENABLE_TIMESTAMP_HYGIENE_FLAG or CERT_CHAIN_ENABLE_MOTW_TIMESTAMP_HYGIENE_FLAG)>
      CERT_CHAIN_MOTW_WEAK_FLAGS equ <(CERT_CHAIN_DISABLE_MOTW_CODE_SIGNING_WEAK_FLAG or CERT_CHAIN_DISABLE_MOTW_TIMESTAMP_WEAK_FLAG or CERT_CHAIN_ENABLE_MOTW_CODE_SIGNING_HYGIENE_FLAG or CERT_CHAIN_ENABLE_MOTW_TIMESTAMP_HYGIENE_FLAG or CERT_CHAIN_MOTW_IGNORE_AFTER_TIME_WEAK_FLAG)>
      CERT_CHAIN_OPT_IN_WEAK_FLAGS equ <(CERT_CHAIN_DISABLE_OPT_IN_SERVER_AUTH_WEAK_FLAG)>
      CERT_CHAIN_AUTO_CURRENT_USER equ 1
      CERT_CHAIN_AUTO_LOCAL_MACHINE equ 2
      CERT_CHAIN_AUTO_IMPERSONATED equ 3
      CERT_CHAIN_AUTO_PROCESS_INFO equ 4
      CERT_CHAIN_AUTO_PINRULE_INFO equ 5
      CERT_CHAIN_AUTO_NETWORK_INFO equ 6
      CERT_CHAIN_AUTO_SERIAL_LOCAL_MACHINE equ 7
      CERT_CHAIN_AUTO_HPKP_RULE_INFO equ 8
      CERT_CHAIN_AUTO_FLAGS_VALUE_NAME equ <L("AutoFlags")>
      CERT_CHAIN_AUTO_FLUSH_DISABLE_FLAG equ 00000001h
      CERT_CHAIN_AUTO_LOG_CREATE_FLAG equ 00000002h
      CERT_CHAIN_AUTO_LOG_FREE_FLAG equ 00000004h
      CERT_CHAIN_AUTO_LOG_FLUSH_FLAG equ 00000008h
      CERT_CHAIN_AUTO_LOG_FLAGS equ <(CERT_CHAIN_AUTO_LOG_CREATE_FLAG or CERT_CHAIN_AUTO_LOG_FREE_FLAG or CERT_CHAIN_AUTO_LOG_FLUSH_FLAG)>
      CERT_CHAIN_AUTO_FLUSH_FIRST_DELTA_SECONDS_VALUE_NAME equ <L("AutoFlushFirstDeltaSeconds")>
      CERT_CHAIN_AUTO_FLUSH_FIRST_DELTA_SECONDS_DEFAULT equ (5 * 60)
      CERT_CHAIN_AUTO_FLUSH_NEXT_DELTA_SECONDS_VALUE_NAME equ <L("AutoFlushNextDeltaSeconds")>
      CERT_CHAIN_AUTO_FLUSH_NEXT_DELTA_SECONDS_DEFAULT equ (30 * 60)
      CERT_CHAIN_AUTO_LOG_FILE_NAME_VALUE_NAME equ <L("AutoLogFileName")>
      CERT_CHAIN_DISABLE_AUTO_FLUSH_PROCESS_NAME_LIST_VALUE_NAME equ <L("DisableAutoFlushProcessNameList")>
      CERT_SRV_OCSP_RESP_MIN_VALIDITY_SECONDS_VALUE_NAME equ <L("SrvOcspRespMinValiditySeconds")>
      CERT_SRV_OCSP_RESP_MIN_VALIDITY_SECONDS_DEFAULT equ (10 * 60)
      CERT_SRV_OCSP_RESP_URL_RETRIEVAL_TIMEOUT_MILLISECONDS_VALUE_NAME equ <L("SrvOcspRespUrlRetrievalTimeoutMilliseconds")>
      CERT_SRV_OCSP_RESP_URL_RETRIEVAL_TIMEOUT_MILLISECONDS_DEFAULT equ (15 * 1000)
      CERT_SRV_OCSP_RESP_MAX_BEFORE_NEXT_UPDATE_SECONDS_VALUE_NAME equ <L("SrvOcspRespMaxBeforeNextUpdateSeconds")>
      CERT_SRV_OCSP_RESP_MAX_BEFORE_NEXT_UPDATE_SECONDS_DEFAULT equ (4 * 60 * 60)
      CERT_SRV_OCSP_RESP_MIN_BEFORE_NEXT_UPDATE_SECONDS_VALUE_NAME equ <L("SrvOcspRespMinBeforeNextUpdateSeconds")>
      CERT_SRV_OCSP_RESP_MIN_BEFORE_NEXT_UPDATE_SECONDS_DEFAULT equ (2 * 60)
      CERT_SRV_OCSP_RESP_MIN_AFTER_NEXT_UPDATE_SECONDS_VALUE_NAME equ <L("SrvOcspRespMinAfterNextUpdateSeconds")>
      CERT_SRV_OCSP_RESP_MIN_AFTER_NEXT_UPDATE_SECONDS_DEFAULT equ (1 * 60)
      CERT_SRV_OCSP_RESP_MIN_SYNC_CERT_FILE_SECONDS_VALUE_NAME equ <L("SrvOcspRespMinSyncCertFileSeconds")>
      CERT_SRV_OCSP_RESP_MIN_SYNC_CERT_FILE_SECONDS_DEFAULT equ 5
      CERT_SRV_OCSP_RESP_MAX_SYNC_CERT_FILE_SECONDS_VALUE_NAME equ <L("SrvOcspRespMaxSyncCertFileSeconds")>
      CERT_SRV_OCSP_RESP_MAX_SYNC_CERT_FILE_SECONDS_DEFAULT equ (1 * 60 * 60)
      CRYPTNET_MAX_CACHED_OCSP_PER_CRL_COUNT_VALUE_NAME equ <L("CryptnetMaxCachedOcspPerCrlCount")>
      CRYPTNET_MAX_CACHED_OCSP_PER_CRL_COUNT_DEFAULT equ 500
      CRYPTNET_OCSP_AFTER_CRL_DISABLE equ 0FFFFFFFFh
      CRYPTNET_URL_CACHE_DEFAULT_FLUSH_EXEMPT_SECONDS_VALUE_NAME equ <L("CryptnetDefaultFlushExemptSeconds")>
      CRYPTNET_URL_CACHE_DEFAULT_FLUSH_EXEMPT_SECONDS_DEFAULT equ (28 * 24 * 60 * 60)
      CRYPTNET_PRE_FETCH_MIN_MAX_AGE_SECONDS_VALUE_NAME equ <L("CryptnetPreFetchMinMaxAgeSeconds")>
      CRYPTNET_PRE_FETCH_MIN_MAX_AGE_SECONDS_DEFAULT equ (1 * 60 * 60)
      CRYPTNET_PRE_FETCH_MAX_MAX_AGE_SECONDS_VALUE_NAME equ <L("CryptnetPreFetchMaxMaxAgeSeconds")>
      CRYPTNET_PRE_FETCH_MAX_MAX_AGE_SECONDS_DEFAULT equ (14 * 24 * 60 * 60)
      CRYPTNET_PRE_FETCH_MIN_OCSP_VALIDITY_PERIOD_SECONDS_VALUE_NAME equ <L("CryptnetPreFetchMinOcspValidityPeriodSeconds")>
      CRYPTNET_PRE_FETCH_MIN_OCSP_VALIDITY_PERIOD_SECONDS_DEFAULT equ (14 * 24 * 60 * 60)
      CRYPTNET_PRE_FETCH_AFTER_PUBLISH_PRE_FETCH_DIVISOR_VALUE_NAME equ <L("CryptnetPreFetchAfterPublishPreFetchDivisor")>
      CRYPTNET_PRE_FETCH_AFTER_PUBLISH_PRE_FETCH_DIVISOR_DEFAULT equ 10
      CRYPTNET_PRE_FETCH_BEFORE_NEXT_UPDATE_PRE_FETCH_DIVISOR_VALUE_NAME equ <L("CryptnetPreFetchBeforeNextUpdatePreFetchDivisor")>
      CRYPTNET_PRE_FETCH_BEFORE_NEXT_UPDATE_PRE_FETCH_DIVISOR_DEFAULT equ 20
      CRYPTNET_PRE_FETCH_MIN_BEFORE_NEXT_UPDATE_PRE_FETCH_PERIOD_SECONDS_VALUE_NAME equ <L("CryptnetPreFetchMinBeforeNextUpdatePreFetchSeconds")>
      CRYPTNET_PRE_FETCH_MIN_BEFORE_NEXT_UPDATE_PRE_FETCH_PERIOD_SECONDS_DEFAULT equ (1 * 60 * 60)
      CRYPTNET_PRE_FETCH_VALIDITY_PERIOD_AFTER_NEXT_UPDATE_PRE_FETCH_DIVISOR_VALUE_NAME equ <L("CryptnetPreFetchValidityPeriodAfterNextUpdatePreFetchDivisor")>
      CRYPTNET_PRE_FETCH_VALIDITY_PERIOD_AFTER_NEXT_UPDATE_PRE_FETCH_DIVISOR_DEFAULT equ 10
      CRYPTNET_PRE_FETCH_MAX_AFTER_NEXT_UPDATE_PRE_FETCH_PERIOD_SECONDS_VALUE_NAME equ <L("CryptnetPreFetchMaxAfterNextUpdatePreFetchPeriodSeconds")>
      CRYPTNET_PRE_FETCH_MAX_AFTER_NEXT_UPDATE_PRE_FETCH_PERIOD_SECONDS_DEFAULT equ (4 * 60 * 60)
      CRYPTNET_PRE_FETCH_MIN_AFTER_NEXT_UPDATE_PRE_FETCH_PERIOD_SECONDS_VALUE_NAME equ <L("CryptnetPreFetchMinAfterNextUpdatePreFetchPeriodSeconds")>
      CRYPTNET_PRE_FETCH_MIN_AFTER_NEXT_UPDATE_PRE_FETCH_PERIOD_SECONDS_DEFAULT equ (30 * 60)
      CRYPTNET_PRE_FETCH_AFTER_CURRENT_TIME_PRE_FETCH_PERIOD_SECONDS_VALUE_NAME equ <L("CryptnetPreFetchAfterCurrentTimePreFetchPeriodSeconds")>
      CRYPTNET_PRE_FETCH_AFTER_CURRENT_TIME_PRE_FETCH_PERIOD_SECONDS_DEFAULT equ (30 * 60)
      CRYPTNET_PRE_FETCH_TRIGGER_PERIOD_SECONDS_VALUE_NAME equ <L("CryptnetPreFetchTriggerPeriodSeconds")>
      CRYPTNET_PRE_FETCH_TRIGGER_PERIOD_SECONDS_DEFAULT equ (10 * 60)
      CRYPTNET_PRE_FETCH_TRIGGER_DISABLE equ 0FFFFFFFFh
      CRYPTNET_PRE_FETCH_SCAN_AFTER_TRIGGER_DELAY_SECONDS_VALUE_NAME equ <L("CryptnetPreFetchScanAfterTriggerDelaySeconds")>
      CRYPTNET_PRE_FETCH_SCAN_AFTER_TRIGGER_DELAY_SECONDS_DEFAULT equ 60
      CRYPTNET_PRE_FETCH_RETRIEVAL_TIMEOUT_SECONDS_VALUE_NAME equ <L("CryptnetPreFetchRetrievalTimeoutSeconds")>
      CRYPTNET_PRE_FETCH_RETRIEVAL_TIMEOUT_SECONDS_DEFAULT equ (5 * 60)
      CRYPTNET_CRL_PRE_FETCH_CONFIG_REGPATH equ <CERT_CHAIN_CONFIG_REGPATH L("\CrlPreFetch")>
      CRYPTNET_CRL_PRE_FETCH_PROCESS_NAME_LIST_VALUE_NAME equ <L("ProcessNameList")>
      CRYPTNET_CRL_PRE_FETCH_URL_LIST_VALUE_NAME equ <L("PreFetchUrlList")>
      CRYPTNET_CRL_PRE_FETCH_DISABLE_INFORMATION_EVENTS_VALUE_NAME equ <L("DisableInformationEvents")>
      CRYPTNET_CRL_PRE_FETCH_LOG_FILE_NAME_VALUE_NAME equ <L("LogFileName")>
      CRYPTNET_CRL_PRE_FETCH_TIMEOUT_SECONDS_VALUE_NAME equ <L("TimeoutSeconds")>
      CRYPTNET_CRL_PRE_FETCH_TIMEOUT_SECONDS_DEFAULT equ (5 * 60)
      CRYPTNET_CRL_PRE_FETCH_MAX_AGE_SECONDS_VALUE_NAME equ <L("MaxAgeSeconds")>
      CRYPTNET_CRL_PRE_FETCH_MAX_AGE_SECONDS_DEFAULT equ (2 * 60 * 60)
      CRYPTNET_CRL_PRE_FETCH_MAX_AGE_SECONDS_MIN equ (5 * 60)
      CRYPTNET_CRL_PRE_FETCH_PUBLISH_BEFORE_NEXT_UPDATE_SECONDS_VALUE_NAME equ <L("PublishBeforeNextUpdateSeconds")>
      CRYPTNET_CRL_PRE_FETCH_PUBLISH_BEFORE_NEXT_UPDATE_SECONDS_DEFAULT equ (1 * 60 * 60)
      CRYPTNET_CRL_PRE_FETCH_PUBLISH_RANDOM_INTERVAL_SECONDS_VALUE_NAME equ <L("PublishRandomIntervalSeconds")>
      CRYPTNET_CRL_PRE_FETCH_PUBLISH_RANDOM_INTERVAL_SECONDS_DEFAULT equ (5 * 60)
      CRYPTNET_CRL_PRE_FETCH_MIN_BEFORE_NEXT_UPDATE_SECONDS_VALUE_NAME equ <L("MinBeforeNextUpdateSeconds")>
      CRYPTNET_CRL_PRE_FETCH_MIN_BEFORE_NEXT_UPDATE_SECONDS_DEFAULT equ (5 * 60)
      CRYPTNET_CRL_PRE_FETCH_MIN_AFTER_NEXT_UPDATE_SECONDS_VALUE_NAME equ <L("MinAfterNextUpdateSeconds")>
      CRYPTNET_CRL_PRE_FETCH_MIN_AFTER_NEXT_UPDATE_SECONDS_DEFAULT equ (5 * 60)
      CERT_GROUP_POLICY_CHAIN_CONFIG_REGPATH equ <CERT_GROUP_POLICY_SYSTEM_STORE_REGPATH L("\ChainEngine\Config")>
      CERT_CHAIN_URL_RETRIEVAL_TIMEOUT_MILLISECONDS_VALUE_NAME equ <L("ChainUrlRetrievalTimeoutMilliseconds")>
      CERT_CHAIN_URL_RETRIEVAL_TIMEOUT_MILLISECONDS_DEFAULT equ (15 * 1000)
      CERT_CHAIN_REV_ACCUMULATIVE_URL_RETRIEVAL_TIMEOUT_MILLISECONDS_VALUE_NAME equ <L("ChainRevAccumulativeUrlRetrievalTimeoutMilliseconds")>
      CERT_CHAIN_REV_ACCUMULATIVE_URL_RETRIEVAL_TIMEOUT_MILLISECONDS_DEFAULT equ (20 * 1000)
      CERT_RETR_BEHAVIOR_INET_AUTH_VALUE_NAME equ <L("EnableInetUnknownAuth")>
      CERT_RETR_BEHAVIOR_INET_STATUS_VALUE_NAME equ <L("EnableInetLocal")>
      CERT_RETR_BEHAVIOR_FILE_VALUE_NAME equ <L("AllowFileUrlScheme")>
      CERT_RETR_BEHAVIOR_LDAP_VALUE_NAME equ <L("DisableLDAPSignAndEncrypt")>
      CRYPTNET_CACHED_OCSP_SWITCH_TO_CRL_COUNT_VALUE_NAME equ <L("CryptnetCachedOcspSwitchToCrlCount")>
      CRYPTNET_CACHED_OCSP_SWITCH_TO_CRL_COUNT_DEFAULT equ 50
      CRYPTNET_CRL_BEFORE_OCSP_ENABLE equ 0FFFFFFFFh
      CERT_CHAIN_DISABLE_AIA_URL_RETRIEVAL_VALUE_NAME equ <L("DisableAIAUrlRetrieval")>
      CERT_CHAIN_OPTIONS_VALUE_NAME equ <L("Options")>
      CERT_CHAIN_OPTION_DISABLE_AIA_URL_RETRIEVAL equ 2h
      CERT_CHAIN_OPTION_ENABLE_SIA_URL_RETRIEVAL equ 4h
      CERT_CHAIN_CROSS_CERT_DOWNLOAD_INTERVAL_HOURS_VALUE_NAME equ <L("CrossCertDownloadIntervalHours")>
      CERT_CHAIN_CROSS_CERT_DOWNLOAD_INTERVAL_HOURS_DEFAULT equ (24 * 7)
      CERT_CHAIN_CRL_VALIDITY_EXT_PERIOD_HOURS_VALUE_NAME equ <L("CRLValidityExtensionPeriod")>
      CERT_CHAIN_CRL_VALIDITY_EXT_PERIOD_HOURS_DEFAULT equ 12
      HCERTCHAINENGINE typedef HANDLE
      HCCE_CURRENT_USER equ <(NULL)>
      HCCE_LOCAL_MACHINE equ (1h)
      HCCE_SERIAL_LOCAL_MACHINE equ (2h)
      CERT_CHAIN_CACHE_END_CERT equ 00000001h
      CERT_CHAIN_THREAD_STORE_SYNC equ 00000002h
      CERT_CHAIN_CACHE_ONLY_URL_RETRIEVAL equ 00000004h
      CERT_CHAIN_USE_LOCAL_MACHINE_STORE equ 00000008h
      CERT_CHAIN_ENABLE_CACHE_AUTO_UPDATE equ 00000010h
      CERT_CHAIN_ENABLE_SHARE_STORE equ 00000020h
      CERT_CHAIN_ENGINE_CONFIG struct
        cbSize DWORD ?
        hRestrictedRoot HCERTSTORE ?
        hRestrictedTrust HCERTSTORE ?
        hRestrictedOther HCERTSTORE ?
        cAdditionalStore DWORD ?
        rghAdditionalStore POINTER ?
        dwFlags DWORD ?
        dwUrlRetrievalTimeout DWORD ?
        MaximumCachedCertificates DWORD ?
        CycleDetectionModulus DWORD ?
        if (NTDDI_VERSION ge NTDDI_WIN7)
          hExclusiveRoot HCERTSTORE ?
          hExclusiveTrustedPeople HCERTSTORE ?
        endif
        if (NTDDI_VERSION ge NTDDI_WIN8)
          dwExclusiveFlags DWORD ?
        endif
      CERT_CHAIN_ENGINE_CONFIG ends
      _CERT_CHAIN_ENGINE_CONFIG typedef CERT_CHAIN_ENGINE_CONFIG
      PCERT_CHAIN_ENGINE_CONFIG typedef ptr CERT_CHAIN_ENGINE_CONFIG
      if (NTDDI_VERSION ge NTDDI_WIN8)
        CERT_CHAIN_EXCLUSIVE_ENABLE_CA_FLAG equ 00000001h
      endif
      @DefProto DllImport, CertCreateCertificateChainEngine, WIN_STD_CALL_CONV,, <:PCERT_CHAIN_ENGINE_CONFIG, :ptr HCERTCHAINENGINE>, 8
      @DefProto DllImport, CertFreeCertificateChainEngine, WIN_STD_CALL_CONV,, <:HCERTCHAINENGINE>, 4
      @DefProto DllImport, CertResyncCertificateChainEngine, WIN_STD_CALL_CONV,, <:HCERTCHAINENGINE>, 4
      CERT_TRUST_STATUS struct
        dwErrorStatus DWORD ?
        dwInfoStatus DWORD ?
      CERT_TRUST_STATUS ends
      _CERT_TRUST_STATUS typedef CERT_TRUST_STATUS
      PCERT_TRUST_STATUS typedef ptr CERT_TRUST_STATUS
      CERT_TRUST_NO_ERROR equ 00000000h
      CERT_TRUST_IS_NOT_TIME_VALID equ 00000001h
      CERT_TRUST_IS_NOT_TIME_NESTED equ 00000002h
      CERT_TRUST_IS_REVOKED equ 00000004h
      CERT_TRUST_IS_NOT_SIGNATURE_VALID equ 00000008h
      CERT_TRUST_IS_NOT_VALID_FOR_USAGE equ 00000010h
      CERT_TRUST_IS_UNTRUSTED_ROOT equ 00000020h
      CERT_TRUST_REVOCATION_STATUS_UNKNOWN equ 00000040h
      CERT_TRUST_IS_CYCLIC equ 00000080h
      CERT_TRUST_INVALID_EXTENSION equ 00000100h
      CERT_TRUST_INVALID_POLICY_CONSTRAINTS equ 00000200h
      CERT_TRUST_INVALID_BASIC_CONSTRAINTS equ 00000400h
      CERT_TRUST_INVALID_NAME_CONSTRAINTS equ 00000800h
      CERT_TRUST_HAS_NOT_SUPPORTED_NAME_CONSTRAINT equ 00001000h
      CERT_TRUST_HAS_NOT_DEFINED_NAME_CONSTRAINT equ 00002000h
      CERT_TRUST_HAS_NOT_PERMITTED_NAME_CONSTRAINT equ 00004000h
      CERT_TRUST_HAS_EXCLUDED_NAME_CONSTRAINT equ 00008000h
      CERT_TRUST_IS_OFFLINE_REVOCATION equ 01000000h
      CERT_TRUST_NO_ISSUANCE_CHAIN_POLICY equ 02000000h
      CERT_TRUST_IS_EXPLICIT_DISTRUST equ 04000000h
      CERT_TRUST_HAS_NOT_SUPPORTED_CRITICAL_EXT equ 08000000h
      CERT_TRUST_HAS_WEAK_SIGNATURE equ 00100000h
      CERT_TRUST_HAS_WEAK_HYGIENE equ 00200000h
      CERT_TRUST_IS_PARTIAL_CHAIN equ 00010000h
      CERT_TRUST_CTL_IS_NOT_TIME_VALID equ 00020000h
      CERT_TRUST_CTL_IS_NOT_SIGNATURE_VALID equ 00040000h
      CERT_TRUST_CTL_IS_NOT_VALID_FOR_USAGE equ 00080000h
      CERT_TRUST_HAS_EXACT_MATCH_ISSUER equ 00000001h
      CERT_TRUST_HAS_KEY_MATCH_ISSUER equ 00000002h
      CERT_TRUST_HAS_NAME_MATCH_ISSUER equ 00000004h
      CERT_TRUST_IS_SELF_SIGNED equ 00000008h
      CERT_TRUST_AUTO_UPDATE_CA_REVOCATION equ 00000010h
      CERT_TRUST_AUTO_UPDATE_END_REVOCATION equ 00000020h
      CERT_TRUST_NO_OCSP_FAILOVER_TO_CRL equ 00000040h
      CERT_TRUST_IS_KEY_ROLLOVER equ 00000080h
      CERT_TRUST_SSL_HANDSHAKE_OCSP equ 00040000h
      CERT_TRUST_SSL_TIME_VALID_OCSP equ 00080000h
      CERT_TRUST_SSL_RECONNECT_OCSP equ 00100000h
      CERT_TRUST_HAS_PREFERRED_ISSUER equ 00000100h
      CERT_TRUST_HAS_ISSUANCE_CHAIN_POLICY equ 00000200h
      CERT_TRUST_HAS_VALID_NAME_CONSTRAINTS equ 00000400h
      CERT_TRUST_IS_PEER_TRUSTED equ 00000800h
      CERT_TRUST_HAS_CRL_VALIDITY_EXTENDED equ 00001000h
      CERT_TRUST_IS_FROM_EXCLUSIVE_TRUST_STORE equ 00002000h
      if (NTDDI_VERSION ge NTDDI_WIN8)
        CERT_TRUST_IS_CA_TRUSTED equ 00004000h
        CERT_TRUST_HAS_AUTO_UPDATE_WEAK_SIGNATURE equ 00008000h
        CERT_TRUST_HAS_ALLOW_WEAK_SIGNATURE equ 00020000h
        CERT_TRUST_BEFORE_DISALLOWED_CA_FILETIME equ 00200000h
      endif
      CERT_TRUST_IS_COMPLEX_CHAIN equ 00010000h
      CERT_TRUST_SSL_TIME_VALID equ 01000000h
      CERT_TRUST_NO_TIME_CHECK equ 02000000h
      CERT_REVOCATION_INFO struct
        cbSize DWORD ?
        dwRevocationResult DWORD ?
        pszRevocationOid LPCSTR ?
        pvOidSpecificInfo LPVOID ?
        fHasFreshnessTime BOOL ?
        dwFreshnessTime DWORD ?
        pCrlInfo PCERT_REVOCATION_CRL_INFO ?
      CERT_REVOCATION_INFO ends
      _CERT_REVOCATION_INFO typedef CERT_REVOCATION_INFO
      PCERT_REVOCATION_INFO typedef ptr CERT_REVOCATION_INFO
      CERT_TRUST_LIST_INFO struct
        cbSize DWORD ?
        pCtlEntry PCTL_ENTRY ?
        pCtlContext PCCTL_CONTEXT ?
      CERT_TRUST_LIST_INFO ends
      _CERT_TRUST_LIST_INFO typedef CERT_TRUST_LIST_INFO
      PCERT_TRUST_LIST_INFO typedef ptr CERT_TRUST_LIST_INFO
      CERT_CHAIN_ELEMENT struct
        cbSize DWORD ?
        pCertContext PCCERT_CONTEXT ?
        TrustStatus CERT_TRUST_STATUS <>
        pRevocationInfo PCERT_REVOCATION_INFO ?
        pIssuanceUsage PCERT_ENHKEY_USAGE ?
        pApplicationUsage PCERT_ENHKEY_USAGE ?
        pwszExtendedErrorInfo LPCWSTR ?
      CERT_CHAIN_ELEMENT ends
      _CERT_CHAIN_ELEMENT typedef CERT_CHAIN_ELEMENT
      PCERT_CHAIN_ELEMENT typedef ptr CERT_CHAIN_ELEMENT
      PCCERT_CHAIN_ELEMENT typedef ptr CERT_CHAIN_ELEMENT
      CERT_SIMPLE_CHAIN struct
        cbSize DWORD ?
        TrustStatus CERT_TRUST_STATUS <>
        cElement DWORD ?
        rgpElement POINTER ?
        pTrustListInfo PCERT_TRUST_LIST_INFO ?
        fHasRevocationFreshnessTime BOOL ?
        dwRevocationFreshnessTime DWORD ?
      CERT_SIMPLE_CHAIN ends
      _CERT_SIMPLE_CHAIN typedef CERT_SIMPLE_CHAIN
      PCERT_SIMPLE_CHAIN typedef ptr CERT_SIMPLE_CHAIN
      PCCERT_SIMPLE_CHAIN typedef ptr CERT_SIMPLE_CHAIN
      CERT_CHAIN_CONTEXT typedef _CERT_CHAIN_CONTEXT
      PCERT_CHAIN_CONTEXT typedef ptr _CERT_CHAIN_CONTEXT
      PCCERT_CHAIN_CONTEXT typedef ptr CERT_CHAIN_CONTEXT
      _CERT_CHAIN_CONTEXT struct
        cbSize DWORD ?
        TrustStatus CERT_TRUST_STATUS <>
        cChain DWORD ?
        rgpChain POINTER ?
        cLowerQualityChainContext DWORD ?
        rgpLowerQualityChainContext POINTER ?
        fHasRevocationFreshnessTime BOOL ?
        dwRevocationFreshnessTime DWORD ?
        dwCreateFlags DWORD ?
        ChainId GUID <>
      _CERT_CHAIN_CONTEXT ends
      USAGE_MATCH_TYPE_AND equ 00000000h
      USAGE_MATCH_TYPE_OR equ 00000001h
      CERT_USAGE_MATCH struct
        dwType DWORD ?
        Usage CERT_ENHKEY_USAGE <>
      CERT_USAGE_MATCH ends
      _CERT_USAGE_MATCH typedef CERT_USAGE_MATCH
      PCERT_USAGE_MATCH typedef ptr CERT_USAGE_MATCH
      CTL_USAGE_MATCH struct
        dwType DWORD ?
        Usage CTL_USAGE <>
      CTL_USAGE_MATCH ends
      _CTL_USAGE_MATCH typedef CTL_USAGE_MATCH
      PCTL_USAGE_MATCH typedef ptr CTL_USAGE_MATCH
      CERT_CHAIN_PARA struct
        cbSize DWORD ?
        RequestedUsage CERT_USAGE_MATCH <>
        ifdef CERT_CHAIN_PARA_HAS_EXTRA_FIELDS
          RequestedIssuancePolicy CERT_USAGE_MATCH <>
          dwUrlRetrievalTimeout DWORD ?
          fCheckRevocationFreshnessTime BOOL ?
          dwRevocationFreshnessTime DWORD ?
          pftCacheResync LPFILETIME ?
          pStrongSignPara PCCERT_STRONG_SIGN_PARA ?
          dwStrongSignFlags DWORD ?
        endif
      CERT_CHAIN_PARA ends
      _CERT_CHAIN_PARA typedef CERT_CHAIN_PARA
      PCERT_CHAIN_PARA typedef ptr CERT_CHAIN_PARA
      CERT_CHAIN_STRONG_SIGN_DISABLE_END_CHECK_FLAG equ 00000001h
      CERT_CHAIN_REVOCATION_CHECK_END_CERT equ 10000000h
      CERT_CHAIN_REVOCATION_CHECK_CHAIN equ 20000000h
      CERT_CHAIN_REVOCATION_CHECK_CHAIN_EXCLUDE_ROOT equ 40000000h
      CERT_CHAIN_REVOCATION_CHECK_CACHE_ONLY equ 80000000h
      CERT_CHAIN_REVOCATION_ACCUMULATIVE_TIMEOUT equ 08000000h
      CERT_CHAIN_REVOCATION_CHECK_OCSP_CERT equ 04000000h
      CERT_CHAIN_DISABLE_PASS1_QUALITY_FILTERING equ 00000040h
      CERT_CHAIN_RETURN_LOWER_QUALITY_CONTEXTS equ 00000080h
      CERT_CHAIN_DISABLE_AUTH_ROOT_AUTO_UPDATE equ 00000100h
      CERT_CHAIN_TIMESTAMP_TIME equ 00000200h
      CERT_CHAIN_ENABLE_PEER_TRUST equ 00000400h
      CERT_CHAIN_DISABLE_MY_PEER_TRUST equ 00000800h
      CERT_CHAIN_DISABLE_MD2_MD4 equ 00001000h
      CERT_CHAIN_DISABLE_AIA equ 00002000h
      CERT_CHAIN_HAS_MOTW equ 00004000h
      CERT_CHAIN_ONLY_ADDITIONAL_AND_AUTH_ROOT equ 00008000h
      CERT_CHAIN_OPT_IN_WEAK_SIGNATURE equ 00010000h
      CERT_CHAIN_ENABLE_DISALLOWED_CA equ 00020000h
      @DefProto DllImport, CertGetCertificateChain, WIN_STD_CALL_CONV,, <:HCERTCHAINENGINE, :PCCERT_CONTEXT, :LPFILETIME, :HCERTSTORE, :PCERT_CHAIN_PARA, :DWORD, :LPVOID, :ptr PCCERT_CHAIN_CONTEXT>, 32
      @DefProto DllImport, CertFreeCertificateChain, WIN_STD_CALL_CONV,, <:PCCERT_CHAIN_CONTEXT>, 4
      @DefProto DllImport, CertDuplicateCertificateChain, WIN_STD_CALL_CONV,, <:PCCERT_CHAIN_CONTEXT>, 4
      _CERT_REVOCATION_CHAIN_PARA struct
        cbSize DWORD ?
        hChainEngine HCERTCHAINENGINE ?
        hAdditionalStore HCERTSTORE ?
        dwChainFlags DWORD ?
        dwUrlRetrievalTimeout DWORD ?
        pftCurrentTime LPFILETIME ?
        pftCacheResync LPFILETIME ?
        cbMaxUrlRetrievalByteCount DWORD ?
      _CERT_REVOCATION_CHAIN_PARA ends
      REVOCATION_OID_CRL_REVOCATION equ (1)
      CRL_REVOCATION_INFO struct
        pCrlEntry PCRL_ENTRY ?
        pCrlContext PCCRL_CONTEXT ?
        pCrlIssuerChain PCCERT_CHAIN_CONTEXT ?
      CRL_REVOCATION_INFO ends
      _CRL_REVOCATION_INFO typedef CRL_REVOCATION_INFO
      PCRL_REVOCATION_INFO typedef ptr CRL_REVOCATION_INFO
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_PHONE_RESTRICTED or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      @DefProto DllImport, CertFindChainInStore, WIN_STD_CALL_CONV,, <:HCERTSTORE, :DWORD, :DWORD, :DWORD, :ptr, :PCCERT_CHAIN_CONTEXT>, 24
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      CERT_CHAIN_FIND_BY_ISSUER equ 1
      TYPE_PFN_CERT_CHAIN_FIND_BY_ISSUER_CALLBACK typedef proto WIN_STD_CALL_CONV :PCCERT_CONTEXT, :ptr
      PFN_CERT_CHAIN_FIND_BY_ISSUER_CALLBACK typedef ptr TYPE_PFN_CERT_CHAIN_FIND_BY_ISSUER_CALLBACK

      CERT_CHAIN_FIND_ISSUER_PARA struct
        cbSize DWORD ?
        pszUsageIdentifier LPCSTR ?
        dwKeySpec DWORD ?
        dwAcquirePrivateKeyFlags DWORD ?
        cIssuer DWORD ?
        rgIssuer POINTER ?
        pfnFindCallback PFN_CERT_CHAIN_FIND_BY_ISSUER_CALLBACK ?
        pvFindArg POINTER ?
        ifdef CERT_CHAIN_FIND_BY_ISSUER_PARA_HAS_EXTRA_FIELDS
          pdwIssuerChainIndex POINTER ?
          pdwIssuerElementIndex POINTER ?
        endif
      CERT_CHAIN_FIND_ISSUER_PARA ends
      _CERT_CHAIN_FIND_BY_ISSUER_PARA typedef CERT_CHAIN_FIND_ISSUER_PARA
      PCERT_CHAIN_FIND_ISSUER_PARA typedef ptr CERT_CHAIN_FIND_ISSUER_PARA
      CERT_CHAIN_FIND_BY_ISSUER_PARA typedef CERT_CHAIN_FIND_ISSUER_PARA
      PCERT_CHAIN_FIND_BY_ISSUER_PARA typedef ptr CERT_CHAIN_FIND_ISSUER_PARA
      CERT_CHAIN_FIND_BY_ISSUER_COMPARE_KEY_FLAG equ 0001h
      CERT_CHAIN_FIND_BY_ISSUER_COMPLEX_CHAIN_FLAG equ 0002h
      CERT_CHAIN_FIND_BY_ISSUER_CACHE_ONLY_URL_FLAG equ 0004h
      CERT_CHAIN_FIND_BY_ISSUER_LOCAL_MACHINE_FLAG equ 0008h
      CERT_CHAIN_FIND_BY_ISSUER_NO_KEY_FLAG equ 4000h
      CERT_CHAIN_FIND_BY_ISSUER_CACHE_ONLY_FLAG equ 8000h
      CERT_CHAIN_POLICY_PARA struct
        cbSize DWORD ?
        dwFlags DWORD ?
        pvExtraPolicyPara POINTER ?
      CERT_CHAIN_POLICY_PARA ends
      _CERT_CHAIN_POLICY_PARA typedef CERT_CHAIN_POLICY_PARA
      PCERT_CHAIN_POLICY_PARA typedef ptr CERT_CHAIN_POLICY_PARA
      CERT_CHAIN_POLICY_STATUS struct
        cbSize DWORD ?
        dwError DWORD ?
        lChainIndex LONG ?
        lElementIndex LONG ?
        pvExtraPolicyStatus POINTER ?
      CERT_CHAIN_POLICY_STATUS ends
      _CERT_CHAIN_POLICY_STATUS typedef CERT_CHAIN_POLICY_STATUS
      PCERT_CHAIN_POLICY_STATUS typedef ptr CERT_CHAIN_POLICY_STATUS
      CERT_CHAIN_POLICY_IGNORE_NOT_TIME_VALID_FLAG equ 00000001h
      CERT_CHAIN_POLICY_IGNORE_CTL_NOT_TIME_VALID_FLAG equ 00000002h
      CERT_CHAIN_POLICY_IGNORE_NOT_TIME_NESTED_FLAG equ 00000004h
      CERT_CHAIN_POLICY_IGNORE_INVALID_BASIC_CONSTRAINTS_FLAG equ 00000008h
      CERT_CHAIN_POLICY_IGNORE_ALL_NOT_TIME_VALID_FLAGS equ <(CERT_CHAIN_POLICY_IGNORE_NOT_TIME_VALID_FLAG or CERT_CHAIN_POLICY_IGNORE_CTL_NOT_TIME_VALID_FLAG or CERT_CHAIN_POLICY_IGNORE_NOT_TIME_NESTED_FLAG)>
      CERT_CHAIN_POLICY_ALLOW_UNKNOWN_CA_FLAG equ 00000010h
      CERT_CHAIN_POLICY_IGNORE_WRONG_USAGE_FLAG equ 00000020h
      CERT_CHAIN_POLICY_IGNORE_INVALID_NAME_FLAG equ 00000040h
      CERT_CHAIN_POLICY_IGNORE_INVALID_POLICY_FLAG equ 00000080h
      CERT_CHAIN_POLICY_IGNORE_END_REV_UNKNOWN_FLAG equ 00000100h
      CERT_CHAIN_POLICY_IGNORE_CTL_SIGNER_REV_UNKNOWN_FLAG equ 00000200h
      CERT_CHAIN_POLICY_IGNORE_CA_REV_UNKNOWN_FLAG equ 00000400h
      CERT_CHAIN_POLICY_IGNORE_ROOT_REV_UNKNOWN_FLAG equ 00000800h
      CERT_CHAIN_POLICY_IGNORE_ALL_REV_UNKNOWN_FLAGS equ <(CERT_CHAIN_POLICY_IGNORE_END_REV_UNKNOWN_FLAG or CERT_CHAIN_POLICY_IGNORE_CTL_SIGNER_REV_UNKNOWN_FLAG or CERT_CHAIN_POLICY_IGNORE_CA_REV_UNKNOWN_FLAG or CERT_CHAIN_POLICY_IGNORE_ROOT_REV_UNKNOWN_FLAG)>
      CERT_CHAIN_POLICY_ALLOW_TESTROOT_FLAG equ 00008000h
      CERT_CHAIN_POLICY_TRUST_TESTROOT_FLAG equ 00004000h
      CERT_CHAIN_POLICY_IGNORE_NOT_SUPPORTED_CRITICAL_EXT_FLAG equ 00002000h
      CERT_CHAIN_POLICY_IGNORE_PEER_TRUST_FLAG equ 00001000h
      CERT_CHAIN_POLICY_IGNORE_WEAK_SIGNATURE_FLAG equ 08000000h
      @DefProto DllImport, CertVerifyCertificateChainPolicy, WIN_STD_CALL_CONV,, <:LPCSTR, :PCCERT_CHAIN_CONTEXT, :PCERT_CHAIN_POLICY_PARA, :PCERT_CHAIN_POLICY_STATUS>, 16
      CRYPT_OID_VERIFY_CERTIFICATE_CHAIN_POLICY_FUNC equ <"CertDllVerifyCertificateChainPolicy">
      CERT_CHAIN_POLICY_BASE equ (1)
      CERT_CHAIN_POLICY_AUTHENTICODE equ (2)
      CERT_CHAIN_POLICY_AUTHENTICODE_TS equ (3)
      CERT_CHAIN_POLICY_SSL equ (4)
      CERT_CHAIN_POLICY_BASIC_CONSTRAINTS equ (5)
      CERT_CHAIN_POLICY_NT_AUTH equ (6)
      CERT_CHAIN_POLICY_MICROSOFT_ROOT equ (7)
      CERT_CHAIN_POLICY_EV equ (8)
      CERT_CHAIN_POLICY_SSL_F12 equ (9)
      CERT_CHAIN_POLICY_SSL_HPKP_HEADER equ (10)
      CERT_CHAIN_POLICY_THIRD_PARTY_ROOT equ (11)
      CERT_CHAIN_POLICY_SSL_KEY_PIN equ (12)
      AUTHENTICODE_EXTRA_CERT_CHAIN_POLICY_PARA struct
        cbSize DWORD ?
        dwRegPolicySettings DWORD ?
        pSignerInfo PCMSG_SIGNER_INFO ?
      AUTHENTICODE_EXTRA_CERT_CHAIN_POLICY_PARA ends
      _AUTHENTICODE_EXTRA_CERT_CHAIN_POLICY_PARA typedef AUTHENTICODE_EXTRA_CERT_CHAIN_POLICY_PARA
      PAUTHENTICODE_EXTRA_CERT_CHAIN_POLICY_PARA typedef ptr AUTHENTICODE_EXTRA_CERT_CHAIN_POLICY_PARA
      AUTHENTICODE_EXTRA_CERT_CHAIN_POLICY_STATUS struct
        cbSize DWORD ?
        fCommercial BOOL ?
      AUTHENTICODE_EXTRA_CERT_CHAIN_POLICY_STATUS ends
      _AUTHENTICODE_EXTRA_CERT_CHAIN_POLICY_STATUS typedef AUTHENTICODE_EXTRA_CERT_CHAIN_POLICY_STATUS
      PAUTHENTICODE_EXTRA_CERT_CHAIN_POLICY_STATUS typedef ptr AUTHENTICODE_EXTRA_CERT_CHAIN_POLICY_STATUS
      AUTHENTICODE_TS_EXTRA_CERT_CHAIN_POLICY_PARA struct
        cbSize DWORD ?
        dwRegPolicySettings DWORD ?
        fCommercial BOOL ?
      AUTHENTICODE_TS_EXTRA_CERT_CHAIN_POLICY_PARA ends
      _AUTHENTICODE_TS_EXTRA_CERT_CHAIN_POLICY_PARA typedef AUTHENTICODE_TS_EXTRA_CERT_CHAIN_POLICY_PARA
      PAUTHENTICODE_TS_EXTRA_CERT_CHAIN_POLICY_PARA typedef ptr AUTHENTICODE_TS_EXTRA_CERT_CHAIN_POLICY_PARA
      HTTPSPolicyCallbackData struct
        union
          cbStruct DWORD ?
          cbSize DWORD ?
        ends
        dwAuthType DWORD ?
        AUTHTYPE_CLIENT equ 1
        AUTHTYPE_SERVER equ 2
        fdwChecks DWORD ?
        pwszServerName POINTER ?
      HTTPSPolicyCallbackData ends
      _HTTPSPolicyCallbackData typedef HTTPSPolicyCallbackData
      PHTTPSPolicyCallbackData typedef ptr HTTPSPolicyCallbackData
      SSL_EXTRA_CERT_CHAIN_POLICY_PARA typedef HTTPSPolicyCallbackData
      PSSL_EXTRA_CERT_CHAIN_POLICY_PARA typedef ptr HTTPSPolicyCallbackData
      BASIC_CONSTRAINTS_CERT_CHAIN_POLICY_CA_FLAG equ 80000000h
      BASIC_CONSTRAINTS_CERT_CHAIN_POLICY_END_ENTITY_FLAG equ 40000000h
      MICROSOFT_ROOT_CERT_CHAIN_POLICY_ENABLE_TEST_ROOT_FLAG equ 00010000h
      MICROSOFT_ROOT_CERT_CHAIN_POLICY_CHECK_APPLICATION_ROOT_FLAG equ 00020000h
      MICROSOFT_ROOT_CERT_CHAIN_POLICY_DISABLE_FLIGHT_ROOT_FLAG equ 00040000h
      EV_EXTRA_CERT_CHAIN_POLICY_PARA struct
        cbSize DWORD ?
        dwRootProgramQualifierFlags DWORD ?
      EV_EXTRA_CERT_CHAIN_POLICY_PARA ends
      _EV_EXTRA_CERT_CHAIN_POLICY_PARA typedef EV_EXTRA_CERT_CHAIN_POLICY_PARA
      PEV_EXTRA_CERT_CHAIN_POLICY_PARA typedef ptr EV_EXTRA_CERT_CHAIN_POLICY_PARA
      EV_EXTRA_CERT_CHAIN_POLICY_STATUS struct
        cbSize DWORD ?
        dwQualifiers DWORD ?
        dwIssuanceUsageIndex DWORD ?
      EV_EXTRA_CERT_CHAIN_POLICY_STATUS ends
      _EV_EXTRA_CERT_CHAIN_POLICY_STATUS typedef EV_EXTRA_CERT_CHAIN_POLICY_STATUS
      PEV_EXTRA_CERT_CHAIN_POLICY_STATUS typedef ptr EV_EXTRA_CERT_CHAIN_POLICY_STATUS
      SSL_F12_ERROR_TEXT_LENGTH equ 256
      SSL_F12_EXTRA_CERT_CHAIN_POLICY_STATUS struct
        cbSize DWORD ?
        dwErrorLevel DWORD ?
        dwErrorCategory DWORD ?
        dwReserved DWORD ?
        wszErrorText WCHAR SSL_F12_ERROR_TEXT_LENGTH dup (?)
      SSL_F12_EXTRA_CERT_CHAIN_POLICY_STATUS ends
      _SSL_F12_EXTRA_CERT_CHAIN_POLICY_STATUS typedef SSL_F12_EXTRA_CERT_CHAIN_POLICY_STATUS
      PSSL_F12_EXTRA_CERT_CHAIN_POLICY_STATUS typedef ptr SSL_F12_EXTRA_CERT_CHAIN_POLICY_STATUS
      CERT_CHAIN_POLICY_SSL_F12_SUCCESS_LEVEL equ 0
      CERT_CHAIN_POLICY_SSL_F12_WARNING_LEVEL equ 1
      CERT_CHAIN_POLICY_SSL_F12_ERROR_LEVEL equ 2
      CERT_CHAIN_POLICY_SSL_F12_NONE_CATEGORY equ 0
      CERT_CHAIN_POLICY_SSL_F12_WEAK_CRYPTO_CATEGORY equ 1
      CERT_CHAIN_POLICY_SSL_F12_ROOT_PROGRAM_CATEGORY equ 2
      SSL_HPKP_PKP_HEADER_INDEX equ 0
      SSL_HPKP_PKP_RO_HEADER_INDEX equ 1
      SSL_HPKP_HEADER_COUNT equ 2
      SSL_HPKP_HEADER_EXTRA_CERT_CHAIN_POLICY_PARA struct
        cbSize DWORD ?
        dwReserved DWORD ?
        pwszServerName LPWSTR ?
        rgpszHpkpValue LPSTR SSL_HPKP_HEADER_COUNT dup (?)
      SSL_HPKP_HEADER_EXTRA_CERT_CHAIN_POLICY_PARA ends
      _SSL_HPKP_HEADER_EXTRA_CERT_CHAIN_POLICY_PARA typedef SSL_HPKP_HEADER_EXTRA_CERT_CHAIN_POLICY_PARA
      PSSL_HPKP_HEADER_EXTRA_CERT_CHAIN_POLICY_PARA typedef ptr SSL_HPKP_HEADER_EXTRA_CERT_CHAIN_POLICY_PARA
      SSL_KEY_PIN_EXTRA_CERT_CHAIN_POLICY_PARA struct
        cbSize DWORD ?
        dwReserved DWORD ?
        pwszServerName PCWSTR ?
      SSL_KEY_PIN_EXTRA_CERT_CHAIN_POLICY_PARA ends
      _SSL_KEY_PIN_EXTRA_CERT_CHAIN_POLICY_PARA typedef SSL_KEY_PIN_EXTRA_CERT_CHAIN_POLICY_PARA
      PSSL_KEY_PIN_EXTRA_CERT_CHAIN_POLICY_PARA typedef ptr SSL_KEY_PIN_EXTRA_CERT_CHAIN_POLICY_PARA
      SSL_KEY_PIN_ERROR_TEXT_LENGTH equ 512
      SSL_KEY_PIN_EXTRA_CERT_CHAIN_POLICY_STATUS struct
        cbSize DWORD ?
        lError LONG ?
        wszErrorText WCHAR SSL_KEY_PIN_ERROR_TEXT_LENGTH dup (?)
      SSL_KEY_PIN_EXTRA_CERT_CHAIN_POLICY_STATUS ends
      _SSL_KEY_PIN_EXTRA_CERT_CHAIN_POLICY_STATUS typedef SSL_KEY_PIN_EXTRA_CERT_CHAIN_POLICY_STATUS
      PSSL_KEY_PIN_EXTRA_CERT_CHAIN_POLICY_STATUS typedef ptr SSL_KEY_PIN_EXTRA_CERT_CHAIN_POLICY_STATUS
      CERT_CHAIN_POLICY_SSL_KEY_PIN_MISMATCH_ERROR equ -2
      CERT_CHAIN_POLICY_SSL_KEY_PIN_MITM_ERROR equ -1
      CERT_CHAIN_POLICY_SSL_KEY_PIN_SUCCESS equ 0
      CERT_CHAIN_POLICY_SSL_KEY_PIN_MITM_WARNING equ 1
      CERT_CHAIN_POLICY_SSL_KEY_PIN_MISMATCH_WARNING equ 2
      @DefProto DllImport, CryptStringToBinaryA, WIN_STD_CALL_CONV,, <:LPCSTR, :DWORD, :DWORD, :ptr BYTE, :ptr DWORD, :ptr DWORD, :ptr DWORD>, 28
      @DefProto DllImport, CryptStringToBinaryW, WIN_STD_CALL_CONV,, <:LPCWSTR, :DWORD, :DWORD, :ptr BYTE, :ptr DWORD, :ptr DWORD, :ptr DWORD>, 28
      ifdef UNICODE
        CryptStringToBinary equ <CryptStringToBinaryW>
      else
        CryptStringToBinary equ <CryptStringToBinaryA>
      endif
      @DefProto DllImport, CryptBinaryToStringA, WIN_STD_CALL_CONV,, <:ptr BYTE, :DWORD, :DWORD, :LPSTR, :ptr DWORD>, 20
      @DefProto DllImport, CryptBinaryToStringW, WIN_STD_CALL_CONV,, <:ptr BYTE, :DWORD, :DWORD, :LPWSTR, :ptr DWORD>, 20
      ifdef UNICODE
        CryptBinaryToString equ <CryptBinaryToStringW>
      else
        CryptBinaryToString equ <CryptBinaryToStringA>
      endif
      CRYPT_STRING_BASE64HEADER equ 00000000h
      CRYPT_STRING_BASE64 equ 00000001h
      CRYPT_STRING_BINARY equ 00000002h
      CRYPT_STRING_BASE64REQUESTHEADER equ 00000003h
      CRYPT_STRING_HEX equ 00000004h
      CRYPT_STRING_HEXASCII equ 00000005h
      CRYPT_STRING_BASE64_ANY equ 00000006h
      CRYPT_STRING_ANY equ 00000007h
      CRYPT_STRING_HEX_ANY equ 00000008h
      CRYPT_STRING_BASE64X509CRLHEADER equ 00000009h
      CRYPT_STRING_HEXADDR equ 0000000ah
      CRYPT_STRING_HEXASCIIADDR equ 0000000bh
      CRYPT_STRING_HEXRAW equ 0000000ch
      CRYPT_STRING_BASE64URI equ 0000000dh
      CRYPT_STRING_ENCODEMASK equ 000000ffh
      CRYPT_STRING_RESERVED100 equ 00000100h
      CRYPT_STRING_RESERVED200 equ 00000200h
      CRYPT_STRING_PERCENTESCAPE equ 08000000h
      CRYPT_STRING_HASHDATA equ 10000000h
      CRYPT_STRING_STRICT equ 20000000h
      CRYPT_STRING_NOCRLF equ 40000000h
      CRYPT_STRING_NOCR equ 80000000h
      szOID_PKCS_12_PbeIds equ <"1.2.840.113549.1.12.1">
      szOID_PKCS_12_pbeWithSHA1And128BitRC4 equ <"1.2.840.113549.1.12.1.1">
      szOID_PKCS_12_pbeWithSHA1And40BitRC4 equ <"1.2.840.113549.1.12.1.2">
      szOID_PKCS_12_pbeWithSHA1And3KeyTripleDES equ <"1.2.840.113549.1.12.1.3">
      szOID_PKCS_12_pbeWithSHA1And2KeyTripleDES equ <"1.2.840.113549.1.12.1.4">
      szOID_PKCS_12_pbeWithSHA1And128BitRC2 equ <"1.2.840.113549.1.12.1.5">
      szOID_PKCS_12_pbeWithSHA1And40BitRC2 equ <"1.2.840.113549.1.12.1.6">
      szOID_PKCS_5_PBKDF2 equ <"1.2.840.113549.1.5.12">
      szOID_PKCS_5_PBES2 equ <"1.2.840.113549.1.5.13">
      CRYPT_PKCS12_PBE_PARAMS struct
        iIterations SDWORD ?
        cbSalt ULONG ?
      CRYPT_PKCS12_PBE_PARAMS ends
      _CRYPT_PKCS12_PBE_PARAMS typedef CRYPT_PKCS12_PBE_PARAMS
      @DefProto DllImport, PFXImportCertStore, WIN_STD_CALL_CONV,, <:ptr CRYPT_DATA_BLOB, :LPCWSTR, :DWORD>, 12
      PKCS12_IMPORT_SILENT equ 00000040h
      CRYPT_USER_KEYSET equ 00001000h
      PKCS12_PREFER_CNG_KSP equ 00000100h
      PKCS12_ALWAYS_CNG_KSP equ 00000200h
      PKCS12_ONLY_CERTIFICATES equ 00000400h
      PKCS12_ONLY_NOT_ENCRYPTED_CERTIFICATES equ 00000800h
      PKCS12_ALLOW_OVERWRITE_KEY equ 00004000h
      PKCS12_NO_PERSIST_KEY equ 00008000h
      PKCS12_VIRTUAL_ISOLATION_KEY equ 00010000h
      PKCS12_IMPORT_RESERVED_MASK equ 0ffff0000h
      PKCS12_OBJECT_LOCATOR_ALL_IMPORT_FLAGS equ <(PKCS12_ALWAYS_CNG_KSP or PKCS12_NO_PERSIST_KEY or PKCS12_IMPORT_SILENT or PKCS12_INCLUDE_EXTENDED_PROPERTIES)>
      PKCS12_ONLY_CERTIFICATES_PROVIDER_TYPE equ 0
      PKCS12_ONLY_CERTIFICATES_PROVIDER_NAME equ <L("PfxProvider")>
      PKCS12_ONLY_CERTIFICATES_CONTAINER_NAME equ <L("PfxContainer")>
      @DefProto DllImport, PFXIsPFXBlob, WIN_STD_CALL_CONV,, <:ptr CRYPT_DATA_BLOB>, 4
      @DefProto DllImport, PFXVerifyPassword, WIN_STD_CALL_CONV,, <:ptr CRYPT_DATA_BLOB, :LPCWSTR, :DWORD>, 12
      @DefProto DllImport, PFXExportCertStoreEx, WIN_STD_CALL_CONV,, <:HCERTSTORE, :ptr CRYPT_DATA_BLOB, :LPCWSTR, :ptr, :DWORD>, 20
      REPORT_NO_PRIVATE_KEY equ 0001h
      REPORT_NOT_ABLE_TO_EXPORT_PRIVATE_KEY equ 0002h
      EXPORT_PRIVATE_KEYS equ 0004h
      PKCS12_INCLUDE_EXTENDED_PROPERTIES equ 0010h
      PKCS12_PROTECT_TO_DOMAIN_SIDS equ 0020h
      PKCS12_EXPORT_SILENT equ 0040h
      PKCS12_EXPORT_PBES2_PARAMS equ 0080h
      PKCS12_DISABLE_ENCRYPT_CERTIFICATES equ 0100h
      PKCS12_ENCRYPT_CERTIFICATES equ 0200h
      PKCS12_EXPORT_ECC_CURVE_PARAMETERS equ 1000h
      PKCS12_EXPORT_ECC_CURVE_OID equ 2000h
      PKCS12_EXPORT_RESERVED_MASK equ 0ffff0000h
      PKCS12_PBKDF2_ID_HMAC_SHA1 equ <"1.2.840.113549.2.7">
      PKCS12_PBKDF2_ID_HMAC_SHA256 equ <"1.2.840.113549.2.9">
      PKCS12_PBKDF2_ID_HMAC_SHA384 equ <"1.2.840.113549.2.10">
      PKCS12_PBKDF2_ID_HMAC_SHA512 equ <"1.2.840.113549.2.11">
      PKCS12_PBES2_EXPORT_PARAMS struct
        dwSize DWORD ?
        hNcryptDescriptor PVOID ?
        pwszPbes2Alg LPWSTR ?
      PKCS12_PBES2_EXPORT_PARAMS ends
      _PKCS12_PBES2_EXPORT_PARAMS typedef PKCS12_PBES2_EXPORT_PARAMS
      PPKCS12_PBES2_EXPORT_PARAMS typedef ptr PKCS12_PBES2_EXPORT_PARAMS
      PKCS12_PBES2_ALG_AES256_SHA256 equ <L("AES256-SHA256")>
      PKCS12_CONFIG_REGPATH equ <L("Software\Microsoft\Windows\CurrentVersion\PFX")>
      PKCS12_ENCRYPT_CERTIFICATES_VALUE_NAME equ <L("EncryptCertificates")>
      @DefProto DllImport, PFXExportCertStore, WIN_STD_CALL_CONV,, <:HCERTSTORE, :ptr CRYPT_DATA_BLOB, :LPCWSTR, :DWORD>, 16
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_PHONE_RESTRICTED or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      if (NTDDI_VERSION ge NTDDI_VISTA)
        HCERT_SERVER_OCSP_RESPONSE typedef ptr VOID
        CERT_SERVER_OCSP_RESPONSE_CONTEXT typedef _CERT_SERVER_OCSP_RESPONSE_CONTEXT
        PCERT_SERVER_OCSP_RESPONSE_CONTEXT typedef ptr _CERT_SERVER_OCSP_RESPONSE_CONTEXT
        PCCERT_SERVER_OCSP_RESPONSE_CONTEXT typedef ptr CERT_SERVER_OCSP_RESPONSE_CONTEXT
        _CERT_SERVER_OCSP_RESPONSE_CONTEXT struct
          cbSize DWORD ?
          pbEncodedOcspResponse POINTER ?
          cbEncodedOcspResponse DWORD ?
        _CERT_SERVER_OCSP_RESPONSE_CONTEXT ends
        TYPE_PFN_CERT_SERVER_OCSP_RESPONSE_UPDATE_CALLBACK typedef proto WIN_STD_CALL_CONV :PCCERT_CHAIN_CONTEXT, :PCCERT_SERVER_OCSP_RESPONSE_CONTEXT, :PCCRL_CONTEXT, :PCCRL_CONTEXT, :PVOID, :DWORD
        PFN_CERT_SERVER_OCSP_RESPONSE_UPDATE_CALLBACK typedef ptr TYPE_PFN_CERT_SERVER_OCSP_RESPONSE_UPDATE_CALLBACK

        CERT_SERVER_OCSP_RESPONSE_OPEN_PARA struct
          cbSize DWORD ?
          dwFlags DWORD ?
          pcbUsedSize POINTER ?
          pwszOcspDirectory PWSTR ?
          pfnUpdateCallback PFN_CERT_SERVER_OCSP_RESPONSE_UPDATE_CALLBACK ?
          pvUpdateCallbackArg PVOID ?
        CERT_SERVER_OCSP_RESPONSE_OPEN_PARA ends
        _CERT_SERVER_OCSP_RESPONSE_OPEN_PARA typedef CERT_SERVER_OCSP_RESPONSE_OPEN_PARA
        PCERT_SERVER_OCSP_RESPONSE_OPEN_PARA typedef ptr CERT_SERVER_OCSP_RESPONSE_OPEN_PARA
        CERT_SERVER_OCSP_RESPONSE_OPEN_PARA_READ_FLAG equ 00000001h
        CERT_SERVER_OCSP_RESPONSE_OPEN_PARA_WRITE_FLAG equ 00000002h
        @DefProto DllImport, CertOpenServerOcspResponse, WIN_STD_CALL_CONV,, <:PCCERT_CHAIN_CONTEXT, :DWORD, :PCERT_SERVER_OCSP_RESPONSE_OPEN_PARA>, 12
        CERT_SERVER_OCSP_RESPONSE_ASYNC_FLAG equ 00000001h
        @DefProto DllImport, CertAddRefServerOcspResponse, WIN_STD_CALL_CONV,, <:HCERT_SERVER_OCSP_RESPONSE>, 4
        @DefProto DllImport, CertCloseServerOcspResponse, WIN_STD_CALL_CONV,, <:HCERT_SERVER_OCSP_RESPONSE, :DWORD>, 8
        @DefProto DllImport, CertGetServerOcspResponseContext, WIN_STD_CALL_CONV,, <:HCERT_SERVER_OCSP_RESPONSE, :DWORD, :LPVOID>, 12
        @DefProto DllImport, CertAddRefServerOcspResponseContext, WIN_STD_CALL_CONV,, <:PCCERT_SERVER_OCSP_RESPONSE_CONTEXT>, 4
        @DefProto DllImport, CertFreeServerOcspResponseContext, WIN_STD_CALL_CONV,, <:PCCERT_SERVER_OCSP_RESPONSE_CONTEXT>, 4
      endif
      @DefProto DllImport, CertRetrieveLogoOrBiometricInfo, WIN_STD_CALL_CONV,, <:PCCERT_CONTEXT, :LPCSTR, :DWORD, :DWORD, :DWORD, :ptr, :ptr ptr BYTE, :ptr DWORD, :ptr LPWSTR>, 36
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      CERT_RETRIEVE_ISSUER_LOGO equ (1)
      CERT_RETRIEVE_SUBJECT_LOGO equ (2)
      CERT_RETRIEVE_COMMUNITY_LOGO equ (3)
      CERT_RETRIEVE_BIOMETRIC_PREDEFINED_BASE_TYPE equ (1000)
      CERT_RETRIEVE_BIOMETRIC_PICTURE_TYPE equ <(CERT_RETRIEVE_BIOMETRIC_PREDEFINED_BASE_TYPE + CERT_BIOMETRIC_PICTURE_TYPE)>
      CERT_RETRIEVE_BIOMETRIC_SIGNATURE_TYPE equ <(CERT_RETRIEVE_BIOMETRIC_PREDEFINED_BASE_TYPE + CERT_BIOMETRIC_SIGNATURE_TYPE)>
      if (NTDDI_VERSION ge NTDDI_WIN7)
        CERT_SELECT_CHAIN_PARA struct
          hChainEngine HCERTCHAINENGINE ?
          pTime PFILETIME ?
          hAdditionalStore HCERTSTORE ?
          pChainPara PCERT_CHAIN_PARA ?
          dwFlags DWORD ?
        CERT_SELECT_CHAIN_PARA ends
        _CERT_SELECT_CHAIN_PARA typedef CERT_SELECT_CHAIN_PARA
        PCERT_SELECT_CHAIN_PARA typedef ptr CERT_SELECT_CHAIN_PARA
        PCCERT_SELECT_CHAIN_PARA typedef ptr CERT_SELECT_CHAIN_PARA
        CERT_SELECT_MAX_PARA equ 500
        CERT_SELECT_CRITERIA struct
          dwType DWORD ?
          cPara DWORD ?
          ppPara POINTER ?
        CERT_SELECT_CRITERIA ends
        _CERT_SELECT_CRITERIA typedef CERT_SELECT_CRITERIA
        PCERT_SELECT_CRITERIA typedef ptr CERT_SELECT_CRITERIA
        PCCERT_SELECT_CRITERIA typedef ptr CERT_SELECT_CRITERIA
        CERT_SELECT_BY_ENHKEY_USAGE equ 1
        CERT_SELECT_BY_KEY_USAGE equ 2
        CERT_SELECT_BY_POLICY_OID equ 3
        CERT_SELECT_BY_PROV_NAME equ 4
        CERT_SELECT_BY_EXTENSION equ 5
        CERT_SELECT_BY_SUBJECT_HOST_NAME equ 6
        CERT_SELECT_BY_ISSUER_ATTR equ 7
        CERT_SELECT_BY_SUBJECT_ATTR equ 8
        CERT_SELECT_BY_ISSUER_NAME equ 9
        CERT_SELECT_BY_PUBLIC_KEY equ 10
        CERT_SELECT_BY_TLS_SIGNATURES equ 11
        CERT_SELECT_BY_ISSUER_DISPLAYNAME equ 12
        CERT_SELECT_BY_FRIENDLYNAME equ 13
        CERT_SELECT_BY_THUMBPRINT equ 14
        CERT_SELECT_LAST equ <CERT_SELECT_BY_TLS_SIGNATURES>
        CERT_SELECT_MAX equ (CERT_SELECT_LAST * 3)
        CERT_SELECT_ALLOW_EXPIRED equ 00000001h
        CERT_SELECT_TRUSTED_ROOT equ 00000002h
        CERT_SELECT_DISALLOW_SELFSIGNED equ 00000004h
        CERT_SELECT_HAS_PRIVATE_KEY equ 00000008h
        CERT_SELECT_HAS_KEY_FOR_SIGNATURE equ 00000010h
        CERT_SELECT_HAS_KEY_FOR_KEY_EXCHANGE equ 00000020h
        CERT_SELECT_HARDWARE_ONLY equ 00000040h
        CERT_SELECT_ALLOW_DUPLICATES equ 00000080h
        CERT_SELECT_IGNORE_AUTOSELECT equ 00000100h
        @DefProto DllImport, CertSelectCertificateChains, WIN_STD_CALL_CONV,, <:LPCGUID, :DWORD, :PCCERT_SELECT_CHAIN_PARA, :DWORD, :PCCERT_SELECT_CRITERIA, :HCERTSTORE, :PDWORD, :ptr ptr PCCERT_CHAIN_CONTEXT>, 32
        @DefProto DllImport, CertFreeCertificateChainList, WIN_STD_CALL_CONV,, <:ptr PCCERT_CHAIN_CONTEXT>, 4
      endif
      if (NTDDI_VERSION ge NTDDI_WIN7)
        TIMESTAMP_VERSION equ 1
        CRYPT_TIMESTAMP_REQUEST struct
          dwVersion DWORD ?
          HashAlgorithm CRYPT_ALGORITHM_IDENTIFIER <>
          HashedMessage CRYPT_DER_BLOB <>
          pszTSAPolicyId LPSTR ?
          Nonce CRYPT_INTEGER_BLOB <>
          fCertReq BOOL ?
          cExtension DWORD ?
          rgExtension PCERT_EXTENSION ?
        CRYPT_TIMESTAMP_REQUEST ends
        _CRYPT_TIMESTAMP_REQUEST typedef CRYPT_TIMESTAMP_REQUEST
        PCRYPT_TIMESTAMP_REQUEST typedef ptr CRYPT_TIMESTAMP_REQUEST
        CRYPT_TIMESTAMP_RESPONSE struct
          dwStatus DWORD ?
          cFreeText DWORD ?
          rgFreeText POINTER ?
          FailureInfo CRYPT_BIT_BLOB <>
          ContentInfo CRYPT_DER_BLOB <>
        CRYPT_TIMESTAMP_RESPONSE ends
        _CRYPT_TIMESTAMP_RESPONSE typedef CRYPT_TIMESTAMP_RESPONSE
        PCRYPT_TIMESTAMP_RESPONSE typedef ptr CRYPT_TIMESTAMP_RESPONSE
        TIMESTAMP_STATUS_GRANTED equ 0
        TIMESTAMP_STATUS_GRANTED_WITH_MODS equ 1
        TIMESTAMP_STATUS_REJECTED equ 2
        TIMESTAMP_STATUS_WAITING equ 3
        TIMESTAMP_STATUS_REVOCATION_WARNING equ 4
        TIMESTAMP_STATUS_REVOKED equ 5
        TIMESTAMP_FAILURE_BAD_ALG equ 0
        TIMESTAMP_FAILURE_BAD_REQUEST equ 2
        TIMESTAMP_FAILURE_BAD_FORMAT equ 5
        TIMESTAMP_FAILURE_TIME_NOT_AVAILABLE equ 14
        TIMESTAMP_FAILURE_POLICY_NOT_SUPPORTED equ 15
        TIMESTAMP_FAILURE_EXTENSION_NOT_SUPPORTED equ 16
        TIMESTAMP_FAILURE_INFO_NOT_AVAILABLE equ 17
        TIMESTAMP_FAILURE_SYSTEM_FAILURE equ 25
        CRYPT_TIMESTAMP_ACCURACY struct
          dwSeconds DWORD ?
          dwMillis DWORD ?
          dwMicros DWORD ?
        CRYPT_TIMESTAMP_ACCURACY ends
        _CRYPT_TIMESTAMP_ACCURACY typedef CRYPT_TIMESTAMP_ACCURACY
        PCRYPT_TIMESTAMP_ACCURACY typedef ptr CRYPT_TIMESTAMP_ACCURACY
        CRYPT_TIMESTAMP_INFO struct
          dwVersion DWORD ?
          pszTSAPolicyId LPSTR ?
          HashAlgorithm CRYPT_ALGORITHM_IDENTIFIER <>
          HashedMessage CRYPT_DER_BLOB <>
          SerialNumber CRYPT_INTEGER_BLOB <>
          ftTime FILETIME <>
          pvAccuracy PCRYPT_TIMESTAMP_ACCURACY ?
          fOrdering BOOL ?
          Nonce CRYPT_DER_BLOB <>
          Tsa CRYPT_DER_BLOB <>
          cExtension DWORD ?
          rgExtension PCERT_EXTENSION ?
        CRYPT_TIMESTAMP_INFO ends
        _CRYPT_TIMESTAMP_INFO typedef CRYPT_TIMESTAMP_INFO
        PCRYPT_TIMESTAMP_INFO typedef ptr CRYPT_TIMESTAMP_INFO
        CRYPT_TIMESTAMP_CONTEXT struct
          cbEncoded DWORD ?
          pbEncoded POINTER ?
          pTimeStamp PCRYPT_TIMESTAMP_INFO ?
        CRYPT_TIMESTAMP_CONTEXT ends
        _CRYPT_TIMESTAMP_CONTEXT typedef CRYPT_TIMESTAMP_CONTEXT
        PCRYPT_TIMESTAMP_CONTEXT typedef ptr CRYPT_TIMESTAMP_CONTEXT
        CRYPT_TIMESTAMP_PARA struct
          pszTSAPolicyId LPCSTR ?
          fRequestCerts BOOL ?
          Nonce CRYPT_INTEGER_BLOB <>
          cExtension DWORD ?
          rgExtension PCERT_EXTENSION ?
        CRYPT_TIMESTAMP_PARA ends
        _CRYPT_TIMESTAMP_PARA typedef CRYPT_TIMESTAMP_PARA
        PCRYPT_TIMESTAMP_PARA typedef ptr CRYPT_TIMESTAMP_PARA
        CryptRetrieveTimeStamp proto WIN_STD_CALL_CONV :LPCWSTR, :DWORD, :DWORD, :LPCSTR, :ptr CRYPT_TIMESTAMP_PARA, :ptr BYTE, :DWORD, :ptr PCRYPT_TIMESTAMP_CONTEXT, :ptr PCCERT_CONTEXT, :ptr HCERTSTORE
        TIMESTAMP_DONT_HASH_DATA equ 00000001h
        TIMESTAMP_VERIFY_CONTEXT_SIGNATURE equ 00000020h
        TIMESTAMP_NO_AUTH_RETRIEVAL equ 00020000h
        CryptVerifyTimeStampSignature proto WIN_STD_CALL_CONV :ptr BYTE, :DWORD, :ptr BYTE, :DWORD, :HCERTSTORE, :ptr PCRYPT_TIMESTAMP_CONTEXT, :ptr PCCERT_CONTEXT, :ptr HCERTSTORE
      endif
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_PHONE_RESTRICTED or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      if (NTDDI_VERSION ge NTDDI_WIN8)
        CRYPT_OBJECT_LOCATOR_SPN_NAME_TYPE equ 1
        CRYPT_OBJECT_LOCATOR_LAST_RESERVED_NAME_TYPE equ 32
        CRYPT_OBJECT_LOCATOR_FIRST_RESERVED_USER_NAME_TYPE equ 33
        CRYPT_OBJECT_LOCATOR_LAST_RESERVED_USER_NAME_TYPE equ 0000FFFFh
        SSL_OBJECT_LOCATOR_PFX_FUNC equ <"SslObjectLocatorInitializePfx">
        SSL_OBJECT_LOCATOR_ISSUER_LIST_FUNC equ <"SslObjectLocatorInitializeIssuerList">
        SSL_OBJECT_LOCATOR_CERT_VALIDATION_CONFIG_FUNC equ <"SslObjectLocatorInitializeCertValidationConfig">
        CRYPT_OBJECT_LOCATOR_RELEASE_SYSTEM_SHUTDOWN equ 1
        CRYPT_OBJECT_LOCATOR_RELEASE_SERVICE_STOP equ 2
        CRYPT_OBJECT_LOCATOR_RELEASE_PROCESS_EXIT equ 3
        CRYPT_OBJECT_LOCATOR_RELEASE_DLL_UNLOAD equ 4
        TYPE_PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_FLUSH typedef proto WIN_STD_CALL_CONV :LPVOID, :ptr PCERT_NAME_BLOB, :DWORD
        PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_FLUSH typedef ptr TYPE_PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_FLUSH

        TYPE_PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_GET typedef proto WIN_STD_CALL_CONV :LPVOID, :PCRYPT_DATA_BLOB, :DWORD, :PCERT_NAME_BLOB, :ptr PBYTE, :ptr DWORD, :ptr PCWSTR, :ptr PCRYPT_DATA_BLOB
        PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_GET typedef ptr TYPE_PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_GET

        TYPE_PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_RELEASE typedef proto WIN_STD_CALL_CONV :DWORD, :LPVOID
        PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_RELEASE typedef ptr TYPE_PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_RELEASE

        TYPE_PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_FREE_PASSWORD typedef proto WIN_STD_CALL_CONV :LPVOID, :PCWSTR
        PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_FREE_PASSWORD typedef ptr TYPE_PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_FREE_PASSWORD

        TYPE_PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_FREE typedef proto WIN_STD_CALL_CONV :LPVOID, :PBYTE
        PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_FREE typedef ptr TYPE_PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_FREE

        TYPE_PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_FREE_IDENTIFIER typedef proto WIN_STD_CALL_CONV :LPVOID, :PCRYPT_DATA_BLOB
        PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_FREE_IDENTIFIER typedef ptr TYPE_PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_FREE_IDENTIFIER

        CRYPT_OBJECT_LOCATOR_PROVIDER_TABLE struct
          cbSize DWORD ?
          pfnGet PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_GET ?
          pfnRelease PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_RELEASE ?
          pfnFreePassword PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_FREE_PASSWORD ?
          pfnFree PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_FREE ?
          pfnFreeIdentifier PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_FREE_IDENTIFIER ?
        CRYPT_OBJECT_LOCATOR_PROVIDER_TABLE ends
        _CRYPT_OBJECT_LOCATOR_PROVIDER_TABLE typedef CRYPT_OBJECT_LOCATOR_PROVIDER_TABLE
        PCRYPT_OBJECT_LOCATOR_PROVIDER_TABLE typedef ptr CRYPT_OBJECT_LOCATOR_PROVIDER_TABLE
        TYPE_PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_INITIALIZE typedef proto WIN_STD_CALL_CONV :PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_FLUSH, :LPVOID, :ptr DWORD, :ptr PCRYPT_OBJECT_LOCATOR_PROVIDER_TABLE, :ptr ptr
        PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_INITIALIZE typedef ptr TYPE_PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_INITIALIZE

        @DefProto DllImport, CertIsWeakHash, WIN_STD_CALL_CONV,, <:DWORD, :LPCWSTR, :DWORD, :PCCERT_CHAIN_CONTEXT, :LPFILETIME, :LPCWSTR>, 24
        TYPE_PFN_CERT_IS_WEAK_HASH typedef proto WIN_STD_CALL_CONV :DWORD, :LPCWSTR, :DWORD, :PCCERT_CHAIN_CONTEXT, :LPFILETIME, :LPCWSTR
        PFN_CERT_IS_WEAK_HASH typedef ptr TYPE_PFN_CERT_IS_WEAK_HASH

        CERT_FILE_HASH_USE_TYPE equ 1
        CERT_TIMESTAMP_HASH_USE_TYPE equ 2
      endif
    endif
  endif
  ifdef __cplusplus
    ;[...]
  endif
  if Defined(_MSC_VER)
    if (_MSC_VER ge 800)
      if _MSC_VER ge 1200
      else
      endif
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    ifndef _WINCRYPT_NO_DPAPI
      include dpapi.inc
    endif
  endif
endif
