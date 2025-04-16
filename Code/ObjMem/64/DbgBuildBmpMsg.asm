; ==================================================================================================
; Title:      DbgBuildBmpMsg.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, November 2023
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
TARGET_STR_TYPE = STR_TYPE_WIDE
% include &ObjMemPath&ObjMemWin.cop


; --------------------------------------------------------------------------------------------------
; Procedure:  DbgBuildBmpMsg
; Purpose:    Debug helper proc that builds a structure in memory to send a bitmap to the
;             DebugCenter server.
; Arguments:  Arg1: Bitamp HANDLE.
;             Arg2: Background RGB color value.
;             Arg3: -> Destination Window WIDE name.
; Return:     rax -> Allocated memory containig the message.
;                 When no longer needed, it should be deallocated using MemFree.
;             ecx = Byte size of the allocated memory block.

% include &ObjMemPath&Common\\DbgBuildBmpMsg_X.inc

end
