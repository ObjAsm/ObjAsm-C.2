; ==================================================================================================
; Title:      xword2base_TX.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, November 2024.
;               - First release.
;               - Bitness neutral code.
;             Original proc UINT64__Baseform
;             Modification from bitRAKE's fasmg_playground
;             https://github.com/bitRAKE/fasmg_playground/blob/master/string/baseform.asm
;==================================================================================================



; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  xword2base
; Purpose:    Convert an sxword/xword to a defined base.
; Arguments:  Arg1: -> Buffer
;             Arg2: Number
;             Arg3: Base.
; Return:     xax -> Transformed number to base x.
;             ecx = BYTEs contained in the buffer, including the ZTC.

.const
align 64
DIGIT_TABLE CHR '0','1','2','3','4','5','6','7','8','9'
            CHR 'A','B','C','D','E','F','G','H','I','J','K','L','M'
            CHR 'N','O','P','Q','R','S','T','U','V','W','X','Y','Z'
            CHR  0 dup(@WordSize - sizeof(CHR))       ;Ensure no access violation 


.code
align ALIGN_CODE
ProcName proc uses xbx xdi pBuffer:POINTER, xInput:XWORD, dBase:DWORD
  mov xax, xInput
  mov ecx, dBase
  mov xdi, pBuffer 
  lea xbx, DIGIT_TABLE
  if Signed
    mov xdx, BIT_SIGN
    test xax, xdx
    .if !ZERO?
      mov CHR ptr [xdi], "-"
      add xdi, sizeof(CHR)
      neg xax
    .endif
  endif
  push 0                                                 ;Push ZTC
  .repeat
    xor edx, edx
    div xcx
    push XWORD ptr [xbx + xdx*sizeof(CHR)]
    test xax, xax
  .until ZERO?
  xor ecx, ecx
  .repeat
    pop xax
    add ecx, sizeof(CHR)
    stosc
    test al, al
  .until ZERO?
  sub xdi, pBuffer                                       ;Return the number of BYTEs in the buffer,
  mov ecx, edi                                           ;including the ZTC
  mov xax, xdi                                           ;Return -> Buffer  
  ret
ProcName endp
