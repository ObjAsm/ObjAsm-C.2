; ==================================================================================================
; Title:      DbgOutTextCA.asm
; Author:     G. Friedrich
; Version:    C.1.1
; Notes:      Version C.1.0, October 2017
;               - First release.
; Notes:      Version C.1.1, November 2023
;               - Code moved to DbgOutTextC_TX.inc.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
TARGET_STR_TYPE = STR_TYPE_ANSI
% include &ObjMemPath&ObjMemWin.cop

ProcName textequ <DbgOutTextCA>

; --------------------------------------------------------------------------------------------------
; Procedure:  DbgOutTextCA
; Purpose:    Send a counted ANSI string to the debug output device.
; Arguments:  Arg1: -> Zero terminated ANSI string.
;             Arg2: Maximal character count.
;             Arg3: Foreground RGB color value.
;             Arg4: Background RGB color value.
;             Arg5: Effect value (DBG_EFFECT_XXX).
;             Arg6: -> Destination Window WIDE name.
; Return:     Nothing.

% include &ObjMemPath&Common\\DbgOutTextC_TX.inc

end
