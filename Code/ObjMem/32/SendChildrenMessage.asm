; ==================================================================================================
; Title:      SendChildrenMessage.asm
; Author:     G. Friedrich
; Version:    C.1.1
; Notes:      Version C.1.1, January 2020
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  SendChildrenMessage
; Purpose:    Callback procedure for EnumChildWindows that sends a message to a child window.
; Arguments:  Arg1: Child window HANDLE.
;             Arg2: -> CHILD_MSG structure.
; Return:     eax = Always TRUE (continue the enumeration).

% include &ObjMemPath&Common\SendChildrenMessage_X.inc

end
