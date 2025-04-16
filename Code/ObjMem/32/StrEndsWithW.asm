; ==================================================================================================
; Title:      StrEndsWithW.asm
; Author:     G. Friedrich
; Version:    C.1.1
; Notes:      Version C.1.1, April 2020
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

TARGET_STR_TYPE = STR_TYPE_WIDE
TARGET_STR_AFFIX textequ <W>
ProcName textequ <StrEndsWithW>

; --------------------------------------------------------------------------------------------------
; Procedure:  StrEndsWithW
; Purpose:    Compare the ending of a string.
; Arguments:  Arg1: -> Analized string.
;             Arg2: -> Suffix string.
; Return:     eax = TRUE of the ending matches, otherwise FALSE.

% include &ObjMemPath&Common\StrEndsWith_TXP.inc

end
