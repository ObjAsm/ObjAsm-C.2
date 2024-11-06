; ==================================================================================================
; Title:      DbgOutMsg.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  DbgOutMsg
; Purpose:    Identifies a windows message with a string.
; Arguments:  Arg1: Windows message ID.
;             Arg2: Foreground RGB color value.
;             Arg3: Background RGB color value.
;             Arg4: -> Destination window name.
; Return:     Nothing.

% include &ObjMemPath&Common\DbgOutMsg_X.inc

end
