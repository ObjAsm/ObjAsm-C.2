; ==================================================================================================
; Title:      ComGetErrStr_TX.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, August 2022
;               - First release.
;               - Character and bitness neutral code.
; ==================================================================================================


% include &ObjMemPath&Common\\ComErrTable_T.inc

.code
; --------------------------------------------------------------------------------------------------
; Procedure:  ComGetErrStrA / ComGetErrStrW 
; Purpose:    Return description string from a COM error code.
; Arguments:  Arg1: COM error code.
; Return:     xax -> Error string.

.code
align ALIGN_CODE
ProcName proc dErrCode:DWORD
  ?mov ecx, dErrCode
  .ifBitSet ecx, BIT31                                  ;Test error bit
    mov eax, ComErrTableCount
    mov xdx, offset ComErrTable
    test eax, eax
    .while !ZERO?                                       ;This search can be smarter!
      .break .if ecx == [xdx].DOM.dCode
      add xdx, sizeof(DOM)
      dec eax
    .endw
    .if eax == 0
      mov xax, $OfsCStr("Unknown error")
    .else
      mov xax, [xdx].DOM.pString
    .endif
  .else
    mov xax, $OfsCStr("Success")
  .endif
  ret
ProcName endp
