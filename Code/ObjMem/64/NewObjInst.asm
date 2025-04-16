; ==================================================================================================
; Title:      NewObjInst.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

ProcName textequ <NewObjInst>

; --------------------------------------------------------------------------------------------------
; Procedure:  NewObjInst
; Purpose:    Create an object instance from an object ID.
; Arguments:  Arg1: Object ID.
; Return:     rax -> New object instance or NULL if failed.

% include &ObjMemPath&Common\NewObjInst_XP.inc

end
