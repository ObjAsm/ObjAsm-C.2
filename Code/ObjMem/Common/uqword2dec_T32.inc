; ==================================================================================================
; Title:      uqword2dec_T32.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, May 2022
;               - First release.
; Links       https://publik.tuwien.ac.at/files/publik_287602.pdf
;             https://calc.penjee.com/  128 hex calculator
;             https://de.wikipedia.org/wiki/Integer_(Datentyp)
; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  uqword2decA / uqword2decW 
; Purpose:    Convert a signed QWORD to its decimal string representation.
; Arguments:  Arg1: -> Destination string buffer.
;             Arg2: QWORD value.
; Return:     eax = Number of BYTEs copied to the destination buffer, including the ZTC.

.code
align ALIGN_CODE
ProcName proc uses ebx edi esi pBuffer:POINTER, qValue:QWORD
  local cBuffer[2*24*sizeof(CHR)]:CHR                     ;21 chars + 3 filler for alignment
                                                          ;All 2x to get safe for final copy
  mov CHR ptr cBuffer[24*sizeof(CHR)], 0
  lea edi, cBuffer[22*sizeof(CHR)]
  mov edx, DWORD ptr [qValue + 4]
  mov eax, DWORD ptr [qValue]
  mov ebx, 100                                            ;Divisor

  .repeat                                                 ;Main loop
    ;Divide by 100
    .if edx == 0                                          ;Only one division needed?
      mov edx, 51EB851Fh
      mul edx
      shrd eax, edx, 5
      mov ecx, edx                                        ;Save edx
      inc eax
      mul ebx
      mov eax, ecx
      %mov ecx, [offset TwoDecDigitTable&TARGET_STR_AFFIX + sizeof(DCHR)*edx]
      shr eax, 5
      xor edx, edx                                        ;edx = quot.-hi(quotient in edx::eax)
    .else
      ;qddiv
      mov ecx, eax                                        ;Save dividend-lo in ecx
      mov eax, edx                                        ;Get dividend-hi
      xor edx, edx                                        ;Zero extend it into edx::eax
      div ebx                                             ;Quotient-hi in eax
      mov esi, eax                                        ;ecx = quotient-hi, eax =dividend-lo
      mov eax, ecx
      div ebx                                             ;eax = quotient-lo
      %mov ecx, [offset TwoDecDigitTable&TARGET_STR_AFFIX + sizeof(DCHR)*edx]
      mov edx, esi                                        ;edx = quot.-hi(quotient in edx::eax)
    .endif

    ;Store character
    mov [edi], $SubReg(ecx, sizeof(DCHR))
    sub edi, sizeof(DCHR)

    ;Check for last decimal digit 
    mov esi, eax
    or esi, edx
  .until ZERO?
  add edi, sizeof(CHR)

  .if cl == '0'
    add edi, sizeof(CHR)                                  ;Discard leading '0' character
  .endif

  ;Copy 21 Chars
  mov ebx, pBuffer
  lea eax, cBuffer[24*sizeof(CHR)]
  if TARGET_STR_TYPE eq STR_TYPE_ANSI                     ;Copy 21 BYTEs
    movups xmm0, [edi + 1]                                ;16 BYTEs
    mov edx, [edi + 17]                                   ;4 BYTEs
    mov cl, [edi + 33]                                    ;1 byte
    movups [ebx], xmm0
    mov [ebx + 16], edx
    mov [ebx + 32], cl
  else                                                    ;Copy 42 BYTEs
    movups xmm0, [edi + 2]                                ;16 BYTEs
    movups xmm1, [edi + 18]                               ;16 BYTEs
    movq xmm2, [edi + 34]                                 ;8 BYTEs
    mov cx, [edi + 42]                                    ;2 BYTEs
    movups [ebx], xmm0
    movups [ebx + 16], xmm1
    movq [ebx + 32], xmm2
    mov [ebx + 40], cx
  endif
  sub eax, edi                                            ;Get BYTE count incl. ZTC

  ret
ProcName endp
