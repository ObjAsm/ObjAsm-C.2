; ==================================================================================================
; Title:      GetRawClientRect.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  GetRawClientRect
; Purpose:    Calculate the window client RECT including scrollbars, but without the room needed
;             for the menubar.
; Arguments:  Arg1: Window HANDLE
;             Arg2: -> RECT.
; Return:     Nothing.

% include &ObjMemPath&Common\GetRawClientRect_X.inc

end
