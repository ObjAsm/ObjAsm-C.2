; ==================================================================================================
; Title:      DbgShowTraceMethod_XP.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Procedure:  DbgShowTraceMethod
; Purpose:    Output trace information about a method.
; Arguments:  Arg1: -> ANSI Method Name.
;             Arg2: Method count.
;             Arg3: -> Method ticks.
;             Arg4: Foreground RGB color value.
;             Arg5: Background RGB color value.
;             Arg6: -> Destination Window WIDE name.
; Return:     Nothing.

.code
align ALIGN_CODE
DbgShowTraceMethod proc uses xbx pMName:POINTER, dCount:DWORD, pTicks:POINTER, \
                                 dForeground:DWORD, dBackground:DWORD, pDest:POINTER
  local cBuffer[100]:CHRW

  lea xbx, cBuffer
  invoke DbgOutTextA, $OfsCStrA("  "), dForeground, dBackground, DBG_EFFECT_NORMAL, pDest
  invoke DbgOutTextA, pMName, dForeground, dBackground, DBG_EFFECT_NORMAL, pDest
  invoke DbgOutTextA, $OfsCStrA(": Calls = "), dForeground, dBackground, DBG_EFFECT_NORMAL, pDest
  invoke wsprintfA, xbx, $OfsCStrA("%li"), dCount
  invoke DbgOutTextA, xbx, dForeground, dBackground, DBG_EFFECT_NORMAL, pDest
  .if dCount != 0
    invoke DbgOutTextA, $OfsCStrA(", Ticks = "), dForeground, dBackground, DBG_EFFECT_NORMAL, pDest
    mov xax, pTicks
    invoke qword2hexA, xbx, QWORD ptr [xax]
    mov WORD ptr [xbx + 16], "h"
    invoke DbgOutTextA, xbx, dForeground, dBackground, DBG_EFFECT_NORMAL, pDest
  .endif
  invoke DbgOutTextA, offset bCRLF, dForeground, dBackground, DBG_EFFECT_NORMAL, pDest
  ret
DbgShowTraceMethod endp
