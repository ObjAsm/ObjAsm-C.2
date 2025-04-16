; ==================================================================================================
; Title:      StrCLengthW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  StrCLengthW
; Purpose:    Get the character count of the source WIDE string with length limitation.
; Arguments:  Arg1: -> Source WIDE string.
;             Arg3: Maximal character count.
; Return:     eax = Limited character count.

OPTION PROC:NONE

.code
align ALIGN_CODE
StrCLengthW proc pStringW:POINTER, dMaxChars:DWORD
  push rdi
  ;rcx = pStringW, edx = dMaxChars
  inc edx
  mov rdi, rcx                                          ;rdi -> StringW
  mov ecx, edx                                          ;ecx = dMaxChars + 1
  xor eax, eax
  repne scasw
  not rcx
  lea eax, [ecx + edx]
  pop rdi
  ret
StrCLengthW endp

OPTION PROC:DEFAULT

end
