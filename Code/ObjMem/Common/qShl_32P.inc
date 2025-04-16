; ==================================================================================================
; Title:      qShl_32P.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, March 2024.
;               - First release.
;               - Platform independent code.
;               - Inspired llshl.asm (nt5src-master).
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Procedure:  sqShl/uqShl
; Purpose:    Shift left of a signed/unsigned QWORD (signed and unsigned procs are identical).
; Arguments:  Arg1: QWORD in edx:eax.
;             Arg2: Shift count in cl.
; Return:     edx:eax Shifted value.

.code
align ALIGN_CODE
ProcName proc
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
ProcName endp

end
