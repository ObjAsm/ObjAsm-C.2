; ==================================================================================================
; Title:      StrW2NewStrA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, November 2024.
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrW2NewStrA
; Purpose:    Create a new StringA with the content of a STRINGW.
; Arguments:  Arg1: -> STRINGW.
; Return:     rax -> STRINGW. When no longer needed, it must be freed using StrDisposeA.

% include &ObjMemPath&Common\StrW2NewStrA_X.inc

end
