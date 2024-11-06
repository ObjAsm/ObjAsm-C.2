; ==================================================================================================
; Title:      GetSysHnsecs.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2023
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
TARGET_STR_TYPE = STR_TYPE_WIDE
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  GetSysHnsecs
; Purpose:    Get the hecto-nano-seconds count from system start.
; Arguments:  Arg1: -> hecto-nano-seconds
; Return:     rax / edx::eax = hecto-nano-second count.

% include &ObjMemPath&Common\GetSysHnsecs_X.inc

end
