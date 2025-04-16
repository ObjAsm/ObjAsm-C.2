; ==================================================================================================
; Title:      StrCompW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  StrCompW
; Purpose:    Compare 2 WIDE strings with case sensitivity.
; Arguments:  Arg1: -> WIDE string 1.
;             Arg2: -> WIDE string 2.
; Return:     If string 1 < string 2, then eax < 0.
;             If string 1 = string 2, then eax = 0.
;             If string 1 > string 2, then eax > 0.

OPTION PROC:NONE

.code
align ALIGN_CODE
StrCompW proc pString1W:POINTER, pString2W:POINTER
  xor r8, r8
  xor eax, eax
@@:
  mov ax, [rcx + r8]
  test ax, ax
  jz @F
  cmp ax, [rdx + r8]
  jnz @F
  add r8, sizeof(CHRW)
  jmp @B
@@:
  movzx ecx, CHRW ptr [rdx + r8]
  sub eax, ecx
  ret
StrCompW endp

OPTION PROC:DEFAULT

end
