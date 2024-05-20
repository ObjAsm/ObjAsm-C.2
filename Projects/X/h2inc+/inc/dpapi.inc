;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\dpapi.h
;             Created on (UTC) 06/04/2024 06:15:53
;             Last modified on (UTC) 08/01/2024 17:04:18

;----------------------------------------------------------------------------
ifndef __DPAPI_H__
  __DPAPI_H__ equ <>
  if (_MSC_VER gt 1020)
  endif
  if (NTDDI_VERSION ge NTDDI_WIN8)
    if  not Defined(DPAPI_IMP)
      DPAPI_IMP equ <>
    endif
  else
    if  not Defined(_CRYPT32_)
      DPAPI_IMP equ <DECLSPEC_IMPORT>
    else
      DPAPI_IMP equ <>
    endif
  endif
  ;(NTDDI_VERSION >= NTDDI_WIN7)
  ifdef __cplusplus
    ;[...]
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
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
    ; Registry value for controlling Data Protection API (DPAPI) UI settings.
    szFORCE_KEY_PROTECTION equ <"ForceKeyProtection">
    dwFORCE_KEY_PROTECTION_DISABLED equ 0h
    dwFORCE_KEY_PROTECTION_USER_SELECT equ 1h
    dwFORCE_KEY_PROTECTION_HIGH equ 2h
    ; Data protection APIs enable applications to easily secure data.
    ; The base provider provides protection based on the users' logon
    ; credentials. The data secured with these APIs follow the same
    ; roaming characteristics as HKCU -- if HKCU roams, the data
    ; protected by the base provider may roam as well. This makes
    ; the API ideal for the munging of data stored in the registry.
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    ; Prompt struct -- what to tell users about the access
    CRYPTPROTECT_PROMPTSTRUCT struct
      cbSize DWORD ?
      dwPromptFlags DWORD ?
      hwndApp HWND ?
      szPrompt =POINTER ?
    CRYPTPROTECT_PROMPTSTRUCT ends
    _CRYPTPROTECT_PROMPTSTRUCT typedef CRYPTPROTECT_PROMPTSTRUCT
    PCRYPTPROTECT_PROMPTSTRUCT typedef ptr CRYPTPROTECT_PROMPTSTRUCT
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    ; base provider action
    CRYPTPROTECT_DEFAULT_PROVIDER equ { 0df9d8cd0h, 1501h, 11d1h, { 8ch, 7ah, 00h, 0c0h, 4fh, 0c2h, 97h, 0ebh } }
    ; CryptProtect PromptStruct dwPromtFlags
    ; prompt on unprotect
    CRYPTPROTECT_PROMPT_ON_UNPROTECT equ 1h; 1<<0

    ; prompt on protect
    CRYPTPROTECT_PROMPT_ON_PROTECT equ 2h; 1<<1

    CRYPTPROTECT_PROMPT_RESERVED equ 04h; reserved, do not use.

    ; default to strong variant UI protection (user supplied password currently).
    CRYPTPROTECT_PROMPT_STRONG equ 08h; 1<<3

    ; require strong variant UI protection (user supplied password currently).
    CRYPTPROTECT_PROMPT_REQUIRE_STRONG equ 10h; 1<<4

    ; CryptProtectData and CryptUnprotectData dwFlags
    ; for remote-access situations where ui is not an option
    ; if UI was specified on protect or unprotect operation, the call
    ; will fail and GetLastError() will indicate ERROR_PASSWORD_RESTRICTION
    CRYPTPROTECT_UI_FORBIDDEN equ 1h
    ; per machine protected data -- any user on machine where CryptProtectData
    ; took place may CryptUnprotectData
    CRYPTPROTECT_LOCAL_MACHINE equ 4h
    ; force credential synchronize during CryptProtectData()
    ; Synchronize is only operation that occurs during this operation
    CRYPTPROTECT_CRED_SYNC equ 8h
    ; Generate an Audit on protect and unprotect operations
    CRYPTPROTECT_AUDIT equ 10h
    ; Protect data with a non-recoverable key
    CRYPTPROTECT_NO_RECOVERY equ 20h
    ; Verify the protection of a protected blob
    CRYPTPROTECT_VERIFY_PROTECTION equ 40h
    ; Regenerate the local machine protection
    CRYPTPROTECT_CRED_REGENERATE equ 80h
    ; flags reserved for system use
    CRYPTPROTECT_FIRST_RESERVED_FLAGVAL equ 0FFFFFFFh
    CRYPTPROTECT_LAST_RESERVED_FLAGVAL equ 0FFFFFFFFh
    ; flags specific to base provider
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, CryptProtectData, WIN_STD_CALL_CONV,, <:ptr DATA_BLOB, :LPCWSTR, :ptr DATA_BLOB, :PVOID, :ptr CRYPTPROTECT_PROMPTSTRUCT, :DWORD, :ptr DATA_BLOB>, 28
    ; out encr blob
    @DefProto DllImport, CryptUnprotectData, WIN_STD_CALL_CONV,, <:ptr DATA_BLOB, :ptr LPWSTR, :ptr DATA_BLOB, :PVOID, :ptr CRYPTPROTECT_PROMPTSTRUCT, :DWORD, :ptr DATA_BLOB>, 28
    ; out
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    if (NTDDI_VERSION ge NTDDI_WIN8)
      CryptProtectDataNoUI proto WIN_STD_CALL_CONV :ptr DATA_BLOB, :LPCWSTR, :ptr DATA_BLOB, :PVOID, :ptr CRYPTPROTECT_PROMPTSTRUCT, :DWORD, :ptr BYTE, :DWORD, :ptr DATA_BLOB
      ; out encr blob
      CryptUnprotectDataNoUI proto WIN_STD_CALL_CONV :ptr DATA_BLOB, :ptr LPWSTR, :ptr DATA_BLOB, :PVOID, :ptr CRYPTPROTECT_PROMPTSTRUCT, :DWORD, :ptr BYTE, :DWORD, :ptr DATA_BLOB
      ; out
    endif
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    if (NTDDI_VERSION ge NTDDI_VISTA)
      @DefProto DllImport, CryptUpdateProtectedState, WIN_STD_CALL_CONV,, <:PSID, :LPCWSTR, :DWORD, :ptr DWORD, :ptr DWORD>, 20
    endif
    ; (NTDDI_VERSION >= NTDDI_VISTA)
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    ; The buffer length passed into CryptProtectMemory and CryptUnprotectMemory
    ; must be a multiple of this length (or zero).
    CRYPTPROTECTMEMORY_BLOCK_SIZE equ 16
    ; CryptProtectMemory/CryptUnprotectMemory dwFlags
    ; Encrypt/Decrypt within current process context.
    CRYPTPROTECTMEMORY_SAME_PROCESS equ 00h
    ; Encrypt/Decrypt across process boundaries.
    ; eg: encrypted buffer passed across LPC to another process which calls CryptUnprotectMemory.
    CRYPTPROTECTMEMORY_CROSS_PROCESS equ 01h
    ; Encrypt/Decrypt across callers with same LogonId.
    ; eg: encrypted buffer passed across LPC to another process which calls CryptUnprotectMemory whilst impersonating.
    CRYPTPROTECTMEMORY_SAME_LOGON equ 02h
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, CryptProtectMemory, WIN_STD_CALL_CONV,, <:LPVOID, :DWORD, :DWORD>, 12
    ; multiple of CRYPTPROTECTMEMORY_BLOCK_SIZE
    @DefProto DllImport, CryptUnprotectMemory, WIN_STD_CALL_CONV,, <:LPVOID, :DWORD, :DWORD>, 12
    ; multiple of CRYPTPROTECTMEMORY_BLOCK_SIZE
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
  endif
  ifdef __cplusplus
    ;[...]
  endif
endif
; __DPAPI_H__
