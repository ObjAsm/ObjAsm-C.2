; ==================================================================================================
; Title:      bin2byteA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, November 2023
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
TARGET_STR_TYPE = STR_TYPE_ANSI
% include &ObjMemPath&ObjMemWin.cop

ProcName textequ <bin2byteA>
BIT_COUNT = 8

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  bin2byteA
; Purpose:    Conversion of an ANSI input string that contains a binary number in the form of a 
;             sequence of "0" and "1" into a BYTE.
; Arguments:  Arg1: -> Input string.
; Return:     eax = Number.

% include &ObjMemPath&Common\bin2reg_TX.inc

end
