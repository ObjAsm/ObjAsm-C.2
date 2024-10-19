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

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  Base32Decode
; Purpose:    Decode a data stream using the BASE32 algoritm.
; Arguments:  Arg1: -> Encoded data buffer.
;             Arg2: Encoded data size in BYTEs (always a multiple of 8).
;             Arg3: Decode table. If NULL, BASE32_DEFAULT_DECODE_TABLE is used.
;                   BASE32_HEX_DECODE_TABLE can be used to decode special content.
; Return:     xax -> Decoded data. When no longer needed, it should be freed using MemFree.
;             ecx = Decoded data size in BYTEs.
;             On error, xax and ecx are zero.
; Links:      https://en.wikipedia.org/wiki/Base32
;             https://datatracker.ietf.org/doc/html/rfc4648
;
; Layout:
;                    ———————————————————————————————————————
;                   | a  | b  | c  | d  | e  | f  | g  | h  |
;                   |———————————————————————————————————————
;                   |   A   |   B   |   C   |   D   |   E   |
;                    ———————————————————————————————————————
;                    ———————————————————————————————————————
;                   | a  | b  | c  | d  | e  | f  | g  | =  |   Input chars (= means 3Dh)
;                   |———————————————————————————————————————
;                   |   A   |   B   |   C   |   D   |           Output data
;                    ———————————————————————————————
;                    ———————————————————————————————————————
;                   | a  | b  | c  | d  | e  | =  | =  | =  |
;                   |———————————————————————————————————————
;                   |   A   |   B   |   C   |
;                    ———————————————————————
;                    ———————————————————————————————————————
;                   | a  | b  | c  | d  | =  | =  | =  | =  |
;                   |———————————————————————————————————————
;                   |   A   |   B   |
;                    ———————————————
;                    ———————————————————————————————————————
;                   | a  | b  | =  | =  | =  | =  | =  | =  |
;                   |———————————————————————————————————————
;                   |   A   |
;                    ———————

BASE32_PADDING  equ '='

B32GetCharInto macro Reg32:req
  movzx Reg32, CHRA ptr [xsi]
  movzx Reg32, BYTE ptr [$SubReg(Reg32, @WordSize) + xbx]
  cmp Reg32, 255                                        ;Valid alphabet character?
  jz @@Error
endm

B32GetChar2Into macro Reg32:req
  movzx Reg32, CHRA ptr [xsi]
  .break .if Reg32 == BASE32_PADDING                    ;Padding character?
  movzx Reg32, BYTE ptr [$SubReg(Reg32, @WordSize) + xbx]
  cmp Reg32, 255                                        ;Valid alphabet character?
  jz @@Error
endm

.code
align ALIGN_CODE
Base32Decode proc uses xbx xdi xsi pEncDataBuffer:POINTER, dEncDataSize:DWORD, pDecodeTable:POINTER
  local pDecodedDataBuffer:POINTER, dDecodedDataSize:DWORD
  _ProcName_ textequ <Base32Decode>
  ArgReg pEncDataBuffer:xcx, dEncDataSize:edx, pDecodeTable:R8
  LocReg dCount:r10d

  mov dDecodedDataSize, 0
  mov pDecodedDataBuffer, NULL
  mov eax, $ArgReg(dEncDataSize)
  mov xsi, $ArgReg(pEncDataBuffer)
  .if eax != 0 && xsi != NULL
    lea eax, [4*eax + eax]
    shr eax, 3
    mov dDecodedDataSize, eax
    mov $LocReg(dCount), eax
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
        inc xsi
        B32GetCharInto eax
        mov ecx, eax
        shl edx, 3
        shr eax, 2
        or eax, edx
        stosb
        dec $LocReg(dCount)

        inc xsi
        B32GetChar2Into edx
        shl ecx, 6
        shl edx, 1
        or ecx, edx
        inc xsi
        B32GetCharInto eax
        mov edx, eax
        shr eax, 4
        or eax, ecx
        stosb
        dec $LocReg(dCount)

        inc xsi
        B32GetChar2Into eax
        mov ecx, eax
        shl edx, 4
        shr eax, 1
        or eax, edx
        stosb
        dec $LocReg(dCount)

        inc xsi
        shl ecx, 7
        B32GetChar2Into eax
        inc xsi
        shl eax, 2
        B32GetCharInto edx
        or eax, ecx
        mov ecx, edx
        shr edx, 3
        or eax, edx
        stosb
        dec $LocReg(dCount)

        inc xsi
        B32GetChar2Into eax
        shl ecx, 5
        or eax, ecx
        stosb
        dec $LocReg(dCount)

        .break .if ZERO?
        inc xsi
      .endw
    .endif
  .endif

  mov ecx, dDecodedDataSize
  sub ecx, $LocReg(dCount)
  mov xax, pDecodedDataBuffer
  ret

@@Error:
  MemFree pDecodedDataBuffer
  xor eax, eax
  xor ecx, ecx
  ret
Base32Decode endp
