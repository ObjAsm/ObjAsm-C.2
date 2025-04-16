; ==================================================================================================
; Title:      IsWinNT.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  IsWinNT
; Purpose:    Detect if the OS is Windows NT based.
; Arguments:  None.
; Return:     eax = TRUE if OS is Windows NT based, otherwise FALSE.

% include &ObjMemPath&Common\IsWinNT_X.inc

end
