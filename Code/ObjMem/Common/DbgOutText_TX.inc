; ==================================================================================================
; Title:      DbgOutText_TX.inc
; Author:     G. Friedrich
; Version:    C.1.1
; Notes:      Version C.1.0, October 2017
;               - First release.
;             Version C.1.1, November 2023
;               - Internet communication added.
; ==================================================================================================


externdef DbgColorError:DWORD

; --------------------------------------------------------------------------------------------------
; Procedure:  DbgOutTextA / DbgOutTextW
; Purpose:    Send a string to the debug output device.
; Arguments:  Arg1: -> Zero terminated string.
;             Arg2: Foreground RGB color value.
;             Arg3: Background RGB color value.
;             Arg4: Effect value (DBG_EFFECT_XXX)
;             Arg5: -> Destination window WIDE name.
; Return:     eax = TRUE if succeeded, otherwise FALSE.

.code
align ALIGN_CODE
ProcName proc uses xbx pString:POINTER, dForeColor:DWORD, dBackColor:DWORD, dEffects:DWORD, pDest:POINTER
  local dResult:DWORD, CDS:COPYDATASTRUCT, dCharsWritten:DWORD

  mov dResult, FALSE
  .if pString == NULL
    c2m pString, $OfsCStr("NULL pointer"), xax
    m2m dForeColor, DbgColorError, edx
  .endif

  mov eax, dDbgDev
  .if eax == DBG_DEV_WIN_LOG
    .if $invoke(DbgOpenLog)
      invoke StrSize, pString
      sub eax, sizeof(CHR)
      invoke WriteFile, hDbgDev, pString, eax, NULL, NULL
    .endif
    .ifBitSet dEffects, DBG_EFFECT_NEWLINE
      invoke WriteFile, hDbgDev, offset cCRLF, 2*sizeof(CHR), NULL, NULL
    .endif
    mov dResult, TRUE

  .elseif eax == DBG_DEV_WIN_CON
    .if $invoke(DbgOpenCon)
      invoke RGB24To16ColorIndex, dForeColor
      invoke SetConsoleTextAttribute, hDbgDev, ax
      invoke StrLength, pString
      lea xbx, dCharsWritten
      invoke WriteConsole, hDbgDev, pString, eax, xbx, NULL
      .ifBitSet dEffects, DBG_EFFECT_NEWLINE
        invoke WriteConsole, hDbgDev, offset cCRLF, 2*sizeof(CHR), xbx, NULL
      .endif
    .endif
    mov dResult, TRUE

  .elseif eax == DBG_DEV_WIN_DC
    .if $invoke(DbgOpenWnd)
      invoke DbgBuildStrMsg, pString, dForeColor, dBackColor, dEffects, pDest
      .if xax != NULL                                   ;Continue if memory allocation succeeded
        mov CDS.dwData, DGB_MSG_ID                      ;Set DebugCenter identifier
        mov CDS.lpData, xax
        mov CDS.cbData, ecx
        invoke SendMessageTimeout, hDbgDev, WM_COPYDATA, -1, addr CDS, \
                                   SMTO_BLOCK, SMTO_TIMEOUT, NULL
        .if eax
          mov dResult, TRUE
        .endif
        MemFree CDS.lpData
      .endif
    .endif

  .elseif eax == DBG_DEV_WIN_NET
    invoke DbgBuildStrMsg, pString, dForeColor, dBackColor, dEffects, pDest
    .if xax != NULL
      mov xbx, xax
  if TARGET_BITNESS eq 32
      invoke DbgPostServer, xax, ecx
  else
      mov edx, ecx
      invoke DbgPostServer, xax, edx
  endif
      mov dResult, eax
      MemFree xbx
    .endif
  .endif

  mov eax, dResult
  ret
ProcName endp
