; ==================================================================================================
; Title:      BStrECat.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  BStrECat
; Purpose:    Append a BStr to another and return the address of the ZTC.
;             BStrCat does not perform any length checking. The destination buffer must have room
;             for at least BStrLength(Destination) + BStrLength(Source) + 1 characters.
; Arguments:  Arg1: -> Destination BStr buffer.
;             Arg2: -> Added BStr.
; Return:     rax -> ZTC.

.code
align ALIGN_CODE
BStrECat proc uses rbx pDstBStr:POINTER, pAddBStr:POINTER  ;rcx -> DstBStr, rdx -> AddBStr
  mov r8d, DWORD ptr [rdx - 4]
  mov r9d, DWORD ptr [rcx - 4]
  add r8d, r9d                                          ;Calc new length
  mov DWORD ptr [rcx - 4], r8d                          ;Store it
  add rcx, r9
  lea rbx, [rcx + r8]
  add r8d, 2                                            ;Add ZTC
  invoke MemShift, rcx, rdx, r8d                        ;pSrcBStr
  mov rax, rbx
  ret
BStrECat endp

end
