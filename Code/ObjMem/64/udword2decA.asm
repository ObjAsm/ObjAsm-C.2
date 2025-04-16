; ==================================================================================================
; Title:      udword2decA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, May 2022
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
TARGET_STR_TYPE = STR_TYPE_ANSI
% include &ObjMemPath&ObjMemWin.cop

externdef TwoDecDigitTableA:BYTE
ProcName textequ <udword2decA>

; --------------------------------------------------------------------------------------------------
; Procedure:  udword2decA
; Purpose:    Convert an unsigned DWORD to its decimal ANSI string representation.
; Arguments:  Arg1: -> Destination ANSI string buffer.
;             Arg2: DWORD value.
; Return:     eax = Number of BYTEs copied to the destination buffer, including the ZTC.
; Note:       The destination buffer must be at least 11 BYTEs large to allocate the output string
;             (10 ANSI characters + ZTC = 11 BYTEs).

% include &ObjMemPath&Common\udword2dec_T64.inc

end
