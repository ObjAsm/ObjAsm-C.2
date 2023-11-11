; ==================================================================================================
; Title:      DbgOutBitmap_X.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, November 2023
;               - First release.
; ==================================================================================================


.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  DbgOutBitmap
; Purpose:    Send a bitmap to the Debug Center Window.
; Arguments:  Arg1: Bitamp HANDLE.
;             Arg2: Background RGB color value.
;             Arg3: -> Destination Window WIDE name.
; Return:     eax = TRUE if succeeded, otherwise FALSE.

align ALIGN_CODE
DbgOutBitmap proc hBmp:HANDLE, dBackColor:DWORD, pDest:POINTER
  local dResult:DWORD, CDS:COPYDATASTRUCT, pData:POINTER

  mov dResult, FALSE
  mov eax, dDbgDev
  .if eax == DBG_DEV_WIN_DC
    .if $invoke(DbgOpenWnd)
      invoke DbgBuildBmpMsg, hBmp, dBackColor, pDest
      .if xax
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
    invoke DbgBuildBmpMsg, hBmp, dBackColor, pDest
    .if xax != NULL
      mov pData, xax
  if TARGET_BITNESS eq 32
      invoke DbgPostServer, xax, ecx
  else
      mov edx, ecx
      invoke DbgPostServer, xax, edx
  endif
      mov dResult, eax
      MemFree pData
    .endif
  .endif
  mov eax, dResult
  ret
DbgOutBitmap endp
