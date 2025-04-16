; ==================================================================================================
; Title:      StrECatCharA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  StrECatCharA
; Purpose:    Append a character to an ANSI string and return the address of the ending zero.
;             StrECatCharA does not perform any length checking. The destination buffer must have
;             enough room for at least StrLengthA(Destination) + 1 + 1 characters.
; Arguments:  Arg1: -> Destination ANSI string buffer.
;             Arg2: -> ANSI character.
; Return:     rax -> ZTC.

.code
align ALIGN_CODE
StrECatCharA proc pBuffer:POINTER, cChar:CHRA
  invoke StrEndA, rcx                                   ;pBuffer
  movzx ecx, cChar
  mov DCHRA ptr [rax], cx                               ;Writes cChar and ZTC
  inc rax
  ret
StrECatCharA endp

end
