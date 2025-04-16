; ==================================================================================================
; Title:      StrECatW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  StrECatW
; Purpose:    Append a WIDE string to another and return the address of the ending zero character.
;             StrCatW does not perform any length checking. The destination buffer must have room
;             for at least StrLengthW(Destination) + StrLengthW(Source) + 1 characters.
; Arguments:  Arg1: -> Destination WIDE character buffer.
;             Arg2: -> Source WIDE string.
; Return:     rax -> ZTC.

.code
align ALIGN_CODE
StrECatW proc pDstStrW:POINTER, pSrcStrW:POINTER
  invoke StrEndW, rcx                                   ;pDstStrW
  invoke StrECopyW, rax, pSrcStrW
  ret
StrECatW endp

end
