; ==================================================================================================
; Title:      DecompressFileFromRes.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2023
;               - First release.
; Links:      https://learn.microsoft.com/en-us/windows/win32/api/compressapi/
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
TARGET_STR_TYPE = STR_TYPE_WIDE
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  DecompressFileFromRes
; Purpose:    Load a compressed file stored as RCDATA resource and decompress it.
;             Compression should be done using a Microsoft compression algorithm: XPRESS, XPRESS
;             with Huffman encoding, MSZIP or LZMS.
; Arguments:  Arg1: Instance HANDLE.
;             Arg2: Resource ID.
; Return:     xax -> Uncompressed data or NULL if failed.
;             ecx = Uncompressed data size in BYTEs.

% include &ObjMemPath&Common\DecompressFileFromRes_X.inc

end
