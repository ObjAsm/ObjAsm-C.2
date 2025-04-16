; ==================================================================================================
; Title:      sqword2decA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, May 2022
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
TARGET_STR_TYPE = STR_TYPE_ANSI
% include &ObjMemPath&ObjMemWin.cop

externdef TwoDecDigitTableA:BYTE
ProcName textequ <sqword2decA>

; --------------------------------------------------------------------------------------------------
; Procedure:  sqword2decA
; Purpose:    Convert a signed QWORD to its decimal ANSI string representation.
; Arguments:  Arg1: -> Destination ANSI string buffer.
;             Arg2: SQWORD value.
; Return:     eax = Number of BYTEs copied to the destination buffer, including the ZTC.
; Note:       The destination buffer must be at least 21 BYTEs large to allocate the output string
;             (Sign + 19 ANSI characters + ZTC = 21 BYTEs).

% include &ObjMemPath&Common\sqword2dec_T32.inc

end
