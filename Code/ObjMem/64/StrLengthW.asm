; ==================================================================================================
; Title:      StrLengthW.asm
; Author:     G. Friedrich
; Version:    C.2.0
; Notes:      Version C.1.0, October 2017
;               - Initial release.
;             Version C.2.0, May 2026
;               - ~50% faster than C.1.0 on typical workloads.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  StrLengthW
; Purpose:    Determine the length of a WIDE string not including the ZTC.
; Arguments:  Arg1: -> WIDE string.
; Return:     rax = Length of the string in characters.

.code
OPTION PROC:NONE
align ALIGN_CODE
StrLengthW proc pStringW:POINTER
  invoke StrSizeW, rcx
  shr eax, 1
  dec eax
  ret
StrLengthW endp
OPTION PROC:DEFAULT


;.code
;OPTION PROC:NONE
;align ALIGN_CODE
;StrLengthW proc pStringW:POINTER
;  push rdi
;  mov rdi, rcx
;  mov ecx, -1
;  xor ax, ax
;  repne scasw
;  not ecx
;  mov eax, ecx
;  dec eax
;  pop rdi
;  ret
;StrLengthW endp
;OPTION PROC:DEFAULT

end
