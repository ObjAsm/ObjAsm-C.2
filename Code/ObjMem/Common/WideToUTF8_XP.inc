; ==================================================================================================
; Title:      WideToUTF8_XP.inc
; Author:     G. Friedrich
; Version:    C.1.1
; Notes:      Version C.1.1, February 2020
;               - First release.
; Links:      https://en.wikipedia.org/wiki/UTF-8
;             https://en.wikipedia.org/wiki/UTF-16
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Procedure:  WideToUTF8
; Purpose:    Convert an WIDE string to an UTF8 encoded stream.
; Arguments:  Arg1: -> Destination buffer.
;             Arg2: -> Source WIDE string.
;             Arg3: Destination buffer size in BYTEs.
; Return:     eax = Number of BYTEs written.
;             ecx = 0: succeeded
;                   1: buffer full
; Notes:      - The destination stream is always zero terminated.

.code
align ALIGN_CODE
WideToUTF8 proc uses xbx xdi xsi pDest:POINTER, pSource:POINTER, dBufferSize:DWORD
  xor eax, eax
  if TARGET_BITNESS eq 32
    mov ebx, dBufferSize
    mov edi, pDest
    mov esi, pSource
  else
    mov ebx, r8d
    mov rdi, rcx
    mov rsi, rdx
  endif
  test ebx, ebx
  jz @@End

@@NextChar:
  repeat 8
    movzx eax, WORD ptr [xsi]
    test ax, ax
    jz @@End
    lea xsi, [xsi + 2]
    cmp ax, 80h
    jae @F
    ;1 Byte encoding (0xxxxxxx)
    ;Check if there is enough space for 1 byte + ZTC
    cmp ebx, 2
    jb @@End
    mov [xdi], al
    sub ebx, 1
    add xdi, 1
  endm
  jmp @@NextChar

@@:
  ;Check for surrogates
  mov ecx, eax
  and ecx, 1111100000000000y
  cmp ecx, SURROGATE_HIGH                               ;0D800h - 0DC00h
  jz @@CheckSurrogates
  cmp ax, 0800h
  jb @@2ByteEnc

@@3ByteEnc:
  ;3 Byte encoding (1110xxxx 10xxxxxx 10xxxxxx)
  ;Check if there is enough space for 3 BYTEs + ZTC
  cmp ebx, 4
  jb @@End

  mov edx, eax
  mov ecx, eax
  and edx, 00111111y
  shl ecx, 2                                            ;-6+8 = +2
  add edx, 10000000y
  and ecx, 0011111100000000y
  shl edx, 16
  shr eax, 12
  add ecx, 1000000000000000y
  and eax, 00001111y
  mov dx, cx
  add eax, 11100000y
  mov dl, al

  sub ebx, 3
  mov [xdi], edx
  add xdi, 3

  jmp @@NextChar

@@2ByteEnc:
  ;2 Byte encoding (110xxxxx 10xxxxxx)
  ;Check if there is enough space for 2 BYTEs + ZTC
  cmp ebx, 3
  jb @@End

  mov edx, eax
  and ax, 00111111y
  shr edx, 6
  add al, 10000000y
  and dl, 00011111y
  mov dh, al
  add dl, 11000000y
  sub ebx, 2
  mov [xdi], dx
  add xdi, sizeof(WORD)

  jmp @@NextChar

@@CheckSurrogates:
  mov cx, ax
  and cx, SURROGATE_MASK
  cmp cx, SURROGATE_HIGH
  jnz @@ReplacementChar                                 ;Isolated surrogates have no interpretation

  mov dx, [xsi]
  mov cx, dx
  and cx, SURROGATE_MASK
  cmp cx, SURROGATE_LOW
  jz @@4ByteEnc                                         ;Isolated surrogates have no interpretation

@@ReplacementChar:
  cmp ebx, 4
  jb @@End
  mov WORD ptr [xdi], 0BFEFh                            ;UNICODE 0FFFDh = UFT8 0EFh + 0BFh + 0BDh
  sub ebx, 3
  mov BYTE ptr [xdi + sizeof(WORD)], 0BDh
  add xdi, 3
  jmp @@NextChar

@@4ByteEnc:
  ;4 byte encoding (11110xxx 10xxxxxx 10xxxxxx 10xxxxxx)
  ;Check if there is enough space for 4 BYTEs + ZTC
  cmp ebx, 5
  jb @@End

  and ax, not SURROGATE_MASK
  add xsi, sizeof(WORD)
  shl eax, 10
  and dx, not SURROGATE_MASK
  add ax, dx
  add eax, 10000h                                       ;Size of BMP (Basic Multilingual Plane)
                                                        ;eax = Code Point
  mov edx, eax
  mov cx, ax
  shr edx, 6
  shr cx, 18
  mov dh, al
  and cx, 00000111y
  shr eax, 12
  and edx, 0011111100111111y
  add cx, 11110000y
  add edx, 1000000010000000y
  and eax, 00111111y
  shl edx, 16
  mov dl, cl
  add al, 10000000y
  mov dh, al

  sub ebx, 4
  mov [xdi], edx
  add xdi, 4

  jmp @@NextChar

@@End:
  mov ecx, 0
  jz @F
  add ecx, 1
@@:
  if TARGET_BITNESS eq 32
    mov eax, dBufferSize
  else
    mov eax, r8d
  endif
  sub ebx, 1
  mov BYTE ptr [xdi], 0
  sub eax, ebx
  ret
WideToUTF8 endp
