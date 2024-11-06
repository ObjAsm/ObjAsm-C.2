; ==================================================================================================
; Title:      UTF8ToWide_XP.inc
; Author:     G. Friedrich
; Version:    C.1.1
; Notes:      Version C.1.1, February 2020
;               - First release.
; Links:      https://en.wikipedia.org/wiki/UTF-8
;             https://en.wikipedia.org/wiki/UTF-16
; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  UTF8ToWide
; Purpose:    Convert an UTF8 byte stream to a WIDE (UTF16) string.
; Arguments:  Arg1: -> Destination WIDE buffer.
;             Arg2: -> Source UTF8 BYTE stream. Must be zero terminated.
;             Arg3: Destination buffer size in BYTEs.
; Return:     eax = Number of BYTEs written.
;             ecx = 0: succeeded
;                   1: buffer full
;                   2: conversion error
; Notes:      - The destination WIDE string is always terminated with a ZTC.
;               (only if buffer size >= 2).

.code
align ALIGN_CODE
UTF8ToWide proc uses xbx xdi xsi pDest:POINTER, pSource:POINTER, dBufferSize:DWORD
  if TARGET_BITNESS eq 32
    mov ebx, dBufferSize
    mov edi, pDest
    and ebx, 0FFFFFFFEh                                 ;Even number => reset last bit
    mov esi, pSource
    jz @@End
    add ebx, pDest
    sub ebx, sizeof(WORD)
  else
    mov ebx, r8d
    mov rdi, rcx
    and ebx, 0FFFFFFFEh                                 ;Even number => reset last bit
    mov rsi, rdx
    jz @@End
    add rbx, rcx
    sub rbx, sizeof(WORD)
  endif

@@NextChar:
  repeat 8
    cmp xdi, xbx
    je @@BufferFull
    movzx ax, BYTE ptr [xsi]
    mov ecx, 0
    test al, al
    jz @@Exit
    mov dl, al
    lea xsi, [xsi + 1]
    test al, 10000000y
    jnz @F
    ;1 Byte encoding (0xxxxxxx)
    mov [xdi], ax
    add xdi, sizeof(WORD)
  endm

  jmp @@NextChar

@@:
  and dl, 11111000y
  .if dl == 11110000y                                   ;11110xxx
    ;check if we have enough room for 2 surrogates
    lea xcx, [xbx - sizeof(WORD)]
    cmp xcx, xdi
    je @@BufferFull

    ;4 Byte encoding (11110xxx 10xxxxxx 10xxxxxx 10xxxxxx)
    and eax, 00000111y
    shl ax, 6
    mov dl, [xsi]
    add xsi, 1
    mov dh, dl
    and dh, 11000000y
    .if dh == 10000000y
      and edx, 00111111y
      add dx, ax
      shl edx, 12

      mov cx, [xsi]
      add xsi, sizeof(WORD)
      mov ax, cx
      and ax, 1100000011000000y
      .if ax == 1000000010000000y
        mov al, cl
        and ch, 00111111y
        and ax, 00111111y
        shl ax, 6
        add al, ch
        add eax, edx

        ;Create the surrogates
        sub eax, 10000h                                 ;Size of BMP (Basic Multilingual Plane)
        mov ecx, eax
        shr eax, 10
        add ax, SURROGATE_HIGH
        mov [xdi], ax
        mov eax, ecx
        add xdi, sizeof(WORD)
        and eax, not SURROGATE_MASK
        add eax, SURROGATE_LOW
        mov [xdi], ax
        add xdi, sizeof(WORD)
        jmp @@NextChar
      .endif
    .endif
    mov ecx, 2
    jmp @@Exit
  .endif

  and dl, 11110000y
  mov cx, [xsi]                                         ;It is save to read 2 BYTEs, ZTC is pending
  .if dl == 11100000y                                   ;1110xxxx
    ;3 Byte encoding (1110xxxx 10xxxxxx 10xxxxxx)
    shl ax, 12
    mov dx, cx
    add xsi, sizeof(WORD)
    and cx, 1100000011000000y
    .if cx == 1000000010000000y
      and dx, 0011111100111111y
      movzx cx, dl
      shl cx, 6
      add cl, dh
      add ax, cx
      mov [xdi], ax
      add xdi, sizeof(WORD)
      jmp @@NextChar
    .endif
    mov ecx, 2
    jmp @@Exit
  .endif

  and dl, 11100000y
  and ax, 00011111y
  .if dl == 11000000y                                   ;110xxxxx
    ;2 Byte encoding (110xxxxx 10xxxxxx)
    mov ch, cl
    shl ax, 6
    and cx, 1100000000111111y
    .if ch == 10000000y
      add al, cl
      add xsi, 1
      mov [xdi], ax
      add xdi, sizeof(WORD)
      jmp @@NextChar
    .endif
  .endif
  mov ecx, 2
  jmp @@Exit

@@BufferFull:
  mov ecx, 1
@@Exit:
  mov WORD ptr [xdi], 0                                 ;Write WIDE ZTC
  lea xax, [xdi + sizeof(WORD)]
  sub xax, pDest
@@End:
  ret
UTF8ToWide endp
