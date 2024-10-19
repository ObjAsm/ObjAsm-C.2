; ==================================================================================================
; Title:      Base64Encode.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, November 2023
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
TARGET_STR_TYPE = STR_TYPE_WIDE
% include &ObjMemPath&ObjMemWin.cop

.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  Base64Encode
; Purpose:    Encode a data stream using the BASE64 algoritm. The output stream contains ANSI
;             characters from the passed alphabet (BASE64_DEFAULT_ALPHABET, BASE64_URL_ALPHABET)
; Arguments:  Arg1: -> Input data buffer.
;             Arg2: Input data size in BYTEs.
;             Arg3: Character alphabet used to encode the data. If NULL, BASE64_DEFAULT_ALPHABET
;                   is used. BASE64_URL_ALPHABET can be used to encode URL content.
; Return:     xax -> Encoded data. When no longer needed, it should be released using MemFree.
;             ecx = Encoded data size in BYTEs. Always a multiple of 4.
; Links:      https://en.wikipedia.org/wiki/Base64
;             https://datatracker.ietf.org/doc/html/rfc4648
; Note:       No ZTC is added to the encoded buffer.

% include &ObjMemPath&Common\\Base64Encode_X.inc

end
