; ==================================================================================================
; Title:      DbgOutFPU_UEFI.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, June 2022.
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemUefi.cop

ProcName textequ <DbgOutFPU_UEFI>

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  DbgOutFPU_UEFI
; Purpose:    Display the content of the FPU.
; Arguments:  Arg1: -> Destination Window WIDE name.
;             Arg2: Foreground RGB color value.
;             Arg3: Background RGB color value.
; Return:     Nothing.

% include &ObjMemPath&Common\\DbgOutFPU_XP.inc

end
