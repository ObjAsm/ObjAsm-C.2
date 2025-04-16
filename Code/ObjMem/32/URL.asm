; ==================================================================================================
; Title:      URL.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm URL encoding and decoding routines.
; Notes:      Version C.1.0, December 2020
;               - First release.
;               - These routines don't support UFT8 encoding.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  UrlEscDecode
; Purpose:    Translate a wide string containig URL escape sequences to a plain wide string.
; Arguments:  Arg1: -> Input wide string.
;             Arg2: -> Output Buffer.
;             Arg3: Output Buffer size in BYTEs.
; Return:     eax = Number of chars written, including the ZTC.

; --------------------------------------------------------------------------------------------------
; Procedure:  UrlEscEncode
; Purpose:    Translate a plain wide string to a wide string containig URL escape sequences.
; Arguments:  Arg1: -> Input wide string.
;             Arg2: -> Output Buffer.
;             Arg3: Output Buffer size in BYTEs.
; Return:     eax = Number of chars written.

; --------------------------------------------------------------------------------------------------
; Method:     UrlEscEncodeSize
; Purpose:    Calculates the requiered buffer size for UrlEscEncode method.
; Arguments:  Arg1: -> Input wide string.
; Return:     eax = Number of BYTEs requierd, including the ZTC.

% include &ObjMemPath&Common\URL_X.inc

end
