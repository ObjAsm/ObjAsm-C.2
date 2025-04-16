; ==================================================================================================
; Title:      udword2decW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, May 2022
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
TARGET_STR_TYPE = STR_TYPE_WIDE
% include &ObjMemPath&ObjMemWin.cop

externdef TwoDecDigitTableW:WORD
ProcName textequ <udword2decW>

; --------------------------------------------------------------------------------------------------
; Procedure:  udword2decW
; Purpose:    Convert an unsigned DWORD to its decimal WIDE string representation.
; Arguments:  Arg1: -> Destination WIDE string buffer.
;             Arg2: DWORD value.
; Return:     eax = Number of BYTEs copied to the destination buffer, including the ZTC.
; Note:       The destination buffer must be at least 22 BYTEs large to allocate the output string
;             (10 WIDE characters + ZTC = 22 BYTEs).

% include &ObjMemPath&Common\udword2dec_T64.inc

end
