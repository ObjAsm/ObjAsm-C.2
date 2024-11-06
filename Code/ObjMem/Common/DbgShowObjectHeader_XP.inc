; ==================================================================================================
; Title:      DbgShowObjectHeader_XP.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  DbgShowObjectHeader / DbgShowObjectHeader_UEFI
; Purpose:    Output heading object information.
; Arguments:  Arg1: -> ANSI Object Name.
;             Arg2: -> Instance.
;             Arg3: Foreground RGB color value.
;             Arg4: Background RGB color value.
;             Arg5: -> Destination window WIDE name.
; Return:     Nothing.

.code
align ALIGN_CODE
ProcName proc pObjectName:POINTER, pInstance:POINTER, dForeColor:DWORD, dBackColor:DWORD, pDest:POINTER
  local bNum[20]:CHRA

  invoke DbgOutTextA, $OfsCStrA("Object "), dForeColor, dBackColor, DBG_EFFECT_BOLD, pDest
  invoke xword2hexA, addr bNum, pInstance
  invoke DbgOutTextA, addr bNum, dForeColor, dBackColor, DBG_EFFECT_BOLD, pDest
  invoke DbgOutTextA, $OfsCStrA("h::"), dForeColor, dBackColor, DBG_EFFECT_BOLD, pDest
  invoke DbgOutTextA, pObjectName, dForeColor, dBackColor, DBG_EFFECT_BOLD, pDest
  ret
ProcName endp
