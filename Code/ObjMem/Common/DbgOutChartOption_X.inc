; ==================================================================================================
; Title:      DbgOutChartOption_X.inc
; Author:     Héctor S. Enrique (HSE) / G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2024
;               - First release.
;               - Original idea from HSE - https://masm32.com/board/index.php?topic=12321.0
; ==================================================================================================


.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  DbgOutChartOption
; Purpose:    Send a chart option value to the Debug Center Window.
; Arguments:  Arg1: Option ID.
;             Arg2: -> Option value.
;             Arg3: Option value size.
;             Arg4: -> Destination Window WIDE name.
; Return:     eax = TRUE if succeeded, otherwise FALSE.

align ALIGN_CODE
DbgOutChartOption proc bID:BYTE, pValue:POINTER, dValueSize:DWORD, pDest:POINTER
  local dResult:DWORD, CDS:COPYDATASTRUCT, pData:POINTER

  mov dResult, FALSE
  mov eax, dDbgDev
  .if eax == DBG_DEV_WIN_DC
    .if $invoke(DbgOpenWnd)
      invoke DbgBuildChtMsg, bID, pValue, dValueSize, pDest
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
      invoke DbgBuildChtMsg, bID, pValue, dValueSize, pDest
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
DbgOutChartOption endp
