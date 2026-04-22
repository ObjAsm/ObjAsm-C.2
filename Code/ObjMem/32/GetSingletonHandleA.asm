; ==================================================================================================
; Title:      GetSingletonHandleA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, April 2026
;               - Initial release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
TARGET_STR_TYPE = STR_TYPE_ANSI
% include &ObjMemPath&ObjMemWin.cop

ProcName textequ <GetSingletonHandleA>

; --------------------------------------------------------------------------------------------------
; Procedure:  GetSingletonHandle
; Purpose:    Attempts to acquire exclusive ownership for single-instance execution.
; Arguments:  Arg1: -> Pointer to a null-terminated identifying ANSI string.
; Return:     xax = Handle representing exclusive ownership if this is the first instance
;                   0 if another instance is already running
;                   INVALID_HANDLE_VALUE if the operation failed
; Notes:      - The returned handle represents the ownership lock and must remain open
;               for the entire lifetime of the application.
;             - The caller is responsible for releasing it using CloseHandle before exit.

% include &ObjMemPath&Common\GetSingletonHandle_TX.inc

end
