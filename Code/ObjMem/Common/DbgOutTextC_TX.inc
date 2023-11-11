; ==================================================================================================
; Title:      DbgOutTextC_TX.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  DbgOutTextCA/DbgOutTextCW
; Purpose:    Send a counted string to the debug output device.
; Arguments:  Arg1: -> Zero terminated string.
;             Arg2: Maximal character count.
;             Arg3: Foreground RGB color value.
;             Arg4: Background RGB color value.
;             Arg5: Effect value (DBG_EFFECT_XXX).
;             Arg6: -> Destination Window WIDE name.
; Return:     Nothing.

align ALIGN_CODE
ProcName proc pString:POINTER, dMaxLength:DWORD, dForeColor:DWORD, dBackColor:DWORD, \
              dEffects:DWORD, pDest:POINTER
  local pBuffer:POINTER, dStrSize:DWORD

  invoke StrLength, pString
  .if eax <= dLength
    invoke DbgOutText, pString, dForeColor, dBackColor, dEffects, pDest
  .else
    mov eax, dLength
  if TARGET_STR_TYPE eq STR_TYPE_WIDE
    add eax, eax
  endif
    mov dStrSize, eax
    add eax, sizeof(CHR)                                  ;Include ZTC
    MemAlloc eax
    .if xax
      mov pBuffer, xax
      invoke MemClone, xax, pString, dStrSize
      mov eax, dStrSize
      add xax, pBuffer
      mov [xax], 0                                        ;Set ZTC
      invoke DbgOutText, pBuffer, dForeColor, dBackColor, dEffects, pDest
      MemFree pBuffer
    .endif
  .endif
  ret
ProcName endp
