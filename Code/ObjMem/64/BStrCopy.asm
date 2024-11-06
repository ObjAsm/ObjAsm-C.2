; ==================================================================================================
; Title:      BStrCopy.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  BStrCopy
; Purpose:    Copy a BStr to a destination buffer.
; Arguments:  Arg1: Destrination BStr buffer.
;             Arg2: Source BStr.
; Return:     Nothing.

.code
align ALIGN_CODE
BStrCopy proc pDstBStr:POINTER, pSrcBStr:POINTER        ;rcx -> DstBStr, rdx -> SrcBStr
  sub rdx, 4
  mov r8d, DWORD ptr [rdx]
  sub rcx, 4
  add r8d, sizeof(DWORD) + sizeof(CHRW)                 ;char count (DWORD) + ZTC (WORD)
  invoke MemShift, rcx, rdx, r8d
  ret
BStrCopy endp

end
