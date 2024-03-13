; ==================================================================================================
; Title:      owordShl_64.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, March 2024.
;               - First release.
;               - Inspired llshl.asm (nt5src-master).
; ==================================================================================================


.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  sowordShl/uowordShl
; Purpose:    Shift left of a signed/unsigned OWORD (signed and unsigned procs are identical).
; Arguments:  Arg1: OWORD in rdx:rax.
;             Arg2: Shift count in cl.
; Return:     rdx:rax Shifted value.

align ALIGN_CODE
ProcName proc
; Handle shifts of 128 or more bits (all get 0)
  .if cl < 128
    ;Handle shifts of between 0 and 63 bits
    .if cl < 64
      shld rdx, rax, cl
      shl rax, cl
      ret
    .endif
    ;Handle shifts of between 64 and 127 bits
    mov rdx, rax
    xor eax, eax
    and cl, 63
    shl rdx, cl
    ret
  .endif
  ;Return 0 in rdx:rax
  xor eax, eax
  xor edx, edx
  ret
ProcName endp

end
