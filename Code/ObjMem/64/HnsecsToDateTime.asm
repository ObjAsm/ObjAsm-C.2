; ==================================================================================================
; Title:      HnsecsToDateTime.asm
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
; Procedure:  HnsecsToDateTime
; Purpose:    Convert hecto-nano-seconds into DTL_DATETIME information.
; Arguments:  Arg1: -> DTL_DATETIME
;             Arg2: -> hecto-nano-seconds
; Return:     eax = TRUE id succeeded, otherwise FALSE.

% include &ObjMemPath&Common\HnsecsToDateTime_X.inc

end

