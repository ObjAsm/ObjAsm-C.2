; ==================================================================================================
; Title:      StrCopyW.asm
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
; Procedure:  StrCopyW
; Purpose:    Copy a WIDE string to a destination buffer.
; Arguments:  Arg1: Destrination WIDE string buffer.
;             Arg2: Source WIDE string.
; Return:     eax = Number of BYTEs copied, including the ZTC.

.code
align ALIGN_CODE
StrCopyW proc pDstStringW:POINTER, pSrcStringW:POINTER
  invoke StrSizeW, rdx
  invoke MemShift, pDstStringW, pSrcStringW, eax
  ret
StrCopyW endp

end
