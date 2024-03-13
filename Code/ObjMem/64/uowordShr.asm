; ==================================================================================================
; Title:      uowordShr.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, March 2024.
;               - First release.
;               - Inspired llshr.asm (nt5src-master).
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  uowordShr
; Purpose:    Shift right of an unsigned OWORD.
; Arguments:  Arg1: OWORD in rdx:rax.
;             Arg2: Shift count in cl.
; Return:     rdx:rax Shifted value.

align ALIGN_CODE
uowordShr proc
; Handle shifts of 128 bits or more (if shifting 128 bits or more, the result
; depends only on the high order bit of rdx).
  .if cl < 128
    .if cl < 64
      ;Handle shifts of between 0 and 63 bits
      shrq rax, rdx, cl
      shr rdx, cl
      ret
    .endif
    ;Handle shifts of between 64 and 127 bits
    mov rax, rdx
    xor rdx, rdx
    and cl, 63
    shr rax, cl
    ret
  .endif
  ;Return 0 in rdx:rax
  xor eax, eax
  xor edx, edx
  ret
uowordShr endp

end