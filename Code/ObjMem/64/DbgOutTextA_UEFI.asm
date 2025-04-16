; ==================================================================================================
; Title:      DbgOutTextA_UEFI.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, June 2022
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemUefi.cop

TARGET_STR_TYPE = STR_TYPE_ANSI
ProcName textequ <DbgOutTextA_UEFI>

; --------------------------------------------------------------------------------------------------
; Procedure:  DbgOutTextA_UEFI
; Purpose:    Send an ANSI string to the debug output device.
; Arguments:  Arg1: -> Zero terminated ANSI string.
;             Arg2: Foreground RGB color value.
;             Arg3: Background RGB color value.
;             Arg4: Effect value (DBG_EFFECT_XXX)
;             Arg5: -> Destination window WIDE name.
; Return:     Nothing.

% include &ObjMemPath&Common\\DbgOutText_TX_UEFI.inc

end
