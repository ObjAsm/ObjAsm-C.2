; ==================================================================================================
; Title:      DbgOutTextW_UEFI.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, June 2022
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
TARGET_STR_TYPE = STR_TYPE_WIDE
% include &ObjMemPath&ObjMemUefi.cop

ProcName textequ <DbgOutTextW_UEFI>

; --------------------------------------------------------------------------------------------------
; Procedure:  DbgOutTextW_UEFI
; Purpose:    Send a WIDE string to the debug output device.
; Arguments:  Arg1: -> Zero terminated WIDE string.
;             Arg2: Foreground RGB color value.
;             Arg3: Background RGB color value.
;             Arg4: Effect value (DBG_EFFECT_XXX)
;             Arg5: -> Destination window WIDE name.
; Return:     Nothing.

% include &ObjMemPath&Common\\DbgOutText_TX_UEFI.inc

end
