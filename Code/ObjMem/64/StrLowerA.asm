; ==================================================================================================
; Title:      StrLowerA.asm
; Author:     G. Friedrich
; Version:    C.2.0
; Notes:      Version C.1.0, October 2017
;               - First release.
;             Version C.2.0, November 2023
;               - Speedup using a lookup table.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
TARGET_STR_TYPE = STR_TYPE_ANSI
% include &ObjMemPath&ObjMemWin.cop

ProcName textequ <StrLowerA>

; --------------------------------------------------------------------------------------------------
; Procedure:  StrLowerA
; Purpose:    Convert all ANSI string characters into uppercase.
; Arguments:  Arg1: -> Source ANSI string.
; Return:     rax -> String.

% include &ObjMemPath&Common\StrLower_TX.inc

end
