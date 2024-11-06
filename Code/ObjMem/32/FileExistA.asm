; ==================================================================================================
; Title:      FileExistA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
TARGET_STR_TYPE = STR_TYPE_ANSI
% include &ObjMemPath&ObjMemWin.cop

ProcName textequ <FileExistA>

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  FileExistA
; Purpose:    Check the existence of a file.
; Arguments:  Arg1: -> ANSI file name.
; Return:     eax = TRUE if the file exists, otherwise FALSE.

% include &ObjMemPath&Common\FileExist_TX.inc

end
