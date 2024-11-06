; ==================================================================================================
; Title:      StrStartsWithW.asm
; Author:     HSE / G. Friedrich
; Version:    C.1.1
; Notes:      Version C.1.1, April 2020
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
TARGET_STR_TYPE = STR_TYPE_WIDE
% include &ObjMemPath&ObjMemWin.cop

ProcName textequ <StrStartsWithW>

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrStartsWithW
; Purpose:    Compare the beginning of a string.
; Arguments:  Arg1: -> Analized string.
;             Arg2: -> Prefix string.
; Return:     eax = TRUE of the beginning matches, otherwise FALSE.

% include &ObjMemPath&Common\StrStartsWith_TXP.inc

end
