; ==================================================================================================
; Title:      TimeToHnsecs.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2023
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
TARGET_STR_TYPE = STR_TYPE_WIDE
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  TimeToHnsecs
; Purpose:    Convert DTL_TIME information into hecto-nano-seconds.
; Arguments:  Arg1: -> hnsecs or NULL
;             Arg2: -> DTL_TIME
; Return:     rax = Time.

% include &ObjMemPath&Common\TimeToHnsecs_X.inc

end