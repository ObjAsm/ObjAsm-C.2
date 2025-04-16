; ==================================================================================================
; Title:      DbgCloseDevice.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  DbgCloseDevice
; Purpose:    Close the connection to the output device.
; Arguments:  None.
; Return:     Nothing.

% include &ObjMemPath&Common\DbgCloseDevice_X.inc

end
