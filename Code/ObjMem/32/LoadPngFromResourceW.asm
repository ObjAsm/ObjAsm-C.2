; ==================================================================================================
; Title:      LoadPngFromResourceW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, August 2022
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
TARGET_STR_TYPE = STR_TYPE_WIDE
% include &ObjMemPath&ObjMemWin.cop

externdef hInstance:HANDLE
ProcName textequ <LoadPngFromResourceW>

; --------------------------------------------------------------------------------------------------
; Procedure:  LoadPngFromResourceW
; Purpose:    Load a PNG resource and return a bitmap HANDLE.
; Arguments:  Arg1: -> Resource WIDE name or ID. 
; Return:     rax = hBitmap or zero if failed.

% include &ObjMemPath&Common\LoadPngFromResource_TX.inc

end
