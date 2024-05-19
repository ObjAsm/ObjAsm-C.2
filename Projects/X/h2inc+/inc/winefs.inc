;Include file created by h2inc+ version C.2.0 on (UTC) 19/05/2024 07:52:23
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\winefs.h\winefs.h
;             Created on (UTC) 06/04/2024 06:16:03
;             Last modified on (UTC) 16/12/2023 11:07:16

include winapifamily.inc
ifndef __WINEFS_H__
  __WINEFS_H__ equ <>
  if (NTDDI_VERSION ge NTDDI_WIN2K)
    if _MSC_VER gt 1000
    endif
    if _MSC_VER ge 1200
    endif
    ifdef __cplusplus
      ;[...]
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      WINEFS_SETUSERKEY_SET_CAPABILITIES equ 00000001h
      if (NTDDI_VERSION ge NTDDI_WINXP)
        ifndef ALGIDDEF
          ALGIDDEF equ <>
          ALG_ID typedef DWORD
        endif
      endif
      EFS_CERTIFICATE_BLOB struct
        dwCertEncodingType DWORD ?
        ifdef MIDL_PASS
          ;[...]
        endif
        cbData DWORD ?
        ifdef MIDL_PASS
          ;[...]
        endif
        pbData PBYTE ?
      EFS_CERTIFICATE_BLOB ends
      _CERTIFICATE_BLOB typedef EFS_CERTIFICATE_BLOB
      PEFS_CERTIFICATE_BLOB typedef ptr EFS_CERTIFICATE_BLOB
      EFS_HASH_BLOB struct
        ifdef MIDL_PASS
          ;[...]
        endif
        cbData DWORD ?
        ifdef MIDL_PASS
          ;[...]
        endif
        pbData PBYTE ?
      EFS_HASH_BLOB ends
      _EFS_HASH_BLOB typedef EFS_HASH_BLOB
      PEFS_HASH_BLOB typedef ptr EFS_HASH_BLOB
      if (NTDDI_VERSION ge NTDDI_WINXP)
        EFS_RPC_BLOB struct
          ifdef MIDL_PASS
            ;[...]
          endif
          cbData DWORD ?
          ifdef MIDL_PASS
            ;[...]
          endif
          pbData PBYTE ?
        EFS_RPC_BLOB ends
        _EFS_RPC_BLOB typedef EFS_RPC_BLOB
        PEFS_RPC_BLOB typedef ptr EFS_RPC_BLOB
      endif
      if (NTDDI_VERSION ge NTDDI_VISTA)
        EFS_PIN_BLOB struct
          ifdef MIDL_PASS
            ;[...]
          endif
          cbPadding DWORD ?
          ifdef MIDL_PASS
            ;[...]
          endif
          cbData DWORD ?
          ifdef MIDL_PASS
            ;[...]
          endif
          pbData PBYTE ?
        EFS_PIN_BLOB ends
        _EFS_PIN_BLOB typedef EFS_PIN_BLOB
        PEFS_PIN_BLOB typedef ptr EFS_PIN_BLOB
      endif
      if (NTDDI_VERSION ge NTDDI_WINXP)
        EFS_KEY_INFO struct
          dwVersion DWORD ?
          Entropy ULONG ?
          Algorithm ALG_ID ?
          KeyLength ULONG ?
        EFS_KEY_INFO ends
        _EFS_KEY_INFO typedef EFS_KEY_INFO
        PEFS_KEY_INFO typedef ptr EFS_KEY_INFO
      endif
      if (NTDDI_VERSION ge NTDDI_WIN7)
        EFS_COMPATIBILITY_INFO struct
          EfsVersion DWORD ?
        EFS_COMPATIBILITY_INFO ends
        _EFS_COMPATIBILITY_INFO typedef EFS_COMPATIBILITY_INFO
        PEFS_COMPATIBILITY_INFO typedef ptr EFS_COMPATIBILITY_INFO
      endif
      if (NTDDI_VERSION ge NTDDI_WINBLUE)
        EFS_COMPATIBILITY_VERSION_NCRYPT_PROTECTOR equ 5
      endif
      if (NTDDI_VERSION ge NTDDI_WINTHRESHOLD)
        EFS_COMPATIBILITY_VERSION_PFILE_PROTECTOR equ 6
        EFS_IS_DESCRIPTOR_VERSION macro __v
          exitm <((__v == EFS_COMPATIBILITY_VERSION_NCRYPT_PROTECTOR) or (__v == EFS_COMPATIBILITY_VERSION_PFILE_PROTECTOR))>
        endm
        EFS_SUBVER_UNKNOWN equ 0
        EFS_EFS_SUBVER_EFS_CERT equ 1
        EFS_PFILE_SUBVER_RMS equ 2
        EFS_PFILE_SUBVER_APPX equ 3
        EFS_VERSION_INFO struct
          EfsVersion DWORD ?
          SubVersion DWORD ?
        EFS_VERSION_INFO ends
        _EFS_VERSION_INFO typedef EFS_VERSION_INFO
        PEFS_VERSION_INFO typedef ptr EFS_VERSION_INFO
        EFS_IS_APPX_VERSION macro __v, __subV
          exitm <((__v == EFS_COMPATIBILITY_VERSION_PFILE_PROTECTOR) and (__subV == EFS_PFILE_SUBVER_APPX))>
        endm
      endif
      if (NTDDI_VERSION ge NTDDI_VISTA)
        EFS_DECRYPTION_STATUS_INFO struct
          dwDecryptionError DWORD ?
          dwHashOffset DWORD ?
          cbHash DWORD ?
        EFS_DECRYPTION_STATUS_INFO ends
        _EFS_DECRYPTION_STATUS_INFO typedef EFS_DECRYPTION_STATUS_INFO
        PEFS_DECRYPTION_STATUS_INFO typedef ptr EFS_DECRYPTION_STATUS_INFO
        EFS_ENCRYPTION_STATUS_INFO struct
          bHasCurrentKey BOOL ?
          dwEncryptionError DWORD ?
        EFS_ENCRYPTION_STATUS_INFO ends
        _EFS_ENCRYPTION_STATUS_INFO typedef EFS_ENCRYPTION_STATUS_INFO
        PEFS_ENCRYPTION_STATUS_INFO typedef ptr EFS_ENCRYPTION_STATUS_INFO
      endif
      ENCRYPTION_CERTIFICATE struct
        cbTotalLength DWORD ?
        pUserSid POINTER ?
        pCertBlob PEFS_CERTIFICATE_BLOB ?
      ENCRYPTION_CERTIFICATE ends
      _ENCRYPTION_CERTIFICATE typedef ENCRYPTION_CERTIFICATE
      PENCRYPTION_CERTIFICATE typedef ptr ENCRYPTION_CERTIFICATE
      MAX_SID_SIZE equ 256
      ENCRYPTION_CERTIFICATE_HASH struct
        cbTotalLength DWORD ?
        pUserSid POINTER ?
        pHash PEFS_HASH_BLOB ?
        ifdef MIDL_PASS
          ;[...]
        endif
        lpDisplayInformation LPWSTR ?
      ENCRYPTION_CERTIFICATE_HASH ends
      _ENCRYPTION_CERTIFICATE_HASH typedef ENCRYPTION_CERTIFICATE_HASH
      PENCRYPTION_CERTIFICATE_HASH typedef ptr ENCRYPTION_CERTIFICATE_HASH
      ENCRYPTION_CERTIFICATE_HASH_LIST struct
        ifdef MIDL_PASS
          ;[...]
        endif
        nCert_Hash DWORD ?
        ifdef MIDL_PASS
          ;[...]
        endif
        pUsers POINTER ?
      ENCRYPTION_CERTIFICATE_HASH_LIST ends
      _ENCRYPTION_CERTIFICATE_HASH_LIST typedef ENCRYPTION_CERTIFICATE_HASH_LIST
      PENCRYPTION_CERTIFICATE_HASH_LIST typedef ptr ENCRYPTION_CERTIFICATE_HASH_LIST
      ENCRYPTION_CERTIFICATE_LIST struct
        ifdef MIDL_PASS
          ;[...]
        endif
        nUsers DWORD ?
        ifdef MIDL_PASS
          ;[...]
        endif
        pUsers POINTER ?
      ENCRYPTION_CERTIFICATE_LIST ends
      _ENCRYPTION_CERTIFICATE_LIST typedef ENCRYPTION_CERTIFICATE_LIST
      PENCRYPTION_CERTIFICATE_LIST typedef ptr ENCRYPTION_CERTIFICATE_LIST
      if (NTDDI_VERSION ge NTDDI_VISTA)
        EFS_METADATA_ADD_USER equ 00000001h
        EFS_METADATA_REMOVE_USER equ 00000002h
        EFS_METADATA_REPLACE_USER equ 00000004h
        EFS_METADATA_GENERAL_OP equ 00000008h
        ENCRYPTED_FILE_METADATA_SIGNATURE struct
          dwEfsAccessType DWORD ?
          pCertificatesAdded PENCRYPTION_CERTIFICATE_HASH_LIST ?
          pEncryptionCertificate PENCRYPTION_CERTIFICATE ?
          pEfsStreamSignature PEFS_RPC_BLOB ?
        ENCRYPTED_FILE_METADATA_SIGNATURE ends
        _ENCRYPTED_FILE_METADATA_SIGNATURE typedef ENCRYPTED_FILE_METADATA_SIGNATURE
        PENCRYPTED_FILE_METADATA_SIGNATURE typedef ptr ENCRYPTED_FILE_METADATA_SIGNATURE
      endif
      if (NTDDI_VERSION ge NTDDI_WIN8)
        ENCRYPTION_PROTECTOR struct
          cbTotalLength DWORD ?
          pUserSid POINTER ?
          ifdef MIDL_PASS
            ;[...]
          endif
          lpProtectorDescriptor LPWSTR ?
        ENCRYPTION_PROTECTOR ends
        _ENCRYPTION_PROTECTOR typedef ENCRYPTION_PROTECTOR
        PENCRYPTION_PROTECTOR typedef ptr ENCRYPTION_PROTECTOR
        ENCRYPTION_PROTECTOR_LIST struct
          nProtectors DWORD ?
          ifdef MIDL_PASS
            ;[...]
          endif
          pProtectors POINTER ?
        ENCRYPTION_PROTECTOR_LIST ends
        _ENCRYPTION_PROTECTOR_LIST typedef ENCRYPTION_PROTECTOR_LIST
        PENCRYPTION_PROTECTOR_LIST typedef ptr ENCRYPTION_PROTECTOR_LIST
      endif
      @DefProto DllImport, QueryUsersOnEncryptedFile, WIN_STD_CALL_CONV,, <:LPCWSTR, :ptr PENCRYPTION_CERTIFICATE_HASH_LIST>, 8
      @DefProto DllImport, QueryRecoveryAgentsOnEncryptedFile, WIN_STD_CALL_CONV,, <:LPCWSTR, :ptr PENCRYPTION_CERTIFICATE_HASH_LIST>, 8
      @DefProto DllImport, RemoveUsersFromEncryptedFile, WIN_STD_CALL_CONV,, <:LPCWSTR, :PENCRYPTION_CERTIFICATE_HASH_LIST>, 8
      @DefProto DllImport, AddUsersToEncryptedFile, WIN_STD_CALL_CONV,, <:LPCWSTR, :PENCRYPTION_CERTIFICATE_LIST>, 8
      if (NTDDI_VERSION ge NTDDI_VISTA)
        @DefProto DllImport, SetUserFileEncryptionKey, WIN_STD_CALL_CONV,, <:PENCRYPTION_CERTIFICATE>, 4
      else
        @DefProto DllImport, SetUserFileEncryptionKey, WIN_STD_CALL_CONV,, <:PENCRYPTION_CERTIFICATE>, 4
      endif
      if (NTDDI_VERSION ge NTDDI_VISTA)
        @DefProto DllImport, SetUserFileEncryptionKeyEx, WIN_STD_CALL_CONV,, <:PENCRYPTION_CERTIFICATE, :DWORD, :DWORD, :LPVOID>, 16
      endif
      @DefProto DllImport, FreeEncryptionCertificateHashList, WIN_STD_CALL_CONV,, <:PENCRYPTION_CERTIFICATE_HASH_LIST>, 4
      @DefProto DllImport, EncryptionDisable, WIN_STD_CALL_CONV,, <:LPCWSTR, :BOOL>, 8
      if (NTDDI_VERSION ge NTDDI_WS03)
        @DefProto DllImport, DuplicateEncryptionInfoFile, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR, :DWORD, :DWORD, :LPSECURITY_ATTRIBUTES>, 20
      elseif (NTDDI_VERSION ge NTDDI_WINXP)
        @DefProto DllImport, DuplicateEncryptionInfoFile, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR, :DWORD, :DWORD, :LPSECURITY_ATTRIBUTES>, 20
      endif
      if (NTDDI_VERSION ge NTDDI_VISTA)
        @DefProto DllImport, GetEncryptedFileMetadata, WIN_STD_CALL_CONV,, <:LPCWSTR, :PDWORD, :ptr PBYTE>, 12
        @DefProto DllImport, SetEncryptedFileMetadata, WIN_STD_CALL_CONV,, <:LPCWSTR, :PBYTE, :PBYTE, :PENCRYPTION_CERTIFICATE_HASH, :DWORD, :PENCRYPTION_CERTIFICATE_HASH_LIST>, 24
        @DefProto DllImport, FreeEncryptedFileMetadata, WIN_STD_CALL_CONV,, <:PBYTE>, 4
      endif
    endif
    ifdef __cplusplus
      ;[...]
    endif
    if _MSC_VER ge 1200
    endif
  endif
endif
