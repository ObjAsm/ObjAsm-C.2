; ==================================================================================================
; Title:      DbgOutComErr_X.inc
; Author:     G. Friedrich
; Version:    C.1.1
; Notes:      Version C.1.0, October 2017
;               - First release.
;               - Bitness independent code.
;             Version C.1.1, August 2022
;               - New ComGetErrStrA proc used. 
; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  DbgOutComErr 
; Purpose:    Identify a COM error with a string.
; Arguments:  Arg1: COM error ID.
;             Arg2: Foreground RGB color value.
;             Arg3: Background RGB color value.
;             Arg4: -> Destination Window WIDE name.
; Return:     Nothing.

align ALIGN_CODE
DbgOutComErr proc uses xbx dErrCode:DWORD, dForeColor:DWORD, dBackColor:DWORD, pDest:POINTER
  local bHexBuffer[16]:CHRA                             ;13 ANSI characters + filler

  invoke ComGetErrStrA, dErrCode
  invoke DbgOutTextA, xax, dForeColor, dBackColor, DBG_EFFECT_NORMAL, pDest
  lea xbx, bHexBuffer
  FillWordA [xbx], < [>
  add xbx, ??StrSize
  invoke dword2hexA, xbx, dErrCode
  FillStringA [xbx + (DWORD2HEX_MAX_CHARS - 1)*sizeof(CHRA)], <h]>
  invoke DbgOutTextA, addr bHexBuffer, dForeColor, dBackColor, DBG_EFFECT_NORMAL, pDest
  ret
DbgOutComErr endp
