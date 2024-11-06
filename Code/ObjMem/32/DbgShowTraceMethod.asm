; ==================================================================================================
; Title:      DbgShowTraceMethod.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  DbgShowTraceMethod
; Purpose:    Output trace information about a method.
; Purpose:    Output trace information about a method.
; Arguments:  Arg1: -> ANSI Method Name.
;             Arg2: Method count.
;             Arg3: -> Method ticks.
;             Arg4: Foreground RGB color value.
;             Arg5: Background RGB color value.
;             Arg6: -> Destination Window WIDE name.
; Return:     Nothing.

% include &ObjMemPath&Common\\DbgShowTraceMethod_XP.inc

end
