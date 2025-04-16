; ==================================================================================================
; Title:      CreateBitmapFromCompressedFileInRes.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2023
;               - First release.
; Links:      https://learn.microsoft.com/en-us/windows/win32/api/compressapi/
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
TARGET_STR_TYPE = STR_TYPE_WIDE
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  CreateBitmapFromCompressedFileInRes
; Purpose:    Create a bitmap from a compressed bitmap file stored as RCDATA resource.
;             Compression should be done using a Microsoft compression algorithm: XPRESS, XPRESS
;             with Huffman encoding, MSZIP or LZMS.
; Arguments:  Arg1: Instance HANDLE.
;             Arg2: Resource ID.
; Return:     rax = HBITMAP or zero if failed.

% include &ObjMemPath&Common\CreateBitmapFromCompressedFileInRes_X.inc

end
