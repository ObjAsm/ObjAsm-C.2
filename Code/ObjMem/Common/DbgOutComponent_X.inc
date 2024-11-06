; ==================================================================================================
; Title:      DbgOutComponent_X.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  DbgOutComponent
; Purpose:    Identify a COM-Component.
; Arguments:  Arg1: -> CSLID.
;             Arg2: Foreground RGB color value.
;             Arg3: Background RGB color value.
;             Arg4: -> Destination Window WIDE name.

.code
align ALIGN_CODE
DbgOutComponent proc pIID:ptr GUID, dForeColor:DWORD, dBackColor:DWORD, pDestWnd:POINTER
  invoke DbgOutTextA, $OfsCStrA("Component: "), dForeColor, dBackColor, DBG_EFFECT_NORMAL, pDestWnd
  invoke DbgOutComponentName, pIID, dForeColor, dBackColor, pDestWnd
  ret
DbgOutComponent endp
