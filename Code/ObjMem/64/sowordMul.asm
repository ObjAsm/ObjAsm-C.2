; ==================================================================================================
; Title:      sowordMul.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, March 2024.
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  sowordMul
; Purpose:    Multiply 2 signed OWORDs.
; Arguments:  Arg1: Multiplicand.
;             Arg2: Multiplier.
; Return:     rdx:rax = Product. OF set on overflow.

align ALIGN_CODE
sowordMul proc uses rbx sqMultiplicandLo:SQWORD, sqMultiplicandHi:SQWORD, \
                        sqMultiplierLo:SQWORD, sqMultiplierHi:SQWORD
	mov	rax, sqMultiplicandHi
	mov	rcx, sqMultiplierHi
  or rcx, rax                                           ;Test for both hi-words zero.
  mov rcx, sqMultiplierLo
  jnz short hard                                        ;both are zero, just mul ALO and BLO

  mov rax, sqMultiplicandLo
  mul rcx                                               ;Result in rdx:rax

  ret

hard:
  mul rcx                                               ;rax has AHI, rcx has BLO, so AHI * BLO
  mov rbx, rax                                          ;Save result

  mov rax, sqMultiplicandLo
  mul sqMultiplierHi                                    ;ALO * BHI
  add rbx, rax                                          ;rbx = ((ALO * BHI) + (AHI * BLO))

  mov rax, sqMultiplicandLo                             ;rcx = BLO
  mul rcx                                               ;So rdx:rax = ALO*BLO
  add rdx, rbx                                          ;Now rdx has all the LO*HI stuff

  ret                                                   ;Result in rdx:rax, OF set on overflow.
sowordMul endp

end

