; ==================================================================================================
; Title:      BStrCECopy.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  BStrCECopy
; Purpose:    Copy the the source BStr with length limitation and return the address of the ZTC.
;             The destination buffer should hold the maximum number of characters + 1.
; Arguments:  Arg1: -> Destination BStr.
;             Arg2: -> Source BStr.
;             Arg3: Maximal number of charachters the destination string can hold including the ZTC.
; Return:     rax = NULL or -> ZTC.

.code
align ALIGN_CODE
BStrCECopy proc pDstBStr:POINTER, pSrcBStr:POINTER, dMaxChars:DWORD  ;rcx -> DstBStr, rdx -> SrcBStr
  shl r8, 1                                             ;r8 = dMaxChars in BYTEs
  mov r9d, DWORD ptr [rcx - 4]
  mov r10d, DWORD ptr [rdx - 4]
  add r9, r10
  xor eax, eax
  cmp r8, r9
  jb @F                                                 ;Destination is full => return NULL
  invoke BStrECopy, rcx, rdx
@@:
  ret
BStrCECopy endp

end
