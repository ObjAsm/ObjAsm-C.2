; ==================================================================================================
; Title:      StrECatW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  StrECatW
; Purpose:    Append a WIDE string to another and return the address of the ending zero character.
;             StrCatW does not perform any length checking. The destination buffer must have room
;             for at least StrLengthW(Destination) + StrLengthW(Source) + 1 characters.
; Arguments:  Arg1: -> Destination WIDE character buffer.
;             Arg2: -> Source WIDE string.
; Return:     eax -> ZTC.

OPTION PROC:NONE

.code
align ALIGN_CODE
StrECatW proc pBuffer:POINTER, pSrcStringW:POINTER
  invoke StrEndW, [esp + 4]                             ;pBuffer
  invoke StrECopyW, eax, [esp + 8]                      ;pSrcStringW
  ret 8
StrECatW endp

OPTION PROC:DEFAULT

end
