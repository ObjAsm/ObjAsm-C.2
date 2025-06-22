; ==================================================================================================
; Title:      UTF8ToWideSize.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, June 2025
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  UTF8ToWideSize
; Purpose:    Calculate the amount of memory needed to store the converted WIDE string from a
;             UTF8 stream.
; Arguments:  Arg1: -> Source UTF8 BYTE stream. Must be zero terminated.
; Return:     eax = Number of BYTEs requred. Zero if failed.
; Notes:      The ZTC is always included in size calculations.
;             The returned value can only be zero if the procedure fails.

% include &ObjMemPath&Common\UTF8ToWideSize_XP.inc

end
