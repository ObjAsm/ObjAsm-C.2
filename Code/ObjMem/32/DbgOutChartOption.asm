; ==================================================================================================
; Title:      DbgOutChartOption.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2024
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
TARGET_STR_TYPE = STR_TYPE_WIDE
% include &ObjMemPath&ObjMemWin.cop

.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  DbgOutChartOption
; Purpose:    Send a chart option value to the Debug Center Window.
; Arguments:  Arg1: Option ID.
;             Arg2: -> Option value.
;             Arg3: Option value size.
;             Arg4: -> Destination Window WIDE name.
; Return:     eax = TRUE if succeeded, otherwise FALSE.

% include &ObjMemPath&Common\\DbgOutChartOption_X.inc

end
