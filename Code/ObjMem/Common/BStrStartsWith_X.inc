; ==================================================================================================
; Title:      BStrStartsWith_X.inc
; Author:     G. Friedrich
; Version:    C.1.1
; Notes:      Version C.1.1, April 2020.
;               - First release.
;               - Bitness neutral code. 
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Procedure:  BStrStartsWith
; Purpose:    Compare the beginning of a BSTR.
; Arguments:  Arg1: -> Analized BSTR.
;             Arg2: -> Prefix BSTR.
; Return:     eax = TRUE of the beginning matches, otherwise FALSE.

.code
align ALIGN_CODE
BStrStartsWith proc pString:POINTER, pPrefix:POINTER
  ?mov xdx, pPrefix
  ?mov xcx, pString
  mov eax, [xdx - 4]                                    ;Byte count of the prefix BSTR without ZTC
  shr eax, 1                                            ;Calculate the max number of chars
  invoke StrCCompW, xcx, xdx, eax
  .if eax == 0
    mov eax, TRUE
  .else
    xor eax, eax
  .endif
  ret
BStrStartsWith endp
