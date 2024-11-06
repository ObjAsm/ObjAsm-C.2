; ==================================================================================================
; Title:      StrA2NewStrW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, November 2024.
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrA2NewStrW
; Purpose:    Create a new StringW with the content of a STRINGA.
; Arguments:  Arg1: -> STRINGA.
; Return:     xax -> STRINGW. When no longer needed, it must be freed using StrDisposeW.

% include &ObjMemPath&Common\StrA2NewStrW_X.inc

end
