; ==================================================================================================
; Title:      DbgOutText_TX_UEFI.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, June 2022
;               - First release.
; ==================================================================================================


externdef DbgColorError:DWORD

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  DbgOutTextA_UEFI / DbgOutTextW_UEFI
; Purpose:    Send a string to the debug output device.
; Arguments:  Arg1: -> Zero terminated string.
;             Arg2: Foreground RGB color value.
;             Arg3: Background RGB color value.
;             Arg4: Effect value (DBG_EFFECT_XXX)
;             Arg5: -> Destination window WIDE name.
; Return:     Nothing.

align ALIGN_CODE
ProcName proc uses xbx pString:POINTER, dForeColor:DWORD, dBackColor:DWORD, dEffects:DWORD, pDest:POINTER
  .if pString == NULL
    mov xax, $OfsCStr("NULL pointer")
    mov pString, xax
    m2m dForeColor, DbgColorError, edx
  .endif

  mov eax, dDbgDev
  .if eax == DBG_DEV_UEFI_CON
    if TARGET_STR_TYPE eq STR_TYPE_ANSI
      invoke StrLengthA, pString
      invoke StrAllocW, eax
      mov xbx, xax
      invoke StrA2StrW, xax, pString
      mov pString, xbx
    endif
    invoke RGB24To16ColorIndex, dForeColor
    mov xbx, pConsoleOut
    invoke [xbx].ConOut.SetAttribute, xbx, xax
    invoke [xbx].ConOut.OutputString, xbx, pString
    .ifBitSet dEffects, DBG_EFFECT_NEWLINE
      invoke [xbx].ConOut.OutputString, xbx, offset wCRLF
    .endif
    if TARGET_STR_TYPE eq STR_TYPE_ANSI
      invoke StrDispose, pString
    endif
  .endif
  ret
ProcName endp
