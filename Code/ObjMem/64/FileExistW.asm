; ==================================================================================================
; Title:      FileExistW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
TARGET_STR_TYPE = STR_TYPE_WIDE
% include &ObjMemPath&ObjMemWin.cop

ProcName textequ <FileExistW>

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  FileExistW
; Purpose:    Check the existence of a file.
; Arguments:  Arg1: -> WIDE file name.
; Return:     eax = TRUE if the file exists, otherwise FALSE.

% include &ObjMemPath&Common\FileExist_TX.inc

end
