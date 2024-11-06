; ==================================================================================================
; Title:      NewObjInst_UEFI.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, June 2022
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemUefi.cop

ProcName textequ <NewObjInst_UEFI>

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  NewObjInst_UEFI
; Purpose:    Create an object instance from an object ID.
; Arguments:  Arg1: Object ID.
; Return:     rax -> New object instance or NULL if failed.

% include &ObjMemPath&Common\NewObjInst_XP.inc

end
