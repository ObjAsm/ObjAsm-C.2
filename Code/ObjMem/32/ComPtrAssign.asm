; ==================================================================================================
; Title:      ComPtrAssign.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

% include &MacPath&Objects.inc
% include &COMPath&COM.inc

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  ComPtrAssign
; Purpose:    First increment the reference count of the new interface and then release any
;             existing interface pointer.
; Arguments:  Arg1: -> Old Interface pointer.
;             Arg2: New Interface pointer.

% include &ObjMemPath&Common\ComPtrAssign_X.inc

end
