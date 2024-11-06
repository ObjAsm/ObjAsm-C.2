; ==================================================================================================
; Title:      Base64DecodeW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, November 2023
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
TARGET_STR_TYPE = STR_TYPE_WIDE
% include &ObjMemPath&ObjMemWin.cop

ProcName textequ <Base64DecodeW>

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  Base64DecodeW
; Purpose:    Decode a CHRW stream using the BASE64 algoritm.
; Arguments:  Arg1: -> Encoded CHRW data buffer.
;             Arg2: Encoded data size in BYTEs (always a multiple of 4*sizeof(CHR)).
;             Arg3: Decode table. If NULL, BASE64_DEFAULT_DECODE_TABLE is used.
;                   BASE64_URL_DECODE_TABLE can be used to decode URL content.
; Return:     xax -> Decoded data. When no longer needed, it should be freed using MemFree.
;             ecx = Decoded data size in BYTEs.
;             On error, xax and ecx are zero.
; Links:      https://en.wikipedia.org/wiki/Base64
;             https://datatracker.ietf.org/doc/html/rfc4648

% include &ObjMemPath&Common\\Base64Decode_TX.inc

end
