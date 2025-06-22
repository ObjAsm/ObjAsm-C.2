; ==================================================================================================
; Title:      WideToUTF8Size.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, June 2025
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  WideToUTF8Size
; Purpose:    Calculate the amount of memory needed to store the converted UTF8 stream from a
;             WIDE string.
; Arguments:  Arg1: -> Source WIDE string. Must be zero terminated.
; Return:     eax = Number of BYTEs requred. Zero if failed.
; Notes:      The ZTC is always included in size calculations.
;             The returned value can only be zero if the procedure fails.

% include &ObjMemPath&Common\WideToUTF8Size_XP.inc

end
