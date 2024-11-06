; ==================================================================================================
; Title:      GetOption.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, July 2024
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
TARGET_STR_TYPE = STR_TYPE_ANSI
% include &ObjMemPath&ObjMemWin.cop
% include &IncPath&Windows\shlwapi.inc

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  GetOption
; Purpose:    Process a single option.
; Arguments:  Arg1: -> Option definition table.
;             Arg2: -> Application options storage.
;             Arg3: -> Argument (WIDE string), e.g. /Verbosity:1
; Return:     eax: TRUE if succeeded, otherwise FALSE.

% include &ObjMemPath&Common\GetOption_X.inc

end
