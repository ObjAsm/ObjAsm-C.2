; ==================================================================================================
; Title:      StrReplaceW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2024
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
TARGET_STR_TYPE = STR_TYPE_ANSI
% include &ObjMemPath&ObjMemWin.cop

ProcName equ <StrReplaceW>

.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrReplaceA
; Purpose:    Dispose an existing WIDE string and replace it with a new one.
; Arguments:  Arg1: -> String to be replaced.
;             Arg2: -> New string.
; Return:     rax -> New allocated string or NULL if failed.

% include &ObjMemPath&Common\StrReplace_TX.inc

end
