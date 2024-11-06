; ==================================================================================================
; Title:      StrCCatCharA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrCCatCharA
; Purpose:    Append a character to the end of an ANSI string with length limitation.
; Arguments:  Arg1: -> Destination ANSI character buffer.
;             Arg2: -> ANSI character.
;             Arg3: Maximal number of characters that fit into the destination buffer.
; Return:     Nothing.

.code
align ALIGN_CODE
StrCCatCharA proc pBuffer:POINTER, cChar:CHRA, dMaxChars:DWORD
  invoke StrEndA, rcx                                   ;pBuffer
  mov ecx, dMaxChars
  add rcx, pBuffer
  sub rcx, rax
  jbe @F
  movzx ecx, cChar
  mov DCHRA ptr [rax], cx                               ;Write char and ZTC
@@:
  ret
StrCCatCharA endp

end
