; ==================================================================================================
; Title:      StrTitleA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, Decemner 2023
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
TARGET_STR_TYPE = STR_TYPE_ANSI
% include &ObjMemPath&ObjMemWin.cop

ProcName equ <StrTitleA>

.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrTitleA
; Purpose:    Capitalize the first character of each word. The rest is converted to lowercase.
; Arguments:  Arg1: -> Source ANSI string.
; Return:     rax -> Converted ANSI String.

% include &ObjMemPath&Common\StrTitle_TX.inc

end
