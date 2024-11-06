; ==================================================================================================
; Title:      BStrLeft.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  BStrLeft
; Purpose:    Extract the left n characters of the source BStr.
; Arguments:  Arg1: -> Destination BStr.
;             Arg2: -> Source BStr.
; Return:     rax = Number of copied characters, not including the ZTC.

.code
align ALIGN_CODE
BStrLeft proc uses rbx pDstBStr:POINTER, pSrcBStr:POINTER, dCharCount:DWORD  
  ;rcx -> DstBStr, rdx -> SrcBStr, r8d = dCharCount
  mov ebx, DWORD ptr [rdx - 4]
  cmp rbx, r8                                           ;dCharCount
  cmova rbx, r8
  mov DWORD ptr [rcx - 4], ebx                          ;Set byte count
  mov WORD ptr [rcx + rbx], 0                           ;Set ZTC
  .if rcx != rdx && rbx != 0
    invoke MemShift, rcx, rdx, ebx
  .endif
  shl rbx, 1
  mov rax, rbx
  ret
BStrLeft endp

end
