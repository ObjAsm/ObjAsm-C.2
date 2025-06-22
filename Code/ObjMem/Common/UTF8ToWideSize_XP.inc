; ==================================================================================================
; Title:      UTF8ToWideSize_XP.inc
; Author:     G. Friedrich
; Version:    C.1.1
; Notes:      Version C.1.1, February 2020
;               - First release.
; Links:      https://en.wikipedia.org/wiki/UTF-8
;             https://en.wikipedia.org/wiki/UTF-16
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Procedure:  UTF8ToWideSize
; Purpose:    Calculate the amount of memory needed to store the converted WIDE string from a
;             UTF8 stream.
; Arguments:  Arg1: -> Source UTF8 BYTE stream. Must be zero terminated.
; Return:     eax = Number of BYTEs requred. Zero if failed.
; Notes:      The ZTC is always included in size calculations.
;             The returned value can only be zero if the procedure fails.

.code
align ALIGN_CODE
UTF8ToWideSize proc pSource:POINTER
  xor eax, eax
  ?mov ecx, pSource
  .if xcx == NULL
    ret
  .endif 
  
@@NextChar:
  movzx edx, BYTE ptr [xcx]
  test edx, edx                                         ;ZTC?
  .if ZERO?
    add eax, sizeof(WORD)                               ;ZTC
    ret
  .endif

  test edx, 10000000y
  .if ZERO?
    ;1 Byte encoding (0xxxxxxx)
    add eax, sizeof(WORD)
    inc xcx
    jmp @@NextChar
  .endif

  and edx, 11111000y
  .if edx == 11110000y                                  ;11110xxx
    ;4 Byte encoding (11110xxx 10xxxxxx 10xxxxxx 10xxxxxx)
    add eax, sizeof(WORD)
    add xcx, 4*sizeof(BYTE)
    jmp @@NextChar
  .endif

  and edx, 11110000y
  .if edx == 11100000y                                  ;1110xxxx
    ;3 Byte encoding (1110xxxx 10xxxxxx 10xxxxxx)
    add eax, sizeof(WORD)
    add xcx, 3*sizeof(BYTE)
    jmp @@NextChar
  .endif

  and edx, 11100000y
  .if edx == 11000000y                                  ;110xxxxx
    ;2 Byte encoding (110xxxxx 10xxxxxx)
    add eax, sizeof(WORD)
    add xcx, 2*sizeof(BYTE)
    jmp @@NextChar
  .endif

  xor eax, eax                                          ;Conversion error
  ret
UTF8ToWideSize endp
