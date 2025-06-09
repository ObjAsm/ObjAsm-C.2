; ==================================================================================================
; Title:      RegisterFileType_TX.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, June 2025
;               - First release.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Procedure:  RegisterFileType
; Purpose:    Register a file extension on the OS with a application.
; Arguments:  Arg1: -> File extension, inclusive '.'.
;             Arg2: -> Programmatic application ID string.
;             Arg3: -> Description string.
;             Arg4: -> Application full file name.
; Return:     Nothing.

.code
align ALIGN_CODE
RegisterFileType proc uses xbx xdi pExtension:PSTRING, pProgID:PSTRING, pDescription:PSTRING, pAppPath:PSTRING
  local hKey:HKEY, cBuffer[1024]:CHR
  
  ;Step 1: Associate .myext with MyApp.File
  invoke RegCreateKeyEx, HKEY_CLASSES_ROOT, pExtension, 0, NULL, 0, KEY_WRITE, NULL, addr hKey, NULL
  .if eax == ERROR_SUCCESS
    invoke StrLength, pProgID
    lea edi, [eax*sizeof(CHR) + sizeof(CHR)]
    invoke RegSetValueEx, hKey, NULL, 0, REG_SZ, pProgID, edi
    invoke RegCloseKey, hKey
  .endif
  
  ;Step 2: Define MyApp.File description
  invoke RegCreateKeyEx, HKEY_CLASSES_ROOT, pProgID, 0, NULL, 0, KEY_WRITE, NULL, addr hKey, NULL
  .if eax == ERROR_SUCCESS
    invoke StrLength, pDescription
    lea edi, [eax*sizeof(CHR) + sizeof(CHR)]
    invoke RegSetValueEx, hKey, NULL, 0, REG_SZ, pDescription, edi
    invoke RegCloseKey, hKey
  .endif

  ;Step 3: Set command to open the file
  lea xbx, cBuffer
  WriteF xbx, "¦ST\shell\open\command", pProgID
  invoke RegCreateKeyEx, HKEY_CLASSES_ROOT, addr cBuffer, 0, NULL, 0, KEY_WRITE, NULL, addr hKey, NULL
  .if eax == ERROR_SUCCESS
    lea xbx, cBuffer
    WriteF xbx, "\`¦ST\` \`%1\`", pAppPath
    lea xax, cBuffer
    sub xbx, xax
    invoke RegSetValueEx, hKey, NULL, 0, REG_SZ, addr cBuffer, ebx
    invoke RegCloseKey, hKey
  .endif

  ;Step 4: Notify the shell that file associations have changed
  invoke SHChangeNotify, SHCNE_ASSOCCHANGED, SHCNF_IDLIST, NULL, NULL

  ret
RegisterFileType endp