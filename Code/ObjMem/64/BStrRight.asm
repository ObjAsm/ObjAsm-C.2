; ==================================================================================================
; Title:      BStrRight.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  BStrRight
; Purpose:    Copy the right n characters from the source string into the destination BStr, that must
;             have enought room for the new BStr.
; Arguments:  Arg1: -> Destination BStr buffer.
;             Arg2: -> Source BStr.
;             Arg3: Character count.
; Return:     rax = Copied characters.

.code
align ALIGN_CODE
BStrRight proc uses rbx pDstBStr:POINTER, pSrcBStr:POINTER, dCharCount:DWORD
  ;rcx -> DstBStr, rdx -> SrcBStr, r8d: dCharCount
  mov r9, r8
  mov r8d, DWORD ptr [rdx - 4]
  shl r9, 1                                             ;ByteCount => CharCount
  mov r10, r8
  cmp r8, r9
  cmova r8, r9

  add rdx, r10                                          ;Compute position
  sub rdx, r8
  mov DWORD ptr [rcx - 4], r8d                          ;Store length
  mov CHRW ptr [rcx + r8], 0                            ;Set ZTC
  mov rbx, r8
  invoke MemShift, rcx, rdx, r8d                        ;Move string; pDstBStr
  mov rax, rbx                                          ;Return character count
  shr rax, 1
  ret
BStrRight endp

end
