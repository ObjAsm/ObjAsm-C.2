; ==================================================================================================
; Title:      StrCLengthA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrCLengthA
; Purpose:    Get the character count of the source ANSI string with length limitation.
; Arguments:  Arg1: -> Source ANSI string.
;             Arg3: Maximal character count.
; Return:     eax = Limited character count.

.code
align ALIGN_CODE
StrCLengthA proc pStringA:POINTER, dMaxChars:DWORD
  push rdi
  ;rcx = pStringA, edx = dMaxChars
  inc edx
  mov rdi, rcx                                          ;rdi -> StringW
  mov ecx, edx                                          ;ecx = dMaxChars + 1
  xor eax, eax
  repne scasb
  not rcx
  lea eax, [ecx + edx]
  pop rdi
  ret
StrCLengthA endp
OPTION PROC:DEFAULT

end
