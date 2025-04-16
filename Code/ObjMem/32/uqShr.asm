; ==================================================================================================
; Title:      uqShr.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, March 2024.
;               - First release.
;               - Inspired llshr.asm (nt5src-master).
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  uqShr
; Purpose:    Shift right of a QWORD.
; Arguments:  Arg1: QWORD in edx:eax.
;             Arg2: Shift count in cl.
; Return:     edx:eax Shifted value.

.code
align ALIGN_CODE
uqShr proc
; Handle shifts of 64 bits or more (if shifting 64 bits or more, the result
; depends only on the high order bit of edx).
  .if cl < 64
    .if cl < 32
      ;Handle shifts of between 0 and 31 bits
      shrd eax, edx, cl
      shr edx, cl
      ret
    .endif
    ;Handle shifts of between 32 and 63 bits
    mov eax, edx
    xor edx, edx
    and cl, 31
    shr eax, cl
    ret
  .endif
  ;Return 0 in edx:eax
  xor eax, eax
  xor edx, edx
  ret
uqShr endp

end