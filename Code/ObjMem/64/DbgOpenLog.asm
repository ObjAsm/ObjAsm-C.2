; ==================================================================================================
; Title:      DbgOpenLog.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - Initial release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  DbgOpenLog
; Purpose:    Open a Log-File.
; Arguments:  None.
; Return:     eax = TRUE if it was opened, otherwise FALSE.

% include &ObjMemPath&Common\DbgOpenLog_X.inc

end
