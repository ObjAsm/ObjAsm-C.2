; ==================================================================================================
; Title:      StrECatA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrECatA
; Purpose:    Append an ANSI string to another and return the address of the ending zero character.
;             StrCatA does not perform any length checking. The destination buffer must have room
;             for at least StrLengthA(Destination) + StrLengthA(Source) + 1 characters.
; Arguments:  Arg1: -> Destination ANSI character buffer.
;             Arg2: -> Source ANSI string.
; Return:     rax -> ZTC.

.code
align ALIGN_CODE
StrECatA proc pDstStrA:POINTER, pSrcStrA:POINTER
  invoke StrEndA, rcx                                   ;pDstStrA
  invoke StrECopyA, rax, pSrcStrA
  ret
StrECatA endp

end
