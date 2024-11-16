; ==================================================================================================
; Title:      ParseCmdLineArgs.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, July 2024
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
TARGET_STR_TYPE = STR_TYPE_ANSI
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  ParseCmdLineArgs
; Purpose:    Parse a WIDE command line string and return an array of PSTRINGW to the arguments,
;             along with a count of these arguments. Delimiters are white chars and CRLF.
; Arguments:  Arg1: -> Input WIDE string.
; Return:     rax -> Array of PSTRINGWs. If rax = NULL, allocation failed or argument count is 0.
;             ecx = Argument count.
; Note:       1. Memory allocated to hold the PSTRINGWs must be freed using MemFree.
;             2. Quoted arguments are retuned without quotation marks.
;             3. The input string is modified with ZTCs at the end of each argument.
;             4. The PSTRINGW list is always terminated with a NULL pointer. 

% include &ObjMemPath&Common\ParseCmdLineArgs_X.inc

end
