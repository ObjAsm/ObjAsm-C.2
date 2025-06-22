; ==================================================================================================
; Title:      WideToUTF8_XP.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1., June 2025
;               - First release.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Procedure:  WideToUTF8Size
; Purpose:    Calculate the amount of memory needed to store the converted UTF8 stream from a
;             WIDE string.
; Arguments:  Arg1: -> Source WIDE string. Must be zero terminated.
; Return:     eax = Number of BYTEs requred. Zero if failed.
; Notes:      The ZTC is always included in size calculations.
;             The returned value can only be zero if the procedure fails.
;             Wide chars can only encode the Basic Multilingual Plane (BMP, or Plane 0), 
;             meaning that sequences of a maximum of three bytes can be generated.

.code
align ALIGN_CODE
WideToUTF8Size proc pSource:POINTER
  xor eax, eax
  ?mov ecx, pSource
  .if xcx == NULL
    ret
  .endif

@@NextChar:
  movzx edx, CHRW ptr [xcx]
  test edx, edx
  .if ZERO?
    inc eax                                             ;Include this last ZTC
    ret
  .endif

  .if edx <= 07Fh
    inc eax
  .elseif edx <= 07FFh
    add eax, 2
  .else
    add eax, 3
  .endif
  add xcx, sizeof(CHRW)
  jmp @@NextChar
WideToUTF8Size endp
