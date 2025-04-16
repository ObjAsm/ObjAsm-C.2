; ==================================================================================================
; Title:      StrRTrim_TX.inc
; Author:     G. Friedrich
; Version:    C.1.1
; Notes:      Version C.1.0, October 2017
;               - First release.
;             Version C.1.1, January 2023
;               - Bitness and character width neutal code.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Procedure:  StrRTrimA / StrRTrimW
; Purpose:    Trim blank characters from the end of a string.
; Arguments:  Arg1: -> Destination character buffer.
;             Arg2: -> Source string.
; Return:     eax = Number of characters copied into the destination buffer (not counting the ZTC).

.code
align ALIGN_CODE
ProcName proc uses xsi pDstString:POINTER, pSrcString:POINTER

  $$ChrReg equ $SubReg(ecx, sizeof(CHR))

if TARGET_BITNESS eq 32
  mov esi, pSrcString
else
  mov rsi, rdx
endif
  invoke StrEnd, xsi                                    ;pSrcString
@@:
  sub xax, sizeof(CHR)                                  ;Move to prev char
  cmp xax, xsi
  jb @F
  mov $$ChrReg, [xax]
  cmp $$ChrReg, ' '                                     ;Loop if space
  je @B
  cmp $$ChrReg, TAB                                     ;Loop if tab
  je @B
@@:
  sub xax, xsi                                          ;pSrcString
  mov xcx, pDstString
  add xax, sizeof(CHR)
  m2z CHR ptr [xcx + xax]                               ;Set ZTC
  jz @F
  .if xcx != xsi
    invoke MemShift, xcx, xsi, eax
  .endif
if TARGET_BITNESS eq 64
  shr rax, 1                                            ;Return number of chars.
endif
@@:
  ret
ProcName endp
