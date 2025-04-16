; ==================================================================================================
; Title:      DbgOutInterface.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  DbgOutInterface
; Purpose:    Identify a COM-Interface.
; Arguments:  Arg1: -> CSLID.
;             Arg2: Foreground RGB color value.
;             Arg3: Background RGB color value.
;             Arg4: -> Destination Window WIDE name.
; Return:     Nothing.

% include &ObjMemPath&Common\DbgOutInterface_X.inc

end
