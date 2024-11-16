; ==================================================================================================
; Title:      DbgBuildCmdMsg.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, November 2023
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
TARGET_STR_TYPE = STR_TYPE_WIDE
% include &ObjMemPath&ObjMemWin.cop


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  DbgBuildCmdMsg
; Purpose:    Debug helper proc that builds a structure in memory to send a command to the
;             DebugCenter server.
; Arguments:  Arg1: Command ID (BYTE).
;             Arg2: First parameter (DWORD).
;             Arg3: Second parameter (DWORD).
;             Arg4: -> Payload. If NULL, the space (Payload size) is reserved anyway.
;             Arg5: Payload size (DWORD).
;             Arg6: -> Destination Window WIDE name.
; Return:     rax -> Allocated memory containig the message.
;                 When no longer needed, it should be deallocated using MemFree.
;             ecx = Byte size of the allocated memory block.
;             rdx -> Payload into message buffer.

% include &ObjMemPath&Common\\DbgBuildCmdMsg_X.inc

end
