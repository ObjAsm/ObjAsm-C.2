; ==================================================================================================
; Title:      dword2binA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, November 2023
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
TARGET_STR_TYPE = STR_TYPE_ANSI
% include &ObjMemPath&ObjMemWin.cop

ProcName textequ <dword2binA>
VALUE_TYPE textequ <DWORD>

; --------------------------------------------------------------------------------------------------
; Procedure:  dword2binA
; Purpose:    Convert a DWORD to its binary ANSI string representation.
; Arguments:  Arg1: -> Destination buffer.
;             Arg2: Value.
; Return:     Nothing.
; Notes:      To allocate the output string, the destination buffer must be at least 33 BYTEs large.
;             (32 character BYTEs + ZTC = 33 BYTEs).

% include &ObjMemPath&Common\reg2binA_64.inc

end
