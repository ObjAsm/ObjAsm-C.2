; ==================================================================================================
; Title:      RegKey.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of registry keys objects.
; Notes:      Must include Advapi32.inc and includelib Advapi32.lib
;             Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


;HKEY_CLASSES_ROOT              equ     80000000h
;HKEY_CURRENT_USER              equ     80000001h
;HKEY_LOCAL_MACHINE             equ     80000002h
;HKEY_PERFORMANCE_DATA          equ     80000003h
;HKEY_CURRENT_CONFIG            equ     80000004h
;HKEY_DYN_DATA                  equ     80000005h

;REG_NONE                       equ     0
;REG_SZ                         equ     1
;REG_EXPAND_SZ                  equ     2
;REG_BINARY                     equ     3
;REG_DWORD                      equ     4
;REG_DWORD_LITTLE_ENDIAN        equ     4
;REG_DWORD_BIG_ENDIAN           equ     5
;REG_LINK                       equ     6
;REG_MULTI_SZ                   equ     7
;REG_RESOURCE_LIST              equ     8
;REG_FULL_RESOURCE_DESCRIPTOR   equ     9
;REG_RESOURCE_REQUIREMENTS_LIST equ     10
;REG_QWORD                      equ     11
;REG_QWORD_LITTLE_ENDIAN        equ     11

;STANDARD_RIGHTS_READ           equ     00020000h
;STANDARD_RIGHTS_WRITE          equ     00020000h
;KEY_QUERY_VALUE                equ     0001h
;KEY_SET_VALUE                  equ     0002h
;KEY_CREATE_SUB_KEY             equ     0004h
;KEY_ENUMERATE_SUB_KEYS         equ     0008h
;KEY_NOTIFY                     equ     0010h
;KEY_CREATE_LINK                equ     0020h
;KEY_READ                       equ     STANDARD_RIGHTS_READ or KEY_QUERY_VALUE or \
;                                       KEY_ENUMERATE_SUB_KEYS or KEY_NOTIFY
;KEY_WRITE                      equ     STANDARD_RIGHTS_WRITE or KEY_SET_VALUE or \
;                                       KEY_CREATE_SUB_KEY
;KEY_EXECUTE                    equ     KEY_READ
;KEY_ALL_ACCESS                 equ     KEY_READ or KEY_WRITE or KEY_CREATE_LINK

;REG_OPTION_RESERVED            equ     0000h
;REG_OPTION_NON_VOLATILE        equ     0000h
;REG_OPTION_VOLATILE            equ     0001h
;REG_OPTION_CREATE_LINK         equ     0002h
;REG_OPTION_BACKUP_RESTORE      equ     0004h
;REG_OPTION_OPEN_LINK           equ     0008h
;REG_LEGAL_OPTION               equ     REG_OPTION_RESERVED or REG_OPTION_NON_VOLATILE or \
;                                       REG_OPTION_CREATE_LINK or \
;                                       REG_OPTION_BACKUP_RESTORE or REG_OPTION_OPEN_LINK

;REG_CREATED_NEW_KEY            equ     1
;REG_OPENED_EXISTING_KEY        equ     2

;REG_WHOLE_HIVE_VOLATILE        equ     0001h
;REG_REFRESH_HIVE               equ     0002h
;REG_NO_LAZY_FLUSH              equ     0004h
;REG_FORCE_RESTORE              equ     0008h

MAX_KEY_LENGTH                  equ     514
MAX_VALUE_LENGTH                equ     32768

EnumerateProc  typedef proto :POINTER

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:   RegKey
; Purpose:  Implement a thin wrapper around Windows registry keys.

