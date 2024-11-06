; ==================================================================================================
; Title:      GetDlgBaseUnits.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  GetDlgBaseUnits
; Purpose:    Returns the Dialog Base Units.
; Arguments:  Arg1: Dialog DC.
; Return:     eax = X DBU.
;             ecx = Y DBU.

% include &ObjMemPath&Common\GetDlgBaseUnits_X.inc

end
