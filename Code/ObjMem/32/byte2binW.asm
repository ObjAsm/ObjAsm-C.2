; ==================================================================================================
; Title:      byte2binW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, November 2023
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
TARGET_STR_TYPE = STR_TYPE_WIDE
% include &ObjMemPath&ObjMemWin.cop

ProcName textequ <byte2binW>
VALUE_TYPE textequ <BYTE>

; --------------------------------------------------------------------------------------------------
; Procedure:  byte2binW
; Purpose:    Convert a BYTE to its binary WIDE string representation.
; Arguments:  Arg1: -> Destination buffer.
;             Arg2: Value.
; Return:     Nothing.
; Notes:      To allocate the output string, the destination buffer must be at least 18 BYTEs large.
;             (8 character WORDs + ZTC = 18 BYTEs).

% include &ObjMemPath&Common\reg2binW_32.inc

end
