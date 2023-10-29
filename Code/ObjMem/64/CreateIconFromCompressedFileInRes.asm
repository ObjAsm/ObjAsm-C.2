; ==================================================================================================
; Title:      CreateIconFromCompressedFileInRes.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2023
;               - First release.
; Links:      https://learn.microsoft.com/en-us/windows/win32/api/compressapi/
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
TARGET_STR_TYPE = STR_TYPE_WIDE
% include &ObjMemPath&ObjMemWin.cop

.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  CreateIconFromCompressedFileInRes
; Purpose:    Create an icon from a compressed icon file stored as RCDATA resource. 
;             Compression should be done using a Microsoft compression algorithm: XPRESS, XPRESS
;             with Huffman encoding, MSZIP or LZMS.
; Arguments:  Arg1: hInstance.
;             Arg2: Resource ID.
;             Arg3: Desired icon width.
;             Arg3: Desired icon height.
; Return:     xax = Icon HANDLE.

% include &ObjMemPath&Common\CreateIconFromCompressedFileInRes_X.inc

end
