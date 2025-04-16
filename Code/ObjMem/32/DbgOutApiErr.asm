; ==================================================================================================
; Title:      DbgOutApiErr.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  DbgOutApiErr
; Purpose:    Identify a API error with a string.
; Arguments:  Arg1: Api error code obtained with GetLastError.
;             Arg2: Foreground RGB color value.
;             Arg3: Background RGB color value.
;             Arg4: -> Destination Window WIDE name.
; Return:     Nothing.

% include &ObjMemPath&Common\DbgOutApiErr_X.inc

end
