; ==================================================================================================
; Title:      DateTimeToStrA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2023
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
TARGET_STR_TYPE = STR_TYPE_ANSI
% include &ObjMemPath&ObjMemWin.cop

ProcName equ <DateTimeToStrA>

.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  DateTimeToStrA
; Purpose:    Convert a PDTL_DATE and DTL_TIME to a formated string representation.
; Arguments:  Arg1: -> Destination ANSI Buffer
;             Arg2: Date Format flags
;             Arg3: -> DTL_DATE
;             Arg4: Time Format flags
;             Arg5: -> DTL_TIME
; Return:     eax = Number of bytes copied, including the ZTC.

% include &ObjMemPath&Common\DateTimeToStr_TX.inc

end