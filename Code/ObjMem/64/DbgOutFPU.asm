; ==================================================================================================
; Title:      DbgOutFPU.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017.
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

ProcName textequ <DbgOutFPU>

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  DbgOutFPU
; Purpose:    Display the content of the FPU.
; Arguments:  Arg1: -> Destination Window WIDE name.
;             Arg2: Foreground RGB color value.
;             Arg3: Background RGB color value.
; Return:     Nothing.

% include &ObjMemPath&Common\\DbgOutFPU_XP.inc

end
