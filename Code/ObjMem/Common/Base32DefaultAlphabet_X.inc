; ==================================================================================================
; Title:      Base32DefaultAlphabet_X.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2024
;               - First release.
;               - RFC 4648 Section 6.
; ==================================================================================================


externdef BASE32_DEFAULT_ALPHABET:CHRA

.const
align ALIGN_DATA
BASE32_DEFAULT_ALPHABET   CHRA "ABCDEFGHIJKLMNOPQRSTUVWXYZ234567"
