; ==================================================================================================
; Title:      Base32DecodeW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2024
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
TARGET_STR_TYPE = STR_TYPE_WIDE
% include &ObjMemPath&ObjMemWin.cop

ProcName textequ <Base32DecodeW>

; --------------------------------------------------------------------------------------------------
; Procedure:  Base32DecodeW
; Purpose:    Decode a data stream using the BASE32 algoritm.
; Arguments:  Arg1: -> Encoded CHRW data buffer.
;             Arg2: Encoded data size in BYTEs (always a multiple of 8*sizeof(CHRW)).
;             Arg3: Decode table. If NULL, BASE32_DEFAULT_DECODE_TABLE is used.
;                   BASE32_HEX_DECODE_TABLE can be used to decode special content.
; Return:     eax -> Decoded CHRW data. When no longer needed, it should be freed using MemFree.
;             ecx = Decoded data size in BYTEs.
;             On error, eax and ecx are zero.
; Links:      https://en.wikipedia.org/wiki/Base32
;             https://datatracker.ietf.org/doc/html/rfc4648

% include &ObjMemPath&Common\\Base32Decode_TX.inc

end
