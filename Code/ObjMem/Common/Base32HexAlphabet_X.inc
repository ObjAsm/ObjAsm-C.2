; ==================================================================================================
; Title:      Base32HexAlphabet_X.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2024
;               - First release.
;               - RFC 4648 Section 7.
; ==================================================================================================


externdef BASE32_HEX_ALPHABET:CHRA

.const
align ALIGN_DATA
BASE32_HEX_ALPHABET       CHRA "0123456789ABCDEFGHIJKLMNOPQRSTUV"
