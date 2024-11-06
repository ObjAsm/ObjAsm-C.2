; ==================================================================================================
; Title:      DbgOutText_TX.inc
; Author:     G. Friedrich
; Version:    C.1.1
; Notes:      Version C.1.0, October 2017
;               - First release.
;             Version C.1.1, November 2023
;               - Internet communication added.
; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  DbgOutCmd
; Purpose:    Send a command to DebugCenter.
; Arguments:  Arg1: Command ID [BYTE].
;             Arg2: First parameter (DWORD).
;             Arg3: Second parameter (DWORD).
;             Arg4: -> Destination Window WIDE name.
; Return:     eax = TRUE if succeeded, otherwise FALSE.

.code
align ALIGN_CODE
DbgOutCmd proc bCommand:BYTE, dParam1:DWORD, dParam2:DWORD, pTargetWnd:POINTER
  local dResult:DWORD, CDS:COPYDATASTRUCT, pData:POINTER

  mov eax, dDbgDev
  .if eax == DBG_DEV_WIN_DC
    .if $invoke(DbgOpenWnd)
      invoke DbgBuildCmdMsg, bCommand, dParam1, dParam2, NULL, 0, pTargetWnd
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

    invoke DbgBuildCmdMsg, bCommand, dParam1, dParam2, NULL, 0, pTargetWnd
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
DbgOutCmd endp
