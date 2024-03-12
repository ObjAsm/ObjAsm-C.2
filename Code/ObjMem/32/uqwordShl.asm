; ==================================================================================================
; Title:      uqwordShl.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, March 2024.
;               - First release.
;               - Inspired llshl.asm (nt5src-master).
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  uqwordShl
; Purpose:    Shift left of a SQWORD (signed and unsigned are identical).
; Arguments:  Arg1: QWORD in edx:eax.
;             Arg2: Shift count in cl.
; Return:     edx:eax Shifted value.

align ALIGN_CODE
uqwordShl proc
; Handle shifts of 64 or more bits (all get 0)
  .if cl < 64
    ;Handle shifts of between 0 and 31 bits
    .if cl < 32
      shld edx, eax, cl
      shl eax, cl
      ret
    .endif
    ;Handle shifts of between 32 and 63 bits
    mov edx, eax
    xor eax, eax
    and cl, 31
    shl edx, cl
    ret
  .endif
  ;Return 0 in edx:eax
  xor eax, eax
  xor edx, edx
  ret
uqwordShl endp

end
