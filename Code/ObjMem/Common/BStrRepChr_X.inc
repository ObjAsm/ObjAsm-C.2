; ==================================================================================================
; Title:      BStrRepChr_X.inc
; Author:     G. Friedrich
; Version:    C.1.1
; Notes:      Version C.1.1, May 2020.
;               - First release.
;               - Bitness neutral code. 
; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  BStrRepChr
; Purpose:    Create a new BSTR filled with a given char.
; Arguments:  Arg1: Used character.
;             Arg2: Repetition count.
; Return:     xax -> New BSTR or NULL if failed.

.code
align ALIGN_CODE
BStrRepChr proc uses xbx wChar:CHRW, dReps:DWORD
  invoke BStrAlloc, dReps
  .if xax != NULL
    mov edx, dReps
    mov bx, wChar
    mov xcx, xax
    test edx, edx
    .while !ZERO?
      mov [xcx], bx
      add xcx, sizeof(CHRW)
      dec edx
    .endw
    m2z CHRW ptr [xcx]                                  ;Set ZTC
  .endif
  ret
BStrRepChr endp
