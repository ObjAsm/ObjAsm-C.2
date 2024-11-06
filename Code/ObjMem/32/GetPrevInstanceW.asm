; ==================================================================================================
; Title:      GetPrevInstanceW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
TARGET_STR_TYPE = STR_TYPE_WIDE
% include &ObjMemPath&ObjMemWin.cop

ProcName textequ <GetPrevInstanceW>

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  GetPrevInstanceW
; Purpose:    Return a HANDLE to a previously running instance of an application.
; Arguments:  Arg1: -> WIDE application name.
;             Arg2: -> WIDE class name.
; Return:     rax = Window HANDLE of the application instance or zero if failed.

; % include &ObjMemPath&Common\GetPrevInstance_TX.inc

end
