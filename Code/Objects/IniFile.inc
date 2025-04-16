; ==================================================================================================
; Title:      IniFile.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of INI-File objects.
; Links:      - http://msdn.microsoft.com/en-us/library/ms724345(VS.85).aspx
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Object:     IniFile
; Purpose:    This object is a thin wrapper around the GetPrivateProfileXXX and SetPrivateProfileXXX
;             APIs. It stores internaly the ini file name to facilitate subsequent calls.
;             OS remapping to the registry is done using the following registry key:
;             HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows NT\CurrentVersion\IniFileMapping.
; Links:      - Mapping rules and example
;               http://msdn.microsoft.com/en-us/library/ms725501(VS.85).aspx
; Note:       Section and key strings are not case-sensitive.

Object IniFile, IniFileID, Primer
  RedefineMethod    Done
  RedefineMethod    Init,         POINTER, PSTRING
  VirtualMethod     GetDWord,     PSTRING, PSTRING, DWORD
  VirtualMethod     GetString,    PSTRING, PSTRING, PSTRING
  VirtualMethod     GetStruc,     PSTRING, PSTRING, POINTER, DWORD
  VirtualMethod     SetDWord,     PSTRING, PSTRING, DWORD
  VirtualMethod     SetString,    PSTRING, PSTRING, PSTRING
  VirtualMethod     SetStruc,     PSTRING, PSTRING, POINTER, DWORD

  DefineVariable    pFileName,    PSTRING,    NULL
ObjectEnd


; ==================================================================================================

if IMPLEMENT

; --------------------------------------------------------------------------------------------------
; Method:     IniFile.Done
; Purpose:    Finalize the IniFile object and release allocated resources.
; Arguments:  None.
; Return:     Nothing.

Method IniFile.Done
  SetObject xcx
  invoke StrDispose, [xcx].pFileName                    ;Save disposal of the string
  ACall Done                                            ;Ancestor disposal call
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IniFile.Init
; Purpose:    Initialize the IniFile object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: -> File name.
; Return:     eax = Error code.

Method IniFile.Init, uses xbx xsi, pOwner:POINTER, pFileName:PSTRING
  local cBuffer[1024]:CHR

  SetObject xsi
  ACall xsi.Init, pOwner                                ;Ancestor initialization call
  lea xbx, cBuffer
  ;We need to create a full path for the (S)GetPrivateProfileXXX APIs.
  invoke GetFullPathName, pFileName, lengthof cBuffer - 1, xbx, NULL
  .if (eax == 0) || (eax > lengthof cBuffer - 1)
    OCall xsi.ErrorReport, NULL, INI_INIT_ERROR         ;Returns the error code
  .else
    invoke StrNew, xbx                                  ;Create a string containing the full path
    mov [xsi].pFileName, xax                            ;Store it here
    xor eax, eax                                        ;Return OBJ_OK
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IniFile.GetDWord
; Purpose:    Return the specified section/key DWORD.
; Arguments:  Arg1: -> Section name.
;             Arg2: -> Key name.
;             Arg3: Default value.
; Return:     eax = DWORD. If the key was not found, the optional default value is returned.
;             If the default value is not specified, zero is returned.

Method IniFile.GetDWord,, pSection:PSTRING, pKey:PSTRING, dDefault:DWORD
  SetObject xax
  invoke GetPrivateProfileInt, pSection, pKey, dDefault, [xax].pFileName
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IniFile.GetString
; Purpose:    Return the specified section/key string.
; Arguments:  Arg1: -> Section name.
;             Arg2: -> Key name.
;             Arg3: -> default string.
; Return:     xax -> New created string. If the key was not found, xax -> Default string.
;             In all cases the retuned string must be freed by the caller using StrDispose.
; Note:       Maximal string size = 1023 chars + ZTC.

Method IniFile.GetString, uses xsi, pSection:PSTRING, pKey:PSTRING, pDefault:PSTRING
  local cBuffer[1024]:CHR

  SetObject xsi
  lea xax, cBuffer                                      ;xax -> Temporary storage
  invoke GetPrivateProfileString, pSection, pKey, pDefault, xax, lengthof cBuffer, [xsi].pFileName
  lea xax, cBuffer
  invoke StrNew, xax                                    ;xax -> Created return string
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IniFile.GetStruc
; Purpose:    Return the specified section/key structure.
; Arguments:  Arg1: -> Section name.
;             Arg2: -> Key name.
;             Arg3: -> Structure.
;             Arg4: Structure size.
; Return:     eax = Error code.

Method IniFile.GetStruc, uses xsi, pSection:PSTRING, pKey:PSTRING, pStruc:POINTER, dSize:DWORD
  SetObject xsi
  invoke GetPrivateProfileStruct, pSection, pKey, pStruc, dSize, [xsi].pFileName
  .if eax == FALSE
    OCall xsi.ErrorReport, NULL, INI_READ_ERROR         ;Returns this error code
  .else
    xor eax, eax                                        ;OBJ_OK
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IniFile.SetDWord
; Purpose:    Set the specified section/key DWORD.
; Arguments:  Arg1: -> Section name.
;             Arg2: -> Key name.
;             Arg3: dWord.
; Return:     eax = Error code.

Method IniFile.SetDWord, uses xsi, pSection:PSTRING, pKey:PSTRING, dValue:DWORD
  local cBuffer[11]:CHR

  SetObject xsi
  invoke dword2dec, addr cBuffer, dValue
  invoke WritePrivateProfileString, pSection, pKey, addr cBuffer, [xsi].pFileName
  .if eax == FALSE
    OCall xsi.ErrorReport, NULL, INI_WRITE_ERROR        ;Returns this error code
  .else
    xor eax, eax                                        ;OBJ_OK
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IniFile.SetString
; Purpose:    Set the specified section/key string.
; Arguments:  Arg1: -> Section name.
;             Arg2: -> Key name.
;             Arg3: -> String.
; Return:     eax = Error code.

Method IniFile.SetString, uses xsi, pSection:PSTRING, pKey:PSTRING, pStr:PSTRING
  SetObject xsi
  invoke WritePrivateProfileString, pSection, pKey, pStr, [xsi].pFileName
  .if eax == FALSE
    OCall xsi.ErrorReport, NULL, INI_WRITE_ERROR        ;Returns this error code
  .else
    xor eax, eax                                        ;OBJ_OK
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IniFile.SetStruc
; Purpose:    Set the specified section/key string.
; Arguments:  Arg1: -> Section name (ANSI string).
;             Arg2: -> Key name (ANSI string).
;             Arg3: -> Structure.
;             Arg4: Structure size.
; Return:     eax = Error code.

Method IniFile.SetStruc, uses xsi, pSection:PSTRING, pKey:PSTRING, pStruc:POINTER, dSize:DWORD
  SetObject xsi
  invoke WritePrivateProfileStruct, pSection, pKey, pStruc, dSize, [xsi].pFileName
  .if eax == FALSE
    OCall xsi.ErrorReport, NULL, INI_WRITE_ERROR        ;Returns this error code
  .else
    xor eax, eax                                        ;OBJ_OK
  .endif
MethodEnd

endif
