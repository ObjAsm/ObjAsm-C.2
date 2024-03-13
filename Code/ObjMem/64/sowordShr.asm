; ==================================================================================================
; Title:      sowordShr.asm
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
; Procedure:  sowordShr
; Purpose:    Shift right of a signed OWORD.
; Arguments:  Arg1: OWORD in rdx:rax.
;             Arg2: Shift count in cl.
; Return:     rdx:rax Shifted value.

align ALIGN_CODE
sowordShr proc
; Handle shifts of 128 bits or more (if shifting 128 bits or more, the result
; depends only on the high order bit of rdx).
  .if cl < 128
    .if cl < 64
      ;Handle shifts of between 0 and 63 bits
      shrq rax, rdx, cl
      sar rdx, cl
      ret
    .endif
    ;Handle shifts of between 64 and 127 bits
    mov rax, rdx
    sar rdx, 63
    and cl, 63
    sar rax, cl
    ret
  .endif
  ;Return 0 or -1, depending on the sign of rdx
  sar rdx, 63
  mov rax, rdx
  ret
sowordShr endp

end