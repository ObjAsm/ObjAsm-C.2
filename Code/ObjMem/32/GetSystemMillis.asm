; ==================================================================================================
; Title:      GetSystemMillis.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2023
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
TARGET_STR_TYPE = STR_TYPE_WIDE
% include &ObjMemPath&ObjMemWin.cop

.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  GetSystemMillis
; Purpose:    Get system millisecond count.
; Arguments:  Arg1: -> Destination variable
; Return:     rax / edx::eax = millisecond count.

% include &ObjMemPath&Common\GetSystemMillis_X.inc

end
