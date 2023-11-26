; ==================================================================================================
; Title:      Base64Encode_X.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, November 2023.
;               - First release.
;               - Bitness neutral code.
; ==================================================================================================


% include &MacPath&ConstDiv.inc

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  Base64Encode
; Purpose:    Encode a data stream using the BASE64 algoritm.
; Arguments:  Arg1: -> Data buffer.
;             Arg2: Data size in BYTEs.
; Return:     xax -> Encoded buffer. When no longer needed, it should be freed using MemFree.
;             ecx = Encoded buffer size in BYTEs.
; Links:      https://en.wikipedia.org/wiki/Base64
;             https://datatracker.ietf.org/doc/html/rfc4648
;
; Layout:
;                    ———————————————————————————————————————————————
; Remaninder = 2    |   A   |   B   |   C   |   D   |   E   |XXXXXXX|   Data (X: don't touch)
;                   |———————————————————————————————————————————————|
; 6R2               |  Q  |  U  |  J  |  D  |  R  |  E  |  U  |  =  |   Digits (= means 3Dh)
;                    ———————————————————————————————————————————————
;                    ———————————————————————————————————————————————
; Remaninder = 1    |   A   |   B   |   C   |   D   |XXXXXXX|XXXXXXX|
;                   |———————————————————————————————————————————————|
; 5R1               |  Q  |  U  |  J  |  D  |  R  |  A  |  =  |  =  |
;                    ———————————————————————————————————————————————
;                    ———————————————————————————————————————————————
; Remaninder = 0    |   A   |   B   |   C   |   D   |   E   |   F   |
;                   |———————————————————————————————————————————————|
; 8R0               |  Q  |  U  |  J  |  D  |  R  |  E  |  V  |  G  |
;                    ———————————————————————————————————————————————

.const
BASE64_CHARS CHRA "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"

.code
align ALIGN_CODE
Base64Encode proc uses xbx xdi xsi pDataBuffer:POINTER, dDataSize:DWORD
  local pEncodedDataBuffer:POINTER, dEncodedDataSize:DWORD, dRemainder:DWORD

  mov dEncodedDataSize, 0
  mov pEncodedDataBuffer, NULL
  mov eax, dDataSize
  .if eax != 0 && pDataBuffer != NULL
    shl eax, 2
    cDivMod 3
    mov ebx, eax                                ;ebx always > 0
    mov dRemainder, edx
    add eax, edx
    .if edx == 1
      add eax, 2
    .endif
    mov dEncodedDataSize, eax
    MemAlloc eax
    .if xax
      mov pEncodedDataBuffer, xax
      mov xsi, pDataBuffer
      mov xdi, xax
      mov xcx, offset BASE64_CHARS
      .while TRUE
        movzx eax, CHRA ptr [xsi]
        mov edx, eax
        shr eax, 2
        mov al, [xcx + xax]
        stosb
        dec ebx
        jz @@Remainder_1
  
        inc xsi
        movzx eax, CHRA ptr [xsi]
        mov ah, dl
        shr eax, 4
        and eax, 0111111b
        mov al, [xcx + xax]
        stosb
        dec ebx
        jz @@Remainder_2
  
        movzx eax, DCHRA ptr [xsi]
        xchg al, ah
        mov edx, eax
        shr eax, 6
        and eax, 0111111b
        mov al, [xcx + xax]
        and edx, 0111111b
        add xsi, 2
        mov ah, [xcx + xdx]
        stosw
        sub ebx, 2
        jz @@Exit
      .endw
  
    @@Remainder_1:
      shl edx, 4
      and edx, 0111111b
      mov al, [xcx + xdx]
      stosb
      mov DCHRA ptr [xdi], '=='                         ;Padding
      jmp @@Exit
    @@Remainder_2:
      xor edx, edx
      mov dh, CHRA ptr [xsi]
      shr edx, 6
      mov ah, '='                                       ;Padding
      and edx, 0111111b
      mov al, [xcx + xdx]
      mov [xdi], ax
    .endif
  .endif

@@Exit:
  mov xax, pEncodedDataBuffer
  mov ecx, dEncodedDataSize
  ret
Base64Encode endp
