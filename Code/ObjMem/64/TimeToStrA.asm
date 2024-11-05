; ==================================================================================================
; Title:      TimeToStrA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2023
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
TARGET_STR_TYPE = STR_TYPE_ANSI
% include &ObjMemPath&ObjMemWin.cop

ProcName equ <TimeToStrA>

.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  TimeToStrA
; Purpose:    Convert a DTL_TIME to a formated string representation.
; Arguments:  Arg1: -> Destination ANSI Buffer
;             Arg2: Format flags
;             Arg3: -> DTL_TIME
; Return:     eax = Number of bytes copied, including the ZTC.

% include &ObjMemPath&Common\TimeToStr_TX.inc

end