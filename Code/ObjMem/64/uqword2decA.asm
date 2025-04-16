; ==================================================================================================
; Title:      uqword2decA.asm
; Author:     G. Friedrich
; Version:    C.1.1
; Notes:      Version C.1.1, May 2022
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
TARGET_STR_TYPE = STR_TYPE_ANSI
% include &ObjMemPath&ObjMemWin.cop

externdef TwoDecDigitTableA:BYTE
ProcName textequ <uqword2decA>

; --------------------------------------------------------------------------------------------------
; Procedure:  uqword2decA
; Purpose:    Convert an unsigned QWORD into its decimal ANSI string representation.
; Arguments:  Arg1: -> Destination ANSI string buffer.
;             Arg2: QWORD value.
; Return:     eax = Number of BYTEs copied to the destination buffer, including the ZTC.
; Note:       The destination buffer must be at least 21 BYTEs large to allocate the output string
;             (20 ANSI characters + ZTC = 21 BYTEs).

% include &ObjMemPath&Common\uqword2dec_T64.inc

end
