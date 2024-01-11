; ==================================================================================================
; Title:      StrRTrimA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, January 2023
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
TARGET_STR_TYPE = STR_TYPE_ANSI
% include &ObjMemPath&ObjMemWin.cop

ProcName equ <StrRTrimA>

.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrRTrimA
; Purpose:    Trim blank characters from the end of an ANSI string.
; Arguments:  Arg1: -> Destination buffer.
;             Arg2: -> Source ANSI string.
; Return:     eax = Number of characters copied into the destination buffer (not counting the ZTC).

% include &ObjMemPath&Common\StrRTrim_TX.inc

end
