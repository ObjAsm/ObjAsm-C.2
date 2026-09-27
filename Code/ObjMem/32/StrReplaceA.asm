; ==================================================================================================
; Title:      StrReplaceA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2024
;               - Initial release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
TARGET_STR_TYPE = STR_TYPE_ANSI
% include &ObjMemPath&ObjMemWin.cop

ProcName textequ <StrReplaceA>

; --------------------------------------------------------------------------------------------------
; Procedure:  StrReplaceA
; Purpose:    Dispose an ANSI string and replace it with another ANSI string.
; Arguments:  Arg1: -> -> ANSI String to be replaced.
;             Arg2: -> Replacing ANSI string.
; Return:     eax -> Replacing ANSI string or NULL if failed.

% include &ObjMemPath&Common\StrReplace_TX.inc

end
