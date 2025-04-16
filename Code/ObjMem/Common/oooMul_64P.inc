; ==================================================================================================
; Title:      oooMul_64P.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, March 2024.
;               - First release.
;               - Platform independent code.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Procedure:  uoooMul/soooMul
; Purpose:    Multiply 2 signed/unsigned OWORDs.
;             (128 bit) Multiplicand multiplied by (128 bit) Multiplier = (128 bit) Product. 
; Arguments:  Arg1: Multiplicand low signed/unsigned word.
;             Arg2: Multiplicand high signed/unsigned word.
;             Arg3: Multiplier low signed/unsigned word.
;             Arg4: Multiplier high signed/unsigned word.
; Return:     rdx:rax = Signed/Unsigned Product.
; Note:       Both signed and unsigned routines are the same, since multiply's
;             work out the same in 2's complement.

.code
align ALIGN_CODE
ProcName proc uses rbx qMultiplicandLo:TypeArg, qMultiplicandHi:TypeArg, \
                       qMultiplierLo:TypeArg, qMultiplierHi:TypeArg
  mov rax, qMultiplicandHi
  mov rcx, qMultiplierHi
  or rcx, rax                                           ;Test for both hi-words zero.
  mov rcx, qMultiplierLo
  jnz short hard                                        ;both are zero, just mul Lo-words

  mov rax, qMultiplicandLo
  mul rcx

  ret

hard:
  mul rcx                                               ;eax = qMultiplicandHi, ecx = qMultiplierLo
  mov rbx, rax                                          ;Save result

  mov rax, qMultiplicandLo
  mul qMultiplierHi                                     ;qMultiplicandLo*qMultiplierHi
  add rbx, rax                                          ;rbx = ((qMultiplicandLo * qMultiplierHi) +
                                                        ;       (qMultiplicandHi * qMultiplierLo))
  mov rax, qMultiplicandLo                              ;rcx = qMultiplierLo
  mul rcx                                               ;So rdx:rax = qMultiplicandLo*qMultiplierLo
  add rdx, rbx                                          ;Now edx has all the Lo-word*hi-word stuff

  ret
ProcName endp
