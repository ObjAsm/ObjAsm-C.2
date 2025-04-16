; ==================================================================================================
; Title:      StrCatCharA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  StrCatCharA
; Purpose:    Append a character to the end of an ANSI string.
; Arguments:  Arg1: Destrination ANSI buffer.
;             Arg2: ANSI character.
; Return:     Nothing.

.code
align ALIGN_CODE
StrCatCharA proc pBuffer:POINTER, bChar:CHRA
  invoke StrEndA, rcx                                   ;pBuffer
  movzx cx, BYTE ptr bChar                              ;bChar
  mov DCHRA ptr [rax], cx                               ;Writes cChar and ZTC
  ret
StrCatCharA endp

end
