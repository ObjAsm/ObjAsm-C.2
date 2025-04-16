; ==================================================================================================
; Title:      BStrECopy.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  BStrECopy
; Purpose:    Copy a BStr to a buffer and return the address of the ZTC.
;             Source and destination strings may overlap.
; Arguments:  Arg1: -> Destination BStr buffer.
;             Arg2: -> Source BStr buffer.
; Return:     rax -> ZTC.

.code
align ALIGN_CODE
BStrECopy proc uses rbx pDstBStr:POINTER, pSrcBStr:POINTER       ;rcx -> DstBStr, rdx -> SrcBStr
  sub rdx, 4
  sub rcx, 4
  mov r8d, DWORD ptr [rdx]
  add r8d, 6
  lea rbx, [rcx + r8]
  invoke MemShift, rcx, rdx, r8d
  mov rax, rbx
  ret
BStrECopy endp

end
