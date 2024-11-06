; ==================================================================================================
; Title:      dec2dwordW.asm
; Author:     G. Friedrich
; Version:    C.1.2
; Notes:      Version C.1.0, October 2017
;               - First release.
;             Version C.1.1 August 2023
;               - Proc frame bug corrected.
;             Version C.1.2 March 2024
;               - code moved to ObjMem/Common.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
TARGET_STR_TYPE = STR_TYPE_WIDE
% include &ObjMemPath&ObjMemWin.cop

ProcName textequ <dec2dwordW>

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  dec2dwordW
; Purpose:    Convert a decimal WIDE string to a DWORD.
; Arguments:  Arg1: -> Source WIDE string. Possible leading characters are " ", tab, "+" and "-",
;                   followed by a sequence of chars between "0".."9" and finalized by a ZTC.
;                   Other characters terminate the convertion returning zero.
; Return:     eax = Converted DWORD.
;             ecx = Conversion result. Zero if succeeded, otherwise failed.

% include &ObjMemPath&Common\\dec2xword_TX.inc

end
