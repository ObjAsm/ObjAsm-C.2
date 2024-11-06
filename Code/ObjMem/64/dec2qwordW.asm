; ==================================================================================================
; Title:      dec2qwordW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, March 2024
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
TARGET_STR_TYPE = STR_TYPE_WIDE
% include &ObjMemPath&ObjMemWin.cop

ProcName textequ <dec2qwordW>

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  dec2qwordW
; Purpose:    Convert a decimal WIDE string to a QWORD.
; Arguments:  Arg1: -> Source WIDE string. Possible leading characters are " ", tab, "+" and "-",
;                   followed by a sequence of chars between "0".."9" and finalized by a ZTC.
;                   Other characters terminate the convertion returning zero.
; Return:     rax = Converted QWORD.
;             rcx = Conversion result. Zero if succeeded, otherwise failed.

% include &ObjMemPath&Common\\dec2xword_TX.inc

end
