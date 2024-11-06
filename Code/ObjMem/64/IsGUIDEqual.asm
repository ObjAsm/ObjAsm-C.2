; ==================================================================================================
; Title:      IsGUIDEqual.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  IsGUIDEqual
; Purpose:    Compare 2 GUIDs.
; Arguments:  Arg1: -> GUID1
;             Arg2: -> GUID2.
; Return:     rax = TRUE if they are equal, otherwise FALSE.

OPTION PROC:NONE

.code
align ALIGN_CODE
IsGUIDEqual proc pGUID1:POINTER, pGUID2:POINTER
  mov rax, QWORD ptr [rdx]
  cmp rax, QWORD ptr [rcx]
  jne @F
  mov rax, QWORD ptr [rdx + 8]
  cmp rax, QWORD ptr [rcx + 8]
  jne @F
  mov rax, TRUE
  ret
@@:
  xor eax, eax
  ret
IsGUIDEqual endp

OPTION PROC:DEFAULT

end
