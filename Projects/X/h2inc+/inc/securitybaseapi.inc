;Include file created by h2inc+ version C.2.0 on (UTC) 19/05/2024 07:52:23
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\securitybaseapi.h\securitybaseapi.h
;             Created on (UTC) 06/04/2024 06:15:58
;             Last modified on (UTC) 21/02/2024 18:13:14

ifdef _MSC_VER
endif
ifndef _APISECUREBASE_
  _APISECUREBASE_ equ <>
  include apiset.inc
  include apisetcconv.inc
  include minwindef.inc
  include minwinbase.inc
  ifdef __cplusplus
    ;[...]
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, AccessCheck, WIN_STD_CALL_CONV,, <:PSECURITY_DESCRIPTOR, :HANDLE, :DWORD, :PGENERIC_MAPPING, :PPRIVILEGE_SET, :LPDWORD, :LPDWORD, :LPBOOL>, 32
    @DefProto DllImport, AccessCheckAndAuditAlarmW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPVOID, :LPWSTR, :LPWSTR, :PSECURITY_DESCRIPTOR, :DWORD, :PGENERIC_MAPPING, :BOOL, :LPDWORD, :LPBOOL, :LPBOOL>, 44
    ifdef UNICODE
      AccessCheckAndAuditAlarm equ <AccessCheckAndAuditAlarmW>
    endif
    @DefProto DllImport, AccessCheckByType, WIN_STD_CALL_CONV,, <:PSECURITY_DESCRIPTOR, :PSID, :HANDLE, :DWORD, :POBJECT_TYPE_LIST, :DWORD, :PGENERIC_MAPPING, :PPRIVILEGE_SET, :LPDWORD, :LPDWORD, :LPBOOL>, 44
    @DefProto DllImport, AccessCheckByTypeResultList, WIN_STD_CALL_CONV,, <:PSECURITY_DESCRIPTOR, :PSID, :HANDLE, :DWORD, :POBJECT_TYPE_LIST, :DWORD, :PGENERIC_MAPPING, :PPRIVILEGE_SET, :LPDWORD, :LPDWORD, :LPDWORD>, 44
    @DefProto DllImport, AccessCheckByTypeAndAuditAlarmW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPVOID, :LPCWSTR, :LPCWSTR, :PSECURITY_DESCRIPTOR, :PSID, :DWORD, :AUDIT_EVENT_TYPE, :DWORD, :POBJECT_TYPE_LIST, :DWORD, :PGENERIC_MAPPING, :BOOL, :LPDWORD, :LPBOOL, :LPBOOL>, 64
    ifdef UNICODE
      AccessCheckByTypeAndAuditAlarm equ <AccessCheckByTypeAndAuditAlarmW>
    endif
    @DefProto DllImport, AccessCheckByTypeResultListAndAuditAlarmW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPVOID, :LPCWSTR, :LPCWSTR, :PSECURITY_DESCRIPTOR, :PSID, :DWORD, :AUDIT_EVENT_TYPE, :DWORD, :POBJECT_TYPE_LIST, :DWORD, :PGENERIC_MAPPING, :BOOL, :LPDWORD, :LPDWORD, :LPBOOL>, 64
    ifdef UNICODE
      AccessCheckByTypeResultListAndAuditAlarm equ <AccessCheckByTypeResultListAndAuditAlarmW>
    endif
    @DefProto DllImport, AccessCheckByTypeResultListAndAuditAlarmByHandleW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPVOID, :HANDLE, :LPCWSTR, :LPCWSTR, :PSECURITY_DESCRIPTOR, :PSID, :DWORD, :AUDIT_EVENT_TYPE, :DWORD, :POBJECT_TYPE_LIST, :DWORD, :PGENERIC_MAPPING, :BOOL, :LPDWORD, :LPDWORD, :LPBOOL>, 68
    ifdef UNICODE
      AccessCheckByTypeResultListAndAuditAlarmByHandle equ <AccessCheckByTypeResultListAndAuditAlarmByHandleW>
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, AddAccessAllowedAce, WIN_STD_CALL_CONV,, <:PACL, :DWORD, :DWORD, :PSID>, 16
    @DefProto DllImport, AddAccessAllowedAceEx, WIN_STD_CALL_CONV,, <:PACL, :DWORD, :DWORD, :DWORD, :PSID>, 20
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, AddAccessAllowedObjectAce, WIN_STD_CALL_CONV,, <:PACL, :DWORD, :DWORD, :DWORD, :ptr GUID, :ptr GUID, :PSID>, 28
    @DefProto DllImport, AddAccessDeniedAce, WIN_STD_CALL_CONV,, <:PACL, :DWORD, :DWORD, :PSID>, 16
    @DefProto DllImport, AddAccessDeniedAceEx, WIN_STD_CALL_CONV,, <:PACL, :DWORD, :DWORD, :DWORD, :PSID>, 20
    @DefProto DllImport, AddAccessDeniedObjectAce, WIN_STD_CALL_CONV,, <:PACL, :DWORD, :DWORD, :DWORD, :ptr GUID, :ptr GUID, :PSID>, 28
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, AddAce, WIN_STD_CALL_CONV,, <:PACL, :DWORD, :DWORD, :LPVOID, :DWORD>, 20
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, AddAuditAccessAce, WIN_STD_CALL_CONV,, <:PACL, :DWORD, :DWORD, :PSID, :BOOL, :BOOL>, 24
    @DefProto DllImport, AddAuditAccessAceEx, WIN_STD_CALL_CONV,, <:PACL, :DWORD, :DWORD, :DWORD, :PSID, :BOOL, :BOOL>, 28
    @DefProto DllImport, AddAuditAccessObjectAce, WIN_STD_CALL_CONV,, <:PACL, :DWORD, :DWORD, :DWORD, :ptr GUID, :ptr GUID, :PSID, :BOOL, :BOOL>, 36
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    if (_WIN32_WINNT ge 0600h)
      @DefProto DllImport, AddMandatoryAce, WIN_STD_CALL_CONV,, <:PACL, :DWORD, :DWORD, :DWORD, :PSID>, 20
    endif
  endif
  if (_WIN32_WINNT ge _WIN32_WINNT_WIN8)
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
      @DefProto DllImport, AddResourceAttributeAce, WIN_STD_CALL_CONV,, <:PACL, :DWORD, :DWORD, :DWORD, :PSID, :PCLAIM_SECURITY_ATTRIBUTES_INFORMATION, :PDWORD>, 28
      @DefProto DllImport, AddScopedPolicyIDAce, WIN_STD_CALL_CONV,, <:PACL, :DWORD, :DWORD, :DWORD, :PSID>, 20
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, AdjustTokenGroups, WIN_STD_CALL_CONV,, <:HANDLE, :BOOL, :PTOKEN_GROUPS, :DWORD, :PTOKEN_GROUPS, :PDWORD>, 24
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, AdjustTokenPrivileges, WIN_STD_CALL_CONV,, <:HANDLE, :BOOL, :PTOKEN_PRIVILEGES, :DWORD, :PTOKEN_PRIVILEGES, :PDWORD>, 24
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, AllocateAndInitializeSid, WIN_STD_CALL_CONV,, <:PSID_IDENTIFIER_AUTHORITY, :BYTE, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :ptr PSID>, 44
    @DefProto DllImport, AllocateLocallyUniqueId, WIN_STD_CALL_CONV,, <:PLUID>, 4
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, AreAllAccessesGranted, WIN_STD_CALL_CONV,, <:DWORD, :DWORD>, 8
    @DefProto DllImport, AreAnyAccessesGranted, WIN_STD_CALL_CONV,, <:DWORD, :DWORD>, 8
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, CheckTokenMembership, WIN_STD_CALL_CONV,, <:HANDLE, :PSID, :PBOOL>, 12
  endif
  if (_WIN32_WINNT ge _WIN32_WINNT_WIN8)
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
      @DefProto DllImport, CheckTokenCapability, WIN_STD_CALL_CONV,, <:HANDLE, :PSID, :PBOOL>, 12
      @DefProto DllImport, GetAppContainerAce, WIN_STD_CALL_CONV,, <:PACL, :DWORD, :ptr PVOID, :ptr DWORD>, 16
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
      @DefProto DllImport, CheckTokenMembershipEx, WIN_STD_CALL_CONV,, <:HANDLE, :PSID, :DWORD, :PBOOL>, 16
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, ConvertToAutoInheritPrivateObjectSecurity, WIN_STD_CALL_CONV,, <:PSECURITY_DESCRIPTOR, :PSECURITY_DESCRIPTOR, :ptr PSECURITY_DESCRIPTOR, :ptr GUID, :BOOLEAN, :PGENERIC_MAPPING>, 24
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, CopySid, WIN_STD_CALL_CONV,, <:DWORD, :PSID, :PSID>, 12
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, CreatePrivateObjectSecurity, WIN_STD_CALL_CONV,, <:PSECURITY_DESCRIPTOR, :PSECURITY_DESCRIPTOR, :ptr PSECURITY_DESCRIPTOR, :BOOL, :HANDLE, :PGENERIC_MAPPING>, 24
    @DefProto DllImport, CreatePrivateObjectSecurityEx, WIN_STD_CALL_CONV,, <:PSECURITY_DESCRIPTOR, :PSECURITY_DESCRIPTOR, :ptr PSECURITY_DESCRIPTOR, :ptr GUID, :BOOL, :ULONG, :HANDLE, :PGENERIC_MAPPING>, 32
    @DefProto DllImport, CreatePrivateObjectSecurityWithMultipleInheritance, WIN_STD_CALL_CONV,, <:PSECURITY_DESCRIPTOR, :PSECURITY_DESCRIPTOR, :ptr PSECURITY_DESCRIPTOR, :ptr ptr GUID, :ULONG, :BOOL, :ULONG, :HANDLE, :PGENERIC_MAPPING>, 36
    @DefProto DllImport, CreateRestrictedToken, WIN_STD_CALL_CONV,, <:HANDLE, :DWORD, :DWORD, :PSID_AND_ATTRIBUTES, :DWORD, :PLUID_AND_ATTRIBUTES, :DWORD, :PSID_AND_ATTRIBUTES, :PHANDLE>, 36
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    if (_WIN32_WINNT ge 0501h)
      @DefProto DllImport, CreateWellKnownSid, WIN_STD_CALL_CONV,, <:WELL_KNOWN_SID_TYPE, :PSID, :PSID, :ptr DWORD>, 16
      @DefProto DllImport, EqualDomainSid, WIN_STD_CALL_CONV,, <:PSID, :PSID, :ptr BOOL>, 12
    endif
    @DefProto DllImport, DeleteAce, WIN_STD_CALL_CONV,, <:PACL, :DWORD>, 8
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, DestroyPrivateObjectSecurity, WIN_STD_CALL_CONV,, <:ptr PSECURITY_DESCRIPTOR>, 4
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, DuplicateToken, WIN_STD_CALL_CONV,, <:HANDLE, :SECURITY_IMPERSONATION_LEVEL, :PHANDLE>, 12
    @DefProto DllImport, DuplicateTokenEx, WIN_STD_CALL_CONV,, <:HANDLE, :DWORD, :LPSECURITY_ATTRIBUTES, :SECURITY_IMPERSONATION_LEVEL, :TOKEN_TYPE, :PHANDLE>, 24
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, EqualPrefixSid, WIN_STD_CALL_CONV,, <:PSID, :PSID>, 8
    @DefProto DllImport, EqualSid, WIN_STD_CALL_CONV,, <:PSID, :PSID>, 8
    @DefProto DllImport, FindFirstFreeAce, WIN_STD_CALL_CONV,, <:PACL, :ptr LPVOID>, 8
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, FreeSid, WIN_STD_CALL_CONV,, <:PSID>, 4
    @DefProto DllImport, GetAce, WIN_STD_CALL_CONV,, <:PACL, :DWORD, :ptr LPVOID>, 12
    @DefProto DllImport, GetAclInformation, WIN_STD_CALL_CONV,, <:PACL, :LPVOID, :DWORD, :ACL_INFORMATION_CLASS>, 16
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, GetFileSecurityW, WIN_STD_CALL_CONV,, <:LPCWSTR, :SECURITY_INFORMATION, :PSECURITY_DESCRIPTOR, :DWORD, :LPDWORD>, 20
    ifdef UNICODE
      GetFileSecurity equ <GetFileSecurityW>
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, GetKernelObjectSecurity, WIN_STD_CALL_CONV,, <:HANDLE, :SECURITY_INFORMATION, :PSECURITY_DESCRIPTOR, :DWORD, :LPDWORD>, 20
    @DefProto DllImport, GetLengthSid, WIN_STD_CALL_CONV,, <:PSID>, 4
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, GetPrivateObjectSecurity, WIN_STD_CALL_CONV,, <:PSECURITY_DESCRIPTOR, :SECURITY_INFORMATION, :PSECURITY_DESCRIPTOR, :DWORD, :PDWORD>, 20
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, GetSecurityDescriptorControl, WIN_STD_CALL_CONV,, <:PSECURITY_DESCRIPTOR, :PSECURITY_DESCRIPTOR_CONTROL, :LPDWORD>, 12
    @DefProto DllImport, GetSecurityDescriptorDacl, WIN_STD_CALL_CONV,, <:PSECURITY_DESCRIPTOR, :LPBOOL, :ptr PACL, :LPBOOL>, 16
    @DefProto DllImport, GetSecurityDescriptorGroup, WIN_STD_CALL_CONV,, <:PSECURITY_DESCRIPTOR, :ptr PSID, :LPBOOL>, 12
    @DefProto DllImport, GetSecurityDescriptorLength, WIN_STD_CALL_CONV,, <:PSECURITY_DESCRIPTOR>, 4
    @DefProto DllImport, GetSecurityDescriptorOwner, WIN_STD_CALL_CONV,, <:PSECURITY_DESCRIPTOR, :ptr PSID, :LPBOOL>, 12
    @DefProto DllImport, GetSecurityDescriptorRMControl, WIN_STD_CALL_CONV,, <:PSECURITY_DESCRIPTOR, :PUCHAR>, 8
    @DefProto DllImport, GetSecurityDescriptorSacl, WIN_STD_CALL_CONV,, <:PSECURITY_DESCRIPTOR, :LPBOOL, :ptr PACL, :LPBOOL>, 16
    @DefProto DllImport, GetSidIdentifierAuthority, WIN_STD_CALL_CONV,, <:PSID>, 4
    @DefProto DllImport, GetSidLengthRequired, WIN_STD_CALL_CONV,, <:UCHAR>, 4
    @DefProto DllImport, GetSidSubAuthority, WIN_STD_CALL_CONV,, <:PSID, :DWORD>, 8
    @DefProto DllImport, GetSidSubAuthorityCount, WIN_STD_CALL_CONV,, <:PSID>, 4
    @DefProto DllImport, GetTokenInformation, WIN_STD_CALL_CONV,, <:HANDLE, :TOKEN_INFORMATION_CLASS, :LPVOID, :DWORD, :PDWORD>, 20
    if (_WIN32_WINNT ge 0501h)
      @DefProto DllImport, GetWindowsAccountDomainSid, WIN_STD_CALL_CONV,, <:PSID, :PSID, :ptr DWORD>, 12
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, ImpersonateAnonymousToken, WIN_STD_CALL_CONV,, <:HANDLE>, 4
    @DefProto DllImport, ImpersonateLoggedOnUser, WIN_STD_CALL_CONV,, <:HANDLE>, 4
    @DefProto DllImport, ImpersonateSelf, WIN_STD_CALL_CONV,, <:SECURITY_IMPERSONATION_LEVEL>, 4
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, InitializeAcl, WIN_STD_CALL_CONV,, <:PACL, :DWORD, :DWORD>, 12
    @DefProto DllImport, InitializeSecurityDescriptor, WIN_STD_CALL_CONV,, <:PSECURITY_DESCRIPTOR, :DWORD>, 8
    @DefProto DllImport, InitializeSid, WIN_STD_CALL_CONV,, <:PSID, :PSID_IDENTIFIER_AUTHORITY, :BYTE>, 12
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, IsTokenRestricted, WIN_STD_CALL_CONV,, <:HANDLE>, 4
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, IsValidAcl, WIN_STD_CALL_CONV,, <:PACL>, 4
    @DefProto DllImport, IsValidSecurityDescriptor, WIN_STD_CALL_CONV,, <:PSECURITY_DESCRIPTOR>, 4
    @DefProto DllImport, IsValidSid, WIN_STD_CALL_CONV,, <:PSID>, 4
    if (_WIN32_WINNT ge 0501h)
      @DefProto DllImport, IsWellKnownSid, WIN_STD_CALL_CONV,, <:PSID, :WELL_KNOWN_SID_TYPE>, 8
    endif
    @DefProto DllImport, MakeAbsoluteSD, WIN_STD_CALL_CONV,, <:PSECURITY_DESCRIPTOR, :PSECURITY_DESCRIPTOR, :LPDWORD, :PACL, :LPDWORD, :PACL, :LPDWORD, :PSID, :LPDWORD, :PSID, :LPDWORD>, 44
    @DefProto DllImport, MakeSelfRelativeSD, WIN_STD_CALL_CONV,, <:PSECURITY_DESCRIPTOR, :PSECURITY_DESCRIPTOR, :LPDWORD>, 12
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, MapGenericMask, WIN_STD_CALL_CONV,, <:PDWORD, :PGENERIC_MAPPING>, 8
    @DefProto DllImport, ObjectCloseAuditAlarmW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPVOID, :BOOL>, 12
    ifdef UNICODE
      ObjectCloseAuditAlarm equ <ObjectCloseAuditAlarmW>
    endif
    @DefProto DllImport, ObjectDeleteAuditAlarmW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPVOID, :BOOL>, 12
    ifdef UNICODE
      ObjectDeleteAuditAlarm equ <ObjectDeleteAuditAlarmW>
    endif
    @DefProto DllImport, ObjectOpenAuditAlarmW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPVOID, :LPWSTR, :LPWSTR, :PSECURITY_DESCRIPTOR, :HANDLE, :DWORD, :DWORD, :PPRIVILEGE_SET, :BOOL, :BOOL, :LPBOOL>, 48
    ifdef UNICODE
      ObjectOpenAuditAlarm equ <ObjectOpenAuditAlarmW>
    endif
    @DefProto DllImport, ObjectPrivilegeAuditAlarmW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPVOID, :HANDLE, :DWORD, :PPRIVILEGE_SET, :BOOL>, 24
    ifdef UNICODE
      ObjectPrivilegeAuditAlarm equ <ObjectPrivilegeAuditAlarmW>
    endif
    @DefProto DllImport, PrivilegeCheck, WIN_STD_CALL_CONV,, <:HANDLE, :PPRIVILEGE_SET, :LPBOOL>, 12
    @DefProto DllImport, PrivilegedServiceAuditAlarmW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR, :HANDLE, :PPRIVILEGE_SET, :BOOL>, 20
    ifdef UNICODE
      PrivilegedServiceAuditAlarm equ <PrivilegedServiceAuditAlarmW>
    endif
    if (_WIN32_WINNT ge 0600h)
      @DefProto DllImport, QuerySecurityAccessMask, WIN_STD_CALL_CONV,, <:SECURITY_INFORMATION, :LPDWORD>, 8
    endif
    @DefProto DllImport, RevertToSelf, WIN_STD_CALL_CONV,, <>, 0
    @DefProto DllImport, SetAclInformation, WIN_STD_CALL_CONV,, <:PACL, :LPVOID, :DWORD, :ACL_INFORMATION_CLASS>, 16
    @DefProto DllImport, SetFileSecurityW, WIN_STD_CALL_CONV,, <:LPCWSTR, :SECURITY_INFORMATION, :PSECURITY_DESCRIPTOR>, 12
    ifdef UNICODE
      SetFileSecurity equ <SetFileSecurityW>
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, SetKernelObjectSecurity, WIN_STD_CALL_CONV,, <:HANDLE, :SECURITY_INFORMATION, :PSECURITY_DESCRIPTOR>, 12
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, SetPrivateObjectSecurity, WIN_STD_CALL_CONV,, <:SECURITY_INFORMATION, :PSECURITY_DESCRIPTOR, :ptr PSECURITY_DESCRIPTOR, :PGENERIC_MAPPING, :HANDLE>, 20
    @DefProto DllImport, SetPrivateObjectSecurityEx, WIN_STD_CALL_CONV,, <:SECURITY_INFORMATION, :PSECURITY_DESCRIPTOR, :ptr PSECURITY_DESCRIPTOR, :ULONG, :PGENERIC_MAPPING, :HANDLE>, 24
    if (_WIN32_WINNT ge 0600h)
      @DefProto DllImport, SetSecurityAccessMask, WIN_STD_CALL_CONV,, <:SECURITY_INFORMATION, :LPDWORD>, 8
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, SetSecurityDescriptorControl, WIN_STD_CALL_CONV,, <:PSECURITY_DESCRIPTOR, :SECURITY_DESCRIPTOR_CONTROL, :SECURITY_DESCRIPTOR_CONTROL>, 12
    @DefProto DllImport, SetSecurityDescriptorDacl, WIN_STD_CALL_CONV,, <:PSECURITY_DESCRIPTOR, :BOOL, :PACL, :BOOL>, 16
    @DefProto DllImport, SetSecurityDescriptorGroup, WIN_STD_CALL_CONV,, <:PSECURITY_DESCRIPTOR, :PSID, :BOOL>, 12
    @DefProto DllImport, SetSecurityDescriptorOwner, WIN_STD_CALL_CONV,, <:PSECURITY_DESCRIPTOR, :PSID, :BOOL>, 12
    @DefProto DllImport, SetSecurityDescriptorRMControl, WIN_STD_CALL_CONV,, <:PSECURITY_DESCRIPTOR, :PUCHAR>, 8
    @DefProto DllImport, SetSecurityDescriptorSacl, WIN_STD_CALL_CONV,, <:PSECURITY_DESCRIPTOR, :BOOL, :PACL, :BOOL>, 16
    @DefProto DllImport, SetTokenInformation, WIN_STD_CALL_CONV,, <:HANDLE, :TOKEN_INFORMATION_CLASS, :LPVOID, :DWORD>, 16
  endif
  if (_WIN32_WINNT ge _WIN32_WINNT_WIN8)
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
      SIGNING_LEVEL_FILE_CACHE_FLAG_NOT_VALIDATED equ 01h
      SIGNING_LEVEL_FILE_CACHE_FLAG_VALIDATE_ONLY equ 04h
      SIGNING_LEVEL_MICROSOFT equ 8
      @DefProto DllImport, SetCachedSigningLevel, WIN_STD_CALL_CONV,, <:PHANDLE, :ULONG, :ULONG, :HANDLE>, 16
      @DefProto DllImport, GetCachedSigningLevel, WIN_STD_CALL_CONV,, <:HANDLE, :PULONG, :PULONG, :PUCHAR, :PULONG, :PULONG>, 24
    endif
  endif
  if (_WIN32_WINNT ge _WIN32_WINNT_WIN10)
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
      @DefProto DllImport, CveEventWrite, WIN_STD_CALL_CONV,, <:PCWSTR, :PCWSTR>, 8
    endif
  endif
  if (_WIN32_WINNT ge _WIN32_WINNT_WIN10)
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
      @DefProto DllImport, DeriveCapabilitySidsFromName, WIN_STD_CALL_CONV,, <:LPCWSTR, :ptr ptr PSID, :ptr DWORD, :ptr ptr PSID, :ptr DWORD>, 20
    endif
  endif
  ifdef __cplusplus
    ;[...]
  endif
endif
