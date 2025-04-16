; ==================================================================================================
; Title:      GetOptions.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, July 2024
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
TARGET_STR_TYPE = STR_TYPE_ANSI
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  GetOptions
; Purpose:    Scan argument list for options.
; Arguments:  Arg1: -> Option definition table.
;             Arg2: -> Application options storage.
;             Arg3: -> List of WIDE string arguments.
; Return:     eax: TRUE if succeeded, otherwise FALSE.
;             ecx: failed option index.
;             rdx: -> failed WIDE string argument.

% include &ObjMemPath&Common\GetOptions_X.inc

end
