; ==================================================================================================
; Title:      qqqMul_32P.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, March 2024.
;               - First release.
;               - Platform independent code.
;               - Inspired llmul.asm (nt5src-master).
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Procedure:  uqqqMul/sqqqMul
; Purpose:    Multiply 2 signed/unsigned QWORDs.
;             (64 bit) Multiplicand multiplied by (64 bit) Multiplier = (64 bit) Product. 
; Arguments:  Arg1: Multiplicand low signed/unsigned word.
;             Arg2: Multiplicand high signed/unsigned word.
;             Arg3: Multiplier low signed/unsigned word.
;             Arg4: Multiplier high signed/unsigned word.
; Return:     edx:eax = Signed product.
; Note:       Both signed and unsigned routines are the same, since multiply's
;             work out the same in 2's complement.

.code
align ALIGN_CODE
ProcName proc uses ebx dMultiplicandLo:TypeArg, dMultiplicandHi:TypeArg, \
                       dMultiplierLo:TypeArg, dMultiplierHi:TypeArg
  mov eax, dMultiplicandHi
  mov ecx, dMultiplierHi
  or ecx, eax                                           ;Test for both hi-words zero.
  mov ecx, dMultiplierLo
  jnz short hard                                        ;Both are zero, just mul lo-words

  mov eax, dMultiplierLo
  mul ecx

  ret

hard:
  mul ecx                                               ;eax = dMultiplicandHi, ecx = dMultiplierLo
  mov ebx, eax                                          ;Save result

  mov eax, dMultiplierLo
  mul dMultiplierHi                                     ;dMultiplicandLo*dMultiplierHi
  add ebx, eax                                          ;ebx = ((dMultiplicandLo * dMultiplierHi) +
                                                        ;       (dMultiplicandHi * dMultiplierLo))
  mov eax, dMultiplierLo                                ;ecx = dMultiplierLo
  mul ecx                                               ;So edx:eax = dMultiplicandLo*dMultiplierLo
  add edx, ebx                                          ;Now edx has all the lo-word*hi-word stuff

  ret
ProcName endp
