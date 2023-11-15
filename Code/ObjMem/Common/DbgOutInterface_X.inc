; ==================================================================================================
; Title:      DbgOutInterface_X.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


externdef DbgColorError:DWORD

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  DbgOutInterface
; Purpose:    Identify a COM-Interface.
; Arguments:  Arg1: -> CSLID.
;             Arg2: Foreground RGB color value.
;             Arg3: Background RGB color value.
;             Arg4: -> Destination Window WIDE name.
; Return:     Nothing.

align ALIGN_CODE
DbgOutInterface proc pIID:ptr GUID, dForeColor:DWORD, dBackColor:DWORD, pDest:POINTER
  .if pIID == NULL
    invoke DbgOutTextA, $OfsCStrA("NULL pointer"), DbgColorError, dBackColor, DBG_EFFECT_NEWLINE, pDest
  .else
    invoke DbgOutTextA, $OfsCStrA("Interface: "), dForeColor, dBackColor, DBG_EFFECT_NORMAL, pDest
    invoke DbgOutInterfaceName, pIID, dForeColor, dBackColor, pDest
  .endif
  ret
DbgOutInterface endp

end
