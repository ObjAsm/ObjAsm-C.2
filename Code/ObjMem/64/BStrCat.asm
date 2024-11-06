; ==================================================================================================
; Title:      BStrCat.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  BStrCat
; Purpose:    Concatenate 2 BStrs.
; Arguments:  Arg1: Destrination BStr.
;             Arg2: Source BStr.
; Return:     Nothing.

.code
align ALIGN_CODE
BStrCat proc pDstBStr:POINTER, pSrcBStr:POINTER         ;rcx -> DstBStr, rdx -> SrcBStr
  mov r9, rdx
  mov r8d, DWORD ptr [rdx - 4]
  mov r10d, DWORD ptr [rcx - 4]
  add DWORD ptr [rcx - 4], r8d                          ;Store new length
  add rcx, r10
  add r8d, 2
  invoke MemShift, rcx, rdx, r8d                        ;pSrcBStr
  ret
BStrCat endp

end
