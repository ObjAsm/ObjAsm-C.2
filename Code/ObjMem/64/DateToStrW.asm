; ==================================================================================================
; Title:      DateToStrW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2023
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
TARGET_STR_TYPE = STR_TYPE_WIDE
% include &ObjMemPath&ObjMemWin.cop

ProcName equ <DateToStrW>

.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  DateToStrW
; Purpose:    Convert a DTL_DATE to a formated string representation.
; Arguments:  Arg1: -> Destination WIDE Buffer
;             Arg2: Format flags
;             Arg3: -> DTL_DATE
; Return:     eax = Number of bytes copied, including the ZTC.

% include &ObjMemPath&Common\DateToStr_TX.inc

end