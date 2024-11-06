; ==================================================================================================
; Title:      bin2dwordA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, November 2023
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
TARGET_STR_TYPE = STR_TYPE_ANSI
% include &ObjMemPath&ObjMemWin.cop

ProcName textequ <bin2dwordA>
BIT_COUNT = 32

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  bin2dwordA
; Purpose:    Conversion of an ANSI input string that contains a binary number in the form of a 
;             sequence of "0" and "1" into a DWORD.
; Arguments:  Arg1: -> Input string.
; Return:     eax = Number.

% include &ObjMemPath&Common\bin2reg_TX.inc

end
