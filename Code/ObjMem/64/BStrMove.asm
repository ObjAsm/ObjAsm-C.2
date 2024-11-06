; ==================================================================================================
; Title:      BStrMove.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  BStrMove
; Purpose:    Move part of a BStr. The ZTC is not appended automatically.
;             Source and destination strings may overlap.
; Arguments:  Arg1: -> Destination BStr.
;             Arg2: -> Source BStr.
;             Arg3: Character count.
; Return:     Nothing.

.code
align ALIGN_CODE
BStrMove proc pDstBStr:POINTER, pSrcBStr:POINTER, dCharCount:DWORD
  ;rcx -> DstBStr, rdx -> SrcBStr, r8d = dCharCount
  sub rcx, 4
  sub rdx, 4
  lea r8d, [2*r8d + 6]
  invoke MemShift, rcx, rdx, r8d
  ret
BStrMove endp

end
