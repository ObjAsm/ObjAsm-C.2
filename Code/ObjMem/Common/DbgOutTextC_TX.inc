; ==================================================================================================
; Title:      DbgOutTextC_TX.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


externdef DbgColorError:DWORD

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

  .if pString == NULL
    invoke DbgOutTextA, $OfsCStrA("NULL pointer"), DbgColorError, dBackColor, DBG_EFFECT_NORMAL, pDest
    ret
  .endif
  mov ebx, dMaxLength
  .if ebx == NULL
    invoke DbgOutTextA, $OfsCStrA("Zero size"), DbgColorError, dBackColor, DBG_EFFECT_NORMAL, pDest
    ret
  .endif

  invoke StrLength, pString
  .if eax <= dMaxLength
    invoke DbgOutText, pString, dForeColor, dBackColor, dEffects, pDest
  .else
    mov eax, dMaxLength
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
      mov CHR ptr [xax], 0                                ;Set ZTC
      invoke DbgOutText, pBuffer, dForeColor, dBackColor, dEffects, pDest
      MemFree pBuffer
    .endif
  .endif
  ret
ProcName endp
