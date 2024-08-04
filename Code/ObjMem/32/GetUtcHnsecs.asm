; ==================================================================================================
; Title:      GetUtcHnsecs.asm
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
; Procedure:  GetUtcHnsecs
; Purpose:    Get the UTC hecto-nano-seconds count.
; Arguments:  Arg1: -> hecto-nano-seconds
; Return:     Nothing, always succeed.

% include &ObjMemPath&Common\GetUtcHnsecs_X.inc

end
