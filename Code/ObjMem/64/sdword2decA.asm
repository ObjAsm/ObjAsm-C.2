; ==================================================================================================
; Title:      sdword2decA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, May 2022
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
TARGET_STR_TYPE = STR_TYPE_ANSI
% include &ObjMemPath&ObjMemWin.cop

externdef TwoDecDigitTableA:BYTE
ProcName textequ <sdword2decA>

; --------------------------------------------------------------------------------------------------
; Procedure:  sdword2decA
; Purpose:    Convert a signed DWORD to its decimal ANSI string representation.
; Arguments:  Arg1: -> Destination ANSI string buffer.
;             Arg2: SDWORD value.
; Return:     eax = Number of BYTEs copied to the destination buffer, including the ZTC.
; Note:       The destination buffer must be at least 12 BYTEs large to allocate the output string
;             (Sign + 10 ANSI characters + ZTC = 12 BYTEs).

% include &ObjMemPath&Common\sdword2dec_T64.inc

end
