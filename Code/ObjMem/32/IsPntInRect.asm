; ==================================================================================================
; Title:      IsPntInRect.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release. Based on code of The Svin.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  IsPntInRect
; Purpose:    Check if a point is within a rect.
;             If rect.left = rect.right = 0, the point.x is considdered inside. Idem for y coord.
; Arguments:  Arg1: -> POINT.
;             ARg2: -> RECT
; Return:     eax = TRUE or FALSE.

OPTION PROC:NONE

.code
align ALIGN_CODE
IsPntInRect proc pPoint:POINTER, pRect:POINTER
  push esi
  mov esi, [esp + 8]                                    ;esi -> Point
  mov eax, [esi].POINT.x
  mov ecx, [esp + 12]                                   ;ecx -> Rect
  mov edx, [ecx].RECT.left
  sub eax, edx
  sub edx, [ecx].RECT.right
  add eax, edx
  jc @F                                                 ;x isn't in the RECT => don't check y

  mov eax, [esi].POINT.y
  mov edx, [ecx].RECT.top
  sub eax, edx
  sub edx, [ecx].RECT.bottom
  add eax, edx
@@:
  sbb eax, eax
  inc eax
  pop esi
  ret 8
IsPntInRect endp

OPTION PROC:DEFAULT

end
