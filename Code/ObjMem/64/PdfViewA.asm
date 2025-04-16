; ==================================================================================================
; Title:      PdfViewA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
TARGET_STR_TYPE = STR_TYPE_ANSI
% include &ObjMemPath&ObjMemWin.cop

% include &IncPath&Windows\shlwapi.inc
% include &IncPath&Windows\shellapi.inc

ProcName textequ <PdfViewA>

; --------------------------------------------------------------------------------------------------
; Procedure:  PdfViewA
; Purpose:    Display a PDF document on a named destination.
; Arguments:  Arg1: Parent HANDLE.
;             Arg2: -> PDF document.
;             Arg3: -> Destination.
; Return:     rax = HINSTANCE. See ShellExecute return values. 
;             A value greater than 32 indicates success.

% include &ObjMemPath&Common\PdfView_TX.inc

end
