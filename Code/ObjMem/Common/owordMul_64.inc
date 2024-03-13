; ==================================================================================================
; Title:      owordMul_64.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, March 2024.
;               - First release.
; ==================================================================================================


.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  uowordMul/sowordMul
; Purpose:    Multiply 2 signed/unsigned OWORDs.
; Arguments:  Arg1: Multiplicand.
;             Arg2: Multiplier.
; Return:     rdx:rax = Product.
; Note:       Both signed and unsigned routines are the same, since multiply's
;             work out the same in 2's complement.

align ALIGN_CODE
ProcName proc uses rbx qMultiplicandLo:TypeArg, qMultiplicandHi:TypeArg, \
                       qMultiplierLo:TypeArg, qMultiplierHi:TypeArg
  mov rax, qMultiplicandHi
  mov rcx, qMultiplierHi
  or ecx, eax                                           ;Test for both hi-words zero.
  mov rcx, qMultiplierLo
  jnz short hard                                        ;both are zero, just mul ALO and BLO

  mov rax, qMultiplicandLo
  mul rcx

  ret

hard:
  mul rcx                                               ;eax has AHI, ecx has BLO, so AHI * BLO
  mov rbx, rax                                          ;Save result

  mov rax, qMultiplicandLo
  mul qMultiplierHi                                     ;ALO * BHI
  add rbx, rax                                          ;rbx = ((ALO * BHI) + (AHI * BLO))

  mov rax, qMultiplicandLo                              ;rcx = BLO
  mul rcx                                               ;So rdx:rax = ALO*BLO
  add rdx, rbx                                          ;Now edx has all the LO*HI stuff

  ret
ProcName endp
