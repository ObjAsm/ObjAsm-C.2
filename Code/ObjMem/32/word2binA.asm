; ==================================================================================================
; Title:      word2binA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, November 2023
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
TARGET_STR_TYPE = STR_TYPE_ANSI
% include &ObjMemPath&ObjMemWin.cop

ProcName textequ <word2binA>
VALUE_TYPE textequ <WORD>

; --------------------------------------------------------------------------------------------------
; Procedure:  word2binA
; Purpose:    Convert a WORD to its binary ANSI string representation.
; Arguments:  Arg1: -> Destination buffer.
;             Arg2: Value.
; Return:     Nothing.
; Notes:      To allocate the output string, the destination buffer must be at least 17 BYTEs large.
;             (16 character BYTEs + ZTC = 17 BYTEs).

% include &ObjMemPath&Common\reg2binA_32.inc

end
