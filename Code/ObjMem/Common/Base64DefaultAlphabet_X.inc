; ==================================================================================================
; Title:      Base64DefaultAlphabet_X.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2024
;               - First release.
;               - RFC 4648 Section 4.
; ==================================================================================================


externdef BASE64_DEFAULT_ALPHABET:CHRA

.const
align ALIGN_DATA
BASE64_DEFAULT_ALPHABET CHRA "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
