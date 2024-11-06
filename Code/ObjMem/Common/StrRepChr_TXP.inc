; ==================================================================================================
; Title:      StrRepChr_TXP.inc
; Author:     G. Friedrich
; Version:    C.1.1
; Notes:      Version C.1.1, May 2020
;               - First release.
;               - Character, bitness and platform independent code. 
; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrRepChrA / StrRepChrW
; Purpose:    Create a new string filled with a given char.
; Arguments:  Arg1: Used character.
;             Arg2: Repetition count.
; Return:     xax -> New string or NULL if failed.

.code
align ALIGN_CODE
ProcName proc uses xbx cChar:CHR, dReps:DWORD
  invoke StrAlloc, dReps
  .if xax != NULL
    mov edx, dReps
    mov $ChrReg(xbx), cChar
    mov xcx, xax
    test edx, edx
    .while !ZERO?
      mov [xcx], $ChrReg(xbx)
      add xcx, sizeof(CHR)
      dec edx
    .endw
    m2z CHRW ptr [xcx]                                  ;Set ZTC
  .endif
  ret
ProcName endp

