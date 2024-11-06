; ==================================================================================================
; Title:      DbgOutCmd.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, November 2023
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
TARGET_STR_TYPE = STR_TYPE_WIDE
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Purpose:    Send a command to DebugCenter.
; Arguments:  Arg1: Command ID [BYTE].
;             Arg2: First parameter (DWORD).
;             Arg3: Second parameter (DWORD).
;             Arg4: -> Destination Window WIDE name.
; Return:     eax = TRUE if succeeded, otherwise FALSE.

% include &ObjMemPath&Common\\DbgOutCmd_X.inc

end
