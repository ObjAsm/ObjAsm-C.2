; ==================================================================================================
; Title:      StrCopyA.asm
; Author:     G. Friedrich
; Version:    C.1.1
; Notes:      Version C.1.0, October 2017
;               - First release.
;             Version C.1.1, July 2022
;               - Return value added.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrCopyA
; Purpose:    Copy an ANSI string to a destination buffer.
; Arguments:  Arg1: Destrination ANSI string buffer.
;             Arg2: Source ANSI string.
; Return:     eax = Number of BYTEs copied, including the ZTC.

OPTION PROC:NONE

.code
align ALIGN_CODE
StrCopyA proc pBuffer:POINTER, pSrcStrA:POINTER
  invoke StrSizeA, [esp + 8]
  invoke MemShift, [esp + 12], [esp + 12], eax
  ret 8
StrCopyA endp

OPTION PROC:DEFAULT

end
