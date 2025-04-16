; ==================================================================================================
; Title:      GetFileLinesA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, December 2020
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
TARGET_STR_TYPE = STR_TYPE_ANSI
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  GetFileLinesA
; Purpose:    Return an array of line ending offsets of an ANSI text file.
; Arguments:  Arg1: File HANDLE.
; Return:     eax = Number of lines.
;             ecx -> Mem block containing an array of DWORD offsets.
;                    The user must dispose it using MemFree.
;
; Notes:     - Lines must be terminated with the ANSI char sequence 13, 10 (CRLF).
;            - The last line may not terminate with a CRLF.

% include &ObjMemPath&Common\GetFileLines_AX.inc

end
