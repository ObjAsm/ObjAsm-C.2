; ==================================================================================================
; Title:      StrReplaceW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2024
;               - Initial release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
TARGET_STR_TYPE = STR_TYPE_WIDE
% include &ObjMemPath&ObjMemWin.cop

ProcName textequ <StrReplaceW>

; --------------------------------------------------------------------------------------------------
; Procedure:  StrReplaceW
; Purpose:    Dispose a WIDE string and replace it with another WIDE string.
; Arguments:  Arg1: -> -> WIDE String to be replaced.
;             Arg2: -> Replacing WIDE string.
; Return:     eax -> Replacing WIDE string or NULL if failed.

% include &ObjMemPath&Common\StrReplace_TX.inc

end
