; ==================================================================================================
; Title:      DbgBuildStrMsgA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, November 2023
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
TARGET_STR_TYPE = STR_TYPE_ANSI
% include &ObjMemPath&ObjMemWin.cop

ProcName textequ <DbgBuildStrMsgA>

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  DbgBuildStrMsgA
; Purpose:    Debug helper proc that builds a structure in memory to send an ANSI string to the
;             DebugCenter server.
; Arguments:  Arg1: -> Zero terminated ANSI string.
;             Arg2: Foreground RGB color value.
;             Arg3: Background RGB color value.
;             Arg4: Effect value (DBG_EFFECT_XXX)
;             Arg5: -> Destination window WIDE name.
; Return:     xax -> Allocated memory containig the message.
;                 When no longer needed, it should be deallocated using MemFree.
;             ecx = byte size of the allocated memory block.

% include &ObjMemPath&Common\\DbgBuildStrMsg_TX.inc

end
