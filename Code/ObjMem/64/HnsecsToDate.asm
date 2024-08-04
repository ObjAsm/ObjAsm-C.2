; ==================================================================================================
; Title:      HnsecsToDate.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2023
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
TARGET_STR_TYPE = STR_TYPE_WIDE
% include &ObjMemPath&ObjMemWin.cop

.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  HnsecsToDate
; Purpose:    Convert hecto-nano-seconds into DTL_DATE information.
; Arguments:  Arg1: -> DTL_DATE
;             Arg2: -> hecto-nano-seconds
; Return:     eax = TRUE if succeeded, otherwise FALSE.

% include &ObjMemPath&Common\HnsecsToDate_X.inc

end
