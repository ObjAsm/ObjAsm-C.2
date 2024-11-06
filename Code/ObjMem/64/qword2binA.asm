; ==================================================================================================
; Title:      qword2binA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, November 2023
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
TARGET_STR_TYPE = STR_TYPE_ANSI
% include &ObjMemPath&ObjMemWin.cop

ProcName textequ <qword2binA>
VALUE_TYPE textequ <QWORD>

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  qword2binA
; Purpose:    Convert a QWORD to its binary ANSI string representation.
; Arguments:  Arg1: -> Destination buffer.
;             Arg2: Value.
; Return:     Nothing.
; Notes:      To allocate the output string, the destination buffer must be at least 65 BYTEs large.
;             (64 character BYTEs + ZTC = 65 BYTEs).

% include &ObjMemPath&Common\reg2binA_64.inc

end
