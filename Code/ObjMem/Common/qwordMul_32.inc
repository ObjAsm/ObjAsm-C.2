; ==================================================================================================
; Title:      qwordMul_32.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, March 2024.
;               - First release.
;               - Inspired llmul.asm (nt5src-master).
; ==================================================================================================


.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  uqwordMul/sqwordMul
; Purpose:    Multiply 2 signed/unsigned QWORDs.
; Arguments:  Arg1: Multiplicand.
;             Arg2: Multiplier.
; Return:     adx:eax = Product.
; Note:       Both signed and unsigned routines are the same, since multiply's
;             work out the same in 2's complement.

HIGH_OFFSET = sizeof(DWORD)

align ALIGN_CODE
ProcName proc uses ebx qMultiplicand:TypeArg, qMultiplier:TypeArg
  mov eax, DWORD ptr (qMultiplicand + HIGH_OFFSET)
  mov ecx, DWORD ptr (qMultiplier + HIGH_OFFSET)
  or ecx, eax                                           ;Test for both hi-words zero.
  mov ecx, DWORD ptr (qMultiplier)
  jnz short hard                                        ;both are zero, just mul ALO and BLO

  mov eax, DWORD ptr (qMultiplicand)
  mul ecx

  ret

hard:
  mul ecx                                               ;eax has AHI, ecx has BLO, so AHI * BLO
  mov ebx, eax                                          ;Save result

  mov eax, DWORD ptr (qMultiplicand)
  mul DWORD ptr (qMultiplier + HIGH_OFFSET)             ;ALO * BHI
  add ebx, eax                                          ;ebx = ((ALO * BHI) + (AHI * BLO))

  mov eax, DWORD ptr (qMultiplicand)                    ;ecx = BLO
  mul ecx                                               ;So edx:eax = ALO*BLO
  add edx, ebx                                          ;Now edx has all the LO*HI stuff

  ret
ProcName endp