Object RegKey, RegKeyID, Primer
  VirtualMethod     Create
  VirtualMethod     Close
  VirtualMethod     Delete
  RedefineMethod    Done
  VirtualMethod     EnumerateSubKeys,   POINTER
  VirtualMethod     EnumerateValues,    POINTER
  VirtualMethod     FileExport,         PSTRING
  VirtualMethod     FileImport,         PSTRING, PSTRING
  RedefineMethod    Init,               POINTER, PSTRING, HKEY
  VirtualMethod     Open
  VirtualMethod     ValueDelete,        PSTRING
  VirtualMethod     ValueGetDW,         PSTRING
  VirtualMethod     ValueGetData,       PSTRING, POINTER, DWORD
  VirtualMethod     ValueGetStr,        PSTRING, POINTER, DWORD
  VirtualMethod     ValueGetQW,         PSTRING
  VirtualMethod     ValueSetDW,         PSTRING, DWORD
  VirtualMethod     ValueSetData,       PSTRING, POINTER, DWORD
  VirtualMethod     ValueSetStrA,       PSTRINGA, PSTRINGA
  VirtualMethod     ValueSetStrW,       PSTRINGW, PSTRINGW
  VirtualMethod     ValueSetQW,         PSTRING, QWORD

  DefineVariable    dErrorCodeEx,       DWORD,        0
  DefineVariable    hKey,               HKEY,         0
  DefineVariable    hParentKey,         HKEY,         0
  DefineVariable    cKeyName,           CHR,          MAX_KEY_LENGTH dup(0)
ObjectEnd

if TARGET_STR_TYPE eq STR_TYPE_ANSI
  $ObjMthd(ValueSetStr) textequ $ObjMthd(ValueSetStrA)
else
  $ObjMthd(ValueSetStr) textequ $ObjMthd(ValueSetStrW)
endif

$ObjMthd(ValueGetStrA)  textequ $ObjMthd(ValueGetStr)
$ObjMthd(ValueGetStrW)  textequ $ObjMthd(ValueGetStr)


; ==================================================================================================

if IMPLEMENT

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     RegKey.Create
; Purpose:    Create a new or open an existing registry key.
; Arguments:  None.
; Return:     eax = Disposition value: REG_CREATED_NEW_KEY (1) or REG_OPENED_EXISTING_KEY (2).

Method RegKey.Create, uses xsi
  local Dispo:DWORD

  SetObject xsi
  invoke RegCreateKeyEx, [xsi].hParentKey, addr [xsi].cKeyName, NULL, NULL, \
           REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, NULL, addr [xsi].hKey, addr Dispo
  .if eax != ERROR_SUCCESS
    mov [xsi].dErrorCodeEx, eax
    OCall xsi.ErrorReport, NULL, RKY_CREATE_FAILED
  .endif
  mov eax, Dispo
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     RegKey.Close
; Purpose:    Close a registry key.
; Arguments:  None.
; Return:     eax = Error code.

Method RegKey.Close, uses xsi
  SetObject xsi
  .if [xsi].hKey != 0
    invoke RegCloseKey, [xsi].hKey
    .if eax == ERROR_SUCCESS
      m2z [xsi].hKey
    .else
      mov [xsi].dErrorCodeEx, eax
      OCall xsi.ErrorReport, NULL, RKY_CLOSE_FAILED
    .endif
  .else
    xor eax, eax
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     RegKey.Delete
; Purpose:    Delete an key from the registry. The key must be close!
; Arguments:  None.
; Return:     eax = Error code.

Method RegKey.Delete, uses xsi
  SetObject xsi
  invoke RegDeleteKey, [xsi].hParentKey, addr [xsi].cKeyName
  .if eax != ERROR_SUCCESS
    mov [xsi].dErrorCodeEx, eax
    OCall xsi.ErrorReport, NULL, RKY_DELETE_KEY_FAILED
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     RegKey.Done
; Purpose:    Finalize the RegKey object.
; Arguments:  None.
; Return:     Nothing.

Method RegKey.Done
  OCall Close
  ACall Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     RegKey.EnumerateSubKeys
; Purpose:    Enumerate all subkeys of the opened RegKey.
; Arguments:  Arg1: -> Handler procedure.
; Return:     Nothing.

