; ==================================================================================================
; Title:      qword2binW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, November 2023
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
TARGET_STR_TYPE = STR_TYPE_WIDE
% include &ObjMemPath&ObjMemWin.cop

ProcName textequ <qword2binW>
VALUE_TYPE textequ <QWORD>

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  qword2binW
; Purpose:    Convert a QWORD to its binary WIDE string representation.
; Arguments:  Arg1: -> Destination buffer.
;             Arg2: Value.
; Return:     Nothing.
; Notes:      To allocate the output string, the destination buffer must be at least 130 BYTEs large.
;             (64 character WORDs + ZTC = 130 BYTEs).

% include &ObjMemPath&Common\reg2binW_64.inc

end
