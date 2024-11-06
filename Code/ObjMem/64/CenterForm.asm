; ==================================================================================================
; Title:      CenterForm.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  CenterForm
; Purpose:    Calculate the starting coordinate of a window based on the screen and the window size.
; Arguments:  Arg1: Window size in pixel.
;             Arg2: Screen size in pixel.
; Return:     eax = Starting point in pixel.

OPTION PROC:NONE

.code
align ALIGN_CODE
CenterForm proc dWindowSize:DWORD, dScreenSize:DWORD
  mov eax, edx
  sub eax, ecx
  shr eax, 1
  ret
CenterForm endp

OPTION PROC:DEFAULT

end
