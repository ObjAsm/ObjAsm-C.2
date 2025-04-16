; ==================================================================================================
; Title:      WideToUTF8.asm
; Author:     G. Friedrich
; Version:    C.1.1
; Notes:      Version C.1.1, February 2020
;               - First release.
; Links:      https://en.wikipedia.org/wiki/UTF-8
;             https://en.wikipedia.org/wiki/UTF-16
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  WideToUTF8
; Purpose:    Convert an WIDE string to an UTF8 encoded stream.
; Arguments:  Arg1: -> Destination buffer.
;             Arg2: -> Source WIDE string.
;             Arg3: Destination buffer size in BYTEs.
; Return:     eax = Number of BYTEs written.
;             ecx = 0: succeeded
;                   1: buffer full
; Notes:      - The destination stream is always zero terminated.

% include &ObjMemPath&Common\WideToUTF8_XP.inc

end