Method RegKey.EnumerateSubKeys, uses xbx xsi, pProc:POINTER
  local dSubKeys:DWORD, dMaxSubKeyLen:DWORD

  .if pProc != NULL
    SetObject xsi
    invoke RegQueryInfoKey, [xsi].hKey, NULL, NULL, NULL, \
           addr dSubKeys, addr dMaxSubKeyLen, NULL, NULL, NULL, NULL, NULL, NULL
    mov xbx, $MemAlloc(dMaxSubKeyLen)
    .while dSubKeys > 0
      dec dSubKeys
      invoke RegEnumKey, [xsi].hKey, dSubKeys, xbx, dMaxSubKeyLen
      invoke EnumerateProc ptr pProc, xbx
    .endw
    MemFree xbx
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     RegKey.EnumerateValues
; Purpose:    Enumerate all values contained in the opened RegKey.
; Arguments:  Arg1: -> Handler procedure.
; Return:     Nothing.

Method RegKey.EnumerateValues, uses xbx xsi, pProc:POINTER
  local dEntries:DWORD, dMaxEntriesNameLen:DWORD, dMaxEntriesValueLen:DWORD

  .if pProc != NULL
    SetObject xsi
    invoke RegQueryInfoKey, [xsi].hKey, NULL, NULL, NULL, NULL, NULL, NULL, \
           addr dEntries, addr dMaxEntriesNameLen, addr dMaxEntriesValueLen, NULL, NULL
    mov xbx, $MemAlloc(dMaxEntriesNameLen)
    .while dEntries > 0
      dec dEntries
      invoke RegEnumKey, [xsi].hKey, dEntries, xbx, dMaxEntriesNameLen
      invoke EnumerateProc ptr pProc, xbx
    .endw
    MemFree xbx
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     RegKey.FileExport
; Purpose:    Export a registry key and all subkeys to a file.
; Arguments:  Arg1: -> File name.
; Return:     eax = Error code.

Method RegKey.FileExport, uses xsi, pFileName:PSTRING
  SetObject xsi
  invoke RegSaveKey, [xsi].hKey, pFileName, NULL
  .if eax != ERROR_SUCCESS
    mov [xsi].dErrorCodeEx, eax
    OCall xsi::RegKey.ErrorReport, NULL, RKY_EXPORT_FAILED
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     RegKey.FileImport
; Purpose:    Import a registry key and all subkeys from a file.
; Arguments:  Arg1: -> Key name.
;             Arg2: -> File name.
; Return:     eax = Error code.

Method RegKey.FileImport, uses xsi, pKeyName:PSTRING, pFileName:PSTRING
;  local pBuffer:POINTER

  SetObject xsi
  invoke RegLoadKey, [xsi].hKey, pKeyName, pFileName
  .if eax != ERROR_SUCCESS
;    mov ecx, eax
;    invoke FormatMessage, FORMAT_MESSAGE_FROM_SYSTEM or FORMAT_MESSAGE_ALLOCATE_BUFFER, \
;           NULL, ecx, 0, addr pBuffer, 0, 0
;    DbgStr pBuffer
;    MemFree pBuffer
    mov [xsi].dErrorCodeEx, eax
    OCall xsi.ErrorReport, NULL, RKY_IMPORT_FAILED
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     RegKey.Init
; Purpose:    Initialize the RegKey object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: -> Key name.
;             Arg3: HANDLE of an open key or any of the following predefined reserved handle
;                   values: HKEY_CLASSES_ROOT, HKEY_CURRENT_USER, HKEY_LOCAL_MACHINE, HKEY_USERS.
; Return:     Nothing.

Method RegKey.Init, uses xsi, pOwner:POINTER, pKeyName:PSTRING, hParentKey:HKEY
  SetObject xsi
  ACall xsi.Init, pOwner
  m2m [xsi].hParentKey, hParentKey, xax
  invoke StrCCopy, addr [xsi].cKeyName, pKeyName, MAX_KEY_LENGTH - 1
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     RegKey.Open
; Purpose:    Open an existing registry key.
; Arguments:  None.
; Return:     eax = Error code.

