; ==================================================================================================
; Title:      DbgOutBitmap.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, November 2023
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
TARGET_STR_TYPE = STR_TYPE_WIDE
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  DbgOutBitmap
; Purpose:    Send a bitmap to the DebugCenter server.
; Arguments:  Arg1: Bitamp HANDLE.
;             Arg2: Background RGB color value.
;             Arg3: -> Destination Window WIDE name.
; Return:     eax = TRUE if succeeded, otherwise FALSE.

% include &ObjMemPath&Common\\DbgOutBitmap_X.inc

end
