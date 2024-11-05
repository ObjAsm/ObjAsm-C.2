; ==================================================================================================
; Title:      Base64Encode_X.inc
; Author:     G. Friedrich
; Version:    C.1.1
; Notes:      Version C.1.0, November 2023.
;               - First release.
;               - Bitness neutral code.
;             Version C.1.1, October 2024
;               - Encode alphabet added.
;               - Bug corrections.
; ==================================================================================================


% include &MacPath&ConstDiv.inc

externdef BASE64_DEFAULT_ALPHABET:CHRA

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  Base64Encode
; Purpose:    Encode a data stream using the BASE64 algoritm. The output stream contains ANSI
;             characters from the passed alphabet (BASE64_DEFAULT_ALPHABET, BASE64_URL_ALPHABET)
; Arguments:  Arg1: -> Input data buffer.
;             Arg2: Input data size in BYTEs.
;             Arg3: Character alphabet used to encode the data. If NULL, BASE64_DEFAULT_ALPHABET
;                   is used. BASE64_URL_ALPHABET can be used to encode URL content.
; Return:     xax -> Buffer containing the encoded data. When no longer needed, it should be
;                    released using MemFree.
;             ecx = Encoded data size in BYTEs, always a multiple of 4*sizeof(CHR)
; Links:      https://en.wikipedia.org/wiki/Base64
;             https://datatracker.ietf.org/doc/html/rfc4648
; Note:       No ZTC is added to the encoded buffer.
;
; Layout:
;                    ———————————————————————————————————————————————
; Remaninder = 0    |   A   |   B   |   C   |   D   |   E   |   F   |
;                   |———————————————————————————————————————————————|
; 8R0               |  a  |  b  |  c  |  d  |  e  |  f  |  g  |  h  |
;                    ———————————————————————————————————————————————
;                    ———————————————————————————————————————————————
; Remaninder = 4    |   A   |   B   |   C   |   D   |   E   |XXXXXXX|   Data (X: don't touched BYTE)
;                   |———————————————————————————————————————————————|
; 6R4               |  a  |  b  |  c  |  d  |  e  |  f  |  g  |  =  |   Output chars ('=' padding)
;                    ———————————————————————————————————————————————
;                    ———————————————————————————————————————————————
; Remaninder = 2    |   A   |   B   |   C   |   D   |XXXXXXX|XXXXXXX|
;                   |———————————————————————————————————————————————|
; 5R2               |  a  |  b  |  c  |  d  |  e  |  f  |  =  |  =  |
;                    ———————————————————————————————————————————————

BASE64_PADDING  equ '='

B64StoreCharAtIndex macro Reg:req
  if TARGET_STR_TYPE eq STR_TYPE_ANSI
    mov al, [xcx + Reg]
    stosb
  else
    movzx ax, BYTE ptr [xcx + Reg]
    stosw
  endif
endm

B64FillPadding macro Count:req
  mov $SubReg(eax, sizeof(CHR)), '='
  if Count eq 1
    stosc
  else
    mov ecx, Count
    rep stosc
  endif
endm

.code
align ALIGN_CODE
ProcName proc uses xbx xdi xsi pDataBuffer:POINTER, dDataSize:DWORD, pAlphabet:POINTER
  _ProcName_ textequ <%ProcName>
  ArgReg pDataBuffer:xcx, dDataSize:edx
  LocReg pEncodedDataBuffer:r10
  local dEncodedDataSize:DWORD

  mov dEncodedDataSize, 0
  mov $LocReg(pEncodedDataBuffer), NULL
  mov eax, $ArgReg(dDataSize)
  mov xsi, $ArgReg(pDataBuffer)
  .if eax != 0 && xsi != NULL
    shl eax, 2
    cDivMod 3
    mov ebx, eax                                        ;ebx always > 0, edx rem from division by 3!
    add eax, edx
    .if edx == 1
      add eax, 2
    .endif
    mov dEncodedDataSize, eax
    MemAlloc eax
    .if xax
      mov xcx, pAlphabet
      mov $LocReg(pEncodedDataBuffer), xax
      test xcx, xcx
      lea xdx, BASE64_DEFAULT_ALPHABET
      mov xdi, xax
      cmovz xcx, xdx
      .while TRUE
        movzx eax, CHRA ptr [xsi]
        mov edx, eax
        shr eax, 2
        B64StoreCharAtIndex xax
        dec ebx
        jz @@Remainder_1

        inc xsi
        movzx eax, CHRA ptr [xsi]
        mov ah, dl
        shr eax, 4
        and eax, 0111111b
        B64StoreCharAtIndex xax
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
        jz @@Quit
      .endw

    @@Remainder_1:
      shl edx, 4
      and edx, 0110000b
      B64StoreCharAtIndex xdx
      B64FillPadding 2                                  ;"==" Padding
      jmp @@Quit

    @@Remainder_2:
      xor edx, edx
      mov dh, CHRA ptr [xsi]
      shr edx, 6
      and edx, 0111100b
      B64StoreCharAtIndex xdx
      B64FillPadding 1

    @@Quit:
      mov xax, $LocReg(pEncodedDataBuffer)
    .endif
  .endif

@@Exit:
  mov ecx, dEncodedDataSize
  ret
ProcName endp
