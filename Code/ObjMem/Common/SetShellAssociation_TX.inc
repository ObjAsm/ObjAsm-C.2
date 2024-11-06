; ==================================================================================================
; Title:      SetShellAssociation_TX.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017.
;               - First release.
;               - Character and bitness neutral code.
; Links:      https://docs.microsoft.com/en-us/windows/desktop/shell/fa-sample-scenarios
;             https://docs.microsoft.com/en-us/previous-versions/windows/desktop/legacy/cc144156(v=vs.85)
;             https://docs.microsoft.com/de-ch/windows/desktop/shell/fa-intro
;             https://docs.microsoft.com/de-ch/windows/desktop/shell/fa-how-work
;             https://stackoverflow.com/questions/1387769/create-registry-entry-to-associate-file-extension-with-application-in-c
; ==================================================================================================


% include &IncPath&Windows\shlwapi.inc
% include &IncPath&Windows\shlobj_core.inc

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  SetShellAssociationA / SetShellAssociationW
; Purpose:    Set association for a file extension.
; Arguments:  Arg1: TRUE = system wide association, FALSE = user account only.
;             Arg2: -> File extension (without dot).
;             Arg3: -> Verb ("open", "print", "play", "edit", etc.). This verb is displayed
;                   in the explorer context menu of a file with this extension.
;             Arg4: -> Application to associate with (full path).
;             Arg5: -> Application arguments, usually $OfsCStr("%1").
; Return:     eax = HRESULT.
; Note:       dGlobal = TRUE requires adminitrative rights.

.code
align ALIGN_CODE
ProcName proc uses xbx dGlobal:DWORD, pExtension:POINTER, pVerb:POINTER, pApplication:POINTER, \
                       pArguments:POINTER
  local hHive:HANDLE, hClassesKey:HANDLE, hKey:HANDLE, dResult:DWORD
  local cBuffer[2*MAX_PATH]:CHR, cProgID[2*MAX_PATH]:CHR

  .if dGlobal != FALSE
    mov hHive, HKEY_LOCAL_MACHINE
  .else
    ;HKCR settings take precedence over HKLM settings
    mov hHive, HKEY_CURRENT_USER
  .endif
  invoke RegOpenKeyEx, hHive, $OfsCStr("Software\Classes"), 0, KEY_ALL_ACCESS, addr hClassesKey
  .if eax == ERROR_SUCCESS
    mov CHR ptr [cBuffer], "."
    lea xcx, [cBuffer + sizeof CHR]
    invoke StrCCopy, xcx, pExtension, lengthof cBuffer - sizeof CHR
    ;Buffer = ".Extension"
    invoke RegCreateKeyEx, hClassesKey, addr cBuffer, 0, NULL, REG_OPTION_NON_VOLATILE, \
                           KEY_ALL_ACCESS, NULL, addr hKey, NULL
    .if eax == ERROR_SUCCESS
      ;ProgID = "ApplicationName.Extension"
      lea xbx, cProgID
      mov xcx, pApplication
      add xcx, sizeof CHR
      invoke PathFindFileName, xcx
      invoke StrCCopy, xbx, xax, lengthof cProgID
      invoke PathRemoveExtension, xbx
      invoke StrCCat, xbx, addr cBuffer, lengthof cBuffer
      ;Set "default" value = ProgID
      invoke StrSize, xbx
      invoke RegSetValueEx, hKey, NULL, 0, REG_SZ, xbx, eax
      mov dResult, eax
      invoke RegCloseKey, hKey
      mov eax, dResult
      .if eax == ERROR_SUCCESS
        ;Create ProgID entry
        invoke StrCCat, xbx, $OfsCStr("\shell\"), lengthof cProgID
        invoke StrCCat, xbx, pVerb, lengthof cProgID
        invoke StrCCat, xbx, $OfsCStr("\command\"), lengthof cProgID
        invoke RegCreateKeyEx, hClassesKey, xbx, 0, NULL, REG_OPTION_NON_VOLATILE, \
                               KEY_ALL_ACCESS, NULL, addr hKey, NULL
        .if eax == ERROR_SUCCESS
          lea xbx, [cBuffer]
          mov CHR ptr [xbx], '"'
          lea xcx, [xbx + sizeof CHR]
          invoke StrCCopy, xcx, pApplication, lengthof cBuffer - sizeof CHR
          invoke StrCCatChar, xbx, '"', lengthof cBuffer
          .if pArguments != NULL
            invoke StrCCat, xbx, $OfsCStr(' "'), lengthof cBuffer
            invoke StrCCat, xbx, pArguments, lengthof cBuffer
            invoke StrCCatChar, xbx, '"', lengthof cBuffer
          .endif
          invoke StrSize, xbx
          invoke RegSetValueEx, hKey, NULL, 0, REG_SZ, xbx, eax
          mov dResult, eax
          invoke RegCloseKey, hKey
          .if dResult == ERROR_SUCCESS
            invoke SHChangeNotify, SHCNE_ASSOCCHANGED, SHCNF_IDLIST, 0, 0
          .endif
          mov eax, dResult
        .else
          mov dResult, eax
          invoke RegCloseKey, hClassesKey
          mov eax, dResult
        .endif
      .endif
    .else
      mov dResult, eax
      invoke RegCloseKey, hClassesKey
      mov eax, dResult
    .endif
  .endif
  ret
ProcName endp
