; ==================================================================================================
; Title:      StrLengthA_AVX.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, May 2026
;               - Initial release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  StrLengthA_AVX
; Purpose:    Determine the length of an ANSI string not including the zero terminating character.
; Arguments:  Arg1: -> Source ANSI string.
; Return:     eax = Length of the string in characters.

.code
OPTION PROC:NONE
align ALIGN_CODE
StrLengthA_AVX proc pStringA:POINTER
  invoke StrSizeA_AVX, rcx
  dec eax
  ret
StrLengthA_AVX endp
OPTION PROC:DEFAULT

end
