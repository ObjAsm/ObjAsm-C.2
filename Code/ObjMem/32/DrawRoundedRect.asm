; ==================================================================================================
; Title:      DrawRoundedRect.asm
; Author:     G. Friedrich
; Version:    C.2.0
; Notes:      Version C.2.0, November 2025
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
TARGET_STR_TYPE = STR_TYPE_WIDE
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  DrawRoundedRect
; Purpose:    Draw an anti-alised rounded rect.
; Arguments:  Arg1: DC HANDLE.
;             Arg2: Left starting position.
;             Arg3: Top starting position.
;             Arg4: Total width.
;             Arg5: Total height.
;             Arg6: Radius of all corners.
;             Arg7: RGB color used to draw the rounded rectangle.
; Return:     Nothing.

% include &ObjMemPath&Common\DrawRoundedRect_X.inc

end
