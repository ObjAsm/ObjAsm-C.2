; ==================================================================================================
; Title:      StrUpperW.asm
; Author:     G. Friedrich
; Version:    C.2.0
; Notes:      Version C.1.0, October 2017
;               - First release.
;             Version C.2.0, November 2023
;               - Speedup using a lookup table.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
TARGET_STR_TYPE = STR_TYPE_WIDE
% include &ObjMemPath&ObjMemWin.cop

ProcName textequ <StrUpperW>

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrUpperW
; Purpose:    Convert all WIDE string characters into uppercase.
; Arguments:  Arg1: -> Source WIDE string.
; Return:     rax -> String.

% include &ObjMemPath&Common\StrUpper_TX.inc

end
