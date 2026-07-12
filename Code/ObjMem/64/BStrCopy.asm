; ==================================================================================================
; Title:      BStrCopy.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - Initial release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  BStrCopy
; Purpose:    Copy a BSTR to a destination buffer.
; Arguments:  Arg1: Destrination BSTR buffer.
;             Arg2: Source BSTR.
; Return:     Nothing.

.code
align ALIGN_CODE
BStrCopy proc pDstBStr:POINTER, pSrcBStr:POINTER        ; rcx -> DstBStr, rdx -> SrcBStr
  sub rdx, 4
  mov r8d, DWORD ptr [rdx]
  sub rcx, 4
  add r8d, sizeof(DWORD) + sizeof(CHRW)                 ; Char count (DWORD) + ZTC (WORD)
  invoke MemShift, rcx, rdx, r8d
  ret
BStrCopy endp

end
