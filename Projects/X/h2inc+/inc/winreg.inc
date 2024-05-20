;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\winreg.h
;             Created on (UTC) 06/04/2024 06:16:03
;             Last modified on (UTC) 21/02/2024 18:13:14

;--*
ifndef _WINREG_
  _WINREG_ equ <>
  include winapifamily.inc
  include apiset.inc
  include apisetcconv.inc
  include minwindef.inc
  include minwinbase.inc
  ifdef _MAC
    ;[...]
  endif
  ifdef __cplusplus
    ;[...]
  endif
  if _MSC_VER ge 1200
    ; padding added after data member
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    ifndef WINVER
      WINVER equ 0500h; version 5.0

      ;* !WINVER *
    endif
  endif
  ; WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    LSTATUS typedef LONG
  endif
  ; WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    ; RRF - Registry Routine Flags (for RegGetValue)
    RRF_RT_REG_NONE equ 00000001h; restrict type to REG_NONE      (other data types will not return ERROR_SUCCESS)

    RRF_RT_REG_SZ equ 00000002h; restrict type to REG_SZ        (other data types will not return ERROR_SUCCESS) (automatically converts REG_EXPAND_SZ to REG_SZ unless RRF_NOEXPAND is specified)

    RRF_RT_REG_EXPAND_SZ equ 00000004h; restrict type to REG_EXPAND_SZ (other data types will not return ERROR_SUCCESS) (must specify RRF_NOEXPAND or RegGetValue will fail with ERROR_INVALID_PARAMETER)

    RRF_RT_REG_BINARY equ 00000008h; restrict type to REG_BINARY    (other data types will not return ERROR_SUCCESS)

    RRF_RT_REG_DWORD equ 00000010h; restrict type to REG_DWORD     (other data types will not return ERROR_SUCCESS)

    RRF_RT_REG_MULTI_SZ equ 00000020h; restrict type to REG_MULTI_SZ  (other data types will not return ERROR_SUCCESS)

    RRF_RT_REG_QWORD equ 00000040h; restrict type to REG_QWORD     (other data types will not return ERROR_SUCCESS)

    RRF_RT_DWORD equ <(RRF_RT_REG_BINARY or RRF_RT_REG_DWORD)>; restrict type to *32-bit* RRF_RT_REG_BINARY or RRF_RT_REG_DWORD (other data types will not return ERROR_SUCCESS)

    RRF_RT_QWORD equ <(RRF_RT_REG_BINARY or RRF_RT_REG_QWORD)>; restrict type to *64-bit* RRF_RT_REG_BINARY or RRF_RT_REG_DWORD (other data types will not return ERROR_SUCCESS)

    RRF_RT_ANY equ 0000ffffh; no type restriction

    if (_WIN32_WINNT ge _WIN32_WINNT_WINTHRESHOLD)
      RRF_SUBKEY_WOW6464KEY equ 00010000h; when opening the subkey (if provided) force open from the 64bit location (only one SUBKEY_WOW64* flag can be set or RegGetValue will fail with ERROR_INVALID_PARAMETER)

      RRF_SUBKEY_WOW6432KEY equ 00020000h; when opening the subkey (if provided) force open from the 32bit location (only one SUBKEY_WOW64* flag can be set or RegGetValue will fail with ERROR_INVALID_PARAMETER)

      RRF_WOW64_MASK equ 00030000h
    endif
    RRF_NOEXPAND equ 10000000h; do not automatically expand environment strings if value is of type REG_EXPAND_SZ

    RRF_ZEROONFAILURE equ 20000000h; if pvData is not NULL, set content to all zeros on failure

    ; Flags for RegLoadAppKey
    REG_PROCESS_APPKEY equ 00000001h
    REG_USE_CURRENT_SECURITY_CONTEXT equ 00000002h
  endif
  ; WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    ; Requested Key access mask type.
    REGSAM typedef ACCESS_MASK
    ; Reserved Key Handles.
    HKEY_CLASSES_ROOT equ ((80000000h))
    HKEY_CURRENT_USER equ ((80000001h))
    HKEY_LOCAL_MACHINE equ ((80000002h))
    HKEY_USERS equ ((80000003h))
    HKEY_PERFORMANCE_DATA equ ((80000004h))
    HKEY_PERFORMANCE_TEXT equ ((80000050h))
    HKEY_PERFORMANCE_NLSTEXT equ ((80000060h))
    if (WINVER ge 0400h)
      HKEY_CURRENT_CONFIG equ ((80000005h))
      HKEY_DYN_DATA equ ((80000006h))
      HKEY_CURRENT_USER_LOCAL_SETTINGS equ ((80000007h))
    endif
    ; WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
      ;*NOINC*
      ifndef _PROVIDER_STRUCTS_DEFINED
        _PROVIDER_STRUCTS_DEFINED equ <>
        PROVIDER_KEEPS_VALUE_LENGTH equ 1h
        val_context struct
          valuelen SDWORD ?
          ; the total length of this value
          value_context POINTER ?
          ; provider's context
          val_buff_ptr POINTER ?
          ; where in the ouput buffer the value is.
        val_context ends
        PVALCONTEXT typedef ptr val_context
        PVALUEA struct
          ; Provider supplied value/context.
          pv_valuename POINTER ?
          ; The value name pointer
          pv_valuelen SDWORD ?
          pv_value_context POINTER ?
          pv_type DWORD ?
        PVALUEA ends
        pvalueA typedef PVALUEA
        PPVALUEA typedef ptr PVALUEA
        PVALUEW struct
          ; Provider supplied value/context.
          pv_valuename POINTER ?
          ; The value name pointer
          pv_valuelen SDWORD ?
          pv_value_context POINTER ?
          pv_type DWORD ?
        PVALUEW ends
        pvalueW typedef PVALUEW
        PPVALUEW typedef ptr PVALUEW
        ifdef UNICODE
          PVALUE typedef PVALUEW
          PPVALUE typedef PPVALUEW
        else
          PVALUE typedef PVALUEA
          PPVALUE typedef PPVALUEA
        endif
        ; UNICODE
        QUERYHANDLER typedef proto :LPVOID, :PVALCONTEXT, :DWORD, :LPVOID, :ptr DWORD, :DWORD
        PQUERYHANDLER typedef ptr QUERYHANDLER
        REG_PROVIDER struct
          pi_R0_1val PQUERYHANDLER ?
          pi_R0_allvals PQUERYHANDLER ?
          pi_R3_1val PQUERYHANDLER ?
          pi_R3_allvals PQUERYHANDLER ?
          pi_flags DWORD ?
          ; capability flags (none defined yet).
          pi_key_context POINTER ?
        REG_PROVIDER ends
        provider_info typedef REG_PROVIDER
        PPROVIDER typedef ptr provider_info
        VALENTA struct
          ve_valuename POINTER ?
          ve_valuelen DWORD ?
          ve_valueptr XWORD ?
          ve_type DWORD ?
        VALENTA ends
        value_entA typedef VALENTA
        PVALENTA typedef ptr VALENTA
        VALENTW struct
          ve_valuename POINTER ?
          ve_valuelen DWORD ?
          ve_valueptr XWORD ?
          ve_type DWORD ?
        VALENTW ends
        value_entW typedef VALENTW
        PVALENTW typedef ptr VALENTW
        ifdef UNICODE
          VALENT typedef VALENTW
          PVALENT typedef PVALENTW
        else
          VALENT typedef VALENTA
          PVALENT typedef PVALENTA
        endif
        ; UNICODE
      endif
      ; not(_PROVIDER_STRUCTS_DEFINED)
      ;*INC*
      ;* WINVER >= 0x0400 *
    endif
    ; Default values for parameters that do not exist in the Win 3.1
    ; compatible APIs.
    WIN31_CLASS equ <NULL>
    ; Flags for RegLoadMUIString
    REG_MUI_STRING_TRUNCATE equ 00000001h
  endif
  ; WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    if (WINVER ge 0400h)
      ; RegConnectRegistryEx supported flags
      REG_SECURE_CONNECTION equ 1
      ;* WINVER >= 0x0400 *
    endif
  endif
  ; WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)
  ; API Prototypes.
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, RegCloseKey, WIN_STD_CALL_CONV,, <:HKEY>, 4
  endif
  ; WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, RegOverridePredefKey, WIN_STD_CALL_CONV,, <:HKEY, :HKEY>, 8
    @DefProto DllImport, RegOpenUserClassesRoot, WIN_STD_CALL_CONV,, <:HANDLE, :DWORD, :REGSAM, :PHKEY>, 16
    @DefProto DllImport, RegOpenCurrentUser, WIN_STD_CALL_CONV,, <:REGSAM, :PHKEY>, 8
    @DefProto DllImport, RegDisablePredefinedCache, WIN_STD_CALL_CONV,, <>, 0
    @DefProto DllImport, RegDisablePredefinedCacheEx, WIN_STD_CALL_CONV,, <>, 0
    @DefProto DllImport, RegConnectRegistryA, WIN_STD_CALL_CONV,, <:LPCSTR, :HKEY, :PHKEY>, 12
    @DefProto DllImport, RegConnectRegistryW, WIN_STD_CALL_CONV,, <:LPCWSTR, :HKEY, :PHKEY>, 12
    ifdef UNICODE
      RegConnectRegistry equ <RegConnectRegistryW>
    else
      RegConnectRegistry equ <RegConnectRegistryA>
    endif
    ; !UNICODE
  endif
  ; WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM)
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, RegConnectRegistryExA, WIN_STD_CALL_CONV,, <:LPCSTR, :HKEY, :ULONG, :PHKEY>, 16
    @DefProto DllImport, RegConnectRegistryExW, WIN_STD_CALL_CONV,, <:LPCWSTR, :HKEY, :ULONG, :PHKEY>, 16
    ifdef UNICODE
      RegConnectRegistryEx equ <RegConnectRegistryExW>
    else
      RegConnectRegistryEx equ <RegConnectRegistryExA>
    endif
    ; !UNICODE
  endif
  ; WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, RegCreateKeyA, WIN_STD_CALL_CONV,, <:HKEY, :LPCSTR, :PHKEY>, 12
    @DefProto DllImport, RegCreateKeyW, WIN_STD_CALL_CONV,, <:HKEY, :LPCWSTR, :PHKEY>, 12
    ifdef UNICODE
      RegCreateKey equ <RegCreateKeyW>
    else
      RegCreateKey equ <RegCreateKeyA>
    endif
    ; !UNICODE
    @DefProto DllImport, RegCreateKeyExA, WIN_STD_CALL_CONV,, <:HKEY, :LPCSTR, :DWORD, :LPSTR, :DWORD, :REGSAM, :LPSECURITY_ATTRIBUTES, :PHKEY, :LPDWORD>, 36
    @DefProto DllImport, RegCreateKeyExW, WIN_STD_CALL_CONV,, <:HKEY, :LPCWSTR, :DWORD, :LPWSTR, :DWORD, :REGSAM, :LPSECURITY_ATTRIBUTES, :PHKEY, :LPDWORD>, 36
    ifdef UNICODE
      RegCreateKeyEx equ <RegCreateKeyExW>
    else
      RegCreateKeyEx equ <RegCreateKeyExA>
    endif
    ; !UNICODE
  endif
  ; WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, RegCreateKeyTransactedA, WIN_STD_CALL_CONV,, <:HKEY, :LPCSTR, :DWORD, :LPSTR, :DWORD, :REGSAM, :LPSECURITY_ATTRIBUTES, :PHKEY, :LPDWORD, :HANDLE, :PVOID>, 44
    @DefProto DllImport, RegCreateKeyTransactedW, WIN_STD_CALL_CONV,, <:HKEY, :LPCWSTR, :DWORD, :LPWSTR, :DWORD, :REGSAM, :LPSECURITY_ATTRIBUTES, :PHKEY, :LPDWORD, :HANDLE, :PVOID>, 44
    ifdef UNICODE
      RegCreateKeyTransacted equ <RegCreateKeyTransactedW>
    else
      RegCreateKeyTransacted equ <RegCreateKeyTransactedA>
    endif
    ; !UNICODE
  endif
  ; WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM)
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, RegDeleteKeyA, WIN_STD_CALL_CONV,, <:HKEY, :LPCSTR>, 8
    @DefProto DllImport, RegDeleteKeyW, WIN_STD_CALL_CONV,, <:HKEY, :LPCWSTR>, 8
    ifdef UNICODE
      RegDeleteKey equ <RegDeleteKeyW>
    else
      RegDeleteKey equ <RegDeleteKeyA>
    endif
    ; !UNICODE
    @DefProto DllImport, RegDeleteKeyExA, WIN_STD_CALL_CONV,, <:HKEY, :LPCSTR, :REGSAM, :DWORD>, 16
    @DefProto DllImport, RegDeleteKeyExW, WIN_STD_CALL_CONV,, <:HKEY, :LPCWSTR, :REGSAM, :DWORD>, 16
    ifdef UNICODE
      RegDeleteKeyEx equ <RegDeleteKeyExW>
    else
      RegDeleteKeyEx equ <RegDeleteKeyExA>
    endif
    ; !UNICODE
  endif
  ; WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, RegDeleteKeyTransactedA, WIN_STD_CALL_CONV,, <:HKEY, :LPCSTR, :REGSAM, :DWORD, :HANDLE, :PVOID>, 24
    @DefProto DllImport, RegDeleteKeyTransactedW, WIN_STD_CALL_CONV,, <:HKEY, :LPCWSTR, :REGSAM, :DWORD, :HANDLE, :PVOID>, 24
    ifdef UNICODE
      RegDeleteKeyTransacted equ <RegDeleteKeyTransactedW>
    else
      RegDeleteKeyTransacted equ <RegDeleteKeyTransactedA>
    endif
    ; !UNICODE
  endif
  ; WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM)
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, RegDisableReflectionKey, WIN_STD_CALL_CONV,, <:HKEY>, 4
    @DefProto DllImport, RegEnableReflectionKey, WIN_STD_CALL_CONV,, <:HKEY>, 4
    @DefProto DllImport, RegQueryReflectionKey, WIN_STD_CALL_CONV,, <:HKEY, :ptr BOOL>, 8
  endif
  ; WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, RegDeleteValueA, WIN_STD_CALL_CONV,, <:HKEY, :LPCSTR>, 8
    @DefProto DllImport, RegDeleteValueW, WIN_STD_CALL_CONV,, <:HKEY, :LPCWSTR>, 8
    ifdef UNICODE
      RegDeleteValue equ <RegDeleteValueW>
    else
      RegDeleteValue equ <RegDeleteValueA>
    endif
    ; !UNICODE
    @DefProto DllImport, RegEnumKeyA, WIN_STD_CALL_CONV,, <:HKEY, :DWORD, :LPSTR, :DWORD>, 16
    @DefProto DllImport, RegEnumKeyW, WIN_STD_CALL_CONV,, <:HKEY, :DWORD, :LPWSTR, :DWORD>, 16
    ifdef UNICODE
      RegEnumKey equ <RegEnumKeyW>
    else
      RegEnumKey equ <RegEnumKeyA>
    endif
    ; !UNICODE
    @DefProto DllImport, RegEnumKeyExA, WIN_STD_CALL_CONV,, <:HKEY, :DWORD, :LPSTR, :LPDWORD, :LPDWORD, :LPSTR, :LPDWORD, :PFILETIME>, 32
    @DefProto DllImport, RegEnumKeyExW, WIN_STD_CALL_CONV,, <:HKEY, :DWORD, :LPWSTR, :LPDWORD, :LPDWORD, :LPWSTR, :LPDWORD, :PFILETIME>, 32
    ifdef UNICODE
      RegEnumKeyEx equ <RegEnumKeyExW>
    else
      RegEnumKeyEx equ <RegEnumKeyExA>
    endif
    ; !UNICODE
    @DefProto DllImport, RegEnumValueA, WIN_STD_CALL_CONV,, <:HKEY, :DWORD, :LPSTR, :LPDWORD, :LPDWORD, :LPDWORD, :LPBYTE, :LPDWORD>, 32
    @DefProto DllImport, RegEnumValueW, WIN_STD_CALL_CONV,, <:HKEY, :DWORD, :LPWSTR, :LPDWORD, :LPDWORD, :LPDWORD, :LPBYTE, :LPDWORD>, 32
    ifdef UNICODE
      RegEnumValue equ <RegEnumValueW>
    else
      RegEnumValue equ <RegEnumValueA>
    endif
    ; !UNICODE
  endif
  ; WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, RegFlushKey, WIN_STD_CALL_CONV,, <:HKEY>, 4
    @DefProto DllImport, RegGetKeySecurity, WIN_STD_CALL_CONV,, <:HKEY, :SECURITY_INFORMATION, :PSECURITY_DESCRIPTOR, :LPDWORD>, 16
    @DefProto DllImport, RegLoadKeyA, WIN_STD_CALL_CONV,, <:HKEY, :LPCSTR, :LPCSTR>, 12
    @DefProto DllImport, RegLoadKeyW, WIN_STD_CALL_CONV,, <:HKEY, :LPCWSTR, :LPCWSTR>, 12
    ifdef UNICODE
      RegLoadKey equ <RegLoadKeyW>
    else
      RegLoadKey equ <RegLoadKeyA>
    endif
    ; !UNICODE
    @DefProto DllImport, RegNotifyChangeKeyValue, WIN_STD_CALL_CONV,, <:HKEY, :BOOL, :DWORD, :HANDLE, :BOOL>, 20
  endif
  ; WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM)
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, RegOpenKeyA, WIN_STD_CALL_CONV,, <:HKEY, :LPCSTR, :PHKEY>, 12
    @DefProto DllImport, RegOpenKeyW, WIN_STD_CALL_CONV,, <:HKEY, :LPCWSTR, :PHKEY>, 12
    ifdef UNICODE
      RegOpenKey equ <RegOpenKeyW>
    else
      RegOpenKey equ <RegOpenKeyA>
    endif
    ; !UNICODE
    @DefProto DllImport, RegOpenKeyExA, WIN_STD_CALL_CONV,, <:HKEY, :LPCSTR, :DWORD, :REGSAM, :PHKEY>, 20
    @DefProto DllImport, RegOpenKeyExW, WIN_STD_CALL_CONV,, <:HKEY, :LPCWSTR, :DWORD, :REGSAM, :PHKEY>, 20
    ifdef UNICODE
      RegOpenKeyEx equ <RegOpenKeyExW>
    else
      RegOpenKeyEx equ <RegOpenKeyExA>
    endif
    ; !UNICODE
  endif
  ; WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, RegOpenKeyTransactedA, WIN_STD_CALL_CONV,, <:HKEY, :LPCSTR, :DWORD, :REGSAM, :PHKEY, :HANDLE, :PVOID>, 28
    @DefProto DllImport, RegOpenKeyTransactedW, WIN_STD_CALL_CONV,, <:HKEY, :LPCWSTR, :DWORD, :REGSAM, :PHKEY, :HANDLE, :PVOID>, 28
    ifdef UNICODE
      RegOpenKeyTransacted equ <RegOpenKeyTransactedW>
    else
      RegOpenKeyTransacted equ <RegOpenKeyTransactedA>
    endif
    ; !UNICODE
  endif
  ; WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM)
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, RegQueryInfoKeyA, WIN_STD_CALL_CONV,, <:HKEY, :LPSTR, :LPDWORD, :LPDWORD, :LPDWORD, :LPDWORD, :LPDWORD, :LPDWORD, :LPDWORD, :LPDWORD, :LPDWORD, :PFILETIME>, 48
    @DefProto DllImport, RegQueryInfoKeyW, WIN_STD_CALL_CONV,, <:HKEY, :LPWSTR, :LPDWORD, :LPDWORD, :LPDWORD, :LPDWORD, :LPDWORD, :LPDWORD, :LPDWORD, :LPDWORD, :LPDWORD, :PFILETIME>, 48
    ifdef UNICODE
      RegQueryInfoKey equ <RegQueryInfoKeyW>
    else
      RegQueryInfoKey equ <RegQueryInfoKeyA>
    endif
    ; !UNICODE
  endif
  ; WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, RegQueryValueA, WIN_STD_CALL_CONV,, <:HKEY, :LPCSTR, :LPSTR, :PLONG>, 16
    @DefProto DllImport, RegQueryValueW, WIN_STD_CALL_CONV,, <:HKEY, :LPCWSTR, :LPWSTR, :PLONG>, 16
    ifdef UNICODE
      RegQueryValue equ <RegQueryValueW>
    else
      RegQueryValue equ <RegQueryValueA>
    endif
    ; !UNICODE
    if (WINVER ge 0400h)
      @DefProto DllImport, RegQueryMultipleValuesA, WIN_STD_CALL_CONV,, <:HKEY, :PVALENTA, :DWORD, :LPSTR, :LPDWORD>, 20
      @DefProto DllImport, RegQueryMultipleValuesW, WIN_STD_CALL_CONV,, <:HKEY, :PVALENTW, :DWORD, :LPWSTR, :LPDWORD>, 20
      ifdef UNICODE
        RegQueryMultipleValues equ <RegQueryMultipleValuesW>
      else
        RegQueryMultipleValues equ <RegQueryMultipleValuesA>
      endif
      ; !UNICODE
      ;* WINVER >= 0x0400 *
    endif
  endif
  ; WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM)
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, RegQueryValueExA, WIN_STD_CALL_CONV,, <:HKEY, :LPCSTR, :LPDWORD, :LPDWORD, :LPBYTE, :LPDWORD>, 24
    @DefProto DllImport, RegQueryValueExW, WIN_STD_CALL_CONV,, <:HKEY, :LPCWSTR, :LPDWORD, :LPDWORD, :LPBYTE, :LPDWORD>, 24
    ifdef UNICODE
      RegQueryValueEx equ <RegQueryValueExW>
    else
      RegQueryValueEx equ <RegQueryValueExA>
    endif
    ; !UNICODE
  endif
  ; WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, RegReplaceKeyA, WIN_STD_CALL_CONV,, <:HKEY, :LPCSTR, :LPCSTR, :LPCSTR>, 16
    @DefProto DllImport, RegReplaceKeyW, WIN_STD_CALL_CONV,, <:HKEY, :LPCWSTR, :LPCWSTR, :LPCWSTR>, 16
    ifdef UNICODE
      RegReplaceKey equ <RegReplaceKeyW>
    else
      RegReplaceKey equ <RegReplaceKeyA>
    endif
    ; !UNICODE
    @DefProto DllImport, RegRestoreKeyA, WIN_STD_CALL_CONV,, <:HKEY, :LPCSTR, :DWORD>, 12
    @DefProto DllImport, RegRestoreKeyW, WIN_STD_CALL_CONV,, <:HKEY, :LPCWSTR, :DWORD>, 12
    ifdef UNICODE
      RegRestoreKey equ <RegRestoreKeyW>
    else
      RegRestoreKey equ <RegRestoreKeyA>
    endif
    ; !UNICODE
  endif
  ; WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM)
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    if (WINVER ge 0600h)
      @DefProto DllImport, RegRenameKey, WIN_STD_CALL_CONV,, <:HKEY, :LPCWSTR, :LPCWSTR>, 12
      ;* WINVER >= 0x0600 *
    endif
  endif
  ; WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, RegSaveKeyA, WIN_STD_CALL_CONV,, <:HKEY, :LPCSTR, :LPSECURITY_ATTRIBUTES>, 12
    @DefProto DllImport, RegSaveKeyW, WIN_STD_CALL_CONV,, <:HKEY, :LPCWSTR, :LPSECURITY_ATTRIBUTES>, 12
    ifdef UNICODE
      RegSaveKey equ <RegSaveKeyW>
    else
      RegSaveKey equ <RegSaveKeyA>
    endif
    ; !UNICODE
    @DefProto DllImport, RegSetKeySecurity, WIN_STD_CALL_CONV,, <:HKEY, :SECURITY_INFORMATION, :PSECURITY_DESCRIPTOR>, 12
    @DefProto DllImport, RegSetValueA, WIN_STD_CALL_CONV,, <:HKEY, :LPCSTR, :DWORD, :LPCSTR, :DWORD>, 20
    @DefProto DllImport, RegSetValueW, WIN_STD_CALL_CONV,, <:HKEY, :LPCWSTR, :DWORD, :LPCWSTR, :DWORD>, 20
    ifdef UNICODE
      RegSetValue equ <RegSetValueW>
    else
      RegSetValue equ <RegSetValueA>
    endif
    ; !UNICODE
  endif
  ; WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM)
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, RegSetValueExA, WIN_STD_CALL_CONV,, <:HKEY, :LPCSTR, :DWORD, :DWORD, :ptr BYTE, :DWORD>, 24
    @DefProto DllImport, RegSetValueExW, WIN_STD_CALL_CONV,, <:HKEY, :LPCWSTR, :DWORD, :DWORD, :ptr BYTE, :DWORD>, 24
    ifdef UNICODE
      RegSetValueEx equ <RegSetValueExW>
    else
      RegSetValueEx equ <RegSetValueExA>
    endif
    ; !UNICODE
  endif
  ; WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, RegUnLoadKeyA, WIN_STD_CALL_CONV,, <:HKEY, :LPCSTR>, 8
    @DefProto DllImport, RegUnLoadKeyW, WIN_STD_CALL_CONV,, <:HKEY, :LPCWSTR>, 8
    ifdef UNICODE
      RegUnLoadKey equ <RegUnLoadKeyW>
    else
      RegUnLoadKey equ <RegUnLoadKeyA>
    endif
    ; !UNICODE
    ; Utils wrappers
    if _WIN32_WINNT ge 0600h
      @DefProto DllImport, RegDeleteKeyValueA, WIN_STD_CALL_CONV,, <:HKEY, :LPCSTR, :LPCSTR>, 12
      @DefProto DllImport, RegDeleteKeyValueW, WIN_STD_CALL_CONV,, <:HKEY, :LPCWSTR, :LPCWSTR>, 12
      ifdef UNICODE
        RegDeleteKeyValue equ <RegDeleteKeyValueW>
      else
        RegDeleteKeyValue equ <RegDeleteKeyValueA>
      endif
      ; !UNICODE
      @DefProto DllImport, RegSetKeyValueA, WIN_STD_CALL_CONV,, <:HKEY, :LPCSTR, :LPCSTR, :DWORD, :LPCVOID, :DWORD>, 24
      @DefProto DllImport, RegSetKeyValueW, WIN_STD_CALL_CONV,, <:HKEY, :LPCWSTR, :LPCWSTR, :DWORD, :LPCVOID, :DWORD>, 24
      ifdef UNICODE
        RegSetKeyValue equ <RegSetKeyValueW>
      else
        RegSetKeyValue equ <RegSetKeyValueA>
      endif
      ; !UNICODE
      @DefProto DllImport, RegDeleteTreeA, WIN_STD_CALL_CONV,, <:HKEY, :LPCSTR>, 8
      @DefProto DllImport, RegDeleteTreeW, WIN_STD_CALL_CONV,, <:HKEY, :LPCWSTR>, 8
      ifdef UNICODE
        RegDeleteTree equ <RegDeleteTreeW>
      else
        RegDeleteTree equ <RegDeleteTreeA>
      endif
      ; !UNICODE
      @DefProto DllImport, RegCopyTreeA, WIN_STD_CALL_CONV,, <:HKEY, :LPCSTR, :HKEY>, 12
      ifndef UNICODE
        RegCopyTree equ <RegCopyTreeA>
      endif
      ; !UNICODE
    endif
    ; _WIN32_WINNT >= 0x0600
    if (_WIN32_WINNT ge 0502h)
      @DefProto DllImport, RegGetValueA, WIN_STD_CALL_CONV,, <:HKEY, :LPCSTR, :LPCSTR, :DWORD, :LPDWORD, :PVOID, :LPDWORD>, 28
      @DefProto DllImport, RegGetValueW, WIN_STD_CALL_CONV,, <:HKEY, :LPCWSTR, :LPCWSTR, :DWORD, :LPDWORD, :PVOID, :LPDWORD>, 28
      ifdef UNICODE
        RegGetValue equ <RegGetValueW>
      else
        RegGetValue equ <RegGetValueA>
      endif
      ; !UNICODE
    endif
    ; (_WIN32_WINNT >= 0x0502)
    if (_WIN32_WINNT ge 0600h)
      @DefProto DllImport, RegCopyTreeW, WIN_STD_CALL_CONV,, <:HKEY, :LPCWSTR, :HKEY>, 12
      ifdef UNICODE
        RegCopyTree equ <RegCopyTreeW>
      endif
      @DefProto DllImport, RegLoadMUIStringA, WIN_STD_CALL_CONV,, <:HKEY, :LPCSTR, :LPSTR, :DWORD, :LPDWORD, :DWORD, :LPCSTR>, 28
      @DefProto DllImport, RegLoadMUIStringW, WIN_STD_CALL_CONV,, <:HKEY, :LPCWSTR, :LPWSTR, :DWORD, :LPDWORD, :DWORD, :LPCWSTR>, 28
      ifdef UNICODE
        RegLoadMUIString equ <RegLoadMUIStringW>
      else
        RegLoadMUIString equ <RegLoadMUIStringA>
      endif
      ; !UNICODE
      @DefProto DllImport, RegLoadAppKeyA, WIN_STD_CALL_CONV,, <:LPCSTR, :PHKEY, :REGSAM, :DWORD, :DWORD>, 20
      @DefProto DllImport, RegLoadAppKeyW, WIN_STD_CALL_CONV,, <:LPCWSTR, :PHKEY, :REGSAM, :DWORD, :DWORD>, 20
      ifdef UNICODE
        RegLoadAppKey equ <RegLoadAppKeyW>
      else
        RegLoadAppKey equ <RegLoadAppKeyA>
      endif
      ; !UNICODE
    endif
    ; _WIN32_WINNT >= 0x0600
  endif
  ; WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM)
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    ; Remoteable System Shutdown APIs
    @DefProto DllImport, InitiateSystemShutdownA, WIN_STD_CALL_CONV,, <:LPSTR, :LPSTR, :DWORD, :BOOL, :BOOL>, 20
    @DefProto DllImport, InitiateSystemShutdownW, WIN_STD_CALL_CONV,, <:LPWSTR, :LPWSTR, :DWORD, :BOOL, :BOOL>, 20
    ifdef UNICODE
      InitiateSystemShutdown equ <InitiateSystemShutdownW>
    else
      InitiateSystemShutdown equ <InitiateSystemShutdownA>
    endif
    ; !UNICODE
    @DefProto DllImport, AbortSystemShutdownA, WIN_STD_CALL_CONV,, <:LPSTR>, 4
    @DefProto DllImport, AbortSystemShutdownW, WIN_STD_CALL_CONV,, <:LPWSTR>, 4
    ifdef UNICODE
      AbortSystemShutdown equ <AbortSystemShutdownW>
    else
      AbortSystemShutdown equ <AbortSystemShutdownA>
    endif
    ; !UNICODE
    ; defines for InitiateSystemShutdownEx reason codes
    include reason.inc
    ; get the public reasons
    ; Then for Historical reasons support some old symbols, internal only
    REASON_SWINSTALL equ <(SHTDN_REASON_MAJOR_SOFTWARE or SHTDN_REASON_MINOR_INSTALLATION)>
    REASON_HWINSTALL equ <(SHTDN_REASON_MAJOR_HARDWARE or SHTDN_REASON_MINOR_INSTALLATION)>
    REASON_SERVICEHANG equ <(SHTDN_REASON_MAJOR_SOFTWARE or SHTDN_REASON_MINOR_HUNG)>
    REASON_UNSTABLE equ <(SHTDN_REASON_MAJOR_SYSTEM or SHTDN_REASON_MINOR_UNSTABLE)>
    REASON_SWHWRECONF equ <(SHTDN_REASON_MAJOR_SOFTWARE or SHTDN_REASON_MINOR_RECONFIG)>
    REASON_OTHER equ <(SHTDN_REASON_MAJOR_OTHER or SHTDN_REASON_MINOR_OTHER)>
    REASON_UNKNOWN equ <SHTDN_REASON_UNKNOWN>
    REASON_LEGACY_API equ <SHTDN_REASON_LEGACY_API>
    REASON_PLANNED_FLAG equ <SHTDN_REASON_FLAG_PLANNED>
    ; MAX Shutdown TimeOut == 10 Years in seconds
    MAX_SHUTDOWN_TIMEOUT equ (10 * 365 * 24 * 60 * 60)
    @DefProto DllImport, InitiateSystemShutdownExA, WIN_STD_CALL_CONV,, <:LPSTR, :LPSTR, :DWORD, :BOOL, :BOOL, :DWORD>, 24
    @DefProto DllImport, InitiateSystemShutdownExW, WIN_STD_CALL_CONV,, <:LPWSTR, :LPWSTR, :DWORD, :BOOL, :BOOL, :DWORD>, 24
    ifdef UNICODE
      InitiateSystemShutdownEx equ <InitiateSystemShutdownExW>
    else
      InitiateSystemShutdownEx equ <InitiateSystemShutdownExA>
    endif
    ; !UNICODE
    ; Shutdown flags
    SHUTDOWN_FORCE_OTHERS equ 00000001h
    SHUTDOWN_FORCE_SELF equ 00000002h
    SHUTDOWN_RESTART equ 00000004h
    SHUTDOWN_POWEROFF equ 00000008h
    SHUTDOWN_NOREBOOT equ 00000010h
    SHUTDOWN_GRACE_OVERRIDE equ 00000020h
    SHUTDOWN_INSTALL_UPDATES equ 00000040h
    SHUTDOWN_RESTARTAPPS equ 00000080h
    SHUTDOWN_SKIP_SVC_PRESHUTDOWN equ 00000100h
    SHUTDOWN_HYBRID equ 00000200h
    SHUTDOWN_RESTART_BOOTOPTIONS equ 00000400h
    SHUTDOWN_SOFT_REBOOT equ 00000800h
    SHUTDOWN_MOBILE_UI equ 00001000h
    SHUTDOWN_ARSO equ 00002000h
    SHUTDOWN_CHECK_SAFE_FOR_SERVER equ 00004000h
    SHUTDOWN_VAIL_CONTAINER equ 00008000h
    SHUTDOWN_SYSTEM_INITIATED equ 00010000h
    @DefProto DllImport, InitiateShutdownA, WIN_STD_CALL_CONV,, <:LPSTR, :LPSTR, :DWORD, :DWORD, :DWORD>, 20
    @DefProto DllImport, InitiateShutdownW, WIN_STD_CALL_CONV,, <:LPWSTR, :LPWSTR, :DWORD, :DWORD, :DWORD>, 20
    ifdef UNICODE
      InitiateShutdown equ <InitiateShutdownW>
    else
      InitiateShutdown equ <InitiateShutdownA>
    endif
    ; !UNICODE
    @DefProto DllImport, CheckForHiberboot, WIN_STD_CALL_CONV,, <:PBOOLEAN, :BOOLEAN>, 8
  endif
  ; WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, RegSaveKeyExA, WIN_STD_CALL_CONV,, <:HKEY, :LPCSTR, :LPSECURITY_ATTRIBUTES, :DWORD>, 16
    @DefProto DllImport, RegSaveKeyExW, WIN_STD_CALL_CONV,, <:HKEY, :LPCWSTR, :LPSECURITY_ATTRIBUTES, :DWORD>, 16
    ifdef UNICODE
      RegSaveKeyEx equ <RegSaveKeyExW>
    else
      RegSaveKeyEx equ <RegSaveKeyExA>
    endif
    ; !UNICODE
  endif
  ; WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM)
  if _MSC_VER ge 1200
  endif
  ifdef __cplusplus
    ;[...]
  endif
endif
; _WINREG_
