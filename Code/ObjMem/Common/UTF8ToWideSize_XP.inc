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
; Purpose:    Convert an UTF8 byte stream to a WIDE (UTF16) string.
; Arguments:  Arg1: -> Destination WIDE buffer.
;             Arg2: -> Source UTF8 BYTE stream. Must be zero terminated.
;             Arg3: Destination buffer size in BYTEs.
; Return:     eax = Number of BYTEs written.
;             ecx = 0: succeeded
;                   2: conversion error
; Notes:      - The size of converted WIDE string is always includes the ZTC.

.code
align ALIGN_CODE
UTF8ToWideSize proc uses xsi pSource:POINTER
  xor edx, edx
  if TARGET_BITNESS eq 32
    mov esi, pSource
  else
    mov rsi, rcx
  endif

@@NextChar:
  repeat 8
    movzx ax, BYTE ptr [xsi]
    test al, al
    jz @@Exit
    inc xsi
    test al, 10000000y
    jnz @F
    ;1 Byte encoding (0xxxxxxx)
    add edx, sizeof(WORD)
  endm

  jmp @@NextChar

@@:
  and al, 11111000y
  .if al == 11110000y                                   ;11110xxx
    ;4 Byte encoding (11110xxx 10xxxxxx 10xxxxxx 10xxxxxx)
    mov al, [xsi]
    add xsi, 1
    and al, 11000000y
    .if al == 10000000y
      mov ax, [xsi]
      add xsi, sizeof(WORD)
      and ax, 1100000011000000y
      .if ax == 1000000010000000y
        add edx, sizeof(DWORD)
        jmp @@NextChar
      .endif
    .endif
    mov ecx, 2
    jmp @@Exit
  .endif

  and al, 11110000y
  mov cx, [xsi]                                         ;It is save to read 2 BYTEs, ZTC is pending
  .if al == 11100000y                                   ;1110xxxx
    ;3 Byte encoding (1110xxxx 10xxxxxx 10xxxxxx)
    add xsi, sizeof(WORD)
    and cx, 1100000011000000y
    .if cx == 1000000010000000y
      add edx, sizeof(WORD)
      jmp @@NextChar
    .endif
    mov ecx, 2
    jmp @@Exit
  .endif

  and al, 11100000y
  .if al == 11000000y                                   ;110xxxxx
    ;2 Byte encoding (110xxxxx 10xxxxxx)
    mov ch, cl
    and cx, 1100000000111111y
    .if ch == 10000000y
      add edx, sizeof(WORD)
      jmp @@NextChar
    .endif
  .endif
  mov ecx, 2
  jmp @@Exit

@@Exit:
  lea eax, [edx + sizeof(WORD)]                         ;ZTC
@@End:
  ret
UTF8ToWideSize endp
