; ==================================================================================================
; Title:      bin2wordW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, November 2023
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
TARGET_STR_TYPE = STR_TYPE_WIDE
% include &ObjMemPath&ObjMemWin.cop

ProcName equ <bin2wordW>
BIT_COUNT = 16

.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  bin2wordW
; Purpose:    Conversion of an WIDE input string that contains a binary number in the form of a 
;             sequence of "0" and "1" into a WORD.
; Arguments:  Arg1: -> Input string.
; Return:     eax = Number.

% include &ObjMemPath&Common\bin2reg_TX.inc

end
