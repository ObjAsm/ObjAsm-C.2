; ==================================================================================================
; Title:      StrTitleW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, Decemner 2023
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
TARGET_STR_TYPE = STR_TYPE_WIDE
% include &ObjMemPath&ObjMemWin.cop

ProcName equ <StrTitleW>

.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrTitleW
; Purpose:    Capitalize the first character of each word. The rest is converted to lowercase.
; Arguments:  Arg1: -> Source WIDE string.
; Return:     rax -> Converted WIDE String.

% include &ObjMemPath&Common\StrTitle_TX.inc

end
