; ==================================================================================================
; Title:      StrCopyW.asm
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
; Procedure:  StrCopyW
; Purpose:    Copy a WIDE string to a destination buffer.
; Arguments:  Arg1: Destrination WIDE string buffer.
; Return:     eax = Number of BYTEs copied, including the ZTC.
; Return:     Nothing.

OPTION PROC:NONE

.code
align ALIGN_CODE
StrCopyW proc pBuffer:POINTER, pSrcStringW:POINTER
  invoke StrSizeW, [esp + 8]                            ;pSrcStringW
  invoke MemShift, [esp + 12], [esp + 12], eax          ;pBuffer, pSrcStringW
  ret 8
StrCopyW endp

OPTION PROC:DEFAULT

end
