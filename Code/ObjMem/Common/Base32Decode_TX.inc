; ==================================================================================================
; Title:      Base32Encode_X.inc
; Author:     G. Friedrich
; Version:    C.1.1
; Notes:      Version C.1.0, November 2023.
;               - First release.
;               - Bitness neutral code.
;             Version C.1.1, October 2024
;               - Decode table added.
;               - Bug corrections.
; ==================================================================================================


externdef BASE32_DEFAULT_DECODE_TABLE:BYTE

; --------------------------------------------------------------------------------------------------
; Procedure:  Base32Decode
; Purpose:    Decode a CHR stream using the BASE32 algoritm.
; Arguments:  Arg1: -> Encoded CHR data buffer.
;             Arg2: Encoded data size in BYTEs (always a multiple of 8*sizeof(CHR)).
;             Arg3: Decode table. If NULL, BASE32_DEFAULT_DECODE_TABLE is used.
;                   BASE32_HEX_DECODE_TABLE can be used to decode special content.
; Return:     xax -> Decoded data. When no longer needed, it should be freed using MemFree.
;             ecx = Decoded data size in BYTEs.
;             On error, xax and ecx are zero.
; Links:      https://en.wikipedia.org/wiki/Base32
;             https://datatracker.ietf.org/doc/html/rfc4648
;
; Layout:
;                    ---------------------------------------
;                   | a  | b  | c  | d  | e  | f  | g  | h  |
;                   |---------------------------------------
;                   |   A   |   B   |   C   |   D   |   E   |
;                    ---------------------------------------
;                    ---------------------------------------
;                   | a  | b  | c  | d  | e  | f  | g  | =  |   Input chars (= means 3Dh)
;                   |---------------------------------------
;                   |   A   |   B   |   C   |   D   |           Output data
;                    -------------------------------
;                    ---------------------------------------
;                   | a  | b  | c  | d  | e  | =  | =  | =  |
;                   |---------------------------------------
;                   |   A   |   B   |   C   |
;                    -----------------------
;                    ---------------------------------------
;                   | a  | b  | c  | d  | =  | =  | =  | =  |
;                   |---------------------------------------
;                   |   A   |   B   |
;                    ---------------
;                    ---------------------------------------
;                   | a  | b  | =  | =  | =  | =  | =  | =  |
;                   |---------------------------------------
;                   |   A   |
;                    -------

BASE32_PADDING  equ '='

B32GetCharInto macro Reg32:req
  movzx Reg32, CHR ptr [xsi]
  if TARGET_STR_TYPE eq STR_TYPE_WIDE
    cmp Reg32, 255                                      ;Valid alphabet character?
    jbe @@Error
  endif
  movzx Reg32, BYTE ptr [$SubReg(Reg32, @WordSize) + xbx]
  cmp Reg32, 255                                        ;Valid alphabet character?
  jz @@Error
endm

B32GetChar2Into macro Reg32:req
  movzx Reg32, CHR ptr [xsi]
  if TARGET_STR_TYPE eq STR_TYPE_WIDE
    cmp Reg32, 255                                      ;Valid alphabet character?
    jbe @@Error
  endif
  .break .if Reg32 == BASE32_PADDING                    ;Padding character?
  movzx Reg32, BYTE ptr [$SubReg(Reg32, @WordSize) + xbx]
  cmp Reg32, 255                                        ;Valid alphabet character?
  jz @@Error
endm

.code
align ALIGN_CODE
ProcName proc uses xbx xdi xsi pEncDataBuffer:POINTER, dEncDataSize:DWORD, pDecodeTable:POINTER
  _ProcName_ textequ <%ProcName>
  ArgReg pEncDataBuffer:xcx, dEncDataSize:edx, pDecodeTable:R8
  local pDecodedDataBuffer:POINTER, dDecodedDataSize:DWORD, dCount:DWORD

  mov dDecodedDataSize, 0
  mov pDecodedDataBuffer, NULL
  mov eax, $ArgReg(dEncDataSize)
  mov xsi, $ArgReg(pEncDataBuffer)
  .if eax != 0 && xsi != NULL
    lea eax, [4*eax + eax]
    shr eax, 3
    mov dDecodedDataSize, eax
    mov dCount, eax
    mov xbx, $ArgReg(pDecodeTable)
    MemAlloc eax
    .if xax
      mov pDecodedDataBuffer, xax
      test xbx, xbx
      lea xdx, BASE32_DEFAULT_DECODE_TABLE
      mov xdi, xax
      cmovz xbx, xdx
      .while TRUE
        B32GetCharInto edx
        add xsi, sizeof(CHR)
        B32GetCharInto eax
        mov ecx, eax
        shl edx, 3
        shr eax, 2
        or eax, edx
        stosb
        dec dCount

        add xsi, sizeof(CHR)
        B32GetChar2Into edx
        shl ecx, 6
        shl edx, 1
        or ecx, edx
        add xsi, sizeof(CHR)
        B32GetCharInto eax
        mov edx, eax
        shr eax, 4
        or eax, ecx
        stosb
        dec dCount

        add xsi, sizeof(CHR)
        B32GetChar2Into eax
        mov ecx, eax
        shl edx, 4
        shr eax, 1
        or eax, edx
        stosb
        dec dCount

        add xsi, sizeof(CHR)
        shl ecx, 7
        B32GetChar2Into eax
        add xsi, sizeof(CHR)
        shl eax, 2
        B32GetCharInto edx
        or eax, ecx
        mov ecx, edx
        shr edx, 3
        or eax, edx
        stosb
        dec dCount

        add xsi, sizeof(CHR)
        B32GetChar2Into eax
        shl ecx, 5
        or eax, ecx
        stosb
        dec dCount

        .break .if ZERO?
        add xsi, sizeof(CHR)
      .endw
    .endif
  .endif

  mov ecx, dDecodedDataSize
  sub ecx, dCount
  mov xax, pDecodedDataBuffer
  ret

@@Error:
  MemFree pDecodedDataBuffer
  xor eax, eax
  xor ecx, ecx
  ret
ProcName endp
