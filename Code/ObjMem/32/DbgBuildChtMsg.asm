; ==================================================================================================
; Title:      DbgBuildChtMsg.asm
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
; Procedure:  DbgBuildChtMsg
; Purpose:    Debug helper proc that builds a structure in memory to send a command to the
;             DebugCenter server.
; Arguments:  Arg1: ID (BYTE).
;             Arg2: -> Payload. If NULL, the space (Payload size) is reserved anyway.
;             Arg3: Payload size (DWORD).
;             Arg4: -> Destination Window WIDE name.
; Return:     xax -> Allocated memory containig the message.
;                 When no longer needed, it should be deallocated using MemFree.
;             ecx = Byte size of the allocated memory block.
;             xdx -> Payload into message buffer.

% include &ObjMemPath&Common\\DbgBuildChtMsg_X.inc

end
