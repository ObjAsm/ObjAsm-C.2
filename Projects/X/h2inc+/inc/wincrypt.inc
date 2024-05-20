;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\wincrypt.h
;             Created on (UTC) 06/04/2024 06:16:02
;             Last modified on (UTC) 21/02/2024 18:13:14

;----------------------------------------------------------------------------
ifndef __WINCRYPT_H__
  __WINCRYPT_H__ equ <>
  ;* for SAL annotations *
  include specstrings.inc
  if Defined(_MSC_VER)
    if (_MSC_VER ge 800)
      if _MSC_VER ge 1200
        ;* #if not_defined treated as #if 0 *
        ;* padding added after data member *
      endif
      ;* Nameless struct/union *
    endif
    if (_MSC_VER gt 1020)
    endif
  endif
  include winapifamily.inc
  ifdef __cplusplus
    ;[...]
  endif
  ;*
  ;* The relationship between partitions and families (from: winapifamily.h) 
  ;*
  ;* The mapping between families and partitions is summarized here.
  ;* An X indicates that the given partition is active for the given
  ;* platform/family.
  ;*
  ;*                             +-------------------+
  ;*                             |      *Partition*  |
  ;*                             +---+---+---+---+---+
  ;*                             |   |   |   | P |   |
  ;*                             |   |   |   | H |   |
  ;*                             | D |   |   | O | O |
  ;*                             | E |   | P | N | N |
  ;*                             | S |   | C | E | E |
  ;*                             | K |   | _ | _ | C |
  ;*                             | T | A | A | A | O |
  ;* +-------------------------+-+ O | P | P | P | R |
  ;* |     *Platform/Family*    \| P | P | P | P | E |
  ;* +---------------------------+---+---+---+---+---+
  ;* | WINAPI_FAMILY_DESKTOP_APP | X | X | X |   |   |
  ;* +---------------------------+---+---+---+---+---+
  ;* |      WINAPI_FAMILY_PC_APP |   | X | X |   |   |
  ;* +---------------------------+---+---+---+---+---+
  ;* |   WINAPI_FAMILY_PHONE_APP |   | X |   | X |   |
  ;* +---------------------------+---+---+---+---+---+
  ;* | WINAPI_FAMILY_ONECORE_APP |   |   |   |   | X |
  ;* +---------------------------+---+---+---+---+---+
  ;*
  ;* The table above is encoded in the following expressions,
  ;* each of which evaluates to 1 or 0.
  ;*
  ;* Whenever a new family is added, all of these expressions
  ;* need to be reconsidered.
  ;*
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
    ;(NTDDI_VERSION >= NTDDI_VISTA)
    if  not Defined(WINCRYPT32STRINGAPI)
      if  not Defined(_CRYPT32STRING_)
        WINCRYPT32STRINGAPI equ <WINCRYPT32API>
      else
        WINCRYPT32STRINGAPI equ <>
      endif
    endif
    ; Algorithm IDs and Flags
    ; ALG_ID crackers
    GET_ALG_CLASS macro x
      exitm <(x and (7 shl 13))>
    endm
    GET_ALG_TYPE macro x
      exitm <(x and (15 shl 9))>
    endm
    GET_ALG_SID macro x
      exitm <(x and (511))>
    endm
    ; Algorithm classes
    ; certenrolld_begin -- ALG_CLASS_*
    ALG_CLASS_ANY equ (0)
    ALG_CLASS_SIGNATURE equ (1 shl 13)
    ALG_CLASS_MSG_ENCRYPT equ (2 shl 13)
    ALG_CLASS_DATA_ENCRYPT equ (3 shl 13)
    ALG_CLASS_HASH equ (4 shl 13)
    ALG_CLASS_KEY_EXCHANGE equ (5 shl 13)
    ALG_CLASS_ALL equ (7 shl 13)
    ; certenrolld_end
    ; Algorithm types
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
    ;(NTDDI_VERSION >= NTDDI_VISTA)
    if (NTDDI_VERSION ge NTDDI_WIN10_RS1)
      ALG_TYPE_THIRDPARTY equ (8 shl 9)
    endif
    ;(NTDDI_VERSION >= NTDDI_WIN10_RS1)
    ; Generic sub-ids
    ALG_SID_ANY equ (0)
    ; Generic ThirdParty sub-ids
    if (NTDDI_VERSION ge NTDDI_WIN10_RS1)
      ALG_SID_THIRDPARTY_ANY equ (0)
    endif
    ;(NTDDI_VERSION >= NTDDI_WIN10_RS1)
    ; Some RSA sub-ids
    ALG_SID_RSA_ANY equ 0
    ALG_SID_RSA_PKCS equ 1
    ALG_SID_RSA_MSATWORK equ 2
    ALG_SID_RSA_ENTRUST equ 3
    ALG_SID_RSA_PGP equ 4
    ; Some DSS sub-ids
    ALG_SID_DSS_ANY equ 0
    ALG_SID_DSS_PKCS equ 1
    ALG_SID_DSS_DMS equ 2
    if (NTDDI_VERSION ge NTDDI_VISTA)
      ALG_SID_ECDSA equ 3
    endif
    ;(NTDDI_VERSION >= NTDDI_VISTA)
    ; Block cipher sub ids
    ; DES sub_ids
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
    ;(NTDDI_VERSION >= NTDDI_WINXP)
    ; Fortezza sub-ids
    ALG_SID_SKIPJACK equ 10
    ALG_SID_TEK equ 11
    ; KP_MODE
    CRYPT_MODE_CBCI equ 6; ANSI CBC Interleaved

    CRYPT_MODE_CFBP equ 7; ANSI CFB Pipelined

    CRYPT_MODE_OFBP equ 8; ANSI OFB Pipelined

    CRYPT_MODE_CBCOFM equ 9; ANSI CBC + OF Masking

    CRYPT_MODE_CBCOFMI equ 10; ANSI CBC + OFM Interleaved

    ; RC2 sub-ids
    ALG_SID_RC2 equ 2
    ; Stream cipher sub-ids
    ALG_SID_RC4 equ 1
    ALG_SID_SEAL equ 2
    ; Diffie-Hellman sub-ids
    ALG_SID_DH_SANDF equ 1
    ALG_SID_DH_EPHEM equ 2
    ALG_SID_AGREED_KEY_ANY equ 3
    ALG_SID_KEA equ 4
    if (NTDDI_VERSION ge NTDDI_VISTA)
      ALG_SID_ECDH equ 5
      ALG_SID_ECDH_EPHEM equ 6
    endif
    ;(NTDDI_VERSION >= NTDDI_VISTA)
    ; Hash sub ids
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
    ;(NTDDI_VERSION >= NTDDI_WINXP)
    if (NTDDI_VERSION gt NTDDI_WINXPSP2)
      ALG_SID_SHA_256 equ 12
      ALG_SID_SHA_384 equ 13
      ALG_SID_SHA_512 equ 14
    endif
    ;(NTDDI_VERSION > NTDDI_WINXPSP2)
    ; secure channel sub ids
    ALG_SID_SSL3_MASTER equ 1
    ALG_SID_SCHANNEL_MASTER_HASH equ 2
    ALG_SID_SCHANNEL_MAC_KEY equ 3
    ALG_SID_PCT1_MASTER equ 4
    ALG_SID_SSL2_MASTER equ 5
    ALG_SID_TLS1_MASTER equ 6
    ALG_SID_SCHANNEL_ENC_KEY equ 7
    if (NTDDI_VERSION ge NTDDI_VISTA)
      ; misc ECC sub ids
      ALG_SID_ECMQV equ 1
    endif
    ;(NTDDI_VERSION >= NTDDI_VISTA)
    ; Our silly example sub-id
    ALG_SID_EXAMPLE equ 80
    ; certenrolls_begin -- PROV_ENUMALGS_EX
    ifndef ALGIDDEF
      ALGIDDEF equ <>
      ALG_ID typedef DWORD
    endif
    ; certenrolls_end
    ; algorithm identifier definitions
    CALG_MD2 equ <(ALG_CLASS_HASH or ALG_TYPE_ANY or ALG_SID_MD2)>
    CALG_MD4 equ <(ALG_CLASS_HASH or ALG_TYPE_ANY or ALG_SID_MD4)>
    CALG_MD5 equ <(ALG_CLASS_HASH or ALG_TYPE_ANY or ALG_SID_MD5)>
    CALG_SHA equ <(ALG_CLASS_HASH or ALG_TYPE_ANY or ALG_SID_SHA)>
    CALG_SHA1 equ <(ALG_CLASS_HASH or ALG_TYPE_ANY or ALG_SID_SHA1)>
    CALG_MAC equ <(ALG_CLASS_HASH or ALG_TYPE_ANY or ALG_SID_MAC)>; Deprecated. Don't use.

    CALG_RSA_SIGN equ <(ALG_CLASS_SIGNATURE or ALG_TYPE_RSA or ALG_SID_RSA_ANY)>
    CALG_DSS_SIGN equ <(ALG_CLASS_SIGNATURE or ALG_TYPE_DSS or ALG_SID_DSS_ANY)>
    if (NTDDI_VERSION ge NTDDI_WINXP)
      CALG_NO_SIGN equ <(ALG_CLASS_SIGNATURE or ALG_TYPE_ANY or ALG_SID_ANY)>
    endif
    ;(NTDDI_VERSION >= NTDDI_WINXP)
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
    CALG_CYLINK_MEK equ <(ALG_CLASS_DATA_ENCRYPT or ALG_TYPE_BLOCK or ALG_SID_CYLINK_MEK)>; Deprecated. Do not use

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
    ;(NTDDI_VERSION >= NTDDI_WINXP)
    if (NTDDI_VERSION gt NTDDI_WINXPSP2)
      CALG_SHA_256 equ <(ALG_CLASS_HASH or ALG_TYPE_ANY or ALG_SID_SHA_256)>
      CALG_SHA_384 equ <(ALG_CLASS_HASH or ALG_TYPE_ANY or ALG_SID_SHA_384)>
      CALG_SHA_512 equ <(ALG_CLASS_HASH or ALG_TYPE_ANY or ALG_SID_SHA_512)>
    endif
    ;(NTDDI_VERSION > NTDDI_WINXPSP2)
    if (NTDDI_VERSION ge NTDDI_VISTA)
      CALG_ECDH equ <(ALG_CLASS_KEY_EXCHANGE or ALG_TYPE_DH or ALG_SID_ECDH)>
      CALG_ECDH_EPHEM equ <(ALG_CLASS_KEY_EXCHANGE or ALG_TYPE_ECDH or ALG_SID_ECDH_EPHEM)>
      CALG_ECMQV equ <(ALG_CLASS_KEY_EXCHANGE or ALG_TYPE_ANY or ALG_SID_ECMQV)>
      CALG_ECDSA equ <(ALG_CLASS_SIGNATURE or ALG_TYPE_DSS or ALG_SID_ECDSA)>
      CALG_NULLCIPHER equ (ALG_CLASS_DATA_ENCRYPT or ALG_TYPE_ANY or 0)
    endif
    ;(NTDDI_VERSION >= NTDDI_VISTA)
    if (NTDDI_VERSION ge NTDDI_WIN10_RS1)
      CALG_THIRDPARTY_KEY_EXCHANGE equ <(ALG_CLASS_KEY_EXCHANGE or ALG_TYPE_THIRDPARTY or ALG_SID_THIRDPARTY_ANY)>
      CALG_THIRDPARTY_SIGNATURE equ <(ALG_CLASS_SIGNATURE or ALG_TYPE_THIRDPARTY or ALG_SID_THIRDPARTY_ANY)>
      CALG_THIRDPARTY_CIPHER equ <(ALG_CLASS_DATA_ENCRYPT or ALG_TYPE_THIRDPARTY or ALG_SID_THIRDPARTY_ANY)>
      CALG_THIRDPARTY_HASH equ <(ALG_CLASS_HASH or ALG_TYPE_THIRDPARTY or ALG_SID_THIRDPARTY_ANY)>
    endif
    ;(NTDDI_VERSION >= NTDDI_WIN10_RS1)
    if (NTDDI_VERSION lt NTDDI_WINXP)
      ; resource number for signatures in the CSP
      SIGNATURE_RESOURCE_NUMBER equ 29Ah
      VTableProvStruc struct
        Version DWORD ?
        FuncVerifyImage FARPROC ?
        FuncReturnhWnd FARPROC ?
        dwProvType DWORD ?
        pbContextInfo POINTER ?
        cbContextInfo DWORD ?
        pszProvName POINTER ?
      VTableProvStruc ends
      _VTableProvStruc typedef VTableProvStruc
      PVTableProvStruc typedef ptr VTableProvStruc
    endif
    ;(NTDDI_VERSION < NTDDI_WINXP)
    ; Used for certenroll.idl:
    ; certenrolls_begin -- HCRYPT*
    ifndef HCRYPTPROV_DEFINED
      HCRYPTPROV_DEFINED equ <>
      HCRYPTPROV typedef ULONG_PTR
      HCRYPTKEY typedef ULONG_PTR
      HCRYPTHASH typedef ULONG_PTR
    endif
    ; certenrolls_end
    ; dwFlags definitions for CryptAcquireContext
    CRYPT_VERIFYCONTEXT equ 0F0000000h
    CRYPT_NEWKEYSET equ 00000008h
    CRYPT_DELETEKEYSET equ 00000010h
    CRYPT_MACHINE_KEYSET equ 00000020h
    CRYPT_SILENT equ 00000040h
    if (NTDDI_VERSION ge NTDDI_VISTA)
      CRYPT_DEFAULT_CONTAINER_OPTIONAL equ 00000080h
    endif
    ;(NTDDI_VERSION >= NTDDI_VISTA)
    ; dwFlag definitions for CryptGenKey
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
    ;PKCS12_ALLOW_OVERWRITE_KEY 0x00004000
    ;PKCS12_NO_PERSIST_KEY 0x00008000
    ;should use other than these two
    CRYPT_USER_PROTECTED_STRONG equ 00100000h
    if (NTDDI_VERSION ge NTDDI_WINXP)
      CRYPT_ARCHIVABLE equ 00004000h
    endif
    ;(NTDDI_VERSION >= NTDDI_WINXP)
    if (NTDDI_VERSION ge NTDDI_VISTA)
      CRYPT_FORCE_KEY_PROTECTION_HIGH equ 00008000h
    endif
    ;(NTDDI_VERSION >= NTDDI_VISTA)
    RSA1024BIT_KEY equ 04000000h
    ; dwFlags definitions for CryptDeriveKey
    CRYPT_SERVER equ 00000400h
    KEY_LENGTH_MASK equ 0FFFF0000h
    ; dwFlag definitions for CryptExportKey
    CRYPT_Y_ONLY equ 00000001h
    CRYPT_SSL2_FALLBACK equ 00000002h
    CRYPT_DESTROYKEY equ 00000004h
    CRYPT_OAEP equ 00000040h; used with RSA encryptions/decryptions

    ; CryptExportKey, CryptImportKey,
    ; CryptEncrypt and CryptDecrypt
    CRYPT_BLOB_VER3 equ 00000080h; export version 3 of a blob type

    if (NTDDI_VERSION ge NTDDI_WINXP)
      CRYPT_IPSEC_HMAC_KEY equ 00000100h; CryptImportKey only

    endif
    ;(NTDDI_VERSION >= NTDDI_WINXP)
    if (NTDDI_VERSION ge NTDDI_WS03)
      ; dwFlags definitions for CryptDecrypt
      ;  See also CRYPT_OAEP, above.
      ;  Note, the following flag is not supported for CryptEncrypt
      CRYPT_DECRYPT_RSA_NO_PADDING_CHECK equ 00000020h
    endif
    ;(NTDDI_VERSION >= NTDDI_WS03)
    ; dwFlags definitions for CryptCreateHash
    CRYPT_SECRETDIGEST equ 00000001h
    if (NTDDI_VERSION ge NTDDI_WINXP)
      ; dwFlags definitions for CryptHashData
      CRYPT_OWF_REPL_LM_HASH equ 00000001h; this is only for the OWF replacement CSP

    endif
    ;(NTDDI_VERSION >= NTDDI_WINXP)
    ; dwFlags definitions for CryptHashSessionKey
    CRYPT_LITTLE_ENDIAN equ 00000001h
    ; dwFlags definitions for CryptSignHash and CryptVerifySignature
    CRYPT_NOHASHOID equ 00000001h
    CRYPT_TYPE2_FORMAT equ 00000002h; Not supported

    CRYPT_X931_FORMAT equ 00000004h; Not supported

    ; dwFlag definitions for CryptSetProviderEx and CryptGetDefaultProvider
    CRYPT_MACHINE_DEFAULT equ 00000001h
    CRYPT_USER_DEFAULT equ 00000002h
    CRYPT_DELETE_DEFAULT equ 00000004h
    ; exported key blob definitions
    ; certenrolld_begin -- *BLOB
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
    ;(NTDDI_VERSION >= NTDDI_WS03)
    ; certenrolld_end
    ; certenrolld_begin -- AT_*
    AT_KEYEXCHANGE equ 1
    AT_SIGNATURE equ 2
    ; certenrolld_end
    CRYPT_USERDATA equ 1
    ; dwParam
    KP_IV equ 1; Initialization vector

    KP_SALT equ 2; Salt value

    KP_PADDING equ 3; Padding values

    KP_MODE equ 4; Mode of the cipher

    KP_MODE_BITS equ 5; Number of bits to feedback

    KP_PERMISSIONS equ 6; Key permissions DWORD

    KP_ALGID equ 7; Key algorithm

    KP_BLOCKLEN equ 8; Block size of the cipher

    KP_KEYLEN equ 9; Length of key in bits

    KP_SALT_EX equ 10; Length of salt in bytes

    KP_P equ 11; DSS/Diffie-Hellman P value

    KP_G equ 12; DSS/Diffie-Hellman G value

    KP_Q equ 13; DSS Q value

    KP_X equ 14; Diffie-Hellman X value

    KP_Y equ 15; Y value

    KP_RA equ 16; Fortezza RA value

    KP_RB equ 17; Fortezza RB value

    KP_INFO equ 18; for putting information into an RSA envelope

    KP_EFFECTIVE_KEYLEN equ 19; setting and getting RC2 effective key length

    KP_SCHANNEL_ALG equ 20; for setting the Secure Channel algorithms

    KP_CLIENT_RANDOM equ 21; for setting the Secure Channel client random data

    KP_SERVER_RANDOM equ 22; for setting the Secure Channel server random data

    KP_RP equ 23
    KP_PRECOMP_MD5 equ 24
    KP_PRECOMP_SHA equ 25
    KP_CERTIFICATE equ 26; for setting Secure Channel certificate data (PCT1)

    KP_CLEAR_KEY equ 27; for setting Secure Channel clear key data (PCT1)

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
    ;(NTDDI_VERSION >= NTDDI_WS03)
    KP_OAEP_PARAMS equ 36; for setting OAEP params on RSA keys

    KP_CMS_KEY_INFO equ 37
    KP_CMS_DH_KEY_INFO equ 38
    KP_PUB_PARAMS equ 39; for setting public parameters

    KP_VERIFY_PARAMS equ 40; for verifying DSA and DH parameters

    KP_HIGHEST_VERSION equ 41; for TLS protocol version setting

    if (NTDDI_VERSION ge NTDDI_WS03)
      KP_GET_USE_COUNT equ 42; for use with PP_CRYPT_COUNT_KEY_USE contexts

    endif
    ;(NTDDI_VERSION >= NTDDI_WS03)
    KP_PIN_ID equ 43
    KP_PIN_INFO equ 44
    ; KP_PADDING
    PKCS5_PADDING equ 1; PKCS 5 (sec 6.2) padding method

    RANDOM_PADDING equ 2
    ZERO_PADDING equ 3
    ; KP_MODE
    CRYPT_MODE_CBC equ 1; Cipher block chaining

    CRYPT_MODE_ECB equ 2; Electronic code book

    CRYPT_MODE_OFB equ 3; Output feedback mode

    CRYPT_MODE_CFB equ 4; Cipher feedback mode

    CRYPT_MODE_CTS equ 5; Ciphertext stealing mode

    ; KP_PERMISSIONS
    CRYPT_ENCRYPT equ 0001h; Allow encryption

    CRYPT_DECRYPT equ 0002h; Allow decryption

    CRYPT_EXPORT equ 0004h; Allow key to be exported

    CRYPT_READ equ 0008h; Allow parameters to be read

    CRYPT_WRITE equ 0010h; Allow parameters to be set

    CRYPT_MAC equ 0020h; Allow MACs to be used with key

    CRYPT_EXPORT_KEY equ 0040h; Allow key to be used for exporting keys

    CRYPT_IMPORT_KEY equ 0080h; Allow key to be used for importing keys

    if (NTDDI_VERSION ge NTDDI_WINXP)
      CRYPT_ARCHIVE equ 0100h; Allow key to be exported at creation only

    endif
    ;(NTDDI_VERSION >= NTDDI_WINXP)
    HP_ALGID equ 0001h; Hash algorithm

    HP_HASHVAL equ 0002h; Hash value

    HP_HASHSIZE equ 0004h; Hash value size

    HP_HMAC_INFO equ 0005h; information for creating an HMAC

    HP_TLS1PRF_LABEL equ 0006h; label for TLS1 PRF

    HP_TLS1PRF_SEED equ 0007h; seed for TLS1 PRF

    CRYPT_FAILED equ <FALSE>
    CRYPT_SUCCEED equ <TRUE>
    RCRYPT_SUCCEEDED macro rt
      exitm <((rt) == CRYPT_SUCCEED)>
    endm
    RCRYPT_FAILED macro rt
      exitm <((rt) == CRYPT_FAILED)>
    endm
    ; CryptGetProvParam
    PP_ENUMALGS equ 1
    PP_ENUMCONTAINERS equ 2
    PP_IMPTYPE equ 3
    PP_NAME equ 4
    PP_VERSION equ 5
    PP_CONTAINER equ 6
    PP_CHANGE_PASSWORD equ 7
    PP_KEYSET_SEC_DESCR equ 8; get/set security descriptor of keyset

    PP_CERTCHAIN equ 9; for retrieving certificates from tokens

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
    ;(NTDDI_VERSION >= NTDDI_WS03)
    if (NTDDI_VERSION ge NTDDI_VISTA)
      PP_USER_CERTSTORE equ 42
      PP_SMARTCARD_READER equ 43
      PP_SMARTCARD_GUID equ 45
      PP_ROOT_CERTSTORE equ 46
    endif
    ;(NTDDI_VERSION >= NTDDI_VISTA)
    if (NTDDI_VERSION ge NTDDI_WIN8)
      PP_SMARTCARD_READER_ICON equ 47
    endif
    ; (NTDDI_VERSION >= NTDDI_WIN8)
    CRYPT_FIRST equ 1
    CRYPT_NEXT equ 2
    CRYPT_SGC_ENUM equ 4
    CRYPT_IMPL_HARDWARE equ 1
    CRYPT_IMPL_SOFTWARE equ 2
    CRYPT_IMPL_MIXED equ 3
    CRYPT_IMPL_UNKNOWN equ 4
    CRYPT_IMPL_REMOVABLE equ 8
    ; key storage flags
    CRYPT_SEC_DESCR equ 00000001h
    CRYPT_PSTORE equ 00000002h
    CRYPT_UI_PROMPT equ 00000004h
    ; protocol flags
    CRYPT_FLAG_PCT1 equ 0001h
    CRYPT_FLAG_SSL2 equ 0002h
    CRYPT_FLAG_SSL3 equ 0004h
    CRYPT_FLAG_TLS1 equ 0008h
    CRYPT_FLAG_IPSEC equ 0010h
    CRYPT_FLAG_SIGNING equ 0020h
    ; SGC flags
    CRYPT_SGC equ 0001h
    CRYPT_FASTSGC equ 0002h
    ; CryptSetProvParam
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
    ;(NTDDI_VERSION >= NTDDI_VISTA)
    if (NTDDI_VERSION ge NTDDI_WIN10_RS5)
      PP_DISMISS_PIN_UI_SEC equ 49
      PP_IS_PFX_EPHEMERAL equ 50
    endif
    ; (NTDDI_VERSION >= NTDDI_WIN10_RS5)
    ; certenrolld_begin -- PROV_RSA_*
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
    ;(NTDDI_VERSION >= NTDDI_WINXP)
    ; certenrolld_end
    if (NTDDI_VERSION le NTDDI_WINXP)
      ; STT defined Providers
      PROV_STT_MER equ 7
      PROV_STT_ACQ equ 8
      PROV_STT_BRND equ 9
      PROV_STT_ROOT equ 10
      PROV_STT_ISS equ 11
    endif
    ;(NTDDI_VERSION <= NTDDI_WINXP)
    ; Provider friendly names
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
    ;(NTDDI_VERSION >= NTDDI_WINXP)
    MAXUIDLEN equ 64
    ; Exponentiation Offload Reg Location
    EXPO_OFFLOAD_REG_VALUE equ <"ExpoOffload">
    EXPO_OFFLOAD_FUNC_NAME equ <"OffloadModExpo">
    ; Registry key in which the following private key-related
    ; values are created.
    ifndef szKEY_CRYPTOAPI_PRIVATE_KEY_OPTIONS
      szKEY_CRYPTOAPI_PRIVATE_KEY_OPTIONS equ <"Software\Policies\Microsoft\Cryptography">
    endif
    ; Registry values for enabling and controlling the caching (and timeout)
    ; of private keys.  This feature is intended for UI-protected private
    ; keys.
    ; Note that in Windows 2000 and later, private keys, once read from storage,
    ; are cached in the associated HCRYPTPROV structure for subsequent use.
    ; In Server 2003 and XP SP1, new key caching behavior is available.  Keys
    ; that have been read from storage and cached may now be considered "stale"
    ; if a period of time has elapsed since the key was last used.  This forces
    ; the key to be re-read from storage (which will make the DPAPI UI appear
    ; again).
    ; Optional Key Timeouts:
    ; In Windows Server 2003, XP SP1, and later, new key caching behavior is
    ; available.  Keys that have been read from storage and cached per-context
    ; may now be considered "stale" if a period of time has elapsed since the
    ; key was last used.  This forces the key to be re-read from storage (which
    ; will make the Data Protection API dialog appear again if the key is
    ; UI-protected).
    ; To enable the new behavior, create the registry DWORD value
    ; szKEY_CACHE_ENABLED and set it to 1.  The registry DWORD value
    ; szKEY_CACHE_SECONDS must also be created and set to the number of seconds
    ; that a cached private key may still be considered usable.
    szKEY_CACHE_ENABLED equ <"CachePrivateKeys">
    szKEY_CACHE_SECONDS equ <"PrivateKeyLifetimeSeconds">
    if (NTDDI_VERSION ge NTDDI_WINXP)
      ; In platforms later than (and not including) Windows Server 2003, private
      ; keys are always cached for a period of time per-process, even when
      ; not being used in any context.
      ; The differences between the process-wide caching settings described below
      ; and the Optional Key Timeouts described above are subtle.
      ;  - The Optional Key Timeout policy is applied only when an attempt is made
      ;    to use a specific private key with an open context handle (HCRYPTPROV).
      ;    If szKEY_CACHE_SECONDS have elapsed since the key was last used, the
      ;    private key will be re-read from storage.
      ;  - The Cache Purge Interval policy, below, is applied whenever any
      ;    non-ephemeral private key is used or read from storage.  If
      ;    szPRIV_KEY_CACHE_PURGE_INTERVAL_SECONDS have elapsed since the last
      ;    purge occurred, all cached keys that have not been referenced since the
      ;    last purge will be removed from the cache.
      ;    If a private key that is purged from the cache is currently
      ;    referenced in an open context, then the key will be re-read from storage
      ;    the next time an attempt is made to use it (via any context).
      ; The following two registry DWORD values control this behavior.
      ; Registry value for controlling the maximum number of persisted
      ; (non-ephemeral) private keys that can be cached per-process.  If the cache
      ; fills up, keys will be replaced on a least-recently-used basis.  If the
      ; maximum number of cached keys is set to zero, no keys will be globally
      ; cached.
      szPRIV_KEY_CACHE_MAX_ITEMS equ <"PrivKeyCacheMaxItems">
      cPRIV_KEY_CACHE_MAX_ITEMS_DEFAULT equ 20
      ; Registry value for controlling the interval at which the private key
      ; cache is proactively purged of outdated keys.
      szPRIV_KEY_CACHE_PURGE_INTERVAL_SECONDS equ <"PrivKeyCachePurgeIntervalSeconds">
      cPRIV_KEY_CACHE_PURGE_INTERVAL_SECONDS_DEFAULT equ 86400; 1 day

    endif
    ;(NTDDI_VERSION >= NTDDI_WINXP)
    CUR_BLOB_VERSION equ 2
    ; structure for use with CryptSetKeyParam for CMS keys
    ; DO NOT USE THIS STRUCTURE!!!!!
    CMS_KEY_INFO struct
      dwVersion DWORD ?
      ; sizeof(CMS_KEY_INFO)
      Algid ALG_ID ?
      ; algorithmm id for the key to be converted
      pbOID POINTER ?
      ; pointer to OID to hash in with Z
      cbOID DWORD ?
      ; length of OID to hash in with Z
    CMS_KEY_INFO ends
    _CMS_KEY_INFO typedef CMS_KEY_INFO
    PCMS_KEY_INFO typedef ptr CMS_KEY_INFO
    ; structure for use with CryptSetHashParam with CALG_HMAC
    HMAC_INFO struct
      HashAlgid ALG_ID ?
      pbInnerString POINTER ?
      cbInnerString DWORD ?
      pbOuterString POINTER ?
      cbOuterString DWORD ?
    HMAC_INFO ends
    _HMAC_Info typedef HMAC_INFO
    PHMAC_INFO typedef ptr HMAC_INFO
    ; structure for use with CryptSetKeyParam with KP_SCHANNEL_ALG
    SCHANNEL_ALG struct
      dwUse DWORD ?
      Algid ALG_ID ?
      cBits DWORD ?
      dwFlags DWORD ?
      dwReserved DWORD ?
    SCHANNEL_ALG ends
    _SCHANNEL_ALG typedef SCHANNEL_ALG
    PSCHANNEL_ALG typedef ptr SCHANNEL_ALG
    ; uses of algortihms for SCHANNEL_ALG structure
    SCHANNEL_MAC_KEY equ 00000000h
    SCHANNEL_ENC_KEY equ 00000001h
    ; uses of dwFlags SCHANNEL_ALG structure
    INTERNATIONAL_USAGE equ 00000001h
    PROV_ENUMALGS struct
      aiAlgid ALG_ID ?
      dwBitLen DWORD ?
      dwNameLen DWORD ?
      szName SBYTE 20 dup (?)
    PROV_ENUMALGS ends
    _PROV_ENUMALGS typedef PROV_ENUMALGS
    ; certenrolls_begin -- PROV_ENUMALGS_EX
    PROV_ENUMALGS_EX struct
      aiAlgid ALG_ID ?
      dwDefaultLen DWORD ?
      dwMinLen DWORD ?
      dwMaxLen DWORD ?
      dwProtocols DWORD ?
      dwNameLen DWORD ?
      szName SBYTE 20 dup (?)
      dwLongNameLen DWORD ?
      szLongName SBYTE 40 dup (?)
    PROV_ENUMALGS_EX ends
    _PROV_ENUMALGS_EX typedef PROV_ENUMALGS_EX
    ; certenrolls_end
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
      ; Has to be RSA1
      bitlen DWORD ?
      ; # of bits in modulus
      pubexp DWORD ?
      ; public exponent
      ; Modulus data follows
    RSAPUBKEY ends
    _RSAPUBKEY typedef RSAPUBKEY
    DHPUBKEY struct
      magic DWORD ?
      bitlen DWORD ?
      ; # of bits in modulus
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
      ; # of bits in prime modulus
      bitlenQ DWORD ?
      ; # of bits in prime q, 0 if not available
      bitlenJ DWORD ?
      ; # of bits in (p-1)/q, 0 if not available
      DSSSeed DSSSEED <>
    DHPUBKEY_VER3 ends
    _PUBKEYVER3 typedef DHPUBKEY_VER3
    DSSPUBKEY_VER3 typedef DHPUBKEY_VER3
    DHPRIVKEY_VER3 struct
      magic DWORD ?
      bitlenP DWORD ?
      ; # of bits in prime modulus
      bitlenQ DWORD ?
      ; # of bits in prime q, 0 if not available
      bitlenJ DWORD ?
      ; # of bits in (p-1)/q, 0 if not available
      bitlenX DWORD ?
      ; # of bits in X
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
    ;(NTDDI_VERSION >= NTDDI_WS03)
    if (NTDDI_VERSION ge NTDDI_VISTA)
      CRYPT_AES_128_KEY_STATE struct
        Key BYTE 16 dup (?)
        IV BYTE 16 dup (?)
        EncryptionState BYTE 11 * 16 dup (?)
        ; 10 rounds + 1
        DecryptionState BYTE 11 * 16 dup (?)
        Feedback BYTE 16 dup (?)
      CRYPT_AES_128_KEY_STATE ends
      _CRYPT_AES_128_KEY_STATE typedef CRYPT_AES_128_KEY_STATE
      PCRYPT_AES_128_KEY_STATE typedef ptr CRYPT_AES_128_KEY_STATE
      CRYPT_AES_256_KEY_STATE struct
        Key BYTE 32 dup (?)
        IV BYTE 16 dup (?)
        EncryptionState BYTE 15 * 16 dup (?)
        ; 14 rounds + 1
        DecryptionState BYTE 15 * 16 dup (?)
        Feedback BYTE 16 dup (?)
      CRYPT_AES_256_KEY_STATE ends
      _CRYPT_AES_256_KEY_STATE typedef CRYPT_AES_256_KEY_STATE
      PCRYPT_AES_256_KEY_STATE typedef ptr CRYPT_AES_256_KEY_STATE
    endif
    ;(NTDDI_VERSION >= NTDDI_VISTA)
    ;+-------------------------------------------------------------------------
    ;  CRYPTOAPI BLOB definitions
    ;--------------------------------------------------------------------------
    ; certenrolls_begin -- *_BLOB
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
    ; certenrolls_end
    ; structure for use with CryptSetKeyParam for CMS keys
    CMS_DH_KEY_INFO struct
      dwVersion DWORD ?
      ; sizeof(CMS_DH_KEY_INFO)
      Algid ALG_ID ?
      ; algorithmm id for the key to be converted
      pszContentEncObjId POINTER ?
      ; pointer to OID to hash in with Z
      PubInfo CRYPT_DATA_BLOB <>
      ; OPTIONAL - public information
      pReserved POINTER ?
      ; reserved - should be NULL
    CMS_DH_KEY_INFO ends
    _CMS_DH_KEY_INFO typedef CMS_DH_KEY_INFO
    PCMS_DH_KEY_INFO typedef ptr CMS_DH_KEY_INFO
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_PHONE_RESTRICTED or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, CryptAcquireContextA, WIN_STD_CALL_CONV,, <:ptr HCRYPTPROV, :LPCSTR, :LPCSTR, :DWORD, :DWORD>, 20
    @DefProto DllImport, CryptAcquireContextW, WIN_STD_CALL_CONV,, <:ptr HCRYPTPROV, :LPCWSTR, :LPCWSTR, :DWORD, :DWORD>, 20
    ifdef UNICODE
      CryptAcquireContext equ <CryptAcquireContextW>
    else
      CryptAcquireContext equ <CryptAcquireContextA>
    endif
    ; !UNICODE
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP|WINAPI_PARTITION_PHONE_RESTRICTED | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, CryptReleaseContext, WIN_STD_CALL_CONV,, <:HCRYPTPROV, :DWORD>, 8
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)*
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
    ; !UNICODE
    @DefProto DllImport, CryptVerifySignatureA, WIN_STD_CALL_CONV,, <:HCRYPTHASH, :ptr BYTE, :DWORD, :HCRYPTKEY, :LPCSTR, :DWORD>, 24
    @DefProto DllImport, CryptVerifySignatureW, WIN_STD_CALL_CONV,, <:HCRYPTHASH, :ptr BYTE, :DWORD, :HCRYPTKEY, :LPCWSTR, :DWORD>, 24
    ifdef UNICODE
      CryptVerifySignature equ <CryptVerifySignatureW>
    else
      CryptVerifySignature equ <CryptVerifySignatureA>
    endif
    ; !UNICODE
    @DefProto DllImport, CryptSetProviderA, WIN_STD_CALL_CONV,, <:LPCSTR, :DWORD>, 8
    @DefProto DllImport, CryptSetProviderW, WIN_STD_CALL_CONV,, <:LPCWSTR, :DWORD>, 8
    ifdef UNICODE
      CryptSetProvider equ <CryptSetProviderW>
    else
      CryptSetProvider equ <CryptSetProviderA>
    endif
    ; !UNICODE
    @DefProto DllImport, CryptSetProviderExA, WIN_STD_CALL_CONV,, <:LPCSTR, :DWORD, :ptr DWORD, :DWORD>, 16
    @DefProto DllImport, CryptSetProviderExW, WIN_STD_CALL_CONV,, <:LPCWSTR, :DWORD, :ptr DWORD, :DWORD>, 16
    ifdef UNICODE
      CryptSetProviderEx equ <CryptSetProviderExW>
    else
      CryptSetProviderEx equ <CryptSetProviderExA>
    endif
    ; !UNICODE
    @DefProto DllImport, CryptGetDefaultProviderA, WIN_STD_CALL_CONV,, <:DWORD, :ptr DWORD, :DWORD, :LPSTR, :ptr DWORD>, 20
    @DefProto DllImport, CryptGetDefaultProviderW, WIN_STD_CALL_CONV,, <:DWORD, :ptr DWORD, :DWORD, :LPWSTR, :ptr DWORD>, 20
    ifdef UNICODE
      CryptGetDefaultProvider equ <CryptGetDefaultProviderW>
    else
      CryptGetDefaultProvider equ <CryptGetDefaultProviderA>
    endif
    ; !UNICODE
    @DefProto DllImport, CryptEnumProviderTypesA, WIN_STD_CALL_CONV,, <:DWORD, :ptr DWORD, :DWORD, :ptr DWORD, :LPSTR, :ptr DWORD>, 24
    @DefProto DllImport, CryptEnumProviderTypesW, WIN_STD_CALL_CONV,, <:DWORD, :ptr DWORD, :DWORD, :ptr DWORD, :LPWSTR, :ptr DWORD>, 24
    ifdef UNICODE
      CryptEnumProviderTypes equ <CryptEnumProviderTypesW>
    else
      CryptEnumProviderTypes equ <CryptEnumProviderTypesA>
    endif
    ; !UNICODE
    @DefProto DllImport, CryptEnumProvidersA, WIN_STD_CALL_CONV,, <:DWORD, :ptr DWORD, :DWORD, :ptr DWORD, :LPSTR, :ptr DWORD>, 24
    @DefProto DllImport, CryptEnumProvidersW, WIN_STD_CALL_CONV,, <:DWORD, :ptr DWORD, :DWORD, :ptr DWORD, :LPWSTR, :ptr DWORD>, 24
    ifdef UNICODE
      CryptEnumProviders equ <CryptEnumProvidersW>
    else
      CryptEnumProviders equ <CryptEnumProvidersA>
    endif
    ; !UNICODE
    @DefProto DllImport, CryptContextAddRef, WIN_STD_CALL_CONV,, <:HCRYPTPROV, :ptr DWORD, :DWORD>, 12
    @DefProto DllImport, CryptDuplicateKey, WIN_STD_CALL_CONV,, <:HCRYPTKEY, :ptr DWORD, :DWORD, :ptr HCRYPTKEY>, 16
    @DefProto DllImport, CryptDuplicateHash, WIN_STD_CALL_CONV,, <:HCRYPTHASH, :ptr DWORD, :DWORD, :ptr HCRYPTHASH>, 16
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP|WINAPI_PARTITION_PHONE_RESTRICTED | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_PHONE_RESTRICTED or WINAPI_PARTITION_GAMES)
    if (NTDDI_VERSION ge NTDDI_WS03)
      ; This function is provided in Microsoft Windows 2000 as a means of
      ; installing the 128-bit encryption provider. This function is unavailable
      ; in Microsoft Windows XP, because Windows XP ships with the 128-bit
      ; encryption provider.
      GetEncSChannel proto c :ptr ptr BYTE, :ptr DWORD
    endif
    ;(NTDDI_VERSION >= NTDDI_WS03)
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_PHONE_RESTRICTED | WINAPI_PARTITION_GAMES) *
  endif
  if  not Defined(_DDK_DRIVER_)
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_PHONE_RESTRICTED or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      ; In Vista, the following APIs were updated to support the new
      ; CNG (Cryptography Next Generation) BCrypt* and NCrypt* APIs in addition
      ; to the above CAPI1 APIs.
      ; Include the definitions for the CNG APIs
      include bcrypt.inc
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP|WINAPI_PARTITION_PHONE_RESTRICTED | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      include ncrypt.inc
      ; This type is used when the API can take either the CAPI1 HCRYPTPROV or
      ; the CNG NCRYPT_KEY_HANDLE. Where appropriate, the HCRYPTPROV will be
      ; converted to a NCRYPT_KEY_HANDLE via the CNG NCryptTranslateHandle().
      HCRYPTPROV_OR_NCRYPT_KEY_HANDLE typedef ULONG_PTR
      ; This type is used where the HCRYPTPROV parameter is no longer used.
      ; The caller should always pass in NULL.
      HCRYPTPROV_LEGACY typedef ULONG_PTR
      ;+-------------------------------------------------------------------------
      ;  In a CRYPT_BIT_BLOB the last byte may contain 0-7 unused bits. Therefore, the
      ;  overall bit length is cbData * 8 - cUnusedBits.
      ;--------------------------------------------------------------------------
      ; certenrolls_begin -- CERT_CONTEXT
      CRYPT_BIT_BLOB struct
        cbData DWORD ?
        pbData POINTER ?
        cUnusedBits DWORD ?
      CRYPT_BIT_BLOB ends
      _CRYPT_BIT_BLOB typedef CRYPT_BIT_BLOB
      PCRYPT_BIT_BLOB typedef ptr CRYPT_BIT_BLOB
      ;+-------------------------------------------------------------------------
      ;  Type used for any algorithm
      ;  Where the Parameters CRYPT_OBJID_BLOB is in its encoded representation. For most
      ;  algorithm types, the Parameters CRYPT_OBJID_BLOB is NULL (Parameters.cbData = 0).
      ;--------------------------------------------------------------------------
      CRYPT_ALGORITHM_IDENTIFIER struct
        pszObjId POINTER ?
        Parameters CRYPT_OBJID_BLOB <>
      CRYPT_ALGORITHM_IDENTIFIER ends
      _CRYPT_ALGORITHM_IDENTIFIER typedef CRYPT_ALGORITHM_IDENTIFIER
      PCRYPT_ALGORITHM_IDENTIFIER typedef ptr CRYPT_ALGORITHM_IDENTIFIER
      ; certenrolls_end
      ; Following are the definitions of various algorithm object identifiers
      ; RSA
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
      ; iso(1) member-body(2) us(840) 10045 keyType(2) unrestricted(1)
      szOID_ECC_PUBLIC_KEY equ <"1.2.840.10045.2.1">
      ; iso(1) member-body(2) us(840) 10045 curves(3) prime(1) 7
      szOID_ECC_CURVE_P256 equ <"1.2.840.10045.3.1.7">
      ; iso(1) identified-organization(3) certicom(132) curve(0) 34
      szOID_ECC_CURVE_P384 equ <"1.3.132.0.34">
      ; iso(1) identified-organization(3) certicom(132) curve(0) 35
      szOID_ECC_CURVE_P521 equ <"1.3.132.0.35">
      ; Generic ECC Curve OIDS
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
      ; iso(1) member-body(2) us(840) 10045 signatures(4) sha1(1)
      szOID_ECDSA_SHA1 equ <"1.2.840.10045.4.1">
      ; iso(1) member-body(2) us(840) 10045 signatures(4) specified(3)
      szOID_ECDSA_SPECIFIED equ <"1.2.840.10045.4.3">
      ; iso(1) member-body(2) us(840) 10045 signatures(4) specified(3) 2
      szOID_ECDSA_SHA256 equ <"1.2.840.10045.4.3.2">
      ; iso(1) member-body(2) us(840) 10045 signatures(4) specified(3) 3
      szOID_ECDSA_SHA384 equ <"1.2.840.10045.4.3.3">
      ; iso(1) member-body(2) us(840) 10045 signatures(4) specified(3) 4
      szOID_ECDSA_SHA512 equ <"1.2.840.10045.4.3.4">
      ; NIST AES CBC Algorithms
      ; joint-iso-itu-t(2) country(16) us(840) organization(1) gov(101) csor(3) nistAlgorithms(4)  aesAlgs(1) }
      szOID_NIST_AES128_CBC equ <"2.16.840.1.101.3.4.1.2">
      szOID_NIST_AES192_CBC equ <"2.16.840.1.101.3.4.1.22">
      szOID_NIST_AES256_CBC equ <"2.16.840.1.101.3.4.1.42">
      ; For the above Algorithms, the AlgorithmIdentifier parameters must be
      ; present and the parameters field MUST contain an AES-IV:
      ;  AES-IV ::= OCTET STRING (SIZE(16))
      ; NIST AES WRAP Algorithms
      szOID_NIST_AES128_WRAP equ <"2.16.840.1.101.3.4.1.5">
      szOID_NIST_AES192_WRAP equ <"2.16.840.1.101.3.4.1.25">
      szOID_NIST_AES256_WRAP equ <"2.16.840.1.101.3.4.1.45">
      ;      x9-63-scheme OBJECT IDENTIFIER ::= { iso(1)
      ;         identified-organization(3) tc68(133) country(16) x9(840)
      ;         x9-63(63) schemes(0) }
      ; ECDH single pass ephemeral-static KeyAgreement KeyEncryptionAlgorithm
      szOID_DH_SINGLE_PASS_STDDH_SHA1_KDF equ <"1.3.133.16.840.63.0.2">
      szOID_DH_SINGLE_PASS_STDDH_SHA256_KDF equ <"1.3.132.1.11.1">
      szOID_DH_SINGLE_PASS_STDDH_SHA384_KDF equ <"1.3.132.1.11.2">
      ; For the above KeyEncryptionAlgorithm the following wrap algorithms are
      ; supported:
      ;  szOID_RSA_SMIMEalgCMS3DESwrap
      ;  szOID_RSA_SMIMEalgCMSRC2wrap
      ;  szOID_NIST_AES128_WRAP
      ;  szOID_NIST_AES192_WRAP
      ;  szOID_NIST_AES256_WRAP
      ; ITU-T UsefulDefinitions
      szOID_DS equ <"2.5">
      szOID_DSALG equ <"2.5.8">
      szOID_DSALG_CRPT equ <"2.5.8.1">
      szOID_DSALG_HASH equ <"2.5.8.2">
      szOID_DSALG_SIGN equ <"2.5.8.3">
      szOID_DSALG_RSA equ <"2.5.8.1.1">
      ; NIST OSE Implementors' Workshop (OIW)
      ; http://nemo.ncsl.nist.gov/oiw/agreements/stable/OSI/12s_9506.w51
      ; http://nemo.ncsl.nist.gov/oiw/agreements/working/OSI/12w_9503.w51
      szOID_OIW equ <"1.3.14">
      ; NIST OSE Implementors' Workshop (OIW) Security SIG algorithm identifiers
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
      ; NIST OSE Implementors' Workshop (OIW) Directory SIG algorithm identifiers
      szOID_OIWDIR equ <"1.3.14.7.2">
      szOID_OIWDIR_CRPT equ <"1.3.14.7.2.1">
      szOID_OIWDIR_HASH equ <"1.3.14.7.2.2">
      szOID_OIWDIR_SIGN equ <"1.3.14.7.2.3">
      szOID_OIWDIR_md2 equ <"1.3.14.7.2.2.1">
      szOID_OIWDIR_md2RSA equ <"1.3.14.7.2.3.1">
      ; INFOSEC Algorithms
      ; joint-iso-ccitt(2) country(16) us(840) organization(1) us-government(101) dod(2) id-infosec(1)
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
      ; NIST Hash Algorithms
      ; joint-iso-itu-t(2) country(16) us(840) organization(1) gov(101) csor(3) nistalgorithm(4) hashalgs(2)
      szOID_NIST_sha256 equ <"2.16.840.1.101.3.4.2.1">
      szOID_NIST_sha384 equ <"2.16.840.1.101.3.4.2.2">
      szOID_NIST_sha512 equ <"2.16.840.1.101.3.4.2.3">
      CRYPT_OBJID_TABLE struct
        dwAlgId DWORD ?
        pszObjId =POINTER ?
      CRYPT_OBJID_TABLE ends
      _CRYPT_OBJID_TABLE typedef CRYPT_OBJID_TABLE
      PCRYPT_OBJID_TABLE typedef ptr CRYPT_OBJID_TABLE
      ;+-------------------------------------------------------------------------
      ;  PKCS #1 HashInfo (DigestInfo)
      ;--------------------------------------------------------------------------
      CRYPT_HASH_INFO struct
        HashAlgorithm CRYPT_ALGORITHM_IDENTIFIER <>
        Hash CRYPT_HASH_BLOB <>
      CRYPT_HASH_INFO ends
      _CRYPT_HASH_INFO typedef CRYPT_HASH_INFO
      PCRYPT_HASH_INFO typedef ptr CRYPT_HASH_INFO
      ;+-------------------------------------------------------------------------
      ;  Type used for an extension to an encoded content
      ;  Where the Value's CRYPT_OBJID_BLOB is in its encoded representation.
      ;--------------------------------------------------------------------------
      ; certenrolls_begin -- CERT_CONTEXT
      CERT_EXTENSION struct
        pszObjId POINTER ?
        fCritical DWORD ?
        Value CRYPT_OBJID_BLOB <>
      CERT_EXTENSION ends
      _CERT_EXTENSION typedef CERT_EXTENSION
      PCERT_EXTENSION typedef ptr CERT_EXTENSION
      PCCERT_EXTENSION typedef ptr CERT_EXTENSION
      ; certenrolls_end
      ;+-------------------------------------------------------------------------
      ;  AttributeTypeValue
      ;  Where the Value's CRYPT_OBJID_BLOB is in its encoded representation.
      ;--------------------------------------------------------------------------
      ; certenrolls_begin -- CRYPT_ATTRIBUTE_TYPE_VALUE
      CRYPT_ATTRIBUTE_TYPE_VALUE struct
        pszObjId POINTER ?
        Value CRYPT_OBJID_BLOB <>
      CRYPT_ATTRIBUTE_TYPE_VALUE ends
      _CRYPT_ATTRIBUTE_TYPE_VALUE typedef CRYPT_ATTRIBUTE_TYPE_VALUE
      PCRYPT_ATTRIBUTE_TYPE_VALUE typedef ptr CRYPT_ATTRIBUTE_TYPE_VALUE
      ; certenrolls_end
      ;+-------------------------------------------------------------------------
      ;  Attributes
      ;  Where the Value's PATTR_BLOBs are in their encoded representation.
      ;--------------------------------------------------------------------------
      ; certenrolls_begin -- CRYPT_ATTRIBUTE
      CRYPT_ATTRIBUTE struct
        pszObjId POINTER ?
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
      ; certenrolls_end
      ;+-------------------------------------------------------------------------
      ;  Attributes making up a Relative Distinguished Name (CERT_RDN)
      ;  The interpretation of the Value depends on the dwValueType.
      ;  See below for a list of the types.
      ;--------------------------------------------------------------------------
      CERT_RDN_ATTR struct
        pszObjId POINTER ?
        dwValueType DWORD ?
        Value CERT_RDN_VALUE_BLOB <>
      CERT_RDN_ATTR ends
      _CERT_RDN_ATTR typedef CERT_RDN_ATTR
      PCERT_RDN_ATTR typedef ptr CERT_RDN_ATTR
      ;+-------------------------------------------------------------------------
      ;  CERT_RDN attribute Object Identifiers
      ;--------------------------------------------------------------------------
      ; Labeling attribute types:
      szOID_COMMON_NAME equ <"2.5.4.3">; case-ignore string

      szOID_SUR_NAME equ <"2.5.4.4">; case-ignore string

      szOID_DEVICE_SERIAL_NUMBER equ <"2.5.4.5">; printable string

      ; Geographic attribute types:
      szOID_COUNTRY_NAME equ <"2.5.4.6">; printable 2char string

      szOID_LOCALITY_NAME equ <"2.5.4.7">; case-ignore string

      szOID_STATE_OR_PROVINCE_NAME equ <"2.5.4.8">; case-ignore string

      szOID_STREET_ADDRESS equ <"2.5.4.9">; case-ignore string

      ; Organizational attribute types:
      szOID_ORGANIZATION_NAME equ <"2.5.4.10">; case-ignore string

      szOID_ORGANIZATIONAL_UNIT_NAME equ <"2.5.4.11">; case-ignore string

      szOID_TITLE equ <"2.5.4.12">; case-ignore string

      ; Explanatory attribute types:
      szOID_DESCRIPTION equ <"2.5.4.13">; case-ignore string

      szOID_SEARCH_GUIDE equ <"2.5.4.14">
      szOID_BUSINESS_CATEGORY equ <"2.5.4.15">; case-ignore string

      ; Postal addressing attribute types:
      szOID_POSTAL_ADDRESS equ <"2.5.4.16">
      szOID_POSTAL_CODE equ <"2.5.4.17">; case-ignore string

      szOID_POST_OFFICE_BOX equ <"2.5.4.18">; case-ignore string

      szOID_PHYSICAL_DELIVERY_OFFICE_NAME equ <"2.5.4.19">; case-ignore string

      ; Telecommunications addressing attribute types:
      szOID_TELEPHONE_NUMBER equ <"2.5.4.20">; telephone number

      szOID_TELEX_NUMBER equ <"2.5.4.21">
      szOID_TELETEXT_TERMINAL_IDENTIFIER equ <"2.5.4.22">
      szOID_FACSIMILE_TELEPHONE_NUMBER equ <"2.5.4.23">
      szOID_X21_ADDRESS equ <"2.5.4.24">; numeric string

      szOID_INTERNATIONAL_ISDN_NUMBER equ <"2.5.4.25">; numeric string

      szOID_REGISTERED_ADDRESS equ <"2.5.4.26">
      szOID_DESTINATION_INDICATOR equ <"2.5.4.27">; printable string

      ; Preference attribute types:
      szOID_PREFERRED_DELIVERY_METHOD equ <"2.5.4.28">
      ; OSI application attribute types:
      szOID_PRESENTATION_ADDRESS equ <"2.5.4.29">
      szOID_SUPPORTED_APPLICATION_CONTEXT equ <"2.5.4.30">
      ; Relational application attribute types:
      szOID_MEMBER equ <"2.5.4.31">
      szOID_OWNER equ <"2.5.4.32">
      szOID_ROLE_OCCUPANT equ <"2.5.4.33">
      szOID_SEE_ALSO equ <"2.5.4.34">
      ; Security attribute types:
      szOID_USER_PASSWORD equ <"2.5.4.35">
      szOID_USER_CERTIFICATE equ <"2.5.4.36">
      szOID_CA_CERTIFICATE equ <"2.5.4.37">
      szOID_AUTHORITY_REVOCATION_LIST equ <"2.5.4.38">
      szOID_CERTIFICATE_REVOCATION_LIST equ <"2.5.4.39">
      szOID_CROSS_CERTIFICATE_PAIR equ <"2.5.4.40">
      ; Undocumented attribute types???
      ;#define szOID_???                         "2.5.4.41"
      szOID_GIVEN_NAME equ <"2.5.4.42">; case-ignore string

      szOID_INITIALS equ <"2.5.4.43">; case-ignore string

      ; The DN Qualifier attribute type specifies disambiguating information to add
      ; to the relative distinguished name of an entry. It is intended to be used
      ; for entries held in multiple DSAs which would otherwise have the same name,
      ; and that its value be the same in a given DSA for all entries to which
      ; the information has been added.
      szOID_DN_QUALIFIER equ <"2.5.4.46">
      ; Pilot user attribute types:
      szOID_DOMAIN_COMPONENT equ <"0.9.2342.19200300.100.1.25">; IA5, UTF8 string

      ; used for PKCS 12 attributes
      szOID_PKCS_12_FRIENDLY_NAME_ATTR equ <"1.2.840.113549.1.9.20">
      szOID_PKCS_12_LOCAL_KEY_ID equ <"1.2.840.113549.1.9.21">
      szOID_PKCS_12_KEY_PROVIDER_NAME_ATTR equ <"1.3.6.1.4.1.311.17.1">
      szOID_LOCAL_MACHINE_KEYSET equ <"1.3.6.1.4.1.311.17.2">
      szOID_PKCS_12_EXTENDED_ATTRIBUTES equ <"1.3.6.1.4.1.311.17.3">
      szOID_PKCS_12_PROTECTED_PASSWORD_SECRET_BAG_TYPE_ID equ <"1.3.6.1.4.1.311.17.4">
      ;+-------------------------------------------------------------------------
      ;  Microsoft CERT_RDN attribute Object Identifiers
      ;--------------------------------------------------------------------------
      ; Special RDN containing the KEY_ID. Its value type is CERT_RDN_OCTET_STRING.
      szOID_KEYID_RDN equ <"1.3.6.1.4.1.311.10.7.1">
      ;+-------------------------------------------------------------------------
      ;  EV RDN OIDs
      ;--------------------------------------------------------------------------
      szOID_EV_RDN_LOCALE equ <"1.3.6.1.4.1.311.60.2.1.1">
      szOID_EV_RDN_STATE_OR_PROVINCE equ <"1.3.6.1.4.1.311.60.2.1.2">
      szOID_EV_RDN_COUNTRY equ <"1.3.6.1.4.1.311.60.2.1.3">
      ;+-------------------------------------------------------------------------
      ;  CERT_RDN Attribute Value Types
      ;  For RDN_ENCODED_BLOB, the Value's CERT_RDN_VALUE_BLOB is in its encoded
      ;  representation. Otherwise, its an array of bytes.
      ;  For all CERT_RDN types, Value.cbData is always the number of bytes, not
      ;  necessarily the number of elements in the string. For instance,
      ;  RDN_UNIVERSAL_STRING is an array of ints (cbData == intCnt * 4) and
      ;  RDN_BMP_STRING is an array of unsigned shorts (cbData == ushortCnt * 2).
      ;  A RDN_UTF8_STRING is an array of UNICODE characters (cbData == charCnt *2).
      ;  These UNICODE characters are encoded as UTF8 8 bit characters.
      ;  For CertDecodeName, two 0 bytes are always appended to the end of the
      ;  string (ensures a CHAR or WCHAR string is null terminated).
      ;  These added 0 bytes are't included in the BLOB.cbData.
      ;--------------------------------------------------------------------------
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
      ;+-------------------------------------------------------------------------
      ;  Flags that can be or'ed with the above Value Type when encoding/decoding
      ;--------------------------------------------------------------------------
      ; For encoding: when set, CERT_RDN_T61_STRING is selected instead of
      ; CERT_RDN_UNICODE_STRING if all the unicode characters are <= 0xFF
      CERT_RDN_ENABLE_T61_UNICODE_FLAG equ 80000000h
      ; For encoding: when set, CERT_RDN_UTF8_STRING is selected instead of
      ; CERT_RDN_UNICODE_STRING.
      CERT_RDN_ENABLE_UTF8_UNICODE_FLAG equ 20000000h
      ; For encoding: when set, CERT_RDN_UTF8_STRING is selected instead of
      ; CERT_RDN_PRINTABLE_STRING for DirectoryString types. Also,
      ; enables CERT_RDN_ENABLE_UTF8_UNICODE_FLAG.
      CERT_RDN_FORCE_UTF8_UNICODE_FLAG equ 10000000h
      ; For encoding: when set, the characters aren't checked to see if they
      ; are valid for the Value Type.
      CERT_RDN_DISABLE_CHECK_TYPE_FLAG equ 40000000h
      ; For decoding: by default, CERT_RDN_T61_STRING values are initially decoded
      ; as UTF8. If the UTF8 decoding fails, then, decoded as 8 bit characters.
      ; Setting this flag skips the initial attempt to decode as UTF8.
      CERT_RDN_DISABLE_IE4_UTF8_FLAG equ 01000000h
      ; For encoding: If the string contains E/Email RDN, and the email-address
      ; (in RDN value) contains unicode characters outside of ASCII character set,
      ; the localpart and the hostname portion of the email-address would be first
      ; encoded in punycode and then the resultant Email-Address would be attempted
      ; to be encoded as IA5String. Punycode encoding of hostname is done on
      ; label-by-label basis.
      ; For decoding: If the name contains E/Email RDN, and local part or hostname
      ; portion of the email-address contains punycode encoded IA5String,
      ; The RDN string value is converted to its unicode equivalent.
      CERT_RDN_ENABLE_PUNYCODE_FLAG equ 02000000h
      ; Macro to check that the dwValueType is a character string and not an
      ; encoded blob or octet string
      IS_CERT_RDN_CHAR_STRING macro X
        exitm <(((X) and CERT_RDN_TYPE_MASK) >= CERT_RDN_NUMERIC_STRING)>
      endm
      ;+-------------------------------------------------------------------------
      ;  A CERT_RDN consists of an array of the above attributes
      ;--------------------------------------------------------------------------
      CERT_RDN struct
        cRDNAttr DWORD ?
        rgRDNAttr PCERT_RDN_ATTR ?
      CERT_RDN ends
      _CERT_RDN typedef CERT_RDN
      PCERT_RDN typedef ptr CERT_RDN
      ;+-------------------------------------------------------------------------
      ;  Information stored in a subject's or issuer's name. The information
      ;  is represented as an array of the above RDNs.
      ;--------------------------------------------------------------------------
      CERT_NAME_INFO struct
        cRDN DWORD ?
        rgRDN PCERT_RDN ?
      CERT_NAME_INFO ends
      _CERT_NAME_INFO typedef CERT_NAME_INFO
      PCERT_NAME_INFO typedef ptr CERT_NAME_INFO
      ;+-------------------------------------------------------------------------
      ;  Name attribute value without the Object Identifier
      ;  The interpretation of the Value depends on the dwValueType.
      ;  See above for a list of the types.
      ;--------------------------------------------------------------------------
      CERT_NAME_VALUE struct
        dwValueType DWORD ?
        Value CERT_RDN_VALUE_BLOB <>
      CERT_NAME_VALUE ends
      _CERT_NAME_VALUE typedef CERT_NAME_VALUE
      PCERT_NAME_VALUE typedef ptr CERT_NAME_VALUE
      ;+-------------------------------------------------------------------------
      ;  Public Key Info
      ;  The PublicKey is the encoded representation of the information as it is
      ;  stored in the bit string
      ;--------------------------------------------------------------------------
      ; certenrolls_begin -- CERT_CONTEXT
      CERT_PUBLIC_KEY_INFO struct
        Algorithm CRYPT_ALGORITHM_IDENTIFIER <>
        PublicKey CRYPT_BIT_BLOB <>
      CERT_PUBLIC_KEY_INFO ends
      _CERT_PUBLIC_KEY_INFO typedef CERT_PUBLIC_KEY_INFO
      PCERT_PUBLIC_KEY_INFO typedef ptr CERT_PUBLIC_KEY_INFO
      ; certenrolls_end
      CERT_RSA_PUBLIC_KEY_OBJID equ <szOID_RSA_RSA>
      CERT_DEFAULT_OID_PUBLIC_KEY_SIGN equ <szOID_RSA_RSA>
      CERT_DEFAULT_OID_PUBLIC_KEY_XCHG equ <szOID_RSA_RSA>
      ;+-------------------------------------------------------------------------
      ;  ECC Private Key Info
      ;--------------------------------------------------------------------------
      CRYPT_ECC_PRIVATE_KEY_INFO struct
        dwVersion DWORD ?
        ; ecPrivKeyVer1(1)
        PrivateKey CRYPT_DER_BLOB <>
        ; d
        szCurveOid POINTER ?
        ; Optional
        PublicKey CRYPT_BIT_BLOB <>
        ; Optional (x, y)
      CRYPT_ECC_PRIVATE_KEY_INFO ends
      _CRYPT_ECC_PRIVATE_KEY_INFO typedef CRYPT_ECC_PRIVATE_KEY_INFO
      PCRYPT_ECC_PRIVATE_KEY_INFO typedef ptr CRYPT_ECC_PRIVATE_KEY_INFO
      CRYPT_ECC_PRIVATE_KEY_INFO_v1 equ 1
      ;+-------------------------------------------------------------------------
      ;  structure that contains all the information in a PKCS#8 PrivateKeyInfo
      ;--------------------------------------------------------------------------
      CRYPT_PRIVATE_KEY_INFO struct
        Version DWORD ?
        Algorithm CRYPT_ALGORITHM_IDENTIFIER <>
        PrivateKey CRYPT_DER_BLOB <>
        pAttributes PCRYPT_ATTRIBUTES ?
      CRYPT_PRIVATE_KEY_INFO ends
      _CRYPT_PRIVATE_KEY_INFO typedef CRYPT_PRIVATE_KEY_INFO
      PCRYPT_PRIVATE_KEY_INFO typedef ptr CRYPT_PRIVATE_KEY_INFO
      ;+-------------------------------------------------------------------------
      ;  structure that contains all the information in a PKCS#8
      ;  EncryptedPrivateKeyInfo
      ;--------------------------------------------------------------------------
      CRYPT_ENCRYPTED_PRIVATE_KEY_INFO struct
        EncryptionAlgorithm CRYPT_ALGORITHM_IDENTIFIER <>
        EncryptedPrivateKey CRYPT_DATA_BLOB <>
      CRYPT_ENCRYPTED_PRIVATE_KEY_INFO ends
      _CRYPT_ENCRYPTED_PRIVATE_KEY_INFO typedef CRYPT_ENCRYPTED_PRIVATE_KEY_INFO
      PCRYPT_ENCRYPTED_PRIVATE_KEY_INFO typedef ptr CRYPT_ENCRYPTED_PRIVATE_KEY_INFO
      ;+-------------------------------------------------------------------------
      ; this callback is given when an EncryptedProvateKeyInfo structure is
      ; encountered during ImportPKCS8.  the caller is then expected to decrypt
      ; the private key and hand back the decrypted contents.
      ; the parameters are:
      ; Algorithm - the algorithm used to encrypt the PrivateKeyInfo
      ; EncryptedPrivateKey - the encrypted private key blob
      ; pClearTextKey - a buffer to receive the clear text
      ; cbClearTextKey - the number of bytes of the pClearTextKey buffer
      ;                  note the if this is zero then this should be
      ;                  filled in with the size required to decrypt the
      ;                  key into, and pClearTextKey should be ignored
      ; pVoidDecryptFunc - this is the pVoid that was passed into the call
      ;                    and is preserved and passed back as context
      ;+-------------------------------------------------------------------------
      TYPE_PCRYPT_DECRYPT_PRIVATE_KEY_FUNC typedef proto WIN_STD_CALL_CONV :CRYPT_ALGORITHM_IDENTIFIER, :CRYPT_DATA_BLOB, :ptr BYTE, :ptr DWORD, :LPVOID
      PCRYPT_DECRYPT_PRIVATE_KEY_FUNC typedef ptr TYPE_PCRYPT_DECRYPT_PRIVATE_KEY_FUNC

      ;+-------------------------------------------------------------------------
      ; this callback is given when creating a PKCS8 EncryptedPrivateKeyInfo.
      ; The caller is then expected to encrypt the private key and hand back
      ; the encrypted contents.
      ; the parameters are:
      ; Algorithm - the algorithm used to encrypt the PrivateKeyInfo
      ; pClearTextPrivateKey - the cleartext private key to be encrypted
      ; pbEncryptedKey - the output encrypted private key blob
      ; cbEncryptedKey - the number of bytes of the pbEncryptedKey buffer
      ;                  note the if this is zero then this should be
      ;                  filled in with the size required to encrypt the
      ;                  key into, and pbEncryptedKey should be ignored
      ; pVoidEncryptFunc - this is the pVoid that was passed into the call
      ;                    and is preserved and passed back as context
      ;+-------------------------------------------------------------------------
      TYPE_PCRYPT_ENCRYPT_PRIVATE_KEY_FUNC typedef proto WIN_STD_CALL_CONV :ptr CRYPT_ALGORITHM_IDENTIFIER, :ptr CRYPT_DATA_BLOB, :ptr BYTE, :ptr DWORD, :LPVOID
      PCRYPT_ENCRYPT_PRIVATE_KEY_FUNC typedef ptr TYPE_PCRYPT_ENCRYPT_PRIVATE_KEY_FUNC

      ;+-------------------------------------------------------------------------
      ; this callback is given from the context of a ImportPKCS8 calls.  the caller
      ; is then expected to hand back an HCRYPTPROV to receive the key being imported
      ; the parameters are:
      ; pPrivateKeyInfo - pointer to a CRYPT_PRIVATE_KEY_INFO structure which
      ;                   describes the key being imported
      ; EncryptedPrivateKey - the encrypted private key blob
      ; phCryptProv - a pointer to a HCRRYPTPROV to be filled in
      ; pVoidResolveFunc - this is the pVoidResolveFunc passed in by the caller in the
      ;                    CRYPT_PRIVATE_KEY_BLOB_AND_PARAMS struct
      ;+-------------------------------------------------------------------------
      TYPE_PCRYPT_RESOLVE_HCRYPTPROV_FUNC typedef proto WIN_STD_CALL_CONV :ptr CRYPT_PRIVATE_KEY_INFO, :ptr HCRYPTPROV, :LPVOID
      PCRYPT_RESOLVE_HCRYPTPROV_FUNC typedef ptr TYPE_PCRYPT_RESOLVE_HCRYPTPROV_FUNC

      ;+-------------------------------------------------------------------------
      ; this struct contains a PKCS8 private key and two pointers to callback
      ; functions, with a corresponding pVoids.  the first callback is used to give
      ; the caller the opportunity to specify where the key is imported to.  the callback
      ; passes the caller the algoroithm OID and key size to use in making the decision.
      ; the other callback is used to decrypt the private key if the PKCS8 contains an
      ; EncryptedPrivateKeyInfo.  both pVoids are preserved and passed back to the caller
      ; in the respective callback
      ;+-------------------------------------------------------------------------
      CRYPT_PKCS8_IMPORT_PARAMS struct
        PrivateKey CRYPT_DIGEST_BLOB <>
        ; PKCS8 blob
        pResolvehCryptProvFunc PCRYPT_RESOLVE_HCRYPTPROV_FUNC ?
        ; optional
        pVoidResolveFunc POINTER ?
        ; optional
        pDecryptPrivateKeyFunc PCRYPT_DECRYPT_PRIVATE_KEY_FUNC ?
        pVoidDecryptFunc POINTER ?
      CRYPT_PKCS8_IMPORT_PARAMS ends
      _CRYPT_PKCS8_IMPORT_PARAMS typedef CRYPT_PKCS8_IMPORT_PARAMS
      PCRYPT_PKCS8_IMPORT_PARAMS typedef ptr CRYPT_PKCS8_IMPORT_PARAMS
      CRYPT_PRIVATE_KEY_BLOB_AND_PARAMS typedef CRYPT_PKCS8_IMPORT_PARAMS
      PCRYPT_PRIVATE_KEY_BLOB_AND_PARAMS typedef ptr CRYPT_PKCS8_IMPORT_PARAMS
      ;+-------------------------------------------------------------------------
      ; this struct contains information identifying a private key and a pointer
      ; to a callback function, with a corresponding pVoid. The callback is used
      ; to encrypt the private key. If the pEncryptPrivateKeyFunc is NULL, the
      ; key will not be encrypted and an EncryptedPrivateKeyInfo will not be generated.
      ; The pVoid is preserved and passed back to the caller in the respective callback
      ;+-------------------------------------------------------------------------
      CRYPT_PKCS8_EXPORT_PARAMS struct
        hCryptProv HCRYPTPROV ?
        dwKeySpec DWORD ?
        pszPrivateKeyObjId POINTER ?
        pEncryptPrivateKeyFunc PCRYPT_ENCRYPT_PRIVATE_KEY_FUNC ?
        pVoidEncryptFunc POINTER ?
      CRYPT_PKCS8_EXPORT_PARAMS ends
      _CRYPT_PKCS8_EXPORT_PARAMS typedef CRYPT_PKCS8_EXPORT_PARAMS
      PCRYPT_PKCS8_EXPORT_PARAMS typedef ptr CRYPT_PKCS8_EXPORT_PARAMS
      ;+-------------------------------------------------------------------------
      ;  Information stored in a certificate
      ;  The Issuer, Subject, Algorithm, PublicKey and Extension BLOBs are the
      ;  encoded representation of the information.
      ;--------------------------------------------------------------------------
      ; certenrolls_begin -- CERT_CONTEXT
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
      ; certenrolls_end
      ;+-------------------------------------------------------------------------
      ;  Certificate versions
      ;--------------------------------------------------------------------------
      CERT_V1 equ 0
      CERT_V2 equ 1
      CERT_V3 equ 2
      ;+-------------------------------------------------------------------------
      ;  Certificate Information Flags
      ;--------------------------------------------------------------------------
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
      ;+-------------------------------------------------------------------------
      ;  An entry in a CRL
      ;  The Extension BLOBs are the encoded representation of the information.
      ;--------------------------------------------------------------------------
      CRL_ENTRY struct
        SerialNumber CRYPT_INTEGER_BLOB <>
        RevocationDate FILETIME <>
        cExtension DWORD ?
        rgExtension PCERT_EXTENSION ?
      CRL_ENTRY ends
      _CRL_ENTRY typedef CRL_ENTRY
      PCRL_ENTRY typedef ptr CRL_ENTRY
      ;+-------------------------------------------------------------------------
      ;  Information stored in a CRL
      ;  The Issuer, Algorithm and Extension BLOBs are the encoded
      ;  representation of the information.
      ;--------------------------------------------------------------------------
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
      ;+-------------------------------------------------------------------------
      ;  CRL versions
      ;--------------------------------------------------------------------------
      CRL_V1 equ 0
      CRL_V2 equ 1
      ;+-------------------------------------------------------------------------
      ; Certificate Bundle
      ;--------------------------------------------------------------------------
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
      ;+-------------------------------------------------------------------------
      ;  Information stored in a certificate request
      ;  The Subject, Algorithm, PublicKey and Attribute BLOBs are the encoded
      ;  representation of the information.
      ;--------------------------------------------------------------------------
      CERT_REQUEST_INFO struct
        dwVersion DWORD ?
        Subject CERT_NAME_BLOB <>
        SubjectPublicKeyInfo CERT_PUBLIC_KEY_INFO <>
        cAttribute DWORD ?
        rgAttribute PCRYPT_ATTRIBUTE ?
      CERT_REQUEST_INFO ends
      _CERT_REQUEST_INFO typedef CERT_REQUEST_INFO
      PCERT_REQUEST_INFO typedef ptr CERT_REQUEST_INFO
      ;+-------------------------------------------------------------------------
      ;  Certificate Request versions
      ;--------------------------------------------------------------------------
      CERT_REQUEST_V1 equ 0
      ;+-------------------------------------------------------------------------
      ;  Information stored in Netscape's Keygen request
      ;--------------------------------------------------------------------------
      CERT_KEYGEN_REQUEST_INFO struct
        dwVersion DWORD ?
        SubjectPublicKeyInfo CERT_PUBLIC_KEY_INFO <>
        pwszChallengeString POINTER ?
        ; encoded as IA5
      CERT_KEYGEN_REQUEST_INFO ends
      _CERT_KEYGEN_REQUEST_INFO typedef CERT_KEYGEN_REQUEST_INFO
      PCERT_KEYGEN_REQUEST_INFO typedef ptr CERT_KEYGEN_REQUEST_INFO
      CERT_KEYGEN_REQUEST_V1 equ 0
      ;+-------------------------------------------------------------------------
      ;  Certificate, CRL, Certificate Request or Keygen Request Signed Content
      ;  The "to be signed" encoded content plus its signature. The ToBeSigned
      ;  is the encoded CERT_INFO, CRL_INFO, CERT_REQUEST_INFO or
      ;  CERT_KEYGEN_REQUEST_INFO.
      ;--------------------------------------------------------------------------
      CERT_SIGNED_CONTENT_INFO struct
        ToBeSigned CRYPT_DER_BLOB <>
        SignatureAlgorithm CRYPT_ALGORITHM_IDENTIFIER <>
        Signature CRYPT_BIT_BLOB <>
      CERT_SIGNED_CONTENT_INFO ends
      _CERT_SIGNED_CONTENT_INFO typedef CERT_SIGNED_CONTENT_INFO
      PCERT_SIGNED_CONTENT_INFO typedef ptr CERT_SIGNED_CONTENT_INFO
      ;+-------------------------------------------------------------------------
      ;  Certificate Trust List (CTL)
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  CTL Usage. Also used for EnhancedKeyUsage extension.
      ;--------------------------------------------------------------------------
      CTL_USAGE struct
        cUsageIdentifier DWORD ?
        rgpszUsageIdentifier POINTER ?
        ; array of pszObjId
      CTL_USAGE ends
      _CTL_USAGE typedef CTL_USAGE
      PCTL_USAGE typedef ptr CTL_USAGE
      CERT_ENHKEY_USAGE typedef CTL_USAGE
      PCERT_ENHKEY_USAGE typedef ptr CTL_USAGE
      PCCTL_USAGE typedef ptr CTL_USAGE
      PCCERT_ENHKEY_USAGE typedef ptr CERT_ENHKEY_USAGE
      ;+-------------------------------------------------------------------------
      ;  An entry in a CTL
      ;--------------------------------------------------------------------------
      CTL_ENTRY struct
        SubjectIdentifier CRYPT_DATA_BLOB <>
        ; For example, its hash
        cAttribute DWORD ?
        rgAttribute PCRYPT_ATTRIBUTE ?
        ; OPTIONAL
      CTL_ENTRY ends
      _CTL_ENTRY typedef CTL_ENTRY
      PCTL_ENTRY typedef ptr CTL_ENTRY
      ;+-------------------------------------------------------------------------
      ;  Information stored in a CTL
      ;--------------------------------------------------------------------------
      CTL_INFO struct
        dwVersion DWORD ?
        SubjectUsage CTL_USAGE <>
        ListIdentifier CRYPT_DATA_BLOB <>
        ; OPTIONAL
        SequenceNumber CRYPT_INTEGER_BLOB <>
        ; OPTIONAL
        ThisUpdate FILETIME <>
        NextUpdate FILETIME <>
        ; OPTIONAL
        SubjectAlgorithm CRYPT_ALGORITHM_IDENTIFIER <>
        cCTLEntry DWORD ?
        rgCTLEntry PCTL_ENTRY ?
        ; OPTIONAL
        cExtension DWORD ?
        rgExtension PCERT_EXTENSION ?
        ; OPTIONAL
      CTL_INFO ends
      _CTL_INFO typedef CTL_INFO
      PCTL_INFO typedef ptr CTL_INFO
      ;+-------------------------------------------------------------------------
      ;  CTL versions
      ;--------------------------------------------------------------------------
      CTL_V1 equ 0
      ;+-------------------------------------------------------------------------
      ;  TimeStamp Request
      ;  The pszTimeStamp is the OID for the Time type requested
      ;  The pszContentType is the Content Type OID for the content, usually DATA
      ;  The Content is a un-decoded blob
      ;--------------------------------------------------------------------------
      CRYPT_TIME_STAMP_REQUEST_INFO struct
        pszTimeStampAlgorithm POINTER ?
        ; pszObjId
        pszContentType POINTER ?
        ; pszObjId
        Content CRYPT_OBJID_BLOB <>
        cAttribute DWORD ?
        rgAttribute PCRYPT_ATTRIBUTE ?
      CRYPT_TIME_STAMP_REQUEST_INFO ends
      _CRYPT_TIME_STAMP_REQUEST_INFO typedef CRYPT_TIME_STAMP_REQUEST_INFO
      PCRYPT_TIME_STAMP_REQUEST_INFO typedef ptr CRYPT_TIME_STAMP_REQUEST_INFO
      ;+-------------------------------------------------------------------------
      ;  Name Value Attribute
      ;--------------------------------------------------------------------------
      CRYPT_ENROLLMENT_NAME_VALUE_PAIR struct
        pwszName POINTER ?
        pwszValue POINTER ?
      CRYPT_ENROLLMENT_NAME_VALUE_PAIR ends
      _CRYPT_ENROLLMENT_NAME_VALUE_PAIR typedef CRYPT_ENROLLMENT_NAME_VALUE_PAIR
      PCRYPT_ENROLLMENT_NAME_VALUE_PAIR typedef ptr CRYPT_ENROLLMENT_NAME_VALUE_PAIR
      ;+-------------------------------------------------------------------------
      ;  CSP Provider
      ;--------------------------------------------------------------------------
      CRYPT_CSP_PROVIDER struct
        dwKeySpec DWORD ?
        pwszProviderName POINTER ?
        Signature CRYPT_BIT_BLOB <>
      CRYPT_CSP_PROVIDER ends
      _CRYPT_CSP_PROVIDER typedef CRYPT_CSP_PROVIDER
      PCRYPT_CSP_PROVIDER typedef ptr CRYPT_CSP_PROVIDER
      ;+-------------------------------------------------------------------------
      ;  Certificate and Message encoding types
      ;  The encoding type is a DWORD containing both the certificate and message
      ;  encoding types. The certificate encoding type is stored in the LOWORD.
      ;  The message encoding type is stored in the HIWORD. Some functions or
      ;  structure fields require only one of the encoding types. The following
      ;  naming convention is used to indicate which encoding type(s) are
      ;  required:
      ;      dwEncodingType              (both encoding types are required)
      ;      dwMsgAndCertEncodingType    (both encoding types are required)
      ;      dwMsgEncodingType           (only msg encoding type is required)
      ;      dwCertEncodingType          (only cert encoding type is required)
      ;  Its always acceptable to specify both.
      ;--------------------------------------------------------------------------
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
      ;+-------------------------------------------------------------------------
      ;  format the specified data structure according to the certificate
      ;  encoding type.
      ;  The default behavior of CryptFormatObject is to return single line
      ;  display of the encoded data, that is, each subfield will be concatenated with
      ;  a ", " on one line.  If user prefers to display the data in multiple line,
      ;  set the flag CRYPT_FORMAT_STR_MULTI_LINE, that is, each subfield will be displayed
      ;  on a seperate line.
      ;  If there is no formatting routine installed or registered
      ;  for the lpszStructType, the hex dump of the encoded BLOB will be returned.
      ;  User can set the flag CRYPT_FORMAT_STR_NO_HEX to disable the hex dump.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CryptFormatObject, WIN_STD_CALL_CONV,, <:DWORD, :DWORD, :DWORD, :ptr, :LPCSTR, :ptr BYTE, :DWORD, :ptr, :ptr DWORD>, 36
      ;-------------------------------------------------------------------------
      ; constants for dwFormatStrType of function CryptFormatObject
      ;-------------------------------------------------------------------------
      CRYPT_FORMAT_STR_MULTI_LINE equ 0001h
      CRYPT_FORMAT_STR_NO_HEX equ 0010h
      ;-------------------------------------------------------------------------
      ; constants for dwFormatType of function CryptFormatObject
      ; when format X509_NAME or X509_UNICODE_NAME
      ;-------------------------------------------------------------------------
      ; Just get the simple string
      CRYPT_FORMAT_SIMPLE equ 0001h
      ;Put an attribute name infront of the attribute
      ;such as "O=Microsoft,DN=xiaohs"
      CRYPT_FORMAT_X509 equ 0002h
      ;Put an OID infront of the simple string, such as
      ;"2.5.4.22=Microsoft,2.5.4.3=xiaohs"
      CRYPT_FORMAT_OID equ 0004h
      ;Put a ";" between each RDN.  The default is ","
      CRYPT_FORMAT_RDN_SEMICOLON equ 0100h
      ;Put a "\n" between each RDN.
      CRYPT_FORMAT_RDN_CRLF equ 0200h
      ;Unquote the DN value, which is quoated by default va the following
      ;rules: if the DN contains leading or trailing
      ;white space or one of the following characters: ",", "+", "=",
      ;""", "\n",  "<", ">", "#" or ";". The quoting character is ".
      ;If the DN Value contains a " it is double quoted ("").
      CRYPT_FORMAT_RDN_UNQUOTE equ 0400h
      ;reverse the order of the RDNs before converting to the string
      CRYPT_FORMAT_RDN_REVERSE equ 0800h
      ;-------------------------------------------------------------------------
      ;  contants dwFormatType of function CryptFormatObject when format a DN.:
      ;  The following three values are defined in the section above:
      ;  CRYPT_FORMAT_SIMPLE:    Just a simple string
      ;                          such as  "Microsoft+xiaohs+NT"
      ;  CRYPT_FORMAT_X509       Put an attribute name infront of the attribute
      ;                          such as "O=Microsoft+xiaohs+NT"
      ;  CRYPT_FORMAT_OID        Put an OID infront of the simple string,
      ;                          such as "2.5.4.22=Microsoft+xiaohs+NT"
      ;  Additional values are defined as following:
      ;----------------------------------------------------------------------------
      ;Put a "," between each value.  Default is "+"
      CRYPT_FORMAT_COMMA equ 1000h
      ;Put a ";" between each value
      CRYPT_FORMAT_SEMICOLON equ <CRYPT_FORMAT_RDN_SEMICOLON>
      ;Put a "\n" between each value
      CRYPT_FORMAT_CRLF equ <CRYPT_FORMAT_RDN_CRLF>
      ;+-------------------------------------------------------------------------
      ;  Encode / decode the specified data structure according to the certificate
      ;  encoding type.
      ;  See below for a list of the predefined data structures.
      ;--------------------------------------------------------------------------
      TYPE_PFN_CRYPT_ALLOC typedef proto WIN_STD_CALL_CONV :size_t
      PFN_CRYPT_ALLOC typedef ptr TYPE_PFN_CRYPT_ALLOC

      TYPE_PFN_CRYPT_FREE typedef proto WIN_STD_CALL_CONV :LPVOID
      PFN_CRYPT_FREE typedef ptr TYPE_PFN_CRYPT_FREE

      CRYPT_ENCODE_PARA struct
        cbSize DWORD ?
        pfnAlloc PFN_CRYPT_ALLOC ?
        ; OPTIONAL
        pfnFree PFN_CRYPT_FREE ?
        ; OPTIONAL
      CRYPT_ENCODE_PARA ends
      _CRYPT_ENCODE_PARA typedef CRYPT_ENCODE_PARA
      PCRYPT_ENCODE_PARA typedef ptr CRYPT_ENCODE_PARA
      @DefProto DllImport, CryptEncodeObjectEx, WIN_STD_CALL_CONV,, <:DWORD, :LPCSTR, :ptr, :DWORD, :PCRYPT_ENCODE_PARA, :ptr, :ptr DWORD>, 28
      @DefProto DllImport, CryptEncodeObject, WIN_STD_CALL_CONV,, <:DWORD, :LPCSTR, :ptr, :ptr BYTE, :ptr DWORD>, 20
      ; By default the signature bytes are reversed. The following flag can
      ; be set to inhibit the byte reversal.
      ; This flag is applicable to
      ;      X509_CERT_TO_BE_SIGNED
      CRYPT_ENCODE_NO_SIGNATURE_BYTE_REVERSAL_FLAG equ 8h
      ;  When the following flag is set the called encode function allocates
      ;  memory for the encoded bytes. A pointer to the allocated bytes
      ;  is returned in pvEncoded. If pEncodePara or pEncodePara->pfnAlloc is
      ;  NULL, then, LocalAlloc is called for the allocation and LocalFree must
      ;  be called to do the free. Otherwise, pEncodePara->pfnAlloc is called
      ;  for the allocation.
      ;  *pcbEncoded is ignored on input and updated with the length of the
      ;  allocated, encoded bytes.
      ;  If pfnAlloc is set, then, pfnFree should also be set.
      CRYPT_ENCODE_ALLOC_FLAG equ 8000h
      ;  The following flag is applicable when encoding X509_UNICODE_NAME.
      ;  When set, CERT_RDN_T61_STRING is selected instead of
      ;  CERT_RDN_UNICODE_STRING if all the unicode characters are <= 0xFF
      CRYPT_UNICODE_NAME_ENCODE_ENABLE_T61_UNICODE_FLAG equ <CERT_RDN_ENABLE_T61_UNICODE_FLAG>
      ;  The following flag is applicable when encoding X509_UNICODE_NAME.
      ;  When set, CERT_RDN_UTF8_STRING is selected instead of
      ;  CERT_RDN_UNICODE_STRING.
      CRYPT_UNICODE_NAME_ENCODE_ENABLE_UTF8_UNICODE_FLAG equ <CERT_RDN_ENABLE_UTF8_UNICODE_FLAG>
      ;  The following flag is applicable when encoding X509_UNICODE_NAME.
      ;  When set, CERT_RDN_UTF8_STRING is selected instead of
      ;  CERT_RDN_PRINTABLE_STRING for DirectoryString types. Also,
      ;  enables CRYPT_UNICODE_NAME_ENCODE_ENABLE_UTF8_UNICODE_FLAG.
      CRYPT_UNICODE_NAME_ENCODE_FORCE_UTF8_UNICODE_FLAG equ <CERT_RDN_FORCE_UTF8_UNICODE_FLAG>
      ;  The following flag is applicable when encoding X509_UNICODE_NAME,
      ;  X509_UNICODE_NAME_VALUE or X509_UNICODE_ANY_STRING.
      ;  When set, the characters aren't checked to see if they
      ;  are valid for the specified Value Type.
      CRYPT_UNICODE_NAME_ENCODE_DISABLE_CHECK_TYPE_FLAG equ <CERT_RDN_DISABLE_CHECK_TYPE_FLAG>
      ;  The following flag is applicable when encoding the PKCS_SORTED_CTL. This
      ;  flag should be set if the identifier for the TrustedSubjects is a hash,
      ;  such as, MD5 or SHA1.
      CRYPT_SORTED_CTL_ENCODE_HASHED_SUBJECT_IDENTIFIER_FLAG equ 10000h
      ; The following flag is applicable when encoding structures that require
      ; IA5String encoding of host name(in DNS Name/ URL/ EmailAddress) containing
      ; non-IA5 characters by encoding the host name in punycode first.
      CRYPT_ENCODE_ENABLE_PUNYCODE_FLAG equ 20000h
      ; The following flag is applicable when encoding structures that require
      ; IA5String encoding of a path (http URL/Ldap query) containing non-IA5
      ; characters by encoding the path part as UTF8 percent encoding.
      CRYPT_ENCODE_ENABLE_UTF8PERCENT_FLAG equ 40000h
      ; The following flag is applicable when encoding structures that require
      ; IA5String encoding of the host name (URL) and path. If the data to be encoded
      ; contains non-IA5 characters then using this flag in during encoding will cause
      ; the hostname to be punycode and the path as UTF8-percent encoding
      ; For example: http://www.zzzzzz.com/yyyyy/qqqqq/rrrrrr.sssss
      ; If zzzzzz contains non-IA5 characters then using this flag will punycode 
      ; encode the zzzzzz component.
      ; If yyyyy or qqqqq or rrrrrr or sssss contain non-IA5 characters then using 
      ; this flag will UTF8 percent encode those characters which are not IA5.
      CRYPT_ENCODE_ENABLE_IA5CONVERSION_FLAG equ <(CRYPT_ENCODE_ENABLE_PUNYCODE_FLAG or CRYPT_ENCODE_ENABLE_UTF8PERCENT_FLAG)>
      CRYPT_DECODE_PARA struct
        cbSize DWORD ?
        pfnAlloc PFN_CRYPT_ALLOC ?
        ; OPTIONAL
        pfnFree PFN_CRYPT_FREE ?
        ; OPTIONAL
      CRYPT_DECODE_PARA ends
      _CRYPT_DECODE_PARA typedef CRYPT_DECODE_PARA
      PCRYPT_DECODE_PARA typedef ptr CRYPT_DECODE_PARA
      @DefProto DllImport, CryptDecodeObjectEx, WIN_STD_CALL_CONV,, <:DWORD, :LPCSTR, :ptr BYTE, :DWORD, :DWORD, :PCRYPT_DECODE_PARA, :ptr, :ptr DWORD>, 32
      @DefProto DllImport, CryptDecodeObject, WIN_STD_CALL_CONV,, <:DWORD, :LPCSTR, :ptr BYTE, :DWORD, :DWORD, :ptr, :ptr DWORD>, 28
      ; When the following flag is set the nocopy optimization is enabled.
      ; This optimization where appropriate, updates the pvStructInfo fields
      ; to point to content residing within pbEncoded instead of making a copy
      ; of and appending to pvStructInfo.
      ; Note, when set, pbEncoded can't be freed until pvStructInfo is freed.
      CRYPT_DECODE_NOCOPY_FLAG equ 1h
      ; For CryptDecodeObject(), by default the pbEncoded is the "to be signed"
      ; plus its signature. Set the following flag, if pbEncoded points to only
      ; the "to be signed".
      ; This flag is applicable to
      ;      X509_CERT_TO_BE_SIGNED
      ;      X509_CERT_CRL_TO_BE_SIGNED
      ;      X509_CERT_REQUEST_TO_BE_SIGNED
      ;      X509_KEYGEN_REQUEST_TO_BE_SIGNED
      CRYPT_DECODE_TO_BE_SIGNED_FLAG equ 2h
      ; When the following flag is set, the OID strings are allocated in
      ; crypt32.dll and shared instead of being copied into the returned
      ; data structure. This flag may be set if crypt32.dll isn't unloaded
      ; before the caller is unloaded.
      CRYPT_DECODE_SHARE_OID_STRING_FLAG equ 4h
      ; By default the signature bytes are reversed. The following flag can
      ; be set to inhibit the byte reversal.
      ; This flag is applicable to
      ;      X509_CERT_TO_BE_SIGNED
      CRYPT_DECODE_NO_SIGNATURE_BYTE_REVERSAL_FLAG equ 8h
      ; When the following flag is set the called decode function allocates
      ; memory for the decoded structure. A pointer to the allocated structure
      ; is returned in pvStructInfo. If pDecodePara or pDecodePara->pfnAlloc is
      ; NULL, then, LocalAlloc is called for the allocation and LocalFree must
      ; be called to do the free. Otherwise, pDecodePara->pfnAlloc is called
      ; for the allocation.
      ; *pcbStructInfo is ignored on input and updated with the length of the
      ; allocated, decoded structure.
      ; This flag may also be set in the CryptDecodeObject API. Since
      ; CryptDecodeObject doesn't take a pDecodePara, LocalAlloc is always
      ; called for the allocation which must be freed by calling LocalFree.
      CRYPT_DECODE_ALLOC_FLAG equ 8000h
      ; The following flag is applicable when decoding X509_UNICODE_NAME,
      ; X509_UNICODE_NAME_VALUE or X509_UNICODE_ANY_STRING.
      ; By default, CERT_RDN_T61_STRING values are initially decoded
      ; as UTF8. If the UTF8 decoding fails, then, decoded as 8 bit characters.
      ; Setting this flag skips the initial attempt to decode as UTF8.
      CRYPT_UNICODE_NAME_DECODE_DISABLE_IE4_UTF8_FLAG equ <CERT_RDN_DISABLE_IE4_UTF8_FLAG>
      ; The following flag is applicable when decoding structures that contain
      ; IA5String encoding of punycode encoded host name (in DNS Name/ URL/
      ; EmailAddress). Decoded value contains the the unicode equivalent of
      ; punycode encoded data.
      CRYPT_DECODE_ENABLE_PUNYCODE_FLAG equ 02000000h
      ; The following flag is applicable when decoding structures that contain
      ; IA5String that is UTF8 percent encoded in the path part of a url.
      CRYPT_DECODE_ENABLE_UTF8PERCENT_FLAG equ 04000000h
      ; The following flag is applicable when decoding structures that contain
      ; an IA5String that is a punycode and UTF8-percent encoded host name and path (URL). The decoded
      ; value contains the Unicode equivalent of the punycode encoded host name and UTF8 percent 
      ; encoded path.
      CRYPT_DECODE_ENABLE_IA5CONVERSION_FLAG equ <(CRYPT_DECODE_ENABLE_PUNYCODE_FLAG or CRYPT_DECODE_ENABLE_UTF8PERCENT_FLAG)>
      ;+-------------------------------------------------------------------------
      ;  Predefined X509 certificate data structures that can be encoded / decoded.
      ;--------------------------------------------------------------------------
      CRYPT_ENCODE_DECODE_NONE equ 0
      X509_CERT equ (1)
      X509_CERT_TO_BE_SIGNED equ (2)
      X509_CERT_CRL_TO_BE_SIGNED equ (3)
      X509_CERT_REQUEST_TO_BE_SIGNED equ (4)
      X509_EXTENSIONS equ (5)
      X509_NAME_VALUE equ (6)
      X509_NAME equ (7)
      X509_PUBLIC_KEY_INFO equ (8)
      ;+-------------------------------------------------------------------------
      ;  Predefined X509 certificate extension data structures that can be
      ;  encoded / decoded.
      ;--------------------------------------------------------------------------
      X509_AUTHORITY_KEY_ID equ (9)
      X509_KEY_ATTRIBUTES equ (10)
      X509_KEY_USAGE_RESTRICTION equ (11)
      X509_ALTERNATE_NAME equ (12)
      X509_BASIC_CONSTRAINTS equ (13)
      X509_KEY_USAGE equ (14)
      X509_BASIC_CONSTRAINTS2 equ (15)
      X509_CERT_POLICIES equ (16)
      ;+-------------------------------------------------------------------------
      ;  Additional predefined data structures that can be encoded / decoded.
      ;--------------------------------------------------------------------------
      PKCS_UTC_TIME equ (17)
      PKCS_TIME_REQUEST equ (18)
      RSA_CSP_PUBLICKEYBLOB equ (19)
      X509_UNICODE_NAME equ (20)
      X509_KEYGEN_REQUEST_TO_BE_SIGNED equ (21)
      PKCS_ATTRIBUTE equ (22)
      PKCS_CONTENT_INFO_SEQUENCE_OF_ANY equ (23)
      ;+-------------------------------------------------------------------------
      ;  Predefined primitive data structures that can be encoded / decoded.
      ;--------------------------------------------------------------------------
      X509_UNICODE_NAME_VALUE equ (24)
      X509_ANY_STRING equ <X509_NAME_VALUE>
      X509_UNICODE_ANY_STRING equ <X509_UNICODE_NAME_VALUE>
      X509_OCTET_STRING equ (25)
      X509_BITS equ (26)
      X509_INTEGER equ (27)
      X509_MULTI_BYTE_INTEGER equ (28)
      X509_ENUMERATED equ (29)
      X509_CHOICE_OF_TIME equ (30)
      ;+-------------------------------------------------------------------------
      ;  More predefined X509 certificate extension data structures that can be
      ;  encoded / decoded.
      ;--------------------------------------------------------------------------
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
      ; Qualified Certificate Statements Extension uses the same encode/decode
      ; function as PKCS_SMIME_CAPABILITIES. Its data structures are identical
      ; except for the names of the fields.
      X509_QC_STATEMENTS_EXT equ (42)
      ;+-------------------------------------------------------------------------
      ;  data structures for private keys
      ;--------------------------------------------------------------------------
      PKCS_RSA_PRIVATE_KEY equ (43)
      PKCS_PRIVATE_KEY_INFO equ (44)
      PKCS_ENCRYPTED_PRIVATE_KEY_INFO equ (45)
      ;+-------------------------------------------------------------------------
      ;  certificate policy qualifier
      ;--------------------------------------------------------------------------
      X509_PKIX_POLICY_QUALIFIER_USERNOTICE equ (46)
      ;+-------------------------------------------------------------------------
      ;  Diffie-Hellman Key Exchange
      ;--------------------------------------------------------------------------
      X509_DH_PUBLICKEY equ <X509_MULTI_BYTE_UINT>
      X509_DH_PARAMETERS equ (47)
      PKCS_ATTRIBUTES equ (48)
      PKCS_SORTED_CTL equ (49)
      ;+-------------------------------------------------------------------------
      ;  ECC Signature
      ;--------------------------------------------------------------------------
      ; Uses the same encode/decode function as X509_DH_PARAMETERS. Its data
      ; structure is identical except for the names of the fields.
      X509_ECC_SIGNATURE equ (47)
      ;+-------------------------------------------------------------------------
      ;  X942 Diffie-Hellman
      ;--------------------------------------------------------------------------
      X942_DH_PARAMETERS equ (50)
      ;+-------------------------------------------------------------------------
      ;  The following is the same as X509_BITS, except before encoding,
      ;  the bit length is decremented to exclude trailing zero bits.
      ;--------------------------------------------------------------------------
      X509_BITS_WITHOUT_TRAILING_ZEROES equ (51)
      ;+-------------------------------------------------------------------------
      ;  X942 Diffie-Hellman Other Info
      ;--------------------------------------------------------------------------
      X942_OTHER_INFO equ (52)
      X509_CERT_PAIR equ (53)
      X509_ISSUING_DIST_POINT equ (54)
      X509_NAME_CONSTRAINTS equ (55)
      X509_POLICY_MAPPINGS equ (56)
      X509_POLICY_CONSTRAINTS equ (57)
      X509_CROSS_CERT_DIST_POINTS equ (58)
      ;+-------------------------------------------------------------------------
      ;  Certificate Management Messages over CMS (CMC) Data Structures
      ;--------------------------------------------------------------------------
      CMC_DATA equ (59)
      CMC_RESPONSE equ (60)
      CMC_STATUS equ (61)
      CMC_ADD_EXTENSIONS equ (62)
      CMC_ADD_ATTRIBUTES equ (63)
      ;+-------------------------------------------------------------------------
      ;  Certificate Template
      ;--------------------------------------------------------------------------
      X509_CERTIFICATE_TEMPLATE equ (64)
      ;+-------------------------------------------------------------------------
      ;  Online Certificate Status Protocol (OCSP) Data Structures
      ;--------------------------------------------------------------------------
      OCSP_SIGNED_REQUEST equ (65)
      OCSP_REQUEST equ (66)
      OCSP_RESPONSE equ (67)
      OCSP_BASIC_SIGNED_RESPONSE equ (68)
      OCSP_BASIC_RESPONSE equ (69)
      ;+-------------------------------------------------------------------------
      ;  Logotype and Biometric Extensions
      ;--------------------------------------------------------------------------
      X509_LOGOTYPE_EXT equ (70)
      X509_BIOMETRIC_EXT equ (71)
      CNG_RSA_PUBLIC_KEY_BLOB equ (72)
      X509_OBJECT_IDENTIFIER equ (73)
      X509_ALGORITHM_IDENTIFIER equ (74)
      PKCS_RSA_SSA_PSS_PARAMETERS equ (75)
      PKCS_RSAES_OAEP_PARAMETERS equ (76)
      ECC_CMS_SHARED_INFO equ (77)
      ;+-------------------------------------------------------------------------
      ;  TIMESTAMP
      ;--------------------------------------------------------------------------
      TIMESTAMP_REQUEST equ (78)
      TIMESTAMP_RESPONSE equ (79)
      TIMESTAMP_INFO equ (80)
      ;+-------------------------------------------------------------------------
      ;  CertificateBundle
      ;--------------------------------------------------------------------------
      X509_CERT_BUNDLE equ (81)
      ;+-------------------------------------------------------------------------
      ;  ECC Keys
      ;--------------------------------------------------------------------------
      X509_ECC_PRIVATE_KEY equ (82); CRYPT_ECC_PRIVATE_KEY_INFO

      CNG_RSA_PRIVATE_KEY_BLOB equ (83); BCRYPT_RSAKEY_BLOB

      ;+-------------------------------------------------------------------------
      ;  Subject Directory Attributes extension
      ;--------------------------------------------------------------------------
      X509_SUBJECT_DIR_ATTRS equ (84)
      ;+-------------------------------------------------------------------------
      ;  Generic ECC Parameters
      ;--------------------------------------------------------------------------
      X509_ECC_PARAMETERS equ (85)
      ;+-------------------------------------------------------------------------
      ;  Predefined PKCS #7 data structures that can be encoded / decoded.
      ;--------------------------------------------------------------------------
      PKCS7_SIGNER_INFO equ (500)
      ;+-------------------------------------------------------------------------
      ;  Predefined PKCS #7 data structures that can be encoded / decoded.
      ;--------------------------------------------------------------------------
      CMS_SIGNER_INFO equ (501)
      ;+-------------------------------------------------------------------------
      ;  Predefined Software Publishing Credential (SPC)  data structures that
      ;  can be encoded / decoded.
      ;  Predefined values: 2000 .. 2999
      ;  See spc.h for value and data structure definitions.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  Extension Object Identifiers
      ;--------------------------------------------------------------------------
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
      ; szOID_CRL_NUMBER -- Base CRLs only.  Monotonically increasing sequence
      ; number for each CRL issued by a CA.
      szOID_CRL_NUMBER equ <"2.5.29.20">
      ; szOID_DELTA_CRL_INDICATOR -- Delta CRLs only.  Marked critical.
      ; Contains the minimum base CRL Number that can be used with a delta CRL.
      szOID_DELTA_CRL_INDICATOR equ <"2.5.29.27">
      szOID_ISSUING_DIST_POINT equ <"2.5.29.28">
      ; szOID_FRESHEST_CRL -- Base CRLs only.  Formatted identically to a CDP
      ; extension that holds URLs to fetch the delta CRL.
      szOID_FRESHEST_CRL equ <"2.5.29.46">
      szOID_NAME_CONSTRAINTS equ <"2.5.29.30">
      ; Note on 1/1/2000 szOID_POLICY_MAPPINGS was changed from "2.5.29.5"
      szOID_POLICY_MAPPINGS equ <"2.5.29.33">
      szOID_LEGACY_POLICY_MAPPINGS equ <"2.5.29.5">
      szOID_POLICY_CONSTRAINTS equ <"2.5.29.36">
      ; Microsoft PKCS10 Attributes
      szOID_RENEWAL_CERTIFICATE equ <"1.3.6.1.4.1.311.13.1">
      szOID_ENROLLMENT_NAME_VALUE_PAIR equ <"1.3.6.1.4.1.311.13.2.1">
      szOID_ENROLLMENT_CSP_PROVIDER equ <"1.3.6.1.4.1.311.13.2.2">
      szOID_OS_VERSION equ <"1.3.6.1.4.1.311.13.2.3">
      ; Extension contain certificate type
      szOID_ENROLLMENT_AGENT equ <"1.3.6.1.4.1.311.20.2.1">
      ; Internet Public Key Infrastructure (PKIX)
      szOID_PKIX equ <"1.3.6.1.5.5.7">
      szOID_PKIX_PE equ <"1.3.6.1.5.5.7.1">
      szOID_AUTHORITY_INFO_ACCESS equ <"1.3.6.1.5.5.7.1.1">
      szOID_SUBJECT_INFO_ACCESS equ <"1.3.6.1.5.5.7.1.11">
      szOID_BIOMETRIC_EXT equ <"1.3.6.1.5.5.7.1.2">
      szOID_QC_STATEMENTS_EXT equ <"1.3.6.1.5.5.7.1.3">
      szOID_LOGOTYPE_EXT equ <"1.3.6.1.5.5.7.1.12">
      ; Following is encoded as a SEQUENCE OF INTEGER.
      ; For OCSP Must-Staple, one of the integers will be set to 5
      ; which corresponds to the OCSP status_request TLS extension,
      ; See RFC 7633 for more details.
      szOID_TLS_FEATURES_EXT equ <"1.3.6.1.5.5.7.1.24">
      ; Microsoft extensions or attributes
      szOID_CERT_EXTENSIONS equ <"1.3.6.1.4.1.311.2.1.14">
      szOID_NEXT_UPDATE_LOCATION equ <"1.3.6.1.4.1.311.10.2">
      szOID_REMOVE_CERTIFICATE equ <"1.3.6.1.4.1.311.10.8.1">
      szOID_CROSS_CERT_DIST_POINTS equ <"1.3.6.1.4.1.311.10.9.1">
      ;  Microsoft PKCS #7 ContentType Object Identifiers
      szOID_CTL equ <"1.3.6.1.4.1.311.10.1">
      ;  Microsoft Sorted CTL Extension Object Identifier
      szOID_SORTED_CTL equ <"1.3.6.1.4.1.311.10.1.1">
      ; serialized serial numbers for PRS
      ifndef szOID_SERIALIZED
        szOID_SERIALIZED equ <"1.3.6.1.4.1.311.10.3.3.1">
      endif
      ; UPN principal name in SubjectAltName
      ifndef szOID_NT_PRINCIPAL_NAME
        szOID_NT_PRINCIPAL_NAME equ <"1.3.6.1.4.1.311.20.2.3">
      endif
      ; Internationalized Email Address in SubjectAltName (OtherName:UTF8)
      ifndef szOID_INTERNATIONALIZED_EMAIL_ADDRESS
        szOID_INTERNATIONALIZED_EMAIL_ADDRESS equ <"1.3.6.1.4.1.311.20.2.4">
      endif
      ; Windows product update unauthenticated attribute
      ifndef szOID_PRODUCT_UPDATE
        szOID_PRODUCT_UPDATE equ <"1.3.6.1.4.1.311.31.1">
      endif
      ; CryptUI
      szOID_ANY_APPLICATION_POLICY equ <"1.3.6.1.4.1.311.10.12.1">
      ;+-------------------------------------------------------------------------
      ;  Object Identifiers for use with Auto Enrollment
      ;--------------------------------------------------------------------------
      szOID_AUTO_ENROLL_CTL_USAGE equ <"1.3.6.1.4.1.311.20.1">
      ; Extension contain certificate type
      ; AKA Certificate template extension (v1)
      szOID_ENROLL_CERTTYPE_EXTENSION equ <"1.3.6.1.4.1.311.20.2">
      szOID_CERT_MANIFOLD equ <"1.3.6.1.4.1.311.20.3">
      ;+-------------------------------------------------------------------------
      ;  Object Identifiers for use with the MS Certificate Server
      ;--------------------------------------------------------------------------
      ifndef szOID_CERTSRV_CA_VERSION
        szOID_CERTSRV_CA_VERSION equ <"1.3.6.1.4.1.311.21.1">
      endif
      ; szOID_CERTSRV_PREVIOUS_CERT_HASH -- Contains the sha1 hash of the previous
      ; version of the CA certificate.
      szOID_CERTSRV_PREVIOUS_CERT_HASH equ <"1.3.6.1.4.1.311.21.2">
      ; szOID_CRL_VIRTUAL_BASE -- Delta CRLs only.  Contains the base CRL Number
      ; of the corresponding base CRL.
      szOID_CRL_VIRTUAL_BASE equ <"1.3.6.1.4.1.311.21.3">
      ; szOID_CRL_NEXT_PUBLISH -- Contains the time when the next CRL is expected
      ; to be published.  This may be sooner than the CRL's NextUpdate field.
      szOID_CRL_NEXT_PUBLISH equ <"1.3.6.1.4.1.311.21.4">
      ; Enhanced Key Usage for CA encryption certificate
      szOID_KP_CA_EXCHANGE equ <"1.3.6.1.4.1.311.21.5">
      ; Enhanced Key Usage for Privacy CA encryption certificate
      szOID_KP_PRIVACY_CA equ <"1.3.6.1.4.1.311.21.36">
      ; Enhanced Key Usage for key recovery agent certificate
      szOID_KP_KEY_RECOVERY_AGENT equ <"1.3.6.1.4.1.311.21.6">
      ; Certificate template extension (v2)
      szOID_CERTIFICATE_TEMPLATE equ <"1.3.6.1.4.1.311.21.7">
      ; The root oid for all enterprise specific oids
      szOID_ENTERPRISE_OID_ROOT equ <"1.3.6.1.4.1.311.21.8">
      ; Dummy signing Subject RDN
      szOID_RDN_DUMMY_SIGNER equ <"1.3.6.1.4.1.311.21.9">
      ; Application Policies extension -- same encoding as szOID_CERT_POLICIES
      szOID_APPLICATION_CERT_POLICIES equ <"1.3.6.1.4.1.311.21.10">
      ; Application Policy Mappings -- same encoding as szOID_POLICY_MAPPINGS
      szOID_APPLICATION_POLICY_MAPPINGS equ <"1.3.6.1.4.1.311.21.11">
      ; Application Policy Constraints -- same encoding as szOID_POLICY_CONSTRAINTS
      szOID_APPLICATION_POLICY_CONSTRAINTS equ <"1.3.6.1.4.1.311.21.12">
      szOID_ARCHIVED_KEY_ATTR equ <"1.3.6.1.4.1.311.21.13">
      szOID_CRL_SELF_CDP equ <"1.3.6.1.4.1.311.21.14">
      ; Requires all certificates below the root to have a non-empty intersecting
      ; issuance certificate policy usage.
      szOID_REQUIRE_CERT_CHAIN_POLICY equ <"1.3.6.1.4.1.311.21.15">
      szOID_ARCHIVED_KEY_CERT_HASH equ <"1.3.6.1.4.1.311.21.16">
      szOID_ISSUED_CERT_HASH equ <"1.3.6.1.4.1.311.21.17">
      ; Enhanced key usage for DS email replication
      szOID_DS_EMAIL_REPLICATION equ <"1.3.6.1.4.1.311.21.19">
      szOID_REQUEST_CLIENT_INFO equ <"1.3.6.1.4.1.311.21.20">
      szOID_ENCRYPTED_KEY_HASH equ <"1.3.6.1.4.1.311.21.21">
      szOID_CERTSRV_CROSSCA_VERSION equ <"1.3.6.1.4.1.311.21.22">
      ;+-------------------------------------------------------------------------
      ;  Object Identifiers for use with the MS Directory Service
      ;--------------------------------------------------------------------------
      szOID_NTDS_REPLICATION equ <"1.3.6.1.4.1.311.25.1">
      szOID_NTDS_CA_SECURITY_EXT equ <"1.3.6.1.4.1.311.25.2">; OID arc for Microsoft CA custom security extension

      szOID_NTDS_OBJECTSID equ <"1.3.6.1.4.1.311.25.2.1">; OID for objectSid info

      ;+-------------------------------------------------------------------------
      ;  URI Prefixes for use with the MS Directory Service
      ;--------------------------------------------------------------------------
      wszURI_NTDS_OBJECTSID_PREFIX equ <L("tag:microsoft.com,2022-09-14:sid:")>; URI for objectSid info in the SAN, to be followed by a string SID

      ;+-------------------------------------------------------------------------
      ;  Extension Object Identifiers
      ;--------------------------------------------------------------------------
      szOID_SUBJECT_DIR_ATTRS equ <"2.5.29.9">
      ;+-------------------------------------------------------------------------
      ;  Enhanced Key Usage (Purpose) Object Identifiers
      ;--------------------------------------------------------------------------
      szOID_PKIX_KP equ <"1.3.6.1.5.5.7.3">
      ; Consistent key usage bits: DIGITAL_SIGNATURE, KEY_ENCIPHERMENT
      ; or KEY_AGREEMENT
      szOID_PKIX_KP_SERVER_AUTH equ <"1.3.6.1.5.5.7.3.1">
      ; Consistent key usage bits: DIGITAL_SIGNATURE
      szOID_PKIX_KP_CLIENT_AUTH equ <"1.3.6.1.5.5.7.3.2">
      ; Consistent key usage bits: DIGITAL_SIGNATURE
      szOID_PKIX_KP_CODE_SIGNING equ <"1.3.6.1.5.5.7.3.3">
      ; Consistent key usage bits: DIGITAL_SIGNATURE, NON_REPUDIATION and/or
      ; (KEY_ENCIPHERMENT or KEY_AGREEMENT)
      szOID_PKIX_KP_EMAIL_PROTECTION equ <"1.3.6.1.5.5.7.3.4">
      ; Consistent key usage bits: DIGITAL_SIGNATURE and/or
      ; (KEY_ENCIPHERMENT or KEY_AGREEMENT)
      szOID_PKIX_KP_IPSEC_END_SYSTEM equ <"1.3.6.1.5.5.7.3.5">
      ; Consistent key usage bits: DIGITAL_SIGNATURE and/or
      ; (KEY_ENCIPHERMENT or KEY_AGREEMENT)
      szOID_PKIX_KP_IPSEC_TUNNEL equ <"1.3.6.1.5.5.7.3.6">
      ; Consistent key usage bits: DIGITAL_SIGNATURE and/or
      ; (KEY_ENCIPHERMENT or KEY_AGREEMENT)
      szOID_PKIX_KP_IPSEC_USER equ <"1.3.6.1.5.5.7.3.7">
      ; Consistent key usage bits: DIGITAL_SIGNATURE or NON_REPUDIATION
      szOID_PKIX_KP_TIMESTAMP_SIGNING equ <"1.3.6.1.5.5.7.3.8">
      ; OCSP response signer
      szOID_PKIX_KP_OCSP_SIGNING equ <"1.3.6.1.5.5.7.3.9">
      ; Following extension is present to indicate no revocation checking
      ; for the OCSP signer certificate
      szOID_PKIX_OCSP_NOCHECK equ <"1.3.6.1.5.5.7.48.1.5">
      ; OCSP Nonce
      szOID_PKIX_OCSP_NONCE equ <"1.3.6.1.5.5.7.48.1.2">
      ; IKE (Internet Key Exchange) Intermediate KP for an IPsec end entity.
      ; Defined in draft-ietf-ipsec-pki-req-04.txt, December 14, 1999.
      szOID_IPSEC_KP_IKE_INTERMEDIATE equ <"1.3.6.1.5.5.8.2.2">
      ; iso (1) org (3) dod (6) internet (1) security (5) kerberosv5 (2) pkinit (3) 5
      szOID_PKINIT_KP_KDC equ <"1.3.6.1.5.2.3.5">
      ;+-------------------------------------------------------------------------
      ;  Microsoft Enhanced Key Usage (Purpose) Object Identifiers
      ;+-------------------------------------------------------------------------
      ;  Signer of CTLs
      szOID_KP_CTL_USAGE_SIGNING equ <"1.3.6.1.4.1.311.10.3.1">
      ;  Signer of TimeStamps
      szOID_KP_TIME_STAMP_SIGNING equ <"1.3.6.1.4.1.311.10.3.2">
      ifndef szOID_SERVER_GATED_CRYPTO
        szOID_SERVER_GATED_CRYPTO equ <"1.3.6.1.4.1.311.10.3.3">
      endif
      ifndef szOID_SGC_NETSCAPE
        szOID_SGC_NETSCAPE equ <"2.16.840.1.113730.4.1">
      endif
      szOID_KP_EFS equ <"1.3.6.1.4.1.311.10.3.4">
      szOID_EFS_RECOVERY equ <"1.3.6.1.4.1.311.10.3.4.1">
      ; Signed by Microsoft through hardware certification (WHQL)
      szOID_WHQL_CRYPTO equ <"1.3.6.1.4.1.311.10.3.5">
      ; Signed by Microsoft after the developer attests it is valid (Attested WHQL)
      szOID_ATTEST_WHQL_CRYPTO equ <"1.3.6.1.4.1.311.10.3.5.1">
      ; Signed by the NT5 build lab
      szOID_NT5_CRYPTO equ <"1.3.6.1.4.1.311.10.3.6">
      ; Signed by and OEM of WHQL
      szOID_OEM_WHQL_CRYPTO equ <"1.3.6.1.4.1.311.10.3.7">
      ; Signed by the Embedded NT
      szOID_EMBEDDED_NT_CRYPTO equ <"1.3.6.1.4.1.311.10.3.8">
      ; Signer of a CTL containing trusted roots
      szOID_ROOT_LIST_SIGNER equ <"1.3.6.1.4.1.311.10.3.9">
      ; Can sign cross-cert and subordinate CA requests with qualified
      ; subordination (name constraints, policy mapping, etc.)
      szOID_KP_QUALIFIED_SUBORDINATION equ <"1.3.6.1.4.1.311.10.3.10">
      ; Can be used to encrypt/recover escrowed keys
      szOID_KP_KEY_RECOVERY equ <"1.3.6.1.4.1.311.10.3.11">
      ; Signer of documents
      szOID_KP_DOCUMENT_SIGNING equ <"1.3.6.1.4.1.311.10.3.12">
      ; The default WinVerifyTrust Authenticode policy is to treat all time stamped
      ; signatures as being valid forever. This OID limits the valid lifetime of the
      ; signature to the lifetime of the certificate. This allows timestamped
      ; signatures to expire. Normally this OID will be used in conjunction with
      ; szOID_PKIX_KP_CODE_SIGNING to indicate new time stamp semantics should be
      ; used. Support for this OID was added in WXP.
      szOID_KP_LIFETIME_SIGNING equ <"1.3.6.1.4.1.311.10.3.13">
      szOID_KP_MOBILE_DEVICE_SOFTWARE equ <"1.3.6.1.4.1.311.10.3.14">
      szOID_KP_SMART_DISPLAY equ <"1.3.6.1.4.1.311.10.3.15">
      szOID_KP_CSP_SIGNATURE equ <"1.3.6.1.4.1.311.10.3.16">
      szOID_KP_FLIGHT_SIGNING equ <"1.3.6.1.4.1.311.10.3.27">
      szOID_PLATFORM_MANIFEST_BINARY_ID equ <"1.3.6.1.4.1.311.10.3.28">
      ifndef szOID_DRM
        szOID_DRM equ <"1.3.6.1.4.1.311.10.5.1">
      endif
      ; Microsoft DRM EKU
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
      ; Signer of CRL
      szOID_REVOKED_LIST_SIGNER equ <"1.3.6.1.4.1.311.10.3.19">
      ; Signer of Kits-built code
      szOID_WINDOWS_KITS_SIGNER equ <"1.3.6.1.4.1.311.10.3.20">
      ; Signer of Windows RT code
      szOID_WINDOWS_RT_SIGNER equ <"1.3.6.1.4.1.311.10.3.21">
      ; Signer of Protected Process Light code
      szOID_PROTECTED_PROCESS_LIGHT_SIGNER equ <"1.3.6.1.4.1.311.10.3.22">
      ; Signer of Windows TCB code
      szOID_WINDOWS_TCB_SIGNER equ <"1.3.6.1.4.1.311.10.3.23">
      ; Signer of Protected Process code
      szOID_PROTECTED_PROCESS_SIGNER equ <"1.3.6.1.4.1.311.10.3.24">
      ; Signer of third-party components that are Windows in box
      szOID_WINDOWS_THIRD_PARTY_COMPONENT_SIGNER equ <"1.3.6.1.4.1.311.10.3.25">
      ; Signed by the Windows Software Portal
      szOID_WINDOWS_SOFTWARE_EXTENSION_SIGNER equ <"1.3.6.1.4.1.311.10.3.26">
      ; CTL containing disallowed entries
      szOID_DISALLOWED_LIST equ <"1.3.6.1.4.1.311.10.3.30">
      ; Signer of a CTL containing Pin Rules.
      ; The szOID_ROOT_LIST_SIGNER OID can also be used
      szOID_PIN_RULES_SIGNER equ <"1.3.6.1.4.1.311.10.3.31">
      ; CTL containing Site Pin Rules
      szOID_PIN_RULES_CTL equ <"1.3.6.1.4.1.311.10.3.32">
      ; Pin Rules CTL extension
      szOID_PIN_RULES_EXT equ <"1.3.6.1.4.1.311.10.3.33">
      ; SubjectAlgorithm for Pin Rules CTL entries
      szOID_PIN_RULES_DOMAIN_NAME equ <"1.3.6.1.4.1.311.10.3.34">
      ; Pin Rules Log End Date CTL extension
      szOID_PIN_RULES_LOG_END_DATE_EXT equ <"1.3.6.1.4.1.311.10.3.35">
      ; Image can be executed in Isolated User Mode (IUM)
      szOID_IUM_SIGNING equ <"1.3.6.1.4.1.311.10.3.37">
      ; Signed by Microsoft through EV hardware certification (EV WHQL)
      szOID_EV_WHQL_CRYPTO equ <"1.3.6.1.4.1.311.10.3.39">
      ; Signer of Biometric code
      szOID_BIOMETRIC_SIGNING equ <"1.3.6.1.4.1.311.10.3.41">
      ; Image can be executed in a VSM Enclave
      szOID_ENCLAVE_SIGNING equ <"1.3.6.1.4.1.311.10.3.42">
      ; The following extension is set in the disallowed CTL to trigger
      ; a quicker sync of the autorootupdate CTL
      szOID_SYNC_ROOT_CTL_EXT equ <"1.3.6.1.4.1.311.10.3.50">
      ; CTL containing HPKP Domain Names
      szOID_HPKP_DOMAIN_NAME_CTL equ <"1.3.6.1.4.1.311.10.3.60">
      ; SubjectAlgorithm for HPKP Domain CTL entries: szOID_PIN_RULES_DOMAIN_NAME
      ; CTL containing HPKP Header Values. Stored as an extension in the
      ; Hpkp Domain Name CTL. This OID is also used to identify
      ; the extension.
      szOID_HPKP_HEADER_VALUE_CTL equ <"1.3.6.1.4.1.311.10.3.61">
      ; SubjectAlgorithm for HPKP Header Value CTL entries: szOID_NIST_sha256
      ; Only the first 16 bytes of the SHA256 hash are used
      ; HAL Extensions
      szOID_KP_KERNEL_MODE_HAL_EXTENSION_SIGNING equ <"1.3.6.1.4.1.311.61.5.1">
      ; Signer of Windows Store applications
      szOID_WINDOWS_STORE_SIGNER equ <"1.3.6.1.4.1.311.76.3.1">
      ; Signer of dynamic code generators
      szOID_DYNAMIC_CODE_GEN_SIGNER equ <"1.3.6.1.4.1.311.76.5.1">
      ; Signer of Microsoft code
      szOID_MICROSOFT_PUBLISHER_SIGNER equ <"1.3.6.1.4.1.311.76.8.1">
      ;+-------------------------------------------------------------------------
      ;  Microsoft Attribute Object Identifiers
      ;+-------------------------------------------------------------------------
      szOID_YESNO_TRUST_ATTR equ <"1.3.6.1.4.1.311.10.4.1">
      szOID_SITE_PIN_RULES_INDEX_ATTR equ <"1.3.6.1.4.1.311.10.4.2">
      szOID_SITE_PIN_RULES_FLAGS_ATTR equ <"1.3.6.1.4.1.311.10.4.3">
      SITE_PIN_RULES_ALL_SUBDOMAINS_FLAG equ 1h
      ;+-------------------------------------------------------------------------
      ;  Qualifiers that may be part of the szOID_CERT_POLICIES and
      ;  szOID_CERT_POLICIES95 extensions
      ;+-------------------------------------------------------------------------
      szOID_PKIX_POLICY_QUALIFIER_CPS equ <"1.3.6.1.5.5.7.2.1">
      szOID_PKIX_POLICY_QUALIFIER_USERNOTICE equ <"1.3.6.1.5.5.7.2.2">
      szOID_ROOT_PROGRAM_FLAGS equ <"1.3.6.1.4.1.311.60.1.1">
      ;+-------------------------------------------------------------------------
      ;  Root program qualifier flags, used in pbData field of
      ;  CERT_POLICY_QUALIFIER_INFO structure.
      ;+-------------------------------------------------------------------------
      ; Validation of the Organization (O) field in the subject name meets
      ; Root Program Requirements for display.
      CERT_ROOT_PROGRAM_FLAG_ORG equ 80h
      ; Validation of the Locale (L), State (S), and Country (C) fields in
      ; the subject name meets Program Requirements for display.
      CERT_ROOT_PROGRAM_FLAG_LSC equ 40h
      ; Subject logotype
      CERT_ROOT_PROGRAM_FLAG_SUBJECT_LOGO equ 20h
      ; Validation of the OrganizationalUnit (OU) field in the subject name
      ; meets Root Program Requirements for display.
      CERT_ROOT_PROGRAM_FLAG_OU equ 10h
      ; Validation of the address field in the subject name meets Root
      ; Program Requirements for display.
      CERT_ROOT_PROGRAM_FLAG_ADDRESS equ 08h
      ; OID for old qualifer
      szOID_CERT_POLICIES_95_QUALIFIER1 equ <"2.16.840.1.113733.1.7.1.1">
      ;+=========================================================================
      ;  TPM Object Identifiers
      ;-=========================================================================
      ; Subject Alt Name Directory Name RDNs
      szOID_RDN_TPM_MANUFACTURER equ <"2.23.133.2.1">
      szOID_RDN_TPM_MODEL equ <"2.23.133.2.2">
      szOID_RDN_TPM_VERSION equ <"2.23.133.2.3">
      szOID_RDN_TCG_PLATFORM_MANUFACTURER equ <"2.23.133.2.4">
      szOID_RDN_TCG_PLATFORM_MODEL equ <"2.23.133.2.5">
      szOID_RDN_TCG_PLATFORM_VERSION equ <"2.23.133.2.6">
      ; TPM Manufacturer ASCII Hex Strings
      ;  AMD                     "AMD"   0x41 0x4D 0x44 0x00
      ;  Atmel                   "ATML"  0x41 0x54 0x4D 0x4C
      ;  Broadcom                "BRCM"  0x42 0x52 0x43 0x4D
      ;  Cisco                   "CSCO"  0x43 0x53 0x43 0x4F
      ;  Flyslice Technologies   "FLYS"  0x46 0x4C 0x59 0x53
      ;  HPE                     "HPE"   0x48 0x50 0x45 0x00
      ;  IBM                     "IBM"   0x49 0x42 0x4d 0x00
      ;  Infineon                "IFX"   0x49 0x46 0x58 0x00
      ;  Intel                   "INTC"  0x49 0x4E 0x54 0x43
      ;  Lenovo                  "LEN"   0x4C 0x45 0x4E 0x00
      ;  Microsoft               "MSFT"  0x4D 0x53 0x46 0x54
      ;  National Semiconductor  "NSM "  0x4E 0x53 0x4D 0x20
      ;  Nationz                 "NTZ"   0x4E 0x54 0x5A 0x00
      ;  Nuvoton Technology      "NTC"   0x4E 0x54 0x43 0x00
      ;  Qualcomm                "QCOM"  0x51 0x43 0x4F 0x4D
      ;  SMSC                    "SMSC"  0x53 0x4D 0x53 0x43
      ;  ST Microelectronics     "STM "  0x53 0x54 0x4D 0x20
      ;  Samsung                 "SMSN"  0x53 0x4D 0x53 0x4E
      ;  Sinosun                 "SNS"   0x53 0x4E 0x53 0x00
      ;  Texas Instruments       "TXN"   0x54 0x58 0x4E 0x00
      ;  Winbond                 "WEC"   0x57 0x45 0x43 0x00
      ;  Fuzhou Rockchip         "ROCC"  0x52 0x4F 0x43 0x43
      ;  Google                  "GOOG"  0x47 0x4F 0x4F 0x47
      ;  VMWare                  "VMW"   0x56 0x4D 0x57 0x00
      ; Obtained from: https://trustedcomputinggroup.org/wp-content/uploads/TCG-TPM-Vendor-ID-Registry-Version-1.02-Revision-1.00.pdf
      szOID_CT_CERT_SCTLIST equ <"1.3.6.1.4.1.11129.2.4.2">; OCTET string

      ; pkcs10 attributes
      szOID_ENROLL_EK_INFO equ <"1.3.6.1.4.1.311.21.23">; EKInfo

      szOID_ENROLL_AIK_INFO equ <"1.3.6.1.4.1.311.21.39">; EKInfo

      szOID_ENROLL_ATTESTATION_STATEMENT equ <"1.3.6.1.4.1.311.21.24">
      ; pkcs10 and CMC Full Response Tagged Attribute containing the KSP name.
      ; Encoded as a unicode string, which must be null terminated.
      ; See CERT_RDN_UNICODE_STRING in the CERT_NAME_VALUE structure.
      szOID_ENROLL_KSP_NAME equ <"1.3.6.1.4.1.311.21.25">
      ; CMC Full Response Tagged Attributes
      szOID_ENROLL_EKPUB_CHALLENGE equ <"1.3.6.1.4.1.311.21.26">
      szOID_ENROLL_CAXCHGCERT_HASH equ <"1.3.6.1.4.1.311.21.27">
      szOID_ENROLL_ATTESTATION_CHALLENGE equ <"1.3.6.1.4.1.311.21.28">
      szOID_ENROLL_ENCRYPTION_ALGORITHM equ <"1.3.6.1.4.1.311.21.29">; algorithm oid

      ; TPM certificate EKU OIDs
      szOID_KP_TPM_EK_CERTIFICATE equ <"2.23.133.8.1">
      szOID_KP_TPM_PLATFORM_CERTIFICATE equ <"2.23.133.8.2">
      szOID_KP_TPM_AIK_CERTIFICATE equ <"2.23.133.8.3">
      ; EK validation Issuance Policy OIDs
      szOID_ENROLL_EKVERIFYKEY equ <"1.3.6.1.4.1.311.21.30">
      szOID_ENROLL_EKVERIFYCERT equ <"1.3.6.1.4.1.311.21.31">
      szOID_ENROLL_EKVERIFYCREDS equ <"1.3.6.1.4.1.311.21.32">
      ; Signed decimal string encoded as a Printable String
      szOID_ENROLL_SCEP_ERROR equ <"1.3.6.1.4.1.311.21.33">; HRESULT

      ; SCEP attestation attributes
      szOID_ENROLL_SCEP_SERVER_STATE equ <"1.3.6.1.4.1.311.21.34">; blob

      szOID_ENROLL_SCEP_CHALLENGE_ANSWER equ <"1.3.6.1.4.1.311.21.35">; blob

      szOID_ENROLL_SCEP_CLIENT_REQUEST equ <"1.3.6.1.4.1.311.21.37">; Pkcs10

      szOID_ENROLL_SCEP_SERVER_MESSAGE equ <"1.3.6.1.4.1.311.21.38">; String

      szOID_ENROLL_SCEP_SERVER_SECRET equ <"1.3.6.1.4.1.311.21.40">; blob

      ; key affinity extension: ASN NULL in requests, SEQUENCE of ANY containing
      ; two OCTET strings in issued certs: a salt blob and a hash value.
      szOID_ENROLL_KEY_AFFINITY equ <"1.3.6.1.4.1.311.21.41">
      ; SCEP pkcs10 attribute: signer cert thumbprint
      szOID_ENROLL_SCEP_SIGNER_HASH equ <"1.3.6.1.4.1.311.21.42">; blob

      ; TPM line specific EK CA KeyId
      szOID_ENROLL_EK_CA_KEYID equ <"1.3.6.1.4.1.311.21.43">; blob

      ; Subject Directory Attributes
      szOID_ATTR_SUPPORTED_ALGORITHMS equ <"2.5.4.52">
      szOID_ATTR_TPM_SPECIFICATION equ <"2.23.133.2.16">
      szOID_ATTR_PLATFORM_SPECIFICATION equ <"2.23.133.2.17">
      szOID_ATTR_TPM_SECURITY_ASSERTIONS equ <"2.23.133.2.18">
      ;+-------------------------------------------------------------------------
      ;  X509_CERT
      ;  The "to be signed" encoded content plus its signature. The ToBeSigned
      ;  content is the CryptEncodeObject() output for one of the following:
      ;  X509_CERT_TO_BE_SIGNED, X509_CERT_CRL_TO_BE_SIGNED or
      ;  X509_CERT_REQUEST_TO_BE_SIGNED.
      ;  pvStructInfo points to CERT_SIGNED_CONTENT_INFO.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  X509_CERT_TO_BE_SIGNED
      ;  pvStructInfo points to CERT_INFO.
      ;  For CryptDecodeObject(), the pbEncoded is the "to be signed" plus its
      ;  signature (output of a X509_CERT CryptEncodeObject()).
      ;  For CryptEncodeObject(), the pbEncoded is just the "to be signed".
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  X509_CERT_CRL_TO_BE_SIGNED
      ;  pvStructInfo points to CRL_INFO.
      ;  For CryptDecodeObject(), the pbEncoded is the "to be signed" plus its
      ;  signature (output of a X509_CERT CryptEncodeObject()).
      ;  For CryptEncodeObject(), the pbEncoded is just the "to be signed".
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  X509_CERT_REQUEST_TO_BE_SIGNED
      ;  pvStructInfo points to CERT_REQUEST_INFO.
      ;  For CryptDecodeObject(), the pbEncoded is the "to be signed" plus its
      ;  signature (output of a X509_CERT CryptEncodeObject()).
      ;  For CryptEncodeObject(), the pbEncoded is just the "to be signed".
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  X509_EXTENSIONS
      ;  szOID_CERT_EXTENSIONS
      ;  pvStructInfo points to following CERT_EXTENSIONS.
      ;--------------------------------------------------------------------------
      ; certenrolls_begin -- CERT_CONTEXTS
      CERT_EXTENSIONS struct
        cExtension DWORD ?
        rgExtension PCERT_EXTENSION ?
      CERT_EXTENSIONS ends
      _CERT_EXTENSIONS typedef CERT_EXTENSIONS
      PCERT_EXTENSIONS typedef ptr CERT_EXTENSIONS
      ; certenrolls_end
      ;+-------------------------------------------------------------------------
      ;  X509_NAME_VALUE
      ;  X509_ANY_STRING
      ;  pvStructInfo points to CERT_NAME_VALUE.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  X509_UNICODE_NAME_VALUE
      ;  X509_UNICODE_ANY_STRING
      ;  pvStructInfo points to CERT_NAME_VALUE.
      ;  The name values are unicode strings.
      ;  For CryptEncodeObject:
      ;    Value.pbData points to the unicode string.
      ;    If Value.cbData = 0, then, the unicode string is NULL terminated.
      ;    Otherwise, Value.cbData is the unicode string byte count. The byte count
      ;    is twice the character count.
      ;    If the unicode string contains an invalid character for the specified
      ;    dwValueType, then, *pcbEncoded is updated with the unicode character
      ;    index of the first invalid character. LastError is set to:
      ;    CRYPT_E_INVALID_NUMERIC_STRING, CRYPT_E_INVALID_PRINTABLE_STRING or
      ;    CRYPT_E_INVALID_IA5_STRING.
      ;    To disable the above check, either set CERT_RDN_DISABLE_CHECK_TYPE_FLAG
      ;    in dwValueType or set CRYPT_UNICODE_NAME_ENCODE_DISABLE_CHECK_TYPE_FLAG
      ;    in dwFlags passed to CryptEncodeObjectEx.
      ;    The unicode string is converted before being encoded according to
      ;    the specified dwValueType. If dwValueType is set to 0, LastError
      ;    is set to E_INVALIDARG.
      ;    If the dwValueType isn't one of the character strings (its a
      ;    CERT_RDN_ENCODED_BLOB or CERT_RDN_OCTET_STRING), then, CryptEncodeObject
      ;    will return FALSE with LastError set to CRYPT_E_NOT_CHAR_STRING.
      ;  For CryptDecodeObject:
      ;    Value.pbData points to a NULL terminated unicode string. Value.cbData
      ;    contains the byte count of the unicode string excluding the NULL
      ;    terminator. dwValueType contains the type used in the encoded object.
      ;    Its not forced to CERT_RDN_UNICODE_STRING. The encoded value is
      ;    converted to the unicode string according to the dwValueType.
      ;    If the encoded object isn't one of the character string types, then,
      ;    CryptDecodeObject will return FALSE with LastError set to
      ;    CRYPT_E_NOT_CHAR_STRING. For a non character string, decode using
      ;    X509_NAME_VALUE or X509_ANY_STRING.
      ;    By default, CERT_RDN_T61_STRING values are initially decoded
      ;    as UTF8. If the UTF8 decoding fails, then, decoded as 8 bit characters.
      ;    Set CRYPT_UNICODE_NAME_DECODE_DISABLE_IE4_UTF8_FLAG in dwFlags
      ;    passed to either CryptDecodeObject or CryptDecodeObjectEx to
      ;    skip the initial attempt to decode as UTF8.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  X509_NAME
      ;  pvStructInfo points to CERT_NAME_INFO.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  X509_UNICODE_NAME
      ;  pvStructInfo points to CERT_NAME_INFO.
      ;  The RDN attribute values are unicode strings except for the dwValueTypes of
      ;  CERT_RDN_ENCODED_BLOB or CERT_RDN_OCTET_STRING. These dwValueTypes are
      ;  the same as for a X509_NAME. Their values aren't converted to/from unicode.
      ;  For CryptEncodeObject:
      ;    Value.pbData points to the unicode string.
      ;    If Value.cbData = 0, then, the unicode string is NULL terminated.
      ;    Otherwise, Value.cbData is the unicode string byte count. The byte count
      ;    is twice the character count.
      ;    If dwValueType = 0 (CERT_RDN_ANY_TYPE), the pszObjId is used to find
      ;    an acceptable dwValueType. If the unicode string contains an
      ;    invalid character for the found or specified dwValueType, then,
      ;    *pcbEncoded is updated with the error location of the invalid character.
      ;    See below for details. LastError is set to:
      ;    CRYPT_E_INVALID_NUMERIC_STRING, CRYPT_E_INVALID_PRINTABLE_STRING or
      ;    CRYPT_E_INVALID_IA5_STRING.
      ;    To disable the above check, either set CERT_RDN_DISABLE_CHECK_TYPE_FLAG
      ;    in dwValueType or set CRYPT_UNICODE_NAME_ENCODE_DISABLE_CHECK_TYPE_FLAG
      ;    in dwFlags passed to CryptEncodeObjectEx.
      ;    Set CERT_RDN_UNICODE_STRING in dwValueType or set
      ;    CRYPT_UNICODE_NAME_ENCODE_ENABLE_T61_UNICODE_FLAG in dwFlags passed
      ;    to CryptEncodeObjectEx to select CERT_RDN_T61_STRING instead of
      ;    CERT_RDN_UNICODE_STRING if all the unicode characters are <= 0xFF.
      ;    Set CERT_RDN_ENABLE_UTF8_UNICODE_STRING in dwValueType or set
      ;    CRYPT_UNICODE_NAME_ENCODE_ENABLE_UTF8_UNICODE_FLAG in dwFlags passed
      ;    to CryptEncodeObjectEx to select CERT_RDN_UTF8_STRING instead of
      ;    CERT_RDN_UNICODE_STRING.
      ;    The unicode string is converted before being encoded according to
      ;    the specified or ObjId matching dwValueType.
      ;  For CryptDecodeObject:
      ;    Value.pbData points to a NULL terminated unicode string. Value.cbData
      ;    contains the byte count of the unicode string excluding the NULL
      ;    terminator. dwValueType contains the type used in the encoded object.
      ;    Its not forced to CERT_RDN_UNICODE_STRING. The encoded value is
      ;    converted to the unicode string according to the dwValueType.
      ;    If the dwValueType of the encoded value isn't a character string
      ;    type, then, it isn't converted to UNICODE. Use the
      ;    IS_CERT_RDN_CHAR_STRING() macro on the dwValueType to check
      ;    that Value.pbData points to a converted unicode string.
      ;    By default, CERT_RDN_T61_STRING values are initially decoded
      ;    as UTF8. If the UTF8 decoding fails, then, decoded as 8 bit characters.
      ;    Set CRYPT_UNICODE_NAME_DECODE_DISABLE_IE4_UTF8_FLAG in dwFlags
      ;    passed to either CryptDecodeObject or CryptDecodeObjectEx to
      ;    skip the initial attempt to decode as UTF8.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  Unicode Name Value Error Location Definitions
      ;  Error location is returned in *pcbEncoded by
      ;  CryptEncodeObject(X509_UNICODE_NAME)
      ;  Error location consists of:
      ;    RDN_INDEX     - 10 bits << 22
      ;    ATTR_INDEX    - 6 bits << 16
      ;    VALUE_INDEX   - 16 bits (unicode character index)
      ;--------------------------------------------------------------------------
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
      ;+-------------------------------------------------------------------------
      ;  X509_PUBLIC_KEY_INFO
      ;  pvStructInfo points to CERT_PUBLIC_KEY_INFO.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  X509_AUTHORITY_KEY_ID
      ;  szOID_AUTHORITY_KEY_IDENTIFIER
      ;  pvStructInfo points to following CERT_AUTHORITY_KEY_ID_INFO.
      ;--------------------------------------------------------------------------
      CERT_AUTHORITY_KEY_ID_INFO struct
        KeyId CRYPT_DATA_BLOB <>
        CertIssuer CERT_NAME_BLOB <>
        CertSerialNumber CRYPT_INTEGER_BLOB <>
      CERT_AUTHORITY_KEY_ID_INFO ends
      _CERT_AUTHORITY_KEY_ID_INFO typedef CERT_AUTHORITY_KEY_ID_INFO
      PCERT_AUTHORITY_KEY_ID_INFO typedef ptr CERT_AUTHORITY_KEY_ID_INFO
      ;+-------------------------------------------------------------------------
      ;  X509_KEY_ATTRIBUTES
      ;  szOID_KEY_ATTRIBUTES
      ;  pvStructInfo points to following CERT_KEY_ATTRIBUTES_INFO.
      ;--------------------------------------------------------------------------
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
        ; OPTIONAL
      CERT_KEY_ATTRIBUTES_INFO ends
      _CERT_KEY_ATTRIBUTES_INFO typedef CERT_KEY_ATTRIBUTES_INFO
      PCERT_KEY_ATTRIBUTES_INFO typedef ptr CERT_KEY_ATTRIBUTES_INFO
      ; certenrolld_begin -- CERT_*_KEY_USAGE
      ; Byte[0]
      CERT_DIGITAL_SIGNATURE_KEY_USAGE equ 80h
      CERT_NON_REPUDIATION_KEY_USAGE equ 40h
      CERT_KEY_ENCIPHERMENT_KEY_USAGE equ 20h
      CERT_DATA_ENCIPHERMENT_KEY_USAGE equ 10h
      CERT_KEY_AGREEMENT_KEY_USAGE equ 08h
      CERT_KEY_CERT_SIGN_KEY_USAGE equ 04h
      CERT_OFFLINE_CRL_SIGN_KEY_USAGE equ 02h
      CERT_CRL_SIGN_KEY_USAGE equ 02h
      CERT_ENCIPHER_ONLY_KEY_USAGE equ 01h
      ; Byte[1]
      CERT_DECIPHER_ONLY_KEY_USAGE equ 80h
      ; certenrolld_end
      ;+-------------------------------------------------------------------------
      ;  X509_KEY_USAGE_RESTRICTION
      ;  szOID_KEY_USAGE_RESTRICTION
      ;  pvStructInfo points to following CERT_KEY_USAGE_RESTRICTION_INFO.
      ;--------------------------------------------------------------------------
      CERT_POLICY_ID struct
        cCertPolicyElementId DWORD ?
        rgpszCertPolicyElementId POINTER ?
        ; pszObjId
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
      ; See CERT_KEY_ATTRIBUTES_INFO for definition of the RestrictedKeyUsage bits
      ;+-------------------------------------------------------------------------
      ;  X509_ALTERNATE_NAME
      ;  szOID_SUBJECT_ALT_NAME
      ;  szOID_ISSUER_ALT_NAME
      ;  szOID_SUBJECT_ALT_NAME2
      ;  szOID_ISSUER_ALT_NAME2
      ;  pvStructInfo points to following CERT_ALT_NAME_INFO.
      ;--------------------------------------------------------------------------
      ; certenrolls_begin -- CERT_ALT_NAME_INFO
      CERT_OTHER_NAME struct
        pszObjId POINTER ?
        Value CRYPT_OBJID_BLOB <>
      CERT_OTHER_NAME ends
      _CERT_OTHER_NAME typedef CERT_OTHER_NAME
      PCERT_OTHER_NAME typedef ptr CERT_OTHER_NAME
      CERT_ALT_NAME_ENTRY struct
        dwAltNameChoice DWORD ?
        union
          ; certenrolls_skip
          pOtherName PCERT_OTHER_NAME ?
          ; 1
          pwszRfc822Name POINTER ?
          ; 2  (encoded IA5)
          pwszDNSName POINTER ?
          ; 3  (encoded IA5)
          ; Not implemented          x400Address;        // 4
          DirectoryName CERT_NAME_BLOB <>
          ; 5
          ; Not implemented          pEdiPartyName;      // 6
          pwszURL POINTER ?
          ; 7  (encoded IA5)
          IPAddress CRYPT_DATA_BLOB <>
          ; 8  (Octet String)
          pszRegisteredID POINTER ?
          ; 9  (Object Identifer)
        ends
        ; certenrolls_skip
      CERT_ALT_NAME_ENTRY ends
      _CERT_ALT_NAME_ENTRY typedef CERT_ALT_NAME_ENTRY
      PCERT_ALT_NAME_ENTRY typedef ptr CERT_ALT_NAME_ENTRY
      ; certenrolls_end
      ; certenrolld_begin -- CERT_ALT_NAME_*
      CERT_ALT_NAME_OTHER_NAME equ 1
      CERT_ALT_NAME_RFC822_NAME equ 2
      CERT_ALT_NAME_DNS_NAME equ 3
      CERT_ALT_NAME_X400_ADDRESS equ 4
      CERT_ALT_NAME_DIRECTORY_NAME equ 5
      CERT_ALT_NAME_EDI_PARTY_NAME equ 6
      CERT_ALT_NAME_URL equ 7
      CERT_ALT_NAME_IP_ADDRESS equ 8
      CERT_ALT_NAME_REGISTERED_ID equ 9
      ; certenrolld_end
      ; certenrolls_begin -- CERT_ALT_NAME_INFO
      CERT_ALT_NAME_INFO struct
        cAltEntry DWORD ?
        rgAltEntry PCERT_ALT_NAME_ENTRY ?
      CERT_ALT_NAME_INFO ends
      _CERT_ALT_NAME_INFO typedef CERT_ALT_NAME_INFO
      PCERT_ALT_NAME_INFO typedef ptr CERT_ALT_NAME_INFO
      ; certenrolls_end
      ;+-------------------------------------------------------------------------
      ;  Alternate name IA5 Error Location Definitions for
      ;  CRYPT_E_INVALID_IA5_STRING.
      ;  Error location is returned in *pcbEncoded by
      ;  CryptEncodeObject(X509_ALTERNATE_NAME)
      ;  Error location consists of:
      ;    ENTRY_INDEX   - 8 bits << 16
      ;    VALUE_INDEX   - 16 bits (unicode character index)
      ;--------------------------------------------------------------------------
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
      ;+-------------------------------------------------------------------------
      ;  X509_BASIC_CONSTRAINTS
      ;  szOID_BASIC_CONSTRAINTS
      ;  pvStructInfo points to following CERT_BASIC_CONSTRAINTS_INFO.
      ;--------------------------------------------------------------------------
      CERT_BASIC_CONSTRAINTS_INFO struct
        SubjectType CRYPT_BIT_BLOB <>
        fPathLenConstraint DWORD ?
        dwPathLenConstraint DWORD ?
        cSubtreesConstraint DWORD ?
        rgSubtreesConstraint POINTER ?
      CERT_BASIC_CONSTRAINTS_INFO ends
      _CERT_BASIC_CONSTRAINTS_INFO typedef CERT_BASIC_CONSTRAINTS_INFO
      PCERT_BASIC_CONSTRAINTS_INFO typedef ptr CERT_BASIC_CONSTRAINTS_INFO
      CERT_CA_SUBJECT_FLAG equ 80h
      CERT_END_ENTITY_SUBJECT_FLAG equ 40h
      ;+-------------------------------------------------------------------------
      ;  X509_BASIC_CONSTRAINTS2
      ;  szOID_BASIC_CONSTRAINTS2
      ;  pvStructInfo points to following CERT_BASIC_CONSTRAINTS2_INFO.
      ;--------------------------------------------------------------------------
      CERT_BASIC_CONSTRAINTS2_INFO struct
        fCA DWORD ?
        fPathLenConstraint DWORD ?
        dwPathLenConstraint DWORD ?
      CERT_BASIC_CONSTRAINTS2_INFO ends
      _CERT_BASIC_CONSTRAINTS2_INFO typedef CERT_BASIC_CONSTRAINTS2_INFO
      PCERT_BASIC_CONSTRAINTS2_INFO typedef ptr CERT_BASIC_CONSTRAINTS2_INFO
      ;+-------------------------------------------------------------------------
      ;  X509_KEY_USAGE
      ;  szOID_KEY_USAGE
      ;  pvStructInfo points to a CRYPT_BIT_BLOB. Has same bit definitions as
      ;  CERT_KEY_ATTRIBUTES_INFO's IntendedKeyUsage.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  X509_CERT_POLICIES
      ;  szOID_CERT_POLICIES
      ;  szOID_CERT_POLICIES_95   NOTE--Only allowed for decoding!!!
      ;  pvStructInfo points to following CERT_POLICIES_INFO.
      ;  NOTE: when decoding using szOID_CERT_POLICIES_95 the pszPolicyIdentifier
      ;        may contain an empty string
      ;--------------------------------------------------------------------------
      ; certenrolls_begin -- CERT_POLICY_QUALIFIER_INFO
      CERT_POLICY_QUALIFIER_INFO struct
        pszPolicyQualifierId POINTER ?
        ; pszObjId
        Qualifier CRYPT_OBJID_BLOB <>
        ; optional
      CERT_POLICY_QUALIFIER_INFO ends
      _CERT_POLICY_QUALIFIER_INFO typedef CERT_POLICY_QUALIFIER_INFO
      PCERT_POLICY_QUALIFIER_INFO typedef ptr CERT_POLICY_QUALIFIER_INFO
      CERT_POLICY_INFO struct
        pszPolicyIdentifier POINTER ?
        ; pszObjId
        cPolicyQualifier DWORD ?
        ; optional
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
      ; certenrolls_end
      ;+-------------------------------------------------------------------------
      ;  X509_PKIX_POLICY_QUALIFIER_USERNOTICE
      ;  szOID_PKIX_POLICY_QUALIFIER_USERNOTICE
      ;  pvStructInfo points to following CERT_POLICY_QUALIFIER_USER_NOTICE.
      ;--------------------------------------------------------------------------
      CERT_POLICY_QUALIFIER_NOTICE_REFERENCE struct
        pszOrganization POINTER ?
        cNoticeNumbers DWORD ?
        rgNoticeNumbers POINTER ?
      CERT_POLICY_QUALIFIER_NOTICE_REFERENCE ends
      _CERT_POLICY_QUALIFIER_NOTICE_REFERENCE typedef CERT_POLICY_QUALIFIER_NOTICE_REFERENCE
      PCERT_POLICY_QUALIFIER_NOTICE_REFERENCE typedef ptr CERT_POLICY_QUALIFIER_NOTICE_REFERENCE
      CERT_POLICY_QUALIFIER_USER_NOTICE struct
        pNoticeReference POINTER ?
        ; optional
        pszDisplayText POINTER ?
        ; optional
      CERT_POLICY_QUALIFIER_USER_NOTICE ends
      _CERT_POLICY_QUALIFIER_USER_NOTICE typedef CERT_POLICY_QUALIFIER_USER_NOTICE
      PCERT_POLICY_QUALIFIER_USER_NOTICE typedef ptr CERT_POLICY_QUALIFIER_USER_NOTICE
      ;+-------------------------------------------------------------------------
      ;  szOID_CERT_POLICIES_95_QUALIFIER1 - Decode Only!!!!
      ;  pvStructInfo points to following CERT_POLICY95_QUALIFIER1.
      ;--------------------------------------------------------------------------
      CPS_URLS struct
        pszURL POINTER ?
        pAlgorithm POINTER ?
        ; optional
        pDigest POINTER ?
        ; optional
      CPS_URLS ends
      _CPS_URLS typedef CPS_URLS
      PCPS_URLS typedef ptr CPS_URLS
      CERT_POLICY95_QUALIFIER1 struct
        pszPracticesReference POINTER ?
        ; optional
        pszNoticeIdentifier POINTER ?
        ; optional
        pszNSINoticeIdentifier POINTER ?
        ; optional
        cCPSURLs DWORD ?
        rgCPSURLs POINTER ?
        ; optional
      CERT_POLICY95_QUALIFIER1 ends
      _CERT_POLICY95_QUALIFIER1 typedef CERT_POLICY95_QUALIFIER1
      PCERT_POLICY95_QUALIFIER1 typedef ptr CERT_POLICY95_QUALIFIER1
      ;+-------------------------------------------------------------------------
      ;  szOID_INHIBIT_ANY_POLICY data structure
      ;  pvStructInfo points to an int.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  X509_POLICY_MAPPINGS
      ;  szOID_POLICY_MAPPINGS
      ;  szOID_LEGACY_POLICY_MAPPINGS
      ;  pvStructInfo points to following CERT_POLICY_MAPPINGS_INFO.
      ;--------------------------------------------------------------------------
      CERT_POLICY_MAPPING struct
        pszIssuerDomainPolicy POINTER ?
        ; pszObjId
        pszSubjectDomainPolicy POINTER ?
        ; pszObjId
      CERT_POLICY_MAPPING ends
      _CERT_POLICY_MAPPING typedef CERT_POLICY_MAPPING
      PCERT_POLICY_MAPPING typedef ptr CERT_POLICY_MAPPING
      CERT_POLICY_MAPPINGS_INFO struct
        cPolicyMapping DWORD ?
        rgPolicyMapping PCERT_POLICY_MAPPING ?
      CERT_POLICY_MAPPINGS_INFO ends
      _CERT_POLICY_MAPPINGS_INFO typedef CERT_POLICY_MAPPINGS_INFO
      PCERT_POLICY_MAPPINGS_INFO typedef ptr CERT_POLICY_MAPPINGS_INFO
      ;+-------------------------------------------------------------------------
      ;  X509_POLICY_CONSTRAINTS
      ;  szOID_POLICY_CONSTRAINTS
      ;  pvStructInfo points to following CERT_POLICY_CONSTRAINTS_INFO.
      ;--------------------------------------------------------------------------
      CERT_POLICY_CONSTRAINTS_INFO struct
        fRequireExplicitPolicy DWORD ?
        dwRequireExplicitPolicySkipCerts DWORD ?
        fInhibitPolicyMapping DWORD ?
        dwInhibitPolicyMappingSkipCerts DWORD ?
      CERT_POLICY_CONSTRAINTS_INFO ends
      _CERT_POLICY_CONSTRAINTS_INFO typedef CERT_POLICY_CONSTRAINTS_INFO
      PCERT_POLICY_CONSTRAINTS_INFO typedef ptr CERT_POLICY_CONSTRAINTS_INFO
      ;+-------------------------------------------------------------------------
      ;  RSA_CSP_PUBLICKEYBLOB
      ;  pvStructInfo points to a PUBLICKEYSTRUC immediately followed by a
      ;  RSAPUBKEY and the modulus bytes.
      ;  CryptExportKey outputs the above StructInfo for a dwBlobType of
      ;  PUBLICKEYBLOB. CryptImportKey expects the above StructInfo when
      ;  importing a public key.
      ;  For dwCertEncodingType = X509_ASN_ENCODING, the RSA_CSP_PUBLICKEYBLOB is
      ;  encoded as a PKCS #1 RSAPublicKey consisting of a SEQUENCE of a
      ;  modulus INTEGER and a publicExponent INTEGER. The modulus is encoded
      ;  as being a unsigned integer. When decoded, if the modulus was encoded
      ;  as unsigned integer with a leading 0 byte, the 0 byte is removed before
      ;  converting to the CSP modulus bytes.
      ;  For decode, the aiKeyAlg field of PUBLICKEYSTRUC is always set to
      ;  CALG_RSA_KEYX.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  CNG_RSA_PUBLIC_KEY_BLOB
      ;  pvStructInfo points to a BCRYPT_RSAKEY_BLOB immediately followed by the
      ;  exponent and the modulus bytes. Both the exponent and modulus are
      ;  big endian. The private key fields consisting of cbPrime1 and cbPrime2
      ;  are set to zero.
      ;  For dwCertEncodingType = X509_ASN_ENCODING, the CNG_RSA_PUBLIC_KEY_BLOB is
      ;  encoded as a PKCS #1 RSAPublicKey consisting of a SEQUENCE of a
      ;  modulus HUGEINTEGER and a publicExponent HUGEINTEGER.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  X509_KEYGEN_REQUEST_TO_BE_SIGNED
      ;  pvStructInfo points to CERT_KEYGEN_REQUEST_INFO.
      ;  For CryptDecodeObject(), the pbEncoded is the "to be signed" plus its
      ;  signature (output of a X509_CERT CryptEncodeObject()).
      ;  For CryptEncodeObject(), the pbEncoded is just the "to be signed".
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  PKCS_ATTRIBUTE data structure
      ;  pvStructInfo points to a CRYPT_ATTRIBUTE.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  PKCS_ATTRIBUTES data structure
      ;  pvStructInfo points to a CRYPT_ATTRIBUTES.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  szOID_SUBJECT_DIR_ATTRS
      ;  X509_SUBJECT_DIR_ATTRS
      ;  pvStructInfo points to a CRYPT_ATTRIBUTES.
      ;  Encoded as a "SEQUENCE OF" instead of "SET OF"
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  X509_ECC_PARAMETERS
      ;  pvStructInfo points to a CRYPT_DATA_BLOB which contains CNG Parameters
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  PKCS_CONTENT_INFO_SEQUENCE_OF_ANY data structure
      ;  pvStructInfo points to following CRYPT_CONTENT_INFO_SEQUENCE_OF_ANY.
      ;  For X509_ASN_ENCODING: encoded as a PKCS#7 ContentInfo structure wrapping
      ;  a sequence of ANY. The value of the contentType field is pszObjId,
      ;  while the content field is the following structure:
      ;      SequenceOfAny ::= SEQUENCE OF ANY
      ;  The CRYPT_DER_BLOBs point to the already encoded ANY content.
      ;--------------------------------------------------------------------------
      CRYPT_CONTENT_INFO_SEQUENCE_OF_ANY struct
        pszObjId POINTER ?
        cValue DWORD ?
        rgValue PCRYPT_DER_BLOB ?
      CRYPT_CONTENT_INFO_SEQUENCE_OF_ANY ends
      _CRYPT_CONTENT_INFO_SEQUENCE_OF_ANY typedef CRYPT_CONTENT_INFO_SEQUENCE_OF_ANY
      PCRYPT_CONTENT_INFO_SEQUENCE_OF_ANY typedef ptr CRYPT_CONTENT_INFO_SEQUENCE_OF_ANY
      ;+-------------------------------------------------------------------------
      ;  PKCS_CONTENT_INFO data structure
      ;  pvStructInfo points to following CRYPT_CONTENT_INFO.
      ;  For X509_ASN_ENCODING: encoded as a PKCS#7 ContentInfo structure.
      ;  The CRYPT_DER_BLOB points to the already encoded ANY content.
      ;--------------------------------------------------------------------------
      CRYPT_CONTENT_INFO struct
        pszObjId POINTER ?
        Content CRYPT_DER_BLOB <>
      CRYPT_CONTENT_INFO ends
      _CRYPT_CONTENT_INFO typedef CRYPT_CONTENT_INFO
      PCRYPT_CONTENT_INFO typedef ptr CRYPT_CONTENT_INFO
      ;+-------------------------------------------------------------------------
      ;  X509_OCTET_STRING data structure
      ;  pvStructInfo points to a CRYPT_DATA_BLOB.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  X509_BITS data structure
      ;  pvStructInfo points to a CRYPT_BIT_BLOB.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  X509_BITS_WITHOUT_TRAILING_ZEROES data structure
      ;  pvStructInfo points to a CRYPT_BIT_BLOB.
      ;  The same as X509_BITS, except before encoding, the bit length is
      ;  decremented to exclude trailing zero bits.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  X509_INTEGER data structure
      ;  pvStructInfo points to an int.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  X509_MULTI_BYTE_INTEGER data structure
      ;  pvStructInfo points to a CRYPT_INTEGER_BLOB.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  X509_ENUMERATED data structure
      ;  pvStructInfo points to an int containing the enumerated value
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  X509_CHOICE_OF_TIME data structure
      ;  pvStructInfo points to a FILETIME.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  X509_SEQUENCE_OF_ANY data structure
      ;  pvStructInfo points to following CRYPT_SEQUENCE_OF_ANY.
      ;  The CRYPT_DER_BLOBs point to the already encoded ANY content.
      ;--------------------------------------------------------------------------
      CRYPT_SEQUENCE_OF_ANY struct
        cValue DWORD ?
        rgValue PCRYPT_DER_BLOB ?
      CRYPT_SEQUENCE_OF_ANY ends
      _CRYPT_SEQUENCE_OF_ANY typedef CRYPT_SEQUENCE_OF_ANY
      PCRYPT_SEQUENCE_OF_ANY typedef ptr CRYPT_SEQUENCE_OF_ANY
      ;+-------------------------------------------------------------------------
      ;  X509_AUTHORITY_KEY_ID2
      ;  szOID_AUTHORITY_KEY_IDENTIFIER2
      ;  pvStructInfo points to following CERT_AUTHORITY_KEY_ID2_INFO.
      ;  For CRYPT_E_INVALID_IA5_STRING, the error location is returned in
      ;  *pcbEncoded by CryptEncodeObject(X509_AUTHORITY_KEY_ID2)
      ;  See X509_ALTERNATE_NAME for error location defines.
      ;--------------------------------------------------------------------------
      CERT_AUTHORITY_KEY_ID2_INFO struct
        KeyId CRYPT_DATA_BLOB <>
        AuthorityCertIssuer CERT_ALT_NAME_INFO <>
        ; Optional, set cAltEntry
        ; to 0 to omit.
        AuthorityCertSerialNumber CRYPT_INTEGER_BLOB <>
      CERT_AUTHORITY_KEY_ID2_INFO ends
      _CERT_AUTHORITY_KEY_ID2_INFO typedef CERT_AUTHORITY_KEY_ID2_INFO
      PCERT_AUTHORITY_KEY_ID2_INFO typedef ptr CERT_AUTHORITY_KEY_ID2_INFO
      ;+-------------------------------------------------------------------------
      ;  szOID_SUBJECT_KEY_IDENTIFIER
      ;  pvStructInfo points to a CRYPT_DATA_BLOB.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  X509_AUTHORITY_INFO_ACCESS
      ;  szOID_AUTHORITY_INFO_ACCESS
      ;  X509_SUBJECT_INFO_ACCESS
      ;  szOID_SUBJECT_INFO_ACCESS
      ;  pvStructInfo points to following CERT_AUTHORITY_INFO_ACCESS.
      ;  For CRYPT_E_INVALID_IA5_STRING, the error location is returned in
      ;  *pcbEncoded by CryptEncodeObject(X509_AUTHORITY_INFO_ACCESS)
      ;  Error location consists of:
      ;    ENTRY_INDEX   - 8 bits << 16
      ;    VALUE_INDEX   - 16 bits (unicode character index)
      ;  See X509_ALTERNATE_NAME for ENTRY_INDEX and VALUE_INDEX error location
      ;  defines.
      ;  Note, the szOID_SUBJECT_INFO_ACCESS extension has the same ASN.1
      ;  encoding as the szOID_AUTHORITY_INFO_ACCESS extension.
      ;--------------------------------------------------------------------------
      CERT_ACCESS_DESCRIPTION struct
        pszAccessMethod POINTER ?
        ; pszObjId
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
      ;+-------------------------------------------------------------------------
      ;  PKIX Access Description: Access Method Object Identifiers
      ;--------------------------------------------------------------------------
      szOID_PKIX_ACC_DESCR equ <"1.3.6.1.5.5.7.48">
      ; For szOID_AUTHORITY_INFO_ACCESS
      szOID_PKIX_OCSP equ <"1.3.6.1.5.5.7.48.1">
      szOID_PKIX_CA_ISSUERS equ <"1.3.6.1.5.5.7.48.2">
      ; For szOID_SUBJECT_INFO_ACCESS
      szOID_PKIX_TIME_STAMPING equ <"1.3.6.1.5.5.7.48.3">
      szOID_PKIX_CA_REPOSITORY equ <"1.3.6.1.5.5.7.48.5">
      ;+-------------------------------------------------------------------------
      ;  X509_CRL_REASON_CODE
      ;  szOID_CRL_REASON_CODE
      ;  pvStructInfo points to an int which can be set to one of the following
      ;  enumerated values:
      ;--------------------------------------------------------------------------
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
      ;+-------------------------------------------------------------------------
      ;  X509_CRL_DIST_POINTS
      ;  szOID_CRL_DIST_POINTS
      ;  pvStructInfo points to following CRL_DIST_POINTS_INFO.
      ;  For CRYPT_E_INVALID_IA5_STRING, the error location is returned in
      ;  *pcbEncoded by CryptEncodeObject(X509_CRL_DIST_POINTS)
      ;  Error location consists of:
      ;    CRL_ISSUER_BIT    - 1 bit  << 31 (0 for FullName, 1 for CRLIssuer)
      ;    POINT_INDEX       - 7 bits << 24
      ;    ENTRY_INDEX       - 8 bits << 16
      ;    VALUE_INDEX       - 16 bits (unicode character index)
      ;  See X509_ALTERNATE_NAME for ENTRY_INDEX and VALUE_INDEX error location
      ;  defines.
      ;--------------------------------------------------------------------------
      CRL_DIST_POINT_NAME struct
        dwDistPointNameChoice DWORD ?
        union
          FullName CERT_ALT_NAME_INFO <>
          ; 1
          ; Not implemented      IssuerRDN;      // 2
        ends
      CRL_DIST_POINT_NAME ends
      _CRL_DIST_POINT_NAME typedef CRL_DIST_POINT_NAME
      PCRL_DIST_POINT_NAME typedef ptr CRL_DIST_POINT_NAME
      CRL_DIST_POINT_NO_NAME equ 0
      CRL_DIST_POINT_FULL_NAME equ 1
      CRL_DIST_POINT_ISSUER_RDN_NAME equ 2
      CRL_DIST_POINT struct
        DistPointName CRL_DIST_POINT_NAME <>
        ; OPTIONAL
        ReasonFlags CRYPT_BIT_BLOB <>
        ; OPTIONAL
        CRLIssuer CERT_ALT_NAME_INFO <>
        ; OPTIONAL
      CRL_DIST_POINT ends
      _CRL_DIST_POINT typedef CRL_DIST_POINT
      PCRL_DIST_POINT typedef ptr CRL_DIST_POINT
      ; Byte[0]
      CRL_REASON_UNUSED_FLAG equ 80h
      CRL_REASON_KEY_COMPROMISE_FLAG equ 40h
      CRL_REASON_CA_COMPROMISE_FLAG equ 20h
      CRL_REASON_AFFILIATION_CHANGED_FLAG equ 10h
      CRL_REASON_SUPERSEDED_FLAG equ 08h
      CRL_REASON_CESSATION_OF_OPERATION_FLAG equ 04h
      CRL_REASON_CERTIFICATE_HOLD_FLAG equ 02h
      CRL_REASON_PRIVILEGE_WITHDRAWN_FLAG equ 01h
      ; Byte[1]
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
      ;+-------------------------------------------------------------------------
      ;  X509_CROSS_CERT_DIST_POINTS
      ;  szOID_CROSS_CERT_DIST_POINTS
      ;  pvStructInfo points to following CROSS_CERT_DIST_POINTS_INFO.
      ;  For CRYPT_E_INVALID_IA5_STRING, the error location is returned in
      ;  *pcbEncoded by CryptEncodeObject(X509_CRL_DIST_POINTS)
      ;  Error location consists of:
      ;    POINT_INDEX       - 8 bits << 24
      ;    ENTRY_INDEX       - 8 bits << 16
      ;    VALUE_INDEX       - 16 bits (unicode character index)
      ;  See X509_ALTERNATE_NAME for ENTRY_INDEX and VALUE_INDEX error location
      ;  defines.
      ;--------------------------------------------------------------------------
      CROSS_CERT_DIST_POINTS_INFO struct
        ; Seconds between syncs. 0 implies use client default.
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
      ;+-------------------------------------------------------------------------
      ;  X509_ENHANCED_KEY_USAGE
      ;  szOID_ENHANCED_KEY_USAGE
      ;  pvStructInfo points to a CERT_ENHKEY_USAGE, CTL_USAGE.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  X509_CERT_PAIR
      ;  pvStructInfo points to the following CERT_PAIR.
      ;--------------------------------------------------------------------------
      CERT_PAIR struct
        Forward CERT_BLOB <>
        ; OPTIONAL, if Forward.cbData == 0, omitted
        Reverse CERT_BLOB <>
        ; OPTIONAL, if Reverse.cbData == 0, omitted
      CERT_PAIR ends
      _CERT_PAIR typedef CERT_PAIR
      PCERT_PAIR typedef ptr CERT_PAIR
      ;+-------------------------------------------------------------------------
      ;  szOID_CRL_NUMBER
      ;  pvStructInfo points to an int.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  szOID_DELTA_CRL_INDICATOR
      ;  pvStructInfo points to an int.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  szOID_ISSUING_DIST_POINT
      ;  X509_ISSUING_DIST_POINT
      ;  pvStructInfo points to the following CRL_ISSUING_DIST_POINT.
      ;  For CRYPT_E_INVALID_IA5_STRING, the error location is returned in
      ;  *pcbEncoded by CryptEncodeObject(X509_ISSUING_DIST_POINT)
      ;  Error location consists of:
      ;    ENTRY_INDEX       - 8 bits << 16
      ;    VALUE_INDEX       - 16 bits (unicode character index)
      ;  See X509_ALTERNATE_NAME for ENTRY_INDEX and VALUE_INDEX error location
      ;  defines.
      ;--------------------------------------------------------------------------
      CRL_ISSUING_DIST_POINT struct
        DistPointName CRL_DIST_POINT_NAME <>
        ; OPTIONAL
        fOnlyContainsUserCerts DWORD ?
        fOnlyContainsCACerts DWORD ?
        OnlySomeReasonFlags CRYPT_BIT_BLOB <>
        ; OPTIONAL
        fIndirectCRL DWORD ?
      CRL_ISSUING_DIST_POINT ends
      _CRL_ISSUING_DIST_POINT typedef CRL_ISSUING_DIST_POINT
      PCRL_ISSUING_DIST_POINT typedef ptr CRL_ISSUING_DIST_POINT
      ;+-------------------------------------------------------------------------
      ;  szOID_FRESHEST_CRL
      ;  pvStructInfo points to CRL_DIST_POINTS_INFO.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  szOID_NAME_CONSTRAINTS
      ;  X509_NAME_CONSTRAINTS
      ;  pvStructInfo points to the following CERT_NAME_CONSTRAINTS_INFO
      ;  For CRYPT_E_INVALID_IA5_STRING, the error location is returned in
      ;  *pcbEncoded by CryptEncodeObject(X509_NAME_CONSTRAINTS)
      ;  Error location consists of:
      ;    EXCLUDED_SUBTREE_BIT  - 1 bit  << 31 (0 for permitted, 1 for excluded)
      ;    ENTRY_INDEX           - 8 bits << 16
      ;    VALUE_INDEX           - 16 bits (unicode character index)
      ;  See X509_ALTERNATE_NAME for ENTRY_INDEX and VALUE_INDEX error location
      ;  defines.
      ;--------------------------------------------------------------------------
      CERT_GENERAL_SUBTREE struct
        Base CERT_ALT_NAME_ENTRY <>
        dwMinimum DWORD ?
        fMaximum DWORD ?
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
      ;+-------------------------------------------------------------------------
      ;  szOID_NEXT_UPDATE_LOCATION
      ;  pvStructInfo points to a CERT_ALT_NAME_INFO.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  szOID_REMOVE_CERTIFICATE
      ;  pvStructInfo points to an int which can be set to one of the following
      ;   0 - Add certificate
      ;   1 - Remove certificate
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  PKCS_CTL
      ;  szOID_CTL
      ;  pvStructInfo points to a CTL_INFO.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  PKCS_SORTED_CTL
      ;  pvStructInfo points to a CTL_INFO.
      ;  Same as for PKCS_CTL, except, the CTL entries are sorted. The following
      ;  extension containing the sort information is inserted as the first
      ;  extension in the encoded CTL.
      ;  Only supported for Encoding. CRYPT_ENCODE_ALLOC_FLAG flag must be
      ;  set.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ; Sorted CTL TrustedSubjects extension
      ;  Array of little endian DWORDs:
      ;   [0] - Flags
      ;   [1] - Count of HashBucket entry offsets
      ;   [2] - Maximum HashBucket entry collision count
      ;   [3 ..] (Count + 1) HashBucket entry offsets
      ;  When this extension is present in the CTL,
      ;  the ASN.1 encoded sequence of TrustedSubjects are HashBucket ordered.
      ;  The entry offsets point to the start of the first encoded TrustedSubject
      ;  sequence for the HashBucket. The encoded TrustedSubjects for a HashBucket
      ;  continue until the encoded offset of the next HashBucket. A HashBucket has
      ;  no entries if HashBucket[N] == HashBucket[N + 1].
      ;  The HashBucket offsets are from the start of the ASN.1 encoded CTL_INFO.
      ;--------------------------------------------------------------------------
      SORTED_CTL_EXT_FLAGS_OFFSET equ (0 * 4)
      SORTED_CTL_EXT_COUNT_OFFSET equ (1 * 4)
      SORTED_CTL_EXT_MAX_COLLISION_OFFSET equ (2 * 4)
      SORTED_CTL_EXT_HASH_BUCKET_OFFSET equ (3 * 4)
      ; If the SubjectIdentifiers are a MD5 or SHA1 hash, the following flag is
      ; set. When set, the first 4 bytes of the SubjectIdentifier are used as
      ; the dwhash. Otherwise, the SubjectIdentifier bytes are hashed into dwHash.
      ; In either case the HashBucket index = dwHash % cHashBucket.
      SORTED_CTL_EXT_HASHED_SUBJECT_IDENTIFIER_FLAG equ 1h
      ;+-------------------------------------------------------------------------
      ;  X509_MULTI_BYTE_UINT
      ;  pvStructInfo points to a CRYPT_UINT_BLOB. Before encoding, inserts a
      ;  leading 0x00. After decoding, removes a leading 0x00.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  X509_DSS_PUBLICKEY
      ;  pvStructInfo points to a CRYPT_UINT_BLOB.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  X509_DSS_PARAMETERS
      ;  pvStructInfo points to following CERT_DSS_PARAMETERS data structure.
      ;--------------------------------------------------------------------------
      CERT_DSS_PARAMETERS struct
        p CRYPT_UINT_BLOB <>
        q CRYPT_UINT_BLOB <>
        g CRYPT_UINT_BLOB <>
      CERT_DSS_PARAMETERS ends
      _CERT_DSS_PARAMETERS typedef CERT_DSS_PARAMETERS
      PCERT_DSS_PARAMETERS typedef ptr CERT_DSS_PARAMETERS
      ;+-------------------------------------------------------------------------
      ;  X509_DSS_SIGNATURE
      ;  pvStructInfo is a BYTE rgbSignature[CERT_DSS_SIGNATURE_LEN]. The
      ;  bytes are ordered as output by the DSS CSP's CryptSignHash().
      ;--------------------------------------------------------------------------
      CERT_DSS_R_LEN equ 20
      CERT_DSS_S_LEN equ 20
      CERT_DSS_SIGNATURE_LEN equ <(CERT_DSS_R_LEN + CERT_DSS_S_LEN)>
      ; Sequence of 2 unsigned integers (the extra +1 is for a potential leading
      ; 0x00 to make the integer unsigned)
      CERT_MAX_ASN_ENCODED_DSS_SIGNATURE_LEN equ (2 + 2 * (2 + 20 + 1))
      ;+-------------------------------------------------------------------------
      ;  X509_DH_PUBLICKEY
      ;  pvStructInfo points to a CRYPT_UINT_BLOB.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  X509_DH_PARAMETERS
      ;  pvStructInfo points to following CERT_DH_PARAMETERS data structure.
      ;--------------------------------------------------------------------------
      CERT_DH_PARAMETERS struct
        p CRYPT_UINT_BLOB <>
        g CRYPT_UINT_BLOB <>
      CERT_DH_PARAMETERS ends
      _CERT_DH_PARAMETERS typedef CERT_DH_PARAMETERS
      PCERT_DH_PARAMETERS typedef ptr CERT_DH_PARAMETERS
      ;+-------------------------------------------------------------------------
      ;  X509_ECC_SIGNATURE
      ;  pvStructInfo points to following CERT_ECC_SIGNATURE data structure.
      ;  Note, identical to the above except for the names of the fields. Same
      ;  underlying encode/decode functions are used.
      ;--------------------------------------------------------------------------
      CERT_ECC_SIGNATURE struct
        r CRYPT_UINT_BLOB <>
        s CRYPT_UINT_BLOB <>
      CERT_ECC_SIGNATURE ends
      _CERT_ECC_SIGNATURE typedef CERT_ECC_SIGNATURE
      PCERT_ECC_SIGNATURE typedef ptr CERT_ECC_SIGNATURE
      ;+-------------------------------------------------------------------------
      ;  X942_DH_PARAMETERS
      ;  pvStructInfo points to following CERT_X942_DH_PARAMETERS data structure.
      ;  If q.cbData == 0, then, the following fields are zero'ed.
      ;--------------------------------------------------------------------------
      CERT_X942_DH_VALIDATION_PARAMS struct
        seed CRYPT_BIT_BLOB <>
        pgenCounter DWORD ?
      CERT_X942_DH_VALIDATION_PARAMS ends
      _CERT_X942_DH_VALIDATION_PARAMS typedef CERT_X942_DH_VALIDATION_PARAMS
      PCERT_X942_DH_VALIDATION_PARAMS typedef ptr CERT_X942_DH_VALIDATION_PARAMS
      CERT_X942_DH_PARAMETERS struct
        p CRYPT_UINT_BLOB <>
        ; odd prime, p = jq + 1
        g CRYPT_UINT_BLOB <>
        ; generator, g
        q CRYPT_UINT_BLOB <>
        ; factor of p - 1, OPTIONAL
        j CRYPT_UINT_BLOB <>
        ; subgroup factor, OPTIONAL
        pValidationParams PCERT_X942_DH_VALIDATION_PARAMS ?
        ; OPTIONAL
      CERT_X942_DH_PARAMETERS ends
      _CERT_X942_DH_PARAMETERS typedef CERT_X942_DH_PARAMETERS
      PCERT_X942_DH_PARAMETERS typedef ptr CERT_X942_DH_PARAMETERS
      ;+-------------------------------------------------------------------------
      ;  X942_OTHER_INFO
      ;  pvStructInfo points to following CRYPT_X942_OTHER_INFO data structure.
      ;  rgbCounter and rgbKeyLength are in Little Endian order.
      ;--------------------------------------------------------------------------
      CRYPT_X942_COUNTER_BYTE_LENGTH equ 4
      CRYPT_X942_KEY_LENGTH_BYTE_LENGTH equ 4
      CRYPT_X942_PUB_INFO_BYTE_LENGTH equ (512 / 8)
      CRYPT_X942_OTHER_INFO struct
        pszContentEncryptionObjId POINTER ?
        rgbCounter BYTE CRYPT_X942_COUNTER_BYTE_LENGTH dup (?)
        rgbKeyLength BYTE CRYPT_X942_KEY_LENGTH_BYTE_LENGTH dup (?)
        PubInfo CRYPT_DATA_BLOB <>
        ; OPTIONAL
      CRYPT_X942_OTHER_INFO ends
      _CRYPT_X942_OTHER_INFO typedef CRYPT_X942_OTHER_INFO
      PCRYPT_X942_OTHER_INFO typedef ptr CRYPT_X942_OTHER_INFO
      ;+-------------------------------------------------------------------------
      ;  ECC_CMS_SHARED_INFO
      ;  pvStructInfo points to following ECC_CMS_SHARED_INFO data structure.
      ;  rgbSuppPubInfo is in Little Endian order.
      ;--------------------------------------------------------------------------
      CRYPT_ECC_CMS_SHARED_INFO_SUPPPUBINFO_BYTE_LENGTH equ 4
      CRYPT_ECC_CMS_SHARED_INFO struct
        Algorithm CRYPT_ALGORITHM_IDENTIFIER <>
        EntityUInfo CRYPT_DATA_BLOB <>
        ; OPTIONAL
        rgbSuppPubInfo BYTE CRYPT_ECC_CMS_SHARED_INFO_SUPPPUBINFO_BYTE_LENGTH dup (?)
      CRYPT_ECC_CMS_SHARED_INFO ends
      _CRYPT_ECC_CMS_SHARED_INFO typedef CRYPT_ECC_CMS_SHARED_INFO
      PCRYPT_ECC_CMS_SHARED_INFO typedef ptr CRYPT_ECC_CMS_SHARED_INFO
      ;+-------------------------------------------------------------------------
      ;  PKCS_RC2_CBC_PARAMETERS
      ;  szOID_RSA_RC2CBC
      ;  pvStructInfo points to following CRYPT_RC2_CBC_PARAMETERS data structure.
      ;--------------------------------------------------------------------------
      CRYPT_RC2_CBC_PARAMETERS struct
        dwVersion DWORD ?
        fIV DWORD ?
        ; set if has following IV
        rgbIV BYTE 8 dup (?)
      CRYPT_RC2_CBC_PARAMETERS ends
      _CRYPT_RC2_CBC_PARAMETERS typedef CRYPT_RC2_CBC_PARAMETERS
      PCRYPT_RC2_CBC_PARAMETERS typedef ptr CRYPT_RC2_CBC_PARAMETERS
      CRYPT_RC2_40BIT_VERSION equ 160
      CRYPT_RC2_56BIT_VERSION equ 52
      CRYPT_RC2_64BIT_VERSION equ 120
      CRYPT_RC2_128BIT_VERSION equ 58
      ;+-------------------------------------------------------------------------
      ;  PKCS_SMIME_CAPABILITIES
      ;  szOID_RSA_SMIMECapabilities
      ;  pvStructInfo points to following CRYPT_SMIME_CAPABILITIES data structure.
      ;  Note, for CryptEncodeObject(X509_ASN_ENCODING), Parameters.cbData == 0
      ;  causes the encoded parameters to be omitted and not encoded as a NULL
      ;  (05 00) as is done when encoding a CRYPT_ALGORITHM_IDENTIFIER. This
      ;  is per the SMIME specification for encoding capabilities.
      ;--------------------------------------------------------------------------
      ; certenrolls_begin -- CRYPT_SMIME_CAPABILITY
      CRYPT_SMIME_CAPABILITY struct
        pszObjId POINTER ?
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
      ; certenrolls_end
      ;+-------------------------------------------------------------------------
      ;  Qualified Certificate Statements Extension Data Structures
      ;  X509_QC_STATEMENTS_EXT
      ;  szOID_QC_STATEMENTS_EXT
      ;  pvStructInfo points to following CERT_QC_STATEMENTS_EXT_INFO
      ;  data structure.
      ;  Note, identical to the above except for the names of the fields. Same
      ;  underlying encode/decode functions are used.
      ;--------------------------------------------------------------------------
      CERT_QC_STATEMENT struct
        pszStatementId POINTER ?
        ; pszObjId
        StatementInfo CRYPT_OBJID_BLOB <>
        ; OPTIONAL
      CERT_QC_STATEMENT ends
      _CERT_QC_STATEMENT typedef CERT_QC_STATEMENT
      PCERT_QC_STATEMENT typedef ptr CERT_QC_STATEMENT
      CERT_QC_STATEMENTS_EXT_INFO struct
        cStatement DWORD ?
        rgStatement PCERT_QC_STATEMENT ?
      CERT_QC_STATEMENTS_EXT_INFO ends
      _CERT_QC_STATEMENTS_EXT_INFO typedef CERT_QC_STATEMENTS_EXT_INFO
      PCERT_QC_STATEMENTS_EXT_INFO typedef ptr CERT_QC_STATEMENTS_EXT_INFO
      ; QC Statment Ids
      ; European Union
      szOID_QC_EU_COMPLIANCE equ <"0.4.0.1862.1.1">
      ; Secure Signature Creation Device
      szOID_QC_SSCD equ <"0.4.0.1862.1.4">
      ;+-------------------------------------------------------------------------
      ;  X509_OBJECT_IDENTIFIER
      ;  szOID_ECC_PUBLIC_KEY
      ;  pvStructInfo points to a LPSTR of the dot representation.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  X509_ALGORITHM_IDENTIFIER
      ;  szOID_ECDSA_SPECIFIED
      ;  pvStructInfo points to a CRYPT_ALGORITHM_IDENTIFIER.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  PKCS_RSA_SSA_PSS_PARAMETERS
      ;  szOID_RSA_SSA_PSS
      ;  pvStructInfo points to the following CRYPT_RSA_SSA_PSS_PARAMETERS
      ;  data structure.
      ;  For encoding uses the following defaults if the corresponding field
      ;  is set to NULL or 0:
      ;      HashAlgorithm.pszObjId : szOID_OIWSEC_sha1
      ;      MaskGenAlgorithm.pszObjId : szOID_RSA_MGF1
      ;      MaskGenAlgorithm.HashAlgorithm.pszObjId : HashAlgorithm.pszObjId
      ;      dwSaltLength: cbHash
      ;      dwTrailerField : PKCS_RSA_SSA_PSS_TRAILER_FIELD_BC
      ;  Normally for encoding, only the HashAlgorithm.pszObjId field will
      ;  need to be set.
      ;  For decoding, all of fields are explicitly set.
      ;--------------------------------------------------------------------------
      CRYPT_MASK_GEN_ALGORITHM struct
        pszObjId POINTER ?
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
      ;+-------------------------------------------------------------------------
      ;  PKCS_RSAES_OAEP_PARAMETERS
      ;  szOID_RSAES_OAEP
      ;  pvStructInfo points to the following CRYPT_RSAES_OAEP_PARAMETERS
      ;  data structure.
      ;  For encoding uses the following defaults if the corresponding field
      ;  is set to NULL or 0:
      ;      HashAlgorithm.pszObjId : szOID_OIWSEC_sha1
      ;      MaskGenAlgorithm.pszObjId : szOID_RSA_MGF1
      ;      MaskGenAlgorithm.HashAlgorithm.pszObjId : HashAlgorithm.pszObjId
      ;      PSourceAlgorithm.pszObjId : szOID_RSA_PSPECIFIED
      ;      PSourceAlgorithm.EncodingParameters.cbData : 0
      ;      PSourceAlgorithm.EncodingParameters.pbData : NULL
      ;  Normally for encoding, only the HashAlgorithm.pszObjId field will
      ;  need to be set.
      ;  For decoding, all of fields are explicitly set.
      ;--------------------------------------------------------------------------
      CRYPT_PSOURCE_ALGORITHM struct
        pszObjId POINTER ?
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
      ;+-------------------------------------------------------------------------
      ;  PKCS7_SIGNER_INFO
      ;  pvStructInfo points to CMSG_SIGNER_INFO.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  CMS_SIGNER_INFO
      ;  pvStructInfo points to CMSG_CMS_SIGNER_INFO.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  Verisign Certificate Extension Object Identifiers
      ;--------------------------------------------------------------------------
      ; Octet String containing Boolean
      szOID_VERISIGN_PRIVATE_6_9 equ <"2.16.840.1.113733.1.6.9">
      ; Octet String containing IA5 string: lower case 32 char hex string
      szOID_VERISIGN_ONSITE_JURISDICTION_HASH equ <"2.16.840.1.113733.1.6.11">
      ; Octet String containing Bit string
      szOID_VERISIGN_BITSTRING_6_13 equ <"2.16.840.1.113733.1.6.13">
      ; EKU
      szOID_VERISIGN_ISS_STRONG_CRYPTO equ <"2.16.840.1.113733.1.8.1">
      ;+-------------------------------------------------------------------------
      ;  Verisign SCEP Signed Pkcs7 authenticated attribute Object Identifiers
      ;--------------------------------------------------------------------------
      ; Signed decimal strings encoded as Printable String
      szOIDVerisign_MessageType equ <"2.16.840.1.113733.1.9.2">
      szOIDVerisign_PkiStatus equ <"2.16.840.1.113733.1.9.3">
      szOIDVerisign_FailInfo equ <"2.16.840.1.113733.1.9.4">
      ; Binary data encoded as Octet String
      szOIDVerisign_SenderNonce equ <"2.16.840.1.113733.1.9.5">
      szOIDVerisign_RecipientNonce equ <"2.16.840.1.113733.1.9.6">
      ; Binary data converted to hexadecimal string and encoded as Printable String
      szOIDVerisign_TransactionID equ <"2.16.840.1.113733.1.9.7">
      ;+-------------------------------------------------------------------------
      ;  Netscape Certificate Extension Object Identifiers
      ;--------------------------------------------------------------------------
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
      ;+-------------------------------------------------------------------------
      ;  Netscape Certificate Data Type Object Identifiers
      ;--------------------------------------------------------------------------
      szOID_NETSCAPE_DATA_TYPE equ <"2.16.840.1.113730.2">
      szOID_NETSCAPE_CERT_SEQUENCE equ <"2.16.840.1.113730.2.5">
      ;+-------------------------------------------------------------------------
      ;  szOID_NETSCAPE_CERT_TYPE extension
      ;  Its value is a bit string. CryptDecodeObject/CryptEncodeObject using
      ;  X509_BITS or X509_BITS_WITHOUT_TRAILING_ZEROES.
      ;  The following bits are defined:
      ;--------------------------------------------------------------------------
      NETSCAPE_SSL_CLIENT_AUTH_CERT_TYPE equ 80h
      NETSCAPE_SSL_SERVER_AUTH_CERT_TYPE equ 40h
      NETSCAPE_SMIME_CERT_TYPE equ 20h
      NETSCAPE_SIGN_CERT_TYPE equ 10h
      NETSCAPE_SSL_CA_CERT_TYPE equ 04h
      NETSCAPE_SMIME_CA_CERT_TYPE equ 02h
      NETSCAPE_SIGN_CA_CERT_TYPE equ 01h
      ;+-------------------------------------------------------------------------
      ;  szOID_NETSCAPE_BASE_URL extension
      ;  Its value is an IA5_STRING. CryptDecodeObject/CryptEncodeObject using
      ;  X509_ANY_STRING or X509_UNICODE_ANY_STRING, where,
      ;  dwValueType = CERT_RDN_IA5_STRING.
      ;  When present this string is added to the beginning of all relative URLs
      ;  in the certificate.  This extension can be considered an optimization
      ;  to reduce the size of the URL extensions.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  szOID_NETSCAPE_REVOCATION_URL extension
      ;  Its value is an IA5_STRING. CryptDecodeObject/CryptEncodeObject using
      ;  X509_ANY_STRING or X509_UNICODE_ANY_STRING, where,
      ;  dwValueType = CERT_RDN_IA5_STRING.
      ;  It is a relative or absolute URL that can be used to check the
      ;  revocation status of a certificate. The revocation check will be
      ;  performed as an HTTP GET method using a url that is the concatenation of
      ;  revocation-url and certificate-serial-number.
      ;  Where the certificate-serial-number is encoded as a string of
      ;  ascii hexadecimal digits. For example, if the netscape-base-url is
      ;  https://www.certs-r-us.com/, the netscape-revocation-url is
      ;  cgi-bin/check-rev.cgi?, and the certificate serial number is 173420,
      ;  the resulting URL would be:
      ;  https://www.certs-r-us.com/cgi-bin/check-rev.cgi?02a56c
      ;  The server should return a document with a Content-Type of
      ;  application/x-netscape-revocation.  The document should contain
      ;  a single ascii digit, '1' if the certificate is not curently valid,
      ;  and '0' if it is curently valid.
      ;  Note: for all of the URLs that include the certificate serial number,
      ;  the serial number will be encoded as a string which consists of an even
      ;  number of hexadecimal digits.  If the number of significant digits is odd,
      ;  the string will have a single leading zero to ensure an even number of
      ;  digits is generated.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  szOID_NETSCAPE_CA_REVOCATION_URL extension
      ;  Its value is an IA5_STRING. CryptDecodeObject/CryptEncodeObject using
      ;  X509_ANY_STRING or X509_UNICODE_ANY_STRING, where,
      ;  dwValueType = CERT_RDN_IA5_STRING.
      ;  It is a relative or absolute URL that can be used to check the
      ;  revocation status of any certificates that are signed by the CA that
      ;  this certificate belongs to. This extension is only valid in CA
      ;  certificates.  The use of this extension is the same as the above
      ;  szOID_NETSCAPE_REVOCATION_URL extension.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  szOID_NETSCAPE_CERT_RENEWAL_URL extension
      ;  Its value is an IA5_STRING. CryptDecodeObject/CryptEncodeObject using
      ;  X509_ANY_STRING or X509_UNICODE_ANY_STRING, where,
      ;  dwValueType = CERT_RDN_IA5_STRING.
      ;  It is a relative or absolute URL that points to a certificate renewal
      ;  form. The renewal form will be accessed with an HTTP GET method using a
      ;  url that is the concatenation of renewal-url and
      ;  certificate-serial-number. Where the certificate-serial-number is
      ;  encoded as a string of ascii hexadecimal digits. For example, if the
      ;  netscape-base-url is https://www.certs-r-us.com/, the
      ;  netscape-cert-renewal-url is cgi-bin/check-renew.cgi?, and the
      ;  certificate serial number is 173420, the resulting URL would be:
      ;  https://www.certs-r-us.com/cgi-bin/check-renew.cgi?02a56c
      ;  The document returned should be an HTML form that will allow the user
      ;  to request a renewal of their certificate.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  szOID_NETSCAPE_CA_POLICY_URL extension
      ;  Its value is an IA5_STRING. CryptDecodeObject/CryptEncodeObject using
      ;  X509_ANY_STRING or X509_UNICODE_ANY_STRING, where,
      ;  dwValueType = CERT_RDN_IA5_STRING.
      ;  It is a relative or absolute URL that points to a web page that
      ;  describes the policies under which the certificate was issued.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  szOID_NETSCAPE_SSL_SERVER_NAME extension
      ;  Its value is an IA5_STRING. CryptDecodeObject/CryptEncodeObject using
      ;  X509_ANY_STRING or X509_UNICODE_ANY_STRING, where,
      ;  dwValueType = CERT_RDN_IA5_STRING.
      ;  It is a "shell expression" that can be used to match the hostname of the
      ;  SSL server that is using this certificate.  It is recommended that if
      ;  the server's hostname does not match this pattern the user be notified
      ;  and given the option to terminate the SSL connection.  If this extension
      ;  is not present then the CommonName in the certificate subject's
      ;  distinguished name is used for the same purpose.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  szOID_NETSCAPE_COMMENT extension
      ;  Its value is an IA5_STRING. CryptDecodeObject/CryptEncodeObject using
      ;  X509_ANY_STRING or X509_UNICODE_ANY_STRING, where,
      ;  dwValueType = CERT_RDN_IA5_STRING.
      ;  It is a comment that may be displayed to the user when the certificate
      ;  is viewed.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  szOID_NETSCAPE_CERT_SEQUENCE
      ;  Its value is a PKCS#7 ContentInfo structure wrapping a sequence of
      ;  certificates. The value of the contentType field is
      ;  szOID_NETSCAPE_CERT_SEQUENCE, while the content field is the following
      ;  structure:
      ;      CertificateSequence ::= SEQUENCE OF Certificate.
      ;  CryptDecodeObject/CryptEncodeObject using
      ;  PKCS_CONTENT_INFO_SEQUENCE_OF_ANY, where,
      ;  pszObjId = szOID_NETSCAPE_CERT_SEQUENCE and the CRYPT_DER_BLOBs point
      ;  to encoded X509 certificates.
      ;--------------------------------------------------------------------------
      ;+=========================================================================
      ;  Certificate Management Messages over CMS (CMC) Data Structures
      ;==========================================================================
      ; Content Type (request)
      szOID_CT_PKI_DATA equ <"1.3.6.1.5.5.7.12.2">
      ; Content Type (response)
      szOID_CT_PKI_RESPONSE equ <"1.3.6.1.5.5.7.12.3">
      ; Signature value that only contains the hash octets. The parameters for
      ; this algorithm must be present and must be encoded as NULL.
      szOID_PKIX_NO_SIGNATURE equ <"1.3.6.1.5.5.7.6.2">
      szOID_CMC equ <"1.3.6.1.5.5.7.7">
      szOID_CMC_STATUS_INFO equ <"1.3.6.1.5.5.7.7.1">
      szOID_CMC_IDENTIFICATION equ <"1.3.6.1.5.5.7.7.2">
      szOID_CMC_IDENTITY_PROOF equ <"1.3.6.1.5.5.7.7.3">
      szOID_CMC_DATA_RETURN equ <"1.3.6.1.5.5.7.7.4">
      ; Transaction Id (integer)
      szOID_CMC_TRANSACTION_ID equ <"1.3.6.1.5.5.7.7.5">
      ; Sender Nonce (octet string)
      szOID_CMC_SENDER_NONCE equ <"1.3.6.1.5.5.7.7.6">
      ; Recipient Nonce (octet string)
      szOID_CMC_RECIPIENT_NONCE equ <"1.3.6.1.5.5.7.7.7">
      szOID_CMC_ADD_EXTENSIONS equ <"1.3.6.1.5.5.7.7.8">
      szOID_CMC_ENCRYPTED_POP equ <"1.3.6.1.5.5.7.7.9">
      szOID_CMC_DECRYPTED_POP equ <"1.3.6.1.5.5.7.7.10">
      szOID_CMC_LRA_POP_WITNESS equ <"1.3.6.1.5.5.7.7.11">
      ; Issuer Name + Serial
      szOID_CMC_GET_CERT equ <"1.3.6.1.5.5.7.7.15">
      ; Issuer Name [+ CRL Name] + Time [+ Reasons]
      szOID_CMC_GET_CRL equ <"1.3.6.1.5.5.7.7.16">
      ; Issuer Name + Serial [+ Reason] [+ Effective Time] [+ Secret] [+ Comment]
      szOID_CMC_REVOKE_REQUEST equ <"1.3.6.1.5.5.7.7.17">
      ; (octet string) URL-style parameter list (IA5?)
      szOID_CMC_REG_INFO equ <"1.3.6.1.5.5.7.7.18">
      szOID_CMC_RESPONSE_INFO equ <"1.3.6.1.5.5.7.7.19">
      ; (octet string)
      szOID_CMC_QUERY_PENDING equ <"1.3.6.1.5.5.7.7.21">
      szOID_CMC_ID_POP_LINK_RANDOM equ <"1.3.6.1.5.5.7.7.22">
      szOID_CMC_ID_POP_LINK_WITNESS equ <"1.3.6.1.5.5.7.7.23">
      ; optional Name + Integer
      szOID_CMC_ID_CONFIRM_CERT_ACCEPTANCE equ <"1.3.6.1.5.5.7.7.24">
      szOID_CMC_ADD_ATTRIBUTES equ <"1.3.6.1.4.1.311.10.10.1">
      ;+-------------------------------------------------------------------------
      ;  CMC_DATA
      ;  CMC_RESPONSE
      ;  Certificate Management Messages over CMS (CMC) PKIData and Response
      ;  messages.
      ;  For CMC_DATA, pvStructInfo points to a CMC_DATA_INFO.
      ;  CMC_DATA_INFO contains optional arrays of tagged attributes, requests,
      ;  content info and/or arbitrary other messages.
      ;  For CMC_RESPONSE, pvStructInfo points to a CMC_RESPONSE_INFO.
      ;  CMC_RESPONSE_INFO is the same as CMC_DATA_INFO without the tagged
      ;  requests.
      ;--------------------------------------------------------------------------
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
          ; CMC_TAGGED_CERT_REQUEST_CHOICE
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
        pszObjId POINTER ?
        Value CRYPT_OBJID_BLOB <>
      CMC_TAGGED_OTHER_MSG ends
      _CMC_TAGGED_OTHER_MSG typedef CMC_TAGGED_OTHER_MSG
      PCMC_TAGGED_OTHER_MSG typedef ptr CMC_TAGGED_OTHER_MSG
      ; All the tagged arrays are optional
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
      ; All the tagged arrays are optional
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
      ;+-------------------------------------------------------------------------
      ;  CMC_STATUS
      ;  Certificate Management Messages over CMS (CMC) Status.
      ;  pvStructInfo points to a CMC_STATUS_INFO.
      ;--------------------------------------------------------------------------
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
        pwszStatusString POINTER ?
        ; OPTIONAL
        dwOtherInfoChoice DWORD ?
        union
          ; CMC_OTHER_INFO_NO_CHOICE
          ;  none
          ; CMC_OTHER_INFO_FAIL_CHOICE
          dwFailInfo DWORD ?
          ; CMC_OTHER_INFO_PEND_CHOICE
          pPendInfo PCMC_PEND_INFO ?
        ends
      CMC_STATUS_INFO ends
      _CMC_STATUS_INFO typedef CMC_STATUS_INFO
      PCMC_STATUS_INFO typedef ptr CMC_STATUS_INFO
      CMC_OTHER_INFO_NO_CHOICE equ 0
      CMC_OTHER_INFO_FAIL_CHOICE equ 1
      CMC_OTHER_INFO_PEND_CHOICE equ 2
      ; dwStatus values
      ; Request was granted
      CMC_STATUS_SUCCESS equ 0
      ; Request failed, more information elsewhere in the message
      CMC_STATUS_FAILED equ 2
      ; The request body part has not yet been processed. Requester is responsible
      ; to poll back. May only be returned for certificate request operations.
      CMC_STATUS_PENDING equ 3
      ; The requested operation is not supported
      CMC_STATUS_NO_SUPPORT equ 4
      ; Confirmation using the idConfirmCertAcceptance control is required
      ; before use of certificate
      CMC_STATUS_CONFIRM_REQUIRED equ 5
      ; dwFailInfo values
      ; Unrecognized or unsupported algorithm
      CMC_FAIL_BAD_ALG equ 0
      ; Integrity check failed
      CMC_FAIL_BAD_MESSAGE_CHECK equ 1
      ; Transaction not permitted or supported
      CMC_FAIL_BAD_REQUEST equ 2
      ; Message time field was not sufficiently close to the system time
      CMC_FAIL_BAD_TIME equ 3
      ; No certificate could be identified matching the provided criteria
      CMC_FAIL_BAD_CERT_ID equ 4
      ; A requested X.509 extension is not supported by the recipient CA.
      CMC_FAIL_UNSUPORTED_EXT equ 5
      ; Private key material must be supplied
      CMC_FAIL_MUST_ARCHIVE_KEYS equ 6
      ; Identification Attribute failed to verify
      CMC_FAIL_BAD_IDENTITY equ 7
      ; Server requires a POP proof before issuing certificate
      CMC_FAIL_POP_REQUIRED equ 8
      ; POP processing failed
      CMC_FAIL_POP_FAILED equ 9
      ; Server policy does not allow key re-use
      CMC_FAIL_NO_KEY_REUSE equ 10
      CMC_FAIL_INTERNAL_CA_ERROR equ 11
      CMC_FAIL_TRY_LATER equ 12
      ;+-------------------------------------------------------------------------
      ;  CMC_ADD_EXTENSIONS
      ;  Certificate Management Messages over CMS (CMC) Add Extensions control
      ;  attribute.
      ;  pvStructInfo points to a CMC_ADD_EXTENSIONS_INFO.
      ;--------------------------------------------------------------------------
      CMC_ADD_EXTENSIONS_INFO struct
        dwCmcDataReference DWORD ?
        cCertReference DWORD ?
        rgdwCertReference POINTER ?
        cExtension DWORD ?
        rgExtension PCERT_EXTENSION ?
      CMC_ADD_EXTENSIONS_INFO ends
      _CMC_ADD_EXTENSIONS_INFO typedef CMC_ADD_EXTENSIONS_INFO
      PCMC_ADD_EXTENSIONS_INFO typedef ptr CMC_ADD_EXTENSIONS_INFO
      ;+-------------------------------------------------------------------------
      ;  CMC_ADD_ATTRIBUTES
      ;  Certificate Management Messages over CMS (CMC) Add Attributes control
      ;  attribute.
      ;  pvStructInfo points to a CMC_ADD_ATTRIBUTES_INFO.
      ;--------------------------------------------------------------------------
      CMC_ADD_ATTRIBUTES_INFO struct
        dwCmcDataReference DWORD ?
        cCertReference DWORD ?
        rgdwCertReference POINTER ?
        cAttribute DWORD ?
        rgAttribute PCRYPT_ATTRIBUTE ?
      CMC_ADD_ATTRIBUTES_INFO ends
      _CMC_ADD_ATTRIBUTES_INFO typedef CMC_ADD_ATTRIBUTES_INFO
      PCMC_ADD_ATTRIBUTES_INFO typedef ptr CMC_ADD_ATTRIBUTES_INFO
      ;+-------------------------------------------------------------------------
      ;  X509_CERTIFICATE_TEMPLATE
      ;  szOID_CERTIFICATE_TEMPLATE
      ;  pvStructInfo points to following CERT_TEMPLATE_EXT data structure.
      ;--------------------------------------------------------------------------
      CERT_TEMPLATE_EXT struct
        pszObjId POINTER ?
        dwMajorVersion DWORD ?
        fMinorVersion DWORD ?
        ; TRUE for a minor version
        dwMinorVersion DWORD ?
      CERT_TEMPLATE_EXT ends
      _CERT_TEMPLATE_EXT typedef CERT_TEMPLATE_EXT
      PCERT_TEMPLATE_EXT typedef ptr CERT_TEMPLATE_EXT
      ;+=========================================================================
      ;  Logotype Extension Data Structures
      ;  X509_LOGOTYPE_EXT
      ;  szOID_LOGOTYPE_EXT
      ;  pvStructInfo points to a CERT_LOGOTYPE_EXT_INFO.
      ;==========================================================================
      CERT_HASHED_URL struct
        HashAlgorithm CRYPT_ALGORITHM_IDENTIFIER <>
        Hash CRYPT_HASH_BLOB <>
        pwszUrl POINTER ?
        ; Encoded as IA5, Optional for
        ; biometric data
      CERT_HASHED_URL ends
      _CERT_HASHED_URL typedef CERT_HASHED_URL
      PCERT_HASHED_URL typedef ptr CERT_HASHED_URL
      CERT_LOGOTYPE_DETAILS struct
        pwszMimeType POINTER ?
        ; Encoded as IA5
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
        ; CERT_LOGOTYPE_GRAY_SCALE_IMAGE_INFO_CHOICE or
        ; CERT_LOGOTYPE_COLOR_IMAGE_INFO_CHOICE
        dwLogotypeImageInfoChoice DWORD ?
        dwFileSize DWORD ?
        ; In octets
        dwXSize DWORD ?
        ; Horizontal size in pixels
        dwYSize DWORD ?
        ; Vertical size in pixels
        dwLogotypeImageResolutionChoice DWORD ?
        union
          ; CERT_LOGOTYPE_NO_IMAGE_RESOLUTION_CHOICE
          ; No resolution value
          ; CERT_LOGOTYPE_BITS_IMAGE_RESOLUTION_CHOICE
          dwNumBits DWORD ?
          ; Resolution in bits
          ; CERT_LOGOTYPE_TABLE_SIZE_IMAGE_RESOLUTION_CHOICE
          dwTableSize DWORD ?
          ; Number of color or grey tones
        ends
        pwszLanguage POINTER ?
        ; Optional. Encoded as IA5.
        ; RFC 3066 Language Tag
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
        ; Optional
      CERT_LOGOTYPE_IMAGE ends
      _CERT_LOGOTYPE_IMAGE typedef CERT_LOGOTYPE_IMAGE
      PCERT_LOGOTYPE_IMAGE typedef ptr CERT_LOGOTYPE_IMAGE
      CERT_LOGOTYPE_AUDIO_INFO struct
        dwFileSize DWORD ?
        ; In octets
        dwPlayTime DWORD ?
        ; In milliseconds
        dwChannels DWORD ?
        ; 1=mono, 2=stereo, 4=quad
        dwSampleRate DWORD ?
        ; Optional. 0 => not present.
        ; Samples per second
        pwszLanguage POINTER ?
        ; Optional. Encoded as IA5.
        ; RFC 3066 Language Tag
      CERT_LOGOTYPE_AUDIO_INFO ends
      _CERT_LOGOTYPE_AUDIO_INFO typedef CERT_LOGOTYPE_AUDIO_INFO
      PCERT_LOGOTYPE_AUDIO_INFO typedef ptr CERT_LOGOTYPE_AUDIO_INFO
      CERT_LOGOTYPE_AUDIO struct
        LogotypeDetails CERT_LOGOTYPE_DETAILS <>
        pLogotypeAudioInfo PCERT_LOGOTYPE_AUDIO_INFO ?
        ; Optional
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
          ; CERT_LOGOTYPE_DIRECT_INFO_CHOICE
          pLogotypeDirectInfo PCERT_LOGOTYPE_DATA ?
          ; CERT_LOGOTYPE_INDIRECT_INFO_CHOICE
          pLogotypeIndirectInfo PCERT_LOGOTYPE_REFERENCE ?
        ends
      CERT_LOGOTYPE_INFO ends
      _CERT_LOGOTYPE_INFO typedef CERT_LOGOTYPE_INFO
      PCERT_LOGOTYPE_INFO typedef ptr CERT_LOGOTYPE_INFO
      CERT_LOGOTYPE_DIRECT_INFO_CHOICE equ 1
      CERT_LOGOTYPE_INDIRECT_INFO_CHOICE equ 2
      CERT_OTHER_LOGOTYPE_INFO struct
        pszObjId POINTER ?
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
        ; Optional
        pSubjectLogo PCERT_LOGOTYPE_INFO ?
        ; Optional
        cOtherLogo DWORD ?
        rgOtherLogo PCERT_OTHER_LOGOTYPE_INFO ?
      CERT_LOGOTYPE_EXT_INFO ends
      _CERT_LOGOTYPE_EXT_INFO typedef CERT_LOGOTYPE_EXT_INFO
      PCERT_LOGOTYPE_EXT_INFO typedef ptr CERT_LOGOTYPE_EXT_INFO
      ;+=========================================================================
      ;  Biometric Extension Data Structures
      ;  X509_BIOMETRIC_EXT
      ;  szOID_BIOMETRIC_EXT
      ;  pvStructInfo points to following CERT_BIOMETRIC_EXT_INFO data structure.
      ;==========================================================================
      CERT_BIOMETRIC_DATA struct
        dwTypeOfBiometricDataChoice DWORD ?
        union
          ; CERT_BIOMETRIC_PREDEFINED_DATA_CHOICE
          dwPredefined DWORD ?
          ; CERT_BIOMETRIC_OID_DATA_CHOICE
          pszObjId POINTER ?
        ends
        HashedUrl CERT_HASHED_URL <>
        ; pwszUrl is Optional.
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
      ;+=========================================================================
      ;  Online Certificate Status Protocol (OCSP) Data Structures
      ;==========================================================================
      ;+-------------------------------------------------------------------------
      ;  OCSP_SIGNED_REQUEST
      ;  OCSP signed request.
      ;  Note, in most instances, pOptionalSignatureInfo will be NULL indicating
      ;  no signature is present.
      ;--------------------------------------------------------------------------
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
        ; Encoded OCSP_REQUEST
        pOptionalSignatureInfo POCSP_SIGNATURE_INFO ?
        ; NULL, no signature
      OCSP_SIGNED_REQUEST_INFO ends
      _OCSP_SIGNED_REQUEST_INFO typedef OCSP_SIGNED_REQUEST_INFO
      POCSP_SIGNED_REQUEST_INFO typedef ptr OCSP_SIGNED_REQUEST_INFO
      ;+-------------------------------------------------------------------------
      ;  OCSP_REQUEST
      ;  ToBeSigned OCSP request.
      ;--------------------------------------------------------------------------
      OCSP_CERT_ID struct
        HashAlgorithm CRYPT_ALGORITHM_IDENTIFIER <>
        ; Normally SHA1
        IssuerNameHash CRYPT_HASH_BLOB <>
        ; Hash of encoded name
        IssuerKeyHash CRYPT_HASH_BLOB <>
        ; Hash of PublicKey bits
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
        ; OPTIONAL
        cRequestEntry DWORD ?
        rgRequestEntry POCSP_REQUEST_ENTRY ?
        cExtension DWORD ?
        rgExtension PCERT_EXTENSION ?
      OCSP_REQUEST_INFO ends
      _OCSP_REQUEST_INFO typedef OCSP_REQUEST_INFO
      POCSP_REQUEST_INFO typedef ptr OCSP_REQUEST_INFO
      OCSP_REQUEST_V1 equ 0
      ;+-------------------------------------------------------------------------
      ;  OCSP_RESPONSE
      ;  OCSP outer, unsigned response wrapper.
      ;--------------------------------------------------------------------------
      OCSP_RESPONSE_INFO struct
        dwStatus DWORD ?
        pszObjId POINTER ?
        ; OPTIONAL, may be NULL
        Value CRYPT_OBJID_BLOB <>
        ; OPTIONAL
      OCSP_RESPONSE_INFO ends
      _OCSP_RESPONSE_INFO typedef OCSP_RESPONSE_INFO
      POCSP_RESPONSE_INFO typedef ptr OCSP_RESPONSE_INFO
      OCSP_SUCCESSFUL_RESPONSE equ 0
      OCSP_MALFORMED_REQUEST_RESPONSE equ 1
      OCSP_INTERNAL_ERROR_RESPONSE equ 2
      OCSP_TRY_LATER_RESPONSE equ 3
      ; 4 is not used
      OCSP_SIG_REQUIRED_RESPONSE equ 5
      OCSP_UNAUTHORIZED_RESPONSE equ 6
      szOID_PKIX_OCSP_BASIC_SIGNED_RESPONSE equ <"1.3.6.1.5.5.7.48.1.1">
      ;+-------------------------------------------------------------------------
      ;  OCSP_BASIC_SIGNED_RESPONSE
      ;  szOID_PKIX_OCSP_BASIC_SIGNED_RESPONSE
      ;  OCSP basic signed response.
      ;--------------------------------------------------------------------------
      OCSP_BASIC_SIGNED_RESPONSE_INFO struct
        ToBeSigned CRYPT_DER_BLOB <>
        ; Encoded OCSP_BASIC_RESPONSE
        SignatureInfo OCSP_SIGNATURE_INFO <>
      OCSP_BASIC_SIGNED_RESPONSE_INFO ends
      _OCSP_BASIC_SIGNED_RESPONSE_INFO typedef OCSP_BASIC_SIGNED_RESPONSE_INFO
      POCSP_BASIC_SIGNED_RESPONSE_INFO typedef ptr OCSP_BASIC_SIGNED_RESPONSE_INFO
      ;+-------------------------------------------------------------------------
      ;  OCSP_BASIC_RESPONSE
      ;  ToBeSigned OCSP basic response.
      ;--------------------------------------------------------------------------
      OCSP_BASIC_REVOKED_INFO struct
        RevocationDate FILETIME <>
        ; See X509_CRL_REASON_CODE for list of reason codes
        dwCrlReasonCode DWORD ?
      OCSP_BASIC_REVOKED_INFO ends
      _OCSP_BASIC_REVOKED_INFO typedef OCSP_BASIC_REVOKED_INFO
      POCSP_BASIC_REVOKED_INFO typedef ptr OCSP_BASIC_REVOKED_INFO
      OCSP_BASIC_RESPONSE_ENTRY struct
        CertId OCSP_CERT_ID <>
        dwCertStatus DWORD ?
        union
          ; OCSP_BASIC_GOOD_CERT_STATUS
          ; OCSP_BASIC_UNKNOWN_CERT_STATUS
          ;  No additional information
          ; OCSP_BASIC_REVOKED_CERT_STATUS
          pRevokedInfo POCSP_BASIC_REVOKED_INFO ?
        ends
        ThisUpdate FILETIME <>
        NextUpdate FILETIME <>
        ; Optional, zero filetime implies
        ; never expires
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
          ; OCSP_BASIC_BY_NAME_RESPONDER_ID
          ByNameResponderId CERT_NAME_BLOB <>
          ; OCSP_BASIC_BY_KEY_RESPONDER_ID
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
      ;+=========================================================================
      ;  TPM CryptEncodeObject/CryptDecodeObject Data Structures
      ;==========================================================================
      ;+-------------------------------------------------------------------------
      ;  szOID_ATTR_SUPPORTED_ALGORITHMS
      ;  pvStructInfo points to following CERT_SUPPORTED_ALGORITHM_INFO.
      ;--------------------------------------------------------------------------
      CERT_SUPPORTED_ALGORITHM_INFO struct
        Algorithm CRYPT_ALGORITHM_IDENTIFIER <>
        IntendedKeyUsage CRYPT_BIT_BLOB <>
        ; OPTIONAL
        IntendedCertPolicies CERT_POLICIES_INFO <>
        ; OPTIONAL
      CERT_SUPPORTED_ALGORITHM_INFO ends
      _CERT_SUPPORTED_ALGORITHM_INFO typedef CERT_SUPPORTED_ALGORITHM_INFO
      PCERT_SUPPORTED_ALGORITHM_INFO typedef ptr CERT_SUPPORTED_ALGORITHM_INFO
      ;+-------------------------------------------------------------------------
      ;  szOID_ATTR_TPM_SPECIFICATION
      ;  pvStructInfo points to following CERT_TPM_SPECIFICATION_INFO.
      ;--------------------------------------------------------------------------
      CERT_TPM_SPECIFICATION_INFO struct
        pwszFamily POINTER ?
        ; Encoded as UTF8
        dwLevel DWORD ?
        dwRevision DWORD ?
      CERT_TPM_SPECIFICATION_INFO ends
      _CERT_TPM_SPECIFICATION_INFO typedef CERT_TPM_SPECIFICATION_INFO
      PCERT_TPM_SPECIFICATION_INFO typedef ptr CERT_TPM_SPECIFICATION_INFO
      ;+-------------------------------------------------------------------------
      ;  szOID_ENROLL_KEY_AFFINITY  -- certificate extension
      ;  pvStructInfo points to a CRYPT_SEQUENCE_OF_ANY.
      ;  The two resulting CRYPT_DER_BLOBs point to a salt blob and a hash result.
      ;  In Pkcs10 requests, the extension will contain an ASN NULL.
      ;--------------------------------------------------------------------------
      ;+=========================================================================
      ;  Object IDentifier (OID) Installable Functions:  Data Structures and APIs
      ;==========================================================================
      HCRYPTOIDFUNCSET typedef ptr
      HCRYPTOIDFUNCADDR typedef ptr
      ; Predefined OID Function Names
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
      ; CryptDllEncodeObject has same function signature as CryptEncodeObject.
      ; CryptDllDecodeObject has same function signature as CryptDecodeObject.
      ; CryptDllEncodeObjectEx has same function signature as CryptEncodeObjectEx.
      ; The Ex version MUST support the CRYPT_ENCODE_ALLOC_FLAG option.
      ; If an Ex function isn't installed or registered, then, attempts to find
      ; a non-EX version. If the ALLOC flag is set, then, CryptEncodeObjectEx,
      ; does the allocation and calls the non-EX version twice.
      ; CryptDllDecodeObjectEx has same function signature as CryptDecodeObjectEx.
      ; The Ex version MUST support the CRYPT_DECODE_ALLOC_FLAG option.
      ; If an Ex function isn't installed or registered, then, attempts to find
      ; a non-EX version. If the ALLOC flag is set, then, CryptDecodeObjectEx,
      ; does the allocation and calls the non-EX version twice.
      ; CryptDllCreateCOMObject has the following signature:
      ;      BOOL WINAPI CryptDllCreateCOMObject(
      ;          _In_ DWORD dwEncodingType,
      ;          _In_ LPCSTR pszOID,
      ;          __In PCRYPT_DATA_BLOB pEncodedContent,
      ;          _In_ DWORD dwFlags,
      ;          _In_ REFIID riid,
      ;          _Outptr_ void **ppvObj);
      ; CertDllVerifyRevocation has the same signature as CertVerifyRevocation
      ;  (See CertVerifyRevocation for details on when called)
      ; CertDllVerifyCTLUsage has the same signature as CertVerifyCTLUsage
      ; CryptDllFindOIDInfo currently is only used to store values used by
      ; CryptFindOIDInfo. See CryptFindOIDInfo() for more details.
      ; CryptDllFindLocalizedName is only used to store localized string
      ; values used by CryptFindLocalizedName. See CryptFindLocalizedName() for
      ; more details.
      ;  Example of a complete OID Function Registry Name:
      ;    HKEY_LOCAL_MACHINE\Software\Microsoft\Cryptography\OID
      ;      Encoding Type 1\CryptDllEncodeObject\1.2.3
      ;  The key's L"Dll" value contains the name of the Dll.
      ;  The key's L"FuncName" value overrides the default function name
      CRYPT_OID_REGPATH equ <"Software\Microsoft\Cryptography\OID">
      CRYPT_OID_REG_ENCODING_TYPE_PREFIX equ <"EncodingType ">
      CRYPT_OID_REG_DLL_VALUE_NAME equ <L("Dll")>
      CRYPT_OID_REG_FUNC_NAME_VALUE_NAME equ <L("FuncName")>
      CRYPT_OID_REG_FUNC_NAME_VALUE_NAME_A equ <"FuncName">
      ; CRYPT_INSTALL_OID_FUNC_BEFORE_FLAG can be set in the key's L"CryptFlags"
      ; value to register the functions before the installed functions.
      ; CryptSetOIDFunctionValue must be called to set this value. L"CryptFlags"
      ; must be set using a dwValueType of REG_DWORD.
      CRYPT_OID_REG_FLAGS_VALUE_NAME equ <L("CryptFlags")>
      ; OID used for Default OID functions
      CRYPT_DEFAULT_OID equ <"DEFAULT">
      CRYPT_OID_FUNC_ENTRY struct
        pszOID =POINTER ?
        pvFuncAddr POINTER ?
      CRYPT_OID_FUNC_ENTRY ends
      _CRYPT_OID_FUNC_ENTRY typedef CRYPT_OID_FUNC_ENTRY
      PCRYPT_OID_FUNC_ENTRY typedef ptr CRYPT_OID_FUNC_ENTRY
      CRYPT_INSTALL_OID_FUNC_BEFORE_FLAG equ 1
      ;+-------------------------------------------------------------------------
      ;  Install a set of callable OID function addresses.
      ;  By default the functions are installed at end of the list.
      ;  Set CRYPT_INSTALL_OID_FUNC_BEFORE_FLAG to install at beginning of list.
      ;  hModule should be updated with the hModule passed to DllMain to prevent
      ;  the Dll containing the function addresses from being unloaded by
      ;  CryptGetOIDFuncAddress/CryptFreeOIDFunctionAddress. This would be the
      ;  case when the Dll has also regsvr32'ed OID functions via
      ;  CryptRegisterOIDFunction.
      ;  DEFAULT functions are installed by setting rgFuncEntry[].pszOID =
      ;  CRYPT_DEFAULT_OID.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CryptInstallOIDFunctionAddress, WIN_STD_CALL_CONV,, <:HMODULE, :DWORD, :LPCSTR, :DWORD, :ptr CRYPT_OID_FUNC_ENTRY, :DWORD>, 24
      ; hModule passed to DllMain
      ;+-------------------------------------------------------------------------
      ;  Initialize and return handle to the OID function set identified by its
      ;  function name.
      ;  If the set already exists, a handle to the existing set is returned.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CryptInitOIDFunctionSet, WIN_STD_CALL_CONV,, <:LPCSTR, :DWORD>, 8
      ;+-------------------------------------------------------------------------
      ;  Search the list of installed functions for an encoding type and OID match.
      ;  If not found, search the registry.
      ;  For success, returns TRUE with *ppvFuncAddr updated with the function's
      ;  address and *phFuncAddr updated with the function address's handle.
      ;  The function's handle is AddRef'ed. CryptFreeOIDFunctionAddress needs to
      ;  be called to release it.
      ;  For a registry match, the Dll containing the function is loaded.
      ;  By default, both the registered and installed function lists are searched.
      ;  Set CRYPT_GET_INSTALLED_OID_FUNC_FLAG to only search the installed list
      ;  of functions. This flag would be set by a registered function to get
      ;  the address of a pre-installed function it was replacing. For example,
      ;  the registered function might handle a new special case and call the
      ;  pre-installed function to handle the remaining cases.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CryptGetOIDFunctionAddress, WIN_STD_CALL_CONV,, <:HCRYPTOIDFUNCSET, :DWORD, :LPCSTR, :DWORD, :ptr ptr, :ptr HCRYPTOIDFUNCADDR>, 24
      CRYPT_GET_INSTALLED_OID_FUNC_FLAG equ 1h
      ;+-------------------------------------------------------------------------
      ;  Get the list of registered default Dll entries for the specified
      ;  function set and encoding type.
      ;  The returned list consists of none, one or more null terminated Dll file
      ;  names. The list is terminated with an empty (L"\0") Dll file name.
      ;  For example: L"first.dll" L"\0" L"second.dll" L"\0" L"\0"
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CryptGetDefaultOIDDllList, WIN_STD_CALL_CONV,, <:HCRYPTOIDFUNCSET, :DWORD, :ptr WCHAR, :ptr DWORD>, 16
      ;+-------------------------------------------------------------------------
      ;  Either: get the first or next installed DEFAULT function OR
      ;  load the Dll containing the DEFAULT function.
      ;  If pwszDll is NULL, search the list of installed DEFAULT functions.
      ;  *phFuncAddr must be set to NULL to get the first installed function.
      ;  Successive installed functions are returned by setting *phFuncAddr
      ;  to the hFuncAddr returned by the previous call.
      ;  If pwszDll is NULL, the input *phFuncAddr
      ;  is always CryptFreeOIDFunctionAddress'ed by this function, even for
      ;  an error.
      ;  If pwszDll isn't NULL, then, attempts to load the Dll and the DEFAULT
      ;  function. *phFuncAddr is ignored upon entry and isn't
      ;  CryptFreeOIDFunctionAddress'ed.
      ;  For success, returns TRUE with *ppvFuncAddr updated with the function's
      ;  address and *phFuncAddr updated with the function address's handle.
      ;  The function's handle is AddRef'ed. CryptFreeOIDFunctionAddress needs to
      ;  be called to release it or CryptGetDefaultOIDFunctionAddress can also
      ;  be called for a NULL pwszDll.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CryptGetDefaultOIDFunctionAddress, WIN_STD_CALL_CONV,, <:HCRYPTOIDFUNCSET, :DWORD, :LPCWSTR, :DWORD, :ptr ptr, :ptr HCRYPTOIDFUNCADDR>, 24
      ;+-------------------------------------------------------------------------
      ;  Releases the handle AddRef'ed and returned by CryptGetOIDFunctionAddress
      ;  or CryptGetDefaultOIDFunctionAddress.
      ;  If a Dll was loaded for the function its unloaded. However, before doing
      ;  the unload, the DllCanUnloadNow function exported by the loaded Dll is
      ;  called. It should return S_FALSE to inhibit the unload or S_TRUE to enable
      ;  the unload. If the Dll doesn't export DllCanUnloadNow, the Dll is unloaded.
      ;  DllCanUnloadNow has the following signature:
      ;      STDAPI  DllCanUnloadNow(void);
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CryptFreeOIDFunctionAddress, WIN_STD_CALL_CONV,, <:HCRYPTOIDFUNCADDR, :DWORD>, 8
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)*
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_PHONE_RESTRICTED or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      ;+-------------------------------------------------------------------------
      ;  Register the Dll containing the function to be called for the specified
      ;  encoding type, function name and OID.
      ;  pwszDll may contain environment-variable strings
      ;  which are ExpandEnvironmentStrings()'ed before loading the Dll.
      ;  In addition to registering the DLL, you may override the
      ;  name of the function to be called. For example,
      ;      pszFuncName = "CryptDllEncodeObject",
      ;      pszOverrideFuncName = "MyEncodeXyz".
      ;  This allows a Dll to export multiple OID functions for the same
      ;  function name without needing to interpose its own OID dispatcher function.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CryptRegisterOIDFunction, WIN_STD_CALL_CONV,, <:DWORD, :LPCSTR, :LPCSTR, :LPCWSTR, :LPCSTR>, 20
      ;+-------------------------------------------------------------------------
      ;  Unregister the Dll containing the function to be called for the specified
      ;  encoding type, function name and OID.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CryptUnregisterOIDFunction, WIN_STD_CALL_CONV,, <:DWORD, :LPCSTR, :LPCSTR>, 12
      ;+-------------------------------------------------------------------------
      ;  Register the Dll containing the default function to be called for the
      ;  specified encoding type and function name.
      ;  Unlike CryptRegisterOIDFunction, you can't override the function name
      ;  needing to be exported by the Dll.
      ;  The Dll is inserted before the entry specified by dwIndex.
      ;    dwIndex == 0, inserts at the beginning.
      ;    dwIndex == CRYPT_REGISTER_LAST_INDEX, appends at the end.
      ;  pwszDll may contain environment-variable strings
      ;  which are ExpandEnvironmentStrings()'ed before loading the Dll.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CryptRegisterDefaultOIDFunction, WIN_STD_CALL_CONV,, <:DWORD, :LPCSTR, :DWORD, :LPCWSTR>, 16
      CRYPT_REGISTER_FIRST_INDEX equ 0
      CRYPT_REGISTER_LAST_INDEX equ 0FFFFFFFFh
      ;+-------------------------------------------------------------------------
      ;  Unregister the Dll containing the default function to be called for
      ;  the specified encoding type and function name.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CryptUnregisterDefaultOIDFunction, WIN_STD_CALL_CONV,, <:DWORD, :LPCSTR, :LPCWSTR>, 12
      ;+-------------------------------------------------------------------------
      ;  Set the value for the specified encoding type, function name, OID and
      ;  value name.
      ;  See RegSetValueEx for the possible value types.
      ;  String types are UNICODE.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CryptSetOIDFunctionValue, WIN_STD_CALL_CONV,, <:DWORD, :LPCSTR, :LPCSTR, :LPCWSTR, :DWORD, :ptr BYTE, :DWORD>, 28
      ;+-------------------------------------------------------------------------
      ;  Get the value for the specified encoding type, function name, OID and
      ;  value name.
      ;  See RegEnumValue for the possible value types.
      ;  String types are UNICODE.
      ;--------------------------------------------------------------------------
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP|WINAPI_PARTITION_PHONE_RESTRICTED | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      @DefProto DllImport, CryptGetOIDFunctionValue, WIN_STD_CALL_CONV,, <:DWORD, :LPCSTR, :LPCSTR, :LPCWSTR, :ptr DWORD, :ptr BYTE, :ptr DWORD>, 28
      TYPE_PFN_CRYPT_ENUM_OID_FUNC typedef proto WIN_STD_CALL_CONV :DWORD, :LPCSTR, :LPCSTR, :DWORD, :ptr DWORD, :ptr LPCWSTR, :ptr ptr BYTE, :ptr DWORD, :ptr
      PFN_CRYPT_ENUM_OID_FUNC typedef ptr TYPE_PFN_CRYPT_ENUM_OID_FUNC

      ;+-------------------------------------------------------------------------
      ;  Enumerate the OID functions identified by their encoding type,
      ;  function name and OID.
      ;  pfnEnumOIDFunc is called for each registry key matching the input
      ;  parameters. Setting dwEncodingType to CRYPT_MATCH_ANY_ENCODING_TYPE matches
      ;  any. Setting pszFuncName or pszOID to NULL matches any.
      ;  Set pszOID == CRYPT_DEFAULT_OID to restrict the enumeration to only the
      ;  DEFAULT functions
      ;  String types are UNICODE.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CryptEnumOIDFunction, WIN_STD_CALL_CONV,, <:DWORD, :LPCSTR, :LPCSTR, :DWORD, :ptr, :PFN_CRYPT_ENUM_OID_FUNC>, 24
      CRYPT_MATCH_ANY_ENCODING_TYPE equ 0FFFFFFFFh
      ;+=========================================================================
      ;  Object IDentifier (OID) Information:  Data Structures and APIs
      ;==========================================================================
      ;+-------------------------------------------------------------------------
      ;  Special ALG_ID's used in CRYPT_OID_INFO
      ;--------------------------------------------------------------------------
      ; Algorithm is only implemented in CNG.
      CALG_OID_INFO_CNG_ONLY equ 0FFFFFFFFh
      ; Algorithm is defined in the encoded parameters. Only supported
      ; using CNG.
      CALG_OID_INFO_PARAMETERS equ 0FFFFFFFEh
      ; Macro to check for a special ALG_ID used in CRYPT_OID_INFO
      IS_SPECIAL_OID_INFO_ALGID macro Algid
        exitm <(Algid >= CALG_OID_INFO_PARAMETERS)>
      endm
      ;+-------------------------------------------------------------------------
      ; Special CNG Algorithms used in CRYPT_OID_INFO
      ;--------------------------------------------------------------------------
      CRYPT_OID_INFO_HASH_PARAMETERS_ALGORITHM equ <L("CryptOIDInfoHashParameters")>
      CRYPT_OID_INFO_ECC_PARAMETERS_ALGORITHM equ <L("CryptOIDInfoECCParameters")>
      CRYPT_OID_INFO_MGF1_PARAMETERS_ALGORITHM equ <L("CryptOIDInfoMgf1Parameters")>
      CRYPT_OID_INFO_NO_SIGN_ALGORITHM equ <L("CryptOIDInfoNoSign")>
      CRYPT_OID_INFO_OAEP_PARAMETERS_ALGORITHM equ <L("CryptOIDInfoOAEPParameters")>
      CRYPT_OID_INFO_ECC_WRAP_PARAMETERS_ALGORITHM equ <L("CryptOIDInfoECCWrapParameters")>
      CRYPT_OID_INFO_NO_PARAMETERS_ALGORITHM equ <L("CryptOIDInfoNoParameters")>
      ;+-------------------------------------------------------------------------
      ;  OID Information
      ;--------------------------------------------------------------------------
      CRYPT_OID_INFO struct
        cbSize DWORD ?
        pszOID =POINTER ?
        pwszName =POINTER ?
        dwGroupId DWORD ?
        union
          dwValue DWORD ?
          Algid ALG_ID ?
          dwLength DWORD ?
        ends
        ExtraInfo CRYPT_DATA_BLOB <>
        ifdef CRYPT_OID_INFO_HAS_EXTRA_FIELDS
          ; Note, if you #define CRYPT_OID_INFO_HAS_EXTRA_FIELDS, then, you
          ; must zero all unused fields in this data structure.
          ; More fields could be added in a future release.
          ; The following 2 fields are set to an empty string, L"", if not defined.
          ; This is the Algid string passed to the BCrypt* and NCrypt* APIs
          ; defined in bcrypt.h and ncrypt.h.
          ; Its only applicable to the following groups:
          ;  CRYPT_HASH_ALG_OID_GROUP_ID
          ;  CRYPT_ENCRYPT_ALG_OID_GROUP_ID
          ;  CRYPT_PUBKEY_ALG_OID_GROUP_ID
          ;  CRYPT_SIGN_ALG_OID_GROUP_ID
          pwszCNGAlgid =POINTER ?
          ; Following is only applicable to the following groups:
          ;  CRYPT_SIGN_ALG_OID_GROUP_ID
          ;      The public key pwszCNGAlgid. For ECC,
          ;      CRYPT_OID_INFO_ECC_PARAMETERS_ALGORITHM.
          ;  CRYPT_PUBKEY_ALG_OID_GROUP_ID
          ;      For the ECC algorithms, CRYPT_OID_INFO_ECC_PARAMETERS_ALGORITHM.
          pwszCNGExtraAlgid =POINTER ?
        endif
      CRYPT_OID_INFO ends
      _CRYPT_OID_INFO typedef CRYPT_OID_INFO
      PCRYPT_OID_INFO typedef ptr CRYPT_OID_INFO
      CCRYPT_OID_INFO typedef CRYPT_OID_INFO
      PCCRYPT_OID_INFO typedef ptr CRYPT_OID_INFO
      ; certenrolld_begin -- CRYPT_*_OID_GROUP_ID
      ;+-------------------------------------------------------------------------
      ;  OID Group IDs
      ;--------------------------------------------------------------------------
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
      ; certenrolld_end
      ; The CRYPT_*_ALG_OID_GROUP_ID's have an Algid. The CRYPT_RDN_ATTR_OID_GROUP_ID
      ; has a dwLength. The CRYPT_EXT_OR_ATTR_OID_GROUP_ID,
      ; CRYPT_ENHKEY_USAGE_OID_GROUP_ID, CRYPT_POLICY_OID_GROUP_ID or
      ; CRYPT_TEMPLATE_OID_GROUP_ID don't have a dwValue.
      ; CRYPT_ENCRYPT_ALG_OID_GROUP_ID has the following optional ExtraInfo
      ; for AES algorithms:
      ;  DWORD[0] - dwBitLength
      ; CRYPT_PUBKEY_ALG_OID_GROUP_ID has the following optional ExtraInfo:
      ;  DWORD[0] - Flags. CRYPT_OID_INHIBIT_SIGNATURE_FORMAT_FLAG can be set to
      ;             inhibit the reformatting of the signature before
      ;             CryptVerifySignature is called or after CryptSignHash
      ;             is called. CRYPT_OID_USE_PUBKEY_PARA_FOR_PKCS7_FLAG can
      ;             be set to include the public key algorithm's parameters
      ;             in the PKCS7's digestEncryptionAlgorithm's parameters.
      ;             CRYPT_OID_NO_NULL_ALGORITHM_PARA_FLAG can be set to omit
      ;             NULL parameters when encoding.
      ; For the ECC named curve public keys
      ;  DWORD[1] - BCRYPT_ECCKEY_BLOB dwMagic field value
      ;  DWORD[2] - dwBitLength. Where BCRYPT_ECCKEY_BLOB's
      ;             cbKey = dwBitLength / 8 + ((dwBitLength % 8) ? 1 : 0)
      CRYPT_OID_INHIBIT_SIGNATURE_FORMAT_FLAG equ 00000001h
      CRYPT_OID_USE_PUBKEY_PARA_FOR_PKCS7_FLAG equ 00000002h
      CRYPT_OID_NO_NULL_ALGORITHM_PARA_FLAG equ 00000004h
      CRYPT_OID_PUBKEY_SIGN_ONLY_FLAG equ 80000000h
      CRYPT_OID_PUBKEY_ENCRYPT_ONLY_FLAG equ 40000000h
      CRYPT_OID_USE_CURVE_NAME_FOR_ENCODE_FLAG equ 20000000h
      CRYPT_OID_USE_CURVE_PARAMETERS_FOR_ENCODE_FLAG equ 10000000h
      ; CRYPT_SIGN_ALG_OID_GROUP_ID has the following optional ExtraInfo:
      ;  DWORD[0] - Public Key Algid.
      ;  DWORD[1] - Flags. Same as above for CRYPT_PUBKEY_ALG_OID_GROUP_ID.
      ;  DWORD[2] - Optional CryptAcquireContext(CRYPT_VERIFYCONTEXT)'s dwProvType.
      ;             If omitted or 0, uses Public Key Algid to select
      ;             appropriate dwProvType for signature verification.
      ; CRYPT_RDN_ATTR_OID_GROUP_ID has the following optional ExtraInfo:
      ;  Array of DWORDs:
      ;   [0 ..] - Null terminated list of acceptable RDN attribute
      ;            value types. An empty list implies CERT_RDN_PRINTABLE_STRING,
      ;            CERT_RDN_UNICODE_STRING, 0.
      ;+-------------------------------------------------------------------------
      ;  Find OID information. Returns NULL if unable to find any information
      ;  for the specified key and group. Note, returns a pointer to a constant
      ;  data structure. The returned pointer MUST NOT be freed.
      ;  dwKeyType's:
      ;    CRYPT_OID_INFO_OID_KEY, pvKey points to a szOID
      ;    CRYPT_OID_INFO_NAME_KEY, pvKey points to a wszName
      ;    CRYPT_OID_INFO_ALGID_KEY, pvKey points to an ALG_ID
      ;    CRYPT_OID_INFO_SIGN_KEY, pvKey points to an array of two ALG_ID's:
      ;      ALG_ID[0] - Hash Algid
      ;      ALG_ID[1] - PubKey Algid
      ;    CRYPT_OID_INFO_CNG_ALGID_KEY, pvKey points to a wszCNGAlgid
      ;    CRYPT_OID_INFO_CNG_SIGN_KEY, pvKey is an array of two
      ;     pwszCNGAlgid's:
      ;      Algid[0] - Hash pwszCNGAlgid
      ;      Algid[1] - PubKey pwszCNGAlgid
      ;  For CRYPT_OID_INFO_NAME_KEY, CRYPT_OID_INFO_CNG_ALGID_KEY and
      ;  CRYPT_OID_INFO_CNG_SIGN_KEY the string comparison is case insensitive.
      ;  Setting dwGroupId to 0, searches all groups according to the dwKeyType.
      ;  Otherwise, only the dwGroupId is searched.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CryptFindOIDInfo, WIN_STD_CALL_CONV,, <:DWORD, :ptr, :DWORD>, 12
      CRYPT_OID_INFO_OID_KEY equ 1
      CRYPT_OID_INFO_NAME_KEY equ 2
      CRYPT_OID_INFO_ALGID_KEY equ 3
      CRYPT_OID_INFO_SIGN_KEY equ 4
      CRYPT_OID_INFO_CNG_ALGID_KEY equ 5
      CRYPT_OID_INFO_CNG_SIGN_KEY equ 6
      ; Set the following in the above dwKeyType parameter to restrict public keys
      ; valid for signing or encrypting
      ; certenrolld_begin -- CRYPT_*_KEY_FLAG
      CRYPT_OID_INFO_OID_KEY_FLAGS_MASK equ 0FFFF0000h
      CRYPT_OID_INFO_PUBKEY_SIGN_KEY_FLAG equ 80000000h
      CRYPT_OID_INFO_PUBKEY_ENCRYPT_KEY_FLAG equ 40000000h
      ; The following flag can be set in above dwGroupId parameter to disable
      ; searching the directory server
      CRYPT_OID_DISABLE_SEARCH_DS_FLAG equ 80000000h
      ifdef CRYPT_OID_INFO_HAS_EXTRA_FIELDS
        ; The following flag can be set in above dwGroupId parameter to search
        ; through CRYPT_OID_INFO records. If there are multiple records that meet
        ; the search criteria, the first record with defined pwszCNGAlgid would be
        ; returned. If none of the records (meeting the search criteria) have
        ; pwszCNGAlgid defined, first record (meeting the search criteria) would be
        ; returned.
        CRYPT_OID_PREFER_CNG_ALGID_FLAG equ 40000000h
      endif
      ; certenrolld_end -- CRYPT_*_KEY_FLAG
      ; The bit length shifted left 16 bits can be OR'ed into the above
      ; dwGroupId parameter. Only applicable to the CRYPT_ENCRYPT_ALG_OID_GROUP_ID.
      ; Also, only applicable to encryption algorithms having a dwBitLen ExtraInfo.
      ; Currently, only the AES encryption algorithms have this.
      ; For example, to find the OIDInfo for BCRYPT_AES_ALGORITHM, bit length 192,
      ; CryptFindOIDInfo would be called as follows:
      ;  PCCRYPT_OID_INFO pOIDInfo =
      ;      CryptFindOIDInfo(
      ;          CRYPT_OID_INFO_CNG_ALGID_KEY,
      ;          (void *) BCRYPT_AES_ALGORITHM,
      ;          CRYPT_ENCRYPT_ALG_OID_GROUP_ID |
      ;              (192 << CRYPT_OID_INFO_OID_GROUP_BIT_LEN_SHIFT)
      ;          );
      CRYPT_OID_INFO_OID_GROUP_BIT_LEN_MASK equ 0FFF0000h
      CRYPT_OID_INFO_OID_GROUP_BIT_LEN_SHIFT equ 16
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)*
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_PHONE_RESTRICTED or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      ;+-------------------------------------------------------------------------
      ;  Register OID information. The OID information specified in the
      ;  CCRYPT_OID_INFO structure is persisted to the registry.
      ;  crypt32.dll contains information for the commonly known OIDs. This function
      ;  allows applications to augment crypt32.dll's OID information. During
      ;  CryptFindOIDInfo's first call, the registered OID information is installed.
      ;  By default the registered OID information is installed after crypt32.dll's
      ;  OID entries. Set CRYPT_INSTALL_OID_INFO_BEFORE_FLAG to install before.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CryptRegisterOIDInfo, WIN_STD_CALL_CONV,, <:PCCRYPT_OID_INFO, :DWORD>, 8
      CRYPT_INSTALL_OID_INFO_BEFORE_FLAG equ 1
      ;+-------------------------------------------------------------------------
      ;  Unregister OID information. Only the pszOID and dwGroupId fields are
      ;  used to identify the OID information to be unregistered.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CryptUnregisterOIDInfo, WIN_STD_CALL_CONV,, <:PCCRYPT_OID_INFO>, 4
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP|WINAPI_PARTITION_PHONE_RESTRICTED | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      ; If the callback returns FALSE, stops the enumeration.
      TYPE_PFN_CRYPT_ENUM_OID_INFO typedef proto WIN_STD_CALL_CONV :PCCRYPT_OID_INFO, :ptr
      PFN_CRYPT_ENUM_OID_INFO typedef ptr TYPE_PFN_CRYPT_ENUM_OID_INFO

      ;+-------------------------------------------------------------------------
      ;  Enumerate the OID information.
      ;  pfnEnumOIDInfo is called for each OID information entry.
      ;  Setting dwGroupId to 0 matches all groups. Otherwise, only enumerates
      ;  entries in the specified group.
      ;  dwFlags currently isn't used and must be set to 0.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CryptEnumOIDInfo, WIN_STD_CALL_CONV,, <:DWORD, :DWORD, :ptr, :PFN_CRYPT_ENUM_OID_INFO>, 16
      ;+-------------------------------------------------------------------------
      ;  Find the localized name for the specified name. For example, find the
      ;  localized name for the "Root" system store name. A case insensitive
      ;  string comparison is done.
      ;  Returns NULL if unable to find the the specified name.
      ;  Localized names for the predefined system stores ("Root", "My") and
      ;  predefined physical stores (".Default", ".LocalMachine") are pre-installed
      ;  as resource strings in crypt32.dll. CryptSetOIDFunctionValue can be called
      ;  as follows to register additional localized strings:
      ;      dwEncodingType = CRYPT_LOCALIZED_NAME_ENCODING_TYPE
      ;      pszFuncName = CRYPT_OID_FIND_LOCALIZED_NAME_FUNC
      ;      pszOID = CRYPT_LOCALIZED_NAME_OID
      ;      pwszValueName = Name to be localized, for example, L"ApplicationStore"
      ;      dwValueType = REG_SZ
      ;      pbValueData = pointer to the UNICODE localized string
      ;      cbValueData = (wcslen(UNICODE localized string) + 1) * sizeof(WCHAR)
      ;  To unregister, set pbValueData to NULL and cbValueData to 0.
      ;  The registered names are searched before the pre-installed names.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CryptFindLocalizedName, WIN_STD_CALL_CONV,, <:LPCWSTR>, 4
      CRYPT_LOCALIZED_NAME_ENCODING_TYPE equ 0
      CRYPT_LOCALIZED_NAME_OID equ <"LocalizedNames">
      ;+=========================================================================
      ;  Certificate Strong Signature Defines and Data Structures
      ;==========================================================================
      CERT_STRONG_SIGN_SERIALIZED_INFO struct
        dwFlags DWORD ?
        pwszCNGSignHashAlgids POINTER ?
        pwszCNGPubKeyMinBitLengths POINTER ?
        ; Optional
      CERT_STRONG_SIGN_SERIALIZED_INFO ends
      _CERT_STRONG_SIGN_SERIALIZED_INFO typedef CERT_STRONG_SIGN_SERIALIZED_INFO
      PCERT_STRONG_SIGN_SERIALIZED_INFO typedef ptr CERT_STRONG_SIGN_SERIALIZED_INFO
      CERT_STRONG_SIGN_ECDSA_ALGORITHM equ <L("ECDSA")>
      ; Following CNG Signature Algorithms are supported
      ;  #define BCRYPT_RSA_ALGORITHM                    L"RSA"
      ;  #define BCRYPT_DSA_ALGORITHM                    L"DSA"
      ;  #define CERT_STRONG_SIGN_ECDSA_ALGORITHM        L"ECDSA"
      ; Following CNG Hash Algorithms are supported
      ;  #define BCRYPT_MD5_ALGORITHM                    L"MD5"
      ;  #define BCRYPT_SHA1_ALGORITHM                   L"SHA1"
      ;  #define BCRYPT_SHA256_ALGORITHM                 L"SHA256"
      ;  #define BCRYPT_SHA384_ALGORITHM                 L"SHA384"
      ;  #define BCRYPT_SHA512_ALGORITHM                 L"SHA512"
      CERT_STRONG_SIGN_PARA struct
        cbSize DWORD ?
        dwInfoChoice DWORD ?
        union
          pvInfo POINTER ?
          ; CERT_STRONG_SIGN_SERIALIZED_INFO_CHOICE
          pSerializedInfo PCERT_STRONG_SIGN_SERIALIZED_INFO ?
          ; CERT_STRONG_SIGN_OID_INFO_CHOICE
          pszOID POINTER ?
        ends
      CERT_STRONG_SIGN_PARA ends
      _CERT_STRONG_SIGN_PARA typedef CERT_STRONG_SIGN_PARA
      PCERT_STRONG_SIGN_PARA typedef ptr CERT_STRONG_SIGN_PARA
      PCCERT_STRONG_SIGN_PARA typedef ptr CERT_STRONG_SIGN_PARA
      CERT_STRONG_SIGN_SERIALIZED_INFO_CHOICE equ 1
      CERT_STRONG_SIGN_OID_INFO_CHOICE equ 2
      ; By default, strong signature checking isn't enabled for either
      ; CRLs or OCSP responses.
      CERT_STRONG_SIGN_ENABLE_CRL_CHECK equ 1h
      CERT_STRONG_SIGN_ENABLE_OCSP_CHECK equ 2h
      ; OID Strong Sign Parameters used by Windows OS Components
      szOID_CERT_STRONG_SIGN_OS_PREFIX equ <"1.3.6.1.4.1.311.72.1.">
      ; OS_1 was supported starting with Windows 8
      ;   Requires
      ;     RSA keys >= 2047 or ECDSA >= 256 (DSA not allowed)
      ;     SHA2 hashes (MD2, MD4, MD5 or SHA1 not allowed)
      ;   Both CERT_STRONG_SIGN_ENABLE_CRL_CHECK and
      ;        CERT_STRONG_SIGN_ENABLE_OCSP_CHECK are set
      szOID_CERT_STRONG_SIGN_OS_1 equ <"1.3.6.1.4.1.311.72.1.1">
      szOID_CERT_STRONG_SIGN_OS_CURRENT equ <szOID_CERT_STRONG_SIGN_OS_1>
      CERT_STRONG_SIGN_PARA_OS_1 equ <{ sizeof(CERT_STRONG_SIGN_PARA), CERT_STRONG_SIGN_OID_INFO_CHOICE, szOID_CERT_STRONG_SIGN_OS_1 }>
      CERT_STRONG_SIGN_PARA_OS_CURRENT equ <{ sizeof(CERT_STRONG_SIGN_PARA), CERT_STRONG_SIGN_OID_INFO_CHOICE, szOID_CERT_STRONG_SIGN_OS_CURRENT }>
      szOID_CERT_STRONG_KEY_OS_PREFIX equ <"1.3.6.1.4.1.311.72.2.">
      ; OS_1 was supported starting with Windows 8
      ;   Requires
      ;     RSA keys >= 2047 or ECDSA >= 256 (DSA not allowed)
      ;     SHA1 or SHA2 hashes  (MD2, MD4 or MD5 not allowed)
      ;   Both CERT_STRONG_SIGN_ENABLE_CRL_CHECK and
      ;        CERT_STRONG_SIGN_ENABLE_OCSP_CHECK are set
      szOID_CERT_STRONG_KEY_OS_1 equ <"1.3.6.1.4.1.311.72.2.1">
      szOID_CERT_STRONG_KEY_OS_CURRENT equ <szOID_CERT_STRONG_KEY_OS_1>
      CERT_STRONG_KEY_PARA_OS_1 equ <{ sizeof(CERT_STRONG_SIGN_PARA), CERT_STRONG_SIGN_OID_INFO_CHOICE, szOID_CERT_STRONG_KEY_OS_1 }>
      CERT_STRONG_KEY_PARA_OS_CURRENT equ <{ sizeof(CERT_STRONG_SIGN_PARA), CERT_STRONG_SIGN_OID_INFO_CHOICE, szOID_CERT_STRONG_KEY_OS_CURRENT }>
      ;+=========================================================================
      ;  Low Level Cryptographic Message Data Structures and APIs
      ;==========================================================================
      HCRYPTMSG typedef ptr
      szOID_PKCS_7_DATA equ <"1.2.840.113549.1.7.1">
      szOID_PKCS_7_SIGNED equ <"1.2.840.113549.1.7.2">
      szOID_PKCS_7_ENVELOPED equ <"1.2.840.113549.1.7.3">
      szOID_PKCS_7_SIGNEDANDENVELOPED equ <"1.2.840.113549.1.7.4">
      szOID_PKCS_7_DIGESTED equ <"1.2.840.113549.1.7.5">
      szOID_PKCS_7_ENCRYPTED equ <"1.2.840.113549.1.7.6">
      szOID_PKCS_9_CONTENT_TYPE equ <"1.2.840.113549.1.9.3">
      szOID_PKCS_9_MESSAGE_DIGEST equ <"1.2.840.113549.1.9.4">
      ;+-------------------------------------------------------------------------
      ;  Message types
      ;--------------------------------------------------------------------------
      CMSG_DATA equ 1
      CMSG_SIGNED equ 2
      CMSG_ENVELOPED equ 3
      CMSG_SIGNED_AND_ENVELOPED equ 4
      CMSG_HASHED equ 5
      CMSG_ENCRYPTED equ 6
      ;+-------------------------------------------------------------------------
      ;  Message Type Bit Flags
      ;--------------------------------------------------------------------------
      CMSG_ALL_FLAGS equ (not 0)
      CMSG_DATA_FLAG equ (1 shl CMSG_DATA)
      CMSG_SIGNED_FLAG equ (1 shl CMSG_SIGNED)
      CMSG_ENVELOPED_FLAG equ (1 shl CMSG_ENVELOPED)
      CMSG_SIGNED_AND_ENVELOPED_FLAG equ (1 shl CMSG_SIGNED_AND_ENVELOPED)
      CMSG_HASHED_FLAG equ (1 shl CMSG_HASHED)
      CMSG_ENCRYPTED_FLAG equ (1 shl CMSG_ENCRYPTED)
      ;+-------------------------------------------------------------------------
      ;  Certificate Issuer and SerialNumber
      ;--------------------------------------------------------------------------
      CERT_ISSUER_SERIAL_NUMBER struct
        Issuer CERT_NAME_BLOB <>
        SerialNumber CRYPT_INTEGER_BLOB <>
      CERT_ISSUER_SERIAL_NUMBER ends
      _CERT_ISSUER_SERIAL_NUMBER typedef CERT_ISSUER_SERIAL_NUMBER
      PCERT_ISSUER_SERIAL_NUMBER typedef ptr CERT_ISSUER_SERIAL_NUMBER
      ;+-------------------------------------------------------------------------
      ;  Certificate Identifier
      ;--------------------------------------------------------------------------
      CERT_ID struct
        dwIdChoice DWORD ?
        union
          ; CERT_ID_ISSUER_SERIAL_NUMBER
          IssuerSerialNumber CERT_ISSUER_SERIAL_NUMBER <>
          ; CERT_ID_KEY_IDENTIFIER
          KeyId CRYPT_HASH_BLOB <>
          ; CERT_ID_SHA1_HASH
          HashId CRYPT_HASH_BLOB <>
        ends
      CERT_ID ends
      _CERT_ID typedef CERT_ID
      PCERT_ID typedef ptr CERT_ID
      CERT_ID_ISSUER_SERIAL_NUMBER equ 1
      CERT_ID_KEY_IDENTIFIER equ 2
      CERT_ID_SHA1_HASH equ 3
      ;+-------------------------------------------------------------------------
      ;  The message encode information (pvMsgEncodeInfo) is message type dependent
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  CMSG_DATA: pvMsgEncodeInfo = NULL
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  CMSG_SIGNED
      ;  The pCertInfo in the CMSG_SIGNER_ENCODE_INFO provides the Issuer, SerialNumber
      ;  and PublicKeyInfo.Algorithm. The PublicKeyInfo.Algorithm implicitly
      ;  specifies the HashEncryptionAlgorithm to be used.
      ;  If the SignerId is present with a nonzero dwIdChoice its used instead
      ;  of the Issuer and SerialNumber in pCertInfo.
      ;  CMS supports the KEY_IDENTIFIER and ISSUER_SERIAL_NUMBER CERT_IDs. PKCS #7
      ;  version 1.5 only supports the ISSUER_SERIAL_NUMBER CERT_ID choice.
      ;  If HashEncryptionAlgorithm is present and not NULL its used instead of
      ;  the PublicKeyInfo.Algorithm.
      ;  Note, for RSA, the hash encryption algorithm is normally the same as
      ;  the public key algorithm. For DSA, the hash encryption algorithm is
      ;  normally a DSS signature algorithm.
      ;  pvHashEncryptionAuxInfo currently isn't used and must be set to NULL if
      ;  present in the data structure.
      ;  The hCryptProv and dwKeySpec specify the private key to use. If dwKeySpec
      ;  == 0, then, defaults to AT_SIGNATURE.
      ;  If the HashEncryptionAlgorithm is set to szOID_PKIX_NO_SIGNATURE, then,
      ;  the signature value only contains the hash octets. hCryptProv must still
      ;  be specified. However, since a private key isn't used the hCryptProv can be
      ;  acquired using CRYPT_VERIFYCONTEXT.
      ;  If CMSG_CRYPT_RELEASE_CONTEXT_FLAG is set in the dwFlags
      ;  passed to CryptMsgOpenToEncode(), the signer hCryptProv's are released.
      ;  For CNG, this applies to the hNCryptKey.
      ;  pvHashAuxInfo currently isn't used and must be set to NULL.
      ;  CMS signed messages allow the inclusion of Attribute Certs.
      ;--------------------------------------------------------------------------
      CMSG_SIGNER_ENCODE_INFO struct
        cbSize DWORD ?
        pCertInfo PCERT_INFO ?
        ; NCryptIsKeyHandle() is called to determine the union choice.
        union
          hCryptProv HCRYPTPROV ?
          hNCryptKey NCRYPT_KEY_HANDLE ?
          ifdef CMSG_SIGNER_ENCODE_INFO_HAS_IUM_FIELDS
            hBCryptKey BCRYPT_KEY_HANDLE ?
          endif
        ends
        ; not applicable for hNCryptKey choice
        dwKeySpec DWORD ?
        HashAlgorithm CRYPT_ALGORITHM_IDENTIFIER <>
        pvHashAuxInfo POINTER ?
        cAuthAttr DWORD ?
        rgAuthAttr PCRYPT_ATTRIBUTE ?
        cUnauthAttr DWORD ?
        rgUnauthAttr PCRYPT_ATTRIBUTE ?
        ifdef CMSG_SIGNER_ENCODE_INFO_HAS_CMS_FIELDS
          SignerId CERT_ID <>
          ; This is also referred to as the SignatureAlgorithm
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
      ;+-------------------------------------------------------------------------
      ;  CMSG_ENVELOPED
      ;  The PCERT_INFO for the rgRecipients provides the Issuer, SerialNumber
      ;  and PublicKeyInfo. The PublicKeyInfo.Algorithm implicitly
      ;  specifies the KeyEncryptionAlgorithm to be used.
      ;  The PublicKeyInfo.PublicKey in PCERT_INFO is used to encrypt the content
      ;  encryption key for the recipient.
      ;  hCryptProv is used to do the content encryption, recipient key encryption
      ;  and export. The hCryptProv's private keys aren't used. If hCryptProv
      ;  is NULL, a default hCryptProv is chosen according to the
      ;  ContentEncryptionAlgorithm and the first recipient KeyEncryptionAlgorithm.
      ;  If CMSG_CRYPT_RELEASE_CONTEXT_FLAG is set in the dwFlags
      ;  passed to CryptMsgOpenToEncode(), the envelope's hCryptProv is released.
      ;  Note: CAPI currently doesn't support more than one KeyEncryptionAlgorithm
      ;  per provider. This will need to be fixed.
      ;  Currently, pvEncryptionAuxInfo is only defined for RC2 or RC4 encryption
      ;  algorithms. Otherwise, its not used and must be set to NULL.
      ;  See CMSG_RC2_AUX_INFO for the RC2 encryption algorithms.
      ;  See CMSG_RC4_AUX_INFO for the RC4 encryption algorithms.
      ;  To enable SP3 compatible encryption, pvEncryptionAuxInfo should point to
      ;  a CMSG_SP3_COMPATIBLE_AUX_INFO data structure.
      ;  To enable the CMS envelope enhancements, rgpRecipients must be set to
      ;  NULL, and rgCmsRecipients updated to point to an array of
      ;  CMSG_RECIPIENT_ENCODE_INFO's.
      ;  Also, CMS envelope enhancements support the inclusion of a bag of
      ;  Certs, CRLs, Attribute Certs and/or Unprotected Attributes.
      ;  AES ContentEncryption and ECC KeyAgreement recipients are only supported
      ;  via CNG. DH KeyAgreement or mail list recipients are only supported via
      ;  CAPI1. SP3 compatible encryption and RC4 are only supported via CAPI1.
      ;  For an RSA recipient identified via PCERT_INFO, for AES ContentEncryption,
      ;  szOID_RSAES_OAEP will be implicitly used for the KeyEncryptionAlgorithm.
      ;--------------------------------------------------------------------------
      CMSG_RECIPIENT_ENCODE_INFO typedef _CMSG_RECIPIENT_ENCODE_INFO
      PCMSG_RECIPIENT_ENCODE_INFO typedef ptr _CMSG_RECIPIENT_ENCODE_INFO
      CMSG_ENVELOPED_ENCODE_INFO struct
        cbSize DWORD ?
        hCryptProv HCRYPTPROV_LEGACY ?
        ContentEncryptionAlgorithm CRYPT_ALGORITHM_IDENTIFIER <>
        pvEncryptionAuxInfo POINTER ?
        cRecipients DWORD ?
        ; The following array may only be used for transport recipients identified
        ; by their IssuereAndSerialNumber. If rgpRecipients != NULL, then,
        ; the rgCmsRecipients must be NULL.
        rgpRecipients POINTER ?
        ifdef CMSG_ENVELOPED_ENCODE_INFO_HAS_CMS_FIELDS
          ; If rgCmsRecipients != NULL, then, the above rgpRecipients must be
          ; NULL.
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
      ;+-------------------------------------------------------------------------
      ;  Key Transport Recipient Encode Info
      ;  hCryptProv is used to do the recipient key encryption
      ;  and export. The hCryptProv's private keys aren't used.
      ;  If hCryptProv is NULL, then, the hCryptProv specified in
      ;  CMSG_ENVELOPED_ENCODE_INFO is used.
      ;  Note, even if CMSG_CRYPT_RELEASE_CONTEXT_FLAG is set in the dwFlags
      ;  passed to CryptMsgOpenToEncode(), this hCryptProv isn't released.
      ;  CMS supports the KEY_IDENTIFIER and ISSUER_SERIAL_NUMBER CERT_IDs. PKCS #7
      ;  version 1.5 only supports the ISSUER_SERIAL_NUMBER CERT_ID choice.
      ;  For RSA AES, KeyEncryptionAlgorithm.pszObjId should be set to
      ;  szOID_RSAES_OAEP. KeyEncryptionAlgorithm.Parameters should be set
      ;  to the encoded PKCS_RSAES_OAEP_PARAMETERS. If
      ;  KeyEncryptionAlgorithm.Parameters.cbData == 0, then, the default
      ;  parameters are used and encoded.
      ;--------------------------------------------------------------------------
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
      ;+-------------------------------------------------------------------------
      ;  Key Agreement Recipient Encode Info
      ;  If hCryptProv is NULL, then, the hCryptProv specified in
      ;  CMSG_ENVELOPED_ENCODE_INFO is used.
      ;  For the CMSG_KEY_AGREE_STATIC_KEY_CHOICE, both the hCryptProv and
      ;  dwKeySpec must be specified to select the sender's private key.
      ;  Note, even if CMSG_CRYPT_RELEASE_CONTEXT_FLAG is set in the dwFlags
      ;  passed to CryptMsgOpenToEncode(), this hCryptProv isn't released.
      ;  CMS supports the KEY_IDENTIFIER and ISSUER_SERIAL_NUMBER CERT_IDs.
      ;  There is 1 key choice, ephemeral originator. The originator's ephemeral
      ;  key is generated using the public key algorithm parameters shared
      ;  amongst all the recipients.
      ;  There are 2 key choices: ephemeral originator or static sender. The
      ;  originator's ephemeral key is generated using the public key algorithm
      ;  parameters shared amongst all the recipients. For the static sender its
      ;  private key is used. The hCryptProv and dwKeySpec specify the private key.
      ;  The pSenderId identifies the certificate containing the sender's public key.
      ;  Currently, pvKeyEncryptionAuxInfo isn't used and must be set to NULL.
      ;  If KeyEncryptionAlgorithm.Parameters.cbData == 0, then, its Parameters
      ;  are updated with the encoded KeyWrapAlgorithm.
      ;  Currently, pvKeyWrapAuxInfo is only defined for algorithms with
      ;  RC2. Otherwise, its not used and must be set to NULL.
      ;  When set for RC2 algorithms, points to a CMSG_RC2_AUX_INFO containing
      ;  the RC2 effective key length.
      ;  Note, key agreement recipients are not supported in PKCS #7 version 1.5.
      ;  For the ECC szOID_DH_SINGLE_PASS_STDDH_SHA1_KDF KeyEncryptionAlgorithm
      ;  the CMSG_KEY_AGREE_EPHEMERAL_KEY_CHOICE must be specified.
      ;--------------------------------------------------------------------------
      CMSG_RECIPIENT_ENCRYPTED_KEY_ENCODE_INFO struct
        cbSize DWORD ?
        RecipientPublicKey CRYPT_BIT_BLOB <>
        RecipientId CERT_ID <>
        ; Following fields are optional and only applicable to KEY_IDENTIFIER
        ; CERT_IDs.
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
        ; The following hCryptProv and dwKeySpec must be specified for the
        ; CMSG_KEY_AGREE_STATIC_KEY_CHOICE.
        ; For CMSG_KEY_AGREE_EPHEMERAL_KEY_CHOICE, dwKeySpec isn't applicable
        ; and hCryptProv is optional.
        hCryptProv HCRYPTPROV_LEGACY ?
        dwKeySpec DWORD ?
        dwKeyChoice DWORD ?
        union
          ; CMSG_KEY_AGREE_EPHEMERAL_KEY_CHOICE
          ; The ephemeral public key algorithm and parameters.
          pEphemeralAlgorithm PCRYPT_ALGORITHM_IDENTIFIER ?
          ; CMSG_KEY_AGREE_STATIC_KEY_CHOICE
          ; The CertId of the sender's certificate
          pSenderId PCERT_ID ?
        ends
        UserKeyingMaterial CRYPT_DATA_BLOB <>
        ; OPTIONAL
        cRecipientEncryptedKeys DWORD ?
        rgpRecipientEncryptedKeys POINTER ?
      CMSG_KEY_AGREE_RECIPIENT_ENCODE_INFO ends
      _CMSG_KEY_AGREE_RECIPIENT_ENCODE_INFO typedef CMSG_KEY_AGREE_RECIPIENT_ENCODE_INFO
      PCMSG_KEY_AGREE_RECIPIENT_ENCODE_INFO typedef ptr CMSG_KEY_AGREE_RECIPIENT_ENCODE_INFO
      CMSG_KEY_AGREE_EPHEMERAL_KEY_CHOICE equ 1
      CMSG_KEY_AGREE_STATIC_KEY_CHOICE equ 2
      ;+-------------------------------------------------------------------------
      ;  Mail List Recipient Encode Info
      ;  There is 1 choice for the KeyEncryptionKey: an already created CSP key
      ;  handle. For the key handle choice, hCryptProv must be nonzero. This key
      ;  handle isn't destroyed.
      ;  Note, even if CMSG_CRYPT_RELEASE_CONTEXT_FLAG is set in the dwFlags
      ;  passed to CryptMsgOpenToEncode(), this hCryptProv isn't released.
      ;  Currently, pvKeyEncryptionAuxInfo is only defined for RC2 key wrap
      ;  algorithms. Otherwise, its not used and must be set to NULL.
      ;  When set for RC2 algorithms, points to a CMSG_RC2_AUX_INFO containing
      ;  the RC2 effective key length.
      ;  Note, mail list recipients are not supported in PKCS #7 version 1.5.
      ;  Mail list recipients aren't supported using CNG.
      ;--------------------------------------------------------------------------
      CMSG_MAIL_LIST_RECIPIENT_ENCODE_INFO struct
        cbSize DWORD ?
        KeyEncryptionAlgorithm CRYPT_ALGORITHM_IDENTIFIER <>
        pvKeyEncryptionAuxInfo POINTER ?
        hCryptProv HCRYPTPROV ?
        dwKeyChoice DWORD ?
        union
          ; CMSG_MAIL_LIST_HANDLE_KEY_CHOICE
          hKeyEncryptionKey HCRYPTKEY ?
          ; Reserve space for a potential pointer choice
          pvKeyEncryptionKey POINTER ?
        ends
        KeyId CRYPT_DATA_BLOB <>
        ; Following fields are optional.
        Date FILETIME <>
        pOtherAttr PCRYPT_ATTRIBUTE_TYPE_VALUE ?
      CMSG_MAIL_LIST_RECIPIENT_ENCODE_INFO ends
      _CMSG_MAIL_LIST_RECIPIENT_ENCODE_INFO typedef CMSG_MAIL_LIST_RECIPIENT_ENCODE_INFO
      PCMSG_MAIL_LIST_RECIPIENT_ENCODE_INFO typedef ptr CMSG_MAIL_LIST_RECIPIENT_ENCODE_INFO
      CMSG_MAIL_LIST_HANDLE_KEY_CHOICE equ 1
      ;+-------------------------------------------------------------------------
      ;  Recipient Encode Info
      ;  Note, only key transport recipients are supported in PKCS #7 version 1.5.
      ;--------------------------------------------------------------------------
      _CMSG_RECIPIENT_ENCODE_INFO struct
        dwRecipientChoice DWORD ?
        union
          ; CMSG_KEY_TRANS_RECIPIENT
          pKeyTrans PCMSG_KEY_TRANS_RECIPIENT_ENCODE_INFO ?
          ; CMSG_KEY_AGREE_RECIPIENT
          pKeyAgree PCMSG_KEY_AGREE_RECIPIENT_ENCODE_INFO ?
          ; CMSG_MAIL_LIST_RECIPIENT
          pMailList PCMSG_MAIL_LIST_RECIPIENT_ENCODE_INFO ?
        ends
      _CMSG_RECIPIENT_ENCODE_INFO ends
      CMSG_KEY_TRANS_RECIPIENT equ 1
      CMSG_KEY_AGREE_RECIPIENT equ 2
      CMSG_MAIL_LIST_RECIPIENT equ 3
      ;+-------------------------------------------------------------------------
      ;  CMSG_RC2_AUX_INFO
      ;  AuxInfo for RC2 encryption algorithms. The pvEncryptionAuxInfo field
      ;  in CMSG_ENCRYPTED_ENCODE_INFO should be updated to point to this
      ;  structure. If not specified, defaults to 40 bit.
      ;  Note, this AuxInfo is only used when, the ContentEncryptionAlgorithm's
      ;  Parameter.cbData is zero. Otherwise, the Parameters is decoded to
      ;  get the bit length.
      ;  If CMSG_SP3_COMPATIBLE_ENCRYPT_FLAG is set in dwBitLen, then, SP3
      ;  compatible encryption is done and the bit length is ignored.
      ;--------------------------------------------------------------------------
      CMSG_RC2_AUX_INFO struct
        cbSize DWORD ?
        dwBitLen DWORD ?
      CMSG_RC2_AUX_INFO ends
      _CMSG_RC2_AUX_INFO typedef CMSG_RC2_AUX_INFO
      PCMSG_RC2_AUX_INFO typedef ptr CMSG_RC2_AUX_INFO
      ;+-------------------------------------------------------------------------
      ;  CMSG_SP3_COMPATIBLE_AUX_INFO
      ;  AuxInfo for enabling SP3 compatible encryption.
      ;  The CMSG_SP3_COMPATIBLE_ENCRYPT_FLAG is set in dwFlags to enable SP3
      ;  compatible encryption. When set, uses zero salt instead of no salt,
      ;  the encryption algorithm parameters are NULL instead of containing the
      ;  encoded RC2 parameters or encoded IV octet string and the encrypted
      ;  symmetric key is encoded little endian instead of big endian.
      ;  SP3 compatible encryption isn't supported using CNG.
      ;--------------------------------------------------------------------------
      CMSG_SP3_COMPATIBLE_AUX_INFO struct
        cbSize DWORD ?
        dwFlags DWORD ?
      CMSG_SP3_COMPATIBLE_AUX_INFO ends
      _CMSG_SP3_COMPATIBLE_AUX_INFO typedef CMSG_SP3_COMPATIBLE_AUX_INFO
      PCMSG_SP3_COMPATIBLE_AUX_INFO typedef ptr CMSG_SP3_COMPATIBLE_AUX_INFO
      CMSG_SP3_COMPATIBLE_ENCRYPT_FLAG equ 80000000h
      ;+-------------------------------------------------------------------------
      ;  CMSG_RC4_AUX_INFO
      ;  AuxInfo for RC4 encryption algorithms. The pvEncryptionAuxInfo field
      ;  in CMSG_ENCRYPTED_ENCODE_INFO should be updated to point to this
      ;  structure. If not specified, uses the CSP's default bit length with no
      ;  salt. Note, the base CSP has a 40 bit default and the enhanced CSP has
      ;  a 128 bit default.
      ;  If CMSG_RC4_NO_SALT_FLAG is set in dwBitLen, then, no salt is generated.
      ;  Otherwise, (128 - dwBitLen)/8 bytes of salt are generated and encoded
      ;  as an OCTET STRING in the algorithm parameters field.
      ;  RC4 isn't supported using CNG.
      ;--------------------------------------------------------------------------
      CMSG_RC4_AUX_INFO struct
        cbSize DWORD ?
        dwBitLen DWORD ?
      CMSG_RC4_AUX_INFO ends
      _CMSG_RC4_AUX_INFO typedef CMSG_RC4_AUX_INFO
      PCMSG_RC4_AUX_INFO typedef ptr CMSG_RC4_AUX_INFO
      CMSG_RC4_NO_SALT_FLAG equ 40000000h
      ;+-------------------------------------------------------------------------
      ;  CMSG_SIGNED_AND_ENVELOPED
      ;  For PKCS #7, a signed and enveloped message doesn't have the
      ;  signer's authenticated or unauthenticated attributes. Otherwise, a
      ;  combination of the CMSG_SIGNED_ENCODE_INFO and CMSG_ENVELOPED_ENCODE_INFO.
      ;--------------------------------------------------------------------------
      CMSG_SIGNED_AND_ENVELOPED_ENCODE_INFO struct
        cbSize DWORD ?
        SignedInfo CMSG_SIGNED_ENCODE_INFO <>
        EnvelopedInfo CMSG_ENVELOPED_ENCODE_INFO <>
      CMSG_SIGNED_AND_ENVELOPED_ENCODE_INFO ends
      _CMSG_SIGNED_AND_ENVELOPED_ENCODE_INFO typedef CMSG_SIGNED_AND_ENVELOPED_ENCODE_INFO
      PCMSG_SIGNED_AND_ENVELOPED_ENCODE_INFO typedef ptr CMSG_SIGNED_AND_ENVELOPED_ENCODE_INFO
      ;+-------------------------------------------------------------------------
      ;  CMSG_HASHED
      ;  hCryptProv is used to do the hash. Doesn't need to use a private key.
      ;  If CMSG_CRYPT_RELEASE_CONTEXT_FLAG is set in the dwFlags
      ;  passed to CryptMsgOpenToEncode(), the hCryptProv is released.
      ;  IN LH, the hCryptProv isn't used. However, its still released if the
      ;  above flag is set.
      ;  If fDetachedHash is set, then, the encoded message doesn't contain
      ;  any content (its treated as NULL Data)
      ;  pvHashAuxInfo currently isn't used and must be set to NULL.
      ;--------------------------------------------------------------------------
      CMSG_HASHED_ENCODE_INFO struct
        cbSize DWORD ?
        hCryptProv HCRYPTPROV_LEGACY ?
        HashAlgorithm CRYPT_ALGORITHM_IDENTIFIER <>
        pvHashAuxInfo POINTER ?
      CMSG_HASHED_ENCODE_INFO ends
      _CMSG_HASHED_ENCODE_INFO typedef CMSG_HASHED_ENCODE_INFO
      PCMSG_HASHED_ENCODE_INFO typedef ptr CMSG_HASHED_ENCODE_INFO
      ;+-------------------------------------------------------------------------
      ;  CMSG_ENCRYPTED
      ;  The key used to encrypt the message is identified outside of the message
      ;  content (for example, password).
      ;  The content input to CryptMsgUpdate has already been encrypted.
      ;  pvEncryptionAuxInfo currently isn't used and must be set to NULL.
      ;--------------------------------------------------------------------------
      CMSG_ENCRYPTED_ENCODE_INFO struct
        cbSize DWORD ?
        ContentEncryptionAlgorithm CRYPT_ALGORITHM_IDENTIFIER <>
        pvEncryptionAuxInfo POINTER ?
      CMSG_ENCRYPTED_ENCODE_INFO ends
      _CMSG_ENCRYPTED_ENCODE_INFO typedef CMSG_ENCRYPTED_ENCODE_INFO
      PCMSG_ENCRYPTED_ENCODE_INFO typedef ptr CMSG_ENCRYPTED_ENCODE_INFO
      ;+-------------------------------------------------------------------------
      ;  This parameter allows messages to be of variable length with streamed
      ;  output.
      ;  By default, messages are of a definite length and
      ;  CryptMsgGetParam(CMSG_CONTENT_PARAM) is
      ;  called to get the cryptographically processed content. Until closed,
      ;  the handle keeps a copy of the processed content.
      ;  With streamed output, the processed content can be freed as its streamed.
      ;  If the length of the content to be updated is known at the time of the
      ;  open, then, ContentLength should be set to that length. Otherwise, it
      ;  should be set to CMSG_INDEFINITE_LENGTH.
      ;--------------------------------------------------------------------------
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
      ;+-------------------------------------------------------------------------
      ;  Open dwFlags
      ;--------------------------------------------------------------------------
      CMSG_BARE_CONTENT_FLAG equ 00000001h
      CMSG_LENGTH_ONLY_FLAG equ 00000002h
      CMSG_DETACHED_FLAG equ 00000004h
      CMSG_AUTHENTICATED_ATTRIBUTES_FLAG equ 00000008h
      CMSG_CONTENTS_OCTETS_FLAG equ 00000010h
      CMSG_MAX_LENGTH_FLAG equ 00000020h
      ; When set, nonData type inner content is encapsulated within an
      ; OCTET STRING. Applicable to both Signed and Enveloped messages.
      CMSG_CMS_ENCAPSULATED_CONTENT_FLAG equ 00000040h
      ; If set then the message will not have a signature in the final PKCS7
      ; of SignedData type. Instead the signature will contain plain text of
      ; the to-be-signed hash. It is used with digest signing.
      CMSG_SIGNED_DATA_NO_SIGN_FLAG equ 00000080h
      ; If set, then, the hCryptProv passed to CryptMsgOpenToEncode or
      ; CryptMsgOpenToDecode is released on the final CryptMsgClose.
      ; Not released if CryptMsgOpenToEncode or CryptMsgOpenToDecode fails.
      ; Also applies to hNCryptKey where applicable.
      ; Note, the envelope recipient hCryptProv's aren't released.
      CMSG_CRYPT_RELEASE_CONTEXT_FLAG equ 00008000h
      ;+-------------------------------------------------------------------------
      ;  Open a cryptographic message for encoding
      ;  If CMSG_BARE_CONTENT_FLAG is specified for a streamed message,
      ;  the streamed output will not have an outer ContentInfo wrapper. This
      ;  makes it suitable to be streamed into an enclosing message.
      ;  The pStreamInfo parameter needs to be set to stream the encoded message
      ;  output.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CryptMsgOpenToEncode, WIN_STD_CALL_CONV,, <:DWORD, :DWORD, :DWORD, :ptr, :LPSTR, :PCMSG_STREAM_INFO>, 24
      ;+-------------------------------------------------------------------------
      ;  Calculate the length of an encoded cryptographic message.
      ;  Calculates the length of the encoded message given the
      ;  message type, encoding parameters and total length of
      ;  the data to be updated. Note, this might not be the exact length. However,
      ;  it will always be greater than or equal to the actual length.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CryptMsgCalculateEncodedLength, WIN_STD_CALL_CONV,, <:DWORD, :DWORD, :DWORD, :ptr, :LPSTR, :DWORD>, 24
      ;+-------------------------------------------------------------------------
      ;  Open a cryptographic message for decoding
      ;  hCryptProv specifies the crypto provider to use for hashing and/or
      ;  decrypting the message. If hCryptProv is NULL, a default crypt provider
      ;  is used.
      ;  Currently pRecipientInfo isn't used and should be set to NULL.
      ;  The pStreamInfo parameter needs to be set to stream the decoded content
      ;  output.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CryptMsgOpenToDecode, WIN_STD_CALL_CONV,, <:DWORD, :DWORD, :DWORD, :HCRYPTPROV_LEGACY, :PCERT_INFO, :PCMSG_STREAM_INFO>, 24
      ;+-------------------------------------------------------------------------
      ;  Duplicate a cryptographic message handle
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CryptMsgDuplicate, WIN_STD_CALL_CONV,, <:HCRYPTMSG>, 4
      ;+-------------------------------------------------------------------------
      ;  Close a cryptographic message handle
      ;  LastError is preserved unless FALSE is returned.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CryptMsgClose, WIN_STD_CALL_CONV,, <:HCRYPTMSG>, 4
      ;+-------------------------------------------------------------------------
      ;  Update the content of a cryptographic message. Depending on how the
      ;  message was opened, the content is either encoded or decoded.
      ;  This function is repetitively called to append to the message content.
      ;  fFinal is set to identify the last update. On fFinal, the encode/decode
      ;  is completed. The encoded/decoded content and the decoded parameters
      ;  are valid until the open and all duplicated handles are closed.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CryptMsgUpdate, WIN_STD_CALL_CONV,, <:HCRYPTMSG, :ptr BYTE, :DWORD, :BOOL>, 16
      ;+-------------------------------------------------------------------------
      ;  Get a parameter after encoding/decoding a cryptographic message. Called
      ;  after the final CryptMsgUpdate. Only the CMSG_CONTENT_PARAM and
      ;  CMSG_COMPUTED_HASH_PARAM are valid for an encoded message.
      ;  For an encoded HASHED message, the CMSG_COMPUTED_HASH_PARAM can be got
      ;  before any CryptMsgUpdates to get its length.
      ;  The pvData type definition depends on the dwParamType value.
      ;  Elements pointed to by fields in the pvData structure follow the
      ;  structure. Therefore, *pcbData may exceed the size of the structure.
      ;  Upon input, if *pcbData == 0, then, *pcbData is updated with the length
      ;  of the data and the pvData parameter is ignored.
      ;  Upon return, *pcbData is updated with the length of the data.
      ;  The OBJID BLOBs returned in the pvData structures point to
      ;  their still encoded representation. The appropriate functions
      ;  must be called to decode the information.
      ;  See below for a list of the parameters to get.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CryptMsgGetParam, WIN_STD_CALL_CONV,, <:HCRYPTMSG, :DWORD, :DWORD, :ptr, :ptr DWORD>, 20
      ;+-------------------------------------------------------------------------
      ;  Get parameter types and their corresponding data structure definitions.
      ;--------------------------------------------------------------------------
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
      ;+-------------------------------------------------------------------------
      ;  CMSG_TYPE_PARAM
      ;  The type of the decoded message.
      ;  pvData points to a DWORD
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  CMSG_CONTENT_PARAM
      ;  The encoded content of a cryptographic message. Depending on how the
      ;  message was opened, the content is either the whole PKCS#7
      ;  message (opened to encode) or the inner content (opened to decode).
      ;  In the decode case, the decrypted content is returned, if enveloped.
      ;  If not enveloped, and if the inner content is of type DATA, the returned
      ;  data is the contents octets of the inner content.
      ;  pvData points to the buffer receiving the content bytes
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  CMSG_BARE_CONTENT_PARAM
      ;  The encoded content of an encoded cryptographic message, without the
      ;  outer layer of ContentInfo. That is, only the encoding of the
      ;  ContentInfo.content field is returned.
      ;  pvData points to the buffer receiving the content bytes
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  CMSG_INNER_CONTENT_TYPE_PARAM
      ;  The type of the inner content of a decoded cryptographic message,
      ;  in the form of a NULL-terminated object identifier string
      ;  (eg. "1.2.840.113549.1.7.1").
      ;  pvData points to the buffer receiving the object identifier string
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  CMSG_SIGNER_COUNT_PARAM
      ;  Count of signers in a SIGNED or SIGNED_AND_ENVELOPED message
      ;  pvData points to a DWORD
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  CMSG_SIGNER_CERT_INFO_PARAM
      ;  To get all the signers, repetitively call CryptMsgGetParam, with
      ;  dwIndex set to 0 .. SignerCount - 1.
      ;  pvData points to a CERT_INFO struct.
      ;  Only the following fields have been updated in the CERT_INFO struct:
      ;  Issuer and SerialNumber.
      ;  Note, if the KEYID choice was selected for a CMS SignerId, then, the
      ;  SerialNumber is 0 and the Issuer is encoded containing a single RDN with a
      ;  single Attribute whose OID is szOID_KEYID_RDN, value type is
      ;  CERT_RDN_OCTET_STRING and value is the KEYID. When the
      ;  CertGetSubjectCertificateFromStore and
      ;  CertFindCertificateInStore(CERT_FIND_SUBJECT_CERT) APIs see this
      ;  special KEYID Issuer and SerialNumber, they do a KEYID match.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  CMSG_SIGNER_INFO_PARAM
      ;  To get all the signers, repetitively call CryptMsgGetParam, with
      ;  dwIndex set to 0 .. SignerCount - 1.
      ;  pvData points to a CMSG_SIGNER_INFO struct.
      ;  Note, if the KEYID choice was selected for a CMS SignerId, then, the
      ;  SerialNumber is 0 and the Issuer is encoded containing a single RDN with a
      ;  single Attribute whose OID is szOID_KEYID_RDN, value type is
      ;  CERT_RDN_OCTET_STRING and value is the KEYID. When the
      ;  CertGetSubjectCertificateFromStore and
      ;  CertFindCertificateInStore(CERT_FIND_SUBJECT_CERT) APIs see this
      ;  special KEYID Issuer and SerialNumber, they do a KEYID match.
      ;--------------------------------------------------------------------------
      CMSG_SIGNER_INFO struct
        dwVersion DWORD ?
        Issuer CERT_NAME_BLOB <>
        SerialNumber CRYPT_INTEGER_BLOB <>
        HashAlgorithm CRYPT_ALGORITHM_IDENTIFIER <>
        ; This is also referred to as the SignatureAlgorithm
        HashEncryptionAlgorithm CRYPT_ALGORITHM_IDENTIFIER <>
        EncryptedHash CRYPT_DATA_BLOB <>
        AuthAttrs CRYPT_ATTRIBUTES <>
        UnauthAttrs CRYPT_ATTRIBUTES <>
      CMSG_SIGNER_INFO ends
      _CMSG_SIGNER_INFO typedef CMSG_SIGNER_INFO
      PCMSG_SIGNER_INFO typedef ptr CMSG_SIGNER_INFO
      ;+-------------------------------------------------------------------------
      ;  CMSG_SIGNER_CERT_ID_PARAM
      ;  To get all the signers, repetitively call CryptMsgGetParam, with
      ;  dwIndex set to 0 .. SignerCount - 1.
      ;  pvData points to a CERT_ID struct.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  CMSG_CMS_SIGNER_INFO_PARAM
      ;  Same as CMSG_SIGNER_INFO_PARAM, except, contains SignerId instead of
      ;  Issuer and SerialNumber.
      ;  To get all the signers, repetitively call CryptMsgGetParam, with
      ;  dwIndex set to 0 .. SignerCount - 1.
      ;  pvData points to a CMSG_CMS_SIGNER_INFO struct.
      ;--------------------------------------------------------------------------
      CMSG_CMS_SIGNER_INFO struct
        dwVersion DWORD ?
        SignerId CERT_ID <>
        HashAlgorithm CRYPT_ALGORITHM_IDENTIFIER <>
        ; This is also referred to as the SignatureAlgorithm
        HashEncryptionAlgorithm CRYPT_ALGORITHM_IDENTIFIER <>
        EncryptedHash CRYPT_DATA_BLOB <>
        AuthAttrs CRYPT_ATTRIBUTES <>
        UnauthAttrs CRYPT_ATTRIBUTES <>
      CMSG_CMS_SIGNER_INFO ends
      _CMSG_CMS_SIGNER_INFO typedef CMSG_CMS_SIGNER_INFO
      PCMSG_CMS_SIGNER_INFO typedef ptr CMSG_CMS_SIGNER_INFO
      ;+-------------------------------------------------------------------------
      ;  CMSG_SIGNER_HASH_ALGORITHM_PARAM
      ;  This parameter specifies the HashAlgorithm that was used for the signer.
      ;  Set dwIndex to iterate through all the signers.
      ;  pvData points to an CRYPT_ALGORITHM_IDENTIFIER struct.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  CMSG_SIGNER_AUTH_ATTR_PARAM
      ;  The authenticated attributes for the signer.
      ;  Set dwIndex to iterate through all the signers.
      ;  pvData points to a CMSG_ATTR struct.
      ;--------------------------------------------------------------------------
      CMSG_ATTR typedef CRYPT_ATTRIBUTES
      PCMSG_ATTR typedef ptr CRYPT_ATTRIBUTES
      ;+-------------------------------------------------------------------------
      ;  CMSG_SIGNER_UNAUTH_ATTR_PARAM
      ;  The unauthenticated attributes for the signer.
      ;  Set dwIndex to iterate through all the signers.
      ;  pvData points to a CMSG_ATTR struct.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  CMSG_CERT_COUNT_PARAM
      ;  Count of certificates in a SIGNED or SIGNED_AND_ENVELOPED message.
      ;  CMS, also supports certificates in an ENVELOPED message.
      ;  pvData points to a DWORD
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  CMSG_CERT_PARAM
      ;  To get all the certificates, repetitively call CryptMsgGetParam, with
      ;  dwIndex set to 0 .. CertCount - 1.
      ;  pvData points to an array of the certificate's encoded bytes.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  CMSG_CRL_COUNT_PARAM
      ;  Count of CRLs in a SIGNED or SIGNED_AND_ENVELOPED message.
      ;  CMS, also supports CRLs in an ENVELOPED message.
      ;  pvData points to a DWORD
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  CMSG_CRL_PARAM
      ;  To get all the CRLs, repetitively call CryptMsgGetParam, with
      ;  dwIndex set to 0 .. CrlCount - 1.
      ;  pvData points to an array of the CRL's encoded bytes.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  CMSG_ENVELOPE_ALGORITHM_PARAM
      ;  The ContentEncryptionAlgorithm that was used in
      ;  an ENVELOPED or SIGNED_AND_ENVELOPED message.
      ;  For streaming you must be able to successfully get this parameter before
      ;  doing a CryptMsgControl decrypt.
      ;  pvData points to an CRYPT_ALGORITHM_IDENTIFIER struct.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  CMSG_RECIPIENT_COUNT_PARAM
      ;  Count of recipients in an ENVELOPED or SIGNED_AND_ENVELOPED message.
      ;  Count of key transport recepients.
      ;  The CMSG_CMS_RECIPIENT_COUNT_PARAM has the total count of
      ;  recipients (it also includes key agree and mail list recipients).
      ;  pvData points to a DWORD
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  CMSG_RECIPIENT_INDEX_PARAM
      ;  Index of the recipient used to decrypt an ENVELOPED or SIGNED_AND_ENVELOPED
      ;  message.
      ;  Index of a key transport recipient. If a non key transport
      ;  recipient was used to decrypt, fails with LastError set to
      ;  CRYPT_E_INVALID_INDEX.
      ;  pvData points to a DWORD
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  CMSG_RECIPIENT_INFO_PARAM
      ;  To get all the recipients, repetitively call CryptMsgGetParam, with
      ;  dwIndex set to 0 .. RecipientCount - 1.
      ;  Only returns the key transport recepients.
      ;  The CMSG_CMS_RECIPIENT_INFO_PARAM returns all recipients.
      ;  pvData points to a CERT_INFO struct.
      ;  Only the following fields have been updated in the CERT_INFO struct:
      ;  Issuer, SerialNumber and PublicKeyAlgorithm. The PublicKeyAlgorithm
      ;  specifies the KeyEncryptionAlgorithm that was used.
      ;  Note, if the KEYID choice was selected for a key transport recipient, then,
      ;  the SerialNumber is 0 and the Issuer is encoded containing a single RDN
      ;  with a single Attribute whose OID is szOID_KEYID_RDN, value type is
      ;  CERT_RDN_OCTET_STRING and value is the KEYID. When the
      ;  CertGetSubjectCertificateFromStore and
      ;  CertFindCertificateInStore(CERT_FIND_SUBJECT_CERT) APIs see this
      ;  special KEYID Issuer and SerialNumber, they do a KEYID match.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  CMSG_HASH_ALGORITHM_PARAM
      ;  The HashAlgorithm in a HASHED message.
      ;  pvData points to an CRYPT_ALGORITHM_IDENTIFIER struct.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  CMSG_HASH_DATA_PARAM
      ;  The hash in a HASHED message.
      ;  pvData points to an array of bytes.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  CMSG_COMPUTED_HASH_PARAM
      ;  The computed hash for a HASHED message.
      ;  This may be called for either an encoded or decoded message.
      ;  Also, the computed hash for one of the signer's in a SIGNED message.
      ;  It may be called for either an encoded or decoded message after the
      ;  final update.  Set dwIndex to iterate through all the signers.
      ;  pvData points to an array of bytes.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  CMSG_ENCRYPT_PARAM
      ;  The ContentEncryptionAlgorithm that was used in an ENCRYPTED message.
      ;  pvData points to an CRYPT_ALGORITHM_IDENTIFIER struct.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  CMSG_ENCODED_MESSAGE
      ;  The full encoded message. This is useful in the case of a decoded
      ;  message which has been modified (eg. a signed-data or
      ;  signed-and-enveloped-data message which has been countersigned).
      ;  pvData points to an array of the message's encoded bytes.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  CMSG_VERSION_PARAM
      ;  The version of the decoded message.
      ;  pvData points to a DWORD
      ;--------------------------------------------------------------------------
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
      ;+-------------------------------------------------------------------------
      ;  CMSG_ATTR_CERT_COUNT_PARAM
      ;  Count of attribute certificates in a SIGNED or ENVELOPED message.
      ;  pvData points to a DWORD
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  CMSG_ATTR_CERT_PARAM
      ;  To get all the attribute certificates, repetitively call CryptMsgGetParam,
      ;  with dwIndex set to 0 .. AttrCertCount - 1.
      ;  pvData points to an array of the attribute certificate's encoded bytes.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  CMSG_CMS_RECIPIENT_COUNT_PARAM
      ;  Count of all CMS recipients in an ENVELOPED message.
      ;  pvData points to a DWORD
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  CMSG_CMS_RECIPIENT_INDEX_PARAM
      ;  Index of the CMS recipient used to decrypt an ENVELOPED message.
      ;  pvData points to a DWORD
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  CMSG_CMS_RECIPIENT_ENCRYPTED_KEY_INDEX_PARAM
      ;  For a CMS key agreement recipient, the index of the encrypted key
      ;  used to decrypt an ENVELOPED message.
      ;  pvData points to a DWORD
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  CMSG_CMS_RECIPIENT_INFO_PARAM
      ;  To get all the CMS recipients, repetitively call CryptMsgGetParam, with
      ;  dwIndex set to 0 .. CmsRecipientCount - 1.
      ;  pvData points to a CMSG_CMS_RECIPIENT_INFO struct.
      ;--------------------------------------------------------------------------
      CMSG_KEY_TRANS_RECIPIENT_INFO struct
        dwVersion DWORD ?
        ; Currently, only ISSUER_SERIAL_NUMBER or KEYID choices
        RecipientId CERT_ID <>
        KeyEncryptionAlgorithm CRYPT_ALGORITHM_IDENTIFIER <>
        EncryptedKey CRYPT_DATA_BLOB <>
      CMSG_KEY_TRANS_RECIPIENT_INFO ends
      _CMSG_KEY_TRANS_RECIPIENT_INFO typedef CMSG_KEY_TRANS_RECIPIENT_INFO
      PCMSG_KEY_TRANS_RECIPIENT_INFO typedef ptr CMSG_KEY_TRANS_RECIPIENT_INFO
      CMSG_RECIPIENT_ENCRYPTED_KEY_INFO struct
        ; Currently, only ISSUER_SERIAL_NUMBER or KEYID choices
        RecipientId CERT_ID <>
        EncryptedKey CRYPT_DATA_BLOB <>
        ; The following optional fields are only applicable to KEYID choice
        Date FILETIME <>
        pOtherAttr PCRYPT_ATTRIBUTE_TYPE_VALUE ?
      CMSG_RECIPIENT_ENCRYPTED_KEY_INFO ends
      _CMSG_RECIPIENT_ENCRYPTED_KEY_INFO typedef CMSG_RECIPIENT_ENCRYPTED_KEY_INFO
      PCMSG_RECIPIENT_ENCRYPTED_KEY_INFO typedef ptr CMSG_RECIPIENT_ENCRYPTED_KEY_INFO
      CMSG_KEY_AGREE_RECIPIENT_INFO struct
        dwVersion DWORD ?
        dwOriginatorChoice DWORD ?
        union
          ; CMSG_KEY_AGREE_ORIGINATOR_CERT
          OriginatorCertId CERT_ID <>
          ; CMSG_KEY_AGREE_ORIGINATOR_PUBLIC_KEY
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
        ; The following fields are optional
        Date FILETIME <>
        pOtherAttr PCRYPT_ATTRIBUTE_TYPE_VALUE ?
      CMSG_MAIL_LIST_RECIPIENT_INFO ends
      _CMSG_MAIL_LIST_RECIPIENT_INFO typedef CMSG_MAIL_LIST_RECIPIENT_INFO
      PCMSG_MAIL_LIST_RECIPIENT_INFO typedef ptr CMSG_MAIL_LIST_RECIPIENT_INFO
      CMSG_CMS_RECIPIENT_INFO struct
        dwRecipientChoice DWORD ?
        union
          ; CMSG_KEY_TRANS_RECIPIENT
          pKeyTrans PCMSG_KEY_TRANS_RECIPIENT_INFO ?
          ; CMSG_KEY_AGREE_RECIPIENT
          pKeyAgree PCMSG_KEY_AGREE_RECIPIENT_INFO ?
          ; CMSG_MAIL_LIST_RECIPIENT
          pMailList PCMSG_MAIL_LIST_RECIPIENT_INFO ?
        ends
      CMSG_CMS_RECIPIENT_INFO ends
      _CMSG_CMS_RECIPIENT_INFO typedef CMSG_CMS_RECIPIENT_INFO
      PCMSG_CMS_RECIPIENT_INFO typedef ptr CMSG_CMS_RECIPIENT_INFO
      ; dwVersion numbers for the KeyTrans, KeyAgree and MailList recipients
      CMSG_ENVELOPED_RECIPIENT_V0 equ 0
      CMSG_ENVELOPED_RECIPIENT_V2 equ 2
      CMSG_ENVELOPED_RECIPIENT_V3 equ 3
      CMSG_ENVELOPED_RECIPIENT_V4 equ 4
      CMSG_KEY_TRANS_PKCS_1_5_VERSION equ <CMSG_ENVELOPED_RECIPIENT_V0>
      CMSG_KEY_TRANS_CMS_VERSION equ <CMSG_ENVELOPED_RECIPIENT_V2>
      CMSG_KEY_AGREE_VERSION equ <CMSG_ENVELOPED_RECIPIENT_V3>
      CMSG_MAIL_LIST_VERSION equ <CMSG_ENVELOPED_RECIPIENT_V4>
      ;+-------------------------------------------------------------------------
      ;  CMSG_UNPROTECTED_ATTR_PARAM
      ;  The unprotected attributes in the envelped message.
      ;  pvData points to a CMSG_ATTR struct.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  Perform a special "control" function after the final CryptMsgUpdate of a
      ;  encoded/decoded cryptographic message.
      ;  The dwCtrlType parameter specifies the type of operation to be performed.
      ;  The pvCtrlPara definition depends on the dwCtrlType value.
      ;  See below for a list of the control operations and their pvCtrlPara
      ;  type definition.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CryptMsgControl, WIN_STD_CALL_CONV,, <:HCRYPTMSG, :DWORD, :DWORD, :ptr>, 16
      ;+-------------------------------------------------------------------------
      ;  Message control types
      ;--------------------------------------------------------------------------
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
      ;+-------------------------------------------------------------------------
      ;  CMSG_CTRL_VERIFY_SIGNATURE
      ;  Verify the signature of a SIGNED or SIGNED_AND_ENVELOPED
      ;  message after it has been decoded.
      ;  For a SIGNED_AND_ENVELOPED message, called after
      ;  CryptMsgControl(CMSG_CTRL_DECRYPT), if CryptMsgOpenToDecode was called
      ;  with a NULL pRecipientInfo.
      ;  pvCtrlPara points to a CERT_INFO struct.
      ;  The CERT_INFO contains the Issuer and SerialNumber identifying
      ;  the Signer of the message. The CERT_INFO also contains the
      ;  PublicKeyInfo
      ;  used to verify the signature. The cryptographic provider specified
      ;  in CryptMsgOpenToDecode is used.
      ;  Note, if the message contains CMS signers identified by KEYID, then,
      ;  the CERT_INFO's Issuer and SerialNumber is ignored and only the public
      ;  key is used to find a signer whose signature verifies.
      ;  The following CMSG_CTRL_VERIFY_SIGNATURE_EX should be used instead.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  CMSG_CTRL_VERIFY_SIGNATURE_EX
      ;  Verify the signature of a SIGNED message after it has been decoded.
      ;  pvCtrlPara points to the following CMSG_CTRL_VERIFY_SIGNATURE_EX_PARA.
      ;  If hCryptProv is NULL, uses the cryptographic provider specified in
      ;  CryptMsgOpenToDecode. If CryptMsgOpenToDecode's hCryptProv is also NULL,
      ;  gets default provider according to the signer's public key OID.
      ;  dwSignerIndex is the index of the signer to use to verify the signature.
      ;  The signer can be a pointer to a CERT_PUBLIC_KEY_INFO, certificate
      ;  context or a chain context.
      ;  If the signer's HashEncryptionAlgorithm is szOID_PKIX_NO_SIGNATURE, then,
      ;  the signature is expected to contain the hash octets. Only dwSignerType
      ;  of CMSG_VERIFY_SIGNER_NULL may be specified to verify this no signature
      ;  case.
      ;--------------------------------------------------------------------------
      CMSG_CTRL_VERIFY_SIGNATURE_EX_PARA struct
        cbSize DWORD ?
        hCryptProv HCRYPTPROV_LEGACY ?
        dwSignerIndex DWORD ?
        dwSignerType DWORD ?
        pvSigner POINTER ?
      CMSG_CTRL_VERIFY_SIGNATURE_EX_PARA ends
      _CMSG_CTRL_VERIFY_SIGNATURE_EX_PARA typedef CMSG_CTRL_VERIFY_SIGNATURE_EX_PARA
      PCMSG_CTRL_VERIFY_SIGNATURE_EX_PARA typedef ptr CMSG_CTRL_VERIFY_SIGNATURE_EX_PARA
      ; Signer Types
      CMSG_VERIFY_SIGNER_PUBKEY equ 1
      ; pvSigner :: PCERT_PUBLIC_KEY_INFO
      CMSG_VERIFY_SIGNER_CERT equ 2
      ; pvSigner :: PCCERT_CONTEXT
      CMSG_VERIFY_SIGNER_CHAIN equ 3
      ; pvSigner :: PCCERT_CHAIN_CONTEXT
      CMSG_VERIFY_SIGNER_NULL equ 4
      ; pvSigner :: NULL
      ;+-------------------------------------------------------------------------
      ;  CMSG_CTRL_ENABLE_STRONG_SIGNATURE
      ;  Enables Strong Signature Checking for subsequent verifies.
      ;  pvCtrlPara points to a const CERT_STRONG_SIGN_PARA struct.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  CMSG_CTRL_DECRYPT
      ;  Decrypt an ENVELOPED or SIGNED_AND_ENVELOPED message after it has been
      ;  decoded.
      ;  This decrypt is only applicable to key transport recipients.
      ;  hCryptProv and dwKeySpec specify the private key to use. For dwKeySpec ==
      ;  0, defaults to AT_KEYEXCHANGE.
      ;  hNCryptKey can be set to decrypt using a CNG private key.
      ;  If CMSG_CRYPT_RELEASE_CONTEXT_FLAG is set in the dwFlags passed
      ;  to CryptMsgControl, then, the hCryptProv is released on the final
      ;  CryptMsgClose. Not released if CryptMsgControl fails. Also applies
      ;  to freeing the hNCryptKey.
      ;  dwRecipientIndex is the index of the recipient in the message associated
      ;  with the hCryptProv's or hNCryptKey's private key.
      ;  The dwRecipientIndex is the index of a key transport recipient.
      ;  Note, the message can only be decrypted once.
      ;--------------------------------------------------------------------------
      CMSG_CTRL_DECRYPT_PARA struct
        cbSize DWORD ?
        ; NCryptIsKeyHandle() is called to determine the union choice.
        union
          hCryptProv HCRYPTPROV ?
          hNCryptKey NCRYPT_KEY_HANDLE ?
        ends
        ; not applicable for hNCryptKey choice
        dwKeySpec DWORD ?
        dwRecipientIndex DWORD ?
      CMSG_CTRL_DECRYPT_PARA ends
      _CMSG_CTRL_DECRYPT_PARA typedef CMSG_CTRL_DECRYPT_PARA
      PCMSG_CTRL_DECRYPT_PARA typedef ptr CMSG_CTRL_DECRYPT_PARA
      ;+-------------------------------------------------------------------------
      ;  CMSG_CTRL_KEY_TRANS_DECRYPT
      ;  Decrypt an ENVELOPED message after it has been decoded for a key
      ;  transport recipient.
      ;  hCryptProv and dwKeySpec specify the private key to use. For dwKeySpec ==
      ;  0, defaults to AT_KEYEXCHANGE.
      ;  hNCryptKey can be set to decrypt using a CNG private key.
      ;  If CMSG_CRYPT_RELEASE_CONTEXT_FLAG is set in the dwFlags passed
      ;  to CryptMsgControl, then, the hCryptProv is released on the final
      ;  CryptMsgClose. Not released if CryptMsgControl fails. Also applies
      ;  to freeing the hNCryptKey.
      ;  pKeyTrans points to the CMSG_KEY_TRANS_RECIPIENT_INFO obtained via
      ;  CryptMsgGetParam(CMSG_CMS_RECIPIENT_INFO_PARAM)
      ;  dwRecipientIndex is the index of the recipient in the message associated
      ;  with the hCryptProv's or hNCryptKey's private key.
      ;  Note, the message can only be decrypted once.
      ;--------------------------------------------------------------------------
      CMSG_CTRL_KEY_TRANS_DECRYPT_PARA struct
        cbSize DWORD ?
        ; NCryptIsKeyHandle() is called to determine the union choice.
        union
          hCryptProv HCRYPTPROV ?
          hNCryptKey NCRYPT_KEY_HANDLE ?
        ends
        ; not applicable for hNCryptKey choice
        dwKeySpec DWORD ?
        pKeyTrans PCMSG_KEY_TRANS_RECIPIENT_INFO ?
        dwRecipientIndex DWORD ?
      CMSG_CTRL_KEY_TRANS_DECRYPT_PARA ends
      _CMSG_CTRL_KEY_TRANS_DECRYPT_PARA typedef CMSG_CTRL_KEY_TRANS_DECRYPT_PARA
      PCMSG_CTRL_KEY_TRANS_DECRYPT_PARA typedef ptr CMSG_CTRL_KEY_TRANS_DECRYPT_PARA
      ;+-------------------------------------------------------------------------
      ;  CMSG_CTRL_KEY_AGREE_DECRYPT
      ;  Decrypt an ENVELOPED message after it has been decoded for a key
      ;  agreement recipient.
      ;  hCryptProv and dwKeySpec specify the private key to use. For dwKeySpec ==
      ;  0, defaults to AT_KEYEXCHANGE.
      ;  hNCryptKey can be set to decrypt using a CNG private key.
      ;  If CMSG_CRYPT_RELEASE_CONTEXT_FLAG is set in the dwFlags passed
      ;  to CryptMsgControl, then, the hCryptProv is released on the final
      ;  CryptMsgClose. Not released if CryptMsgControl fails. Also applies
      ;  to freeing the hNCryptKey.
      ;  pKeyAgree points to the CMSG_KEY_AGREE_RECIPIENT_INFO obtained via
      ;  CryptMsgGetParam(CMSG_CMS_RECIPIENT_INFO_PARAM) for dwRecipientIndex.
      ;  dwRecipientIndex, dwRecipientEncryptedKeyIndex are the indices of the
      ;  recipient's encrypted key in the message associated with the hCryptProv's
      ;  or hNCryptKey's private key.
      ;  OriginatorPublicKey is the originator's public key obtained from either
      ;  the originator's certificate or the CMSG_KEY_AGREE_RECIPIENT_INFO obtained
      ;  via the CMSG_CMS_RECIPIENT_INFO_PARAM.
      ;  Note, the message can only be decrypted once.
      ;--------------------------------------------------------------------------
      CMSG_CTRL_KEY_AGREE_DECRYPT_PARA struct
        cbSize DWORD ?
        ; NCryptIsKeyHandle() is called to determine the union choice.
        union
          hCryptProv HCRYPTPROV ?
          hNCryptKey NCRYPT_KEY_HANDLE ?
        ends
        ; not applicable for hNCryptKey choice
        dwKeySpec DWORD ?
        pKeyAgree PCMSG_KEY_AGREE_RECIPIENT_INFO ?
        dwRecipientIndex DWORD ?
        dwRecipientEncryptedKeyIndex DWORD ?
        OriginatorPublicKey CRYPT_BIT_BLOB <>
      CMSG_CTRL_KEY_AGREE_DECRYPT_PARA ends
      _CMSG_CTRL_KEY_AGREE_DECRYPT_PARA typedef CMSG_CTRL_KEY_AGREE_DECRYPT_PARA
      PCMSG_CTRL_KEY_AGREE_DECRYPT_PARA typedef ptr CMSG_CTRL_KEY_AGREE_DECRYPT_PARA
      ;+-------------------------------------------------------------------------
      ;  CMSG_CTRL_MAIL_LIST_DECRYPT
      ;  Decrypt an ENVELOPED message after it has been decoded for a mail
      ;  list recipient.
      ;  pMailList points to the CMSG_MAIL_LIST_RECIPIENT_INFO obtained via
      ;  CryptMsgGetParam(CMSG_CMS_RECIPIENT_INFO_PARAM) for dwRecipientIndex.
      ;  There is 1 choice for the KeyEncryptionKey: an already created CSP key
      ;  handle. For the key handle choice, hCryptProv must be nonzero. This key
      ;  handle isn't destroyed.
      ;  If CMSG_CRYPT_RELEASE_CONTEXT_FLAG is set in the dwFlags passed
      ;  to CryptMsgControl, then, the hCryptProv is released on the final
      ;  CryptMsgClose. Not released if CryptMsgControl fails.
      ;  For RC2 wrap, the effective key length is obtained from the
      ;  KeyEncryptionAlgorithm parameters and set on the hKeyEncryptionKey before
      ;  decrypting.
      ;  Note, the message can only be decrypted once.
      ;  Mail list recipients aren't supported using CNG.
      ;--------------------------------------------------------------------------
      CMSG_CTRL_MAIL_LIST_DECRYPT_PARA struct
        cbSize DWORD ?
        hCryptProv HCRYPTPROV ?
        pMailList PCMSG_MAIL_LIST_RECIPIENT_INFO ?
        dwRecipientIndex DWORD ?
        dwKeyChoice DWORD ?
        union
          ; CMSG_MAIL_LIST_HANDLE_KEY_CHOICE
          hKeyEncryptionKey HCRYPTKEY ?
          ; Reserve space for a potential pointer choice
          pvKeyEncryptionKey POINTER ?
        ends
      CMSG_CTRL_MAIL_LIST_DECRYPT_PARA ends
      _CMSG_CTRL_MAIL_LIST_DECRYPT_PARA typedef CMSG_CTRL_MAIL_LIST_DECRYPT_PARA
      PCMSG_CTRL_MAIL_LIST_DECRYPT_PARA typedef ptr CMSG_CTRL_MAIL_LIST_DECRYPT_PARA
      ;+-------------------------------------------------------------------------
      ;  CMSG_CTRL_VERIFY_HASH
      ;  Verify the hash of a HASHED message after it has been decoded.
      ;  Only the hCryptMsg parameter is used, to specify the message whose
      ;  hash is being verified.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  CMSG_CTRL_ADD_SIGNER
      ;  Add a signer to a signed-data message.
      ;  pvCtrlPara points to a CMSG_SIGNER_ENCODE_INFO.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  CMSG_CTRL_ADD_CMS_SIGNER_INFO
      ;  Add a signer to a signed-data message.
      ;  Differs from the above, CMSG_CTRL_ADD_SIGNER, wherein, the signer info
      ;  already contains the signature.
      ;  pvCtrlPara points to a CMSG_CMS_SIGNER_INFO.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  CMSG_CTRL_DEL_SIGNER
      ;  Remove a signer from a signed-data or signed-and-enveloped-data message.
      ;  pvCtrlPara points to a DWORD containing the 0-based index of the
      ;  signer to be removed.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  CMSG_CTRL_ADD_SIGNER_UNAUTH_ATTR
      ;  Add an unauthenticated attribute to the SignerInfo of a signed-data or
      ;  signed-and-enveloped-data message.
      ;  The unauthenticated attribute is input in the form of an encoded blob.
      ;--------------------------------------------------------------------------
      CMSG_CTRL_ADD_SIGNER_UNAUTH_ATTR_PARA struct
        cbSize DWORD ?
        dwSignerIndex DWORD ?
        blob CRYPT_DATA_BLOB <>
      CMSG_CTRL_ADD_SIGNER_UNAUTH_ATTR_PARA ends
      _CMSG_CTRL_ADD_SIGNER_UNAUTH_ATTR_PARA typedef CMSG_CTRL_ADD_SIGNER_UNAUTH_ATTR_PARA
      PCMSG_CTRL_ADD_SIGNER_UNAUTH_ATTR_PARA typedef ptr CMSG_CTRL_ADD_SIGNER_UNAUTH_ATTR_PARA
      ;+-------------------------------------------------------------------------
      ;  CMSG_CTRL_DEL_SIGNER_UNAUTH_ATTR
      ;  Delete an unauthenticated attribute from the SignerInfo of a signed-data
      ;  or signed-and-enveloped-data message.
      ;  The unauthenticated attribute to be removed is specified by
      ;  a 0-based index.
      ;--------------------------------------------------------------------------
      CMSG_CTRL_DEL_SIGNER_UNAUTH_ATTR_PARA struct
        cbSize DWORD ?
        dwSignerIndex DWORD ?
        dwUnauthAttrIndex DWORD ?
      CMSG_CTRL_DEL_SIGNER_UNAUTH_ATTR_PARA ends
      _CMSG_CTRL_DEL_SIGNER_UNAUTH_ATTR_PARA typedef CMSG_CTRL_DEL_SIGNER_UNAUTH_ATTR_PARA
      PCMSG_CTRL_DEL_SIGNER_UNAUTH_ATTR_PARA typedef ptr CMSG_CTRL_DEL_SIGNER_UNAUTH_ATTR_PARA
      ;+-------------------------------------------------------------------------
      ;  CMSG_CTRL_ADD_CERT
      ;  Add a certificate to a signed-data or signed-and-enveloped-data message.
      ;  pvCtrlPara points to a CRYPT_DATA_BLOB containing the certificate's
      ;  encoded bytes.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  CMSG_CTRL_DEL_CERT
      ;  Delete a certificate from a signed-data or signed-and-enveloped-data
      ;  message.
      ;  pvCtrlPara points to a DWORD containing the 0-based index of the
      ;  certificate to be removed.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  CMSG_CTRL_ADD_CRL
      ;  Add a CRL to a signed-data or signed-and-enveloped-data message.
      ;  pvCtrlPara points to a CRYPT_DATA_BLOB containing the CRL's
      ;  encoded bytes.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  CMSG_CTRL_DEL_CRL
      ;  Delete a CRL from a signed-data or signed-and-enveloped-data message.
      ;  pvCtrlPara points to a DWORD containing the 0-based index of the CRL
      ;  to be removed.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  CMSG_CTRL_ADD_ATTR_CERT
      ;  Add an attribute certificate to a signed-data message.
      ;  pvCtrlPara points to a CRYPT_DATA_BLOB containing the attribute
      ;  certificate's encoded bytes.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  CMSG_CTRL_DEL_ATTR_CERT
      ;  Delete an attribute certificate from a signed-data message.
      ;  pvCtrlPara points to a DWORD containing the 0-based index of the
      ;  attribute certificate to be removed.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  Verify a countersignature, at the SignerInfo level.
      ;  ie. verify that pbSignerInfoCountersignature contains the encrypted
      ;  hash of the encryptedDigest field of pbSignerInfo.
      ;  hCryptProv is used to hash the encryptedDigest field of pbSignerInfo.
      ;  The only fields referenced from pciCountersigner are SerialNumber, Issuer,
      ;  and SubjectPublicKeyInfo.
      ;--------------------------------------------------------------------------
      CryptMsgVerifyCountersignatureEncoded proto WIN_STD_CALL_CONV :HCRYPTPROV_LEGACY, :DWORD, :PBYTE, :DWORD, :PBYTE, :DWORD, :PCERT_INFO
      ;+-------------------------------------------------------------------------
      ;  Verify a countersignature, at the SignerInfo level.
      ;  ie. verify that pbSignerInfoCountersignature contains the encrypted
      ;  hash of the encryptedDigest field of pbSignerInfo.
      ;  hCryptProv is used to hash the encryptedDigest field of pbSignerInfo.
      ;  The signer can be a CERT_PUBLIC_KEY_INFO, certificate context or a
      ;  chain context.
      ;--------------------------------------------------------------------------
      CryptMsgVerifyCountersignatureEncodedEx proto WIN_STD_CALL_CONV :HCRYPTPROV_LEGACY, :DWORD, :PBYTE, :DWORD, :PBYTE, :DWORD, :DWORD, :ptr, :DWORD, :ptr
      ; See CMSG_CTRL_VERIFY_SIGNATURE_EX_PARA for dwSignerType definitions
      ; When set, pvExtra points to const CERT_STRONG_SIGN_PARA struct
      CMSG_VERIFY_COUNTER_SIGN_ENABLE_STRONG_FLAG equ 00000001h
      ;+-------------------------------------------------------------------------
      ;  Countersign an already-existing signature in a message
      ;  dwIndex is a zero-based index of the SignerInfo to be countersigned.
      ;--------------------------------------------------------------------------
      CryptMsgCountersign proto WIN_STD_CALL_CONV :HCRYPTMSG, :DWORD, :DWORD, :PCMSG_SIGNER_ENCODE_INFO
      ;+-------------------------------------------------------------------------
      ;  Countersign an already-existing signature (encoded SignerInfo).
      ;  Output an encoded SignerInfo blob, suitable for use as a countersignature
      ;  attribute in the unauthenticated attributes of a signed-data or
      ;  signed-and-enveloped-data message.
      ;--------------------------------------------------------------------------
      CryptMsgCountersignEncoded proto WIN_STD_CALL_CONV :DWORD, :PBYTE, :DWORD, :DWORD, :PCMSG_SIGNER_ENCODE_INFO, :PBYTE, :PDWORD
      ;+-------------------------------------------------------------------------
      ;  CryptMsg OID installable functions
      ;--------------------------------------------------------------------------
      TYPE_PFN_CMSG_ALLOC typedef proto WIN_STD_CALL_CONV :size_t
      PFN_CMSG_ALLOC typedef ptr TYPE_PFN_CMSG_ALLOC

      TYPE_PFN_CMSG_FREE typedef proto WIN_STD_CALL_CONV :ptr
      PFN_CMSG_FREE typedef ptr TYPE_PFN_CMSG_FREE

      ; Note, the following 3 installable functions are obsolete and have been
      ; replaced with GenContentEncryptKey, ExportKeyTrans, ExportKeyAgree,
      ; ExportMailList, ImportKeyTrans, ImportKeyAgree and ImportMailList
      ; installable functions.
      ; If *phCryptProv is NULL upon entry, then, if supported, the installable
      ; function should acquire a default provider and return. Note, its up
      ; to the installable function to release at process detach.
      ; If paiEncrypt->Parameters.cbData is 0, then, the callback may optionally
      ; return default encoded parameters in *ppbEncryptParameters and
      ; *pcbEncryptParameters. pfnAlloc must be called for the allocation.
      CMSG_OID_GEN_ENCRYPT_KEY_FUNC equ <"CryptMsgDllGenEncryptKey">
      TYPE_PFN_CMSG_GEN_ENCRYPT_KEY typedef proto WIN_STD_CALL_CONV :ptr HCRYPTPROV, :PCRYPT_ALGORITHM_IDENTIFIER, :PVOID, :PCERT_PUBLIC_KEY_INFO, :PFN_CMSG_ALLOC, :ptr HCRYPTKEY, :ptr PBYTE, :PDWORD
      PFN_CMSG_GEN_ENCRYPT_KEY typedef ptr TYPE_PFN_CMSG_GEN_ENCRYPT_KEY

      CMSG_OID_EXPORT_ENCRYPT_KEY_FUNC equ <"CryptMsgDllExportEncryptKey">
      TYPE_PFN_CMSG_EXPORT_ENCRYPT_KEY typedef proto WIN_STD_CALL_CONV :HCRYPTPROV, :HCRYPTKEY, :PCERT_PUBLIC_KEY_INFO, :PBYTE, :PDWORD
      PFN_CMSG_EXPORT_ENCRYPT_KEY typedef ptr TYPE_PFN_CMSG_EXPORT_ENCRYPT_KEY

      CMSG_OID_IMPORT_ENCRYPT_KEY_FUNC equ <"CryptMsgDllImportEncryptKey">
      TYPE_PFN_CMSG_IMPORT_ENCRYPT_KEY typedef proto WIN_STD_CALL_CONV :HCRYPTPROV, :DWORD, :PCRYPT_ALGORITHM_IDENTIFIER, :PCRYPT_ALGORITHM_IDENTIFIER, :PBYTE, :DWORD, :ptr HCRYPTKEY
      PFN_CMSG_IMPORT_ENCRYPT_KEY typedef ptr TYPE_PFN_CMSG_IMPORT_ENCRYPT_KEY

      ; To get the default installable function for GenContentEncryptKey,
      ; ExportKeyTrans, ExportKeyAgree, ExportMailList, ImportKeyTrans,
      ; ImportKeyAgree or ImportMailList call CryptGetOIDFunctionAddress()
      ; with the pszOID argument set to the following constant. dwEncodingType
      ; should be set to CRYPT_ASN_ENCODING or X509_ASN_ENCODING.
      CMSG_DEFAULT_INSTALLABLE_FUNC_OID equ (1)
      ;+-------------------------------------------------------------------------
      ;  Content Encrypt Info
      ;  The following data structure contains the information shared between
      ;  the GenContentEncryptKey and the ExportKeyTrans, ExportKeyAgree and
      ;  ExportMailList installable functions.
      ;  For a ContentEncryptionAlgorithm.pszObjId having a "Special" algid, only
      ;  supported via CNG, for example, AES, then, fCNG will be set.
      ;  fCNG will also be set to TRUE for any ECC agreement or OAEP RSA transport
      ;  recipients.
      ;  When, fCNG is TRUE, the hCNGContentEncryptKey choice is selected and
      ;  pbCNGContentEncryptKeyObject and pbContentEncryptKey will be pfnAlloc'ed.
      ;--------------------------------------------------------------------------
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
          ; fCNG == FALSE
          hContentEncryptKey HCRYPTKEY ?
          ; fCNG == TRUE
          hCNGContentEncryptKey BCRYPT_KEY_HANDLE ?
        ends
        dwFlags DWORD ?
        fCNG DWORD ?
        ; When fCNG == TRUE, pfnAlloc'ed
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
      ;+-------------------------------------------------------------------------
      ; Upon input, ContentEncryptInfo has been initialized from the
      ; EnvelopedEncodeInfo.
      ; Note, if rgpRecipients instead of rgCmsRecipients are set in the
      ; EnvelopedEncodeInfo, then, the rgpRecipients have been converted
      ; to rgCmsRecipients in the ContentEncryptInfo.
      ; For fCNG == FALSE, the following fields may be changed in ContentEncryptInfo:
      ;      hContentEncryptKey
      ;      hCryptProv
      ;      ContentEncryptionAlgorithm.pszObjId
      ;      ContentEncryptionAlgorithm.Parameters
      ;      dwFlags
      ; For fCNG == TRUE, the following fields may be changed in ContentEncryptInfo:
      ;      hCNGContentEncryptKey
      ;      pbCNGContentEncryptKeyObject
      ;      pbContentEncryptKey
      ;      cbContentEncryptKey
      ;      ContentEncryptionAlgorithm.pszObjId
      ;      ContentEncryptionAlgorithm.Parameters
      ;      dwFlags
      ; All other fields in the ContentEncryptInfo are READONLY.
      ; If CMSG_CONTENT_ENCRYPT_PAD_ENCODED_LEN_FLAG is set upon entry
      ; in dwEncryptFlags, then, any potentially variable length encoded
      ; output should be padded with zeroes to always obtain the
      ; same maximum encoded length. This is necessary for
      ; CryptMsgCalculateEncodedLength() or CryptMsgOpenToEncode() with
      ; definite length streaming.
      ; For fCNG == FALSE:
      ;      The hContentEncryptKey must be updated.
      ;      If hCryptProv is NULL upon input, then, it must be updated.
      ;      If a HCRYPTPROV is acquired that must be released, then, the
      ;      CMSG_CONTENT_ENCRYPT_RELEASE_CONTEXT_FLAG must be set in dwFlags.
      ; Otherwise, for fCNG == TRUE:
      ;      The hCNGContentEncryptKey and cbContentEncryptKey must be updated and
      ;      pbCNGContentEncryptKeyObject and pbContentEncryptKey pfnAlloc'ed.
      ;      This key will be freed and destroyed when hCryptMsg is closed.
      ; If ContentEncryptionAlgorithm.pszObjId is changed, then, the
      ; CMSG_CONTENT_ENCRYPT_FREE_OBJID_FLAG must be set in dwFlags.
      ; If ContentEncryptionAlgorithm.Parameters is updated, then, the
      ; CMSG_CONTENT_ENCRYPT_FREE_PARA_FLAG must be set in dwFlags. pfnAlloc and
      ; pfnFree must be used for doing the allocation.
      ; ContentEncryptionAlgorithm.pszObjId is used to get the OIDFunctionAddress.
      ;--------------------------------------------------------------------------
      ; The following CAPI1 installable function is called when fCNG == FALSE.
      CMSG_OID_GEN_CONTENT_ENCRYPT_KEY_FUNC equ <"CryptMsgDllGenContentEncryptKey">
      CMSG_OID_CAPI1_GEN_CONTENT_ENCRYPT_KEY_FUNC equ <CMSG_OID_GEN_CONTENT_ENCRYPT_KEY_FUNC>
      TYPE_PFN_CMSG_GEN_CONTENT_ENCRYPT_KEY typedef proto WIN_STD_CALL_CONV :PCMSG_CONTENT_ENCRYPT_INFO, :DWORD, :ptr
      PFN_CMSG_GEN_CONTENT_ENCRYPT_KEY typedef ptr TYPE_PFN_CMSG_GEN_CONTENT_ENCRYPT_KEY

      ; The following installable function is called when fCNG == TRUE. It has the
      ; same API signature as for the above
      ; CMSG_OID_CAPI1_GEN_CONTENT_ENCRYPT_KEY_FUNC.
      CMSG_OID_CNG_GEN_CONTENT_ENCRYPT_KEY_FUNC equ <"CryptMsgDllCNGGenContentEncryptKey">
      ;+-------------------------------------------------------------------------
      ;  Key Transport Encrypt Info
      ;  The following data structure contains the information updated by the
      ;  ExportKeyTrans installable function.
      ;--------------------------------------------------------------------------
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
      ;+-------------------------------------------------------------------------
      ; Upon input, KeyTransEncryptInfo has been initialized from the
      ; KeyTransEncodeInfo.
      ; The following fields may be changed in KeyTransEncryptInfo:
      ;      EncryptedKey
      ;      KeyEncryptionAlgorithm.pszObjId
      ;      KeyEncryptionAlgorithm.Parameters
      ;      dwFlags
      ; All other fields in the KeyTransEncryptInfo are READONLY.
      ; The EncryptedKey must be updated. The pfnAlloc and pfnFree specified in
      ; ContentEncryptInfo must be used for doing the allocation.
      ; If the KeyEncryptionAlgorithm.pszObjId is changed, then, the
      ; CMSG_KEY_TRANS_ENCRYPT_FREE_OBJID_FLAG  must be set in dwFlags.
      ; If the KeyEncryptionAlgorithm.Parameters is updated, then, the
      ; CMSG_KEY_TRANS_ENCRYPT_FREE_PARA_FLAG must be set in dwFlags.
      ; The pfnAlloc and pfnFree specified in ContentEncryptInfo must be used
      ; for doing the allocation.
      ; KeyEncryptionAlgorithm.pszObjId is used to get the OIDFunctionAddress.
      ;--------------------------------------------------------------------------
      ; The following CAPI1 installable function is called when
      ; pContentEncryptInfo->fCNG == FALSE.
      CMSG_OID_EXPORT_KEY_TRANS_FUNC equ <"CryptMsgDllExportKeyTrans">
      CMSG_OID_CAPI1_EXPORT_KEY_TRANS_FUNC equ <CMSG_OID_EXPORT_KEY_TRANS_FUNC>
      TYPE_PFN_CMSG_EXPORT_KEY_TRANS typedef proto WIN_STD_CALL_CONV :PCMSG_CONTENT_ENCRYPT_INFO, :PCMSG_KEY_TRANS_RECIPIENT_ENCODE_INFO, :PCMSG_KEY_TRANS_ENCRYPT_INFO, :DWORD, :ptr
      PFN_CMSG_EXPORT_KEY_TRANS typedef ptr TYPE_PFN_CMSG_EXPORT_KEY_TRANS

      ; The following CNG installable function is called when
      ; pContentEncryptInfo->fCNG == TRUE. It has the same API signature as for
      ; the above CMSG_OID_CAPI1_EXPORT_KEY_TRANS_FUNC.
      CMSG_OID_CNG_EXPORT_KEY_TRANS_FUNC equ <"CryptMsgDllCNGExportKeyTrans">
      ;+-------------------------------------------------------------------------
      ;  Key Agree Key Encrypt Info
      ;  The following data structure contains the information updated by the
      ;  ExportKeyAgree installable function for each encrypted key agree
      ;  recipient.
      ;--------------------------------------------------------------------------
      CMSG_KEY_AGREE_KEY_ENCRYPT_INFO struct
        cbSize DWORD ?
        EncryptedKey CRYPT_DATA_BLOB <>
      CMSG_KEY_AGREE_KEY_ENCRYPT_INFO ends
      _CMSG_KEY_AGREE_KEY_ENCRYPT_INFO typedef CMSG_KEY_AGREE_KEY_ENCRYPT_INFO
      PCMSG_KEY_AGREE_KEY_ENCRYPT_INFO typedef ptr CMSG_KEY_AGREE_KEY_ENCRYPT_INFO
      ;+-------------------------------------------------------------------------
      ;  Key Agree Encrypt Info
      ;  The following data structure contains the information applicable to
      ;  all recipients. Its updated by the ExportKeyAgree installable function.
      ;--------------------------------------------------------------------------
      CMSG_KEY_AGREE_ENCRYPT_INFO struct
        cbSize DWORD ?
        dwRecipientIndex DWORD ?
        KeyEncryptionAlgorithm CRYPT_ALGORITHM_IDENTIFIER <>
        UserKeyingMaterial CRYPT_DATA_BLOB <>
        dwOriginatorChoice DWORD ?
        union
          ; CMSG_KEY_AGREE_ORIGINATOR_CERT
          OriginatorCertId CERT_ID <>
          ; CMSG_KEY_AGREE_ORIGINATOR_PUBLIC_KEY
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
      ;+-------------------------------------------------------------------------
      ; Upon input, KeyAgreeEncryptInfo has been initialized from the
      ; KeyAgreeEncodeInfo.
      ; The following fields may be changed in KeyAgreeEncryptInfo:
      ;      KeyEncryptionAlgorithm.pszObjId
      ;      KeyEncryptionAlgorithm.Parameters
      ;      UserKeyingMaterial
      ;      dwOriginatorChoice
      ;      OriginatorCertId
      ;      OriginatorPublicKeyInfo
      ;      dwFlags
      ; All other fields in the KeyAgreeEncryptInfo are READONLY.
      ; If the KeyEncryptionAlgorithm.pszObjId is changed, then, the
      ; CMSG_KEY_AGREE_ENCRYPT_FREE_OBJID_FLAG  must be set in dwFlags.
      ; If the KeyEncryptionAlgorithm.Parameters is updated, then, the
      ; CMSG_KEY_AGREE_ENCRYPT_FREE_PARA_FLAG must be set in dwFlags.
      ; The pfnAlloc and pfnFree specified in ContentEncryptInfo must be used
      ; for doing the allocation.
      ; If the UserKeyingMaterial is updated, then, the
      ; CMSG_KEY_AGREE_ENCRYPT_FREE_MATERIAL_FLAG must be set in dwFlags.
      ; pfnAlloc and pfnFree must be used for doing the allocation.
      ; The dwOriginatorChoice must be updated to either
      ; CMSG_KEY_AGREE_ORIGINATOR_CERT or CMSG_KEY_AGREE_ORIGINATOR_PUBLIC_KEY.
      ; If the OriginatorPublicKeyInfo is updated, then, the appropriate
      ; CMSG_KEY_AGREE_ENCRYPT_FREE_PUBKEY_*_FLAG must be set in dwFlags and
      ; pfnAlloc and pfnFree must be used for doing the allocation.
      ; If CMSG_CONTENT_ENCRYPT_PAD_ENCODED_LEN_FLAG is set upon entry
      ; in pContentEncryptInfo->dwEncryptFlags, then, the OriginatorPublicKeyInfo's
      ; Ephemeral PublicKey should be padded with zeroes to always obtain the
      ; same maximum encoded length. Note, the length of the generated ephemeral Y
      ; public key can vary depending on the number of leading zero bits.
      ; Upon input, the array of *rgpKeyAgreeKeyEncryptInfo has been initialized.
      ; The EncryptedKey must be updated for each recipient key.
      ; The pfnAlloc and pfnFree specified in
      ; ContentEncryptInfo must be used for doing the allocation.
      ; KeyEncryptionAlgorithm.pszObjId is used to get the OIDFunctionAddress.
      ;--------------------------------------------------------------------------
      ; The following CAPI1 installable function is called when
      ; pContentEncryptInfo->fCNG == FALSE.
      CMSG_OID_EXPORT_KEY_AGREE_FUNC equ <"CryptMsgDllExportKeyAgree">
      CMSG_OID_CAPI1_EXPORT_KEY_AGREE_FUNC equ <CMSG_OID_EXPORT_KEY_AGREE_FUNC>
      TYPE_PFN_CMSG_EXPORT_KEY_AGREE typedef proto WIN_STD_CALL_CONV :PCMSG_CONTENT_ENCRYPT_INFO, :PCMSG_KEY_AGREE_RECIPIENT_ENCODE_INFO, :PCMSG_KEY_AGREE_ENCRYPT_INFO, :DWORD, :ptr
      PFN_CMSG_EXPORT_KEY_AGREE typedef ptr TYPE_PFN_CMSG_EXPORT_KEY_AGREE

      ; The following CNG installable function is called when
      ; pContentEncryptInfo->fCNG == TRUE. It has the same API signature as for
      ; the above CMSG_OID_CAPI1_EXPORT_KEY_AGREE_FUNC.
      CMSG_OID_CNG_EXPORT_KEY_AGREE_FUNC equ <"CryptMsgDllCNGExportKeyAgree">
      ;+-------------------------------------------------------------------------
      ;  Mail List Encrypt Info
      ;  The following data structure contains the information updated by the
      ;  ExportMailList installable function.
      ;--------------------------------------------------------------------------
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
      ;+-------------------------------------------------------------------------
      ; Upon input, MailListEncryptInfo has been initialized from the
      ; MailListEncodeInfo.
      ; The following fields may be changed in MailListEncryptInfo:
      ;      EncryptedKey
      ;      KeyEncryptionAlgorithm.pszObjId
      ;      KeyEncryptionAlgorithm.Parameters
      ;      dwFlags
      ; All other fields in the MailListEncryptInfo are READONLY.
      ; The EncryptedKey must be updated. The pfnAlloc and pfnFree specified in
      ; ContentEncryptInfo must be used for doing the allocation.
      ; If the KeyEncryptionAlgorithm.pszObjId is changed, then, the
      ; CMSG_MAIL_LIST_ENCRYPT_FREE_OBJID_FLAG must be set in dwFlags.
      ; If the KeyEncryptionAlgorithm.Parameters is updated, then, the
      ; CMSG_MAIL_LIST_ENCRYPT_FREE_PARA_FLAG must be set in dwFlags.
      ; The pfnAlloc and pfnFree specified in ContentEncryptInfo must be used
      ; for doing the allocation.
      ; KeyEncryptionAlgorithm.pszObjId is used to get the OIDFunctionAddress.
      ; Note, only has a CAPI1 installable function. No CNG installable function.
      ;--------------------------------------------------------------------------
      ; The following CAPI1 installable function is called when
      ; pContentEncryptInfo->fCNG == FALSE.
      CMSG_OID_EXPORT_MAIL_LIST_FUNC equ <"CryptMsgDllExportMailList">
      CMSG_OID_CAPI1_EXPORT_MAIL_LIST_FUNC equ <CMSG_OID_EXPORT_MAIL_LIST_FUNC>
      TYPE_PFN_CMSG_EXPORT_MAIL_LIST typedef proto WIN_STD_CALL_CONV :PCMSG_CONTENT_ENCRYPT_INFO, :PCMSG_MAIL_LIST_RECIPIENT_ENCODE_INFO, :PCMSG_MAIL_LIST_ENCRYPT_INFO, :DWORD, :ptr
      PFN_CMSG_EXPORT_MAIL_LIST typedef ptr TYPE_PFN_CMSG_EXPORT_MAIL_LIST

      ;+-------------------------------------------------------------------------
      ; CAPI1 OID Installable functions for importing an encoded and encrypted
      ; content encryption key.
      ; There's a different installable function for each CMS Recipient choice:
      ;  ImportKeyTrans
      ;  ImportKeyAgree
      ;  ImportMailList
      ; Iterates through the following OIDs to get the OID installable function:
      ;   KeyEncryptionOID!ContentEncryptionOID
      ;   KeyEncryptionOID
      ;   ContentEncryptionOID
      ; If the OID installable function doesn't support the specified
      ; KeyEncryption and ContentEncryption OIDs, then, return FALSE with
      ; LastError set to E_NOTIMPL.
      ;--------------------------------------------------------------------------
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

      ;+-------------------------------------------------------------------------
      ;  CNG Content Decrypt Info
      ;  The following data structure contains the information shared between
      ;  CNGImportKeyTrans, CNGImportKeyAgree and CNGImportContentEncryptKey
      ;  installable functions.
      ;  pbContentEncryptKey and pbCNGContentEncryptKeyObject are allocated
      ;  and freed via pfnAlloc and pfnFree.
      ;--------------------------------------------------------------------------
      CMSG_CNG_CONTENT_DECRYPT_INFO struct
        cbSize DWORD ?
        ContentEncryptionAlgorithm CRYPT_ALGORITHM_IDENTIFIER <>
        pfnAlloc PFN_CMSG_ALLOC ?
        pfnFree PFN_CMSG_FREE ?
        ; This key must be used over the one in the DecryptPara. An
        ; HCRYPTPROV in the DecryptPara may have been converted to a
        ; NCRYPT_KEY_HANDLE.
        hNCryptKey NCRYPT_KEY_HANDLE ?
        pbContentEncryptKey POINTER ?
        cbContentEncryptKey DWORD ?
        hCNGContentEncryptKey BCRYPT_KEY_HANDLE ?
        pbCNGContentEncryptKeyObject POINTER ?
      CMSG_CNG_CONTENT_DECRYPT_INFO ends
      _CMSG_CNG_CONTENT_DECRYPT_INFO typedef CMSG_CNG_CONTENT_DECRYPT_INFO
      PCMSG_CNG_CONTENT_DECRYPT_INFO typedef ptr CMSG_CNG_CONTENT_DECRYPT_INFO
      ;+-------------------------------------------------------------------------
      ; CNG OID Installable function for importing and decrypting a key transport
      ; recipient encrypted content encryption key.
      ; Upon input, CNGContentDecryptInfo has been initialized.
      ; The following fields must be updated using hNCryptKey to decrypt
      ; pKeyTransDecryptPara->pKeyTrans->EncryptedKey.
      ;      pbContentEncryptKey (pfnAlloc'ed)
      ;      cbContentEncryptKey
      ; All other fields in the CNGContentEncryptInfo are READONLY.
      ; pKeyTransDecryptPara->pKeyTrans->KeyEncryptionAlgorithm.pszObjId is used
      ; to get the OIDFunctionAddress.
      ;--------------------------------------------------------------------------
      CMSG_OID_CNG_IMPORT_KEY_TRANS_FUNC equ <"CryptMsgDllCNGImportKeyTrans">
      TYPE_PFN_CMSG_CNG_IMPORT_KEY_TRANS typedef proto WIN_STD_CALL_CONV :PCMSG_CNG_CONTENT_DECRYPT_INFO, :PCMSG_CTRL_KEY_TRANS_DECRYPT_PARA, :DWORD, :ptr
      PFN_CMSG_CNG_IMPORT_KEY_TRANS typedef ptr TYPE_PFN_CMSG_CNG_IMPORT_KEY_TRANS

      ;+-------------------------------------------------------------------------
      ; CNG OID Installable function for importing and decrypting a key agreement
      ; recipient encrypted content encryption key.
      ; Upon input, CNGContentDecryptInfo has been initialized.
      ; The following fields must be updated using hNCryptKey to decrypt
      ; pKeyAgreeDecryptPara->pKeyAgree->rgpRecipientEncryptedKeys[
      ;  pKeyAgreeDecryptPara->dwRecipientEncryptedKeyIndex]->EncryptedKey.
      ;      pbContentEncryptKey (pfnAlloc'ed)
      ;      cbContentEncryptKey
      ; All other fields in the CNGContentEncryptInfo are READONLY.
      ; pKeyAgreeDecryptPara->pKeyAgree->KeyEncryptionAlgorithm.pszObjId is used
      ; to get the OIDFunctionAddress.
      ;--------------------------------------------------------------------------
      CMSG_OID_CNG_IMPORT_KEY_AGREE_FUNC equ <"CryptMsgDllCNGImportKeyAgree">
      TYPE_PFN_CMSG_CNG_IMPORT_KEY_AGREE typedef proto WIN_STD_CALL_CONV :PCMSG_CNG_CONTENT_DECRYPT_INFO, :PCMSG_CTRL_KEY_AGREE_DECRYPT_PARA, :DWORD, :ptr
      PFN_CMSG_CNG_IMPORT_KEY_AGREE typedef ptr TYPE_PFN_CMSG_CNG_IMPORT_KEY_AGREE

      ;+-------------------------------------------------------------------------
      ; CNG OID Installable function for importing an already decrypted
      ; content encryption key.
      ; Upon input, CNGContentDecryptInfo has been initialized.
      ; The following fields must be updated using pbContentEncryptKey and
      ; cbContentEncryptKey:
      ;      hCNGContentEncryptKey
      ;      pbCNGContentEncryptKeyObject (pfnAlloc'ed)
      ; The hCNGContentEncryptKey will be destroyed when hCryptMsg is closed.
      ; All other fields in the CNGContentEncryptInfo are READONLY.
      ; ContentEncryptionAlgorithm.pszObjId is used to get the OIDFunctionAddress.
      ;--------------------------------------------------------------------------
      CMSG_OID_CNG_IMPORT_CONTENT_ENCRYPT_KEY_FUNC equ <"CryptMsgDllCNGImportContentEncryptKey">
      TYPE_PFN_CMSG_CNG_IMPORT_CONTENT_ENCRYPT_KEY typedef proto WIN_STD_CALL_CONV :PCMSG_CNG_CONTENT_DECRYPT_INFO, :DWORD, :ptr
      PFN_CMSG_CNG_IMPORT_CONTENT_ENCRYPT_KEY typedef ptr TYPE_PFN_CMSG_CNG_IMPORT_CONTENT_ENCRYPT_KEY

      ;+=========================================================================
      ;  Certificate Store Data Structures and APIs
      ;==========================================================================
      ;+-------------------------------------------------------------------------
      ;              In its most basic implementation, a cert store is simply a
      ;              collection of certificates and/or CRLs. This is the case when
      ;              a cert store is opened with all of its certificates and CRLs
      ;              coming from a PKCS #7 encoded cryptographic message.
      ;              Nonetheless, all cert stores have the following properties:
      ;               - A public key may have more than one certificate in the store.
      ;                 For example, a private/public key used for signing may have a
      ;                 certificate issued for VISA and another issued for
      ;                 Mastercard. Also, when a certificate is renewed there might
      ;                 be more than one certificate with the same subject and
      ;                 issuer.
      ;               - However, each certificate in the store is uniquely
      ;                 identified by its Issuer and SerialNumber.
      ;               - There's an issuer of subject certificate relationship. A
      ;                 certificate's issuer is found by doing a match of
      ;                 pSubjectCert->Issuer with pIssuerCert->Subject.
      ;                 The relationship is verified by using
      ;                 the issuer's public key to verify the subject certificate's
      ;                 signature. Note, there might be X.509 v3 extensions
      ;                 to assist in finding the issuer certificate.
      ;               - Since issuer certificates might be renewed, a subject
      ;                 certificate might have more than one issuer certificate.
      ;               - There's an issuer of CRL relationship. An
      ;                 issuer's CRL is found by doing a match of
      ;                 pIssuerCert->Subject with pCrl->Issuer.
      ;                 The relationship is verified by using
      ;                 the issuer's public key to verify the CRL's
      ;                 signature. Note, there might be X.509 v3 extensions
      ;                 to assist in finding the CRL.
      ;               - Since some issuers might support the X.509 v3 delta CRL
      ;                 extensions, an issuer might have more than one CRL.
      ;               - The store shouldn't have any redundant certificates or
      ;                 CRLs. There shouldn't be two certificates with the same
      ;                 Issuer and SerialNumber. There shouldn't be two CRLs with
      ;                 the same Issuer, ThisUpdate and NextUpdate.
      ;               - The store has NO policy or trust information. No
      ;                 certificates are tagged as being "root". Its up to
      ;                 the application to maintain a list of CertIds (Issuer +
      ;                 SerialNumber) for certificates it trusts.
      ;               - The store might contain bad certificates and/or CRLs.
      ;                 The issuer's signature of a subject certificate or CRL may
      ;                 not verify. Certificates or CRLs may not satisfy their
      ;                 time validity requirements. Certificates may be
      ;                 revoked.
      ;              In addition to the certificates and CRLs, properties can be
      ;              stored. There are two predefined property IDs for a user
      ;              certificate: CERT_KEY_PROV_HANDLE_PROP_ID and
      ;              CERT_KEY_PROV_INFO_PROP_ID. The CERT_KEY_PROV_HANDLE_PROP_ID
      ;              is a HCRYPTPROV handle to the private key assoicated
      ;              with the certificate. The CERT_KEY_PROV_INFO_PROP_ID contains
      ;              information to be used to call
      ;              CryptAcquireContext and CryptSetProvParam to get a handle
      ;              to the private key associated with the certificate.
      ;              There exists two more predefined property IDs for certificates
      ;              and CRLs, CERT_SHA1_HASH_PROP_ID and CERT_MD5_HASH_PROP_ID.
      ;              If these properties don't already exist, then, a hash of the
      ;              content is computed. (CERT_HASH_PROP_ID maps to the default
      ;              hash algorithm, currently, CERT_SHA1_HASH_PROP_ID).
      ;              There are additional APIs for creating certificate and CRL
      ;      contexts not in a store (CertCreateCertificateContext and
      ;      CertCreateCRLContext).
      ;--------------------------------------------------------------------------
      HCERTSTORE typedef ptr
      ;+-------------------------------------------------------------------------
      ;  Certificate context.
      ;  A certificate context contains both the encoded and decoded representation
      ;  of a certificate. A certificate context returned by a cert store function
      ;  must be freed by calling the CertFreeCertificateContext function. The
      ;  CertDuplicateCertificateContext function can be called to make a duplicate
      ;  copy (which also must be freed by calling CertFreeCertificateContext).
      ;--------------------------------------------------------------------------
      ; certenrolls_begin -- CERT_CONTEXT
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
      ; certenrolls_end
      ;+-------------------------------------------------------------------------
      ;  CRL context.
      ;  A CRL context contains both the encoded and decoded representation
      ;  of a CRL. A CRL context returned by a cert store function
      ;  must be freed by calling the CertFreeCRLContext function. The
      ;  CertDuplicateCRLContext function can be called to make a duplicate
      ;  copy (which also must be freed by calling CertFreeCRLContext).
      ;--------------------------------------------------------------------------
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
      ;+-------------------------------------------------------------------------
      ;  Certificate Trust List (CTL) context.
      ;  A CTL context contains both the encoded and decoded representation
      ;  of a CTL. Also contains an opened HCRYPTMSG handle to the decoded
      ;  cryptographic signed message containing the CTL_INFO as its inner content.
      ;  pbCtlContent is the encoded inner content of the signed message.
      ;  The CryptMsg APIs can be used to extract additional signer information.
      ;--------------------------------------------------------------------------
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
      ; certenrolld_begin -- CERT_*_PROP_ID
      ;+-------------------------------------------------------------------------
      ;  Certificate, CRL and CTL property IDs
      ;  See CertSetCertificateContextProperty or CertGetCertificateContextProperty
      ;  for usage information.
      ;--------------------------------------------------------------------------
      CERT_KEY_PROV_HANDLE_PROP_ID equ 1
      CERT_KEY_PROV_INFO_PROP_ID equ 2; CRYPT_KEY_PROV_INFO

      CERT_SHA1_HASH_PROP_ID equ 3
      CERT_MD5_HASH_PROP_ID equ 4
      CERT_HASH_PROP_ID equ <CERT_SHA1_HASH_PROP_ID>
      CERT_KEY_CONTEXT_PROP_ID equ 5; CERT_KEY_CONTEXT

      CERT_KEY_SPEC_PROP_ID equ 6
      CERT_IE30_RESERVED_PROP_ID equ 7
      CERT_PUBKEY_HASH_RESERVED_PROP_ID equ 8
      CERT_ENHKEY_USAGE_PROP_ID equ 9
      CERT_CTL_USAGE_PROP_ID equ <CERT_ENHKEY_USAGE_PROP_ID>
      CERT_NEXT_UPDATE_LOCATION_PROP_ID equ 10
      CERT_FRIENDLY_NAME_PROP_ID equ 11; string

      CERT_PVK_FILE_PROP_ID equ 12
      CERT_DESCRIPTION_PROP_ID equ 13; string

      CERT_ACCESS_STATE_PROP_ID equ 14
      CERT_SIGNATURE_HASH_PROP_ID equ 15
      CERT_SMART_CARD_DATA_PROP_ID equ 16
      CERT_EFS_PROP_ID equ 17
      CERT_FORTEZZA_DATA_PROP_ID equ 18
      CERT_ARCHIVED_PROP_ID equ 19
      CERT_KEY_IDENTIFIER_PROP_ID equ 20
      CERT_AUTO_ENROLL_PROP_ID equ 21; string:Template name

      CERT_PUBKEY_ALG_PARA_PROP_ID equ 22
      CERT_CROSS_CERT_DIST_POINTS_PROP_ID equ 23
      CERT_ISSUER_PUBLIC_KEY_MD5_HASH_PROP_ID equ 24
      CERT_SUBJECT_PUBLIC_KEY_MD5_HASH_PROP_ID equ 25
      CERT_ENROLLMENT_PROP_ID equ 26; RequestId+CADNS+CACN+Friendly Name

      CERT_DATE_STAMP_PROP_ID equ 27; FILETIME

      CERT_ISSUER_SERIAL_NUMBER_MD5_HASH_PROP_ID equ 28
      CERT_SUBJECT_NAME_MD5_HASH_PROP_ID equ 29
      CERT_EXTENDED_ERROR_INFO_PROP_ID equ 30; string

      ; Note, 32 - 35 are reserved for the CERT, CRL, CTL and KeyId file element IDs.
      ;       36 - 62 are reserved for future element IDs.
      CERT_RENEWAL_PROP_ID equ 64
      CERT_ARCHIVED_KEY_HASH_PROP_ID equ 65; Encrypted key hash

      CERT_AUTO_ENROLL_RETRY_PROP_ID equ 66; AE_RETRY_INFO:cb+cRetry+FILETIME

      CERT_AIA_URL_RETRIEVED_PROP_ID equ 67
      CERT_AUTHORITY_INFO_ACCESS_PROP_ID equ 68
      CERT_BACKED_UP_PROP_ID equ 69; VARIANT_BOOL+FILETIME

      CERT_OCSP_RESPONSE_PROP_ID equ 70
      CERT_REQUEST_ORIGINATOR_PROP_ID equ 71; string:machine DNS name

      CERT_SOURCE_LOCATION_PROP_ID equ 72; string

      CERT_SOURCE_URL_PROP_ID equ 73; string

      CERT_NEW_KEY_PROP_ID equ 74
      CERT_OCSP_CACHE_PREFIX_PROP_ID equ 75; string

      CERT_SMART_CARD_ROOT_INFO_PROP_ID equ 76; CRYPT_SMART_CARD_ROOT_INFO

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
      CERT_CEP_PROP_ID equ 87; Version+PropFlags+AuthType+UrlFlags+CESAuthType+Url+Id+CESUrl+ReqId

      ; 88 reserved, originally used for CERT_CEP_PROP_ID
      CERT_SIGN_HASH_CNG_ALG_PROP_ID equ 89; eg: "RSA/SHA1"

      CERT_SCARD_PIN_ID_PROP_ID equ 90
      CERT_SCARD_PIN_INFO_PROP_ID equ 91
      CERT_SUBJECT_PUB_KEY_BIT_LENGTH_PROP_ID equ 92
      CERT_PUB_KEY_CNG_ALG_BIT_LENGTH_PROP_ID equ 93
      CERT_ISSUER_PUB_KEY_BIT_LENGTH_PROP_ID equ 94
      CERT_ISSUER_CHAIN_SIGN_HASH_CNG_ALG_PROP_ID equ 95
      CERT_ISSUER_CHAIN_PUB_KEY_CNG_ALG_BIT_LENGTH_PROP_ID equ 96
      CERT_NO_EXPIRE_NOTIFICATION_PROP_ID equ 97
      ; Following property isn't implicitly created via a GetProperty.
      CERT_AUTH_ROOT_SHA256_HASH_PROP_ID equ 98
      CERT_NCRYPT_KEY_HANDLE_TRANSFER_PROP_ID equ 99
      CERT_HCRYPTPROV_TRANSFER_PROP_ID equ 100
      ; Smart card reader image path
      CERT_SMART_CARD_READER_PROP_ID equ 101;string

      ; Send as trusted issuer
      CERT_SEND_AS_TRUSTED_ISSUER_PROP_ID equ 102;boolean

      CERT_KEY_REPAIR_ATTEMPTED_PROP_ID equ 103; FILETME

      CERT_DISALLOWED_FILETIME_PROP_ID equ 104
      CERT_ROOT_PROGRAM_CHAIN_POLICIES_PROP_ID equ 105
      ; Smart card reader removable capabilities
      CERT_SMART_CARD_READER_NON_REMOVABLE_PROP_ID equ 106; boolean

      CERT_SHA256_HASH_PROP_ID equ 107
      CERT_SCEP_SERVER_CERTS_PROP_ID equ 108; Pkcs7

      CERT_SCEP_RA_SIGNATURE_CERT_PROP_ID equ 109; sha1 Thumbprint

      CERT_SCEP_RA_ENCRYPTION_CERT_PROP_ID equ 110; sha1 Thumbprint

      CERT_SCEP_CA_CERT_PROP_ID equ 111; sha1 Thumbprint

      CERT_SCEP_SIGNER_CERT_PROP_ID equ 112; sha1 Thumbprint

      CERT_SCEP_NONCE_PROP_ID equ 113; blob

      ; string: "CNGEncryptAlgId/CNGHashAlgId"  example: "3DES/SHA1"
      CERT_SCEP_ENCRYPT_HASH_CNG_ALG_PROP_ID equ 114
      CERT_SCEP_FLAGS_PROP_ID equ 115; DWORD

      CERT_SCEP_GUID_PROP_ID equ 116; string

      CERT_SERIALIZABLE_KEY_CONTEXT_PROP_ID equ 117; CERT_KEY_CONTEXT

      ; Binary: isolated 
      CERT_ISOLATED_KEY_PROP_ID equ 118; blob

      CERT_SERIAL_CHAIN_PROP_ID equ 119
      CERT_KEY_CLASSIFICATION_PROP_ID equ 120; DWORD CertKeyType

      ; 1 byte value. Set to 1 if the certificate has the
      ; szOID_TLS_FEATURES_EXT extension and an integer set to 5
      ; correpsonding to the OCSP status_request TLS extension.
      CERT_OCSP_MUST_STAPLE_PROP_ID equ 121
      CERT_DISALLOWED_ENHKEY_USAGE_PROP_ID equ 122
      CERT_NONCOMPLIANT_ROOT_URL_PROP_ID equ 123; NULL terminated UNICODE string

      CERT_PIN_SHA256_HASH_PROP_ID equ 124
      CERT_CLR_DELETE_KEY_PROP_ID equ 125
      CERT_NOT_BEFORE_FILETIME_PROP_ID equ 126
      CERT_NOT_BEFORE_ENHKEY_USAGE_PROP_ID equ 127
      CERT_DISALLOWED_CA_FILETIME_PROP_ID equ 128
      CERT_FIRST_RESERVED_PROP_ID equ 129
      CERT_LAST_RESERVED_PROP_ID equ 00007FFFh
      CERT_FIRST_USER_PROP_ID equ 00008000h
      CERT_LAST_USER_PROP_ID equ 0000FFFFh
      ; certenrolld_end
      ; Values for CERT_KEY_CLASSIFICATION_PROP_ID.
      ; Must be stored as a DWORD.
      if Defined(__cplusplus) and  not Defined(SORTPP_PASS)
        ;[...]
      else
        WINCRYPT_DWORD_CPP_ONLY equ <>
      endif
      WINCRYPT_DWORD_CPP_ONLY typedef SDWORD
      ; Unknown
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
      ;+-------------------------------------------------------------------------
      ;  Property OIDs
      ;--------------------------------------------------------------------------
      ; The OID component following the prefix contains the PROP_ID (decimal)
      szOID_CERT_PROP_ID_PREFIX equ <"1.3.6.1.4.1.311.10.11.">
      _szPROP_ID macro PropId
        exitm <# PropId>
      endm
      ; Ansi OID string from Property Id:
      szOID_CERT_PROP_ID macro PropId
        exitm <szOID_CERT_PROP_ID_PREFIX _szPROP_ID(PropId)>
      endm
      ; Unicode OID string from Property Id:
      __CRYPT32WTEXT macro quote
        exitm <L ## quote>
      endm
      _CRYPT32WTEXT macro quote
        exitm <__CRYPT32WTEXT(quote)>
      endm
      wszOID_CERT_PROP_ID macro PropId
        exitm <_CRYPT32WTEXT(szOID_CERT_PROP_ID_PREFIX) _CRYPT32WTEXT(_szPROP_ID(PropId))>
      endm
      ; Use szOID_CERT_PROP_ID(CERT_KEY_IDENTIFIER_PROP_ID) instead:
      szOID_CERT_KEY_IDENTIFIER_PROP_ID equ <"1.3.6.1.4.1.311.10.11.20">
      ; Use szOID_CERT_PROP_ID(CERT_ISSUER_SERIAL_NUMBER_MD5_HASH_PROP_ID) instead:
      szOID_CERT_ISSUER_SERIAL_NUMBER_MD5_HASH_PROP_ID equ <"1.3.6.1.4.1.311.10.11.28">
      ; Use szOID_CERT_PROP_ID(CERT_SUBJECT_NAME_MD5_HASH_PROP_ID) instead:
      szOID_CERT_SUBJECT_NAME_MD5_HASH_PROP_ID equ <"1.3.6.1.4.1.311.10.11.29">
      ; Use szOID_CERT_PROP_ID(CERT_MD5_HASH_PROP_ID) instead:
      szOID_CERT_MD5_HASH_PROP_ID equ <"1.3.6.1.4.1.311.10.11.4">
      ; Use szOID_CERT_PROP_ID(CERT_SIGNATURE_HASH_PROP_ID) instead:
      szOID_CERT_SIGNATURE_HASH_PROP_ID equ <"1.3.6.1.4.1.311.10.11.15">
      ; The CERT_SIGNATURE_HASH_PROP_ID and CERT_SUBJECT_PUBLIC_KEY_MD5_HASH_PROP_ID
      ; properties are used for disallowed hashes.
      szOID_DISALLOWED_HASH equ <szOID_CERT_SIGNATURE_HASH_PROP_ID>
      ; Use szOID_CERT_PROP_ID(CERT_DISALLOWED_FILETIME_PROP_ID) instead:
      szOID_CERT_DISALLOWED_FILETIME_PROP_ID equ <"1.3.6.1.4.1.311.10.11.104">
      ; Use szOID_CERT_PROP_ID(CERT_DISALLOWED_CA_FILETIME_PROP_ID) instead:
      szOID_CERT_DISALLOWED_CA_FILETIME_PROP_ID equ <"1.3.6.1.4.1.311.10.11.128">
      ;+-------------------------------------------------------------------------
      ;  Access State flags returned by CERT_ACCESS_STATE_PROP_ID. Note,
      ;  CERT_ACCESS_PROP_ID is read only.
      ;--------------------------------------------------------------------------
      ; Set if context property writes are persisted. For instance, not set for
      ; memory store contexts. Set for registry based stores opened as read or write.
      ; Not set for registry based stores opened as read only.
      CERT_ACCESS_STATE_WRITE_PERSIST_FLAG equ 1h
      ; Set if context resides in a SYSTEM or SYSTEM_REGISTRY store.
      CERT_ACCESS_STATE_SYSTEM_STORE_FLAG equ 2h
      ; Set if context resides in a LocalMachine SYSTEM or SYSTEM_REGISTRY store.
      CERT_ACCESS_STATE_LM_SYSTEM_STORE_FLAG equ 4h
      ; Set if context resides in a GroupPolicy SYSTEM or SYSTEM_REGISTRY store.
      CERT_ACCESS_STATE_GP_SYSTEM_STORE_FLAG equ 8h
      ; Set if context resides in a SHARED_USER physical store.
      CERT_ACCESS_STATE_SHARED_USER_FLAG equ 10h
      ;+-------------------------------------------------------------------------
      ;  CERT_ROOT_PROGRAM_CHAIN_POLICIES_PROP_ID Property
      ;  Encoded as an X509_ENHANCED_KEY_USAGE: sequence of Policy OIDs.
      ;--------------------------------------------------------------------------
      ; Supported Root Program Chain Policies:
      szOID_ROOT_PROGRAM_AUTO_UPDATE_CA_REVOCATION equ <"1.3.6.1.4.1.311.60.3.1">
      szOID_ROOT_PROGRAM_AUTO_UPDATE_END_REVOCATION equ <"1.3.6.1.4.1.311.60.3.2">
      szOID_ROOT_PROGRAM_NO_OCSP_FAILOVER_TO_CRL equ <"1.3.6.1.4.1.311.60.3.3">
      ;+-------------------------------------------------------------------------
      ;  Cryptographic Key Provider Information
      ;  CRYPT_KEY_PROV_INFO defines the CERT_KEY_PROV_INFO_PROP_ID's pvData.
      ;  The CRYPT_KEY_PROV_INFO fields are passed to CryptAcquireContext
      ;  to get a HCRYPTPROV handle. The optional CRYPT_KEY_PROV_PARAM fields are
      ;  passed to CryptSetProvParam to further initialize the provider.
      ;  The dwKeySpec field identifies the private key to use from the container
      ;  For example, AT_KEYEXCHANGE or AT_SIGNATURE.
      ;--------------------------------------------------------------------------
      CRYPT_KEY_PROV_PARAM struct
        dwParam DWORD ?
        pbData POINTER ?
        cbData DWORD ?
        dwFlags DWORD ?
      CRYPT_KEY_PROV_PARAM ends
      _CRYPT_KEY_PROV_PARAM typedef CRYPT_KEY_PROV_PARAM
      PCRYPT_KEY_PROV_PARAM typedef ptr CRYPT_KEY_PROV_PARAM
      CRYPT_KEY_PROV_INFO struct
        pwszContainerName POINTER ?
        pwszProvName POINTER ?
        dwProvType DWORD ?
        dwFlags DWORD ?
        cProvParam DWORD ?
        rgProvParam PCRYPT_KEY_PROV_PARAM ?
        dwKeySpec DWORD ?
      CRYPT_KEY_PROV_INFO ends
      _CRYPT_KEY_PROV_INFO typedef CRYPT_KEY_PROV_INFO
      PCRYPT_KEY_PROV_INFO typedef ptr CRYPT_KEY_PROV_INFO
      ;+-------------------------------------------------------------------------
      ;  The following flag should be set in the above dwFlags to enable
      ;  a CertSetCertificateContextProperty(CERT_KEY_CONTEXT_PROP_ID) after a
      ;  CryptAcquireContext is done in the Sign or Decrypt Message functions.
      ;  The following define must not collide with any of the
      ;  CryptAcquireContext dwFlag defines.
      ;--------------------------------------------------------------------------
      CERT_SET_KEY_PROV_HANDLE_PROP_ID equ 00000001h
      CERT_SET_KEY_CONTEXT_PROP_ID equ 00000001h
      ; Special dwKeySpec indicating a CNG NCRYPT_KEY_HANDLE instead of a CAPI1
      ; HCRYPTPROV
      CERT_NCRYPT_KEY_SPEC equ 0FFFFFFFFh
      ;+-------------------------------------------------------------------------
      ;  Certificate Key Context
      ;  CERT_KEY_CONTEXT defines the CERT_KEY_CONTEXT_PROP_ID's pvData.
      ;  dwKeySpec is set to the special CERT_NCRYPT_KEY_SPEC to select the
      ;  hNCryptKey choice.
      ;--------------------------------------------------------------------------
      CERT_KEY_CONTEXT struct
        cbSize DWORD ?
        ; sizeof(CERT_KEY_CONTEXT)
        union
          hCryptProv HCRYPTPROV ?
          ; dwKeySpec == CERT_NCRYPT_KEY_SPEC
          hNCryptKey NCRYPT_KEY_HANDLE ?
        ends
        dwKeySpec DWORD ?
      CERT_KEY_CONTEXT ends
      _CERT_KEY_CONTEXT typedef CERT_KEY_CONTEXT
      PCERT_KEY_CONTEXT typedef ptr CERT_KEY_CONTEXT
      ;+-------------------------------------------------------------------------
      ;  Cryptographic Smart Card Root Information
      ;  CRYPT_SMART_CARD_ROOT_INFO defines the
      ;  CERT_SMART_CARD_ROOT_INFO_PROP_ID's pvData.
      ;--------------------------------------------------------------------------
      ROOT_INFO_LUID struct
        LowPart DWORD ?
        HighPart SDWORD ?
      ROOT_INFO_LUID ends
      _ROOT_INFO_LUID typedef ROOT_INFO_LUID
      PROOT_INFO_LUID typedef ptr ROOT_INFO_LUID
      CRYPT_SMART_CARD_ROOT_INFO struct
        rgbCardID BYTE 16 dup (?)
        luid ROOT_INFO_LUID <>
      CRYPT_SMART_CARD_ROOT_INFO ends
      _CRYPT_SMART_CARD_ROOT_INFO typedef CRYPT_SMART_CARD_ROOT_INFO
      PCRYPT_SMART_CARD_ROOT_INFO typedef ptr CRYPT_SMART_CARD_ROOT_INFO
      ;+-------------------------------------------------------------------------
      ;  Certificate Store Provider Types
      ;--------------------------------------------------------------------------
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
      ; SmartCard Store Provider isn't supported
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
      ; SmartCard Store Provider isn't supported
      sz_CERT_STORE_PROV_SMART_CARD_W equ <"SmartCard">
      sz_CERT_STORE_PROV_SMART_CARD equ <sz_CERT_STORE_PROV_SMART_CARD_W>
      sz_CERT_STORE_PROV_LDAP_W equ <"Ldap">
      sz_CERT_STORE_PROV_LDAP equ <sz_CERT_STORE_PROV_LDAP_W>
      ;+-------------------------------------------------------------------------
      ;  Certificate Store verify/results flags
      ;--------------------------------------------------------------------------
      CERT_STORE_SIGNATURE_FLAG equ 00000001h
      CERT_STORE_TIME_VALIDITY_FLAG equ 00000002h
      CERT_STORE_REVOCATION_FLAG equ 00000004h
      CERT_STORE_NO_CRL_FLAG equ 00010000h
      CERT_STORE_NO_ISSUER_FLAG equ 00020000h
      CERT_STORE_BASE_CRL_FLAG equ 00000100h
      CERT_STORE_DELTA_CRL_FLAG equ 00000200h
      ;+-------------------------------------------------------------------------
      ;  Certificate Store open/property flags
      ;--------------------------------------------------------------------------
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
      ;+-------------------------------------------------------------------------
      ;  Certificate Store Provider flags are in the HiWord (0xFFFF0000)
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  Certificate System Store Flag Values
      ;--------------------------------------------------------------------------
      ; Includes flags and location
      CERT_SYSTEM_STORE_MASK equ 0FFFF0000h
      ; Set if pvPara points to a CERT_SYSTEM_STORE_RELOCATE_PARA structure
      CERT_SYSTEM_STORE_RELOCATE_FLAG equ 80000000h
      CERT_SYSTEM_STORE_RELOCATE_PARA struct
        union
          hKeyBase HKEY ?
          pvBase POINTER ?
        ends
        union
          pvSystemStore POINTER ?
          pszSystemStore =POINTER ?
          pwszSystemStore =POINTER ?
        ends
      CERT_SYSTEM_STORE_RELOCATE_PARA ends
      _CERT_SYSTEM_STORE_RELOCATE_PARA typedef CERT_SYSTEM_STORE_RELOCATE_PARA
      PCERT_SYSTEM_STORE_RELOCATE_PARA typedef ptr CERT_SYSTEM_STORE_RELOCATE_PARA
      ; By default, when the CurrentUser "Root" store is opened, any SystemRegistry
      ; roots not also on the protected root list are deleted from the cache before
      ; CertOpenStore() returns. Set the following flag to return all the roots
      ; in the SystemRegistry without checking the protected root list.
      CERT_SYSTEM_STORE_UNPROTECTED_FLAG equ 40000000h
      CERT_SYSTEM_STORE_DEFER_READ_FLAG equ 20000000h
      ; Location of the system store:
      CERT_SYSTEM_STORE_LOCATION_MASK equ 00FF0000h
      CERT_SYSTEM_STORE_LOCATION_SHIFT equ 16
      ;  Registry: HKEY_CURRENT_USER or HKEY_LOCAL_MACHINE
      CERT_SYSTEM_STORE_CURRENT_USER_ID equ 1
      CERT_SYSTEM_STORE_LOCAL_MACHINE_ID equ 2
      ;  Registry: HKEY_LOCAL_MACHINE\Software\Microsoft\Cryptography\Services
      CERT_SYSTEM_STORE_CURRENT_SERVICE_ID equ 4
      CERT_SYSTEM_STORE_SERVICES_ID equ 5
      ;  Registry: HKEY_USERS
      CERT_SYSTEM_STORE_USERS_ID equ 6
      ;  Registry: HKEY_CURRENT_USER\Software\Policies\Microsoft\SystemCertificates
      CERT_SYSTEM_STORE_CURRENT_USER_GROUP_POLICY_ID equ 7
      ;  Registry: HKEY_LOCAL_MACHINE\Software\Policies\Microsoft\SystemCertificates
      CERT_SYSTEM_STORE_LOCAL_MACHINE_GROUP_POLICY_ID equ 8
      ;  Registry: HKEY_LOCAL_MACHINE\Software\Microsoft\EnterpriseCertificates
      CERT_SYSTEM_STORE_LOCAL_MACHINE_ENTERPRISE_ID equ 9
      ;  Registry: HKEY_LOCAL_MACHINE\OSDATA\Software\Microsoft\WCOSCertificates
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
      ;+-------------------------------------------------------------------------
      ;  Group Policy Store Defines
      ;--------------------------------------------------------------------------
      ; Registry path to the Group Policy system stores
      CERT_GROUP_POLICY_SYSTEM_STORE_REGPATH equ <L("Software\Policies\Microsoft\SystemCertificates")>
      ;+-------------------------------------------------------------------------
      ;  EFS Defines
      ;--------------------------------------------------------------------------
      ; Registry path to the EFS EFSBlob SubKey - Value type is REG_BINARY
      CERT_EFSBLOB_REGPATH equ <CERT_GROUP_POLICY_SYSTEM_STORE_REGPATH L("\EFS")>
      CERT_EFSBLOB_VALUE_NAME equ <L("EFSBlob")>
      ;+-------------------------------------------------------------------------
      ;  Protected Root Defines
      ;--------------------------------------------------------------------------
      ; Registry path to the Protected Roots Flags SubKey
      CERT_PROT_ROOT_FLAGS_REGPATH equ <CERT_GROUP_POLICY_SYSTEM_STORE_REGPATH L("\Root\ProtectedRoots")>
      ; The following is a REG_DWORD. The bit definitions follow.
      CERT_PROT_ROOT_FLAGS_VALUE_NAME equ <L("Flags")>
      ; Set the following flag to inhibit the opening of the CurrentUser's
      ; .Default physical store when opening the CurrentUser's "Root" system store.
      ; The .Default physical store open's the CurrentUser SystemRegistry "Root"
      ; store.
      CERT_PROT_ROOT_DISABLE_CURRENT_USER_FLAG equ 1h
      ; Set the following flag to inhibit the adding of roots from the
      ; CurrentUser SystemRegistry "Root" store to the protected root list
      ; when the "Root" store is initially protected.
      CERT_PROT_ROOT_INHIBIT_ADD_AT_INIT_FLAG equ 2h
      ; Set the following flag to inhibit the purging of protected roots from the
      ; CurrentUser SystemRegistry "Root" store that are
      ; also in the LocalMachine SystemRegistry "Root" store. Note, when not
      ; disabled, the purging is done silently without UI.
      CERT_PROT_ROOT_INHIBIT_PURGE_LM_FLAG equ 4h
      ; Set the following flag to inhibit the opening of the LocalMachine's
      ; .AuthRoot physical store when opening the LocalMachine's "Root" system store.
      ; The .AuthRoot physical store open's the LocalMachine SystemRegistry
      ; "AuthRoot" store. The "AuthRoot" store contains the pre-installed
      ; SSL ServerAuth and the ActiveX Authenticode "root" certificates.
      CERT_PROT_ROOT_DISABLE_LM_AUTH_FLAG equ 8h
      ; The semantics for the following legacy definition has been changed to be
      ; the same as for the CERT_PROT_ROOT_DISABLE_LM_AUTH_FLAG.
      CERT_PROT_ROOT_ONLY_LM_GPT_FLAG equ 8h
      ; Set the following flag to disable the requiring of the issuing CA
      ; certificate being in the "NTAuth" system registry store found in the
      ; CERT_SYSTEM_STORE_LOCAL_MACHINE_ENTERPRISE store location.
      ; When set, CertVerifyCertificateChainPolicy(CERT_CHAIN_POLICY_NT_AUTH)
      ; will check that the chain has a valid name constraint for all name
      ; spaces, including UPN if the issuing CA isn't in the "NTAuth" store.
      CERT_PROT_ROOT_DISABLE_NT_AUTH_REQUIRED_FLAG equ 10h
      ; Set the following flag to disable checking for not defined name
      ; constraints.
      ; When set, CertGetCertificateChain won't check for or set the following
      ; dwErrorStatus: CERT_TRUST_HAS_NOT_DEFINED_NAME_CONSTRAINT.
      ; In LH, checking for not defined name constraints is always disabled.
      CERT_PROT_ROOT_DISABLE_NOT_DEFINED_NAME_CONSTRAINT_FLAG equ 20h
      ; Set the following flag to disallow the users to trust peer-trust
      CERT_PROT_ROOT_DISABLE_PEER_TRUST equ 10000h
      ; The following is a REG_MULTI_SZ containing the list of user allowed
      ; Enhanced Key Usages for peer trust.
      CERT_PROT_ROOT_PEER_USAGES_VALUE_NAME equ <L("PeerUsages")>
      CERT_PROT_ROOT_PEER_USAGES_VALUE_NAME_A equ <"PeerUsages">
      ; If the above REG_MULTI_SZ isn't defined or is empty, defaults to
      ; the following multi-string value
      CERT_PROT_ROOT_PEER_USAGES_DEFAULT_A equ <szOID_PKIX_KP_CLIENT_AUTH,0o szOID_PKIX_KP_EMAIL_PROTECTION,0o szOID_KP_EFS,0o>
      ;+-------------------------------------------------------------------------
      ;  Trusted Publisher Definitions
      ;--------------------------------------------------------------------------
      ; Registry path to the trusted publisher "Safer" group policy subkey
      CERT_TRUST_PUB_SAFER_GROUP_POLICY_REGPATH equ <CERT_GROUP_POLICY_SYSTEM_STORE_REGPATH L("\TrustedPublisher\Safer")>
      ; Registry path to the Local Machine system stores
      CERT_LOCAL_MACHINE_SYSTEM_STORE_REGPATH equ <L("Software\Microsoft\SystemCertificates")>
      ; Registry path to the trusted publisher "Safer" local machine subkey
      CERT_TRUST_PUB_SAFER_LOCAL_MACHINE_REGPATH equ <CERT_LOCAL_MACHINE_SYSTEM_STORE_REGPATH L("\TrustedPublisher\Safer")>
      ; "Safer" subkey value names. All values are DWORDs.
      CERT_TRUST_PUB_AUTHENTICODE_FLAGS_VALUE_NAME equ <L("AuthenticodeFlags")>
      ; AuthenticodeFlags definitions
      ; Definition of who is allowed to trust publishers
      ; Setting allowed trust to MACHINE_ADMIN or ENTERPRISE_ADMIN disables UI,
      ; only trusts publishers in the "TrustedPublisher" system store and
      ; inhibits the opening of the CurrentUser's .Default physical store when
      ; opening the CurrentUsers's "TrustedPublisher" system store.
      ; The .Default physical store open's the CurrentUser SystemRegistry
      ; "TrustedPublisher" store.
      ; Setting allowed trust to ENTERPRISE_ADMIN only opens the
      ; LocalMachine's .GroupPolicy and .Enterprise physical stores when opening
      ; the CurrentUser's "TrustedPublisher" system store or when opening the
      ; LocalMachine's "TrustedPublisher" system store.
      CERT_TRUST_PUB_ALLOW_TRUST_MASK equ 00000003h
      CERT_TRUST_PUB_ALLOW_END_USER_TRUST equ 00000000h
      CERT_TRUST_PUB_ALLOW_MACHINE_ADMIN_TRUST equ 00000001h
      CERT_TRUST_PUB_ALLOW_ENTERPRISE_ADMIN_TRUST equ 00000002h
      ; Set the following flag to enable revocation checking of the publisher
      ; chain.
      CERT_TRUST_PUB_CHECK_PUBLISHER_REV_FLAG equ 00000100h
      ; Set the following flag to enable revocation checking of the time stamp
      ; chain.
      CERT_TRUST_PUB_CHECK_TIMESTAMP_REV_FLAG equ 00000200h
      ;+-------------------------------------------------------------------------
      ;  OCM Subcomponents Definitions
      ;  Reading of the following registry key has been deprecated on Vista.
      ;--------------------------------------------------------------------------
      ; Registry path to the OCM Subcomponents local machine subkey
      CERT_OCM_SUBCOMPONENTS_LOCAL_MACHINE_REGPATH equ <L("SOFTWARE\Microsoft\Windows\CurrentVersion\Setup\OC Manager\Subcomponents")>
      ; REG_DWORD, 1 is installed, 0 is NOT installed
      CERT_OCM_SUBCOMPONENTS_ROOT_AUTO_UPDATE_VALUE_NAME equ <L("RootAutoUpdate")>
      ;+-------------------------------------------------------------------------
      ;  Root, Disallowed Certificate and Pin Rules AutoUpdate Defines
      ;--------------------------------------------------------------------------
      ; Registry path to the DisableRootAutoUpdate SubKey
      CERT_DISABLE_ROOT_AUTO_UPDATE_REGPATH equ <CERT_GROUP_POLICY_SYSTEM_STORE_REGPATH L("\AuthRoot")>
      ; The following disables Root, Disallowed Certificate and Pin Rules AutoUpdate
      ; REG_DWORD Value Name, 1 - disables, 0 - enables
      CERT_DISABLE_ROOT_AUTO_UPDATE_VALUE_NAME equ <L("DisableRootAutoUpdate")>
      ; The following enables Disallowed Certificate and Pin Rules AutoUpdate.
      ; It takes precedence over the above registry setting.
      ; REG_DWORD Value Name, 1 - enables
      CERT_ENABLE_DISALLOWED_CERT_AUTO_UPDATE_VALUE_NAME equ <L("EnableDisallowedCertAutoUpdate")>
      ; The following disables Pin Rules AutoUpdate.
      ; It takes precedence over the above registry setting.
      ; REG_DWORD Value Name, 1 - disables
      CERT_DISABLE_PIN_RULES_AUTO_UPDATE_VALUE_NAME equ <L("DisablePinRulesAutoUpdate")>
      ;+-------------------------------------------------------------------------
      ;  Auto Update Definitions
      ;--------------------------------------------------------------------------
      ; Registry path to the "Auto Update" local machine subkey
      CERT_AUTO_UPDATE_LOCAL_MACHINE_REGPATH equ <CERT_LOCAL_MACHINE_SYSTEM_STORE_REGPATH L("\AuthRoot\AutoUpdate")>
      ; Auto Update subkey value names.
      ; REG_SZ, URL to the directory containing the AutoUpdate files
      CERT_AUTO_UPDATE_ROOT_DIR_URL_VALUE_NAME equ <L("RootDirUrl")>
      ; REG_SZ, URL to the AutoUpdate test staging directory containing the
      ; AutoUpdate files. certutil.exe will use for its -syncWithWU and
      ; -generateSSTFromWU verbs to override the default Windows Update URL.
      CERT_AUTO_UPDATE_SYNC_FROM_DIR_URL_VALUE_NAME equ <L("SyncFromDirUrl")>
      ;+-------------------------------------------------------------------------
      ;  AuthRoot Auto Update Definitions
      ;--------------------------------------------------------------------------
      ; Registry path to the AuthRoot "Auto Update" local machine subkey
      CERT_AUTH_ROOT_AUTO_UPDATE_LOCAL_MACHINE_REGPATH equ <CERT_AUTO_UPDATE_LOCAL_MACHINE_REGPATH>
      ; AuthRoot Auto Update subkey value names.
      ; REG_SZ, URL to the directory containing the AuthRoots, CTL and Seq files
      CERT_AUTH_ROOT_AUTO_UPDATE_ROOT_DIR_URL_VALUE_NAME equ <CERT_AUTO_UPDATE_ROOT_DIR_URL_VALUE_NAME>
      ; REG_DWORD, seconds between syncs. 0 implies use default.
      CERT_AUTH_ROOT_AUTO_UPDATE_SYNC_DELTA_TIME_VALUE_NAME equ <L("SyncDeltaTime")>
      ; REG_DWORD, misc flags
      CERT_AUTH_ROOT_AUTO_UPDATE_FLAGS_VALUE_NAME equ <L("Flags")>
      CERT_AUTH_ROOT_AUTO_UPDATE_DISABLE_UNTRUSTED_ROOT_LOGGING_FLAG equ 1h
      CERT_AUTH_ROOT_AUTO_UPDATE_DISABLE_PARTIAL_CHAIN_LOGGING_FLAG equ 2h
      ; By default a random query string is appended to the Auto Update URLs
      ; passed to CryptRetrieveObjectByUrlW. See the
      ; CRYPT_RANDOM_QUERY_STRING_RETRIEVAL flag for more details. Set
      ; this flag to not set this random query string. This might be the 
      ; case when setting CERT_AUTO_UPDATE_ROOT_DIR_URL_VALUE_NAME where the
      ; server doesn't strip off the query string.
      CERT_AUTO_UPDATE_DISABLE_RANDOM_QUERY_STRING_FLAG equ 4h
      ; REG_BINARY, updated with FILETIME of last wire retrieval of authroot cab/ctl
      CERT_AUTH_ROOT_AUTO_UPDATE_LAST_SYNC_TIME_VALUE_NAME equ <L("LastSyncTime")>
      ; REG_BINARY, updated with last retrieved and verified authroot ctl
      CERT_AUTH_ROOT_AUTO_UPDATE_ENCODED_CTL_VALUE_NAME equ <L("EncodedCtl")>
      ; AuthRoot Auto Update filenames
      ; CTL containing the list of certs in the AuthRoot store
      CERT_AUTH_ROOT_CTL_FILENAME equ <L("authroot.stl")>
      CERT_AUTH_ROOT_CTL_FILENAME_A equ <"authroot.stl">
      ; Cab containing the above CTL
      CERT_AUTH_ROOT_CAB_FILENAME equ <L("authrootstl.cab")>
      ; SequenceNumber (Formatted as big endian ascii hex)
      CERT_AUTH_ROOT_SEQ_FILENAME equ <L("authrootseq.txt")>
      ; Root certs extension
      CERT_AUTH_ROOT_CERT_EXT equ <L(".crt")>
      ;+-------------------------------------------------------------------------
      ;  DisallowedCert Auto Update Definitions
      ;--------------------------------------------------------------------------
      ; DisallowedCert Auto Update subkey value names.
      ; REG_DWORD, seconds between syncs. 0 implies use default.
      CERT_DISALLOWED_CERT_AUTO_UPDATE_SYNC_DELTA_TIME_VALUE_NAME equ <L("DisallowedCertSyncDeltaTime")>
      ; REG_BINARY, updated with FILETIME of last wire retrieval of disallowed cert
      ; CTL
      CERT_DISALLOWED_CERT_AUTO_UPDATE_LAST_SYNC_TIME_VALUE_NAME equ <L("DisallowedCertLastSyncTime")>
      ; REG_BINARY, updated with last retrieved and verified disallowed cert ctl
      CERT_DISALLOWED_CERT_AUTO_UPDATE_ENCODED_CTL_VALUE_NAME equ <L("DisallowedCertEncodedCtl")>
      ; DisallowedCert Auto Update filenames
      ; CTL containing the list of disallowed certs
      CERT_DISALLOWED_CERT_CTL_FILENAME equ <L("disallowedcert.stl")>
      CERT_DISALLOWED_CERT_CTL_FILENAME_A equ <"disallowedcert.stl">
      ; Cab containing disallowed certs  CTL
      CERT_DISALLOWED_CERT_CAB_FILENAME equ <L("disallowedcertstl.cab")>
      ; DisallowedCert Auto Update CTL List Identifiers
      ; Disallowed Cert CTL List Identifier
      CERT_DISALLOWED_CERT_AUTO_UPDATE_LIST_IDENTIFIER equ <L("DisallowedCert_AutoUpdate_1")>
      ;+-------------------------------------------------------------------------
      ;  PinRules Auto Update Definitions
      ;--------------------------------------------------------------------------
      ; PinRules Auto Update subkey value names.
      ; REG_DWORD, seconds between syncs. 0 implies use default.
      CERT_PIN_RULES_AUTO_UPDATE_SYNC_DELTA_TIME_VALUE_NAME equ <L("PinRulesSyncDeltaTime")>
      ; REG_BINARY, updated with FILETIME of last wire retrieval of pin rules 
      ; CTL
      CERT_PIN_RULES_AUTO_UPDATE_LAST_SYNC_TIME_VALUE_NAME equ <L("PinRulesLastSyncTime")>
      ; REG_BINARY, updated with last retrieved and verified pin rules ctl
      CERT_PIN_RULES_AUTO_UPDATE_ENCODED_CTL_VALUE_NAME equ <L("PinRulesEncodedCtl")>
      ; PinRules Auto Update filenames
      ; CTL containing the list of pin rules
      CERT_PIN_RULES_CTL_FILENAME equ <L("pinrules.stl")>
      CERT_PIN_RULES_CTL_FILENAME_A equ <"pinrules.stl">
      ; Cab containing pin rules  CTL
      CERT_PIN_RULES_CAB_FILENAME equ <L("pinrulesstl.cab")>
      ; Pin Rules Auto Update CTL List Identifiers
      ; Pin Rules CTL List Identifier
      CERT_PIN_RULES_AUTO_UPDATE_LIST_IDENTIFIER equ <L("PinRules_AutoUpdate_1")>
      ;+-------------------------------------------------------------------------
      ;  Certificate Registry Store Flag Values (CERT_STORE_REG)
      ;--------------------------------------------------------------------------
      ; Set this flag if the HKEY passed in pvPara points to a remote computer
      ; registry key.
      CERT_REGISTRY_STORE_REMOTE_FLAG equ 10000h
      ; Set this flag if the contexts are to be persisted as a single serialized
      ; store in the registry. Mainly used for stores downloaded from the GPT.
      ; Such as the CurrentUserGroupPolicy or LocalMachineGroupPolicy stores.
      CERT_REGISTRY_STORE_SERIALIZED_FLAG equ 20000h
      ; The following flags are for internal use. When set, the
      ; pvPara parameter passed to CertOpenStore is a pointer to the following
      ; data structure and not the HKEY. The above CERT_REGISTRY_STORE_REMOTE_FLAG
      ; is also set if hKeyBase was obtained via RegConnectRegistry().
      CERT_REGISTRY_STORE_CLIENT_GPT_FLAG equ 80000000h
      CERT_REGISTRY_STORE_LM_GPT_FLAG equ 01000000h
      CERT_REGISTRY_STORE_CLIENT_GPT_PARA struct
        hKeyBase HKEY ?
        pwszRegPath POINTER ?
      CERT_REGISTRY_STORE_CLIENT_GPT_PARA ends
      _CERT_REGISTRY_STORE_CLIENT_GPT_PARA typedef CERT_REGISTRY_STORE_CLIENT_GPT_PARA
      PCERT_REGISTRY_STORE_CLIENT_GPT_PARA typedef ptr CERT_REGISTRY_STORE_CLIENT_GPT_PARA
      ; The following flag is for internal use. When set, the contexts are
      ; persisted into roaming files instead of the registry. Such as, the
      ; CurrentUser "My" store. When this flag is set, the following data structure
      ; is passed to CertOpenStore instead of HKEY.
      CERT_REGISTRY_STORE_ROAMING_FLAG equ 40000h
      ; hKey may be NULL or non-NULL. When non-NULL, existing contexts are
      ; moved from the registry to roaming files.
      CERT_REGISTRY_STORE_ROAMING_PARA struct
        hKey HKEY ?
        pwszStoreDirectory POINTER ?
      CERT_REGISTRY_STORE_ROAMING_PARA ends
      _CERT_REGISTRY_STORE_ROAMING_PARA typedef CERT_REGISTRY_STORE_ROAMING_PARA
      PCERT_REGISTRY_STORE_ROAMING_PARA typedef ptr CERT_REGISTRY_STORE_ROAMING_PARA
      ; The following flag is for internal use. When set, the "My" DWORD value
      ; at HKLM\Software\Microsoft\Cryptography\IEDirtyFlags is set to 0x1
      ; whenever a certificate is added to the registry store.
      ; Legacy definition, no longer supported after 01-May-02 (Server 2003)
      CERT_REGISTRY_STORE_MY_IE_DIRTY_FLAG equ 80000h
      CERT_REGISTRY_STORE_EXTERNAL_FLAG equ 100000h
      ; Registry path to the subkey containing the "My" DWORD value to be set
      ; Legacy definition, no longer supported after 01-May-02 (Server 2003)
      CERT_IE_DIRTY_FLAGS_REGPATH equ <L("Software\Microsoft\Cryptography\IEDirtyFlags")>
      ;+-------------------------------------------------------------------------
      ;  Certificate File Store Flag Values for the providers:
      ;      CERT_STORE_PROV_FILE
      ;      CERT_STORE_PROV_FILENAME
      ;      CERT_STORE_PROV_FILENAME_A
      ;      CERT_STORE_PROV_FILENAME_W
      ;      sz_CERT_STORE_PROV_FILENAME_W
      ;--------------------------------------------------------------------------
      ; Set this flag if any store changes are to be committed to the file.
      ; The changes are committed at CertCloseStore or by calling
      ; CertControlStore(CERT_STORE_CTRL_COMMIT).
      ; The open fails with E_INVALIDARG if both CERT_FILE_STORE_COMMIT_ENABLE_FLAG
      ; and CERT_STORE_READONLY_FLAG are set in dwFlags.
      ; For the FILENAME providers:  if the file contains an X509 encoded
      ; certificate, the open fails with ERROR_ACCESS_DENIED.
      ; For the FILENAME providers: if CERT_STORE_CREATE_NEW_FLAG is set, the
      ; CreateFile uses CREATE_NEW. If CERT_STORE_OPEN_EXISTING is set, uses
      ; OPEN_EXISTING. Otherwise, defaults to OPEN_ALWAYS.
      ; For the FILENAME providers:  the file is committed as either a PKCS7 or
      ; serialized store depending on the type read at open. However, if the
      ; file is empty then, if the filename has either a ".p7c" or ".spc"
      ; extension its committed as a PKCS7. Otherwise, its committed as a
      ; serialized store.
      ; For CERT_STORE_PROV_FILE, the file handle is duplicated. Its always
      ; committed as a serialized store.
      CERT_FILE_STORE_COMMIT_ENABLE_FLAG equ 10000h
      ;+-------------------------------------------------------------------------
      ;  Certificate LDAP Store Flag Values for the providers:
      ;      CERT_STORE_PROV_LDAP
      ;      CERT_STORE_PROV_LDAP_W
      ;      sz_CERT_STORE_PROV_LDAP_W
      ;      sz_CERT_STORE_PROV_LDAP
      ;--------------------------------------------------------------------------
      ; Set this flag to digitally sign all of the ldap traffic to and from a
      ; Windows 2000 LDAP server using the Kerberos authentication protocol.
      ; This feature provides integrity required by some applications.
      CERT_LDAP_STORE_SIGN_FLAG equ 10000h
      ; Performs an A-Record only DNS lookup on the supplied host string.
      ; This prevents bogus DNS queries from being generated when resolving host
      ; names. Use this flag whenever passing a hostname as opposed to a
      ; domain name for the hostname parameter.
      ; See LDAP_OPT_AREC_EXCLUSIVE defined in winldap.h for more details.
      CERT_LDAP_STORE_AREC_EXCLUSIVE_FLAG equ 20000h
      ; Set this flag if the LDAP session handle has already been opened. When
      ; set, pvPara points to the following CERT_LDAP_STORE_OPENED_PARA structure.
      CERT_LDAP_STORE_OPENED_FLAG equ 40000h
      CERT_LDAP_STORE_OPENED_PARA struct
        pvLdapSessionHandle POINTER ?
        ; The (LDAP *) handle returned by
        ; ldap_init
        pwszLdapUrl =POINTER ?
      CERT_LDAP_STORE_OPENED_PARA ends
      _CERT_LDAP_STORE_OPENED_PARA typedef CERT_LDAP_STORE_OPENED_PARA
      PCERT_LDAP_STORE_OPENED_PARA typedef ptr CERT_LDAP_STORE_OPENED_PARA
      ; Set this flag if the above CERT_LDAP_STORE_OPENED_FLAG is set and
      ; you want an ldap_unbind() of the above pvLdapSessionHandle when the
      ; store is closed. Note, if CertOpenStore() fails, then, ldap_unbind()
      ; isn't called.
      CERT_LDAP_STORE_UNBIND_FLAG equ 80000h
      ;+-------------------------------------------------------------------------
      ;  Open the cert store using the specified store provider.
      ;  If CERT_STORE_DELETE_FLAG is set, then, the store is deleted. NULL is
      ;  returned for both success and failure. However, GetLastError() returns 0
      ;  for success and nonzero for failure.
      ;  If CERT_STORE_SET_LOCALIZED_NAME_FLAG is set, then, if supported, the
      ;  provider sets the store's CERT_STORE_LOCALIZED_NAME_PROP_ID property.
      ;  The store's localized name can be retrieved by calling
      ;  CertSetStoreProperty(dwPropID = CERT_STORE_LOCALIZED_NAME_PROP_ID).
      ;  This flag is supported by the following providers (and their sz_
      ;  equivalent):
      ;      CERT_STORE_PROV_FILENAME_A
      ;      CERT_STORE_PROV_FILENAME_W
      ;      CERT_STORE_PROV_SYSTEM_A
      ;      CERT_STORE_PROV_SYSTEM_W
      ;      CERT_STORE_PROV_SYSTEM_REGISTRY_A
      ;      CERT_STORE_PROV_SYSTEM_REGISTRY_W
      ;      CERT_STORE_PROV_PHYSICAL_W
      ;  If CERT_STORE_DEFER_CLOSE_UNTIL_LAST_FREE_FLAG is set, then, the
      ;  closing of the store's provider is deferred until all certificate,
      ;  CRL and CTL contexts obtained from the store are freed. Also,
      ;  if a non NULL HCRYPTPROV was passed, then, it will continue to be used.
      ;  By default, the store's provider is closed on the final CertCloseStore.
      ;  If this flag isn't set, then, any property changes made to previously
      ;  duplicated contexts after the final CertCloseStore will not be persisted.
      ;  By setting this flag, property changes made
      ;  after the CertCloseStore will be persisted. Note, setting this flag
      ;  causes extra overhead in doing context duplicates and frees.
      ;  If CertCloseStore is called with CERT_CLOSE_STORE_FORCE_FLAG, then,
      ;  the CERT_STORE_DEFER_CLOSE_UNTIL_LAST_FREE_FLAG flag is ignored.
      ;  CERT_STORE_MANIFOLD_FLAG can be set to check for certificates having the
      ;  manifold extension and archive the "older" certificates with the same
      ;  manifold extension value. A certificate is archived by setting the
      ;  CERT_ARCHIVED_PROP_ID.
      ;  By default, contexts having the CERT_ARCHIVED_PROP_ID, are skipped
      ;  during enumeration. CERT_STORE_ENUM_ARCHIVED_FLAG can be set to include
      ;  archived contexts when enumerating. Note, contexts having the
      ;  CERT_ARCHIVED_PROP_ID are still found for explicit finds, such as,
      ;  finding a context with a specific hash or finding a certificate having
      ;  a specific issuer and serial number.
      ;  CERT_STORE_UPDATE_KEYID_FLAG can be set to also update the Key Identifier's
      ;  CERT_KEY_PROV_INFO_PROP_ID property whenever a certificate's
      ;  CERT_KEY_IDENTIFIER_PROP_ID or CERT_KEY_PROV_INFO_PROP_ID property is set
      ;  and the other property already exists. If the Key Identifier's
      ;  CERT_KEY_PROV_INFO_PROP_ID already exists, it isn't updated. Any
      ;  errors encountered are silently ignored.
      ;  By default, this flag is implicitly set for the "My\.Default" CurrentUser
      ;  and LocalMachine physical stores.
      ;  CERT_STORE_READONLY_FLAG can be set to open the store as read only.
      ;  Otherwise, the store is opened as read/write.
      ;  CERT_STORE_OPEN_EXISTING_FLAG can be set to only open an existing
      ;  store. CERT_STORE_CREATE_NEW_FLAG can be set to create a new store and
      ;  fail if the store already exists. Otherwise, the default is to open
      ;  an existing store or create a new store if it doesn't already exist.
      ;  hCryptProv specifies the crypto provider to use to create the hash
      ;  properties or verify the signature of a subject certificate or CRL.
      ;  The store doesn't need to use a private
      ;  key. If the CERT_STORE_NO_CRYPT_RELEASE_FLAG isn't set, hCryptProv is
      ;  CryptReleaseContext'ed on the final CertCloseStore.
      ;  Note, if the open fails, hCryptProv is released if it would have been
      ;  released when the store was closed.
      ;  If hCryptProv is zero, then, the default provider and container for the
      ;  PROV_RSA_FULL provider type is CryptAcquireContext'ed with
      ;  CRYPT_VERIFYCONTEXT access. The CryptAcquireContext is deferred until
      ;  the first create hash or verify signature. In addition, once acquired,
      ;  the default provider isn't released until process exit when crypt32.dll
      ;  is unloaded. The acquired default provider is shared across all stores
      ;  and threads.
      ;  After initializing the store's data structures and optionally acquiring a
      ;  default crypt provider, CertOpenStore calls CryptGetOIDFunctionAddress to
      ;  get the address of the CRYPT_OID_OPEN_STORE_PROV_FUNC specified by
      ;  lpszStoreProvider. Since a store can contain certificates with different
      ;  encoding types, CryptGetOIDFunctionAddress is called with dwEncodingType
      ;  set to 0 and not the dwEncodingType passed to CertOpenStore.
      ;  PFN_CERT_DLL_OPEN_STORE_FUNC specifies the signature of the provider's
      ;  open function. This provider open function is called to load the
      ;  store's certificates and CRLs. Optionally, the provider may return an
      ;  array of functions called before a certificate or CRL is added or deleted
      ;  or has a property that is set.
      ;  Use of the dwEncodingType parameter is provider dependent. The type
      ;  definition for pvPara also depends on the provider.
      ;  Store providers are installed or registered via
      ;  CryptInstallOIDFunctionAddress or CryptRegisterOIDFunction, where,
      ;  dwEncodingType is 0 and pszFuncName is CRYPT_OID_OPEN_STORE_PROV_FUNC.
      ;  Here's a list of the predefined provider types (implemented in crypt32.dll):
      ;  CERT_STORE_PROV_MSG:
      ;      Gets the certificates and CRLs from the specified cryptographic message.
      ;      dwEncodingType contains the message and certificate encoding types.
      ;      The message's handle is passed in pvPara. Given,
      ;          HCRYPTMSG hCryptMsg; pvPara = (const void *) hCryptMsg;
      ;  CERT_STORE_PROV_MEMORY
      ;  sz_CERT_STORE_PROV_MEMORY:
      ;      Opens a store without any initial certificates or CRLs. pvPara
      ;      isn't used.
      ;  CERT_STORE_PROV_FILE:
      ;      Reads the certificates and CRLs from the specified file. The file's
      ;      handle is passed in pvPara. Given,
      ;          HANDLE hFile; pvPara = (const void *) hFile;
      ;      For a successful open, the file pointer is advanced past
      ;      the certificates and CRLs and their properties read from the file.
      ;      Note, only expects a serialized store and not a file containing
      ;      either a PKCS #7 signed message or a single encoded certificate.
      ;      The hFile isn't closed.
      ;  CERT_STORE_PROV_REG:
      ;      Reads the certificates and CRLs from the registry. The registry's
      ;      key handle is passed in pvPara. Given,
      ;          HKEY hKey; pvPara = (const void *) hKey;
      ;      The input hKey isn't closed by the provider. Before returning, the
      ;      provider opens it own copy of the hKey.
      ;      If CERT_STORE_READONLY_FLAG is set, then, the registry subkeys are
      ;      RegOpenKey'ed with KEY_READ_ACCESS. Otherwise, the registry subkeys
      ;      are RegCreateKey'ed with KEY_ALL_ACCESS.
      ;      This provider returns the array of functions for reading, writing,
      ;      deleting and property setting certificates and CRLs.
      ;      Any changes to the opened store are immediately pushed through to
      ;      the registry. However, if CERT_STORE_READONLY_FLAG is set, then,
      ;      writing, deleting or property setting results in a
      ;      SetLastError(E_ACCESSDENIED).
      ;      Note, all the certificates and CRLs are read from the registry
      ;      when the store is opened. The opened store serves as a write through
      ;      cache.
      ;      If CERT_REGISTRY_STORE_SERIALIZED_FLAG is set, then, the
      ;      contexts are persisted as a single serialized store subkey in the
      ;      registry.
      ;  CERT_STORE_PROV_PKCS7:
      ;  sz_CERT_STORE_PROV_PKCS7:
      ;      Gets the certificates and CRLs from the encoded PKCS #7 signed message.
      ;      dwEncodingType specifies the message and certificate encoding types.
      ;      The pointer to the encoded message's blob is passed in pvPara. Given,
      ;          CRYPT_DATA_BLOB EncodedMsg; pvPara = (const void *) &EncodedMsg;
      ;      Note, also supports the IE3.0 special version of a
      ;      PKCS #7 signed message referred to as a "SPC" formatted message.
      ;  CERT_STORE_PROV_SERIALIZED:
      ;  sz_CERT_STORE_PROV_SERIALIZED:
      ;      Gets the certificates and CRLs from memory containing a serialized
      ;      store.  The pointer to the serialized memory blob is passed in pvPara.
      ;      Given,
      ;          CRYPT_DATA_BLOB Serialized; pvPara = (const void *) &Serialized;
      ;  CERT_STORE_PROV_FILENAME_A:
      ;  CERT_STORE_PROV_FILENAME_W:
      ;  CERT_STORE_PROV_FILENAME:
      ;  sz_CERT_STORE_PROV_FILENAME_W:
      ;  sz_CERT_STORE_PROV_FILENAME:
      ;      Opens the file and first attempts to read as a serialized store. Then,
      ;      as a PKCS #7 signed message. Finally, as a single encoded certificate.
      ;      The filename is passed in pvPara. The filename is UNICODE for the
      ;      "_W" provider and ASCII for the "_A" provider. For "_W": given,
      ;          LPCWSTR pwszFilename; pvPara = (const void *) pwszFilename;
      ;      For "_A": given,
      ;          LPCSTR pszFilename; pvPara = (const void *) pszFilename;
      ;      Note, the default (without "_A" or "_W") is unicode.
      ;      Note, also supports the reading of the IE3.0 special version of a
      ;      PKCS #7 signed message file referred to as a "SPC" formatted file.
      ;  CERT_STORE_PROV_SYSTEM_A:
      ;  CERT_STORE_PROV_SYSTEM_W:
      ;  CERT_STORE_PROV_SYSTEM:
      ;  sz_CERT_STORE_PROV_SYSTEM_W:
      ;  sz_CERT_STORE_PROV_SYSTEM:
      ;      Opens the specified logical "System" store. The upper word of the
      ;      dwFlags parameter is used to specify the location of the system store.
      ;      A "System" store is a collection consisting of one or more "Physical"
      ;      stores. A "Physical" store is registered via the
      ;      CertRegisterPhysicalStore API. Each of the registered physical stores
      ;      is CertStoreOpen'ed and added to the collection via
      ;      CertAddStoreToCollection.
      ;      The CERT_SYSTEM_STORE_CURRENT_USER, CERT_SYSTEM_STORE_LOCAL_MACHINE,
      ;      CERT_SYSTEM_STORE_CURRENT_SERVICE, CERT_SYSTEM_STORE_SERVICES,
      ;      CERT_SYSTEM_STORE_USERS, CERT_SYSTEM_STORE_CURRENT_USER_GROUP_POLICY,
      ;      CERT_SYSTEM_STORE_LOCAL_MACHINE_GROUP_POLICY and
      ;      CERT_SYSTEM_STORE_LOCAL_MACHINE_ENTERPRSE
      ;      system stores by default have a "SystemRegistry" store that is
      ;      opened and added to the collection.
      ;      The system store name is passed in pvPara. The name is UNICODE for the
      ;      "_W" provider and ASCII for the "_A" provider. For "_W": given,
      ;          LPCWSTR pwszSystemName; pvPara = (const void *) pwszSystemName;
      ;      For "_A": given,
      ;          LPCSTR pszSystemName; pvPara = (const void *) pszSystemName;
      ;      Note, the default (without "_A" or "_W") is UNICODE.
      ;      The system store name can't contain any backslashes.
      ;      If CERT_SYSTEM_STORE_RELOCATE_FLAG is set in dwFlags, pvPara
      ;      points to a CERT_SYSTEM_STORE_RELOCATE_PARA data structure instead
      ;      of pointing to a null terminated UNICODE or ASCII string.
      ;      Sibling physical stores are also opened as relocated using
      ;      pvPara's hKeyBase.
      ;      The CERT_SYSTEM_STORE_SERVICES or CERT_SYSTEM_STORE_USERS system
      ;      store name must be prefixed with the ServiceName or UserName.
      ;      For example, "ServiceName\Trust".
      ;      Stores on remote computers can be accessed for the
      ;      CERT_SYSTEM_STORE_LOCAL_MACHINE, CERT_SYSTEM_STORE_SERVICES,
      ;      CERT_SYSTEM_STORE_USERS, CERT_SYSTEM_STORE_LOCAL_MACHINE_GROUP_POLICY
      ;      or CERT_SYSTEM_STORE_LOCAL_MACHINE_ENTERPRISE
      ;      locations by prepending the computer name. For example, a remote
      ;      local machine store is accessed via "\\ComputerName\Trust" or
      ;      "ComputerName\Trust". A remote service store is accessed via
      ;      "\\ComputerName\ServiceName\Trust". The leading "\\" backslashes are
      ;      optional in the ComputerName.
      ;      If CERT_STORE_READONLY_FLAG is set, then, the registry is
      ;      RegOpenKey'ed with KEY_READ_ACCESS. Otherwise, the registry is
      ;      RegCreateKey'ed with KEY_ALL_ACCESS.
      ;      The "root" store is treated differently from the other system
      ;      stores. Before a certificate is added to or deleted from the "root"
      ;      store, a pop up message box is displayed. The certificate's subject,
      ;      issuer, serial number, time validity, sha1 and md5 thumbprints are
      ;      displayed. The user is given the option to do the add or delete.
      ;      If they don't allow the operation, LastError is set to E_ACCESSDENIED.
      ;  CERT_STORE_PROV_SYSTEM_REGISTRY_A
      ;  CERT_STORE_PROV_SYSTEM_REGISTRY_W
      ;  CERT_STORE_PROV_SYSTEM_REGISTRY
      ;  sz_CERT_STORE_PROV_SYSTEM_REGISTRY_W
      ;  sz_CERT_STORE_PROV_SYSTEM_REGISTRY
      ;      Opens the "System" store's default "Physical" store residing in the
      ;      registry. The upper word of the dwFlags
      ;      parameter is used to specify the location of the system store.
      ;      After opening the registry key associated with the system name,
      ;      the CERT_STORE_PROV_REG provider is called to complete the open.
      ;      The system store name is passed in pvPara. The name is UNICODE for the
      ;      "_W" provider and ASCII for the "_A" provider. For "_W": given,
      ;          LPCWSTR pwszSystemName; pvPara = (const void *) pwszSystemName;
      ;      For "_A": given,
      ;          LPCSTR pszSystemName; pvPara = (const void *) pszSystemName;
      ;      Note, the default (without "_A" or "_W") is UNICODE.
      ;      If CERT_SYSTEM_STORE_RELOCATE_FLAG is set in dwFlags, pvPara
      ;      points to a CERT_SYSTEM_STORE_RELOCATE_PARA data structure instead
      ;      of pointing to a null terminated UNICODE or ASCII string.
      ;      See above for details on prepending a ServiceName and/or ComputerName
      ;      to the store name.
      ;      If CERT_STORE_READONLY_FLAG is set, then, the registry is
      ;      RegOpenKey'ed with KEY_READ_ACCESS. Otherwise, the registry is
      ;      RegCreateKey'ed with KEY_ALL_ACCESS.
      ;      The "root" store is treated differently from the other system
      ;      stores. Before a certificate is added to or deleted from the "root"
      ;      store, a pop up message box is displayed. The certificate's subject,
      ;      issuer, serial number, time validity, sha1 and md5 thumbprints are
      ;      displayed. The user is given the option to do the add or delete.
      ;      If they don't allow the operation, LastError is set to E_ACCESSDENIED.
      ;  CERT_STORE_PROV_PHYSICAL_W
      ;  CERT_STORE_PROV_PHYSICAL
      ;  sz_CERT_STORE_PROV_PHYSICAL_W
      ;  sz_CERT_STORE_PROV_PHYSICAL
      ;      Opens the specified "Physical" store in the "System" store.
      ;      Both the system store and physical names are passed in pvPara. The
      ;      names are separated with an intervening "\". For example,
      ;      "Root\.Default". The string is UNICODE.
      ;      The system and physical store names can't contain any backslashes.
      ;      If CERT_SYSTEM_STORE_RELOCATE_FLAG is set in dwFlags, pvPara
      ;      points to a CERT_SYSTEM_STORE_RELOCATE_PARA data structure instead
      ;      of pointing to a null terminated UNICODE string.
      ;      The specified physical store is opened as relocated using pvPara's
      ;      hKeyBase.
      ;      For CERT_SYSTEM_STORE_SERVICES or CERT_SYSTEM_STORE_USERS,
      ;      the system and physical store names
      ;      must be prefixed with the ServiceName or UserName. For example,
      ;      "ServiceName\Root\.Default".
      ;      Physical stores on remote computers can be accessed for the
      ;      CERT_SYSTEM_STORE_LOCAL_MACHINE, CERT_SYSTEM_STORE_SERVICES,
      ;      CERT_SYSTEM_STORE_USERS, CERT_SYSTEM_STORE_LOCAL_MACHINE_GROUP_POLICY
      ;      or CERT_SYSTEM_STORE_LOCAL_MACHINE_ENTERPRISE
      ;      locations by prepending the computer name. For example, a remote
      ;      local machine store is accessed via "\\ComputerName\Root\.Default"
      ;      or "ComputerName\Root\.Default". A remote service store is
      ;      accessed via "\\ComputerName\ServiceName\Root\.Default". The
      ;      leading "\\" backslashes are optional in the ComputerName.
      ;  CERT_STORE_PROV_COLLECTION
      ;  sz_CERT_STORE_PROV_COLLECTION
      ;      Opens a store that is a collection of other stores. Stores are
      ;      added or removed to/from the collection via the CertAddStoreToCollection
      ;      and CertRemoveStoreFromCollection APIs.
      ;  CERT_STORE_PROV_SMART_CARD_W
      ;  CERT_STORE_PROV_SMART_CARD
      ;  sz_CERT_STORE_PROV_SMART_CARD_W
      ;  sz_CERT_STORE_PROV_SMART_CARD
      ;      Opens a store instantiated over a particular smart card storage.  pvPara
      ;      identifies where on the card the store is located and is of the
      ;      following format:
      ;                Card Name\Provider Name\Provider Type[\Container Name]
      ;      Container Name is optional and if NOT specified the Card Name is used
      ;      as the Container Name.  Future versions of the provider will support
      ;      instantiating the store over the entire card in which case just
      ;      Card Name ( or id ) will be sufficient.
      ;  Here's a list of the predefined provider types (implemented in
      ;  cryptnet.dll):
      ;  CERT_STORE_PROV_LDAP_W
      ;  CERT_STORE_PROV_LDAP
      ;  sz_CERT_STORE_PROV_LDAP_W
      ;  sz_CERT_STORE_PROV_LDAP
      ;      Opens a store over the results of the query specified by and LDAP
      ;      URL which is passed in via pvPara.  In order to do writes to the
      ;      store the URL must specify a BASE query, no filter and a single
      ;      attribute.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertOpenStore, WIN_STD_CALL_CONV,, <:LPCSTR, :DWORD, :HCRYPTPROV_LEGACY, :DWORD, :ptr>, 20
      ;+-------------------------------------------------------------------------
      ;  OID Installable Certificate Store Provider Data Structures
      ;--------------------------------------------------------------------------
      ; Handle returned by the store provider when opened.
      HCERTSTOREPROV typedef ptr
      ; Store Provider OID function's pszFuncName.
      CRYPT_OID_OPEN_STORE_PROV_FUNC equ <"CertDllOpenStoreProv">
      ; Note, the Store Provider OID function's dwEncodingType is always 0.
      ; The following information is returned by the provider when opened. Its
      ; zeroed with cbSize set before the provider is called. If the provider
      ; doesn't need to be called again after the open it doesn't need to
      ; make any updates to the CERT_STORE_PROV_INFO.
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
      ; Definition of the store provider's open function.
      ; *pStoreProvInfo has been zeroed before the call.
      ; Note, pStoreProvInfo->cStoreProvFunc should be set last.  Once set,
      ; all subsequent store calls, such as CertAddSerializedElementToStore will
      ; call the appropriate provider callback function.
      TYPE_PFN_CERT_DLL_OPEN_STORE_PROV_FUNC typedef proto WIN_STD_CALL_CONV :LPCSTR, :DWORD, :HCRYPTPROV_LEGACY, :DWORD, :ptr, :HCERTSTORE, :PCERT_STORE_PROV_INFO
      PFN_CERT_DLL_OPEN_STORE_PROV_FUNC typedef ptr TYPE_PFN_CERT_DLL_OPEN_STORE_PROV_FUNC

      ; The open callback sets the following flag, if it maintains its
      ; contexts externally and not in the cached store.
      CERT_STORE_PROV_EXTERNAL_FLAG equ 1h
      ; The open callback sets the following flag for a successful delete.
      ; When set, the close callback isn't called.
      CERT_STORE_PROV_DELETED_FLAG equ 2h
      ; The open callback sets the following flag if it doesn't persist store
      ; changes.
      CERT_STORE_PROV_NO_PERSIST_FLAG equ 4h
      ; The open callback sets the following flag if the contexts are persisted
      ; to a system store.
      CERT_STORE_PROV_SYSTEM_STORE_FLAG equ 8h
      ; The open callback sets the following flag if the contexts are persisted
      ; to a LocalMachine system store.
      CERT_STORE_PROV_LM_SYSTEM_STORE_FLAG equ 10h
      ; The open callback sets the following flag if the contexts are persisted
      ; to a GroupPolicy system store.
      CERT_STORE_PROV_GP_SYSTEM_STORE_FLAG equ 20h
      ; The open callback sets the following flag if the contexts are from
      ; a Shared User physical store.
      CERT_STORE_PROV_SHARED_USER_FLAG equ 40h
      ; Indices into the store provider's array of callback functions.
      ; The provider can implement any subset of the following functions. It
      ; sets pStoreProvInfo->cStoreProvFunc to the last index + 1 and any
      ; preceding not implemented functions to NULL.
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
      ; Called by CertCloseStore when the store's reference count is
      ; decremented to 0.
      TYPE_PFN_CERT_STORE_PROV_CLOSE typedef proto WIN_STD_CALL_CONV :HCERTSTOREPROV, :DWORD
      PFN_CERT_STORE_PROV_CLOSE typedef ptr TYPE_PFN_CERT_STORE_PROV_CLOSE

      ; Currently not called directly by the store APIs. However, may be exported
      ; to support other providers based on it.
      ; Reads the provider's copy of the certificate context. If it exists,
      ; creates a new certificate context.
      TYPE_PFN_CERT_STORE_PROV_READ_CERT typedef proto WIN_STD_CALL_CONV :HCERTSTOREPROV, :PCCERT_CONTEXT, :DWORD, :ptr PCCERT_CONTEXT
      PFN_CERT_STORE_PROV_READ_CERT typedef ptr TYPE_PFN_CERT_STORE_PROV_READ_CERT

      CERT_STORE_PROV_WRITE_ADD_FLAG equ 1h
      ; Called by CertAddEncodedCertificateToStore,
      ; CertAddCertificateContextToStore or CertAddSerializedElementToStore before
      ; adding to the store. The CERT_STORE_PROV_WRITE_ADD_FLAG is set. In
      ; addition to the encoded certificate, the added pCertContext might also
      ; have properties.
      ; Returns TRUE if its OK to update the the store.
      TYPE_PFN_CERT_STORE_PROV_WRITE_CERT typedef proto WIN_STD_CALL_CONV :HCERTSTOREPROV, :PCCERT_CONTEXT, :DWORD
      PFN_CERT_STORE_PROV_WRITE_CERT typedef ptr TYPE_PFN_CERT_STORE_PROV_WRITE_CERT

      ; Called by CertDeleteCertificateFromStore before deleting from the
      ; store.
      ; Returns TRUE if its OK to delete from the store.
      TYPE_PFN_CERT_STORE_PROV_DELETE_CERT typedef proto WIN_STD_CALL_CONV :HCERTSTOREPROV, :PCCERT_CONTEXT, :DWORD
      PFN_CERT_STORE_PROV_DELETE_CERT typedef ptr TYPE_PFN_CERT_STORE_PROV_DELETE_CERT

      ; Called by CertSetCertificateContextProperty before setting the
      ; certificate's property. Also called by CertGetCertificateContextProperty,
      ; when getting a hash property that needs to be created and then persisted
      ; via the set.
      ; Upon input, the property hasn't been set for the pCertContext parameter.
      ; Returns TRUE if its OK to set the property.
      TYPE_PFN_CERT_STORE_PROV_SET_CERT_PROPERTY typedef proto WIN_STD_CALL_CONV :HCERTSTOREPROV, :PCCERT_CONTEXT, :DWORD, :DWORD, :ptr
      PFN_CERT_STORE_PROV_SET_CERT_PROPERTY typedef ptr TYPE_PFN_CERT_STORE_PROV_SET_CERT_PROPERTY

      ; Currently not called directly by the store APIs. However, may be exported
      ; to support other providers based on it.
      ; Reads the provider's copy of the CRL context. If it exists,
      ; creates a new CRL context.
      TYPE_PFN_CERT_STORE_PROV_READ_CRL typedef proto WIN_STD_CALL_CONV :HCERTSTOREPROV, :PCCRL_CONTEXT, :DWORD, :ptr PCCRL_CONTEXT
      PFN_CERT_STORE_PROV_READ_CRL typedef ptr TYPE_PFN_CERT_STORE_PROV_READ_CRL

      ; Called by CertAddEncodedCRLToStore,
      ; CertAddCRLContextToStore or CertAddSerializedElementToStore before
      ; adding to the store. The CERT_STORE_PROV_WRITE_ADD_FLAG is set. In
      ; addition to the encoded CRL, the added pCertContext might also
      ; have properties.
      ; Returns TRUE if its OK to update the the store.
      TYPE_PFN_CERT_STORE_PROV_WRITE_CRL typedef proto WIN_STD_CALL_CONV :HCERTSTOREPROV, :PCCRL_CONTEXT, :DWORD
      PFN_CERT_STORE_PROV_WRITE_CRL typedef ptr TYPE_PFN_CERT_STORE_PROV_WRITE_CRL

      ; Called by CertDeleteCRLFromStore before deleting from the store.
      ; Returns TRUE if its OK to delete from the store.
      TYPE_PFN_CERT_STORE_PROV_DELETE_CRL typedef proto WIN_STD_CALL_CONV :HCERTSTOREPROV, :PCCRL_CONTEXT, :DWORD
      PFN_CERT_STORE_PROV_DELETE_CRL typedef ptr TYPE_PFN_CERT_STORE_PROV_DELETE_CRL

      ; Called by CertSetCRLContextProperty before setting the
      ; CRL's property. Also called by CertGetCRLContextProperty,
      ; when getting a hash property that needs to be created and then persisted
      ; via the set.
      ; Upon input, the property hasn't been set for the pCrlContext parameter.
      ; Returns TRUE if its OK to set the property.
      TYPE_PFN_CERT_STORE_PROV_SET_CRL_PROPERTY typedef proto WIN_STD_CALL_CONV :HCERTSTOREPROV, :PCCRL_CONTEXT, :DWORD, :DWORD, :ptr
      PFN_CERT_STORE_PROV_SET_CRL_PROPERTY typedef ptr TYPE_PFN_CERT_STORE_PROV_SET_CRL_PROPERTY

      ; Currently not called directly by the store APIs. However, may be exported
      ; to support other providers based on it.
      ; Reads the provider's copy of the CTL context. If it exists,
      ; creates a new CTL context.
      TYPE_PFN_CERT_STORE_PROV_READ_CTL typedef proto WIN_STD_CALL_CONV :HCERTSTOREPROV, :PCCTL_CONTEXT, :DWORD, :ptr PCCTL_CONTEXT
      PFN_CERT_STORE_PROV_READ_CTL typedef ptr TYPE_PFN_CERT_STORE_PROV_READ_CTL

      ; Called by CertAddEncodedCTLToStore,
      ; CertAddCTLContextToStore or CertAddSerializedElementToStore before
      ; adding to the store. The CERT_STORE_PROV_WRITE_ADD_FLAG is set. In
      ; addition to the encoded CTL, the added pCertContext might also
      ; have properties.
      ; Returns TRUE if its OK to update the the store.
      TYPE_PFN_CERT_STORE_PROV_WRITE_CTL typedef proto WIN_STD_CALL_CONV :HCERTSTOREPROV, :PCCTL_CONTEXT, :DWORD
      PFN_CERT_STORE_PROV_WRITE_CTL typedef ptr TYPE_PFN_CERT_STORE_PROV_WRITE_CTL

      ; Called by CertDeleteCTLFromStore before deleting from the store.
      ; Returns TRUE if its OK to delete from the store.
      TYPE_PFN_CERT_STORE_PROV_DELETE_CTL typedef proto WIN_STD_CALL_CONV :HCERTSTOREPROV, :PCCTL_CONTEXT, :DWORD
      PFN_CERT_STORE_PROV_DELETE_CTL typedef ptr TYPE_PFN_CERT_STORE_PROV_DELETE_CTL

      ; Called by CertSetCTLContextProperty before setting the
      ; CTL's property. Also called by CertGetCTLContextProperty,
      ; when getting a hash property that needs to be created and then persisted
      ; via the set.
      ; Upon input, the property hasn't been set for the pCtlContext parameter.
      ; Returns TRUE if its OK to set the property.
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

      ;+-------------------------------------------------------------------------
      ;  Duplicate a cert store handle
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertDuplicateStore, WIN_STD_CALL_CONV,, <:HCERTSTORE>, 4
      CERT_STORE_SAVE_AS_STORE equ 1
      CERT_STORE_SAVE_AS_PKCS7 equ 2
      CERT_STORE_SAVE_AS_PKCS12 equ 3
      CERT_STORE_SAVE_TO_FILE equ 1
      CERT_STORE_SAVE_TO_MEMORY equ 2
      CERT_STORE_SAVE_TO_FILENAME_A equ 3
      CERT_STORE_SAVE_TO_FILENAME_W equ 4
      CERT_STORE_SAVE_TO_FILENAME equ <CERT_STORE_SAVE_TO_FILENAME_W>
      ;+-------------------------------------------------------------------------
      ;  Save the cert store. Extended version with lots of options.
      ;  According to the dwSaveAs parameter, the store can be saved as a
      ;  serialized store (CERT_STORE_SAVE_AS_STORE) containing properties in
      ;  addition to encoded certificates, CRLs and CTLs or the store can be saved
      ;  as a PKCS #7 signed message (CERT_STORE_SAVE_AS_PKCS7) which doesn't
      ;  include the properties or CTLs.
      ;  Note, the CERT_KEY_CONTEXT_PROP_ID property (and its
      ;  CERT_KEY_PROV_HANDLE_PROP_ID or CERT_KEY_SPEC_PROP_ID) isn't saved into
      ;  a serialized store.
      ;  For CERT_STORE_SAVE_AS_PKCS7, the dwEncodingType specifies the message
      ;  encoding type. The dwEncodingType parameter isn't used for
      ;  CERT_STORE_SAVE_AS_STORE.
      ;  The dwFlags parameter currently isn't used and should be set to 0.
      ;  The dwSaveTo and pvSaveToPara parameters specify where to save the
      ;  store as follows:
      ;    CERT_STORE_SAVE_TO_FILE:
      ;      Saves to the specified file. The file's handle is passed in
      ;      pvSaveToPara. Given,
      ;          HANDLE hFile; pvSaveToPara = (void *) hFile;
      ;      For a successful save, the file pointer is positioned after the
      ;      last write.
      ;    CERT_STORE_SAVE_TO_MEMORY:
      ;      Saves to the specified memory blob. The pointer to
      ;      the memory blob is passed in pvSaveToPara. Given,
      ;          CRYPT_DATA_BLOB SaveBlob; pvSaveToPara = (void *) &SaveBlob;
      ;      Upon entry, the SaveBlob's pbData and cbData need to be initialized.
      ;      Upon return, cbData is updated with the actual length.
      ;      For a length only calculation, pbData should be set to NULL. If
      ;      pbData is non-NULL and cbData isn't large enough, FALSE is returned
      ;      with a last error of ERRROR_MORE_DATA.
      ;    CERT_STORE_SAVE_TO_FILENAME_A:
      ;    CERT_STORE_SAVE_TO_FILENAME_W:
      ;    CERT_STORE_SAVE_TO_FILENAME:
      ;      Opens the file and saves to it. The filename is passed in pvSaveToPara.
      ;      The filename is UNICODE for the "_W" option and ASCII for the "_A"
      ;      option. For "_W": given,
      ;          LPCWSTR pwszFilename; pvSaveToPara = (void *) pwszFilename;
      ;      For "_A": given,
      ;          LPCSTR pszFilename; pvSaveToPara = (void *) pszFilename;
      ;      Note, the default (without "_A" or "_W") is UNICODE.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertSaveStore, WIN_STD_CALL_CONV,, <:HCERTSTORE, :DWORD, :DWORD, :DWORD, :ptr, :DWORD>, 24
      ;+-------------------------------------------------------------------------
      ;  Certificate Store close flags
      ;--------------------------------------------------------------------------
      CERT_CLOSE_STORE_FORCE_FLAG equ 00000001h
      CERT_CLOSE_STORE_CHECK_FLAG equ 00000002h
      ;+-------------------------------------------------------------------------
      ;  Close a cert store handle.
      ;  There needs to be a corresponding close for each open and duplicate.
      ;  Even on the final close, the cert store isn't freed until all of its
      ;  certificate and CRL contexts have also been freed.
      ;  On the final close, the hCryptProv passed to CertStoreOpen is
      ;  CryptReleaseContext'ed.
      ;  To force the closure of the store with all of its memory freed, set the
      ;  CERT_STORE_CLOSE_FORCE_FLAG. This flag should be set when the caller does
      ;  its own reference counting and wants everything to vanish.
      ;  To check if all the store's certificates and CRLs have been freed and that
      ;  this is the last CertCloseStore, set the CERT_CLOSE_STORE_CHECK_FLAG. If
      ;  set and certs, CRLs or stores still need to be freed/closed, FALSE is
      ;  returned with LastError set to CRYPT_E_PENDING_CLOSE. Note, for FALSE,
      ;  the store is still closed. This is a diagnostic flag.
      ;  LastError is preserved unless CERT_CLOSE_STORE_CHECK_FLAG is set and FALSE
      ;  is returned.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertCloseStore, WIN_STD_CALL_CONV,, <:HCERTSTORE, :DWORD>, 8
      ;+-------------------------------------------------------------------------
      ;  Get the subject certificate context uniquely identified by its Issuer and
      ;  SerialNumber from the store.
      ;  If the certificate isn't found, NULL is returned. Otherwise, a pointer to
      ;  a read only CERT_CONTEXT is returned. CERT_CONTEXT must be freed by calling
      ;  CertFreeCertificateContext. CertDuplicateCertificateContext can be called to make a
      ;  duplicate.
      ;  The returned certificate might not be valid. Normally, it would be
      ;  verified when getting its issuer certificate (CertGetIssuerCertificateFromStore).
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertGetSubjectCertificateFromStore, WIN_STD_CALL_CONV,, <:HCERTSTORE, :DWORD, :PCERT_INFO>, 12
      ; fields are used
      ;+-------------------------------------------------------------------------
      ;  Enumerate the certificate contexts in the store.
      ;  If a certificate isn't found, NULL is returned.
      ;  Otherwise, a pointer to a read only CERT_CONTEXT is returned. CERT_CONTEXT
      ;  must be freed by calling CertFreeCertificateContext or is freed when passed as the
      ;  pPrevCertContext on a subsequent call. CertDuplicateCertificateContext
      ;  can be called to make a duplicate.
      ;  pPrevCertContext MUST BE NULL to enumerate the first
      ;  certificate in the store. Successive certificates are enumerated by setting
      ;  pPrevCertContext to the CERT_CONTEXT returned by a previous call.
      ;  NOTE: a NON-NULL pPrevCertContext is always CertFreeCertificateContext'ed by
      ;  this function, even for an error.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertEnumCertificatesInStore, WIN_STD_CALL_CONV,, <:HCERTSTORE, :PCCERT_CONTEXT>, 8
      ;+-------------------------------------------------------------------------
      ;  Find the first or next certificate context in the store.
      ;  The certificate is found according to the dwFindType and its pvFindPara.
      ;  See below for a list of the find types and its parameters.
      ;  Currently dwFindFlags is only used for CERT_FIND_SUBJECT_ATTR,
      ;  CERT_FIND_ISSUER_ATTR or CERT_FIND_CTL_USAGE. Otherwise, must be set to 0.
      ;  Usage of dwCertEncodingType depends on the dwFindType.
      ;  If the first or next certificate isn't found, NULL is returned.
      ;  Otherwise, a pointer to a read only CERT_CONTEXT is returned. CERT_CONTEXT
      ;  must be freed by calling CertFreeCertificateContext or is freed when passed as the
      ;  pPrevCertContext on a subsequent call. CertDuplicateCertificateContext
      ;  can be called to make a duplicate.
      ;  pPrevCertContext MUST BE NULL on the first
      ;  call to find the certificate. To find the next certificate, the
      ;  pPrevCertContext is set to the CERT_CONTEXT returned by a previous call.
      ;  NOTE: a NON-NULL pPrevCertContext is always CertFreeCertificateContext'ed by
      ;  this function, even for an error.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertFindCertificateInStore, WIN_STD_CALL_CONV,, <:HCERTSTORE, :DWORD, :DWORD, :DWORD, :ptr, :PCCERT_CONTEXT>, 24
      ;+-------------------------------------------------------------------------
      ; Certificate comparison functions
      ;--------------------------------------------------------------------------
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
      ;+-------------------------------------------------------------------------
      ;  dwFindType
      ;  The dwFindType definition consists of two components:
      ;   - comparison function
      ;   - certificate information flag
      ;--------------------------------------------------------------------------
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
      ;+-------------------------------------------------------------------------
      ;  CERT_FIND_ANY
      ;  Find any certificate.
      ;  pvFindPara isn't used.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  CERT_FIND_HASH
      ;  Find a certificate with the specified hash.
      ;  pvFindPara points to a CRYPT_HASH_BLOB.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  CERT_FIND_KEY_IDENTIFIER
      ;  Find a certificate with the specified KeyIdentifier. Gets the
      ;  CERT_KEY_IDENTIFIER_PROP_ID property and compares with the input
      ;  CRYPT_HASH_BLOB.
      ;  pvFindPara points to a CRYPT_HASH_BLOB.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  CERT_FIND_PROPERTY
      ;  Find a certificate having the specified property.
      ;  pvFindPara points to a DWORD containing the PROP_ID
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  CERT_FIND_PUBLIC_KEY
      ;  Find a certificate matching the specified public key.
      ;  pvFindPara points to a CERT_PUBLIC_KEY_INFO containing the public key
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  CERT_FIND_SUBJECT_NAME
      ;  CERT_FIND_ISSUER_NAME
      ;  Find a certificate with the specified subject/issuer name. Does an exact
      ;  match of the entire name.
      ;  Restricts search to certificates matching the dwCertEncodingType.
      ;  pvFindPara points to a CERT_NAME_BLOB.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  CERT_FIND_SUBJECT_ATTR
      ;  CERT_FIND_ISSUER_ATTR
      ;  Find a certificate with the specified subject/issuer attributes.
      ;  Compares the attributes in the subject/issuer name with the
      ;  Relative Distinguished Name's (CERT_RDN) array of attributes specified in
      ;  pvFindPara. The comparison iterates through the CERT_RDN attributes and looks
      ;  for an attribute match in any of the subject/issuer's RDNs.
      ;  The CERT_RDN_ATTR fields can have the following special values:
      ;    pszObjId == NULL              - ignore the attribute object identifier
      ;    dwValueType == RDN_ANY_TYPE   - ignore the value type
      ;    Value.pbData == NULL          - match any value
      ;  CERT_CASE_INSENSITIVE_IS_RDN_ATTRS_FLAG should be set in dwFindFlags to do
      ;  a case insensitive match. Otherwise, defaults to an exact, case sensitive
      ;  match.
      ;  CERT_UNICODE_IS_RDN_ATTRS_FLAG should be set in dwFindFlags if the RDN was
      ;  initialized with unicode strings as for
      ;  CryptEncodeObject(X509_UNICODE_NAME).
      ;  Restricts search to certificates matching the dwCertEncodingType.
      ;  pvFindPara points to a CERT_RDN (defined in wincert.h).
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  CERT_FIND_SUBJECT_STR_A
      ;  CERT_FIND_SUBJECT_STR_W | CERT_FIND_SUBJECT_STR
      ;  CERT_FIND_ISSUER_STR_A
      ;  CERT_FIND_ISSUER_STR_W  | CERT_FIND_ISSUER_STR
      ;  Find a certificate containing the specified subject/issuer name string.
      ;  First, the certificate's subject/issuer is converted to a name string
      ;  via CertNameToStrA/CertNameToStrW(CERT_SIMPLE_NAME_STR). Then, a
      ;  case insensitive substring within string match is performed.
      ;  Restricts search to certificates matching the dwCertEncodingType.
      ;  For *_STR_A, pvFindPara points to a null terminated character string.
      ;  For *_STR_W, pvFindPara points to a null terminated wide character string.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  CERT_FIND_KEY_SPEC
      ;  Find a certificate having a CERT_KEY_SPEC_PROP_ID property matching
      ;  the specified KeySpec.
      ;  pvFindPara points to a DWORD containing the KeySpec.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  CERT_FIND_ENHKEY_USAGE
      ;  Find a certificate having the szOID_ENHANCED_KEY_USAGE extension or
      ;  the CERT_ENHKEY_USAGE_PROP_ID and matching the specified pszUsageIdentifers.
      ;  pvFindPara points to a CERT_ENHKEY_USAGE data structure. If pvFindPara
      ;  is NULL or CERT_ENHKEY_USAGE's cUsageIdentifier is 0, then, matches any
      ;  certificate having enhanced key usage.
      ;  If the CERT_FIND_VALID_ENHKEY_USAGE_FLAG is set, then, only does a match
      ;  for certificates that are valid for the specified usages. By default,
      ;  the ceriticate must be valid for all usages. CERT_FIND_OR_ENHKEY_USAGE_FLAG
      ;  can be set, if the certificate only needs to be valid for one of the
      ;  specified usages. Note, CertGetValidUsages() is called to get the
      ;  certificate's list of valid usages. Only the CERT_FIND_OR_ENHKEY_USAGE_FLAG
      ;  is applicable when this flag is set.
      ;  The CERT_FIND_OPTIONAL_ENHKEY_USAGE_FLAG can be set in dwFindFlags to
      ;  also match a certificate without either the extension or property.
      ;  If CERT_FIND_NO_ENHKEY_USAGE_FLAG is set in dwFindFlags, finds
      ;  certificates without the key usage extension or property. Setting this
      ;  flag takes precedence over pvFindPara being NULL.
      ;  If the CERT_FIND_EXT_ONLY_ENHKEY_USAGE_FLAG is set, then, only does a match
      ;  using the extension. If pvFindPara is NULL or cUsageIdentifier is set to
      ;  0, finds certificates having the extension. If
      ;  CERT_FIND_OPTIONAL_ENHKEY_USAGE_FLAG is set, also matches a certificate
      ;  without the extension. If CERT_FIND_NO_ENHKEY_USAGE_FLAG is set, finds
      ;  certificates without the extension.
      ;  If the CERT_FIND_PROP_ONLY_ENHKEY_USAGE_FLAG is set, then, only does a match
      ;  using the property. If pvFindPara is NULL or cUsageIdentifier is set to
      ;  0, finds certificates having the property. If
      ;  CERT_FIND_OPTIONAL_ENHKEY_USAGE_FLAG is set, also matches a certificate
      ;  without the property. If CERT_FIND_NO_ENHKEY_USAGE_FLAG is set, finds
      ;  certificates without the property.
      ;  If CERT_FIND_OR_ENHKEY_USAGE_FLAG is set, does an "OR" match of any of
      ;  the specified pszUsageIdentifiers. If not set, then, does an "AND" match
      ;  of all of the specified pszUsageIdentifiers.
      ;--------------------------------------------------------------------------
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
      ;+-------------------------------------------------------------------------
      ;  CERT_FIND_CERT_ID
      ;  Find a certificate with the specified CERT_ID.
      ;  pvFindPara points to a CERT_ID.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  CERT_FIND_CROSS_CERT_DIST_POINTS
      ;  Find a certificate having either a cross certificate distribution
      ;  point extension or property.
      ;  pvFindPara isn't used.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  CERT_FIND_SUBJECT_INFO_ACCESS
      ;  Find a certificate having either a SubjectInfoAccess extension or
      ;  property.
      ;  pvFindPara isn't used.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  CERT_FIND_HASH_STR
      ;  Find a certificate with the specified hash.
      ;  pvFindPara points to a null terminated wide character string, containing
      ;  40 hexadecimal digits that CryptStringToBinary(CRYPT_STRING_HEXRAW) can
      ;  convert to a 20 byte SHA1 CRYPT_HASH_BLOB.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  Get the certificate context from the store for the first or next issuer
      ;  of the specified subject certificate. Perform the enabled
      ;  verification checks on the subject. (Note, the checks are on the subject
      ;  using the returned issuer certificate.)
      ;  If the first or next issuer certificate isn't found, NULL is returned.
      ;  Otherwise, a pointer to a read only CERT_CONTEXT is returned. CERT_CONTEXT
      ;  must be freed by calling CertFreeCertificateContext or is freed when passed as the
      ;  pPrevIssuerContext on a subsequent call. CertDuplicateCertificateContext
      ;  can be called to make a duplicate.
      ;  For a self signed subject certificate, NULL is returned with LastError set
      ;  to CERT_STORE_SELF_SIGNED. The enabled verification checks are still done.
      ;  The pSubjectContext may have been obtained from this store, another store
      ;  or created by the caller application. When created by the caller, the
      ;  CertCreateCertificateContext function must have been called.
      ;  An issuer may have multiple certificates. This may occur when the validity
      ;  period is about to change. pPrevIssuerContext MUST BE NULL on the first
      ;  call to get the issuer. To get the next certificate for the issuer, the
      ;  pPrevIssuerContext is set to the CERT_CONTEXT returned by a previous call.
      ;  NOTE: a NON-NULL pPrevIssuerContext is always CertFreeCertificateContext'ed by
      ;  this function, even for an error.
      ;  The following flags can be set in *pdwFlags to enable verification checks
      ;  on the subject certificate context:
      ;      CERT_STORE_SIGNATURE_FLAG     - use the public key in the returned
      ;                                      issuer certificate to verify the
      ;                                      signature on the subject certificate.
      ;                                      Note, if pSubjectContext->hCertStore ==
      ;                                      hCertStore, the store provider might
      ;                                      be able to eliminate a redo of
      ;                                      the signature verify.
      ;      CERT_STORE_TIME_VALIDITY_FLAG - get the current time and verify that
      ;                                      its within the subject certificate's
      ;                                      validity period
      ;      CERT_STORE_REVOCATION_FLAG    - check if the subject certificate is on
      ;                                      the issuer's revocation list
      ;  If an enabled verification check fails, then, its flag is set upon return.
      ;  If CERT_STORE_REVOCATION_FLAG was enabled and the issuer doesn't have a
      ;  CRL in the store, then, CERT_STORE_NO_CRL_FLAG is set in addition to
      ;  the CERT_STORE_REVOCATION_FLAG.
      ;  If CERT_STORE_SIGNATURE_FLAG or CERT_STORE_REVOCATION_FLAG is set, then,
      ;  CERT_STORE_NO_ISSUER_FLAG is set if it doesn't have an issuer certificate
      ;  in the store.
      ;  For a verification check failure, a pointer to the issuer's CERT_CONTEXT
      ;  is still returned and SetLastError isn't updated.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertGetIssuerCertificateFromStore, WIN_STD_CALL_CONV,, <:HCERTSTORE, :PCCERT_CONTEXT, :PCCERT_CONTEXT, :ptr DWORD>, 16
      ;+-------------------------------------------------------------------------
      ;  Perform the enabled verification checks on the subject certificate
      ;  using the issuer. Same checks and flags definitions as for the above
      ;  CertGetIssuerCertificateFromStore.
      ;  If you are only checking CERT_STORE_TIME_VALIDITY_FLAG, then, the
      ;  issuer can be NULL.
      ;  For a verification check failure, SUCCESS is still returned.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertVerifySubjectCertificateContext, WIN_STD_CALL_CONV,, <:PCCERT_CONTEXT, :PCCERT_CONTEXT, :ptr DWORD>, 12
      ;+-------------------------------------------------------------------------
      ;  Duplicate a certificate context
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertDuplicateCertificateContext, WIN_STD_CALL_CONV,, <:PCCERT_CONTEXT>, 4
      ;+-------------------------------------------------------------------------
      ;  Create a certificate context from the encoded certificate. The created
      ;  context isn't put in a store.
      ;  Makes a copy of the encoded certificate in the created context.
      ;  If unable to decode and create the certificate context, NULL is returned.
      ;  Otherwise, a pointer to a read only CERT_CONTEXT is returned.
      ;  CERT_CONTEXT must be freed by calling CertFreeCertificateContext.
      ;  CertDuplicateCertificateContext can be called to make a duplicate.
      ;  CertSetCertificateContextProperty and CertGetCertificateContextProperty can be called
      ;  to store properties for the certificate.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertCreateCertificateContext, WIN_STD_CALL_CONV,, <:DWORD, :ptr BYTE, :DWORD>, 12
      ;+-------------------------------------------------------------------------
      ;  Free a certificate context
      ;  There needs to be a corresponding free for each context obtained by a
      ;  get, find, duplicate or create.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertFreeCertificateContext, WIN_STD_CALL_CONV,, <:PCCERT_CONTEXT>, 4
      ;+-------------------------------------------------------------------------
      ;  Set the property for the specified certificate context.
      ;  The type definition for pvData depends on the dwPropId value. There are
      ;  five predefined types:
      ;      CERT_KEY_PROV_HANDLE_PROP_ID - a HCRYPTPROV for the certificate's
      ;      private key is passed in pvData. Updates the hCryptProv field
      ;      of the CERT_KEY_CONTEXT_PROP_ID. If the CERT_KEY_CONTEXT_PROP_ID
      ;      doesn't exist, its created with all the other fields zeroed out. If
      ;      CERT_STORE_NO_CRYPT_RELEASE_FLAG isn't set, HCRYPTPROV is implicitly
      ;      released when either the property is set to NULL or on the final
      ;      free of the CertContext.
      ;      CERT_NCRYPT_KEY_HANDLE_PROP_ID - a NCRYPT_KEY_HANDLE for the
      ;      certificate's private key is passed in pvData. The dwKeySpec is
      ;      set to CERT_NCRYPT_KEY_SPEC.
      ;      CERT_HCRYPTPROV_OR_NCRYPT_KEY_HANDLE_PROP_ID - a
      ;      HCRYPTPROV_OR_NCRYPT_KEY_HANDLE for the certificates's private
      ;      key is passed in pvData.  NCryptIsKeyHandle()
      ;      is called to determine if this is a CNG NCRYPT_KEY_HANDLE.
      ;      For a NCRYPT_KEY_HANDLE does a CERT_NCRYPT_KEY_HANDLE_PROP_ID set.
      ;      Otherwise, does a CERT_KEY_PROV_HANDLE_PROP_ID set.
      ;      CERT_KEY_PROV_INFO_PROP_ID - a PCRYPT_KEY_PROV_INFO for the certificate's
      ;      private key is passed in pvData.
      ;      CERT_SHA1_HASH_PROP_ID       -
      ;      CERT_MD5_HASH_PROP_ID        -
      ;      CERT_SIGNATURE_HASH_PROP_ID  - normally, a hash property is implicitly
      ;      set by doing a CertGetCertificateContextProperty. pvData points to a
      ;      CRYPT_HASH_BLOB.
      ;      CERT_KEY_CONTEXT_PROP_ID - a PCERT_KEY_CONTEXT for the certificate's
      ;      private key is passed in pvData. The CERT_KEY_CONTEXT contains both the
      ;      hCryptProv and dwKeySpec for the private key. A dwKeySpec of
      ;      CERT_NCRYPT_KEY_SPEC selects the hNCryptKey choice.
      ;      See the CERT_KEY_PROV_HANDLE_PROP_ID for more information about
      ;      the hCryptProv field and dwFlags settings. Note, more fields may
      ;      be added for this property. The cbSize field value will be adjusted
      ;      accordingly.
      ;      CERT_KEY_SPEC_PROP_ID - the dwKeySpec for the private key. pvData
      ;      points to a DWORD containing the KeySpec
      ;      CERT_ENHKEY_USAGE_PROP_ID - enhanced key usage definition for the
      ;      certificate. pvData points to a CRYPT_DATA_BLOB containing an
      ;      ASN.1 encoded CERT_ENHKEY_USAGE (encoded via
      ;      CryptEncodeObject(X509_ENHANCED_KEY_USAGE).
      ;      CERT_NEXT_UPDATE_LOCATION_PROP_ID - location of the next update.
      ;      Currently only applicable to CTLs. pvData points to a CRYPT_DATA_BLOB
      ;      containing an ASN.1 encoded CERT_ALT_NAME_INFO (encoded via
      ;      CryptEncodeObject(X509_ALTERNATE_NAME)).
      ;      CERT_FRIENDLY_NAME_PROP_ID - friendly name for the cert, CRL or CTL.
      ;      pvData points to a CRYPT_DATA_BLOB. pbData is a pointer to a NULL
      ;      terminated unicode, wide character string.
      ;      cbData = (wcslen((LPWSTR) pbData) + 1) * sizeof(WCHAR).
      ;      CERT_DESCRIPTION_PROP_ID - description for the cert, CRL or CTL.
      ;      pvData points to a CRYPT_DATA_BLOB. pbData is a pointer to a NULL
      ;      terminated unicode, wide character string.
      ;      cbData = (wcslen((LPWSTR) pbData) + 1) * sizeof(WCHAR).
      ;      CERT_ARCHIVED_PROP_ID - when this property is set, the certificate
      ;      is skipped during enumeration. Note, certificates having this property
      ;      are still found for explicit finds, such as, finding a certificate
      ;      with a specific hash or finding a certificate having a specific issuer
      ;      and serial number. pvData points to a CRYPT_DATA_BLOB. This blob
      ;      can be NULL (pbData = NULL, cbData = 0).
      ;      CERT_PUBKEY_ALG_PARA_PROP_ID - for public keys supporting
      ;      algorithm parameter inheritance. pvData points to a CRYPT_OBJID_BLOB
      ;      containing the ASN.1 encoded PublicKey Algorithm Parameters. For
      ;      DSS this would be the parameters encoded via
      ;      CryptEncodeObject(X509_DSS_PARAMETERS). This property may be set
      ;      by CryptVerifyCertificateSignatureEx().
      ;      CERT_CROSS_CERT_DIST_POINTS_PROP_ID - location of the cross certs.
      ;      Currently only applicable to certs. pvData points to a CRYPT_DATA_BLOB
      ;      containing an ASN.1 encoded CROSS_CERT_DIST_POINTS_INFO (encoded via
      ;      CryptEncodeObject(X509_CROSS_CERT_DIST_POINTS)).
      ;      CERT_ENROLLMENT_PROP_ID - enrollment information of the pending request.
      ;      It contains RequestID, CADNSName, CAName, and FriendlyName.
      ;      The data format is defined as: the first 4 bytes - pending request ID,
      ;      next 4 bytes - CADNSName size in characters including null-terminator
      ;      followed by CADNSName string with null-terminator,
      ;      next 4 bytes - CAName size in characters including null-terminator
      ;      followed by CAName string with null-terminator,
      ;      next 4 bytes - FriendlyName size in characters including null-terminator
      ;      followed by FriendlyName string with null-terminator.
      ;      CERT_DATE_STAMP_PROP_ID - contains the time when added to the store
      ;      by an admin tool. pvData points to a CRYPT_DATA_BLOB containing
      ;      the FILETIME.
      ;      CERT_RENEWAL_PROP_ID - contains the hash of renewed certificate
      ;      CERT_OCSP_RESPONSE_PROP_ID - contains the encoded OCSP response.
      ;      CryptDecodeObject/CryptEncodeObject using
      ;      lpszStructType = OCSP_RESPONSE.
      ;      pvData points to a CRYPT_DATA_BLOB containing the encoded OCSP response.
      ;      If this property is present, CertVerifyRevocation() will first attempt
      ;      to use before doing an URL retrieval.
      ;      CERT_SOURCE_LOCATION_PROP_ID - contains source location of the CRL or
      ;      OCSP. pvData points to a CRYPT_DATA_BLOB. pbData is a pointer to a NULL
      ;      terminated unicode, wide character string. Where,
      ;      cbData = (wcslen((LPWSTR) pbData) + 1) * sizeof(WCHAR).
      ;      CERT_SOURCE_URL_PROP_ID - contains URL for the CRL or OCSP. pvData
      ;      is the same as for CERT_SOURCE_LOCATION_PROP_ID.
      ;      CERT_CEP_PROP_ID - contains Version, PropertyFlags, AuthType,
      ;      UrlFlags and CESAuthType, followed by the CEPUrl, CEPId, CESUrl and
      ;      RequestId strings
      ;      The data format is defined as: the first 4 bytes - property version,
      ;      next 4 bytes - Property Flags
      ;      next 4 bytes - Authentication Type
      ;      next 4 bytes - Url Flags
      ;      next 4 bytes - CES Authentication Type
      ;      followed by Url string with null-terminator,
      ;      followed by Id string with null-terminator,
      ;      followed by CES Url string with null-terminator,
      ;      followed by RequestId string with null-terminator.
      ;      a single null-terminator indicates no string is present.
      ;      CERT_KEY_REPAIR_ATTEMPTED_PROP_ID - contains the time when repair of
      ;	a missing CERT_KEY_PROV_INFO_PROP_ID property was attempted and failed.
      ;      pvData points to a CRYPT_DATA_BLOB containing the FILETIME.
      ;  For all the other PROP_IDs: an encoded PCRYPT_DATA_BLOB is passed in pvData.
      ;  If the property already exists, then, the old value is deleted and silently
      ;  replaced. Setting, pvData to NULL, deletes the property.
      ;  CERT_SET_PROPERTY_IGNORE_PERSIST_ERROR_FLAG can be set to ignore any
      ;  provider write errors and always update the cached context's property.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertSetCertificateContextProperty, WIN_STD_CALL_CONV,, <:PCCERT_CONTEXT, :DWORD, :DWORD, :ptr>, 16
      ; Set this flag to ignore any store provider write errors and always update
      ; the cached context's property
      CERT_SET_PROPERTY_IGNORE_PERSIST_ERROR_FLAG equ 80000000h
      ; Set this flag to inhibit the persisting of this property
      CERT_SET_PROPERTY_INHIBIT_PERSIST_FLAG equ 40000000h
      ;+-------------------------------------------------------------------------
      ;  Get the property for the specified certificate context.
      ;  For CERT_KEY_PROV_HANDLE_PROP_ID, pvData points to a HCRYPTPROV.
      ;  The CERT_NCRYPT_KEY_SPEC NCRYPT_KEY_HANDLE choice isn't returned.
      ;  For CERT_NCRYPT_KEY_HANDLE_PROP_ID, pvData points to a NCRYPT_KEY_HANDLE.
      ;  Only returned for the CERT_NCRYPT_KEY_SPEC choice.
      ;  For CERT_HCRYPTPROV_OR_NCRYPT_KEY_HANDLE_PROP_ID, pvData points to a
      ;  HCRYPTPROV_OR_NCRYPT_KEY_HANDLE. Returns either the HCRYPTPROV or
      ;  NCRYPT_KEY_HANDLE choice.
      ;  For CERT_KEY_PROV_INFO_PROP_ID, pvData points to a CRYPT_KEY_PROV_INFO structure.
      ;  Elements pointed to by fields in the pvData structure follow the
      ;  structure. Therefore, *pcbData may exceed the size of the structure.
      ;  For CERT_KEY_CONTEXT_PROP_ID, pvData points to a CERT_KEY_CONTEXT structure.
      ;  For CERT_KEY_SPEC_PROP_ID, pvData points to a DWORD containing the KeySpec.
      ;  If the CERT_KEY_CONTEXT_PROP_ID exists, the KeySpec is obtained from there.
      ;  Otherwise, if the CERT_KEY_PROV_INFO_PROP_ID exists, its the source
      ;  of the KeySpec. CERT_NCRYPT_KEY_SPEC is returned if the
      ;  CERT_NCRYPT_KEY_HANDLE_PROP_ID has been set.
      ;  For CERT_SHA1_HASH_PROP_ID or CERT_MD5_HASH_PROP_ID, if the hash
      ;  doesn't already exist, then, its computed via CryptHashCertificate()
      ;  and then set. pvData points to the computed hash. Normally, the length
      ;  is 20 bytes for SHA and 16 for MD5.
      ;  For CERT_SIGNATURE_HASH_PROP_ID, if the hash
      ;  doesn't already exist, then, its computed via CryptHashToBeSigned()
      ;  and then set. pvData points to the computed hash. Normally, the length
      ;  is 20 bytes for SHA and 16 for MD5.
      ;  For CERT_ACCESS_STATE_PROP_ID, pvData points to a DWORD containing the
      ;  access state flags. The appropriate CERT_ACCESS_STATE_*_FLAG's are set
      ;  in the returned DWORD. See the CERT_ACCESS_STATE_*_FLAG definitions
      ;  above. Note, this property is read only. It can't be set.
      ;  For CERT_KEY_IDENTIFIER_PROP_ID, if property doesn't already exist,
      ;  first searches for the szOID_SUBJECT_KEY_IDENTIFIER extension. Next,
      ;  does SHA1 hash of the certficate's SubjectPublicKeyInfo. pvData
      ;  points to the key identifier bytes. Normally, the length is 20 bytes.
      ;  For CERT_PUBKEY_ALG_PARA_PROP_ID, pvPara points to the ASN.1 encoded
      ;  PublicKey Algorithm Parameters. This property will only be set
      ;  for public keys supporting algorithm parameter inheritance and when the
      ;  parameters have been omitted from the encoded and signed certificate.
      ;  For CERT_DATE_STAMP_PROP_ID, pvPara points to a FILETIME updated by
      ;  an admin tool to indicate when the certificate was added to the store.
      ;  For CERT_OCSP_RESPONSE_PROP_ID, pvPara points to an encoded OCSP response.
      ;  For CERT_SOURCE_LOCATION_PROP_ID and CERT_SOURCE_URL_PROP_ID,
      ;  pvPara points to a NULL terminated unicode, wide character string.
      ;  For all other PROP_IDs, pvData points to an encoded array of bytes.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertGetCertificateContextProperty, WIN_STD_CALL_CONV,, <:PCCERT_CONTEXT, :DWORD, :ptr, :ptr DWORD>, 16
      ;+-------------------------------------------------------------------------
      ;  Enumerate the properties for the specified certificate context.
      ;  To get the first property, set dwPropId to 0. The ID of the first
      ;  property is returned. To get the next property, set dwPropId to the
      ;  ID returned by the last call. To enumerate all the properties continue
      ;  until 0 is returned.
      ;  CertGetCertificateContextProperty is called to get the property's data.
      ;  Note, since, the CERT_KEY_PROV_HANDLE_PROP_ID and CERT_KEY_SPEC_PROP_ID
      ;  properties are stored as fields in the CERT_KEY_CONTEXT_PROP_ID
      ;  property, they aren't enumerated individually.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertEnumCertificateContextProperties, WIN_STD_CALL_CONV,, <:PCCERT_CONTEXT, :DWORD>, 8
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)*
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_PHONE_RESTRICTED or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      ;+-------------------------------------------------------------------------
      ;  Creates a CTL entry whose attributes are the certificate context's
      ;  properties.
      ;  The SubjectIdentifier in the CTL entry is the SHA1 hash of the certificate.
      ;  The certificate properties are added as attributes. The property attribute
      ;  OID is the decimal PROP_ID preceded by szOID_CERT_PROP_ID_PREFIX. Each
      ;  property value is copied as a single attribute value.
      ;  Any additional attributes to be included in the CTL entry can be passed
      ;  in via the cOptAttr and rgOptAttr parameters.
      ;  CTL_ENTRY_FROM_PROP_CHAIN_FLAG can be set in dwFlags, to force the
      ;  inclusion of the chain building hash properties as attributes.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertCreateCTLEntryFromCertificateContextProperties, WIN_STD_CALL_CONV,, <:PCCERT_CONTEXT, :DWORD, :PCRYPT_ATTRIBUTE, :DWORD, :ptr, :PCTL_ENTRY, :ptr DWORD>, 28
      ; Set this flag to get and include the chain building hash properties
      ; as attributes in the CTL entry
      CTL_ENTRY_FROM_PROP_CHAIN_FLAG equ 1h
      ;+-------------------------------------------------------------------------
      ;  Sets properties on the certificate context using the attributes in
      ;  the CTL entry.
      ;  The property attribute OID is the decimal PROP_ID preceded by
      ;  szOID_CERT_PROP_ID_PREFIX. Only attributes containing such an OID are
      ;  copied.
      ;  CERT_SET_PROPERTY_IGNORE_PERSIST_ERROR_FLAG may be set in dwFlags.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertSetCertificateContextPropertiesFromCTLEntry, WIN_STD_CALL_CONV,, <:PCCERT_CONTEXT, :PCTL_ENTRY, :DWORD>, 12
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP|WINAPI_PARTITION_PHONE_RESTRICTED | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      ;+-------------------------------------------------------------------------
      ;  Get the first or next CRL context from the store for the specified
      ;  issuer certificate. Perform the enabled verification checks on the CRL.
      ;  If the first or next CRL isn't found, NULL is returned.
      ;  Otherwise, a pointer to a read only CRL_CONTEXT is returned. CRL_CONTEXT
      ;  must be freed by calling CertFreeCRLContext. However, the free must be
      ;  pPrevCrlContext on a subsequent call. CertDuplicateCRLContext
      ;  can be called to make a duplicate.
      ;  The pIssuerContext may have been obtained from this store, another store
      ;  or created by the caller application. When created by the caller, the
      ;  CertCreateCertificateContext function must have been called.
      ;  If pIssuerContext == NULL, finds all the CRLs in the store.
      ;  An issuer may have multiple CRLs. For example, it generates delta CRLs
      ;  using a X.509 v3 extension. pPrevCrlContext MUST BE NULL on the first
      ;  call to get the CRL. To get the next CRL for the issuer, the
      ;  pPrevCrlContext is set to the CRL_CONTEXT returned by a previous call.
      ;  NOTE: a NON-NULL pPrevCrlContext is always CertFreeCRLContext'ed by
      ;  this function, even for an error.
      ;  The following flags can be set in *pdwFlags to enable verification checks
      ;  on the returned CRL:
      ;      CERT_STORE_SIGNATURE_FLAG     - use the public key in the
      ;                                      issuer's certificate to verify the
      ;                                      signature on the returned CRL.
      ;                                      Note, if pIssuerContext->hCertStore ==
      ;                                      hCertStore, the store provider might
      ;                                      be able to eliminate a redo of
      ;                                      the signature verify.
      ;      CERT_STORE_TIME_VALIDITY_FLAG - get the current time and verify that
      ;                                      its within the CRL's ThisUpdate and
      ;                                      NextUpdate validity period.
      ;      CERT_STORE_BASE_CRL_FLAG      - get base CRL.
      ;      CERT_STORE_DELTA_CRL_FLAG     - get delta CRL.
      ;  If only one of CERT_STORE_BASE_CRL_FLAG or CERT_STORE_DELTA_CRL_FLAG is
      ;  set, then, only returns either a base or delta CRL. In any case, the
      ;  appropriate base or delta flag will be cleared upon returned. If both
      ;  flags are set, then, only one of flags will be cleared.
      ;  If an enabled verification check fails, then, its flag is set upon return.
      ;  If pIssuerContext == NULL, then, an enabled CERT_STORE_SIGNATURE_FLAG
      ;  always fails and the CERT_STORE_NO_ISSUER_FLAG is also set.
      ;  For a verification check failure, a pointer to the first or next
      ;  CRL_CONTEXT is still returned and SetLastError isn't updated.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertGetCRLFromStore, WIN_STD_CALL_CONV,, <:HCERTSTORE, :PCCERT_CONTEXT, :PCCRL_CONTEXT, :ptr DWORD>, 16
      ;+-------------------------------------------------------------------------
      ;  Enumerate the CRL contexts in the store.
      ;  If a CRL isn't found, NULL is returned.
      ;  Otherwise, a pointer to a read only CRL_CONTEXT is returned. CRL_CONTEXT
      ;  must be freed by calling CertFreeCRLContext or is freed when passed as the
      ;  pPrevCrlContext on a subsequent call. CertDuplicateCRLContext
      ;  can be called to make a duplicate.
      ;  pPrevCrlContext MUST BE NULL to enumerate the first
      ;  CRL in the store. Successive CRLs are enumerated by setting
      ;  pPrevCrlContext to the CRL_CONTEXT returned by a previous call.
      ;  NOTE: a NON-NULL pPrevCrlContext is always CertFreeCRLContext'ed by
      ;  this function, even for an error.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertEnumCRLsInStore, WIN_STD_CALL_CONV,, <:HCERTSTORE, :PCCRL_CONTEXT>, 8
      ;+-------------------------------------------------------------------------
      ;  Find the first or next CRL context in the store.
      ;  The CRL is found according to the dwFindType and its pvFindPara.
      ;  See below for a list of the find types and its parameters.
      ;  Currently dwFindFlags isn't used and must be set to 0.
      ;  Usage of dwCertEncodingType depends on the dwFindType.
      ;  If the first or next CRL isn't found, NULL is returned.
      ;  Otherwise, a pointer to a read only CRL_CONTEXT is returned. CRL_CONTEXT
      ;  must be freed by calling CertFreeCRLContext or is freed when passed as the
      ;  pPrevCrlContext on a subsequent call. CertDuplicateCRLContext
      ;  can be called to make a duplicate.
      ;  pPrevCrlContext MUST BE NULL on the first
      ;  call to find the CRL. To find the next CRL, the
      ;  pPrevCrlContext is set to the CRL_CONTEXT returned by a previous call.
      ;  NOTE: a NON-NULL pPrevCrlContext is always CertFreeCRLContext'ed by
      ;  this function, even for an error.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertFindCRLInStore, WIN_STD_CALL_CONV,, <:HCERTSTORE, :DWORD, :DWORD, :DWORD, :ptr, :PCCRL_CONTEXT>, 24
      CRL_FIND_ANY equ 0
      CRL_FIND_ISSUED_BY equ 1
      CRL_FIND_EXISTING equ 2
      CRL_FIND_ISSUED_FOR equ 3
      ;+-------------------------------------------------------------------------
      ;  CRL_FIND_ANY
      ;  Find any CRL.
      ;  pvFindPara isn't used.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  CRL_FIND_ISSUED_BY
      ;  Find CRL matching the specified issuer.
      ;  pvFindPara is the PCCERT_CONTEXT of the CRL issuer. May be NULL to
      ;  match any issuer.
      ;  By default, only does issuer name matching. The following flags can be
      ;  set in dwFindFlags to do additional filtering.
      ;  If CRL_FIND_ISSUED_BY_AKI_FLAG is set in dwFindFlags, then, checks if the
      ;  CRL has an Authority Key Identifier (AKI) extension. If the CRL has an
      ;  AKI, then, only returns a CRL whose AKI matches the issuer.
      ;  Note, the AKI extension has the following OID:
      ;  szOID_AUTHORITY_KEY_IDENTIFIER2 and its corresponding data structure.
      ;  If CRL_FIND_ISSUED_BY_SIGNATURE_FLAG is set in dwFindFlags, then,
      ;  uses the public key in the issuer's certificate to verify the
      ;  signature on the CRL. Only returns a CRL having a valid signature.
      ;  If CRL_FIND_ISSUED_BY_DELTA_FLAG is set in dwFindFlags, then, only
      ;  returns a delta CRL.
      ;  If CRL_FIND_ISSUED_BY_BASE_FLAG is set in dwFindFlags, then, only
      ;  returns a base CRL.
      ;--------------------------------------------------------------------------
      CRL_FIND_ISSUED_BY_AKI_FLAG equ 1h
      CRL_FIND_ISSUED_BY_SIGNATURE_FLAG equ 2h
      CRL_FIND_ISSUED_BY_DELTA_FLAG equ 4h
      CRL_FIND_ISSUED_BY_BASE_FLAG equ 8h
      ;+-------------------------------------------------------------------------
      ;  CRL_FIND_EXISTING
      ;  Find existing CRL in the store.
      ;  pvFindPara is the PCCRL_CONTEXT of the CRL to check if it already
      ;  exists in the store.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  CRL_FIND_ISSUED_FOR
      ;  Find CRL for the specified subject and its issuer.
      ;  pvFindPara points to the following CRL_FIND_ISSUED_FOR_PARA which contains
      ;  both the subject and issuer certificates. Not optional.
      ;  The subject's issuer name is used to match the CRL's issuer name. Otherwise,
      ;  the issuer's certificate is used the same as in the above
      ;  CRL_FIND_ISSUED_BY.
      ;  Note, when cross certificates are used, the subject name in the issuer's
      ;  certificate may not match the issuer name in the subject certificate and
      ;  its corresponding CRL.
      ;  All of the above CRL_FIND_ISSUED_BY_*_FLAGS apply to this find type.
      ;--------------------------------------------------------------------------
      CRL_FIND_ISSUED_FOR_PARA struct
        pSubjectCert PCCERT_CONTEXT ?
        pIssuerCert PCCERT_CONTEXT ?
      CRL_FIND_ISSUED_FOR_PARA ends
      _CRL_FIND_ISSUED_FOR_PARA typedef CRL_FIND_ISSUED_FOR_PARA
      PCRL_FIND_ISSUED_FOR_PARA typedef ptr CRL_FIND_ISSUED_FOR_PARA
      ; When the following flag is set, the strong signature properties
      ; are also set on the returned CRL.
      ;  The strong signature properties are:
      ;    - CERT_SIGN_HASH_CNG_ALG_PROP_ID
      ;    - CERT_ISSUER_PUB_KEY_BIT_LENGTH_PROP_ID
      CRL_FIND_ISSUED_FOR_SET_STRONG_PROPERTIES_FLAG equ 10h
      ;+-------------------------------------------------------------------------
      ;  Duplicate a CRL context
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertDuplicateCRLContext, WIN_STD_CALL_CONV,, <:PCCRL_CONTEXT>, 4
      ;+-------------------------------------------------------------------------
      ;  Create a CRL context from the encoded CRL. The created
      ;  context isn't put in a store.
      ;  Makes a copy of the encoded CRL in the created context.
      ;  If unable to decode and create the CRL context, NULL is returned.
      ;  Otherwise, a pointer to a read only CRL_CONTEXT is returned.
      ;  CRL_CONTEXT must be freed by calling CertFreeCRLContext.
      ;  CertDuplicateCRLContext can be called to make a duplicate.
      ;  CertSetCRLContextProperty and CertGetCRLContextProperty can be called
      ;  to store properties for the CRL.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertCreateCRLContext, WIN_STD_CALL_CONV,, <:DWORD, :ptr BYTE, :DWORD>, 12
      ;+-------------------------------------------------------------------------
      ;  Free a CRL context
      ;  There needs to be a corresponding free for each context obtained by a
      ;  get, duplicate or create.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertFreeCRLContext, WIN_STD_CALL_CONV,, <:PCCRL_CONTEXT>, 4
      ;+-------------------------------------------------------------------------
      ;  Set the property for the specified CRL context.
      ;  Same Property Ids and semantics as CertSetCertificateContextProperty.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertSetCRLContextProperty, WIN_STD_CALL_CONV,, <:PCCRL_CONTEXT, :DWORD, :DWORD, :ptr>, 16
      ;+-------------------------------------------------------------------------
      ;  Get the property for the specified CRL context.
      ;  Same Property Ids and semantics as CertGetCertificateContextProperty.
      ;  CERT_SHA1_HASH_PROP_ID, CERT_MD5_HASH_PROP_ID or
      ;  CERT_SIGNATURE_HASH_PROP_ID is the predefined property of most interest.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertGetCRLContextProperty, WIN_STD_CALL_CONV,, <:PCCRL_CONTEXT, :DWORD, :ptr, :ptr DWORD>, 16
      ;+-------------------------------------------------------------------------
      ;  Enumerate the properties for the specified CRL context.
      ;  To get the first property, set dwPropId to 0. The ID of the first
      ;  property is returned. To get the next property, set dwPropId to the
      ;  ID returned by the last call. To enumerate all the properties continue
      ;  until 0 is returned.
      ;  CertGetCRLContextProperty is called to get the property's data.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertEnumCRLContextProperties, WIN_STD_CALL_CONV,, <:PCCRL_CONTEXT, :DWORD>, 8
      ;+-------------------------------------------------------------------------
      ;  Search the CRL's list of entries for the specified certificate.
      ;  TRUE is returned if we were able to search the list. Otherwise, FALSE is
      ;  returned,
      ;  For success, if the certificate was found in the list, *ppCrlEntry is
      ;  updated with a pointer to the entry. Otherwise, *ppCrlEntry is set to NULL.
      ;  The returned entry isn't allocated and must not be freed.
      ;  dwFlags and pvReserved currently aren't used and must be set to 0 or NULL.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertFindCertificateInCRL, WIN_STD_CALL_CONV,, <:PCCERT_CONTEXT, :PCCRL_CONTEXT, :DWORD, :ptr, :ptr PCRL_ENTRY>, 20
      ;+-------------------------------------------------------------------------
      ;  Is the specified CRL valid for the certificate.
      ;  Returns TRUE if the CRL's list of entries would contain the certificate
      ;  if it was revoked. Note, doesn't check that the certificate is in the
      ;  list of entries.
      ;  If the CRL has an Issuing Distribution Point (IDP) extension, checks
      ;  that it's valid for the subject certificate.
      ;  dwFlags and pvReserved currently aren't used and must be set to 0 and NULL.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertIsValidCRLForCertificate, WIN_STD_CALL_CONV,, <:PCCERT_CONTEXT, :PCCRL_CONTEXT, :DWORD, :ptr>, 16
      ;+-------------------------------------------------------------------------
      ; Add certificate/CRL, encoded, context or element disposition values.
      ;--------------------------------------------------------------------------
      CERT_STORE_ADD_NEW equ 1
      CERT_STORE_ADD_USE_EXISTING equ 2
      CERT_STORE_ADD_REPLACE_EXISTING equ 3
      CERT_STORE_ADD_ALWAYS equ 4
      CERT_STORE_ADD_REPLACE_EXISTING_INHERIT_PROPERTIES equ 5
      CERT_STORE_ADD_NEWER equ 6
      CERT_STORE_ADD_NEWER_INHERIT_PROPERTIES equ 7
      ;+-------------------------------------------------------------------------
      ;  Add the encoded certificate to the store according to the specified
      ;  disposition action.
      ;  Makes a copy of the encoded certificate before adding to the store.
      ;  dwAddDispostion specifies the action to take if the certificate
      ;  already exists in the store. This parameter must be one of the following
      ;  values:
      ;    CERT_STORE_ADD_NEW
      ;      Fails if the certificate already exists in the store. LastError
      ;      is set to CRYPT_E_EXISTS.
      ;    CERT_STORE_ADD_USE_EXISTING
      ;      If the certifcate already exists, then, its used and if ppCertContext
      ;      is non-NULL, the existing context is duplicated.
      ;    CERT_STORE_ADD_REPLACE_EXISTING
      ;      If the certificate already exists, then, the existing certificate
      ;      context is deleted before creating and adding the new context.
      ;    CERT_STORE_ADD_ALWAYS
      ;      No check is made to see if the certificate already exists. A
      ;      new certificate context is always created. This may lead to
      ;      duplicates in the store.
      ;    CERT_STORE_ADD_REPLACE_EXISTING_INHERIT_PROPERTIES
      ;      If the certificate already exists, then, its used.
      ;    CERT_STORE_ADD_NEWER
      ;      Fails if the certificate already exists in the store AND the NotBefore
      ;      time of the existing certificate is equal to or greater than the
      ;      NotBefore time of the new certificate being added. LastError
      ;      is set to CRYPT_E_EXISTS.
      ;      If an older certificate is replaced, same as
      ;      CERT_STORE_ADD_REPLACE_EXISTING.
      ;      For CRLs or CTLs compares the ThisUpdate times.
      ;    CERT_STORE_ADD_NEWER_INHERIT_PROPERTIES
      ;      Same as CERT_STORE_ADD_NEWER. However, if an older certificate is
      ;      replaced, same as CERT_STORE_ADD_REPLACE_EXISTING_INHERIT_PROPERTIES.
      ;  CertGetSubjectCertificateFromStore is called to determine if the
      ;  certificate already exists in the store.
      ;  ppCertContext can be NULL, indicating the caller isn't interested
      ;  in getting the CERT_CONTEXT of the added or existing certificate.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertAddEncodedCertificateToStore, WIN_STD_CALL_CONV,, <:HCERTSTORE, :DWORD, :ptr BYTE, :DWORD, :DWORD, :ptr PCCERT_CONTEXT>, 24
      ;+-------------------------------------------------------------------------
      ;  Add the certificate context to the store according to the specified
      ;  disposition action.
      ;  In addition to the encoded certificate, the context's properties are
      ;  also copied.  Note, the CERT_KEY_CONTEXT_PROP_ID property (and its
      ;  CERT_KEY_PROV_HANDLE_PROP_ID or CERT_KEY_SPEC_PROP_ID) isn't copied.
      ;  Makes a copy of the certificate context before adding to the store.
      ;  dwAddDispostion specifies the action to take if the certificate
      ;  already exists in the store. This parameter must be one of the following
      ;  values:
      ;    CERT_STORE_ADD_NEW
      ;      Fails if the certificate already exists in the store. LastError
      ;      is set to CRYPT_E_EXISTS.
      ;    CERT_STORE_ADD_USE_EXISTING
      ;      If the certifcate already exists, then, its used and if ppStoreContext
      ;      is non-NULL, the existing context is duplicated. Iterates
      ;      through pCertContext's properties and only copies the properties
      ;      that don't already exist. The SHA1 and MD5 hash properties aren't
      ;      copied.
      ;    CERT_STORE_ADD_REPLACE_EXISTING
      ;      If the certificate already exists, then, the existing certificate
      ;      context is deleted before creating and adding a new context.
      ;      Properties are copied before doing the add.
      ;    CERT_STORE_ADD_ALWAYS
      ;      No check is made to see if the certificate already exists. A
      ;      new certificate context is always created and added. This may lead to
      ;      duplicates in the store. Properties are
      ;      copied before doing the add.
      ;    CERT_STORE_ADD_REPLACE_EXISTING_INHERIT_PROPERTIES
      ;      If the certificate already exists, then, the existing certificate
      ;      context is used. Properties from the added context are copied and
      ;      replace existing properties. However, any existing properties not
      ;      in the added context remain and aren't deleted.
      ;    CERT_STORE_ADD_NEWER
      ;      Fails if the certificate already exists in the store AND the NotBefore
      ;      time of the existing context is equal to or greater than the
      ;      NotBefore time of the new context being added. LastError
      ;      is set to CRYPT_E_EXISTS.
      ;      If an older context is replaced, same as
      ;      CERT_STORE_ADD_REPLACE_EXISTING.
      ;      For CRLs or CTLs compares the ThisUpdate times.
      ;    CERT_STORE_ADD_NEWER_INHERIT_PROPERTIES
      ;      Same as CERT_STORE_ADD_NEWER. However, if an older context is
      ;      replaced, same as CERT_STORE_ADD_REPLACE_EXISTING_INHERIT_PROPERTIES.
      ;  CertGetSubjectCertificateFromStore is called to determine if the
      ;  certificate already exists in the store.
      ;  ppStoreContext can be NULL, indicating the caller isn't interested
      ;  in getting the CERT_CONTEXT of the added or existing certificate.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertAddCertificateContextToStore, WIN_STD_CALL_CONV,, <:HCERTSTORE, :PCCERT_CONTEXT, :DWORD, :ptr PCCERT_CONTEXT>, 16
      ;+-------------------------------------------------------------------------
      ;  Certificate Store Context Types
      ;--------------------------------------------------------------------------
      CERT_STORE_CERTIFICATE_CONTEXT equ 1
      CERT_STORE_CRL_CONTEXT equ 2
      CERT_STORE_CTL_CONTEXT equ 3
      ;+-------------------------------------------------------------------------
      ;  Certificate Store Context Bit Flags
      ;--------------------------------------------------------------------------
      CERT_STORE_ALL_CONTEXT_FLAG equ (not 0)
      CERT_STORE_CERTIFICATE_CONTEXT_FLAG equ (1 shl CERT_STORE_CERTIFICATE_CONTEXT)
      CERT_STORE_CRL_CONTEXT_FLAG equ (1 shl CERT_STORE_CRL_CONTEXT)
      CERT_STORE_CTL_CONTEXT_FLAG equ (1 shl CERT_STORE_CTL_CONTEXT)
      ;+-------------------------------------------------------------------------
      ;  Add the serialized certificate or CRL element to the store.
      ;  The serialized element contains the encoded certificate, CRL or CTL and
      ;  its properties, such as, CERT_KEY_PROV_INFO_PROP_ID.
      ;  If hCertStore is NULL, creates a certificate, CRL or CTL context not
      ;  residing in any store.
      ;  dwAddDispostion specifies the action to take if the certificate or CRL
      ;  already exists in the store. See CertAddCertificateContextToStore for a
      ;  list of and actions taken.
      ;  dwFlags currently isn't used and should be set to 0.
      ;  dwContextTypeFlags specifies the set of allowable contexts. For example, to
      ;  add either a certificate or CRL, set dwContextTypeFlags to:
      ;      CERT_STORE_CERTIFICATE_CONTEXT_FLAG | CERT_STORE_CRL_CONTEXT_FLAG
      ;  *pdwContextType is updated with the type of the context returned in
      ;  *ppvContxt. pdwContextType or ppvContext can be NULL, indicating the
      ;  caller isn't interested in getting the output. If *ppvContext is
      ;  returned it must be freed by calling CertFreeCertificateContext or
      ;  CertFreeCRLContext.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertAddSerializedElementToStore, WIN_STD_CALL_CONV,, <:HCERTSTORE, :ptr BYTE, :DWORD, :DWORD, :DWORD, :DWORD, :ptr DWORD, :ptr ptr>, 32
      ;+-------------------------------------------------------------------------
      ;  Delete the specified certificate from the store.
      ;  All subsequent gets or finds for the certificate will fail. However,
      ;  memory allocated for the certificate isn't freed until all of its contexts
      ;  have also been freed.
      ;  The pCertContext is obtained from a get, enum, find or duplicate.
      ;  Some store provider implementations might also delete the issuer's CRLs
      ;  if this is the last certificate for the issuer in the store.
      ;  NOTE: the pCertContext is always CertFreeCertificateContext'ed by
      ;  this function, even for an error.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertDeleteCertificateFromStore, WIN_STD_CALL_CONV,, <:PCCERT_CONTEXT>, 4
      ;+-------------------------------------------------------------------------
      ;  Add the encoded CRL to the store according to the specified
      ;  disposition option.
      ;  Makes a copy of the encoded CRL before adding to the store.
      ;  dwAddDispostion specifies the action to take if the CRL
      ;  already exists in the store. See CertAddEncodedCertificateToStore for a
      ;  list of and actions taken.
      ;  Compares the CRL's Issuer to determine if the CRL already exists in the
      ;  store.
      ;  ppCrlContext can be NULL, indicating the caller isn't interested
      ;  in getting the CRL_CONTEXT of the added or existing CRL.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertAddEncodedCRLToStore, WIN_STD_CALL_CONV,, <:HCERTSTORE, :DWORD, :ptr BYTE, :DWORD, :DWORD, :ptr PCCRL_CONTEXT>, 24
      ;+-------------------------------------------------------------------------
      ;  Add the CRL context to the store according to the specified
      ;  disposition option.
      ;  In addition to the encoded CRL, the context's properties are
      ;  also copied.  Note, the CERT_KEY_CONTEXT_PROP_ID property (and its
      ;  CERT_KEY_PROV_HANDLE_PROP_ID or CERT_KEY_SPEC_PROP_ID) isn't copied.
      ;  Makes a copy of the encoded CRL before adding to the store.
      ;  dwAddDispostion specifies the action to take if the CRL
      ;  already exists in the store. See CertAddCertificateContextToStore for a
      ;  list of and actions taken.
      ;  Compares the CRL's Issuer, ThisUpdate and NextUpdate to determine
      ;  if the CRL already exists in the store.
      ;  ppStoreContext can be NULL, indicating the caller isn't interested
      ;  in getting the CRL_CONTEXT of the added or existing CRL.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertAddCRLContextToStore, WIN_STD_CALL_CONV,, <:HCERTSTORE, :PCCRL_CONTEXT, :DWORD, :ptr PCCRL_CONTEXT>, 16
      ;+-------------------------------------------------------------------------
      ;  Delete the specified CRL from the store.
      ;  All subsequent gets for the CRL will fail. However,
      ;  memory allocated for the CRL isn't freed until all of its contexts
      ;  have also been freed.
      ;  The pCrlContext is obtained from a get or duplicate.
      ;  NOTE: the pCrlContext is always CertFreeCRLContext'ed by
      ;  this function, even for an error.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertDeleteCRLFromStore, WIN_STD_CALL_CONV,, <:PCCRL_CONTEXT>, 4
      ;+-------------------------------------------------------------------------
      ;  Serialize the certificate context's encoded certificate and its
      ;  properties.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertSerializeCertificateStoreElement, WIN_STD_CALL_CONV,, <:PCCERT_CONTEXT, :DWORD, :ptr BYTE, :ptr DWORD>, 16
      ;+-------------------------------------------------------------------------
      ;  Serialize the CRL context's encoded CRL and its properties.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertSerializeCRLStoreElement, WIN_STD_CALL_CONV,, <:PCCRL_CONTEXT, :DWORD, :ptr BYTE, :ptr DWORD>, 16
      ;+=========================================================================
      ;  Certificate Trust List (CTL) Store Data Structures and APIs
      ;==========================================================================
      ;+-------------------------------------------------------------------------
      ;  Duplicate a CTL context
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertDuplicateCTLContext, WIN_STD_CALL_CONV,, <:PCCTL_CONTEXT>, 4
      ;+-------------------------------------------------------------------------
      ;  Create a CTL context from the encoded CTL. The created
      ;  context isn't put in a store.
      ;  Makes a copy of the encoded CTL in the created context.
      ;  If unable to decode and create the CTL context, NULL is returned.
      ;  Otherwise, a pointer to a read only CTL_CONTEXT is returned.
      ;  CTL_CONTEXT must be freed by calling CertFreeCTLContext.
      ;  CertDuplicateCTLContext can be called to make a duplicate.
      ;  CertSetCTLContextProperty and CertGetCTLContextProperty can be called
      ;  to store properties for the CTL.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertCreateCTLContext, WIN_STD_CALL_CONV,, <:DWORD, :ptr BYTE, :DWORD>, 12
      ;+-------------------------------------------------------------------------
      ;  Free a CTL context
      ;  There needs to be a corresponding free for each context obtained by a
      ;  get, duplicate or create.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertFreeCTLContext, WIN_STD_CALL_CONV,, <:PCCTL_CONTEXT>, 4
      ;+-------------------------------------------------------------------------
      ;  Set the property for the specified CTL context.
      ;  Same Property Ids and semantics as CertSetCertificateContextProperty.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertSetCTLContextProperty, WIN_STD_CALL_CONV,, <:PCCTL_CONTEXT, :DWORD, :DWORD, :ptr>, 16
      ;+-------------------------------------------------------------------------
      ;  Get the property for the specified CTL context.
      ;  Same Property Ids and semantics as CertGetCertificateContextProperty.
      ;  CERT_SHA1_HASH_PROP_ID or CERT_NEXT_UPDATE_LOCATION_PROP_ID are the
      ;  predefined properties of most interest.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertGetCTLContextProperty, WIN_STD_CALL_CONV,, <:PCCTL_CONTEXT, :DWORD, :ptr, :ptr DWORD>, 16
      ;+-------------------------------------------------------------------------
      ;  Enumerate the properties for the specified CTL context.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertEnumCTLContextProperties, WIN_STD_CALL_CONV,, <:PCCTL_CONTEXT, :DWORD>, 8
      ;+-------------------------------------------------------------------------
      ;  Enumerate the CTL contexts in the store.
      ;  If a CTL isn't found, NULL is returned.
      ;  Otherwise, a pointer to a read only CTL_CONTEXT is returned. CTL_CONTEXT
      ;  must be freed by calling CertFreeCTLContext or is freed when passed as the
      ;  pPrevCtlContext on a subsequent call. CertDuplicateCTLContext
      ;  can be called to make a duplicate.
      ;  pPrevCtlContext MUST BE NULL to enumerate the first
      ;  CTL in the store. Successive CTLs are enumerated by setting
      ;  pPrevCtlContext to the CTL_CONTEXT returned by a previous call.
      ;  NOTE: a NON-NULL pPrevCtlContext is always CertFreeCTLContext'ed by
      ;  this function, even for an error.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertEnumCTLsInStore, WIN_STD_CALL_CONV,, <:HCERTSTORE, :PCCTL_CONTEXT>, 8
      ;+-------------------------------------------------------------------------
      ;  Attempt to find the specified subject in the CTL.
      ;  For CTL_CERT_SUBJECT_TYPE, pvSubject points to a CERT_CONTEXT. The CTL's
      ;  SubjectAlgorithm is examined to determine the representation of the
      ;  subject's identity. Initially, only SHA1 or MD5 hash will be supported.
      ;  The appropriate hash property is obtained from the CERT_CONTEXT.
      ;  For CTL_ANY_SUBJECT_TYPE, pvSubject points to the CTL_ANY_SUBJECT_INFO
      ;  structure which contains the SubjectAlgorithm to be matched in the CTL
      ;  and the SubjectIdentifer to be matched in one of the CTL entries.
      ;  The certificate's hash or the CTL_ANY_SUBJECT_INFO's SubjectIdentifier
      ;  is used as the key in searching the subject entries. A binary
      ;  memory comparison is done between the key and the entry's SubjectIdentifer.
      ;  dwEncodingType isn't used for either of the above SubjectTypes.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertFindSubjectInCTL, WIN_STD_CALL_CONV,, <:DWORD, :DWORD, :ptr, :PCCTL_CONTEXT, :DWORD>, 20
      ; Subject Types:
      ;  CTL_ANY_SUBJECT_TYPE, pvSubject points to following CTL_ANY_SUBJECT_INFO.
      ;  CTL_CERT_SUBJECT_TYPE, pvSubject points to CERT_CONTEXT.
      CTL_ANY_SUBJECT_TYPE equ 1
      CTL_CERT_SUBJECT_TYPE equ 2
      CTL_ANY_SUBJECT_INFO struct
        SubjectAlgorithm CRYPT_ALGORITHM_IDENTIFIER <>
        SubjectIdentifier CRYPT_DATA_BLOB <>
      CTL_ANY_SUBJECT_INFO ends
      _CTL_ANY_SUBJECT_INFO typedef CTL_ANY_SUBJECT_INFO
      PCTL_ANY_SUBJECT_INFO typedef ptr CTL_ANY_SUBJECT_INFO
      ;+-------------------------------------------------------------------------
      ;  Find the first or next CTL context in the store.
      ;  The CTL is found according to the dwFindType and its pvFindPara.
      ;  See below for a list of the find types and its parameters.
      ;  Currently dwFindFlags isn't used and must be set to 0.
      ;  Usage of dwMsgAndCertEncodingType depends on the dwFindType.
      ;  If the first or next CTL isn't found, NULL is returned.
      ;  Otherwise, a pointer to a read only CTL_CONTEXT is returned. CTL_CONTEXT
      ;  must be freed by calling CertFreeCTLContext or is freed when passed as the
      ;  pPrevCtlContext on a subsequent call. CertDuplicateCTLContext
      ;  can be called to make a duplicate.
      ;  pPrevCtlContext MUST BE NULL on the first
      ;  call to find the CTL. To find the next CTL, the
      ;  pPrevCtlContext is set to the CTL_CONTEXT returned by a previous call.
      ;  NOTE: a NON-NULL pPrevCtlContext is always CertFreeCTLContext'ed by
      ;  this function, even for an error.
      ;--------------------------------------------------------------------------
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
        ; optional
        ListIdentifier CRYPT_DATA_BLOB <>
        ; optional
        pSigner PCERT_INFO ?
        ; optional
      CTL_FIND_USAGE_PARA ends
      _CTL_FIND_USAGE_PARA typedef CTL_FIND_USAGE_PARA
      PCTL_FIND_USAGE_PARA typedef ptr CTL_FIND_USAGE_PARA
      CTL_FIND_NO_LIST_ID_CBDATA equ 0FFFFFFFFh
      CTL_FIND_NO_SIGNER_PTR equ ((PCERT_INFO) - 1)
      CTL_FIND_SAME_USAGE_FLAG equ 1h
      CTL_FIND_SUBJECT_PARA struct
        cbSize DWORD ?
        pUsagePara PCTL_FIND_USAGE_PARA ?
        ; optional
        dwSubjectType DWORD ?
        pvSubject POINTER ?
      CTL_FIND_SUBJECT_PARA ends
      _CTL_FIND_SUBJECT_PARA typedef CTL_FIND_SUBJECT_PARA
      PCTL_FIND_SUBJECT_PARA typedef ptr CTL_FIND_SUBJECT_PARA
      ;+-------------------------------------------------------------------------
      ;  CTL_FIND_ANY
      ;  Find any CTL.
      ;  pvFindPara isn't used.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  CTL_FIND_SHA1_HASH
      ;  CTL_FIND_MD5_HASH
      ;  Find a CTL with the specified hash.
      ;  pvFindPara points to a CRYPT_HASH_BLOB.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  CTL_FIND_USAGE
      ;  Find a CTL having the specified usage identifiers, list identifier or
      ;  signer. The CertEncodingType of the signer is obtained from the
      ;  dwMsgAndCertEncodingType parameter.
      ;  pvFindPara points to a CTL_FIND_USAGE_PARA data structure. The
      ;  SubjectUsage.cUsageIdentifer can be 0 to match any usage. The
      ;  ListIdentifier.cbData can be 0 to match any list identifier. To only match
      ;  CTLs without a ListIdentifier, cbData must be set to
      ;  CTL_FIND_NO_LIST_ID_CBDATA. pSigner can be NULL to match any signer. Only
      ;  the Issuer and SerialNumber fields of the pSigner's PCERT_INFO are used.
      ;  To only match CTLs without a signer, pSigner must be set to
      ;  CTL_FIND_NO_SIGNER_PTR.
      ;  The CTL_FIND_SAME_USAGE_FLAG can be set in dwFindFlags to
      ;  only match CTLs with the same usage identifiers. CTLs having additional
      ;  usage identifiers aren't matched. For example, if only "1.2.3" is specified
      ;  in CTL_FIND_USAGE_PARA, then, for a match, the CTL must only contain
      ;  "1.2.3" and not any additional usage identifers.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  CTL_FIND_SUBJECT
      ;  Find a CTL having the specified subject. CertFindSubjectInCTL can be
      ;  called to get a pointer to the subject's entry in the CTL.  pUsagePara can
      ;  optionally be set to enable the above CTL_FIND_USAGE matching.
      ;  pvFindPara points to a CTL_FIND_SUBJECT_PARA data structure.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  Add the encoded CTL to the store according to the specified
      ;  disposition option.
      ;  Makes a copy of the encoded CTL before adding to the store.
      ;  dwAddDispostion specifies the action to take if the CTL
      ;  already exists in the store. See CertAddEncodedCertificateToStore for a
      ;  list of and actions taken.
      ;  Compares the CTL's SubjectUsage, ListIdentifier and any of its signers
      ;  to determine if the CTL already exists in the store.
      ;  ppCtlContext can be NULL, indicating the caller isn't interested
      ;  in getting the CTL_CONTEXT of the added or existing CTL.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertAddEncodedCTLToStore, WIN_STD_CALL_CONV,, <:HCERTSTORE, :DWORD, :ptr BYTE, :DWORD, :DWORD, :ptr PCCTL_CONTEXT>, 24
      ;+-------------------------------------------------------------------------
      ;  Add the CTL context to the store according to the specified
      ;  disposition option.
      ;  In addition to the encoded CTL, the context's properties are
      ;  also copied.  Note, the CERT_KEY_CONTEXT_PROP_ID property (and its
      ;  CERT_KEY_PROV_HANDLE_PROP_ID or CERT_KEY_SPEC_PROP_ID) isn't copied.
      ;  Makes a copy of the encoded CTL before adding to the store.
      ;  dwAddDispostion specifies the action to take if the CTL
      ;  already exists in the store. See CertAddCertificateContextToStore for a
      ;  list of and actions taken.
      ;  Compares the CTL's SubjectUsage, ListIdentifier and any of its signers
      ;  to determine if the CTL already exists in the store.
      ;  ppStoreContext can be NULL, indicating the caller isn't interested
      ;  in getting the CTL_CONTEXT of the added or existing CTL.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertAddCTLContextToStore, WIN_STD_CALL_CONV,, <:HCERTSTORE, :PCCTL_CONTEXT, :DWORD, :ptr PCCTL_CONTEXT>, 16
      ;+-------------------------------------------------------------------------
      ;  Serialize the CTL context's encoded CTL and its properties.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertSerializeCTLStoreElement, WIN_STD_CALL_CONV,, <:PCCTL_CONTEXT, :DWORD, :ptr BYTE, :ptr DWORD>, 16
      ;+-------------------------------------------------------------------------
      ;  Delete the specified CTL from the store.
      ;  All subsequent gets for the CTL will fail. However,
      ;  memory allocated for the CTL isn't freed until all of its contexts
      ;  have also been freed.
      ;  The pCtlContext is obtained from a get or duplicate.
      ;  NOTE: the pCtlContext is always CertFreeCTLContext'ed by
      ;  this function, even for an error.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertDeleteCTLFromStore, WIN_STD_CALL_CONV,, <:PCCTL_CONTEXT>, 4
      @DefProto DllImport, CertAddCertificateLinkToStore, WIN_STD_CALL_CONV,, <:HCERTSTORE, :PCCERT_CONTEXT, :DWORD, :ptr PCCERT_CONTEXT>, 16
      @DefProto DllImport, CertAddCRLLinkToStore, WIN_STD_CALL_CONV,, <:HCERTSTORE, :PCCRL_CONTEXT, :DWORD, :ptr PCCRL_CONTEXT>, 16
      @DefProto DllImport, CertAddCTLLinkToStore, WIN_STD_CALL_CONV,, <:HCERTSTORE, :PCCTL_CONTEXT, :DWORD, :ptr PCCTL_CONTEXT>, 16
      @DefProto DllImport, CertAddStoreToCollection, WIN_STD_CALL_CONV,, <:HCERTSTORE, :HCERTSTORE, :DWORD, :DWORD>, 16
      @DefProto DllImport, CertRemoveStoreFromCollection, WIN_STD_CALL_CONV,, <:HCERTSTORE, :HCERTSTORE>, 8
      @DefProto DllImport, CertControlStore, WIN_STD_CALL_CONV,, <:HCERTSTORE, :DWORD, :DWORD, :ptr>, 16
      ;+-------------------------------------------------------------------------
      ;  Certificate Store control types
      ;--------------------------------------------------------------------------
      CERT_STORE_CTRL_RESYNC equ 1
      CERT_STORE_CTRL_NOTIFY_CHANGE equ 2
      CERT_STORE_CTRL_COMMIT equ 3
      CERT_STORE_CTRL_AUTO_RESYNC equ 4
      CERT_STORE_CTRL_CANCEL_NOTIFY equ 5
      CERT_STORE_CTRL_INHIBIT_DUPLICATE_HANDLE_FLAG equ 1h
      ;+-------------------------------------------------------------------------
      ;  CERT_STORE_CTRL_RESYNC
      ;  Re-synchronize the store.
      ;  The pvCtrlPara points to the event HANDLE to be signaled on
      ;  the next store change. Normally, this would be the same
      ;  event HANDLE passed to CERT_STORE_CTRL_NOTIFY_CHANGE during initialization.
      ;  If pvCtrlPara is NULL, no events are re-armed.
      ;  By default the event HANDLE is DuplicateHandle'd.
      ;  CERT_STORE_CTRL_INHIBIT_DUPLICATE_HANDLE_FLAG can be set in dwFlags
      ;  to inhibit a DupicateHandle of the event HANDLE. If this flag
      ;  is set, then, CertControlStore(CERT_STORE_CTRL_CANCEL_NOTIFY) must be
      ;  called for this event HANDLE before closing the hCertStore.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  CERT_STORE_CTRL_NOTIFY_CHANGE
      ;  Signal the event when the underlying store is changed.
      ;  pvCtrlPara points to the event HANDLE to be signaled.
      ;  pvCtrlPara can be NULL to inform the store of a subsequent
      ;  CERT_STORE_CTRL_RESYNC and allow it to optimize by only doing a resync
      ;  if the store has changed. For the registry based stores, an internal
      ;  notify change event is created and registered to be signaled.
      ;  Recommend calling CERT_STORE_CTRL_NOTIFY_CHANGE once for each event to
      ;  be passed to CERT_STORE_CTRL_RESYNC. This should only happen after
      ;  the event has been created. Not after each time the event is signaled.
      ;  By default the event HANDLE is DuplicateHandle'd.
      ;  CERT_STORE_CTRL_INHIBIT_DUPLICATE_HANDLE_FLAG can be set in dwFlags
      ;  to inhibit a DupicateHandle of the event HANDLE. If this flag
      ;  is set, then, CertControlStore(CERT_STORE_CTRL_CANCEL_NOTIFY) must be
      ;  called for this event HANDLE before closing the hCertStore.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  CERT_STORE_CTRL_CANCEL_NOTIFY
      ;  Cancel notification signaling of the event HANDLE passed in a previous
      ;  CERT_STORE_CTRL_NOTIFY_CHANGE or CERT_STORE_CTRL_RESYNC.
      ;  pvCtrlPara points to the event HANDLE to be canceled.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  CERT_STORE_CTRL_AUTO_RESYNC
      ;  At the start of every enumeration or find store API call, check if the
      ;  underlying store has changed. If it has changed, re-synchronize.
      ;  This check is only done in the enumeration or find APIs when the
      ;  pPrevContext is NULL.
      ;  The pvCtrlPara isn't used and must be set to NULL.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  CERT_STORE_CTRL_COMMIT
      ;  If any changes have been to the cached store, they are committed to
      ;  persisted storage. If no changes have been made since the store was
      ;  opened or the last commit, this call is ignored. May also be ignored by
      ;  store providers that persist changes immediately.
      ;  CERT_STORE_CTRL_COMMIT_FORCE_FLAG can be set to force the store
      ;  to be committed even if it hasn't been touched.
      ;  CERT_STORE_CTRL_COMMIT_CLEAR_FLAG can be set to inhibit a commit on
      ;  store close.
      ;--------------------------------------------------------------------------
      CERT_STORE_CTRL_COMMIT_FORCE_FLAG equ 1h
      CERT_STORE_CTRL_COMMIT_CLEAR_FLAG equ 2h
      ;+=========================================================================
      ;  Cert Store Property Defines and APIs
      ;==========================================================================
      ;+-------------------------------------------------------------------------
      ;  Store property IDs. This is a property applicable to the entire store.
      ;  Its not a property on an individual certificate, CRL or CTL context.
      ;  Currently, no store properties are persisted. (This differs from
      ;  most context properties which are persisted.)
      ;  See CertSetStoreProperty or CertGetStoreProperty for usage information.
      ;  Note, the range for predefined store properties should be outside
      ;  the range of predefined context properties. We will start at 4096.
      ;--------------------------------------------------------------------------
      ; certenrolld_begin -- CERT_*_PROP_ID
      CERT_STORE_LOCALIZED_NAME_PROP_ID equ 1000h
      ; certenrolld_end
      ;+-------------------------------------------------------------------------
      ;  Set a store property.
      ;  The type definition for pvData depends on the dwPropId value.
      ;      CERT_STORE_LOCALIZED_NAME_PROP_ID - localized name of the store.
      ;      pvData points to a CRYPT_DATA_BLOB. pbData is a pointer to a NULL
      ;      terminated unicode, wide character string.
      ;      cbData = (wcslen((LPWSTR) pbData) + 1) * sizeof(WCHAR).
      ;  For all the other PROP_IDs: an encoded PCRYPT_DATA_BLOB is passed in pvData.
      ;  If the property already exists, then, the old value is deleted and silently
      ;  replaced. Setting, pvData to NULL, deletes the property.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertSetStoreProperty, WIN_STD_CALL_CONV,, <:HCERTSTORE, :DWORD, :DWORD, :ptr>, 16
      ;+-------------------------------------------------------------------------
      ;  Get a store property.
      ;  The type definition for pvData depends on the dwPropId value.
      ;      CERT_STORE_LOCALIZED_NAME_PROP_ID - localized name of the store.
      ;      pvData points to a NULL terminated unicode, wide character string.
      ;      cbData = (wcslen((LPWSTR) pvData) + 1) * sizeof(WCHAR).
      ;  For all other PROP_IDs, pvData points to an array of bytes.
      ;  If the property doesn't exist, returns FALSE and sets LastError to
      ;  CRYPT_E_NOT_FOUND.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertGetStoreProperty, WIN_STD_CALL_CONV,, <:HCERTSTORE, :DWORD, :ptr, :ptr DWORD>, 16
      ;+-------------------------------------------------------------------------
      ; If the callback returns FALSE, stops the sort. CertCreateContext
      ; will return FALSE and set last error to ERROR_CANCELLED if the sort
      ; was stopped.
      ; Where:
      ;  cbTotalEncoded  - total byte count of the encoded entries.
      ;  cbRemainEncoded - remaining byte count of the encoded entries.
      ;  cEntry          - running count of sorted entries
      ;  pvSort          - value passed in pCreatePara
      ;--------------------------------------------------------------------------
      TYPE_PFN_CERT_CREATE_CONTEXT_SORT_FUNC typedef proto WIN_STD_CALL_CONV :DWORD, :DWORD, :DWORD, :ptr
      PFN_CERT_CREATE_CONTEXT_SORT_FUNC typedef ptr TYPE_PFN_CERT_CREATE_CONTEXT_SORT_FUNC

      CERT_CREATE_CONTEXT_PARA struct
        cbSize DWORD ?
        pfnFree PFN_CRYPT_FREE ?
        ; OPTIONAL
        pvFree POINTER ?
        ; OPTIONAL
        ; Only applicable to CERT_STORE_CTL_CONTEXT when
        ; CERT_CREATE_CONTEXT_SORTED_FLAG is set in dwFlags.
        pfnSort PFN_CERT_CREATE_CONTEXT_SORT_FUNC ?
        ; OPTIONAL
        pvSort POINTER ?
        ; OPTIONAL
      CERT_CREATE_CONTEXT_PARA ends
      _CERT_CREATE_CONTEXT_PARA typedef CERT_CREATE_CONTEXT_PARA
      PCERT_CREATE_CONTEXT_PARA typedef ptr CERT_CREATE_CONTEXT_PARA
      ;+-------------------------------------------------------------------------
      ;  Creates the specified context from the encoded bytes. The created
      ;  context isn't put in a store.
      ;  dwContextType values:
      ;      CERT_STORE_CERTIFICATE_CONTEXT
      ;      CERT_STORE_CRL_CONTEXT
      ;      CERT_STORE_CTL_CONTEXT
      ;  If CERT_CREATE_CONTEXT_NOCOPY_FLAG is set, the created context points
      ;  directly to the pbEncoded instead of an allocated copy. See flag
      ;  definition for more details.
      ;  If CERT_CREATE_CONTEXT_SORTED_FLAG is set, the context is created
      ;  with sorted entries. This flag may only be set for CERT_STORE_CTL_CONTEXT.
      ;  Setting this flag implicitly sets CERT_CREATE_CONTEXT_NO_HCRYPTMSG_FLAG and
      ;  CERT_CREATE_CONTEXT_NO_ENTRY_FLAG. See flag definition for
      ;  more details.
      ;  If CERT_CREATE_CONTEXT_NO_HCRYPTMSG_FLAG is set, the context is created
      ;  without creating a HCRYPTMSG handle for the context. This flag may only be
      ;  set for CERT_STORE_CTL_CONTEXT.  See flag definition for more details.
      ;  If CERT_CREATE_CONTEXT_NO_ENTRY_FLAG is set, the context is created
      ;  without decoding the entries. This flag may only be set for
      ;  CERT_STORE_CTL_CONTEXT.  See flag definition for more details.
      ;  If unable to decode and create the context, NULL is returned.
      ;  Otherwise, a pointer to a read only CERT_CONTEXT, CRL_CONTEXT or
      ;  CTL_CONTEXT is returned. The context must be freed by the appropriate
      ;  free context API. The context can be duplicated by calling the
      ;  appropriate duplicate context API.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertCreateContext, WIN_STD_CALL_CONV,, <:DWORD, :DWORD, :ptr BYTE, :DWORD, :DWORD, :PCERT_CREATE_CONTEXT_PARA>, 24
      ; When the following flag is set, the created context points directly to the
      ; pbEncoded instead of an allocated copy. If pCreatePara and
      ; pCreatePara->pfnFree are non-NULL, then, pfnFree is called to free
      ; the pbEncoded when the context is last freed. Otherwise, no attempt is
      ; made to free the pbEncoded. If pCreatePara->pvFree is non-NULL, then its
      ; passed to pfnFree instead of pbEncoded.
      ; Note, if CertCreateContext fails, pfnFree is still called.
      CERT_CREATE_CONTEXT_NOCOPY_FLAG equ 1h
      ; When the following flag is set, a context with sorted entries is created.
      ; Currently only applicable to a CTL context.
      ; For CTLs: the cCTLEntry in the returned CTL_INFO is always
      ; 0. CertFindSubjectInSortedCTL and CertEnumSubjectInSortedCTL must be called
      ; to find or enumerate the CTL entries.
      ; The Sorted CTL TrustedSubjects extension isn't returned in the created
      ; context's CTL_INFO.
      ; pfnSort and pvSort can be set in the pCreatePara parameter to be called for
      ; each sorted entry. pfnSort can return FALSE to stop the sorting.
      CERT_CREATE_CONTEXT_SORTED_FLAG equ 2h
      ; By default when a CTL context is created, a HCRYPTMSG handle to its
      ; SignedData message is created. This flag can be set to improve performance
      ; by not creating the HCRYPTMSG handle.
      ; This flag is only applicable to a CTL context.
      CERT_CREATE_CONTEXT_NO_HCRYPTMSG_FLAG equ 4h
      ; By default when a CTL context is created, its entries are decoded.
      ; This flag can be set to improve performance by not decoding the
      ; entries.
      ; This flag is only applicable to a CTL context.
      CERT_CREATE_CONTEXT_NO_ENTRY_FLAG equ 8h
      ;+=========================================================================
      ;  Certificate System Store Data Structures and APIs
      ;==========================================================================
      ;+-------------------------------------------------------------------------
      ;  System Store Information
      ;  Currently, no system store information is persisted.
      ;--------------------------------------------------------------------------
      CERT_SYSTEM_STORE_INFO struct
        cbSize DWORD ?
      CERT_SYSTEM_STORE_INFO ends
      _CERT_SYSTEM_STORE_INFO typedef CERT_SYSTEM_STORE_INFO
      PCERT_SYSTEM_STORE_INFO typedef ptr CERT_SYSTEM_STORE_INFO
      ;+-------------------------------------------------------------------------
      ;  Physical Store Information
      ;  The Open fields are passed directly to CertOpenStore() to open
      ;  the physical store.
      ;  By default all system stores located in the registry have an
      ;  implicit SystemRegistry physical store that is opened. To disable the
      ;  opening of this store, the SystemRegistry
      ;  physical store corresponding to the System store must be registered with
      ;  CERT_PHYSICAL_STORE_OPEN_DISABLE_FLAG set in dwFlags. Alternatively,
      ;  a physical store with the name of ".Default" may be registered.
      ;  Depending on the store location and store name, additional predefined
      ;  physical stores may be opened. For example, system stores in
      ;  CURRENT_USER have the predefined physical store, .LocalMachine.
      ;  To disable the opening of these predefined physical stores, the
      ;  corresponding physical store must be registered with
      ;  CERT_PHYSICAL_STORE_OPEN_DISABLE_FLAG set in dwFlags.
      ;  The CERT_PHYSICAL_STORE_ADD_ENABLE_FLAG must be set in dwFlags
      ;  to enable the adding of a context to the store.
      ;  When a system store is opened via the SERVICES or USERS store location,
      ;  the ServiceName\ is prepended to the OpenParameters
      ;  for CERT_SYSTEM_STORE_CURRENT_USER or CERT_SYSTEM_STORE_CURRENT_SERVICE
      ;  physical stores and the dwOpenFlags store location is changed to
      ;  CERT_SYSTEM_STORE_USERS or CERT_SYSTEM_STORE_SERVICES.
      ;  By default the SYSTEM, SYSTEM_REGISTRY and PHYSICAL provider
      ;  stores are also opened remotely when the outer system store is opened.
      ;  The CERT_PHYSICAL_STORE_REMOTE_OPEN_DISABLE_FLAG may be set in dwFlags
      ;  to disable remote opens.
      ;  When opened remotely, the \\ComputerName is implicitly prepended to the
      ;  OpenParameters for the SYSTEM, SYSTEM_REGISTRY and PHYSICAL provider types.
      ;  To also prepend the \\ComputerName to other provider types, set the
      ;  CERT_PHYSICAL_STORE_INSERT_COMPUTER_NAME_ENABLE_FLAG in dwFlags.
      ;  When the system store is opened, its physical stores are ordered
      ;  according to the dwPriority. A larger dwPriority indicates higher priority.
      ;--------------------------------------------------------------------------
      CERT_PHYSICAL_STORE_INFO struct
        cbSize DWORD ?
        pszOpenStoreProvider POINTER ?
        ; REG_SZ
        dwOpenEncodingType DWORD ?
        ; REG_DWORD
        dwOpenFlags DWORD ?
        ; REG_DWORD
        OpenParameters CRYPT_DATA_BLOB <>
        ; REG_BINARY
        dwFlags DWORD ?
        ; REG_DWORD
        dwPriority DWORD ?
        ; REG_DWORD
      CERT_PHYSICAL_STORE_INFO ends
      _CERT_PHYSICAL_STORE_INFO typedef CERT_PHYSICAL_STORE_INFO
      PCERT_PHYSICAL_STORE_INFO typedef ptr CERT_PHYSICAL_STORE_INFO
      ;+-------------------------------------------------------------------------
      ;  Physical Store Information dwFlags
      ;--------------------------------------------------------------------------
      CERT_PHYSICAL_STORE_ADD_ENABLE_FLAG equ 1h
      CERT_PHYSICAL_STORE_OPEN_DISABLE_FLAG equ 2h
      CERT_PHYSICAL_STORE_REMOTE_OPEN_DISABLE_FLAG equ 4h
      CERT_PHYSICAL_STORE_INSERT_COMPUTER_NAME_ENABLE_FLAG equ 8h
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)*
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_PHONE_RESTRICTED or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      ;+-------------------------------------------------------------------------
      ;  Register a system store.
      ;  The upper word of the dwFlags parameter is used to specify the location of
      ;  the system store.
      ;  If CERT_SYSTEM_STORE_RELOCATE_FLAG is set in dwFlags, pvSystemStore
      ;  points to a CERT_SYSTEM_STORE_RELOCATE_PARA data structure. Otherwise,
      ;  pvSystemStore points to a null terminated UNICODE string.
      ;  The CERT_SYSTEM_STORE_SERVICES or CERT_SYSTEM_STORE_USERS system store
      ;  name must be prefixed with the ServiceName or UserName. For example,
      ;  "ServiceName\Trust".
      ;  Stores on remote computers can be registered for the
      ;  CERT_SYSTEM_STORE_LOCAL_MACHINE, CERT_SYSTEM_STORE_SERVICES,
      ;  CERT_SYSTEM_STORE_USERS, CERT_SYSTEM_STORE_LOCAL_MACHINE_GROUP_POLICY
      ;  or CERT_SYSTEM_STORE_LOCAL_MACHINE_ENTERPRISE
      ;  locations by prepending the computer name. For example, a remote
      ;  local machine store is registered via "\\ComputerName\Trust" or
      ;  "ComputerName\Trust". A remote service store is registered via
      ;  "\\ComputerName\ServiceName\Trust". The leading "\\" backslashes are
      ;  optional in the ComputerName.
      ;  Set CERT_STORE_CREATE_NEW_FLAG to cause a failure if the system store
      ;  already exists in the store location.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertRegisterSystemStore, WIN_STD_CALL_CONV,, <:ptr, :DWORD, :PCERT_SYSTEM_STORE_INFO, :ptr>, 16
      ;+-------------------------------------------------------------------------
      ;  Register a physical store for the specified system store.
      ;  The upper word of the dwFlags parameter is used to specify the location of
      ;  the system store.
      ;  If CERT_SYSTEM_STORE_RELOCATE_FLAG is set in dwFlags, pvSystemStore
      ;  points to a CERT_SYSTEM_STORE_RELOCATE_PARA data structure. Otherwise,
      ;  pvSystemStore points to a null terminated UNICODE string.
      ;  See CertRegisterSystemStore for details on prepending a ServiceName
      ;  and/or ComputerName to the system store name.
      ;  Set CERT_STORE_CREATE_NEW_FLAG to cause a failure if the physical store
      ;  already exists in the system store.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertRegisterPhysicalStore, WIN_STD_CALL_CONV,, <:ptr, :DWORD, :LPCWSTR, :PCERT_PHYSICAL_STORE_INFO, :ptr>, 20
      ;+-------------------------------------------------------------------------
      ;  Unregister the specified system store.
      ;  The upper word of the dwFlags parameter is used to specify the location of
      ;  the system store.
      ;  If CERT_SYSTEM_STORE_RELOCATE_FLAG is set in dwFlags, pvSystemStore
      ;  points to a CERT_SYSTEM_STORE_RELOCATE_PARA data structure. Otherwise,
      ;  pvSystemStore points to a null terminated UNICODE string.
      ;  See CertRegisterSystemStore for details on prepending a ServiceName
      ;  and/or ComputerName to the system store name.
      ;  CERT_STORE_DELETE_FLAG can optionally be set in dwFlags.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertUnregisterSystemStore, WIN_STD_CALL_CONV,, <:ptr, :DWORD>, 8
      ;+-------------------------------------------------------------------------
      ;  Unregister the physical store from the specified system store.
      ;  The upper word of the dwFlags parameter is used to specify the location of
      ;  the system store.
      ;  If CERT_SYSTEM_STORE_RELOCATE_FLAG is set in dwFlags, pvSystemStore
      ;  points to a CERT_SYSTEM_STORE_RELOCATE_PARA data structure. Otherwise,
      ;  pvSystemStore points to a null terminated UNICODE string.
      ;  See CertRegisterSystemStore for details on prepending a ServiceName
      ;  and/or ComputerName to the system store name.
      ;  CERT_STORE_DELETE_FLAG can optionally be set in dwFlags.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertUnregisterPhysicalStore, WIN_STD_CALL_CONV,, <:ptr, :DWORD, :LPCWSTR>, 12
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP|WINAPI_PARTITION_PHONE_RESTRICTED | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      ;+-------------------------------------------------------------------------
      ;  Enum callbacks
      ;  The CERT_SYSTEM_STORE_LOCATION_MASK bits in the dwFlags parameter
      ;  specifies the location of the system store
      ;  If CERT_SYSTEM_STORE_RELOCATE_FLAG is set in dwFlags, pvSystemStore
      ;  points to a CERT_SYSTEM_STORE_RELOCATE_PARA data structure. Otherwise,
      ;  pvSystemStore points to a null terminated UNICODE string.
      ;  The callback returns FALSE and sets LAST_ERROR to stop the enumeration.
      ;  The LAST_ERROR is returned to the caller of the enumeration.
      ;  The pvSystemStore passed to the callback has leading ComputerName and/or
      ;  ServiceName prefixes where appropriate.
      ;--------------------------------------------------------------------------
      TYPE_PFN_CERT_ENUM_SYSTEM_STORE_LOCATION typedef proto WIN_STD_CALL_CONV :LPCWSTR, :DWORD, :ptr, :ptr
      PFN_CERT_ENUM_SYSTEM_STORE_LOCATION typedef ptr TYPE_PFN_CERT_ENUM_SYSTEM_STORE_LOCATION

      TYPE_PFN_CERT_ENUM_SYSTEM_STORE typedef proto WIN_STD_CALL_CONV :ptr, :DWORD, :PCERT_SYSTEM_STORE_INFO, :ptr, :ptr
      PFN_CERT_ENUM_SYSTEM_STORE typedef ptr TYPE_PFN_CERT_ENUM_SYSTEM_STORE

      TYPE_PFN_CERT_ENUM_PHYSICAL_STORE typedef proto WIN_STD_CALL_CONV :ptr, :DWORD, :LPCWSTR, :PCERT_PHYSICAL_STORE_INFO, :ptr, :ptr
      PFN_CERT_ENUM_PHYSICAL_STORE typedef ptr TYPE_PFN_CERT_ENUM_PHYSICAL_STORE

      ; In the PFN_CERT_ENUM_PHYSICAL_STORE callback the following flag is
      ; set if the physical store wasn't registered and is an implicitly created
      ; predefined physical store.
      CERT_PHYSICAL_STORE_PREDEFINED_ENUM_FLAG equ 1h
      ; Names of implicitly created predefined physical stores
      CERT_PHYSICAL_STORE_DEFAULT_NAME equ <L(".Default")>
      CERT_PHYSICAL_STORE_GROUP_POLICY_NAME equ <L(".GroupPolicy")>
      CERT_PHYSICAL_STORE_LOCAL_MACHINE_NAME equ <L(".LocalMachine")>
      CERT_PHYSICAL_STORE_DS_USER_CERTIFICATE_NAME equ <L(".UserCertificate")>
      CERT_PHYSICAL_STORE_LOCAL_MACHINE_GROUP_POLICY_NAME equ <L(".LocalMachineGroupPolicy")>
      CERT_PHYSICAL_STORE_ENTERPRISE_NAME equ <L(".Enterprise")>
      CERT_PHYSICAL_STORE_AUTH_ROOT_NAME equ <L(".AuthRoot")>
      CERT_PHYSICAL_STORE_SMART_CARD_NAME equ <L(".SmartCard")>
      ;+-------------------------------------------------------------------------
      ;  Enumerate the system store locations.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertEnumSystemStoreLocation, WIN_STD_CALL_CONV,, <:DWORD, :ptr, :PFN_CERT_ENUM_SYSTEM_STORE_LOCATION>, 12
      ;+-------------------------------------------------------------------------
      ;  Enumerate the system stores.
      ;  The upper word of the dwFlags parameter is used to specify the location of
      ;  the system store.
      ;  If CERT_SYSTEM_STORE_RELOCATE_FLAG is set in dwFlags,
      ;  pvSystemStoreLocationPara points to a CERT_SYSTEM_STORE_RELOCATE_PARA
      ;  data structure. Otherwise, pvSystemStoreLocationPara points to a null
      ;  terminated UNICODE string.
      ;  For CERT_SYSTEM_STORE_LOCAL_MACHINE,
      ;  CERT_SYSTEM_STORE_LOCAL_MACHINE_GROUP_POLICY or
      ;  CERT_SYSTEM_STORE_LOCAL_MACHINE_ENTERPRISE, pvSystemStoreLocationPara can
      ;  optionally be set to a unicode computer name for enumerating local machine
      ;  stores on a remote computer. For example, "\\ComputerName" or
      ;  "ComputerName".  The leading "\\" backslashes are optional in the
      ;  ComputerName.
      ;  For CERT_SYSTEM_STORE_SERVICES or CERT_SYSTEM_STORE_USERS,
      ;  if pvSystemStoreLocationPara is NULL, then,
      ;  enumerates both the service/user names and the stores for each service/user
      ;  name. Otherwise, pvSystemStoreLocationPara is a unicode string specifying a
      ;  remote computer name and/or service/user name. For example:
      ;      "ServiceName"
      ;      "\\ComputerName" or "ComputerName\"
      ;      "ComputerName\ServiceName"
      ;  Note, if only the ComputerName is specified, then, it must have either
      ;  the leading "\\" backslashes or a trailing backslash. Otherwise, its
      ;  interpretted as the ServiceName or UserName.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertEnumSystemStore, WIN_STD_CALL_CONV,, <:DWORD, :ptr, :ptr, :PFN_CERT_ENUM_SYSTEM_STORE>, 16
      ;+-------------------------------------------------------------------------
      ;  Enumerate the physical stores for the specified system store.
      ;  The upper word of the dwFlags parameter is used to specify the location of
      ;  the system store.
      ;  If CERT_SYSTEM_STORE_RELOCATE_FLAG is set in dwFlags, pvSystemStore
      ;  points to a CERT_SYSTEM_STORE_RELOCATE_PARA data structure. Otherwise,
      ;  pvSystemStore points to a null terminated UNICODE string.
      ;  See CertRegisterSystemStore for details on prepending a ServiceName
      ;  and/or ComputerName to the system store name.
      ;  If the system store location only supports system stores and doesn't
      ;  support physical stores, LastError is set to ERROR_CALL_NOT_IMPLEMENTED.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertEnumPhysicalStore, WIN_STD_CALL_CONV,, <:ptr, :DWORD, :ptr, :PFN_CERT_ENUM_PHYSICAL_STORE>, 16
      ;+-------------------------------------------------------------------------
      ;  Certificate System Store Installable Functions
      ;  The CERT_SYSTEM_STORE_LOCATION_MASK bits in the dwFlags parameter passed
      ;  to the CertOpenStore(for "System", "SystemRegistry" or "Physical"
      ;  Provider), CertRegisterSystemStore,
      ;  CertUnregisterSystemStore, CertEnumSystemStore, CertRegisterPhysicalStore,
      ;  CertUnregisterPhysicalStore and CertEnumPhysicalStore APIs is used as the
      ;  constant pszOID value passed to the OID installable functions.
      ;  Therefore, the pszOID is restricted to a constant <= (LPCSTR) 0x0FFF.
      ;  The EncodingType is 0.
      ;--------------------------------------------------------------------------
      ; Installable System Store Provider OID pszFuncNames.
      CRYPT_OID_OPEN_SYSTEM_STORE_PROV_FUNC equ <"CertDllOpenSystemStoreProv">
      CRYPT_OID_REGISTER_SYSTEM_STORE_FUNC equ <"CertDllRegisterSystemStore">
      CRYPT_OID_UNREGISTER_SYSTEM_STORE_FUNC equ <"CertDllUnregisterSystemStore">
      CRYPT_OID_ENUM_SYSTEM_STORE_FUNC equ <"CertDllEnumSystemStore">
      CRYPT_OID_REGISTER_PHYSICAL_STORE_FUNC equ <"CertDllRegisterPhysicalStore">
      CRYPT_OID_UNREGISTER_PHYSICAL_STORE_FUNC equ <"CertDllUnregisterPhysicalStore">
      CRYPT_OID_ENUM_PHYSICAL_STORE_FUNC equ <"CertDllEnumPhysicalStore">
      ; CertDllOpenSystemStoreProv has the same function signature as the
      ; installable "CertDllOpenStoreProv" function. See CertOpenStore for
      ; more details.
      ; CertDllRegisterSystemStore has the same function signature as
      ; CertRegisterSystemStore.
      ; The "SystemStoreLocation" REG_SZ value must also be set for registered
      ; CertDllEnumSystemStore OID functions.
      CRYPT_OID_SYSTEM_STORE_LOCATION_VALUE_NAME equ <L("SystemStoreLocation")>
      ; The remaining Register, Enum and Unregister OID installable functions
      ; have the same signature as their Cert Store API counterpart.
      ;+=========================================================================
      ;  Enhanced Key Usage Helper Functions
      ;==========================================================================
      ;+-------------------------------------------------------------------------
      ;  Get the enhanced key usage extension or property from the certificate
      ;  and decode.
      ;  If the CERT_FIND_EXT_ONLY_ENHKEY_USAGE_FLAG is set, then, only get the
      ;  extension.
      ;  If the CERT_FIND_PROP_ONLY_ENHKEY_USAGE_FLAG is set, then, only get the
      ;  property.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertGetEnhancedKeyUsage, WIN_STD_CALL_CONV,, <:PCCERT_CONTEXT, :DWORD, :PCERT_ENHKEY_USAGE, :ptr DWORD>, 16
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)*
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_PHONE_RESTRICTED or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      ;+-------------------------------------------------------------------------
      ;  Set the enhanced key usage property for the certificate.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertSetEnhancedKeyUsage, WIN_STD_CALL_CONV,, <:PCCERT_CONTEXT, :PCERT_ENHKEY_USAGE>, 8
      ;+-------------------------------------------------------------------------
      ;  Add the usage identifier to the certificate's enhanced key usage property.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertAddEnhancedKeyUsageIdentifier, WIN_STD_CALL_CONV,, <:PCCERT_CONTEXT, :LPCSTR>, 8
      ;+-------------------------------------------------------------------------
      ;  Remove the usage identifier from the certificate's enhanced key usage
      ;  property.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertRemoveEnhancedKeyUsageIdentifier, WIN_STD_CALL_CONV,, <:PCCERT_CONTEXT, :LPCSTR>, 8
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP|WINAPI_PARTITION_PHONE_RESTRICTED | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      ;+---------------------------------------------------------------------------
      ;  Takes an array of certs and returns an array of usages
      ;  which consists of the intersection of the valid usages for each cert.
      ;  If each cert is good for all possible usages then the cNumOIDs is set to -1.
      ;----------------------------------------------------------------------------
      @DefProto DllImport, CertGetValidUsages, WIN_STD_CALL_CONV,, <:DWORD, :ptr PCCERT_CONTEXT, :ptr SDWORD, :ptr LPSTR, :ptr DWORD>, 20
      ;+=========================================================================
      ;  Cryptographic Message helper functions for verifying and signing a
      ;  CTL.
      ;==========================================================================
      ;+-------------------------------------------------------------------------
      ;  Get and verify the signer of a cryptographic message.
      ;  To verify a CTL, the hCryptMsg is obtained from the CTL_CONTEXT's
      ;  hCryptMsg field.
      ;  If CMSG_TRUSTED_SIGNER_FLAG is set, then, treat the Signer stores as being
      ;  trusted and only search them to find the certificate corresponding to the
      ;  signer's issuer and serial number.  Otherwise, the SignerStores are
      ;  optionally provided to supplement the message's store of certificates.
      ;  If a signer certificate is found, its public key is used to verify
      ;  the message signature. The CMSG_SIGNER_ONLY_FLAG can be set to
      ;  return the signer without doing the signature verify.
      ;  If CMSG_USE_SIGNER_INDEX_FLAG is set, then, only get the signer specified
      ;  by *pdwSignerIndex. Otherwise, iterate through all the signers
      ;  until a signer verifies or no more signers.
      ;  For a verified signature, *ppSigner is updated with certificate context
      ;  of the signer and *pdwSignerIndex is updated with the index of the signer.
      ;  ppSigner and/or pdwSignerIndex can be NULL, indicating the caller isn't
      ;  interested in getting the CertContext and/or index of the signer.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CryptMsgGetAndVerifySigner, WIN_STD_CALL_CONV,, <:HCRYPTMSG, :DWORD, :ptr HCERTSTORE, :DWORD, :ptr PCCERT_CONTEXT, :ptr DWORD>, 24
      CMSG_TRUSTED_SIGNER_FLAG equ 1h
      CMSG_SIGNER_ONLY_FLAG equ 2h
      CMSG_USE_SIGNER_INDEX_FLAG equ 4h
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)*
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_PHONE_RESTRICTED or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      ;+-------------------------------------------------------------------------
      ;  Sign an encoded CTL.
      ;  The pbCtlContent can be obtained via a CTL_CONTEXT's pbCtlContent
      ;  field or via a CryptEncodeObject(PKCS_CTL or PKCS_SORTED_CTL).
      ;  CMSG_CMS_ENCAPSULATED_CTL_FLAG can be set to encode a CMS compatible
      ;  V3 SignedData message.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CryptMsgSignCTL, WIN_STD_CALL_CONV,, <:DWORD, :ptr BYTE, :DWORD, :PCMSG_SIGNED_ENCODE_INFO, :DWORD, :ptr BYTE, :ptr DWORD>, 28
      ; When set, CTL inner content is encapsulated within an OCTET STRING
      CMSG_CMS_ENCAPSULATED_CTL_FLAG equ 00008000h
      ;+-------------------------------------------------------------------------
      ;  Encode the CTL and create a signed message containing the encoded CTL.
      ;  Set CMSG_ENCODE_SORTED_CTL_FLAG if the CTL entries are to be sorted
      ;  before encoding. This flag should be set, if the
      ;  CertFindSubjectInSortedCTL or CertEnumSubjectInSortedCTL APIs will
      ;  be called. If the identifier for the CTL entries is a hash, such as,
      ;  MD5 or SHA1, then, CMSG_ENCODE_HASHED_SUBJECT_IDENTIFIER_FLAG should
      ;  also be set.
      ;  CMSG_CMS_ENCAPSULATED_CTL_FLAG can be set to encode a CMS compatible
      ;  V3 SignedData message.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CryptMsgEncodeAndSignCTL, WIN_STD_CALL_CONV,, <:DWORD, :PCTL_INFO, :PCMSG_SIGNED_ENCODE_INFO, :DWORD, :ptr BYTE, :ptr DWORD>, 24
      ;  The following flag is set if the CTL is to be encoded with sorted
      ;  trusted subjects and the szOID_SORTED_CTL extension is inserted containing
      ;  sorted offsets to the encoded subjects.
      CMSG_ENCODE_SORTED_CTL_FLAG equ 1h
      ;  If the above sorted flag is set, then, the following flag should also
      ;  be set if the identifier for the TrustedSubjects is a hash,
      ;  such as, MD5 or SHA1.
      CMSG_ENCODE_HASHED_SUBJECT_IDENTIFIER_FLAG equ 2h
      ;+-------------------------------------------------------------------------
      ;  Returns TRUE if the SubjectIdentifier exists in the CTL. Optionally
      ;  returns a pointer to and byte count of the Subject's encoded attributes.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertFindSubjectInSortedCTL, WIN_STD_CALL_CONV,, <:PCRYPT_DATA_BLOB, :PCCTL_CONTEXT, :DWORD, :ptr, :PCRYPT_DER_BLOB>, 20
      ;+-------------------------------------------------------------------------
      ;  Enumerates through the sequence of TrustedSubjects in a CTL context
      ;  created with CERT_CREATE_CONTEXT_SORTED_FLAG set.
      ;  To start the enumeration, *ppvNextSubject must be NULL. Upon return,
      ;  *ppvNextSubject is updated to point to the next TrustedSubject in
      ;  the encoded sequence.
      ;  Returns FALSE for no more subjects or invalid arguments.
      ;  Note, the returned DER_BLOBs point directly into the encoded
      ;  bytes (not allocated, and must not be freed).
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertEnumSubjectInSortedCTL, WIN_STD_CALL_CONV,, <:PCCTL_CONTEXT, :ptr ptr, :PCRYPT_DER_BLOB, :PCRYPT_DER_BLOB>, 16
      ;+=========================================================================
      ;  Certificate Verify CTL Usage Data Structures and APIs
      ;==========================================================================
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP|WINAPI_PARTITION_PHONE_RESTRICTED | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      CTL_VERIFY_USAGE_PARA struct
        cbSize DWORD ?
        ListIdentifier CRYPT_DATA_BLOB <>
        ; OPTIONAL
        cCtlStore DWORD ?
        rghCtlStore POINTER ?
        ; OPTIONAL
        cSignerStore DWORD ?
        rghSignerStore POINTER ?
        ; OPTIONAL
      CTL_VERIFY_USAGE_PARA ends
      _CTL_VERIFY_USAGE_PARA typedef CTL_VERIFY_USAGE_PARA
      PCTL_VERIFY_USAGE_PARA typedef ptr CTL_VERIFY_USAGE_PARA
      CTL_VERIFY_USAGE_STATUS struct
        cbSize DWORD ?
        dwError DWORD ?
        dwFlags DWORD ?
        ppCtl POINTER ?
        ; IN OUT OPTIONAL
        dwCtlEntryIndex DWORD ?
        ppSigner POINTER ?
        ; IN OUT OPTIONAL
        dwSignerIndex DWORD ?
      CTL_VERIFY_USAGE_STATUS ends
      _CTL_VERIFY_USAGE_STATUS typedef CTL_VERIFY_USAGE_STATUS
      PCTL_VERIFY_USAGE_STATUS typedef ptr CTL_VERIFY_USAGE_STATUS
      CERT_VERIFY_INHIBIT_CTL_UPDATE_FLAG equ 1h
      CERT_VERIFY_TRUSTED_SIGNERS_FLAG equ 2h
      CERT_VERIFY_NO_TIME_CHECK_FLAG equ 4h
      CERT_VERIFY_ALLOW_MORE_USAGE_FLAG equ 8h
      CERT_VERIFY_UPDATED_CTL_FLAG equ 1h
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)*
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_PHONE_RESTRICTED or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      ;+-------------------------------------------------------------------------
      ;  Verify that a subject is trusted for the specified usage by finding a
      ;  signed and time valid CTL with the usage identifiers and containing the
      ;  the subject. A subject can be identified by either its certificate context
      ;  or any identifier such as its SHA1 hash.
      ;  See CertFindSubjectInCTL for definition of dwSubjectType and pvSubject
      ;  parameters.
      ;  Via pVerifyUsagePara, the caller can specify the stores to be searched
      ;  to find the CTL. The caller can also specify the stores containing
      ;  acceptable CTL signers. By setting the ListIdentifier, the caller
      ;  can also restrict to a particular signer CTL list.
      ;  Via pVerifyUsageStatus, the CTL containing the subject, the subject's
      ;  index into the CTL's array of entries, and the signer of the CTL
      ;  are returned. If the caller is not interested, ppCtl and ppSigner can be set
      ;  to NULL. Returned contexts must be freed via the store's free context APIs.
      ;  If the CERT_VERIFY_INHIBIT_CTL_UPDATE_FLAG isn't set, then, a time
      ;  invalid CTL in one of the CtlStores may be replaced. When replaced, the
      ;  CERT_VERIFY_UPDATED_CTL_FLAG is set in pVerifyUsageStatus->dwFlags.
      ;  If the CERT_VERIFY_TRUSTED_SIGNERS_FLAG is set, then, only the
      ;  SignerStores specified in pVerifyUsageStatus are searched to find
      ;  the signer. Otherwise, the SignerStores provide additional sources
      ;  to find the signer's certificate.
      ;  If CERT_VERIFY_NO_TIME_CHECK_FLAG is set, then, the CTLs aren't checked
      ;  for time validity.
      ;  If CERT_VERIFY_ALLOW_MORE_USAGE_FLAG is set, then, the CTL may contain
      ;  additional usage identifiers than specified by pSubjectUsage. Otherwise,
      ;  the found CTL will contain the same usage identifers and no more.
      ;  CertVerifyCTLUsage will be implemented as a dispatcher to OID installable
      ;  functions. First, it will try to find an OID function matching the first
      ;  usage object identifier in the pUsage sequence. Next, it will dispatch
      ;  to the default CertDllVerifyCTLUsage functions.
      ;  If the subject is trusted for the specified usage, then, TRUE is
      ;  returned. Otherwise, FALSE is returned with dwError set to one of the
      ;  following:
      ;      CRYPT_E_NO_VERIFY_USAGE_DLL
      ;      CRYPT_E_NO_VERIFY_USAGE_CHECK
      ;      CRYPT_E_VERIFY_USAGE_OFFLINE
      ;      CRYPT_E_NOT_IN_CTL
      ;      CRYPT_E_NO_TRUSTED_SIGNER
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertVerifyCTLUsage, WIN_STD_CALL_CONV,, <:DWORD, :DWORD, :ptr, :PCTL_USAGE, :DWORD, :PCTL_VERIFY_USAGE_PARA, :PCTL_VERIFY_USAGE_STATUS>, 28
      ;+=========================================================================
      ;  Certificate Revocation Data Structures and APIs
      ;==========================================================================
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP|WINAPI_PARTITION_PHONE_RESTRICTED | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      ;+-------------------------------------------------------------------------
      ;  This data structure is updated by a CRL revocation type handler
      ;  with the base and possibly the delta CRL used.
      ;--------------------------------------------------------------------------
      CERT_REVOCATION_CRL_INFO struct
        cbSize DWORD ?
        pBaseCrlContext PCCRL_CONTEXT ?
        pDeltaCrlContext PCCRL_CONTEXT ?
        ; When revoked, points to entry in either of the above CRL contexts.
        ; Don't free.
        pCrlEntry PCRL_ENTRY ?
        fDeltaCrlEntry DWORD ?
        ; TRUE if in pDeltaCrlContext
      CERT_REVOCATION_CRL_INFO ends
      _CERT_REVOCATION_CRL_INFO typedef CERT_REVOCATION_CRL_INFO
      PCERT_REVOCATION_CRL_INFO typedef ptr CERT_REVOCATION_CRL_INFO
      ;+-------------------------------------------------------------------------
      ;  This data structure is optionally pointed to by the pChainPara field
      ;  in the CERT_REVOCATION_PARA and CRYPT_GET_TIME_VALID_OBJECT_EXTRA_INFO
      ;  data structures.
      ;  Its struct definition follows the CertGetCertificateChain() API
      ;  definition below.
      ;--------------------------------------------------------------------------
      CERT_REVOCATION_CHAIN_PARA typedef _CERT_REVOCATION_CHAIN_PARA
      PCERT_REVOCATION_CHAIN_PARA typedef ptr _CERT_REVOCATION_CHAIN_PARA
      ;+-------------------------------------------------------------------------
      ;  The following data structure may be passed to CertVerifyRevocation to
      ;  assist in finding the issuer of the context to be verified.
      ;  When pIssuerCert is specified, pIssuerCert is the issuer of
      ;  rgpvContext[cContext - 1].
      ;  When cCertStore and rgCertStore are specified, these stores may contain
      ;  an issuer certificate.
      ;  When hCrlStore is specified then a handler which uses CRLs can search this
      ;  store for them
      ;  When pftTimeToUse is specified then the handler (if possible) must determine
      ;  revocation status relative to the time given otherwise the answer may be
      ;  independent of time or relative to current time
      ;--------------------------------------------------------------------------
      CERT_REVOCATION_PARA struct
        cbSize DWORD ?
        pIssuerCert PCCERT_CONTEXT ?
        cCertStore DWORD ?
        rgCertStore POINTER ?
        hCrlStore HCERTSTORE ?
        pftTimeToUse LPFILETIME ?
        ifdef CERT_REVOCATION_PARA_HAS_EXTRA_FIELDS
          ; Note, if you #define CERT_REVOCATION_PARA_HAS_EXTRA_FIELDS, then, you
          ; must zero all unused fields in this data structure.
          ; More fields could be added in a future release.
          ; 0 uses revocation handler's default timeout.
          dwUrlRetrievalTimeout DWORD ?
          ; milliseconds
          ; When set, checks and attempts to retrieve a CRL where
          ; ThisUpdate >= (CurrentTime - dwFreshnessTime). Otherwise, defaults
          ; to using the CRL's NextUpdate.
          fCheckFreshnessTime DWORD ?
          dwFreshnessTime DWORD ?
          ; seconds
          ; If NULL, revocation handler gets the current time
          pftCurrentTime LPFILETIME ?
          ; If nonNULL, a CRL revocation type handler updates with the base and
          ; possibly the delta CRL used. Note, *pCrlInfo must be initialized
          ; by the caller. Any nonNULL CRL contexts are freed. Any updated
          ; CRL contexts must be freed by the caller.
          ; The CRL info is only applicable to the last context checked. If
          ; interested in this information, then, CertVerifyRevocation should be
          ; called with cContext = 1.
          pCrlInfo PCERT_REVOCATION_CRL_INFO ?
          ; If nonNULL, any cached information before this time is considered
          ; time invalid and forces a wire retrieval.
          pftCacheResync LPFILETIME ?
          ; If nonNULL, CertGetCertificateChain() parameters used by the caller.
          ; Enables independent OCSP signer certificate chain verification.
          pChainPara PCERT_REVOCATION_CHAIN_PARA ?
        endif
      CERT_REVOCATION_PARA ends
      _CERT_REVOCATION_PARA typedef CERT_REVOCATION_PARA
      PCERT_REVOCATION_PARA typedef ptr CERT_REVOCATION_PARA
      ;+-------------------------------------------------------------------------
      ;  The following data structure is returned by CertVerifyRevocation to
      ;  specify the status of the revoked or unchecked context. Review the
      ;  following CertVerifyRevocation comments for details.
      ;  Upon input to CertVerifyRevocation, cbSize must be set to a size
      ;  >= (offsetof(CERT_REVOCATION_STATUS, dwReason) + sizeof(DWORD) ).
      ;  Otherwise, CertVerifyRevocation returns FALSE and sets LastError to
      ;  E_INVALIDARG.
      ;  Upon input to the installed or registered CRYPT_OID_VERIFY_REVOCATION_FUNC
      ;  functions, the dwIndex, dwError and dwReason have been zero'ed.
      ;  If present, fHasFreshnessTime and dwFreshnessTime have been zero'ed.
      ;--------------------------------------------------------------------------
      CERT_REVOCATION_STATUS struct
        cbSize DWORD ?
        dwIndex DWORD ?
        dwError DWORD ?
        dwReason DWORD ?
        ; Depending on cbSize, the following fields may optionally be returned.
        ; The Freshness time is only applicable to the last context checked. If
        ; interested in this information, then, CertVerifyRevocation should be
        ; called with cContext = 1.
        ; fHasFreshnessTime is only set if we are able to retrieve revocation
        ; information. For a CRL its CurrentTime - ThisUpdate.
        fHasFreshnessTime DWORD ?
        dwFreshnessTime DWORD ?
        ; seconds
      CERT_REVOCATION_STATUS ends
      _CERT_REVOCATION_STATUS typedef CERT_REVOCATION_STATUS
      PCERT_REVOCATION_STATUS typedef ptr CERT_REVOCATION_STATUS
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)*
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_PHONE_RESTRICTED or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      ;+-------------------------------------------------------------------------
      ;  Verifies the array of contexts for revocation. The dwRevType parameter
      ;  indicates the type of the context data structure passed in rgpvContext.
      ;  Currently only the revocation of certificates is defined.
      ;  If the CERT_VERIFY_REV_CHAIN_FLAG flag is set, then, CertVerifyRevocation
      ;  is verifying a chain of certs where, rgpvContext[i + 1] is the issuer
      ;  of rgpvContext[i]. Otherwise, CertVerifyRevocation makes no assumptions
      ;  about the order of the contexts.
      ;  To assist in finding the issuer, the pRevPara may optionally be set. See
      ;  the CERT_REVOCATION_PARA data structure for details.
      ;  The contexts must contain enough information to allow the
      ;  installable or registered revocation DLLs to find the revocation server. For
      ;  certificates, this information would normally be conveyed in an
      ;  extension such as the IETF's AuthorityInfoAccess extension.
      ;  CertVerifyRevocation returns TRUE if all of the contexts were successfully
      ;  checked and none were revoked. Otherwise, returns FALSE and updates the
      ;  returned pRevStatus data structure as follows:
      ;    dwIndex
      ;      Index of the first context that was revoked or unable to
      ;      be checked for revocation
      ;    dwError
      ;      Error status. LastError is also set to this error status.
      ;      dwError can be set to one of the following error codes defined
      ;      in winerror.h:
      ;        ERROR_SUCCESS - good context
      ;        CRYPT_E_REVOKED - context was revoked. dwReason contains the
      ;           reason for revocation
      ;        CRYPT_E_REVOCATION_OFFLINE - unable to connect to the
      ;           revocation server
      ;        CRYPT_E_NOT_IN_REVOCATION_DATABASE - the context to be checked
      ;           was not found in the revocation server's database.
      ;        CRYPT_E_NO_REVOCATION_CHECK - the called revocation function
      ;           wasn't able to do a revocation check on the context
      ;        CRYPT_E_NO_REVOCATION_DLL - no installed or registered Dll was
      ;           found to verify revocation
      ;    dwReason
      ;      The dwReason is currently only set for CRYPT_E_REVOKED and contains
      ;      the reason why the context was revoked. May be one of the following
      ;      CRL reasons defined by the CRL Reason Code extension ("2.5.29.21")
      ;          CRL_REASON_UNSPECIFIED              0
      ;          CRL_REASON_KEY_COMPROMISE           1
      ;          CRL_REASON_CA_COMPROMISE            2
      ;          CRL_REASON_AFFILIATION_CHANGED      3
      ;          CRL_REASON_SUPERSEDED               4
      ;          CRL_REASON_CESSATION_OF_OPERATION   5
      ;          CRL_REASON_CERTIFICATE_HOLD         6
      ;  For each entry in rgpvContext, CertVerifyRevocation iterates
      ;  through the CRYPT_OID_VERIFY_REVOCATION_FUNC
      ;  function set's list of installed DEFAULT functions.
      ;  CryptGetDefaultOIDFunctionAddress is called with pwszDll = NULL. If no
      ;  installed functions are found capable of doing the revocation verification,
      ;  CryptVerifyRevocation iterates through CRYPT_OID_VERIFY_REVOCATION_FUNC's
      ;  list of registered DEFAULT Dlls. CryptGetDefaultOIDDllList is called to
      ;  get the list. CryptGetDefaultOIDFunctionAddress is called to load the Dll.
      ;  The called functions have the same signature as CertVerifyRevocation. A
      ;  called function returns TRUE if it was able to successfully check all of
      ;  the contexts and none were revoked. Otherwise, the called function returns
      ;  FALSE and updates pRevStatus. dwIndex is set to the index of
      ;  the first context that was found to be revoked or unable to be checked.
      ;  dwError and LastError are updated. For CRYPT_E_REVOKED, dwReason
      ;  is updated. Upon input to the called function, dwIndex, dwError and
      ;  dwReason have been zero'ed. cbSize has been checked to be >=
      ;  sizeof(CERT_REVOCATION_STATUS).
      ;  If the called function returns FALSE, and dwError isn't set to
      ;  CRYPT_E_REVOKED, then, CertVerifyRevocation either continues on to the
      ;  next DLL in the list for a returned dwIndex of 0 or for a returned
      ;  dwIndex > 0, restarts the process of finding a verify function by
      ;  advancing the start of the context array to the returned dwIndex and
      ;  decrementing the count of remaining contexts.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertVerifyRevocation, WIN_STD_CALL_CONV,, <:DWORD, :DWORD, :DWORD, :ptr PVOID, :DWORD, :PCERT_REVOCATION_PARA, :PCERT_REVOCATION_STATUS>, 28
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP|WINAPI_PARTITION_PHONE_RESTRICTED | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      ;+-------------------------------------------------------------------------
      ;  Revocation types
      ;--------------------------------------------------------------------------
      CERT_CONTEXT_REVOCATION_TYPE equ 1
      ;+-------------------------------------------------------------------------
      ;  When the following flag is set, rgpvContext[] consists of a chain
      ;  of certificates, where rgpvContext[i + 1] is the issuer of rgpvContext[i].
      ;--------------------------------------------------------------------------
      CERT_VERIFY_REV_CHAIN_FLAG equ 00000001h
      ;+-------------------------------------------------------------------------
      ; CERT_VERIFY_CACHE_ONLY_BASED_REVOCATION prevents the revocation handler from
      ; accessing any network based resources for revocation checking
      ;--------------------------------------------------------------------------
      CERT_VERIFY_CACHE_ONLY_BASED_REVOCATION equ 00000002h
      ;+-------------------------------------------------------------------------
      ;  By default, the dwUrlRetrievalTimeout in pRevPara is the timeout used
      ;  for each URL wire retrieval. When the following flag is set,
      ;  dwUrlRetrievalTimeout is the accumulative timeout across all URL wire
      ;  retrievals.
      ;--------------------------------------------------------------------------
      CERT_VERIFY_REV_ACCUMULATIVE_TIMEOUT_FLAG equ 00000004h
      ;+-------------------------------------------------------------------------
      ;  When the following flag is set, only OCSP responses are used for
      ;  doing revocation checking. If the certificate doesn't have any
      ;  OCSP AIA URLs, dwError is set to CRYPT_E_NOT_IN_REVOCATION_DATABASE.
      ;--------------------------------------------------------------------------
      CERT_VERIFY_REV_SERVER_OCSP_FLAG equ 00000008h
      ;+-------------------------------------------------------------------------
      ;  When the following flag is set, only the OCSP AIA URL is used if
      ;  present in the subject. If the subject doesn't have an OCSP AIA URL, then,
      ;  the CDP URLs are used.
      ;--------------------------------------------------------------------------
      CERT_VERIFY_REV_NO_OCSP_FAILOVER_TO_CRL_FLAG equ 00000010h
      ;+-------------------------------------------------------------------------
      ;  When the following flag is set, only wire retrieval for OCSP responses.
      ;--------------------------------------------------------------------------
      CERT_VERIFY_REV_SERVER_OCSP_WIRE_ONLY_FLAG equ 00000020h
      ;+-------------------------------------------------------------------------
      ;  CERT_CONTEXT_REVOCATION_TYPE
      ;  pvContext points to a const CERT_CONTEXT.
      ;--------------------------------------------------------------------------
      ;+=========================================================================
      ;  Certificate Helper APIs
      ;==========================================================================
      ;+-------------------------------------------------------------------------
      ;  Compare two multiple byte integer blobs to see if they are identical.
      ;  Before doing the comparison, leading zero bytes are removed from a
      ;  positive number and leading 0xFF bytes are removed from a negative
      ;  number.
      ;  The multiple byte integers are treated as Little Endian. pbData[0] is the
      ;  least significant byte and pbData[cbData - 1] is the most significant
      ;  byte.
      ;  Returns TRUE if the integer blobs are identical after removing leading
      ;  0 or 0xFF bytes.
      ;--------------------------------------------------------------------------
      CertCompareIntegerBlob proto WIN_STD_CALL_CONV :PCRYPT_INTEGER_BLOB, :PCRYPT_INTEGER_BLOB
      ;+-------------------------------------------------------------------------
      ;  Compare two certificates to see if they are identical.
      ;  Since a certificate is uniquely identified by its Issuer and SerialNumber,
      ;  these are the only fields needing to be compared.
      ;  Returns TRUE if the certificates are identical.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertCompareCertificate, WIN_STD_CALL_CONV,, <:DWORD, :PCERT_INFO, :PCERT_INFO>, 12
      ;+-------------------------------------------------------------------------
      ;  Compare two certificate names to see if they are identical.
      ;  Returns TRUE if the names are identical.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertCompareCertificateName, WIN_STD_CALL_CONV,, <:DWORD, :PCERT_NAME_BLOB, :PCERT_NAME_BLOB>, 12
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)*
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_PHONE_RESTRICTED or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      ;+-------------------------------------------------------------------------
      ;  Compare the attributes in the certificate name with the specified
      ;  Relative Distinguished Name's (CERT_RDN) array of attributes.
      ;  The comparison iterates through the CERT_RDN attributes and looks for an
      ;  attribute match in any of the certificate name's RDNs.
      ;  Returns TRUE if all the attributes are found and match.
      ;  The CERT_RDN_ATTR fields can have the following special values:
      ;    pszObjId == NULL              - ignore the attribute object identifier
      ;    dwValueType == RDN_ANY_TYPE   - ignore the value type
      ;  CERT_CASE_INSENSITIVE_IS_RDN_ATTRS_FLAG should be set to do
      ;  a case insensitive match. Otherwise, defaults to an exact, case sensitive
      ;  match.
      ;  CERT_UNICODE_IS_RDN_ATTRS_FLAG should be set if the pRDN was initialized
      ;  with unicode strings as for CryptEncodeObject(X509_UNICODE_NAME).
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertIsRDNAttrsInCertificateName, WIN_STD_CALL_CONV,, <:DWORD, :DWORD, :PCERT_NAME_BLOB, :PCERT_RDN>, 16
      CERT_UNICODE_IS_RDN_ATTRS_FLAG equ 1h
      CERT_CASE_INSENSITIVE_IS_RDN_ATTRS_FLAG equ 2h
      ;+-------------------------------------------------------------------------
      ;  Compare two public keys to see if they are identical.
      ;  Returns TRUE if the keys are identical.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertComparePublicKeyInfo, WIN_STD_CALL_CONV,, <:DWORD, :PCERT_PUBLIC_KEY_INFO, :PCERT_PUBLIC_KEY_INFO>, 12
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP|WINAPI_PARTITION_PHONE_RESTRICTED | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)*
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      ;+-------------------------------------------------------------------------
      ;  Get the public/private key's bit length.
      ;  Returns 0 if unable to determine the key's length.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertGetPublicKeyLength, WIN_STD_CALL_CONV,, <:DWORD, :PCERT_PUBLIC_KEY_INFO>, 8
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)*
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_PHONE_RESTRICTED or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      ;+-------------------------------------------------------------------------
      ;  Verify the signature of a subject certificate or a CRL using the
      ;  public key info
      ;  Returns TRUE for a valid signature.
      ;  hCryptProv specifies the crypto provider to use to verify the signature.
      ;  It doesn't need to use a private key.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CryptVerifyCertificateSignature, WIN_STD_CALL_CONV,, <:HCRYPTPROV_LEGACY, :DWORD, :ptr BYTE, :DWORD, :PCERT_PUBLIC_KEY_INFO>, 20
      ;+-------------------------------------------------------------------------
      ;  Verify the signature of a subject certificate, CRL, certificate request
      ;  or keygen request using the issuer's public key.
      ;  Returns TRUE for a valid signature.
      ;  The subject can be an encoded blob or a context for a certificate or CRL.
      ;  For a subject certificate context, if the certificate is missing
      ;  inheritable PublicKey Algorithm Parameters, the context's
      ;  CERT_PUBKEY_ALG_PARA_PROP_ID is updated with the issuer's public key
      ;  algorithm parameters for a valid signature.
      ;  The issuer can be a pointer to a CERT_PUBLIC_KEY_INFO, certificate
      ;  context or a chain context.
      ;  hCryptProv specifies the crypto provider to use to verify the signature.
      ;  Its private key isn't used. If hCryptProv is NULL, a default
      ;  provider is picked according to the PublicKey Algorithm OID.
      ;  If the signature algorithm is a hashing algorithm, then, the
      ;  signature is expected to contain the hash octets. Only dwIssuerType
      ;  of CRYPT_VERIFY_CERT_SIGN_ISSUER_NULL may be specified
      ;  to verify this no signature case. If any other dwIssuerType is
      ;  specified, the verify will fail with LastError set to E_INVALIDARG.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CryptVerifyCertificateSignatureEx, WIN_STD_CALL_CONV,, <:HCRYPTPROV_LEGACY, :DWORD, :DWORD, :ptr, :DWORD, :ptr, :DWORD, :ptr>, 32
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP|WINAPI_PARTITION_PHONE_RESTRICTED | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      ; Subject Types
      CRYPT_VERIFY_CERT_SIGN_SUBJECT_BLOB equ 1
      ; pvSubject :: PCRYPT_DATA_BLOB
      CRYPT_VERIFY_CERT_SIGN_SUBJECT_CERT equ 2
      ; pvSubject :: PCCERT_CONTEXT
      CRYPT_VERIFY_CERT_SIGN_SUBJECT_CRL equ 3
      ; pvSubject :: PCCRL_CONTEXT
      CRYPT_VERIFY_CERT_SIGN_SUBJECT_OCSP_BASIC_SIGNED_RESPONSE equ 4
      ; pvSubject :: POCSP_BASIC_SIGNED_RESPONSE_INFO
      ; Issuer Types
      CRYPT_VERIFY_CERT_SIGN_ISSUER_PUBKEY equ 1
      ; pvIssuer :: PCERT_PUBLIC_KEY_INFO
      CRYPT_VERIFY_CERT_SIGN_ISSUER_CERT equ 2
      ; pvIssuer :: PCCERT_CONTEXT
      CRYPT_VERIFY_CERT_SIGN_ISSUER_CHAIN equ 3
      ; pvIssuer :: PCCERT_CHAIN_CONTEXT
      CRYPT_VERIFY_CERT_SIGN_ISSUER_NULL equ 4
      ; pvIssuer :: NULL
      ; If the following flag is set and a MD2 or MD4 signature hash is
      ; detected, then, this API fails and sets LastError to NTE_BAD_ALGID
      ; This API first does the signature verification check. If the signature 
      ; verification succeeds and the following flag is set, it then checks for a
      ; MD2 or MD4 hash. For a MD2 or MD4 hash FALSE is returned with LastError set
      ; to NTE_BAD_ALGID. This error will only be set if MD2 or MD4 is detected.
      ; If NTE_BAD_ALGID is returned, then, the MD2 or MD4 signature verified.
      ; This allows the caller to conditionally allow MD2 or MD4.
      CRYPT_VERIFY_CERT_SIGN_DISABLE_MD2_MD4_FLAG equ 00000001h
      ; When the following flag is set, the strong signature properties are
      ; also set on the Subject. Only applicable to the
      ; CRYPT_VERIFY_CERT_SIGN_SUBJECT_CRL Subject Type.
      ;  The strong signature properties are:
      ;    - CERT_SIGN_HASH_CNG_ALG_PROP_ID
      ;    - CERT_ISSUER_PUB_KEY_BIT_LENGTH_PROP_ID
      CRYPT_VERIFY_CERT_SIGN_SET_STRONG_PROPERTIES_FLAG equ 00000002h
      ; When the following flag is set, the strong signature properties are also
      ; returned. Only applicable to the
      ; CRYPT_VERIFY_CERT_SIGN_SUBJECT_OCSP_BASIC_SIGNED_RESPONSE Subject Type.
      ; pvExtra points to a pointer to CRYPT_VERIFY_CERT_SIGN_VERIFY_PROPERTIES_INFO.
      ;  ie, PCRYPT_VERIFY_CERT_SIGN_STRONG_PROPERTIES_INFO *ppStrongPropertiesInfo.
      ; The returned pointer is freed via CryptMemFree().
      ;  The strong signature properties are:
      ;    - CERT_SIGN_HASH_CNG_ALG_PROP_ID
      ;    - CERT_ISSUER_PUB_KEY_BIT_LENGTH_PROP_ID
      CRYPT_VERIFY_CERT_SIGN_RETURN_STRONG_PROPERTIES_FLAG equ 00000004h
      CRYPT_VERIFY_CERT_SIGN_STRONG_PROPERTIES_INFO struct
        ; CERT_SIGN_HASH_CNG_ALG_PROP_ID
        CertSignHashCNGAlgPropData CRYPT_DATA_BLOB <>
        ; CERT_ISSUER_PUB_KEY_BIT_LENGTH_PROP_ID
        CertIssuerPubKeyBitLengthPropData CRYPT_DATA_BLOB <>
      CRYPT_VERIFY_CERT_SIGN_STRONG_PROPERTIES_INFO ends
      _CRYPT_VERIFY_CERT_SIGN_STRONG_PROPERTIES_INFO typedef CRYPT_VERIFY_CERT_SIGN_STRONG_PROPERTIES_INFO
      PCRYPT_VERIFY_CERT_SIGN_STRONG_PROPERTIES_INFO typedef ptr CRYPT_VERIFY_CERT_SIGN_STRONG_PROPERTIES_INFO
      CRYPT_VERIFY_CERT_SIGN_CHECK_WEAK_HASH_FLAG equ 00000008h
      CRYPT_VERIFY_CERT_SIGN_WEAK_HASH_INFO struct
        cCNGHashAlgid DWORD ?
        rgpwszCNGHashAlgid POINTER ?
        ; If not weak, dwWeakIndex is set to cCNGHashAlgid. Otherwise,
        ; index into the above array.
        dwWeakIndex DWORD ?
      CRYPT_VERIFY_CERT_SIGN_WEAK_HASH_INFO ends
      _CRYPT_VERIFY_CERT_SIGN_WEAK_HASH_INFO typedef CRYPT_VERIFY_CERT_SIGN_WEAK_HASH_INFO
      PCRYPT_VERIFY_CERT_SIGN_WEAK_HASH_INFO typedef ptr CRYPT_VERIFY_CERT_SIGN_WEAK_HASH_INFO
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)*
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_PHONE_RESTRICTED or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      ;+-------------------------------------------------------------------------
      ;  Checks if the specified hash algorithm and the signing certificate's
      ;  public key algorithm can be used to do a strong signature.
      ;  Returns TRUE if the hash algorithm and certificate public key algorithm
      ;  satisfy the strong signature requirements.
      ;  pwszCNGHashAlgid is the CNG hash algorithm identifier string, for example,
      ;  BCRYPT_SHA256_ALGORITHM (L"SHA256")
      ;  The CNG hash algorithm identifier string can be empty (L"") to only check
      ;  if the certificate's public key is strong.
      ;  The SigningCert can be NULL to only check if the CNG hash algorithm is
      ;  strong.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertIsStrongHashToSign, WIN_STD_CALL_CONV,, <:PCCERT_STRONG_SIGN_PARA, :LPCWSTR, :PCCERT_CONTEXT>, 12
      ;+-------------------------------------------------------------------------
      ;  Compute the hash of the "to be signed" information in the encoded
      ;  signed content (CERT_SIGNED_CONTENT_INFO).
      ;  hCryptProv specifies the crypto provider to use to compute the hash.
      ;  It doesn't need to use a private key.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CryptHashToBeSigned, WIN_STD_CALL_CONV,, <:HCRYPTPROV_LEGACY, :DWORD, :ptr BYTE, :DWORD, :ptr BYTE, :ptr DWORD>, 24
      ;+-------------------------------------------------------------------------
      ;  Hash the encoded content.
      ;  hCryptProv specifies the crypto provider to use to compute the hash.
      ;  It doesn't need to use a private key.
      ;  Algid specifies the CAPI hash algorithm to use. If Algid is 0, then, the
      ;  default hash algorithm (currently SHA1) is used.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CryptHashCertificate, WIN_STD_CALL_CONV,, <:HCRYPTPROV_LEGACY, :ALG_ID, :DWORD, :ptr BYTE, :DWORD, :ptr BYTE, :ptr DWORD>, 28
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP|WINAPI_PARTITION_PHONE_RESTRICTED | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      if (NTDDI_VERSION ge NTDDI_VISTA)
        ;+-------------------------------------------------------------------------
        ;  Hash the encoded content using the CNG hash algorithm provider.
        ;--------------------------------------------------------------------------
        @DefProto DllImport, CryptHashCertificate2, WIN_STD_CALL_CONV,, <:LPCWSTR, :DWORD, :ptr, :ptr BYTE, :DWORD, :ptr BYTE, :ptr DWORD>, 28
      endif
      ; (NTDDI_VERSION >= NTDDI_VISTA)
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)*
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_PHONE_RESTRICTED or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      ;+-------------------------------------------------------------------------
      ;  Sign the "to be signed" information in the encoded signed content.
      ;  hCryptProvOrNCryptKey specifies the crypto provider to use to do the
      ;  signature.  It uses the specified private key.
      ;  If the SignatureAlgorithm is a hash algorithm, then, the signature
      ;  contains the hash octets. A private key isn't used to encrypt the hash.
      ;  dwKeySpec isn't used and hCryptProvOrNCryptKey can be NULL where an
      ;  appropriate default provider will be used for hashing.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CryptSignCertificate, WIN_STD_CALL_CONV,, <ifdef CMSG_SIGNER_ENCODE_INFO_HAS_IUM_FIELDS
        :BCRYPT_KEY_HANDLE,else
         :HCRYPTPROV_OR_NCRYPT_KEY_HANDLE,endif
       :DWORD, :DWORD, :ptr BYTE, :DWORD, :PCRYPT_ALGORITHM_IDENTIFIER, :ptr, :ptr BYTE, :ptr DWORD>, 40
      ; not applicable for NCRYPT_KEY_HANDLE
      ;+-------------------------------------------------------------------------
      ;  Encode the "to be signed" information. Sign the encoded "to be signed".
      ;  Encode the "to be signed" and the signature.
      ;  hCryptProv specifies the crypto provider to use to do the signature.
      ;  It uses the specified private key.
      ;  If the SignatureAlgorithm is a hash algorithm, then, the signature
      ;  contains the hash octets. A private key isn't used to encrypt the hash.
      ;  dwKeySpec isn't used and hCryptProv can be NULL where an appropriate
      ;  default provider will be used for hashing.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CryptSignAndEncodeCertificate, WIN_STD_CALL_CONV,, <ifdef CMSG_SIGNER_ENCODE_INFO_HAS_IUM_FIELDS
        :BCRYPT_KEY_HANDLE,else
         :HCRYPTPROV_OR_NCRYPT_KEY_HANDLE,endif
       :DWORD, :DWORD, :LPCSTR, :ptr, :PCRYPT_ALGORITHM_IDENTIFIER, :ptr, :ptr BYTE, :ptr DWORD>, 40
      ; "to be signed"
      ;+-------------------------------------------------------------------------
      ;  Certificate and CryptMsg encoded signature OID installable functions
      ;--------------------------------------------------------------------------
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP|WINAPI_PARTITION_PHONE_RESTRICTED | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      ; The dwCertEncodingType and pSignatureAlgorithm->pszObjId are used
      ; to call the signature OID installable functions.
      ; If the OID installable function doesn't support the signature,
      ; it should return FALSE with LastError set to ERROR_NOT_SUPPORTED.
      ; Called if the signature has encoded parameters. Returns the CNG
      ; hash algorithm identifier string. Optionally returns the decoded
      ; signature parameters passed to either the SignAndEncodeHash or
      ; VerifyEncodedSignature OID installable function.
      ; Returned allocated parameters are freed via LocalFree().
      CRYPT_OID_EXTRACT_ENCODED_SIGNATURE_PARAMETERS_FUNC equ <"CryptDllExtractEncodedSignatureParameters">
      ; LocalFree()
      ; LocalFree()
      TYPE_PFN_CRYPT_EXTRACT_ENCODED_SIGNATURE_PARAMETERS_FUNC typedef proto WIN_STD_CALL_CONV :DWORD, :PCRYPT_ALGORITHM_IDENTIFIER, :ptr ptr, :ptr LPWSTR
      PFN_CRYPT_EXTRACT_ENCODED_SIGNATURE_PARAMETERS_FUNC typedef ptr TYPE_PFN_CRYPT_EXTRACT_ENCODED_SIGNATURE_PARAMETERS_FUNC

      ; Called to sign the computed hash and encode it.
      CRYPT_OID_SIGN_AND_ENCODE_HASH_FUNC equ <"CryptDllSignAndEncodeHash">
      ; obtained from signature OID
      TYPE_PFN_CRYPT_SIGN_AND_ENCODE_HASH_FUNC typedef proto WIN_STD_CALL_CONV :NCRYPT_KEY_HANDLE, :DWORD, :PCRYPT_ALGORITHM_IDENTIFIER, :ptr, :LPCWSTR, :LPCWSTR, :ptr BYTE, :DWORD, :ptr BYTE, :ptr DWORD
      PFN_CRYPT_SIGN_AND_ENCODE_HASH_FUNC typedef ptr TYPE_PFN_CRYPT_SIGN_AND_ENCODE_HASH_FUNC

      ; Called to decode and decrypt the encoded signature and compare it with the
      ; computed hash.
      CRYPT_OID_VERIFY_ENCODED_SIGNATURE_FUNC equ <"CryptDllVerifyEncodedSignature">
      ; obtained from signature OID
      TYPE_PFN_CRYPT_VERIFY_ENCODED_SIGNATURE_FUNC typedef proto WIN_STD_CALL_CONV :DWORD, :PCERT_PUBLIC_KEY_INFO, :PCRYPT_ALGORITHM_IDENTIFIER, :ptr, :LPCWSTR, :LPCWSTR, :ptr BYTE, :DWORD, :ptr BYTE, :DWORD
      PFN_CRYPT_VERIFY_ENCODED_SIGNATURE_FUNC typedef ptr TYPE_PFN_CRYPT_VERIFY_ENCODED_SIGNATURE_FUNC

      ;+-------------------------------------------------------------------------
      ;  Verify the time validity of a certificate.
      ;  Returns -1 if before NotBefore, +1 if after NotAfter and otherwise 0 for
      ;  a valid certificate
      ;  If pTimeToVerify is NULL, uses the current time.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertVerifyTimeValidity, WIN_STD_CALL_CONV,, <:LPFILETIME, :PCERT_INFO>, 8
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)*
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_PHONE_RESTRICTED or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      ;+-------------------------------------------------------------------------
      ;  Verify the time validity of a CRL.
      ;  Returns -1 if before ThisUpdate, +1 if after NextUpdate and otherwise 0 for
      ;  a valid CRL
      ;  If pTimeToVerify is NULL, uses the current time.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertVerifyCRLTimeValidity, WIN_STD_CALL_CONV,, <:LPFILETIME, :PCRL_INFO>, 8
      ;+-------------------------------------------------------------------------
      ;  Verify that the subject's time validity nests within the issuer's time
      ;  validity.
      ;  Returns TRUE if it nests. Otherwise, returns FALSE.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertVerifyValidityNesting, WIN_STD_CALL_CONV,, <:PCERT_INFO, :PCERT_INFO>, 8
      ;+-------------------------------------------------------------------------
      ;  Verify that the subject certificate isn't on its issuer CRL.
      ;  Returns true if the certificate isn't on the CRL.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertVerifyCRLRevocation, WIN_STD_CALL_CONV,, <:DWORD, :PCERT_INFO, :DWORD, :ptr PCRL_INFO>, 16
      ; fields are used
      ;+-------------------------------------------------------------------------
      ;  Convert the CAPI AlgId to the ASN.1 Object Identifier string
      ;  Returns NULL if there isn't an ObjId corresponding to the AlgId.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertAlgIdToOID, WIN_STD_CALL_CONV,, <:DWORD>, 4
      ;+-------------------------------------------------------------------------
      ;  Convert the ASN.1 Object Identifier string to the CAPI AlgId.
      ;  Returns 0 if there isn't an AlgId corresponding to the ObjId.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertOIDToAlgId, WIN_STD_CALL_CONV,, <:LPCSTR>, 4
      ;+-------------------------------------------------------------------------
      ;  Find an extension identified by its Object Identifier.
      ;  If found, returns pointer to the extension. Otherwise, returns NULL.
      ;--------------------------------------------------------------------------
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP|WINAPI_PARTITION_PHONE_RESTRICTED | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      @DefProto DllImport, CertFindExtension, WIN_STD_CALL_CONV,, <:LPCSTR, :DWORD, :ptr CERT_EXTENSION>, 12
      ;+-------------------------------------------------------------------------
      ;  Find the first attribute identified by its Object Identifier.
      ;  If found, returns pointer to the attribute. Otherwise, returns NULL.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertFindAttribute, WIN_STD_CALL_CONV,, <:LPCSTR, :DWORD, :ptr CRYPT_ATTRIBUTE>, 12
      ;+-------------------------------------------------------------------------
      ;  Find the first CERT_RDN attribute identified by its Object Identifier in
      ;  the name's list of Relative Distinguished Names.
      ;  If found, returns pointer to the attribute. Otherwise, returns NULL.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertFindRDNAttr, WIN_STD_CALL_CONV,, <:LPCSTR, :PCERT_NAME_INFO>, 8
      ;+-------------------------------------------------------------------------
      ;  Get the intended key usage bytes from the certificate.
      ;  If the certificate doesn't have any intended key usage bytes, returns FALSE
      ;  and *pbKeyUsage is zeroed. Otherwise, returns TRUE and up through
      ;  cbKeyUsage bytes are copied into *pbKeyUsage. Any remaining uncopied
      ;  bytes are zeroed.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertGetIntendedKeyUsage, WIN_STD_CALL_CONV,, <:DWORD, :PCERT_INFO, :ptr BYTE, :DWORD>, 16
      HCRYPTDEFAULTCONTEXT typedef ptr
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)*
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_PHONE_RESTRICTED or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      ;+-------------------------------------------------------------------------
      ;  Install a previously CryptAcquiredContext'ed HCRYPTPROV to be used as
      ;  a default context.
      ;  dwDefaultType and pvDefaultPara specify where the default context is used.
      ;  For example, install the HCRYPTPROV to be used to verify certificate's
      ;  having szOID_OIWSEC_md5RSA signatures.
      ;  By default, the installed HCRYPTPROV is only applicable to the current
      ;  thread. Set CRYPT_DEFAULT_CONTEXT_PROCESS_FLAG to allow the HCRYPTPROV
      ;  to be used by all threads in the current process.
      ;  For a successful install, TRUE is returned and *phDefaultContext is
      ;  updated with the HANDLE to be passed to CryptUninstallDefaultContext.
      ;  The installed HCRYPTPROVs are stack ordered (the last installed
      ;  HCRYPTPROV is checked first). All thread installed HCRYPTPROVs are
      ;  checked before any process HCRYPTPROVs.
      ;  The installed HCRYPTPROV remains available for default usage until
      ;  CryptUninstallDefaultContext is called or the thread or process exits.
      ;  If CRYPT_DEFAULT_CONTEXT_AUTO_RELEASE_FLAG is set, then, the HCRYPTPROV
      ;  is CryptReleaseContext'ed at thread or process exit. However,
      ;  not CryptReleaseContext'ed if CryptUninstallDefaultContext is
      ;  called.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CryptInstallDefaultContext, WIN_STD_CALL_CONV,, <:HCRYPTPROV, :DWORD, :ptr, :DWORD, :ptr, :ptr HCRYPTDEFAULTCONTEXT>, 24
      ; dwFlags
      CRYPT_DEFAULT_CONTEXT_AUTO_RELEASE_FLAG equ 00000001h
      CRYPT_DEFAULT_CONTEXT_PROCESS_FLAG equ 00000002h
      ; List of dwDefaultType's
      CRYPT_DEFAULT_CONTEXT_CERT_SIGN_OID equ 1
      CRYPT_DEFAULT_CONTEXT_MULTI_CERT_SIGN_OID equ 2
      ;+-------------------------------------------------------------------------
      ;  CRYPT_DEFAULT_CONTEXT_CERT_SIGN_OID
      ;  Install a default HCRYPTPROV used to verify a certificate
      ;  signature. pvDefaultPara points to the szOID of the certificate
      ;  signature algorithm, for example, szOID_OIWSEC_md5RSA. If
      ;  pvDefaultPara is NULL, then, the HCRYPTPROV is used to verify all
      ;  certificate signatures. Note, pvDefaultPara can't be NULL when
      ;  CRYPT_DEFAULT_CONTEXT_PROCESS_FLAG is set.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  CRYPT_DEFAULT_CONTEXT_MULTI_CERT_SIGN_OID
      ;  Same as CRYPT_DEFAULT_CONTEXT_CERT_SIGN_OID. However, the default
      ;  HCRYPTPROV is to be used for multiple signature szOIDs. pvDefaultPara
      ;  points to a CRYPT_DEFAULT_CONTEXT_MULTI_OID_PARA structure containing
      ;  an array of szOID pointers.
      ;--------------------------------------------------------------------------
      CRYPT_DEFAULT_CONTEXT_MULTI_OID_PARA struct
        cOID DWORD ?
        rgpszOID POINTER ?
      CRYPT_DEFAULT_CONTEXT_MULTI_OID_PARA ends
      _CRYPT_DEFAULT_CONTEXT_MULTI_OID_PARA typedef CRYPT_DEFAULT_CONTEXT_MULTI_OID_PARA
      PCRYPT_DEFAULT_CONTEXT_MULTI_OID_PARA typedef ptr CRYPT_DEFAULT_CONTEXT_MULTI_OID_PARA
      ;+-------------------------------------------------------------------------
      ;  Uninstall a default context previously installed by
      ;  CryptInstallDefaultContext.
      ;  For a default context installed with CRYPT_DEFAULT_CONTEXT_PROCESS_FLAG
      ;  set, if any other threads are currently using this context,
      ;  this function will block until they finish.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CryptUninstallDefaultContext, WIN_STD_CALL_CONV,, <:HCRYPTDEFAULTCONTEXT, :DWORD, :ptr>, 12
      ;+-------------------------------------------------------------------------
      ;  Export the public key info associated with the provider's corresponding
      ;  private key.
      ;  Calls CryptExportPublicKeyInfoEx with pszPublicKeyObjId = NULL,
      ;  dwFlags = 0 and pvAuxInfo = NULL.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CryptExportPublicKeyInfo, WIN_STD_CALL_CONV,, <:HCRYPTPROV_OR_NCRYPT_KEY_HANDLE, :DWORD, :DWORD, :PCERT_PUBLIC_KEY_INFO, :ptr DWORD>, 20
      ; not applicable for NCRYPT_KEY_HANDLE
      ;+-------------------------------------------------------------------------
      ;  Export the public key info associated with the provider's corresponding
      ;  private key.
      ;  Uses the dwCertEncodingType and pszPublicKeyObjId to call the
      ;  installable CRYPT_OID_EXPORT_PUBLIC_KEY_INFO_FUNC. The called function
      ;  has the same signature as CryptExportPublicKeyInfoEx.
      ;  If unable to find an installable OID function for the pszPublicKeyObjId,
      ;  attempts to export as a RSA Public Key (szOID_RSA_RSA).
      ;  The dwFlags and pvAuxInfo aren't used for szOID_RSA_RSA.
      ;  dwFlags can be set with the following 2 flags passed directly to
      ;  CryptFindOIDInfo:
      ;      CRYPT_OID_INFO_PUBKEY_SIGN_KEY_FLAG
      ;      CRYPT_OID_INFO_PUBKEY_ENCRYPT_KEY_FLAG
      ;  dwFlags can be set with the following 2 flags to encode either Curve OID
      ;  or ECC Parameters in Algorithm's Parameters section:
      ;      CRYPT_OID_USE_CURVE_NAME_FOR_ENCODE_FLAG
      ;      CRYPT_OID_USE_CURVE_PARAMETERS_FOR_ENCODE_FLAG
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CryptExportPublicKeyInfoEx, WIN_STD_CALL_CONV,, <:HCRYPTPROV_OR_NCRYPT_KEY_HANDLE, :DWORD, :DWORD, :LPSTR, :DWORD, :ptr, :PCERT_PUBLIC_KEY_INFO, :ptr DWORD>, 32
      ; not applicable for NCRYPT_KEY_HANDLE
      ; Legacy define used for exporting CAPI1 HCRYPTPROV public keys.
      CRYPT_OID_EXPORT_PUBLIC_KEY_INFO_FUNC equ <"CryptDllExportPublicKeyInfoEx">
      ;+-------------------------------------------------------------------------
      ;  Export CNG PublicKeyInfo OID installable function. Note, not called
      ;  for a HCRYPTPROV choice.
      ;--------------------------------------------------------------------------
      CRYPT_OID_EXPORT_PUBLIC_KEY_INFO_EX2_FUNC equ <"CryptDllExportPublicKeyInfoEx2">
      TYPE_PFN_CRYPT_EXPORT_PUBLIC_KEY_INFO_EX2_FUNC typedef proto WIN_STD_CALL_CONV :NCRYPT_KEY_HANDLE, :DWORD, :LPSTR, :DWORD, :ptr, :PCERT_PUBLIC_KEY_INFO, :ptr DWORD
      PFN_CRYPT_EXPORT_PUBLIC_KEY_INFO_EX2_FUNC typedef ptr TYPE_PFN_CRYPT_EXPORT_PUBLIC_KEY_INFO_EX2_FUNC

      if (NTDDI_VERSION ge NTDDI_WIN7)
        ;+-------------------------------------------------------------------------
        ;  Export the public key info associated with the provider's corresponding
        ;  private key.
        ;  Uses the dwCertEncodingType and pszPublicKeyObjId to call the
        ;  installable CRYPT_OID_EXPORT_PUBLIC_KEY_INFO_FROM_BCRYPT_HANDLE_FUNC. The
        ;  called function has the same signature as
        ;  CryptExportPublicKeyInfoFromBCryptKeyHandle.
        ;  If unable to find an installable OID function for the pszPublicKeyObjId,
        ;  attempts to export as a RSA Public Key (szOID_RSA_RSA).
        ;  The dwFlags and pvAuxInfo aren't used for szOID_RSA_RSA.
        ;  In addition dwFlags can be set with the following 2 flags passed directly
        ;  to CryptFindOIDInfo:
        ;      CRYPT_OID_INFO_PUBKEY_SIGN_KEY_FLAG
        ;      CRYPT_OID_INFO_PUBKEY_ENCRYPT_KEY_FLAG
        ;--------------------------------------------------------------------------
        @DefProto DllImport, CryptExportPublicKeyInfoFromBCryptKeyHandle, WIN_STD_CALL_CONV,, <:BCRYPT_KEY_HANDLE, :DWORD, :LPSTR, :DWORD, :ptr, :PCERT_PUBLIC_KEY_INFO, :ptr DWORD>, 28
        ;+-------------------------------------------------------------------------
        ;  Export CNG PublicKeyInfo OID installable function. Note, not called
        ;  for a HCRYPTPROV or NCRYPT_KEY_HANDLE choice.
        ;--------------------------------------------------------------------------
        CRYPT_OID_EXPORT_PUBLIC_KEY_INFO_FROM_BCRYPT_HANDLE_FUNC equ <"CryptDllExportPublicKeyInfoFromBCryptKeyHandle">
        TYPE_PFN_CRYPT_EXPORT_PUBLIC_KEY_INFO_FROM_BCRYPT_HANDLE_FUNC typedef proto WIN_STD_CALL_CONV :BCRYPT_KEY_HANDLE, :DWORD, :LPSTR, :DWORD, :ptr, :PCERT_PUBLIC_KEY_INFO, :ptr DWORD
        PFN_CRYPT_EXPORT_PUBLIC_KEY_INFO_FROM_BCRYPT_HANDLE_FUNC typedef ptr TYPE_PFN_CRYPT_EXPORT_PUBLIC_KEY_INFO_FROM_BCRYPT_HANDLE_FUNC

      endif
      ; (NTDDI_VERSION >= NTDDI_WIN7)
      ;+-------------------------------------------------------------------------
      ;  Convert and import the public key info into the provider and return a
      ;  handle to the public key.
      ;  Calls CryptImportPublicKeyInfoEx with aiKeyAlg = 0, dwFlags = 0 and
      ;  pvAuxInfo = NULL.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CryptImportPublicKeyInfo, WIN_STD_CALL_CONV,, <:HCRYPTPROV, :DWORD, :PCERT_PUBLIC_KEY_INFO, :ptr HCRYPTKEY>, 16
      ;+-------------------------------------------------------------------------
      ;  Convert and import the public key info into the provider and return a
      ;  handle to the public key.
      ;  Uses the dwCertEncodingType and pInfo->Algorithm.pszObjId to call the
      ;  installable CRYPT_OID_IMPORT_PUBLIC_KEY_INFO_FUNC. The called function
      ;  has the same signature as CryptImportPublicKeyInfoEx.
      ;  If unable to find an installable OID function for the pszObjId,
      ;  attempts to import as a RSA Public Key (szOID_RSA_RSA).
      ;  For szOID_RSA_RSA: aiKeyAlg may be set to CALG_RSA_SIGN or CALG_RSA_KEYX.
      ;  Defaults to CALG_RSA_KEYX. The dwFlags and pvAuxInfo aren't used.
      ;--------------------------------------------------------------------------
      CRYPT_OID_IMPORT_PUBLIC_KEY_INFO_FUNC equ <"CryptDllImportPublicKeyInfoEx">
      @DefProto DllImport, CryptImportPublicKeyInfoEx, WIN_STD_CALL_CONV,, <:HCRYPTPROV, :DWORD, :PCERT_PUBLIC_KEY_INFO, :ALG_ID, :DWORD, :ptr, :ptr HCRYPTKEY>, 28
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP|WINAPI_PARTITION_PHONE_RESTRICTED | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      if (NTDDI_VERSION ge NTDDI_VISTA)
        ;+-------------------------------------------------------------------------
        ;  Convert and import the public key info into the CNG asymmetric or
        ;  signature algorithm provider and return a BCRYPT_KEY_HANDLE to it.
        ;  Uses the dwCertEncodingType and pInfo->Algorithm.pszObjId to call the
        ;  installable CRYPT_OID_IMPORT_PUBLIC_KEY_INFO_EX2_FUNC. The called function
        ;  has the same signature as CryptImportPublicKeyInfoEx2.
        ;  dwFlags can be set with the following 2 flags passed directly to
        ;  CryptFindOIDInfo:
        ;      CRYPT_OID_INFO_PUBKEY_SIGN_KEY_FLAG
        ;      CRYPT_OID_INFO_PUBKEY_ENCRYPT_KEY_FLAG
        ;  dwFlags can also have BCRYPT_NO_KEY_VALIDATION OR'd in. This flag is
        ;  passed to BCryptImportKeyPair.
        ;--------------------------------------------------------------------------
        @DefProto DllImport, CryptImportPublicKeyInfoEx2, WIN_STD_CALL_CONV,, <:DWORD, :PCERT_PUBLIC_KEY_INFO, :DWORD, :ptr, :ptr BCRYPT_KEY_HANDLE>, 20
        ;+-------------------------------------------------------------------------
        ;  Import CNG PublicKeyInfo OID installable function
        ;--------------------------------------------------------------------------
        CRYPT_OID_IMPORT_PUBLIC_KEY_INFO_EX2_FUNC equ <"CryptDllImportPublicKeyInfoEx2">
        TYPE_PFN_IMPORT_PUBLIC_KEY_INFO_EX2_FUNC typedef proto WIN_STD_CALL_CONV :DWORD, :PCERT_PUBLIC_KEY_INFO, :DWORD, :ptr, :ptr BCRYPT_KEY_HANDLE
        PFN_IMPORT_PUBLIC_KEY_INFO_EX2_FUNC typedef ptr TYPE_PFN_IMPORT_PUBLIC_KEY_INFO_EX2_FUNC

      endif
      ; (NTDDI_VERSION >= NTDDI_VISTA)
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)*
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_PHONE_RESTRICTED or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      ;+-------------------------------------------------------------------------
      ;  Acquire a HCRYPTPROV and dwKeySpec or NCRYPT_KEY_HANDLE for the
      ;  specified certificate context. Uses the certificate's
      ;  CERT_KEY_PROV_INFO_PROP_ID property.
      ;  The returned HCRYPTPROV or NCRYPT_KEY_HANDLE handle may optionally be
      ;  cached using the certificate's CERT_KEY_CONTEXT_PROP_ID property.
      ;  If CRYPT_ACQUIRE_CACHE_FLAG is set, then, if an already acquired and
      ;  cached HCRYPTPROV or NCRYPT_KEY_HANDLE exists for the certificate, its
      ;  returned. Otherwise, a HCRYPTPROV or NCRYPT_KEY_HANDLE is acquired and
      ;  then cached via the certificate's CERT_KEY_CONTEXT_PROP_ID.
      ;  The CRYPT_ACQUIRE_USE_PROV_INFO_FLAG can be set to use the dwFlags field of
      ;  the certificate's CERT_KEY_PROV_INFO_PROP_ID property's CRYPT_KEY_PROV_INFO
      ;  data structure to determine if the returned HCRYPTPROV or
      ;  NCRYPT_KEY_HANDLE should be cached.
      ;  Caching is enabled if the CERT_SET_KEY_CONTEXT_PROP_ID flag was
      ;  set.
      ;  If CRYPT_ACQUIRE_COMPARE_KEY_FLAG is set, then,
      ;  the public key in the certificate is compared with the public
      ;  key returned by the cryptographic provider. If the keys don't match, the
      ;  acquire fails and LastError is set to NTE_BAD_PUBLIC_KEY. Note, if
      ;  a cached HCRYPTPROV or NCRYPT_KEY_HANDLE is returned, the comparison isn't
      ;  done. We assume the comparison was done on the initial acquire.
      ;  The CRYPT_ACQUIRE_NO_HEALING flags prohibits this function from
      ;  attempting to recreate the CERT_KEY_PROV_INFO_PROP_ID in the certificate
      ;  context if it fails to retrieve this property.
      ;  The CRYPT_ACQUIRE_SILENT_FLAG can be set to suppress any UI by the CSP.
      ;  See CryptAcquireContext's CRYPT_SILENT flag for more details.
      ;  The CRYPT_ACQUIRE_WINDOW_HANDLE_FLAG can be set when a pointer to a window handle (HWND*)
      ;  is passed in as the pvParameters. The window handle will be used
      ;  by calling CryptSetProvParam with a NULL HCRYPTPROV and dwParam
      ;  is PP_CLIENT_HWND before the call to CryptAcquireContext. 
      ;  This will set the window handle for all CAPI calls in this process.
      ;  The caller should make sure the window handle is valid or clear it out by
      ;  calling CryptSetProvParam with PP_CLIENT_HWND with a NULL hWnd.
      ;  Or for cng, the hwnd will be used by calling NCryptSetProperty on the storage provider
      ;  handle provider with property NCRYPT_WINDOW_HANDLE_PROPERTY and
      ;  by calling NCryptSetPRoperty on the key handle with property NCRYPT_WINDOW_HANDLE_PROPERTY.
      ;  If both calls to NCryptSetProperty fail then the function will return the failure of 
      ;  setting the NCRYPT_WINDOW_HANDLE_PROPERTY on the key handle.
      ;  Do not use this flag with CRYPT_ACQUIRE_SILENT_FLAG.
      ;  The following flags can be set to optionally open and return a CNG
      ;  NCRYPT_KEY_HANDLE instead of a HCRYPTPROV. *pdwKeySpec is set to
      ;  CERT_NCRYPT_KEY_SPEC when a NCRYPT_KEY_HANDLE is returned.
      ;      CRYPT_ACQUIRE_ALLOW_NCRYPT_KEY_FLAG - if the CryptAcquireContext
      ;      fails, then, an NCryptOpenKey is attempted.
      ;      CRYPT_ACQUIRE_PREFER_NCRYPT_KEY_FLAG - the NCryptOpenKey is
      ;      first attempted and its handle returned for success.
      ;      CRYPT_ACQUIRE_ONLY_NCRYPT_KEY_FLAG - only the NCryptOpenKey is
      ;      attempted.
      ;  *pfCallerFreeProvOrNCryptKey is returned set to FALSE for:
      ;    - Acquire or public key comparison fails.
      ;    - CRYPT_ACQUIRE_CACHE_FLAG is set.
      ;    - CRYPT_ACQUIRE_USE_PROV_INFO_FLAG is set AND
      ;      CERT_SET_KEY_CONTEXT_PROP_ID flag is set in the dwFlags field of the
      ;      certificate's CERT_KEY_PROV_INFO_PROP_ID property's
      ;      CRYPT_KEY_PROV_INFO data structure.
      ;  When *pfCallerFreeProvOrNCryptKey is FALSE, the caller must not release. The
      ;  returned HCRYPTPROV or NCRYPT_KEY_HANDLE will be released on the last
      ;  free of the certificate context.
      ;  Otherwise, *pfCallerFreeProvOrNCryptKey is TRUE and a returned
      ;  HCRYPTPROV must be released by the caller by calling CryptReleaseContext.
      ;  A returned NCRYPT_KEY_HANDLE is freed by calling NCryptFreeObject.
      ;  *pdwKeySpec MUST be checked when CRYPT_ACQUIRE_ALLOW_NCRYPT_KEY_FLAG
      ;  or CRYPT_ACQUIRE_PREFER_NCRYPT_KEY_FLAG is set.
      ;--------------------------------------------------------------------------
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP|WINAPI_PARTITION_PHONE_RESTRICTED | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
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
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)*
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_PHONE_RESTRICTED or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      ;+-------------------------------------------------------------------------
      ;  Enumerates the cryptographic providers and their containers to find the
      ;  private key corresponding to the certificate's public key. For a match,
      ;  the certificate's CERT_KEY_PROV_INFO_PROP_ID property is updated.
      ;  If the CERT_KEY_PROV_INFO_PROP_ID is already set, then, its checked to
      ;  see if it matches the provider's public key. For a match, the above
      ;  enumeration is skipped.
      ;  By default both the user and machine key containers are searched.
      ;  The CRYPT_FIND_USER_KEYSET_FLAG or CRYPT_FIND_MACHINE_KEYSET_FLAG
      ;  can be set in dwFlags to restrict the search to either of the containers.
      ;  The CRYPT_FIND_SILENT_KEYSET_FLAG can be set to suppress any UI by the CSP.
      ;  See CryptAcquireContext's CRYPT_SILENT flag for more details.
      ;  If a container isn't found, returns FALSE with LastError set to
      ;  NTE_NO_KEY.
      ;  The above CRYPT_ACQUIRE_NCRYPT_KEY_FLAGS can also be set. The default
      ;  is CRYPT_ACQUIRE_ALLOW_NCRYPT_KEY_FLAG.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CryptFindCertificateKeyProvInfo, WIN_STD_CALL_CONV,, <:PCCERT_CONTEXT, :DWORD, :ptr>, 12
      CRYPT_FIND_USER_KEYSET_FLAG equ 00000001h
      CRYPT_FIND_MACHINE_KEYSET_FLAG equ 00000002h
      CRYPT_FIND_SILENT_KEYSET_FLAG equ 00000040h
      ;+-------------------------------------------------------------------------
      ;  This is the prototype for the installable function which is called to
      ;  actually import a key into a CSP.  an installable of this type is called
      ;  from CryptImportPKCS8.  the algorithm OID of the private key is used
      ;  to look up the proper installable function to call.
      ;  hCryptProv - the provider to import the key to
      ;  pPrivateKeyInfo - describes the key to be imported
      ;  dwFlags - The available flags are:
      ;              CRYPT_EXPORTABLE
      ;              this flag is used when importing private keys, for a full
      ;              explanation please see the documentation for CryptImportKey.
      ;  pvAuxInfo - reserved for future, must be NULL
      ;--------------------------------------------------------------------------
      ; in
      ; in
      ; in
      ; in, optional
      TYPE_PFN_IMPORT_PRIV_KEY_FUNC typedef proto WIN_STD_CALL_CONV :HCRYPTPROV, :ptr CRYPT_PRIVATE_KEY_INFO, :DWORD, :ptr
      PFN_IMPORT_PRIV_KEY_FUNC typedef ptr TYPE_PFN_IMPORT_PRIV_KEY_FUNC

      CRYPT_OID_IMPORT_PRIVATE_KEY_INFO_FUNC equ <"CryptDllImportPrivateKeyInfoEx">
      ;+-------------------------------------------------------------------------
      ; Convert (from PKCS8 format) and import the private key into a provider
      ; and return a handle to the provider as well as the KeySpec used to import to.
      ; This function will call the PRESOLVE_HCRYPTPROV_FUNC in the
      ; privateKeyAndParams to obtain a handle of provider to import the key to.
      ; if the PRESOLVE_HCRYPTPROV_FUNC is NULL then the default provider will be used.
      ; privateKeyAndParams - private key blob and corresponding parameters
      ; dwFlags - The available flags are:
      ;              CRYPT_EXPORTABLE
      ;              this flag is used when importing private keys, for a full
      ;              explanation please see the documentation for CryptImportKey.
      ; phCryptProv - filled in with the handle of the provider the key was
      ;               imported to, the caller is responsible for freeing it
      ; pvAuxInfo - This parameter is reserved for future use and should be set
      ;             to NULL in the interim.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CryptImportPKCS8, WIN_STD_CALL_CONV,, <:CRYPT_PKCS8_IMPORT_PARAMS, :DWORD, :ptr HCRYPTPROV, :ptr>, 16
      ; in, optional
      ;+-------------------------------------------------------------------------
      ; this is the prototype for installable functions for exporting the private key
      ;--------------------------------------------------------------------------
      ; in
      ; in
      ; in
      ; in
      ; in
      ; out
      ; in, out
      TYPE_PFN_EXPORT_PRIV_KEY_FUNC typedef proto WIN_STD_CALL_CONV :HCRYPTPROV, :DWORD, :LPSTR, :DWORD, :ptr, :ptr CRYPT_PRIVATE_KEY_INFO, :ptr DWORD
      PFN_EXPORT_PRIV_KEY_FUNC typedef ptr TYPE_PFN_EXPORT_PRIV_KEY_FUNC

      CRYPT_OID_EXPORT_PRIVATE_KEY_INFO_FUNC equ <"CryptDllExportPrivateKeyInfoEx">
      CRYPT_DELETE_KEYSET equ <CRYPT_DELETEKEYSET>
      ;+-------------------------------------------------------------------------
      ;  CryptExportPKCS8 -- superseded by CryptExportPKCS8Ex
      ;  Export the private key in PKCS8 format
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CryptExportPKCS8, WIN_STD_CALL_CONV,, <:HCRYPTPROV, :DWORD, :LPSTR, :DWORD, :ptr, :ptr BYTE, :ptr DWORD>, 28
      ; in, out
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP|WINAPI_PARTITION_PHONE_RESTRICTED | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_PHONE_RESTRICTED or WINAPI_PARTITION_GAMES)
      ;+-------------------------------------------------------------------------
      ; CryptExportPKCS8Ex
      ;  Export the private key in PKCS8 format
      ;  Uses the pszPrivateKeyObjId to call the
      ;  installable CRYPT_OID_EXPORT_PRIVATE_KEY_INFO_FUNC. The called function
      ;  has the signature defined by PFN_EXPORT_PRIV_KEY_FUNC.
      ;  If unable to find an installable OID function for the pszPrivateKeyObjId,
      ;  attempts to export as a RSA Private Key (szOID_RSA_RSA).
      ; psExportParams - specifies information about the key to export
      ; dwFlags - The flag values. None currently supported
      ; pvAuxInfo - This parameter is reserved for future use and should be set to
      ;                         NULL in the interim.
      ; pbPrivateKeyBlob - A pointer to the private key blob.  It will be encoded
      ;                                        as a PKCS8 PrivateKeyInfo.
      ; pcbPrivateKeyBlob - A pointer to a DWORD that contains the size, in bytes,
      ;                                         of the private key blob being exported.
      ;+-------------------------------------------------------------------------
      @DefProto DllImport, CryptExportPKCS8Ex, WIN_STD_CALL_CONV,, <:ptr CRYPT_PKCS8_EXPORT_PARAMS, :DWORD, :ptr, :ptr BYTE, :ptr DWORD>, 20
      ; in, out
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_PHONE_RESTRICTED | WINAPI_PARTITION_GAMES) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      ;+-------------------------------------------------------------------------
      ;  Compute the hash of the encoded public key info.
      ;  The public key info is encoded and then hashed.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CryptHashPublicKeyInfo, WIN_STD_CALL_CONV,, <:HCRYPTPROV_LEGACY, :ALG_ID, :DWORD, :DWORD, :PCERT_PUBLIC_KEY_INFO, :ptr BYTE, :ptr DWORD>, 28
      ;+-------------------------------------------------------------------------
      ;  Convert a Name Value to a null terminated char string
      ;  Returns the number of characters converted including the terminating null
      ;  character. If psz is NULL or csz is 0, returns the required size of the
      ;  destination string (including the terminating null char).
      ;  If psz != NULL && csz != 0, returned psz is always NULL terminated.
      ;  Note: csz includes the NULL char.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertRDNValueToStrA, WIN_STD_CALL_CONV,, <:DWORD, :PCERT_RDN_VALUE_BLOB, :LPSTR, :DWORD>, 16
      ;+-------------------------------------------------------------------------
      ;  Convert a Name Value to a null terminated char string
      ;  Returns the number of characters converted including the terminating null
      ;  character. If psz is NULL or csz is 0, returns the required size of the
      ;  destination string (including the terminating null char).
      ;  If psz != NULL && csz != 0, returned psz is always NULL terminated.
      ;  Note: csz includes the NULL char.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertRDNValueToStrW, WIN_STD_CALL_CONV,, <:DWORD, :PCERT_RDN_VALUE_BLOB, :LPWSTR, :DWORD>, 16
      ifdef UNICODE
        CertRDNValueToStr equ <CertRDNValueToStrW>
      else
        CertRDNValueToStr equ <CertRDNValueToStrA>
      endif
      ; !UNICODE
      ;+-------------------------------------------------------------------------
      ;  Convert the certificate name blob to a null terminated char string.
      ;  Follows the string representation of distinguished names specified in
      ;  RFC 1779. (Note, added double quoting "" for embedded quotes, quote
      ;  empty strings and don't quote strings containing consecutive spaces).
      ;  RDN values of type CERT_RDN_ENCODED_BLOB or CERT_RDN_OCTET_STRING are
      ;  formatted in hexadecimal (e.g. #0A56CF).
      ;  The name string is formatted according to the dwStrType:
      ;    CERT_SIMPLE_NAME_STR
      ;      The object identifiers are discarded. CERT_RDN entries are separated
      ;      by ", ". Multiple attributes per CERT_RDN are separated by " + ".
      ;      For example:
      ;          Microsoft, Joe Cool + Programmer
      ;    CERT_OID_NAME_STR
      ;      The object identifiers are included with a "=" separator from their
      ;      attribute value. CERT_RDN entries are separated by ", ".
      ;      Multiple attributes per CERT_RDN are separated by " + ". For example:
      ;          2.5.4.11=Microsoft, 2.5.4.3=Joe Cool + 2.5.4.12=Programmer
      ;    CERT_X500_NAME_STR
      ;      The object identifiers are converted to their X500 key name. Otherwise,
      ;      same as CERT_OID_NAME_STR. If the object identifier doesn't have
      ;      a corresponding X500 key name, then, the object identifier is used with
      ;      a "OID." prefix. For example:
      ;          OU=Microsoft, CN=Joe Cool + T=Programmer, OID.1.2.3.4.5.6=Unknown
      ;    CERT_XML_NAME_STR
      ;      The object identifiers are converted the same as the above
      ;      CERT_X500_NAME_STR. However, formatted as sequence of XML elements.
      ;      Here's an example:
      ;          <CN>cart.barnesandnoble.com</CN>
      ;          <OU>Terms of use at www.verisign.com/rpa (c)00</OU>
      ;          <OU rDNAttribute="true">IT Operations</OU>
      ;          <O>Barnesandnoble.com</O>
      ;          <L>New York</L>
      ;          <S>New York</S>
      ;          <C>US</C>
      ;          <RDN oid="1.2.3.4" type="string">name</RDN>
      ;          <RDN rDNAttribute="true" oid="1.2.1.3" type="encoded">0500</RDN>
      ;          <RDN oid="1.2.1.4" type="encoded">020135</RDN>
      ;          <RDN oid="1.2.2.5.3" type="octet">01FF7F</RDN>
      ;      Where:
      ;          Any XML markup characters are escaped:
      ;             L'&'   - L"&amp;"
      ;             L'<'   - L"&lt;"
      ;             L'>'   - L"&gt;"
      ;             L'\''  - L"&apos;"
      ;             L'\"'  - L"&quot;"
      ;          Will escape characters > 0x7F via chararacter references,
      ;          L"&#xXXXX;"
      ;          CERT_NAME_STR_REVERSE_FLAG and CERT_NAME_STR_CRLF_FLAG can be set.
      ;          The following quoting, semicolon and plus semantics aren't
      ;          applicable. The "+" is replaced with rDNAttribute="true".
      ;  We quote the RDN value if it contains leading or trailing whitespace
      ;  or one of the following characters: ",", "+", "=", """, "\n",  "<", ">",
      ;  "#" or ";". The quoting character is ". If the the RDN Value contains
      ;  a " it is double quoted (""). For example:
      ;      OU="  Microsoft", CN="Joe ""Cool""" + T="Programmer, Manager"
      ;  CERT_NAME_STR_SEMICOLON_FLAG can be or'ed into dwStrType to replace
      ;  the ", " separator with a "; " separator.
      ;  CERT_NAME_STR_CRLF_FLAG can be or'ed into dwStrType to replace
      ;  the ", " separator with a "\r\n" separator.
      ;  CERT_NAME_STR_NO_PLUS_FLAG can be or'ed into dwStrType to replace the
      ;  " + " separator with a single space, " ".
      ;  CERT_NAME_STR_NO_QUOTING_FLAG can be or'ed into dwStrType to inhibit
      ;  the above quoting.
      ;  CERT_NAME_STR_REVERSE_FLAG can be or'ed into dwStrType to reverse the
      ;  order of the RDNs before converting to the string.
      ;  By default, CERT_RDN_T61_STRING encoded values are initially decoded
      ;  as UTF8. If the UTF8 decoding fails, then, decoded as 8 bit characters.
      ;  CERT_NAME_STR_DISABLE_IE4_UTF8_FLAG can be or'ed into dwStrType to
      ;  skip the initial attempt to decode as UTF8.
      ;  CERT_NAME_STR_ENABLE_PUNYCODE_FLAG can be or'ed into dwStrType to enable
      ;  encoding/decoding of unicode characters in email RDN value.
      ;  Returns the number of characters converted including the terminating null
      ;  character. If psz is NULL or csz is 0, returns the required size of the
      ;  destination string (including the terminating null char).
      ;  If psz != NULL && csz != 0, returned psz is always NULL terminated.
      ;  Note: csz includes the NULL char.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertNameToStrA, WIN_STD_CALL_CONV,, <:DWORD, :PCERT_NAME_BLOB, :DWORD, :LPSTR, :DWORD>, 20
      @DefProto DllImport, CertNameToStrW, WIN_STD_CALL_CONV,, <:DWORD, :PCERT_NAME_BLOB, :DWORD, :LPWSTR, :DWORD>, 20
      ifdef UNICODE
        CertNameToStr equ <CertNameToStrW>
      else
        CertNameToStr equ <CertNameToStrA>
      endif
      ; !UNICODE
      ; certenrolld_begin -- CERT_NAME_STR_*_FLAG
      ;+-------------------------------------------------------------------------
      ;  Certificate name string types
      ;--------------------------------------------------------------------------
      CERT_SIMPLE_NAME_STR equ 1
      CERT_OID_NAME_STR equ 2
      CERT_X500_NAME_STR equ 3
      CERT_XML_NAME_STR equ 4
      ;+-------------------------------------------------------------------------
      ;  Certificate name string type flags OR'ed with the above types
      ;--------------------------------------------------------------------------
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
      ;#define CERT_NAME_STR_RESERVED00800000          0x00800000
      ; certenrolld_end
      ;+-------------------------------------------------------------------------
      ;  Convert the null terminated X500 string to an encoded certificate name.
      ;  The input string is expected to be formatted the same as the output
      ;  from the above CertNameToStr API.
      ;  The CERT_SIMPLE_NAME_STR type and CERT_XML_NAME_STR aren't supported.
      ;  Otherwise, when dwStrType
      ;  is set to 0, CERT_OID_NAME_STR or CERT_X500_NAME_STR, allow either a
      ;  case insensitive X500 key (CN=), case insensitive "OID." prefixed
      ;  object identifier (OID.1.2.3.4.5.6=) or an object identifier (1.2.3.4=).
      ;  If no flags are OR'ed into dwStrType, then, allow "," or ";" as RDN
      ;  separators and "+" as the multiple RDN value separator. Quoting is
      ;  supported. A quote may be included in a quoted value by double quoting,
      ;  for example (CN="Joe ""Cool"""). A value starting with a "#" is treated
      ;  as ascii hex and converted to a CERT_RDN_OCTET_STRING. Embedded whitespace
      ;  is skipped (1.2.3 = # AB CD 01  is the same as 1.2.3=#ABCD01).
      ;  Whitespace surrounding the keys, object identifers and values is removed.
      ;  CERT_NAME_STR_COMMA_FLAG can be or'ed into dwStrType to only allow the
      ;  "," as the RDN separator.
      ;  CERT_NAME_STR_SEMICOLON_FLAG can be or'ed into dwStrType to only allow the
      ;  ";" as the RDN separator.
      ;  CERT_NAME_STR_CRLF_FLAG can be or'ed into dwStrType to only allow
      ;  "\r" or "\n" as the RDN separator.
      ;  CERT_NAME_STR_NO_PLUS_FLAG can be or'ed into dwStrType to ignore "+"
      ;  as a separator and not allow multiple values per RDN.
      ;  CERT_NAME_STR_NO_QUOTING_FLAG can be or'ed into dwStrType to inhibit
      ;  quoting.
      ;  CERT_NAME_STR_REVERSE_FLAG can be or'ed into dwStrType to reverse the
      ;  order of the RDNs after converting from the string and before encoding.
      ;  CERT_NAME_STR_FORWARD_FLAG can be or'ed into dwStrType to defeat setting
      ;  CERT_NAME_STR_REVERSE_FLAG, if reverse order becomes the default.
      ;  CERT_NAME_STR_ENABLE_T61_UNICODE_FLAG can be or'ed into dwStrType to
      ;  to select the CERT_RDN_T61_STRING encoded value type instead of
      ;  CERT_RDN_UNICODE_STRING if all the UNICODE characters are <= 0xFF.
      ;  CERT_NAME_STR_ENABLE_UTF8_UNICODE_FLAG can be or'ed into dwStrType to
      ;  to select the CERT_RDN_UTF8_STRING encoded value type instead of
      ;  CERT_RDN_UNICODE_STRING.
      ;  CERT_NAME_STR_FORCE_UTF8_DIR_STR_FLAG can be or'ed into dwStrType
      ;  to force the CERT_RDN_UTF8_STRING encoded value type instead of
      ;  allowing CERT_RDN_PRINTABLE_STRING for DirectoryString types.
      ;  Applies to the X500 Keys below which allow "Printable, Unicode".
      ;  Also, enables CERT_NAME_STR_ENABLE_UTF8_UNICODE_FLAG.
      ;  CERT_NAME_STR_DISABLE_UTF8_DIR_STR_FLAG can be or'ed into dwStrType to
      ;  defeat setting CERT_NAME_STR_FORCE_UTF8_DIR_STR_FLAG, if forcing UTF-8
      ;  becomes the default.
      ;  Support the following X500 Keys:
      ;  Key         Object Identifier               RDN Value Type(s)
      ;  ---         -----------------               -----------------
      ;  CN          szOID_COMMON_NAME               Printable, Unicode
      ;  L           szOID_LOCALITY_NAME             Printable, Unicode
      ;  O           szOID_ORGANIZATION_NAME         Printable, Unicode
      ;  OU          szOID_ORGANIZATIONAL_UNIT_NAME  Printable, Unicode
      ;  E           szOID_RSA_emailAddr             Only IA5
      ;  Email       szOID_RSA_emailAddr             Only IA5
      ;  C           szOID_COUNTRY_NAME              Only Printable
      ;  S           szOID_STATE_OR_PROVINCE_NAME    Printable, Unicode
      ;  ST          szOID_STATE_OR_PROVINCE_NAME    Printable, Unicode
      ;  STREET      szOID_STREET_ADDRESS            Printable, Unicode
      ;  T           szOID_TITLE                     Printable, Unicode
      ;  Title       szOID_TITLE                     Printable, Unicode
      ;  G           szOID_GIVEN_NAME                Printable, Unicode
      ;  GN          szOID_GIVEN_NAME                Printable, Unicode
      ;  GivenName   szOID_GIVEN_NAME                Printable, Unicode
      ;  I           szOID_INITIALS                  Printable, Unicode
      ;  Initials    szOID_INITIALS                  Printable, Unicode
      ;  SN          szOID_SUR_NAME                  Printable, Unicode
      ;  DC          szOID_DOMAIN_COMPONENT          IA5, UTF8
      ;  SERIALNUMBER szOID_DEVICE_SERIAL_NUMBER     Only Printable
      ;  Note, T61 is selected instead of Unicode if
      ;  CERT_NAME_STR_ENABLE_T61_UNICODE_FLAG is set and all the unicode
      ;  characters are <= 0xFF.
      ;  Note, UTF8 is selected instead of Unicode if
      ;  CERT_NAME_STR_ENABLE_UTF8_UNICODE_FLAG is set.
      ;  Returns TRUE if successfully parsed the input string and encoded
      ;  the name.
      ;  If the input string is detected to be invalid, *ppszError is updated
      ;  to point to the beginning of the invalid character sequence. Otherwise,
      ;  *ppszError is set to NULL. *ppszError is updated with a non-NULL pointer
      ;  for the following errors:
      ;      CRYPT_E_INVALID_X500_STRING
      ;      CRYPT_E_INVALID_NUMERIC_STRING
      ;      CRYPT_E_INVALID_PRINTABLE_STRING
      ;      CRYPT_E_INVALID_IA5_STRING
      ;  ppszError can be set to NULL if not interested in getting a pointer
      ;  to the invalid character sequence.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertStrToNameA, WIN_STD_CALL_CONV,, <:DWORD, :LPCSTR, :DWORD, :ptr, :ptr BYTE, :ptr DWORD, :ptr LPCSTR>, 28
      ;+-------------------------------------------------------------------------
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertStrToNameW, WIN_STD_CALL_CONV,, <:DWORD, :LPCWSTR, :DWORD, :ptr, :ptr BYTE, :ptr DWORD, :ptr LPCWSTR>, 28
      ifdef UNICODE
        CertStrToName equ <CertStrToNameW>
      else
        CertStrToName equ <CertStrToNameA>
      endif
      ; !UNICODE
      ;+-------------------------------------------------------------------------
      ;  Get the subject or issuer name from the certificate and
      ;  according to the specified format type, convert to a null terminated
      ;  character string.
      ;  CERT_NAME_ISSUER_FLAG can be set to get the issuer's name. Otherwise,
      ;  gets the subject's name.
      ;  By default, CERT_RDN_T61_STRING encoded values are initially decoded
      ;  as UTF8. If the UTF8 decoding fails, then, decoded as 8 bit characters.
      ;  CERT_NAME_DISABLE_IE4_UTF8_FLAG can be set in dwFlags to
      ;  skip the initial attempt to decode as UTF8.
      ;  The name string is formatted according to the dwType:
      ;    CERT_NAME_EMAIL_TYPE
      ;      If the certificate has a Subject Alternative Name extension (for
      ;      issuer, Issuer Alternative Name), searches for first rfc822Name choice.
      ;      If the rfc822Name choice isn't found in the extension, searches the
      ;      Subject Name field for the Email OID, "1.2.840.113549.1.9.1".
      ;      If the rfc822Name or Email OID is found, returns the string. Otherwise,
      ;      returns an empty string (returned character count is 1).
      ;    CERT_NAME_DNS_TYPE
      ;      If the certificate has a Subject Alternative Name extension (for
      ;      issuer, Issuer Alternative Name), searches for first DNSName choice.
      ;      If the DNSName choice isn't found in the extension, searches the
      ;      Subject Name field for the CN OID, "2.5.4.3".
      ;      If the DNSName or CN OID is found, returns the string. Otherwise,
      ;      returns an empty string.
      ;    CERT_NAME_URL_TYPE
      ;      If the certificate has a Subject Alternative Name extension (for
      ;      issuer, Issuer Alternative Name), searches for first URL choice.
      ;      If the URL choice is found, returns the string. Otherwise,
      ;      returns an empty string.
      ;    CERT_NAME_UPN_TYPE
      ;      If the certificate has a Subject Alternative Name extension,
      ;      searches the OtherName choices looking for a
      ;      pszObjId == szOID_NT_PRINCIPAL_NAME, "1.3.6.1.4.1.311.20.2.3".
      ;      If the UPN OID is found, the blob is decoded as a
      ;      X509_UNICODE_ANY_STRING and the decoded string is returned.
      ;      Otherwise, returns an empty string.
      ;    CERT_NAME_RDN_TYPE
      ;      Converts the Subject Name blob by calling CertNameToStr. pvTypePara
      ;      points to a DWORD containing the dwStrType passed to CertNameToStr.
      ;      If the Subject Name field is empty and the certificate has a
      ;      Subject Alternative Name extension, searches for and converts
      ;      the first directoryName choice.
      ;    CERT_NAME_ATTR_TYPE
      ;      pvTypePara points to the Object Identifier specifying the name attribute
      ;      to be returned. For example, to get the CN,
      ;      pvTypePara = szOID_COMMON_NAME ("2.5.4.3"). Searches, the Subject Name
      ;      field for the attribute.
      ;      If the Subject Name field is empty and the certificate has a
      ;      Subject Alternative Name extension, checks for
      ;      the first directoryName choice and searches it.
      ;      Note, searches the RDNs in reverse order.
      ;    CERT_NAME_SIMPLE_DISPLAY_TYPE
      ;      Iterates through the following list of name attributes and searches
      ;      the Subject Name and then the Subject Alternative Name extension
      ;      for the first occurrence of:
      ;          szOID_COMMON_NAME ("2.5.4.3")
      ;          szOID_ORGANIZATIONAL_UNIT_NAME ("2.5.4.11")
      ;          szOID_ORGANIZATION_NAME ("2.5.4.10")
      ;          szOID_RSA_emailAddr ("1.2.840.113549.1.9.1")
      ;      If none of the above attributes is found, then, searches the
      ;      Subject Alternative Name extension for a rfc822Name choice.
      ;      If still no match, then, returns the first attribute.
      ;      Note, like CERT_NAME_ATTR_TYPE, searches the RDNs in reverse order.
      ;    CERT_NAME_FRIENDLY_DISPLAY_TYPE
      ;      First checks if the certificate has a CERT_FRIENDLY_NAME_PROP_ID
      ;      property. If it does, then, this property is returned. Otherwise,
      ;      returns the above CERT_NAME_SIMPLE_DISPLAY_TYPE.
      ;  Returns the number of characters converted including the terminating null
      ;  character. If pwszNameString is NULL or cchNameString is 0, returns the
      ;  required size of the destination string (including the terminating null
      ;  char). If the specified name type isn't found. returns an empty string
      ;  with a returned character count of 1.
      ;  If pwszNameString != NULL && cwszNameString != 0, returned pwszNameString
      ;  is always NULL terminated.
      ;  Note: cchNameString includes the NULL char.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertGetNameStringA, WIN_STD_CALL_CONV,, <:PCCERT_CONTEXT, :DWORD, :DWORD, :ptr, :LPSTR, :DWORD>, 24
      ;+-------------------------------------------------------------------------
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertGetNameStringW, WIN_STD_CALL_CONV,, <:PCCERT_CONTEXT, :DWORD, :DWORD, :ptr, :LPWSTR, :DWORD>, 24
      ifdef UNICODE
        CertGetNameString equ <CertGetNameStringW>
      else
        CertGetNameString equ <CertGetNameStringA>
      endif
      ; !UNICODE
      ;+-------------------------------------------------------------------------
      ;  Certificate name types
      ;--------------------------------------------------------------------------
      CERT_NAME_EMAIL_TYPE equ 1
      CERT_NAME_RDN_TYPE equ 2
      CERT_NAME_ATTR_TYPE equ 3
      CERT_NAME_SIMPLE_DISPLAY_TYPE equ 4
      CERT_NAME_FRIENDLY_DISPLAY_TYPE equ 5
      CERT_NAME_DNS_TYPE equ 6
      CERT_NAME_URL_TYPE equ 7
      CERT_NAME_UPN_TYPE equ 8
      ;+-------------------------------------------------------------------------
      ;  Certificate name flags
      ;--------------------------------------------------------------------------
      CERT_NAME_ISSUER_FLAG equ 1h
      CERT_NAME_DISABLE_IE4_UTF8_FLAG equ 00010000h
      ; Following is only applicable to CERT_NAME_DNS_TYPE. When set returns
      ; all names not just the first one. Returns a multi-string. Each string
      ; will be null terminated. The last string will be double null terminated. 
      CERT_NAME_SEARCH_ALL_NAMES_FLAG equ 2h
      ;+=========================================================================
      ;  Simplified Cryptographic Message Data Structures and APIs
      ;==========================================================================
      ;+-------------------------------------------------------------------------
      ;              Conventions for the *pb and *pcb output parameters:
      ;              Upon entry to the function:
      ;                  if pcb is OPTIONAL && pcb == NULL, then,
      ;                      No output is returned
      ;                  else if pb == NULL && pcb != NULL, then,
      ;                      Length only determination. No length error is
      ;                      returned.
      ;                  otherwise where (pb != NULL && pcb != NULL && *pcb != 0)
      ;                      Output is returned. If *pcb isn't big enough a
      ;                      length error is returned. In all cases *pcb is updated
      ;                      with the actual length needed/returned.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  Type definitions of the parameters used for doing the cryptographic
      ;  operations.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  Callback to get and verify the signer's certificate.
      ;  Passed the CertId of the signer (its Issuer and SerialNumber) and a
      ;  handle to its cryptographic signed message's cert store.
      ;  For CRYPT_E_NO_SIGNER, called with pSignerId == NULL.
      ;  For a valid signer certificate, returns a pointer to a read only
      ;  CERT_CONTEXT. The returned CERT_CONTEXT is either obtained from a
      ;  cert store or was created via CertCreateCertificateContext. For either case,
      ;  its freed via CertFreeCertificateContext.
      ;  If a valid certificate isn't found, this callback returns NULL with
      ;  LastError set via SetLastError().
      ;  The NULL implementation tries to get the Signer certificate from the
      ;  message cert store. It doesn't verify the certificate.
      ;  Note, if the KEYID choice was selected for a CMS SignerId, then, the
      ;  SerialNumber is 0 and the Issuer is encoded containing a single RDN with a
      ;  single Attribute whose OID is szOID_KEYID_RDN, value type is
      ;  CERT_RDN_OCTET_STRING and value is the KEYID. When the
      ;  CertGetSubjectCertificateFromStore and
      ;  CertFindCertificateInStore(CERT_FIND_SUBJECT_CERT) APIs see this
      ;  special KEYID Issuer and SerialNumber, they do a KEYID match.
      ;--------------------------------------------------------------------------
      ; Only the Issuer and SerialNumber
      ; fields have been updated
      TYPE_PFN_CRYPT_GET_SIGNER_CERTIFICATE typedef proto WIN_STD_CALL_CONV :ptr, :DWORD, :PCERT_INFO, :HCERTSTORE
      PFN_CRYPT_GET_SIGNER_CERTIFICATE typedef ptr TYPE_PFN_CRYPT_GET_SIGNER_CERTIFICATE

      ;+-------------------------------------------------------------------------
      ;  The CRYPT_SIGN_MESSAGE_PARA are used for signing messages using the
      ;  specified signing certificate context.
      ;  Either the CERT_KEY_PROV_HANDLE_PROP_ID or CERT_KEY_PROV_INFO_PROP_ID must
      ;  be set for each rgpSigningCert[]. Either one specifies the private
      ;  signature key to use.
      ;  If any certificates and/or CRLs are to be included in the signed message,
      ;  then, the MsgCert and MsgCrl parameters need to be updated. If the
      ;  rgpSigningCerts are to be included, then, they must also be in the
      ;  rgpMsgCert array.
      ;  cbSize must be set to the sizeof(CRYPT_SIGN_MESSAGE_PARA) or else
      ;  LastError will be updated with E_INVALIDARG.
      ;  pvHashAuxInfo currently isn't used and must be set to NULL.
      ;  dwFlags normally is set to 0. However, if the encoded output
      ;  is to be a CMSG_SIGNED inner content of an outer cryptographic message,
      ;  such as a CMSG_ENVELOPED, then, the CRYPT_MESSAGE_BARE_CONTENT_OUT_FLAG
      ;  should be set. If not set, then it would be encoded as an inner content
      ;  type of CMSG_DATA.
      ;  dwInnerContentType is normally set to 0. It needs to be set if the
      ;  ToBeSigned input is the encoded output of another cryptographic
      ;  message, such as, an CMSG_ENVELOPED. When set, it's one of the cryptographic
      ;  message types, for example, CMSG_ENVELOPED.
      ;  If the inner content of a nested cryptographic message is data (CMSG_DATA
      ;  the default), then, neither dwFlags or dwInnerContentType need to be set.
      ;  For CMS messages, CRYPT_MESSAGE_ENCAPSULATED_CONTENT_OUT_FLAG may be
      ;  set to encapsulate nonData inner content within an OCTET STRING.
      ;  For CMS messages, CRYPT_MESSAGE_KEYID_SIGNER_FLAG may be set to identify
      ;  signers by their Key Identifier and not their Issuer and Serial Number.
      ;  The CRYPT_MESSAGE_SILENT_KEYSET_FLAG can be set to suppress any UI by the
      ;  CSP. See CryptAcquireContext's CRYPT_SILENT flag for more details.
      ;  If HashEncryptionAlgorithm is present and not NULL its used instead of
      ;  the SigningCert's PublicKeyInfo.Algorithm.
      ;  Note, for RSA, the hash encryption algorithm is normally the same as
      ;  the public key algorithm. For DSA, the hash encryption algorithm is
      ;  normally a DSS signature algorithm.
      ;  pvHashEncryptionAuxInfo currently isn't used and must be set to NULL if
      ;  present in the data structure.
      ;--------------------------------------------------------------------------
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
          ; This is also referred to as the SignatureAlgorithm
          HashEncryptionAlgorithm CRYPT_ALGORITHM_IDENTIFIER <>
          pvHashEncryptionAuxInfo POINTER ?
        endif
      CRYPT_SIGN_MESSAGE_PARA ends
      _CRYPT_SIGN_MESSAGE_PARA typedef CRYPT_SIGN_MESSAGE_PARA
      PCRYPT_SIGN_MESSAGE_PARA typedef ptr CRYPT_SIGN_MESSAGE_PARA
      CRYPT_MESSAGE_BARE_CONTENT_OUT_FLAG equ 00000001h
      ; When set, nonData type inner content is encapsulated within an
      ; OCTET STRING
      CRYPT_MESSAGE_ENCAPSULATED_CONTENT_OUT_FLAG equ 00000002h
      ; When set, signers are identified by their Key Identifier and not
      ; their Issuer and Serial Number.
      CRYPT_MESSAGE_KEYID_SIGNER_FLAG equ 00000004h
      ; When set, suppresses any UI by the CSP.
      ; See CryptAcquireContext's CRYPT_SILENT flag for more details.
      CRYPT_MESSAGE_SILENT_KEYSET_FLAG equ 00000040h
      ;+-------------------------------------------------------------------------
      ;  The CRYPT_VERIFY_MESSAGE_PARA are used to verify signed messages.
      ;  hCryptProv is used to do hashing and signature verification.
      ;  The dwCertEncodingType specifies the encoding type of the certificates
      ;  and/or CRLs in the message.
      ;  pfnGetSignerCertificate is called to get and verify the message signer's
      ;  certificate.
      ;  cbSize must be set to the sizeof(CRYPT_VERIFY_MESSAGE_PARA) or else
      ;  LastError will be updated with E_INVALIDARG.
      ;--------------------------------------------------------------------------
      CRYPT_VERIFY_MESSAGE_PARA struct
        cbSize DWORD ?
        dwMsgAndCertEncodingType DWORD ?
        hCryptProv HCRYPTPROV_LEGACY ?
        pfnGetSignerCertificate PFN_CRYPT_GET_SIGNER_CERTIFICATE ?
        pvGetArg POINTER ?
        ifdef CRYPT_VERIFY_MESSAGE_PARA_HAS_EXTRA_FIELDS
          ; Note, if you #define CRYPT_VERIFY_MESSAGE_PARA_HAS_EXTRA_FIELDS,
          ; then, you must zero all unused fields in this data structure.
          ; More fields could be added in a future release.
          ; The following is set to check for Strong and Restricted Signatures
          pStrongSignPara PCCERT_STRONG_SIGN_PARA ?
        endif
      CRYPT_VERIFY_MESSAGE_PARA ends
      _CRYPT_VERIFY_MESSAGE_PARA typedef CRYPT_VERIFY_MESSAGE_PARA
      PCRYPT_VERIFY_MESSAGE_PARA typedef ptr CRYPT_VERIFY_MESSAGE_PARA
      ;+-------------------------------------------------------------------------
      ;  The CRYPT_ENCRYPT_MESSAGE_PARA are used for encrypting messages.
      ;  hCryptProv is used to do content encryption, recipient key
      ;  encryption, and recipient key export. Its private key
      ;  isn't used.
      ;  Currently, pvEncryptionAuxInfo is only defined for RC2 or RC4 encryption
      ;  algorithms. Otherwise, its not used and must be set to NULL.
      ;  See CMSG_RC2_AUX_INFO for the RC2 encryption algorithms.
      ;  See CMSG_RC4_AUX_INFO for the RC4 encryption algorithms.
      ;  To enable SP3 compatible encryption, pvEncryptionAuxInfo should point to
      ;  a CMSG_SP3_COMPATIBLE_AUX_INFO data structure.
      ;  cbSize must be set to the sizeof(CRYPT_ENCRYPT_MESSAGE_PARA) or else
      ;  LastError will be updated with E_INVALIDARG.
      ;  dwFlags normally is set to 0. However, if the encoded output
      ;  is to be a CMSG_ENVELOPED inner content of an outer cryptographic message,
      ;  such as a CMSG_SIGNED, then, the CRYPT_MESSAGE_BARE_CONTENT_OUT_FLAG
      ;  should be set. If not set, then it would be encoded as an inner content
      ;  type of CMSG_DATA.
      ;  dwInnerContentType is normally set to 0. It needs to be set if the
      ;  ToBeEncrypted input is the encoded output of another cryptographic
      ;  message, such as, an CMSG_SIGNED. When set, it's one of the cryptographic
      ;  message types, for example, CMSG_SIGNED.
      ;  If the inner content of a nested cryptographic message is data (CMSG_DATA
      ;  the default), then, neither dwFlags or dwInnerContentType need to be set.
      ;  For CMS messages, CRYPT_MESSAGE_ENCAPSULATED_CONTENT_OUT_FLAG may be
      ;  set to encapsulate nonData inner content within an OCTET STRING before
      ;  encrypting.
      ;  For CMS messages, CRYPT_MESSAGE_KEYID_RECIPIENT_FLAG may be set to identify
      ;  recipients by their Key Identifier and not their Issuer and Serial Number.
      ;--------------------------------------------------------------------------
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
      ; When set, recipients are identified by their Key Identifier and not
      ; their Issuer and Serial Number.
      CRYPT_MESSAGE_KEYID_RECIPIENT_FLAG equ 4h
      ;+-------------------------------------------------------------------------
      ;  The CRYPT_DECRYPT_MESSAGE_PARA are used for decrypting messages.
      ;  The CertContext to use for decrypting a message is obtained from one
      ;  of the specified cert stores. An encrypted message can have one or
      ;  more recipients. The recipients are identified by their CertId (Issuer
      ;  and SerialNumber). The cert stores are searched to find the CertContext
      ;  corresponding to the CertId.
      ;  For CMS, the recipients may also be identified by their KeyId.
      ;  CMS also allows Key Agreement (Diffie Hellman) in addition to
      ;  Key Transport (RSA) recipients.
      ;  Only CertContexts in the store with either
      ;  the CERT_KEY_PROV_HANDLE_PROP_ID or CERT_KEY_PROV_INFO_PROP_ID set
      ;  can be used. Either property specifies the private exchange key to use.
      ;  cbSize must be set to the sizeof(CRYPT_DECRYPT_MESSAGE_PARA) or else
      ;  LastError will be updated with E_INVALIDARG.
      ;--------------------------------------------------------------------------
      CRYPT_DECRYPT_MESSAGE_PARA struct
        cbSize DWORD ?
        dwMsgAndCertEncodingType DWORD ?
        cCertStore DWORD ?
        rghCertStore POINTER ?
        ifdef CRYPT_DECRYPT_MESSAGE_PARA_HAS_EXTRA_FIELDS
          ; The above defined, CRYPT_MESSAGE_SILENT_KEYSET_FLAG, can be set to
          ; suppress UI by the CSP.  See CryptAcquireContext's CRYPT_SILENT
          ; flag for more details.
          dwFlags DWORD ?
        endif
      CRYPT_DECRYPT_MESSAGE_PARA ends
      _CRYPT_DECRYPT_MESSAGE_PARA typedef CRYPT_DECRYPT_MESSAGE_PARA
      PCRYPT_DECRYPT_MESSAGE_PARA typedef ptr CRYPT_DECRYPT_MESSAGE_PARA
      ;+-------------------------------------------------------------------------
      ;  The CRYPT_HASH_MESSAGE_PARA are used for hashing or unhashing
      ;  messages.
      ;  hCryptProv is used to compute the hash.
      ;  pvHashAuxInfo currently isn't used and must be set to NULL.
      ;  cbSize must be set to the sizeof(CRYPT_HASH_MESSAGE_PARA) or else
      ;  LastError will be updated with E_INVALIDARG.
      ;--------------------------------------------------------------------------
      CRYPT_HASH_MESSAGE_PARA struct
        cbSize DWORD ?
        dwMsgEncodingType DWORD ?
        hCryptProv HCRYPTPROV_LEGACY ?
        HashAlgorithm CRYPT_ALGORITHM_IDENTIFIER <>
        pvHashAuxInfo POINTER ?
      CRYPT_HASH_MESSAGE_PARA ends
      _CRYPT_HASH_MESSAGE_PARA typedef CRYPT_HASH_MESSAGE_PARA
      PCRYPT_HASH_MESSAGE_PARA typedef ptr CRYPT_HASH_MESSAGE_PARA
      ;+-------------------------------------------------------------------------
      ;  The CRYPT_KEY_SIGN_MESSAGE_PARA are used for signing messages until a
      ;  certificate has been created for the signature key.
      ;  pvHashAuxInfo currently isn't used and must be set to NULL.
      ;  If PubKeyAlgorithm isn't set, defaults to szOID_RSA_RSA.
      ;  cbSize must be set to the sizeof(CRYPT_KEY_SIGN_MESSAGE_PARA) or else
      ;  LastError will be updated with E_INVALIDARG.
      ;--------------------------------------------------------------------------
      CRYPT_KEY_SIGN_MESSAGE_PARA struct
        cbSize DWORD ?
        dwMsgAndCertEncodingType DWORD ?
        ; NCryptIsKeyHandle() is called to determine the union choice.
        union
          hCryptProv HCRYPTPROV ?
          hNCryptKey NCRYPT_KEY_HANDLE ?
        ends
        ; not applicable for hNCryptKey choice
        dwKeySpec DWORD ?
        HashAlgorithm CRYPT_ALGORITHM_IDENTIFIER <>
        pvHashAuxInfo POINTER ?
        ; This is also referred to as the SignatureAlgorithm
        PubKeyAlgorithm CRYPT_ALGORITHM_IDENTIFIER <>
      CRYPT_KEY_SIGN_MESSAGE_PARA ends
      _CRYPT_KEY_SIGN_MESSAGE_PARA typedef CRYPT_KEY_SIGN_MESSAGE_PARA
      PCRYPT_KEY_SIGN_MESSAGE_PARA typedef ptr CRYPT_KEY_SIGN_MESSAGE_PARA
      ;+-------------------------------------------------------------------------
      ;  The CRYPT_KEY_VERIFY_MESSAGE_PARA are used to verify signed messages without
      ;  a certificate for the signer.
      ;  Normally used until a certificate has been created for the key.
      ;  hCryptProv is used to do hashing and signature verification.
      ;  cbSize must be set to the sizeof(CRYPT_KEY_VERIFY_MESSAGE_PARA) or else
      ;  LastError will be updated with E_INVALIDARG.
      ;--------------------------------------------------------------------------
      CRYPT_KEY_VERIFY_MESSAGE_PARA struct
        cbSize DWORD ?
        dwMsgEncodingType DWORD ?
        hCryptProv HCRYPTPROV_LEGACY ?
      CRYPT_KEY_VERIFY_MESSAGE_PARA ends
      _CRYPT_KEY_VERIFY_MESSAGE_PARA typedef CRYPT_KEY_VERIFY_MESSAGE_PARA
      PCRYPT_KEY_VERIFY_MESSAGE_PARA typedef ptr CRYPT_KEY_VERIFY_MESSAGE_PARA
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)*
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_PHONE_RESTRICTED or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      ;+-------------------------------------------------------------------------
      ;  Sign the message.
      ;  If fDetachedSignature is TRUE, the "to be signed" content isn't included
      ;  in the encoded signed blob.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CryptSignMessage, WIN_STD_CALL_CONV,, <:PCRYPT_SIGN_MESSAGE_PARA, :BOOL, :DWORD, :ptr ptr BYTE, :ptr DWORD, :ptr BYTE, :ptr DWORD>, 28
      ;+-------------------------------------------------------------------------
      ;  Verify a signed message.
      ;  If pbDecoded == NULL, then, *pcbDecoded is implicitly set to 0 on input.
      ;  For *pcbDecoded == 0 && ppSignerCert == NULL on input, the signer isn't
      ;  verified.
      ;  A message might have more than one signer. Set dwSignerIndex to iterate
      ;  through all the signers. dwSignerIndex == 0 selects the first signer.
      ;  pVerifyPara's pfnGetSignerCertificate is called to get the signer's
      ;  certificate.
      ;  For a verified signer and message, *ppSignerCert is updated
      ;  with the CertContext of the signer. It must be freed by calling
      ;  CertFreeCertificateContext. Otherwise, *ppSignerCert is set to NULL.
      ;  ppSignerCert can be NULL, indicating the caller isn't interested
      ;  in getting the CertContext of the signer.
      ;  pcbDecoded can be NULL, indicating the caller isn't interested in getting
      ;  the decoded content. Furthermore, if the message doesn't contain any
      ;  content or signers, then, pcbDecoded must be set to NULL, to allow the
      ;  pVerifyPara->pfnGetCertificate to be called. Normally, this would be
      ;  the case when the signed message contains only certficates and CRLs.
      ;  If pcbDecoded is NULL and the message doesn't have the indicated signer,
      ;  pfnGetCertificate is called with pSignerId set to NULL.
      ;  If the message doesn't contain any signers || dwSignerIndex > message's
      ;  SignerCount, then, an error is returned with LastError set to
      ;  CRYPT_E_NO_SIGNER. Also, for CRYPT_E_NO_SIGNER, pfnGetSignerCertificate
      ;  is still called with pSignerId set to NULL.
      ;  Note, an alternative way to get the certificates and CRLs from a
      ;  signed message is to call CryptGetMessageCertificates.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CryptVerifyMessageSignature, WIN_STD_CALL_CONV,, <:PCRYPT_VERIFY_MESSAGE_PARA, :DWORD, :ptr BYTE, :DWORD, :ptr BYTE, :ptr DWORD, :ptr PCCERT_CONTEXT>, 28
      ;+-------------------------------------------------------------------------
      ;  Returns the count of signers in the signed message. For no signers, returns
      ;  0. For an error returns -1 with LastError updated accordingly.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CryptGetMessageSignerCount, WIN_STD_CALL_CONV,, <:DWORD, :ptr BYTE, :DWORD>, 12
      ;+-------------------------------------------------------------------------
      ;  Returns the cert store containing the message's certs and CRLs.
      ;  For an error, returns NULL with LastError updated.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CryptGetMessageCertificates, WIN_STD_CALL_CONV,, <:DWORD, :HCRYPTPROV_LEGACY, :DWORD, :ptr BYTE, :DWORD>, 20
      ; passed to CertOpenStore
      ;+-------------------------------------------------------------------------
      ;  Verify a signed message containing detached signature(s).
      ;  The "to be signed" content is passed in separately. No
      ;  decoded output. Otherwise, identical to CryptVerifyMessageSignature.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CryptVerifyDetachedMessageSignature, WIN_STD_CALL_CONV,, <:PCRYPT_VERIFY_MESSAGE_PARA, :DWORD, :ptr BYTE, :DWORD, :DWORD, :ptr ptr BYTE, :ptr DWORD, :ptr PCCERT_CONTEXT>, 32
      ;+-------------------------------------------------------------------------
      ;  Encrypts the message for the recipient(s).
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CryptEncryptMessage, WIN_STD_CALL_CONV,, <:PCRYPT_ENCRYPT_MESSAGE_PARA, :DWORD, :ptr PCCERT_CONTEXT, :ptr BYTE, :DWORD, :ptr BYTE, :ptr DWORD>, 28
      ;+-------------------------------------------------------------------------
      ;  Decrypts the message.
      ;  If pbDecrypted == NULL, then, *pcbDecrypted is implicitly set to 0 on input.
      ;  For *pcbDecrypted == 0 && ppXchgCert == NULL on input, the message isn't
      ;  decrypted.
      ;  For a successfully decrypted message, *ppXchgCert is updated
      ;  with the CertContext used to decrypt. It must be freed by calling
      ;  CertStoreFreeCert. Otherwise, *ppXchgCert is set to NULL.
      ;  ppXchgCert can be NULL, indicating the caller isn't interested
      ;  in getting the CertContext used to decrypt.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CryptDecryptMessage, WIN_STD_CALL_CONV,, <:PCRYPT_DECRYPT_MESSAGE_PARA, :ptr BYTE, :DWORD, :ptr BYTE, :ptr DWORD, :ptr PCCERT_CONTEXT>, 24
      ;+-------------------------------------------------------------------------
      ;  Sign the message and encrypt for the recipient(s). Does a CryptSignMessage
      ;  followed with a CryptEncryptMessage.
      ;  Note: this isn't the CMSG_SIGNED_AND_ENVELOPED. Its a CMSG_SIGNED
      ;  inside of an CMSG_ENVELOPED.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CryptSignAndEncryptMessage, WIN_STD_CALL_CONV,, <:PCRYPT_SIGN_MESSAGE_PARA, :PCRYPT_ENCRYPT_MESSAGE_PARA, :DWORD, :ptr PCCERT_CONTEXT, :ptr BYTE, :DWORD, :ptr BYTE, :ptr DWORD>, 32
      ;+-------------------------------------------------------------------------
      ;  Decrypts the message and verifies the signer. Does a CryptDecryptMessage
      ;  followed with a CryptVerifyMessageSignature.
      ;  If pbDecrypted == NULL, then, *pcbDecrypted is implicitly set to 0 on input.
      ;  For *pcbDecrypted == 0 && ppSignerCert == NULL on input, the signer isn't
      ;  verified.
      ;  A message might have more than one signer. Set dwSignerIndex to iterate
      ;  through all the signers. dwSignerIndex == 0 selects the first signer.
      ;  The pVerifyPara's VerifySignerPolicy is called to verify the signer's
      ;  certificate.
      ;  For a successfully decrypted and verified message, *ppXchgCert and
      ;  *ppSignerCert are updated. They must be freed by calling
      ;  CertStoreFreeCert. Otherwise, they are set to NULL.
      ;  ppXchgCert and/or ppSignerCert can be NULL, indicating the
      ;  caller isn't interested in getting the CertContext.
      ;  Note: this isn't the CMSG_SIGNED_AND_ENVELOPED. Its a CMSG_SIGNED
      ;  inside of an CMSG_ENVELOPED.
      ;  The message always needs to be decrypted to allow access to the
      ;  signed message. Therefore, if ppXchgCert != NULL, its always updated.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CryptDecryptAndVerifyMessageSignature, WIN_STD_CALL_CONV,, <:PCRYPT_DECRYPT_MESSAGE_PARA, :PCRYPT_VERIFY_MESSAGE_PARA, :DWORD, :ptr BYTE, :DWORD, :ptr BYTE, :ptr DWORD, :ptr PCCERT_CONTEXT, :ptr PCCERT_CONTEXT>, 36
      ;+-------------------------------------------------------------------------
      ;  Decodes a cryptographic message which may be one of the following types:
      ;    CMSG_DATA
      ;    CMSG_SIGNED
      ;    CMSG_ENVELOPED
      ;    CMSG_SIGNED_AND_ENVELOPED
      ;    CMSG_HASHED
      ;  dwMsgTypeFlags specifies the set of allowable messages. For example, to
      ;  decode either SIGNED or ENVELOPED messages, set dwMsgTypeFlags to:
      ;      CMSG_SIGNED_FLAG | CMSG_ENVELOPED_FLAG.
      ;  dwProvInnerContentType is only applicable when processing nested
      ;  crytographic messages. When processing an outer crytographic message
      ;  it must be set to 0. When decoding a nested cryptographic message
      ;  its the dwInnerContentType returned by a previous CryptDecodeMessage
      ;  of the outer message. The InnerContentType can be any of the CMSG types,
      ;  for example, CMSG_DATA, CMSG_SIGNED, ...
      ;  The optional *pdwMsgType is updated with the type of message.
      ;  The optional *pdwInnerContentType is updated with the type of the inner
      ;  message. Unless there is cryptographic message nesting, CMSG_DATA
      ;  is returned.
      ;  For CMSG_DATA: returns decoded content.
      ;  For CMSG_SIGNED: same as CryptVerifyMessageSignature.
      ;  For CMSG_ENVELOPED: same as CryptDecryptMessage.
      ;  For CMSG_SIGNED_AND_ENVELOPED: same as CryptDecryptMessage plus
      ;      CryptVerifyMessageSignature.
      ;  For CMSG_HASHED: verifies the hash and returns decoded content.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CryptDecodeMessage, WIN_STD_CALL_CONV,, <:DWORD, :PCRYPT_DECRYPT_MESSAGE_PARA, :PCRYPT_VERIFY_MESSAGE_PARA, :DWORD, :ptr BYTE, :DWORD, :DWORD, :ptr DWORD, :ptr DWORD, :ptr BYTE, :ptr DWORD, :ptr PCCERT_CONTEXT, :ptr PCCERT_CONTEXT>, 52
      ;+-------------------------------------------------------------------------
      ;  Hash the message.
      ;  If fDetachedHash is TRUE, only the ComputedHash is encoded in the
      ;  pbHashedBlob. Otherwise, both the ToBeHashed and ComputedHash
      ;  are encoded.
      ;  pcbHashedBlob or pcbComputedHash can be NULL, indicating the caller
      ;  isn't interested in getting the output.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CryptHashMessage, WIN_STD_CALL_CONV,, <:PCRYPT_HASH_MESSAGE_PARA, :BOOL, :DWORD, :ptr ptr BYTE, :ptr DWORD, :ptr BYTE, :ptr DWORD, :ptr BYTE, :ptr DWORD>, 36
      ;+-------------------------------------------------------------------------
      ;  Verify a hashed message.
      ;  pcbToBeHashed or pcbComputedHash can be NULL,
      ;  indicating the caller isn't interested in getting the output.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CryptVerifyMessageHash, WIN_STD_CALL_CONV,, <:PCRYPT_HASH_MESSAGE_PARA, :ptr BYTE, :DWORD, :ptr BYTE, :ptr DWORD, :ptr BYTE, :ptr DWORD>, 28
      ;+-------------------------------------------------------------------------
      ;  Verify a hashed message containing a detached hash.
      ;  The "to be hashed" content is passed in separately. No
      ;  decoded output. Otherwise, identical to CryptVerifyMessageHash.
      ;  pcbComputedHash can be NULL, indicating the caller isn't interested
      ;  in getting the output.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CryptVerifyDetachedMessageHash, WIN_STD_CALL_CONV,, <:PCRYPT_HASH_MESSAGE_PARA, :ptr BYTE, :DWORD, :DWORD, :ptr ptr BYTE, :ptr DWORD, :ptr BYTE, :ptr DWORD>, 32
      ;+-------------------------------------------------------------------------
      ;  Sign the message using the provider's private key specified in the
      ;  parameters. A dummy SignerId is created and stored in the message.
      ;  Normally used until a certificate has been created for the key.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CryptSignMessageWithKey, WIN_STD_CALL_CONV,, <:PCRYPT_KEY_SIGN_MESSAGE_PARA, :ptr BYTE, :DWORD, :ptr BYTE, :ptr DWORD>, 20
      ;+-------------------------------------------------------------------------
      ;  Verify a signed message using the specified public key info.
      ;  Normally called by a CA until it has created a certificate for the
      ;  key.
      ;  pPublicKeyInfo contains the public key to use to verify the signed
      ;  message. If NULL, the signature isn't verified (for instance, the decoded
      ;  content may contain the PublicKeyInfo).
      ;  pcbDecoded can be NULL, indicating the caller isn't interested
      ;  in getting the decoded content.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CryptVerifyMessageSignatureWithKey, WIN_STD_CALL_CONV,, <:PCRYPT_KEY_VERIFY_MESSAGE_PARA, :PCERT_PUBLIC_KEY_INFO, :ptr BYTE, :DWORD, :ptr BYTE, :ptr DWORD>, 24
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP|WINAPI_PARTITION_PHONE_RESTRICTED | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_PHONE_RESTRICTED or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      ;+=========================================================================
      ;  System Certificate Store Data Structures and APIs
      ;==========================================================================
      ;+-------------------------------------------------------------------------
      ;  Get a system certificate store based on a subsystem protocol.
      ;  Current examples of subsystems protocols are:
      ;      "MY"    Cert Store hold certs with associated Private Keys
      ;      "CA"    Certifying Authority certs
      ;      "ROOT"  Root Certs
      ;      "SPC"   Software publisher certs
      ;  If hProv is NULL the default provider "1" is opened for you.
      ;  When the store is closed the provider is release. Otherwise
      ;  if hProv is not NULL, no provider is created or released.
      ;  The returned Cert Store can be searched for an appropriate Cert
      ;  using the Cert Store API's (see certstor.h)
      ;  When done, the cert store should be closed using CertStoreClose
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertOpenSystemStoreA, WIN_STD_CALL_CONV,, <:HCRYPTPROV_LEGACY, :LPCSTR>, 8
      @DefProto DllImport, CertOpenSystemStoreW, WIN_STD_CALL_CONV,, <:HCRYPTPROV_LEGACY, :LPCWSTR>, 8
      ifdef UNICODE
        CertOpenSystemStore equ <CertOpenSystemStoreW>
      else
        CertOpenSystemStore equ <CertOpenSystemStoreA>
      endif
      ; !UNICODE
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_PHONE_RESTRICTED | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_PHONE_RESTRICTED or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      @DefProto DllImport, CertAddEncodedCertificateToSystemStoreA, WIN_STD_CALL_CONV,, <:LPCSTR, :ptr BYTE, :DWORD>, 12
      @DefProto DllImport, CertAddEncodedCertificateToSystemStoreW, WIN_STD_CALL_CONV,, <:LPCWSTR, :ptr BYTE, :DWORD>, 12
      ifdef UNICODE
        CertAddEncodedCertificateToSystemStore equ <CertAddEncodedCertificateToSystemStoreW>
      else
        CertAddEncodedCertificateToSystemStore equ <CertAddEncodedCertificateToSystemStoreA>
      endif
      ; !UNICODE
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP|WINAPI_PARTITION_PHONE_RESTRICTED | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_PHONE_RESTRICTED or WINAPI_PARTITION_PKG_WINTRUST or WINAPI_PARTITION_GAMES)
      ;+-------------------------------------------------------------------------
      ;  Find all certificate chains tying the given issuer name to any certificate
      ;  that the current user has a private key for.
      ;  If no certificate chain is found, FALSE is returned with LastError set
      ;  to CRYPT_E_NOT_FOUND and the counts zeroed.
      ;  IE 3.0 ASSUMPTION:
      ;   The client certificates are in the "My" system store. The issuer
      ;   cerificates may be in the "Root", "CA" or "My" system stores.
      ;--------------------------------------------------------------------------
      CERT_CHAIN struct
        cCerts DWORD ?
        ; number of certs in chain
        certs PCERT_BLOB ?
        ; pointer to array of cert chain blobs
        ; representing the certs
        keyLocatorInfo CRYPT_KEY_PROV_INFO <>
        ; key locator for cert
      CERT_CHAIN ends
      _CERT_CHAIN typedef CERT_CHAIN
      PCERT_CHAIN typedef ptr CERT_CHAIN
      ; WINCRYPT32API    This is not exported by crypt32, it is exported by softpub
      FindCertsByIssuer proto WIN_STD_CALL_CONV :PCERT_CHAIN, :ptr DWORD, :ptr DWORD, :ptr BYTE, :DWORD, :LPCWSTR, :DWORD
      ; keyspec
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP |WINAPI_PARTITION_PHONE_RESTRICTED | WINAPI_PARTITION_PKG_WINTRUST | WINAPI_PARTITION_GAMES) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      ;-------------------------------------------------------------------------
      ;  CryptQueryObject takes a CERT_BLOB or a file name and returns the
      ;  information about the content in the blob or in the file.
      ;  Parameters:
      ;  INPUT   dwObjectType:
      ;                       Indicate the type of the object.  Should be one of the
      ;                       following:
      ;                          CERT_QUERY_OBJECT_FILE
      ;                          CERT_QUERY_OBJECT_BLOB
      ;  INPUT   pvObject:
      ;                        If dwObjectType == CERT_QUERY_OBJECT_FILE, it is a
      ;                        LPWSTR, that is, the pointer to a wchar file name
      ;                        if dwObjectType == CERT_QUERY_OBJECT_BLOB, it is a
      ;                        PCERT_BLOB, that is, a pointer to a CERT_BLOB
      ;  INPUT   dwExpectedContentTypeFlags:
      ;                        Indicate the expected contenet type.
      ;                        Can be one of the following:
      ;                              CERT_QUERY_CONTENT_FLAG_ALL  (the content can be any type)
      ;                              CERT_QUERY_CONTENT_FLAG_CERT
      ;                              CERT_QUERY_CONTENT_FLAG_CTL
      ;                              CERT_QUERY_CONTENT_FLAG_CRL
      ;                              CERT_QUERY_CONTENT_FLAG_SERIALIZED_STORE
      ;                              CERT_QUERY_CONTENT_FLAG_SERIALIZED_CERT
      ;                              CERT_QUERY_CONTENT_FLAG_SERIALIZED_CTL
      ;                              CERT_QUERY_CONTENT_FLAG_SERIALIZED_CRL
      ;                              CERT_QUERY_CONTENT_FLAG_PKCS7_SIGNED
      ;                              CERT_QUERY_CONTENT_FLAG_PKCS7_UNSIGNED
      ;                              CERT_QUERY_CONTENT_FLAG_PKCS7_SIGNED_EMBED
      ;                              CERT_QUERY_CONTENT_FLAG_PKCS10
      ;                              CERT_QUERY_CONTENT_FLAG_PFX
      ;                              CERT_QUERY_CONTENT_FLAG_CERT_PAIR
      ;                              CERT_QUERY_CONTENT_FLAG_PFX_AND_LOAD
      ;  INPUT   dwExpectedFormatTypeFlags:
      ;                        Indicate the expected format type.
      ;                        Can be one of the following:
      ;                              CERT_QUERY_FORMAT_FLAG_ALL (the content can be any format)
      ;                              CERT_QUERY_FORMAT_FLAG_BINARY
      ;                              CERT_QUERY_FORMAT_FLAG_BASE64_ENCODED
      ;                              CERT_QUERY_FORMAT_FLAG_ASN_ASCII_HEX_ENCODED
      ;  INPUT   dwFlags
      ;                        Reserved flag.  Should always set to 0
      ;  OUTPUT  pdwMsgAndCertEncodingType
      ;                        Optional output.  If NULL != pdwMsgAndCertEncodingType,
      ;                        it contains the encoding type of the content as any
      ;                        combination of the following:
      ;                              X509_ASN_ENCODING
      ;                              PKCS_7_ASN_ENCODING
      ;  OUTPUT  pdwContentType
      ;                        Optional output.  If NULL!=pdwContentType, it contains
      ;                        the content type as one of the the following:
      ;                              CERT_QUERY_CONTENT_CERT
      ;                              CERT_QUERY_CONTENT_CTL
      ;                              CERT_QUERY_CONTENT_CRL
      ;                              CERT_QUERY_CONTENT_SERIALIZED_STORE
      ;                              CERT_QUERY_CONTENT_SERIALIZED_CERT
      ;                              CERT_QUERY_CONTENT_SERIALIZED_CTL
      ;                              CERT_QUERY_CONTENT_SERIALIZED_CRL
      ;                              CERT_QUERY_CONTENT_PKCS7_SIGNED
      ;                              CERT_QUERY_CONTENT_PKCS7_UNSIGNED
      ;                              CERT_QUERY_CONTENT_PKCS7_SIGNED_EMBED
      ;                              CERT_QUERY_CONTENT_PKCS10
      ;                              CERT_QUERY_CONTENT_PFX
      ;                              CERT_QUERY_CONTENT_CERT_PAIR
      ;                              CERT_QUERY_CONTENT_PFX_AND_LOAD
      ;  OUTPUT  pdwFormatType
      ;                        Optional output.  If NULL !=pdwFormatType, it
      ;                        contains the format type of the content as one of the
      ;                        following:
      ;                              CERT_QUERY_FORMAT_BINARY
      ;                              CERT_QUERY_FORMAT_BASE64_ENCODED
      ;                              CERT_QUERY_FORMAT_ASN_ASCII_HEX_ENCODED
      ;  OUTPUT  phCertStore
      ;                        Optional output.  If NULL !=phStore,
      ;                        it contains a cert store that includes all of certificates,
      ;                        CRL, and CTL in the object if the object content type is
      ;                        one of the following:
      ;                              CERT_QUERY_CONTENT_CERT
      ;                              CERT_QUERY_CONTENT_CTL
      ;                              CERT_QUERY_CONTENT_CRL
      ;                              CERT_QUERY_CONTENT_SERIALIZED_STORE
      ;                              CERT_QUERY_CONTENT_SERIALIZED_CERT
      ;                              CERT_QUERY_CONTENT_SERIALIZED_CTL
      ;                              CERT_QUERY_CONTENT_SERIALIZED_CRL
      ;                              CERT_QUERY_CONTENT_PKCS7_SIGNED
      ;                              CERT_QUERY_CONTENT_PKCS7_SIGNED_EMBED
      ;                              CERT_QUERY_CONTENT_CERT_PAIR
      ;                       Caller should free *phCertStore via CertCloseStore.
      ;  OUTPUT  phMsg        Optional output.  If NULL != phMsg,
      ;                        it contains a handle to a opened message if
      ;                        the content type is one of the following:
      ;                              CERT_QUERY_CONTENT_PKCS7_SIGNED
      ;                              CERT_QUERY_CONTENT_PKCS7_UNSIGNED
      ;                              CERT_QUERY_CONTENT_PKCS7_SIGNED_EMBED
      ;                       Caller should free *phMsg via CryptMsgClose.
      ;  OUTPUT pContext     Optional output.  If NULL != pContext,
      ;                      it contains either a PCCERT_CONTEXT or PCCRL_CONTEXT,
      ;                      or PCCTL_CONTEXT based on the content type.
      ;                      If the content type is CERT_QUERY_CONTENT_CERT or
      ;                      CERT_QUERY_CONTENT_SERIALIZED_CERT, it is a PCCERT_CONTEXT;
      ;                      Caller should free the pContext via CertFreeCertificateContext.
      ;                      If the content type is CERT_QUERY_CONTENT_CRL or
      ;                      CERT_QUERY_CONTENT_SERIALIZED_CRL, it is a PCCRL_CONTEXT;
      ;                      Caller should free the pContext via CertFreeCRLContext.
      ;                      If the content type is CERT_QUERY_CONTENT_CTL or
      ;                      CERT_QUERY_CONTENT_SERIALIZED_CTL, it is a PCCTL_CONTEXT;
      ;                      Caller should free the pContext via CertFreeCTLContext.
      ;  If the *pbObject is of type CERT_QUERY_CONTENT_PKCS10 or CERT_QUERY_CONTENT_PFX, CryptQueryObject
      ;  will not return anything in *phCertstore, *phMsg, or *ppvContext.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CryptQueryObject, WIN_STD_CALL_CONV,, <:DWORD, :ptr, :DWORD, :DWORD, :DWORD, :ptr DWORD, :ptr DWORD, :ptr DWORD, :ptr HCERTSTORE, :ptr HCRYPTMSG, :ptr ptr>, 44
      ;-------------------------------------------------------------------------
      ;dwObjectType for CryptQueryObject
      ;-------------------------------------------------------------------------
      CERT_QUERY_OBJECT_FILE equ 00000001h
      CERT_QUERY_OBJECT_BLOB equ 00000002h
      ;-------------------------------------------------------------------------
      ;dwContentType for CryptQueryObject
      ;-------------------------------------------------------------------------
      ;encoded single certificate
      CERT_QUERY_CONTENT_CERT equ 1
      ;encoded single CTL
      CERT_QUERY_CONTENT_CTL equ 2
      ;encoded single CRL
      CERT_QUERY_CONTENT_CRL equ 3
      ;serialized store
      CERT_QUERY_CONTENT_SERIALIZED_STORE equ 4
      ;serialized single certificate
      CERT_QUERY_CONTENT_SERIALIZED_CERT equ 5
      ;serialized single CTL
      CERT_QUERY_CONTENT_SERIALIZED_CTL equ 6
      ;serialized single CRL
      CERT_QUERY_CONTENT_SERIALIZED_CRL equ 7
      ;a PKCS#7 signed message
      CERT_QUERY_CONTENT_PKCS7_SIGNED equ 8
      ;a PKCS#7 message, such as enveloped message.  But it is not a signed message,
      CERT_QUERY_CONTENT_PKCS7_UNSIGNED equ 9
      ;a PKCS7 signed message embedded in a file
      CERT_QUERY_CONTENT_PKCS7_SIGNED_EMBED equ 10
      ;an encoded PKCS#10
      CERT_QUERY_CONTENT_PKCS10 equ 11
      ;an encoded PFX BLOB
      CERT_QUERY_CONTENT_PFX equ 12
      ;an encoded CertificatePair (contains forward and/or reverse cross certs)
      CERT_QUERY_CONTENT_CERT_PAIR equ 13
      ;an encoded PFX BLOB, which was loaded to phCertStore
      CERT_QUERY_CONTENT_PFX_AND_LOAD equ 14
      ;-------------------------------------------------------------------------
      ;dwExpectedConentTypeFlags for CryptQueryObject
      ;-------------------------------------------------------------------------
      ;encoded single certificate
      CERT_QUERY_CONTENT_FLAG_CERT equ (1 shl CERT_QUERY_CONTENT_CERT)
      ;encoded single CTL
      CERT_QUERY_CONTENT_FLAG_CTL equ (1 shl CERT_QUERY_CONTENT_CTL)
      ;encoded single CRL
      CERT_QUERY_CONTENT_FLAG_CRL equ (1 shl CERT_QUERY_CONTENT_CRL)
      ;serialized store
      CERT_QUERY_CONTENT_FLAG_SERIALIZED_STORE equ (1 shl CERT_QUERY_CONTENT_SERIALIZED_STORE)
      ;serialized single certificate
      CERT_QUERY_CONTENT_FLAG_SERIALIZED_CERT equ (1 shl CERT_QUERY_CONTENT_SERIALIZED_CERT)
      ;serialized single CTL
      CERT_QUERY_CONTENT_FLAG_SERIALIZED_CTL equ (1 shl CERT_QUERY_CONTENT_SERIALIZED_CTL)
      ;serialized single CRL
      CERT_QUERY_CONTENT_FLAG_SERIALIZED_CRL equ (1 shl CERT_QUERY_CONTENT_SERIALIZED_CRL)
      ;an encoded PKCS#7 signed message
      CERT_QUERY_CONTENT_FLAG_PKCS7_SIGNED equ (1 shl CERT_QUERY_CONTENT_PKCS7_SIGNED)
      ;an encoded PKCS#7 message.  But it is not a signed message
      CERT_QUERY_CONTENT_FLAG_PKCS7_UNSIGNED equ (1 shl CERT_QUERY_CONTENT_PKCS7_UNSIGNED)
      ;the content includes an embedded PKCS7 signed message
      CERT_QUERY_CONTENT_FLAG_PKCS7_SIGNED_EMBED equ (1 shl CERT_QUERY_CONTENT_PKCS7_SIGNED_EMBED)
      ;an encoded PKCS#10
      CERT_QUERY_CONTENT_FLAG_PKCS10 equ (1 shl CERT_QUERY_CONTENT_PKCS10)
      ;an encoded PFX BLOB
      CERT_QUERY_CONTENT_FLAG_PFX equ (1 shl CERT_QUERY_CONTENT_PFX)
      ;an encoded CertificatePair (contains forward and/or reverse cross certs)
      CERT_QUERY_CONTENT_FLAG_CERT_PAIR equ (1 shl CERT_QUERY_CONTENT_CERT_PAIR)
      ;an encoded PFX BLOB, and we do want to load it (not included in
      ;CERT_QUERY_CONTENT_FLAG_ALL)
      CERT_QUERY_CONTENT_FLAG_PFX_AND_LOAD equ (1 shl CERT_QUERY_CONTENT_PFX_AND_LOAD)
      ;content can be any type
      CERT_QUERY_CONTENT_FLAG_ALL equ <(CERT_QUERY_CONTENT_FLAG_CERT or CERT_QUERY_CONTENT_FLAG_CTL or CERT_QUERY_CONTENT_FLAG_CRL or CERT_QUERY_CONTENT_FLAG_SERIALIZED_STORE or CERT_QUERY_CONTENT_FLAG_SERIALIZED_CERT or CERT_QUERY_CONTENT_FLAG_SERIALIZED_CTL or CERT_QUERY_CONTENT_FLAG_SERIALIZED_CRL or CERT_QUERY_CONTENT_FLAG_PKCS7_SIGNED or CERT_QUERY_CONTENT_FLAG_PKCS7_UNSIGNED or CERT_QUERY_CONTENT_FLAG_PKCS7_SIGNED_EMBED or CERT_QUERY_CONTENT_FLAG_PKCS10 or CERT_QUERY_CONTENT_FLAG_PFX or CERT_QUERY_CONTENT_FLAG_CERT_PAIR)>
      ;content types allowed for Issuer certificates
      CERT_QUERY_CONTENT_FLAG_ALL_ISSUER_CERT equ <(CERT_QUERY_CONTENT_FLAG_CERT or CERT_QUERY_CONTENT_FLAG_SERIALIZED_STORE or CERT_QUERY_CONTENT_FLAG_SERIALIZED_CERT or CERT_QUERY_CONTENT_FLAG_PKCS7_SIGNED or CERT_QUERY_CONTENT_FLAG_PKCS7_UNSIGNED)>
      ;-------------------------------------------------------------------------
      ;dwFormatType for CryptQueryObject
      ;-------------------------------------------------------------------------
      ;the content is in binary format
      CERT_QUERY_FORMAT_BINARY equ 1
      ;the content is base64 encoded
      CERT_QUERY_FORMAT_BASE64_ENCODED equ 2
      ;the content is ascii hex encoded with "{ASN}" prefix
      CERT_QUERY_FORMAT_ASN_ASCII_HEX_ENCODED equ 3
      ;-------------------------------------------------------------------------
      ;dwExpectedFormatTypeFlags for CryptQueryObject
      ;-------------------------------------------------------------------------
      ;the content is in binary format
      CERT_QUERY_FORMAT_FLAG_BINARY equ (1 shl CERT_QUERY_FORMAT_BINARY)
      ;the content is base64 encoded
      CERT_QUERY_FORMAT_FLAG_BASE64_ENCODED equ (1 shl CERT_QUERY_FORMAT_BASE64_ENCODED)
      ;the content is ascii hex encoded with "{ASN}" prefix
      CERT_QUERY_FORMAT_FLAG_ASN_ASCII_HEX_ENCODED equ (1 shl CERT_QUERY_FORMAT_ASN_ASCII_HEX_ENCODED)
      ;the content can be of any format
      CERT_QUERY_FORMAT_FLAG_ALL equ <(CERT_QUERY_FORMAT_FLAG_BINARY or CERT_QUERY_FORMAT_FLAG_BASE64_ENCODED or CERT_QUERY_FORMAT_FLAG_ASN_ASCII_HEX_ENCODED)>
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)*
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_PHONE_RESTRICTED or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      ; Crypt32 Memory Management Routines.  All Crypt32 API which return allocated
      ; buffers will do so via CryptMemAlloc, CryptMemRealloc.  Clients can free
      ; those buffers using CryptMemFree.  Also included is CryptMemSize
      @DefProto DllImport, CryptMemAlloc, WIN_STD_CALL_CONV,, <:ULONG>, 4
      @DefProto DllImport, CryptMemRealloc, WIN_STD_CALL_CONV,, <:LPVOID, :ULONG>, 8
      @DefProto DllImport, CryptMemFree, WIN_STD_CALL_CONV,, <:LPVOID>, 4
      ; Crypt32 Asynchronous Parameter Management Routines.  All Crypt32 API which
      ; expose asynchronous mode operation use a Crypt32 Async Handle to pass
      ; around information about the operation e.g. callback routines.  The
      ; following API are used for manipulation of the async handle
      ; Following functions were never used. If called, will fail with LastError
      ; set to ERROR_CALL_NOT_IMPLEMENTED.
      HCRYPTASYNC typedef HANDLE
      PHCRYPTASYNC typedef ptr HANDLE
      TYPE_PFN_CRYPT_ASYNC_PARAM_FREE_FUNC typedef proto WIN_STD_CALL_CONV :LPSTR, :LPVOID
      PFN_CRYPT_ASYNC_PARAM_FREE_FUNC typedef ptr TYPE_PFN_CRYPT_ASYNC_PARAM_FREE_FUNC

      @DefProto DllImport, CryptCreateAsyncHandle, WIN_STD_CALL_CONV,, <:DWORD, :PHCRYPTASYNC>, 8
      @DefProto DllImport, CryptSetAsyncParam, WIN_STD_CALL_CONV,, <:HCRYPTASYNC, :LPSTR, :LPVOID, :PFN_CRYPT_ASYNC_PARAM_FREE_FUNC>, 16
      @DefProto DllImport, CryptGetAsyncParam, WIN_STD_CALL_CONV,, <:HCRYPTASYNC, :LPSTR, :ptr LPVOID, :ptr PFN_CRYPT_ASYNC_PARAM_FREE_FUNC>, 16
      @DefProto DllImport, CryptCloseAsyncHandle, WIN_STD_CALL_CONV,, <:HCRYPTASYNC>, 4
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP|WINAPI_PARTITION_PHONE_RESTRICTED | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      ; Crypt32 Remote Object Retrieval Routines.  This API allows retrieval of
      ; remote PKI objects where the location is given by an URL.  The remote
      ; object retrieval manager exposes two provider models.  One is the "Scheme
      ; Provider" model which allows for installable protocol providers as defined
      ; by the URL scheme e.g. ldap, http, ftp.  The scheme provider entry point is
      ; the same as the CryptRetrieveObjectByUrl however the *ppvObject returned
      ; is ALWAYS a counted array of encoded bits (one per object retrieved).  The
      ; second provider model is the "Context Provider" model which allows for
      ; installable creators of CAPI2 context handles (objects) based on the
      ; retrieved encoded bits.  These are dispatched based on the object OID given
      ; in the call to CryptRetrieveObjectByUrl.
      CRYPT_BLOB_ARRAY struct
        cBlob DWORD ?
        rgBlob PCRYPT_DATA_BLOB ?
      CRYPT_BLOB_ARRAY ends
      _CRYPT_BLOB_ARRAY typedef CRYPT_BLOB_ARRAY
      PCRYPT_BLOB_ARRAY typedef ptr CRYPT_BLOB_ARRAY
      CRYPT_CREDENTIALS struct
        cbSize DWORD ?
        pszCredentialsOid =POINTER ?
        pvCredentials POINTER ?
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
      ;UNICODE
      CRYPT_PASSWORD_CREDENTIALSA struct
        cbSize DWORD ?
        pszUsername POINTER ?
        pszPassword POINTER ?
      CRYPT_PASSWORD_CREDENTIALSA ends
      _CRYPT_PASSWORD_CREDENTIALSA typedef CRYPT_PASSWORD_CREDENTIALSA
      PCRYPT_PASSWORD_CREDENTIALSA typedef ptr CRYPT_PASSWORD_CREDENTIALSA
      CRYPT_PASSWORD_CREDENTIALSW struct
        cbSize DWORD ?
        pszUsername POINTER ?
        pszPassword POINTER ?
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
      ; UNICODE
      ; Scheme Provider Signatures
      ; The following is obsolete and has been replaced with the following
      ; definition
      SCHEME_OID_RETRIEVE_ENCODED_OBJECT_FUNC equ <"SchemeDllRetrieveEncodedObject">
      ; 2-8-02 Server 2003 changed to use UNICODE Url strings instead of multibyte
      SCHEME_OID_RETRIEVE_ENCODED_OBJECTW_FUNC equ <"SchemeDllRetrieveEncodedObjectW">
      TYPE_PFN_FREE_ENCODED_OBJECT_FUNC typedef proto WIN_STD_CALL_CONV :LPCSTR, :PCRYPT_BLOB_ARRAY, :LPVOID
      PFN_FREE_ENCODED_OBJECT_FUNC typedef ptr TYPE_PFN_FREE_ENCODED_OBJECT_FUNC

      ; SchemeDllRetrieveEncodedObject was replaced in Server 2003 with
      ; the following. (Changed to use UNICODE Url Strings.)
      ; SchemeDllRetrieveEncodedObjectW has the following signature:
      ; _Success_(return != FALSE)
      ; BOOL WINAPI SchemeDllRetrieveEncodedObjectW (
      ;                   _In_ LPCWSTR pwszUrl,
      ;                   _In_opt_ LPCSTR pszObjectOid,
      ;                   _In_ DWORD dwRetrievalFlags,
      ;                   _In_ DWORD dwTimeout,                // milliseconds
      ;                   _Out_ PCRYPT_BLOB_ARRAY pObject,
      ;                   _Outptr_ __callback PFN_FREE_ENCODED_OBJECT_FUNC* ppfnFreeObject,
      ;                   _Outptr_result_maybenull_ LPVOID* ppvFreeContext,
      ;                   _In_opt_ HCRYPTASYNC hAsyncRetrieve,
      ;                   _In_opt_ PCRYPT_CREDENTIALS pCredentials,
      ;                   _Inout_opt_ PCRYPT_RETRIEVE_AUX_INFO pAuxInfo
      ;                   )
      ; Context Provider Signatures
      CONTEXT_OID_CREATE_OBJECT_CONTEXT_FUNC equ <"ContextDllCreateObjectContext">
      CONTEXT_OID_CERTIFICATE equ (1)
      CONTEXT_OID_CRL equ (2)
      CONTEXT_OID_CTL equ (3)
      CONTEXT_OID_PKCS7 equ (4)
      CONTEXT_OID_CAPI2_ANY equ (5)
      CONTEXT_OID_OCSP_RESP equ (6)
      ; ContextDllCreateObjectContext has the following signature:
      ; _Success_(return != FALSE)
      ; BOOL WINAPI ContextDllCreateObjectContext (
      ;                    _In_opt_ LPCSTR pszObjectOid,
      ;                    _In_ DWORD dwRetrievalFlags,
      ;                    _In_ PCRYPT_BLOB_ARRAY pObject,
      ;                    _Outptr_ LPVOID* ppvContext
      ;                    )
      ; Remote Object Retrieval API
      ; Retrieval flags
      CRYPT_RETRIEVE_MULTIPLE_OBJECTS equ 00000001h
      CRYPT_CACHE_ONLY_RETRIEVAL equ 00000002h
      CRYPT_WIRE_ONLY_RETRIEVAL equ 00000004h
      CRYPT_DONT_CACHE_RESULT equ 00000008h
      CRYPT_ASYNC_RETRIEVAL equ 00000010h
      CRYPT_STICKY_CACHE_RETRIEVAL equ 00001000h
      CRYPT_LDAP_SCOPE_BASE_ONLY_RETRIEVAL equ 00002000h
      CRYPT_OFFLINE_CHECK_RETRIEVAL equ 00004000h
      ; When the following flag is set, the following 2 NULL terminated ascii
      ; strings are inserted at the beginning of each returned blob:
      ;  "%d\0%s\0", dwEntryIndex, pszAttribute
      ;  The first dwEntryIndex is 0, "0\0".
      ; When set, pszObjectOid must be NULL, so that a PCRYPT_BLOB_ARRAY is returned.
      CRYPT_LDAP_INSERT_ENTRY_ATTRIBUTE equ 00008000h
      ; Set this flag to digitally sign all of the ldap traffic to and from a
      ; Windows 2000 LDAP server using the Kerberos authentication protocol.
      ; This feature provides integrity required by some applications.
      CRYPT_LDAP_SIGN_RETRIEVAL equ 00010000h
      ; Set this flag to inhibit automatic authentication handling. See the
      ; wininet flag, INTERNET_FLAG_NO_AUTH, for more details.
      CRYPT_NO_AUTH_RETRIEVAL equ 00020000h
      ; Performs an A-Record only DNS lookup on the supplied host string.
      ; This prevents bogus DNS queries from being generated when resolving host
      ; names. Use this flag whenever passing a hostname as opposed to a
      ; domain name for the hostname parameter.
      ; See LDAP_OPT_AREC_EXCLUSIVE defined in winldap.h for more details.
      CRYPT_LDAP_AREC_EXCLUSIVE_RETRIEVAL equ 00040000h
      ; Apply AIA URL restrictions, such as, validate retrieved content before
      ; writing to cache.
      CRYPT_AIA_RETRIEVAL equ 00080000h
      ; For HTTP: use POST instead of the default GET
      ; The POST additional binary data and header strings are appended to
      ; the host name and path URL as follows:
      ;  + L'/'<Optional url escaped and base64 encoded additional data>
      ;  + L'?'<Optional additional headers>
      ; Here's an example of an OCSP POST URL:
      ;  http://ocsp.openvalidation.org/MEIwQDA%2BMDwwOjAJBgUrDgMCGgUABBQdKNE
      ;      wjytjKBQADcgM61jfflNpyQQUv1NDgnjQnsOA5RtnygUA37lIg6UCA
      ;      QI%3D?Content-Type: application/ocsp-request
      ; When this flag is set, CryptRetrieveObjectByUrl, searches for the
      ; last L'/' and L'?' POST marker characters in the URL string.
      ; These are removed from the URL before it is passed to the WinHttp
      ; APIs. The L'?' string is passed as the AdditionHeaders to
      ; WinHttpSendRequest. The L'/' string is url unescaped (%xx converted
      ; to appropriate character) and base64 decoded into binary. This
      ; decoded binary is passed as the additional data to WinHttpSendRequest.
      CRYPT_HTTP_POST_RETRIEVAL equ 00100000h
      ; When this flag is set we won't attempt to bypass any potential proxy caches.
      ; If a proxy cache wasn't explicitly bypassed, fProxyCacheRetrieval will be
      ; set in pAuxInfo. Only applicable to http URL retrievals.
      CRYPT_PROXY_CACHE_RETRIEVAL equ 00200000h
      ; When this flag is set, for a conditional retrieval returning not modified,
      ; TRUE is returned and *ppvObject is set to NULL. For a nonNULL pAuxInfo,
      ; dwHttpStatusCode is set to winhttp.h's HTTP_STATUS_NOT_MODIFIED. Otherwise,
      ; *ppvObject is updated for a successful retrieval. Only applicable to
      ; http URL retrievals.
      CRYPT_NOT_MODIFIED_RETRIEVAL equ 00400000h
      ; When this flag is set, revocation checking is enabled for https URLs.
      ; If the server's certificate is revoked, then, LastError is set to
      ; CRYPT_E_REVOKED. For no other errors, LastError is set to
      ; CRYPT_E_REVOCATION_OFFLINE for any offline revocation error.
      ; To ignore offline revocation errors, this API can be called again without
      ; setting this flag.
      CRYPT_ENABLE_SSL_REVOCATION_RETRIEVAL equ 00800000h
      ; Set this flag to append a random query string to the URL passed to
      ; WinHttpOpenRequest. This should only be set on URL's accessing Windows
      ; Update content. The random query string ensures that cached proxy content
      ; isn't used and the HTTP request will always reach the Content Delivery
      ; Network (CDN) used by Windows Update which removes a query string
      ; before doing a cache lookup.
      CRYPT_RANDOM_QUERY_STRING_RETRIEVAL equ 04000000h
      ; File scheme retrieval's are disabled by default. This flag can be set to
      ; allow file retrievals.
      CRYPT_ENABLE_FILE_RETRIEVAL equ 08000000h
      ; Set this flag to check if a cache flush entry already exists for this URL.
      ; If it already exists, this API will fail and set LastError to
      ; ERROR_FILE_EXISTS. Otherwise, the pvVerify parameter will be used.
      ; If NULL, we only check if the cache entry exists. If nonNULL, then,
      ; pvVerify should be a PCRYPTNET_URL_CACHE_FLUSH_INFO containing the
      ; flush information to be written.
      CRYPT_CREATE_NEW_FLUSH_ENTRY equ 10000000h
      ; Data verification retrieval flags
      ; CRYPT_VERIFY_CONTEXT_SIGNATURE is used to get signature verification
      ; on the context created.  In this case pszObjectOid must be non-NULL and
      ; pvVerify points to the signer certificate context
      ; CRYPT_VERIFY_DATA_HASH is used to get verification of the blob data
      ; retrieved by the protocol.  The pvVerify points to an URL_DATA_HASH
      ; structure (TBD)
      CRYPT_VERIFY_CONTEXT_SIGNATURE equ 00000020h
      CRYPT_VERIFY_DATA_HASH equ 00000040h
      ; Time Valid Object flags
      CRYPT_KEEP_TIME_VALID equ 00000080h
      CRYPT_DONT_VERIFY_SIGNATURE equ 00000100h
      CRYPT_DONT_CHECK_TIME_VALIDITY equ 00000200h
      ; The default checks if ftNextUpdate >= ftValidFor. Set this flag to
      ; check if ftThisUpdate >= ftValidFor.
      CRYPT_CHECK_FRESHNESS_TIME_VALIDITY equ 00000400h
      CRYPT_ACCUMULATIVE_TIMEOUT equ 00000800h
      ; Set this flag to only use OCSP AIA URLs.
      CRYPT_OCSP_ONLY_RETRIEVAL equ 01000000h
      ; Set this flag to only use the OCSP AIA URL if present. If the subject
      ; doesn't have an OCSP AIA URL, then, the CDP URLs are used.
      CRYPT_NO_OCSP_FAILOVER_TO_CRL_RETRIEVAL equ 02000000h
      ; Cryptnet URL Cache Pre-Fetch Info
      CRYPTNET_URL_CACHE_PRE_FETCH_INFO struct
        cbSize DWORD ?
        dwObjectType DWORD ?
        ; Possible errors:
        ;  S_OK                - Pending
        ;  ERROR_MEDIA_OFFLINE - CRL pre-fetch disabled due to OCSP offline.
        ;  ERROR_FILE_OFFLINE  - Unchanged pre-fetch content
        ;  ERROR_INVALID_DATA  - Invalid pre-fetch content
        ;  Other errors        - Unable to retrieve pre-fetch content
        dwError DWORD ?
        dwReserved DWORD ?
        ThisUpdateTime FILETIME <>
        NextUpdateTime FILETIME <>
        PublishTime FILETIME <>
        ; May be zero
      CRYPTNET_URL_CACHE_PRE_FETCH_INFO ends
      _CRYPTNET_URL_CACHE_PRE_FETCH_INFO typedef CRYPTNET_URL_CACHE_PRE_FETCH_INFO
      PCRYPTNET_URL_CACHE_PRE_FETCH_INFO typedef ptr CRYPTNET_URL_CACHE_PRE_FETCH_INFO
      ; Pre-fetch ObjectTypes
      CRYPTNET_URL_CACHE_PRE_FETCH_NONE equ 0
      CRYPTNET_URL_CACHE_PRE_FETCH_BLOB equ 1
      CRYPTNET_URL_CACHE_PRE_FETCH_CRL equ 2
      CRYPTNET_URL_CACHE_PRE_FETCH_OCSP equ 3
      CRYPTNET_URL_CACHE_PRE_FETCH_AUTOROOT_CAB equ 5
      CRYPTNET_URL_CACHE_PRE_FETCH_DISALLOWED_CERT_CAB equ 6
      CRYPTNET_URL_CACHE_PRE_FETCH_PIN_RULES_CAB equ 7
      ; Cryptnet URL Cache Flush Info
      CRYPTNET_URL_CACHE_FLUSH_INFO struct
        cbSize DWORD ?
        ; If pre-fetching is enabled, following is ignored
        ; 0          - use default flush exempt seconds (2 weeks)
        ; 0xFFFFFFFF - disable flushing
        dwExemptSeconds DWORD ?
        ; Time the object expires. The above dwExemptSeconds is added to
        ; to determine the flush time. The LastSyncTime is used if
        ; after this time.
        ExpireTime FILETIME <>
      CRYPTNET_URL_CACHE_FLUSH_INFO ends
      _CRYPTNET_URL_CACHE_FLUSH_INFO typedef CRYPTNET_URL_CACHE_FLUSH_INFO
      PCRYPTNET_URL_CACHE_FLUSH_INFO typedef ptr CRYPTNET_URL_CACHE_FLUSH_INFO
      CRYPTNET_URL_CACHE_DEFAULT_FLUSH equ 0
      CRYPTNET_URL_CACHE_DISABLE_FLUSH equ 0FFFFFFFFh
      ; Cryptnet URL Cache Response Info
      CRYPTNET_URL_CACHE_RESPONSE_INFO struct
        cbSize DWORD ?
        wResponseType WORD ?
        wResponseFlags WORD ?
        ; The following are zero if not present
        LastModifiedTime FILETIME <>
        dwMaxAge DWORD ?
        pwszETag =POINTER ?
        dwProxyId DWORD ?
      CRYPTNET_URL_CACHE_RESPONSE_INFO ends
      _CRYPTNET_URL_CACHE_RESPONSE_INFO typedef CRYPTNET_URL_CACHE_RESPONSE_INFO
      PCRYPTNET_URL_CACHE_RESPONSE_INFO typedef ptr CRYPTNET_URL_CACHE_RESPONSE_INFO
      ; ResponseTypes
      CRYPTNET_URL_CACHE_RESPONSE_NONE equ 0
      CRYPTNET_URL_CACHE_RESPONSE_HTTP equ 1
      ; ResponseFlags
      CRYPTNET_URL_CACHE_RESPONSE_VALIDATED equ 8000h
      ; CryptRetrieveObjectByUrl Auxilliary Info
      ; All unused fields in this data structure must be zeroed. More fields
      ; could be added in a future release.
      CRYPT_RETRIEVE_AUX_INFO struct
        cbSize DWORD ?
        pLastSyncTime POINTER ?
        ; 0 => implies no limit
        dwMaxUrlRetrievalByteCount DWORD ?
        ; To get any PreFetchInfo, set the following pointer to a
        ; CRYPTNET_URL_CACHE_PRE_FETCH_INFO structure with its cbSize set
        ; upon input. For no PreFetchInfo, except for cbSize, the data
        ; structure is zeroed upon return.
        pPreFetchInfo PCRYPTNET_URL_CACHE_PRE_FETCH_INFO ?
        ; To get any FlushInfo, set the following pointer to a
        ; CRYPTNET_URL_CACHE_FLUSH_INFO structure with its cbSize set
        ; upon input. For no FlushInfo, except for cbSize, the data structure
        ; is zeroed upon return.
        pFlushInfo PCRYPTNET_URL_CACHE_FLUSH_INFO ?
        ; To get any ResponseInfo, set the following pointer to the address
        ; of a PCRYPTNET_URL_CACHE_RESPONSE_INFO pointer updated with
        ; the allocated structure. For no ResponseInfo, *ppResponseInfo is set
        ; to NULL. Otherwise, *ppResponseInfo must be free via CryptMemFree().
        ppResponseInfo POINTER ?
        ; If nonNULL, the specified prefix string is prepended to the
        ; cached filename.
        pwszCacheFileNamePrefix POINTER ?
        ; If nonNULL, any cached information before this time is considered
        ; time invalid. For CRYPT_CACHE_ONLY_RETRIEVAL, if there is a
        ; cached entry before this time, LastError is set to ERROR_INVALID_TIME.
        ; Also used to set max-age for http retrievals.
        pftCacheResync LPFILETIME ?
        ; The following flag is set upon return if CRYPT_PROXY_CACHE_RETRIEVAL
        ; was set in dwRetrievalFlags and the proxy cache wasn't explicitly
        ; bypassed for the retrieval. This flag won't be explicitly cleared.
        ; This flag will only be set for http URL retrievals.
        fProxyCacheRetrieval DWORD ?
        ; This value is only updated upon return for a nonSuccessful status code
        ; returned in a HTTP response header. This value won't be explicitly
        ; cleared. This value will only be updated for http or https URL
        ; retrievals.
        ; If CRYPT_NOT_MODIFIED_RETRIEVAL was set in dwFlags, set to winhttp.h's
        ; HTTP_STATUS_NOT_MODIFIED if the retrieval returned not modified. In
        ; this case TRUE is returned with *ppvObject set to NULL.
        dwHttpStatusCode DWORD ?
        ; To get the HTTP response headers for a retrieval error, set the following
        ; pointer to the address of a LPWSTR to receive the list of
        ; headers. L'|' is used as the separator between headers.
        ; The *ppwszErrorResponseHeaders must be freed via CryptMemFree().
        ppwszErrorResponseHeaders POINTER ?
        ; To get the content for a retrieval decode error, set the following
        ; pointer to the address of a PCRYPT_DATA_BLOB.
        ; The *ppErrorContentBlob must be freed via CryptMemFree().
        ppErrorContentBlob POINTER ?
      CRYPT_RETRIEVE_AUX_INFO ends
      _CRYPT_RETRIEVE_AUX_INFO typedef CRYPT_RETRIEVE_AUX_INFO
      PCRYPT_RETRIEVE_AUX_INFO typedef ptr CRYPT_RETRIEVE_AUX_INFO
      ; Limit the error content to be allocated and returned.
      CRYPT_RETRIEVE_MAX_ERROR_CONTENT_LENGTH equ 1000h
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)*
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_PHONE_RESTRICTED or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      @DefProto DllImport, CryptRetrieveObjectByUrlA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPCSTR, :DWORD, :DWORD, :ptr LPVOID, :HCRYPTASYNC, :PCRYPT_CREDENTIALS, :LPVOID, :PCRYPT_RETRIEVE_AUX_INFO>, 36
      ; milliseconds
      @DefProto DllImport, CryptRetrieveObjectByUrlW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCSTR, :DWORD, :DWORD, :ptr LPVOID, :HCRYPTASYNC, :PCRYPT_CREDENTIALS, :LPVOID, :PCRYPT_RETRIEVE_AUX_INFO>, 36
      ; milliseconds
      ifdef UNICODE
        CryptRetrieveObjectByUrl equ <CryptRetrieveObjectByUrlW>
      else
        CryptRetrieveObjectByUrl equ <CryptRetrieveObjectByUrlA>
      endif
      ; !UNICODE
      ; Call back function to cancel object retrieval
      ; The function can be installed on a per thread basis.
      ; If CryptInstallCancelRetrieval is called for multiple times, only the most recent
      ; installation will be kept.
      ; This is only effective for http, https, gopher, and ftp protocol.
      ; It is ignored by the rest of the protocols.
      TYPE_PFN_CRYPT_CANCEL_RETRIEVAL typedef proto WIN_STD_CALL_CONV :DWORD, :ptr
      PFN_CRYPT_CANCEL_RETRIEVAL typedef ptr TYPE_PFN_CRYPT_CANCEL_RETRIEVAL

      ; PFN_CRYPT_CANCEL_RETRIEVAL
      ; This function should return FALSE when the object retrieval should be continued
      ; and return TRUE when the object retrieval should be cancelled.
      @DefProto DllImport, CryptInstallCancelRetrieval, WIN_STD_CALL_CONV,, <:PFN_CRYPT_CANCEL_RETRIEVAL, :ptr, :DWORD, :ptr>, 16
      @DefProto DllImport, CryptUninstallCancelRetrieval, WIN_STD_CALL_CONV,, <:DWORD, :ptr>, 8
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP|WINAPI_PARTITION_PHONE_RESTRICTED | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_PHONE_RESTRICTED or WINAPI_PARTITION_GAMES)
      @DefProto DllImport, CryptCancelAsyncRetrieval, WIN_STD_CALL_CONV,, <:HCRYPTASYNC>, 4
      ; Remote Object Async Retrieval parameters
      ; A client that wants to be notified of asynchronous object retrieval
      ; completion sets this parameter on the async handle
      CRYPT_PARAM_ASYNC_RETRIEVAL_COMPLETION equ (1)
      TYPE_PFN_CRYPT_ASYNC_RETRIEVAL_COMPLETION_FUNC typedef proto WIN_STD_CALL_CONV :LPVOID, :DWORD, :LPCSTR, :LPSTR, :LPVOID
      PFN_CRYPT_ASYNC_RETRIEVAL_COMPLETION_FUNC typedef ptr TYPE_PFN_CRYPT_ASYNC_RETRIEVAL_COMPLETION_FUNC

      CRYPT_ASYNC_RETRIEVAL_COMPLETION struct
        pfnCompletion PFN_CRYPT_ASYNC_RETRIEVAL_COMPLETION_FUNC ?
        pvCompletion POINTER ?
      CRYPT_ASYNC_RETRIEVAL_COMPLETION ends
      _CRYPT_ASYNC_RETRIEVAL_COMPLETION typedef CRYPT_ASYNC_RETRIEVAL_COMPLETION
      PCRYPT_ASYNC_RETRIEVAL_COMPLETION typedef ptr CRYPT_ASYNC_RETRIEVAL_COMPLETION
      ; This function is set on the async handle by a scheme provider that
      ; supports asynchronous retrieval
      CRYPT_PARAM_CANCEL_ASYNC_RETRIEVAL equ (2)
      TYPE_PFN_CANCEL_ASYNC_RETRIEVAL_FUNC typedef proto WIN_STD_CALL_CONV :HCRYPTASYNC
      PFN_CANCEL_ASYNC_RETRIEVAL_FUNC typedef ptr TYPE_PFN_CANCEL_ASYNC_RETRIEVAL_FUNC

      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_PHONE_RESTRICTED | WINAPI_PARTITION_GAMES) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_PHONE_RESTRICTED or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      ; Get the locator for a CAPI object
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
        ; Seconds between syncs
        dwSyncDeltaTime DWORD ?
        ; Returned URLs may be grouped. For instance, groups of cross cert
        ; distribution points. Each distribution point may have multiple
        ; URLs, (LDAP and HTTP scheme).
        cGroup DWORD ?
        rgcGroupEntry POINTER ?
      CRYPT_URL_INFO ends
      _CRYPT_URL_INFO typedef CRYPT_URL_INFO
      PCRYPT_URL_INFO typedef ptr CRYPT_URL_INFO
      @DefProto DllImport, CryptGetObjectUrl, WIN_STD_CALL_CONV,, <:LPCSTR, :LPVOID, :DWORD, :PCRYPT_URL_ARRAY, :ptr DWORD, :PCRYPT_URL_INFO, :ptr DWORD, :LPVOID>, 32
      URL_OID_GET_OBJECT_URL_FUNC equ <"UrlDllGetObjectUrl">
      ; UrlDllGetObjectUrl has the same signature as CryptGetObjectUrl
      ; URL_OID_CERTIFICATE_ISSUER
      ; pvPara == PCCERT_CONTEXT, certificate whose issuer's URL is being requested
      ; This will be retrieved from the authority info access extension or property
      ; on the certificate
      ; URL_OID_CERTIFICATE_CRL_DIST_POINT
      ; pvPara == PCCERT_CONTEXT, certificate whose CRL distribution point is being
      ; requested
      ; This will be retrieved from the CRL distribution point extension or property
      ; on the certificate
      ; URL_OID_CTL_ISSUER
      ; pvPara == PCCTL_CONTEXT, Signer Index, CTL whose issuer's URL (identified
      ; by the signer index) is being requested
      ; This will be retrieved from an authority info access attribute method encoded
      ; in each signer info in the PKCS7 (CTL)
      ; URL_OID_CTL_NEXT_UPDATE
      ; pvPara == PCCTL_CONTEXT, Signer Index, CTL whose next update URL is being
      ; requested and an optional signer index in case we need to check signer
      ; info attributes
      ; This will be retrieved from an authority info access CTL extension, property,
      ; or signer info attribute method
      ; URL_OID_CRL_ISSUER
      ; pvPara == PCCRL_CONTEXT, CRL whose issuer's URL is being requested
      ; This will be retrieved from a property on the CRL which has been inherited
      ; from the subject cert (either from the subject cert issuer or the subject
      ; cert distribution point extension).  It will be encoded as an authority
      ; info access extension method.
      ; URL_OID_CERTIFICATE_FRESHEST_CRL
      ; pvPara == PCCERT_CONTEXT, certificate whose freshest CRL distribution point
      ; is being requested
      ; This will be retrieved from the freshest CRL extension or property
      ; on the certificate
      ; URL_OID_CRL_FRESHEST_CRL
      ; pvPara == PCCERT_CRL_CONTEXT_PAIR, certificate's base CRL whose
      ; freshest CRL distribution point is being requested
      ; This will be retrieved from the freshest CRL extension or property
      ; on the CRL
      ; URL_OID_CROSS_CERT_DIST_POINT
      ; pvPara == PCCERT_CONTEXT, certificate whose cross certificate distribution
      ; point is being requested
      ; This will be retrieved from the cross certificate distribution point
      ; extension or property on the certificate
      ; URL_OID_CERTIFICATE_OCSP
      ; pvPara == PCCERT_CONTEXT, certificate whose OCSP URL is being requested
      ; This will be retrieved from the authority info access extension or property
      ; on the certificate
      ; URL_OID_CERTIFICATE_OCSP_AND_CRL_DIST_POINT
      ; pvPara == PCCERT_CONTEXT, certificate whose OCSP URL and
      ; CRL distribution point are being requested
      ; This will be retrieved from the authority info access and
      ; CRL distribution point extension or property on the certificate.
      ; If any OCSP URLs are present, they will be first with each URL prefixed
      ; with L"ocsp:". The L"ocsp:" prefix should be removed before using.
      ; URL_OID_CERTIFICATE_CRL_DIST_POINT_AND_OCSP
      ; Same as URL_OID_CERTIFICATE_OCSP_AND_CRL_DIST_POINT, except,
      ; the CRL URLs will be first
      ; URL_OID_CERTIFICATE_ONLY_OCSP
      ; Same as URL_OID_CERTIFICATE_OCSP_AND_CRL_DIST_POINT, except,
      ; only OCSP URLs are retrieved.
      ; URL_OID_CROSS_CERT_SUBJECT_INFO_ACCESS
      ; pvPara == PCCERT_CONTEXT, certificate whose cross certificates
      ; are being requested
      ; This will be retrieved from the Authority Info Access
      ; extension or property on the certificate. Only access methods
      ; matching szOID_PKIX_CA_REPOSITORY will be returned.
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
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP|WINAPI_PARTITION_PHONE_RESTRICTED | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_PHONE_RESTRICTED or WINAPI_PARTITION_GAMES)
      ; Get a time valid CAPI2 object
      ;+-------------------------------------------------------------------------
      ;  The following optional Extra Info may be passed to
      ;  CryptGetTimeValidObject().
      ;  All unused fields in this data structure must be zeroed. More fields
      ;  could be added in a future release.
      ;--------------------------------------------------------------------------
      CRYPT_GET_TIME_VALID_OBJECT_EXTRA_INFO struct
        cbSize DWORD ?
        ; If > 0, check that the CRL's number is >=
        ; Should be 0x7fffffff if pDeltaCrlIndicator is nonNull
        iDeltaCrlIndicator SDWORD ?
        ; If nonNULL, any cached information before this time is considered
        ; time invalid and forces a wire retrieval.
        pftCacheResync LPFILETIME ?
        ; If nonNull, returns the cache's LastSyncTime
        pLastSyncTime LPFILETIME ?
        ; If nonNull, returns the internal MaxAge expiration time
        ; for the object. If the object doesn't have a MaxAge expiration, set
        ; to zero.
        pMaxAgeTime LPFILETIME ?
        ; If nonNULL, CertGetCertificateChain() parameters used by the caller.
        ; Enables independent OCSP signer certificate chain verification.
        pChainPara PCERT_REVOCATION_CHAIN_PARA ?
        ; Should be used if the DeltaCrlIndicator value is more than 4 bytes
        ; If nonNull and iDeltaCrlIndicator == MAXLONG, check that the CRL's number is >=
        pDeltaCrlIndicator PCRYPT_INTEGER_BLOB ?
      CRYPT_GET_TIME_VALID_OBJECT_EXTRA_INFO ends
      _CRYPT_GET_TIME_VALID_OBJECT_EXTRA_INFO typedef CRYPT_GET_TIME_VALID_OBJECT_EXTRA_INFO
      PCRYPT_GET_TIME_VALID_OBJECT_EXTRA_INFO typedef ptr CRYPT_GET_TIME_VALID_OBJECT_EXTRA_INFO
      @DefProto DllImport, CryptGetTimeValidObject, WIN_STD_CALL_CONV,, <:LPCSTR, :LPVOID, :PCCERT_CONTEXT, :LPFILETIME, :DWORD, :DWORD, :ptr LPVOID, :PCRYPT_CREDENTIALS, :PCRYPT_GET_TIME_VALID_OBJECT_EXTRA_INFO>, 36
      ; milliseconds
      TIME_VALID_OID_GET_OBJECT_FUNC equ <"TimeValidDllGetObject">
      ; TimeValidDllGetObject has the same signature as CryptGetTimeValidObject
      ; TIME_VALID_OID_GET_CTL
      ; pvPara == PCCTL_CONTEXT, the current CTL
      ; TIME_VALID_OID_GET_CRL
      ; pvPara == PCCRL_CONTEXT, the current CRL
      ; TIME_VALID_OID_GET_CRL_FROM_CERT
      ; pvPara == PCCERT_CONTEXT, the subject cert
      ; TIME_VALID_OID_GET_FRESHEST_CRL_FROM_CERT
      ; pvPara == PCCERT_CONTEXT, the subject cert
      ; TIME_VALID_OID_GET_FRESHEST_CRL_FROM_CRL
      ; pvPara == PCCERT_CRL_CONTEXT_PAIR, the subject cert and its base CRL
      TIME_VALID_OID_GET_CTL equ (1)
      TIME_VALID_OID_GET_CRL equ (2)
      TIME_VALID_OID_GET_CRL_FROM_CERT equ (3)
      TIME_VALID_OID_GET_FRESHEST_CRL_FROM_CERT equ (4)
      TIME_VALID_OID_GET_FRESHEST_CRL_FROM_CRL equ (5)
      @DefProto DllImport, CryptFlushTimeValidObject, WIN_STD_CALL_CONV,, <:LPCSTR, :LPVOID, :PCCERT_CONTEXT, :DWORD, :LPVOID>, 20
      TIME_VALID_OID_FLUSH_OBJECT_FUNC equ <"TimeValidDllFlushObject">
      ; TimeValidDllFlushObject has the same signature as CryptFlushTimeValidObject
      ; TIME_VALID_OID_FLUSH_CTL
      ; pvPara == PCCTL_CONTEXT, the CTL to flush
      ; TIME_VALID_OID_FLUSH_CRL
      ; pvPara == PCCRL_CONTEXT, the CRL to flush
      ; TIME_VALID_OID_FLUSH_CRL_FROM_CERT
      ; pvPara == PCCERT_CONTEXT, the subject cert's CRL to flush
      ; TIME_VALID_OID_FLUSH_FRESHEST_CRL_FROM_CERT
      ; pvPara == PCCERT_CONTEXT, the subject cert's freshest CRL to flush
      ; TIME_VALID_OID_FLUSH_FRESHEST_CRL_FROM_CRL
      ; pvPara == PCCERT_CRL_CONTEXT_PAIR, the subject cert and its base CRL's
      ; freshest CRL to flush
      TIME_VALID_OID_FLUSH_CTL equ (1)
      TIME_VALID_OID_FLUSH_CRL equ (2)
      TIME_VALID_OID_FLUSH_CRL_FROM_CERT equ (3)
      TIME_VALID_OID_FLUSH_FRESHEST_CRL_FROM_CERT equ (4)
      TIME_VALID_OID_FLUSH_FRESHEST_CRL_FROM_CRL equ (5)
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_PHONE_RESTRICTED | WINAPI_PARTITION_GAMES) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      ;+=========================================================================
      ;  Helper functions to build certificates
      ;==========================================================================
      ;+-------------------------------------------------------------------------
      ; Builds a self-signed certificate and returns a PCCERT_CONTEXT representing
      ; the certificate. A hProv may be specified to build the cert context.
      ; pSubjectIssuerBlob is the DN for the certifcate. If an alternate subject
      ; name is desired it must be specified as an extension in the pExtensions
      ; parameter. pSubjectIssuerBlob can NOT be NULL, so minimually an empty DN
      ; must be specified.
      ; By default:
      ; pKeyProvInfo - The CSP is queried for the KeyProvInfo parameters. Only the Provider,
      ; Provider Type and Container is queried. Many CSPs don't support these
      ; queries and will cause a failure. In such cases the pKeyProvInfo
      ; must be specified (RSA BASE works fine).
      ; pSignatureAlgorithm - will default to SHA1RSA
      ; pStartTime will default to the current time
      ; pEndTime will default to 1 year
      ; pEntensions will be empty.
      ; The returned PCCERT_CONTEXT will reference the private keys by setting the
      ; CERT_KEY_PROV_INFO_PROP_ID. However, if this property is not desired specify the
      ; CERT_CREATE_SELFSIGN_NO_KEY_INFO in dwFlags.
      ; If the cert being built is only a dummy placeholder cert for speed it may not
      ; need to be signed. Signing of the cert is skipped if CERT_CREATE_SELFSIGN_NO_SIGN
      ; is specified in dwFlags.
      ; Following flags can be passed to CertCreateSelfSignCertificate which will be
      ; directly passed to CryptExportPublicKeyInfo to indicate the preference of
      ; putting ECC Curve OID vs ECC Curve Parameters in Cert's Public Key information's
      ; algorithm section:
      ;      CRYPT_OID_USE_CURVE_NAME_FOR_ENCODE_FLAG
      ;      CRYPT_OID_USE_CURVE_PARAMETERS_FOR_ENCODE_FLAG
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertCreateSelfSignCertificate, WIN_STD_CALL_CONV,, <:HCRYPTPROV_OR_NCRYPT_KEY_HANDLE, :PCERT_NAME_BLOB, :DWORD, :PCRYPT_KEY_PROV_INFO, :PCRYPT_ALGORITHM_IDENTIFIER, :PSYSTEMTIME, :PSYSTEMTIME, :PCERT_EXTENSIONS>, 32
      CERT_CREATE_SELFSIGN_NO_SIGN equ 1
      CERT_CREATE_SELFSIGN_NO_KEY_INFO equ 2
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)*
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_PHONE_RESTRICTED or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      ;+=========================================================================
      ;  Key Identifier Property Data Structures and APIs
      ;==========================================================================
      ;+-------------------------------------------------------------------------
      ;  Get the property for the specified Key Identifier.
      ;  The Key Identifier is the SHA1 hash of the encoded CERT_PUBLIC_KEY_INFO.
      ;  The Key Identifier for a certificate can be obtained by getting the
      ;  certificate's CERT_KEY_IDENTIFIER_PROP_ID. The
      ;  CryptCreateKeyIdentifierFromCSP API can be called to create the Key
      ;  Identifier from a CSP Public Key Blob.
      ;  A Key Identifier can have the same properties as a certificate context.
      ;  CERT_KEY_PROV_INFO_PROP_ID is the property of most interest.
      ;  For CERT_KEY_PROV_INFO_PROP_ID, pvData points to a CRYPT_KEY_PROV_INFO
      ;  structure. Elements pointed to by fields in the pvData structure follow the
      ;  structure. Therefore, *pcbData will exceed the size of the structure.
      ;  If CRYPT_KEYID_ALLOC_FLAG is set, then, *pvData is updated with a
      ;  pointer to allocated memory. LocalFree() must be called to free the
      ;  allocated memory.
      ;  By default, searches the CurrentUser's list of Key Identifiers.
      ;  CRYPT_KEYID_MACHINE_FLAG can be set to search the LocalMachine's list
      ;  of Key Identifiers. When CRYPT_KEYID_MACHINE_FLAG is set, pwszComputerName
      ;  can also be set to specify the name of a remote computer to be searched
      ;  instead of the local machine.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CryptGetKeyIdentifierProperty, WIN_STD_CALL_CONV,, <:ptr CRYPT_HASH_BLOB, :DWORD, :DWORD, :LPCWSTR, :ptr, :ptr, :ptr DWORD>, 28
      ; When the following flag is set, searches the LocalMachine instead of the
      ; CurrentUser. This flag is applicable to all the KeyIdentifierProperty APIs.
      CRYPT_KEYID_MACHINE_FLAG equ 00000020h
      ; When the following flag is set, *pvData is updated with a pointer to
      ; allocated memory. LocalFree() must be called to free the allocated memory.
      CRYPT_KEYID_ALLOC_FLAG equ 00008000h
      ;+-------------------------------------------------------------------------
      ;  Set the property for the specified Key Identifier.
      ;  For CERT_KEY_PROV_INFO_PROP_ID pvData points to the
      ;  CRYPT_KEY_PROV_INFO data structure. For all other properties, pvData
      ;  points to a CRYPT_DATA_BLOB.
      ;  Setting pvData == NULL, deletes the property.
      ;  Set CRYPT_KEYID_MACHINE_FLAG to set the property for a LocalMachine
      ;  Key Identifier. Set pwszComputerName, to select a remote computer.
      ;  If CRYPT_KEYID_DELETE_FLAG is set, the Key Identifier and all its
      ;  properties is deleted.
      ;  If CRYPT_KEYID_SET_NEW_FLAG is set, the set fails if the property already
      ;  exists. For an existing property, FALSE is returned with LastError set to
      ;  CRYPT_E_EXISTS.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CryptSetKeyIdentifierProperty, WIN_STD_CALL_CONV,, <:ptr CRYPT_HASH_BLOB, :DWORD, :DWORD, :LPCWSTR, :ptr, :ptr>, 24
      ; When the following flag is set, the Key Identifier and all its properties
      ; are deleted.
      CRYPT_KEYID_DELETE_FLAG equ 00000010h
      ; When the following flag is set, the set fails if the property already
      ; exists.
      CRYPT_KEYID_SET_NEW_FLAG equ 00002000h
      ;+-------------------------------------------------------------------------
      ;  For CERT_KEY_PROV_INFO_PROP_ID, rgppvData[] points to a
      ;  CRYPT_KEY_PROV_INFO.
      ;  Return FALSE to stop the enumeration.
      ;--------------------------------------------------------------------------
      TYPE_PFN_CRYPT_ENUM_KEYID_PROP typedef proto WIN_STD_CALL_CONV :ptr CRYPT_HASH_BLOB, :DWORD, :ptr, :ptr, :DWORD, :ptr DWORD, :ptr ptr, :ptr DWORD
      PFN_CRYPT_ENUM_KEYID_PROP typedef ptr TYPE_PFN_CRYPT_ENUM_KEYID_PROP

      ;+-------------------------------------------------------------------------
      ;  Enumerate the Key Identifiers.
      ;  If pKeyIdentifier is NULL, enumerates all Key Identifers. Otherwise,
      ;  calls the callback for the specified KeyIdentifier. If dwPropId is
      ;  0, calls the callback with all the properties. Otherwise, only calls
      ;  the callback with the specified property (cProp = 1).
      ;  Furthermore, when dwPropId is specified, skips KeyIdentifiers not
      ;  having the property.
      ;  Set CRYPT_KEYID_MACHINE_FLAG to enumerate the LocalMachine
      ;  Key Identifiers. Set pwszComputerName, to enumerate Key Identifiers on
      ;  a remote computer.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CryptEnumKeyIdentifierProperties, WIN_STD_CALL_CONV,, <:ptr CRYPT_HASH_BLOB, :DWORD, :DWORD, :LPCWSTR, :ptr, :ptr, :PFN_CRYPT_ENUM_KEYID_PROP>, 28
      ;+-------------------------------------------------------------------------
      ;  Create a KeyIdentifier from the CSP Public Key Blob.
      ;  Converts the CSP PUBLICKEYSTRUC into a X.509 CERT_PUBLIC_KEY_INFO and
      ;  encodes. The encoded CERT_PUBLIC_KEY_INFO is SHA1 hashed to obtain
      ;  the Key Identifier.
      ;  By default, the pPubKeyStruc->aiKeyAlg is used to find the appropriate
      ;  public key Object Identifier. pszPubKeyOID can be set to override
      ;  the default OID obtained from the aiKeyAlg.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CryptCreateKeyIdentifierFromCSP, WIN_STD_CALL_CONV,, <:DWORD, :LPCSTR, :ptr PUBLICKEYSTRUC, :DWORD, :DWORD, :ptr, :ptr BYTE, :ptr DWORD>, 32
      ;+=========================================================================
      ;  Certificate Chaining Infrastructure
      ;==========================================================================
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP|WINAPI_PARTITION_PHONE_RESTRICTED | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      CERT_CHAIN_CONFIG_REGPATH equ <L("Software\Microsoft\Cryptography\OID\EncodingType 0\CertDllCreateCertificateChainEngine\Config")>
      ; max size of the cryptographic object to download, in bytes
      ; NOTE: AIA has different configuration
      CERT_CHAIN_MAX_URL_RETRIEVAL_BYTE_COUNT_VALUE_NAME equ <L("MaxUrlRetrievalByteCount")>
      CERT_CHAIN_MAX_URL_RETRIEVAL_BYTE_COUNT_DEFAULT equ (100 * 1024 * 1024)
      ; The following is a REG_BINARY. It contains the cache resync FILETIME.
      ; Any cached information before this time is considered time invalid
      ; and forces a wire retrieval. By default this is disabled.
      CERT_CHAIN_CACHE_RESYNC_FILETIME_VALUE_NAME equ <L("ChainCacheResyncFiletime")>
      ; The following are REG_DWORD's. These configuration parameters are used
      ; to disable different chain building semantics enabled by default. Set
      ; the appropriate registry value to nonzero to disable.
      CERT_CHAIN_DISABLE_MANDATORY_BASIC_CONSTRAINTS_VALUE_NAME equ <L("DisableMandatoryBasicConstraints")>
      ; By default the BasicConstraints extension must be present with CA enabled
      ; for non-Root intermediate CA certificates.
      CERT_CHAIN_DISABLE_CA_NAME_CONSTRAINTS_VALUE_NAME equ <L("DisableCANameConstraints")>
      ; By default the NameConstraints extension is applied to the intermediate
      ; CA certificates in addition to the end entity certificate.
      CERT_CHAIN_DISABLE_UNSUPPORTED_CRITICAL_EXTENSIONS_VALUE_NAME equ <L("DisableUnsupportedCriticalExtensions")>
      ; By default any unsupported extension marked critical sets the following
      ; dwErrorStatus bit: CERT_TRUST_HAS_NOT_SUPPORTED_CRITICAL_EXT.
      ; The following are REG_DWORD's. These configuration parameters are used
      ; to restrict Authority Info Access (AIA) URL retrieval.
      CERT_CHAIN_MAX_AIA_URL_COUNT_IN_CERT_VALUE_NAME equ <L("MaxAIAUrlCountInCert")>
      CERT_CHAIN_MAX_AIA_URL_COUNT_IN_CERT_DEFAULT equ 5
      CERT_CHAIN_MAX_AIA_URL_RETRIEVAL_COUNT_PER_CHAIN_VALUE_NAME equ <L("MaxAIAUrlRetrievalCountPerChain")>
      CERT_CHAIN_MAX_AIA_URL_RETRIEVAL_COUNT_PER_CHAIN_DEFAULT equ 3
      ; max size of the object to download, specified by a URL in AIA extention, in bytes
      CERT_CHAIN_MAX_AIA_URL_RETRIEVAL_BYTE_COUNT_VALUE_NAME equ <L("MaxAIAUrlRetrievalByteCount")>
      CERT_CHAIN_MAX_AIA_URL_RETRIEVAL_BYTE_COUNT_DEFAULT equ 100000
      CERT_CHAIN_MAX_AIA_URL_RETRIEVAL_CERT_COUNT_VALUE_NAME equ <L("MaxAIAUrlRetrievalCertCount")>
      CERT_CHAIN_MAX_AIA_URL_RETRIEVAL_CERT_COUNT_DEFAULT equ 10
      ; The following is a REG_DWORD. If the OCSP response NextUpdate is zero,
      ; this value is added to the ThisUpdate to get a nonzero NextUpdate.
      CERT_CHAIN_OCSP_VALIDITY_SECONDS_VALUE_NAME equ <L("OcspValiditySeconds")>
      ; 12 hours
      CERT_CHAIN_OCSP_VALIDITY_SECONDS_DEFAULT equ (12 * 60 * 60)
      ; The following is a REG_DWORD. It can be set to a nonzero value to disable
      ; the use of the Serial Chain optimization for SSL ServerAuth chains. This
      ; value is queried in each process on the first CertGetCertificateChain call
      ; where the CERT_SERIAL_CHAIN_PROP_ID property is set.
      CERT_CHAIN_DISABLE_SERIAL_CHAIN_VALUE_NAME equ <L("DisableSerialChain")>
      ; The following is a REG_SZ containing the name of the file to log
      ; Serial Chain errors.
      ; The file's directory must already exist. If the file already
      ; exists, events are appended. Otherwise, the file is created.
      ; The directory/file should be ACL'ed so all processes and users have
      ; write access.
      CERT_CHAIN_SERIAL_CHAIN_LOG_FILE_NAME_VALUE_NAME equ <L("SerialChainLogFileName")>
      ; The following is a REG_DWORD. It can be set to a nonzero value to disable
      ; using SSL handshakes as a source of time. Will also disable the above
      ; Serial Chain optimization. Value is queried once on the first SSL
      ; handshake in the lsass.exe process.
      CERT_CHAIN_DISABLE_SYNC_WITH_SSL_TIME_VALUE_NAME equ <L("DisableSyncWithSslTime")>
      ; The following is a REG_DWORD that specifies the maximum number of
      ; "SslTimeUpdated" events to be uploaded after boot or when the
      ; current time is synch'ed with SSL time. If not defined or a value of
      ; 0, uses the default value.
      CERT_CHAIN_MAX_SSL_TIME_UPDATED_EVENT_COUNT_VALUE_NAME equ <L("MaxSslTimeUpdatedEventCount")>
      CERT_CHAIN_MAX_SSL_TIME_UPDATED_EVENT_COUNT_DEFAULT equ 5
      ; The following value disables uploading "SslTimeUpdated" events
      CERT_CHAIN_MAX_SSL_TIME_UPDATED_EVENT_COUNT_DISABLE equ 0FFFFFFFFh
      ; The following is a REG_SZ containing the name of the file to log
      ; SSL handshakes that were processed.
      ; The file's directory must already exist. If the file already
      ; exists, events are appended. Otherwise, the file is created.
      CERT_CHAIN_SSL_HANDSHAKE_LOG_FILE_NAME_VALUE_NAME equ <L("SslHandshakeLogFileName")>
      ; The following is a REG_DWORD. Flags can be set to enable weak
      ; signature hash algorithms and/or weak public key lengths that
      ; are disabled by default. Also, has flags to enable logging of weak
      ; certificates.
      CERT_CHAIN_ENABLE_WEAK_SIGNATURE_FLAGS_VALUE_NAME equ <L("EnableWeakSignatureFlags")>
      ; The following flag is set to enable MD2 or MD4 hashes that are
      ; disabled by default. If none, code signing, driver signing
      ; or time stamping requested EKUs are passed to CertGetCertificateChain API,
      ; then MD2 or MD4 isn't disabled by default.
      CERT_CHAIN_ENABLE_MD2_MD4_FLAG equ 00000001h
      ; The following flag is set to enable weak RSA public key lengths
      ; for trusted roots that are disabled by default.
      CERT_CHAIN_ENABLE_WEAK_RSA_ROOT_FLAG equ 00000002h
      ; The following flag is set to enable the logging of weak certificates
      ; to the directory identified by CERT_CHAIN_WEAK_SIGNATURE_LOG_DIR_VALUE_NAME.
      ; Not applicable to MD2 or MD4 certificates.
      CERT_CHAIN_ENABLE_WEAK_LOGGING_FLAG equ 00000004h
      ; The following flag is set to only log weak certificates. Disables
      ; weak signature errors from being returned. Not applicable
      ; to MD2 or MD4 certificates. 
      CERT_CHAIN_ENABLE_ONLY_WEAK_LOGGING_FLAG equ 00000008h
      ; The following is a REG_DWORD that specifies the minimum RSA public
      ; key length in bits. If not defined or a value of 0, uses the
      ; default value.
      CERT_CHAIN_MIN_RSA_PUB_KEY_BIT_LENGTH_VALUE_NAME equ <L("MinRsaPubKeyBitLength")>
      CERT_CHAIN_MIN_RSA_PUB_KEY_BIT_LENGTH_DEFAULT equ 1023
      ; The following value disables checking for weak RSA public key lengths.
      CERT_CHAIN_MIN_RSA_PUB_KEY_BIT_LENGTH_DISABLE equ 0FFFFFFFFh
      ; The following is a REG_BINARY containing the 8 byte FILETIME. The weak
      ; RSA public key length check is disabled for timestamped files before
      ; this time. If not defined or a zero FILETIME, uses the default value. 
      CERT_CHAIN_WEAK_RSA_PUB_KEY_TIME_VALUE_NAME equ <L("WeakRsaPubKeyTime")>
      ; The default time: UTC: Fri Jan 01 00:00:00 2010
      CERT_CHAIN_WEAK_RSA_PUB_KEY_TIME_DEFAULT equ 01CA8A755C6E0000h
      ; The following is a REG_SZ. When defined, weak certificates are
      ; written to this directory. This directory should be ACL'ed to allow
      ; modify access by Authenticated Users and All Application Packages.
      CERT_CHAIN_WEAK_SIGNATURE_LOG_DIR_VALUE_NAME equ <L("WeakSignatureLogDir")>
      ;+=========================================================================
      ; Weak Signature Registry Configuration
      ;==========================================================================
      ; The administrator will continue to place the weak crypto settings under:
      ; CERT_CHAIN_CONFIG_REGPATH defined above.
      ; The OS and Windows Update will configure the same settings in the
      ; "Default" subkey under CERT_CHAIN_CONFIG_REGPATH.
      CERT_CHAIN_DEFAULT_CONFIG_SUBDIR equ <L("Default")>
      ; The registry values will have the following name syntax:
      ;  "Weak"<CryptoAlg><ConfigType><ValueType>
      ; Where:
      ;  - <CryptoAlg> can be: "Md5", "Sha1", "Rsa", "Dsa" or "Ecdsa"
      ;  - <ConfigType> can be: "ThirdParty" or "All"
      ;  - <ValueType> can be: "Flags", "Hygiene", "MinBitLength", "AfterTime",
      ;    "FileHashAfterTime "TimestampHashAfterTime" or "Sha256Allow"
      ;     - "Hygiene" is only applicable to hash algorithms
      ;     - "FileHashAfterTime" and "TimestampHashAfterTime" are only applicable
      ;        to hash algorithms. These times can be in the future.
      ;     - "MinBitLengh" is only applicable to key algorithms
      ;  - <CryptoAlg>, <ConfigType> and <ValueType> will be present in all names.
      ; For example, all possible registry value names for Md5:
      ;  WeakMd5ThirdPartyFlags
      ;  WeakMd5AllFlags
      ;  WeakMd5ThirdPartyHygiene
      ;  WeakMd5AllHygiene
      ;  WeakMd5ThirdPartyAfterTime
      ;  WeakMd5AllAfterTime
      ;  WeakMd5ThirdPartyFileHashAfterTime
      ;  WeakMd5AllFileHashAfterTime
      ;  WeakMd5ThirdPartyTimestampHashAfterTime
      ;  WeakMd5AllTimestampHashAfterTime
      ;  WeakMd5ThirdPartySha256Allow
      ;  WeakMd5AllSha256Allow
      ; For example, all possible registry value names for Rsa:
      ;  WeakRsaThirdPartyFlags
      ;  WeakRsaAllFlags
      ;  WeakRsaThirdPartyAfterTime
      ;  WeakRsaAllAfterTime
      ;  WeakRsaThirdPartyMinBitLength
      ;  WeakRsaAllMinBitLength
      ;  WeakRsaThirdPartySha256Allow
      ;  WeakRsaAllSha256Allow
      ; The following registry values can be set:
      ;  - "Weak"<CryptoAlg><ConfigType>"Flags"
      ;     - REG_DWORD
      ;     - Flags can be set to disable the hash algorithm or enable a
      ;       minimum key length. See below for a complete list.
      ;  - "Weak"<HashCryptoAlg><ConfigType>"Hygiene"
      ;     - REG_DWORD or REG_QWORD. The REG_DWORD can be used until the number
      ;       of hygiene functions exceeds 32. We will support either registry type
      ;       for this value.
      ;     - This value corresponds to the qwHygieneFlags parameter passed to the
      ;       I_CertGetCertificateHygieneStatus internal API.
      ;     - The hygiene checks are skipped if the hash algorithm has been disabled.
      ;  - "Weak"<KeyCryptoAlg><ConfigType>"MinBitLength"
      ;     - REG_DWORD
      ;     - This value specifies the minimum public key length in bits.
      ;  - "Weak"<CryptoAlg><ConfigType>"AfterTime"
      ;     - REG_BINARY
      ;     - This value contains an 8 byte FILETIME. The weak crypto algorithm
      ;       check is disabled for time stamped files before this time.
      ;     - This configuration value isn't applicable to timestamp chains.
      ;     - This configuration value isn't applicable to hygiene checks.
      ;     - If this time is after the CurrentTime, then, the CurrentTime is used.
      ;  - "Weak"<CryptoAlg><ConfigType>"FileHashAfterTime"
      ;     - REG_BINARY
      ;     - This value contains an 8 byte FILETIME. The file hash weak crypto
      ;       algorithm check is disabled for time stamped files before this time.
      ;       This can be set to a date/time in the future.
      ;     - Only applicable to the API: CertIsWeakHash.
      ;  - "Weak"<CryptoAlg><ConfigType>"TimestampHashAfterTime"
      ;     - REG_BINARY
      ;     - This value contains an 8 byte FILETIME. The timestamp hash weak crypto
      ;       algorithm check is disabled before this time is reached. This can be
      ;       set to a date/time in the future.
      ;     - Only applicable to the API: CertIsWeakHash.
      ;  - "Weak"<CryptoAlg><ConfigType>"Sha256Allow"
      ;     - REG_SZ or REG_MULTI_SZ
      ;     - This value contains the list of certificate SHA256 thumbprints
      ;       (ASCII_HEX formatted) identifying weak certificates to be explicitly
      ;       allowed. Non ASCII_HEX characters in the string are skipped.
      ;       This allows embedded spaces.
      ;     - The resultant set used for either "Weak"<CryptoAlg>"ThirdParty" or
      ;       "Weak"<CryptoAlg>"All" is the union of:
      ;        - Default and Administrator
      ;        - "ThirdParty" and "All"
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
      ; The following value disables checking for weak public key lengths.
      CERT_CHAIN_MIN_PUB_KEY_BIT_LENGTH_DISABLE equ 0FFFFFFFFh
      ; The following flags can be set in the above
      ; "Weak"<CryptoAlg><ConfigType>"Flags"
      ; If the following flag isn't set, then all other flags and registry values
      ; are ignored for this "Weak"<CryptoAlg><ConfigType>.
      ; If the administrator sets this flag for its "Weak"<CryptoAlg><ConfigType>,
      ; then, the corresponding Default OS/Windows Update settings are ignored.
      ; If this flag is set in "Weak"<CryptoAlg>"AllFlags":
      ;  - Resultant "Weak"<CryptoAlg>"ThirdPartyFlags" will or with
      ;    "Weak"<CryptoAlg>"AllFlags".  However, "Weak"<CryptoAlg>"ThirdPartyFlags"
      ;    logging flags won't be updated.
      ;    ThirdPartyFlags |= AllFlags &
      ;                           ~(CERT_CHAIN_ENABLE_WEAK_LOGGING_FLAG |
      ;                             CERT_CHAIN_ENABLE_ONLY_WEAK_LOGGING_FLAG);
      ;  - Resultant "Weak"<HashCryptoAlg>"ThirdPartyHygine" will or with
      ;    "Weak"<HashCryptoAlg>AllHygiene"
      ;  - Resultant "Weak<CryptoAlg>"ThirdPartyAfterTime" will be earliest
      ;    ("Weak"<CryptoAlg>"AllAfterTime", "Weak"<CryptoAlg>"ThirdPartyAfterTime").
      ;    Only applicable if "Weak"<CryptoAlg>"AllAfterTime" is defined and nonzero.
      ;  - Resultant "Weak"<KeyCryptoAlg>"ThirdPartyMinBitLength" will be largest
      ;    ("Weak"<KeyCryptoAlg>"AllMinBitLength",
      ;     "Weak"<KeyCryptoAlg>"ThirdPartyMinBitLength"
      CERT_CHAIN_ENABLE_WEAK_SETTINGS_FLAG equ 80000000h
      ; The following flag is set to enable the logging of weak certificates to the
      ; directory identified by CERT_CHAIN_WEAK_SIGNATURE_LOG_DIR_VALUE_NAME.
      ; #define CERT_CHAIN_ENABLE_WEAK_LOGGING_FLAG         0x00000004
      ; The following flag is set to only log weak certificates to the directory
      ; identified by CERT_CHAIN_WEAK_SIGNATURE_LOG_DIR_VALUE_NAME. Weak signature
      ; errors aren't returned.
      ; #define CERT_CHAIN_ENABLE_ONLY_WEAK_LOGGING_FLAG    0x00000008
      ; The following flag is set to disable ECC certificates using
      ; key parameters instead of normal key curve name OID.
      CERT_CHAIN_DISABLE_ECC_PARA_FLAG equ 00000010h
      ; In addition to setting the above CERT_CHAIN_ENABLE_WEAK_SETTINGS_FLAG flag,
      ; the following flags corresponding to the EKU must be set to disable weak
      ; signature or enable weak hash hygiene checks:
      ; This flag disables for all EKUs.
      CERT_CHAIN_DISABLE_ALL_EKU_WEAK_FLAG equ 00010000h
      ; This flag enables hygiene for all EKUs not disabling.
      CERT_CHAIN_ENABLE_ALL_EKU_HYGIENE_FLAG equ 00020000h
      ; This flag disables for ServerAuth EKUs only when CertGetCertificateChain
      ; is called with CERT_CHAIN_OPT_IN_WEAK_SIGNATURE.
      CERT_CHAIN_DISABLE_OPT_IN_SERVER_AUTH_WEAK_FLAG equ 00040000h
      ; This flag disables for ServerAuth EKUs.
      CERT_CHAIN_DISABLE_SERVER_AUTH_WEAK_FLAG equ 00100000h
      ; This flag enables hygiene for ServerAuth EKUs.
      CERT_CHAIN_ENABLE_SERVER_AUTH_HYGIENE_FLAG equ 00200000h
      ; This flag disables for code signing EKUs
      CERT_CHAIN_DISABLE_CODE_SIGNING_WEAK_FLAG equ 00400000h
      ; This flag disables for code signing EKUs only when CertGetCertificateChain
      ; is called with the Mark-Of-The-Web (CERT_CHAIN_HAS_MOTW) 
      CERT_CHAIN_DISABLE_MOTW_CODE_SIGNING_WEAK_FLAG equ 00800000h
      ; This flag enables hygiene for code signing EKUs
      CERT_CHAIN_ENABLE_CODE_SIGNING_HYGIENE_FLAG equ 01000000h
      ; This flag enables hygiene for code signing EKUs only when
      ; CertGetCertificateChain is called with the
      ; Mark-Of-The-Web (CERT_CHAIN_HAS_MOTW)
      CERT_CHAIN_ENABLE_MOTW_CODE_SIGNING_HYGIENE_FLAG equ 02000000h
      ; This flag disables for timestamp EKUs.
      CERT_CHAIN_DISABLE_TIMESTAMP_WEAK_FLAG equ 04000000h
      ; This flag disables for timestamp EKUs only when CertGetCertificateChain is
      ; called with the Mark-Of-The-Web (CERT_CHAIN_HAS_MOTW)
      CERT_CHAIN_DISABLE_MOTW_TIMESTAMP_WEAK_FLAG equ 08000000h
      ; This flag enables hygiene for timestamp EKUs
      CERT_CHAIN_ENABLE_TIMESTAMP_HYGIENE_FLAG equ 10000000h
      ; This flag enables hygiene for timestamp EKUs only when
      ; CertGetCertificateChain is called with the
      ; Mark-Of-The-Web (CERT_CHAIN_HAS_MOTW)
      CERT_CHAIN_ENABLE_MOTW_TIMESTAMP_HYGIENE_FLAG equ 20000000h
      ; This flag ignores the "Weak"<CryptoAlg><ConfigType>"AfterTime" value
      ; when CertGetCertificateChain is called with the
      ; Mark-Of-The-Web (CERT_CHAIN_HAS_MOTW)
      CERT_CHAIN_MOTW_IGNORE_AFTER_TIME_WEAK_FLAG equ 40000000h
      ; If the hash algorithm is disabled, then, the hygiene check will be skipped.
      ; The hygiene flags are only applicable to hash algorithms.
      ; If no EKU flags are set, then, weak crypto isn't enforced for the
      ; "Weak"<CryptoAlg><ConfigType>. This allows the administrator to always
      ; ignore the Default OS/Windows Update settings.
      ; This flag disables for file hashes. Only applicable to CertIsWeakHash()
      ; API.
      CERT_CHAIN_DISABLE_FILE_HASH_WEAK_FLAG equ 00001000h
      ; This flag disables for file hashes. Only applicable when CertIsWeakHash()
      ; API is called with the Mark-Of-The-Web (CERT_CHAIN_HAS_MOTW)
      CERT_CHAIN_DISABLE_MOTW_FILE_HASH_WEAK_FLAG equ 00002000h
      ; This flag disables for timestamp hashes. Only applicable to CertIsWeakHash()
      ; API.
      CERT_CHAIN_DISABLE_TIMESTAMP_HASH_WEAK_FLAG equ 00004000h
      ; This flag disables for timestamp hashes. Only applicable when CertIsWeakHash()
      ; API is called with the Mark-Of-The-Web (CERT_CHAIN_HAS_MOTW)
      CERT_CHAIN_DISABLE_MOTW_TIMESTAMP_HASH_WEAK_FLAG equ 00008000h
      CERT_CHAIN_DISABLE_WEAK_FLAGS equ <(CERT_CHAIN_DISABLE_ECC_PARA_FLAG or CERT_CHAIN_DISABLE_ALL_EKU_WEAK_FLAG or CERT_CHAIN_DISABLE_SERVER_AUTH_WEAK_FLAG or CERT_CHAIN_DISABLE_OPT_IN_SERVER_AUTH_WEAK_FLAG or CERT_CHAIN_DISABLE_CODE_SIGNING_WEAK_FLAG or CERT_CHAIN_DISABLE_MOTW_CODE_SIGNING_WEAK_FLAG or CERT_CHAIN_DISABLE_TIMESTAMP_WEAK_FLAG or CERT_CHAIN_DISABLE_MOTW_TIMESTAMP_WEAK_FLAG)>
      CERT_CHAIN_DISABLE_FILE_HASH_WEAK_FLAGS equ <(CERT_CHAIN_DISABLE_FILE_HASH_WEAK_FLAG or CERT_CHAIN_DISABLE_MOTW_FILE_HASH_WEAK_FLAG)>
      CERT_CHAIN_DISABLE_TIMESTAMP_HASH_WEAK_FLAGS equ <(CERT_CHAIN_DISABLE_TIMESTAMP_HASH_WEAK_FLAG or CERT_CHAIN_DISABLE_MOTW_TIMESTAMP_HASH_WEAK_FLAG)>
      CERT_CHAIN_ENABLE_HYGIENE_FLAGS equ <(CERT_CHAIN_ENABLE_ALL_EKU_HYGIENE_FLAG or CERT_CHAIN_ENABLE_SERVER_AUTH_HYGIENE_FLAG or CERT_CHAIN_ENABLE_CODE_SIGNING_HYGIENE_FLAG or CERT_CHAIN_ENABLE_MOTW_CODE_SIGNING_HYGIENE_FLAG or CERT_CHAIN_ENABLE_TIMESTAMP_HYGIENE_FLAG or CERT_CHAIN_ENABLE_MOTW_TIMESTAMP_HYGIENE_FLAG)>
      CERT_CHAIN_MOTW_WEAK_FLAGS equ <(CERT_CHAIN_DISABLE_MOTW_CODE_SIGNING_WEAK_FLAG or CERT_CHAIN_DISABLE_MOTW_TIMESTAMP_WEAK_FLAG or CERT_CHAIN_ENABLE_MOTW_CODE_SIGNING_HYGIENE_FLAG or CERT_CHAIN_ENABLE_MOTW_TIMESTAMP_HYGIENE_FLAG or CERT_CHAIN_MOTW_IGNORE_AFTER_TIME_WEAK_FLAG)>
      CERT_CHAIN_OPT_IN_WEAK_FLAGS equ <(CERT_CHAIN_DISABLE_OPT_IN_SERVER_AUTH_WEAK_FLAG)>
      ;+=========================================================================
      ; Certificate Chain Engine Auto Flush Registry Configuration
      ;==========================================================================
      ; The following registry values are under the 
      ; CERT_CHAIN_CONFIG_REGPATH defined above.
      ; Types of certificate chain engine auto create and flush events
      CERT_CHAIN_AUTO_CURRENT_USER equ 1
      CERT_CHAIN_AUTO_LOCAL_MACHINE equ 2
      CERT_CHAIN_AUTO_IMPERSONATED equ 3
      CERT_CHAIN_AUTO_PROCESS_INFO equ 4
      CERT_CHAIN_AUTO_PINRULE_INFO equ 5
      CERT_CHAIN_AUTO_NETWORK_INFO equ 6
      CERT_CHAIN_AUTO_SERIAL_LOCAL_MACHINE equ 7
      CERT_CHAIN_AUTO_HPKP_RULE_INFO equ 8
      ; The following is a REG_DWORD that can be set to disable
      ; auto flush or enable the logging of auto create, free or
      ; flush events. By default, auto flush is enabled without
      ; any logging.
      CERT_CHAIN_AUTO_FLAGS_VALUE_NAME equ <L("AutoFlags")>
      CERT_CHAIN_AUTO_FLUSH_DISABLE_FLAG equ 00000001h
      CERT_CHAIN_AUTO_LOG_CREATE_FLAG equ 00000002h
      CERT_CHAIN_AUTO_LOG_FREE_FLAG equ 00000004h
      CERT_CHAIN_AUTO_LOG_FLUSH_FLAG equ 00000008h
      CERT_CHAIN_AUTO_LOG_FLAGS equ <(CERT_CHAIN_AUTO_LOG_CREATE_FLAG or CERT_CHAIN_AUTO_LOG_FREE_FLAG or CERT_CHAIN_AUTO_LOG_FLUSH_FLAG)>
      ; The following are REG_DWORDs. If the registry value doesn't exist or
      ; is set to zero, then, the DEFAULT is used.
      ; This is the delta time in seconds to set the first timeout.
      ; At the first timeout we set the initial next timeout.
      CERT_CHAIN_AUTO_FLUSH_FIRST_DELTA_SECONDS_VALUE_NAME equ <L("AutoFlushFirstDeltaSeconds")>
      ; 5 Minutes
      CERT_CHAIN_AUTO_FLUSH_FIRST_DELTA_SECONDS_DEFAULT equ (5 * 60)
      ; This is the delta time in seconds to set the next timeouts.
      ; For each next timeout, we check if there was any chain
      ; engine usage (such as CertGetCertificateChain) since
      ; the last timeout. Auto flush is triggered if there wasn't
      ; any usage. Otherwise, we set the next timeout to this delta time.
      CERT_CHAIN_AUTO_FLUSH_NEXT_DELTA_SECONDS_VALUE_NAME equ <L("AutoFlushNextDeltaSeconds")>
      ; 30 Minutes
      CERT_CHAIN_AUTO_FLUSH_NEXT_DELTA_SECONDS_DEFAULT equ (30 * 60)
      ; The following is REG_SZ containing the name of the file to log
      ; the certificate chain engine auto events to.
      ; The file's directory must already exist. If the file already
      ; exists, events are appended. Otherwise, the file is created.
      ; The directory/file should be ACL'ed so all processes and users have
      ; write access.
      CERT_CHAIN_AUTO_LOG_FILE_NAME_VALUE_NAME equ <L("AutoLogFileName")>
      ; The following is REG_MULTI_SZ containing the list of
      ; process names to disable auto flush for.
      ; Auto flush is always disabled for the lsass.exe process. It doesn't need
      ; to be in the following registry value list.
      CERT_CHAIN_DISABLE_AUTO_FLUSH_PROCESS_NAME_LIST_VALUE_NAME equ <L("DisableAutoFlushProcessNameList")>
      ; The following are REG_DWORD's. These configuration parameters are
      ; used by the following APIs to get a non-blocking, time valid OCSP
      ; response for a server certificate chain:
      ;   CertOpenServerOcspResponse
      ;   CertAddRefServerOcspResponse
      ;   CertCloseServerOcspResponse
      ;   CertGetServerOcspResponseContext
      ;   CertAddRefServerOcspResponseContext
      ;   CertFreeServerOcspResponseContext
      ; This is the minimum validity of the server OCSP response to be
      ; returned by CertGetServerOcspResponseContext(). Since this OCSP
      ; response will be returned to the client, it must be sufficiently long
      ; so that the client will treat it as being time valid.
      CERT_SRV_OCSP_RESP_MIN_VALIDITY_SECONDS_VALUE_NAME equ <L("SrvOcspRespMinValiditySeconds")>
      ; 10 minutes
      CERT_SRV_OCSP_RESP_MIN_VALIDITY_SECONDS_DEFAULT equ (10 * 60)
      ; This is the maximum number of milliseconds for each server OCSP response
      ; pre-fetch wire URL retrieval.
      CERT_SRV_OCSP_RESP_URL_RETRIEVAL_TIMEOUT_MILLISECONDS_VALUE_NAME equ <L("SrvOcspRespUrlRetrievalTimeoutMilliseconds")>
      ; 15 seconds
      CERT_SRV_OCSP_RESP_URL_RETRIEVAL_TIMEOUT_MILLISECONDS_DEFAULT equ (15 * 1000)
      ; This is the maximum number of seconds to do a server OCSP response
      ; pre-fetch retrieval before the OCSP response's NextUpdate. The
      ; server OCSP response pre-fetch thread will wait until CurrentTime >=
      ; NextUpdate - MaxBeforeNextUpdateSeconds before doing the next retrieval.
      CERT_SRV_OCSP_RESP_MAX_BEFORE_NEXT_UPDATE_SECONDS_VALUE_NAME equ <L("SrvOcspRespMaxBeforeNextUpdateSeconds")>
      ; 4 hours
      CERT_SRV_OCSP_RESP_MAX_BEFORE_NEXT_UPDATE_SECONDS_DEFAULT equ (4 * 60 * 60)
      ; This is the minimum number of seconds to do a server OCSP response
      ; pre-fetch retrieval before the OCSP response's NextUpdate.
      ; If CurrentTime >= NextUpdate - MinBeforeNextUpdateSeconds, will wait until
      ; after NextUpdate + MinAfterNextUpdateSeconds.
      CERT_SRV_OCSP_RESP_MIN_BEFORE_NEXT_UPDATE_SECONDS_VALUE_NAME equ <L("SrvOcspRespMinBeforeNextUpdateSeconds")>
      ; 2 minutes
      CERT_SRV_OCSP_RESP_MIN_BEFORE_NEXT_UPDATE_SECONDS_DEFAULT equ (2 * 60)
      ; This is the minimum number of seconds to do a server OCSP response
      ; pre-fetch retrieval after the OCSP response's NextUpdate when
      ; (NextUpdate - MinBeforeNextUpdateSeconds) < CurrentTime < NextUpdate.
      CERT_SRV_OCSP_RESP_MIN_AFTER_NEXT_UPDATE_SECONDS_VALUE_NAME equ <L("SrvOcspRespMinAfterNextUpdateSeconds")>
      ; 1 minute
      CERT_SRV_OCSP_RESP_MIN_AFTER_NEXT_UPDATE_SECONDS_DEFAULT equ (1 * 60)
      ; This is the minimum number of seconds between certificate directory
      ; update sync checks. Used by certutil.exe for the downloadOcsp option.
      CERT_SRV_OCSP_RESP_MIN_SYNC_CERT_FILE_SECONDS_VALUE_NAME equ <L("SrvOcspRespMinSyncCertFileSeconds")>
      ; 5 seconds
      CERT_SRV_OCSP_RESP_MIN_SYNC_CERT_FILE_SECONDS_DEFAULT equ 5
      ; This is the maximum number of seconds between certificate directory
      ; update sync checks. Used by certutil.exe for the downloadOcsp option.
      CERT_SRV_OCSP_RESP_MAX_SYNC_CERT_FILE_SECONDS_VALUE_NAME equ <L("SrvOcspRespMaxSyncCertFileSeconds")>
      ; 1 hour
      CERT_SRV_OCSP_RESP_MAX_SYNC_CERT_FILE_SECONDS_DEFAULT equ (1 * 60 * 60)
      ; The following are REG_DWORD's. These configuration parameters are used
      ; in the ordering of the revocation retrieval URLs.
      ; When the number of cached OCSP URLs associated with the same CDP extension
      ; equal or exceed this number, the OCSP AIA URLs aren't used.
      CRYPTNET_MAX_CACHED_OCSP_PER_CRL_COUNT_VALUE_NAME equ <L("CryptnetMaxCachedOcspPerCrlCount")>
      CRYPTNET_MAX_CACHED_OCSP_PER_CRL_COUNT_DEFAULT equ 500
      ; The above registry value can be set to this value, to disable OCSP
      ; when a CDP extension is present. Note, a registry value of 0, uses the
      ; above default value.
      CRYPTNET_OCSP_AFTER_CRL_DISABLE equ 0FFFFFFFFh
      ; The following are REG_DWORD's. These configuration parameters are
      ; used by the Cryptnet Url Cache Service (CUCS).
      ; The following parameter is used as the default flush exempt seconds
      CRYPTNET_URL_CACHE_DEFAULT_FLUSH_EXEMPT_SECONDS_VALUE_NAME equ <L("CryptnetDefaultFlushExemptSeconds")>
      ; 4 Weeks : 28 days * 24 hours * 60 minutes * 60 seconds
      CRYPTNET_URL_CACHE_DEFAULT_FLUSH_EXEMPT_SECONDS_DEFAULT equ (28 * 24 * 60 * 60)
      ; Following 2 parameters are used to set the lower and upper limit
      ; on the max-age retrievals done before the Publish and NextUpdate times.
      CRYPTNET_PRE_FETCH_MIN_MAX_AGE_SECONDS_VALUE_NAME equ <L("CryptnetPreFetchMinMaxAgeSeconds")>
      ; 1 hour
      CRYPTNET_PRE_FETCH_MIN_MAX_AGE_SECONDS_DEFAULT equ (1 * 60 * 60)
      CRYPTNET_PRE_FETCH_MAX_MAX_AGE_SECONDS_VALUE_NAME equ <L("CryptnetPreFetchMaxMaxAgeSeconds")>
      ; 2 Weeks : 14 days * 24 hours * 60 minutes * 60 seconds
      CRYPTNET_PRE_FETCH_MAX_MAX_AGE_SECONDS_DEFAULT equ (14 * 24 * 60 * 60)
      ; Following parameter is used to set the lower limit on the
      ; OCSP validity period
      CRYPTNET_PRE_FETCH_MIN_OCSP_VALIDITY_PERIOD_SECONDS_VALUE_NAME equ <L("CryptnetPreFetchMinOcspValidityPeriodSeconds")>
      ; 2 Weeks : 14 days * 24 hours * 60 minutes * 60 seconds
      CRYPTNET_PRE_FETCH_MIN_OCSP_VALIDITY_PERIOD_SECONDS_DEFAULT equ (14 * 24 * 60 * 60)
      ; Following 3 parameters are used to calculate the PreFetch start before
      ; the NextUpdate
      ; Where PreFetchStartTime = PublishTime +
      ;                              PublishPeriod / AfterPublishPreFetchDivisor
      ;       PreFetchEndTime = NextUpdate -
      ;                              PublishPeriod / BeforeNextUpdatePreFetchDivisor
      ;       PreFetchPeriod = PreFetchEndTime - PreFetchStartTime
      ;       if (PreFetchPeriod < MinBeforeNextUpdatePreFetchPeriodSeconds)
      ;          - No PreFetch is done before NextUpdate
      ;       else
      ;          - PreFetch starts are randomized over this period
      ; The start of the PreFetch period is delayed after the start of the
      ; Publish period by dividing the PublishPeriod (NextUpdate - PublishTime)
      ; by this integer divisor.
      CRYPTNET_PRE_FETCH_AFTER_PUBLISH_PRE_FETCH_DIVISOR_VALUE_NAME equ <L("CryptnetPreFetchAfterPublishPreFetchDivisor")>
      ; 10, where 12 hours / 10 = 72 minutes or 1.2 hours / 10 = 7.2 minutes
      CRYPTNET_PRE_FETCH_AFTER_PUBLISH_PRE_FETCH_DIVISOR_DEFAULT equ 10
      ; The finish of the PreFetch period occurs before NextUpdate
      ; by dividing the PublishPeriod (NextUpdate - PublishTime)
      ; by this integer divisor.
      CRYPTNET_PRE_FETCH_BEFORE_NEXT_UPDATE_PRE_FETCH_DIVISOR_VALUE_NAME equ <L("CryptnetPreFetchBeforeNextUpdatePreFetchDivisor")>
      ; 20, where 12 hours / 20 = 36 minutes or 1.2 hours / 10 = 3.6 minutes
      CRYPTNET_PRE_FETCH_BEFORE_NEXT_UPDATE_PRE_FETCH_DIVISOR_DEFAULT equ 20
      ; The PreFetch period must exceed this minimum duration in seconds
      ; to do a PreFetch before NextUpdate
      CRYPTNET_PRE_FETCH_MIN_BEFORE_NEXT_UPDATE_PRE_FETCH_PERIOD_SECONDS_VALUE_NAME equ <L("CryptnetPreFetchMinBeforeNextUpdatePreFetchSeconds")>
      ; 1 hour
      ; For the default OCSP period of 12 hours using above defaults,
      ; PreFetchPeriod = 72 minutes - 7.2 minutes - 3.6 mintes = 61.2 minutes
      CRYPTNET_PRE_FETCH_MIN_BEFORE_NEXT_UPDATE_PRE_FETCH_PERIOD_SECONDS_DEFAULT equ (1 * 60 * 60)
      ; Following 4 parameters are used to calculate the PreFetch start after
      ; the NextUpdate
      ; ValidityPeriod = NextUpdate - ThisUpdate
      ; PreFetchPeriod = ValidityPeriod / AfterNextUpdatePreFetchDivisor
      ; Where PreFetchPeriod is decreased to MaxAfterNextUpdatePreFetchPeriodSeconds
      ; or increased to MinAfterNextUpdatePreFetchPeriodSeconds;
      ; PreFetchStartTime = NextUpdate
      ; PreFetchEndTime = PreFetchStartTime + PreFetchPeriod
      ; PreFetch starts are randomized over the above PreFetchPeriod
      ; If CurrentTime > RandomPreFetchStartTime, then, the
      ; AfterCurrentTimePreFetchPeriodSeconds is randomized and added to
      ; CurrentTime for the RandomPreFetchStartTime
      ; The PreFetch period after NextUpdate is initially calculated by
      ; dividing the ValidityPeriod (NextUpdate - ThisUpdate) by this integer
      ; divisor.
      CRYPTNET_PRE_FETCH_VALIDITY_PERIOD_AFTER_NEXT_UPDATE_PRE_FETCH_DIVISOR_VALUE_NAME equ <L("CryptnetPreFetchValidityPeriodAfterNextUpdatePreFetchDivisor")>
      ; 10, where 1 week / 10 = 16.8 hours
      CRYPTNET_PRE_FETCH_VALIDITY_PERIOD_AFTER_NEXT_UPDATE_PRE_FETCH_DIVISOR_DEFAULT equ 10
      ; If necessary, the above PreFetch period will be decreased
      ; to this maximum duration in seconds.
      CRYPTNET_PRE_FETCH_MAX_AFTER_NEXT_UPDATE_PRE_FETCH_PERIOD_SECONDS_VALUE_NAME equ <L("CryptnetPreFetchMaxAfterNextUpdatePreFetchPeriodSeconds")>
      ; 4 hours
      CRYPTNET_PRE_FETCH_MAX_AFTER_NEXT_UPDATE_PRE_FETCH_PERIOD_SECONDS_DEFAULT equ (4 * 60 * 60)
      ; If necessary, the above PreFetch period will be increased
      ; to this minimum duration in seconds.
      CRYPTNET_PRE_FETCH_MIN_AFTER_NEXT_UPDATE_PRE_FETCH_PERIOD_SECONDS_VALUE_NAME equ <L("CryptnetPreFetchMinAfterNextUpdatePreFetchPeriodSeconds")>
      ; 30 minutes
      CRYPTNET_PRE_FETCH_MIN_AFTER_NEXT_UPDATE_PRE_FETCH_PERIOD_SECONDS_DEFAULT equ (30 * 60)
      ; If the CurrentTime is after the above randomized start time, the following
      ; parameter will be randomized and added to the CurrentTime.
      CRYPTNET_PRE_FETCH_AFTER_CURRENT_TIME_PRE_FETCH_PERIOD_SECONDS_VALUE_NAME equ <L("CryptnetPreFetchAfterCurrentTimePreFetchPeriodSeconds")>
      ; 30 minutes
      CRYPTNET_PRE_FETCH_AFTER_CURRENT_TIME_PRE_FETCH_PERIOD_SECONDS_DEFAULT equ (30 * 60)
      ; Following parameter specifies the minimum time period between sending
      ; trigger URL cache PreFetch LRPC messages to cryptsvc after doing online
      ; revocation enabled chain builds.
      CRYPTNET_PRE_FETCH_TRIGGER_PERIOD_SECONDS_VALUE_NAME equ <L("CryptnetPreFetchTriggerPeriodSeconds")>
      ; 10 minutes
      CRYPTNET_PRE_FETCH_TRIGGER_PERIOD_SECONDS_DEFAULT equ (10 * 60)
      ; The above registry value can be set to this value, to disable the
      ; sending of trigger URL cache PreFetch LRPC messages. Note, a registry
      ; value of 0, uses the above default value.
      CRYPTNET_PRE_FETCH_TRIGGER_DISABLE equ 0FFFFFFFFh
      ; Following parameter specifies the delay time to wait to scan the
      ; URL cache directory after receiving a trigger LRPC message request.
      CRYPTNET_PRE_FETCH_SCAN_AFTER_TRIGGER_DELAY_SECONDS_VALUE_NAME equ <L("CryptnetPreFetchScanAfterTriggerDelaySeconds")>
      ; 60 seconds
      CRYPTNET_PRE_FETCH_SCAN_AFTER_TRIGGER_DELAY_SECONDS_DEFAULT equ 60
      ; Following parameter specifies the maximum amount of time to wait for any
      ; PreFetch retrieval to complete
      CRYPTNET_PRE_FETCH_RETRIEVAL_TIMEOUT_SECONDS_VALUE_NAME equ <L("CryptnetPreFetchRetrievalTimeoutSeconds")>
      ; 5 minutes
      CRYPTNET_PRE_FETCH_RETRIEVAL_TIMEOUT_SECONDS_DEFAULT equ (5 * 60)
      ;+-------------------------------------------------------------------------
      ; Cryptnet in-process CRL PreFetch configuration
      ;--------------------------------------------------------------------------
      CRYPTNET_CRL_PRE_FETCH_CONFIG_REGPATH equ <CERT_CHAIN_CONFIG_REGPATH L("\CrlPreFetch")>
      ; The following is REG_MULTI_SZ containing the list of
      ; process names to enable PreFetching for
      CRYPTNET_CRL_PRE_FETCH_PROCESS_NAME_LIST_VALUE_NAME equ <L("ProcessNameList")>
      ; The following is REG_MULTI_SZ containing the list of
      ; CRL Urls to be PreFetched. This should be the encoded format used
      ; in the certificate. Normally, the one with the %20 for the " " space 
      ; character.
      CRYPTNET_CRL_PRE_FETCH_URL_LIST_VALUE_NAME equ <L("PreFetchUrlList")>
      ; By default PreFetch information events are logged to the Windows
      ; Application Logs. The following REG_DWORD can be set to nonzero
      ; value to disable the logging.
      CRYPTNET_CRL_PRE_FETCH_DISABLE_INFORMATION_EVENTS_VALUE_NAME equ <L("DisableInformationEvents")>
      ; The following is REG_SZ containing the name of the file to log verbose events
      ; to. The file's directory must already exist. If the file already
      ; exists, events are appended. Otherwise, the file is created.
      ; The directory/file should be ACL'ed so all processes and users have
      ; write access.
      CRYPTNET_CRL_PRE_FETCH_LOG_FILE_NAME_VALUE_NAME equ <L("LogFileName")>
      ; The following are REG_DWORDs. If the registry value doesn't exist or
      ; is set to zero, then, the DEFAULT is used.
      ; Following parameter specifies the maximum amount of time to wait for any
      ; CRL PreFetch retrieval to complete
      CRYPTNET_CRL_PRE_FETCH_TIMEOUT_SECONDS_VALUE_NAME equ <L("TimeoutSeconds")>
      ; 5 minutes
      CRYPTNET_CRL_PRE_FETCH_TIMEOUT_SECONDS_DEFAULT equ (5 * 60)
      ; Following parameter specifies the max-age retrievals before the
      ; expected publish time. Setting to any value >= NextUpdate - ThisUpdate
      ; will disable. 5 minutes is the minimum.
      CRYPTNET_CRL_PRE_FETCH_MAX_AGE_SECONDS_VALUE_NAME equ <L("MaxAgeSeconds")>
      ; 2 hours
      CRYPTNET_CRL_PRE_FETCH_MAX_AGE_SECONDS_DEFAULT equ (2 * 60 * 60)
      ; 5 minutes
      CRYPTNET_CRL_PRE_FETCH_MAX_AGE_SECONDS_MIN equ (5 * 60)
      ; Following parameter specifies the expected publish time before
      ; NextUpdate
      CRYPTNET_CRL_PRE_FETCH_PUBLISH_BEFORE_NEXT_UPDATE_SECONDS_VALUE_NAME equ <L("PublishBeforeNextUpdateSeconds")>
      ; 1 hour
      CRYPTNET_CRL_PRE_FETCH_PUBLISH_BEFORE_NEXT_UPDATE_SECONDS_DEFAULT equ (1 * 60 * 60)
      ; Following parameter specifies the interval to be randomized and
      ; subtracted from the expected publish time. Setting to any value
      ; >= publish time will disable randomization. Setting to 1
      ; will disable any randomization. Setting to 0 will use the DEFAULT.
      CRYPTNET_CRL_PRE_FETCH_PUBLISH_RANDOM_INTERVAL_SECONDS_VALUE_NAME equ <L("PublishRandomIntervalSeconds")>
      ; 5 minutes
      CRYPTNET_CRL_PRE_FETCH_PUBLISH_RANDOM_INTERVAL_SECONDS_DEFAULT equ (5 * 60)
      ; Following parameter specifies the minimum time before NextUpdate
      CRYPTNET_CRL_PRE_FETCH_MIN_BEFORE_NEXT_UPDATE_SECONDS_VALUE_NAME equ <L("MinBeforeNextUpdateSeconds")>
      ; 5 minutes
      CRYPTNET_CRL_PRE_FETCH_MIN_BEFORE_NEXT_UPDATE_SECONDS_DEFAULT equ (5 * 60)
      ; Following parameter specifies the minimum time after NextUpdate
      CRYPTNET_CRL_PRE_FETCH_MIN_AFTER_NEXT_UPDATE_SECONDS_VALUE_NAME equ <L("MinAfterNextUpdateSeconds")>
      ; 5 minutes
      CRYPTNET_CRL_PRE_FETCH_MIN_AFTER_NEXT_UPDATE_SECONDS_DEFAULT equ (5 * 60)
      ;+-------------------------------------------------------------------------
      ; The following configuration parameters are store in HKLM group policy
      ;--------------------------------------------------------------------------
      CERT_GROUP_POLICY_CHAIN_CONFIG_REGPATH equ <CERT_GROUP_POLICY_SYSTEM_STORE_REGPATH L("\ChainEngine\Config")>
      ; In Vista, the following have been moved from the above HKLM
      ; configuration parameters:
      ; The following are REG_DWORD's. These configuration parameters are used
      ; to override the default URL timeouts in chain building
      ; This is the default URL timeout in milliseconds
      CERT_CHAIN_URL_RETRIEVAL_TIMEOUT_MILLISECONDS_VALUE_NAME equ <L("ChainUrlRetrievalTimeoutMilliseconds")>
      ; 15 seconds
      CERT_CHAIN_URL_RETRIEVAL_TIMEOUT_MILLISECONDS_DEFAULT equ (15 * 1000)
      ; This is the default revocation accumulative URL timeout in milliseconds
      ; The first revocation URL retrieval uses half of this timeout
      CERT_CHAIN_REV_ACCUMULATIVE_URL_RETRIEVAL_TIMEOUT_MILLISECONDS_VALUE_NAME equ <L("ChainRevAccumulativeUrlRetrievalTimeoutMilliseconds")>
      ; 20 seconds
      CERT_CHAIN_REV_ACCUMULATIVE_URL_RETRIEVAL_TIMEOUT_MILLISECONDS_DEFAULT equ (20 * 1000)
      ; REG_DWORD: Set this value to non-zero in order to enable Internet connections
      ; with Unknown Authorization
      CERT_RETR_BEHAVIOR_INET_AUTH_VALUE_NAME equ <L("EnableInetUnknownAuth")>
      ; REG_DWORD: Set this value to non-zero in order to override Internet
      ; connectivity status allowing LOCAL to be treated as INTERNET.
      CERT_RETR_BEHAVIOR_INET_STATUS_VALUE_NAME equ <L("EnableInetLocal")>
      ; REG_DWORD: Set this value to non-zero in order to allow
      ; file:// URL scheme.
      CERT_RETR_BEHAVIOR_FILE_VALUE_NAME equ <L("AllowFileUrlScheme")>
      ; REG_DWORD: Set this value to non-zero in order to disable
      ; LDAP mutual authentication and & encryption.
      CERT_RETR_BEHAVIOR_LDAP_VALUE_NAME equ <L("DisableLDAPSignAndEncrypt")>
      ; Note, will allow the machine setting to be used if this value isn't
      ; defined.
      ; By default AIA OCSP URLs are before CDP CRL URLs. When the number of cached
      ; OCSP URLs associated with the same CDP extension equal or exceed this
      ; number, the CRL URLs are placed before the OCSP URLs.
      CRYPTNET_CACHED_OCSP_SWITCH_TO_CRL_COUNT_VALUE_NAME equ <L("CryptnetCachedOcspSwitchToCrlCount")>
      CRYPTNET_CACHED_OCSP_SWITCH_TO_CRL_COUNT_DEFAULT equ 50
      ; The above registry value can be set to this value, to always place
      ; the CRL URLs before the OCSP URLs. Note, a registry value of 0, uses the
      ; above default value.
      CRYPTNET_CRL_BEFORE_OCSP_ENABLE equ 0FFFFFFFFh
      ; Support for the following was removed in Vista. Changed to use
      ; the following OPTIONS flags in HKLM Group Policy
      CERT_CHAIN_DISABLE_AIA_URL_RETRIEVAL_VALUE_NAME equ <L("DisableAIAUrlRetrieval")>
      ; By default AIA Url Retrieval is enabled. Set this registry value to nonzero
      ; to disable
      ; This is the name of the REG_DWORD for chain engine Options
      CERT_CHAIN_OPTIONS_VALUE_NAME equ <L("Options")>
      ; Disable AIA URL retrieval when this bit is set in the Options
      CERT_CHAIN_OPTION_DISABLE_AIA_URL_RETRIEVAL equ 2h
      ; Enable SIA URL retrieval when this bit is set in the Options
      CERT_CHAIN_OPTION_ENABLE_SIA_URL_RETRIEVAL equ 4h
      CERT_CHAIN_CROSS_CERT_DOWNLOAD_INTERVAL_HOURS_VALUE_NAME equ <L("CrossCertDownloadIntervalHours")>
      ; 7 days
      CERT_CHAIN_CROSS_CERT_DOWNLOAD_INTERVAL_HOURS_DEFAULT equ (24 * 7)
      ; When not defined or zero, the CRL validity isn't extended
      CERT_CHAIN_CRL_VALIDITY_EXT_PERIOD_HOURS_VALUE_NAME equ <L("CRLValidityExtensionPeriod")>
      ; 12 hour
      CERT_CHAIN_CRL_VALIDITY_EXT_PERIOD_HOURS_DEFAULT equ 12
      ; The chain engine defines the store namespace and cache partitioning for
      ; the Certificate Chaining infrastructure.  A default chain engine
      ; is defined for the process which uses all default system stores e.g.
      ; Root, CA, Trust, for chain building and caching.  If an application
      ; wishes to define its own store namespace or have its own partitioned
      ; cache then it can create its own chain engine.  It is advisable to create
      ; a chain engine at application startup and use it throughout the lifetime
      ; of the application in order to get optimal caching behavior
      HCERTCHAINENGINE typedef HANDLE
      HCCE_CURRENT_USER equ <(NULL)>
      HCCE_LOCAL_MACHINE equ (1h)
      HCCE_SERIAL_LOCAL_MACHINE equ (2h)
      ; Create a certificate chain engine.
      ; Configuration parameters for the certificate chain engine
      ;      hRestrictedRoot - restrict the root store (must be a subset of "Root")
      ;      hRestrictedTrust - restrict the store for CTLs
      ;      hRestrictedOther - restrict the store for certs and CRLs
      ;      cAdditionalStore, rghAdditionalStore - additional stores
      ;      hExclusiveRoot - the root store to be used exclusively.
      ;                       If not NULL, then the restricted  stores
      ;                       the system "Root" and "TrustedPeople" are not used
      ;      hExclusiveTrustedPeople - the trusted people store to be used exclusively.
      ;                       If not NULL, then the restricted  stores
      ;                       the system "Root" and "TrustedPeople" are not used
      ;      NOTE:
      ;        (hExclusiveRoot, hExclusiveTrustedPeople) are mutually exclusive
      ;        with (hRestrictedRoot, hRestrictedTrust, hRestrictedOther).
      ;        If either hExclusiveRoot or hExclusiveTrustedPeople are used,
      ;        then all restricted handles must be NULL and non of the system
      ;        "Root" and "TrustedPeople" are used.
      ;      The algorithm used to define the stores for the engine is as
      ;            follows:
      ;          If NULL!=hExclusiveRoot or NULL!=hExclusiveTrustedPeople
      ;              hRoot = hExclusiveRoot
      ;              hTrust = hWorld (defined later)
      ;              hOther = hWorld
      ;              hWorld = hRoot + hExclusiveTrustedPeople + "CA" + "My" + rghAdditionalStore
      ;          Else
      ;              hRoot = hRestrictedRoot or System Store "Root"
      ;              hTrust = hRestrictedTrust or hWorld (defined later)
      ;              hOther = hRestrictedOther or (hRestrictedTrust == NULL) ? hWorld :
      ;                       hRestrictedTrust + hWorld
      ;              hWorld = hRoot + "CA" + "My" + "Trust" + rghAdditionalStore
      ;          Endif
      ;      dwFlags  - flags
      ;          CERT_CHAIN_CACHE_END_CERT - information will be cached on
      ;                                      the end cert as well as the other
      ;                                      certs in the chain
      ;          CERT_CHAIN_THREAD_STORE_SYNC - use separate thread for store syncs
      ;                                         and related cache updates
      ;          CERT_CHAIN_CACHE_ONLY_URL_RETRIEVAL - don't hit the wire to get
      ;                                                URL based objects
      ;      dwUrlRetrievalTimeout - timeout for wire based URL object retrievals
      ;                              (milliseconds)
      CERT_CHAIN_CACHE_END_CERT equ 00000001h
      CERT_CHAIN_THREAD_STORE_SYNC equ 00000002h
      CERT_CHAIN_CACHE_ONLY_URL_RETRIEVAL equ 00000004h
      CERT_CHAIN_USE_LOCAL_MACHINE_STORE equ 00000008h
      CERT_CHAIN_ENABLE_CACHE_AUTO_UPDATE equ 00000010h
      CERT_CHAIN_ENABLE_SHARE_STORE equ 00000020h
      ; Following CertGetCertificateChain dwFlag can also be set on the 
      ; chain engine flags
      ; #define CERT_CHAIN_DISABLE_AIA                      0x00002000
      CERT_CHAIN_ENGINE_CONFIG struct
        cbSize DWORD ?
        hRestrictedRoot HCERTSTORE ?
        hRestrictedTrust HCERTSTORE ?
        hRestrictedOther HCERTSTORE ?
        cAdditionalStore DWORD ?
        rghAdditionalStore POINTER ?
        dwFlags DWORD ?
        dwUrlRetrievalTimeout DWORD ?
        ; milliseconds
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
        ; dwExclusiveFlags
        ; CA certificates in hExclusiveRoot are also trusted. Chain building
        ; can terminate in a trusted CA certificate.
        CERT_CHAIN_EXCLUSIVE_ENABLE_CA_FLAG equ 00000001h
      endif
      @DefProto DllImport, CertCreateCertificateChainEngine, WIN_STD_CALL_CONV,, <:PCERT_CHAIN_ENGINE_CONFIG, :ptr HCERTCHAINENGINE>, 8
      ; Free a certificate trust engine
      @DefProto DllImport, CertFreeCertificateChainEngine, WIN_STD_CALL_CONV,, <:HCERTCHAINENGINE>, 4
      ; Resync the certificate chain engine.  This resync's the stores backing
      ; the engine and updates the engine caches.
      @DefProto DllImport, CertResyncCertificateChainEngine, WIN_STD_CALL_CONV,, <:HCERTCHAINENGINE>, 4
      ; When an application requests a certificate chain, the data structure
      ; returned is in the form of a CERT_CHAIN_CONTEXT.  This contains
      ; an array of CERT_SIMPLE_CHAIN where each simple chain goes from
      ; an end cert to a self signed cert and the chain context connects simple
      ; chains via trust lists.  Each simple chain contains the chain of
      ; certificates, summary trust information about the chain and trust information
      ; about each certificate element in the chain.
      ; Trust status bits
      CERT_TRUST_STATUS struct
        dwErrorStatus DWORD ?
        dwInfoStatus DWORD ?
      CERT_TRUST_STATUS ends
      _CERT_TRUST_STATUS typedef CERT_TRUST_STATUS
      PCERT_TRUST_STATUS typedef ptr CERT_TRUST_STATUS
      ; The following are error status bits
      ; These can be applied to certificates and chains
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
      ; In LH, this error will never be set.
      CERT_TRUST_HAS_NOT_DEFINED_NAME_CONSTRAINT equ 00002000h
      CERT_TRUST_HAS_NOT_PERMITTED_NAME_CONSTRAINT equ 00004000h
      CERT_TRUST_HAS_EXCLUDED_NAME_CONSTRAINT equ 00008000h
      CERT_TRUST_IS_OFFLINE_REVOCATION equ 01000000h
      CERT_TRUST_NO_ISSUANCE_CHAIN_POLICY equ 02000000h
      CERT_TRUST_IS_EXPLICIT_DISTRUST equ 04000000h
      CERT_TRUST_HAS_NOT_SUPPORTED_CRITICAL_EXT equ 08000000h
      CERT_TRUST_HAS_WEAK_SIGNATURE equ 00100000h
      CERT_TRUST_HAS_WEAK_HYGIENE equ 00200000h
      ; These can be applied to chains only
      CERT_TRUST_IS_PARTIAL_CHAIN equ 00010000h
      CERT_TRUST_CTL_IS_NOT_TIME_VALID equ 00020000h
      CERT_TRUST_CTL_IS_NOT_SIGNATURE_VALID equ 00040000h
      CERT_TRUST_CTL_IS_NOT_VALID_FOR_USAGE equ 00080000h
      ; The following are info status bits
      ; These can be applied to certificates only
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
      ; These can be applied to certificates and chains
      CERT_TRUST_HAS_PREFERRED_ISSUER equ 00000100h
      CERT_TRUST_HAS_ISSUANCE_CHAIN_POLICY equ 00000200h
      CERT_TRUST_HAS_VALID_NAME_CONSTRAINTS equ 00000400h
      CERT_TRUST_IS_PEER_TRUSTED equ 00000800h
      CERT_TRUST_HAS_CRL_VALIDITY_EXTENDED equ 00001000h
      ; Indicates that the certificate was found in
      ; a store specified by hExclusiveRoot or hExclusiveTrustedPeople
      CERT_TRUST_IS_FROM_EXCLUSIVE_TRUST_STORE equ 00002000h
      if (NTDDI_VERSION ge NTDDI_WIN8)
        CERT_TRUST_IS_CA_TRUSTED equ 00004000h
        CERT_TRUST_HAS_AUTO_UPDATE_WEAK_SIGNATURE equ 00008000h
        CERT_TRUST_HAS_ALLOW_WEAK_SIGNATURE equ 00020000h
        ; Following is set if the input time is before the
        ; DISALLOWED_CA_FILETIME.
        CERT_TRUST_BEFORE_DISALLOWED_CA_FILETIME equ 00200000h
      endif
      ; These can be applied to chains only
      CERT_TRUST_IS_COMPLEX_CHAIN equ 00010000h
      CERT_TRUST_SSL_TIME_VALID equ 01000000h
      CERT_TRUST_NO_TIME_CHECK equ 02000000h
      ; Each certificate context in a simple chain has a corresponding chain element
      ; in the simple chain context
      ; dwErrorStatus has CERT_TRUST_IS_REVOKED, pRevocationInfo set
      ; dwErrorStatus has CERT_TRUST_REVOCATION_STATUS_UNKNOWN, pRevocationInfo set
      ;         Note that the post processing revocation supported in the first
      ;         version only sets cbSize and dwRevocationResult.  Everything else
      ;         is NULL
      ; Revocation Information
      CERT_REVOCATION_INFO struct
        cbSize DWORD ?
        dwRevocationResult DWORD ?
        pszRevocationOid =POINTER ?
        pvOidSpecificInfo POINTER ?
        ; fHasFreshnessTime is only set if we are able to retrieve revocation
        ; information. For a CRL its CurrentTime - ThisUpdate.
        fHasFreshnessTime DWORD ?
        dwFreshnessTime DWORD ?
        ; seconds
        ; NonNULL for CRL base revocation checking
        pCrlInfo PCERT_REVOCATION_CRL_INFO ?
      CERT_REVOCATION_INFO ends
      _CERT_REVOCATION_INFO typedef CERT_REVOCATION_INFO
      PCERT_REVOCATION_INFO typedef ptr CERT_REVOCATION_INFO
      ; Trust List Information
      CERT_TRUST_LIST_INFO struct
        cbSize DWORD ?
        pCtlEntry PCTL_ENTRY ?
        pCtlContext PCCTL_CONTEXT ?
      CERT_TRUST_LIST_INFO ends
      _CERT_TRUST_LIST_INFO typedef CERT_TRUST_LIST_INFO
      PCERT_TRUST_LIST_INFO typedef ptr CERT_TRUST_LIST_INFO
      ; Chain Element
      CERT_CHAIN_ELEMENT struct
        cbSize DWORD ?
        pCertContext PCCERT_CONTEXT ?
        TrustStatus CERT_TRUST_STATUS <>
        pRevocationInfo PCERT_REVOCATION_INFO ?
        pIssuanceUsage PCERT_ENHKEY_USAGE ?
        ; If NULL, any
        pApplicationUsage PCERT_ENHKEY_USAGE ?
        ; If NULL, any
        pwszExtendedErrorInfo =POINTER ?
        ; If NULL, none
      CERT_CHAIN_ELEMENT ends
      _CERT_CHAIN_ELEMENT typedef CERT_CHAIN_ELEMENT
      PCERT_CHAIN_ELEMENT typedef ptr CERT_CHAIN_ELEMENT
      PCCERT_CHAIN_ELEMENT typedef ptr CERT_CHAIN_ELEMENT
      ; The simple chain is an array of chain elements and a summary trust status
      ; for the chain
      ; rgpElements[0] is the end certificate chain element
      ; rgpElements[cElement-1] is the self-signed "root" certificate chain element
      CERT_SIMPLE_CHAIN struct
        cbSize DWORD ?
        TrustStatus CERT_TRUST_STATUS <>
        cElement DWORD ?
        rgpElement POINTER ?
        pTrustListInfo PCERT_TRUST_LIST_INFO ?
        ; fHasRevocationFreshnessTime is only set if we are able to retrieve
        ; revocation information for all elements checked for revocation.
        ; For a CRL its CurrentTime - ThisUpdate.
        ; dwRevocationFreshnessTime is the largest time across all elements
        ; checked.
        fHasRevocationFreshnessTime DWORD ?
        dwRevocationFreshnessTime DWORD ?
        ; seconds
      CERT_SIMPLE_CHAIN ends
      _CERT_SIMPLE_CHAIN typedef CERT_SIMPLE_CHAIN
      PCERT_SIMPLE_CHAIN typedef ptr CERT_SIMPLE_CHAIN
      PCCERT_SIMPLE_CHAIN typedef ptr CERT_SIMPLE_CHAIN
      ; And the chain context contains an array of simple chains and summary trust
      ; status for all the connected simple chains
      ; rgpChains[0] is the end certificate simple chain
      ; rgpChains[cChain-1] is the final (possibly trust list signer) chain which
      ; ends in a certificate which is contained in the root store
      CERT_CHAIN_CONTEXT typedef _CERT_CHAIN_CONTEXT
      PCERT_CHAIN_CONTEXT typedef ptr _CERT_CHAIN_CONTEXT
      PCCERT_CHAIN_CONTEXT typedef ptr CERT_CHAIN_CONTEXT
      _CERT_CHAIN_CONTEXT struct
        cbSize DWORD ?
        TrustStatus CERT_TRUST_STATUS <>
        cChain DWORD ?
        rgpChain POINTER ?
        ; Following is returned when CERT_CHAIN_RETURN_LOWER_QUALITY_CONTEXTS
        ; is set in dwFlags
        cLowerQualityChainContext DWORD ?
        rgpLowerQualityChainContext POINTER ?
        ; fHasRevocationFreshnessTime is only set if we are able to retrieve
        ; revocation information for all elements checked for revocation.
        ; For a CRL its CurrentTime - ThisUpdate.
        ; dwRevocationFreshnessTime is the largest time across all elements
        ; checked.
        fHasRevocationFreshnessTime DWORD ?
        dwRevocationFreshnessTime DWORD ?
        ; seconds
        ; Flags passed when created via CertGetCertificateChain
        dwCreateFlags DWORD ?
        ; Following is updated with unique Id when the chain context is logged.
        ChainId GUID <>
      _CERT_CHAIN_CONTEXT ends
      ; When building a chain, the there are various parameters used for finding
      ; issuing certificates and trust lists.  They are identified in the
      ; following structure
      ; Default usage match type is AND with value zero
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
          ; Note, if you #define CERT_CHAIN_PARA_HAS_EXTRA_FIELDS, then, you
          ; must zero all unused fields in this data structure.
          ; More fields could be added in a future release.
          RequestedIssuancePolicy CERT_USAGE_MATCH <>
          dwUrlRetrievalTimeout DWORD ?
          ; milliseconds
          fCheckRevocationFreshnessTime DWORD ?
          dwRevocationFreshnessTime DWORD ?
          ; seconds
          ; If nonNULL, any cached information before this time is considered
          ; time invalid and forces a wire retrieval. When set overrides
          ; the registry configuration CacheResync time.
          pftCacheResync LPFILETIME ?
          ; The following is set to check for Strong Signatures
          pStrongSignPara PCCERT_STRONG_SIGN_PARA ?
          ; By default the public key in the end certificate is checked.
          ; CERT_CHAIN_STRONG_SIGN_DISABLE_END_CHECK_FLAG can be
          ; set in the following flags to not check if the end certificate's public
          ; key length is strong.
          dwStrongSignFlags DWORD ?
        endif
      CERT_CHAIN_PARA ends
      _CERT_CHAIN_PARA typedef CERT_CHAIN_PARA
      PCERT_CHAIN_PARA typedef ptr CERT_CHAIN_PARA
      CERT_CHAIN_STRONG_SIGN_DISABLE_END_CHECK_FLAG equ 00000001h
      ; The following API is used for retrieving certificate chains
      ; Parameters:
      ;      hChainEngine     - the chain engine (namespace and cache) to use, NULL
      ;                         mean use the default chain engine
      ;      pCertContext     - the context we are retrieving the chain for, it
      ;                         will be the zero index element in the chain
      ;      pTime            - the point in time that we want the chain validated
      ;                         for.  Note that the time does not affect trust list,
      ;                         revocation, or root store checking.  NULL means use
      ;                         the current system time
      ;      hAdditionalStore - additional store to use when looking up objects
      ;      pChainPara       - parameters for chain building
      ;      dwFlags          - flags such as should revocation checking be done
      ;                         on the chain?
      ;      pvReserved       - reserved parameter, must be NULL
      ;      ppChainContext   - chain context returned
      ; CERT_CHAIN_CACHE_END_CERT can be used here as well
      ; Revocation flags are in the high nibble
      CERT_CHAIN_REVOCATION_CHECK_END_CERT equ 10000000h
      CERT_CHAIN_REVOCATION_CHECK_CHAIN equ 20000000h
      CERT_CHAIN_REVOCATION_CHECK_CHAIN_EXCLUDE_ROOT equ 40000000h
      CERT_CHAIN_REVOCATION_CHECK_CACHE_ONLY equ 80000000h
      ; By default, the dwUrlRetrievalTimeout in pChainPara is the timeout used
      ; for each revocation URL wire retrieval. When the following flag is set,
      ; dwUrlRetrievalTimeout is the accumulative timeout across all
      ; revocation URL wire retrievals.
      CERT_CHAIN_REVOCATION_ACCUMULATIVE_TIMEOUT equ 08000000h
      ; Revocation checking for an independent OCSP signer certificate.
      ; The above revocation flags indicate if just the signer certificate or all
      ; the certificates in the chain, excluding the root should be checked
      ; for revocation. If the signer certificate contains the
      ; szOID_PKIX_OCSP_NOCHECK extension, then, revocation checking is skipped
      ; for the leaf signer certificate. Both OCSP and CRL checking are allowed.
      ; However, recursive, independent OCSP signer certs are disabled.
      CERT_CHAIN_REVOCATION_CHECK_OCSP_CERT equ 04000000h
      ; First pass determines highest quality based upon:
      ;  - Chain signature valid (higest quality bit of this set)
      ;  - Complete chain
      ;  - Trusted root          (lowestest quality bit of this set)
      ; By default, second pass only considers paths >= highest first pass quality
      CERT_CHAIN_DISABLE_PASS1_QUALITY_FILTERING equ 00000040h
      CERT_CHAIN_RETURN_LOWER_QUALITY_CONTEXTS equ 00000080h
      CERT_CHAIN_DISABLE_AUTH_ROOT_AUTO_UPDATE equ 00000100h
      ; When this flag is set, pTime will be used as the timestamp time.
      ; pTime will be used to determine if the end certificate was valid at this
      ; time. Revocation checking will be relative to pTime.
      ; In addition, current time will also be used
      ; to determine if the certificate is still time valid. All remaining
      ; CA and root certificates will be checked using current time and not pTime.
      ; This flag was added 4/5/01 in WXP.
      CERT_CHAIN_TIMESTAMP_TIME equ 00000200h
      ; When this flag is set, "My" certificates having a private key or end
      ; entity certificates in the "TrustedPeople" store are trusted without
      ; doing any chain building. Neither the CERT_TRUST_IS_PARTIAL_CHAIN or
      ; CERT_TRUST_IS_UNTRUSTED_ROOT dwErrorStatus bits will be set for
      ; such certificates.
      ; This flag was added 6/9/03 in LH.
      CERT_CHAIN_ENABLE_PEER_TRUST equ 00000400h
      ; When this flag is set, "My" certificates aren't considered for
      ; PEER_TRUST.
      ; This flag was added 11/12/04 in LH.
      ; On 8-05-05 changed to never consider "My" certificates for PEER_TRUST.
      CERT_CHAIN_DISABLE_MY_PEER_TRUST equ 00000800h
      ; The following flag should be set to explicitly disable MD2 or MD4 for
      ; any requested EKU. By default, MD2 or MD4 isn't disabled for none,
      ; code signing, driver signing or time stamping requested EKUs.
      CERT_CHAIN_DISABLE_MD2_MD4 equ 00001000h
      ; The following flag can be set to explicitly disable AIA retrievals.
      ; If can also be set in the chain engine dwFlags.
      CERT_CHAIN_DISABLE_AIA equ 00002000h
      ; The following flag should be set when verifying the certificate
      ; associated with a file having the Mark-Of-The-Web
      CERT_CHAIN_HAS_MOTW equ 00004000h
      ; Only use certificates from the Additional and AuthRoot stores.
      ; If disabled, AuthRoot trust is enabled for this call.
      CERT_CHAIN_ONLY_ADDITIONAL_AND_AUTH_ROOT equ 00008000h
      ; The following flag should be set when the caller is prepared
      ; for opt-in weak signature errors. Should support an user
      ; option to click through. First for SHA1. In the future
      ; for RSA < 2048 bits.
      CERT_CHAIN_OPT_IN_WEAK_SIGNATURE equ 00010000h
      ; The following flag should be set when the caller is prepared
      ; to match the returned chain context elements when
      ; CERT_TRUST_BEFORE_DISALLOWED_CA_FILETIME is set in the
      ; dwInfoStatus.
      CERT_CHAIN_ENABLE_DISALLOWED_CA equ 00020000h
      @DefProto DllImport, CertGetCertificateChain, WIN_STD_CALL_CONV,, <:HCERTCHAINENGINE, :PCCERT_CONTEXT, :LPFILETIME, :HCERTSTORE, :PCERT_CHAIN_PARA, :DWORD, :LPVOID, :ptr PCCERT_CHAIN_CONTEXT>, 32
      ; Free a certificate chain
      @DefProto DllImport, CertFreeCertificateChain, WIN_STD_CALL_CONV,, <:PCCERT_CHAIN_CONTEXT>, 4
      ; Duplicate (add a reference to) a certificate chain
      @DefProto DllImport, CertDuplicateCertificateChain, WIN_STD_CALL_CONV,, <:PCCERT_CHAIN_CONTEXT>, 4
      ;+-------------------------------------------------------------------------
      ;  This data structure is optionally pointed to by the pChainPara field
      ;  in the CERT_REVOCATION_PARA and CRYPT_GET_TIME_VALID_OBJECT_EXTRA_INFO
      ;  data structures. CertGetCertificateChain() populates when it calls
      ;  the CertVerifyRevocation() API.
      ;--------------------------------------------------------------------------
      _CERT_REVOCATION_CHAIN_PARA struct
        cbSize DWORD ?
        hChainEngine HCERTCHAINENGINE ?
        hAdditionalStore HCERTSTORE ?
        dwChainFlags DWORD ?
        dwUrlRetrievalTimeout DWORD ?
        ; milliseconds
        pftCurrentTime LPFILETIME ?
        pftCacheResync LPFILETIME ?
        ; Max size of the URL object to download, in bytes.
        ; 0 value means no limit.
        cbMaxUrlRetrievalByteCount DWORD ?
      _CERT_REVOCATION_CHAIN_PARA ends
      ; Specific Revocation Type OID and structure definitions
      ; CRL Revocation OID
      REVOCATION_OID_CRL_REVOCATION equ (1)
      ; For the CRL revocation OID the pvRevocationPara is NULL
      ; CRL Revocation Info
      CRL_REVOCATION_INFO struct
        pCrlEntry PCRL_ENTRY ?
        pCrlContext PCCRL_CONTEXT ?
        pCrlIssuerChain PCCERT_CHAIN_CONTEXT ?
      CRL_REVOCATION_INFO ends
      _CRL_REVOCATION_INFO typedef CRL_REVOCATION_INFO
      PCRL_REVOCATION_INFO typedef ptr CRL_REVOCATION_INFO
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)*
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_PHONE_RESTRICTED or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      ;+-------------------------------------------------------------------------
      ;  Find the first or next certificate chain context in the store.
      ;  The chain context is found according to the dwFindFlags, dwFindType and
      ;  its pvFindPara. See below for a list of the find types and its parameters.
      ;  If the first or next chain context isn't found, NULL is returned.
      ;  Otherwise, a pointer to a read only CERT_CHAIN_CONTEXT is returned.
      ;  CERT_CHAIN_CONTEXT must be freed by calling CertFreeCertificateChain
      ;  or is freed when passed as the
      ;  pPrevChainContext on a subsequent call. CertDuplicateCertificateChain
      ;  can be called to make a duplicate.
      ;  pPrevChainContext MUST BE NULL on the first
      ;  call to find the chain context. To find the next chain context, the
      ;  pPrevChainContext is set to the CERT_CHAIN_CONTEXT returned by a previous
      ;  call.
      ;  NOTE: a NON-NULL pPrevChainContext is always CertFreeCertificateChain'ed by
      ;  this function, even for an error.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertFindChainInStore, WIN_STD_CALL_CONV,, <:HCERTSTORE, :DWORD, :DWORD, :DWORD, :ptr, :PCCERT_CHAIN_CONTEXT>, 24
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP|WINAPI_PARTITION_PHONE_RESTRICTED | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      CERT_CHAIN_FIND_BY_ISSUER equ 1
      ;+-------------------------------------------------------------------------
      ;  CERT_CHAIN_FIND_BY_ISSUER
      ;  Find a certificate chain having a private key for the end certificate and
      ;  matching one of the given issuer names. A matching dwKeySpec and
      ;  enhanced key usage can also be specified. Additionally a callback can
      ;  be provided for even more caller provided filtering before building the
      ;  chain.
      ;  By default, only the issuers in the first simple chain are compared
      ;  for a name match. CERT_CHAIN_FIND_BY_ISSUER_COMPLEX_CHAIN_FLAG can
      ;  be set in dwFindFlags to match issuers in all the simple chains.
      ;  CERT_CHAIN_FIND_BY_ISSUER_NO_KEY_FLAG can be set in dwFindFlags to
      ;  not check if the end certificate has a private key.
      ;  CERT_CHAIN_FIND_BY_ISSUER_COMPARE_KEY_FLAG can be set in dwFindFlags
      ;  to compare the public key in the end certificate with the crypto
      ;  provider's public key. The dwAcquirePrivateKeyFlags can be set
      ;  in CERT_CHAIN_FIND_BY_ISSUER_PARA to enable caching of the private key's
      ;  HKEY returned by the CSP.
      ;  If dwCertEncodingType == 0, defaults to X509_ASN_ENCODING for the
      ;  array of encoded issuer names.
      ;  By default, the hCertStore passed to CertFindChainInStore, is passed
      ;  as an additional store to CertGetCertificateChain.
      ;  CERT_CHAIN_FIND_BY_ISSUER_CACHE_ONLY_FLAG can be set in dwFindFlags
      ;  to improve performance by only searching the cached system stores
      ;  (root, my, ca, trust) to find the issuer certificates. If you are doing
      ;  a find in the "my" system store, than, this flag should be set to
      ;  improve performance.
      ;  Setting CERT_CHAIN_FIND_BY_ISSUER_LOCAL_MACHINE_FLAG in dwFindFlags
      ;  restricts CertGetCertificateChain to search the Local Machine
      ;  cached system stores instead of the Current User's.
      ;  Setting CERT_CHAIN_FIND_BY_ISSUER_CACHE_ONLY_URL_FLAG in dwFindFlags
      ;  restricts CertGetCertificateChain to only search the URL cache
      ;  and not hit the wire.
      ;--------------------------------------------------------------------------
      ; Returns FALSE to skip this certificate. Otherwise, returns TRUE to
      ; build a chain for this certificate.
      TYPE_PFN_CERT_CHAIN_FIND_BY_ISSUER_CALLBACK typedef proto WIN_STD_CALL_CONV :PCCERT_CONTEXT, :ptr
      PFN_CERT_CHAIN_FIND_BY_ISSUER_CALLBACK typedef ptr TYPE_PFN_CERT_CHAIN_FIND_BY_ISSUER_CALLBACK

      CERT_CHAIN_FIND_ISSUER_PARA struct
        cbSize DWORD ?
        ; If pszUsageIdentifier == NULL, matches any usage.
        pszUsageIdentifier =POINTER ?
        ; If dwKeySpec == 0, matches any KeySpec
        dwKeySpec DWORD ?
        ; When CERT_CHAIN_FIND_BY_ISSUER_COMPARE_KEY_FLAG is set in dwFindFlags,
        ; CryptAcquireCertificatePrivateKey is called to do the public key
        ; comparison. The following flags can be set to enable caching
        ; of the acquired private key or suppress CSP UI. See the API for more
        ; details on these flags.
        dwAcquirePrivateKeyFlags DWORD ?
        ; Pointer to an array of X509, ASN.1 encoded issuer name blobs. If
        ; cIssuer == 0, matches any issuer
        cIssuer DWORD ?
        rgIssuer POINTER ?
        ; If NULL or Callback returns TRUE, builds the chain for the end
        ; certificate having a private key with the specified KeySpec and
        ; enhanced key usage.
        pfnFindCallback PFN_CERT_CHAIN_FIND_BY_ISSUER_CALLBACK ?
        pvFindArg POINTER ?
        ifdef CERT_CHAIN_FIND_BY_ISSUER_PARA_HAS_EXTRA_FIELDS
          ; Note, if you #define CERT_CHAIN_FIND_BY_ISSUER_PARA_HAS_EXTRA_FIELDS,
          ; then, you must zero all unused fields in this data structure.
          ; More fields could be added in a future release.
          ; If the following pointers are nonNull, returns the index of the
          ; matching issuer certificate, which is at:
          ; pChainContext->
          ;      rgpChain[*pdwIssuerChainIndex]->rgpElement[*pdwIssuerElementIndex].
          ; The issuer name blob is compared against the Issuer field in the
          ; certificate. The *pdwIssuerElementIndex is set to the index of this
          ; subject certificate + 1. Therefore, its possible for a partial chain or
          ; a self signed certificate matching the name blob, where
          ; *pdwIssuerElementIndex points past the last certificate in the chain.
          ; Note, not updated if the above cIssuer == 0.
          pdwIssuerChainIndex POINTER ?
          pdwIssuerElementIndex POINTER ?
        endif
      CERT_CHAIN_FIND_ISSUER_PARA ends
      _CERT_CHAIN_FIND_BY_ISSUER_PARA typedef CERT_CHAIN_FIND_ISSUER_PARA
      PCERT_CHAIN_FIND_ISSUER_PARA typedef ptr CERT_CHAIN_FIND_ISSUER_PARA
      CERT_CHAIN_FIND_BY_ISSUER_PARA typedef CERT_CHAIN_FIND_ISSUER_PARA
      PCERT_CHAIN_FIND_BY_ISSUER_PARA typedef ptr CERT_CHAIN_FIND_ISSUER_PARA
      ; The following dwFindFlags can be set for CERT_CHAIN_FIND_BY_ISSUER
      ; If set, compares the public key in the end certificate with the crypto
      ; provider's public key. This comparison is the last check made on the
      ; build chain.
      CERT_CHAIN_FIND_BY_ISSUER_COMPARE_KEY_FLAG equ 0001h
      ; If not set, only checks the first simple chain for an issuer name match.
      ; When set, also checks second and subsequent simple chains.
      CERT_CHAIN_FIND_BY_ISSUER_COMPLEX_CHAIN_FLAG equ 0002h
      ; If set, CertGetCertificateChain only searches the URL cache and
      ; doesn't hit the wire.
      CERT_CHAIN_FIND_BY_ISSUER_CACHE_ONLY_URL_FLAG equ 0004h
      ; If set, CertGetCertificateChain only opens the Local Machine
      ; certificate stores instead of the Current User's.
      CERT_CHAIN_FIND_BY_ISSUER_LOCAL_MACHINE_FLAG equ 0008h
      ; If set, no check is made to see if the end certificate has a private
      ; key associated with it.
      CERT_CHAIN_FIND_BY_ISSUER_NO_KEY_FLAG equ 4000h
      ; By default, the hCertStore passed to CertFindChainInStore, is passed
      ; as the additional store to CertGetCertificateChain. This flag can be
      ; set to improve performance by only searching the cached system stores
      ; (root, my, ca, trust) to find the issuer certificates. If not set, then,
      ; the hCertStore is always searched in addition to the cached system
      ; stores.
      CERT_CHAIN_FIND_BY_ISSUER_CACHE_ONLY_FLAG equ 8000h
      ;+=========================================================================
      ;  Certificate Chain Policy Data Structures and APIs
      ;==========================================================================
      CERT_CHAIN_POLICY_PARA struct
        cbSize DWORD ?
        dwFlags DWORD ?
        pvExtraPolicyPara POINTER ?
        ; pszPolicyOID specific
      CERT_CHAIN_POLICY_PARA ends
      _CERT_CHAIN_POLICY_PARA typedef CERT_CHAIN_POLICY_PARA
      PCERT_CHAIN_POLICY_PARA typedef ptr CERT_CHAIN_POLICY_PARA
      ; If both lChainIndex and lElementIndex are set to -1, the dwError applies
      ; to the whole chain context. If only lElementIndex is set to -1, the
      ; dwError applies to the lChainIndex'ed chain. Otherwise, the dwError applies
      ; to the certificate element at
      ; pChainContext->rgpChain[lChainIndex]->rgpElement[lElementIndex].
      CERT_CHAIN_POLICY_STATUS struct
        cbSize DWORD ?
        dwError DWORD ?
        lChainIndex SDWORD ?
        lElementIndex SDWORD ?
        pvExtraPolicyStatus POINTER ?
        ; pszPolicyOID specific
      CERT_CHAIN_POLICY_STATUS ends
      _CERT_CHAIN_POLICY_STATUS typedef CERT_CHAIN_POLICY_STATUS
      PCERT_CHAIN_POLICY_STATUS typedef ptr CERT_CHAIN_POLICY_STATUS
      ; Common chain policy flags
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
      ;+-------------------------------------------------------------------------
      ;  Verify that the certificate chain satisfies the specified policy
      ;  requirements. If we were able to verify the chain policy, TRUE is returned
      ;  and the dwError field of the pPolicyStatus is updated. A dwError of 0
      ;  (ERROR_SUCCESS, S_OK) indicates the chain satisfies the specified policy.
      ;  If dwError applies to the entire chain context, both lChainIndex and
      ;  lElementIndex are set to -1. If dwError applies to a simple chain,
      ;  lElementIndex is set to -1 and lChainIndex is set to the index of the
      ;  first offending chain having the error. If dwError applies to a
      ;  certificate element, lChainIndex and lElementIndex are updated to
      ;  index the first offending certificate having the error, where, the
      ;  the certificate element is at:
      ;      pChainContext->rgpChain[lChainIndex]->rgpElement[lElementIndex].
      ;  The dwFlags in pPolicyPara can be set to change the default policy checking
      ;  behaviour. In addition, policy specific parameters can be passed in
      ;  the pvExtraPolicyPara field of pPolicyPara.
      ;  In addition to returning dwError, in pPolicyStatus, policy OID specific
      ;  extra status may be returned via pvExtraPolicyStatus.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertVerifyCertificateChainPolicy, WIN_STD_CALL_CONV,, <:LPCSTR, :PCCERT_CHAIN_CONTEXT, :PCERT_CHAIN_POLICY_PARA, :PCERT_CHAIN_POLICY_STATUS>, 16
      ; Predefined OID Function Names
      CRYPT_OID_VERIFY_CERTIFICATE_CHAIN_POLICY_FUNC equ <"CertDllVerifyCertificateChainPolicy">
      ; CertDllVerifyCertificateChainPolicy has same function signature as
      ; CertVerifyCertificateChainPolicy.
      ;+-------------------------------------------------------------------------
      ;  Predefined verify chain policies
      ;--------------------------------------------------------------------------
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
      ;+-------------------------------------------------------------------------
      ;  CERT_CHAIN_POLICY_BASE
      ;  Implements the base chain policy verification checks. dwFlags can
      ;  be set in pPolicyPara to alter the default policy checking behaviour.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  CERT_CHAIN_POLICY_AUTHENTICODE
      ;  Implements the Authenticode chain policy verification checks.
      ;  pvExtraPolicyPara may optionally be set to point to the following
      ;  AUTHENTICODE_EXTRA_CERT_CHAIN_POLICY_PARA.
      ;  pvExtraPolicyStatus may optionally be set to point to the following
      ;  AUTHENTICODE_EXTRA_CERT_CHAIN_POLICY_STATUS.
      ;--------------------------------------------------------------------------
      ; dwRegPolicySettings are defined in wintrust.h
      AUTHENTICODE_EXTRA_CERT_CHAIN_POLICY_PARA struct
        cbSize DWORD ?
        dwRegPolicySettings DWORD ?
        pSignerInfo PCMSG_SIGNER_INFO ?
        ; optional
      AUTHENTICODE_EXTRA_CERT_CHAIN_POLICY_PARA ends
      _AUTHENTICODE_EXTRA_CERT_CHAIN_POLICY_PARA typedef AUTHENTICODE_EXTRA_CERT_CHAIN_POLICY_PARA
      PAUTHENTICODE_EXTRA_CERT_CHAIN_POLICY_PARA typedef ptr AUTHENTICODE_EXTRA_CERT_CHAIN_POLICY_PARA
      AUTHENTICODE_EXTRA_CERT_CHAIN_POLICY_STATUS struct
        cbSize DWORD ?
        fCommercial DWORD ?
        ; obtained from signer statement
      AUTHENTICODE_EXTRA_CERT_CHAIN_POLICY_STATUS ends
      _AUTHENTICODE_EXTRA_CERT_CHAIN_POLICY_STATUS typedef AUTHENTICODE_EXTRA_CERT_CHAIN_POLICY_STATUS
      PAUTHENTICODE_EXTRA_CERT_CHAIN_POLICY_STATUS typedef ptr AUTHENTICODE_EXTRA_CERT_CHAIN_POLICY_STATUS
      ;+-------------------------------------------------------------------------
      ;  CERT_CHAIN_POLICY_AUTHENTICODE_TS
      ;  Implements the Authenticode Time Stamp chain policy verification checks.
      ;  pvExtraPolicyPara may optionally be set to point to the following
      ;  AUTHENTICODE_TS_EXTRA_CERT_CHAIN_POLICY_PARA.
      ;  pvExtraPolicyStatus isn't used and must be set to NULL.
      ;--------------------------------------------------------------------------
      ; dwRegPolicySettings are defined in wintrust.h
      AUTHENTICODE_TS_EXTRA_CERT_CHAIN_POLICY_PARA struct
        cbSize DWORD ?
        dwRegPolicySettings DWORD ?
        fCommercial DWORD ?
      AUTHENTICODE_TS_EXTRA_CERT_CHAIN_POLICY_PARA ends
      _AUTHENTICODE_TS_EXTRA_CERT_CHAIN_POLICY_PARA typedef AUTHENTICODE_TS_EXTRA_CERT_CHAIN_POLICY_PARA
      PAUTHENTICODE_TS_EXTRA_CERT_CHAIN_POLICY_PARA typedef ptr AUTHENTICODE_TS_EXTRA_CERT_CHAIN_POLICY_PARA
      ;+-------------------------------------------------------------------------
      ;  CERT_CHAIN_POLICY_SSL
      ;  Implements the SSL client/server chain policy verification checks.
      ;  pvExtraPolicyPara may optionally be set to point to the following
      ;  SSL_EXTRA_CERT_CHAIN_POLICY_PARA data structure
      ;--------------------------------------------------------------------------
      ; fdwChecks flags are defined in wininet.h
      HTTPSPolicyCallbackData struct
        union
          cbStruct DWORD ?
          ; sizeof(HTTPSPolicyCallbackData);
          cbSize DWORD ?
          ; sizeof(HTTPSPolicyCallbackData);
        ends
        dwAuthType DWORD ?
        AUTHTYPE_CLIENT equ 1
        AUTHTYPE_SERVER equ 2
        fdwChecks DWORD ?
        pwszServerName POINTER ?
        ; used to check against CN=xxxx
      HTTPSPolicyCallbackData ends
      _HTTPSPolicyCallbackData typedef HTTPSPolicyCallbackData
      PHTTPSPolicyCallbackData typedef ptr HTTPSPolicyCallbackData
      SSL_EXTRA_CERT_CHAIN_POLICY_PARA typedef HTTPSPolicyCallbackData
      PSSL_EXTRA_CERT_CHAIN_POLICY_PARA typedef ptr HTTPSPolicyCallbackData
      ;+-------------------------------------------------------------------------
      ;  CERT_CHAIN_POLICY_BASIC_CONSTRAINTS
      ;  Implements the basic constraints chain policy.
      ;  Iterates through all the certificates in the chain checking for either
      ;  a szOID_BASIC_CONSTRAINTS or a szOID_BASIC_CONSTRAINTS2 extension. If
      ;  neither extension is present, the certificate is assumed to have
      ;  valid policy. Otherwise, for the first certificate element, checks if
      ;  it matches the expected CA_FLAG or END_ENTITY_FLAG specified in
      ;  pPolicyPara->dwFlags. If neither or both flags are set, then, the first
      ;  element can be either a CA or END_ENTITY. All other elements must be
      ;  a CA. If the PathLenConstraint is present in the extension, its
      ;  checked.
      ;  The first elements in the remaining simple chains (ie, the certificate
      ;  used to sign the CTL) are checked to be an END_ENTITY.
      ;  If this verification fails, dwError will be set to
      ;  TRUST_E_BASIC_CONSTRAINTS.
      ;--------------------------------------------------------------------------
      BASIC_CONSTRAINTS_CERT_CHAIN_POLICY_CA_FLAG equ 80000000h
      BASIC_CONSTRAINTS_CERT_CHAIN_POLICY_END_ENTITY_FLAG equ 40000000h
      ;+-------------------------------------------------------------------------
      ;  CERT_CHAIN_POLICY_NT_AUTH
      ;  Implements the NT Authentication chain policy.
      ;  The NT Authentication chain policy consists of 3 distinct chain
      ;  verifications in the following order:
      ;      [1] CERT_CHAIN_POLICY_BASE - Implements the base chain policy
      ;          verification checks. The LOWORD of dwFlags can be set in
      ;          pPolicyPara to alter the default policy checking behaviour. See
      ;          CERT_CHAIN_POLICY_BASE for more details.
      ;      [2] CERT_CHAIN_POLICY_BASIC_CONSTRAINTS - Implements the basic
      ;          constraints chain policy. The HIWORD of dwFlags can be set
      ;          to specify if the first element must be either a CA or END_ENTITY.
      ;          See CERT_CHAIN_POLICY_BASIC_CONSTRAINTS for more details.
      ;      [3] Checks if the second element in the chain, the CA that issued
      ;          the end certificate, is a trusted CA for NT
      ;          Authentication. A CA is considered to be trusted if it exists in
      ;          the "NTAuth" system registry store found in the
      ;          CERT_SYSTEM_STORE_LOCAL_MACHINE_ENTERPRISE store location.
      ;          If this verification fails, whereby the CA isn't trusted,
      ;          dwError is set to CERT_E_UNTRUSTEDCA.
      ;          If CERT_PROT_ROOT_DISABLE_NT_AUTH_REQUIRED_FLAG is set
      ;          in the "Flags" value of the HKLM policy "ProtectedRoots" subkey
      ;          defined by CERT_PROT_ROOT_FLAGS_REGPATH, then,
      ;          if the above check fails, checks if the chain
      ;          has CERT_TRUST_HAS_VALID_NAME_CONSTRAINTS set in dwInfoStatus. This
      ;          will only be set if there was a valid name constraint for all
      ;          name spaces including UPN. If the chain doesn't have this info
      ;          status set, dwError is set to CERT_E_UNTRUSTEDCA.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  CERT_CHAIN_POLICY_MICROSOFT_ROOT
      ;  Checks if the last element of the first simple chain contains a
      ;  Microsoft root public key. If it doesn't contain a Microsoft root
      ;  public key, dwError is set to CERT_E_UNTRUSTEDROOT.
      ;  pPolicyPara is optional. However,
      ;  MICROSOFT_ROOT_CERT_CHAIN_POLICY_ENABLE_TEST_ROOT_FLAG can be set in
      ;  the dwFlags in pPolicyPara to also check for the Microsoft Test Roots.
      ;  MICROSOFT_ROOT_CERT_CHAIN_POLICY_CHECK_APPLICATION_ROOT_FLAG can be set
      ;  in the dwFlags in pPolicyPara to check for the Microsoft root for
      ;  application signing instead of the Microsoft product root. This flag
      ;  explicitly checks for the application root only and cannot be combined
      ;  with the test root flag.  
      ;  MICROSOFT_ROOT_CERT_CHAIN_POLICY_DISABLE_FLIGHT_ROOT_FLAG can be set
      ;  in the dwFlags in pPolicyPara to always disable the Flight root.
      ;  pvExtraPolicyPara and pvExtraPolicyStatus aren't used and must be set
      ;  to NULL.
      ;--------------------------------------------------------------------------
      MICROSOFT_ROOT_CERT_CHAIN_POLICY_ENABLE_TEST_ROOT_FLAG equ 00010000h
      MICROSOFT_ROOT_CERT_CHAIN_POLICY_CHECK_APPLICATION_ROOT_FLAG equ 00020000h
      MICROSOFT_ROOT_CERT_CHAIN_POLICY_DISABLE_FLIGHT_ROOT_FLAG equ 00040000h
      ;+-------------------------------------------------------------------------
      ;  CERT_CHAIN_POLICY_EV
      ;  Verify the issuance policy in the end certificate of the first simple
      ;  chain matches with the root certificate EV policy.
      ;  pvExtraPolicyPara may optionally be set to point to the following
      ;  EV_EXTRA_CERT_CHAIN_POLICY_PARA. The dwRootProgramQualifierFlags member
      ;  can be set to one or more of the CERT_ROOT_PROGRAM_FLAG_* to define
      ;  which of the EV policy qualifier bits are required for validation.
      ;  pvExtraPolicyStatus may optionally be set to point to the following
      ;  EV_EXTRA_CERT_CHAIN_POLICY_STATUS. The fQualifiers member will contain
      ;  a combination of CERT_ROOT_PROGRAM_FLAG_* flags.
      ;--------------------------------------------------------------------------
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
      ;+-------------------------------------------------------------------------
      ;  CERT_CHAIN_POLICY_SSL_F12
      ;  Checks if any certificates in the chain have weak crypto to
      ;  change the default https lock and provide an F12 error string.
      ;  For a Third Party root, checks if it is in compliance with the Microsoft
      ;  Root Program requirements. (Will be implemented in RS2.)
      ;  pvExtraPolicyStatus must point to the following
      ;  SSL_F12_EXTRA_CERT_CHAIN_POLICY_STATUS. It will be updated with the
      ;  results of the weak crypto and root program compliance checks.
      ;  Before calling, the cbSize must be set to a
      ;  value >= sizeof(SSL_F12_EXTRA_CERT_CHAIN_POLICY_STATUS).
      ;  dwError in CERT_CHAIN_POLICY_STATUS will be set to TRUST_E_CERT_SIGNATURE
      ;  for potential weak crypto and set to CERT_E_UNTRUSTEDROOT for Third Party
      ;  Roots not in compliance with the Microsoft Root Program.
      ;--------------------------------------------------------------------------
      SSL_F12_ERROR_TEXT_LENGTH equ 256
      SSL_F12_EXTRA_CERT_CHAIN_POLICY_STATUS struct
        cbSize DWORD ?
        dwErrorLevel DWORD ?
        dwErrorCategory DWORD ?
        dwReserved DWORD ?
        wszErrorText WORD SSL_F12_ERROR_TEXT_LENGTH dup (?)
        ; Localized
      SSL_F12_EXTRA_CERT_CHAIN_POLICY_STATUS ends
      _SSL_F12_EXTRA_CERT_CHAIN_POLICY_STATUS typedef SSL_F12_EXTRA_CERT_CHAIN_POLICY_STATUS
      PSSL_F12_EXTRA_CERT_CHAIN_POLICY_STATUS typedef ptr SSL_F12_EXTRA_CERT_CHAIN_POLICY_STATUS
      ;+-------------------------------------------------------------------------
      ;  SSL_F12 Error Levels
      ;--------------------------------------------------------------------------
      CERT_CHAIN_POLICY_SSL_F12_SUCCESS_LEVEL equ 0
      CERT_CHAIN_POLICY_SSL_F12_WARNING_LEVEL equ 1
      CERT_CHAIN_POLICY_SSL_F12_ERROR_LEVEL equ 2
      ;+-------------------------------------------------------------------------
      ;  SSL_F12 Error Categories
      ;--------------------------------------------------------------------------
      CERT_CHAIN_POLICY_SSL_F12_NONE_CATEGORY equ 0
      CERT_CHAIN_POLICY_SSL_F12_WEAK_CRYPTO_CATEGORY equ 1
      CERT_CHAIN_POLICY_SSL_F12_ROOT_PROGRAM_CATEGORY equ 2
      ; Error Level for CERT_CHAIN_POLICY_SSL_F12_WEAK_CRYPTO_CATEGORY:
      ;  - CERT_CHAIN_POLICY_SSL_F12_ERROR_LEVEL
      ;     -- Third Party Root
      ;  - CERT_CHAIN_POLICY_SSL_F12_WARNING_LEVEL
      ;     -- All other roots including enterprise
      ; Error Level for CERT_CHAIN_POLICY_SSL_F12_ROOT_PROGRAM_CATEGORY:
      ;  - CERT_CHAIN_POLICY_SSL_F12_WARNING_LEVEL
      ;     -- All Root Program compliance failures will map to warning level
      ;+-------------------------------------------------------------------------
      ;  CERT_CHAIN_POLICY_SSL_HPKP_HEADER
      ;  Processes the Http Public Key Pinning (HPKP) responses headers.
      ;  There are two possible response headers:
      ;   - "Public-Key-Pins" (PKP_HEADER)
      ;   - "Public-Key-Pins-Report-Only" (PKP_RO_HEADER)
      ;  One or both of the above header values must be present.
      ;  pvExtraPolicyPara must be set to point to the following
      ;  SSL_HPKP_HEADER_EXTRA_CERT_CHAIN_POLICY_PARA
      ;  One of the following dwError's will be set if the HPKP header isn't
      ;  used:
      ;   ERROR_SERVICE_DISABLED
      ;      HPKP has been explicitly disabled
      ;   ERROR_NOT_FOUND
      ;      No previous call using CERT_CHAIN_POLICY_SSL policy for chain and
      ;      server name.
      ;   ERROR_ALREADY_EXISTS
      ;      Second add to same server within 10 minutes
      ;   ERROR_NOT_SUPPORTED
      ;      Only the "Public-Key-Pins-Report-Only" header was set. It will
      ;      only be trace logged.
      ;   CRYPT_E_NO_MATCH
      ;      No public key match in the chain context being used.
      ;   CERT_E_UNTRUSTEDROOT
      ;      Didn't chain up to a Third Party Root.
      ;   ERROR_INVALID_TIME
      ;      max-age value was less than the supported minimum. Default is 7 days.
      ;   ERROR_INVALID_DATA
      ;      HPKP header parsing errors.
      ;--------------------------------------------------------------------------
      ; "Public-Key-Pins" and "Public-Key-Pins-Report-Only" header indices
      SSL_HPKP_PKP_HEADER_INDEX equ 0
      SSL_HPKP_PKP_RO_HEADER_INDEX equ 1
      SSL_HPKP_HEADER_COUNT equ 2
      SSL_HPKP_HEADER_EXTRA_CERT_CHAIN_POLICY_PARA struct
        cbSize DWORD ?
        dwReserved DWORD ?
        pwszServerName POINTER ?
        ; One or both of the following must be nonNULL.
        rgpszHpkpValue POINTER SSL_HPKP_HEADER_COUNT dup (?)
      SSL_HPKP_HEADER_EXTRA_CERT_CHAIN_POLICY_PARA ends
      _SSL_HPKP_HEADER_EXTRA_CERT_CHAIN_POLICY_PARA typedef SSL_HPKP_HEADER_EXTRA_CERT_CHAIN_POLICY_PARA
      PSSL_HPKP_HEADER_EXTRA_CERT_CHAIN_POLICY_PARA typedef ptr SSL_HPKP_HEADER_EXTRA_CERT_CHAIN_POLICY_PARA
      ;+-------------------------------------------------------------------------
      ;  CERT_CHAIN_POLICY_THIRD_PARTY_ROOT
      ;  Checks if the last element of the first simple chain is
      ;  a Third Party root. If it isn't dwError is set to CERT_E_UNTRUSTEDROOT.
      ;  pvExtraPolicyPara and pvExtraPolicyStatus aren't used and must be set
      ;  to NULL.
      ;--------------------------------------------------------------------------
      ;+-------------------------------------------------------------------------
      ;  CERT_CHAIN_POLICY_SSL_KEY_PIN
      ;  Uses the machine's non-expired HPKP rules to check for
      ;  SSL server certificate Key Pin matches.
      ;  Also uses the Microsoft Windows Update Pin Rules to check if a potential
      ;  MiTM root was used.
      ;  pvExtraPolicyPara must point to the 
      ;  SSL_KEY_PIN_EXTRA_CERT_CHAIN_POLICY_PARA data structure.
      ;  pvExtraPolicyStatus must point to the
      ;  SSL_KEY_PIN_EXTRA_CERT_CHAIN_POLICY_STATUS data structure.
      ;  lError will be updated as follows:
      ;   = 0 - SUCCESS. No MiTM or mismatch errors
      ;   < 0 - ERROR.   User should be prompted with a click through option
      ;   > 0 - WARNING. Only F12 warning
      ;  Two types of errors:
      ;   - MITM -     Server certificates didn't chain up to a third party root
      ;                 ERROR -   Current User or Local Machine root
      ;                 WARNING - Group Policy or Enterprise root
      ;   - MISMATCH - Server certificates chained up to a third party root
      ;                 ERROR -   Only domain mismatches
      ;                 WARNING - Both a domain mismatch and a domain match
      ;  For any errors wszErrorText will be updated with localized error string
      ;  to be included in F12.
      ;  Before calling, the cbSize must be set to a
      ;  value >= sizeof(SSL_KEY_PIN_EXTRA_CERT_CHAIN_POLICY_STATUS).
      ;  dwError in CERT_CHAIN_POLICY_STATUS will be set to CERT_E_CN_NO_MATCH
      ;  for either MITM or MISMATCH error.
      ;--------------------------------------------------------------------------
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
        lError SDWORD ?
        wszErrorText WORD SSL_KEY_PIN_ERROR_TEXT_LENGTH dup (?)
        ; Localized
      SSL_KEY_PIN_EXTRA_CERT_CHAIN_POLICY_STATUS ends
      _SSL_KEY_PIN_EXTRA_CERT_CHAIN_POLICY_STATUS typedef SSL_KEY_PIN_EXTRA_CERT_CHAIN_POLICY_STATUS
      PSSL_KEY_PIN_EXTRA_CERT_CHAIN_POLICY_STATUS typedef ptr SSL_KEY_PIN_EXTRA_CERT_CHAIN_POLICY_STATUS
      ;+-------------------------------------------------------------------------
      ;  SSL_KEY_PIN Errors
      ;--------------------------------------------------------------------------
      CERT_CHAIN_POLICY_SSL_KEY_PIN_MISMATCH_ERROR equ -2
      CERT_CHAIN_POLICY_SSL_KEY_PIN_MITM_ERROR equ -1
      CERT_CHAIN_POLICY_SSL_KEY_PIN_SUCCESS equ 0
      CERT_CHAIN_POLICY_SSL_KEY_PIN_MITM_WARNING equ 1
      CERT_CHAIN_POLICY_SSL_KEY_PIN_MISMATCH_WARNING equ 2
      ;+-------------------------------------------------------------------------
      ; convert formatted string to binary
      ; If cchString is 0, then pszString is NULL terminated and
      ; cchString is obtained via strlen() + 1.
      ; dwFlags defines string format
      ; if pbBinary is NULL, *pcbBinary returns the size of required memory
      ; *pdwSkip returns the character count of skipped strings, optional
      ; *pdwFlags returns the actual format used in the conversion, optional
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CryptStringToBinaryA, WIN_STD_CALL_CONV,, <:LPCSTR, :DWORD, :DWORD, :ptr BYTE, :ptr DWORD, :ptr DWORD, :ptr DWORD>, 28
      ;+-------------------------------------------------------------------------
      ; convert formatted string to binary
      ; If cchString is 0, then pszString is NULL terminated and
      ; cchString is obtained via strlen() + 1.
      ; dwFlags defines string format
      ; if pbBinary is NULL, *pcbBinary returns the size of required memory
      ; *pdwSkip returns the character count of skipped strings, optional
      ; *pdwFlags returns the actual format used in the conversion, optional
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CryptStringToBinaryW, WIN_STD_CALL_CONV,, <:LPCWSTR, :DWORD, :DWORD, :ptr BYTE, :ptr DWORD, :ptr DWORD, :ptr DWORD>, 28
      ifdef UNICODE
        CryptStringToBinary equ <CryptStringToBinaryW>
      else
        CryptStringToBinary equ <CryptStringToBinaryA>
      endif
      ; !UNICODE
      ;+-------------------------------------------------------------------------
      ; convert binary to formatted string
      ; dwFlags defines string format
      ; if pszString is NULL, *pcchString returns size in characters
      ; including null-terminator
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CryptBinaryToStringA, WIN_STD_CALL_CONV,, <:ptr BYTE, :DWORD, :DWORD, :LPSTR, :ptr DWORD>, 20
      ;+-------------------------------------------------------------------------
      ; convert binary to formatted string
      ; dwFlags defines string format
      ; if pszString is NULL, *pcchString returns size in characters
      ; including null-terminator
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CryptBinaryToStringW, WIN_STD_CALL_CONV,, <:ptr BYTE, :DWORD, :DWORD, :LPWSTR, :ptr DWORD>, 20
      ifdef UNICODE
        CryptBinaryToString equ <CryptBinaryToStringW>
      else
        CryptBinaryToString equ <CryptBinaryToStringA>
      endif
      ; !UNICODE
      ; dwFlags has the following defines
      ; certenrolld_begin -- CRYPT_STRING_*
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
      CRYPT_STRING_PERCENTESCAPE equ 08000000h; base64 formats only

      CRYPT_STRING_HASHDATA equ 10000000h
      CRYPT_STRING_STRICT equ 20000000h
      CRYPT_STRING_NOCRLF equ 40000000h
      CRYPT_STRING_NOCR equ 80000000h
      ; certenrolld_end
      ; CryptBinaryToString uses the following flags
      ; CRYPT_STRING_BASE64HEADER - base64 format with certificate begin
      ;                             and end headers
      ; CRYPT_STRING_BASE64 - only base64 without headers
      ; CRYPT_STRING_BINARY - pure binary copy
      ; CRYPT_STRING_BASE64REQUESTHEADER - base64 format with request begin
      ;                                    and end headers
      ; CRYPT_STRING_BASE64X509CRLHEADER - base64 format with x509 crl begin
      ;                                    and end headers
      ; CRYPT_STRING_HEX - only hex format
      ; CRYPT_STRING_HEXASCII - hex format with ascii char display
      ; CRYPT_STRING_HEXADDR - hex format with address display
      ; CRYPT_STRING_HEXASCIIADDR - hex format with ascii char and address display
      ; CryptBinaryToString accepts CRYPT_STRING_NOCR or'd into one of the above.
      ; When set, line breaks contain only LF, instead of CR-LF pairs.
      ; CryptStringToBinary uses the following flags
      ; CRYPT_STRING_BASE64_ANY tries the following, in order:
      ;    CRYPT_STRING_BASE64HEADER
      ;    CRYPT_STRING_BASE64
      ; CRYPT_STRING_ANY tries the following, in order:
      ;    CRYPT_STRING_BASE64_ANY
      ;    CRYPT_STRING_BINARY -- should always succeed
      ; CRYPT_STRING_HEX_ANY tries the following, in order:
      ;    CRYPT_STRING_HEXADDR
      ;    CRYPT_STRING_HEXASCIIADDR
      ;    CRYPT_STRING_HEXASCII
      ;    CRYPT_STRING_HEX
      ;+=========================================================================
      ;  PFX (PKCS #12) function definitions and types
      ;==========================================================================
      ;+-------------------------------------------------------------------------
      ;  PKCS#12 OIDs
      ;--------------------------------------------------------------------------
      szOID_PKCS_12_PbeIds equ <"1.2.840.113549.1.12.1">
      szOID_PKCS_12_pbeWithSHA1And128BitRC4 equ <"1.2.840.113549.1.12.1.1">
      szOID_PKCS_12_pbeWithSHA1And40BitRC4 equ <"1.2.840.113549.1.12.1.2">
      szOID_PKCS_12_pbeWithSHA1And3KeyTripleDES equ <"1.2.840.113549.1.12.1.3">
      szOID_PKCS_12_pbeWithSHA1And2KeyTripleDES equ <"1.2.840.113549.1.12.1.4">
      szOID_PKCS_12_pbeWithSHA1And128BitRC2 equ <"1.2.840.113549.1.12.1.5">
      szOID_PKCS_12_pbeWithSHA1And40BitRC2 equ <"1.2.840.113549.1.12.1.6">
      szOID_PKCS_5_PBKDF2 equ <"1.2.840.113549.1.5.12">
      szOID_PKCS_5_PBES2 equ <"1.2.840.113549.1.5.13">
      ;+-------------------------------------------------------------------------
      ;  PBE parameters as defined in PKCS#12 as pkcs-12PbeParams.
      ;  NOTE that the salt bytes will immediately follow this structure.
      ;  we avoid using pointers in this structure for easy of passing
      ;  it into NCryptExportKey() as a NCryptBuffer (may be sent via RPC
      ;  to the key isolation process).
      ;--------------------------------------------------------------------------
      CRYPT_PKCS12_PBE_PARAMS struct
        iIterations SDWORD ?
        ;* iteration count              *
        cbSalt DWORD ?
        ;* byte size of the salt        *
      CRYPT_PKCS12_PBE_PARAMS ends
      _CRYPT_PKCS12_PBE_PARAMS typedef CRYPT_PKCS12_PBE_PARAMS
      ;+-------------------------------------------------------------------------
      ;      PFXImportCertStore
      ;  Import the PFX blob and return a store containing certificates
      ;  If the password parameter is incorrect or any other problems decoding
      ;  the PFX blob are encountered, the function will return NULL and the
      ;      error code can be found from GetLastError().
      ;  The dwFlags parameter may be set to the following:
      ;  PKCS12_IMPORT_SILENT    - only allow importing key in silent mode. If the
      ;                            csp or ksp requires ui then this call will fail
      ;                            with the error from the csp or ksp.
      ;  CRYPT_EXPORTABLE - specify that any imported keys should be marked as
      ;                     exportable (see documentation on CryptImportKey)
      ;  CRYPT_USER_PROTECTED - (see documentation on CryptImportKey)
      ;  CRYPT_MACHINE_KEYSET - used to force the private key to be stored in the
      ;                        the local machine and not the current user.
      ;  CRYPT_USER_KEYSET - used to force the private key to be stored in the
      ;                      the current user and not the local machine, even if
      ;                      the pfx blob specifies that it should go into local
      ;                      machine.
      ;  PKCS12_INCLUDE_EXTENDED_PROPERTIES - used to import all extended
      ;                     properties that were saved with CertExportCertStore()
      ;                     using the same flag.
      ;  PKCS12_ONLY_CERTIFICATES - the returned store only contains certificates.
      ;                             Private keys aren't decrypted or imported.
      ;                             If the certificates weren't encrypted, then,
      ;                             we won't use a password to decrypt. Otherwise,
      ;                             will do normal password decryption.
      ;                             For certificates having an associated private
      ;                             key, we add the CERT_KEY_PROV_INFO_PROP_ID.
      ;                             The KeyProvInfo will have the following special
      ;                             values:
      ;                               dwProvType = 0
      ;                               pwszProvName = L"PfxProvider"
      ;                               pwszProvName = L"PfxContainer"
      ;                             For not encrypted certificates, we won't use
      ;                             any password to do the MAC check. If a MAC
      ;                             check is necessary, then, PKCS12_NO_PERSIST_KEY
      ;                             option should be selected instead.
      ;  PKCS12_ONLY_NOT_ENCRYPTED_CERTIFICATES - same as for PKCS12_ONLY_CERTIFICATES
      ;                                           except, we won't fallback to
      ;                                           using the password to decrypt.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, PFXImportCertStore, WIN_STD_CALL_CONV,, <:ptr CRYPT_DATA_BLOB, :LPCWSTR, :DWORD>, 12
      ; dwFlags definitions for PFXImportCertStore
      ;#define CRYPT_EXPORTABLE          0x00000001  // CryptImportKey dwFlags
      ;#define CRYPT_USER_PROTECTED      0x00000002  // CryptImportKey dwFlags
      ;#define CRYPT_MACHINE_KEYSET      0x00000020  // CryptAcquireContext dwFlags
      ;#define CRYPT_USER_PROTECTED_STRONG 0x00100000
      ;#define PKCS12_INCLUDE_EXTENDED_PROPERTIES 0x10
      PKCS12_IMPORT_SILENT equ 00000040h
      CRYPT_USER_KEYSET equ 00001000h
      PKCS12_PREFER_CNG_KSP equ 00000100h; prefer using CNG KSP

      PKCS12_ALWAYS_CNG_KSP equ 00000200h; always use CNG KSP

      PKCS12_ONLY_CERTIFICATES equ 00000400h
      PKCS12_ONLY_NOT_ENCRYPTED_CERTIFICATES equ 00000800h
      PKCS12_ALLOW_OVERWRITE_KEY equ 00004000h; allow overwrite existing key

      PKCS12_NO_PERSIST_KEY equ 00008000h; key will not be persisted

      PKCS12_VIRTUAL_ISOLATION_KEY equ 00010000h; key will be saved into VSM

      PKCS12_IMPORT_RESERVED_MASK equ 0ffff0000h
      PKCS12_OBJECT_LOCATOR_ALL_IMPORT_FLAGS equ <(PKCS12_ALWAYS_CNG_KSP or PKCS12_NO_PERSIST_KEY or PKCS12_IMPORT_SILENT or PKCS12_INCLUDE_EXTENDED_PROPERTIES)>
      PKCS12_ONLY_CERTIFICATES_PROVIDER_TYPE equ 0
      PKCS12_ONLY_CERTIFICATES_PROVIDER_NAME equ <L("PfxProvider")>
      PKCS12_ONLY_CERTIFICATES_CONTAINER_NAME equ <L("PfxContainer")>
      ;+-------------------------------------------------------------------------
      ;      PFXIsPFXBlob
      ;  This function will try to decode the outer layer of the blob as a pfx
      ;  blob, and if that works it will return TRUE, it will return FALSE otherwise
      ;--------------------------------------------------------------------------
      @DefProto DllImport, PFXIsPFXBlob, WIN_STD_CALL_CONV,, <:ptr CRYPT_DATA_BLOB>, 4
      ;+-------------------------------------------------------------------------
      ;      PFXVerifyPassword
      ;  This function will attempt to decode the outer layer of the blob as a pfx
      ;  blob and decrypt with the given password. No data from the blob will be
      ;  imported.
      ;  Return value is TRUE if password appears correct, FALSE otherwise.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, PFXVerifyPassword, WIN_STD_CALL_CONV,, <:ptr CRYPT_DATA_BLOB, :LPCWSTR, :DWORD>, 12
      ;+-------------------------------------------------------------------------
      ;      PFXExportCertStoreEx
      ;  Export the certificates and private keys referenced in the passed-in store
      ;  This API encodes the blob under a stronger algorithm. The resulting
      ;  PKCS12 blobs are incompatible with the earlier PFXExportCertStore API.
      ;  The value passed in the password parameter will be used to encrypt and
      ;  verify the integrity of the PFX packet. If any problems encoding the store
      ;  are encountered, the function will return FALSE and the error code can
      ;  be found from GetLastError().
      ;  The PKCS12_PROTECT_TO_DOMAIN_SIDS flag together with an 
      ;  NCRYPT_DESCRIPTOR_HANDLE* for pvPara means the password will be stored
      ;  in the pfx protected to the NCRYPT_DESCRIPTOR_HANDLE. On import, any
      ;  principal that is listed in NCRYPT_DESCRIPTOR_HANDLE can decrypt the 
      ;  password within the pfx and use it to descrypt the entire pfx.
      ;  
      ;  If the password parameter is NULL or L"" and the 
      ;  PKCS12_PROTECT_TO_DOMAIN_SIDS flag is set together with an
      ;  NCRYPT_DESCRIPTOR_HANDLE* for pvPara then a random password of length
      ;  40 characters is chosen to protect the pfx. This password will be 
      ;  protected inside the pfx.
      ;  If the certificates don't need to be private, such as, the PFX is
      ;  hosted on a file share accessed by IIS, then,
      ;  the PKCS12_DISABLE_ENCRYPT_CERTIFICATES flag should be set.
      ;  Note, OpenSSL and down level platforms support certificates that weren't
      ;  encrypted.
      ;  In Threshold the default was changed not to encrypt the certificates.
      ;  The following registry value can be set to change the default to enable
      ;  the encryption.
      ;      HKLM\Software\Microsoft\Windows\CurrentVersion\PFX
      ;          REG_DWORD EncryptCertificates
      ;  The PKCS12_ENCRYPT_CERTIFICATES flag should be set to always
      ;  encrypt the certificates.
      ;  The dwFlags parameter may be set to any combination of
      ;      EXPORT_PRIVATE_KEYS
      ;      REPORT_NO_PRIVATE_KEY
      ;      REPORT_NOT_ABLE_TO_EXPORT_PRIVATE_KEY
      ;      PKCS12_EXPORT_SILENT
      ;      PKCS12_INCLUDE_EXTENDED_PROPERTIES
      ;      PKCS12_PROTECT_TO_DOMAIN_SIDS
      ;      PKCS12_DISABLE_ENCRYPT_CERTIFICATES or PKCS12_ENCRYPT_CERTIFICATES
      ;      PKCS12_EXPORT_ECC_CURVE_PARAMETERS
      ;      PKCS12_EXPORT_ECC_CURVE_OID
      ;  The encoded PFX blob is returned in *pPFX. If pPFX->pbData is NULL upon
      ;  input, this is a length only calculation, whereby, pPFX->cbData is updated
      ;  with the number of bytes required for the encoded blob. Otherwise,
      ;  the memory pointed to by pPFX->pbData is updated with the encoded bytes
      ;  and pPFX->cbData is updated with the encoded byte length.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, PFXExportCertStoreEx, WIN_STD_CALL_CONV,, <:HCERTSTORE, :ptr CRYPT_DATA_BLOB, :LPCWSTR, :ptr, :DWORD>, 20
      ; dwFlags definitions for PFXExportCertStoreEx
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
      ; PKCS12 Pbes2 Parameter Structure
      ;     It is passed into PFXExportCertStoreEx as pvPara 
      ;     when PKCS12_EXPORT_PBES2_PARAMS is set for dwFlags.
      PKCS12_PBES2_EXPORT_PARAMS struct
        dwSize DWORD ?
        ; structure size of _PKCS12_PBES2_EXPORT_PARAMS    
        hNcryptDescriptor POINTER ?
        pwszPbes2Alg POINTER ?
      PKCS12_PBES2_EXPORT_PARAMS ends
      _PKCS12_PBES2_EXPORT_PARAMS typedef PKCS12_PBES2_EXPORT_PARAMS
      PPKCS12_PBES2_EXPORT_PARAMS typedef ptr PKCS12_PBES2_EXPORT_PARAMS
      ; PKCS12 Pbes2 Algorithm string definition
      ;     This string is passed into pwszPbes2Alg of the structure
      ;     PKCS12_PBES2_EXPORT_PARAMS, which indicates which
      ;     algorithms will be used for key and certificate encryption,
      ;     and MacData hashing.
      ; AES256 will be used for key/certificate encryption, and
      ; SHA256 will be used for KDF2, and MacData hashing.
      PKCS12_PBES2_ALG_AES256_SHA256 equ <L("AES256-SHA256")>
      ; Registry path to the PFX configuration local machine subkey
      PKCS12_CONFIG_REGPATH equ <L("Software\Microsoft\Windows\CurrentVersion\PFX")>
      ; The default is not to encrypt the certificates included in the PFX.
      ; The following is a REG_DWORD. It should be set to a nonzero value
      ; to change the default to enable encrypting the certificates.
      PKCS12_ENCRYPT_CERTIFICATES_VALUE_NAME equ <L("EncryptCertificates")>
      ;+-------------------------------------------------------------------------
      ;      PFXExportCertStore
      ;  Export the certificates and private keys referenced in the passed-in store
      ;  This is an old API kept for compatibility with IE4 clients. New applications
      ;  should call the above PfxExportCertStoreEx for enhanced security.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, PFXExportCertStore, WIN_STD_CALL_CONV,, <:HCERTSTORE, :ptr CRYPT_DATA_BLOB, :LPCWSTR, :DWORD>, 16
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)*
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_PHONE_RESTRICTED or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      ;+=========================================================================
      ;  APIs to get a non-blocking, time valid OCSP response for
      ;  a server certificate chain.
      ;  Normally, this OCSP response will be included along with the server
      ;  certificate in a message returned to the client. As a result only the
      ;  server should need to contact the OCSP responser for its certificate.
      ;==========================================================================
      if (NTDDI_VERSION ge NTDDI_VISTA)
        ;+-------------------------------------------------------------------------
        ;  Server OCSP response handle.
        ;--------------------------------------------------------------------------
        HCERT_SERVER_OCSP_RESPONSE typedef ptr VOID
        ;+-------------------------------------------------------------------------
        ;  Server OCSP response context.
        ;--------------------------------------------------------------------------
        CERT_SERVER_OCSP_RESPONSE_CONTEXT typedef _CERT_SERVER_OCSP_RESPONSE_CONTEXT
        PCERT_SERVER_OCSP_RESPONSE_CONTEXT typedef ptr _CERT_SERVER_OCSP_RESPONSE_CONTEXT
        PCCERT_SERVER_OCSP_RESPONSE_CONTEXT typedef ptr CERT_SERVER_OCSP_RESPONSE_CONTEXT
        _CERT_SERVER_OCSP_RESPONSE_CONTEXT struct
          cbSize DWORD ?
          pbEncodedOcspResponse POINTER ?
          cbEncodedOcspResponse DWORD ?
        _CERT_SERVER_OCSP_RESPONSE_CONTEXT ends
        ;+-------------------------------------------------------------------------
        ;  Server OCSP response update callback
        ;  If CERT_SERVER_OCSP_RESPONSE_OPEN_PARA_WRITE_FLAG has been enabled
        ;  then dwWriteOcspFileError will be set. Otherwise, always set to 0.
        ;--------------------------------------------------------------------------
        TYPE_PFN_CERT_SERVER_OCSP_RESPONSE_UPDATE_CALLBACK typedef proto WIN_STD_CALL_CONV :PCCERT_CHAIN_CONTEXT, :PCCERT_SERVER_OCSP_RESPONSE_CONTEXT, :PCCRL_CONTEXT, :PCCRL_CONTEXT, :PVOID, :DWORD
        PFN_CERT_SERVER_OCSP_RESPONSE_UPDATE_CALLBACK typedef ptr TYPE_PFN_CERT_SERVER_OCSP_RESPONSE_UPDATE_CALLBACK

        ;+-------------------------------------------------------------------------
        ;  Server OCSP response open parameters
        ;--------------------------------------------------------------------------
        CERT_SERVER_OCSP_RESPONSE_OPEN_PARA struct
          cbSize DWORD ?
          dwFlags DWORD ?
          ; If nonNULL, *pcbUsedSize is updated with subset of cbSize that was
          ; used. If OPEN_PARA isn't supported, then, *pcbUsedSize won't be
          ; updated.
          pcbUsedSize POINTER ?
          ; If nonNULL, the OCSP response is either read from or written to
          ; this directory. The CERT_SERVER_OCSP_RESPONSE_OPEN_PARA_READ_FLAG
          ; dwFlags must be set to read.
          ; The CERT_SERVER_OCSP_RESPONSE_OPEN_PARA_WRITE_FLAG dwFlags must be
          ; set to write. Its an ERROR_INVALID_PARAMETER error to set both dwFlags.
          ; The format of the OCSP response file name:
          ; <ASCII HEX ServerCert SHA1 Thumbprint>".ocsp"
          pwszOcspDirectory POINTER ?
          ; If nonNULL, the callback is called whenever the OCSP response is
          ; updated. Note, the updated OCSP response might not be time valid.
          pfnUpdateCallback PFN_CERT_SERVER_OCSP_RESPONSE_UPDATE_CALLBACK ?
          pvUpdateCallbackArg POINTER ?
        CERT_SERVER_OCSP_RESPONSE_OPEN_PARA ends
        _CERT_SERVER_OCSP_RESPONSE_OPEN_PARA typedef CERT_SERVER_OCSP_RESPONSE_OPEN_PARA
        PCERT_SERVER_OCSP_RESPONSE_OPEN_PARA typedef ptr CERT_SERVER_OCSP_RESPONSE_OPEN_PARA
        ; Set either of these flags in the above dwFlags to use the
        ; pwszOcspDirectory.
        CERT_SERVER_OCSP_RESPONSE_OPEN_PARA_READ_FLAG equ 00000001h
        CERT_SERVER_OCSP_RESPONSE_OPEN_PARA_WRITE_FLAG equ 00000002h
        ;+-------------------------------------------------------------------------
        ;  Open a handle to an OCSP response associated with a server certificate
        ;  chain. If the end certificate doesn't have an OCSP AIA URL, NULL is
        ;  returned with LastError set to CRYPT_E_NOT_IN_REVOCATION_DATABASE. NULL
        ;  will also be returned if unable to allocate memory or create system
        ;  objects.
        ;  This API will try to retrieve an initial OCSP response before returning.
        ;  This API will block during the retrieval. If unable to successfully
        ;  retrieve the first OCSP response, a non-NULL handle will still be returned
        ;  if not one of the error cases mentioned above.
        ;  The CERT_SERVER_OCSP_RESPONSE_ASYNC_FLAG flag can be set to
        ;  return immediately without making the initial synchronous retrieval.
        ;  A background thread is created that will pre-fetch time valid
        ;  OCSP responses.
        ;  The input chain context will be AddRef'ed and not freed until
        ;  the returned handle is closed.
        ;  CertCloseServerOcspResponse() must be called to close the returned
        ;  handle.
        ;--------------------------------------------------------------------------
        @DefProto DllImport, CertOpenServerOcspResponse, WIN_STD_CALL_CONV,, <:PCCERT_CHAIN_CONTEXT, :DWORD, :PCERT_SERVER_OCSP_RESPONSE_OPEN_PARA>, 12
        ; Set this flag to return immediately without making the initial
        ; synchronous retrieval
        CERT_SERVER_OCSP_RESPONSE_ASYNC_FLAG equ 00000001h
        ;+-------------------------------------------------------------------------
        ;  AddRef a HCERT_SERVER_OCSP_RESPONSE returned by
        ;  CertOpenServerOcspResponse(). Each Open and AddRef requires a
        ;  corresponding CertCloseServerOcspResponse().
        ;--------------------------------------------------------------------------
        @DefProto DllImport, CertAddRefServerOcspResponse, WIN_STD_CALL_CONV,, <:HCERT_SERVER_OCSP_RESPONSE>, 4
        ;+-------------------------------------------------------------------------
        ;  Close the handle returned by CertOpenServerOcspResponse() or AddRef'ed
        ;  by CertAddRefServerOcspResponse().
        ;  dwFlags isn't currently used and must be set to 0.
        ;--------------------------------------------------------------------------
        @DefProto DllImport, CertCloseServerOcspResponse, WIN_STD_CALL_CONV,, <:HCERT_SERVER_OCSP_RESPONSE, :DWORD>, 8
        ;+-------------------------------------------------------------------------
        ;  Get a time valid OCSP response context for the handle created for
        ;  the server certificate chain.
        ;  This API won't block to retrieve the OCSP response. It will return
        ;  the current pre-fetched OCSP response. If a time valid OCSP response
        ;  isn't available, NULL will be returned with LAST_ERROR set to
        ;  CRYPT_E_REVOCATION_OFFLINE.
        ;  CertFreeServerOcspResponseContext() must be called to free the
        ;  returned OCSP response context.
        ;--------------------------------------------------------------------------
        @DefProto DllImport, CertGetServerOcspResponseContext, WIN_STD_CALL_CONV,, <:HCERT_SERVER_OCSP_RESPONSE, :DWORD, :LPVOID>, 12
        ;+-------------------------------------------------------------------------
        ;  AddRef a PCCERT_SERVER_OCSP_RESPONSE_CONTEXT returned by
        ;  CertGetServerOcspResponseContext(). Each Get and AddRef requires a
        ;  corresponding CertFreeServerOcspResponseContext().
        ;--------------------------------------------------------------------------
        @DefProto DllImport, CertAddRefServerOcspResponseContext, WIN_STD_CALL_CONV,, <:PCCERT_SERVER_OCSP_RESPONSE_CONTEXT>, 4
        ;+-------------------------------------------------------------------------
        ;  Free the OCSP response context returned by
        ;  CertGetServerOcspResponseContext().
        ;--------------------------------------------------------------------------
        @DefProto DllImport, CertFreeServerOcspResponseContext, WIN_STD_CALL_CONV,, <:PCCERT_SERVER_OCSP_RESPONSE_CONTEXT>, 4
      endif
      ; (NTDDI_VERSION >= NTDDI_VISTA)
      ;+-------------------------------------------------------------------------
      ;  Helper function to do URL retrieval of logo or biometric information
      ;  specified in either the szOID_LOGOTYPE_EXT or szOID_BIOMETRIC_EXT
      ;  certificate extension.
      ;  Only the first hashed URL matching lpszLogoOrBiometricType is used
      ;  to do the URL retrieval. Only direct logotypes are supported.
      ;  The bytes at the first URL are retrieved via
      ;  CryptRetrieveObjectByUrlW and hashed. The computed hash is compared
      ;  against the hash in the certificate.  For success, ppbData, pcbData
      ;  and optionally ppwszMimeType are updated with
      ;  CryptMemAlloc'ed memory which must be freed by calling CryptMemFree().
      ;  For failure, *ppbData, *pcbData and optionally *ppwszMimeType are
      ;  zero'ed.
      ;  For failure, the following errors may be set in LastError:
      ;      E_INVALIDARG - invalid lpszLogoOrBiometricType, not one of the
      ;          acceptable predefined types.
      ;      CRYPT_E_NOT_FOUND - certificate doesn't have the
      ;          szOID_LOGOTYPE_EXT or szOID_BIOMETRIC_EXT extension or a matching
      ;          lpszLogoOrBiometricType wasn't found with a non-empty
      ;          hashed URL.
      ;      ERROR_NOT_SUPPORTED - matched the unsupported indirect logotype
      ;      NTE_BAD_ALGID - unknown hash algorithm OID
      ;      ERROR_INVALID_DATA - no bytes were retrieved at the specified URL
      ;          in the certificate extension
      ;      CRYPT_E_HASH_VALUE - the computed hash doesn't match the hash
      ;          in the certificate
      ;  CertRetrieveLogoOrBiometricInfo calls the following functions which
      ;  will set LastError for failure:
      ;      CryptDecodeObjectEx(szOID_LOGOTYPE_EXT or szOID_BIOMETRIC_EXT)
      ;      CryptRetrieveObjectByUrlW
      ;      CryptHashCertificate
      ;      CryptMemAlloc
      ;  lpszLogoOrBiometricType is one of the predefined logotype or biometric
      ;  types, an other logotype OID or a biometric OID.
      ;  dwRetrievalFlags - see CryptRetrieveObjectByUrlW
      ;  dwTimeout - see CryptRetrieveObjectByUrlW
      ;  dwFlags - reserved, must be set to 0
      ;  pvReserved - reserved, must be set to NULL
      ;  *ppwszMimeType is always NULL for the biometric types. For success,
      ;  the caller must always check if non-NULL before dereferencing.
      ;--------------------------------------------------------------------------
      @DefProto DllImport, CertRetrieveLogoOrBiometricInfo, WIN_STD_CALL_CONV,, <:PCCERT_CONTEXT, :LPCSTR, :DWORD, :DWORD, :DWORD, :ptr, :ptr ptr BYTE, :ptr DWORD, :ptr LPWSTR>, 36
      ; CryptMemFree()
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP|WINAPI_PARTITION_PHONE_RESTRICTED | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      ; Predefined Logotypes
      CERT_RETRIEVE_ISSUER_LOGO equ (1)
      CERT_RETRIEVE_SUBJECT_LOGO equ (2)
      CERT_RETRIEVE_COMMUNITY_LOGO equ (3)
      ; Predefined Biometric types
      CERT_RETRIEVE_BIOMETRIC_PREDEFINED_BASE_TYPE equ (1000)
      CERT_RETRIEVE_BIOMETRIC_PICTURE_TYPE equ <(CERT_RETRIEVE_BIOMETRIC_PREDEFINED_BASE_TYPE + CERT_BIOMETRIC_PICTURE_TYPE)>
      CERT_RETRIEVE_BIOMETRIC_SIGNATURE_TYPE equ <(CERT_RETRIEVE_BIOMETRIC_PREDEFINED_BASE_TYPE + CERT_BIOMETRIC_SIGNATURE_TYPE)>
      ; Certificate Selection API
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
        ; Selection Criteria
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
        ;add for WinRT
        CERT_SELECT_BY_ISSUER_DISPLAYNAME equ 12
        CERT_SELECT_BY_FRIENDLYNAME equ 13
        CERT_SELECT_BY_THUMBPRINT equ 14
        CERT_SELECT_LAST equ <CERT_SELECT_BY_TLS_SIGNATURES>
        CERT_SELECT_MAX equ (CERT_SELECT_LAST * 3)
        ; Selection Flags
        CERT_SELECT_ALLOW_EXPIRED equ 00000001h
        CERT_SELECT_TRUSTED_ROOT equ 00000002h
        CERT_SELECT_DISALLOW_SELFSIGNED equ 00000004h
        CERT_SELECT_HAS_PRIVATE_KEY equ 00000008h
        CERT_SELECT_HAS_KEY_FOR_SIGNATURE equ 00000010h
        CERT_SELECT_HAS_KEY_FOR_KEY_EXCHANGE equ 00000020h
        CERT_SELECT_HARDWARE_ONLY equ 00000040h
        CERT_SELECT_ALLOW_DUPLICATES equ 00000080h
        CERT_SELECT_IGNORE_AUTOSELECT equ 00000100h
        ;+-------------------------------------------------------------------------
        ;  Build certificate chains from the certificates in the store and select
        ;  the matching ones based on the flags and selection criteria.
        ;--------------------------------------------------------------------------
        @DefProto DllImport, CertSelectCertificateChains, WIN_STD_CALL_CONV,, <:LPCGUID, :DWORD, :PCCERT_SELECT_CHAIN_PARA, :DWORD, :PCCERT_SELECT_CRITERIA, :HCERTSTORE, :PDWORD, :ptr ptr PCCERT_CHAIN_CONTEXT>, 32
        ;+-------------------------------------------------------------------------
        ;  Free the array of pointers to chain contexts.
        ;  CertFreeCertificateChain is NOT called for each entry.
        ;--------------------------------------------------------------------------
        @DefProto DllImport, CertFreeCertificateChainList, WIN_STD_CALL_CONV,, <:ptr PCCERT_CHAIN_CONTEXT>, 4
      endif
      ; (NTDDI_VERSION >= NTDDI_WIN7)
      ; Time stamp API
      if (NTDDI_VERSION ge NTDDI_WIN7)
        ;+-------------------------------------------------------------------------
        ;  CRYPT_TIMESTAMP_REQUEST
        ;--------------------------------------------------------------------------
        TIMESTAMP_VERSION equ 1
        CRYPT_TIMESTAMP_REQUEST struct
          dwVersion DWORD ?
          ; v1
          HashAlgorithm CRYPT_ALGORITHM_IDENTIFIER <>
          HashedMessage CRYPT_DER_BLOB <>
          pszTSAPolicyId POINTER ?
          ; OPTIONAL
          Nonce CRYPT_INTEGER_BLOB <>
          ; OPTIONAL
          fCertReq DWORD ?
          ; DEFAULT FALSE
          cExtension DWORD ?
          rgExtension PCERT_EXTENSION ?
          ; OPTIONAL
        CRYPT_TIMESTAMP_REQUEST ends
        _CRYPT_TIMESTAMP_REQUEST typedef CRYPT_TIMESTAMP_REQUEST
        PCRYPT_TIMESTAMP_REQUEST typedef ptr CRYPT_TIMESTAMP_REQUEST
        ;+-------------------------------------------------------------------------
        ;  CRYPT_TIMESTAMP_RESPONSE
        ;--------------------------------------------------------------------------
        CRYPT_TIMESTAMP_RESPONSE struct
          dwStatus DWORD ?
          cFreeText DWORD ?
          ; OPTIONAL
          rgFreeText POINTER ?
          FailureInfo CRYPT_BIT_BLOB <>
          ; OPTIONAL
          ContentInfo CRYPT_DER_BLOB <>
          ; OPTIONAL
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
        ;+-------------------------------------------------------------------------
        ;  CRYPT_TIMESTAMP_ACCURACY
        ;--------------------------------------------------------------------------
        CRYPT_TIMESTAMP_ACCURACY struct
          dwSeconds DWORD ?
          ; OPTIONAL
          dwMillis DWORD ?
          ; OPTIONAL
          dwMicros DWORD ?
          ; OPTIONAL
        CRYPT_TIMESTAMP_ACCURACY ends
        _CRYPT_TIMESTAMP_ACCURACY typedef CRYPT_TIMESTAMP_ACCURACY
        PCRYPT_TIMESTAMP_ACCURACY typedef ptr CRYPT_TIMESTAMP_ACCURACY
        ;+-------------------------------------------------------------------------
        ;  CRYPT_TIMESTAMP_INFO
        ;--------------------------------------------------------------------------
        CRYPT_TIMESTAMP_INFO struct
          dwVersion DWORD ?
          ; v1
          pszTSAPolicyId POINTER ?
          HashAlgorithm CRYPT_ALGORITHM_IDENTIFIER <>
          HashedMessage CRYPT_DER_BLOB <>
          SerialNumber CRYPT_INTEGER_BLOB <>
          ftTime FILETIME <>
          pvAccuracy PCRYPT_TIMESTAMP_ACCURACY ?
          ; OPTIONAL
          fOrdering DWORD ?
          ; OPTIONAL
          Nonce CRYPT_DER_BLOB <>
          ; OPTIONAL
          Tsa CRYPT_DER_BLOB <>
          ; OPTIONAL
          cExtension DWORD ?
          rgExtension PCERT_EXTENSION ?
          ; OPTIONAL
        CRYPT_TIMESTAMP_INFO ends
        _CRYPT_TIMESTAMP_INFO typedef CRYPT_TIMESTAMP_INFO
        PCRYPT_TIMESTAMP_INFO typedef ptr CRYPT_TIMESTAMP_INFO
        ;+-------------------------------------------------------------------------
        ;  CRYPT_TIMESTAMP_CONTEXT
        ;--------------------------------------------------------------------------
        CRYPT_TIMESTAMP_CONTEXT struct
          cbEncoded DWORD ?
          pbEncoded POINTER ?
          pTimeStamp PCRYPT_TIMESTAMP_INFO ?
        CRYPT_TIMESTAMP_CONTEXT ends
        _CRYPT_TIMESTAMP_CONTEXT typedef CRYPT_TIMESTAMP_CONTEXT
        PCRYPT_TIMESTAMP_CONTEXT typedef ptr CRYPT_TIMESTAMP_CONTEXT
        ;+-------------------------------------------------------------------------
        ;  CRYPT_TIMESTAMP_PARA
        ;  pszTSAPolicyId
        ;      [optional] Specifies the TSA policy under which the time stamp token
        ;      should be provided.
        ;  Nonce
        ;      [optional] Specifies the nonce value used by the client to verify the
        ;      timeliness of the response when no local clock is available.
        ;  fCertReq
        ;      Specifies whether the TSA must include in response the certificates
        ;      used to sign the time stamp token.
        ;  rgExtension
        ;      [optional]  Specifies Extensions to be included in request.
        ;--------------------------------------------------------------------------
        CRYPT_TIMESTAMP_PARA struct
          pszTSAPolicyId =POINTER ?
          ; OPTIONAL
          fRequestCerts DWORD ?
          ; Default is TRUE
          Nonce CRYPT_INTEGER_BLOB <>
          ; OPTIONAL
          cExtension DWORD ?
          rgExtension PCERT_EXTENSION ?
          ; OPTIONAL
        CRYPT_TIMESTAMP_PARA ends
        _CRYPT_TIMESTAMP_PARA typedef CRYPT_TIMESTAMP_PARA
        PCRYPT_TIMESTAMP_PARA typedef ptr CRYPT_TIMESTAMP_PARA
        ;+-------------------------------------------------------------------------
        ;  CryptRetrieveTimeStamp
        ;  wszUrl
        ;     [in] Specifies TSA where to send request to.
        ;  dwRetrievalFlags
        ;     [in]
        ;         TIMESTAMP_VERIFY_CONTEXT_SIGNATURE
        ;         TIMESTAMP_NO_AUTH_RETRIEVAL
        ;         TIMESTAMP_DONT_HASH_DATA
        ;  dwTimeout
        ;     [in] Specifies the maximum number of milliseconds to wait for retrieval.
        ;     If a value of zero is specified, this function does not time-out.
        ;  pszHashId
        ;      [in] Specifies hash algorithm OID.
        ;  pPara
        ;      [in, optional] Specifies additional request parameters.
        ;  pbData
        ;      [in] Points to array of bytes to be timestamped.
        ;  cbData
        ;      [in] Number of bytes in pbData.
        ;  ppTsContext
        ;     [out] The caller must free ppTsContext with CryptMemFree.
        ;  ppTsSigner
        ;     [out, optional] The address of a CERT_CONTEXT structure pointer that
        ;     receives the certificate of the signer.
        ;     When you have finished using this structure, free it by passing this
        ;     pointer to the CertFreeCertificateContext function.
        ;     This parameter can be NULL if the TSA signer's certificate is not needed.
        ; Remarks:
        ;     The TIMESTAMP_VERIFY_CONTEXT_SIGNATURE flag can be only used,
        ;     if fRequestCerts value is TRUE.
        ;--------------------------------------------------------------------------
        CryptRetrieveTimeStamp proto WIN_STD_CALL_CONV :LPCWSTR, :DWORD, :DWORD, :LPCSTR, :ptr CRYPT_TIMESTAMP_PARA, :ptr BYTE, :DWORD, :ptr PCRYPT_TIMESTAMP_CONTEXT, :ptr PCCERT_CONTEXT, :ptr HCERTSTORE
        ; Set this flag to inhibit hash calculation on pbData
        TIMESTAMP_DONT_HASH_DATA equ 00000001h
        ; Set this flag to enforce signature validation on retrieved time stamp.
        TIMESTAMP_VERIFY_CONTEXT_SIGNATURE equ 00000020h; CRYPT_VERIFY_CONTEXT_SIGNATURE

        ; Set this flag to inhibit automatic authentication handling. See the
        ; wininet flag, INTERNET_FLAG_NO_AUTH, for more details.
        TIMESTAMP_NO_AUTH_RETRIEVAL equ 00020000h;  CRYPT_NO_AUTH_RETRIEVAL

        ;+-------------------------------------------------------------------------
        ; CryptVerifyTimeStampSignature
        ;  pbTSContentInfo
        ;      [in] Points to a buffer with timestamp content.
        ;      These bytes are the same as returned in response by CRYPT_TIMESTAMP_CONTEXT::pbEncoded
        ;  cbTSContentInfo
        ;      [in] Number of bytes in pbTSContentInfo.
        ;  pbData
        ;      [in] Points to array of bytes to be timestamped.
        ;  cbData
        ;      [in] Number of bytes in pbData.
        ; hAdditionalStore
        ;    [in] Handle of any additional store to search for supporting
        ;    TSA's signing certificates and certificate trust lists (CTLs).
        ;    This parameter can be NULL if no additional store is to be searched.
        ; ppTsContext
        ;    [out] The caller must free ppTsContext with CryptMemFree
        ; ppTsSigner
        ;    [out, optional] The address of a CERT_CONTEXT structure pointer that
        ;    receives the certificate of the signer.
        ;    When you have finished using this structure, free it by passing this
        ;    pointer to the CertFreeCertificateContext function.
        ;    This parameter can be NULL if the TSA signer's certificate is not needed.
        ; NOTE:
        ;    The caller should validate pszTSAPolicyId, if any was specified in the request,
        ;    and ftTime.
        ;    The caller should also build a chain for ppTsSigner and validate the trust.
        ;--------------------------------------------------------------------------
        CryptVerifyTimeStampSignature proto WIN_STD_CALL_CONV :ptr BYTE, :DWORD, :ptr BYTE, :DWORD, :HCERTSTORE, :ptr PCRYPT_TIMESTAMP_CONTEXT, :ptr PCCERT_CONTEXT, :ptr HCERTSTORE
      endif
      ; (NTDDI_VERSION >= NTDDI_WIN7)
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)*
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_PHONE_RESTRICTED or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      ; Object Locator Provider API
      if (NTDDI_VERSION ge NTDDI_WIN8)
        CRYPT_OBJECT_LOCATOR_SPN_NAME_TYPE equ 1;ex. "HTTP/www.contoso.com"

        CRYPT_OBJECT_LOCATOR_LAST_RESERVED_NAME_TYPE equ 32
        CRYPT_OBJECT_LOCATOR_FIRST_RESERVED_USER_NAME_TYPE equ 33
        CRYPT_OBJECT_LOCATOR_LAST_RESERVED_USER_NAME_TYPE equ 0000FFFFh
        SSL_OBJECT_LOCATOR_PFX_FUNC equ <"SslObjectLocatorInitializePfx">
        SSL_OBJECT_LOCATOR_ISSUER_LIST_FUNC equ <"SslObjectLocatorInitializeIssuerList">
        SSL_OBJECT_LOCATOR_CERT_VALIDATION_CONFIG_FUNC equ <"SslObjectLocatorInitializeCertValidationConfig">
        ;--------------------------------------------------------------------------
        ; Releasing the locator can be done with the following reasons
        ; On system shutdown and process exit, the provider is not expected to
        ; release all memory. However, on service stop and dll unload the provider
        ; should clean itself up.
        ;--------------------------------------------------------------------------
        CRYPT_OBJECT_LOCATOR_RELEASE_SYSTEM_SHUTDOWN equ 1
        CRYPT_OBJECT_LOCATOR_RELEASE_SERVICE_STOP equ 2
        CRYPT_OBJECT_LOCATOR_RELEASE_PROCESS_EXIT equ 3
        CRYPT_OBJECT_LOCATOR_RELEASE_DLL_UNLOAD equ 4
        ;--------------------------------------------------------------------------
        ; The object locator provider receives this function when it is initialized.
        ; The object locator provider is expected to call this function when an
        ; object has changed. This indicates to the application that its copy of the
        ; object is stale and it should get an updated object.
        ; pContext
        ;    This is the context pararameter passed into the object locator providers
        ;    initialize function. The object locator provider must hold onto this context
        ;    and pass it back into this flush function.
        ; rgIdentifierOrNameList
        ;    An array of name/identifier blobs for objects that are stale. If an object
        ;    has an identifier then pass in the identifier name. If an object does not have
        ;    an identifier then pass in the name. You can pass in NULL which indicates all
        ;    objects are stale but this is not recommended for performance reasons.
        ; dwIdentifierOrNameListCount
        ;    Number of names/identifiers in the array. 0 implies that rgIdentifierOrNameList
        ;    is NULL which means all objects are stale.
        ;--------------------------------------------------------------------------
        TYPE_PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_FLUSH typedef proto WIN_STD_CALL_CONV :LPVOID, :ptr PCERT_NAME_BLOB, :DWORD
        PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_FLUSH typedef ptr TYPE_PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_FLUSH

        ;--------------------------------------------------------------------------
        ; An application will call on the object provider with the GET function when
        ; the application needs an object. The name blob uniquely identifies the content
        ; to return. This function can return an identifier data blob. Subsequent calls
        ; to this function for the same object will pass in the identifier that was previously
        ; returned. The identifier does not need to uniquely identify a particular object.
        ; pPluginContext
        ;    This is the context that is returned by the object locator provider when
        ;    it is initialized. 
        ; pIdentifier
        ;    This is the identifier that was returned on a previous GET call for this object.
        ;    On the first call for a particular object it is always NULL.
        ; dwNameType, pNameBlob
        ;    The name the application is using for the object. The name will uniquely identify
        ;    an object.
        ; ppContent, pcbContent
        ;    The returned object.
        ; ppwszPassword
        ;    If the returned object is a pfx then this is the password for the pfx.
        ; ppIdentifier
        ;    The identifier for the object.
        ;--------------------------------------------------------------------------
        TYPE_PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_GET typedef proto WIN_STD_CALL_CONV :LPVOID, :PCRYPT_DATA_BLOB, :DWORD, :PCERT_NAME_BLOB, :ptr PBYTE, :ptr DWORD, :ptr PCWSTR, :ptr PCRYPT_DATA_BLOB
        PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_GET typedef ptr TYPE_PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_GET

        ;--------------------------------------------------------------------------
        ; The application has indicated it no longer needs to locate objects by
        ; calling this release function.
        ; dwReason
        ;   Can be one of:
        ;       CRYPT_OBJECT_LOCATOR_RELEASE_SYSTEM_SHUTDOWN
        ;       CRYPT_OBJECT_LOCATOR_RELEASE_SERVICE_STOP 
        ;       CRYPT_OBJECT_LOCATOR_RELEASE_PROCESS_EXIT
        ;       CRYPT_OBJECT_LOCATOR_RELEASE_DLL_UNLOAD
        ;  pPluginContext
        ;    This is the context that is returned by the object locator provider when
        ;    it is initialized. 
        ;--------------------------------------------------------------------------
        TYPE_PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_RELEASE typedef proto WIN_STD_CALL_CONV :DWORD, :LPVOID
        PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_RELEASE typedef ptr TYPE_PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_RELEASE

        ;--------------------------------------------------------------------------
        ; If the PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_GET function returns a password
        ; that is non-NULL then this function will be called to release the memory.
        ; Best practice is to zero the memory before releasing it.
        ;  pPluginContext
        ;    This is the context that is returned by the object locator provider when
        ;    it is initialized. 
        ;  pwszPassword
        ;    Password obtained from PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_GET
        ;--------------------------------------------------------------------------
        TYPE_PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_FREE_PASSWORD typedef proto WIN_STD_CALL_CONV :LPVOID, :PCWSTR
        PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_FREE_PASSWORD typedef ptr TYPE_PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_FREE_PASSWORD

        ;--------------------------------------------------------------------------
        ; The content returned by the PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_GET function
        ; is released using this function.
        ;  pPluginContext
        ;    This is the context that is returned by the object locator provider when
        ;    it is initialized. 
        ;  pbData
        ;    Content returned by the GET function.
        ;--------------------------------------------------------------------------
        TYPE_PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_FREE typedef proto WIN_STD_CALL_CONV :LPVOID, :PBYTE
        PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_FREE typedef ptr TYPE_PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_FREE

        ;--------------------------------------------------------------------------
        ; The identifier returned by the PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_GET function
        ; is released with this function. This will be called only if the identifier is 
        ; non-NULL.
        ; The identifier will be released when the application no longer needs the
        ; object that was returned by the GET call.
        ; pPluginContext
        ;    This is the context that is returned by the object locator provider when
        ;    it is initialized. 
        ; pIdentifier
        ;    Identifier returned by the GET function.
        ;--------------------------------------------------------------------------
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
        ;--------------------------------------------------------------------------
        ; This is the initialization function of the object locator provider.
        ; 
        ; pfnFlush
        ;    This is the function which the provider must call when it detects that
        ;    an object has changed and the calling application should know about it
        ;    to prevent stale copies of the object from being used.
        ; pContext
        ;    This context is passed to the intialization function. The provider
        ;    is expected to hold onto this context and pass it back with the call
        ;    call to the flush function
        ; pdwExpectedObjectCount
        ;    The number of objects that the provider expects it will need to locate.
        ;    This number will determine the size of a hash table used internally.
        ; pFuncTable
        ;    A structure that describes a set of callback functions which can be used
        ;    to get objects and free objects.
        ; ppPluginContext
        ;    Extra information that the provider can return in its initialize call which
        ;    will be passed back to each of the subsequent callback functions.
        ;--------------------------------------------------------------------------
        TYPE_PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_INITIALIZE typedef proto WIN_STD_CALL_CONV :PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_FLUSH, :LPVOID, :ptr DWORD, :ptr PCRYPT_OBJECT_LOCATOR_PROVIDER_TABLE, :ptr ptr
        PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_INITIALIZE typedef ptr TYPE_PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_INITIALIZE

        ; If pTimeStamp is NULL or zero time, then, current time is used.
        ; For CERT_TIMESTAMP_HASH_USE_TYPE, current time is always used.
        ; If pSignerChainContext is NULL, then, checks if weak hash has
        ; been disabled for the more restrictive Third Party Chain. If TRUE
        ; is returned, then, this API must be called again with a nonNULL
        ; pSignerChainContext which might return FALSE for logging only or
        ; if this isn't a Third Party Chain and weak hash hasn't been disabled for
        ; all signers.
        ; For CERT_TIMESTAMP_HASH_USE_TYPE, this should be the file signer and
        ; not the timestamp chain signer.
        ; The following WinVerifyTrust dwProvFlags map to the corresponding
        ; dwChainFlags:
        ;  WTD_DISABLE_MD2_MD4 -> CERT_CHAIN_DISABLE_MD2_MD4
        ;  WTD_MOTW -> CERT_CHAIN_HAS_MOTW
        @DefProto DllImport, CertIsWeakHash, WIN_STD_CALL_CONV,, <:DWORD, :LPCWSTR, :DWORD, :PCCERT_CHAIN_CONTEXT, :LPFILETIME, :LPCWSTR>, 24
        TYPE_PFN_CERT_IS_WEAK_HASH typedef proto WIN_STD_CALL_CONV :DWORD, :LPCWSTR, :DWORD, :PCCERT_CHAIN_CONTEXT, :LPFILETIME, :LPCWSTR
        PFN_CERT_IS_WEAK_HASH typedef ptr TYPE_PFN_CERT_IS_WEAK_HASH

        ; Hash Use Types
        CERT_FILE_HASH_USE_TYPE equ 1
        CERT_TIMESTAMP_HASH_USE_TYPE equ 2
      endif
      ; (NTDDI_VERSION >= NTDDI_WIN8)
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP|WINAPI_PARTITION_PHONE_RESTRICTED | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
    endif
  endif
  ;!defined(_DDK_DRIVER_)
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
    ; The following headers are refactored out of WinCrypt.h,
    ; reflecting the separate binaries.
    ; Applications which do not depend on all functionality of CRYPT32 etc.,
    ; can link directly to smaller binaries using smaller headers also.
    ifndef _WINCRYPT_NO_DPAPI
      include dpapi.inc
    endif
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
  endif
endif
; __WINCRYPT_H__
