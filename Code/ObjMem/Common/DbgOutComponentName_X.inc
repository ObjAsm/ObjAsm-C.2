; ==================================================================================================
; Title:      DbgOutComponentName_X.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  DbgOutComponentName
; Purpose:    Identify a COM-Component.
; Arguments:  Arg1: -> CSLID.
;             Arg2: Foreground RGB color value.
;             Arg3: Background RGB color value.
;             Arg4: -> Destination Window WIDE name.
; Return:     Nothing.

align ALIGN_CODE
DbgOutComponentName proc uses xbx pIID:ptr GUID, dForeColor:DWORD, dBackColor:DWORD, pDestWnd:POINTER
  local hKey:HANDLE, SubKey[260]:CHRA, dSubKeyLength:DWORD

  lea xbx, SubKey
	FillStringA [xbx], <CLSID\{>
  invoke GUID2StrA, addr SubKey[7], pIID
  invoke DbgOutTextA, addr SubKey[7] , dForeColor, dBackColor, DBG_EFFECT_NORMAL, pDestWnd
  FillStringA [xbx + 43], <}>
  invoke RegOpenKeyA, HKEY_CLASSES_ROOT, xbx, addr hKey
  .if eax == ERROR_SUCCESS
    mov dSubKeyLength, sizeof(SubKey)
    invoke RegQueryValueA, hKey, NULL, xbx, addr dSubKeyLength
    invoke DbgOutTextA, xbx, dForeColor, dBackColor, DBG_EFFECT_NORMAL, pDestWnd
    invoke RegCloseKey, hKey
  .endif
  ret
DbgOutComponentName endp
