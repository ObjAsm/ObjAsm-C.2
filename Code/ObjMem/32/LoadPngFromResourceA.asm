; ==================================================================================================
; Title:      LoadPngFromResourceA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, August 2022
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
TARGET_STR_TYPE = STR_TYPE_ANSI
% include &ObjMemPath&ObjMemWin.cop

externdef hInstance:HANDLE
ProcName textequ <LoadPngFromResourceA>

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  LoadPngFromResourceA
; Purpose:    Load a PNG resource and return a bitmap HANDLE.
; Arguments:  Arg1: -> Resource ANSI name or ID. 
; Return:     rax = hBitmap or zero if failed.

% include &ObjMemPath&Common\LoadPngFromResource_TX.inc

end
