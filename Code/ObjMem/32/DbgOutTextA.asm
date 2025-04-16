; ==================================================================================================
; Title:      DbgOutTextA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
TARGET_STR_TYPE = STR_TYPE_ANSI
% include &ObjMemPath&ObjMemWin.cop

ProcName textequ <DbgOutTextA>

; --------------------------------------------------------------------------------------------------
; Procedure:  DbgOutTextA
; Purpose:    Send an ANSI string to the debug output device.
; Arguments:  Arg1: -> Zero terminated ANSI string.
;             Arg2: Foreground RGB color value.
;             Arg3: Background RGB color value.
;             Arg4: Effect value (DBG_EFFECT_XXX)
;             Arg5: -> Destination window WIDE name.
; Return:     Nothing.

% include &ObjMemPath&Common\\DbgOutText_TX.inc

end
