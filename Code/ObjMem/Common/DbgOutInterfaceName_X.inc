; ==================================================================================================
; Title:      DbgOutInterfaceName_X.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  DbgOutInterfaceName
; Purpose:    Identify a COM-Interface.
; Arguments:  Arg1: -> CSLID.
;             Arg2: Foreground RGB color value.
;             Arg3: Background RGB color value.
;             Arg4: -> Destination Window WIDE name.
; Return:     Nothing.

align ALIGN_CODE
DbgOutInterfaceName proc uses xbx pIID:ptr GUID, dForeColor:DWORD, dBackColor:DWORD, pDestWnd:POINTER
  local hKey:HANDLE, SubKey[260]:CHRA, dSubKeyLenght:DWORD

  lea xbx, SubKey
	FillStringA [xbx], <Interface\{>                       ;$$Len = 11
	invoke GUID2StrA, addr SubKey[$$Len], pIID
  invoke DbgOutTextA, addr SubKey[$$Len] , dForeColor, dBackColor, DBG_EFFECT_NORMAL, pDestWnd
  mov DCHRA ptr [xbx + $$Len + GUID2STR_MAX_CHARS - 1], "}"
  m2z hKey
  invoke RegOpenKeyA, HKEY_CLASSES_ROOT, xbx, addr hKey
  .if eax == ERROR_SUCCESS
    mov DCHRA ptr [xbx], "( "
    mov dSubKeyLenght, sizeof(SubKey) - 2*sizeof(CHRA)
    invoke RegQueryValueA, hKey, NULL, addr SubKey[2], addr dSubKeyLenght
    mov eax, dSubKeyLenght
    mov CHRA ptr [xax + xbx + 1], ")"
    invoke DbgOutTextA, xbx, dForeColor, dBackColor, DBG_EFFECT_NORMAL, pDestWnd
    invoke RegCloseKey, hKey
  .endif
  ret
DbgOutInterfaceName endp
