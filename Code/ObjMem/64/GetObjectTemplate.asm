; ==================================================================================================
; Title:      \GetObjectTemplateX.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  GetObjectTemplate
; Purpose:    Get the template address of an object type ID.
; Arguments:  Arg1: Object type ID.
; Return:     rax -> Object template or NULL if not found.
;             ecx = Object template size or zero if not found.

% include &ObjMemPath&Common\\GetObjectTemplate_XP.inc

end
