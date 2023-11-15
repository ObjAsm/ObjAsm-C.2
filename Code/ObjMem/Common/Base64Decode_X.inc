; ==================================================================================================
; Title:      Base64Encode_X.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, November 2023.
;               - First release.
;               - Bitness neutral code.
; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  Base64Decode
; Purpose:    Decode a data stream using the BASE64 algoritm.
; Arguments:  Arg1: -> Encoded data buffer.
;             Arg2: Encoded data size in BYTEs (always a multiple of 4).
; Return:     xax -> Decoded buffer. When no longer needed, it should be freed using MemFree.
;             ecx = Decoded buffer size in BYTEs.
; Links:      https://en.wikipedia.org/wiki/Base64
;             https://datatracker.ietf.org/doc/html/rfc4648
;
; Layout:
;                    ———————————————————————————————————————————————
;                   |  Q  |  U  |  J  |  D  |  R  |  E  |  U  |  =  |   Digits (= means 3Dh)
;                   |———————————————————————————————————————————————|
;                   |   A   |   B   |   C   |   D   |   E   |XXXXXXX|
;                    ———————————————————————————————————————————————
;                    ———————————————————————————————————————————————
;                   |  Q  |  U  |  J  |  D  |  R  |  A  |  =  |  =  |
;                   |———————————————————————————————————————————————|
;                   |   A   |   B   |   C   |   D   |XXXXXXX|XXXXXXX|
;                    ———————————————————————————————————————————————
;                    ———————————————————————————————————————————————
;                   |  Q  |  U  |  J  |  D  |  R  |  E  |  V  |  G  |
;                   |———————————————————————————————————————————————|
;                   |   A   |   B   |   C   |   D   |   E   |   F   |
;                    ———————————————————————————————————————————————

.const
BASE64_DECODE_TABLE label BYTE
  ;  NUL SOH STX ETX EDT ENQ ACK BEL  BS TAB  LF  VF  FF  CR  SO  SI
  db 000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000
  ;  DLE DC1 DC2 DC3 DC4 NAK SYN ETB CAN BM  SUB ESC FS  GS  RS  US
  db 000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000
  ;  SPC   !   "   #   $   %   &   '   (   )   *   +   ,   -   .   /
  db 000,000,000,000,000,000,000,000,000,000,000,062,000,000,000,063  ;+,/
  ;    0   1   2   3   4   5   6   7   8   9   :   ;   <   =   >   ?
  db 052,053,054,055,056,057,058,059,060,061,000,000,000,000,000,000  ;0..9
  ;    @   A   B   C   D   E   F   G   H   I   J   K   L   M   N   O
  db 000,000,001,002,003,004,005,006,007,008,009,010,011,012,013,014  ;A..O
  ;    P   Q   R   S   T   U   V   W   X   Y   Z   [   \   ]   ^   _
  db 015,016,017,018,019,020,021,022,023,024,025,000,000,000,000,000  ;P..Z
  ;    `   a   b   c   d   e   f   g   h   i   j   k   l   m   n   o
  db 000,026,027,028,029,030,031,032,033,034,035,036,037,038,039,040  ;a..o
  ;    p   q   r   s   t   u   v   w   x   y   z   {   |   }   ~
  db 041,042,043,044,045,046,047,048,049,050,051,000,000,000,000,000  ;p..z
  db 000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000
  db 000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000
  db 000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000
  db 000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000
  db 000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000
  db 000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000
  db 000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000
  db 000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000

B64GetCharInto macro Reg32:req
  movzx Reg32, CHRA ptr [xsi]
  movzx Reg32, BYTE ptr [$SubReg(Reg32, @WordSize)  + xbx]
endm

.code
Base64Decode proc uses xbx xdi xsi pDataBuffer:POINTER, dDataSize:DWORD
  local pDecodedDataBuffer:POINTER, dDecodedDataSize:DWORD, dCount:DWORD

  mov dDecodedDataSize, 0
  mov pDecodedDataBuffer, NULL
  mov eax, dDataSize
  .if eax != 0 && pDataBuffer != NULL
    lea eax, [2*eax + eax]
    shr eax, 2
    mov dDecodedDataSize, eax
    mov dCount, eax
    lea xbx, BASE64_DECODE_TABLE
    MemAlloc eax
    .if xax
      mov pDecodedDataBuffer, xax
      mov xsi, pDataBuffer
      mov xdi, xax
      .while TRUE
        B64GetCharInto edx
        inc xsi
        B64GetCharInto eax
        mov ecx, eax
        shl edx, 2
        shr eax, 4
        or eax, edx
        stosb
        
        inc xsi
        B64GetCharInto eax
        mov edx, eax
        and ecx, 1111b 
        shl ecx, 4
        shr eax, 2
        or eax, ecx
        stosb
        
        inc xsi
        B64GetCharInto eax
        mov ecx, eax
        shl edx, 6
        or eax, edx
        stosb
        sub dCount, 3
        .break .if ZERO?
        inc xsi
      .endw
    .endif
  .endif

  .if ecx == -4
    dec dDecodedDataSize
    .if CHRA ptr [xsi - 1] == '='
      dec dDecodedDataSize
    .endif
  .endif

  mov xax, pDecodedDataBuffer
  mov ecx, dDecodedDataSize
  ret
Base64Decode endp
