; ==================================================================================================
; Title:      Base32EncodeA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2024
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
TARGET_STR_TYPE = STR_TYPE_ANSI
% include &ObjMemPath&ObjMemWin.cop

ProcName textequ <Base32EncodeA>

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  Base32EncodeA
; Purpose:    Encode a data stream using the BASE32 algorithm. The output stream contains only
;             characters from the specified alphabet (BASE32_DEFAULT_ALPHABET, BASE32_URL_ALPHABET)
; Arguments:  Arg1: -> Input data buffer.
;             Arg2: Input data size in BYTEs.
;             Arg3: Character alphabet used to encode the data. If NULL, BASE32_DEFAULT_ALPHABET
;                   is used. BASE32_HEX_ALPHABET can be used to encode special content.
; Return:     xax -> Buffer containing the encoded data. When no longer needed, it should be
;                    released using MemFree.
;             ecx = Encoded data size in BYTEs, always a multiple of 8*sizeof(CHRA)
; Links:      https://en.wikipedia.org/wiki/Base32
;             https://datatracker.ietf.org/doc/html/rfc4648
; Note:       No ZTC is added to the encoded buffer.

% include &ObjMemPath&Common\\Base32Encode_TX.inc

end
