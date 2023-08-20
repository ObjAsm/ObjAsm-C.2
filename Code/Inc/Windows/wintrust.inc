;Include file created by h2incX, Version C.01.00, 20/08/2023 08:22
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: 'C:\Program Files (x86)\Windows Kits\10\Include\10.0.22621.0\um\wintrust.h', last modified: 08/05/2023 18:08
;Creation parameters: 

ifndef WINTRUST_H
  WINTRUST_H equ <>
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_PKG_WINTRUST)
    include wincrypt.inc
    if Defined(_MSC_VER) and (_MSC_VER ge 800)
      if _MSC_VER gt 1000
      endif
      if _MSC_VER ge 1200
      endif
    endif
    ifdef __cplusplus
      ;[...]
    endif
    ifndef WIN_CERT_REVISION_1_0
      WT_DEFINE_ALL_APIS equ <>
    else
    endif
    include pshpack8.inc
    WINTRUST_CONFIG_REGPATH equ <L("Software\Microsoft\Cryptography\Wintrust\Config")>
    WINTRUST_MAX_HEADER_BYTES_TO_MAP_VALUE_NAME equ <L("MaxHeaderBytesToMap")>
    WINTRUST_MAX_HEADER_BYTES_TO_MAP_DEFAULT equ 00A00000h
    WINTRUST_MAX_HASH_BYTES_TO_MAP_VALUE_NAME equ <L("MaxHashBytesToMap")>
    WINTRUST_MAX_HASH_BYTES_TO_MAP_DEFAULT equ 00100000h
    WINTRUST_DATA struct
      cbStruct DWORD ?
      pPolicyCallbackData LPVOID ?
      pSIPClientData LPVOID ?
      dwUIChoice DWORD ?
      WTD_UI_ALL equ 1
      WTD_UI_NONE equ 2
      WTD_UI_NOBAD equ 3
      WTD_UI_NOGOOD equ 4
      fdwRevocationChecks DWORD ?
      WTD_REVOKE_NONE equ 00000000h
      WTD_REVOKE_WHOLECHAIN equ 00000001h
      dwUnionChoice DWORD ?
      WTD_CHOICE_FILE equ 1
      WTD_CHOICE_CATALOG equ 2
      WTD_CHOICE_BLOB equ 3
      WTD_CHOICE_SIGNER equ 4
      WTD_CHOICE_CERT equ 5
      union
        pFile POINTER ?
        pCatalog POINTER ?
        pBlob POINTER ?
        pSgnr POINTER ?
        pCert POINTER ?
      ends
      dwStateAction DWORD ?
      WTD_STATEACTION_IGNORE equ 00000000h
      WTD_STATEACTION_VERIFY equ 00000001h
      WTD_STATEACTION_CLOSE equ 00000002h
      WTD_STATEACTION_AUTO_CACHE equ 00000003h
      WTD_STATEACTION_AUTO_CACHE_FLUSH equ 00000004h
      hWVTStateData HANDLE ?
      pwszURLReference POINTER ?
      dwProvFlags DWORD ?
      WTD_PROV_FLAGS_MASK equ 0000FFFFh
      WTD_USE_IE4_TRUST_FLAG equ 00000001h
      WTD_NO_IE4_CHAIN_FLAG equ 00000002h
      WTD_NO_POLICY_USAGE_FLAG equ 00000004h
      WTD_REVOCATION_CHECK_NONE equ 00000010h
      WTD_REVOCATION_CHECK_END_CERT equ 00000020h
      WTD_REVOCATION_CHECK_CHAIN equ 00000040h
      WTD_REVOCATION_CHECK_CHAIN_EXCLUDE_ROOT equ 00000080h
      WTD_SAFER_FLAG equ 00000100h
      WTD_HASH_ONLY_FLAG equ 00000200h
      WTD_USE_DEFAULT_OSVER_CHECK equ 00000400h
      WTD_LIFETIME_SIGNING_FLAG equ 00000800h
      WTD_CACHE_ONLY_URL_RETRIEVAL equ 00001000h
      WTD_DISABLE_MD2_MD4 equ 00002000h
      WTD_MOTW equ 00004000h
      WTD_CODE_INTEGRITY_DRIVER_MODE equ 00008000h
      dwUIContext DWORD ?
      WTD_UICONTEXT_EXECUTE equ 0
      WTD_UICONTEXT_INSTALL equ 1
      if (NTDDI_VERSION ge NTDDI_WIN8)
        pSignatureSettings POINTER ?
      endif
    WINTRUST_DATA ends
    _WINTRUST_DATA typedef WINTRUST_DATA
    PWINTRUST_DATA typedef ptr WINTRUST_DATA
    
    if (NTDDI_VERSION ge NTDDI_WIN8)
      WINTRUST_SIGNATURE_SETTINGS struct
        cbStruct DWORD ?
        dwIndex DWORD ?
        dwFlags DWORD ?
        cSecondarySigs DWORD ?
        dwVerifiedSigIndex DWORD ?
        pCryptoPolicy PCERT_STRONG_SIGN_PARA ?
      WINTRUST_SIGNATURE_SETTINGS ends
      WINTRUST_SIGNATURE_SETTINGS_ typedef WINTRUST_SIGNATURE_SETTINGS
      PWINTRUST_SIGNATURE_SETTINGS typedef ptr WINTRUST_SIGNATURE_SETTINGS
      
      WSS_VERIFY_SPECIFIC equ 00000001h
      WSS_GET_SECONDARY_SIG_COUNT equ 00000002h
      if (NTDDI_VERSION ge NTDDI_WINBLUE)
        WSS_VERIFY_SEALING equ 00000004h
        WSS_INPUT_FLAG_MASK equ 00000007h
        WSS_OUT_SEALING_STATUS_VERIFIED equ 80000000h
        WSS_OUT_HAS_SEALING_INTENT equ 40000000h
        WSS_OUT_FILE_SUPPORTS_SEAL equ 20000000h
        WSS_OUTPUT_FLAG_MASK equ 0e0000000h
      endif
    endif
    WINTRUST_FILE_INFO struct
      cbStruct DWORD ?
      pcwszFilePath LPCWSTR ?
      hFile HANDLE ?
      pgKnownSubject POINTER ?
    WINTRUST_FILE_INFO ends
    WINTRUST_FILE_INFO_ typedef WINTRUST_FILE_INFO
    PWINTRUST_FILE_INFO typedef ptr WINTRUST_FILE_INFO
    
    HCATADMIN typedef HANDLE
    WINTRUST_CATALOG_INFO struct
      cbStruct DWORD ?
      dwCatalogVersion DWORD ?
      pcwszCatalogFilePath LPCWSTR ?
      pcwszMemberTag LPCWSTR ?
      pcwszMemberFilePath LPCWSTR ?
      hMemberFile HANDLE ?
      pbCalculatedFileHash POINTER ?
      cbCalculatedFileHash DWORD ?
      pcCatalogContext PCCTL_CONTEXT ?
      if (NTDDI_VERSION ge NTDDI_WIN8)
        hCatAdmin HCATADMIN ?
      endif
    WINTRUST_CATALOG_INFO ends
    WINTRUST_CATALOG_INFO_ typedef WINTRUST_CATALOG_INFO
    PWINTRUST_CATALOG_INFO typedef ptr WINTRUST_CATALOG_INFO
    
    WINTRUST_BLOB_INFO struct
      cbStruct DWORD ?
      gSubject GUID <>
      pcwszDisplayName LPCWSTR ?
      cbMemObject DWORD ?
      pbMemObject POINTER ?
      cbMemSignedMsg DWORD ?
      pbMemSignedMsg POINTER ?
    WINTRUST_BLOB_INFO ends
    WINTRUST_BLOB_INFO_ typedef WINTRUST_BLOB_INFO
    PWINTRUST_BLOB_INFO typedef ptr WINTRUST_BLOB_INFO
    
    WINTRUST_SGNR_INFO struct
      cbStruct DWORD ?
      pcwszDisplayName LPCWSTR ?
      psSignerInfo POINTER ?
      chStores DWORD ?
      pahStores POINTER ?
    WINTRUST_SGNR_INFO ends
    WINTRUST_SGNR_INFO_ typedef WINTRUST_SGNR_INFO
    PWINTRUST_SGNR_INFO typedef ptr WINTRUST_SGNR_INFO
    
    WINTRUST_CERT_INFO struct
      cbStruct DWORD ?
      pcwszDisplayName LPCWSTR ?
      psCertContext POINTER ?
      chStores DWORD ?
      pahStores POINTER ?
      dwFlags DWORD ?
      WTCI_DONT_OPEN_STORES equ 00000001h
      WTCI_OPEN_ONLY_ROOT equ 00000002h
      WTCI_USE_LOCAL_MACHINE equ 00000004h
      psftVerifyAsOf POINTER ?
    WINTRUST_CERT_INFO ends
    WINTRUST_CERT_INFO_ typedef WINTRUST_CERT_INFO
    PWINTRUST_CERT_INFO typedef ptr WINTRUST_CERT_INFO
    
    include poppack.inc
    WinVerifyTrust proto WIN_STD_CALL_CONV :HWND, :ptr GUID, :LPVOID
    WinVerifyTrustEx proto WIN_STD_CALL_CONV :HWND, :ptr GUID, :ptr WINTRUST_DATA
    WTPF_TRUSTTEST equ 00000020h
    WTPF_TESTCANBEVALID equ 00000080h
    WTPF_IGNOREEXPIRATION equ 00000100h
    WTPF_IGNOREREVOKATION equ 00000200h
    WTPF_OFFLINEOK_IND equ 00000400h
    WTPF_OFFLINEOK_COM equ 00000800h
    WTPF_OFFLINEOKNBU_IND equ 00001000h
    WTPF_OFFLINEOKNBU_COM equ 00002000h
    WTPF_VERIFY_V1_OFF equ 00010000h
    WTPF_IGNOREREVOCATIONONTS equ 00020000h
    WTPF_ALLOWONLYPERTRUST equ 00040000h
    WintrustGetRegPolicyFlags proto WIN_STD_CALL_CONV :ptr DWORD
    WintrustSetRegPolicyFlags proto WIN_STD_CALL_CONV :DWORD
    TRUSTERROR_STEP_WVTPARAMS equ 0
    TRUSTERROR_STEP_FILEIO equ 2
    TRUSTERROR_STEP_SIP equ 3
    TRUSTERROR_STEP_SIPSUBJINFO equ 5
    TRUSTERROR_STEP_CATALOGFILE equ 6
    TRUSTERROR_STEP_CERTSTORE equ 7
    TRUSTERROR_STEP_MESSAGE equ 8
    TRUSTERROR_STEP_MSG_SIGNERCOUNT equ 9
    TRUSTERROR_STEP_MSG_INNERCNTTYPE equ 10
    TRUSTERROR_STEP_MSG_INNERCNT equ 11
    TRUSTERROR_STEP_MSG_STORE equ 12
    TRUSTERROR_STEP_MSG_SIGNERINFO equ 13
    TRUSTERROR_STEP_MSG_SIGNERCERT equ 14
    TRUSTERROR_STEP_MSG_CERTCHAIN equ 15
    TRUSTERROR_STEP_MSG_COUNTERSIGINFO equ 16
    TRUSTERROR_STEP_MSG_COUNTERSIGCERT equ 17
    TRUSTERROR_STEP_VERIFY_MSGHASH equ 18
    TRUSTERROR_STEP_VERIFY_MSGINDIRECTDATA equ 19
    TRUSTERROR_STEP_FINAL_WVTINIT equ 30
    TRUSTERROR_STEP_FINAL_INITPROV equ 31
    TRUSTERROR_STEP_FINAL_OBJPROV equ 32
    TRUSTERROR_STEP_FINAL_SIGPROV equ 33
    TRUSTERROR_STEP_FINAL_CERTPROV equ 34
    TRUSTERROR_STEP_FINAL_CERTCHKPROV equ 35
    TRUSTERROR_STEP_FINAL_POLICYPROV equ 36
    TRUSTERROR_STEP_FINAL_UIPROV equ 37
    TRUSTERROR_MAX_STEPS equ 38
    TYPE_PFN_CPD_MEM_ALLOC typedef proto WIN_STD_CALL_CONV :DWORD
    PFN_CPD_MEM_ALLOC typedef ptr TYPE_PFN_CPD_MEM_ALLOC
    TYPE_PFN_CPD_MEM_FREE typedef proto WIN_STD_CALL_CONV :ptr
    PFN_CPD_MEM_FREE typedef ptr TYPE_PFN_CPD_MEM_FREE
    TYPE_PFN_CPD_ADD_STORE typedef proto WIN_STD_CALL_CONV :ptr _CRYPT_PROVIDER_DATA, :HCERTSTORE
    PFN_CPD_ADD_STORE typedef ptr TYPE_PFN_CPD_ADD_STORE
    TYPE_PFN_CPD_ADD_SGNR typedef proto WIN_STD_CALL_CONV :ptr _CRYPT_PROVIDER_DATA, :BOOL, :DWORD, :ptr _CRYPT_PROVIDER_SGNR
    PFN_CPD_ADD_SGNR typedef ptr TYPE_PFN_CPD_ADD_SGNR
    TYPE_PFN_CPD_ADD_CERT typedef proto WIN_STD_CALL_CONV :ptr _CRYPT_PROVIDER_DATA, :DWORD, :BOOL, :DWORD, :PCCERT_CONTEXT
    PFN_CPD_ADD_CERT typedef ptr TYPE_PFN_CPD_ADD_CERT
    TYPE_PFN_CPD_ADD_PRIVDATA typedef proto WIN_STD_CALL_CONV :ptr _CRYPT_PROVIDER_DATA, :ptr _CRYPT_PROVIDER_PRIVDATA
    PFN_CPD_ADD_PRIVDATA typedef ptr TYPE_PFN_CPD_ADD_PRIVDATA
    TYPE_PFN_PROVIDER_INIT_CALL typedef proto WIN_STD_CALL_CONV :ptr _CRYPT_PROVIDER_DATA
    PFN_PROVIDER_INIT_CALL typedef ptr TYPE_PFN_PROVIDER_INIT_CALL
    TYPE_PFN_PROVIDER_OBJTRUST_CALL typedef proto WIN_STD_CALL_CONV :ptr _CRYPT_PROVIDER_DATA
    PFN_PROVIDER_OBJTRUST_CALL typedef ptr TYPE_PFN_PROVIDER_OBJTRUST_CALL
    TYPE_PFN_PROVIDER_SIGTRUST_CALL typedef proto WIN_STD_CALL_CONV :ptr _CRYPT_PROVIDER_DATA
    PFN_PROVIDER_SIGTRUST_CALL typedef ptr TYPE_PFN_PROVIDER_SIGTRUST_CALL
    TYPE_PFN_PROVIDER_CERTTRUST_CALL typedef proto WIN_STD_CALL_CONV :ptr _CRYPT_PROVIDER_DATA
    PFN_PROVIDER_CERTTRUST_CALL typedef ptr TYPE_PFN_PROVIDER_CERTTRUST_CALL
    TYPE_PFN_PROVIDER_FINALPOLICY_CALL typedef proto WIN_STD_CALL_CONV :ptr _CRYPT_PROVIDER_DATA
    PFN_PROVIDER_FINALPOLICY_CALL typedef ptr TYPE_PFN_PROVIDER_FINALPOLICY_CALL
    TYPE_PFN_PROVIDER_TESTFINALPOLICY_CALL typedef proto WIN_STD_CALL_CONV :ptr _CRYPT_PROVIDER_DATA
    PFN_PROVIDER_TESTFINALPOLICY_CALL typedef ptr TYPE_PFN_PROVIDER_TESTFINALPOLICY_CALL
    TYPE_PFN_PROVIDER_CLEANUP_CALL typedef proto WIN_STD_CALL_CONV :ptr _CRYPT_PROVIDER_DATA
    PFN_PROVIDER_CLEANUP_CALL typedef ptr TYPE_PFN_PROVIDER_CLEANUP_CALL
    TYPE_PFN_PROVIDER_CERTCHKPOLICY_CALL typedef proto WIN_STD_CALL_CONV :ptr _CRYPT_PROVIDER_DATA, :DWORD, :BOOL, :DWORD
    PFN_PROVIDER_CERTCHKPOLICY_CALL typedef ptr TYPE_PFN_PROVIDER_CERTCHKPOLICY_CALL
    WVT_OFFSETOF macro t, f
      exitm <(((and ((t *) 0) - f)))>
    endm
    WVT_ISINSTRUCT macro structtypedef, structpassedsize, member
      exitm <((WVT_OFFSETOF(structtypedef, member) + sizeof(((structtypedef *) 0) - member) <= structpassedsize) ? TRUE : FALSE)>
    endm
    WVT_IS_CBSTRUCT_GT_MEMBEROFFSET macro structtypedef, structpassedsize, member
      exitm <WVT_ISINSTRUCT(structtypedef, structpassedsize, member)>
    endm
    include pshpack8.inc
    CRYPT_PROVIDER_DATA struct
      cbStruct DWORD ?
      pWintrustData POINTER ?
      fOpenedFile BOOL ?
      hWndParent HWND ?
      pgActionID POINTER ?
      hProv HCRYPTPROV ?
      dwError DWORD ?
      dwRegSecuritySettings DWORD ?
      dwRegPolicySettings DWORD ?
      psPfns POINTER ?
      cdwTrustStepErrors DWORD ?
      padwTrustStepErrors POINTER ?
      chStores DWORD ?
      pahStores POINTER ?
      dwEncoding DWORD ?
      hMsg HCRYPTMSG ?
      csSigners DWORD ?
      pasSigners POINTER ?
      csProvPrivData DWORD ?
      pasProvPrivData POINTER ?
      dwSubjectChoice DWORD ?
      CPD_CHOICE_SIP equ 1
      union
        pPDSip POINTER ?
      ends
      pszUsageOID POINTER ?
      fRecallWithState BOOL ?
      sftSystemTime FILETIME <>
      pszCTLSignerUsageOID POINTER ?
      dwProvFlags DWORD ?
      CPD_USE_NT5_CHAIN_FLAG equ 80000000h
      CPD_REVOCATION_CHECK_NONE equ 00010000h
      CPD_REVOCATION_CHECK_END_CERT equ 00020000h
      CPD_REVOCATION_CHECK_CHAIN equ 00040000h
      CPD_REVOCATION_CHECK_CHAIN_EXCLUDE_ROOT equ 00080000h
      CPD_RETURN_LOWER_QUALITY_CHAINS equ 00100000h
      CPD_RFC3161v21 equ 00200000h
      dwFinalError DWORD ?
      pRequestUsage PCERT_USAGE_MATCH ?
      dwTrustPubSettings DWORD ?
      dwUIStateFlags DWORD ?
      CPD_UISTATE_MODE_PROMPT equ 00000000h
      CPD_UISTATE_MODE_BLOCK equ 00000001h
      CPD_UISTATE_MODE_ALLOW equ 00000002h
      CPD_UISTATE_MODE_MASK equ 00000003h
      if (NTDDI_VERSION ge NTDDI_WIN8)
        pSigState POINTER ?
        pSigSettings POINTER ?
      endif
    CRYPT_PROVIDER_DATA ends
    _CRYPT_PROVIDER_DATA typedef CRYPT_PROVIDER_DATA
    PCRYPT_PROVIDER_DATA typedef ptr CRYPT_PROVIDER_DATA
    
    if (NTDDI_VERSION ge NTDDI_WIN8)
      CRYPT_PROVIDER_SIGSTATE struct
        cbStruct DWORD ?
        rhSecondarySigs POINTER ?
        hPrimarySig HCRYPTMSG ?
        fFirstAttemptMade BOOL ?
        fNoMoreSigs BOOL ?
        cSecondarySigs DWORD ?
        dwCurrentIndex DWORD ?
        fSupportMultiSig BOOL ?
        dwCryptoPolicySupport DWORD ?
        if (NTDDI_VERSION ge NTDDI_WINBLUE)
          iAttemptCount DWORD ?
          fCheckedSealing BOOL ?
          pSealingSignature POINTER ?
        endif
      CRYPT_PROVIDER_SIGSTATE ends
      _CRYPT_PROVIDER_SIGSTATE typedef CRYPT_PROVIDER_SIGSTATE
      PCRYPT_PROVIDER_SIGSTATE typedef ptr CRYPT_PROVIDER_SIGSTATE
      
      WSS_OBJTRUST_SUPPORT equ 00000001h
      WSS_SIGTRUST_SUPPORT equ 00000002h
      WSS_CERTTRUST_SUPPORT equ 00000004h
    endif
    CRYPT_PROVIDER_FUNCTIONS struct
      cbStruct DWORD ?
      pfnAlloc PFN_CPD_MEM_ALLOC ?
      pfnFree PFN_CPD_MEM_FREE ?
      pfnAddStore2Chain PFN_CPD_ADD_STORE ?
      pfnAddSgnr2Chain PFN_CPD_ADD_SGNR ?
      pfnAddCert2Chain PFN_CPD_ADD_CERT ?
      pfnAddPrivData2Chain PFN_CPD_ADD_PRIVDATA ?
      pfnInitialize PFN_PROVIDER_INIT_CALL ?
      pfnObjectTrust PFN_PROVIDER_OBJTRUST_CALL ?
      pfnSignatureTrust PFN_PROVIDER_SIGTRUST_CALL ?
      pfnCertificateTrust PFN_PROVIDER_CERTTRUST_CALL ?
      pfnFinalPolicy PFN_PROVIDER_FINALPOLICY_CALL ?
      pfnCertCheckPolicy PFN_PROVIDER_CERTCHKPOLICY_CALL ?
      pfnTestFinalPolicy PFN_PROVIDER_TESTFINALPOLICY_CALL ?
      psUIpfns POINTER ?
      pfnCleanupPolicy PFN_PROVIDER_CLEANUP_CALL ?
    CRYPT_PROVIDER_FUNCTIONS ends
    _CRYPT_PROVIDER_FUNCTIONS typedef CRYPT_PROVIDER_FUNCTIONS
    PCRYPT_PROVIDER_FUNCTIONS typedef ptr CRYPT_PROVIDER_FUNCTIONS
    
    TYPE_PFN_PROVUI_CALL typedef proto WIN_STD_CALL_CONV :HWND, :ptr _CRYPT_PROVIDER_DATA
    PFN_PROVUI_CALL typedef ptr TYPE_PFN_PROVUI_CALL
    CRYPT_PROVUI_FUNCS struct
      cbStruct DWORD ?
      psUIData POINTER ?
      pfnOnMoreInfoClick PFN_PROVUI_CALL ?
      pfnOnMoreInfoClickDefault PFN_PROVUI_CALL ?
      pfnOnAdvancedClick PFN_PROVUI_CALL ?
      pfnOnAdvancedClickDefault PFN_PROVUI_CALL ?
    CRYPT_PROVUI_FUNCS ends
    _CRYPT_PROVUI_FUNCS typedef CRYPT_PROVUI_FUNCS
    PCRYPT_PROVUI_FUNCS typedef ptr CRYPT_PROVUI_FUNCS
    
    CRYPT_PROVUI_DATA struct
      cbStruct DWORD ?
      dwFinalError DWORD ?
      pYesButtonText POINTER ?
      pNoButtonText POINTER ?
      pMoreInfoButtonText POINTER ?
      pAdvancedLinkText POINTER ?
      pCopyActionText POINTER ?
      pCopyActionTextNoTS POINTER ?
      pCopyActionTextNotSigned POINTER ?
    CRYPT_PROVUI_DATA ends
    _CRYPT_PROVUI_DATA typedef CRYPT_PROVUI_DATA
    PCRYPT_PROVUI_DATA typedef ptr CRYPT_PROVUI_DATA
    
    CRYPT_PROVIDER_SGNR struct
      cbStruct DWORD ?
      sftVerifyAsOf FILETIME <>
      csCertChain DWORD ?
      pasCertChain POINTER ?
      dwSignerType DWORD ?
      SGNR_TYPE_TIMESTAMP equ 00000010h
      psSigner POINTER ?
      dwError DWORD ?
      csCounterSigners DWORD ?
      pasCounterSigners POINTER ?
      pChainContext POINTER ?
    CRYPT_PROVIDER_SGNR ends
    _CRYPT_PROVIDER_SGNR typedef CRYPT_PROVIDER_SGNR
    PCRYPT_PROVIDER_SGNR typedef ptr CRYPT_PROVIDER_SGNR
    
    CRYPT_PROVIDER_CERT struct
      cbStruct DWORD ?
      pCert PCCERT_CONTEXT ?
      fCommercial BOOL ?
      fTrustedRoot BOOL ?
      fSelfSigned BOOL ?
      fTestCert BOOL ?
      ;dwRevokedReason DWORD ?
      dwConfidence DWORD ?
      CERT_CONFIDENCE_SIG equ 10000000h
      CERT_CONFIDENCE_TIME equ 01000000h
      CERT_CONFIDENCE_TIMENEST equ 00100000h
      CERT_CONFIDENCE_AUTHIDEXT equ 00010000h
      CERT_CONFIDENCE_HYGIENE equ 00001000h
      CERT_CONFIDENCE_HIGHEST equ 11111000h
      dwError DWORD ?
      pTrustListContext POINTER ?
      fTrustListSignerCert BOOL ?
      pCtlContext PCCTL_CONTEXT ?
      dwCtlError DWORD ?
      fIsCyclic BOOL ?
      pChainElement PCERT_CHAIN_ELEMENT ?
    CRYPT_PROVIDER_CERT ends
    _CRYPT_PROVIDER_CERT typedef CRYPT_PROVIDER_CERT
    PCRYPT_PROVIDER_CERT typedef ptr CRYPT_PROVIDER_CERT
    
    CRYPT_PROVIDER_PRIVDATA struct
      cbStruct DWORD ?
      gProviderID GUID <>
      cbProvData DWORD ?
      pvProvData POINTER ?
    CRYPT_PROVIDER_PRIVDATA ends
    _CRYPT_PROVIDER_PRIVDATA typedef CRYPT_PROVIDER_PRIVDATA
    PCRYPT_PROVIDER_PRIVDATA typedef ptr CRYPT_PROVIDER_PRIVDATA
    
    PROVDATA_SIP struct
      cbStruct DWORD ?
      gSubject GUID <>
      pSip POINTER ?
      pCATSip POINTER ?
      psSipSubjectInfo POINTER ?
      psSipCATSubjectInfo POINTER ?
      psIndirectData POINTER ?
    PROVDATA_SIP ends
    _PROVDATA_SIP typedef PROVDATA_SIP
    PPROVDATA_SIP typedef ptr PROVDATA_SIP
    
    WT_CURRENT_VERSION equ 00000200h
    CRYPT_TRUST_REG_ENTRY struct
      cbStruct DWORD ?
      pwszDLLName POINTER ?
      pwszFunctionName POINTER ?
    CRYPT_TRUST_REG_ENTRY ends
    _CRYPT_TRUST_REG_ENTRY typedef CRYPT_TRUST_REG_ENTRY
    PCRYPT_TRUST_REG_ENTRY typedef ptr CRYPT_TRUST_REG_ENTRY
    
    CRYPT_REGISTER_ACTIONID struct
      cbStruct DWORD ?
      sInitProvider CRYPT_TRUST_REG_ENTRY <>
      sObjectProvider CRYPT_TRUST_REG_ENTRY <>
      sSignatureProvider CRYPT_TRUST_REG_ENTRY <>
      sCertificateProvider CRYPT_TRUST_REG_ENTRY <>
      sCertificatePolicyProvider CRYPT_TRUST_REG_ENTRY <>
      sFinalPolicyProvider CRYPT_TRUST_REG_ENTRY <>
      sTestPolicyProvider CRYPT_TRUST_REG_ENTRY <>
      sCleanupProvider CRYPT_TRUST_REG_ENTRY <>
    CRYPT_REGISTER_ACTIONID ends
    _CRYPT_REGISTER_ACTIONID typedef CRYPT_REGISTER_ACTIONID
    PCRYPT_REGISTER_ACTIONID typedef ptr CRYPT_REGISTER_ACTIONID
    
    TYPE_PFN_ALLOCANDFILLDEFUSAGE typedef proto WIN_STD_CALL_CONV :ptr SBYTE, :ptr _CRYPT_PROVIDER_DEFUSAGE
    PFN_ALLOCANDFILLDEFUSAGE typedef ptr TYPE_PFN_ALLOCANDFILLDEFUSAGE
    TYPE_PFN_FREEDEFUSAGE typedef proto WIN_STD_CALL_CONV :ptr SBYTE, :ptr _CRYPT_PROVIDER_DEFUSAGE
    PFN_FREEDEFUSAGE typedef ptr TYPE_PFN_FREEDEFUSAGE
    CRYPT_PROVIDER_REGDEFUSAGE struct
      cbStruct DWORD ?
      pgActionID POINTER ?
      pwszDllName POINTER ?
      pwszLoadCallbackDataFunctionName POINTER ?
      pwszFreeCallbackDataFunctionName POINTER ?
    CRYPT_PROVIDER_REGDEFUSAGE ends
    _CRYPT_PROVIDER_REGDEFUSAGE typedef CRYPT_PROVIDER_REGDEFUSAGE
    PCRYPT_PROVIDER_REGDEFUSAGE typedef ptr CRYPT_PROVIDER_REGDEFUSAGE
    
    CRYPT_PROVIDER_DEFUSAGE struct
      cbStruct DWORD ?
      gActionID GUID <>
      pDefPolicyCallbackData LPVOID ?
      pDefSIPClientData LPVOID ?
    CRYPT_PROVIDER_DEFUSAGE ends
    _CRYPT_PROVIDER_DEFUSAGE typedef CRYPT_PROVIDER_DEFUSAGE
    PCRYPT_PROVIDER_DEFUSAGE typedef ptr CRYPT_PROVIDER_DEFUSAGE
    
    include poppack.inc
    WT_PROVIDER_DLL_NAME equ <L("WINTRUST.DLL")>
    WT_PROVIDER_CERTTRUST_FUNCTION equ <L("WintrustCertificateTrust")>
    WintrustAddActionID proto WIN_STD_CALL_CONV :ptr GUID, :DWORD, :ptr CRYPT_REGISTER_ACTIONID
    WT_ADD_ACTION_ID_RET_RESULT_FLAG equ 1h
    WintrustRemoveActionID proto WIN_STD_CALL_CONV :ptr GUID
    WintrustLoadFunctionPointers proto WIN_STD_CALL_CONV :ptr GUID, :ptr CRYPT_PROVIDER_FUNCTIONS
    WintrustAddDefaultForUsage proto WIN_STD_CALL_CONV :ptr SBYTE, :ptr CRYPT_PROVIDER_REGDEFUSAGE
    DWACTION_ALLOCANDFILL equ 1
    DWACTION_FREE equ 2
    WintrustGetDefaultForUsage proto WIN_STD_CALL_CONV :DWORD, :ptr SBYTE, :ptr CRYPT_PROVIDER_DEFUSAGE
    WTHelperGetProvSignerFromChain proto WIN_STD_CALL_CONV :ptr CRYPT_PROVIDER_DATA, :DWORD, :BOOL, :DWORD
    WTHelperGetProvCertFromChain proto WIN_STD_CALL_CONV :ptr CRYPT_PROVIDER_SGNR, :DWORD
    WTHelperProvDataFromStateData proto WIN_STD_CALL_CONV :HANDLE
    WTHelperGetProvPrivateDataFromChain proto WIN_STD_CALL_CONV :ptr CRYPT_PROVIDER_DATA, :ptr GUID
    WTHelperCertIsSelfSigned proto WIN_STD_CALL_CONV :DWORD, :ptr CERT_INFO
    WTHelperCertCheckValidSignature proto WIN_STD_CALL_CONV :ptr CRYPT_PROVIDER_DATA
    include pshpack8.inc
    szOID_TRUSTED_CODESIGNING_CA_LIST equ <"1.3.6.1.4.1.311.2.2.1">
    szOID_TRUSTED_CLIENT_AUTH_CA_LIST equ <"1.3.6.1.4.1.311.2.2.2">
    szOID_TRUSTED_SERVER_AUTH_CA_LIST equ <"1.3.6.1.4.1.311.2.2.3">
    SPC_COMMON_NAME_OBJID equ <szOID_COMMON_NAME>
    SPC_TIME_STAMP_REQUEST_OBJID equ <"1.3.6.1.4.1.311.3.2.1">
    SPC_INDIRECT_DATA_OBJID equ <"1.3.6.1.4.1.311.2.1.4">
    SPC_SP_AGENCY_INFO_OBJID equ <"1.3.6.1.4.1.311.2.1.10">
    SPC_STATEMENT_TYPE_OBJID equ <"1.3.6.1.4.1.311.2.1.11">
    SPC_SP_OPUS_INFO_OBJID equ <"1.3.6.1.4.1.311.2.1.12">
    SPC_CERT_EXTENSIONS_OBJID equ <"1.3.6.1.4.1.311.2.1.14">
    SPC_PE_IMAGE_DATA_OBJID equ <"1.3.6.1.4.1.311.2.1.15">
    SPC_RAW_FILE_DATA_OBJID equ <"1.3.6.1.4.1.311.2.1.18">
    SPC_STRUCTURED_STORAGE_DATA_OBJID equ <"1.3.6.1.4.1.311.2.1.19">
    SPC_JAVA_CLASS_DATA_OBJID equ <"1.3.6.1.4.1.311.2.1.20">
    SPC_INDIVIDUAL_SP_KEY_PURPOSE_OBJID equ <"1.3.6.1.4.1.311.2.1.21">
    SPC_COMMERCIAL_SP_KEY_PURPOSE_OBJID equ <"1.3.6.1.4.1.311.2.1.22">
    SPC_CAB_DATA_OBJID equ <"1.3.6.1.4.1.311.2.1.25">
    SPC_GLUE_RDN_OBJID equ <"1.3.6.1.4.1.311.2.1.25">
    SPC_MINIMAL_CRITERIA_OBJID equ <"1.3.6.1.4.1.311.2.1.26">
    SPC_FINANCIAL_CRITERIA_OBJID equ <"1.3.6.1.4.1.311.2.1.27">
    SPC_LINK_OBJID equ <"1.3.6.1.4.1.311.2.1.28">
    SPC_SIGINFO_OBJID equ <"1.3.6.1.4.1.311.2.1.30">
    SPC_PE_IMAGE_PAGE_HASHES_V1_OBJID equ <"1.3.6.1.4.1.311.2.3.1">
    SPC_PE_IMAGE_PAGE_HASHES_V2_OBJID equ <"1.3.6.1.4.1.311.2.3.2">
    szOID_NESTED_SIGNATURE equ <"1.3.6.1.4.1.311.2.4.1">
    szOID_INTENT_TO_SEAL equ <"1.3.6.1.4.1.311.2.4.2">
    szOID_SEALING_SIGNATURE equ <"1.3.6.1.4.1.311.2.4.3">
    szOID_SEALING_TIMESTAMP equ <"1.3.6.1.4.1.311.2.4.4">
    szOID_ENHANCED_HASH equ <"1.3.6.1.4.1.311.2.5.1">
    SPC_RELAXED_PE_MARKER_CHECK_OBJID equ <"1.3.6.1.4.1.311.2.6.1">
    SPC_ENCRYPTED_DIGEST_RETRY_COUNT_OBJID equ <"1.3.6.1.4.1.311.2.6.2">
    szOID_PKCS_9_SEQUENCE_NUMBER equ <"1.2.840.113549.1.9.25.4">
    CAT_NAMEVALUE_OBJID equ <"1.3.6.1.4.1.311.12.2.1">
    CAT_MEMBERINFO_OBJID equ <"1.3.6.1.4.1.311.12.2.2">
    CAT_MEMBERINFO2_OBJID equ <"1.3.6.1.4.1.311.12.2.3">
    SPC_WINDOWS_HELLO_COMPATIBILITY_OBJID equ <"1.3.6.1.4.1.311.10.41.1">
    SPC_NATURAL_AUTH_PLUGIN_OBJID equ <"1.3.6.1.4.1.311.96.1.1">
    SPC_SP_AGENCY_INFO_STRUCT equ (2000)
    SPC_MINIMAL_CRITERIA_STRUCT equ (2001)
    SPC_FINANCIAL_CRITERIA_STRUCT equ (2002)
    SPC_INDIRECT_DATA_CONTENT_STRUCT equ (2003)
    SPC_PE_IMAGE_DATA_STRUCT equ (2004)
    SPC_LINK_STRUCT equ (2005)
    SPC_STATEMENT_TYPE_STRUCT equ (2006)
    SPC_SP_OPUS_INFO_STRUCT equ (2007)
    SPC_CAB_DATA_STRUCT equ (2008)
    SPC_JAVA_CLASS_DATA_STRUCT equ (2009)
    INTENT_TO_SEAL_ATTRIBUTE_STRUCT equ (2010)
    SEALING_SIGNATURE_ATTRIBUTE_STRUCT equ (2011)
    SEALING_TIMESTAMP_ATTRIBUTE_STRUCT equ (2012)
    SPC_SIGINFO_STRUCT equ (2130)
    CAT_NAMEVALUE_STRUCT equ (2221)
    CAT_MEMBERINFO_STRUCT equ (2222)
    CAT_MEMBERINFO2_STRUCT equ (2223)
    SPC_UUID_LENGTH equ 16
    SPC_UUID struct
      BYTE SPC_UUID_LENGTH dup (?)
    SPC_UUID ends
    SpcSerializedObjectAttributesClassId equ { 0A6h, 0B5h, 86h, 0D5h, 0B4h, 0A1h, 24h, 66h, 0AEh, 05h, 0A2h, 17h, 0DAh, 8Eh, 60h, 0D6h }
    SPC_SERIALIZED_OBJECT struct
      ClassId SPC_UUID <>
      SerializedData CRYPT_DATA_BLOB <>
    SPC_SERIALIZED_OBJECT ends
    _SPC_SERIALIZED_OBJECT typedef SPC_SERIALIZED_OBJECT
    PSPC_SERIALIZED_OBJECT typedef ptr SPC_SERIALIZED_OBJECT
    
    SPC_SIGINFO struct
      dwSipVersion DWORD ?
      gSIPGuid GUID <>
      dwReserved1 DWORD ?
      dwReserved2 DWORD ?
      dwReserved3 DWORD ?
      dwReserved4 DWORD ?
      dwReserved5 DWORD ?
    SPC_SIGINFO ends
    SPC_SIGINFO_ typedef SPC_SIGINFO
    PSPC_SIGINFO typedef ptr SPC_SIGINFO
    
    SPC_LINK struct
      dwLinkChoice DWORD ?
      SPC_URL_LINK_CHOICE equ 1
      SPC_MONIKER_LINK_CHOICE equ 2
      SPC_FILE_LINK_CHOICE equ 3
      union
        pwszUrl LPWSTR ?
        Moniker SPC_SERIALIZED_OBJECT <>
        pwszFile LPWSTR ?
      ends
    SPC_LINK ends
    SPC_LINK_ typedef SPC_LINK
    PSPC_LINK typedef ptr SPC_LINK
    
    SPC_PE_IMAGE_DATA struct
      Flags CRYPT_BIT_BLOB <>
      pFile PSPC_LINK ?
    SPC_PE_IMAGE_DATA ends
    _SPC_PE_IMAGE_DATA typedef SPC_PE_IMAGE_DATA
    PSPC_PE_IMAGE_DATA typedef ptr SPC_PE_IMAGE_DATA
    
    SPC_INDIRECT_DATA_CONTENT struct
      Data CRYPT_ATTRIBUTE_TYPE_VALUE <>
      DigestAlgorithm CRYPT_ALGORITHM_IDENTIFIER <>
      Digest CRYPT_HASH_BLOB <>
    SPC_INDIRECT_DATA_CONTENT ends
    _SPC_INDIRECT_DATA_CONTENT typedef SPC_INDIRECT_DATA_CONTENT
    PSPC_INDIRECT_DATA_CONTENT typedef ptr SPC_INDIRECT_DATA_CONTENT
    
    SPC_FINANCIAL_CRITERIA struct
      fFinancialInfoAvailable BOOL ?
      fMeetsCriteria BOOL ?
    SPC_FINANCIAL_CRITERIA ends
    _SPC_FINANCIAL_CRITERIA typedef SPC_FINANCIAL_CRITERIA
    PSPC_FINANCIAL_CRITERIA typedef ptr SPC_FINANCIAL_CRITERIA
    
    SPC_IMAGE struct
      pImageLink POINTER ?
      Bitmap CRYPT_DATA_BLOB <>
      Metafile CRYPT_DATA_BLOB <>
      EnhancedMetafile CRYPT_DATA_BLOB <>
      GifFile CRYPT_DATA_BLOB <>
    SPC_IMAGE ends
    _SPC_IMAGE typedef SPC_IMAGE
    PSPC_IMAGE typedef ptr SPC_IMAGE
    
    SPC_SP_AGENCY_INFO struct
      pPolicyInformation POINTER ?
      pwszPolicyDisplayText LPWSTR ?
      pLogoImage PSPC_IMAGE ?
      pLogoLink POINTER ?
    SPC_SP_AGENCY_INFO ends
    _SPC_SP_AGENCY_INFO typedef SPC_SP_AGENCY_INFO
    PSPC_SP_AGENCY_INFO typedef ptr SPC_SP_AGENCY_INFO
    
    SPC_STATEMENT_TYPE struct
      cKeyPurposeId DWORD ?
      rgpszKeyPurposeId POINTER ?
    SPC_STATEMENT_TYPE ends
    _SPC_STATEMENT_TYPE typedef SPC_STATEMENT_TYPE
    PSPC_STATEMENT_TYPE typedef ptr SPC_STATEMENT_TYPE
    
    SPC_SP_OPUS_INFO struct
      pwszProgramName LPCWSTR ?
      pMoreInfo POINTER ?
      pPublisherInfo POINTER ?
    SPC_SP_OPUS_INFO ends
    _SPC_SP_OPUS_INFO typedef SPC_SP_OPUS_INFO
    PSPC_SP_OPUS_INFO typedef ptr SPC_SP_OPUS_INFO
    
    CAT_NAMEVALUE struct
      pwszTag LPWSTR ?
      fdwFlags DWORD ?
      Value CRYPT_DATA_BLOB <>
    CAT_NAMEVALUE ends
    _CAT_NAMEVALUE typedef CAT_NAMEVALUE
    PCAT_NAMEVALUE typedef ptr CAT_NAMEVALUE
    
    CAT_MEMBERINFO struct
      pwszSubjGuid LPWSTR ?
      dwCertVersion DWORD ?
    CAT_MEMBERINFO ends
    _CAT_MEMBERINFO typedef CAT_MEMBERINFO
    PCAT_MEMBERINFO typedef ptr CAT_MEMBERINFO
    
    if (NTDDI_VERSION ge NTDDI_WIN8)
      CAT_MEMBERINFO2 struct
        SubjectGuid GUID <>
        dwCertVersion DWORD ?
      CAT_MEMBERINFO2 ends
      _CAT_MEMBERINFO2 typedef CAT_MEMBERINFO2
      PCAT_MEMBERINFO2 typedef ptr CAT_MEMBERINFO2
      
    endif
    if (NTDDI_VERSION ge NTDDI_WIN7)
      INTENT_TO_SEAL_ATTRIBUTE struct
        version ULONG ?
        seal BOOLEAN ?
      INTENT_TO_SEAL_ATTRIBUTE ends
      _INTENT_TO_SEAL_ATTRIBUTE typedef INTENT_TO_SEAL_ATTRIBUTE
      PINTENT_TO_SEAL_ATTRIBUTE typedef ptr INTENT_TO_SEAL_ATTRIBUTE
      
      SEALING_SIGNATURE_ATTRIBUTE struct
        version ULONG ?
        signerIndex ULONG ?
        signatureAlgorithm CRYPT_ALGORITHM_IDENTIFIER <>
        encryptedDigest CRYPT_DIGEST_BLOB <>
      SEALING_SIGNATURE_ATTRIBUTE ends
      _SEALING_SIGNATURE_ATTRIBUTE typedef SEALING_SIGNATURE_ATTRIBUTE
      PSEALING_SIGNATURE_ATTRIBUTE typedef ptr SEALING_SIGNATURE_ATTRIBUTE
      
      SEALING_TIMESTAMP_ATTRIBUTE struct
        version ULONG ?
        signerIndex ULONG ?
        sealTimeStampToken CRYPT_DATA_BLOB <>
      SEALING_TIMESTAMP_ATTRIBUTE ends
      _SEALING_TIMESTAMP_ATTRIBUTE typedef SEALING_TIMESTAMP_ATTRIBUTE
      PSEALING_TIMESTAMP_ATTRIBUTE typedef ptr SEALING_TIMESTAMP_ATTRIBUTE
      
    endif
    include poppack.inc
    ifdef WT_DEFINE_ALL_APIS
      WIN_CERTIFICATE struct
        dwLength DWORD ?
        wRevision WORD ?
        wCertificateType WORD ?
        bCertificate BYTE ANYSIZE_ARRAY dup (?)
      WIN_CERTIFICATE ends
      _WIN_CERTIFICATE typedef WIN_CERTIFICATE
      LPWIN_CERTIFICATE typedef ptr WIN_CERTIFICATE
      
      WIN_CERT_REVISION_1_0 equ 0100h
      WIN_CERT_REVISION_2_0 equ 0200h
      WIN_CERT_TYPE_X509 equ 0001h
      WIN_CERT_TYPE_PKCS_SIGNED_DATA equ 0002h
      WIN_CERT_TYPE_RESERVED_1 equ 0003h
      WIN_CERT_TYPE_TS_STACK_SIGNED equ 0004h
      WIN_TRUST_SUBJECT typedef LPVOID
      WIN_TRUST_ACTDATA_CONTEXT_WITH_SUBJECT struct
        hClientToken HANDLE ?
        SubjectType POINTER ?
        Subject WIN_TRUST_SUBJECT ?
      WIN_TRUST_ACTDATA_CONTEXT_WITH_SUBJECT ends
      _WIN_TRUST_ACTDATA_CONTEXT_WITH_SUBJECT typedef WIN_TRUST_ACTDATA_CONTEXT_WITH_SUBJECT
      LPWIN_TRUST_ACTDATA_CONTEXT_WITH_SUBJECT typedef ptr WIN_TRUST_ACTDATA_CONTEXT_WITH_SUBJECT
      
      WIN_TRUST_ACTDATA_SUBJECT_ONLY struct
        SubjectType POINTER ?
        Subject WIN_TRUST_SUBJECT ?
      WIN_TRUST_ACTDATA_SUBJECT_ONLY ends
      _WIN_TRUST_ACTDATA_SUBJECT_ONLY typedef WIN_TRUST_ACTDATA_SUBJECT_ONLY
      LPWIN_TRUST_ACTDATA_SUBJECT_ONLY typedef ptr WIN_TRUST_ACTDATA_SUBJECT_ONLY
      
      WIN_TRUST_SUBJTYPE_RAW_FILE equ { 959dc450h, 8d9eh, 11cfh, { 87h, 36h, 00h, 0aah, 00h, 0a4h, 85h, 0ebh } }
      WIN_TRUST_SUBJTYPE_PE_IMAGE equ { 43c9a1e0h, 8da0h, 11cfh, { 87h, 36h, 00h, 0aah, 00h, 0a4h, 85h, 0ebh } }
      WIN_TRUST_SUBJTYPE_JAVA_CLASS equ { 08ad3990h, 8da1h, 11cfh, { 87h, 36h, 00h, 0aah, 00h, 0a4h, 85h, 0ebh } }
      WIN_TRUST_SUBJTYPE_CABINET equ { 0d17c5374h, 0a392h, 11cfh, { 9dh, 0f5h, 0h, 0aah, 0h, 0c1h, 84h, 0e0h } }
      WIN_TRUST_SUBJECT_FILE struct
        hFile HANDLE ?
        lpPath LPCWSTR ?
      WIN_TRUST_SUBJECT_FILE ends
      _WIN_TRUST_SUBJECT_FILE typedef WIN_TRUST_SUBJECT_FILE
      LPWIN_TRUST_SUBJECT_FILE typedef ptr WIN_TRUST_SUBJECT_FILE
      
      WIN_TRUST_SUBJTYPE_RAW_FILEEX equ { 6f458110h, 0c2f1h, 11cfh, { 8ah, 69h, 0h, 0aah, 0h, 6ch, 37h, 6h } }
      WIN_TRUST_SUBJTYPE_PE_IMAGEEX equ { 6f458111h, 0c2f1h, 11cfh, { 8ah, 69h, 0h, 0aah, 0h, 6ch, 37h, 6h } }
      WIN_TRUST_SUBJTYPE_JAVA_CLASSEX equ { 6f458113h, 0c2f1h, 11cfh, { 8ah, 69h, 0h, 0aah, 0h, 6ch, 37h, 6h } }
      WIN_TRUST_SUBJTYPE_CABINETEX equ { 6f458114h, 0c2f1h, 11cfh, { 8ah, 69h, 0h, 0aah, 0h, 6ch, 37h, 6h } }
      WIN_TRUST_SUBJECT_FILE_AND_DISPLAY struct
        hFile HANDLE ?
        lpPath LPCWSTR ?
        lpDisplayName LPCWSTR ?
      WIN_TRUST_SUBJECT_FILE_AND_DISPLAY ends
      _WIN_TRUST_SUBJECT_FILE_AND_DISPLAY typedef WIN_TRUST_SUBJECT_FILE_AND_DISPLAY
      LPWIN_TRUST_SUBJECT_FILE_AND_DISPLAY typedef ptr WIN_TRUST_SUBJECT_FILE_AND_DISPLAY
      
      WIN_TRUST_SUBJTYPE_OLE_STORAGE equ { 0c257e740h, 8da0h, 11cfh, { 87h, 36h, 00h, 0aah, 00h, 0a4h, 85h, 0ebh } }
      WIN_SPUB_ACTION_TRUSTED_PUBLISHER equ { 66426730h, 8da1h, 11cfh, { 87h, 36h, 00h, 0aah, 00h, 0a4h, 85h, 0ebh } }
      WIN_SPUB_ACTION_NT_ACTIVATE_IMAGE equ { 8bc96b00h, 8da1h, 11cfh, { 87h, 36h, 00h, 0aah, 00h, 0a4h, 85h, 0ebh } }
      WIN_SPUB_ACTION_PUBLISHED_SOFTWARE equ { 64b9d180h, 8da2h, 11cfh, { 87h, 36h, 00h, 0aah, 00h, 0a4h, 85h, 0ebh } }
      WIN_SPUB_TRUSTED_PUBLISHER_DATA struct
        hClientToken HANDLE ?
        lpCertificate LPWIN_CERTIFICATE ?
      WIN_SPUB_TRUSTED_PUBLISHER_DATA ends
      _WIN_SPUB_TRUSTED_PUBLISHER_DATA typedef WIN_SPUB_TRUSTED_PUBLISHER_DATA
      LPWIN_SPUB_TRUSTED_PUBLISHER_DATA typedef ptr WIN_SPUB_TRUSTED_PUBLISHER_DATA
      
    endif
    OpenPersonalTrustDBDialogEx proto WIN_STD_CALL_CONV :HWND, :DWORD, :ptr PVOID
    WT_TRUSTDBDIALOG_NO_UI_FLAG equ 00000001h
    WT_TRUSTDBDIALOG_ONLY_PUB_TAB_FLAG equ 00000002h
    WT_TRUSTDBDIALOG_WRITE_LEGACY_REG_FLAG equ 00000100h
    WT_TRUSTDBDIALOG_WRITE_IEAK_STORE_FLAG equ 00000200h
    OpenPersonalTrustDBDialog proto WIN_STD_CALL_CONV :HWND
    WintrustSetDefaultIncludePEPageHashes proto WIN_STD_CALL_CONV :BOOL
    ifdef __cplusplus
      ;[...]
    endif
    if Defined(_MSC_VER) and (_MSC_VER ge 800)
      if _MSC_VER ge 1200
      else
      endif
    endif
  endif
endif
 