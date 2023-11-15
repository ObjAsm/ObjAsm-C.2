; ==================================================================================================
; Title:      Base64Encode.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, November 2023
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
TARGET_STR_TYPE = STR_TYPE_WIDE
% include &ObjMemPath&ObjMemWin.cop

.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  Base64Encode
; Purpose:    Encode a data stream using the BASE64 algoritm.
; Arguments:  Arg1: -> Data buffer.
;             Arg2: Data size in BYTEs.
; Return:     xax -> Encoded buffer. When no longer needed, it should be freed using MemFree.
;             ecx = Encoded buffer size in BYTEs.
; Links:      https://en.wikipedia.org/wiki/Base64
;             https://datatracker.ietf.org/doc/html/rfc4648

% include &ObjMemPath&Common\\Base64Encode_X.inc

end
