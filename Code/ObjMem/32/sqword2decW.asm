; ==================================================================================================
; Title:      sqword2decW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, May 2022
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
TARGET_STR_TYPE = STR_TYPE_WIDE
% include &ObjMemPath&ObjMemWin.cop

externdef TwoDecDigitTableW:WORD
ProcName textequ <sqword2decW>

; --------------------------------------------------------------------------------------------------
; Procedure:  sqword2decW
; Purpose:    Convert a signed SQWORD to its decimal WIDE string representation.
; Arguments:  Arg1: -> Destination WIDE string buffer.
;             Arg2: SQWORD value.
; Return:     eax = Number of BYTEs copied to the destination buffer, including the ZTC.
; Note:       The destination buffer must be at least 42 BYTEs large to allocate the output string
;             (Sign + 19 WIDE characters + ZTC = 42 BYTEs).

% include &ObjMemPath&Common\sqword2dec_T32.inc

end
