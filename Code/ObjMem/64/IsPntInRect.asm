; ==================================================================================================
; Title:      IsPntInRect.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  IsPntInRect
; Purpose:    Check if a point is within a rect.
; Arguments:  Arg1: -> POINT.
;             Arg2: -> RECT
; Return:     rax = TRUE or FALSE.

OPTION PROC:NONE

.code
align ALIGN_CODE
IsPntInRect proc pPoint:POINTER, pRect:POINTER
  mov eax, [rcx].POINT.x
  mov r8d, [rdx].RECT.left
  sub eax, r8d
  sub r8d, [rdx].RECT.right
  add eax, r8d
  jc @F                                                 ;x isn't in the RECT => don't check y

  mov eax, [rcx].POINT.y
  mov r8d, [rdx].RECT.top
  sub eax, r8d
  sub r8d, [rdx].RECT.bottom
  add eax, r8d
@@:
  sbb rax, rax
  inc rax
  ret
IsPntInRect endp

OPTION PROC:DEFAULT

end
