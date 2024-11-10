; ==================================================================================================
; Title:      StrCopyA.asm
; Author:     G. Friedrich
; Version:    C.1.1
; Notes:      Version C.1.0, October 2017
;               - First release.
;             Version C.1.1, July 2022
;               - Return value added.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrCopyA
; Purpose:    Copy an ANSI string to a destination buffer.
; Arguments:  Arg1: Destrination ANSI string.
;             Arg2: Source ANSI string.
; Return:     rax = Number of BYTEs copied, including the ZTC.

.code
align ALIGN_CODE
StrCopyA proc pDstStrA:POINTER, pSrcStrA:POINTER
  invoke StrSizeA, rdx
  invoke MemShift, pDstStrA, pSrcStrA, eax
  ret
StrCopyA endp

end
