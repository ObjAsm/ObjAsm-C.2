; ==================================================================================================
; Title:      DbgOpenWnd.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - Initial release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  DbgOpenWnd
; Purpose:    Open a "Debug Center" instance.
; Arguments:  None.
; Return:     eax = TRUE if it was opened, otherwise FALSE.

% include &ObjMemPath&Common\DbgOpenWnd_X.inc

end
