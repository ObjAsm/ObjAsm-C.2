; ==================================================================================================
; Title:      StrLengthW.asm
; Author:     G. Friedrich
; Version:    3.0.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrLengthW
; Purpose:    Determine the length of a WIDE string not including the ZTC.
; Arguments:  Arg1: -> WIDE string.
; Return:     rax = Length of the string in characters.

OPTION PROC:NONE

.code
align ALIGN_CODE
StrLengthW proc pStringW:POINTER
  push rdi
  mov rdi, rcx
  mov ecx, -1
  xor ax, ax
  repne scasw
  not ecx
  mov eax, ecx
  dec eax
  pop rdi
  ret
StrLengthW endp

OPTION PROC:DEFAULT

end
