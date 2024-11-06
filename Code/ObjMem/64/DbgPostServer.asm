; ==================================================================================================
; Title:      DbgPostServer.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, November 2023
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
TARGET_STR_TYPE = STR_TYPE_WIDE
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  DbgPostServer
; Purpose:    Send a POST request to the DebugCenter Server
; Arguments:  Arg1: -> Data.
;             Arg2: DataSize.
; Return:     eax = TRUE if succeeded, otherwise FALSE.

% include &ObjMemPath&Common\\DbgPostServer_X.inc

end