Method RegKey.Open, uses xsi
  SetObject xsi
  invoke RegOpenKeyEx, [xsi].hParentKey, addr [xsi].cKeyName, 0, KEY_ALL_ACCESS, addr [xsi].hKey
  .if eax != ERROR_SUCCESS
    mov [xsi].dErrorCodeEx, eax
    OCall xsi::RegKey.ErrorReport, NULL, RKY_OPEN_FAILED
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     RegKey.ValueDelete
; Purpose:    Delete a value from a registry Key. The key must be open!
; Arguments:  Arg1: -> Value name string.
; Return:     eax = Error code.

Method RegKey.ValueDelete, uses xsi, pValueName:PSTRING
  SetObject xsi
  invoke RegDeleteValue, [xsi].hKey, pValueName
  .if eax != ERROR_SUCCESS
    mov [xsi].dErrorCodeEx, eax
    OCall xsi::RegKey.ErrorReport, NULL, RKY_DELETE_VAL_FAILED
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     RegKey.ValueGetDW
; Purpose:    Read a DWORD from registry key value.
; Arguments:  Arg1: -> Value name string.
; Return:     eax = Requested DWORD.

Method RegKey.ValueGetDW, uses xsi, pValueName:PSTRING
  local dValueType:DWORD, dValueSize:DWORD, dRetValue:DWORD

  SetObject xsi
  mov dValueSize, sizeof(DWORD)
  invoke RegQueryValueEx, [xsi].hKey, pValueName, NULL, addr dValueType, \
                          addr dRetValue, addr dValueSize
  .if eax != ERROR_SUCCESS
    mov [xsi].dErrorCodeEx, eax
    OCall xsi.ErrorReport, NULL, RKY_GET_DW_FAILED
  .endif
  mov eax, dRetValue
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     RegKey.ValueGetData
; Purpose:    Read binary data in any form from registry key value.
; Arguments:  Arg1: -> Data name string.
;             Arg2: -> Buffer to hold the data. This pointer can be NULL to request
;                   the data size to allocate an appropiate buffer.
;             Arg2: Size of the buffer.
; Return:     eax = Lenght of returned data.

Method RegKey.ValueGetData, uses xsi, pValueName:PSTRING, pData:POINTER, dDataSize:DWORD
  local dValueType:DWORD

  SetObject xsi
  invoke RegQueryValueEx, [xsi].hKey, pValueName, NULL, addr dValueType, pData, addr dDataSize
  .if eax != ERROR_SUCCESS
    mov [xsi].dErrorCodeEx, eax
    OCall xsi.ErrorReport, NULL, RKY_GET_DATA_FAILED
  .endif
  mov eax, dDataSize
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     RegKey.ValueGetStr
; Purpose:    Read a string from registry key value.
; Arguments:  Arg1: -> String name string.
;             Arg2: -> Buffer to store the string. This pointer can be NULL to request
;                   the string length to allocate an appropiate buffer.
;             Arg3: Size of the buffer.
; Return:     eax = Size of returned string.

Method RegKey.ValueGetStr, uses xsi, pValueName:PSTRING, pBuffer:POINTER, dBufSize:DWORD
  local dValueType:DWORD

  SetObject xsi
  invoke RegQueryValueEx, [xsi].hKey, pValueName, NULL, addr dValueType, pBuffer, addr dBufSize
  .if eax != ERROR_SUCCESS
    mov [xsi].dErrorCodeEx, eax
    OCall xsi.ErrorReport, NULL, RKY_GET_STR_FAILED
  .endif
  mov eax, dBufSize
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     RegKey.ValueGetQW
; Purpose:    Read a QWORD from registry key value.
; Arguments:  Arg1: -> Value name string.
; Return:     rax/edx:eax = Requested QWORD.

