; ==================================================================================================
; Title:      CreateCursorFromCompressedFileInRes.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2023
;               - First release.
; Links:      https://learn.microsoft.com/en-us/windows/win32/api/compressapi/
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
TARGET_STR_TYPE = STR_TYPE_WIDE
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  CreateCursorFromCompressedFileInRes
; Purpose:    Create a cursor from a compressed cursor file stored as RCDATA resource. 
;             Compression should be done using a Microsoft compression algorithm: XPRESS, XPRESS
;             with Huffman encoding, MSZIP or LZMS.
; Arguments:  Arg1: hInstance.
;             Arg2: Resource ID.
;             Arg3: Desired cursor width.
;             Arg3: Desired cursor height.
; Return:     eax = Cursor HANDLE or zero if failed.

% include &ObjMemPath&Common\CreateCursorFromCompressedFileInRes_X.inc

end
