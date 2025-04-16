; ==================================================================================================
; Title:      bin2byteW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, November 2023
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
TARGET_STR_TYPE = STR_TYPE_WIDE
% include &ObjMemPath&ObjMemWin.cop

ProcName textequ <bin2byteW>
BIT_COUNT = 8

; --------------------------------------------------------------------------------------------------
; Procedure:  bin2byteW
; Purpose:    Conversion of an WIDE input string that contains a binary number in the form of a 
;             sequence of "0" and "1" into a BYTE.
; Arguments:  Arg1: -> Input string.
; Return:     eax = Number.

% include &ObjMemPath&Common\bin2reg_TX.inc

end
