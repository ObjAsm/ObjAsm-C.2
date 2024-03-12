; ==================================================================================================
; Title:      sqwordMul.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, March 2024.
;               - First release.
;               - Inspired llmul.asm (nt5src-master).
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  sqwordMul
; Purpose:    Multiply 2 signed/unsigned QWORDs.
; Arguments:  Arg1: Multiplicand.
;             Arg2: Multiplier.
; Return:     edx:eax = Product.
; Note:       Both signed and unsigned routines are the same, since multiply's
;             work out the same in 2's complement.

HIGH_OFFSET = sizeof(DWORD)

align ALIGN_CODE
sqwordMul proc uses ebx sqMultiplicand:SQWORD, sqMultiplier:SQWORD
  mov eax, SDWORD ptr (sqMultiplicand + HIGH_OFFSET)
  mov ecx, SDWORD ptr (sqMultiplier + HIGH_OFFSET)
  or ecx, eax                                           ;Test for both hi-words zero.
  mov ecx, SDWORD ptr (sqMultiplier)
  jnz short hard                                        ;both are zero, just mul ALO and BLO

  mov eax, SDWORD ptr (sqMultiplicand)
  mul ecx

  ret

hard:
  mul ecx                                               ;eax has AHI, ecx has BLO, so AHI * BLO
  mov ebx, eax                                          ;Save result

  mov eax, SDWORD ptr (sqMultiplicand)
  mul SDWORD ptr (sqMultiplier + HIGH_OFFSET)           ;ALO * BHI
  add ebx, eax                                          ;ebx = ((ALO * BHI) + (AHI * BLO))

  mov eax, SDWORD ptr (sqMultiplicand)                  ;ecx = BLO
  mul ecx                                               ;So edx:eax = ALO*BLO
  add edx, ebx                                          ;Now edx has all the LO*HI stuff

  ret
sqwordMul endp

end

