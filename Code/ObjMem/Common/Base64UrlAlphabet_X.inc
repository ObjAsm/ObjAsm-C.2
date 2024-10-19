; ==================================================================================================
; Title:      Base64UrlAlphabet_X.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2024
;               - First release.
;               - RFC 4648 Section 5.
; ==================================================================================================


externdef BASE64_URL_ALPHABET:CHRA

.const
align ALIGN_DATA
BASE64_URL_ALPHABET     CHRA "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-_"
