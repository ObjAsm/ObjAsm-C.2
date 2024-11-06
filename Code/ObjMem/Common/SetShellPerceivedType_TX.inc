; ==================================================================================================
; Title:      SetShellPerceivedType_TX.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017.
;               - First release.
;               - Character and bitness neutral code.
; ==================================================================================================


% include &IncPath&Windows\shlwapi.inc
% include &IncPath&Windows\shlobj_core.inc

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  SetShellPerceivedTypeA / SetShellPerceivedTypeW
; Purpose:    Set shell perception of a file type.
; Arguments:  Arg1: TRUE = system wide perseption, FALSE = user account only.
;             Arg2: -> File extension (without dot).
;             Arg3: -> Type (Folder, Text, Image, Audio, Video, Compressed, Document, System, 
;                            Application, Gamemedia, Contacts)
; Return:     eax = HRESULT.
; Note:       To retrieve the perceived type use the AssocGetPerceivedType API.
;             dGlobal = TRUE requires adminitrative rights.

.code
align ALIGN_CODE
ProcName proc uses xbx dGlobal:DWORD, pExtension:POINTER, pPerceivedType:POINTER
  local hHive:HANDLE, hKey:HANDLE, dResult:DWORD, cBuffer[2*MAX_PATH]:CHR

  .if dGlobal != FALSE
    mov hHive, HKEY_LOCAL_MACHINE
  .else
    ;HKCR settings take precedence over HKLM settings
    mov hHive, HKEY_CURRENT_USER
  .endif
  FillString cBuffer, <Software\Classes\.>
  lea xbx, cBuffer
  invoke StrCCat, xbx, pExtension, lengthof cBuffer
  ;Buffer = ".Extension"
  invoke RegCreateKeyEx, hHive, xbx, 0, NULL, REG_OPTION_NON_VOLATILE, \
                         KEY_ALL_ACCESS, NULL, addr hKey, NULL
  .if eax == ERROR_SUCCESS
    invoke StrSize, pPerceivedType
    mov ebx, eax
    invoke RegSetValueEx, hKey, $OfsCStr("PerceivedType"), 0, REG_SZ, pPerceivedType, ebx
    mov dResult, eax
    invoke RegCloseKey, hKey
    .if dResult == ERROR_SUCCESS
      invoke SHChangeNotify, SHCNE_ASSOCCHANGED, SHCNF_IDLIST, 0, 0
    .endif
    mov eax, dResult
  .endif
  ret
ProcName endp
