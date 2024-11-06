; ==================================================================================================
; Title:      StrCLengthA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrCLengthA
; Purpose:    Get the character count of the source ANSI string with length limitation.
; Arguments:  Arg1: -> Source ANSI string.
;             Arg3: Maximal character count.
; Return:     eax = Limited character count.

OPTION PROC:NONE

.code
align ALIGN_CODE
StrCLengthA proc pStringA:POINTER, dMaxChars:DWORD
  push edi
  mov ecx, [esp + 12]                                   ;ecx = dMaxChars
  mov edi, [esp + 8]                                    ;edi -> STRINGA
  inc ecx
  push ecx
  xor eax, eax
  repne scasb
  pop eax
  sub eax, ecx
  dec eax
  pop edi
  ret 8
StrCLengthA endp

OPTION PROC:DEFAULT

end
