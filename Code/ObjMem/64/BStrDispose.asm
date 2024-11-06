; ==================================================================================================
; Title:      BStrDispose.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, November 2024
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  BStrDispose
; Purpose:    Free the memory allocated for the string using BStrNew, BStrCNew, BStrLENew or
;             BStrAlloc.
;             If the pointer to the string is NULL, BStrDispose does nothing.
; Arguments:  Arg1: BSTR.
; Return:     Nothing.

% include &ObjMemPath&Common\BStrDispose_X.inc

end
