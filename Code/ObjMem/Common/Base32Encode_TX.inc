; ==================================================================================================
; Title:      Base32Encode_X.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2024.
;               - First release.
;               - Bitness neutral code.
; ==================================================================================================


% include &MacPath&ConstDiv.inc

externdef BASE32_DEFAULT_ALPHABET:CHRA

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  Base32Encode
; Purpose:    Encode a data stream using the BASE32 algorithm. The output stream contains only
;             characters from the specified alphabet (BASE32_DEFAULT_ALPHABET, BASE32_URL_ALPHABET)
; Arguments:  Arg1: -> Input data buffer.
;             Arg2: Input data size in BYTEs.
;             Arg3: Character alphabet used to encode the data. If NULL, BASE32_DEFAULT_ALPHABET
;                   is used. BASE32_HEX_ALPHABET can be used to encode special content.
; Return:     xax -> Buffer containing the encoded data. When no longer needed, it should be
;                    released using MemFree.
;             ecx = Encoded data size in BYTEs, always a multiple of 8*sizeof(CHR)
; Links:      https://en.wikipedia.org/wiki/Base32
;             https://datatracker.ietf.org/doc/html/rfc4648
; Note:       No ZTC is added to the encoded buffer.
;
; Layout:
;                    ———————————————————————————————————————
; Remaninder = 0    |   A   |   B   |   C   |   D   |   E   |
;                   |———————————————————————————————————————
; 8R0               | a  | b  | c  | d  | e  | f  | g  | h  |
;                    ———————————————————————————————————————
;                    ———————————————————————————————————————
; Remaninder = 2    |   A   |   B   |   C   |   D   |XXXXXXX|   Data (X: don't touched BYTE)
;                   |———————————————————————————————————————|
; 6R2               | a  | b  | c  | d  | e  | f  | g  | =  |   Output chars ('=' padding)
;                    ———————————————————————————————————————
;                    ———————————————————————————————————————
; Remaninder = 4    |   A   |   B   |   C   |XXXXXXX|XXXXXXX|
;                   |———————————————————————————————————————|
; 4R4               | a  | b  | c  | d  | e  | =  | =  | =  |
;                    ———————————————————————————————————————
;                    ———————————————————————————————————————
; Remaninder = 1    |   A   |   B   |XXXXXXX|XXXXXXX|XXXXXXX|
;                   |———————————————————————————————————————
; 3R1               | a  | b  | c  | d  | =  | =  | =  | =  |
;                    ———————————————————————————————————————
;                    ———————————————————————————————————————
; Remaninder = 3    |   A   |XXXXXXX|XXXXXXX|XXXXXXX|XXXXXXX|
;                   |———————————————————————————————————————
; 1R3               | a  | b  | =  | =  | =  | =  | =  | =  |
;                    ———————————————————————————————————————

BASE32_PADDING  equ '='

.const
B32_ADD_TABLE label BYTE
  db 0, 5, 2, 7, 4

B32StoreCharAtIndex macro Reg:req
  if TARGET_STR_TYPE eq STR_TYPE_ANSI
    mov al, [xcx + Reg]
    stosb
  else
    movzx ax, BYTE ptr [xcx + Reg]
    stosw
  endif
endm

B32FillPadding macro Count:req
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
  mov eax, $ArgReg(dDataSize)
  mov xsi, $ArgReg(pDataBuffer)
  .if eax != 0 && xsi != NULL
    shl eax, 3
    cDivMod 5                                           ;edx = rem from division by 5!
    mov ecx, eax
    mov eax, edx
    lea xbx, B32_ADD_TABLE
    xlat
    add eax, ecx
    mov ebx, ecx                                        ;ebx always > 0
    mov dEncodedDataSize, eax
    MemAlloc eax
    .if xax
      mov xcx, pAlphabet
      mov $LocReg(pEncodedDataBuffer), xax
      test xcx, xcx
      lea xdx, BASE32_DEFAULT_ALPHABET
      mov xdi, xax
      cmovz xcx, xdx
      .while TRUE
        movzx eax, CHRA ptr [xsi]
        inc xsi
        mov edx, eax
        shr eax, 3
        B32StoreCharAtIndex xax
        dec ebx
        jz @@Remainder_1

        lodsb
        mov ah, dl
        mov dl, al
        shr ax, 6
        and xax, 011111b
        B32StoreCharAtIndex xax
        dec ebx

        mov al, dl
        shr al, 1
        and xax, 011111b
        B32StoreCharAtIndex xax
        dec ebx
        jz @@Remainder_3

        lodsb
        mov ah, dl
        mov dl, al
        shr ax, 4
        and xax, 011111b
        B32StoreCharAtIndex xax
        dec ebx
        jz @@Remainder_4

        lodsb
        mov ah, dl
        mov dl, al
        shr ax, 7
        and xax, 011111b
        B32StoreCharAtIndex xax
        dec ebx

        mov al, dl
        shr al, 2
        and xax, 011111b
        B32StoreCharAtIndex xax
        dec ebx
        jz @@Remainder_6

        lodsb
        mov ah, dl
        mov dl, al
        shr ax, 5
        and xax, 011111b
        mov al, [xcx + xax]
        stosc
        dec ebx

        mov al, dl
        and xax, 011111b
        B32StoreCharAtIndex xax
        dec ebx
        jz @@Quit
      .endw

    @@Remainder_1:
      lodsb
      shl dl, 2
      and xdx, 011100b
      B32StoreCharAtIndex xdx
      B32FillPadding 6                                  ;"======" Padding
      jmp @@Quit

    @@Remainder_3:
      shl dl, 4
      and xdx, 010000b
      B32StoreCharAtIndex xdx
      B32FillPadding 4                                  ;"====" Padding
      jmp @@Quit
      
    @@Remainder_4:
      shl dl, 1
      and xdx, 011110b
      B32StoreCharAtIndex xdx
      B32FillPadding 3                                  ;"===" Padding
      jmp @@Quit

    @@Remainder_6:
      shl dl, 3
      and xdx, 011000b
      B32StoreCharAtIndex xdx
      B32FillPadding 1                                  ;"=" Padding

@@Quit:
      mov xax, $LocReg(pEncodedDataBuffer)
    .endif
  .endif

  mov ecx, dEncodedDataSize
  ret
ProcName endp
