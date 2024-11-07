; ==================================================================================================
; Title:      GetPrevInstanceA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
TARGET_STR_TYPE = STR_TYPE_ANSI
% include &ObjMemPath&ObjMemWin.cop

ProcName textequ <GetPrevInstanceA>

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  GetPrevInstanceA
; Purpose:    Return a HANDLE to a previously running instance of an application.
; Arguments:  Arg1: -> Any application ID ANSI name.
;             Arg2: -> ANSI Window class name.
; Return:     eax = Window HANDLE of the application instance or zero if failed.

% include &ObjMemPath&Common\GetPrevInstance_TX.inc

end
