; ==================================================================================================
; Title:      uqword2decW.asm
; Author:     G. Friedrich
; Version:    C.1.1
; Notes:      Version C.1.1, May 2022
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
TARGET_STR_TYPE = STR_TYPE_WIDE
% include &ObjMemPath&ObjMemWin.cop

externdef TwoDecDigitTableW:WORD
ProcName textequ <uqword2decW>

; --------------------------------------------------------------------------------------------------
; Procedure:  uqword2decW
; Purpose:    Convert an unsigned QWORD to its decimal WIDE string representation.
; Arguments:  Arg1: -> Destination WIDE string buffer.
;             Arg2: QWORD value.
; Return:     eax = Number of BYTEs copied to the destination buffer, including the ZTC.
; Note:       The destination buffer must be at least 42 BYTEs large to allocate the output string
;             (20 WIDE characters + ZTC = 42 BYTEs).

% include &ObjMemPath&Common\uqword2dec_T32.inc

end
