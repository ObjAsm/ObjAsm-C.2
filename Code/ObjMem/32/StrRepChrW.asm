; ==================================================================================================
; Title:      StrRepChrW.asm
; Author:     G. Friedrich
; Version:    C.1.1
; Notes:      Version C.1.1, May 2020
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
TARGET_STR_TYPE = STR_TYPE_WIDE
% include &ObjMemPath&ObjMemWin.cop

ProcName textequ <StrRepChrW>

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrRepChrW
; Purpose:    Create a new string filled with a given char.
; Arguments:  Arg1: Used character.
;             Arg2: Repetition count.
; Return:     eax -> New string or NULL if failed.

% include &ObjMemPath&Common\StrRepChr_TXP.inc

end