Method RegKey.ValueGetQW, uses xsi, pValueName:PSTRING
  local dValueType:DWORD, dValueSize:DWORD, qRetValue:QWORD

  SetObject xsi
  mov dValueSize, sizeof(QWORD)
  invoke RegQueryValueEx, [xsi].hKey, pValueName, NULL, addr dValueType, \
                          addr qRetValue, addr dValueSize
  .if eax != ERROR_SUCCESS
    mov [xsi].dErrorCodeEx, eax
    OCall xsi.ErrorReport, NULL, RKY_GET_QW_FAILED
  .endif
  if TARGET_BITNESS eq 32
    mov eax, DWORD ptr [qRetValue]
    mov edx, DWORD ptr [qRetValue + sizeof(DWORD)]
  else
    mov rax, qRetValue
  endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     RegKey.ValueSetDW
; Purpose:    Write a DWORD to the registry key value.
; Arguments:  Arg1: -> Value name string.
;             Arg2: 32 bit value to set.
; Return:     eax = Error code.

Method RegKey.ValueSetDW, uses xsi, pValueName:PSTRING, dValue:DWORD
  SetObject xsi
  invoke RegSetValueEx, [xsi].hKey, pValueName, NULL, REG_DWORD, addr dValue, sizeof(dValue)
  .if eax != ERROR_SUCCESS
    mov [xsi].dErrorCodeEx, eax
    OCall xsi.ErrorReport, NULL, RKY_SET_DW_FAILED
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     RegKey.ValueSetData
; Purpose:    Write binary data in any form to the registry key value.
; Arguments:  Arg1: -> Data name string.
;             Arg2: -> Data.
;             Arg3: Data size.
; Return:     eax = Error code.

Method RegKey.ValueSetData, uses xsi, pValueName:PSTRING, pData:POINTER, dDataSize:DWORD
  SetObject xsi
  invoke RegSetValueEx, [xsi].hKey, pValueName, NULL, REG_BINARY, pData, dDataSize
  .if eax != ERROR_SUCCESS
    mov [xsi].dErrorCodeEx, eax
    OCall xsi.ErrorReport, NULL, RKY_SET_DATA_FAILED
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     RegKey.ValueSetStrA
; Purpose:    Write an ANSI string to the registry key value.
; Arguments:  Arg1: -> ANSI String name string.
;             Arg2: -> ANSI String.
; Return:     eax = Error code.

Method RegKey.ValueSetStrA, uses xsi, pStrNameA:PSTRINGA, pStrA:PSTRINGA
  local dStrSize:DWORD

  SetObject xsi
  invoke StrSizeA, pStrA
  mov dStrSize, eax
  invoke RegSetValueEx, [xsi].hKey, pStrNameA, NULL, REG_SZ, pStrA, dStrSize
  .if eax != ERROR_SUCCESS
    mov [xsi].dErrorCodeEx, eax
    OCall xsi.ErrorReport, NULL, RKY_SET_STR_FAILED
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     RegKey.ValueSetStrW
; Purpose:    Write a string to the registry key value.
; Arguments:  Arg1: -> String name string.
;             Arg2: -> WIDE String.
; Return:     eax = Error code.

Method RegKey.ValueSetStrW, uses xsi, pStrNameW:PSTRINGW, pStrW:PSTRINGW
  local dStrSize:DWORD

  SetObject xsi
  invoke StrSizeW, pStrW
  mov dStrSize, eax
  invoke RegSetValueEx, [xsi].hKey, pStrNameW, NULL, REG_SZ, pStrW, dStrSize
  .if eax != ERROR_SUCCESS
    mov [xsi].dErrorCodeEx, eax
    OCall xsi.ErrorReport, NULL, RKY_SET_STR_FAILED
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     RegKey.ValueSetQW
; Purpose:    Write a QWORD to the registry key value.
; Arguments:  Arg1: -> Value name string.
;             Arg2: 64 bit value.
; Return:     eax = Error code.

Method RegKey.ValueSetQW, uses xsi, pValueName:PSTRING, qValue:QWORD
  SetObject xsi
  invoke RegSetValueEx, [xsi].hKey, pValueName, NULL, REG_QWORD, addr qValue, sizeof(qValue)
  .if eax != ERROR_SUCCESS
    mov [xsi].dErrorCodeEx, eax
    OCall xsi.ErrorReport, NULL, RKY_SET_QW_FAILED
  .endif
MethodEnd

endif
