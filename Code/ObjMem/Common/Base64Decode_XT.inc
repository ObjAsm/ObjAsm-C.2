; ==================================================================================================
; Title:      Base64Encode_X.inc
; Author:     G. Friedrich
; Version:    C.1.1
; Notes:      Version C.1.0, November 2023.
;               - First release.
;               - Bitness neutral code.
;             Version C.1.1, October 2024
;               - Decode table added.
;               - Bug corrections.
; ==================================================================================================


externdef BASE64_DEFAULT_DECODE_TABLE:BYTE

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  Base64Decode
; Purpose:    Decode a CHR stream using the BASE64 algoritm.
; Arguments:  Arg1: -> Encoded CHR data buffer.
;             Arg2: Encoded data size in BYTEs (always a multiple of 4*sizeof(CHR)).
;             Arg3: Decode table. If NULL, BASE64_DEFAULT_DECODE_TABLE is used.
;                   BASE64_URL_DECODE_TABLE can be used to decode URL content.
; Return:     xax -> Decoded data. When no longer needed, it should be freed using MemFree.
;             ecx = Decoded data size in BYTEs.
;             On error, xax and ecx are zero.
; Links:      https://en.wikipedia.org/wiki/Base64
;             https://datatracker.ietf.org/doc/html/rfc4648
;
; Layout:
;                    ———————————————————————————————————————————————
;                   |  a  |  b  |  c  |  d  |  e  |  f  |  g  |  h  |
;                   |———————————————————————————————————————————————|
;                   |   A   |   B   |   C   |   D   |   E   |   F   |
;                    ———————————————————————————————————————————————
;                    ———————————————————————————————————————————————
;                   |  a  |  b  |  c  |  d  |  e  |  f  |  g  |  =  |   Input chars (= means 3Dh)
;                   |———————————————————————————————————————————————
;                   |   A   |   B   |   C   |   D   |   E   |           Output data
;                    ———————————————————————————————————————
;                    ———————————————————————————————————————————————
;                   |  a  |  b  |  c  |  d  |  e  |  f  |  =  |  =  |
;                   |———————————————————————————————————————————————
;                   |   A   |   B   |   C   |   D   |
;                    ———————————————————————————————

BASE64_PADDING  equ '='

B64GetCharInto macro Reg32:req
  movzx Reg32, CHR ptr [xsi]
  if TARGET_STR_TYPE eq STR_TYPE_WIDE
    cmp Reg32, 255                                      ;Valid alphabet character?
    jbe @@Error
  endif
  movzx Reg32, BYTE ptr [$SubReg(Reg32, @WordSize) + xbx]
  cmp Reg32, 255                                        ;Valid alphabet character?
  jz @@Error
endm

B64GetChar2Into macro Reg32:req
  movzx Reg32, CHR ptr [xsi]
  if TARGET_STR_TYPE eq STR_TYPE_WIDE
    cmp Reg32, 255                                      ;Valid alphabet character?
    jbe @@Error
  endif
  .break .if Reg32 == BASE64_PADDING                    ;Padding character?
  movzx Reg32, BYTE ptr [$SubReg(Reg32, @WordSize) + xbx]
  cmp Reg32, 255                                        ;Valid alphabet character?
  jz @@Error
endm

.code
align ALIGN_CODE
ProcName proc uses xbx xdi xsi pEncDataBuffer:POINTER, dEncDataSize:DWORD, pDecodeTable:POINTER
  _ProcName_ textequ <%ProcName>
  ArgReg pEncDataBuffer:xcx, dEncDataSize:edx, pDecodeTable:R8
  LocReg dCount:r10d
  local pDecodedDataBuffer:POINTER, dDecodedDataSize:DWORD

  mov dDecodedDataSize, 0
  mov pDecodedDataBuffer, NULL
  mov eax, $ArgReg(dEncDataSize)
  mov xsi, $ArgReg(pEncDataBuffer)
  .if eax != 0 && xsi != NULL
    lea eax, [2*eax + eax]
    shr eax, 2
    mov dDecodedDataSize, eax
    mov $LocReg(dCount), eax
    mov xbx, $ArgReg(pDecodeTable)
    MemAlloc eax
    .if xax
      mov pDecodedDataBuffer, xax
      test xbx, xbx
      lea xdx, BASE64_DEFAULT_DECODE_TABLE
      mov xdi, xax
      cmovz xbx, xdx
      .while TRUE
        B64GetCharInto edx
        add xsi, sizeof(CHR)
        B64GetCharInto eax
        mov ecx, eax
        shl edx, 2
        shr eax, 4
        or eax, edx
        stosb
        dec $LocReg(dCount)

        add xsi, sizeof(CHR)
        B64GetChar2Into eax
        mov edx, eax
        and ecx, 1111b
        shl ecx, 4
        shr eax, 2
        or eax, ecx
        stosb
        dec $LocReg(dCount)

        add xsi, sizeof(CHR)
        B64GetChar2Into eax
        mov ecx, eax
        shl edx, 6
        or eax, edx
        stosb
        dec $LocReg(dCount)
        .break .if ZERO?
        add xsi, sizeof(CHR)
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
ProcName endp
