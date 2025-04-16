; ==================================================================================================
; Title:      StrCatCharA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  StrCatCharA
; Purpose:    Append a character to the end of an ANSI string.
; Arguments:  Arg1: Destrination ANSI buffer.
;             Arg2: ANSI character.
; Return:     Nothing.

OPTION PROC:NONE

.code
align ALIGN_CODE
StrCatCharA proc pBuffer:POINTER, cChar:CHRA
  invoke StrEndA, [esp + 4]                             ;pBuffer
  movzx cx, BYTE ptr [esp + 8]                          ;cChar
  mov WORD ptr [eax], cx                                ;Writes cChar and ZTC
  ret 8
StrCatCharA endp

OPTION PROC:DEFAULT

end
