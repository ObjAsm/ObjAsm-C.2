; ==================================================================================================
; Title:      BStrRepChr,asm
; Author:     G. Friedrich
; Version:    C.1.1
; Notes:      Version C.1.1, May 2020
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  BStrRepChr
; Purpose:    Create a new BSTR filled with a given char.
; Arguments:  Arg1: Used character.
;             Arg2: Repetition count.
; Return:     rax -> New BSTR or NULL if failed.

% include &ObjMemPath&Common\BStrRepChr_X.inc

end
