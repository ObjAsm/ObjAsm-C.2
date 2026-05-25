; ==================================================================================================
; Title:      StrLengthA.asm
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
; Procedure:  StrLengthA
; Purpose:    Determine the length of an ANSI string not including the zero terminating character.
; Arguments:  Arg1: -> Source ANSI string.
; Return:     eax = Length of the string in characters.

.code
OPTION PROC:NONE
align ALIGN_CODE
StrLengthA proc pStringA:POINTER
  invoke StrSizeA, rcx
  dec eax
  ret
StrLengthA endp
OPTION PROC:DEFAULT


;.code
;OPTION PROC:NONE
;align ALIGN_CODE
;StrLengthA proc pString:POINTER
;  push rdi
;  mov rdi, rcx
;  mov ecx, -1
;  xor al, al
;  repne scasb
;  not ecx
;  mov eax, ecx
;  dec eax
;  pop rdi
;  ret
;StrLengthA endp
;OPTION PROC:DEFAULT

end
