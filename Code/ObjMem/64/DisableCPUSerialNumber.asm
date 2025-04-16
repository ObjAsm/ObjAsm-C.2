; ==================================================================================================
; Title:      DisableCPUSerialNumber.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  DisableCPUSerialNumber
; Purpose:    Disable the reading of the CPU serial number. 
; Arguments:  None.
; Return:     Nothing.

% include &ObjMemPath&Common\DisableCPUSerialNumber_X.inc

end
