; ==================================================================================================
; Title:      dec2qwordA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, March 2024
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
TARGET_STR_TYPE = STR_TYPE_ANSI
% include &ObjMemPath&ObjMemWin.cop

ProcName textequ <dec2qwordA>

.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  dec2qwordA
; Purpose:    Convert a decimal ANSI string to a QWORD.
; Arguments:  Arg1: -> Source ANSI string. Possible leading characters are " ", tab, "+" and "-",
;                   followed by a sequence of chars between "0".."9" and finalized by a ZTC.
;                   Other characters terminate the convertion returning zero.
; Return:     rax = Converted QWORD.
;             rcx = Conversion result. Zero if succeeded, otherwise failed.

% include &ObjMemPath&Common\\dec2xword_TX.inc

end
